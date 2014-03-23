#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <new>

#include "KWD.h"
#include "File.h"
#include "EffectElement.h"
#include "Effect.h"
#include "Terrain.h"
#include "Object.h"
#include "Room.h"
#include "Creature.h"
#include "CreatureSpell.h"
#include "KeeperSpell.h"
#include "Trap.h"
#include "Door.h"
#include "Player.h"
#include "Variable.h"
#include "Map.h"
#include "Trigger.h"
#include "Thing.h"

int
ucs2lencpy( ucs2le_t *dst, const ucs2le_t *src, int n )
{
  while( n-- && *src == 0 )
    *dst++ = *src++;
  if( n )
    *dst = 0;
}

KWDContext::KWDContext()
{
  m_pfLoadStep = NULL;
  m_pLoadStepArg = NULL; /* 4 */
  m_pfTerrainHeader = NULL; /* 8 */
  m_pfTerrainData = NULL; /* c */
  m_pTerrainArg = NULL; /* 10 */
  m_pfMapHeader = NULL; /* 14 */
  m_pfMapData = NULL; /* 18 */
  m_pMapArg = NULL; /* 1c */
  m_pfRoomsHeader = NULL; /* 20 */
  m_pfRoomsData = NULL; /* 24 */
  m_pRoomsArg = NULL; /* 28 */
  m_pfDoorsHeader = NULL; /* 2c */
  m_pfDoorsData = NULL; /* 30 */
  m_pDoorsArg = NULL; /* 34 */
  m_pfTrapsHeader = NULL; /* 38 */
  m_pfTrapsData = NULL; /* 3c */
  m_pTrapsArg = NULL; /* 40 */
  m_pfKeeperSpellsHeader = NULL; /* 44 */
  m_pfKeeperSpellsData = NULL; /* 48 */
  m_pKeeperSpellsArg = NULL; /* 4c */
  m_pfCreatureSpellsHeader = NULL; /* 50 */
  m_pfCreatureSpellsData = NULL; /* 54 */
  m_pCreatureSpellsArg = NULL; /* 58 */
  m_pfCreaturesHeader = NULL; /* 5c */
  m_pfCreaturesData = NULL; /* 60 */
  m_pCreaturesArg = NULL; /* 64 */
  m_pfPlayersHeader = NULL; /* 68 */
  m_pfPlayersData = NULL; /* 6c */
  m_pPlayersArg = NULL; /* 70 */
  m_pfThingsHeader = NULL; /* 74 */
  m_pfThingsType01 = NULL; /* 78 */
  m_pfThingsType02 = NULL; /* 7c */
  m_pfThingsType03 = NULL; /* 80 */
  m_pfThingsType04 = NULL; /* 84 */
  m_pfThingsType05 = NULL; /* 88 */
  m_pfThingsType06 = NULL; /* 8c */
  m_pfThingsType07 = NULL; /* 90 */
  m_pfThingsType08 = NULL; /* 94 */
  m_pfThingsType09 = NULL; /* 98 */
  m_pfThingsType10 = NULL; /* 9c */
  m_pfThingsType11 = NULL; /* a0 */
  m_pfThingsType12 = NULL; /* a4 */
  m_pfThingsType13 = NULL; /* a8 */
  m_pThingsArg = NULL; /* ac */
  m_pfTriggersHeader = NULL; /* b0 */
  m_pfTriggersType1 = NULL; /* b4 likely trigger */
  m_pfTriggersType2 = NULL; /* b8 and action */
  m_pTriggersArg = NULL; /* bc */
  m_pfLevelHeader = NULL; /* c0 */
  m_pfLevelType1 = NULL; /* c4 */
  m_pfLevelType2 = NULL; /* c8 */
  m_pfLevelType3 = NULL; /* cc */
  m_pLevelArg = NULL; /* d0 */
  m_pfVariablesHeader = NULL; /* d4 */
  m_pfVariablesData = NULL; /* d8 */
  m_pVariablesArg = NULL; /* dc */
  m_pfObjectsHeader = NULL; /* e0 */
  m_pfObjectsData = NULL; /* e4 */
  m_pObjectsArg = NULL; /* e8 */
  m_pfEffectElementsHeader = NULL; /* ec */
  m_pfEffectElementsData = NULL; /* f0 */
  m_pEffectElementsArg = NULL; /* f4 */
  m_pfEffectsHeader = NULL; /* f8 */
  m_pfEffectsData = NULL; /* fc */
  m_pEffectsArg = NULL; /* 100 */
  m_pfShotsHeader = NULL; /* 104 */
  m_pfShotsData = NULL; /* 108 */
  m_pShotsArg = NULL; /* 10c */
}

