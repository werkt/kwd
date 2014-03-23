#include <sys/types.h>
#include <unistd.h>
#include <dirent.h>
#include <fcntl.h>
#include <errno.h>
#include <string.h>
#include <stdio.h>
#include <pthread.h>

#include "File.h"

int dk2_stat( const char *path, struct stat *st );

/* vtable at 672778 */
struct class_5d9200 : public class_672708 {
public:
  class_5d9200();
  virtual ~class_5d9200() { }
  int &sub_5d9620( int &res, const char *p );
  virtual int &virt04( int &ret, FileSystem::TbFile &arg4, const char *name,
                       unsigned int flags, void *arg10 );
  virtual int &virt08( int &ret, const char *name, CFileManager_0008 &arg8 ) { abort(); }
  virtual void virt30() { }

private:
  int x24;
};

/* read */
bool &
sub_5b3eb0( bool &ret, TbDiscFile *file, void *buf, size_t size, size_t *sizeReadRet )
{
  size_t sizeRead = file->virt08(buf, size);
  if( sizeReadRet ) *sizeReadRet = sizeRead;
  return ret = (sizeRead == size);
}

/* open */
int &
sub_5b3980( int &ret, TbDiscFile **arg4, const char *filename, int mode )
{
  TbDiscFile *var_10 = new TbDiscFile;

  int var_14;
  var_10->virt24(var_14, filename, mode);
  if( var_14 >= 0 ) {
    *arg4 = var_10;
    ret = 0;
  } else ret = var_14;
  return ret;
}

/* close */
int &
sub_5b3a30( int &ret, TbDiscFile *file )
{
  file->virt04();
  delete file;
  return ret = 0;
}

/* file size */
size_t
sub_5b3b80( TbDiscFile *file )
{
  return file->virt14();
}

/* offset */
off_t
sub_5b3a80( TbDiscFile *file )
{
  return file->virt18();
}

/* seek */
off_t
sub_5b3a90( TbDiscFile *file, off_t offset, int whence )
{
  return file->virt10(offset, whence);
}

bool
sub_5b3bf0( const char *path )
{
  struct stat st;

  return dk2_stat(path, &st) == 0;
}

int &
sub_5b3900( int &ret, const char *path )
{
  abort();
}

static bool
dk2_path_fill( char *match, size_t match_len,
               const char *path, size_t path_len )
{
  char xpath[MAX_PATH];
  DIR *dir;
  struct dirent *ent;

  if( path_len ) {
    strncpy(xpath, path, path_len);
    xpath[path_len] = '\0';
  } else {
    strcpy(xpath, ".");
  }

  dir = opendir(xpath);
  if( dir == NULL )
    return false;

  while( (ent = readdir(dir)) ) {
    if( strlen(ent->d_name) != match_len ||
        strncasecmp(ent->d_name, match, match_len) ) continue;
    strncpy(match, ent->d_name, match_len);
    closedir(dir);
    return true;
  }

  closedir(dir);

  return false;
}

static bool
dk2_path( char *buf, size_t len, const char *path )
{
  char *dk2p, *dk2c;

  if( strlen(path) > len - 1 ) {
    errno = ENAMETOOLONG;
    return -1;
  }

  strcpy(buf, path);

  if( buf[0] == '\\' ) {
    errno = EINVAL;
    return -1;
  }

  for( dk2c = dk2p = buf;; dk2p++ ) {
    if( (*dk2p == '\0' || *dk2p == '\\' || *dk2p == '/') && dk2p - dk2c > 0 ) {
      if( !dk2_path_fill(dk2c, dk2p - dk2c, buf, dk2c - buf) ) {
        errno = ENOENT;
        return -1;
      }
    }
    if( *dk2p == '\0' ) break;
    if( *dk2p == '\\' || *dk2p == '/' ) {
      *dk2p = '/';
      dk2c = dk2p + 1;
    }
  }

  return true;
}

int
dk2_stat( const char *path, struct stat *st )
{
  char buf[MAX_PATH];

  if( !dk2_path(buf, sizeof(buf), path) ) return -1;

  return stat(buf, st);
}

static int
dk2_open( const char *path, int flags )
{
  char buf[MAX_PATH];

  if( !dk2_path(buf, sizeof(buf), path) ) return -1;

  return open(buf, flags);
}

FILE *
dk2_fopen( const char *path, const char *mode )
{
  char buf[MAX_PATH];

  if( !dk2_path(buf, sizeof(buf), path) ) return NULL;

  return fopen(buf, mode);
}

