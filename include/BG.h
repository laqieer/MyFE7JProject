#pragma once

#include "FE7J.h"

//BG显示相关
#define PaletteRAM				0x5000000
#define BGPaletteRAM			PaletteRAM
#define VRAM					0x6000000
#define	IORegisters				0x4000000
#define REG_DISPCNT				IORegisters
#define BGMODE(mode)			(mode)
#define EnableDisplayBG(n) 		(1<<(8+n))
#define BGCNT(n)				(IORegisters+8+2*n)
#define BGPriority(n)			(n)
#define CharacterBaseBlock(n)	((n)<<2)
#define	BG256Colors				(1<<7)
#define ScreenBaseBlock(n)		((n)<<8)
#define BGScreenSize(n)			(n<<14)
#define BGHOFS(n)				(IORegisters+0x10+4*n)
#define BGVOFS(n)				(IORegisters+0x12+4*n)
#define BLDCNT					(IORegisters+0x50)
#define BLDY					(IORegisters+0x54)
#define OBJVramBase				0x6010000
#define CharacterNameVramBase	(OBJVramBase+0x20)
#define CharacterNameTilePalette	0x5000200
#define OAMBase	0x7000000
#define CharacterNameOAMBase	OAMBase
#define RegMOSAIC				(IORegisters+0x4C)
#define WINOUT					(IORegisters+0x4A)
#define WININ					(IORegisters+0x48)
#define WIN0H					(IORegisters+0x40)
#define WIN0V					(IORegisters+0x44)
#define OBJPaletteRAM			(PaletteRAM+0x200)
#define BLDALPHA				(IORegisters+0x52)

//等待一定帧数 60fps
#define Wait(n)					while(n--) VBlankIntrWait();

//人物全身像在屏幕左边自下向上滚动，带影子，人物名字从右向左移动至中间
void DrawCharacter(const unsigned int *CharacterTiles,const unsigned short *CharacterMap,const unsigned short *CharacterPal/* ,int CharacterTilesLength,int CharacterMapLength,int CharacterPalLength */,const unsigned short *CharacterNamePal,const unsigned int *CharacterNameTiles);
//两个人物并排，从白色背景中逐渐显现，左边的人物先出现
void Draw2Characters(const unsigned int *CharacterTiles,const unsigned short *CharacterMap,const unsigned short *CharacterPal,int leftWidth);
//马赛克效果显示CG
void ShowCGWithMosaic(const unsigned int *CGBitmap);
//横向滚动显示CG
void ScrollCGHorizontally(const unsigned int *Tiles,const unsigned short *Map,const unsigned short *Pal);
//OBJ蒙版效果
void CircleMask(const unsigned int *CGBitmap,const unsigned int *MaskOBJTiles,const unsigned short *MaskOBJPal);
//矩形蒙版效果
void RectangleMask(const unsigned int *CGBitmap);
//阿尔法混合
void AlphaBlending(const unsigned short *Pal,const unsigned int *Tiles,const unsigned short *Map/* 1,const unsigned short *Map2 */);
