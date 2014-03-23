#ifndef KEEPER_FILE_H
#define KEEPER_FILE_H

#include <sys/stat.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdint.h>

#include "TbString.h"

#define MAX_PATH 260

class class_672708;

class class_5b7610 {
public:
  class_5b7610();
  ~class_5b7610();

private:
  pthread_mutex_t m_kMutex;
};

/* makes sense given the offset below of 130, i believe */
struct CFileManager_0008 {
  CFileManager_0008() : x0020(x0024) { x0024[0] = '\0'; }
  unsigned int x0000; /* length of current file */
  unsigned int x0004;
  unsigned int x0008;
  unsigned int x000c;
  unsigned int x0010;
  unsigned int x0014;
  unsigned int x0018;
  unsigned int x001c;

  char *x0020; /* basename of file */
  char x0024[MAX_PATH]; /* filename */
};

/* maybe 6725d8 ??? */
class TbRefCount {
public:
  TbRefCount() : m_pk04(NULL), m_dwCounter(0) { }
  virtual ~TbRefCount() { }
  void sub_5d7230() { m_dwCounter++; /* interlocked increment */ }
  virtual int virt04( void *pBuffer, int size ) = 0; /* read */
  virtual int virt0c( long lDistanceToMove, unsigned int dwMoveMethod ) = 0; /* seek */
  virtual size_t virt10() const = 0; /* get file size */
  virtual off_t virt14() const = 0;
  virtual void virt28( TbRefCount *arg0 ); /* 5d7290, just a guess that it belongs here */

protected:
  TbRefCount *m_pk04;
  unsigned int m_dwCounter; /* 8 */
};

/* dk version initializes a semaphore at x1c, probably useful to do the same */
class class_672fe8 : public TbRefCount {
public:
#ifdef __linux__
  class_672fe8();
  virtual ~class_672fe8();
  int &open( int &ret, const char *filename, int mode ); /* my own construction based on sub_5ffec0 */
#endif

  virtual int virt04( void *pBuffer, int size ); /* read */
  virtual int virt0c( long lDistanceToMove, unsigned int dwMoveMethod ); /* seek */
  virtual size_t virt10() const; /* get file size */
  virtual off_t virt14() const; /* return offset, stored at x10 */
  /* insane strstreambuf like thing at 5ffdf0 */
  virtual void virt28( TbRefCount *arg0 ) { }

#ifdef __linux__
  int m_nFD; /* c */
#else
  HANDLE m_hFile; /* c */
#endif
  off_t m_dwOffset; /* 10 */
};

namespace FileSystem {
  class TbFile {
  public:
    TbFile(); /* 5b6e40 */
    virtual void virt04();
    virtual ssize_t virt08( void *buf, size_t size ); /* read */
    virtual off_t virt10( off_t arg0, int whence ); /* seek */
    virtual size_t virt14(); /* file size, 5fde70 */
    virtual off_t virt18(); /* offset, 5b6f00 */

    TbRefCount *sub_5b6f10();
    void sub_5b6f20( TbRefCount *pkAtomic );
    int sub_5b6ea0( void *buf, int size ); /* read */
    int sub_5fde70(); /* file size likely */
    int sub_5b6f00(); /* position also likely */

  protected:
    TbRefCount *m_p04;
  };

  /* 672348 */
  class TbFileStorage {
  public:
    TbFileStorage() : x04(NULL) { }
    class_672708 *get04() { return x04; }
    void sub_5b9d00( TbFileStorage &arg0 );
    void sub_5b9e80( class_672708 *obj );

    virtual void virt00();
    virtual int &virt04( int &ret, const char *name, CFileManager_0008 &arg8 );
    virtual int &virt0c( int &ret, TbFile &arg4, const char *arg8,
                         int argc, void *arg10 ); /* 5b9e30 */
    virtual int &virt14( int &ret, char *buf, const char *path, int size );
    virtual void virt2c( class_672708 *arg0 ) { abort(); }

  protected:
    class_672708 *x04;
  };
}

class TbDiscFileStorage : public FileSystem::TbFileStorage {
public:
  TbDiscFileStorage();

  int &sub_5baba0( int &ret, const char *p );
};

class class_672708 {
public:
  class_672708();
  virtual ~class_672708() { }

  virtual int &virt04( int &ret, FileSystem::TbFile &arg4, const char *arg8,
                       unsigned int flags, void *arg10 ) = 0;
  virtual int &virt08( int &ret, const char *name,
                       CFileManager_0008 &arg8 ) = 0;
  virtual int &virt14( int &ret, char *arg4, const char *language, int argc );
  virtual void virt2c( class_672708 *arg );
  virtual void virt30() { abort(); }

  void setNext( class_672708 *value ) { m_pkNext04 = value; }
  class_672708 *getNext() { return m_pkNext04; }
  TbDynamicStringTemplate<char> &get10() { return x10; }
  int sub_5d8230();
  int sub_5d8220();

protected:
  class_672708 *m_pkNext04;
  class_5b7610 x08;
  int x0c;
  TbDynamicStringTemplate<char> x10;
};

class TbDiscFile : public FileSystem::TbFile {
public:
  virtual ~TbDiscFile() { }
  virtual int &virt24(int &ret, const char *filename, int mode);
  /* no constructor */
};


bool &sub_5b3eb0( bool &ret, TbDiscFile *file, void *buf, size_t size, size_t *sizeReadRet ); /* read */
int &sub_5b3980( int &arg0, TbDiscFile **arg4, const char *filename, int mode ); /* open */
int &sub_5b3a30( int &ret, TbDiscFile *file ); /* close */
size_t sub_5b3b80( TbDiscFile *file ); /* file size */
off_t sub_5b3a80( TbDiscFile *file ); /* offset */
off_t sub_5b3a90( TbDiscFile *file, off_t offset, int whence );
bool sub_5b3bf0( const char *path );
int &sub_5b3900( int &ret, const char *path );

#endif