bool
IsDBCSLeadByte( uint8_t ch )
{
  return false;
}

/* 5b9f77 */
int &
TbDiscFile::virt24(int &ret, const char *filename, int mode)
{
  TbDynamicStringTemplate<char> var_34(filename);
  uint8_t bl = 0;
  int edi = -1;
  int esi = 20000;
  while( bl == 0 ) {
    if( (esi = var_34.sub_5d7fe0("\\/", edi)) <= 0 ||
        IsDBCSLeadByte(var_34.get08()[esi - 1]) ) {
      abort(); /* 5b9fe3 */
    } else {
      esi++;
      bl = 1;
    }
    if( esi <= 0 ) break;
  }
  if( esi == -1 )
    esi = 0;
  /* return is a 672300, which i suspect is the REAL std::string */
  /* this is modified from call with only pos argument */
  /* adding the npos second arg to be explicit... real call is at 5d80c0 */
  TbDynamicStringTemplate<char> var_20(var_34.sub_5d80c0(esi));

  /* not a normal virt call, it pulls the address of +x1c, then calls into
   * it as virt00... is this indicative of multiple inheritance? */
  var_34.virt1c(var_34.sub_5d8050(esi));

  TbDiscFileStorage var_5c;

  int arg_4;
  if( var_5c.sub_5baba0(arg_4, var_34.get08()) < 0 ||
      var_5c.virt0c(arg_4, *this, var_20.get08(), mode, NULL) < 0 )
    return ret = -1;
  return ret = 0;
}

void
FileSystem::TbFileStorage::virt00()
{
  if( x04 ) x04->sub_5d8230();
}

int &
FileSystem::TbFileStorage::virt04( int &ret, const char *name,
                                   CFileManager_0008 &arg8 )
{
  if( x04 == NULL ) return ret = -1;
  x04->virt08(ret, name, arg8);
  return ret;
}

/* 5b9e30 */
int &
FileSystem::TbFileStorage::virt0c( int &ret, FileSystem::TbFile &arg4,
                                   const char *arg8, int argc, void *arg10 )
{
  if( x04 == NULL ) return ret = -1;
  x04->virt04(ret, arg4, arg8, argc, arg10);
  return ret;
}

class_672fe8::~class_672fe8()
{
  if( m_nFD != -1 ) {
    close(m_nFD);
    m_nFD = -1;
  }
}

class_672fe8::class_672fe8()
  : m_nFD(-1), m_dwOffset(0)
{
}

int &
class_672fe8::open( int &ret, const char *filename, int mode )
{
  int fd = dk2_open(filename, O_RDONLY);
  if( fd < 0 ) return ret = -1;
  m_nFD = fd;
  m_dwOffset = 0;
  return ret = 0;
}

/* read */
int
class_672fe8::virt04( void *pBuffer, int size )
{
  ssize_t len = ::read(m_nFD, pBuffer, size);
  if( len != -1 )
    m_dwOffset += len;
  return len;
}

/* seek */
int
class_672fe8::virt0c( long lDistanceToMove, unsigned int dwMoveMethod )
{
  return m_dwOffset = lseek(m_nFD, lDistanceToMove, dwMoveMethod);
}

/* get file size */
size_t
class_672fe8::virt10() const
{
  struct stat st;

  if( fstat(m_nFD, &st) != 0 ) return (size_t) -1;

  return st.st_size;
}

/* return offset, stored at x10 */
off_t
class_672fe8::virt14() const
{
  return m_dwOffset;
}

int &
FileSystem::TbFileStorage::virt14( int &ret, char *buf, const char *path,
                                   int size )
{
  if( x04 == NULL ) return ret = -1;
  x04->virt14(ret, buf, path, size);
  return ret;
}

void
TbRefCount::virt28( TbRefCount *arg0 )
{
  if( m_pk04 ) arg0->virt28(m_pk04);
  m_pk04 = arg0;
}

FileSystem::TbFile::TbFile() : m_p04(NULL) { }

TbRefCount *
FileSystem::TbFile::sub_5b6f10()
{
  return m_p04;
}

void
FileSystem::TbFile::sub_5b6f20( TbRefCount *pkAtomic )
{
  if( pkAtomic ) {
    pkAtomic->sub_5d7230();
    if( m_p04 ) pkAtomic->virt28(m_p04);
    m_p04 = pkAtomic;
  }
}

void
FileSystem::TbFile::virt04()
{
  if( m_p04 ) {
    delete m_p04;
    m_p04 = NULL;
  }
}

