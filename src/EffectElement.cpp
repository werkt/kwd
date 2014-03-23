#include <string.h>

#include "EffectElement.h"

void
EffectElementLoadBlock::load( EffectElementBlock &rkBlock )
{
  m_fNamePresent = true;
  strncpy(m_kBlock.m_sName, rkBlock.m_sName, 32);
  m_kBlock.m_sName[31] = '\0';

  m_fIdPresent = true;
  m_kBlock.m_wId = rkBlock.m_wId;

  m_fArtResourcePresent = true;
  m_kBlock.m_kArtResource = rkBlock.m_kArtResource;

  m_fMinHpPresent = true;
  m_kBlock.min_hp = rkBlock.min_hp;

  m_fMaxHpPresent = true;
  m_kBlock.max_hp = rkBlock.max_hp;

  m_fMassPresent = true;
  m_kBlock.mass = rkBlock.mass;

  m_fAirFrictionPresent = true;
  m_kBlock.air_friction = rkBlock.air_friction;

  m_fElasticityPresent = true;
  m_kBlock.elasticity = rkBlock.elasticity;

  m_fMinScalePresent = true;
  m_kBlock.min_scale = rkBlock.min_scale;

  m_fMaxScalePresent = true;
  m_kBlock.max_scale = rkBlock.max_scale;

  m_fMinSpeedXYPresent = true;
  m_kBlock.min_speed_xy = rkBlock.min_speed_xy;

  m_fMaxSpeedXYPresent = true;
  m_kBlock.max_speed_xy = rkBlock.max_speed_xy;

  m_fMinSpeedYZPresent = true;
  m_kBlock.min_speed_yz = rkBlock.min_speed_yz;

  m_fMaxSpeedYZPresent = true;
  m_kBlock.max_speed_yz = rkBlock.max_speed_yz;

  m_fScaleRatioPresent = true;
  m_kBlock.scale_ratio = rkBlock.scale_ratio;

  m_fNextEffectPresent = true;
  m_kBlock.next_effect = rkBlock.next_effect;

  m_fDeathElementPresent = true;
  m_kBlock.death_element = rkBlock.death_element;

  m_fHitSolidElementPresent = true;
  m_kBlock.hit_solid_element = rkBlock.hit_solid_element;

  m_fHitWaterElementPresent = true;
  m_kBlock.hit_water_element = rkBlock.hit_water_element;

  m_fHitLavaElementPresent = true;
  m_kBlock.hit_lava_element = rkBlock.hit_lava_element;

  m_fRandomColorIndexPresent = true;
  m_kBlock.random_color_index = rkBlock.random_color_index;

  m_fTableColorIndexPresent = true;
  m_kBlock.table_color_index = rkBlock.table_color_index;

  m_fColorRedPresent = true;
  m_kBlock.color[0] = rkBlock.color[0];

  m_fColorGreenPresent = true;
  m_kBlock.color[1] = rkBlock.color[1];

  m_fColorBluePresent = true;
  m_kBlock.color[2] = rkBlock.color[2];

  m_fFadePercentagePresent = true;
  m_kBlock.fade_percentage = rkBlock.fade_percentage;

  m_fFlagsPresent = true;
  m_kBlock.flags = rkBlock.flags;
}
