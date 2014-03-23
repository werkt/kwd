#ifndef PLAYER_H
#define PLAYER_H

#pragma pack(push,1)

/* cd in size */
struct PlayerBlock {
  int x00;
  int x04;
  uint8_t x08[158];
  uint16_t xa6;
  uint8_t xa8;
  uint16_t xa9;
  uint16_t xab;
  char name[32]; /* ad */
};

#pragma pack(pop)

class PlayerLoadBlock {
public:
  /* should theoretically zero everything */
  void load( PlayerBlock &block ) {
    m_kBlock = block;
    present[0] = true;
    present[1] = true;
    present[2] = true;
    present[3] = true;
    present[4] = true;
    present[5] = true;
    present[6] = true;
    present[7] = true;
  }
  const PlayerBlock &block() const { return m_kBlock; }

private:
  bool present[8]; /* to be examined on load */
  PlayerBlock m_kBlock;
};

#endif
