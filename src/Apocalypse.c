#include "Apocalypse.h"

__attribute__((section(".ApocalypseEntry")))
const PTRFUN ApocalypseEntry = &ApocalypseSpellAnimation;

//把火炎的魔法动画ID指定为阿波卡布斯的，测试用
__attribute__((section(".FireAnimationID")))
const int FireAnimationID = 0x23;

const struct funcUnit ApocalypseData[3] =
{
	{0x19,0},{3,&Apocalypse},{0,0}
};

const struct funcUnit ApocalypseBGPalData[4] =
{
	{0x19,0},{0xA000F,0},{3,ApocalypseBGPal},{0,0}
};

const struct funcUnit FE6_85D2638_Data[4] =
{
	{0x19,0},{0x91000E,0},{3,sub_FE6_8052C9C},{0,0}
};

const struct funcUnit FE6_85D2708_Data[3] =
{
	{0x19,0},{3,sub_FE6_805318C},{0,0}
};

const struct funcUnit FE6_85D2720_Data[4] =
{
	{0x19,0},{3,sub_FE6_80531F4},{3,sub_FE6_8053218},{0,0}
};

const struct funcUnit FE6_85D2678_Data[7] =
{
	{0x19,0},{0xC3000E,0},{3,sub_FE6_8052E30},{3,1+sub_FE6_8052E9C},{3,1+sub_FE6_8052F28},{3,1+sub_FE6_8052FB4},{0,0}
};

const struct funcUnit FE6_85D2620_Data[3] =
{
	{0x19,0},{3,sub_FE6_8052C34},{0,0}
};

const struct funcUnit FE6_85D26D0_Data[4] =
{
	{0x19,0},{0xA000F,0},{3,sub_FE6_805308C},{0,0}
};

const struct funcUnit FE6_85D26F0_Data[3] =
{
	{0x19,0},{3,sub_FE6_8053114},{0,0}
};

const struct funcUnit FE6_85D2740_Data[3] =
{
	{0x19,0},{3,sub_FE6_8053340},{0,0}
};

const struct funcUnit FE6_85D2778_Data[4] =
{
	{0x19,0},{3,sub_FE6_80534BC},{3,sub_FE6_80534FC},{0,0}
};

const struct funcUnit FE6_85D2798_Data[3] =
{
	{0x19,0},{3,sub_FE6_8053568},{0,0}
};

const struct funcUnit FE6_85D2A0C_Data[3] =
{
	{0x19,0},{3,1+sub_FE6_80536C4},{0,0}
};

const _DWORD FE6_85EB87C_Data[8][6]={
	{0x40000000, 0xFFF80000, 0xFFF8, 1, 0, 0},
	{0x40000000, 0xFFF80002, 0xFFF8, 1, 0, 0},
	{0x40000000, 0xFFF80004, 0xFFF8, 1, 0, 0},
	{0x40000000, 0xFFF80006, 0xFFF8, 1, 0, 0},
	{0x40000000, 0xFFF80008, 0xFFF8, 1, 0, 0},
	{0x40000000, 0xFFF8000A, 0xFFF8, 1, 0, 0},
	{0x40000000, 0xFFF8000C, 0xFFF8, 1, 0, 0},
	{0x40000000, 0xFFF8000E, 0xFFF8, 1, 0, 0},
};

const u32 FE6_85EB93C_Data[8][2]={
	{1+(u32)FE6_85EB87C_Data[0],0x80000000},
	{1+(u32)FE6_85EB87C_Data[1],0x80000000},
	{1+(u32)FE6_85EB87C_Data[2],0x80000000},
	{1+(u32)FE6_85EB87C_Data[3],0x80000000},
	{1+(u32)FE6_85EB87C_Data[4],0x80000000},
	{1+(u32)FE6_85EB87C_Data[5],0x80000000},
	{1+(u32)FE6_85EB87C_Data[6],0x80000000},
	{1+(u32)FE6_85EB87C_Data[7],0x80000000},
};

const u32 FE6_85D26B0_Data[8]={
	1+(u32)FE6_85EB93C_Data[0],
	1+(u32)FE6_85EB93C_Data[1],
	1+(u32)FE6_85EB93C_Data[2],
	1+(u32)FE6_85EB93C_Data[3],
	1+(u32)FE6_85EB93C_Data[4],
	1+(u32)FE6_85EB93C_Data[5],
	1+(u32)FE6_85EB93C_Data[6],
	1+(u32)FE6_85EB93C_Data[7],	
};

/* //正弦表 FE6-80F9998 FE7J-80C0E98
const _WORD Sin[129]={
	0, 0x64, 0xC8, 0x12D, 0x191, 0x1F5, 0x259, 0x2BC, 0x31F,
	0x381, 0x3E3, 0x444, 0x4A5, 0x504, 0x563, 0x5C2, 0x61F,
	0x67B, 0x6D7, 0x731, 0x78A, 0x7E2, 0x839, 0x88F, 0x8E3,
	0x936, 0x987, 0x9D7, 0xA26, 0xA73, 0xABE, 0xB08, 0xB50,
	0xB96, 0xBDA, 0xC1D, 0xC5E, 0xC9D, 0xCD9, 0xD14, 0xD4D,
	0xD84, 0xDB9, 0xDEB, 0xE1C, 0xE4A, 0xE76, 0xEA0, 0xEC8,
	0xEED, 0xF10, 0xF31, 0xF4F, 0xF6B, 0xF85, 0xF9C, 0xFB1,
	0xFC3, 0xFD3, 0xFE1, 0xFEC, 0xFF4, 0xFFB, 0xFFE, 0x1000,
	0xFFE, 0xFFB, 0xFF4, 0xFEC, 0xFE1, 0xFD3, 0xFC3, 0xFB1,
	0xF9C, 0xF85, 0xF6B, 0xF4F, 0xF31, 0xF10, 0xEED, 0xEC8,
	0xEA0, 0xE76, 0xE4A, 0xE1C, 0xDEB, 0xDB9, 0xD84, 0xD4D,
	0xD14, 0xCD9, 0xC9D, 0xC5E, 0xC1D, 0xBDA, 0xB96, 0xB50,
	0xB08, 0xABE, 0xA73, 0xA26, 0x9D7, 0x987, 0x936, 0x8E3,
	0x88F, 0x839, 0x7E2, 0x78A, 0x731, 0x6D7, 0x67B, 0x61F,
	0x5C2, 0x563, 0x504, 0x4A5, 0x444, 0x3E3, 0x381, 0x31F,
	0x2BC, 0x259, 0x1F5, 0x191, 0x12D, 0xC8, 0x64,0
};
 */
 
 const _DWORD ApocalypseWhirlPoolAnimationPlayData[6]={
	 0x30000, 0x30001, 0x30002, 0x30003, 0xFFFE, 0xFFFF00BE
 };
 