void
class_56bf40::sub_56c100( const LevelInfoBlock &rkBlock )
{
  m_fNamePresent = true;
  ucs2lencpy(m_kBlock.m_wsName, rkBlock.m_wsName, 64);
  m_kBlock.m_wsName[63] = 0;

  m_fDescriptionPresent = true;
  ucs2lencpy(m_kBlock.m_wsDescription, rkBlock.m_wsDescription, 1024);
  m_kBlock.m_wsDescription[1023] = 0;

  m_fAuthorPresent = true;
  ucs2lencpy(m_kBlock.m_wsAuthor, rkBlock.m_wsAuthor, 64);
  m_kBlock.m_wsAuthor[63] = 0;

  m_fEmailPresent = true;
  ucs2lencpy(m_kBlock.m_wsEmail, rkBlock.m_wsEmail, 64);
  m_kBlock.m_wsEmail[63] = 0;

  m_fInformationPresent = true;
  ucs2lencpy(m_kBlock.m_wsInformation, rkBlock.m_wsInformation, 1024);
  m_kBlock.m_wsInformation[1023] = 0;

  m_fShortId0Present = true;
  m_kBlock.m_wShortId0 = rkBlock.m_wShortId0;

  m_fShortId1Present = true;
  m_kBlock.m_wShortId1 = rkBlock.m_wShortId1;

  for( int i = 0; i < 20; i++ ) {
    m_fUnknown0138cPresent[i] = true;
    ucs2lencpy(m_kBlock.m_wsUnknown0138c[i], rkBlock.m_wsUnknown0138c[i], 512);
  }
  for( int i = 0; i < 4; i++ ) {
    m_fUnknown063afPresent[i] = true;
    m_kBlock.x063af[i] = rkBlock.x063af[i];
  }
  m_fUnknown06405Present = true;
  m_kBlock.x06405 = rkBlock.x06405;
  for( int i = 0; i < 4; i++ ) {
    m_fUnknown063b3Present[i] = true;
    m_kBlock.x063b3[i] = rkBlock.x063b3[i];
  }
  m_fUnknown06406Present = true;
  m_kBlock.x06406 = rkBlock.x06406;
  m_fUnknown063aePresent = true;
  m_kBlock.x063ae = rkBlock.x063ae;
  m_fUnknown06403Present = true;
  m_kBlock.x06403 = rkBlock.x06403;
  m_fUnknown06407Present = true;
  m_kBlock.x06407 = rkBlock.x06407;

  m_fUnknown0638ePresent = true;
  strncpy(m_kBlock.x0638e, rkBlock.x0638e, 32);
  m_kBlock.x0638e[31] = '\0';

  m_fUnknown063b8Present = true;
  m_kBlock.x063b8 = rkBlock.x063b8;
  m_fUnknown063b9Present = true;
  m_kBlock.x063b9 = rkBlock.x063b9;
  m_fUnknown063bbPresent = true;
  m_kBlock.x063bb = rkBlock.x063bb;
  m_fUnknown063bdPresent = true;
  m_kBlock.x063bd = rkBlock.x063bd;
  m_fUnknown063bfPresent = true;
  m_kBlock.x063bf = rkBlock.x063bf;
  m_fUnknown063c5Present = true;
  m_kBlock.x063c5 = rkBlock.x063c5;
  m_fUnknown063c7Present = true;
  m_kBlock.x063c7 = rkBlock.x063c7;
  m_fUnknown063c3Present = true;
  m_kBlock.x063c3 = rkBlock.x063c3;
  m_fUnknown063c9Present = true;
  m_kBlock.x063c9 = rkBlock.x063c9;
  m_fUnknown063caPresent = true;
  m_kBlock.x063ca = rkBlock.x063ca;

  for( int i = 0; i < 8; i++ ) {
    m_fUnknown063cbPresent[i] = true;
    m_kBlock.x063cb[i] = rkBlock.x063cb[i];
  }

  for( int i = 0; i < 8; i++ ) {
    m_fUnknown063d3Present[i] = true;
    m_kBlock.x063d3[i] = rkBlock.x063d3[i];
  }

  m_fUnknown063e3Present = true;
  strncpy(m_kBlock.x063e3, rkBlock.x063e3, 32);
  m_kBlock.x063e3[31] = '\0';

  m_fUnknown06404Present = true;
  m_kBlock.x06404 = rkBlock.x06404;

  for( int i = 0; i < 5; i++ ) {
    m_fUnknown06409Present[i] = true;
    m_kBlock.x06409[i] = rkBlock.x06409[i];
  }

  m_fUnknown06413Present = true;
  ucs2lencpy(m_kBlock.x06413, rkBlock.x06413, 32);

  m_fUnknown0638cPresent = true;
  m_kBlock.x0638c |= rkBlock.x0638c;
}

static union {
  unsigned char dataMap[0x10000];
  struct {
    LevelInfoBlock information;
    char unk_74d313[25991]; /* above fits in x134 element */
  } dataLevel;
  struct {
    EffectElementBlock block;
    char unk_746f76[1024];
  } dataEffectElements;
  struct {
    EffectBlock block;
    char unk_746fb6[1024];
  } dataEffects;
  struct {
    TerrainBlock block;
    char unk_7470e8[1024];
  } dataTerrain;
  struct {
    ObjectBlock block;
    char unk_74723e[1024];
  } dataObjects;
  struct {
    RoomBlock block;
    char unk_7472df[1024];
  } dataRooms;
  struct {
    CreatureBlock block;
    char unk_748409[1024];
  } dataCreatures;
  struct {
    CreatureSpellBlock block;
    char unk_746fca[1024];
  } dataCreatureSpells;
  struct {
    TrapBlock block;
    char unk_747103[1024];
  } dataTraps;
  struct {
    DoorBlock block;
    char unk_747128[1024];
  } dataDoors;
  struct {
    KeeperSpellBlock block;
    char unk_747056[1024];
  } dataKeeperSpells;
};

struct kwdHeader {
  unsigned int id;
  unsigned int size;
  union {
    struct {
      uint16_t w08;
      uint16_t w0a;
    } level;
    unsigned int dw08;
  };
  unsigned int x0c[7];
};

bool
sub_56c4e0( TbDiscFile **file, KWDContext *ctx )
{
  size_t bytesRead;
  bool var_f8;
  kwdHeader header;
  uint32_t level_after_dd[2];

  /* return is tested, unsure exactly with what acceptance */
  sub_5b3eb0(var_f8, *file, &header, 36, &bytesRead);
  if( header.id != 221 ) return false;
  if( ctx->m_pfLevelHeader ) {
    /* takes the header and passes it to the function, with the
     * world passed in ctx as this */
    ctx->m_pfLevelHeader(&header.level.w08, ctx->m_pLevelArg);
  }
  sub_5b3eb0(var_f8, *file, level_after_dd, 8, &bytesRead);
  if( level_after_dd[0] != 223 ) return false;
  if( level_after_dd[1] != 0x6453 ) abort(); /* it appears 6453 as length is special */
  sub_5b3eb0(var_f8, *file, &dataLevel.information, 0x6453, &bytesRead);
  if( ctx->m_pfLevelType1 ) {
    register class_56bf40 *edi = new (dataLevel.unk_74d313) class_56bf40();
    edi->sub_56c100(dataLevel.information);
    if( ctx->m_pfLevelType1(edi, ctx->m_pLevelArg) == false ) return false;
  }
  uint32_t var_a0[2];
  sub_5b3eb0(var_f8, *file, var_a0, 8, &bytesRead);
  if( var_a0[0] != 222 ) return false;
  if( ctx->m_pfLevelType2 == NULL ) {
    off_t offset = sub_5b3a80(*file) + header.level.w08 * 72;
    return sub_5b3a90(*file, header.level.w08 * 72, SEEK_CUR) == offset;
  }
  var_f8 = false;
  for( uint16_t i = 0; i < header.level.w08; i++ ) {
    unsigned int var_48[18];
    sub_5b3eb0(var_f8, *file, var_48, 72, &bytesRead);
    unsigned int var_98[20];
    memset(var_98, 0, sizeof(var_98));
    var_98[0] = 1;
    var_98[1] = 1;
    var_98[2] = var_48[2];
    strncpy((char *) &var_98[4], (const char *) &var_48[2], 64);
    if( !ctx->m_pfLevelType2(var_98, ctx->m_pLevelArg) ) return false;
  }
  if( ctx->m_pfLevelType3 == NULL ) abort();
  for( uint16_t i = 0; i < header.level.w0a; i++ ) {
    bool var_ec;
    int var_f0;
    sub_5b3eb0(var_ec, *file, &var_f0, 4, &bytesRead);
    unsigned int var_f8[2];
    var_f8[0] = 1;
    var_f8[1] = (unsigned char) var_f0;
    if( !ctx->m_pfLevelType3(var_f8, ctx->m_pLevelArg) ) return false;
  }
  return true;
}

