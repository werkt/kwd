#ifndef TRAP_H
#define TRAP_H

#include "Resource.h"

struct TrapBlock {
  char name[32];
  ArtResource ref[5];
  uint8_t data[127];
};

class class_570b60 {
public:
  void sub_570d10( TrapBlock &rkBlock ) { /* unimplemented */ }

private:
  TrapBlock m_kBlock;
};

#endif
