#ifndef KWD_H
#define KWD_H

#include "Resource.h"

/* just identifies our wide strings for levels */
typedef uint16_t ucs2le_t;

class KWDContext {
public:
  KWDContext();

  bool load( const char *filename );

  typedef bool (*dataCallback)( void *pData, void *pArg );

  void (*m_pfLoadStep)( int step, bool arg4, void *pArg ); /* 0 */
  void *m_pLoadStepArg; /* 4 */
  dataCallback m_pfTerrainHeader; /* 8 */
  dataCallback m_pfTerrainData; /* c */
  void *m_pTerrainArg; /* 10 */
  dataCallback m_pfMapHeader; /* 14 */
  bool (*m_pfMapData)( int x, int y, void *pData, void *pArg ); /* 18 */
  void *m_pMapArg; /* 1c */
  dataCallback m_pfRoomsHeader; /* 20 */
  dataCallback m_pfRoomsData; /* 24 */
  void *m_pRoomsArg; /* 28 */
  dataCallback m_pfDoorsHeader; /* 2c */
  dataCallback m_pfDoorsData; /* 30 */
  void *m_pDoorsArg; /* 34 */
  dataCallback m_pfTrapsHeader; /* 38 */
  dataCallback m_pfTrapsData; /* 3c */
  void *m_pTrapsArg; /* 40 */
  dataCallback m_pfKeeperSpellsHeader; /* 44 */
  dataCallback m_pfKeeperSpellsData; /* 48 */
  void *m_pKeeperSpellsArg; /* 4c */
  dataCallback m_pfCreatureSpellsHeader; /* 50 */
  dataCallback m_pfCreatureSpellsData; /* 54 */
  void *m_pCreatureSpellsArg; /* 58 */
  dataCallback m_pfCreaturesHeader; /* 5c */
  dataCallback m_pfCreaturesData; /* 60 */
  void *m_pCreaturesArg; /* 64 */
  dataCallback m_pfPlayersHeader; /* 68 */
  dataCallback m_pfPlayersData; /* 6c */
  void *m_pPlayersArg; /* 70 */
  dataCallback m_pfThingsHeader; /* 74 */
  dataCallback m_pfThingsType01; /* 78 */
  dataCallback m_pfThingsType02; /* 7c */
  dataCallback m_pfThingsType03; /* 80 */
  dataCallback m_pfThingsType04; /* 84 */
  dataCallback m_pfThingsType05; /* 88 */
  dataCallback m_pfThingsType06; /* 8c */
  dataCallback m_pfThingsType07; /* 90 */
  dataCallback m_pfThingsType08; /* 94 */
  dataCallback m_pfThingsType09; /* 98 */
  dataCallback m_pfThingsType10; /* 9c */
  dataCallback m_pfThingsType11; /* a0 */
  dataCallback m_pfThingsType12; /* a4 */
  dataCallback m_pfThingsType13; /* a8 */
  void *m_pThingsArg; /* ac */
  dataCallback m_pfTriggersHeader; /* b0 */
  dataCallback m_pfTriggersType1; /* b4 likely trigger */
  dataCallback m_pfTriggersType2; /* b8 and action */
  void *m_pTriggersArg; /* bc */
  dataCallback m_pfLevelHeader; /* c0 */
  dataCallback m_pfLevelType1; /* c4 */
  dataCallback m_pfLevelType2; /* c8 */
  dataCallback m_pfLevelType3; /* cc */
  void *m_pLevelArg; /* d0 */
  dataCallback m_pfVariablesHeader; /* d4 */
  dataCallback m_pfVariablesData; /* d8 */
  void *m_pVariablesArg; /* dc */
  dataCallback m_pfObjectsHeader; /* e0 */
  dataCallback m_pfObjectsData; /* e4 */
  void *m_pObjectsArg; /* e8 */
  dataCallback m_pfEffectElementsHeader; /* ec */
  dataCallback m_pfEffectElementsData; /* f0 */
  void *m_pEffectElementsArg; /* f4 */
  dataCallback m_pfEffectsHeader; /* f8 */
  dataCallback m_pfEffectsData; /* fc */
  void *m_pEffectsArg; /* 100 */
  dataCallback m_pfShotsHeader; /* 104 */
  dataCallback m_pfShotsData; /* 108 */
  void *m_pShotsArg; /* 10c */
};

