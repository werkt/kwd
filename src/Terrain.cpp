#include <string.h>

#include "Terrain.h"

void
TerrainLoadBlock::load( TerrainBlock &rkBlock )
{
  m_fIdPresent = true;
  m_kBlock.id = rkBlock.id;

  m_fStartingHealthPresent = true;
  m_kBlock.starting_health = rkBlock.starting_health;

  m_fMaxHealthPresent = true;
  m_kBlock.max_health = rkBlock.max_health;
  m_fUnknown188Present = true;
  m_kBlock.unk188 = rkBlock.unk188;
  m_fDamagePresent = true;
  m_kBlock.damage = rkBlock.damage;
  m_fUnknown196Present = true;
  m_kBlock.unk196 = rkBlock.unk196;
  m_fUnknown198Present = true;
  m_kBlock.unk198 = rkBlock.unk198;
  m_fMaxHealthTypePresent = true;
  m_kBlock.max_health_type = rkBlock.max_health_type;
  m_fDestroyedTypePresent = true;
  m_kBlock.destroyed_type = rkBlock.destroyed_type;

  m_fNamePresent = true;
  strncpy(m_kBlock.name, rkBlock.name, 32);
  m_kBlock.name[31] = '\0';

  m_fCompletePresent = true;
  m_kBlock.complete = rkBlock.complete;
  m_fSidePresent = true;
  m_kBlock.side = rkBlock.side;
  m_fTopPresent = true;
  m_kBlock.top = rkBlock.top;
  m_fTaggedPresent = true;
  m_kBlock.tagged = rkBlock.tagged;

  m_fManaGainPresent = true;
  m_kBlock.max_mana_gain = rkBlock.max_mana_gain;
  m_fMaxManaGainPresent = true;
  m_kBlock.gold_value = rkBlock.gold_value;
  m_fGoldValuePresent = true;
  m_kBlock.unk1a0 = rkBlock.unk1a0;
  m_fUnknown1a0Present = true;
  m_kBlock.unk1a2 = rkBlock.unk1a2;
  m_fUnknown1a2Present = true;
  m_kBlock.unk1a8 = rkBlock.unk1a8;
  m_fUnknown1a8Present = true;
  m_kBlock.unk1aa = rkBlock.unk1aa;
  m_fUnknown1aaPresent = true;
  m_kBlock.unk1ac = rkBlock.unk1ac;
  m_fUnknown1acPresent = true;
  m_kBlock.unk1a4 = rkBlock.unk1a4;
  m_fUnknown1a4Present = true;
  m_kBlock.unk1a6 = rkBlock.unk1a6;
  m_fUnknown1a6Present = true;
  m_kBlock.wibble_h = rkBlock.wibble_h;
  m_fWibbleVPresent = true;
  m_kBlock.wibble_v = rkBlock.wibble_v;
  m_fWibbleHPresent = true;
  m_kBlock.terrain_light[0] = rkBlock.terrain_light[0];
  m_fTerrainLightRPresent = true;
  m_kBlock.terrain_light[1] = rkBlock.terrain_light[1];
  m_fTerrainLightGPresent = true;
  m_kBlock.terrain_light[2] = rkBlock.terrain_light[2];
  m_fTerrainLightBPresent = true;
  m_kBlock.unk224 = rkBlock.unk224;
  m_fUnknown224Present = true;
  m_kBlock.ambient_light[0] = rkBlock.ambient_light[0];
  m_fAmbientLightRPresent = true;
  m_kBlock.ambient_light[1] = rkBlock.ambient_light[1];
  m_fAmbientLightGPresent = true;
  m_kBlock.ambient_light[2] = rkBlock.ambient_light[2];
  m_fAmbientLightBPresent = true;
  m_kBlock.light_height = rkBlock.light_height;
  m_fLightHeightPresent = true;
  m_kBlock.texture_frames = rkBlock.texture_frames;
  m_fTextureFramesPresent = true;
  
  m_fStringIdsPresent = true;
  m_kBlock.string_ids = rkBlock.string_ids;
  m_fFlagsPresent = true; /* with the funky or-ing */
  m_kBlock.flags = rkBlock.flags;
  m_fString1Present = true; /* strncpy */
  strncpy(m_kBlock.str1, rkBlock.str1, 32);
  m_kBlock.str1[31] = '\0';
  m_fString2Present = true; /* strncpy */
  strncpy(m_kBlock.str2, rkBlock.str2, 32);
  m_kBlock.str2[31] = '\0';

  for( int i = 0; i < 16; i++ ) {
    m_fUnknown1aePresent = true; /* yes, only one, set in the loop */
    m_kBlock.unk1ae[i] = rkBlock.unk1ae[i];
  }

  for( int i = 0; i < 3; i++ ) {
    m_fLeanHPresent[i] = true;
    m_kBlock.lean_h[i] = rkBlock.lean_h[i];
  }
  for( int i = 0; i < 3; i++ ) {
    m_fLeanVPresent[i] = true;
    m_kBlock.lean_v[i] = rkBlock.lean_v[i];
  }
}

