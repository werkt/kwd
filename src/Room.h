#ifndef ROOM_H
#define ROOM_H

#include "Resource.h"

#pragma pack(push,1)

struct RoomBlock {
  char name[32]; /* 0 */
  ArtResource gui_icon; /* 20 */
  ArtResource room_icon; /* 74 */
  ArtResource complete; /* c8 */
  ArtResource ref[7]; /* 11c */
  uint32_t unk1; /* 368 - very likely flags */
  uint16_t unk2; /* 36c */
  uint16_t intensity; /* 36e */
  uint32_t unk3; /* 370 */
  uint16_t x374;
  uint16_t x376;
  uint16_t x378;
  uint16_t x37a;
  uint16_t x37c;
  uint16_t x37e;
  uint16_t unk5; /* 380 */
  uint16_t effects[8]; /* 382 */
  uint8_t id; /* 392 */
  uint8_t unk7; /* 393 */
  uint8_t terrain; /* 394 */
  uint8_t tile_construction; /* 395 */
  uint8_t unk8; /* 396 */
  uint8_t torch_color[3]; /* 397 */
  uint8_t objects[8]; /* 39a */
  char sound_category[32]; /* 3a2 */
  uint8_t x3c2; /* 3c2 */
  uint8_t x3c3; /* 3c3 */
  uint16_t unk10; /* 3c4 */
  uint8_t unk11; /* 3c6 */
  ArtResource torch; /* 3c7 */
  uint8_t x41b; /* 41b */
  uint8_t x41c; /* 41c */
  short x41d; /* 41d */
};

#pragma pack(pop)

class RoomLoadBlock {
public:
  RoomLoadBlock();
  void load( RoomBlock &rkRoom ); /* 56dfd0 */
  const RoomBlock &block() const { return m_kBlock; }
  bool hasName() const { return m_bNamePresent; } /* 0 */
  bool hasId() const { return m_bIdPresent; } /* 4 */
  bool hasTerrain() const { return m_bTerrainPresent; } /* 8 */
  bool hasSoundCategory() const { return m_bSoundCategoryPresent; } /* c */
  bool hasGuiIcon() const { return m_bGuiIconPresent; } /* 10 */
  bool hasRoomIcon() const { return m_bRoomIconPresent; } /* 14 */
  bool hasComplete() const { return m_bCompletePresent; } /* 18 */
  bool hasRef0() const { return m_bRef0Present; } /* 1c */
  bool hasRef1() const { return m_bRef1Present; } /* 20 */
  bool hasRef2() const { return m_bRef2Present; } /* 24 */
  bool hasRef3() const { return m_bRef3Present; } /* 28 */
  bool hasRef4() const { return m_bRef4Present; } /* 2c */
  bool hasRef5() const { return m_bRef5Present; } /* 30 */
  bool hasTorch() const { return m_bTorchPresent; } /* 34 */
  bool hasRef6() const { return m_bRef6Present; } /* 38 */
  bool has374() const { return m_b374Present; } /* 3c */
  bool has376() const { return m_b376Present; } /* 40 */
  bool has37c() const { return m_b37cPresent; } /* 44 */
  bool has37e() const { return m_b37ePresent; } /* 48 */
  bool hasUnk1() const { return m_bUnk1Present; } /* 4c */
  bool has378() const { return m_b378Present; } /* 50 */
  bool hasUnk2() const { return m_bUnk2Present; } /* 54 */
  bool hasTileConstruction() const { return m_bTileConstructionPresent; } /* 58 */
  bool hasUnk8() const { return m_bUnk8Present; } /* 5c */
  bool hasUnk7() const { return m_bUnk7Present; } /* 60 */
  bool hasTorchRed() const { return m_bTorchRedPresent; } /* 64 */
  bool hasTorchGreen() const { return m_bTorchGreenPresent; } /* 68 */
  bool hasTorchBlue() const { return m_bTorchBluePresent; } /* 6c */
  bool hasUnk5() const { return m_bUnk5Present; } /* 70 */
  bool hasIntensity() const { return m_bIntensityPresent; } /* 74 */
  bool has3c3() const { return m_b3c3Present; } /* 78 */
  bool has37a() const { return m_b37aPresent; } /* 7c */
  bool hasObjects( int index ) const { return m_bObjectsPresent[index]; } /* 80 */
  bool hasEffects( int index ) const { return m_bEffectsPresent[index]; } /* a0 */
  bool has41d() const { return m_b41dPresent; } /* c0 */
  bool has3c2() const { return m_b3c2Present; } /* c4 */
  bool has41b() const { return m_b41bPresent; } /* c8 */
  bool has41c() const { return m_b41cPresent; } /* cc */
  bool hasUnk3() const { return m_bUnk3Present; } /* d0 */

private:
  bool m_bNamePresent; /* 0 */
  bool m_bIdPresent; /* 4 */
  bool m_bTerrainPresent; /* 8 */
  bool m_bSoundCategoryPresent; /* c */
  bool m_bGuiIconPresent; /* 10 */
  bool m_bRoomIconPresent; /* 14 */
  bool m_bCompletePresent; /* 18 */
  bool m_bRef0Present; /* 1c */
  bool m_bRef1Present; /* 20 */
  bool m_bRef2Present; /* 24 */
  bool m_bRef3Present; /* 28 */
  bool m_bRef4Present; /* 2c */
  bool m_bRef5Present; /* 30 */
  bool m_bTorchPresent; /* 34 */
  bool m_bRef6Present; /* 38 */
  bool m_b374Present; /* 3c */
  bool m_b376Present; /* 40 */
  bool m_b37cPresent; /* 44 */
  bool m_b37ePresent; /* 48 */
  bool m_bUnk1Present; /* 4c */
  bool m_b378Present; /* 50 */
  bool m_bUnk2Present; /* 54 */
  bool m_bTileConstructionPresent; /* 58 */
  bool m_bUnk8Present; /* 5c */
  bool m_bUnk7Present; /* 60 */
  bool m_bTorchRedPresent; /* 64 */
  bool m_bTorchGreenPresent; /* 68 */
  bool m_bTorchBluePresent; /* 6c */
  bool m_bUnk5Present; /* 70 */
  bool m_bIntensityPresent; /* 74 */
  bool m_b3c3Present; /* 78 */
  bool m_b37aPresent; /* 7c */
  bool m_bObjectsPresent[8]; /* 80 */
  bool m_bEffectsPresent[8]; /* a0 */
  bool m_b41dPresent; /* c0 */
  bool m_b3c2Present; /* c4 */
  bool m_b41bPresent; /* c8 */
  bool m_b41cPresent; /* cc */
  bool m_bUnk3Present; /* d0 */
  RoomBlock m_kBlock; /* d4 */
};

#endif
