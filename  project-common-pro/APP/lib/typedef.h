/*--------------------------------------------------------------------------*/
/**@file     typedef.h
   @brief    参数配置
   @author
   @date   2010-12-13
   @note   AC209N
*/
/*----------------------------------------------------------------------------*/

#ifndef _typedef_h_
#define _typedef_h_


#ifdef __C51__
#include "string.h"

typedef unsigned char	u8, uint8;
typedef char			s8, int8;

#ifdef WIN32
typedef unsigned short	u16, uint16;
typedef signed short	s16, int16;
typedef unsigned int	u32, uint32;
typedef signed int		s32, int32,func;
typedef unsigned long	u64, uint64;
typedef signed long		s64, int64;
#endif

#ifdef __KEIL__
typedef unsigned int	u16, uint16;
typedef signed int		s16, int16, func;
typedef unsigned long	u32, uint32;
typedef signed long		s32, int32;
#endif

typedef xdata unsigned char 	xd_u8, xd_uint8;
typedef xdata unsigned int		xd_u16, xd_uint16;
typedef xdata signed long		xd_u32, xd_uint32;

#define FALSE	0
#define TRUE    1

#define false	0
#define true    1

#ifdef WIN32
#define	LD_WORD(ptr)		(u16)(*(u16*)(u8*)(ptr))
#define	LD_DWORD(ptr)		(u32)(*(u32*)(u8*)(ptr))
#define	ST_WORD(ptr,val)	*(u16*)(u8*)(ptr)=(u16)(val)
#define	ST_DWORD(ptr,val)	*(u32*)(u8*)(ptr)=(u32)(val)
#endif

#ifdef __KEIL__
#define  	LD_WORD(ptr)	int2(ptr)
#define  	LD_DWORD(ptr)	int4(ptr)
//#define	LD_WORD(ptr)		(u16)(((u16)*(u8*)((ptr)+1)<<8)|(u16)*(u8*)(ptr))
//#define	LD_DWORD(ptr)		(u32)(((u32)*(u8*)((ptr)+3)<<24)|((u32)*(u8*)((ptr)+2)<<16)|((u16)*(u8*)((ptr)+1)<<8)|*(u8*)(ptr))
//#define	ST_WORD(ptr,val)	*(volatile u8*)(ptr)=(u8)(val); *(volatile u8*)((ptr)+1)=(u8)((u16)(val)>>8)
//#define	ST_DWORD(ptr,val)	*(volatile u8*)(ptr)=(u8)(val); *(volatile u8*)((ptr)+1)=(u8)((u16)(val)>>8); *(volatile u8*)((ptr)+2)=(u8)((u32)(val)>>16); *(volatile u8*)((ptr)+3)=(u8)((u32)(val)>>24)
#endif

#ifdef __KEIL__					//使用KEIL环境编译
#define bool		bit
#define _xdata		xdata
#define _data		data
#define _idata		idata
#define _pdata		pdata
#define _bdata		bdata
#define _bit		bit
#define _sbit		sbit
#define _code		code
#define _small		small
#define _large      large
#define pu16		u16
#define pu32		u32
#define ubit        bit


extern void my_memset(u8 _xdata *s1, u8 volume, u16 len);
extern void my_memcpy(u8 _xdata *s1, u8 _xdata *s2, u16 len);

#endif

#ifdef WIN32
#define _xdata
#define _data
#define _idata
#define _pdata
#define _bdata
#define _code
#define _bit		bool
#define _sbit		bool
#define pu16		u16
#define pu32		u32
#define memset      my_memset
#define memcpy      my_memcpy
#define memset      my_imemset
#define memcpy      my_imemcpy
#endif


#define     clrBit(x,y)         x &= ~(1L << y)
#define     setBit(x,y)         x |= (1L << y)
#endif

#define     BIT(n)	            (1 << n)
#endif