/*  const u8 *FE6_85D2758_Data[8]={
	FE6_817BBD4_data_bin,
	FE6_817CDDC_data_bin+0x704,
	FE6_817E5DC_data_bin+0x7B0,
	FE6_817FF7C_data_bin+0x578,
	FE6_8181E60_data_bin+0x20,
	FE6_8181F3C_data_bin+0x3E4,
	FE6_818273C_data_bin+0x74,
	FE6_818273C_data_bin+0x510
 }; */
 
 const u8 *ApocalypseWhirlPoolFrameTiles[4] = {
	ApocalypseWhirlPoolFrame0TilesLZ_bin,
	ApocalypseWhirlPoolFrame1TilesLZ_bin,
	ApocalypseWhirlPoolFrame2TilesLZ_bin,
	ApocalypseWhirlPoolFrame3TilesLZ_bin
 };
 
  const u8 *ApocalypseWhirlPoolFrameMap[4] = {
	ApocalypseWhirlPoolFrame0MapLZ_bin,
	ApocalypseWhirlPoolFrame1MapLZ_bin,
	ApocalypseWhirlPoolFrame2MapLZ_bin,
	ApocalypseWhirlPoolFrame3MapLZ_bin
 };
 
 const _DWORD FE6_85EBEF8_Data[3][6] = {
	{0x40000000, 0xFFF80058, 0xFFF8, 1, 0, 0},
	{0x40000000, 0xFFF8005A, 0xFFF8, 1, 0, 0},
	{0,0xFFF8007C, 0xFFF8, 1, 0, 0}
 };
 
 const _DWORD FE6_85EBF40_Data[10] = {
	 0x10000000+0x85EB97C-0x85EB97C+(u32)FE6_85EB97C_data_bin,
	 0x10000000+0x85EBB50-0x85EB97C+(u32)FE6_85EB97C_data_bin, 
	 0x10000000+0x85EBD24-0x85EB97C+(u32)FE6_85EB97C_data_bin, 0x82000000,
	 1+(u32)FE6_85EBEF8_Data[0],0x82000000,
	 1+(u32)FE6_85EBEF8_Data[1],0x82000000,
	 1+(u32)FE6_85EBEF8_Data[2],0x82000000
 };
 
 const _DWORD FE6_85EC478_data[] = {
	0x85EBFA6-0x85EBF68+(u32)FE6_85EBF68_data_bin, 0x85EC072-0x85EBF68+(u32)FE6_85EBF68_data_bin, 0x85EBF6A-0x85EBF68+(u32)FE6_85EBF68_data_bin, (0x85EC13E)-0x85EBF68+(u32)FE6_85EBF68_data_bin, 0x85EC1AA-0x85EBF68+(u32)FE6_85EBF68_data_bin,
	0x85EC216-0x85EBF68+(u32)FE6_85EBF68_data_bin, 0x85EC282-0x85EBF68+(u32)FE6_85EBF68_data_bin, (0x85EC2EE)-0x85EBF68+(u32)FE6_85EBF68_data_bin, 0x85EC35A-0x85EBF68+(u32)FE6_85EBF68_data_bin, 0x85EC3C6-0x85EBF68+(u32)FE6_85EBF68_data_bin,
	0x85EC432-0x85EBF68+(u32)FE6_85EBF68_data_bin, 0x85EC44A-0x85EBF68+(u32)FE6_85EBF68_data_bin, 0x85EC462-0x85EBF68+(u32)FE6_85EBF68_data_bin, 
	0x80000000, 0x80004000,
	0xFFE80044, 0x18, 0x40000000, 0x40, 8, 0,
	0x80000, 0, 0,
	0xFFE80020, 0x10, 0x40008000, 0x100002, 0xFFF0, 0x40008000,
	0x180003, 0xFFE0, 0x40004000, 4, 0xFFD8, 1, 0, 0,
	0x80004000, 0xFFE8004C, 0x18, 0x40000000, 0x48, 8,
	0,
	8, 8, 0,
	0
 };
 
 const _DWORD FE6_85D27B0_data[]={
	 0x2B, 0x26, 0x2C, 0x24, 0x2B, 0x29, 0x32, 0x2C, 0x30,
	 0x23, 0x24, 0x22, 0x2C, 0x2D, 0x23, 0x23, 0x31, 0x26,
	 0x23, 0x2C, 0x32, 0x2E, 0x1F, 0x2D, 0x24, 0x32, 0x30,
	 0x2A, 0x2D, 0x24, 0x1E, 0x29, 0x28, 0x2C, 0x20, 0x22,
	 0x20, 0x22, 0x23, 0x24, 0x2E, 0x21, 0x21, 0x2D, 0x32,
	 0x21, 0x25, 0x27, 0x2A, 0x31, 0xFFFFFFFF
 };
 
 const _DWORD FE6_85D287C_data[]={
	 0x7C34, 0x85C7, 0x3FB2, 0x7C4D, 0x8810, 0xFF13, 0xDB8E,
	 0xA559, 0x7A6C, 0x585F, 0x9EEA, 0x3365, 0xFD48, 0xA3AB,
	 0x83C6, 0xC871, 0x5AA4, 0x12F7, 0x2422, 0x267D, 0x7C80,
	 0xF843, 0xB9FE, 0x2F89, 0xECDC, 0xC58F, 0x1F5A, 0xE595,
	 0xD5B8, 0xCDB, 0xCE36, 0x6AA1, 0x114, 0x8027, 0xE092,
	 0xAD, 0xD8F0, 0xF173, 0x106E, 0x9B9, 0x674C, 0x52BF,
	 0xB7CA, 0x7C5, 0x5628, 0xB60B, 0xD0A6, 0x9CD1, 0xEF84,
	 0x4D57
 };
 
 const _DWORD FE6_85D2944_data[]={
	 1, 0,
	 6, 0,
	 2, 3, 4, 4, 0,
	 3, 4, 5, 6, 4, 5, 6, 4, 5, 1, 6, 3, 2, 4, 0,
	 3, 5, 2, 6, 6, 4, 4, 5, 0,
	 4, 6, 3, 4, 4, 1, 1, 4, 4, 3, 0, 0,
	 5, 2, 2, 3, 2
 };
 
int ApocalypseSpellAnimation(int a1)
{
  int v1; // r5@1
  int v2; // r0@1
  int v3; // r4@1
  __int16 v4; // r0@1
//  int v6; // [sp+8h] [bp-4h]@0

  v1 = a1;
  sub16(80507CC)();
  sub16(8050348)();
  sub16(80507E4)();
  v2 = sub16(8004370)(ApocalypseData, 3);
  v3 = v2;
  *(_DWORD *)(v2 + 92) = v1;
  *(_WORD *)(v2 + 44) = 0;
  v4 = sub16(8054FEC)(v1);
  *(_BYTE *)(v3 + 41) = sub16(8054E74)(v4);
  return 1;
//  return v6;
}

