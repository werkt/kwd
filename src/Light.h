#ifndef LIGHT_H
#define LIGHT_H

struct LightBlock {
  int m_kPos[3]; /* 0x1000 = 1.0 */
  unsigned int radius; /* same */
  unsigned int flags; /* 10 */
  unsigned char color[4]; /* bgr? */
};

#endif
