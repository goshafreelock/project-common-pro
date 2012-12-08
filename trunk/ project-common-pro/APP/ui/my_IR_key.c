/*--------------------------------------------------------------------------*/
/**@file   my_IR_key.c
   @brief  红外按键码值映射表
   @details
   @author
   @date   2010-12-13
   @note
*/
/*----------------------------------------------------------------------------*/
#include "key.h"
#include "my_IR_key.h"

#ifdef _MY_IR_KEY_


#if defined(IR_REMOTER_WITH_POWER_MUTE_PRINT)
_code MY_IR_KEY_STRUCT My_IRTab[]=       /*user code is 0xFF*/
{
	//{My_IR_KEY_TATOL,		My_IR_KEY_TATOL},	//4 总共键个数
	{My_IR_KEY_NONE,		NO_KEY},
	{My_IR_KEY_0,			INFO_0},
	{My_IR_KEY_1,			INFO_1},
	{My_IR_KEY_2,			INFO_2},
	{My_IR_KEY_3,			INFO_3},
	{My_IR_KEY_4,			INFO_4},
	{My_IR_KEY_5,			INFO_5},
	{My_IR_KEY_6,			INFO_6},
	{My_IR_KEY_7,			INFO_7},
	{My_IR_KEY_8,			INFO_8},
	{My_IR_KEY_9,			INFO_9},
#ifdef KEY_100_ENABLE	
	{My_IR_KEY_100,			INFO_100},
#endif	
	
	{My_IR_KEY_MODE,		INFO_MODE},
	{My_IR_KEY_PLAY,			INFO_PLAY},
	{My_IR_KEY_PLAY_M,		INFO_PLAY_MODE},
	{My_IR_KEY_VOL_UP,		INFO_VOL_PLUS},
	{My_IR_KEY_VOL_DN,		INFO_VOL_MINUS},
	{My_IR_KEY_PREV,		INFO_PREV_FIL},
	{My_IR_KEY_NEXT,		INFO_NEXT_FIL},
	{My_IR_KEY_EQ_UP,		INFO_EQ_UP},
	{My_IR_KEY_EQ_DN,		INFO_EQ_DOWN},
	{My_IR_KEY_CHN_UP,		INFO_MUTE},
	{My_IR_KEY_CHN_DN,		INFO_POWER},
};
#elif defined(K1161_YJH_1161_V002)||defined(K2091_YJH_863_V001)||defined(K2150_HF_1234_V001)
_code MY_IR_KEY_STRUCT My_IRTab[]=       /*user code is 0xFF*/
{
	//{My_IR_KEY_TATOL,		My_IR_KEY_TATOL},	//4 总共键个数
	{My_IR_KEY_NONE,		NO_KEY},
	{My_IR_KEY_0,			INFO_VOL_MINUS},
	{My_IR_KEY_1,			INFO_1},
	{My_IR_KEY_2,			INFO_2},
	{My_IR_KEY_3,			INFO_3},
	{My_IR_KEY_4,			INFO_4},
	{My_IR_KEY_5,			INFO_5},
	{My_IR_KEY_6,			INFO_6},
	{My_IR_KEY_7,			INFO_7},
	{My_IR_KEY_8,			INFO_8},
	{My_IR_KEY_9,			INFO_9},
#if 1//def KEY_100_ENABLE	
	{My_IR_KEY_100,			INFO_VOL_PLUS},
#endif	
	
	{My_IR_KEY_MODE,		INFO_PLAY_MODE},
	{My_IR_KEY_PLAY,			INFO_EQ_UP},
	{My_IR_KEY_PLAY_M,		INFO_0},
	{My_IR_KEY_VOL_UP,		INFO_NEXT_FIL},
	{My_IR_KEY_VOL_DN,		INFO_PREV_FIL},
	{My_IR_KEY_PREV,		INFO_CH_PREV},
	{My_IR_KEY_NEXT,		INFO_CH_NEXT},
	{My_IR_KEY_EQ_UP,		INFO_PLAY },
	{My_IR_KEY_EQ_DN,		INFO_EQ_DOWN},
	{My_IR_KEY_CHN_UP,		INFO_MODE},
	{My_IR_KEY_CHN_DN,		INFO_POWER},
};
#elif defined(K568_ZX_568_V002)||defined(K015_983_SW005_ZhuoXin_V002)
_code MY_IR_KEY_STRUCT My_IRTab[]=       /*user code is 0xFF*/
{
	//{My_IR_KEY_TATOL,		My_IR_KEY_TATOL},	//4 总共键个数
	{My_IR_KEY_NONE,		NO_KEY},
	{My_IR_KEY_0,			INFO_0},
	{My_IR_KEY_1,			INFO_1},
	{My_IR_KEY_2,			INFO_2},
	{My_IR_KEY_3,			INFO_3},
	{My_IR_KEY_4,			INFO_4},
	{My_IR_KEY_5,			INFO_5},
	{My_IR_KEY_6,			INFO_6},
	{My_IR_KEY_7,			INFO_7},
	{My_IR_KEY_8,			INFO_8},
	{My_IR_KEY_9,			INFO_9},
#if 1//def KEY_100_ENABLE	
	{My_IR_KEY_100,			INFO_100},
#endif	
	
	{My_IR_KEY_MODE,		INFO_MODE},
	{My_IR_KEY_PLAY,			INFO_PLAY},
	{My_IR_KEY_PLAY_M,		INFO_MUTE},
	{My_IR_KEY_VOL_UP,		INFO_VOL_PLUS},
	{My_IR_KEY_VOL_DN,		INFO_VOL_MINUS},
	{My_IR_KEY_PREV,		INFO_PREV_FIL},
	{My_IR_KEY_NEXT,		INFO_NEXT_FIL},
	{My_IR_KEY_EQ_UP,		INFO_EQ_UP},
	{My_IR_KEY_EQ_DN,		INFO_POWER},
	{My_IR_KEY_CHN_UP,		INFO_CH_UP},
	{My_IR_KEY_CHN_DN,		INFO_CH_DOWN},
};
#elif defined(K000_ZG_HA8918_NOR_V001)||defined(K000_ZG_HA8919_BT_V001)
_code MY_IR_KEY_STRUCT My_IRTab[]=       /*user code is 0xFF*/
{
	//{My_IR_KEY_TATOL,		My_IR_KEY_TATOL},	//4 总共键个数
	{My_IR_KEY_NONE,		NO_KEY},
	{My_IR_KEY_0,			NO_KEY},
	{My_IR_KEY_1,			INFO_POWER},
	{My_IR_KEY_2,			NO_KEY},
	{My_IR_KEY_3,			NO_KEY},
	{My_IR_KEY_4,			INFO_PLAY},
	{My_IR_KEY_5,			INFO_PREV_FIL},
	{My_IR_KEY_6,			INFO_NEXT_FIL},
	{My_IR_KEY_7,			INFO_VOL_PLUS},
	{My_IR_KEY_8,			INFO_VOL_MINUS},
	{My_IR_KEY_9,			INFO_MODE},
#ifdef KEY_100_ENABLE	
	{My_IR_KEY_100,			NO_KEY},
#endif	
	
	{My_IR_KEY_MODE,		NO_KEY},
	{My_IR_KEY_PLAY,			NO_KEY},
	{My_IR_KEY_PLAY_M,		NO_KEY},
	{My_IR_KEY_VOL_UP,		NO_KEY},
	{My_IR_KEY_VOL_DN,		NO_KEY},
	{My_IR_KEY_PREV,		NO_KEY},
	{My_IR_KEY_NEXT,		NO_KEY},
	{My_IR_KEY_EQ_UP,		NO_KEY},
	{My_IR_KEY_EQ_DN,		NO_KEY},
	{My_IR_KEY_CHN_UP,		NO_KEY},
	{My_IR_KEY_CHN_DN,		NO_KEY},
};
#elif defined(K302_ZhengYang_ZY302_V001)
_code MY_IR_KEY_STRUCT My_IRTab[]=       /*user code is 0xFF*/
{
	//{My_IR_KEY_TATOL,		My_IR_KEY_TATOL},	//4 总共键个数
	{My_IR_KEY_CUSTOM_1,	INFO_STOP},
	{My_IR_KEY_0,			INFO_0},
	{My_IR_KEY_1,			INFO_1},
	{My_IR_KEY_2,			INFO_2},
	{My_IR_KEY_3,			INFO_3},
	{My_IR_KEY_4,			INFO_4},
	{My_IR_KEY_5,			INFO_5},
	{My_IR_KEY_6,			INFO_6},
	{My_IR_KEY_7,			INFO_7},
	{My_IR_KEY_8,			INFO_8},
	{My_IR_KEY_9,			INFO_9},
#ifdef KEY_100_ENABLE	
	{My_IR_KEY_100,			INFO_100},
#endif	
	
	{My_IR_KEY_MODE,		INFO_MODE},
	{My_IR_KEY_PLAY,			INFO_PLAY},
	{My_IR_KEY_PLAY_M,		INFO_PLAY_MODE},
	{My_IR_KEY_VOL_UP,		INFO_VOL_PLUS},
	{My_IR_KEY_VOL_DN,		INFO_VOL_MINUS},
	{My_IR_KEY_PREV,		INFO_PREV_FIL},
	{My_IR_KEY_NEXT,		INFO_NEXT_FIL},
	{My_IR_KEY_EQ_UP,		INFO_EQ_UP},
	{My_IR_KEY_EQ_DN,		INFO_EQ_DOWN},
	{My_IR_KEY_CHN_UP,		INFO_MUTE},
	{My_IR_KEY_CHN_DN,		INFO_POWER},
};
#elif defined(K0000_BT_CHT909_V001)||defined(K0000_BT_CHT909_V002)||defined(K0000_BT_CHT909_V003)
_code MY_IR_KEY_STRUCT My_IRTab[]=       /*user code is 0xFF*/
{
	//{My_IR_KEY_TATOL,		My_IR_KEY_TATOL},	//4 总共键个数
	{My_IR_KEY_NONE,		NO_KEY},
	{My_IR_KEY_0,			INFO_0},
	{My_IR_KEY_1,			INFO_1},
	{My_IR_KEY_2,			INFO_2},
	{My_IR_KEY_3,			INFO_3},
	{My_IR_KEY_4,			INFO_4},
	{My_IR_KEY_5,			INFO_5},
	{My_IR_KEY_6,			INFO_6},
	{My_IR_KEY_7,			INFO_7},
	{My_IR_KEY_8,			INFO_8},
	{My_IR_KEY_9,			INFO_9},
#ifdef KEY_100_ENABLE	
	{My_IR_KEY_100,			INFO_100},
#endif	
	
	{My_IR_KEY_MODE,		INFO_MODE},
	{My_IR_KEY_PLAY,			INFO_PLAY},
	{My_IR_KEY_PLAY_M,		INFO_STOP},
	{My_IR_KEY_VOL_UP,		INFO_VOL_PLUS},
	{My_IR_KEY_VOL_DN,		INFO_VOL_MINUS},
	{My_IR_KEY_PREV,		INFO_PREV_FIL},
	{My_IR_KEY_NEXT,		INFO_NEXT_FIL},
	{My_IR_KEY_EQ_UP,		INFO_EQ_UP},
	{My_IR_KEY_EQ_DN,		INFO_EQ_DOWN},
	{My_IR_KEY_CHN_UP,		INFO_MUTE},
	{My_IR_KEY_CHN_DN,		INFO_POWER},
};
#elif defined(K0000_SRS_6032_V002)||defined(K0000_XDS_6032_V002)
_code MY_IR_KEY_STRUCT My_IRTab[]=       /*user code is 0xFF*/
{
	//{My_IR_KEY_TATOL,		My_IR_KEY_TATOL},	//4 总共键个数
	{My_IR_KEY_NONE,		NO_KEY},
	{My_IR_KEY_0,			INFO_0},
	{My_IR_KEY_1,			INFO_1},
	{My_IR_KEY_2,			INFO_2},
	{My_IR_KEY_3,			INFO_3},
	{My_IR_KEY_4,			INFO_4},
	{My_IR_KEY_5,			INFO_5},
	{My_IR_KEY_6,			INFO_6},
	{My_IR_KEY_7,			INFO_7},
	{My_IR_KEY_8,			INFO_8},
	{My_IR_KEY_9,			INFO_9},
#if 1//def KEY_100_ENABLE	
	{My_IR_KEY_100,			INFO_PLAY_MODE},
#endif	
	
	{My_IR_KEY_MODE,		NO_KEY},
	{My_IR_KEY_PLAY,			INFO_NEXT_FIL},
	{My_IR_KEY_PLAY_M,		NO_KEY},
	{My_IR_KEY_VOL_UP,		INFO_VOL_MINUS},
	{My_IR_KEY_VOL_DN,		INFO_EQ_UP},
	{My_IR_KEY_PREV,		INFO_PLAY},
	{My_IR_KEY_NEXT,		INFO_PREV_FIL},
	{My_IR_KEY_EQ_UP,		INFO_VOL_PLUS},
	{My_IR_KEY_EQ_DN,		INFO_EQ_DOWN},
	{My_IR_KEY_CHN_UP,		NO_KEY},
	{My_IR_KEY_CHN_DN,		INFO_MODE},
};
#elif defined(K302_ZhengYang_ZY302_V001)
_code MY_IR_KEY_STRUCT My_IRTab[]=       /*user code is 0xFF*/
{
	//{My_IR_KEY_TATOL,		My_IR_KEY_TATOL},	//4 总共键个数
	{My_IR_KEY_CUSTOM_1,	INFO_STOP},
	{My_IR_KEY_0,			INFO_0},
	{My_IR_KEY_1,			INFO_1},
	{My_IR_KEY_2,			INFO_2},
	{My_IR_KEY_3,			INFO_3},
	{My_IR_KEY_4,			INFO_4},
	{My_IR_KEY_5,			INFO_5},
	{My_IR_KEY_6,			INFO_6},
	{My_IR_KEY_7,			INFO_7},
	{My_IR_KEY_8,			INFO_8},
	{My_IR_KEY_9,			INFO_9},
#ifdef KEY_100_ENABLE	
	{My_IR_KEY_100,			INFO_100},
#endif	
	
	{My_IR_KEY_MODE,		INFO_MODE},
	{My_IR_KEY_PLAY,			INFO_PLAY},
	{My_IR_KEY_PLAY_M,		INFO_PLAY_MODE},
	{My_IR_KEY_VOL_UP,		INFO_VOL_PLUS},
	{My_IR_KEY_VOL_DN,		INFO_VOL_MINUS},
	{My_IR_KEY_PREV,		INFO_PREV_FIL},
	{My_IR_KEY_NEXT,		INFO_NEXT_FIL},
	{My_IR_KEY_EQ_UP,		INFO_EQ_UP},
	{My_IR_KEY_EQ_DN,		INFO_EQ_DOWN},
	{My_IR_KEY_CHN_UP,		INFO_MUTE},
	{My_IR_KEY_CHN_DN,		INFO_POWER},
};
#elif defined(K000_XingChuang_x821_V002)
_code MY_IR_KEY_STRUCT My_IRTab[]=       /*user code is 0xFF*/
{
	//{My_IR_KEY_TATOL,		My_IR_KEY_TATOL},	//4 总共键个数
	{My_IR_KEY_NONE,		NO_KEY},
	{My_IR_KEY_0,			INFO_PLUS},
	{My_IR_KEY_1,			INFO_MINUS},
	{My_IR_KEY_2,			INFO_2},
	{My_IR_KEY_3,			INFO_3},
	{My_IR_KEY_4,			INFO_4},
	{My_IR_KEY_5,			INFO_5},
	{My_IR_KEY_6,			INFO_6},
	{My_IR_KEY_7,			INFO_7},
	{My_IR_KEY_8,			INFO_8},
	{My_IR_KEY_9,			INFO_9},
#ifdef KEY_100_ENABLE	
	{My_IR_KEY_100,			INFO_100},
#endif	
	
	{My_IR_KEY_MODE,		INFO_MODE},
	{My_IR_KEY_PLAY,			INFO_PLAY},
	{My_IR_KEY_PLAY_M,		INFO_PLAY_MODE},
	{My_IR_KEY_VOL_UP,		INFO_VOL_PLUS},
	{My_IR_KEY_VOL_DN,		INFO_VOL_MINUS},
	{My_IR_KEY_PREV,		INFO_PREV_FIL},
	{My_IR_KEY_NEXT,		INFO_NEXT_FIL},
	{My_IR_KEY_EQ_UP,		INFO_EQ_UP},
	{My_IR_KEY_EQ_DN,		INFO_EQ_DOWN},
	{My_IR_KEY_CHN_UP,		INFO_MUTE},
	{My_IR_KEY_CHN_DN,		INFO_POWER},
};
#elif defined(IR_REMOTE_TYPE_JGY)
_code MY_IR_KEY_STRUCT My_IRTab[]=       /*user code is 0xFF*/
{
	//{My_IR_KEY_TATOL,		My_IR_KEY_TATOL},	//4 总共键个数
	{My_IR_KEY_NONE,		NO_KEY},
	{My_IR_KEY_0,			INFO_0},
	{My_IR_KEY_1,			INFO_1},
	{My_IR_KEY_2,			INFO_2},
	{My_IR_KEY_3,			INFO_3},
	{My_IR_KEY_4,			INFO_4},
	{My_IR_KEY_5,			INFO_5},
	{My_IR_KEY_6,			INFO_6},
	{My_IR_KEY_7,			INFO_7},
	{My_IR_KEY_8,			INFO_8},
	{My_IR_KEY_9,			INFO_9},
#ifdef KEY_100_ENABLE	
	{My_IR_KEY_100,			INFO_MODE},
#endif	
	
	{My_IR_KEY_MODE,		NO_KEY},
	{My_IR_KEY_PLAY,			INFO_PLAY},
	{My_IR_KEY_PLAY_M,		INFO_PICK_SONG | KEY_SHORT_UP},
	{My_IR_KEY_VOL_UP,		INFO_VOL_PLUS},
	{My_IR_KEY_VOL_DN,		INFO_VOL_MINUS},
	{My_IR_KEY_PREV,		INFO_PREV_FIL},
	{My_IR_KEY_NEXT,		INFO_NEXT_FIL},
	{My_IR_KEY_EQ_UP,		INFO_EQ_UP},
	{My_IR_KEY_EQ_DN,		INFO_MODE},
	{My_IR_KEY_CHN_UP,		INFO_CH_UP},
	{My_IR_KEY_CHN_DN,		INFO_CH_DOWN},
};
#elif defined(K572_AOKAILIN_811_V001)
_code MY_IR_KEY_STRUCT My_IRTab[]=       /*user code is 0xFF*/
{
	//{My_IR_KEY_TATOL,		My_IR_KEY_TATOL},	//4 总共键个数
	{My_IR_KEY_NONE,		NO_KEY},
	{My_IR_KEY_0,			INFO_0},
	{My_IR_KEY_1,			INFO_1},
	{My_IR_KEY_2,			INFO_2},
	{My_IR_KEY_3,			INFO_3},
	{My_IR_KEY_4,			INFO_4},
	{My_IR_KEY_5,			INFO_5},
	{My_IR_KEY_6,			INFO_6},
	{My_IR_KEY_7,			INFO_7},
	{My_IR_KEY_8,			INFO_8},
	{My_IR_KEY_9,			INFO_9},
#if 1//def KEY_100_ENABLE	
	{My_IR_KEY_100,			INFO_MODE},
#endif	
	
	{My_IR_KEY_MODE,		NO_KEY},
	{My_IR_KEY_PLAY,			INFO_PLAY},
	{My_IR_KEY_PLAY_M,		INFO_AUX_MOD},
	{My_IR_KEY_VOL_UP,		INFO_VOL_PLUS},
	{My_IR_KEY_VOL_DN,		INFO_VOL_MINUS},
	{My_IR_KEY_PREV,		INFO_PREV_FIL},
	{My_IR_KEY_NEXT,		INFO_NEXT_FIL},
	{My_IR_KEY_EQ_UP,		INFO_EQ_UP},
	{My_IR_KEY_EQ_DN,		INFO_EQ_DOWN},
	{My_IR_KEY_CHN_UP,		INFO_CH_UP},
	{My_IR_KEY_CHN_DN,		INFO_CH_DOWN},
};
#elif defined(K566_JLH_566_V001)||defined(K566_SWD_566_V001)
_code MY_IR_KEY_STRUCT My_IRTab[]=       /*user code is 0xFF*/
{
	//{My_IR_KEY_TATOL,		My_IR_KEY_TATOL},	//4 总共键个数
	{My_IR_KEY_NONE,		NO_KEY},
	{My_IR_KEY_0,			INFO_0},
	{My_IR_KEY_1,			INFO_1},
	{My_IR_KEY_2,			INFO_2},
	{My_IR_KEY_3,			INFO_3},
	{My_IR_KEY_4,			INFO_4},
	{My_IR_KEY_5,			INFO_5},
	{My_IR_KEY_6,			INFO_6},
	{My_IR_KEY_7,			INFO_7},
	{My_IR_KEY_8,			INFO_8},
	{My_IR_KEY_9,			INFO_9},
#ifdef KEY_100_ENABLE	
	{My_IR_KEY_100,			INFO_100},
#endif	
	
	{My_IR_KEY_MODE,		INFO_MODE},
	{My_IR_KEY_PLAY,			INFO_PLAY},
	{My_IR_KEY_PLAY_M,		INFO_PLAY_MODE},
	{My_IR_KEY_VOL_UP,		INFO_VOL_PLUS},
	{My_IR_KEY_VOL_DN,		INFO_VOL_MINUS},
	{My_IR_KEY_PREV,		INFO_PREV_FIL},
	{My_IR_KEY_NEXT,		INFO_NEXT_FIL},
	{My_IR_KEY_EQ_UP,		INFO_EQ_UP},
	{My_IR_KEY_EQ_DN,		INFO_EQ_DOWN},
	{My_IR_KEY_CHN_UP,		INFO_MUTE},
	{My_IR_KEY_CHN_DN,		INFO_POWER},
};
#elif defined(K1119_LS_1119_V001)
_code MY_IR_KEY_STRUCT My_IRTab[]=       /*user code is 0xFF*/
{
	//{My_IR_KEY_TATOL,		My_IR_KEY_TATOL},	//4 总共键个数
	{My_IR_KEY_NONE,		NO_KEY},
	{My_IR_KEY_0,			INFO_CH_DOWN},
	{My_IR_KEY_1,			INFO_CH_UP},
	{My_IR_KEY_2,			INFO_MINUS},
	{My_IR_KEY_3,			INFO_PLUS},
	{My_IR_KEY_4,			INFO_4},
	{My_IR_KEY_5,			INFO_5},
	{My_IR_KEY_6,			INFO_6},
	{My_IR_KEY_7,			INFO_7},
	{My_IR_KEY_8,			INFO_8},
	{My_IR_KEY_9,			INFO_9},
#ifdef KEY_100_ENABLE	
	{My_IR_KEY_100,			INFO_100},
#endif	
	
	{My_IR_KEY_MODE,		INFO_MODE},
	{My_IR_KEY_PLAY,			INFO_PLAY},
	{My_IR_KEY_PLAY_M,		INFO_PLAY_MODE},
	{My_IR_KEY_VOL_UP,		INFO_VOL_PLUS},
	{My_IR_KEY_VOL_DN,		INFO_VOL_MINUS},
	{My_IR_KEY_PREV,		INFO_PREV_FIL},
	{My_IR_KEY_NEXT,		INFO_NEXT_FIL},
	{My_IR_KEY_EQ_UP,		INFO_EQ_UP},
	{My_IR_KEY_EQ_DN,		INFO_EQ_DOWN},
	{My_IR_KEY_CHN_UP,		INFO_MUTE},
	{My_IR_KEY_CHN_DN,		INFO_POWER},
};
#elif defined(JINRUI_IR_REMOTE_TYPE)||defined(K568_JinRui_568_V001)||defined(K2035_SES_2035_V001)||defined(K2035_SES_2035_V002)||defined(K566_JinRui_566_V001)||defined(K769_JinRui_769_V001)||defined(K599_JinRui_599_V001)||defined(K1037_JinRUI_1037_V001)
_code MY_IR_KEY_STRUCT My_IRTab[]=       /*user code is 0xFF*/
{
	//{My_IR_KEY_TATOL,		My_IR_KEY_TATOL},	//4 总共键个数
	{My_IR_KEY_NONE,		NO_KEY},
	{My_IR_KEY_0,			INFO_VOL_MINUS},
	{My_IR_KEY_1,			INFO_1},
	{My_IR_KEY_2,			INFO_2},
	{My_IR_KEY_3,			INFO_3},
	{My_IR_KEY_4,			INFO_4},
	{My_IR_KEY_5,			INFO_5},
	{My_IR_KEY_6,			INFO_6},
	{My_IR_KEY_7,			INFO_7},
	{My_IR_KEY_8,			INFO_8},
	{My_IR_KEY_9,			INFO_9},
#if 1//def KEY_100_ENABLE	
	{My_IR_KEY_100,			INFO_VOL_PLUS},
#endif	
	
	{My_IR_KEY_MODE,		INFO_STOP},
	{My_IR_KEY_PLAY,			INFO_EQ_UP},
	{My_IR_KEY_PLAY_M,		INFO_0},
	{My_IR_KEY_VOL_UP,		INFO_NEXT_FIL},
	{My_IR_KEY_VOL_DN,		INFO_PREV_FIL},
	{My_IR_KEY_PREV,		INFO_MODE},
	{My_IR_KEY_NEXT,		INFO_PLAY_MODE},
	{My_IR_KEY_EQ_UP,		INFO_PLAY},
	//{My_IR_KEY_EQ_DN,		INFO_EQ_DOWN},
	{My_IR_KEY_CHN_UP,		INFO_MUTE},
	{My_IR_KEY_CHN_DN,		INFO_POWER},
};
#elif defined(K000_XingChuang_X824_V001)
_code MY_IR_KEY_STRUCT My_IRTab[]=       /*user code is 0xFF*/
{
	//{My_IR_KEY_TATOL,		My_IR_KEY_TATOL},	//4 总共键个数
	{My_IR_KEY_NONE,		NO_KEY},
	{My_IR_KEY_0,			INFO_VOL_MINUS},
	{My_IR_KEY_1,			INFO_1},
	{My_IR_KEY_2,			INFO_2},
	{My_IR_KEY_3,			INFO_3},
	{My_IR_KEY_4,			INFO_4},
	{My_IR_KEY_5,			INFO_5},
	{My_IR_KEY_6,			INFO_6},
	{My_IR_KEY_7,			INFO_7},
	{My_IR_KEY_8,			INFO_8},
	{My_IR_KEY_9,			INFO_9},
#if 1 //def KEY_100_ENABLE	
	{My_IR_KEY_100,			INFO_VOL_PLUS},
#endif	
	
	{My_IR_KEY_MODE,		INFO_PLAY_MODE},
	{My_IR_KEY_PLAY,			INFO_EQ_UP},
	{My_IR_KEY_PLAY_M,		INFO_0},
	{My_IR_KEY_VOL_UP,		INFO_NEXT_FIL},
	{My_IR_KEY_VOL_DN,		INFO_PREV_FIL},
	{My_IR_KEY_PREV,		INFO_CH_DOWN},
	{My_IR_KEY_NEXT,		INFO_CH_UP},
	{My_IR_KEY_EQ_UP,		INFO_PLAY},
	{My_IR_KEY_EQ_DN,		INFO_EQ_DOWN},
	{My_IR_KEY_CHN_UP,		INFO_MODE},
	{My_IR_KEY_CHN_DN,		INFO_POWER},
};
#elif defined(K010_XFW_931_V001)||defined(K3015_XFW_931_V001)
_code MY_IR_KEY_STRUCT My_IRTab[]=       /*user code is 0xFF*/
{
	//{My_IR_KEY_TATOL,		My_IR_KEY_TATOL},	//4 总共键个数
	{My_IR_KEY_NONE,		NO_KEY},
	{My_IR_KEY_0,			INFO_VOL_MINUS},
	{My_IR_KEY_1,			INFO_1},
	{My_IR_KEY_2,			INFO_2},
	{My_IR_KEY_3,			INFO_3},
	{My_IR_KEY_4,			INFO_4},
	{My_IR_KEY_5,			INFO_5},
	{My_IR_KEY_6,			INFO_6},
	{My_IR_KEY_7,			INFO_7},
	{My_IR_KEY_8,			INFO_8},
	{My_IR_KEY_9,			INFO_9},
#if 1 //def KEY_100_ENABLE	
	{My_IR_KEY_100,			INFO_VOL_PLUS},
#endif	
	
	{My_IR_KEY_MODE,		INFO_PLAY_MODE},
	{My_IR_KEY_PLAY,			INFO_EQ_UP},
	{My_IR_KEY_PLAY_M,		INFO_0},
	{My_IR_KEY_VOL_UP,		INFO_NEXT_FIL},
	{My_IR_KEY_VOL_DN,		INFO_PREV_FIL},
	{My_IR_KEY_PREV,		INFO_CH_DOWN},
	{My_IR_KEY_NEXT,		INFO_CH_UP},
	{My_IR_KEY_EQ_UP,		INFO_PLAY},
	{My_IR_KEY_EQ_DN,		INFO_EQ_DOWN},
	{My_IR_KEY_CHN_UP,		INFO_MODE},
	{My_IR_KEY_CHN_DN,		INFO_POWER},
};
#elif defined(K0000_GW_300G_V001)||defined(GUOWEI_IR_REMOTE)
_code MY_IR_KEY_STRUCT My_IRTab[]=       /*user code is 0xFF*/
{
	//{My_IR_KEY_TATOL,		My_IR_KEY_TATOL},	//4 总共键个数
	{My_IR_KEY_CUSTOM_1,	INFO_STOP},
	{My_IR_KEY_0,			INFO_0},
	{My_IR_KEY_1,			INFO_1},
	{My_IR_KEY_2,			INFO_2},
	{My_IR_KEY_3,			INFO_3},
	{My_IR_KEY_4,			INFO_4},
	{My_IR_KEY_5,			INFO_5},
	{My_IR_KEY_6,			INFO_6},
	{My_IR_KEY_7,			INFO_7},
	{My_IR_KEY_8,			INFO_8},
	{My_IR_KEY_9,			INFO_9},
	{My_IR_KEY_100,			INFO_PLAY_MODE},
	
	{My_IR_KEY_MODE,		INFO_MODE},
	{My_IR_KEY_PLAY,			INFO_NEXT_FIL},
	{My_IR_KEY_PLAY_M,		INFO_EQ_DOWN},
	{My_IR_KEY_VOL_UP,		INFO_VOL_MINUS},
	{My_IR_KEY_VOL_DN,		INFO_EQ_UP},
	{My_IR_KEY_PREV,		INFO_PLAY},
	{My_IR_KEY_NEXT,		INFO_PREV_FIL},
	{My_IR_KEY_EQ_UP,		INFO_VOL_PLUS},
	{My_IR_KEY_EQ_DN,		INFO_EQ_DOWN},
	{My_IR_KEY_CHN_UP,		INFO_MUTE},
	{My_IR_KEY_CHN_DN,		INFO_POWER},
};
#elif defined(MEICHENG_IR_REMOTE)
_code MY_IR_KEY_STRUCT My_IRTab[]=       /*user code is 0xFF*/
{
	//{My_IR_KEY_TATOL,		My_IR_KEY_TATOL},	//4 总共键个数
	{My_IR_KEY_NONE,		NO_KEY},
	{My_IR_KEY_0,			INFO_0},
	{My_IR_KEY_1,			INFO_1},
	{My_IR_KEY_2,			INFO_2},
	{My_IR_KEY_3,			INFO_3},
	{My_IR_KEY_4,			INFO_4},
	{My_IR_KEY_5,			INFO_5},
	{My_IR_KEY_6,			INFO_6},
	{My_IR_KEY_7,			INFO_7},
	{My_IR_KEY_8,			INFO_8},
	{My_IR_KEY_9,			INFO_9},
	{My_IR_KEY_100,			INFO_PLAY_MODE},
	
	{My_IR_KEY_MODE,		INFO_MODE},
	{My_IR_KEY_PLAY,			INFO_NEXT_FIL},
	{My_IR_KEY_PLAY_M,		INFO_EQ_DOWN},
	{My_IR_KEY_VOL_UP,		INFO_VOL_MINUS},
	{My_IR_KEY_VOL_DN,		INFO_EQ_UP},
	{My_IR_KEY_PREV,		INFO_PLAY},
	{My_IR_KEY_NEXT,		INFO_PREV_FIL},
	{My_IR_KEY_EQ_UP,		INFO_VOL_PLUS},
	{My_IR_KEY_EQ_DN,		INFO_MODE},
	{My_IR_KEY_CHN_UP,		INFO_MUTE},
	{My_IR_KEY_CHN_DN,		INFO_POWER},
};
#elif defined(K120_YJH_120_V001)||defined(K1051_JIAMEI_1051C_V001)||defined(K0000_GW_238_V001)
_code MY_IR_KEY_STRUCT My_IRTab[]=       /*user code is 0xFF*/
{
	//{My_IR_KEY_TATOL,		My_IR_KEY_TATOL},	//4 总共键个数
	{My_IR_KEY_NONE,		NO_KEY},
	{My_IR_KEY_0,			INFO_0},
	{My_IR_KEY_1,			INFO_1},
	{My_IR_KEY_2,			INFO_2},
	{My_IR_KEY_3,			INFO_3},
	{My_IR_KEY_4,			INFO_4},
	{My_IR_KEY_5,			INFO_5},
	{My_IR_KEY_6,			INFO_6},
	{My_IR_KEY_7,			INFO_7},
	{My_IR_KEY_8,			INFO_8},
	{My_IR_KEY_9,			INFO_9},
	{My_IR_KEY_100,			INFO_PLAY_MODE},
	
	{My_IR_KEY_MODE,		INFO_MODE},
	{My_IR_KEY_PLAY,			INFO_NEXT_FIL},
	{My_IR_KEY_PLAY_M,		INFO_EQ_DOWN},
	{My_IR_KEY_VOL_UP,		INFO_VOL_MINUS},
	{My_IR_KEY_VOL_DN,		INFO_EQ_UP},
	{My_IR_KEY_PREV,		INFO_PLAY},
	{My_IR_KEY_NEXT,		INFO_PREV_FIL},
	{My_IR_KEY_EQ_UP,		INFO_VOL_PLUS},
	{My_IR_KEY_EQ_DN,		INFO_EQ_DOWN},
	{My_IR_KEY_CHN_UP,		INFO_MUTE},
	{My_IR_KEY_CHN_DN,		INFO_POWER},
};
#elif defined(K015_983_JLH_V001)
_code MY_IR_KEY_STRUCT My_IRTab[]=       /*user code is 0xFF*/
{
	//{My_IR_KEY_TATOL,		My_IR_KEY_TATOL},	//4 总共键个数
	{My_IR_KEY_NONE,	NO_KEY},
	{My_IR_KEY_0,			INFO_0},
	{My_IR_KEY_1,			INFO_1},
	{My_IR_KEY_2,			INFO_2},
	{My_IR_KEY_3,			INFO_3},
	{My_IR_KEY_4,			INFO_4},
	{My_IR_KEY_5,			INFO_5},
	{My_IR_KEY_6,			INFO_6},
	{My_IR_KEY_7,			INFO_7},
	{My_IR_KEY_8,			INFO_8},
	{My_IR_KEY_9,			INFO_9},
#if 1//def KEY_100_ENABLE	
	{My_IR_KEY_100,			INFO_PLAY_MODE},
#endif	
	
	{My_IR_KEY_MODE,		NO_KEY},
	{My_IR_KEY_PLAY,			INFO_NEXT_FIL},
	{My_IR_KEY_PLAY_M,		INFO_MODE},
	{My_IR_KEY_VOL_UP,		INFO_VOL_PLUS},
	{My_IR_KEY_VOL_DN,		INFO_EQ_UP},
	{My_IR_KEY_PREV,		INFO_PLAY},
	{My_IR_KEY_NEXT,		INFO_PREV_FIL},
	{My_IR_KEY_EQ_UP,		INFO_VOL_MINUS},
	{My_IR_KEY_EQ_DN,		INFO_EQ_DOWN},
	{My_IR_KEY_CHN_UP,		INFO_MUTE},
	{My_IR_KEY_CHN_DN,		INFO_POWER},
};
#elif defined(K722_YJH_722_V001)
_code MY_IR_KEY_STRUCT My_IRTab[]=       /*user code is 0xFF*/
{
	//{My_IR_KEY_TATOL,		My_IR_KEY_TATOL},	//4 总共键个数
	{My_IR_KEY_NONE,		NO_KEY},
	{My_IR_KEY_0,			INFO_0},
	{My_IR_KEY_1,			INFO_1},
	{My_IR_KEY_2,			INFO_2},
	{My_IR_KEY_3,			INFO_3},
	{My_IR_KEY_4,			INFO_4},
	{My_IR_KEY_5,			INFO_5},
	{My_IR_KEY_6,			INFO_6},
	{My_IR_KEY_7,			INFO_7},
	{My_IR_KEY_8,			INFO_8},
	{My_IR_KEY_9,			INFO_9},
#ifdef KEY_100_ENABLE	
	{My_IR_KEY_100,			INFO_100},
#endif	
	
	{My_IR_KEY_MODE,		INFO_MODE},
	{My_IR_KEY_PLAY,			INFO_PREV_FIL},
	{My_IR_KEY_PLAY_M,		INFO_EQ_DOWN},
	{My_IR_KEY_VOL_UP,		INFO_EQ_UP },
	{My_IR_KEY_VOL_DN,		INFO_VOL_PLUS},
	{My_IR_KEY_PREV,		INFO_NEXT_FIL },
	{My_IR_KEY_NEXT,		INFO_PLAY },
	{My_IR_KEY_EQ_UP,		INFO_VOL_MINUS},
	{My_IR_KEY_EQ_DN,		INFO_PLAY_MODE},
	{My_IR_KEY_CHN_UP,		INFO_MUTE},
	{My_IR_KEY_CHN_DN,		INFO_POWER},
};
#elif defined(K015_983_SW005_ZhuoXin_FB001_V001)
_code MY_IR_KEY_STRUCT My_IRTab[]=       /*user code is 0xFF*/
{
	//{My_IR_KEY_TATOL,		My_IR_KEY_TATOL},	//4 总共键个数
	{My_IR_KEY_NONE,		NO_KEY},
	{My_IR_KEY_0,			INFO_0},
	{My_IR_KEY_1,			INFO_1},
	{My_IR_KEY_2,			INFO_2},
	{My_IR_KEY_3,			INFO_3},
	{My_IR_KEY_4,			INFO_4},
	{My_IR_KEY_5,			INFO_5},
	{My_IR_KEY_6,			INFO_6},
	{My_IR_KEY_7,			INFO_7},
	{My_IR_KEY_8,			INFO_8},
	{My_IR_KEY_9,			INFO_9},
#if 1//def KEY_10_ENABLE	
	{My_IR_KEY_100,			INFO_100},
#endif	
	
	{My_IR_KEY_MODE,		INFO_MODE},
	{My_IR_KEY_PLAY,			INFO_PLAY},
	{My_IR_KEY_PLAY_M,		INFO_PLAY_MODE},
	{My_IR_KEY_VOL_UP,		INFO_VOL_PLUS},
	{My_IR_KEY_VOL_DN,		INFO_VOL_MINUS},
	{My_IR_KEY_PREV,		INFO_PREV_FIL},
	{My_IR_KEY_NEXT,		INFO_NEXT_FIL},
	{My_IR_KEY_EQ_UP,		INFO_EQ_UP},
	{My_IR_KEY_EQ_DN,		INFO_MINUS},
	{My_IR_KEY_CHN_UP,		INFO_PLUS},
	{My_IR_KEY_CHN_DN,		INFO_POWER},
};
#elif defined(K608_TC_608_V001)||defined(K608_TC_608_V002)||defined(K801_TC_801_V001)||defined(TianCheng_Remote)||defined(K000_HG_898_V001)
_code MY_IR_KEY_STRUCT My_IRTab[]=       /*user code is 0xFF*/
{
	//{My_IR_KEY_TATOL,		My_IR_KEY_TATOL},	//4 总共键个数
	{My_IR_KEY_NONE,		NO_KEY},
	{My_IR_KEY_0,			INFO_0},
	{My_IR_KEY_1,			INFO_1},
	{My_IR_KEY_2,			INFO_2},
	{My_IR_KEY_3,			INFO_3},
	{My_IR_KEY_4,			INFO_4},
	{My_IR_KEY_5,			INFO_5},
	{My_IR_KEY_6,			INFO_6},
	{My_IR_KEY_7,			INFO_7},
	{My_IR_KEY_8,			INFO_8},
	{My_IR_KEY_9,			INFO_9},
	{My_IR_KEY_100,			INFO_PLAY_MODE},
	
	{My_IR_KEY_MODE,		INFO_MODE},
	{My_IR_KEY_PLAY,			INFO_NEXT_FIL},
	{My_IR_KEY_PLAY_M,		INFO_EQ_DOWN},
	{My_IR_KEY_VOL_UP,		INFO_VOL_MINUS},
	{My_IR_KEY_VOL_DN,		INFO_EQ_UP},
	{My_IR_KEY_PREV,		INFO_PLAY},
	{My_IR_KEY_NEXT,		INFO_PREV_FIL},
	{My_IR_KEY_EQ_UP,		INFO_VOL_PLUS},
	//{My_IR_KEY_EQ_DN,		INFO_EQ_DOWN},
	{My_IR_KEY_CHN_UP,		INFO_MUTE},
	{My_IR_KEY_CHN_DN,		INFO_POWER},
};
#elif defined(K000_JR_210_V001)
_code MY_IR_KEY_STRUCT My_IRTab[]=       /*user code is 0xFF*/
{
	//{My_IR_KEY_TATOL,		My_IR_KEY_TATOL},	//4 总共键个数
	{My_IR_KEY_NONE,		NO_KEY},
	{My_IR_KEY_0,			INFO_SUB_PLUS},
	{My_IR_KEY_1,			INFO_SUB_MINUS},
	{My_IR_KEY_2,			INFO_TRE_PLUS},
	{My_IR_KEY_3,			INFO_TRE_MINUS},
	{My_IR_KEY_4,			INFO_SW_PLUS},
	{My_IR_KEY_5,			INFO_SW_MINUS},
	{My_IR_KEY_6,			NO_KEY},
	{My_IR_KEY_7,			NO_KEY},
	{My_IR_KEY_8,			NO_KEY},
	{My_IR_KEY_9,			NO_KEY},
#ifdef KEY_100_ENABLE	
	{My_IR_KEY_100,			INFO_100},
#endif	
	
	{My_IR_KEY_MODE,		INFO_MODE},
	{My_IR_KEY_PLAY,			INFO_PLAY},
	{My_IR_KEY_PLAY_M,		INFO_PLAY_MODE},
	{My_IR_KEY_VOL_UP,		INFO_VOL_PLUS},
	{My_IR_KEY_VOL_DN,		INFO_VOL_MINUS},
	{My_IR_KEY_PREV,		INFO_PREV_FIL},
	{My_IR_KEY_NEXT,		INFO_NEXT_FIL},
	{My_IR_KEY_EQ_UP,		INFO_EQ_UP},
	{My_IR_KEY_EQ_DN,		INFO_EQ_DOWN},
	{My_IR_KEY_CHN_UP,		INFO_MUTE},
	{My_IR_KEY_CHN_DN,		INFO_POWER},
};
#else /*IR_REMOTER_WITH_CHANEL_SELECT*/
_code MY_IR_KEY_STRUCT My_IRTab[]=       /*user code is 0xFF*/
{
	//{My_IR_KEY_TATOL,		My_IR_KEY_TATOL},	//4 总共键个数
	{My_IR_KEY_NONE,		NO_KEY},
	{My_IR_KEY_0,			INFO_0},
	{My_IR_KEY_1,			INFO_1},
	{My_IR_KEY_2,			INFO_2},
	{My_IR_KEY_3,			INFO_3},
	{My_IR_KEY_4,			INFO_4},
	{My_IR_KEY_5,			INFO_5},
	{My_IR_KEY_6,			INFO_6},
	{My_IR_KEY_7,			INFO_7},
	{My_IR_KEY_8,			INFO_8},
	{My_IR_KEY_9,			INFO_9},
#ifdef KEY_100_ENABLE	
	{My_IR_KEY_100,			INFO_100},
#endif	
	
	{My_IR_KEY_MODE,		INFO_MODE},
	{My_IR_KEY_PLAY,			INFO_PLAY},
	{My_IR_KEY_PLAY_M,		INFO_PLAY_MODE},
	{My_IR_KEY_VOL_UP,		INFO_VOL_PLUS},
	{My_IR_KEY_VOL_DN,		INFO_VOL_MINUS},
	{My_IR_KEY_PREV,		INFO_PREV_FIL},
	{My_IR_KEY_NEXT,		INFO_NEXT_FIL},
	{My_IR_KEY_EQ_UP,		INFO_EQ_UP},
	{My_IR_KEY_EQ_DN,		INFO_EQ_DOWN},
	{My_IR_KEY_CHN_UP,		INFO_CH_UP},
	{My_IR_KEY_CHN_DN,		INFO_CH_DOWN},
};
#endif