int Apocalypse(int a1)
{
  int v1; // r6@1
  int v2; // r5@1
  signed int v3; // r4@1
  __int16 v4; // r0@1
  int v5; // r1@3
  int v6; // r0@4
  int v7; // r0@4
//  int v8; // r0@17
//  int v9; // [sp+18h] [bp-4h]@0

  v1 = a1;
  v2 = sub16(8054F90)(*(_DWORD *)(a1 + 92));
  v3 = sub16(8050F54)();
  v4 = *(_WORD *)(v1 + 44) + 1;
  *(_WORD *)(v1 + 44) = v4;
  if ( v4 == 1 )
    sub16(804EC74)(*(_DWORD *)(v1 + 92), 0xFFFFu);
  v5 = *(_WORD *)(v1 + 44);
  if ( v5 == v3 + 1 )
  {
    loadApocalypseBGData(v2, 465);//大魔法阵
    loadApocalypseBGPal(v2);
    sub_FE6_8052C68();
    sub_FE6_805315C(v2, 395, 10);
    sub_FE6_80531C4(v2, 415, 20);
    loadApocalypseCharacters(v2); //旋转字符
    sub_FE6_805304C(v2, 465); 
    v6 = sub16(80560A4)(v2, 465, 20, 128);
    sub_FE6_80530E4(v2, v6, 140);
    sub16(80565FC)(v2, 465, (int)sub_FE6_804CD4C);
    v7 = 260;
LABEL_11:
    sub16(80689D0)(v7, 256, 120, 0); //音效播放函数
//    return v9;
	return 1;
  }
  if ( v5 == v3 + 146 )
  {
    v7 = 261;
    goto LABEL_11;
  }
  if ( v5 == v3 + 460 )
  {
    sub16(804F8D8)(v2, 10, 20);
  }
  else
  {
    if ( v5 == v3 + 469 )
    {
      loadApocalypseWhirlPool(v2, 160); //暗漩涡
      sub16(80566F0)(v2, 110, 40, 16);
      loadApocalypseBlackSun(v2, 140, 24); //黑太阳
      loadApocalypseDust(v2, 60); //砂尘
      // sub_FE6_804D050(v2, 90);
	  sub16(80569B8)(v2, 90);
      v7 = 262;
      goto LABEL_11;
    }
    if ( v5 == v3 + 525 )
    {
      *(_WORD *)(v2 + 16) |= 9u;
      sub16(805091C)(v2, *(_BYTE *)(v1 + 41));
      if ( !*(_BYTE *)(v1 + 41) )
        sub16(8068500)(v2);
    }
    else if ( v5 != v3 + 625 && v5 == v3 + 635 )
    {
      sub16(80507D8)();
      sub16(80503A0)();
      sub16(800457C)(v1);
    }
  }
  return 1;
//  return v9;
}

int loadApocalypseBGData(int a1, __int16 a2)
{
  int v2; // r4@1
  __int16 v3; // r5@1
  int v4; // r0@1
 // int v6; // [sp+10h] [bp-4h]@0

  v2 = a1;
  v3 = a2;
  ++*(vl int *)0x201774C;
  v4 = sub16(8004370)(FE6_85D2620_Data, 3);
  *(_DWORD *)(v4 + 92) = v2;
  *(_WORD *)(v4 + 44) = 0;
  *(_WORD *)(v4 + 46) = v3;
  sub16(8050DE8)(ApocalypseBGTilesLZ_bin, 0x1080);//解压BG图块并拷贝到0x6002000
  sub16(80507F4)();
  LZ77UnCompWram(ApocalypseBGMapLZ_bin, (void *)0x2019784);
  sub16(80672B8)(0x2019784, 0x2023460, 0x20u, 0x14u, 1, 256);
  sub16(805081C)();
  *(vl _BYTE *)0x3002791 &= 0x1Fu;
  return 1;
}

int loadApocalypseBGPal(int a1)
{
  int v1; // r4@1
  int v2; // r0@1
//  int v4; // [sp+4h] [bp-4h]@0

  v1 = a1;
  ++*(vl int *)0x201774C;
  v2 = sub16(8004370)(ApocalypseBGPalData, 3);
  *(_DWORD *)(v2 + 92) = v1;
  *(_WORD *)(v2 + 44) = 0;
  *(_WORD *)(v2 + 46) = 16;
  sub16(8050E10)(ApocalypseBGPal_bin, 32);
  sub16(80676D4)(0x2022860, 1, 1, 16);
  sub16(8001034)();
//  return v4;
  return 1;
}

int ApocalypseBGPal(int a1)
{
  int v1; // r5@1
  int v2; // ST00_4@1
  int v3; // r4@1
  int v4; // r0@1
//  int v6; // [sp+Ch] [bp-4h]@0

  v1 = a1;
  v2 = *(_WORD *)(a1 + 46);
  v3 = sub16(8013508)(0, 16, 0, *(_WORD *)(a1 + 44),v2);
  sub16(8050E10)(ApocalypseBGPal_bin, 32);
  sub16(80676D4)(0x2022860, 1, 1, v3);
  sub16(8001034)();
  v4 = *(_WORD *)(v1 + 44) + 1;
  *(_WORD *)(v1 + 44) = v4;
  if ( v4 << 16 > *(_WORD *)(v1 + 46) << 16 )
  {
    --*(vl int *)0x201774C;
    sub16(800457C)(v1);
  }
//  return v6;
  return 1;
}

int sub_FE6_8052C68()
{
  int v0; // r4@1
//  int v2; // [sp+4h] [bp-4h]@0

  ++*(vl int *)0x201774C;
  v0 = sub16(8004370)(FE6_85D2638_Data, 3);
  sub16(8001D64)(1u, 0, 16);
  *(_WORD *)(v0 + 44) = 0;
  *(_WORD *)(v0 + 46) = 0;
  *(_WORD *)(v0 + 48) = 0;
//  return v2;	
  return 1;
}

