// by laqieer on 2017/1/9
#pragma once

//数据类型定义
typedef     unsigned char           u8;
typedef     unsigned short int      u16;
typedef     unsigned int            u32;
typedef     unsigned long long int  u64;

typedef     signed char             s8;
typedef     signed short int        s16;
typedef     signed int              s32;
typedef     signed long long int    s64;

typedef     float                   f32;
typedef     double                  f64;

#define     vl                      volatile

typedef     vl u8                   vu8;
typedef     vl u16                  vu16;
typedef     vl u32                  vu32;
typedef     vl u64                  vu64;

typedef     vl s8                   vs8;
typedef     vl s16                  vs16;
typedef     vl s32                  vs32;
typedef     vl s64                  vs64;

typedef     vl f32                  vf32;
typedef     vl f64                  vf64;

//取数组长度
#define Length_of(array) (sizeof(array)/sizeof(array[0]))

//定义函数指针类型
typedef int (*PTRFUN)();
//定义函数指针调用宏
#define sub16(Addr) (*(PTRFUN)(0x##Addr+1))
#define sub32(Addr) (*(PTRFUN)(0x##Addr))

//BIOS函数
#define ArcTan2 sub16(80C0548)
#define BgAffineSet sub16(80C054C)
#define CPUFastSet sub16(80C0550)
#define CPUSet sub16(80C0554)
#define Div sub16(80C0558)
#define Mod sub16(80C055C)
#define HuffUnComp sub16(80C0564)
#define LZ77UnCompVram sub16(80C0568)
#define LZ77UnCompWram sub16(80C056C)
#define MultiBoot sub16(80C0570)
#define ObjAffineSet sub16(80C0578)
#define RLUnCompVram sub16(80C057C)
#define RLUnCompWram sub16(80C0580)
#define SoundBiasReset sub16(80C059C)
#define SoundBiasSet sub16(80C05A4)
#define Sqrt sub16(80C05AC)
#define VBlankIntrWait sub16(80C05B0)

struct funcUnit{
	int index;
	PTRFUN func;
};

// #define Sin(alpha) (*(_WORD *)(0x80C0E98+2*(alpha)))
#define Sin(alpha) *((_WORD *)0x80C0E98+(alpha))