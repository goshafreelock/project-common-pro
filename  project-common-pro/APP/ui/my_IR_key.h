/*--------------------------------------------------------------------------*/
/**@file   my_IR_key.h
   @brief  按键消息扫描头文件
   @details
   @author
   @date   2010-12-13
   @note
*/
/*----------------------------------------------------------------------------*/
#ifndef	_MY_IR_KEY_H_
#define _MY_IR_KEY_H_
#include "Custom_config.h"

/* FILL BELOW TO ASSIGN CODE TABLE*/
#if defined(IR_USER_CODE_0x7F80)

#if defined(K015_983_1_SW005_V001)
#define  My_IR_KEY_0			0x07
#define  My_IR_KEY_1			0x0A
#define  My_IR_KEY_2			0x1B
#define  My_IR_KEY_3			0x1F
#define  My_IR_KEY_4			0x0C
#define  My_IR_KEY_5			0x0D
#define  My_IR_KEY_6			0x0E
#define  My_IR_KEY_7			0x00
#define  My_IR_KEY_8			0x0F
#define  My_IR_KEY_9			0x19
#define  My_IR_KEY_100			0xFF

#define  My_IR_KEY_MODE		0x1A
#define  My_IR_KEY_PLAY			0x01
#define  My_IR_KEY_PLAY_M		0x08
#define  My_IR_KEY_VOL_UP		0x06
#define  My_IR_KEY_VOL_DN		0x05	
#define  My_IR_KEY_PREV			0x02
#define  My_IR_KEY_NEXT			0x03
#define  My_IR_KEY_EQ_UP		0x04
#define  My_IR_KEY_EQ_DN		0x09
#define  My_IR_KEY_CHN_UP		0x1E
#define  My_IR_KEY_CHN_DN		0x12
#else
#define  My_IR_KEY_0			0x07
#define  My_IR_KEY_1			0x0A
#define  My_IR_KEY_2			0x1B
#define  My_IR_KEY_3			0x1F
#define  My_IR_KEY_4			0x0C
#define  My_IR_KEY_5			0x0D
#define  My_IR_KEY_6			0x0E
#define  My_IR_KEY_7			0x00
#define  My_IR_KEY_8			0x0F
#define  My_IR_KEY_9			0x19
#define  My_IR_KEY_100			0xFF

#define  My_IR_KEY_MODE		0x1A
#define  My_IR_KEY_PLAY			0x01
#define  My_IR_KEY_PLAY_M		0x08
#define  My_IR_KEY_VOL_UP		0x06
#define  My_IR_KEY_VOL_DN		0x05	
#define  My_IR_KEY_PREV			0x02
#define  My_IR_KEY_NEXT			0x03
#define  My_IR_KEY_EQ_UP		0x04
#define  My_IR_KEY_EQ_DN		0x09
#define  My_IR_KEY_CHN_UP		0x1E
#define  My_IR_KEY_CHN_DN		0x12
#endif

#elif defined(IR_USER_CODE_0xFE01)
#define  My_IR_KEY_0			0x09
#define  My_IR_KEY_1			0x01
#define  My_IR_KEY_2			0x44
#define  My_IR_KEY_3			0x48
#define  My_IR_KEY_4			0x45
#define  My_IR_KEY_5			0x49
#define  My_IR_KEY_6			0xff
#define  My_IR_KEY_7			0xff
#define  My_IR_KEY_8			0xff
#define  My_IR_KEY_9			0xff
#define  My_IR_KEY_100			0xff

#define  My_IR_KEY_MODE		0x04
#define  My_IR_KEY_PLAY			0x03
#define  My_IR_KEY_PLAY_M		0x44
#define  My_IR_KEY_VOL_UP		0x05
#define  My_IR_KEY_VOL_DN		0x06	
#define  My_IR_KEY_PREV			0x07
#define  My_IR_KEY_NEXT			0x0B
#define  My_IR_KEY_EQ_UP		0x40
#define  My_IR_KEY_EQ_DN		0x41
#define  My_IR_KEY_CHN_UP		0x08
#define  My_IR_KEY_CHN_DN		0x00

