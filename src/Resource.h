#ifndef RESOURCE_H
#define RESOURCE_H

#include <stdint.h>

#pragma pack(push, 1)

struct ArtResourceSettings {
  uint32_t flags; /* 0 */
  union {
    struct {
      uint32_t width; /* fixed */
      uint32_t height; /* fixed */
      int16_t frames;
    } image;
    struct {
      int32_t scale; /* fixed */
      uint16_t frames;
    } mesh;
    struct {
      uint32_t frames; /* 4 */
      uint32_t fps; /* 8 */
      uint16_t start_dist; /* c */
      uint16_t end_dist; /* e */
    } anim;
    struct {
      uint32_t id;
    } proc;
    struct {
      uint32_t x00;
      uint32_t x04;
      uint8_t frames;
    } terrain;
  } data;
  uint8_t type; /* 10 */
  uint8_t start_af; /* 11 */
  uint8_t end_af; /* 12 */
  uint8_t sometimes_one; /* 13 */
};

struct ArtResource {
  char name[64];
  ArtResourceSettings settings;
};

struct StringIds {
  uint32_t ids[5];
  uint8_t x14[4];
};

#pragma pack(pop)

#endif