int sub_FE6_8052C9C(int a1)
{
  int v1; // r6@1
  __int16 v2; // r2@1
  __int16 v3; // r3@3
  int v4; // r0@5
//  int v6; // [sp+10h] [bp-4h]@0

  v1 = a1;
  v2 = sub16(8013508)(0, 0, 255, *(_WORD *)(a1 + 48), 150);
  if ( (signed int)*(_WORD *)(v1 + 48) <= 150 )
    ++*(_WORD *)(v1 + 48);
  v3 = *(_WORD *)(v1 + 46);
  *(vl _WORD *)0x30027B0 = *((_WORD *)FE6_8605A94_data_bin + (unsigned __int8)v3) * v2 << 16 >> 24;
  *(vl _WORD *)0x30027B2 = (*((_WORD *)FE6_8605A94_data_bin + (unsigned __int8)v3 + 64) * v2 << 16 >> 24) + 16;
  *(_WORD *)(v1 + 46) = v3 + 2;
  if ( !(*(_WORD *)(v1 + 44) & 1) )
    sub16(8001D64)(1u, 0, 16);
  v4 = *(_WORD *)(v1 + 44) + 1;
  *(_WORD *)(v1 + 44) = v4;
  if ( v4 << 16 == 0x1400000 )
  {
    --*(vl int *)0x201774C;
    sub16(800457C)(v1);
  }
//  return v6;
  return 1;
}

int sub_FE6_805315C(int a1, __int16 a2, __int16 a3)
{
  int v3; // r6@1
  __int16 v4; // r4@1
  __int16 v5; // r5@1
  int v6; // r0@1
//  int v8; // [sp+Ch] [bp-4h]@0

  v3 = a1;
  v4 = a2;
  v5 = a3;
  ++*(vl int *)0x201774C;
  v6 = sub16(8004370)(FE6_85D2708_Data, 3);
  *(_WORD *)(v6 + 44) = 0;
  *(_WORD *)(v6 + 46) = v4;
  *(_WORD *)(v6 + 48) = v5;
  *(_DWORD *)(v6 + 92) = v3;
//  return v8;
  return 1;
}

int sub_FE6_805318C(int a1)
{
  int v1; // r4@1
  int v2; // r0@1
//  int v4; // [sp+4h] [bp-4h]@0

  v1 = a1;
  v2 = *(_WORD *)(a1 + 44) + 1;
  *(_WORD *)(v1 + 44) = v2;
  if ( v2 << 16 > *(_WORD *)(v1 + 46) << 16 )
  {
    --*(vl int *)0x201774C;
    sub16(804F7B8)(*(_DWORD *)(v1 + 92), *(_WORD *)(v1 + 48));
    sub16(800457C)(v1);
  }
//  return v4;
  return 1;
}

int sub_FE6_80531C4(int a1, __int16 a2, __int16 a3)
{
  int v3; // r6@1
  __int16 v4; // r4@1
  __int16 v5; // r5@1
  int v6; // r0@1
//  int v8; // [sp+Ch] [bp-4h]@0

  v3 = a1;
  v4 = a2;
  v5 = a3;
  ++*(vl int *)0x201774C;
  v6 = sub16(8004370)(FE6_85D2720_Data, 3);
  *(_WORD *)(v6 + 44) = 0;
  *(_WORD *)(v6 + 46) = v4;
  *(_WORD *)(v6 + 48) = v5;
  *(_DWORD *)(v6 + 92) = v3;
//  return v8;
  return 1;
}

int sub_FE6_80531F4(int a1)
{
  int v1; // r2@1
  int v2; // r0@1
//  int v4; // [sp+0h] [bp-4h]@0

  v1 = a1;
  v2 = *(_WORD *)(a1 + 44) + 1;
  *(_WORD *)(v1 + 44) = v2;
  if ( v2 << 16 > *(_WORD *)(v1 + 46) << 16 )
  {
    *(_WORD *)(v1 + 44) = 0;
    sub16(800457C)(v1);
  }
//  return v4;
  return 1;
}

int sub_FE6_8053218(int a1)
{
  int v1; // r5@1
  int v2; // r4@1
  int v3; // r0@1
//  int v5; // [sp+Ch] [bp-4h]@0

  v1 = a1;
  v2 = sub16(8013508)(0, 0, 16, *(_WORD *)(a1 + 44), *(_WORD *)(a1 + 48));
  sub16(8050E10)(ApocalypseBGPal_bin, 32);
  sub16(8067750)(0x2022860, 1, 1, v2);
  v3 = *(_WORD *)(v1 + 44) + 1;
  *(_WORD *)(v1 + 44) = v3;
  if ( v3 << 16 > *(_WORD *)(v1 + 48) << 16 )
  {
    --*(vl int *)0x201774C;
    sub16(800457C)(v1);
  }
//  return v5;
  return 1;
}

int loadApocalypseCharacters(int a1)
{
  int v1; // r5@1
  unsigned int v2; // r4@1
  int v3; // r0@2
//  int v5; // [sp+8h] [bp-4h]@0

  v1 = a1;
  v2 = 0;
  do
  {
    v3 = sub16(8004370)(FE6_85D2678_Data, 3);
    *(_DWORD *)(v3 + 92) = v1;
    *(_DWORD *)(v3 + 68) = v2++;
  }
  while ( v2 <= 7 );
  sub16(8050DCC)(ApocalypseCharactersPal_bin, 32);
  sub16(8050DA4)(ApocalypseCharactersTilesLZ_bin, 2048);
//  return v5;
  return 1;
}

int sub_FE6_8052E30(int a1)
{
  int v1; // r4@1
  int v2; // r0@1
  int v3; // r0@1
//  int v5; // [sp+8h] [bp-4h]@0

  v1 = a1;
  ++*(vl int *)0x201774C;
  *(_WORD *)(a1 + 44) = 0;
  *(_WORD *)(a1 + 46) = 0;
  v2 = *(_DWORD *)(a1 + 68);
  *(_WORD *)(v1 + 48) = (_WORD)v2 << 13;
  v3 = sub16(8050BF8)(
         *(_DWORD *)(v1 + 92),
         (int)FE6_85D26B0_Data[v2],
         (int)FE6_85D26B0_Data[v2],
         (int)FE6_85D26B0_Data[v2],
         (int)FE6_85D26B0_Data[v2]);
  *(_DWORD *)(v1 + 96) = v3;
  *(_WORD *)(v3 + 8) = *(_WORD *)(v3 + 8) & 0xF3FF | 0x400;
  *(_WORD *)(v3 + 2) = 256;
  *(_WORD *)(v3 + 4) = 256;
  *(_WORD *)(v1 + 50) = 120;
  *(_WORD *)(v1 + 58) = 64;
  sub16(800457C)(v1);
//  return v5;
  return 1;
}