ssize_t
FileSystem::TbFile::virt08( void *buf, size_t size )
{
  if( m_p04 == NULL ) return ~0;
  return m_p04->virt04(buf, size);
}

off_t
FileSystem::TbFile::virt10( off_t arg0, int arg4 )
{
  if( m_p04 == NULL ) return -1;
  return m_p04->virt0c(arg0, arg4);
}

size_t
FileSystem::TbFile::virt14()
{
  if( m_p04 == NULL ) return ~0;
  return m_p04->virt10();
}

off_t
FileSystem::TbFile::virt18()
{
  if( m_p04 == NULL ) return ~0;
  return m_p04->virt14();
}

int
FileSystem::TbFile::sub_5b6ea0( void *buf, int size )
{
  if( m_p04 == NULL ) return -1;
  return m_p04->virt04(buf, size);
}

int
FileSystem::TbFile::sub_5fde70()
{
  if( m_p04 == NULL ) return -1;
  return m_p04->virt10();
}

int
FileSystem::TbFile::sub_5b6f00()
{
  if( m_p04 == NULL ) return -1;
  return m_p04->virt14();
}

TbDiscFileStorage::TbDiscFileStorage()
{
}

void
FileSystem::TbFileStorage::sub_5b9e80( class_672708 *obj )
{
  obj->sub_5d8220();
  if( x04 )
    virt2c(x04);
  x04 = obj;
}

int &
TbDiscFileStorage::sub_5baba0( int &x, const char *p )
{
  virt00();
  class_5d9200 *obj = new class_5d9200();
  int res;
  if( obj->sub_5d9620(res, p) == 0 ) {
    sub_5b9e80(obj);
    x = 0;
    return x;
  }
  delete obj;
  x = -1;
  return x;
}

/* prefixes game paths with the executable location.
 * force absolute paths for now */
int &
makeAbsolute( int &rval, char *buffer, int size, const char *path )
{
  if( path == NULL ) abort();
#ifdef __linux__
  if( path[0] != '/' ) abort();
#else
  if( path[1] != ':' ) dkabort();
  if( path[2] != '/' && path[2] != '\\' ) dkabort();
#endif
  strcpy(buffer, path);
  return rval = 0;
}

class_5d9200::class_5d9200()
{
  x24 = -1;
}

int &
class_5d9200::virt04( int &ret, FileSystem::TbFile &arg4, const char *name,
                      unsigned int flags, void *arg10 )
{
  if( arg4.sub_5b6f10() != NULL ) return ret = -1;

  TbDynamicStringTemplate<char> var_20(static_cast<const TbStringTemplate<char> &>(x10));
  var_20.virt20(name);

  if( flags & 0x8000 ) abort();
  class_672fe8 *edi = new class_672fe8();
  int xret;
  if( edi->open(xret, var_20.get08(), flags) < 0 ) {
    delete edi;
    return ret = -1;
  }
  arg4.sub_5b6f20(edi);
  return ret = 0;
}

int &
class_5d9200::sub_5d9620( int &res, const char *path )
{
  int var_108;
  char FileName[MAX_PATH];
  struct stat st;

  makeAbsolute(var_108, FileName, MAX_PATH, path);
  if( dk2_stat(FileName, &st) == -1 ) return res = -1;
  x10.virt14(FileName);
  if( x10.get08()[x10.get04() - 1] != '\\' &&
      x10.get08()[x10.get04() - 1] != '/' )
    x10.virt24("\\");
  return res = 0;
}

class_672708::class_672708()
{
  x0c = 0;
  m_pkNext04 = NULL;
}

int
class_672708::sub_5d8220()
{
  return ++x0c; /* InterlockedIncrement */
}

int
class_672708::sub_5d8230()
{
  if( --x0c ) return x0c; /* InterlockedDecrement */
  virt30();
  if( m_pkNext04 ) {
    m_pkNext04->sub_5d8230();
    m_pkNext04 = NULL;
  }
  delete this;
  return 0;
}

int &
class_672708::virt14( int &ret, char *arg4, const char *language, int argc )
{
  class_672ec0<char> var_20(arg4, argc, 1);
  var_20.virt14(x10);
  var_20.virt18(language);
  return ret = (var_20.get10() == 0 ? 0 : -1);
}

void
class_672708::virt2c( class_672708 *arg )
{
  if( getNext() ) arg->virt2c(getNext());
  setNext(arg);
}

class_5b7610::class_5b7610()
{
  pthread_mutex_init(&m_kMutex, NULL);
}

/* 5b76a0 */
class_5b7610::~class_5b7610()
{
  pthread_mutex_destroy(&m_kMutex);
}
