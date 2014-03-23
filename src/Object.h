#ifndef OBJECT_H
#define OBJECT_H

#include "Resource.h"
#include "Light.h"

#pragma pack(push,1)

struct ObjectBlock {
  char name[32]; /* 0 */
  ArtResource kMeshResource; /* 20 */
  ArtResource kGuiIconResource; /* 74 */
  ArtResource kInHandIconResource; /* c8 */
  ArtResource kInHandMeshResource; /* 11c */
  ArtResource kUnknownResource; /* 170 */
  ArtResource kAdditionalResources[4]; /* 1c4 */
  LightBlock light; /* 314 */
  uint32_t width; /* 32c fixed 0x1000 */
  uint32_t height; /* 330 */
  uint32_t mass; /* 334 */
  uint32_t unk1; /* 338 */
  uint32_t unk2; /* 33c */
  uint8_t material; /* 340 */
  uint8_t unk3[3]; /* 341 */
  uint32_t flags; /* 344 */
  uint16_t hp; /* 348 */
  uint16_t unk4;
  uint16_t x34c;
  uint16_t x34e;
  uint16_t x350;
  uint16_t x352; /* 34a */
  uint16_t slap_effect; /* 354 */
  uint16_t death_effect; /* 356 */
  uint16_t unk5; /* 358 */
  uint8_t id; /* 35a */
  uint8_t unk6; /* 35b */
  uint8_t room_capacity; /* 35c */
  uint8_t unk7; /* 35d */
  char sound_category[32]; /* 35e */
};

#pragma pack(pop)

class ObjectLoadBlock {
public:
  void load( ObjectBlock &rkBlock );
  const ObjectBlock &block() const { return m_kBlock; }
  bool hasName() const { return m_fNamePresent; }
  bool hasId() const { return m_fIdPresent; }
  bool hasSoundCategory() const { return m_fSoundCategoryPresent; }
  bool hasMeshResource() const { return m_fMeshResourcePresent; }
  bool hasGuiIconResource() const { return m_fGuiIconResourcePresent; }
  bool hasInHandIconResource() const { return m_fInHandIconResourcePresent; }
  bool hasUnknownResource() const { return m_fUnknownResourcePresent; }
  bool hasInHandMeshResource() const { return m_fInHandMeshResourcePresent; }
  bool hasAdditionalResource( int index ) const {
    return m_fAdditionalResourcesPresent[index];
  }
  bool hasLight() const { return m_fLightPresent; }
  bool hasWidth() const { return m_fWidthPresent; }
  bool hasHeight() const { return m_fHeightPresent; }
  bool hasMass() const { return m_fMassPresent; }
  bool hasUnk2() const { return m_fUnk2Present; }
  bool hasUnk1() const { return m_fUnk1Present; }
  bool hasUnk4() const { return m_fUnk4Present; }
  bool hasHp() const { return m_fHpPresent; }
  bool has34c() const { return m_f34cPresent; }
  bool has34e() const { return m_f34ePresent; }
  bool has350() const { return m_f350Present; }
  bool has352() const { return m_f352Present; }
  bool hasSlapEffect() const { return m_fSlapEffectPresent; }
  bool hasUnk5() const { return m_fUnk5Present; }
  bool hasDeathEffect() const { return m_fDeathEffectPresent; }
  bool hasUnk6() const { return m_fUnk6Present; }
  bool hasRoomCapacity() const { return m_fRoomCapacityPresent; }
  bool hasUnk7() const { return m_fUnk7Present; }
  bool hasMaterial() const { return m_fMaterialPresent; }
  bool hasFlags() const { return m_fFlagsPresent; }

private:
  bool m_fNamePresent; /* 0 */
  bool m_fIdPresent; /* 4 */
  bool m_fSoundCategoryPresent; /* 8 */
  bool m_fMeshResourcePresent; /* c */
  bool m_fGuiIconResourcePresent; /* 10 */
  bool m_fInHandIconResourcePresent; /* 14 */
  bool m_fUnknownResourcePresent; /* 18 */
  bool m_fInHandMeshResourcePresent; /* 1c */
  bool m_fAdditionalResourcesPresent[4]; /* 20 */
  bool m_fLightPresent; /* 30 */
  bool m_fWidthPresent; /* 34 */
  bool m_fHeightPresent; /* 38 */
  bool m_fMassPresent; /* 3c */
  bool m_fUnk2Present; /* 40 */
  bool m_fUnk1Present; /* 44 */
  bool m_fUnk4Present; /* 48 */
  bool m_fHpPresent; /* 4c */
  bool m_f34cPresent; /* 50 */
  bool m_f34ePresent; /* 54 */
  bool m_f350Present; /* 58 */
  bool m_f352Present; /* 5c */
  bool m_fSlapEffectPresent; /* 60 */
  bool m_fUnk5Present; /* 64 */
  bool m_fDeathEffectPresent; /* 68 */
  bool m_fUnk6Present; /* 6c */
  bool m_fRoomCapacityPresent; /* 70 */
  bool m_fUnk7Present; /* 74 */
  bool m_fMaterialPresent; /* 78 */
  bool m_fFlagsPresent; /* 7c */
  ObjectBlock m_kBlock; /* 80 */
};

#endif
