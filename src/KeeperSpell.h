#ifndef KEEPER_SPELL_H
#define KEEPER_SPELL_H

#include "Resource.h"

#pragma pack(push,1)

struct KeeperSpellBlock {
  char name[32];
  ArtResource ref1;
  ArtResource ref3;
  int xc8;
  int xcc;
  int xd0;
  int xd4;
  uint16_t xd8;
  uint8_t xda;
  uint8_t xdb;
  int xdc;
  uint16_t xe0Unreferenced; /* e0 */
  uint16_t xe2;
  uint16_t xe4;
  uint16_t xe6;
  uint16_t xe8;
  uint16_t xea;
  uint16_t xec;
  uint8_t id; /* ee */
  uint8_t xef;
  uint8_t xf0;
  char yname[32]; /* xf1 */
  uint16_t x111;
  uint8_t x113;
  int x114;
  int x118;
  int x11c;
  ArtResource ref2; /* 120 */
  char xname[32]; /* 174 */
  uint8_t x194;
  uint8_t x195;
};

#pragma pack(pop)

/* 56b990 */
class KeeperSpellLoadBlock {
public:
  void load( KeeperSpellBlock &rkBlock ); /* 56bab0 */
  const KeeperSpellBlock &block() const { return m_kBlock; }
  bool hasName() const { return m_bNamePresent; }
  bool hasId() const { return m_bIdPresent; }
  bool hasYName() const { return m_bYNamePresent; }
  bool hasXName() const { return m_bXNamePresent; }
  bool hasRef1() const { return m_bRef1Present; }
  bool hasRef3() const { return m_bRef3Present; }
  bool hasC8() const { return m_bC8Present; }
  bool hasCC() const { return m_bCCPresent; }
  bool hasF0() const { return m_bF0Present; }
  bool hasD0() const { return m_bD0Present; }
  bool hasD4() const { return m_bD4Present; }
  bool hasRef2() const { return m_bRef2Present; }
  bool has111() const { return m_b111Present; }
  bool has113() const { return m_b113Present; }
  bool has114() const { return m_b114Present; }
  bool has118() const { return m_b118Present; }
  bool has11C() const { return m_b11CPresent; }
  bool hasE2() const { return m_bE2Present; }
  bool hasE4() const { return m_bE4Present; }
  bool hasE6() const { return m_bE6Present; }
  bool hasE8() const { return m_bE8Present; }
  bool hasEA() const { return m_bEAPresent; }
  bool hasEC() const { return m_bECPresent; }
  bool hasD8() const { return m_bD8Present; }
  bool hasEF() const { return m_bEFPresent; }
  bool hasDA() const { return m_bDAPresent; }
  bool has194() const { return m_b194Present; }
  bool has195() const { return m_b195Present; }
  bool hasDB() const { return m_bDBPresent; }
  bool hasDC() const { return m_bDCPresent; }

private:
  bool m_bNamePresent;
  bool m_bIdPresent;
  bool m_bYNamePresent;
  bool m_bXNamePresent;
  bool m_bRef1Present; /* 10 */
  bool m_bRef3Present; /* 14 */
  bool m_bC8Present; /* 18 */
  bool m_bCCPresent; /* 1c */
  bool m_bF0Present; /* 20 */
  bool m_bD0Present; /* 24 */
  bool m_bD4Present; /* 28 */
  bool m_bRef2Present; /* 2c */
  bool m_b111Present; /* 30 */
  bool m_b113Present; /* 34 */
  bool m_b114Present; /* 38 */
  bool m_b118Present; /* 3c */
  bool m_b11CPresent; /* 40 */
  bool m_bE2Present; /* 44 */
  bool m_bE4Present; /* 48 */
  bool m_bE6Present; /* 4c */
  bool m_bE8Present; /* 50 */
  bool m_bEAPresent; /* 54 */
  bool m_bECPresent; /* 58 */
  bool m_bD8Present; /* 5c */
  bool m_bEFPresent; /* 60 */
  bool m_bDAPresent; /* 64 */
  bool m_b194Present; /* 68 */
  bool m_b195Present; /* 6c */
  bool m_bDBPresent; /* 70 */
  bool m_bDCPresent; /* 74 */
  KeeperSpellBlock m_kBlock;
};

#endif