static bool
kwdEffectElements( TbDiscFile **file, KWDContext *ctx )
{
  size_t bytesRead;
  bool ret;
  kwdHeader header;
  unsigned int dataTag[2];

  sub_5b3eb0(ret, *file, &header, 36, &bytesRead);
  if( header.id != 251 ) return false;
  if( ctx->m_pfEffectElementsHeader )
    if( !ctx->m_pfEffectElementsHeader(&header.dw08,
                                       ctx->m_pEffectElementsArg) )
      return false;
  sub_5b3eb0(ret, *file, dataTag, 8, &bytesRead);
  if( dataTag[0] != 252 ) return false;
  int length;
  if( ctx->m_pfEffectElementsData &&
      (length = dataTag[1] / header.dw08) > 0 ) {
    for( unsigned int i = 0; i < header.dw08; i++ ) {
      EffectElementLoadBlock *ebx = new (dataEffectElements.unk_746f76) EffectElementLoadBlock();
      if( length != 182 ) abort();
      sub_5b3eb0(ret, *file, &dataEffectElements.block, 182, &bytesRead);
      ebx->load(dataEffectElements.block);
      if( !ctx->m_pfEffectElementsData(ebx, ctx->m_pEffectElementsArg) )
        return false;
    }
    return true;
  } else {
    off_t offset = sub_5b3a80(*file) + dataTag[1];
    return sub_5b3a90(*file, dataTag[1], SEEK_CUR) == offset;
  }
}

static bool
kwdEffects( TbDiscFile **file, KWDContext *ctx )
{
  size_t bytesRead;
  bool ret;
  kwdHeader header;
  unsigned int dataTag[2];

  sub_5b3eb0(ret, *file, &header, 36, &bytesRead);
  if( header.id != 271 ) return false;
  if( ctx->m_pfEffectsHeader )
    if( !ctx->m_pfEffectsHeader(&header.dw08, ctx->m_pEffectsArg) )
      return false;
  sub_5b3eb0(ret, *file, dataTag, 8, &bytesRead);
  if( dataTag[0] != 272 ) return false;
  int length;
  if( ctx->m_pfEffectsData &&
      (length = dataTag[1] / header.dw08) > 0 ) {
    for( unsigned int i = 0; i < header.dw08; i++ ) {
      EffectLoadBlock *ebx = new (dataEffects.unk_746fb6) EffectLoadBlock();
      if( length != 246 ) abort();
      sub_5b3eb0(ret, *file, &dataEffects.block, 246, &bytesRead);
      ebx->load(dataEffects.block);
      if( !ctx->m_pfEffectsData(ebx, ctx->m_pEffectsArg) )
        return false;
    }
    return true;
  } else {
    off_t offset = sub_5b3a80(*file) + dataTag[1];
    return sub_5b3a90(*file, dataTag[1], SEEK_CUR) == offset;
  }
}

static bool
kwdTerrain( TbDiscFile **file, KWDContext *ctx )
{
  size_t bytesRead;
  bool ret;
  kwdHeader header;
  unsigned int dataTag[2];

  sub_5b3eb0(ret, *file, &header, 36, &bytesRead);
  if( header.id != 111 ) return false;
  if( ctx->m_pfTerrainHeader )
    if( !ctx->m_pfTerrainHeader(&header.dw08, ctx->m_pTerrainArg) )
      return false;
  sub_5b3eb0(ret, *file, dataTag, 8, &bytesRead);
  if( dataTag[0] != 112 ) return false;
  int length;
  if( ctx->m_pfTerrainData ) {
    if( (length = dataTag[1] / header.dw08) <= 0 ) return true;
    for( unsigned int i = 0; i < header.dw08; i++ ) {
      TerrainLoadBlock *ebx = new (dataTerrain.unk_7470e8) TerrainLoadBlock();
      if( length != 552 ) abort();
      sub_5b3eb0(ret, *file, &dataTerrain.block, 552, &bytesRead);
      ebx->load(dataTerrain.block);
      if( !ctx->m_pfTerrainData(ebx, ctx->m_pTerrainArg) )
        return false;
    }
    return true;
  } else {
    unsigned int offset = sub_5b3a80(*file) + dataTag[1];
    return sub_5b3a90(*file, dataTag[1], SEEK_CUR) == offset;
  }
}

static bool
kwdObjects( TbDiscFile **file, KWDContext *ctx )
{
  size_t bytesRead;
  bool ret;
  kwdHeader header;
  unsigned int dataTag[2];

  sub_5b3eb0(ret, *file, &header, 36, &bytesRead);
  if( header.id != 241 ) return false;
  if( ctx->m_pfObjectsHeader )
    if( !ctx->m_pfObjectsHeader(&header.dw08, ctx->m_pObjectsArg) )
      return false;
  sub_5b3eb0(ret, *file, dataTag, 8, &bytesRead);
  if( dataTag[0] != 242 ) return false;
  int length;
  if( ctx->m_pfObjectsData ) {
    if( (length = dataTag[1] / header.dw08) <= 0 ) return true;
    for( unsigned int i = 0; i < header.dw08; i++ ) {
      ObjectLoadBlock *ebx = new (dataObjects.unk_74723e) ObjectLoadBlock();
      if( length != 894 ) abort();
      sub_5b3eb0(ret, *file, &dataObjects.block, 894, &bytesRead);
      ebx->load(dataObjects.block);
      if( !ctx->m_pfObjectsData(ebx, ctx->m_pObjectsArg) )
        return false;
    }
    return true;
  } else {
    unsigned int offset = sub_5b3a80(*file) + dataTag[1];
    return sub_5b3a90(*file, dataTag[1], SEEK_CUR) == offset;
  }
}

