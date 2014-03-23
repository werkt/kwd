template <typename T>
uint8_t
TbStringTemplate<T>::sub_5d7d30( char const *s ) const
{
  if( s == 0 ) return x04 == 0;
  if( strlen(s) != x04 ) return 0;
  return strncmp(x08, s, x04) == 0;
}

template <typename T>
int
TbStringTemplate<T>::sub_5d7e20( char const *s, int pos ) const
{
  if( pos >= x04 ) pos = x04;
  if( *s == '\0' || pos >= x04 ) return -1;
  for( int edx = pos; edx < x04; edx++ )
    if( x08[edx] == *s ) return edx;
  return -1;
}

template <typename T>
size_t
TbStringTemplate<T>::sub_5d7f60( char const *s, size_t pos )
{
  if( pos >= x04 ) pos = x04;
  if( s == 0 || pos >= x04 ) return (size_t) -1;
  const char *esi = x08 + pos;
  while( esi < x08 + x04 ) {
    const char *cp = s;
    while( *cp ) {
      if( *cp == *esi )
        return esi - x08;
      cp++;
    }
    esi++;
  }
  return (size_t) -1;
}

template <typename T>
size_t
TbStringTemplate<T>::sub_5d7fe0( char const *arg0, size_t pos )
{
  if( arg0 == 0 ) return (size_t ) -1;
  if( pos >= x04 - 1 ) pos = x04 - 1;
  const char *esi = x08 + pos;
  while( esi >= x08 ) {
    const char *cp = arg0;
    while( *cp ) {
      if( *cp == *esi )
        return esi - x08;
      cp++;
    }
    esi--;
  }
  return (size_t ) -1;
}

template <typename T>
TbStringTemplate<T>
TbStringTemplate<T>::sub_5d8050( size_t len ) const
{
  if( len >= x04 ) len = x04;
  return TbStringTemplate<T>(len, x08);
}

template <typename T>
TbStringTemplate<T>
TbStringTemplate<T>::sub_5d8080( size_t len ) const
{
  if( len >= x04 ) len = x04;
  return TbStringTemplate<T>(len, &x08[x04 - len]);
}

template <typename T>
TbStringTemplate<T>
TbStringTemplate<T>::sub_5d80c0( size_t len ) const
{
  if( len >= x04 ) len = x04;
  return TbStringTemplate<T>(x04 - len, &x08[len]);
}

template <typename T>
TbStringTemplate<T>
TbStringTemplate<T>::sub_5d8100( size_t pos, size_t len ) const
{
  if( pos >= x04 ) pos = x04;
  if( len >= x04 - pos ) len = x04 - pos;
  return TbStringTemplate<T>(len, &x08[pos]);
}

template <typename T>
TbDynamicStringTemplate<T>::TbDynamicStringTemplate( char const *s )
{
  if( s == 0 ) {
    x0c = x10 = 8;
    this->x08 = new char[9];
    this->x08[this->x04] = '\0';
  } else {
    this->x04 = TbStringTemplate<T>::sub_5d7a70(s);
    x10 = 8;
    x0c = (this->x04 >> 3) * 8 + 8;
    this->x08 = new char[x0c + 1];
    this->x08[x0c + 1] = '\0';
    TbStringTemplate<T>::sub_5d7a90(this->x08, s);
  }
}

template <typename T>
TbDynamicStringTemplate<T>::TbDynamicStringTemplate( const TbStringTemplate<T> &rkString )
{
  this->x04 = rkString.get04();
  x0c = (rkString.get04() >> 3) * 8 + 8;
  this->x08 = new char[x0c + 1];
  this->x08[this->x04] = '\0';
  TbStringTemplate<T>::sub_5d7ac0(this->x08, rkString.get08(), this->x04);
  this->x08[this->x04] = '\0';
}

