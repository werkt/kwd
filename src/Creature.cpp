#include <string.h>

#include "Creature.h"

void
CreatureLoadBlock::load( CreatureBlock &rkBlock )
{
  m_fIdPresent = true;
  m_kBlock.id = rkBlock.id;

  m_fUnk2e_0Present = true;
  m_kBlock.unk2e[0] = rkBlock.unk2e[0];

  m_fNamePresent = true;
  strncpy(m_kBlock.name, rkBlock.name, 32);
  m_kBlock.name[31] = '\0';

  m_fUnkea0Present = true;
  m_kBlock.unkea0 = rkBlock.unkea0;

  m_fHeightPresent = true;
  m_kBlock.height = rkBlock.height;

  m_fEyeHeightPresent = true;
  m_kBlock.eye_height = rkBlock.eye_height;

  m_fUnk3f_0Present = true;
  m_kBlock.unk3f[0] = rkBlock.unk3f[0];

  m_fUnkea8Present = true;
  m_kBlock.unkea8 = rkBlock.unkea8;

  m_fHPPresent = true;
  m_kBlock.hp = rkBlock.hp;

  m_fHPFromChickenPresent = true;
  m_kBlock.hp_from_chicken = rkBlock.hp_from_chicken;

  m_fFearPresent = true;
  m_kBlock.fear = rkBlock.fear;

  m_fThreatPresent = true;
  m_kBlock.threat = rkBlock.threat;

  m_fPayPresent = true;
  m_kBlock.pay = rkBlock.pay;

  m_fMaxGoldHeldPresent = true;
  m_kBlock.max_gold_held = rkBlock.max_gold_held;

  m_fLairObjectIdPresent = true;
  m_kBlock.lair_object_id = rkBlock.lair_object_id;

  m_fSpeedPresent = true;
  m_kBlock.speed = rkBlock.speed;

  m_fRunSpeedPresent = true;
  m_kBlock.run_speed = rkBlock.run_speed;

  m_fShuffleSpeedPresent = true;
  m_kBlock.shuffle_speed = rkBlock.shuffle_speed;

  m_fUnkef0Present = true;
  m_kBlock.unkef0 = rkBlock.unkef0;

  m_fUnk3ccPresent = true;
  m_kBlock.unk3cc = rkBlock.unk3cc;

  m_fUnkec8Present = true;
  m_kBlock.unkec8 = rkBlock.unkec8;

  m_fUnkeccPresent = true;
  m_kBlock.unkecc = rkBlock.unkecc;

  m_fUnkd01Present = true;
  m_kBlock.unkd01 = rkBlock.unkd01;

  m_fSlapDamagePresent = true;
  m_kBlock.slap_damage = rkBlock.slap_damage;

  m_fUnk3acPresent = true;
  m_kBlock.unk3ac = rkBlock.unk3ac;
  
  m_fUnk3ea_2Present = true;
  m_kBlock.unk3ea[2] = rkBlock.unk3ea[2];

  m_fRef1_37Present = true;
  m_kBlock.ref1[37] = rkBlock.ref1[37];

  m_fRef1_38Present = true;
  m_kBlock.ref1[38] = rkBlock.ref1[38];

  m_fRef2Present = true;
  m_kBlock.ref2 = rkBlock.ref2;

  m_fReff77Present = true;
  m_kBlock.reff77 = rkBlock.reff77;

  m_fRef4Present = true;
  m_kBlock.ref4 = rkBlock.ref4;

  m_fManaGenPrayerPresent = true;
  m_kBlock.mana_gen_prayer = rkBlock.mana_gen_prayer;

  m_fUnk3cbPresent = true;
  m_kBlock.unk3cb = rkBlock.unk3cb;

  m_fUnk3ea_0Present = true;
  m_kBlock.unk3ea[0] = rkBlock.unk3ea[0];

  m_fOwnLandHealthIncreasePresent = true;
  m_kBlock.own_land_health_increase = rkBlock.own_land_health_increase;

  m_fUnkcfdPresent = true;
  m_kBlock.unkcfd = rkBlock.unkcfd;

  m_fExpForNextLevelPresent = true;
  m_kBlock.exp_for_next_level = rkBlock.exp_for_next_level;

  m_fExpPerSecondPresent = true;
  m_kBlock.exp_per_second = rkBlock.exp_per_second;

  m_fExpPerSecondTrainingPresent = true;
  m_kBlock.exp_per_second_training = rkBlock.exp_per_second_training;

  m_fResearchPerSecondPresent = true;
  m_kBlock.research_per_second = rkBlock.research_per_second;

  m_fManufacturePerSecondPresent = true;
  m_kBlock.manufacture_per_second = rkBlock.manufacture_per_second;

  m_fUnk3abPresent = true;
  m_kBlock.unk3ab = rkBlock.unk3ab;

  m_fUnk3cd_0Present = true;
  m_kBlock.unk3cd[0] = rkBlock.unk3cd[0];

  m_fUnk3cd_1Present = true;
  m_kBlock.unk3cd[1] = rkBlock.unk3cd[1];

  m_fUnk3ce_1Present = true;
  m_kBlock.unk3ce[1] = rkBlock.unk3ce[1];

  m_fUnk3ce_2Present = true;
  m_kBlock.unk3ce[2] = rkBlock.unk3ce[2];

  m_fSlapEffectIdPresent = true;
  m_kBlock.slap_effect_id = rkBlock.slap_effect_id;

  m_fUnkcffPresent = true;
  m_kBlock.unkcff = rkBlock.unkcff;

  m_fUnk3ea_1Present = true;
  m_kBlock.unk3ea[1] = rkBlock.unk3ea[1];

  m_fUnk3ea_2Present = true;
  m_kBlock.unk3ea[2] = rkBlock.unk3ea[2];

  m_fUnk3ce_0Present = true;
  m_kBlock.unk3ce[0] = rkBlock.unk3ce[0];

  m_fUnkf40Present = true;
  m_kBlock.unkf40 = rkBlock.unkf40;

  m_fUnk3eb_0Present = true;
  m_kBlock.unk3eb[0] = rkBlock.unk3eb[0];

  m_fMeleeDamagePresent = true;
  m_kBlock.melee_damage = rkBlock.melee_damage;

  m_fShotDelayPresent = true;
  m_kBlock.shot_delay = rkBlock.shot_delay;

  m_fMeleeRechargePresent = true;
  m_kBlock.melee_recharge = rkBlock.melee_recharge;

  m_fRangePresent = true;
  m_kBlock.range = rkBlock.range;

  m_fTimeAwakePresent = true;
  m_kBlock.time_awake = rkBlock.time_awake;

  m_fTimeSleepPresent = true;
  m_kBlock.time_sleep = rkBlock.time_sleep;

  m_fUnhappyThresholdPresent = true;
  m_kBlock.unhappy_threshold = rkBlock.unhappy_threshold;

  m_fDecomposeValuePresent = true;
  m_kBlock.decompose_value = rkBlock.decompose_value;

  m_fUnk3eb_1Present = true;
  m_kBlock.unk3eb[1] = rkBlock.unk3eb[1];

  m_fUnk3afPresent = true;
  m_kBlock.unk3af = rkBlock.unk3af;

  m_fInitialGoldHeldPresent = true;
  m_kBlock.initial_gold_held = rkBlock.initial_gold_held;

  m_fAngerNoLairPresent = true;
  m_kBlock.anger_no_lair = rkBlock.anger_no_lair;

  m_fAngerNoFoodPresent = true;
  m_kBlock.anger_no_food = rkBlock.anger_no_food;

  m_fAngerNoPayPresent = true;
  m_kBlock.anger_no_pay = rkBlock.anger_no_pay;

  m_fAngerNoWorkPresent = true;
  m_kBlock.anger_no_work = rkBlock.anger_no_work;

  m_fAngerSlapPresent = true;
  m_kBlock.anger_slap = rkBlock.anger_slap;

  m_fAngerInHandPresent = true;
  m_kBlock.anger_in_hand = rkBlock.anger_in_hand;

  m_fUnkfcbPresent = true;
  m_kBlock.unkfcb = rkBlock.unkfcb;

  m_fLightPresent = true;
  m_kBlock.light = rkBlock.light;

  m_fXNamePresent = true;
  strncpy(m_kBlock.xname, rkBlock.xname, 32);
  m_kBlock.xname[31] = '\0';

  m_fUnkd17Present = true;
  strncpy(m_kBlock.unkd17, rkBlock.unkd17, 32);
  m_kBlock.unkd17[31] = '\0';

  m_fUnk3f_2Present = true;
  m_kBlock.unk3f[2] = rkBlock.unk3f[2];

  m_fUnk3b_0Present = true;
  m_kBlock.unk3b[0] = rkBlock.unk3b[0];

  m_fUnk3b_1Present = true;
  m_kBlock.unk3b[1] = rkBlock.unk3b[1];

  m_fUnked0Present = true;
  m_kBlock.unked0 = rkBlock.unked0;

  m_fUnked4Present = true;
  m_kBlock.unked4 = rkBlock.unked4;

  m_fUnked8Present = true;
  m_kBlock.unked8 = rkBlock.unked8;

  m_fSlapFearlessDurationPresent = true;
  m_kBlock.slap_fearless_duration = rkBlock.slap_fearless_duration;

  m_fUnkee0Present = true;
  m_kBlock.unkee0 = rkBlock.unkee0;

  m_fUnkee4Present = true;
  m_kBlock.unkee4 = rkBlock.unkee4;

  m_fPossessionManaCostPresent = true;
  m_kBlock.possession_mana_cost = rkBlock.possession_mana_cost;

  m_fUnk3f_1Present = true;
  m_kBlock.unk3f[1] = rkBlock.unk3f[1];

  m_fMaterialPresent = true;
  m_kBlock.material = rkBlock.material;

  m_fUnk4Present = true;
  m_kBlock.unk4 = rkBlock.unk4;

  m_fUnkcecPresent = true;
  m_kBlock.unkcec = rkBlock.unkcec;

  m_fUnkceePresent = true;
  m_kBlock.unkcee = rkBlock.unkcee;

  m_fUnkcf2Present = true;
  m_kBlock.unkcf2 = rkBlock.unkcf2;

  m_fEditorOrderPresent = true;
  m_kBlock.editor_order = rkBlock.editor_order;

  m_fUnk6Present = true;
  m_kBlock.unk6 = rkBlock.unk6;

  m_fTortureHPChangePresent = true;
  m_kBlock.torture_hp_change = rkBlock.torture_hp_change;

  m_fTortureMoodChangePresent = true;
  m_kBlock.torture_mood_change = rkBlock.torture_mood_change;

  m_fUnkdbcPresent = true;
  m_kBlock.unkdbc = rkBlock.unkdbc;

  m_fUnkdc0Present = true;
  m_kBlock.unkdc0 = rkBlock.unkdc0;

  m_fUnk2e_2Present = true;
  m_kBlock.unk2e[2] = rkBlock.unk2e[2];

  m_fUnk2e_1Present = true;
  m_kBlock.unk2e[1] = rkBlock.unk2e[1];

  m_fUnk2e_3Present = true;
  m_kBlock.unk2e[3] = rkBlock.unk2e[3];

  m_fUnk14dfPresent = true;
  m_kBlock.unk14df = rkBlock.unk14df;

  m_fRef8Present = true;
  m_kBlock.ref8 = rkBlock.ref8;

  m_fUnk1545Present = true;
  m_kBlock.unk1545 = rkBlock.unk1545;

  m_fUnkefcPresent = true;
  m_kBlock.unkefc = rkBlock.unkefc;

  for( int i = 0; i < 37; i++ ) {
    m_fRef1_0_36Present[i] = true;
    m_kBlock.ref1[i] = rkBlock.ref1[i];
  }

  m_fRef3Present = true;
  m_kBlock.ref3 = rkBlock.ref3;

  m_fRef6Present = true;
  m_kBlock.ref6 = rkBlock.ref6;

  m_fRef7_0Present = true;
  m_kBlock.ref7[0] = rkBlock.ref7[0];

  m_fRef7_1Present = true;
  m_kBlock.ref7[1] = rkBlock.ref7[1];

  m_fRef7_2Present = true;
  m_kBlock.ref7[2] = rkBlock.ref7[2];

  for( int i = 0; i < 6; i++ ) {
    m_fRef5Present[i] = true;
    m_kBlock.ref5[i] = rkBlock.ref5[i];
  }

  for( int i = 0; i < 2; i++ ) {
    m_fAttractionPresent[i] = true;
    m_kBlock.attraction[i] = rkBlock.attraction[i];
  }

  for( int i = 0; i < 3; i++ ) {
    m_kBlock.xdc4[i] = rkBlock.xdc4[i];
    m_fUnkdc4Present[i] = true;
  }

  for( int i = 0; i < 4; i++ ) {
    m_kBlock.xe0c[i] = rkBlock.xe0c[i];
    m_fUnke0cPresent[i] = true;
  }

  for( int i = 0; i < 3; i++ ) {
    m_kBlock.unkf48[i] = rkBlock.unkf48[i];
    m_fUnkf48Present[i] = true;
  }

  for( int i = 0; i < 3; i++ ) {
    m_kBlock.xe14[i] = rkBlock.xe14[i];
    m_fUnke14Present[i] = true;
  }

  for( int i = 0; i < 2; i++ ) {
    m_kBlock.xe38[i] = rkBlock.xe38[i];
    m_fUnke38Present[i] = true;
  }

  for( int i = 0; i < 3; i++ ) {
    m_kBlock.xe50[i] = rkBlock.xe50[i];
    m_fUnke50Present[i] = true;
  }

  for( int i = 0; i < 2; i++ ) {
    m_kBlock.xe74[i] = rkBlock.xe74[i];
    m_fUnke74Present[i] = true;
  }

  for( int i = 0; i < 2; i++ ) {
    /* this is NOT the location being written to in the routine... */
    m_kBlock.x14e1[i] = rkBlock.x14e1[i];
    m_fUnk14e1Present[i] = true;
  }

  for( int i = 0; i < 3; i++ ) {
    m_kBlock.xe7c[i] = rkBlock.xe7c[i];
    m_fUnke7cPresent[i] = true;
  }

  for( int i = 0; i < 2; i++ ) {
    m_kBlock.x14e9[i] = rkBlock.x14e9[i];
    m_fUnk14e9Present[i] = true;
  }

  /* these loops continue to make less and less sense... */
  /* provisions for > the end... */
  for( int i = 0; i < 9; i++ ) {
    m_kBlock.unk2d[i] = rkBlock.unk2d[i];
    m_fUnk2dPresent[i] = true;
  }

  m_kBlock.unk2c = rkBlock.unk2c;
  m_fUnk2cPresent = true;

  for( int i = 0; i < 7; i++ ) {
    m_kBlock.unk7[i] = rkBlock.unk7[i];
    m_fUnk7Present[i] = true;
  }

  m_fUnke94Present = true;
  m_kBlock.xe94 = rkBlock.xe94;

  for( int i = 0; i < 3; i++ ) {
    m_kBlock.unk3d[i] = rkBlock.unk3d[i];
    m_fUnk3dPresent[i] = true;
  }

  for( int i = 0; i < 2; i++ ) {
    m_kBlock.unk5[i] = rkBlock.unk5[i];
    m_fUnk5Present[i] = true;
  }

  m_fUnkf45Present = true;
  m_kBlock.unkf45 = rkBlock.unkf45;

  for( int i = 0; i < 48; i++ ) {
    m_kBlock.x1323[i] = rkBlock.x1323[i];
    m_fUnk1323Present[i] = true;
  }
}
