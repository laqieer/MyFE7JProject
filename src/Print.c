#include "Print.h"

//单字符
void printc(int x,int y,char c)
{
	struct UnPackInfo{
		u16 SrcDataLen;
		u8 SrcUnitBitWidth;
		u8 DstUnitBitWidth;
		u32 DataOffset;
	}unpackinfo;
	unpackinfo.SrcDataLen = 8;
	unpackinfo.SrcUnitBitWidth = 1;
	unpackinfo.DstUnitBitWidth = 4;
	unpackinfo.DataOffset = 0;
	*(vu16 *)REG_DISPCNT |= EnableDisplayOBJ;
	*(vu16 *)REG_DISPCNT &= ~(1<<7); //解除强制黑屏
	*(vu16 *)(CharacterPaletteRAM+2) = 0x1f|(0x1f<<5)|(0x1f<<10);//白色字体
/* 	_asm 
{
	ldr r0,=(ASCII8x8font_bin+c)
	ldr r1,=CharacterTileVramBase
	ldr r2,=unpackinfo
	swi 0x10
} */
	asm vl("mov r0,%0;mov r1,%1;mov r2,%2;swi 0x10"::"r"(ASCII8x8font_bin+8*c),"r"(CharacterTileVramBase),"r"(&unpackinfo):"r0","r1","r2","r3","memory");
 	*(vu16 *)CharacterOAMBase = y&255;
	*(vu16 *)(CharacterOAMBase+2) = (x&511)|(1<<12);
	*(vu16 *)(CharacterOAMBase+4) = 512;
	return;
}
//字符串 very ugly
void prints(int x,int y,char s[],int offset)
{
	vl int len = 0;
	while(s[len]!=0) len++;
/* 	do
		len++;
	while(s[len]!=0); */
	struct UnPackInfo{
		u16 SrcDataLen;
		u8 SrcUnitBitWidth;
		u8 DstUnitBitWidth;
		u32 DataOffset;
	}unpackinfo;
	unpackinfo.SrcDataLen = 8;
	unpackinfo.SrcUnitBitWidth = 1;
	unpackinfo.DstUnitBitWidth = 4;
	unpackinfo.DataOffset = 0;
	*(vu16 *)REG_DISPCNT |= EnableDisplayOBJ;
	*(vu16 *)REG_DISPCNT &= ~(1<<7); //解除强制黑屏
	*(vu16 *)(CharacterPaletteRAM+2) = 0x1f|(0x1f<<5)|(0x1f<<10);//白色字体
	int k=0;//不重复的字模序号
	int i;
	int j;
	for(i=0;i<len;i++)
	{
		for(j=0;j<i;j++)
		{
			if(s[i]==s[j])
				break;	
		}
		if(j==i)
		{
			asm vl("mov r0,%0;mov r1,%1;mov r2,%2;swi 0x10"::"r"(ASCII8x8font_bin+8*s[i]),"r"(CharacterTileVramBase+32*(k+offset)),"r"(&unpackinfo):"r0","r1","r2","r3","memory");
			*(vu16 *)(CharacterOAMBase+8*(i+offset)+4) = (k+512+offset)|(8<<12);
			k++;
		}
		*(vu16 *)(CharacterOAMBase+8*(i+offset)+2) = ((x+8*i)&511)|(1<<12);
		*(vu16 *)(CharacterOAMBase+8*(i+offset)) = y&255;
		*(vu16 *)(CharacterOAMBase+8*(i+offset)+4) = *(vu16 *)(CharacterOAMBase+8*(j+offset)+4);
	}
	return;
}
//清屏
void clearp()
{
	u32 clear = 0;
	CPUFastSet(&clear,CharacterTileVramBase,(0x4000>>2)|(1<<24));
	CPUFastSet(&clear,CharacterOAMBase,(0x200>>2)|(1<<24));
}
