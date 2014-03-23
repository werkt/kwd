#ifndef TRIGGER_H
#define TRIGGER_H

#pragma pack(push,1)

struct TriggerBlock {
  int x00;
  int x04;
  uint16_t x08;
  uint16_t x0a;
  uint16_t x0c;
  uint8_t x0e;
  uint8_t x0f;
};

#pragma pack(pop)

class TriggerLoadBlock {
public:
  TriggerLoadBlock()
    : m_bPresent0(false), m_bPresent1(false), m_bPresent2(false),
      m_bPresent3(false), m_bPresent4(false), m_bPresent5(false),
      m_bPresent6(false) { }
  const TriggerBlock &block() const { return m_kBlock; }
  void load( TriggerBlock &rkBlock ) {
    m_bPresent0 = true;
    m_bPresent1 = true;
    m_bPresent2 = true;
    m_bPresent3 = true;
    m_bPresent4 = true;
    m_bPresent5 = true;
    m_bPresent6 = true;
    m_kBlock.x00 = rkBlock.x00;
    m_kBlock.x04 = rkBlock.x04;
    m_kBlock.x08 = rkBlock.x08;
    m_kBlock.x0a = rkBlock.x0a;
    m_kBlock.x0c = rkBlock.x0c;
    m_kBlock.x0e = rkBlock.x0e;
    m_kBlock.x0f = rkBlock.x0f;
  }

private:
  bool m_bPresent0;
  bool m_bPresent1;
  bool m_bPresent2;
  bool m_bPresent3;
  bool m_bPresent4;
  bool m_bPresent5;
  bool m_bPresent6;
  TriggerBlock m_kBlock;
};

class TriggerActionLoadBlock {
public:
  TriggerActionLoadBlock()
    : m_bPresent0(false), m_bPresent1(false), m_bPresent2(false),
      m_bPresent3(false), m_bPresent4(false), m_bPresent5(false) { }
  const TriggerBlock &block() const { return m_kBlock; }
  void load( TriggerBlock &rkBlock ) {
    m_bPresent0 = true;
    m_bPresent1 = true;
    m_bPresent2 = true;
    m_bPresent3 = true;
    m_bPresent4 = true;
    m_bPresent5 = true;
    m_kBlock.x00 = rkBlock.x00;
    m_kBlock.x04 = rkBlock.x04;
    m_kBlock.x08 = rkBlock.x08;
    m_kBlock.x0a = rkBlock.x0a;
    m_kBlock.x0c = rkBlock.x0c;
    m_kBlock.x0e = rkBlock.x0e;
  }

private:
  bool m_bPresent0;
  bool m_bPresent1;
  bool m_bPresent2;
  bool m_bPresent3;
  bool m_bPresent4;
  bool m_bPresent5;
  TriggerBlock m_kBlock;
};

#endif
