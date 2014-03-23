#include "Thing.h"

Thing03LoadBlock::Thing03LoadBlock()
  : m_bIdPresent(false), m_bPosPresent(false), m_b1bPresent(false),
    m_b0cPresent(false), m_b0ePresent(false), m_b10Present(false),
    m_b14Present(false), m_b18Present(false), m_b0fPresent(false)
{
  memset(&m_kBlock, '\0', sizeof(m_kBlock));
}

void
Thing03LoadBlock::load( const Thing03Block &rkBlock )
{
  m_bIdPresent = true;
  m_kBlock.id = rkBlock.id;

  m_bPosPresent = true;
  memcpy(m_kBlock.pos, rkBlock.pos, sizeof(m_kBlock.pos));

  m_b1bPresent = true;
  m_kBlock.x1b = rkBlock.x1b;

  m_b0cPresent = true;
  m_kBlock.x0c = rkBlock.x0c;

  m_b0ePresent = true;
  m_kBlock.x0e = rkBlock.x0e;

  m_b10Present = true;
  m_kBlock.x10 = rkBlock.x10;

  m_b14Present = true;
  m_kBlock.x14 = rkBlock.x14;

  m_b18Present = true;
  m_kBlock.x18 = rkBlock.x18;

  m_b0fPresent = true;
  m_kBlock.x0f |= rkBlock.x0f;
}

void
Thing12LoadBlock::load( const Thing12Block &rkBlock )
{
  m_f00Present = true;
  m_kBlock.x00 = rkBlock.x00;

  m_f0cPresent = true;
  m_kBlock.x0c = rkBlock.x0c;

  m_f18Present = true;
  m_kBlock.x18 = rkBlock.x18;

  m_f24Present = true;
  m_kBlock.x24 = rkBlock.x24;

  m_f28Present = true;
  m_kBlock.x28 = rkBlock.x28;

  m_f2cPresent = true;
  m_kBlock.x2c = rkBlock.x2c;

  m_f30Present = true;
  m_kBlock.x30 = rkBlock.x30;

  m_f34Present = true;
  m_kBlock.x34 = rkBlock.x34;

  m_f38Present = true;
  m_kBlock.x38 = rkBlock.x38;

  m_f3cPresent = true;
  m_kBlock.x3c = rkBlock.x3c;

  m_f40Present = true;
  m_kBlock.x40 = rkBlock.x40;

  m_f44Present = true;
  m_kBlock.x44 = rkBlock.x44;

  m_f48Present = true;
  m_kBlock.x48 = rkBlock.x48;

  m_f4cPresent = true;
  m_kBlock.x4c = rkBlock.x4c;

  m_f4ePresent = true;
  m_kBlock.x4e = rkBlock.x4e;

  m_f50Present = true;
  m_kBlock.x50 = rkBlock.x50;

  m_f52Present = true;
  m_kBlock.x52 = rkBlock.x52;
}

void
ActionPointLoadBlock::load( const ActionPointBlock &rkBlock )
{
  m_fIdPresent = true;
  m_kBlock.id = rkBlock.id;

  m_fNamePresent = true;
  strncpy(m_kBlock.name, rkBlock.name, sizeof(m_kBlock.name));
  m_kBlock.name[31] = '\0';

  m_f14Present = true;
  m_kBlock.x14 = rkBlock.x14;

  m_f17Present = true;
  m_kBlock.x17 = rkBlock.x17;

  m_f10Present = true;
  m_kBlock.x10 = rkBlock.x10;

  if( rkBlock.x08 ) {
    m_f00Present = true;
    m_kBlock.x00 = rkBlock.x00;

    m_f04Present = true;
    m_kBlock.x04 = rkBlock.x04;

    m_f08Present = true;
    m_kBlock.x08 = rkBlock.x08;

    m_f0cPresent = true;
    m_kBlock.x0c = rkBlock.x0c;
  } else {
    m_f00Present = true;
    m_kBlock.x00 = rkBlock.x00 - rkBlock.x0c;

    m_f04Present = true;
    m_kBlock.x04 = rkBlock.x04 - rkBlock.x0c;

    m_f08Present = true;
    m_kBlock.x08 = rkBlock.x00 + rkBlock.x0c;

    m_f0cPresent = true;
    m_kBlock.x0c = rkBlock.x04 + rkBlock.x0c;
  }
}