#elif defined(IR_USER_CODE_0xDF20)
#ifdef IR_REMOTE_TYPE_JGY
#define  My_IR_KEY_0			0x08
#define  My_IR_KEY_1			0x0c
#define  My_IR_KEY_2			0x0d
#define  My_IR_KEY_3			0x0e
#define  My_IR_KEY_4			0x10
#define  My_IR_KEY_5			0x11
#define  My_IR_KEY_6			0x12
#define  My_IR_KEY_7			0x14
#define  My_IR_KEY_8			0x15
#define  My_IR_KEY_9			0x16
#define  My_IR_KEY_100			0xff

#define  My_IR_KEY_MODE		0xFF
#define  My_IR_KEY_PLAY			0x00
#define  My_IR_KEY_PLAY_M		0x18
#define  My_IR_KEY_VOL_UP		0x06
#define  My_IR_KEY_VOL_DN		0x05	
#define  My_IR_KEY_PREV			0x09
#define  My_IR_KEY_NEXT			0x0a
#define  My_IR_KEY_EQ_UP		0x04
#define  My_IR_KEY_EQ_DN		0x1a
#define  My_IR_KEY_CHN_UP		0x02
#define  My_IR_KEY_CHN_DN		0x04
#else
#define  My_IR_KEY_0			0x03
#define  My_IR_KEY_1			0x00
#define  My_IR_KEY_2			0x01
#define  My_IR_KEY_3			0x0f
#define  My_IR_KEY_4			0xff
#define  My_IR_KEY_5			0xff
#define  My_IR_KEY_6			0xff
#define  My_IR_KEY_7			0xff
#define  My_IR_KEY_8			0xff
#define  My_IR_KEY_9			0xff
#define  My_IR_KEY_100			0xff

#define  My_IR_KEY_MODE		0x0d
#define  My_IR_KEY_PLAY			0x15
#define  My_IR_KEY_PLAY_M		0x1b
#define  My_IR_KEY_VOL_UP		0x0E
#define  My_IR_KEY_VOL_DN		0x1A	
#define  My_IR_KEY_PREV			0x11
#define  My_IR_KEY_NEXT			0x17
#define  My_IR_KEY_EQ_UP		0x19
#define  My_IR_KEY_EQ_DN		0x12
#define  My_IR_KEY_CHN_UP		0x1F
#define  My_IR_KEY_CHN_DN		0x09
#endif
#elif defined(IR_USER_CODE_0xBF00)
#define  My_IR_KEY_0			0x10
#define  My_IR_KEY_1			0x04
#define  My_IR_KEY_2			0x05
#define  My_IR_KEY_3			0x06
#define  My_IR_KEY_4			0x08
#define  My_IR_KEY_5			0x09
#define  My_IR_KEY_6			0x0A
#define  My_IR_KEY_7			0x0C
#define  My_IR_KEY_8			0x0D
#define  My_IR_KEY_9			0x0E
#define  My_IR_KEY_100			0x11

#define  My_IR_KEY_MODE		0x02
#define  My_IR_KEY_PLAY			0x01
#define  My_IR_KEY_PLAY_M		0x08
#define  My_IR_KEY_VOL_UP		0x12
#define  My_IR_KEY_VOL_DN		0x16	
#define  My_IR_KEY_PREV			0x14
#define  My_IR_KEY_NEXT			0x15
#define  My_IR_KEY_EQ_UP		0x1a
#define  My_IR_KEY_EQ_DN		0x18
#define  My_IR_KEY_CHN_UP		0x19
#define  My_IR_KEY_CHN_DN		0x00
#elif defined(IR_USER_CODE_0x00FF)
#define  My_IR_KEY_0			0x0A
#define  My_IR_KEY_1			0x08
#define  My_IR_KEY_2			0x12
#define  My_IR_KEY_3			0x1E
#define  My_IR_KEY_4			0x13
#define  My_IR_KEY_5			0x1C
#define  My_IR_KEY_6			0x1D
#define  My_IR_KEY_7			0x01
#define  My_IR_KEY_8			0x02
#define  My_IR_KEY_9			0x05
#define  My_IR_KEY_100			0xff