//BUG：只能显示gba屏幕第一象限的1/4圆的运动轨迹，废弃，用汇编重写
/* int sub_FE6_8052E9C(int a1)
{
  int v1; // r5@1
  int v2; // r4@1
  __int16 v3; // r0@1
  unsigned int v4; // r1@1
  unsigned int v5; // r2@1
  int v6; // r1@1
  int v7; // r0@1
  __int16 v8; // r3@1
  __int16 v9; // r0@3
//  int v11; // [sp+14h] [bp-4h]@0

  v1 = a1;
  v2 = *(_DWORD *)(a1 + 96);
  v3 = sub16(8013508)(0, 180, 50, *(_WORD *)(a1 + 44), 60);
  v4 = *(_WORD *)(v1 + 48) + 768;
  *(_WORD *)(v1 + 48) = v4;
  v5 = v4 >> 8;
  v6 = 16 * Sin(v4 >> 8) * v3;
  v7 = 16 * v3 * Sin(v5 + 64);
  v8 = *(_WORD *)(v1 + 58);
  *(_WORD *)(v2 + 2) = *(_WORD *)(v1 + 50) + HIWORD(v6);
  *(_WORD *)(v2 + 4) = v8 + HIWORD(v7);
  LOWORD(v7) = *(_WORD *)(v1 + 44) + 1;//warning: dereferencing type-punned pointer will break strict-aliasing rules [-Wstrict-aliasing]
  *(_WORD *)(v1 + 44) = v7;
  if ( (signed __int16)v7 > 60 )
    *(_WORD *)(v1 + 44) = 60;
  v9 = *(_WORD *)(v1 + 46) + 1;
  *(_WORD *)(v1 + 46) = v9;
  if ( v9 > 120 )
  {
    *(_WORD *)(v1 + 44) = 0;
    *(_WORD *)(v1 + 46) = 0;
    sub16(800457C)(v1);
  }
//  return v11;
  return 1;
}

int sub_FE6_8052F28(int a1)
{
  int v1; // r5@1
  int v2; // r4@1
  __int16 v3; // r0@1
  unsigned int v4; // r1@1
  unsigned int v5; // r2@1
  int v6; // r1@1
  int v7; // r0@1
  __int16 v8; // r3@1
  __int16 v9; // r0@3
//  int v11; // [sp+14h] [bp-4h]@0

  v1 = a1;
  v2 = *(_DWORD *)(a1 + 96);
  v3 = sub16(8013508)(0, 50, 0, *(_WORD *)(a1 + 44), 80);
  v4 = *(_WORD *)(v1 + 48) + 768;
  *(_WORD *)(v1 + 48) = v4;
  v5 = v4 >> 8;
  v6 = 16 * Sin(v4 >> 8) * v3;
  v7 = 16 * v3 * Sin(v5 + 64);
  v8 = *(_WORD *)(v1 + 58);
  *(_WORD *)(v2 + 2) = *(_WORD *)(v1 + 50) + HIWORD(v6);
  *(_WORD *)(v2 + 4) = v8 + HIWORD(v7);
  LOWORD(v7) = *(_WORD *)(v1 + 44) + 1;//warning: dereferencing type-punned pointer will break strict-aliasing rules [-Wstrict-aliasing]
  *(_WORD *)(v1 + 44) = v7;
  if ( (signed __int16)v7 > 80 )
    *(_WORD *)(v1 + 44) = 80;
  v9 = *(_WORD *)(v1 + 46) + 1;
  *(_WORD *)(v1 + 46) = v9;
  if ( v9 > 80 )
  {
    *(_WORD *)(v1 + 44) = 0;
    *(_WORD *)(v1 + 46) = 0;
    sub16(800457C)(v1);
  }
//  return v11;
  return 1;
}

int sub_FE6_8052FB4(int a1)
{
  int v1; // r5@1
  int v2; // r4@1
  __int16 v3; // r0@1
  unsigned int v4; // r1@1
  unsigned int v5; // r2@1
  int v6; // r1@1
  int v7; // r0@1
  __int16 v8; // r3@1
  __int16 v9; // r0@3
//  int v11; // [sp+10h] [bp-4h]@0

  v1 = a1;
  v2 = *(_DWORD *)(a1 + 96);
  v3 = sub16(8013508)(1u, 0, 180, *(_WORD *)(a1 + 44), 50);
  v4 = *(_WORD *)(v1 + 48) + 2048;
  *(_WORD *)(v1 + 48) = v4;
  v5 = v4 >> 8;
  v6 = 16 * Sin(v4 >> 8) * v3;
  v7 = 16 * v3 * Sin(v5 + 64);//诱导公式 cosA=sin(A+pi/2)
  v8 = *(_WORD *)(v1 + 58);
  *(_WORD *)(v2 + 2) = *(_WORD *)(v1 + 50) + HIWORD(v6);
  *(_WORD *)(v2 + 4) = v8 + HIWORD(v7);
  LOWORD(v7) = *(_WORD *)(v1 + 44) + 1;//warning: dereferencing type-punned pointer will break strict-aliasing rules [-Wstrict-aliasing]
  *(_WORD *)(v1 + 44) = v7;
  if ( (signed __int16)v7 > 50 )
    *(_WORD *)(v1 + 44) = 50;
  v9 = *(_WORD *)(v1 + 46) + 1;
  *(_WORD *)(v1 + 46) = v9;
  if ( v9 > 50 )
  {
    --*(vl int *)0x201774C;
    sub16(80064E0)(*(_DWORD *)(v1 + 96));
    sub16(800457C)(v1);
  }
//  return v11;
  return 1;
} */

int sub_FE6_8052C34(int a1)
{
  int v1; // r4@1
  int v2; // r0@1
//  int v4; // [sp+4h] [bp-4h]@0

  v1 = a1;
  v2 = *(_WORD *)(a1 + 44) + 1;
  *(_WORD *)(v1 + 44) = v2;
  if ( v2 << 16 == *(_WORD *)(v1 + 46) << 16 )
  {
    sub16(80507F4)();
    --*(vl int *)0x201774C;
    sub16(80508F4)();
    sub16(8004460)(v1);
  }
//  return v4;
  return 1;
}

int sub_FE6_805304C(int a1, __int16 a2)
{
  int v2; // r4@1
  __int16 v3; // r5@1
  int v4; // r0@1
//  int v6; // [sp+8h] [bp-4h]@0

  v2 = a1;
  v3 = a2;
  ++*(vl int *)0x201774C;
  v4 = sub16(8004370)(FE6_85D26D0_Data, 3);
  *(_DWORD *)(v4 + 92) = v2;
  *(_WORD *)(v4 + 44) = 0;
  *(_WORD *)(v4 + 46) = 0;
  *(_WORD *)(v4 + 48) = v3;
  *(_DWORD *)(v4 + 68) = 0;
  *(_DWORD *)(v4 + 72) = (u32)FE6_811A62A_data_bin;
  *(_DWORD *)(v4 + 76) = (u32)&ApocalypseCharactersPal_bin[2];
//  return v6;
  return 1;
}

