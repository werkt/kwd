#ifndef CREATURE_H
#define CREATURE_H

#include "Resource.h"
#include "Light.h"

#pragma pack(push,1)

struct CreatureBlock {
  char name[32]; /* 0 */
  ArtResource ref1[39]; /* 20 */
  uint16_t unkcec; /* cec */
  uint32_t unkcee; /* cee */
  uint32_t unkcf2; /* cf2 */
  uint8_t editor_order; /* cf6 */
  uint16_t unk2c; /* cf7 */
  int32_t shot_delay; /* cf9 */
  uint16_t unkcfd; /* cfd */
  uint16_t unkcff; /* cff */
  uint32_t unkd01; /* d01 */
  uint16_t unk2d[9]; /* d05 */
  char unkd17[32]; /* d17 */
  int32_t shuffle_speed; /* d37 */
  uint8_t unk2e[5]; /* d3b */
  ArtResource ref2; /* d40 */
  LightBlock light; /* d94 */
  struct {
    uint32_t present; /* dac */
    uint32_t room_id_and_size; /* db0 */
  } attraction[2];
  uint32_t unkdbc; /* dbc */
  uint32_t unkdc0; /* dc0 */
  struct { /* bytes in these structs might be product of padding */
    uint32_t x00;
    uint32_t x04;
    uint32_t x08;
    uint8_t x0c;
    uint8_t x0d;
    uint8_t x0e;
    uint8_t x0f;
    uint32_t x10;
    uint8_t x14;
    uint8_t x15;
    uint8_t x16;
    uint8_t x17;
  } xdc4[3];
  struct {
    uint8_t x00;
    uint8_t x01;
  } xe0c[4];
  struct {
    uint32_t x00;
    uint16_t x04;
    uint16_t x06;
    uint8_t x08;
    uint8_t x09;
    uint8_t x0a;
    uint8_t x0b;
  } xe14[3], xe38[2], xe50[3];
  uint32_t xe74[2];
  struct {
    uint32_t x00;
    uint16_t x04;
    uint16_t x06;
  } xe7c[3];
  struct {
    uint32_t x00;
    uint32_t x04;
    uint32_t x08;
  } xe94;
  int32_t unkea0; /* ea0 */
  int32_t height; /* ea4 */
  uint32_t unkea8; /* ea8 */
  uint32_t unk3ab; /* eac */
  int32_t eye_height; /* eb0 */
  int32_t speed; /* eb4 */
  int32_t run_speed; /* eb8 */
  uint32_t unk3ac; /* ebc */
  uint32_t time_awake; /* ec0 */
  uint32_t time_sleep; /* ec4 */
  uint32_t unkec8; /* ec8 */
  uint32_t unkecc; /* ecc */
  uint32_t unked0; /* ed0 */
  uint32_t unked4; /* ed4 */
  uint32_t unked8; /* ed8 */
  int32_t slap_fearless_duration; /* edc */
  int32_t unkee0; /* ee0 */
  int32_t unkee4; /* ee4 */
  short possession_mana_cost; /* ee8 */
  short own_land_health_increase; /* eea */
  int32_t range; /* eec */
  uint32_t unkef0; /* ef0 */
  uint32_t unk3af; /* ef4 */
  int32_t melee_recharge; /* ef8 */
  uint32_t unkefc; /* efc */
  uint16_t exp_for_next_level; /* f00 */
  uint8_t unk3b[2]; /* f02 */
  uint16_t exp_per_second; /* f04 */
  uint16_t exp_per_second_training; /* f06 */
  uint16_t research_per_second; /* f08 */
  uint16_t manufacture_per_second; /* f0a */
  uint16_t hp; /* f0c */
  uint16_t hp_from_chicken; /* f0e */
  uint16_t fear; /* f10 */
  uint16_t threat; /* f12 */
  uint16_t melee_damage; /* f14 */
  uint16_t slap_damage; /* f16 */
  uint16_t mana_gen_prayer; /* f18 */
  uint16_t unk3cb; /* f1a */
  uint16_t pay; /* f1c */
  uint16_t max_gold_held; /* f1e */
  uint16_t unk3cc; /* f20 */
  uint16_t decompose_value; /* f22 */
  uint16_t unk3cd[2]; /* f24 */
  short anger_no_lair; /* f28 */
  short anger_no_food; /* f2a */
  short anger_no_pay; /* f2c */
  short anger_no_work; /* f2e */
  short anger_slap; /* f30 */
  short anger_in_hand; /* f32 */
  short initial_gold_held; /* f34 */
  uint16_t unk3ce[3]; /* f36 */
  uint16_t slap_effect_id; /* f3c */
  uint16_t death_effect_id; /* f3e */
  uint16_t unkf40; /* f40 */
  uint8_t unk3d[3]; /* f42 */
  uint8_t unkf45; /* f45 */
  uint8_t unk40[2]; /* f46 */
  uint8_t unkf48[3]; /* f48 */
  uint8_t id; /* f4b */
  uint8_t unk3ea[3]; /* f4c */
  uint8_t unhappy_threshold; /* f4f */
  uint8_t unk3eb[2]; /* f50 */
  uint8_t lair_object_id; /* f52 */
  uint8_t unk3f[3]; /* f53 */
  char xname[32]; /* f56 */
  uint8_t material; /* f76 */
  ArtResource reff77; /* f77 */
  uint16_t unkfcb; /* fcb */
  uint32_t unk4; /* fcd */
  ArtResource ref3; /* fd1 */
  uint8_t unk5[2]; /* 1025 */
  ArtResource ref4; /* 1027 */
  uint32_t unk6; /* 107b */
  short torture_hp_change; /* 107f */
  short torture_mood_change; /* 1081 */
  ArtResource ref5[6]; /* 1083 */
  struct {
    uint32_t x00;
    uint32_t x04;
    uint32_t x08;
  } unk7[7]; /* 127b */
  ArtResource ref6; /* 12cf */
  struct {
    uint16_t x00;
    uint16_t x02;
  } x1323[48];
  ArtResource ref7[3]; /* 13e3 */
  uint16_t unk14df;
  uint32_t x14e1[2]; /* 14e1 */
  uint32_t x14e9[2]; /* 14e9 */
  ArtResource ref8; /* 14f1 */
  uint32_t unk1545;
};

