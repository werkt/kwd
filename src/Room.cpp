#include <string.h>

#include "Room.h"

/* lots more - 56de40 */
RoomLoadBlock::RoomLoadBlock()
{
  memset(&m_kBlock, '\0', sizeof(m_kBlock));
}

void
RoomLoadBlock::load( RoomBlock &rkRoom )
{
  m_bNamePresent = true;
  strncpy(m_kBlock.name, rkRoom.name, 32);
  m_kBlock.name[31] = '\0';

  m_bIdPresent = true;
  m_kBlock.id = rkRoom.id;
  m_bTerrainPresent = true;
  m_kBlock.terrain = rkRoom.terrain;
  m_b374Present = true;
  m_kBlock.x374 = rkRoom.x374;
  m_b376Present = true;
  m_kBlock.x376 = rkRoom.x376;
  m_b37cPresent = true;
  m_kBlock.x37c = rkRoom.x37c;
  m_b37ePresent = true;
  m_kBlock.x37e = rkRoom.x37e;

  m_bGuiIconPresent = true;
  m_kBlock.gui_icon = rkRoom.gui_icon;
  m_bRoomIconPresent = true;
  m_kBlock.room_icon = rkRoom.room_icon;
  m_bCompletePresent = true;
  m_kBlock.complete = rkRoom.complete;
  m_bRef0Present = true;
  m_kBlock.ref[0] = rkRoom.ref[0];
  m_bRef1Present = true;
  m_kBlock.ref[1] = rkRoom.ref[1];
  m_bRef2Present = true;
  m_kBlock.ref[2] = rkRoom.ref[2];
  m_bRef3Present = true;
  m_kBlock.ref[3] = rkRoom.ref[3];
  m_bRef4Present = true;
  m_kBlock.ref[4] = rkRoom.ref[4];
  m_bRef5Present = true;
  m_kBlock.ref[5] = rkRoom.ref[5];
  m_bTorchPresent = true;
  m_kBlock.torch = rkRoom.torch;
  m_bRef6Present = true;
  m_kBlock.ref[6] = rkRoom.ref[6];
  
  m_bUnk1Present = true;
  m_kBlock.unk1 = rkRoom.unk1;
  m_b378Present = true;
  m_kBlock.x378 = rkRoom.x378;
  m_bTileConstructionPresent = true;
  m_kBlock.tile_construction = rkRoom.tile_construction;
  m_bUnk8Present = true;
  m_kBlock.unk8 = rkRoom.unk8;
  m_bUnk7Present = true;
  m_kBlock.unk7 = rkRoom.unk7;
  m_bTorchRedPresent = true;
  m_kBlock.torch_color[0] = rkRoom.torch_color[0];
  m_bTorchGreenPresent = true;
  m_kBlock.torch_color[1] = rkRoom.torch_color[1];
  m_bTorchBluePresent = true;
  m_kBlock.torch_color[2] = rkRoom.torch_color[2];
  m_bUnk5Present = true;
  m_kBlock.unk5 = rkRoom.unk5;
  m_bIntensityPresent = true;
  m_kBlock.intensity = rkRoom.intensity;
  m_b3c3Present = true;
  m_kBlock.x3c3 = rkRoom.x3c3;
  m_b37aPresent = true;
  m_kBlock.x37a = rkRoom.x37a;
  m_bUnk2Present = true;
  m_kBlock.unk2 = rkRoom.unk2;

  m_bSoundCategoryPresent = true;
  strncpy(m_kBlock.sound_category, rkRoom.sound_category, 32);
  m_kBlock.sound_category[31] = '\0';

  m_b3c2Present = true;
  m_kBlock.x3c2 = rkRoom.x3c2;
  m_b41bPresent = true;
  m_kBlock.x41b = rkRoom.x41b;
  m_b41cPresent = true;
  m_kBlock.x41c = rkRoom.x41c;
  m_b41dPresent = true;
  m_kBlock.x41d = rkRoom.x41d;

  m_bUnk3Present = true;
  m_kBlock.unk3 |= rkRoom.unk3;

  for( int i = 0; i < 8; i++ ) {
    m_bObjectsPresent[i] = true;
    m_kBlock.objects[i] = rkRoom.objects[i];
  }

  for( int i = 0; i < 8; i++ ) {
    m_bEffectsPresent[i] = true;
    m_kBlock.effects[i] = rkRoom.effects[i];
  }
}