int sub_FE6_805308C(int a1)
{
  int v1; // r4@1
  int v2; // r3@1
  int v3; // r0@3
//  int v5; // [sp+8h] [bp-4h]@0

  v1 = a1;
  v2 = (signed __int16)sub_FE6_8047BA4((_WORD *)(a1 + 44), (_WORD *)(v1 + 68), *(__int16 **)(v1 + 72));
//  v2 = sub16(8050EC0)((_WORD *)(a1 + 44), (_WORD *)(v1 + 68), *(__int16 **)(v1 + 72));
  if ( v2 >= 0 )
  sub_FE6_8047B6C(*(_DWORD *)(v1 + 76), 0x2022862, v2, 0xFu, 0xFu);
//  sub16(8050E58)(*(int *)(v1 + 76),0x2022862,(unsigned int)v2,0xFu, 0xFu);
  v3 = *(_WORD *)(v1 + 46) + 1;
  *(_WORD *)(v1 + 46) = v3;
  if ( v3 << 16 > *(_WORD *)(v1 + 48) << 16 )
  {
    --*(vl int *)0x201774C;
    sub16(800457C)(v1);
  }
//  return v5;
  return 1;
}

signed int sub_FE6_8047BA4(_WORD *a1, _WORD *a2, __int16 *a3)
{
  _WORD *v3; // r5@1
  _WORD *v4; // r3@1
  int v5; // r0@1
  __int16 v6; // r6@1
  int v7; // r0@2
  int v8; // r12@2
  __int16 *v9; // r0@2
  __int16 v10; // r4@2
  int v11; // r1@2
  signed int result; // r0@4
  int v13; // r1@9
  __int16 v14; // r0@9

  v3 = a1;
  v4 = a2;
  v5 = *a1;
  v6 = v5;
  if ( v5 )
  {
    *v3 = v5 - 1;
    result = -5;
  }
  else
  {
    v7 = *a2;
    v8 = v7;
    v9 = &a3[2 * v7];
    v10 = *v9;
    v11 = *v9;
    if ( v11 != -1 && v11 != -4 )
    {
      if ( v11 == -2 )
      {
        *v4 = v6;
        v10 = *a3;
      }
      else if ( v11 == -3 )
      {
        *v4 = v8 - 1;
        v10 = a3[2 * (v8 - 1)];
      }
      v13 = *v4;
      v14 = a3[2 * v13 + 1];
      *v4 = v13 + 1;
      *v3 = v14 - 1;
      result = v10;
    }
    else
    {
      result = *v9;
    }
  }
  return result;
}

int sub_FE6_8047B6C(int a1, int a2, unsigned int a3, unsigned int a4, unsigned int a5)
{
  unsigned int v5; // r5@1
  unsigned int v6; // r3@1
  _WORD *v7; // r1@2
//  int v9; // [sp+Ch] [bp-4h]@0

  v5 = a4;
  v6 = 0;
  if ( a5 > 0 )
  {
    v7 = (_WORD *)(a2 + 576);
    do
    {
      if ( a3 >= v5 )
        a3 = 0;
      *v7 = *(_WORD *)(2 * a3 + a1);
      ++v7;
      ++v6;
      ++a3;
    }
    while ( v6 < a5 );
  }
  sub16(8001034)();
//  return v9;
  return 1;
}

int sub_FE6_80530E4(int a1, int a2, __int16 a3)
{
  int v3; // r4@1
  int v4; // r6@1
  __int16 v5; // r5@1
  int v6; // r0@1
//  int v8; // [sp+Ch] [bp-4h]@0

  v3 = a1;
  v4 = a2;
  v5 = a3;
  ++*(vl int *)0x201774C;
  v6 = sub16(8004370)(FE6_85D26F0_Data, 3);
  *(_DWORD *)(v6 + 92) = v3;
  *(_WORD *)(v6 + 44) = 0;
  *(_WORD *)(v6 + 46) = v5;
  *(_DWORD *)(v6 + 100) = v4;
//  return v8;
  return 1;
}

int sub_FE6_8053114(int a1)
{
  int v1; // r5@1
  int v2; // r4@1
  int v3; // r0@1
//  int v5; // [sp+Ch] [bp-4h]@0

  v1 = a1;
  v2 = *(_DWORD *)(a1 + 100);
  *(_DWORD *)(v2 + 76) = sub16(8013508)(4u, 128, 0, *(_WORD *)(a1 + 44), *(_WORD *)(a1 + 46));
  v3 = *(_WORD *)(v1 + 44) + 1;
  *(_WORD *)(v1 + 44) = v3;
  if ( v3 << 16 > *(_WORD *)(v1 + 46) << 16 )
  {
    --*(vl int *)0x201774C;
    sub16(800457C)(v1);
  }
//  return v5;
  return 1;
}

int loadApocalypseWhirlPool(int a1, __int16 a2)
{
  int v2; // r6@1
  __int16 v3; // r4@1
  int v4; // r5@1
//  int v5; // r0@1
  int v6; // r0@2
//  int v8; // [sp+Ch] [bp-4h]@0

  v2 = a1;
  v3 = a2;
  ++*(vl int *)0x201774C;
  v4 = sub16(8004370)(FE6_85D2740_Data, 3);
  *(_DWORD *)(v4 + 92) = v2;
  *(_WORD *)(v4 + 44) = 0;
  *(_WORD *)(v4 + 46) = 0;
  *(_WORD *)(v4 + 48) = v3;
  *(_DWORD *)(v4 + 68) = 0;
  *(_DWORD *)(v4 + 72) = (u32)ApocalypseWhirlPoolAnimationPlayData;
  *(_DWORD *)(v4 + 76) = (u32)ApocalypseWhirlPoolFrameMap;
  *(_DWORD *)(v4 + 80) = (u32)ApocalypseWhirlPoolFrameMap;
  *(_DWORD *)(v4 + 84) = (u32)ApocalypseWhirlPoolFrameTiles;
  sub16(8050E10)(ApocalypseWhirlPoolPal_bin, 32);
  sub16(805081C)();
  sub16(8001D64)(1u, 0, 0);
  if ( sub_FE6_805894C() )
  {
    v6 = sub_FE6_804B80C(*(_DWORD *)(v4 + 92));
    *(_BYTE *)0x300279C &= 0xFCu;
    *(_BYTE *)0x30027A8 = *(_BYTE *)0x30027A8 & 0xFC | 1;
    *(_BYTE *)0x30027A0 = *(_BYTE *)0x30027A0 & 0xFC | 2;
    *(_BYTE *)0x30027A4 |= 3u;
    *(_WORD *)(v2 + 8) = *(_WORD *)(v2 + 8) & 0xF3FF | 0x400;
    *(_WORD *)(v6 + 8) = *(_WORD *)(v6 + 8) & 0xF3FF | 0x400;
  }
  // return v8;
  return 1;
}

