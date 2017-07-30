#pragma once

#include "FE7J.h"
#include "IDAPro.h"

#include "ApocalypseBGMapLZ_bin.h"
#include "ApocalypseBGPal_bin.h"
#include "ApocalypseBGTilesLZ_bin.h"
#include "ApocalypseCharactersPal_bin.h"
#include "ApocalypseCharactersTilesLZ_bin.h"
#include "ApocalypseSpritePal_bin.h"
#include "ApocalypseSpriteTilesLZ_bin.h"
#include "FE6_8605A94_data_bin.h"
#include "FE6_811A62A_data_bin.h"
/* #include "FE6_817BBD4_data_bin.h"
#include "FE6_817CDDC_data_bin.h"
#include "FE6_817E5DC_data_bin.h"
#include "FE6_817FF7C_data_bin.h"
#include "FE6_8181E60_data_bin.h"
#include "FE6_8181F3C_data_bin.h"
#include "FE6_818273C_data_bin.h" */
#include "ApocalypseWhirlPoolPal_bin.h"
#include "ApocalypseWhirlPoolFrame0TilesLZ_bin.h"
#include "ApocalypseWhirlPoolFrame1TilesLZ_bin.h"
#include "ApocalypseWhirlPoolFrame2TilesLZ_bin.h"
#include "ApocalypseWhirlPoolFrame3TilesLZ_bin.h"
#include "ApocalypseWhirlPoolFrame0MapLZ_bin.h"
#include "ApocalypseWhirlPoolFrame1MapLZ_bin.h"
#include "ApocalypseWhirlPoolFrame2MapLZ_bin.h"
#include "ApocalypseWhirlPoolFrame3MapLZ_bin.h"
#include "ApocalypseSpritePal_bin.h"
#include "ApocalypseSpriteTilesLZ_bin.h"
#include "ApocalypseBlackSunTilesLZ_bin.h"
#include "FE6_85EBF68_data_bin.h"
#include "FE6_85EB97C_data_bin.h"

#pragma long_calls
int ApocalypseSpellAnimation(int a1);
#pragma long_calls_off

int Apocalypse(int a1);

int loadApocalypseBGData(int a1, __int16 a2);
int loadApocalypseBGPal(int a1);
int ApocalypseBGPal(int a1);
int sub_FE6_8052C68();
int sub_FE6_8052C9C(int a1);
int sub_FE6_805315C(int a1, __int16 a2, __int16 a3);
int sub_FE6_805318C(int a1);
int sub_FE6_80531F4(int a1);
int sub_FE6_8053218(int a1);
int sub_FE6_80531C4(int a1, __int16 a2, __int16 a3);
int loadApocalypseCharacters(int a1);
int sub_FE6_8052E30(int a1);
extern int sub_FE6_8052E9C(int a1);
extern int sub_FE6_8052F28(int a1);
extern int sub_FE6_8052FB4(int a1);
// int sub_FE6_8052E9C(int a1);
// int sub_FE6_8052F28(int a1);
// int sub_FE6_8052FB4(int a1);
int sub_FE6_8052C34(int a1);
int sub_FE6_805304C(int a1, __int16 a2);
int sub_FE6_805308C(int a1);
signed int sub_FE6_8047BA4(_WORD *a1, _WORD *a2, __int16 *a3);
int sub_FE6_8047B6C(int a1, int a2, unsigned int a3, unsigned int a4, unsigned int a5);
int sub_FE6_80530E4(int a1, int a2, __int16 a3);
int sub_FE6_8053114(int a1);
int loadApocalypseWhirlPool(int a1, __int16 a2);
signed int sub_FE6_805894C();
int sub_FE6_80589FC(int a1);
int sub_FE6_804CD4C();
int sub_FE6_804B80C(int a1);
bool sub_FE6_804B6C4(int a1);
int sub_FE6_8053340(int a1);
int loadApocalypseBlackSun(int a1, __int16 a2, __int16 a3);
int sub_FE6_80534BC(int a1);
int sub_FE6_80534FC(int a1);
int loadApocalypseDust(int a1, __int16 a2);
int sub_FE6_8053568(int a1);
int sub_FE6_80535F8(int a1, int a2, int a3, unsigned int a4);
// int sub_FE6_80536C4(int a1);
extern int sub_FE6_80536C4(int a1);
// int sub_FE6_804D050(int a1, __int16 a2);
