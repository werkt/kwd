#ifndef THING_H
#define THING_H

#include <string.h>

#include "Resource.h"

struct Position3D {
  int32_t X;
  int32_t Y;
  int32_t Z;
};

#pragma pack(push,1)

struct ActionPointBlock {
  int32_t x00;
  int32_t x04;
  int32_t x08;
  int32_t x0c;
  int32_t x10;
  int16_t x14;
  uint8_t id; /* 16 */
  uint8_t x17;
  char name[32]; /* 18 */
};

#pragma pack(pop)

/* named for load function, inline constructor */
/* ActionPointLoadBlock */
class ActionPointLoadBlock {
public:
  void load( const ActionPointBlock &pkBlock ); /* 56f790 */
  const ActionPointBlock &block() const { return m_kBlock; }

private:
  bool m_fNamePresent;
  bool m_fIdPresent;
  bool m_f00Present;
  bool m_f04Present;
  bool m_f08Present;
  bool m_f0cPresent;
  bool m_f14Present;
  bool m_f17Present;
  bool m_f10Present;
  ActionPointBlock m_kBlock; /* 24 */
};

#pragma pack(push,1)

struct HeroPartyData {
  int32_t x00;
  int32_t x04;
  int32_t x08;
  int16_t goldHeld;
  uint8_t x0e; /* level */
  uint8_t x0f;
  int32_t x10;
  int32_t initialHealth;
  int16_t x18; /* trigger root */
  uint8_t x1a;
  uint8_t x1b;
  uint8_t x1c;
  uint8_t x1d;
  uint8_t x1e;
  uint8_t x1f;
};

struct Thing08Block { /* hero party */
  char name[32];
  int16_t x20;
  uint8_t x22;
  int32_t x23; /* these two are unreferenced... */
  int32_t x27;
  HeroPartyData x2b[16];
};

#pragma pack(pop)

class Thing08LoadBlock {
public:
  void load( const Thing08Block &rkBlock ) {
    m_fPresent00 = true;
    strncpy(m_kBlock.name, rkBlock.name, 32);
    m_kBlock.name[31] = '\0';

    m_fPresent01 = true;
    m_kBlock.x20 = rkBlock.x20;

    m_fPresent02 = true;
    m_kBlock.x22 = rkBlock.x22;

    for( int i = 0; i < 16; i++ ) {
      m_fPresent03[i] = true;
      m_kBlock.x2b[i] = rkBlock.x2b[i];
    }
  }
  const Thing08Block &block() const { return m_kBlock; }

private:
  bool m_fPresent00;
  bool m_fPresent01;
  bool m_fPresent02;
  bool m_fPresent03[16];
  Thing08Block m_kBlock;
};

#pragma pack(push,1)

struct Thing10Block {
  int32_t x00;
  int32_t x04;
  int32_t x08;
  int32_t x0c;
  int16_t x10;
  int16_t x12;
  int16_t x14[4];
  uint8_t x1c;
  uint8_t x1d;
  uint8_t pad[6];
};

#pragma pack(pop)

class Thing10LoadBlock {
public:
  void load( const Thing10Block &rkBlock ) {
    m_bfPresent00 = true;
    m_kBlock.x00 = rkBlock.x00;

    m_bfPresent04 = true;
    m_kBlock.x04 = rkBlock.x04;

    m_bfPresent08 = true;
    m_kBlock.x08 = rkBlock.x08;

    m_bfPresent0c = true;
    m_kBlock.x0c = rkBlock.x0c;

    m_bfPresent10 = true;
    m_kBlock.x10 = rkBlock.x10;

    m_bfPresent12 = true;
    m_kBlock.x12 = rkBlock.x12;

    for( int i = 0; i < 4; i++ ) {
      m_bfPresent14[i] = true;
      m_kBlock.x14[i] = rkBlock.x14[i];
    }

    m_bfPresent1c = true;
    m_kBlock.x1c = rkBlock.x1c;

    m_bfPresent1d = true;
    m_kBlock.x1d = rkBlock.x1d;
  }
  const Thing10Block &block() const { return m_kBlock; }

private:
  bool m_bfPresent00;
  bool m_bfPresent04;
  bool m_bfPresent08;
  bool m_bfPresent0c;
  bool m_bfPresent10;
  bool m_bfPresent12;
  bool m_bfPresent14[4];
  bool m_bfPresent1c;
  bool m_bfPresent1d;
  Thing10Block m_kBlock;
};

