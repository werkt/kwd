#include <string.h>

#include "KeeperSpell.h"

/* 56bab0 */
void
KeeperSpellLoadBlock::load( KeeperSpellBlock &rkBlock )
{
  m_bNamePresent = true;
  strncpy(m_kBlock.name, rkBlock.name, 32);
  m_kBlock.name[31] = '\0';
  
  m_bIdPresent = true;
  m_kBlock.id = rkBlock.id;

  m_bRef1Present = true;
  m_kBlock.ref1 = rkBlock.ref1;

  m_bRef3Present = true;
  m_kBlock.ref3 = rkBlock.ref3;

  m_b11CPresent = true;
  m_kBlock.x11c = rkBlock.x11c;

  m_bE2Present = true;
  m_kBlock.xe2 = rkBlock.xe2;

  m_bC8Present = true;
  m_kBlock.xc8 = rkBlock.xc8;

  m_bCCPresent = true;
  m_kBlock.xcc = rkBlock.xcc;

  m_bE4Present = true;
  m_kBlock.xe4 = rkBlock.xe4;

  m_bE6Present = true;
  m_kBlock.xe6 = rkBlock.xe6;

  m_bE8Present = true;
  m_kBlock.xe8 = rkBlock.xe8;

  m_bEAPresent = true;
  m_kBlock.xea = rkBlock.xea;

  m_bECPresent = true;
  m_kBlock.xec = rkBlock.xec;

  m_bEFPresent = true;
  m_kBlock.xef = rkBlock.xef;

  m_bDAPresent = true;
  m_kBlock.xda = rkBlock.xda;

  m_bF0Present = true;
  m_kBlock.xf0 = rkBlock.xf0;

  m_bD0Present = true;
  m_kBlock.xd0 = rkBlock.xd0;

  m_bD4Present = true;
  m_kBlock.xd4 = rkBlock.xd4;

  m_bRef2Present = true;
  m_kBlock.ref2 = rkBlock.ref2;

  m_b111Present = true;
  m_kBlock.x111 = rkBlock.x111;

  m_b113Present = true;
  m_kBlock.x113 = rkBlock.x113;

  m_b114Present = true;
  m_kBlock.x114 = rkBlock.x114;

  m_b118Present = true;
  m_kBlock.x118 = rkBlock.x118;

  m_bD8Present = true;
  m_kBlock.xd8 = rkBlock.xd8;

  m_bYNamePresent = true;
  strncpy(m_kBlock.yname, rkBlock.yname, 32);
  m_kBlock.yname[31] = '\0';

  m_bNamePresent = true;
  strncpy(m_kBlock.xname, rkBlock.xname, 32);
  m_kBlock.xname[31] = '\0';

  m_bDBPresent = true;
  m_kBlock.xdb = rkBlock.xdb;

  m_b194Present = true;
  m_kBlock.x194 = rkBlock.x194;

  m_b195Present = true;
  m_kBlock.x195 = rkBlock.x195;

  m_bDCPresent = true;
  m_kBlock.xdc |= rkBlock.xdc;
}
