#ifndef EFFECT_ELEMENT_H
#define EFFECT_ELEMENT_H

#include "Resource.h"

#pragma pack(push, 1)

struct EffectElementBlock {
  char m_sName[32];
  ArtResource m_kArtResource;
  int32_t mass; /* 74 */
  uint32_t air_friction; /* 78 */
  uint32_t elasticity; /* 7c */
  int32_t min_speed_xy; /* 80 */
  int32_t max_speed_xy; /* 84 */
  int32_t min_speed_yz; /* 88 says it's yz, but appears to only be Z */
  int32_t max_speed_yz; /* 8c z speed at end */
  uint32_t min_scale; /* 90 */
  uint32_t max_scale; /* 94 */
  uint32_t scale_ratio; /* 98 */
  uint32_t flags; /* 9c */
  uint16_t m_wId; /* a0 */
  uint16_t min_hp; /* a2 */
  uint16_t max_hp; /* a4 */
  uint16_t death_element; /* a6 */
  uint16_t hit_solid_element; /* a8 */
  uint16_t hit_water_element; /* aa */
  uint16_t hit_lava_element; /* ac */
  uint8_t color[3]; /* ae */
  uint8_t random_color_index; /* b1 */
  uint8_t table_color_index; /* b2 */
  uint8_t fade_percentage; /* b3 */
  uint16_t next_effect; /* b4 */
};

#pragma pack(pop)

class EffectElementLoadBlock {
public:
  EffectElementLoadBlock() { }
  void load( EffectElementBlock &rkBlock );
  bool hasId() const { return m_fIdPresent; }
  bool hasArtResource() const { return m_fArtResourcePresent; }
  bool hasMinHp() const { return m_fMinHpPresent; } /* c */
  bool hasMaxHp() const { return m_fMaxHpPresent; } /* 10 */
  bool hasMass() const { return m_fMassPresent; } /* 14 */
  bool hasAirFriction() const { return m_fAirFrictionPresent; } /* 18 */
  bool hasElasticity() const { return m_fElasticityPresent; } /* 1c */
  bool hasMinScale() const { return m_fMinScalePresent; } /* 20 */
  bool hasMaxScale() const { return m_fMaxScalePresent; } /* 24 */
  bool hasScaleRatio() const { return m_fScaleRatioPresent; } /* 28 */
  bool hasMinSpeedXY() const { return m_fMinSpeedXYPresent; } /* 2c */
  bool hasMaxSpeedXY() const { return m_fMaxSpeedXYPresent; } /* 30 */
  bool hasMinSpeedYZ() const { return m_fMinSpeedYZPresent; } /* 34 */
  bool hasMaxSpeedYZ() const { return m_fMaxSpeedYZPresent; } /* 38 */
  bool hasFlags() const { return m_fFlagsPresent; } /* 3c */
  bool hasColorRed() const { return m_fColorRedPresent; } /* 40 */
  bool hasColorGreen() const { return m_fColorGreenPresent; } /* 44 */
  bool hasColorBlue() const { return m_fColorBluePresent; } /* 48 */
  bool hasNextEffect() const { return m_fNextEffectPresent; } /* 4c */
  bool hasDeathElement() const { return m_fDeathElementPresent; } /* 50 */
  bool hasHitSolidElement() const { return m_fHitSolidElementPresent; } /* 54 */
  bool hasHitWaterElement() const { return m_fHitWaterElementPresent; } /* 58 */
  bool hasHitLavaElement() const { return m_fHitLavaElementPresent; }  /* 5c */
  bool hasRandomColorIndex() const { return m_fRandomColorIndexPresent; } /* 60 */
  bool hasTableColorIndex() const { return m_fTableColorIndexPresent; } /* 64 */
  bool hasFadePercentage() const { return m_fFadePercentagePresent; } /* 68 */

  uint16_t id() const { return m_kBlock.m_wId; }
  const ArtResource &artResource() const { return m_kBlock.m_kArtResource; }
  int minHp() const { return m_kBlock.min_hp; } /* c */
  int maxHp() const { return m_kBlock.max_hp; } /* 10 */
  int mass() const { return m_kBlock.mass; } /* 14 */
  int airFriction() const { return m_kBlock.air_friction; } /* 18 */
  int elasticity() const { return m_kBlock.elasticity; } /* 1c */
  int minScale() const { return m_kBlock.min_scale; } /* 20 */
  int maxScale() const { return m_kBlock.max_scale; } /* 24 */
  int scaleRatio() const { return m_kBlock.scale_ratio; } /* 28 */
  int minSpeedXY() const { return m_kBlock.min_speed_xy; } /* 2c */
  int maxSpeedXY() const { return m_kBlock.max_speed_xy; } /* 30 */
  int minSpeedYZ() const { return m_kBlock.min_speed_yz; } /* 34 */
  int maxSpeedYZ() const { return m_kBlock.max_speed_yz; } /* 38 */
  int flags() const { return m_kBlock.flags; } /* 3c */
  int colorRed() const { return m_kBlock.color[0]; } /* 40 */
  int colorGreen() const { return m_kBlock.color[1]; } /* 44 */
  int colorBlue() const { return m_kBlock.color[2]; } /* 48 */
  int nextEffect() const { return m_kBlock.next_effect; } /* 4c */
  int deathElement() const { return m_kBlock.death_element; } /* 50 */
  int hitSolidElement() const { return m_kBlock.hit_solid_element; } /* 54 */
  int hitWaterElement() const { return m_kBlock.hit_water_element; } /* 58 */
  int hitLavaElement() const { return m_kBlock.hit_lava_element; }  /* 5c */
  int randomColorIndex() const { return m_kBlock.random_color_index; } /* 60 */
  int tableColorIndex() const { return m_kBlock.table_color_index; } /* 64 */
  int fadePercentage() const { return m_kBlock.fade_percentage; } /* 68 */

private:
  bool m_fNamePresent;
  bool m_fIdPresent;
  bool m_fArtResourcePresent;
  bool m_fMinHpPresent; /* c */
  bool m_fMaxHpPresent; /* 10 */
  bool m_fMassPresent; /* 14 */
  bool m_fAirFrictionPresent; /* 18 */
  bool m_fElasticityPresent; /* 1c */
  bool m_fMinScalePresent; /* 20 */
  bool m_fMaxScalePresent; /* 24 */
  bool m_fScaleRatioPresent; /* 28 */
  bool m_fMinSpeedXYPresent; /* 2c */
  bool m_fMaxSpeedXYPresent; /* 30 */
  bool m_fMinSpeedYZPresent; /* 34 */
  bool m_fMaxSpeedYZPresent; /* 38 */
  bool m_fFlagsPresent; /* 3c */
  bool m_fColorRedPresent; /* 40 */
  bool m_fColorGreenPresent; /* 44 */
  bool m_fColorBluePresent; /* 48 */
  bool m_fNextEffectPresent; /* 4c */
  bool m_fDeathElementPresent; /* 50 */
  bool m_fHitSolidElementPresent; /* 54 */
  bool m_fHitWaterElementPresent; /* 58 */
  bool m_fHitLavaElementPresent;  /* 5c */
  bool m_fRandomColorIndexPresent; /* 60 */
  bool m_fTableColorIndexPresent; /* 64 */
  bool m_fFadePercentagePresent; /* 68 */
  EffectElementBlock m_kBlock;
};

#endif