#pragma pack(pop)

/* 0x1939 bytes */
class CreatureLoadBlock {
public:
  void load( CreatureBlock &rkBlock );

  bool hasName() const { return m_fNamePresent; } /* 0 */
  bool hasId() const { return m_fIdPresent; } /* 4 */
  bool hasUnk2e_0() const { return m_fUnk2e_0Present; } /* 8 */
  bool hasXName() const { return m_fXNamePresent; } /* c */
  bool hasUnkd17() const { return m_fUnkd17Present; } /* 10 */
  bool hasRef1_0_36( int i ) const { return m_fRef1_0_36Present[i]; } /* 14 */
  bool hasRef3() const { return m_fRef3Present; } /* a8 */
  bool hasRef6() const { return m_fRef6Present; } /* ac */
  bool hasRef7_0() const { return m_fRef7_0Present; } /* b0 */
  bool hasRef7_1() const { return m_fRef7_1Present; } /* b4 */
  bool hasRef7_2() const { return m_fRef7_2Present; } /* b8 */
  bool hasRef5( int i ) const { return m_fRef5Present[i]; } /* bc */
  bool hasRef1_37() const { return m_fRef1_37Present; } /* d4 */
  bool hasRef1_38() const { return m_fRef1_38Present; } /* d8 */
  bool hasRef2() const { return m_fRef2Present; } /* dc */
  bool hasReff77() const { return m_fReff77Present; } /* e0 */
  bool hasRef4() const { return m_fRef4Present; } /* e4 */
  bool hasLight() const { return m_fLightPresent; } /* e8 */
  bool hasUnkea0() const { return m_fUnkea0Present; } /* ec */
  bool hasHeight() const { return m_fHeightPresent; } /* f0 */
  bool hasEyeHeight() const { return m_fEyeHeightPresent; } /* f4 */
  bool hasUnk3f_0() const { return m_fUnk3f_0Present; } /* f8 */
  bool hasUnkea8() const { return m_fUnkea8Present; } /* fc */
  bool hasUnk3ab() const { return m_fUnk3abPresent; } /* 100 */
  bool hasSpeed() const { return m_fSpeedPresent; } /* 104 */
  bool hasRunSpeed() const { return m_fRunSpeedPresent; } /* 108 */
  bool hasShuffleSpeed() const { return m_fShuffleSpeedPresent; } /* 10c */
  bool hasUnkef0() const { return m_fUnkef0Present; } /* 110 */
  bool hasSlapDamage() const { return m_fSlapDamagePresent; } /* 114 */
  bool hasExpForNextLevel() const { return m_fExpForNextLevelPresent; } /* 118 */
  bool hasExpPerSecond() const { return m_fExpPerSecondPresent; } /* 11c */
  bool hasExpPerSecondTraining() const { return m_fExpPerSecondTrainingPresent; } /* 120 */
  bool hasResearchPerSecond() const { return m_fResearchPerSecondPresent; } /* 124 */
  bool hasManufacturePerSecond() const { return m_fManufacturePerSecondPresent; } /* 128 */
  bool hasHP() const { return m_fHPPresent; } /* 12c */
  bool hasHPFromChicken() const { return m_fHPFromChickenPresent; } /* 130 */
  bool hasFear() const { return m_fFearPresent; } /* 134 */
  bool hasThreat() const { return m_fThreatPresent; } /* 138 */
  bool hasManaGenPrayer() const { return m_fManaGenPrayerPresent; } /* 13c */
  bool hasUnk3cb() const { return m_fUnk3cbPresent; } /* 140 */
  bool hasPay() const { return m_fPayPresent; } /* 144 */
  bool hasMaxGoldHeld() const { return m_fMaxGoldHeldPresent; } /* 148 */
  bool hasUnk3cc() const { return m_fUnk3ccPresent; } /* 14c */
  bool hasUnkec8() const { return m_fUnkec8Present; } /* 150 */
  bool hasUnkecc() const { return m_fUnkeccPresent; } /* 154 */
  bool hasUnkd01() const { return m_fUnkd01Present; } /* 158 */
  bool hasUnk3ac() const { return m_fUnk3acPresent; } /* 15c */
  bool hasUnk3ea_2() const { return m_fUnk3ea_2Present; } /* 160 */
  bool hasTimeAwake() const { return m_fTimeAwakePresent; } /* 164 */
  bool hasTimeSleep() const { return m_fTimeSleepPresent; } /* 168 */
  bool hasDecomposeValue() const { return m_fDecomposeValuePresent; } /* 16c */
  bool hasOwnLandHealthIncrease() const { return m_fOwnLandHealthIncreasePresent; } /* 170 */
  bool hasUnkcfd() const { return m_fUnkcfdPresent; } /* 174 */
  bool hasUnk3cd_0() const { return m_fUnk3cd_0Present; } /* 178 */
  bool hasUnk3cd_1() const { return m_fUnk3cd_1Present; } /* 17c */
  bool hasUnk3ce_1() const { return m_fUnk3ce_1Present; } /* 180 */
  bool hasUnk3ce_2() const { return m_fUnk3ce_2Present; } /* 184 */
  bool hasSlapEffectId() const { return m_fSlapEffectIdPresent; } /* 188 */
  bool hasUnkcff() const { return m_fUnkcffPresent; } /* 18c */
  bool hasUnk3ea_1() const { return m_fUnk3ea_1Present; } /* 190 */
  bool hasLairObjectId() const { return m_fLairObjectIdPresent; } /* 194 */
  bool hasUnhappyThreshold() const { return m_fUnhappyThresholdPresent; } /* 198 */
  bool hasUnk3ea_0() const { return m_fUnk3ea_0Present; } /* 19c */
  bool hasDeathEffectId() const { return m_fDeathEffectIdPresent; } /* 1a0 */
  bool hasUnk3ce_0() const { return m_fUnk3ce_0Present; } /* 1a4 */
  bool hasUnkf40() const { return m_fUnkf40Present; } /* 1a8 */
  bool hasUnk3eb_0() const { return m_fUnk3eb_0Present; } /* 1ac */
  bool hasMeleeDamage() const { return m_fMeleeDamagePresent; } /* 1b0 */
  bool hasMeleeRecharge() const { return m_fMeleeRechargePresent; } /* 1b4 */
  bool hasRange() const { return m_fRangePresent; } /* 1b8 */
  bool hasShotDelay() const { return m_fShotDelayPresent; } /* 1bc */
  bool hasUnk3eb_1() const { return m_fUnk3eb_1Present; } /* 1c0 */
  bool hasUnk3af() const { return m_fUnk3afPresent; } /* 1c4 */
  bool hasInitialGoldHeld() const { return m_fInitialGoldHeldPresent; } /* 1c8 */
  bool hasAngerNoLair() const { return m_fAngerNoLairPresent; } /* 1cc */
  bool hasAngerNoFood() const { return m_fAngerNoFoodPresent; } /* 1d0 */
  bool hasAngerNoPay() const { return m_fAngerNoPayPresent; } /* 1d4 */
  bool hasAngerNoWork() const { return m_fAngerNoWorkPresent; } /* 1d8 */
  bool hasAngerSlap() const { return m_fAngerSlapPresent; } /* 1dc */
  bool hasAngerInHand() const { return m_fAngerInHandPresent; } /* 1e0 */
  bool hasUnkfcb() const { return m_fUnkfcbPresent; } /* 1e4 */
  bool hasUnk3f_2() const { return m_fUnk3f_2Present; } /* 1e8 */
  bool hasUnk3b_0() const { return m_fUnk3b_0Present; } /* 1ec */
  bool hasUnk3b_1() const { return m_fUnk3b_1Present; } /* 1f0 */
  bool hasUnked0() const { return m_fUnked0Present; } /* 1f4 */
  bool hasUnked4() const { return m_fUnked4Present; } /* 1f8 */
  bool hasUnked8() const { return m_fUnked8Present; } /* 1fc */
  bool hasSlapFearlessDuration() const { return m_fSlapFearlessDurationPresent; } /* 200 */
  bool hasUnkee0() const { return m_fUnkee0Present; } /* 204 */
  bool hasUnkee4() const { return m_fUnkee4Present; } /* 208 */
  bool hasPossessionManaCost() const { return m_fPossessionManaCostPresent; } /* 20c */
  bool hasUnke94() const { return m_fUnke94Present; } /* 210 */
  bool hasUnk3f_1() const { return m_fUnk3f_1Present; } /* 214 */
  bool hasUnkf45() const { return m_fUnkf45Present; } /* 218 */
  bool hasMaterial() const { return m_fMaterialPresent; } /* 21c */
  bool hasUnk4() const { return m_fUnk4Present; } /* 220 */
  bool hasUnkcec() const { return m_fUnkcecPresent; } /* 224 */
  bool hasUnkcee() const { return m_fUnkceePresent; } /* 228 */
  bool hasUnkcf2() const { return m_fUnkcf2Present; } /* 22c */
  bool hasEditorOrder() const { return m_fEditorOrderPresent; } /* 230 */
  bool hasUnk6() const { return m_fUnk6Present; } /* 234 */
  bool hasTortureHPChange() const { return m_fTortureHPChangePresent; } /* 238 */
  bool hasTortureMoodChange() const { return m_fTortureMoodChangePresent; } /* 23c */
  bool hasUnkdbc() const { return m_fUnkdbcPresent; } /* 240 */
  bool hasUnkdc0() const { return m_fUnkdc0Present; } /* 244 */
  bool hasUnk2e_2() const { return m_fUnk2e_2Present; } /* 248 */
  bool hasUnk2e_1() const { return m_fUnk2e_1Present; } /* 24c */
  bool hasUnk2e_3() const { return m_fUnk2e_3Present; } /* 250 */
  bool hasUnk14df() const { return m_fUnk14dfPresent; } /* 254 */
  bool hasRef8() const { return m_fRef8Present; } /* 258 */
  bool hasUnkefc() const { return m_fUnkefcPresent; } /* 25c */
  bool hasUnk1545() const { return m_fUnk1545Present; } /* 260 */
  bool hasAttraction( int i ) const { return m_fAttractionPresent[i]; } /* 264 */
  bool hasUnkdc4( int i ) const { return m_fUnkdc4Present[i]; } /* 26c */
  bool hasUnkf48( int i ) const { return m_fUnkf48Present[i]; } /* 278 */
  bool hasUnke0c( int i ) const { return m_fUnke0cPresent[i]; } /* 284 */
  bool hasUnke14( int i ) const { return m_fUnke14Present[i]; } /* 294 */
  bool hasUnke38( int i ) const { return m_fUnke38Present[i]; } /* 2a0 */
  bool hasUnke50( int i ) const { return m_fUnke50Present[i]; } /* 2a8 */
  bool hasUnke74( int i ) const { return m_fUnke74Present[i]; } /* 2b4 */
  bool hasUnk14e1( int i ) const { return m_fUnk14e1Present[i]; } /* 2bc */
  bool hasUnke7c( int i ) const { return m_fUnke7cPresent[i]; } /* 2c4 */
  bool hasUnk14e9( int i ) const { return m_fUnk14e9Present[i]; } /* 2d0 */
  bool hasUnk3d( int i ) const { return m_fUnk3dPresent[i]; } /* 2d8 */
  bool hasUnk5( int i ) const { return m_fUnk5Present[i]; } /* 2e4 */
  bool hasUnk7( int i ) const { return m_fUnk7Present[i]; } /* 2ec */
  bool hasUnk2d( int i ) const { return m_fUnk2dPresent[i]; } /* 308 */
  bool hasUnk2c( int i ) const { return m_fUnk2cPresent; } /* 32c */
  bool hasUnk1323( int i ) const { return m_fUnk1323Present[i]; } /* 330 */

