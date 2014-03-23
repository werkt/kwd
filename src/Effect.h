#ifndef EFFECT_H
#define EFFECT_H

#include <stdbool.h>

#include "Resource.h"
#include "Light.h"

#pragma pack(push, 1)

struct EffectBlock {
  char m_sName[32];
  ArtResource m_kArtResource;
  LightBlock m_kLight;
  int32_t mass; /* 8c 0x1000 = 1.0 */
  uint32_t air_friction; /* 90 0x10000 = 1.0 */
  uint32_t elasticity; /* 94 0x10000 = 1.0 */
  uint32_t radius; /* 98 0x1000 = 1.0 */
  int32_t min_speed_xy; /* 9c same */
  int32_t max_speed_xy; /* a0 same */
  int32_t min_speed_yz; /* a4 same */
  int32_t max_speed_yz; /* a8 same */
  uint32_t min_scale; /* ac same */
  uint32_t max_scale; /* b0 same */
  uint32_t flags; /* b4 */
  uint16_t m_wId; /* b8 */
  uint16_t min_hp; /* ba number of particles emitted in sequence */
  uint16_t max_hp; /* bc */
  uint16_t fade_duration; /* be */
  /* might be a repeatable block */
  uint16_t next_effect; /* c0 */
  uint16_t death_effect; /* c2 */
  uint16_t hit_solid_effect; /* c4 */
  uint16_t hit_water_effect; /* c6 */
  uint16_t hit_lava_effect; /* c8 */
  uint16_t generate_ids[8]; /* ca elements or effects, depending on flags */
  uint16_t generation_data[12];
#if 0
  uint16_t outer_origin_range; /* da */
  uint16_t lower_height_limit; /* dc */
  uint16_t upper_height_limit; /* de */
  uint16_t orientation_range; /* e0 range of rotation */
  uint16_t sprite_spin_rate_range; /* e2 range of rotation speed */
  uint16_t whirlpool_rate; /* e4 */
  uint16_t directional_spread; /* e6 */
  uint16_t circular_path_rate; /* e8 possibly sin along path */
  uint16_t inner_origin_range; /* ea */
  uint16_t generate_randomness; /* ec */
  uint16_t misc[2]; /* ee */
#endif
  uint8_t unknown1; /* f2 */
  uint8_t elements_per_turn; /* f3 */
  uint16_t unknown3; /* f4 pad? */
};

#pragma pack(pop)

class EffectLoadBlock {
public:
  EffectLoadBlock() { }
  void load( EffectBlock &rkBlock );
  bool hasName() const { return m_fNamePresent; } /* 0 */
  bool hasId() const { return m_fIdPresent; } /* 4 */
  bool hasArtResource() const { return m_fArtResourcePresent; } /* 8 */
  bool hasLight() const { return m_fLightPresent; } /* c */
  bool hasRadius() const { return m_fRadiusPresent; } /* 10 */
  bool hasMinHp() const { return m_fMinHpPresent; } /* 14 */
  bool hasMaxHp() const { return m_fMaxHpPresent; } /* 18 */
  bool hasMass() const { return m_fMassPresent; } /* 1c */
  bool hasMinSpeedXY() const { return m_fMinSpeedXYPresent; } /* 20 */
  bool hasMaxSpeedXY() const { return m_fMaxSpeedXYPresent; } /* 24 */
  bool hasMinSpeedYZ() const { return m_fMinSpeedYZPresent; } /* 28 */
  bool hasMaxSpeedYZ() const { return m_fMaxSpeedYZPresent; } /* 2c */
  bool hasMinScale() const { return m_fMinScalePresent; } /* 30 */
  bool hasMaxScale() const { return m_fMaxScalePresent; } /* 34 */
  bool hasAirFriction() const { return m_fAirFrictionPresent; } /* 38 */
  bool hasElasticity() const { return m_fElasticityPresent; } /* 3c */
  bool hasNextEffect() const { return m_fNextEffectPresent; } /* 40 */
  bool hasUnknown1() const { return m_fUnknown1Present; } /* 44 */
  bool hasElementsPerTurn() const { return m_fElementsPerTurnPresent; } /* 48 */
  bool hasFlags() const { return m_fFlagsPresent; } /* 4c */
  bool hasDeathElement() const { return m_fDeathElementPresent; } /* 50 */
  bool hasHitSolidElement() const { return m_fHitSolidElementPresent; } /* 54 */
  bool hasHitWaterElement() const { return m_fHitWaterElementPresent; } /* 58 */
  bool hasHitLavaElement() const { return m_fHitLavaElementPresent; }  /* 5c */
  bool hasGenerationData( int i ) const { return m_fGenerationDataPresent[i]; }
  bool hasGenerateIds( int i ) const { return m_fGenerateIdsPresent[i]; }
  bool hasFadeDuration() const { return m_fFadeDurationPresent; } /* b0 */