/* REQUIRES -fshort-wchar */
struct LevelInfoBlock {
  ucs2le_t m_wsName[64]; /* 134 */
  ucs2le_t m_wsDescription[1024]; /* 1b4 */
  ucs2le_t m_wsAuthor[64]; /* 9b4 */
  ucs2le_t m_wsEmail[64]; /* a34 */
  ucs2le_t m_wsInformation[1024]; /* ab4 */
  uint16_t m_wShortId0;
  uint16_t m_wShortId1;
  uint8_t x01184[520];
  ucs2le_t m_wsUnknown0138c[20][512];
  uint16_t x0638c;
  char x0638e[32];
  uint8_t x063ae;
  uint8_t x063af[4];
  uint8_t x063b3[4];
  uint8_t x063b7;
  uint8_t x063b8;
  uint16_t x063b9;
  uint16_t x063bb;
  uint16_t x063bd;
  uint16_t x063bf;
  uint16_t x063c3;
  uint16_t x063c5;
  uint16_t x063c7;
  uint16_t x063c9;
  uint16_t x063ca;
  uint8_t x063cb[8];
  uint16_t x063d3[8];
  char x063e3[32];
  uint8_t x06403;
  uint8_t x06404;
  uint8_t x06405;
  uint8_t x06406;
  uint16_t x06407;
  uint16_t x06409[5];
  ucs2le_t x06413[32];
};

class class_56bf40 {
public:
  class_56bf40() { }
  void sub_56c100( const LevelInfoBlock &rkBlock );
  LevelInfoBlock &block() { return m_kBlock; }
  bool unk0138cPresent( int i ) { return m_fUnknown0138cPresent[i]; }
  bool unk0638ePresent() { return m_fUnknown0638ePresent; }

private:
  bool m_fNamePresent; /* 0 */
  bool m_fDescriptionPresent; /* 4 */
  bool m_fAuthorPresent; /* 8 */
  bool m_fEmailPresent; /* c */
  bool m_fInformationPresent; /* 10 */
  bool m_fShortId0Present; /* 14 */
  bool m_fShortId1Present; /* 18 */
  bool m_fUnknown0138cPresent[20]; /* 1c */
  bool m_fUnknown0638ePresent; /* 6c */
  bool m_fUnknown063aePresent; /* 70 */
  bool m_fUnknown06403Present; /* 74 */
  bool m_fUnknown06407Present; /* 78 */
  bool m_fUnknown063afPresent[4]; /* 7c */
  bool m_fUnknown06405Present; /* 8c */
  bool m_fUnknown063b3Present[4]; /* 90 */
  bool m_fUnknown06406Present; /* a0 */
  bool m_fUnknown063b7Present; /* a4 */
  bool m_fUnknown063b8Present; /* a8 */
  bool m_fUnknown0638cPresent; /* ac */
  bool m_fUnknown063b9Present; /* b0 */
  bool m_fUnknown063bbPresent; /* b4 */
  bool m_fUnknown063bdPresent; /* b8 */
  bool m_fUnknown063bfPresent; /* bc */
  bool m_fUnknown063c5Present; /* c0 */
  bool m_fUnknown063c7Present; /* c4 */
  bool m_fUnknown063c3Present; /* c8 */
  bool m_fUnknown063c9Present; /* cc */
  bool m_fUnknown063caPresent; /* d0 */
  bool m_fUnknown063cbPresent[8]; /* d4 */
  bool m_fUnknown063d3Present[8]; /* f4 */
  bool m_fUnknown063e3Present; /* 114 */
  bool m_fUnknown06404Present; /* 118 */
  bool m_fUnknown06409Present[5]; /* 11c */
  bool m_fUnknown06413Present; /* 130 */
  LevelInfoBlock m_kBlock;
};

#endif