  const CreatureBlock &block() const { return m_kBlock; }

  const char *name() const { return m_kBlock.name; }
  const ArtResource &ref1( int i ) const { return m_kBlock.ref1[i]; }
  uint16_t unkcec() const { return m_kBlock.unkcec; }
  uint32_t unkcee() const { return m_kBlock.unkcee; }
  uint32_t unkcf2() const { return m_kBlock.unkcf2; }
  uint8_t editorOrder() const { return m_kBlock.editor_order; }
  uint16_t unk2c() const { return m_kBlock.unk2c; }
  int shotDelay() const { return m_kBlock.shot_delay; }
  uint16_t unkcfd() const { return m_kBlock.unkcfd; }
  uint16_t unkcff() const { return m_kBlock.unkcff; }
  uint32_t unkd01() const { return m_kBlock.unkd01; }
  int shuffleSpeed() const { return m_kBlock.shuffle_speed; }
  uint8_t unk2e_0() const { return m_kBlock.unk2e[0]; }
  ArtResource ref2() const { return m_kBlock.ref2; }
  LightBlock light() const { return m_kBlock.light; }

  uint32_t unkdbc() const { return m_kBlock.unkdbc; }
  uint32_t unkdc0() const { return m_kBlock.unkdc0; }






  int unkea0() const { return m_kBlock.unkea0; }
  int height() const { return m_kBlock.height; }
  uint32_t unkea8() const { return m_kBlock.unkea8; }
  uint32_t unk3ab() const { return m_kBlock.unk3ab; }
  int eyeHeight() const { return m_kBlock.eye_height; }
  int speed() const { return m_kBlock.speed; }
  int runSpeed() const { return m_kBlock.run_speed; }
  uint32_t unk3ac() const { return m_kBlock.unk3ac; }
  uint32_t timeAwake() const { return m_kBlock.time_awake; }
  uint32_t timeSleep() const { return m_kBlock.time_sleep; }
  uint32_t unkec8() const { return m_kBlock.unkec8; }
  uint32_t unkecc() const { return m_kBlock.unkecc; }
  uint32_t unked0() const { return m_kBlock.unked0; }
  uint32_t unked4() const { return m_kBlock.unked4; }
  uint32_t unked8() const { return m_kBlock.unked8; }
  int slapFearlessDuration() const { return m_kBlock.slap_fearless_duration; }
  int unkee0() const { return m_kBlock.unkee0; }
  int unkee4() const { return m_kBlock.unkee4; }
  short possessionManaCost() const { return m_kBlock.possession_mana_cost; }
  short ownLandHealthIncrease() const { return m_kBlock.own_land_health_increase; }
  int range() const { return m_kBlock.range; }
  uint32_t unkef0() const { return m_kBlock.unkef0; }
  uint32_t unk3af() const { return m_kBlock.unk3af; }
  int meleeRecharge() const { return m_kBlock.melee_recharge; }
  uint32_t unkefc() const { return m_kBlock.unkefc; }
  uint16_t expForNextLevel() const { return m_kBlock.exp_for_next_level; }
  uint8_t unk3b_0() const { return m_kBlock.unk3b[0]; }
  uint8_t unk3b_1() const { return m_kBlock.unk3b[1]; }
  uint16_t expPerSecond() const { return m_kBlock.exp_per_second; }
  uint16_t expPerSecondTraining() const { return m_kBlock.exp_per_second_training; }
  uint16_t researchPerSecond() const { return m_kBlock.research_per_second; }
  uint16_t manufacturePerSecond() const { return m_kBlock.manufacture_per_second; }
  uint16_t hp() const { return m_kBlock.hp; }
  uint16_t hpFromChicken() const { return m_kBlock.hp_from_chicken; }
  uint16_t fear() const { return m_kBlock.fear; }
  uint16_t threat() const { return m_kBlock.threat; }
  uint16_t meleeDamage() const { return m_kBlock.melee_damage; }
  uint16_t slapDamage() const { return m_kBlock.slap_damage; }
  uint16_t manaGenPrayer() const { return m_kBlock.mana_gen_prayer; }
  uint16_t unk3cb() const { return m_kBlock.unk3cb; }
  uint16_t pay() const { return m_kBlock.pay; }
  uint16_t maxGoldHeld() const { return m_kBlock.max_gold_held; }
  uint16_t unk3cc() const { return m_kBlock.unk3cc; }
  uint16_t decomposeValue() const { return m_kBlock.decompose_value; }
  uint16_t unk3cd_0() const { return m_kBlock.unk3cd[0]; }
  uint16_t unk3cd_1() const { return m_kBlock.unk3cd[1]; }
  short angerNoLair() const { return m_kBlock.anger_no_lair; }
  short angerNoFood() const { return m_kBlock.anger_no_food; }
  short angerNoPay() const { return m_kBlock.anger_no_pay; }
  short angerNoWork() const { return m_kBlock.anger_no_work; }
  short angerSlap() const { return m_kBlock.anger_slap; }
  short angerInHand() const { return m_kBlock.anger_in_hand; }
  short initialGoldHeld() const { return m_kBlock.initial_gold_held; }
  uint16_t unk3ce_0() const { return m_kBlock.unk3ce[0]; }
  uint16_t unk3ce_1() const { return m_kBlock.unk3ce[1]; }
  uint16_t unk3ce_2() const { return m_kBlock.unk3ce[2]; }
  uint16_t slapEffectId() const { return m_kBlock.slap_effect_id; }
  uint16_t deathEffectId() const { return m_kBlock.death_effect_id; }
  uint16_t unkf40() const { return m_kBlock.unkf40; }