  uint16_t id() const { return m_kBlock.m_wId; }
  const ArtResource &artResource() const { return m_kBlock.m_kArtResource; }
  const LightBlock &light() const { return m_kBlock.m_kLight; }
  uint16_t minHp() const { return m_kBlock.min_hp; }
  uint16_t maxHp() const { return m_kBlock.max_hp; }
  uint16_t mass() const { return m_kBlock.mass; }
  uint16_t radius() const { return m_kBlock.radius; }
  uint8_t unknown1() const { return m_kBlock.unknown1; }
  uint8_t elementsPerTurn() const { return m_kBlock.elements_per_turn; }
  uint16_t fadeDuration() const { return m_kBlock.elements_per_turn; }
  uint16_t airFriction() const { return m_kBlock.air_friction; }
  uint16_t elasticity() const { return m_kBlock.elasticity; }
  uint16_t minScale() const { return m_kBlock.min_scale; }
  uint16_t maxScale() const { return m_kBlock.max_scale; }
  uint16_t minSpeedXY() const { return m_kBlock.min_speed_xy; }
  uint16_t maxSpeedXY() const { return m_kBlock.max_speed_xy; }
  uint16_t minSpeedYZ() const { return m_kBlock.min_speed_yz; }
  uint16_t maxSpeedYZ() const { return m_kBlock.max_speed_yz; }
  uint32_t flags() const { return m_kBlock.flags; }
  uint16_t nextEffect() const { return m_kBlock.next_effect; }
  uint16_t deathElement() const { return m_kBlock.death_effect; }
  uint16_t hitSolidElement() const { return m_kBlock.hit_solid_effect; }
  uint16_t hitWaterElement() const { return m_kBlock.hit_water_effect; }
  uint16_t hitLavaElement() const { return m_kBlock.hit_lava_effect; } 
  uint16_t generationData( int i ) const { return m_kBlock.generation_data[i]; }
  uint16_t generateId( int i ) const { return m_kBlock.generate_ids[i]; }

private:
  bool m_fNamePresent; /* 0 */
  bool m_fIdPresent; /* 4 */
  bool m_fArtResourcePresent; /* 8 */
  bool m_fLightPresent; /* c */
  bool m_fRadiusPresent; /* 10 */
  bool m_fMinHpPresent; /* 14 */
  bool m_fMaxHpPresent; /* 18 */
  bool m_fMassPresent; /* 1c */
  bool m_fMinSpeedXYPresent; /* 20 */
  bool m_fMaxSpeedXYPresent; /* 24 */
  bool m_fMinSpeedYZPresent; /* 28 */
  bool m_fMaxSpeedYZPresent; /* 2c */
  bool m_fMinScalePresent; /* 30 */
  bool m_fMaxScalePresent; /* 34 */
  bool m_fAirFrictionPresent; /* 38 */
  bool m_fElasticityPresent; /* 3c */
  bool m_fNextEffectPresent; /* 40 */
  bool m_fUnknown1Present; /* 44 */
  bool m_fElementsPerTurnPresent; /* 48 */
  bool m_fFlagsPresent; /* 4c */
  bool m_fDeathElementPresent; /* 50 */
  bool m_fHitSolidElementPresent; /* 54 */
  bool m_fHitWaterElementPresent; /* 58 */
  bool m_fHitLavaElementPresent;  /* 5c */
  bool m_fGenerateIdsPresent[8]; /* 60 */
  bool m_fGenerationDataPresent[12]; /* 80 */
  bool m_fFadeDurationPresent; /* b0 */

  EffectBlock m_kBlock; /* b4 */
};

#endif