signed int sub_FE6_805894C()
{
  signed int v0; // r4@1

  v0 = 0;
  if ( *(_WORD *)sub_FE6_80589FC(0) == 83 )
    v0 = 1;
  if ( *(_WORD *)sub_FE6_80589FC(1) == 83 )
    v0 |= 2u;
  if ( *(_WORD *)sub_FE6_80589FC(0) == 112 )
    v0 |= 0x10u;
  if ( *(_WORD *)sub_FE6_80589FC(1) == 112 )
    v0 |= 0x20u;
  return v0;
}

int sub_FE6_80589FC(int a1)
{
  return 2 * a1 + 0x203E0D0;
}

int sub_FE6_804CD4C()
{
  int result; // r0@1

  result = *(vl _BYTE *)0x4000004 & 1;
  if ( !(*(vl _BYTE *)0x4000004 & 1) )
  {
    *(vl _WORD *)0x4000040 = *(vl _WORD *)(*(vl _DWORD *)0x201FB28);
    *(vl _DWORD *)0x201FB28 += 2;
    *(vl _WORD *)0x4000014 = *(vl _WORD *)(*(vl _DWORD *)0x201FDB4);
    result = *(vl _DWORD *)0x201FDB4 + 2;
    *(vl _DWORD *)0x201FDB4 += 2;
  }
  return result;
}

int sub_FE6_804B80C(int a1)
{
  return *(_DWORD *)(8 * !sub_FE6_804B6C4(a1) + 0x2000000);
}

bool sub_FE6_804B6C4(int a1)
{
  return (*(_WORD *)(a1 + 12) & 0x200) != 0;
}

int sub_FE6_8053340(int a1)
{
  int v1; // r7@1
  int v2; // r8@1
  int v3; // r4@1
  int v4; // r5@2
  int v5; // r6@2
  int v6; // r4@2
  int v7; // r0@3
  // int v9; // [sp+14h] [bp-4h]@0

  v1 = a1;
  v2 = sub_FE6_804B80C(*(_DWORD *)(a1 + 92));
  v3 = (signed __int16)sub_FE6_8047BA4((_WORD *)(v1 + 44), (_WORD *)(v1 + 68), *(__int16 **)(v1 + 72));
  if ( v3 >= 0 )
  {
    v4 = *(_DWORD *)(v1 + 76);
    v5 = *(_DWORD *)(v1 + 80);
    v6 = 4 * v3;
    sub16(8050DE8)(*(_DWORD *)(v6 + *(_DWORD *)(v1 + 84)), 0x2000);
    sub16(8050CB8)(*(_DWORD *)(v1 + 92), *(void **)(v6 + v4), *(void **)(v6 + v5));
  }
  v7 = *(_WORD *)(v1 + 46) + 1;
  *(_WORD *)(v1 + 46) = v7;
  if ( v7 << 16 == *(_WORD *)(v1 + 48) << 16 )
  {
    if ( sub_FE6_805894C() )
    {
      *(_BYTE *)0x300279C &= 0xFCu;
      *(_BYTE *)0x30027A0 = *(_BYTE *)0x30027A0 & 0xFC | 1;
      *(_BYTE *)0x30027A8 = *(_BYTE *)0x30027A8 & 0xFC | 2;
      *(_BYTE *)0x30027A4 |= 3u;
      *(_WORD *)(*(_DWORD *)(v1 + 92) + 8) &= 0xF3FFu;
      *(_WORD *)(*(_DWORD *)(v1 + 92) + 8) |= 0x800u;
      *(_WORD *)(v2 + 8) = *(_WORD *)(v2 + 8) & 0xF3FF | 0x800;
    }
    sub16(80507F4)();
    --*(vl int *)0x201774C;
    sub16(80508F4)();
    sub16(8004460)(v1);
  }
  // return v9;
}

int loadApocalypseBlackSun(int a1, __int16 a2, __int16 a3)
{
  int v3; // r5@1
  __int16 v4; // r6@1
  __int16 v5; // r8@1
  int v6; // r4@1
  unsigned int v7; // r5@1
//  int v9; // [sp+14h] [bp-4h]@0

  v3 = a1;
  v4 = a2;
  v5 = a3;
  ++*(vl int *)0x201774C;
  v6 = sub16(8004370)(FE6_85D2778_Data, 3);
  *(_DWORD *)(v6 + 92) = v3;
  *(_WORD *)(v6 + 44) = 0;
  *(_WORD *)(v6 + 46) = v4;
  *(_WORD *)(v6 + 48) = v5;
  v7 = sub16(8050BF8)(v3, (int)FE6_85EBF40_Data, (int)FE6_85EBF40_Data, (int)FE6_85EBF40_Data, (int)FE6_85EBF40_Data);
  *(_DWORD *)(v6 + 96) = v7;
  *(_WORD *)(v7 + 2) = 120;
  *(_WORD *)(v7 + 4) = 72;
  *(_WORD *)(v7 + 10) = 20;
  sub16(8006488)();
  if ( sub_FE6_805894C() )
    *(_WORD *)(v7 + 8) = *(_WORD *)(v7 + 8) & 0xF3FF | 0xC00;
  sub16(8050DCC)(ApocalypseSpritePal_bin, 32);
  sub16(8050DA4)(ApocalypseSpriteTilesLZ_bin, 4096);
//  return v9;
  return 1;
}

int sub_FE6_80534BC(int a1)
{
  int v1; // r4@1
  int v2; // r2@1
  int v3; // r0@1
//  int v5; // [sp+8h] [bp-4h]@0

  v1 = a1;
  v2 = *(_DWORD *)(a1 + 96);
  v3 = *(_WORD *)(a1 + 44) + 1;
  *(_WORD *)(v1 + 44) = v3;
  if ( v3 << 16 > *(_WORD *)(v1 + 46) << 16 )
  {
    *(_WORD *)(v1 + 44) = 0;
    *(_DWORD *)(v2 + 36) = (u32)FE6_85EC478_data;
    *(_DWORD *)(v2 + 32) = (u32)FE6_85EC478_data;
    *(_WORD *)(v2 + 6) = 0;
    sub16(8050DA4)(ApocalypseBlackSunTilesLZ_bin, 4096);
    sub16(800457C)(v1);
  }
//  return v5;
  return 1;
}

int sub_FE6_80534FC(int a1)
{
  int v1; // r4@1
  int v2; // r0@1
  // int v4; // [sp+4h] [bp-4h]@0

  v1 = a1;
  v2 = *(_WORD *)(a1 + 44) + 1;
  *(_WORD *)(v1 + 44) = v2;
  if ( v2 << 16 > *(_WORD *)(v1 + 48) << 16 )
  {
    sub16(80064E0)(*(_DWORD *)(v1 + 96));
    --*(vl int *)0x201774C;
    sub16(800457C)(v1);
  }
  // return v4;
  return 1;
}