  uint8_t unkf45() const { return m_kBlock.unkf45; }


  uint8_t id() const { return m_kBlock.id; }
  uint8_t unk3ea_1() const { return m_kBlock.unk3ea[1]; }
  uint8_t unk3ea_2() const { return m_kBlock.unk3ea[2]; }
  uint8_t unhappyThreshold() const { return m_kBlock.unhappy_threshold; }
  uint8_t unk3eb_0() const { return m_kBlock.unk3eb[0]; }
  uint8_t unk3eb_1() const { return m_kBlock.unk3eb[1]; }
  uint8_t lairObjectId() const { return m_kBlock.lair_object_id; }
  uint8_t unk3f_2() const { return m_kBlock.unk3f[2]; }
  const char *xname() const { return m_kBlock.xname; }
  uint8_t material() const { return m_kBlock.material; }
  const ArtResource &reff77() const { return m_kBlock.reff77; }
  uint16_t unkfcb() const { return m_kBlock.unkfcb; }
  uint32_t unk4() const { return m_kBlock.unk4; }
  const ArtResource &ref3() const { return m_kBlock.ref3; }

  const ArtResource &ref4() const { return m_kBlock.ref4; }
  uint32_t unk6() const { return m_kBlock.unk6; }
  short tortureHPChange() const { return m_kBlock.torture_hp_change; }
  short tortureMoodChange() const { return m_kBlock.torture_mood_change; }
  const ArtResource &ref5( int i ) const { return m_kBlock.ref5[i]; }

