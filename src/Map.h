#ifndef MAP_H
#define MAP_H

class ElementLoadBlock {
public:
  ElementLoadBlock( uint8_t *pkBlock ) : x00(0), x01(0), x02(0), x03(0) {
    present[0] = true;
    x00 = pkBlock[0];
    present[1] = true;
    x01 = pkBlock[1];
    present[2] = true;
    x02 = pkBlock[2];
  }

public:
  bool present[3];
  uint8_t x00; /* c */
  uint8_t x01;
  uint8_t x02;
  uint8_t x03; /* padding */
};

#endif
