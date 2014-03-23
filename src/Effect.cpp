#include <string.h>

#include "Effect.h"

void
EffectLoadBlock::load( EffectBlock &rkBlock )
{
  m_fNamePresent = true;
  strncpy(m_kBlock.m_sName, rkBlock.m_sName, 32);
  m_kBlock.m_sName[31] = '\0';

  m_fIdPresent = true;
  m_kBlock.m_wId = rkBlock.m_wId;

  m_fArtResourcePresent = true;
  m_kBlock.m_kArtResource = rkBlock.m_kArtResource;

  m_fLightPresent = true;
  m_kBlock.m_kLight = rkBlock.m_kLight;

  m_fMassPresent = true;
  m_kBlock.mass = rkBlock.mass;

  m_fMinHpPresent = true; /* 14 */
  m_kBlock.min_hp = rkBlock.min_hp;

  m_fMaxHpPresent = true; /* 18 */
  m_kBlock.max_hp = rkBlock.max_hp;

  m_fRadiusPresent = true; /* 10 */
  m_kBlock.radius = rkBlock.radius;

  m_fUnknown1Present = true; /* 44 */
  m_kBlock.unknown1 = rkBlock.unknown1;

  m_fMinSpeedXYPresent = true; /* 20 */
  m_kBlock.min_speed_xy = rkBlock.min_speed_xy;

  m_fMaxSpeedXYPresent = true; /* 24 */
  m_kBlock.max_speed_xy = rkBlock.max_speed_xy;

  m_fMinSpeedYZPresent = true; /* 28 */
  m_kBlock.min_speed_yz = rkBlock.min_speed_yz;

  m_fMaxSpeedYZPresent = true; /* 2c */
  m_kBlock.max_speed_yz = rkBlock.max_speed_yz;

  m_fMinScalePresent = true; /* 30 */
  m_kBlock.min_scale = rkBlock.min_scale;

  m_fMaxScalePresent = true; /* 34 */
  m_kBlock.max_scale = rkBlock.max_scale;

  m_fAirFrictionPresent = true; /* 38 */
  m_kBlock.air_friction = rkBlock.air_friction;

  m_fElasticityPresent = true; /* 3c */
  m_kBlock.elasticity = rkBlock.elasticity;

  m_fElementsPerTurnPresent = true; /* 48 */
  m_kBlock.elements_per_turn = rkBlock.elements_per_turn;

  m_fNextEffectPresent = true; /* 40 */
  m_kBlock.next_effect = rkBlock.next_effect;

  m_fDeathElementPresent = true; /* 50 */
  m_kBlock.death_effect = rkBlock.death_effect;

  m_fHitSolidElementPresent = true; /* 54 */
  m_kBlock.hit_solid_effect = rkBlock.hit_solid_effect;

  m_fHitWaterElementPresent = true; /* 58 */
  m_kBlock.hit_water_effect = rkBlock.hit_water_effect;

  m_fHitLavaElementPresent = true;  /* 5c */
  m_kBlock.hit_lava_effect = rkBlock.hit_lava_effect;

  m_fFadeDurationPresent = true; /* b0 */
  m_kBlock.fade_duration = rkBlock.fade_duration;

  m_fFlagsPresent = true; /* 4c */
  m_kBlock.flags = rkBlock.flags;

  for( int i = 0; i < 8; i++ ) {
    m_fGenerateIdsPresent[i] = true;
    m_kBlock.generate_ids[i] = rkBlock.generate_ids[i];
  }

  for( int i = 0; i < 12; i++ ) {
    m_fGenerationDataPresent[i] = true;
    m_kBlock.generation_data[i] = rkBlock.generation_data[i];
  }
}
