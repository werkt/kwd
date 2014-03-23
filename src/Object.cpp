#include <string.h>

#include "Object.h"

void
ObjectLoadBlock::load( ObjectBlock &rkBlock )
{
  m_fIdPresent = true;
  m_kBlock.id = rkBlock.id;

  m_fUnk6Present = true;
  m_kBlock.unk6 = rkBlock.unk6;

  m_fSlapEffectPresent = true;
  m_kBlock.slap_effect = rkBlock.slap_effect;

  m_fUnk5Present = true;
  m_kBlock.unk5 = rkBlock.unk5;

  m_fDeathEffectPresent = true;
  m_kBlock.death_effect = rkBlock.death_effect;

  m_fNamePresent = true;
  strncpy(m_kBlock.name, rkBlock.name, 32);
  m_kBlock.name[31] = '\0';
  m_fWidthPresent = true;
  m_kBlock.width = rkBlock.width;

  m_fHeightPresent = true;
  m_kBlock.height = rkBlock.height;

  m_fMassPresent = true;
  m_kBlock.mass = rkBlock.mass;

  m_fUnk1Present = true;
  m_kBlock.unk1 = rkBlock.unk1;

  m_fUnk2Present = true;
  m_kBlock.unk2 = rkBlock.unk2;

  m_fUnk4Present = true;
  m_kBlock.unk4 = rkBlock.unk4;

  m_fGuiIconResourcePresent = true;
  m_kBlock.kGuiIconResource = rkBlock.kGuiIconResource;

  m_fInHandIconResourcePresent = true;
  m_kBlock.kInHandIconResource = rkBlock.kInHandIconResource;

  m_fMeshResourcePresent = true;
  m_kBlock.kMeshResource = rkBlock.kMeshResource;

  m_fUnknownResourcePresent = true;
  m_kBlock.kUnknownResource = rkBlock.kUnknownResource;

  m_fInHandMeshResourcePresent = true;
  m_kBlock.kInHandMeshResource = rkBlock.kInHandMeshResource;

  m_fHpPresent = true;
  m_kBlock.hp = rkBlock.hp;

  m_f34cPresent = true;
  m_kBlock.x34c = rkBlock.x34c;

  m_f34ePresent = true;
  m_kBlock.x34e = rkBlock.x34e;

  m_f350Present = true;
  m_kBlock.x350 = rkBlock.x350;

  m_f352Present = true;
  m_kBlock.x352 = rkBlock.x352;

  m_fRoomCapacityPresent = true;
  m_kBlock.room_capacity = rkBlock.room_capacity;

  m_fLightPresent = true;
  m_kBlock.light = rkBlock.light;

  m_fSoundCategoryPresent = true;
  strncpy(m_kBlock.sound_category, rkBlock.sound_category, 32);

  m_fUnk7Present = true;
  m_kBlock.unk7 = rkBlock.unk7;

  m_fMaterialPresent = true;
  m_kBlock.material = rkBlock.material;

  m_fFlagsPresent = true;
  /* dk does an or here.. */
  m_kBlock.flags = rkBlock.flags;

  for( int i = 0; i < 4; i++ ) {
    m_fAdditionalResourcesPresent[i] = true;
    m_kBlock.kAdditionalResources[i] = rkBlock.kAdditionalResources[i];
  }
}