  const ArtResource &ref6() const { return m_kBlock.ref6; }

  const ArtResource &ref7( int i ) const { return m_kBlock.ref7[i]; }
  uint16_t unk14df() const { return m_kBlock.unk14df; }


  const ArtResource &ref8() const { return m_kBlock.ref8; }
  uint32_t unk1545() const { return m_kBlock.unk1545; }

  bool sub_569c40( int i ) const {
    return i < 2 ? m_fAttractionPresent[i] : false;
  }

  uint32_t sub_569c80( int i ) const {
    return i < 2 ? m_kBlock.attraction[i].room_id_and_size : false;
  }

  uint32_t sub_569c60( int i ) const {
    return i < 2 ? m_kBlock.attraction[i].present : false;
  }

  bool sub_569ca0( int i ) const {
    return i < 3 ? m_fUnkdc4Present[i] : false;
  }

  uint8_t sub_569cc0( int i ) const {
    return i < 3 ? m_kBlock.xdc4[i].x16 : false;
  }

  uint8_t sub_569ce0( int i ) const {
    return i < 3 ? m_kBlock.xdc4[i].x17 : false;
  }

  uint32_t sub_569d00( int i ) const {
    return i < 3 ? m_kBlock.xdc4[i].x10 : false;
  }

  const uint32_t *sub_569d20( int i ) const {
    /* not null... returns something on stack, probably Vec3 */
    return i < 3 ? &m_kBlock.xdc4[i].x00 : NULL;
  }

