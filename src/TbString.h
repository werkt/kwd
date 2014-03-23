#ifndef TB_STRING_H
#define TB_STRING_H

#include <string.h>
#include <stdint.h>

/* Read only string, no deallocation */
template <typename T>
class TbStringTemplate {
public:
  TbStringTemplate() : x04(0), x08(NULL) { }
  TbStringTemplate( int len, char *str ) : x04(len), x08(str) { }

  virtual void virt00() { } /* printf, has a buffer first arg, then */
                            /* fmt, then args... so awesome */
  virtual void virt04( int size ) { }

  /* I would bet dollars that this is available through the template
   * type - it, i believe, makes templating over char sizes possible */
  int sub_5d7a70( const char *arg0 ) const { return strlen(arg0); }
  char *sub_5d7ae0( char *dst, const char *s ) {
    return strcat(dst, s);
  }
  char *sub_5d7a90( char *dst, const char *src ) {
    return strcpy(dst, src);
  }
  char *sub_5d7ac0( char *dst, const char *src, int chars ) {
    return strncpy(dst, src, chars);
  }
  char *sub_5d7b20( char *dst, const char *src, int chars ) {
    return strncat(dst, src, chars);
  }

  uint8_t sub_5d7d30( const char *arg0 ) const; /* == */
  int sub_5d7e20( const char *arg0, int pos ) const; /* find */
  size_t sub_5d7f60( const char *arg0, size_t pos ); /* find_first_of */
  size_t sub_5d7fe0( const char *arg0, size_t pos ); /* find_last_of */
  TbStringTemplate sub_5d8050( size_t pos ) const; /* ro substring at pos */
  TbStringTemplate sub_5d8080( size_t pos ) const; /* rsubstr */
  TbStringTemplate sub_5d80c0( size_t len ) const; /* ro substring of len */
  TbStringTemplate sub_5d8100( size_t pos, size_t len ) const; /* substr */

  int get04() const { return x04; }
  const char *get08() const { return x08; }
  char *get08() { return x08; }

protected:
  int x04;
  T *x08;
};

/* I've definitely seen the above called from either a 6722d0 or a 672300 */

/* Further, I believe we have the following hierarchy in play */
/* TbTList<TbDynamicStringTemplate<char>, TbDynamicStringTemplate<char> &>
 *   TbCharStringList
 *     class_672774 - magic file path string list */

/* TbCharString - based on 55c3c0 and its TbCharStringList that contains it */

/* 6722d0 */
template <typename T>
class TbDynamicStringTemplate : public TbStringTemplate<T> {
public:
  TbDynamicStringTemplate() { /* 5b8880 */
    x10 = 8;
    x0c = 8;

    this->x08 = new T[9];
    this->x08[this->x04] = '\0';
  }
  TbDynamicStringTemplate( const char *arg0 ); /* 5b87e0 */
  TbDynamicStringTemplate( const TbStringTemplate<T> &arg0 ); /* 5b8770 */

  virtual void virt00() { abort(); } /* 5b8ab0 */
  virtual void virt04( int size ); /* 5b8730 - resize */
  virtual void virt08( int size ); /* 5b86f0 - grow to */

  virtual TbDynamicStringTemplate &virt14( const char *arg0 ); /* 5b8920 */
  virtual TbDynamicStringTemplate &virt18( const TbStringTemplate<T> &arg0 ); /* 672300 */
  virtual TbDynamicStringTemplate &virt1c( const TbStringTemplate<T> &arg0 ); /* 5b89b0 */
  virtual TbDynamicStringTemplate &virt20( const char *arg0 ); /* 5b8a00 */
  virtual TbDynamicStringTemplate &virt24( const char *arg0 ); /* 5b8a40 */
  virtual TbDynamicStringTemplate &virt28( const TbDynamicStringTemplate &arg0 ); /* 5b8a70 */

private:
  explicit TbDynamicStringTemplate( const TbDynamicStringTemplate &arg0 );

private:
  int x0c;
  int x10;
};

/* not sure here, but definitely a string */
/* uses an externally maintained buffer, but does dynamic actions */
template <typename T>
class class_672ec0 : public TbStringTemplate<T> {
public:
  class_672ec0( char *arg0, int arg4, int arg8 ); /* 5fe000 */

  virtual void virt00() { abort(); } /* 5fe240 */
  virtual void virt04( int chars ) {
    if( chars >= x0c ) {
      x10 = 1;
      this->x04 = x0c - 1;
    } else {
      this->x04 = chars;
      x10 = 0;
    }
    this->x08[this->x04] = '\0';
  }
  virtual class_672ec0 &virt14( const TbStringTemplate<T> &arg0 ); /* 5fe150 */
  virtual class_672ec0 &virt18( const char *arg0 ); /* 5fe180 */

  int get10() const { return x10; }

private:
  int x0c;
  int x10; /* flag of sorts, possibly 'is nul terminated' */
};

#include "TbString.inl"

#endif
