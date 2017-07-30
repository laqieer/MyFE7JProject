#include "BG.h"

void DrawCharacter(const unsigned int *CharacterTiles,const unsigned short *CharacterMap,const unsigned short *CharacterPal/* ,int CharacterTilesLength,int CharacterMapLength,int CharacterPalLength */,const unsigned short *CharacterNamePal,const unsigned int *CharacterNameTiles)
{
	u16 namex = 240;
	u16 namey = 16;
	u16 y = 255-160; //当前屏幕左上角纵坐标
	int wt = 84; //画面定格帧数
//	图片、调色板、TSA全部采用LZ77压缩，节约rom空间（压缩调色板其实不节约……），减少了参数传递（数组（地址）在传参过程中会退化成指针，sizeof无法取整个数组的字节数，所以需要额外的数组长度参数）
//	CPUFastSet(CharacterPal,BGPaletteRAM,CharacterPalLength>>2);
	LZ77UnCompVram(CharacterPal,BGPaletteRAM);
//	*(vu16 *)BGPaletteRAM = 0x7FFF;//设置背景色
	LZ77UnCompVram(CharacterTiles,VRAM);
//	LZ77UnCompVram(CharacterTiles,VRAM+0x4000);
	LZ77UnCompVram(CharacterMap,VRAM+0x8000);
//	LZ77UnCompVram(CharacterMap,VRAM+0x8000+0x800);
//	CPUFastSet(CharacterTiles,VRAM,CharacterTilesLength>>2);
//	CPUFastSet(CharacterMap,VRAM+0x8000,CharacterMapLength>>2);
	LZ77UnCompVram(CharacterNamePal,CharacterNameTilePalette);
	LZ77UnCompVram(CharacterNameTiles,CharacterNameVramBase);
	*(vu16 *)CharacterNameOAMBase = namey|(1<<14);
	*(vu16 *)(CharacterNameOAMBase+4) = 1;
	*(vu16 *)REG_DISPCNT = BGMODE(0)|EnableDisplayBG(0)|EnableDisplayBG(1)|(1<<12)|(1<<6);
	*(vu16 *)BGCNT(0) = BGPriority(0)|CharacterBaseBlock(0)|BG256Colors|ScreenBaseBlock(32/2)|BGScreenSize(0);
//	*(vu16 *)BGCNT(1) = BGPriority(1)|CharacterBaseBlock(1)|BG256Colors|ScreenBaseBlock(32/2+1)|BGScreenSize(0);
	*(vu16 *)BGCNT(1) = BGPriority(1)|CharacterBaseBlock(0)|BG256Colors|ScreenBaseBlock(32/2)|BGScreenSize(0);
	*(vu16 *)BLDCNT = (1<<1)|(3<<6);
	*(vu16 *)BLDY = 16;
	*(vu16 *)BGHOFS(0) = 0;
	*(vu16 *)BGHOFS(1) = 16;
	while(1)
	{
		*(vu16 *)BGVOFS(0) = y;
		*(vu16 *)BGVOFS(1) = y;
		if(namex>120)//调整人物名字的最终位置
			*(vu16 *)(CharacterNameOAMBase+2) = (namex--)|(2<<14);
		VBlankIntrWait();
		if(y)
			y--;
		else
			wt--;
		if(0==wt)
			return;
	}
}