static bool
kwdRooms( TbDiscFile **file, KWDContext *ctx )
{
  size_t bytesRead;
  bool ret;
  kwdHeader header;
  unsigned int dataTag[2];

  sub_5b3eb0(ret, *file, &header, 36, &bytesRead);
  if( header.id != 121 ) return false;
  if( ctx->m_pfRoomsHeader )
    if( !ctx->m_pfRoomsHeader(&header.dw08, ctx->m_pRoomsArg) )
      return false;
  sub_5b3eb0(ret, *file, dataTag, 8, &bytesRead);
  if( dataTag[0] != 122 ) return false;
  int length;
  if( ctx->m_pfRoomsData ) {
    if( (length = dataTag[1] / header.dw08) <= 0 ) return true;
    for( unsigned int i = 0; i < header.dw08; i++ ) {
      RoomLoadBlock *loadBlock = new (dataRooms.unk_7472df) RoomLoadBlock;
      if( length != 1055 ) abort();
      sub_5b3eb0(ret, *file, &dataRooms.block, 1055, &bytesRead);
      loadBlock->load(dataRooms.block);
      if( !ctx->m_pfRoomsData(loadBlock, ctx->m_pRoomsArg) )
        return false;
    }
    return true;
  } else {
    unsigned int offset = sub_5b3a80(*file) + dataTag[1];
    return sub_5b3a90(*file, dataTag[1], SEEK_CUR) == offset;
  }
}

static bool
kwdCreatures( TbDiscFile **file, KWDContext *ctx )
{
  size_t bytesRead;
  bool ret;
  kwdHeader header;
  unsigned int dataTag[2];

  sub_5b3eb0(ret, *file, &header, 36, &bytesRead);
  if( header.id != 171 ) return false;
  if( ctx->m_pfCreaturesHeader )
    if( !ctx->m_pfCreaturesHeader(&header.dw08, ctx->m_pCreaturesArg) )
      return false;
  sub_5b3eb0(ret, *file, dataTag, 8, &bytesRead);
  if( dataTag[0] != 172 ) return false;
  int length;
  if( ctx->m_pfCreaturesData ) {
    if( (length = dataTag[1] / header.dw08) <= 0 ) return true;
    for( unsigned int i = 0; i < header.dw08; i++ ) {
      CreatureLoadBlock *ebx = new (dataCreatures.unk_748409) CreatureLoadBlock();
      if( length != 5449 ) abort();
      sub_5b3eb0(ret, *file, &dataCreatures.block, 5449, &bytesRead);
      ebx->load(dataCreatures.block);
      if( !ctx->m_pfCreaturesData(ebx, ctx->m_pCreaturesArg) )
        return false;
    }
    return true;
  } else {
    unsigned int offset = sub_5b3a80(*file) + dataTag[1];
    return sub_5b3a90(*file, dataTag[1], SEEK_CUR) == offset;
  }
}

static bool
kwdCreatureSpells( TbDiscFile **file, KWDContext *ctx )
{
  size_t bytesRead;
  bool ret;
  kwdHeader header;
  unsigned int dataTag[2];

  sub_5b3eb0(ret, *file, &header, 36, &bytesRead);
  if( header.id != 161 ) return false;
  if( ctx->m_pfCreatureSpellsHeader )
    if( !ctx->m_pfCreatureSpellsHeader(&header.dw08, ctx->m_pCreatureSpellsArg) )
      return false;
  sub_5b3eb0(ret, *file, dataTag, 8, &bytesRead);
  if( dataTag[0] != 162 ) return false;
  int length;
  if( ctx->m_pfCreatureSpellsData ) {
    if( (length = dataTag[1] / header.dw08) <= 0 ) return true;
    for( unsigned int i = 0; i < header.dw08; i++ ) {
      class_56a490 *ebx = new (dataCreatureSpells.unk_746fca) class_56a490();
      if( length != 266 ) abort();
      sub_5b3eb0(ret, *file, &dataCreatureSpells.block, 266, &bytesRead);
      ebx->sub_56a560(dataCreatureSpells.block);
      if( !ctx->m_pfCreatureSpellsData(ebx, ctx->m_pCreatureSpellsArg) )
        return false;
    }
    return true;
  } else {
    unsigned int offset = sub_5b3a80(*file) + dataTag[1];
    return sub_5b3a90(*file, dataTag[1], SEEK_CUR) == offset;
  }
}

static bool
kwdTraps( TbDiscFile **file, KWDContext *ctx )
{
  size_t bytesRead;
  bool ret;
  kwdHeader header;
  unsigned int dataTag[2];

  sub_5b3eb0(ret, *file, &header, 36, &bytesRead);
  if( header.id != 131 ) return false;
  if( ctx->m_pfTrapsHeader )
    if( !ctx->m_pfTrapsHeader(&header.dw08, ctx->m_pTrapsArg) )
      return false;
  sub_5b3eb0(ret, *file, dataTag, 8, &bytesRead);
  if( dataTag[0] != 132 ) return false;
  int length;
  if( ctx->m_pfTrapsData ) {
    if( (length = dataTag[1] / header.dw08) <= 0 ) return true;
    for( unsigned int i = 0; i < header.dw08; i++ ) {
      class_570b60 *ebx = new (dataTraps.unk_747103) class_570b60();
      if( length != 579 ) abort();
      sub_5b3eb0(ret, *file, &dataTraps.block, 579, &bytesRead);
      ebx->sub_570d10(dataTraps.block);
      if( !ctx->m_pfTrapsData(ebx, ctx->m_pTrapsArg) )
        return false;
    }
    return true;
  } else {
    unsigned int offset = sub_5b3a80(*file) + dataTag[1];
    return sub_5b3a90(*file, dataTag[1], SEEK_CUR) == offset;
  }
}

static bool
kwdDoors( TbDiscFile **file, KWDContext *ctx )
{
  size_t bytesRead;
  bool ret;
  kwdHeader header;
  unsigned int dataTag[2];

  sub_5b3eb0(ret, *file, &header, 36, &bytesRead);
  if( header.id != 141 ) return false;
  if( ctx->m_pfDoorsHeader )
    if( !ctx->m_pfDoorsHeader(&header.dw08, ctx->m_pDoorsArg) )
      return false;
  sub_5b3eb0(ret, *file, dataTag, 8, &bytesRead);
  if( dataTag[0] != 142 ) return false;
  int length;
  if( ctx->m_pfDoorsData ) {
    if( (length = dataTag[1] / header.dw08) <= 0 ) return true;
    for( unsigned int i = 0; i < header.dw08; i++ ) {
      class_56a920 *ebx = new (dataDoors.unk_747128) class_56a920();
      if( length != 616 ) abort();
      sub_5b3eb0(ret, *file, &dataDoors.block, 616, &bytesRead);
      ebx->sub_56aa40(dataDoors.block);
      if( !ctx->m_pfDoorsData(ebx, ctx->m_pDoorsArg) )
        return false;
    }
    return true;
  } else {
    unsigned int offset = sub_5b3a80(*file) + dataTag[1];
    return sub_5b3a90(*file, dataTag[1], SEEK_CUR) == offset;
  }
}

