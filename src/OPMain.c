// by laqieer 2017/1/9

#include "BG.h"
#include "Print.h"

//ͼƬ
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

//VBlank�ж����
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

// ƬͷOP����������
//__attribute__((section(".OPMain")))
void OPMain()
{
	ffplayVideo("FESoVOP.mkv");
}

void OPMainOld()
{
	int n = 1;
	//���ж�
	*(vu32 *)RegIME = 1;
	*(vu16 *)RegIE |= VBlankIntrFlag;
	*(vu16 *)DISPSTAT |= VBlankIRQEnable;
	
	//��ӡ������汾��Ϣ
	prints(240-8*11,160-8*3,__DATE__,0);
	prints(240-8*11,160-8*2,__TIME__,11);
	prints(240-8*5,160-8*2,"(UTC)",16);
	prints(240-8*7,160-8,"laqieer",23);
	n = 120;
	Wait(n);
	clearp();
		
	//������ʾ��������
/* 	int LynTilesLength = LynTilesLen;
	int LynMapLength = LynMapLen;
	int LynPalLength = LynPalLen; */
	DrawCharacter(LynTiles,LynMap,LynPal/* ,LynTilesLength,LynMapLength,LynPalLength */,LynNamePal,LynNameTiles);
	
	//�������Ϳ��׶��ĺ�Ӱ
	Draw2Characters(KarlaKarelTiles,KarlaKarelMap,KarlaKarelPal,18);
	
	//·��˹���գ������˴���
	ShowCGWithMosaic(SexyLuiseBitmap);
	
	//��������������ܽ��������Ƭ
	ScrollCGHorizontally(HotFlorinaTiles,HotFlorinaMap,HotFlorinaPal);
	
	//�𱴿�������ϣ����Ӱ�������ɰ�Ч��
	RectangleMask(RebaccaPrescillaBitmap);
	
	//�𱴿�������ϣ����Ӱ��Բ���ɰ�Ч��
	//CircleMask(RebaccaPrescillaBitmap,Circle32x32Tiles,Circle32x32Pal);
	CircleMask(RebaccaPrescillaBitmap,Circle64x64Tiles,Circle64x64Pal);
	
	//�Ʋ�ͳǱ����������Ч��
	AlphaBlending(CloudCastlePal,CloudCastleTiles,/* cloudMap,castleMap */CloudCastleMap);
	
	return;
}

// �ж�������
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