  uint8_t sub_569d50( int i ) const {
    return i < 3 ? m_kBlock.xdc4[i].x0d : false;
  }

  bool sub_569d70( int i ) const {
    return i < 4 ? m_fUnke0cPresent[i] : false;
  }

  uint8_t sub_569d90( int i ) const {
    return i < 4 ? m_kBlock.xe0c[i].x00 : false;
  }

  uint8_t sub_569db0( int i ) const {
    return i < 4 ? m_kBlock.xe0c[i].x01 : false;
  }

  bool sub_56a0d0( int i ) const {
    return i < 10 ? m_fUnk2dPresent[i] : false;
  }

  uint16_t sub_56a0f0( int i ) const {
    return i < 10 ? (i == 9 ? m_kBlock.unk2c : m_kBlock.unk2d[i]) : false;
  }

  /* fixed incorrect check for < 8 here... */
  bool sub_56a120( int i ) const {
    return i < 7 ? m_fUnk7Present[i] : false;
  }

  /* again, probably a vec3 */
  const uint32_t *sub_56a140( int i ) const {
    return i < 7 ? &m_kBlock.unk7[i].x00 : NULL;
  }

  bool sub_569dd0( int i ) const { return i < 3 ? m_fUnke14Present[i] : false; }
  bool sub_569e70( int i ) const { return i < 2 ? m_fUnke38Present[i] : false; }
  bool sub_569f10( int i ) const { return i < 3 ? m_fUnke50Present[i] : false; }
  bool sub_569fb0( int i ) const { return i < 4 ? m_fUnke74Present[i] : false; }
  bool sub_569ff0( int i ) const { return i < 3 ? m_fUnke7cPresent[i] : false; }
  bool sub_56a070( int i ) const { return i < 2 ? m_fUnk14e9Present[i] : false; }
  bool sub_56a1d0( int i ) const { return i < 3 ? m_fUnk3dPresent[i] : false; }
  bool sub_56a210( int i ) const { return i < 2 ? m_fUnk5Present[i] : false; }
  bool sub_56a170( int i ) const { return i < 48 ? m_fUnk1323Present[i] : false; }

