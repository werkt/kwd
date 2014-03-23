#ifndef TERRAIN_H
#define TERRAIN_H

#include "Resource.h"

#pragma pack(push,1)

struct TerrainBlock {
  char name[32]; /* 0 */
  ArtResource complete; /* 20 */
  ArtResource side; /* 74 */
  ArtResource top; /* c8 */
  ArtResource tagged; /* 11c */
  StringIds string_ids; /* 170 */
  uint32_t unk188; /* 188 */
  uint32_t light_height; /* 18c */
  uint32_t flags; /* 190 */
  uint16_t damage; /* 194 */
  uint16_t unk196; /* 196 */
  uint16_t unk198; /* 198 */
  uint16_t gold_value; /* 19a */
  uint16_t mana_gain; /* 19c */
  uint16_t max_mana_gain; /* 19e */
  uint16_t unk1a0; /* 1a0 */
  uint16_t unk1a2; /* 1a2 */
  uint16_t unk1a4; /* 1a4 */
  uint16_t unk1a6; /* 1a6 */
  uint16_t unk1a8; /* 1a8 */
  uint16_t unk1aa; /* 1aa */
  uint16_t unk1ac; /* 1ac */
  uint16_t unk1ae[16]; /* 1ae */
  uint8_t wibble_h; /* 1ce */
  uint8_t lean_h[3]; /* 1cf */
  uint8_t wibble_v; /* 1d2 */
  uint8_t lean_v[3]; /* 1d3 */
  uint8_t id; /* 1d6 */
  uint16_t starting_health; /* 1d7 */
  uint8_t max_health_type; /* 1d9 */
  uint8_t destroyed_type; /* 1da */
  uint8_t terrain_light[3]; /* 1db */
  uint8_t texture_frames; /* 1de */
  char str1[32]; /* 1df */
  uint16_t max_health; /* 1ff */
  uint8_t ambient_light[3]; /* 201 */
  char str2[32]; /* 204 */
  uint32_t unk224; /* 224 */
};

#pragma pack(pop)

class TerrainLoadBlock {
public:
  void load( TerrainBlock &rkBlock );
  const TerrainBlock &block() const { return m_kBlock; }

  bool m_fNamePresent; /* 0 */
  bool m_fIdPresent; /* 4 */
  bool m_fString1Present; /* 8 */
  bool m_fString2Present; /* c */
  bool m_fCompletePresent; /* 10 */
  bool m_fSidePresent; /* 14 */
  bool m_fTopPresent; /* 18 */
  bool m_fTaggedPresent; /* 1c */
  bool m_fStringIdsPresent; /* 20 */
  bool m_fUnknown188Present; /* 24 */
  bool m_fDamagePresent; /* 28 */
  bool m_fUnknown196Present; /* 2c */
  bool m_fUnknown198Present; /* 30 */
  bool m_fManaGainPresent; /* 34 */
  bool m_fMaxManaGainPresent; /* 38 */
  bool m_fGoldValuePresent; /* 3c */
  bool m_fUnknown1a0Present; /* 40 */
  bool m_fUnknown1a2Present; /* 44 */
  bool m_fUnknown1a8Present; /* 48 */
  bool m_fUnknown1aaPresent; /* 4c */
  bool m_fUnknown1acPresent; /* 50 */
  bool m_fWibbleHPresent; /* 54 */
  bool m_fLeanHPresent[3]; /* 58 */
  bool m_fWibbleVPresent; /* 64 */
  bool m_fLeanVPresent[3]; /* 68 */
  bool m_fStartingHealthPresent; /* 74 */
  bool m_fMaxHealthPresent; /* 78 */
  bool m_fMaxHealthTypePresent; /* 7c */
  bool m_fDestroyedTypePresent; /* 80 */
  bool m_fUnknown1a4Present; /* 84 */
  bool m_fUnknown1a6Present; /* 88 */
  bool m_fTerrainLightRPresent; /* 8c */
  bool m_fTerrainLightGPresent; /* 90 */
  bool m_fTerrainLightBPresent; /* 94 */
  bool m_fUnknown224Present; /* 98 */
  bool m_fAmbientLightRPresent; /* 9c */
  bool m_fAmbientLightGPresent; /* a0 */
  bool m_fAmbientLightBPresent; /* a4 */
  bool m_fLightHeightPresent; /* a8 */
  bool m_fTextureFramesPresent; /* ac */
  bool m_fFlagsPresent; /* b0 */
  bool m_fUnknown1aePresent; /* b4 */
  TerrainBlock m_kBlock; /* b8 */
};

#endif