#define  My_IR_KEY_MODE		0x04
#define  My_IR_KEY_PLAY			0x14
#define  My_IR_KEY_PLAY_M		0x17
#define  My_IR_KEY_VOL_UP		0x5B
#define  My_IR_KEY_VOL_DN		0x1B	
#define  My_IR_KEY_PREV			0x18
#define  My_IR_KEY_NEXT			0x44
#define  My_IR_KEY_EQ_UP		0x16
#define  My_IR_KEY_EQ_DN		0x46
#define  My_IR_KEY_CHN_UP		0x15
#define  My_IR_KEY_CHN_DN		0x06
#elif defined(XC_MINI_IR_REMOTE)
#define  My_IR_KEY_0			0x09
#define  My_IR_KEY_1			0x0C
#define  My_IR_KEY_2			0xFF
#define  My_IR_KEY_3			0xFF
#define  My_IR_KEY_4			0xFF
#define  My_IR_KEY_5			0xFF
#define  My_IR_KEY_6			0xFF
#define  My_IR_KEY_7			0xFF
#define  My_IR_KEY_8			0xFF
#define  My_IR_KEY_9			0xFF
#define  My_IR_KEY_100			0xFF

#define  My_IR_KEY_MODE		0x0d
#define  My_IR_KEY_PLAY			0x16
#define  My_IR_KEY_PLAY_M		0x0e
#define  My_IR_KEY_VOL_UP		0x14
#define  My_IR_KEY_VOL_DN		0x08	
#define  My_IR_KEY_PREV			0x0a
#define  My_IR_KEY_NEXT			0x15
#define  My_IR_KEY_EQ_UP		0x06
#define  My_IR_KEY_EQ_DN		0xFF
#define  My_IR_KEY_CHN_UP		0x01
#define  My_IR_KEY_CHN_DN		0x00
#else
#define  My_IR_KEY_0			0x16
#define  My_IR_KEY_1			0x0C
#define  My_IR_KEY_2			0x18
#define  My_IR_KEY_3			0x5E
#define  My_IR_KEY_4			0x08
#define  My_IR_KEY_5			0x1C
#define  My_IR_KEY_6			0x5A
#define  My_IR_KEY_7			0x42
#define  My_IR_KEY_8			0x52
#define  My_IR_KEY_9			0x4A
#define  My_IR_KEY_100			0x19

#define  My_IR_KEY_MODE		0x46
#define  My_IR_KEY_PLAY			0x43
#define  My_IR_KEY_PLAY_M		0x0D
#define  My_IR_KEY_VOL_UP		0x15
#define  My_IR_KEY_VOL_DN		0x07	
#define  My_IR_KEY_PREV			0x44
#define  My_IR_KEY_NEXT			0x40
#define  My_IR_KEY_EQ_UP		0x09
#define  My_IR_KEY_EQ_DN		0xFF
#define  My_IR_KEY_CHN_UP		0x47
#define  My_IR_KEY_CHN_DN		0x45
#endif
#define My_IR_KEY_RETURN		0xFF
#define My_IR_KEY_NONE 			0xFF
#define My_IR_KEY_CUSTOM_1	0x00
#define My_IR_KEY_CUSTOM_2	0x00

#if defined(K0000_GW_300G_V001)
#undef My_IR_KEY_CUSTOM_1		
#define My_IR_KEY_CUSTOM_1	0x50
#endif
#define My_IR_KEY_TATOL		23

#if defined(IR_USER_CODE_0x7F80)
#define USER_CODE	0x7F80
#elif defined(IR_USER_CODE_0xBF00)
#define USER_CODE	0xBF00
#elif defined(IR_USER_CODE_0xDF20)
#define USER_CODE	0xDF20
#elif defined(IR_USER_CODE_0x00FF)
#define USER_CODE	0x00FF
#elif defined(IR_USER_CODE_0xFE01)
#define USER_CODE	0xFE01
#else
#define USER_CODE	0xFF00
#endif


#if defined(USE_TWO_IR_REMOTE)

#if defined(K302_ZhengYang_ZY302_V001)