static bool
kwdShots( TbDiscFile **file, KWDContext *ctx )
{
  size_t bytesRead;
  bool ret;
  kwdHeader header;
  unsigned int dataTag[2];

  sub_5b3eb0(ret, *file, &header, 36, &bytesRead);
  if( header.id != 141 ) return false;
  if( ctx->m_pfShotsHeader )
    if( !ctx->m_pfShotsHeader(&header.dw08, ctx->m_pShotsArg) )
      return false;
  sub_5b3eb0(ret, *file, dataTag, 8, &bytesRead);
  if( dataTag[0] != 142 ) return false;
  int length;
  if( ctx->m_pfShotsData ) {
    if( (length = dataTag[1] / header.dw08) <= 0 ) return true;
    abort();
#if 0
    for( unsigned int i = 0; i < header.dw08; i++ ) {
      printf( "%d / %d\n", i, header.dw08  );
      ShotLoadBlock *ebx = new (dataShots.unk_746fb6) ShotLoadBlock();
      if( length != 239 ) abort();
      sub_5b3eb0(ret, *file, &dataShots.block, 239, &bytesRead);
      ebx->sub_56afe0(dataShots.block);
      if( !ctx->m_pfShotsData(ebx, ctx->m_pShotsArg) )
        return false;
    }
#endif
    return true;
  } else {
    unsigned int offset = sub_5b3a80(*file) + dataTag[1];
    return sub_5b3a90(*file, dataTag[1], SEEK_CUR) == offset;
  }
}

static bool
kwdKeeperSpells( TbDiscFile **file, KWDContext *ctx )
{
  size_t bytesRead;
  bool ret;
  kwdHeader header;
  unsigned int dataTag[2];

  sub_5b3eb0(ret, *file, &header, 36, &bytesRead);
  if( header.id != 151 ) return false;
  if( ctx->m_pfKeeperSpellsHeader )
    if( !ctx->m_pfKeeperSpellsHeader(&header.dw08, ctx->m_pKeeperSpellsArg) )
      return false;
  sub_5b3eb0(ret, *file, dataTag, 8, &bytesRead);
  if( dataTag[0] != 152 ) return false;
  int length;
  if( ctx->m_pfKeeperSpellsData ) {
    if( (length = dataTag[1] / header.dw08) <= 0 ) return true;
    for( unsigned int i = 0; i < header.dw08; i++ ) {
      KeeperSpellLoadBlock *pkLoadBlock =
        new (dataKeeperSpells.unk_747056) KeeperSpellLoadBlock();
      if( length != 406 ) abort();
      sub_5b3eb0(ret, *file, &dataKeeperSpells.block, 406, &bytesRead);
      pkLoadBlock->load(dataKeeperSpells.block);
      if( !ctx->m_pfKeeperSpellsData(pkLoadBlock, ctx->m_pKeeperSpellsArg) )
        return false;
    }
    return true;
  } else {
    unsigned int offset = sub_5b3a80(*file) + dataTag[1];
    return sub_5b3a90(*file, dataTag[1], SEEK_CUR) == offset;
  }
}

static bool
kwdPlayers( TbDiscFile **file, KWDContext *ctx )
{
  size_t bytesRead;
  bool ret;
  kwdHeader header;
  unsigned int dataTag[2];

  sub_5b3eb0(ret, *file, &header, 36, &bytesRead);
  if( header.id != 181 ) return false;
  if( ctx->m_pfPlayersHeader )
    if( !ctx->m_pfPlayersHeader(&header.dw08, ctx->m_pPlayersArg) )
      return false;
  sub_5b3eb0(ret, *file, dataTag, 8, &bytesRead);
  if( dataTag[0] != 182 ) return false;
  int length;
  if( ctx->m_pfPlayersData ) {
    if( (length = dataTag[1] / header.dw08) <= 0 ) return false;
    for( unsigned int i = 0; i < header.dw08; i++ ) {
      PlayerBlock data;

      if( length != sizeof(data) ) abort();
      PlayerLoadBlock loadBlock;
      if( sub_5b3eb0(ret, *file, &data, 205, &bytesRead) < 0 ) return false;

      loadBlock.load(data);
      if( !ctx->m_pfPlayersData(&loadBlock, ctx->m_pPlayersArg) )
        return false;
    }
    return true;
  } else {
    unsigned int offset = sub_5b3a80(*file) + dataTag[1];
    return sub_5b3a90(*file, dataTag[1], SEEK_CUR) == offset;
  }
}

static bool
kwdMap( TbDiscFile **file, KWDContext *ctx )
{
  size_t bytesRead;
  bool ret;
  kwdHeader header;
  unsigned int dataTag[2];

  sub_5b3eb0(ret, *file, &header, 16, &bytesRead);
  if( header.id != 101 ) return false;
  if( ctx->m_pfMapHeader )
    if( !ctx->m_pfMapHeader(&header.dw08, ctx->m_pMapArg) )
      return false;
  sub_5b3eb0(ret, *file, dataTag, 8, &bytesRead);
  if( dataTag[0] != 102 ) return false;
  if( ctx->m_pfMapData ) {
    int size = header.dw08 * header.x0c[0];
    unsigned int x = 0;
    int y = 0;
    while( size ) {
      int block = size > 0x4000 ? 0x4000 : size;
      unsigned char *mapPtr = dataMap;
      if( sub_5b3eb0(ret, *file, dataMap, size * 4, &bytesRead) < 0 )
        return false;

      for( int i = 0; i < block; i++ ) {
        ElementLoadBlock var_20(mapPtr);;

        if( !ctx->m_pfMapData(x, y, &var_20, ctx->m_pMapArg) )
          return false;

        mapPtr += 4;

        x++;
        if( x == header.dw08 ) {
          y++;
          x = 0;
        }
      }
      size -= block;
    }
    return true;
  } else {
    unsigned int offset = sub_5b3a80(*file) + dataTag[1];
    return sub_5b3a90(*file, dataTag[1], SEEK_CUR) == offset;
  }
}

