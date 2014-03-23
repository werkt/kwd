#ifndef CREATURE_SPELL_H
#define CREATURE_SPELL_H

struct CreatureSpellBlock {
  char name[32];
  uint8_t data[234];
};

class class_56a490 {
public:
  void sub_56a560( CreatureSpellBlock &rkBlock ) { /* unimplemented */ }

private:
  CreatureSpellBlock m_kBlock;
};

#endif