#if defined(USE_TWO_IR_REMOTE)

#if defined(K302_ZhengYang_ZY302_V001)

_code MY_IR_KEY_STRUCT My_IRTab_2[]=       /*user code is 0xFF*/
{
	//{My_IR_KEY_TATOL,		My_IR_KEY_TATOL},	//4 总共键个数
	{My_IR2_KEY_CUSTOM_1,	INFO_STOP},
	{My_IR2_KEY_0,			INFO_0},
	{My_IR2_KEY_1,			INFO_AUX_MOD},
	{My_IR2_KEY_2,			INFO_MP3_MOD},
	{My_IR2_KEY_3,			INFO_FM_MOD},
	{My_IR2_KEY_4,			INFO_MUTE},
	{My_IR2_KEY_5,			INFO_5},
	{My_IR2_KEY_6,			INFO_6},
	{My_IR2_KEY_7,			INFO_7},
	{My_IR2_KEY_8,			INFO_MINUS},
	{My_IR2_KEY_9,			INFO_PLUS},
#ifdef KEY_100_ENABLE	
	{My_IR2_KEY_100,			INFO_100},
#endif	
	
	{My_IR2_KEY_MODE,		INFO_MODE},
	{My_IR2_KEY_PLAY,		INFO_PLAY},
	{My_IR2_KEY_PLAY_M,		INFO_PLAY_MODE},
	{My_IR2_KEY_VOL_UP,		INFO_VOL_PLUS},
	{My_IR2_KEY_VOL_DN,		INFO_VOL_MINUS},
	{My_IR2_KEY_PREV,		INFO_PREV_FIL},
	{My_IR2_KEY_NEXT,		INFO_NEXT_FIL},
	{My_IR2_KEY_EQ_UP,		INFO_EQ_UP},
	{My_IR2_KEY_EQ_DN,		INFO_EQ_DOWN},
	{My_IR2_KEY_CHN_UP,		INFO_CH_NEXT},
	{My_IR2_KEY_CHN_DN,		INFO_CH_PREV},
};
#elif defined(K000_JR_210_V001)
_code MY_IR_KEY_STRUCT My_IRTab_2[]=       /*user code is 0xFF*/
{
	//{My_IR_KEY_TATOL,		My_IR_KEY_TATOL},	//4 总共键个数
	{My_IR2_KEY_NONE,		NO_KEY},
	{My_IR2_KEY_0,			INFO_SUB_PLUS},
	{My_IR2_KEY_1,			INFO_SUB_MINUS},
	{My_IR2_KEY_2,			INFO_TRE_PLUS},
	{My_IR2_KEY_3,			INFO_TRE_MINUS},
	{My_IR2_KEY_4,			INFO_SW_PLUS},
	{My_IR2_KEY_5,			INFO_SW_MINUS},
	{My_IR2_KEY_6,			INFO_EQ_CLASS},
	{My_IR2_KEY_7,			INFO_EQ_JAZZ},
	{My_IR2_KEY_8,			INFO_EQ_ROCK},
	{My_IR2_KEY_9,			INFO_EQ_NORMAL},
	{My_IR2_KEY_10,			INFO_CH_PREV},
	{My_IR2_KEY_11,			INFO_CH_NEXT},
	{My_IR2_KEY_12,			INFO_MINUS},
	{My_IR2_KEY_13,			INFO_PLUS},
#ifdef KEY_100_ENABLE	
	{My_IR2_KEY_100,			INFO_100},
#endif	
	
	{My_IR2_KEY_MODE,		INFO_MODE},
	{My_IR2_KEY_PLAY,		INFO_PLAY},
	{My_IR2_KEY_PLAY_M,		NO_KEY},
	{My_IR2_KEY_VOL_UP,		INFO_VOL_PLUS},
	{My_IR2_KEY_VOL_DN,		INFO_VOL_MINUS},
	{My_IR2_KEY_PREV,		INFO_PREV_FIL},
	{My_IR2_KEY_NEXT,		INFO_NEXT_FIL},
	{My_IR2_KEY_EQ_UP,		INFO_EQ_UP},
	{My_IR2_KEY_EQ_DN,		INFO_EQ_DOWN},
	{My_IR2_KEY_CHN_UP,		INFO_MUTE},
	{My_IR2_KEY_CHN_DN,		INFO_POWER},
};
#elif defined(K1051_JIAMEI_1051C_V001)
_code MY_IR_KEY_STRUCT My_IRTab_2[]=       /*user code is 0xFF*/
{
	//{My_IR_KEY_TATOL,		My_IR_KEY_TATOL},	//4 总共键个数
	{My_IR2_KEY_NONE,		NO_KEY},
	{My_IR2_KEY_0,			INFO_0},
	{My_IR2_KEY_1,			INFO_1},
	{My_IR2_KEY_2,			INFO_2},
	{My_IR2_KEY_3,			INFO_3},
	{My_IR2_KEY_4,			INFO_4},
	{My_IR2_KEY_5,			INFO_5},
	{My_IR2_KEY_6,			INFO_6},
	{My_IR2_KEY_7,			INFO_7},
	{My_IR2_KEY_8,			INFO_8},
	{My_IR2_KEY_9,			INFO_9},
#ifdef KEY_100_ENABLE	
	{My_IR2_KEY_100,			INFO_100},
#endif	
	
	{My_IR2_KEY_MODE,		INFO_MODE},
	{My_IR2_KEY_PLAY,		INFO_PLAY},
	{My_IR2_KEY_PLAY_M,		INFO_PLAY_MODE},
	{My_IR2_KEY_VOL_UP,		INFO_VOL_PLUS},
	{My_IR2_KEY_VOL_DN,		INFO_VOL_MINUS},
	{My_IR2_KEY_PREV,		INFO_PREV_FIL},
	{My_IR2_KEY_NEXT,		INFO_NEXT_FIL},
	{My_IR2_KEY_EQ_UP,		INFO_EQ_UP},
	{My_IR2_KEY_EQ_DN,		INFO_EQ_DOWN},
	{My_IR2_KEY_CHN_UP,		INFO_MUTE},
	{My_IR2_KEY_CHN_DN,		INFO_POWER},
};
#else
_code MY_IR_KEY_STRUCT My_IRTab_2[]=       /*user code is 0xFF*/
{
	//{My_IR_KEY_TATOL,		My_IR_KEY_TATOL},	//4 总共键个数
	{My_IR2_KEY_NONE,		NO_KEY},
	{My_IR2_KEY_0,			INFO_0},
	{My_IR2_KEY_1,			INFO_1},
	{My_IR2_KEY_2,			INFO_2},
	{My_IR2_KEY_3,			INFO_3},
	{My_IR2_KEY_4,			INFO_4},
	{My_IR2_KEY_5,			INFO_5},
	{My_IR2_KEY_6,			INFO_6},
	{My_IR2_KEY_7,			INFO_7},
	{My_IR2_KEY_8,			INFO_8},
	{My_IR2_KEY_9,			INFO_9},
#ifdef KEY_100_ENABLE	
	{My_IR2_KEY_100,			INFO_100},
#endif	
	
	{My_IR2_KEY_MODE,		INFO_MODE},
	{My_IR2_KEY_PLAY,		INFO_PLAY},
	{My_IR2_KEY_PLAY_M,		INFO_PLAY_MODE},
	{My_IR2_KEY_VOL_UP,		INFO_VOL_PLUS},
	{My_IR2_KEY_VOL_DN,		INFO_VOL_MINUS},
	{My_IR2_KEY_PREV,		INFO_PREV_FIL},
	{My_IR2_KEY_NEXT,		INFO_NEXT_FIL},
	{My_IR2_KEY_EQ_UP,		INFO_EQ_UP},
	{My_IR2_KEY_EQ_DN,		INFO_EQ_DOWN},
	{My_IR2_KEY_CHN_UP,		INFO_CH_UP},
	{My_IR2_KEY_CHN_DN,		INFO_CH_DOWN},
};
#endif

#endif
u8 get_my_IR_key_MAX()
{
	return (u8)((sizeof(My_IRTab))/2);
}
#if defined(USE_TWO_IR_REMOTE)
u8 get_my_IR2_key_MAX()
{
	return (u8)((sizeof(My_IRTab_2))/2);
}
#endif
#endif


