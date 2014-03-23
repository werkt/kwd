#ifndef DOOR_H
#define DOOR_H

#include "Resource.h"

struct DoorBlock {
  char name[32];
  ArtResource ref[5];
  uint8_t unk[164];
};

class class_56a920 {
public:
  void sub_56aa40( DoorBlock &rkBlock ) { /* unimplemented */ }

private:
  DoorBlock m_kBlock;
};

#endif