  uint8_t sub_56a090( int i ) const { return i < 2 ? m_kBlock.unk40[i] : 0; }
  uint8_t sub_56a0b0( int i ) const { return i < 2 ? m_kBlock.x14e9[i] : 0; }

private:
  bool m_fNamePresent; /* 0 */
  bool m_fIdPresent; /* 4 */
  bool m_fUnk2e_0Present; /* 8 */
  bool m_fXNamePresent; /* c */
  bool m_fUnkd17Present; /* 10 */
  bool m_fRef1_0_36Present[37]; /* 14 */
  bool m_fRef3Present; /* a8 */
  bool m_fRef6Present; /* ac */
  bool m_fRef7_0Present; /* b0 */
  bool m_fRef7_1Present; /* b4 */
  bool m_fRef7_2Present; /* b8 */
  bool m_fRef5Present[6]; /* bc */
  bool m_fRef1_37Present; /* d4 */
  bool m_fRef1_38Present; /* d8 */
  bool m_fRef2Present; /* dc */
  bool m_fReff77Present; /* e0 */
  bool m_fRef4Present; /* e4 */
  bool m_fLightPresent; /* e8 */
  bool m_fUnkea0Present; /* ec */
  bool m_fHeightPresent; /* f0 */
  bool m_fEyeHeightPresent; /* f4 */
  bool m_fUnk3f_0Present; /* f8 */
  bool m_fUnkea8Present; /* fc */
  bool m_fUnk3abPresent; /* 100 */
  bool m_fSpeedPresent; /* 104 */
  bool m_fRunSpeedPresent; /* 108 */
  bool m_fShuffleSpeedPresent; /* 10c */
  bool m_fUnkef0Present; /* 110 */
  bool m_fSlapDamagePresent; /* 114 */
  bool m_fExpForNextLevelPresent; /* 118 */
  bool m_fExpPerSecondPresent; /* 11c */
  bool m_fExpPerSecondTrainingPresent; /* 120 */
  bool m_fResearchPerSecondPresent; /* 124 */
  bool m_fManufacturePerSecondPresent; /* 128 */
  bool m_fHPPresent; /* 12c */
  bool m_fHPFromChickenPresent; /* 130 */
  bool m_fFearPresent; /* 134 */
  bool m_fThreatPresent; /* 138 */
  bool m_fManaGenPrayerPresent; /* 13c */
  bool m_fUnk3cbPresent; /* 140 */
  bool m_fPayPresent; /* 144 */
  bool m_fMaxGoldHeldPresent; /* 148 */
  bool m_fUnk3ccPresent; /* 14c */
  bool m_fUnkec8Present; /* 150 */
  bool m_fUnkeccPresent; /* 154 */
  bool m_fUnkd01Present; /* 158 */
  bool m_fUnk3acPresent; /* 15c */
  bool m_fUnk3ea_2Present; /* 160 */
  bool m_fTimeAwakePresent; /* 164 */
  bool m_fTimeSleepPresent; /* 168 */
  bool m_fDecomposeValuePresent; /* 16c */
  bool m_fOwnLandHealthIncreasePresent; /* 170 */
  bool m_fUnkcfdPresent; /* 174 */
  bool m_fUnk3cd_0Present; /* 178 */
  bool m_fUnk3cd_1Present; /* 17c */
  bool m_fUnk3ce_1Present; /* 180 */
  bool m_fUnk3ce_2Present; /* 184 */
  bool m_fSlapEffectIdPresent; /* 188 */
  bool m_fUnkcffPresent; /* 18c */
  bool m_fUnk3ea_1Present; /* 190 */
  bool m_fLairObjectIdPresent; /* 194 */
  bool m_fUnhappyThresholdPresent; /* 198 */
  bool m_fUnk3ea_0Present; /* 19c */
  bool m_fDeathEffectIdPresent; /* 1a0 */
  bool m_fUnk3ce_0Present; /* 1a4 */
  bool m_fUnkf40Present; /* 1a8 */
  bool m_fUnk3eb_0Present; /* 1ac */
  bool m_fMeleeDamagePresent; /* 1b0 */
  bool m_fMeleeRechargePresent; /* 1b4 */
  bool m_fRangePresent; /* 1b8 */
  bool m_fShotDelayPresent; /* 1bc */
  bool m_fUnk3eb_1Present; /* 1c0 */
  bool m_fUnk3afPresent; /* 1c4 */
  bool m_fInitialGoldHeldPresent; /* 1c8 */
  bool m_fAngerNoLairPresent; /* 1cc */
  bool m_fAngerNoFoodPresent; /* 1d0 */
  bool m_fAngerNoPayPresent; /* 1d4 */
  bool m_fAngerNoWorkPresent; /* 1d8 */
  bool m_fAngerSlapPresent; /* 1dc */
  bool m_fAngerInHandPresent; /* 1e0 */
  bool m_fUnkfcbPresent; /* 1e4 */
  bool m_fUnk3f_2Present; /* 1e8 */
  bool m_fUnk3b_0Present; /* 1ec */
  bool m_fUnk3b_1Present; /* 1f0 */
  bool m_fUnked0Present; /* 1f4 */
  bool m_fUnked4Present; /* 1f8 */
  bool m_fUnked8Present; /* 1fc */
  bool m_fSlapFearlessDurationPresent; /* 200 */
  bool m_fUnkee0Present; /* 204 */
  bool m_fUnkee4Present; /* 208 */
  bool m_fPossessionManaCostPresent; /* 20c */
  bool m_fUnke94Present; /* 210 */
  bool m_fUnk3f_1Present; /* 214 */
  bool m_fUnkf45Present; /* 218 */
  bool m_fMaterialPresent; /* 21c */
  bool m_fUnk4Present; /* 220 */
  bool m_fUnkcecPresent; /* 224 */
  bool m_fUnkceePresent; /* 228 */
  bool m_fUnkcf2Present; /* 22c */
  bool m_fEditorOrderPresent; /* 230 */
  bool m_fUnk6Present; /* 234 */
  bool m_fTortureHPChangePresent; /* 238 */
  bool m_fTortureMoodChangePresent; /* 23c */
  bool m_fUnkdbcPresent; /* 240 */
  bool m_fUnkdc0Present; /* 244 */
  bool m_fUnk2e_2Present; /* 248 */
  bool m_fUnk2e_1Present; /* 24c */
  bool m_fUnk2e_3Present; /* 250 */
  bool m_fUnk14dfPresent; /* 254 */
  bool m_fRef8Present; /* 258 */
  bool m_fUnkefcPresent; /* 25c doublecheck ordering in load function */
  bool m_fUnk1545Present; /* 260 */
  bool m_fAttractionPresent[2]; /* 264 */
  bool m_fUnkdc4Present[3]; /* 26c */
  bool m_fUnkf48Present[3]; /* 278 */
  bool m_fUnke0cPresent[4]; /* 284 */
  bool m_fUnke14Present[3]; /* 294 */
  bool m_fUnke38Present[2]; /* 2a0 */
  bool m_fUnke50Present[3]; /* 2a8 */
  bool m_fUnke74Present[2]; /* 2b4 */
  bool m_fUnk14e1Present[2]; /* 2bc */
  bool m_fUnke7cPresent[3]; /* 2c4 */
  bool m_fUnk14e9Present[2]; /* 2d0 */
  bool m_fUnk3dPresent[3]; /* 2d8 */
  bool m_fUnk5Present[2]; /* 2e4 */
  bool m_fUnk7Present[7]; /* 2ec */
  bool m_fUnk2dPresent[9]; /* 308 */
  bool m_fUnk2cPresent; /* 32c */
  bool m_fUnk1323Present[48]; /* 330 */
  CreatureBlock m_kBlock; /* 3f0 */
};

#endif