static bool
kwdTriggers( TbDiscFile **file, KWDContext *ctx )
{
  size_t bytesRead;
  bool ret;
  kwdHeader header;
  unsigned int dataTag[2];

  sub_5b3eb0(ret, *file, &header, 40, &bytesRead);
  if( header.id != 211 ) return false;
  if( ctx->m_pfTriggersHeader )
    if( !ctx->m_pfTriggersHeader(&header.dw08, ctx->m_pTriggersArg) )
      return false;
  sub_5b3eb0(ret, *file, dataTag, 8, &bytesRead);
  if( dataTag[0] != 212 ) return false;

  for( unsigned int i = 0; i < header.dw08 + header.x0c[0]; i++ ) {
    unsigned int triggerTag[2];
    if( sub_5b3eb0(ret, *file, triggerTag, 8, &bytesRead) < 0 ) return false;
    if( triggerTag[0] == 213 ) {
      if( ctx->m_pfTriggersType1 ) {
        TriggerBlock kBlock;

        sub_5b3eb0(ret, *file, &kBlock, 16, &bytesRead);

        TriggerLoadBlock loadBlock;
        loadBlock.load(kBlock);

        if( !ctx->m_pfTriggersType1(&loadBlock, ctx->m_pTriggersArg) )
          return false;
      } else {
        unsigned int offset = sub_5b3a80(*file) + triggerTag[1];
        if( sub_5b3a90(*file, triggerTag[1], SEEK_CUR) != offset )
          return false;
      }
    } else if( triggerTag[0] == 214 ) {
      if( ctx->m_pfTriggersType2 ) {
        TriggerBlock kBlock;

        sub_5b3eb0(ret, *file, &kBlock, 16, &bytesRead);

        TriggerActionLoadBlock loadBlock;
        loadBlock.load(kBlock);

        if( !ctx->m_pfTriggersType2(&loadBlock, ctx->m_pTriggersArg) )
          return false;
      } else {
        unsigned int offset = sub_5b3a80(*file) + triggerTag[1];
        if( sub_5b3a90(*file, triggerTag[1], SEEK_CUR) != offset )
          return false;
      }
    }
  }

  return true;
}

static bool
kwdVariables( TbDiscFile **file, KWDContext *ctx )
{
  size_t bytesRead;
  bool ret;
  kwdHeader header;
  unsigned int dataTag[2];

  sub_5b3eb0(ret, *file, &header, 36, &bytesRead);
  if( header.id != 231 ) return false;
  if( ctx->m_pfVariablesHeader )
    if( !ctx->m_pfVariablesHeader(&header.dw08, ctx->m_pVariablesArg) )
      return false;
  sub_5b3eb0(ret, *file, dataTag, 8, &bytesRead);
  if( dataTag[0] != 232 ) return false;

  if( ctx->m_pfVariablesData ) {
    VariableBlock var_54;
    for( unsigned int i = 0; i < header.dw08; i++ ) {
      if( sub_5b3eb0(ret, *file, &var_54, sizeof(var_54), &bytesRead) < 0 )
        return false;

      VariableLoadBlock loadBlock;
      loadBlock.load(var_54);

      if( !ctx->m_pfVariablesData(&loadBlock, ctx->m_pVariablesArg) )
        return false;
    }
  } else {
    unsigned int offset = sub_5b3a80(*file) + dataTag[1];
    return sub_5b3a90(*file, dataTag[1], SEEK_CUR) == offset;
  }

  return true;
}

static bool
sub_5700a0( unsigned int *thingTag, TbDiscFile **file, KWDContext *ctx )
{
  if( ctx->m_pfThingsType07 != NULL ) {
    size_t bytesRead;
    bool ret;
    ActionPointBlock kBlock;
    if( thingTag[1] != 56 ) abort();
    if( sub_5b3eb0(ret, *file, &kBlock, 56, &bytesRead) < 0 ) return false;
    ActionPointLoadBlock kLoadBlock;
    kLoadBlock.load(kBlock);
    if( !ctx->m_pfThingsType07(&kLoadBlock, ctx->m_pThingsArg) )
      return false;
  } else {
    size_t offset = sub_5b3a80(*file) + thingTag[1];
    if( sub_5b3a90(*file, thingTag[1], SEEK_CUR) != offset )
      return false;
  }
  return true;
}

static bool
sub_5708a0( unsigned int *thingTag, TbDiscFile **file, KWDContext *ctx )
{
  if( ctx->m_pfThingsType11 != NULL ) {
    size_t bytesRead;
    bool ret;
    Thing11Block kBlock;
    if( thingTag[1] != 20 ) abort();
    if( sub_5b3eb0(ret, *file, &kBlock, 20, &bytesRead) < 0 ) return false;
    Thing11LoadBlock kLoadBlock;
    kLoadBlock.load(kBlock);
    if( !ctx->m_pfThingsType11(&kLoadBlock, ctx->m_pThingsArg) )
      return false;
  } else {
    size_t offset = sub_5b3a80(*file) + thingTag[1];
    if( sub_5b3a90(*file, thingTag[1], SEEK_CUR) != offset )
      return false;
  }
  return true;
}

static bool
sub_570a20( unsigned int *thingTag, TbDiscFile **file, KWDContext *ctx )
{
  if( ctx->m_pfThingsType12 != NULL ) {
    size_t bytesRead;
    bool ret;
    Thing12Block kBlock;
    if( thingTag[1] != 84 ) abort();
    if( sub_5b3eb0(ret, *file, &kBlock, 84, &bytesRead) < 0 ) return false;
    Thing12LoadBlock kLoadBlock;
    kLoadBlock.load(kBlock);
    if( !ctx->m_pfThingsType12(&kLoadBlock, ctx->m_pThingsArg) )
      return false;
  } else {
    size_t offset = sub_5b3a80(*file) + thingTag[1];
    if( sub_5b3a90(*file, thingTag[1], SEEK_CUR) != offset )
      return false;
  }
  return true;
}

static bool
sub_570210( unsigned int *thingTag, TbDiscFile **file, KWDContext *ctx )
{
  if( ctx->m_pfThingsType08 != NULL ) {
    size_t bytesRead;
    bool ret;
    Thing08Block kBlock;
    if( thingTag[1] == 264 ) abort();
    if( thingTag[1] == 268 ) abort();
    if( thingTag[1] == 300 ) abort();
    if( sub_5b3eb0(ret, *file, &kBlock, 555, &bytesRead) < 0 ) return false;
    Thing08LoadBlock kLoadBlock;
    kLoadBlock.load(kBlock);
    if( !ctx->m_pfThingsType08(&kLoadBlock, ctx->m_pThingsArg) )
      return false;
  } else {
    size_t offset = sub_5b3a80(*file) + thingTag[1];
    if( sub_5b3a90(*file, thingTag[1], SEEK_CUR) != offset )
      return false;
  }
  return true;
}

