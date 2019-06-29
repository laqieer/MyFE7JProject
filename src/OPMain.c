// by laqieer 2017/1/9

#include "BG.h"
#include "Print.h"

//图片
#include "Lyn.h"
#include "LynName.h"
#include "KarlaKarel.h"
#include "SexyLuise.h"
#include "HotFlorina.h"
#include "RebaccaPrescilla.h"
//#include "Circle32x32.h"
#include "Circle64x64.h"
/* #include "castle.h"
#include "cloud.h" */
#include "CloudCastle.h"

//VBlank中断相关
#define DISPSTAT				(IORegisters+4)
#define VBlankIRQEnable			(1<<3)
#define RegIME					(IORegisters+0x208)
#define RegIE					(IORegisters+0x200)
#define RegIF					(IORegisters+0x202)
#define IFBIOS				0x3007FF8
#define VBlankIntrFlag			1

void ffplayVideo(char *filename)
{
	asm volatile("mov r0, %0;"
               "swi 0xf8;"
               : // no ouput
               : "r" (filename)
               : "r0");
}

// 片头OP动画主程序
//__attribute__((section(".OPMain")))
void OPMain()
{
	ffplayVideo("FESoVOP.mkv");
}

void OPMainOld()
{
	int n = 1;
	//开中断
	*(vu32 *)RegIME = 1;
	*(vu16 *)RegIE |= VBlankIntrFlag;
	*(vu16 *)DISPSTAT |= VBlankIRQEnable;
	
	//打印主程序版本信息
	prints(240-8*11,160-8*3,__DATE__,0);
	prints(240-8*11,160-8*2,__TIME__,11);
	prints(240-8*5,160-8*2,"(UTC)",16);
	prints(240-8*7,160-8,"laqieer",23);
	n = 120;
	Wait(n);
	clearp();
		
	//滑动显示人物立绘
/* 	int LynTilesLength = LynTilesLen;
	int LynMapLength = LynMapLen;
	int LynPalLength = LynPalLen; */
	DrawCharacter(LynTiles,LynMap,LynPal/* ,LynTilesLength,LynMapLength,LynPalLength */,LynNamePal,LynNameTiles);
	
	//卡尔拉和卡雷尔的合影
	Draw2Characters(KarlaKarelTiles,KarlaKarelMap,KarlaKarelPal,18);
	
	//路易斯床照（马赛克处理）
	ShowCGWithMosaic(SexyLuiseBitmap);
	
	//自右向左横向滚动芙洛莉娜照片
	ScrollCGHorizontally(HotFlorinaTiles,HotFlorinaMap,HotFlorinaPal);
	
	//瑞贝卡和普莉希拉合影，矩形蒙版效果
	RectangleMask(RebaccaPrescillaBitmap);
	
	//瑞贝卡和普莉希拉合影，圆形蒙版效果
	//CircleMask(RebaccaPrescillaBitmap,Circle32x32Tiles,Circle32x32Pal);
	CircleMask(RebaccaPrescillaBitmap,Circle64x64Tiles,Circle64x64Pal);
	
	//云层和城堡阿尔法混合效果
	AlphaBlending(CloudCastlePal,CloudCastleTiles,/* cloudMap,castleMap */CloudCastleMap);
	
	return;
}

// 中断向量表
typedef void (*IntrFuncp)(void);
void IntrDammy(void);
void VBlankIntr(void);
const IntrFuncp OPIntrTable[15] = {
	VBlankIntr,	IntrDammy,
	IntrDammy,	IntrDammy,
	IntrDammy,	IntrDammy,
	IntrDammy,	IntrDammy,
	IntrDammy,	IntrDammy,
	IntrDammy,	IntrDammy,
	IntrDammy,	IntrDammy,
	IntrDammy,
};

//------------------------------------------------------------------//
//			V Counter Interrupt Processing              //
//------------------------------------------------------------------//

void VBlankIntr(void)
{
	*(vu16 *)RegIF = VBlankIntrFlag;
	*(vu32 *)IFBIOS |= VBlankIntrFlag;
}

void IntrDammy(void)
{

}