template <typename T>
class_672ec0<T>::class_672ec0( char *buf, int arg4, int arg8 )
{
  if( arg4 <= 0 ) arg4 = 0;
  x0c = arg4;
  this->x08 = buf;
  if( arg8 == 0 ) {
    int eax = TbStringTemplate<T>::sub_5d7a70(buf);
    if( eax >= x0c ) {
      x10 = 1;
      this->x04 = x0c - 1;
      this->x08[this->x04] = '\0';
    } else {
      this->x04 = eax;
      x10 = 0;
      this->x08[this->x04] = '\0';
    }
  } else {
    if( x0c <= 0 ) abort(); /* 5fe052 */
    else {
      this->x04 = 0;
      x10 = 0;
      this->x08[0] = '\0';
    }
  }
}

/* 5fe150 */
template <typename T>
class_672ec0<T> &
class_672ec0<T>::virt14( const TbStringTemplate<T> &arg0 )
{
  virt04(arg0.get04());
  TbStringTemplate<T>::sub_5d7ac0(this->x08, arg0.get08(), this->x04);
  return *this;
}

/* 5fe180 */
template <typename T>
class_672ec0<T> &
class_672ec0<T>::virt18( const char *s )
{
  if( s != 0 ) {
    virt04(TbStringTemplate<T>::sub_5d7a70(s) + this->x04);
    TbStringTemplate<T>::sub_5d7b20(this->x08, s, this->x04);
  }
  return *this;
}

/* 5b8730 */
template <typename T>
void
TbDynamicStringTemplate<T>::virt04( int size )
{
  if( size <= x0c ) {
    this->x04 = size;
    this->x08[size] = '\0';
  } else {
    char *edi = this->x08; /* previous buffer */
    virt08(size);
    TbStringTemplate<T>::sub_5d7a90(this->x08, edi);
    delete[] edi;
  }
}

template <typename T>
void
TbDynamicStringTemplate<T>::virt08( int size )
{
  this->x04 = size;
  x10 = 8;
  x0c = (this->x04 >> 3) * 8 + 8;
  this->x08 = new char[x0c + 1];
  this->x08[this->x04] = 0;
}

/* 5b8920 - retval is actually *this */
template <typename T>
TbDynamicStringTemplate<T> &
TbDynamicStringTemplate<T>::virt14( const char *s )
{
  if( s == 0 ) {
    *this->x08 = 0;
    this->x04 = 0;
  } else {
    virt04(TbStringTemplate<T>::sub_5d7a70(s));
    TbStringTemplate<T>::sub_5d7a90(this->x08, s);
  }
  return *this;
}

template <typename T>
TbDynamicStringTemplate<T> &
TbDynamicStringTemplate<T>::virt18( const TbStringTemplate<T> &rkString )
{
  TbStringTemplate<T> var_10(rkString);
  return virt1c(var_10);
}

template <typename T>
TbDynamicStringTemplate<T> &
TbDynamicStringTemplate<T>::virt1c( const TbStringTemplate<T> &rkString )
{
  if( this != &rkString ) {
    if( this->x04 < rkString.get04() ) virt04(rkString.get04());
    TbStringTemplate<T>::sub_5d7ac0(this->x08, rkString.get08(), rkString.get04());
    virt04(rkString.get04());
  }
  return *this;
}

template <typename T>
TbDynamicStringTemplate<T> &
TbDynamicStringTemplate<T>::virt20( const char *s )
{
  if( s != 0 ) {
    virt04(TbStringTemplate<T>::sub_5d7a70(s) + this->x04);
    TbStringTemplate<T>::sub_5d7ae0(this->x08, s);
  }
  return *this;
}

template <typename T>
TbDynamicStringTemplate<T> &
TbDynamicStringTemplate<T>::virt24( char const *s )
{
  if( *s != '\0' ) {
    virt04(this->x04 + 1);
    this->x08[this->x04 - 1] = *s;
  }
  return *this;
}

template <typename T>
TbDynamicStringTemplate<T> &
TbDynamicStringTemplate<T>::virt28( const TbDynamicStringTemplate<T> &rkString )
{
  virt04(this->x04 + rkString.get04());
  TbStringTemplate<T>::sub_5d7b20(this->x08, rkString.get08(), rkString.get04());
  return *this;
}
