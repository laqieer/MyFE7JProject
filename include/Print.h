// by Laqieer 2017/1/11
// ��ӡ��Ϣ��GBA��Ļ����(һ�β�����64���ַ�)
#pragma once

#include "FE7J.h"
#include "ASCII8x8font_bin.h"

//��ģ��ȡ
//http://book.51cto.com/art/201403/431914.htm
//http://book.51cto.com/art/201403/431915.htm

//�������
#define REG_DISPCNT					0x4000000
#define EnableDisplayOBJ			(1<<12)
#define OBJCharacterVramMapping(n)	(((1==n)?1:0)<<6)
#define CharacterTileVramBase		0x06014000
#define	CharacterPaletteRAM			0x5000300
#define CharacterOAMBase			0x7000200

//���ַ�
void printc(int x,int y,char c);
//�ַ���
void prints(int x,int y,char* s,int offset);
//����
void clearp();