static bool
sub_570630( unsigned int *thingTag, TbDiscFile **file, KWDContext *ctx )
{
  if( ctx->m_pfThingsType10 != NULL ) {
    size_t bytesRead;
    bool ret;
    Thing10Block kBlock;
    if( sub_5b3eb0(ret, *file, &kBlock, 36, &bytesRead) < 0 ) return false;
    Thing10LoadBlock kLoadBlock;
    kLoadBlock.load(kBlock);
    if( !ctx->m_pfThingsType10(&kLoadBlock, ctx->m_pThingsArg) )
      return false;
  } else {
    size_t offset = sub_5b3a80(*file) + thingTag[1];
    if( sub_5b3a90(*file, thingTag[1], SEEK_CUR) != offset )
      return false;
  }
  return true;
}

static bool
kwdThings( TbDiscFile **file, KWDContext *ctx )
{
  size_t bytesRead;
  bool ret;
  kwdHeader header;
  unsigned int dataTag[2];

  sub_5b3eb0(ret, *file, &header, 36, &bytesRead);
  if( header.id != 191 ) return false;
  if( ctx->m_pfThingsHeader )
    if( !ctx->m_pfThingsHeader(&header.dw08, ctx->m_pThingsArg) )
      return false;
  sub_5b3eb0(ret, *file, dataTag, 8, &bytesRead);
  if( dataTag[0] != 192 ) return false;

  for( unsigned int i = 0; i < header.dw08; i++ ) {
    unsigned int thingTag[2], offset;
    if( sub_5b3eb0(ret, *file, thingTag, 8, &bytesRead) < 0 ) return false;
    switch(thingTag[0]) {
    case 193: abort();
    case 194:
      if( ctx->m_pfThingsType06 ) {
        unsigned char data[24];
        sub_5b3eb0(ret, *file, &data, 24, &bytesRead);
#if 0
        class_56f4d0 var_94;
        var_94.sub_56f540(data);
        if( !ctx->m_pfThingsType03(&var_94, ctx->m_pThingsArg) )
          return false;
#endif
      } else {
        offset = sub_5b3a80(*file) + thingTag[1];
        if( sub_5b3a90(*file, thingTag[1], SEEK_CUR) != offset )
          return false;
      }
      break;
    case 195:
      if( ctx->m_pfThingsType05 ) abort();
      offset = sub_5b3a80(*file) + thingTag[1];
      if( sub_5b3a90(*file, thingTag[1], SEEK_CUR) != offset )
        return false;
      break;
    case 196:
      if( ctx->m_pfThingsType04 ) abort();
      offset = sub_5b3a80(*file) + thingTag[1];
      if( sub_5b3a90(*file, thingTag[1], SEEK_CUR) != offset )
        return false;
      break;
    case 197:
      if( !sub_5700a0(thingTag, file, ctx) )
        return false;
      break;
    case 198:
      if( ctx->m_pfThingsType01 ) abort();
      offset = sub_5b3a80(*file) + thingTag[1];
      if( sub_5b3a90(*file, thingTag[1], SEEK_CUR) != offset )
        return false;
      break;
    case 199:
      if( ctx->m_pfThingsType02 ) abort();
      offset = sub_5b3a80(*file) + thingTag[1];
      if( sub_5b3a90(*file, thingTag[1], SEEK_CUR) != offset )
        return false;
      break;
    case 200:
      if( ctx->m_pfThingsType03 ) {
        Thing03Block kBlock;
        if( sub_5b3eb0(ret, *file, &kBlock, sizeof(kBlock), &bytesRead) < 0 )
          return false;
        Thing03LoadBlock kLoadBlock;
        kLoadBlock.load(kBlock);
        if( !ctx->m_pfThingsType03(&kLoadBlock, ctx->m_pThingsArg) )
          return false;
      } else {
        offset = sub_5b3a80(*file) + thingTag[1];
        if( sub_5b3a90(*file, thingTag[1], SEEK_CUR) != offset )
          return false;
      }
      break;
    case 201:
      if( !sub_570210(thingTag, file, ctx) )
        return false;
      break;
    case 202: abort();
    case 203:
      if( !sub_570630(thingTag, file, ctx) ) return false;
      break;
    case 204:
      if( !sub_5708a0(thingTag, file, ctx) )
        return false;
      break;
    case 205:
      if( !sub_570a20(thingTag, file, ctx) )
        return false;
      break;
    case 206: abort();
    default: abort();
    }
  }


  return true;
}