void Draw2Characters(const unsigned int *CharacterTiles,const unsigned short *CharacterMap,const unsigned short *CharacterPal,int leftWidth)
{
	int n=1;
	u32 clear=0;
	int k=16;
	CPUFastSet(&clear,VRAM+0x8000,(2*0x800>>2)|(1<<24));
	LZ77UnCompVram(CharacterPal,BGPaletteRAM);
	LZ77UnCompVram(CharacterTiles,VRAM);
	for(int i=0;i<256/8;i++)
	{
		int j=0;//一行里的Tilej
		for(;j<leftWidth;j++)
			*(vu16 *)(VRAM+0x8000+0x40*i+2*j) = CharacterMap[0x20*i+j];
		for(;j<256/8;j++)
			*(vu16 *)(VRAM+0x8000+0x800+0x40*i+2*j) = CharacterMap[0x20*i+j];
	}
	*(vu16 *)REG_DISPCNT = BGMODE(0)|EnableDisplayBG(0);
//	*(vu16 *)REG_DISPCNT = BGMODE(0)|EnableDisplayBG(0)|EnableDisplayBG(1);
	*(vu16 *)BGCNT(0) = BGPriority(0)|CharacterBaseBlock(0)|BG256Colors|ScreenBaseBlock(0x8000/0x800)|BGScreenSize(0);
	*(vu16 *)BGCNT(1) = BGPriority(1)|CharacterBaseBlock(0)|BG256Colors|ScreenBaseBlock(0x8000/0x800+1)|BGScreenSize(0);
	*(vu16 *)BGHOFS(0) = 0;
	*(vu16 *)BGVOFS(0) = 0;
	*(vu16 *)BGHOFS(1) = 0;
	*(vu16 *)BGVOFS(1) = 0;
	*(vu16 *)BLDCNT = 1|(2<<6);
	while(k>=0)
	{
		*(vu16 *)BLDY = k;
		n=4;
		Wait(n);
		k--;
	}
	*(vu16 *)REG_DISPCNT|=EnableDisplayBG(1);
	*(vu16 *)BLDCNT = (1<<1)|(2<<6);
	k = 16;
	while(k>=0)
	{
		*(vu16 *)BLDY=k;
		n=4;
		Wait(n);
		k--;
	}
	k = 0;
	while(k<=16)
	{
		*(vu16 *)BLDY=k;
		n=4;
		Wait(n);
		k++;
	}
	k = 0;
	*(vu16 *)REG_DISPCNT&=~EnableDisplayBG(1);
	*(vu16 *)BLDCNT = 1|(2<<6);
	while(k<=16)
	{
		*(vu16 *)BLDY=k;
		n=4;
		Wait(n);
		k++;
	}
	*(vu16 *)REG_DISPCNT&=~EnableDisplayBG(0);
	*(vu16 *)BLDCNT = 0;
	*(vu16 *)BLDY = 0;
	return;
}

void ShowCGWithMosaic(const unsigned int *CGBitmap)
{
	int n=1;
	int mosaicSize = 5;
	LZ77UnCompVram(CGBitmap,VRAM);
	*(vu16 *)REG_DISPCNT = BGMODE(3)|EnableDisplayBG(2);
	*(vu16 *)BGCNT(2)=1<<6;
	while(mosaicSize>=0)
	{
		*(vu16 *)RegMOSAIC = mosaicSize|(mosaicSize<<4);
		n=10;
		Wait(n);
		mosaicSize--;
	}
	n=60;
	Wait(n);
	mosaicSize = 0;
	while(mosaicSize<=5)
	{
		*(vu16 *)RegMOSAIC = mosaicSize|(mosaicSize<<4);
		n=10;
		Wait(n);
		mosaicSize++;
	}
	return;	
}

void ScrollCGHorizontally(const unsigned int *Tiles,const unsigned short *Map,const unsigned short *Pal)
{
	int n=60;
	LZ77UnCompVram(Pal,BGPaletteRAM);
//	*(vu16 *)BGPaletteRAM = 0x7FFF;
	LZ77UnCompVram(Tiles,VRAM);
	LZ77UnCompVram(Map,VRAM+0x10000-0x1000);
	*(vu16 *)REG_DISPCNT = BGMODE(0)|EnableDisplayBG(0);
	*(vu16 *)BGCNT(0) = BGPriority(0)|CharacterBaseBlock(0)|BG256Colors|ScreenBaseBlock((0x10000-0x1000)/0x800)|BGScreenSize(1);
	*(vu16 *)BGVOFS(0) = 256-160-8*4;
	for(int x=512-240;x>=0;x--)
	{
		*(vu16 *)BGHOFS(0) = x;
		VBlankIntrWait();
	}
	Wait(n);
	return;
}

