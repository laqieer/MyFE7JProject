// by Laqieer 2017/1/11
// 打印信息到GBA屏幕上用(一次不超过64个字符)
#pragma once

#include "FE7J.h"
#include "ASCII8x8font_bin.h"

//字模提取
//http://book.51cto.com/art/201403/431914.htm
//http://book.51cto.com/art/201403/431915.htm

//精灵相关
#define REG_DISPCNT					0x4000000
#define EnableDisplayOBJ			(1<<12)
#define OBJCharacterVramMapping(n)	(((1==n)?1:0)<<6)
#define CharacterTileVramBase		0x06014000
#define	CharacterPaletteRAM			0x5000300
#define CharacterOAMBase			0x7000200

//单字符
void printc(int x,int y,char c);
//字符串
void prints(int x,int y,char* s,int offset);
//清屏
void clearp();