bool
sub_56cbd0( TbDiscFile **file, KWDContext *ctx )
{
  unsigned int header[3];
  bool ret;
  size_t bytesRead;

  sub_5b3eb0(ret, *file, header, 12, &bytesRead);
  if( ret < 0 ) return false;
  if( header[0] - 100 > 170 ) return false;
  switch(header[0]) {
  case 100:
    if( ctx->m_pfLoadStep )
      ctx->m_pfLoadStep(27, ctx->m_pfMapHeader != NULL, ctx->m_pLoadStepArg);
    if( !kwdMap(file, ctx) ) return false;
    if( ctx->m_pfLoadStep )
      ctx->m_pfLoadStep(28, ctx->m_pfMapHeader != NULL, ctx->m_pLoadStepArg);
    return true;
  case 110:
    if( ctx->m_pfLoadStep )
      ctx->m_pfLoadStep(7, ctx->m_pfTerrainHeader != NULL, ctx->m_pLoadStepArg);
    if( !kwdTerrain(file, ctx) ) return false;
    if( ctx->m_pfLoadStep )
      ctx->m_pfLoadStep(8, ctx->m_pfTerrainHeader != NULL, ctx->m_pLoadStepArg);
    return true;
  case 120:
    if( ctx->m_pfLoadStep )
      ctx->m_pfLoadStep(11, ctx->m_pfRoomsHeader != NULL, ctx->m_pLoadStepArg);
    if( !kwdRooms(file, ctx) ) return false;
    if( ctx->m_pfLoadStep )
      ctx->m_pfLoadStep(12, ctx->m_pfRoomsHeader != NULL, ctx->m_pLoadStepArg);
    return true;
  case 130:
    if( ctx->m_pfLoadStep )
      ctx->m_pfLoadStep(17, ctx->m_pfTrapsHeader != NULL, ctx->m_pLoadStepArg);
    if( !kwdTraps(file, ctx) ) return false;
    if( ctx->m_pfLoadStep )
      ctx->m_pfLoadStep(18, ctx->m_pfTrapsHeader != NULL, ctx->m_pLoadStepArg);
    return true;
  case 140:
    if( ctx->m_pfLoadStep )
      ctx->m_pfLoadStep(19, ctx->m_pfDoorsHeader != NULL, ctx->m_pLoadStepArg);
    if( !kwdDoors(file, ctx) ) return false;
    if( ctx->m_pfLoadStep )
      ctx->m_pfLoadStep(20, ctx->m_pfDoorsHeader != NULL, ctx->m_pLoadStepArg);
    return true;
  case 150:
    if( ctx->m_pfLoadStep )
      ctx->m_pfLoadStep(23, ctx->m_pfKeeperSpellsHeader != NULL, ctx->m_pLoadStepArg);
    if( !kwdKeeperSpells(file, ctx) ) return false;
    if( ctx->m_pfLoadStep )
      ctx->m_pfLoadStep(24, ctx->m_pfKeeperSpellsHeader != NULL, ctx->m_pLoadStepArg);
    return true;
  case 160:
    if( ctx->m_pfLoadStep )
      ctx->m_pfLoadStep(15, ctx->m_pfCreatureSpellsHeader != NULL, ctx->m_pLoadStepArg);
    if( !kwdCreatureSpells(file, ctx) ) return false;
    if( ctx->m_pfLoadStep )
      ctx->m_pfLoadStep(16, ctx->m_pfCreatureSpellsHeader != NULL, ctx->m_pLoadStepArg);
    return true;
  case 170:
    if( ctx->m_pfLoadStep )
      ctx->m_pfLoadStep(13, ctx->m_pfCreaturesHeader != NULL, ctx->m_pLoadStepArg);
    if( !kwdCreatures(file, ctx) ) return false;
    if( ctx->m_pfLoadStep )
      ctx->m_pfLoadStep(14, ctx->m_pfCreaturesHeader != NULL, ctx->m_pLoadStepArg);
    return true;
  case 180:
    if( ctx->m_pfLoadStep )
      ctx->m_pfLoadStep(25, ctx->m_pfPlayersHeader != NULL, ctx->m_pLoadStepArg);
    if( !kwdPlayers(file, ctx) ) return false;
    if( ctx->m_pfLoadStep )
      ctx->m_pfLoadStep(26, ctx->m_pfPlayersHeader != NULL, ctx->m_pLoadStepArg);
    return true;
  case 190:
    if( !kwdThings(file, ctx) ) return false;
    return true;
  case 210:
    if( ctx->m_pfLoadStep )
      ctx->m_pfLoadStep(29, ctx->m_pfTriggersHeader != NULL, ctx->m_pLoadStepArg);
    if( !kwdTriggers(file, ctx) ) return false;
    if( ctx->m_pfLoadStep )
      ctx->m_pfLoadStep(30, ctx->m_pfTriggersHeader != NULL, ctx->m_pLoadStepArg);
    return true;
  case 220:
    if( ctx->m_pfLoadStep )
      ctx->m_pfLoadStep(31, ctx->m_pfLevelHeader != NULL, ctx->m_pLoadStepArg);
    if( !sub_56c4e0(file, ctx) ) return false;
    if( ctx->m_pfLoadStep )
      ctx->m_pfLoadStep(32, ctx->m_pfLevelHeader != NULL, ctx->m_pLoadStepArg);
    return true;
  case 230:
    if( !kwdVariables(file, ctx) ) return false;
    return true;
  case 240:
    if( ctx->m_pfLoadStep )
      ctx->m_pfLoadStep(9, ctx->m_pfObjectsHeader != NULL, ctx->m_pLoadStepArg);
    if( !kwdObjects(file, ctx) ) return false;
    if( ctx->m_pfLoadStep )
      ctx->m_pfLoadStep(10, ctx->m_pfObjectsHeader != NULL, ctx->m_pLoadStepArg);
    return true;
  case 250:
    if( !kwdEffectElements(file, ctx) ) return false;
    return true;
  case 260:
    if( ctx->m_pfLoadStep )
      ctx->m_pfLoadStep(21, ctx->m_pfShotsHeader != NULL, ctx->m_pLoadStepArg);
    if( !kwdShots(file, ctx) ) return false;
    if( ctx->m_pfLoadStep )
      ctx->m_pfLoadStep(22, ctx->m_pfShotsHeader != NULL, ctx->m_pLoadStepArg);
    return true;
  case 270:
    if( !kwdEffects(file, ctx) ) return false;
    return true;
  default: return false;
  }
  return false;
}

/* 56c960 */
bool
KWDContext::load( const char *filename )
{
  const char *ext = strrchr(filename, '.');
  char var_104[MAX_PATH];
  /* not quite, but they're doing some silly math */
  TbDiscFile *var_114;
  int ret;
  if( ext == NULL || strlen(ext) != 4 ) {
    sprintf(var_104, "%s.%s", filename, "KWD");
    if( sub_5b3980(ret, &var_114, var_104, 0x80000001) < 0 ) {
      sprintf(var_104, "%s.%s", filename, "KLF");
      if( sub_5b3980(ret, &var_114, var_104, 0x80000001) < 0 ) {
        sprintf(var_104, "%s.%s", filename, "KLD");
        if( sub_5b3980(ret, &var_114, var_104, 0x80000001) < 0 ) return false;
      }
    }
    sub_5b3a30(ret, var_114);
  } else {
    /* above checks .kwd, then .klf??, then .kld */
    strcpy(var_104, filename);
  }
  ext = strrchr(var_104, '.');
  if( ext == NULL || strlen(ext) != 4 ) return false;
  ++ext;
  if( !strcasecmp(ext, "KWD") && !strcasecmp(ext, "KLD") ) return false;
  /* var_114 used as obj (but not really for below */
  /* bet this was a scoped_ptr or something like it */
  sub_5b3980(ret, &var_114, var_104, 0x80000001);
  if( ret < 0 )
    return false;
         /* file size */       /* position */
  while( sub_5b3b80(var_114) > sub_5b3a80(var_114) ) {
    if( !sub_56cbd0(&var_114, this) ) {
      sub_5b3a30(ret, var_114);
      return false;
    }
  }
  sub_5b3a30(ret, var_114);
  return true;
}