int loadApocalypseDust(int a1, __int16 a2)
{
  int v2; // r4@1
  __int16 v3; // r5@1
  int v4; // r0@1
  // int v6; // [sp+8h] [bp-4h]@0

  v2 = a1;
  v3 = a2;
  ++*(vl int *)0x201774C;
  v4 = sub16(8004370)(FE6_85D2798_Data, 3);
  *(_DWORD *)(v4 + 92) = v2;
  *(_WORD *)(v4 + 44) = 0;
  *(_WORD *)(v4 + 46) = v3;
  *(_WORD *)(v4 + 48) = 0;
  *(_DWORD *)(v4 + 68) = 1;
  *(_DWORD *)(v4 + 72) = 0;
  *(_DWORD *)(v4 + 76) = 0;
  // return v6;
  return 1;
}

int sub_FE6_8053568(int a1)
{
  int v1; // r4@1
  int v2; // r0@1
  __int16 v3; // r0@3
  int v4; // r1@4
  int v5; // r7@4
  int v6; // r6@4
  unsigned int v7; // r5@4
  // int v9; // [sp+10h] [bp-4h]@0

  v1 = a1;
  v2 = *(_WORD *)(a1 + 44) + 1;
  *(_WORD *)(v1 + 44) = v2;
  if ( v2 << 16 == *(_WORD *)(v1 + 46) << 16 )
  {
    --*(vl int *)0x201774C;
    sub16(800457C)(v1);
  }
  else
  {
    v3 = *(_WORD *)(v1 + 48) + 1;
    *(_WORD *)(v1 + 48) = v3;
    if ( v3 == *(_DWORD *)(v1 + 68) )
    {
      *(_WORD *)(v1 + 48) = 0;
      *(_DWORD *)(v1 + 68) = 2;
      v4 = *(_DWORD *)(v1 + 76);
      v5 = FE6_85D27B0_data[v4];
      v6 = FE6_85D287C_data[v4];
      v7 = FE6_85D2944_data[v4++];
      *(_DWORD *)(v1 + 76) = v4;
      if ( FE6_85D27B0_data[v4] == -1 )
        *(_DWORD *)(v1 + 76) = 0;
      sub_FE6_80535F8(*(_DWORD *)(v1 + 92), v5, v6, v7);
    }
  }
  // return v9;
  return 1;
}

int sub_FE6_80535F8(int a1, int a2, int a3, unsigned int a4)
{
  int v4; // r8@1
  int v5; // r4@1
  int v6; // r5@1
  unsigned int v7; // r7@1
  int v8; // r6@1
  void **v9; // r3@3
  unsigned int v10; // r4@6
  // int v12; // [sp+18h] [bp-4h]@0

  v4 = a1;
  v5 = a2;
  v6 = a3;
  v7 = a4;
  ++*(vl int *)0x201774C;
  v8 = sub16(8004370)(FE6_85D2A0C_Data, 3);
  *(_DWORD *)(v8 + 92) = v4;
  *(_WORD *)(v8 + 44) = 0;
  *(_WORD *)(v8 + 46) = v5;
  *(_DWORD *)(v8 + 68) = v6;
  *(_DWORD *)(v8 + 72) = v6 + (v5 << 11);
  *(_WORD *)(v8 + 50) = 120;
  *(_WORD *)(v8 + 58) = 72;
  if ( v7 > 6 )
  {
def_8053640:
    v9 = &FE6_85EBF40_Data[4];
  }
  else
  {
    switch ( v7 )
    {
      case 0u:
      case 1u:
      case 2u:
      case 3u:
      case 4u:
        v9 = (void **)&FE6_85EBF40_Data[8];
        break;
      case 5u:
        v9 = &FE6_85EBF40_Data[6];
        break;
      default:
        goto def_8053640;
    }
  }
  v10 = sub16(8050BF8)(v4, (int)v9, (int)v9, (int)v9, (int)v9);
  *(_DWORD *)(v8 + 96) = v10;
  *(_WORD *)(v10 + 2) = 256;
  *(_WORD *)(v10 + 4) = 256;
  if ( sub_FE6_805894C() )
    *(_WORD *)(v10 + 8) = *(_WORD *)(v10 + 8) & 0xF3FF | 0x400;
  // return v12;
  return 1;
}

//BUG：只能显示gba屏幕第一象限内，废弃，用汇编重写
/* int sub_FE6_80536C4(int a1)
{
  int v1; // r6@1
  int v2; // r5@1
  __int16 v3; // r4@1
  unsigned int v4; // r0@1
  _WORD *v5; // r1@1
  int v6; // r0@1
  // int v8; // [sp+14h] [bp-4h]@0

  v1 = a1;
  v2 = *(_DWORD *)(a1 + 96);
  v3 = sub16(8013508)(1u, 110, 0, *(_WORD *)(a1 + 44), *(_WORD *)(a1 + 46));
  v4 = (unsigned int)(sub16(8013508)(
                        1u,
                        *(_DWORD *)(v1 + 68),
                        *(_DWORD *)(v1 + 72),
                        *(_WORD *)(v1 + 44),
                        *(_WORD *)(v1 + 46)) << 16) >> 24;
  v5 = &Sin(v4);
  LOWORD(v4) = *(_WORD *)(v1 + 58) + ((unsigned int)(Sin(v4 + 64) * v3) >> 12);
  *(_WORD *)(v2 + 2) = *(_WORD *)(v1 + 50) + ((unsigned int)(*v5 * v3) >> 12);
  *(_WORD *)(v2 + 4) = v4;
  v6 = *(_WORD *)(v1 + 44) + 1;
  *(_WORD *)(v1 + 44) = v6;
  if ( v6 << 16 > *(_WORD *)(v1 + 46) << 16 )
  {
    sub16(80064E0)(*(_DWORD *)(v1 + 96));
    --*(vl int *)0x201774C;
    sub16(800457C)(v1);
  }
  // return v8;
}
 */

//这个函数不需要重写 
/* int sub_FE6_804D050(int a1, __int16 a2)
{
  int v2; // r5@1
  __int16 v3; // r6@1
  int v4; // r0@1
  int v5; // r4@1
  // int v7; // [sp+Ch] [bp-4h]@0

  v2 = a1;
  v3 = a2;
  ++*(vl int *)0x201774C;
  v4 = sub16(8004370)(0x8C108F0, 3);
  v5 = v4;
  *(_DWORD *)(v4 + 92) = v2;
  *(_DWORD *)(v4 + 96) = sub16(804EF18)(6, 0);
  *(_WORD *)(v5 + 44) = 0;
  *(_WORD *)(v5 + 46) = v3;
  // return v7;
  return 1;
}
 */