void CircleMask(const unsigned int *CGBitmap,const unsigned int *MaskOBJTiles,const unsigned short *MaskOBJPal)
{
	int x = 240-8*11;//蒙版OBJ左上角横坐标
	int y = 0;//蒙版OBJ左上角纵坐标
	LZ77UnCompVram(MaskOBJPal,OBJPaletteRAM);
	LZ77UnCompVram(CGBitmap,VRAM);
	LZ77UnCompVram(MaskOBJTiles,OBJVramBase+0x4000+0x20);
	*(vu16 *)WINOUT = (1<<10)|(1<<12);
	*(vu16 *)REG_DISPCNT = BGMODE(3)|EnableDisplayBG(2)|(1<<12)|(1<<15)|(1<<6);
	*(vu16 *)BGCNT(2) = 0;
	*(vu16 *)(OAMBase+4) = 1+0x4000/0x20;
	*(vu16 *)(OAMBase+2) = x|(3<<14);
	while(y<=160-64)
	{
		*(vu16 *)OAMBase = (2<<10)|y;
		y++;
		VBlankIntrWait();
	}
	int n = 60;
	Wait(n);
	return;
}

void RectangleMask(const unsigned int *CGBitmap)
{
	int x = 8*0;//矩形左上角横坐标
	int y = 8*0;//矩形左上角纵坐标
	int dx = 96;//矩形宽
	int dy = 32;//矩形高
	*(vu16 *)BGPaletteRAM = 0;
	LZ77UnCompVram(CGBitmap,VRAM);
	*(vu16 *)WININ = 1<<2;
	*(vu16 *)REG_DISPCNT = BGMODE(3)|EnableDisplayBG(2)|(1<<13);
	*(vu16 *)BGCNT(2) = 0;
	while((y<=160-dy)&&(x<=240-dx))
	{
		x++;
		y++;
		*(vu16 *)WIN0H = (x<<8)|(x+dx);
		*(vu16 *)WIN0V = (y<<8)|(y+dy);
		VBlankIntrWait();
	}
	int n = 60;
	Wait(n);
	return;
}

void AlphaBlending(const unsigned short *Pal,const unsigned int *Tiles,const unsigned short *Map/* 1,const unsigned short *Map2 */)
{
	int i = 0;//循环计数变量
	int n = 1;
	int x = 0;//BG0的横坐标
	int alpha = 4;//混合系数
	LZ77UnCompVram(Pal,BGPaletteRAM);
	LZ77UnCompVram(Tiles,VRAM);
	LZ77UnCompVram(Map,VRAM+0xD000);
//	LZ77UnCompVram(Map2,VRAM+0xD800);
	*(vu16 *)REG_DISPCNT = BGMODE(0)|EnableDisplayBG(0)|EnableDisplayBG(1);
	*(vu16 *)BGVOFS(1) = 0;
	*(vu16 *)BGHOFS(1) = 0;
	*(vu16 *)BGVOFS(0) = 0;
	*(vu16 *)BGCNT(0) = BGPriority(0)|CharacterBaseBlock(0)|BG256Colors|ScreenBaseBlock(0xD000/0x800)|BGScreenSize(0);
	*(vu16 *)BGCNT(1) = BGPriority(1)|CharacterBaseBlock(0)|BG256Colors|ScreenBaseBlock(0xD800/0x800)|BGScreenSize(0);
	*(vu16 *)BLDCNT = 1|(1<<6)|(1<<9);
	while(alpha<=12)
	{
		*(vu16 *)BLDALPHA = alpha|((16-alpha)<<8);
		alpha++;
		for(i=0;i<5;i++)
		{
			*(vu16 *)BGHOFS(0) = x++;
			n = 2;
			Wait(n);
		}
	}
	while(alpha>=4)
	{
		*(vu16 *)BLDALPHA = alpha|((16-alpha)<<8);
		alpha--;
		for(i=0;i<5;i++)
		{
			*(vu16 *)BGHOFS(0) = x++;
			n = 2;
			Wait(n);
		}
	}
	*(vu16 *)BLDCNT = 0;
	*(vu16 *)BGVOFS(1) = 0;
	*(vu16 *)BLDALPHA = 0;
	return;
}