#pragma pack(push,1)

struct Thing03Block {
  int32_t pos[3];
  uint16_t x0c;
  uint8_t x0e; /* level */
  uint8_t x0f; /* likely flags */
  int32_t x10;
  int32_t x14;
  uint16_t x18;
  uint8_t id; /* 1a */
  uint8_t x1b; /* player id */
};

#pragma pack(pop)

/* 56f4d0 */
class Thing03LoadBlock {
public:
  Thing03LoadBlock();
  void load( const Thing03Block &rkBlock ); /* 56f540 */
  const Thing03Block &block() const { return m_kBlock; }

private:
  bool m_bIdPresent;
  bool m_bPosPresent;
  bool m_b1bPresent;
  bool m_b0cPresent;
  bool m_b0ePresent;
  bool m_b10Present;
  bool m_b14Present;
  bool m_b18Present;
  bool m_b0fPresent;
  Thing03Block m_kBlock;
};

#pragma pack(push,1)

struct Thing11Block {
  Thing11Block()
    : x00(0), x04(0), x08(0), x0c(0), x0e(0), x0f(0), x10(0), x12(0), x13(0) { }

  int32_t x00;
  int32_t x04;
  int32_t x08;
  int16_t x0c;
  uint8_t x0e;
  uint8_t x0f; /* maybe padding */
  int16_t x10;
  uint8_t x12;
  uint8_t x13;
};

#pragma pack(pop)

class Thing11LoadBlock {
public:
  Thing11LoadBlock() {
    m_bPresent[0] = false;
    m_bPresent[1] = false;
    m_bPresent[2] = false;
    m_bPresent[3] = false;
    m_bPresent[4] = false;
    m_bPresent[5] = false;
  }
  void load( const Thing11Block &rkBlock ) {
    m_kBlock = rkBlock;
    m_bPresent[0] = true;
    m_bPresent[1] = true;
    m_bPresent[2] = true;
    m_bPresent[3] = true;
    m_bPresent[4] = true;
    m_bPresent[5] = true;
  }
  const Thing11Block &block() const { return m_kBlock; }

private:
  bool m_bPresent[6];
  Thing11Block m_kBlock;
};

#pragma pack(push,1)

struct Thing12Block {
  Position3D x00;
  Position3D x0c;
  Position3D x18;
  int32_t x24;
  int32_t x28;
  int32_t x2c;
  int32_t x30;
  int32_t x34;
  int32_t x38;
  int32_t x3c;
  int32_t x40;
  int32_t x44;
  int32_t x48; /* flags */
  uint16_t x4c;
  uint16_t x4e;
  uint16_t x50;
  uint8_t x52;
};

#pragma pack(pop)

class Thing12LoadBlock {
public:
  void load( const Thing12Block &rkBlock );
  const Thing12Block &block() const { return m_kBlock; }

private:
  bool m_f00Present; /* 0 */
  bool m_f0cPresent;
  bool m_f18Present;
  bool m_f24Present;
  bool m_f28Present; /* 10 */
  bool m_f2cPresent;
  bool m_f30Present;
  bool m_f34Present;
  bool m_f38Present; /* 20 */
  bool m_f3cPresent;
  bool m_f40Present;
  bool m_f44Present;
  bool m_f48Present; /* 30 */
  bool m_f4cPresent;
  bool m_f4ePresent;
  bool m_f50Present;
  bool m_f52Present; /* 40 */
  Thing12Block m_kBlock; /* 44 */
};

#endif