#define  My_IR2_KEY_0			0xff
#define  My_IR2_KEY_1			0x11
#define  My_IR2_KEY_2			0x13
#define  My_IR2_KEY_3			0x16
#define  My_IR2_KEY_4			0x12
#define  My_IR2_KEY_5			0xFF
#define  My_IR2_KEY_6			0xFF
#define  My_IR2_KEY_7			0xFF
#define  My_IR2_KEY_8			0xFF
#define  My_IR2_KEY_9			0xFF
#define  My_IR2_KEY_100			0xFF

#define  My_IR2_KEY_MODE		0xFF
#define  My_IR2_KEY_PLAY		0x05
#define  My_IR2_KEY_PLAY_M		0x14
#define  My_IR2_KEY_VOL_UP		0x1b
#define  My_IR2_KEY_VOL_DN		0x1a	
#define  My_IR2_KEY_PREV		0x04
#define  My_IR2_KEY_NEXT		0x06
#define  My_IR2_KEY_EQ_UP		0x15
#define  My_IR2_KEY_EQ_DN		0x09
#define  My_IR2_KEY_CHN_UP		0x18
#define  My_IR2_KEY_CHN_DN		0x17

#define USER_CODE_2		0x7F80
#elif defined(K000_JR_210_V001)
#define  My_IR2_KEY_0			0x12
#define  My_IR2_KEY_1			0x13
#define  My_IR2_KEY_2			0x08
#define  My_IR2_KEY_3			0x0a
#define  My_IR2_KEY_4			0x0b
#define  My_IR2_KEY_5			0x09
#define  My_IR2_KEY_6			0x00
#define  My_IR2_KEY_7			0x01
#define  My_IR2_KEY_8			0x02
#define  My_IR2_KEY_9			0x03
#define  My_IR2_KEY_10			0x1D
#define  My_IR2_KEY_11			0x48
#define  My_IR2_KEY_12			0x4C
#define  My_IR2_KEY_13			0x4D
#define  My_IR2_KEY_100			0x1D

#define  My_IR2_KEY_MODE		0x0C
#define  My_IR2_KEY_PLAY		0x16
#define  My_IR2_KEY_PLAY_M		0xFF
#define  My_IR2_KEY_VOL_UP		0x10
#define  My_IR2_KEY_VOL_DN		0x11	
#define  My_IR2_KEY_PREV		0x49
#define  My_IR2_KEY_NEXT		0x1C
#define  My_IR2_KEY_EQ_UP		0xff
#define  My_IR2_KEY_EQ_DN		0x14
#define  My_IR2_KEY_CHN_UP		0x0E
#define  My_IR2_KEY_CHN_DN		0x0d

#define USER_CODE_2		0xEB10
#else
#define  My_IR2_KEY_0			0x07
#define  My_IR2_KEY_1			0x0A
#define  My_IR2_KEY_2			0x1B
#define  My_IR2_KEY_3			0x1F
#define  My_IR2_KEY_4			0x0C
#define  My_IR2_KEY_5			0x0D
#define  My_IR2_KEY_6			0x0E
#define  My_IR2_KEY_7			0x00
#define  My_IR2_KEY_8			0x0F
#define  My_IR2_KEY_9			0x19
#define  My_IR2_KEY_100			0xFF

#define  My_IR2_KEY_MODE		0x1A
#define  My_IR2_KEY_PLAY		0x01
#define  My_IR2_KEY_PLAY_M		0x08
#define  My_IR2_KEY_VOL_UP		0x06
#define  My_IR2_KEY_VOL_DN		0x05	
#define  My_IR2_KEY_PREV		0x02
#define  My_IR2_KEY_NEXT		0x03
#define  My_IR2_KEY_EQ_UP		0x04
#define  My_IR2_KEY_EQ_DN		0x09
#define  My_IR2_KEY_CHN_UP		0x1E
#define  My_IR2_KEY_CHN_DN		0x12

#define USER_CODE_2		0x7F80

#endif

#define My_IR2_KEY_NONE 		0xFF

#define My_IR2_KEY_CUSTOM_1	0x00
#define My_IR2_KEY_CUSTOM_2	0x00
#endif

typedef struct{
	u8	IR_Key_Value;
	u8	APP_Key;
}MY_IR_KEY_STRUCT;

#endif/*_MY_IR_KEY_H_*/


