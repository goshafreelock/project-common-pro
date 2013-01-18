/*--------------------------------------------------------------------------*/
/**@file     mp3mode.h
   @brief    解码任务
   @details
   @author
   @date   2010-12-13
   @note
*/
/*----------------------------------------------------------------------------*/

#ifndef _MP3_MODE_
#define _MP3_MODE_

#ifdef __C51__
#include "config.h"
#include "uart.h"
#include "decode.h"
#include "filesystem.h"

#include "device.h"
#include "key.h"
#include "display_common.h"
#include "eq.h"
#include "iic.h"
#include "get_music_file.h"
#include "id3.h"
#include "dac.h"

#ifdef CUSTOM_OUTPUT_LIMIT
#define CUSTOM_OUTPUT_VAL		4
#endif

typedef enum
{
#if 1//defined(PLAY_MODE_REPEAT_ALL)
    REPEAT_ALL = 0,
    REPEAT_DEV_ALL=0,	
#endif    
    REPEAT_FOLDER,
    REPEAT_ONE,
    REPEAT_RANDOM,
    REPEAT_OFF,

}PLAY_MODE;

enum 							//config command
{
    MUSIC_PAUSE = 0,				//播放暂停
	MUSIC_PLAY,					//正在播放中
	MUSIC_FF_FR,					//快进快退
	MUSIC_STOP,
};
#ifdef FF_LARGE_STEP
#define FF_FF_STEP		6
#define FF_FR_STEP		-6
#elif defined(FAST_FORWARD_STEP_ONE_SEC)
#define FF_FF_STEP		1
#define FF_FR_STEP		-1
#else
#define FF_FF_STEP		3
#define FF_FR_STEP		-3
#endif
void decode_play(void);
void music_info_init(void);
#ifdef PLAY_MODE_USE_INTRO_MODE
void init_intro_play_mode(void);
#endif
#endif

#define MAX_VOL 30
#define MIN_VOL 0

#ifndef NO_VOLUME_LIMITE

#if defined(VOLUME_CUSTOMER_DEFINE)
#define MAX_VOL_SHOW 	50
#elif defined(NEW_CUSTOMED_VOLUME_DIVIDED_METHOD)

#if defined(VOLUME_CUSTOMER_DEFINE_16)
#define MAX_VOL_SHOW 	16
#define VOL_POINT_ONE	5
#define VOL_POINT_TWO	10
#define VOL_POINT_A		15
#define VOL_POINT_B		22
#else
#define MAX_VOL_SHOW 	50
#define VOL_POINT_ONE	20
#define VOL_POINT_TWO	30
#define VOL_POINT_A		15
#define VOL_POINT_B		20
#endif
#elif defined(VOLUME_CUSTOMER_DEFINE_63)
#define MAX_VOL_SHOW 	63
#elif defined(VOLUME_CUSTOMER_DEFINE_16)
#define MAX_VOL_SHOW 	16
#elif defined(VOLUME_CUSTOMER_DEFINE_28)
#define USE_VOL_LIMTATION
#define MAX_VOL_SHOW 	28
#elif defined(VOLUME_CUSTOMER_DEFINE_34)
#define USE_VOL_LIMTATION
#define MAX_VOL_SHOW 	34
#elif defined(VOLUME_CUSTOMER_DEFINE_32)
#define USE_VOL_LIMTATION
#define MAX_VOL_SHOW 	32
#else
#define USE_VOL_LIMTATION
#define MAX_VOL_SHOW 	30
#endif

#endif

#if defined(CUSTOMIZED_VOL_LIMITATION)

#if defined(K086_JLH_2096_V001)
#undef MAX_VOL
#define MAX_VOL VOLUME_DEFUALT
#define VOL_LIMIT VOLUME_DEFUALT
#elif defined(K000_AOKAILIN_G01_V001)||defined(K000_AOKAILIN_537B_V001)||defined(K000_AOKAILIN_535B_V001)

#define VOL_LIMIT 	MAX_VOL	//4 不限制音量
#elif defined(K000_JLH_2402_V001)
#undef MAX_VOL_SHOW
#define MAX_VOL_SHOW	25

#undef MAX_VOL
#define MAX_VOL MAX_VOL_SHOW
#define VOL_LIMIT 25
#else
#undef MAX_VOL
#define MAX_VOL MAX_VOL_SHOW
#define VOL_LIMIT 28
#endif

#elif defined(CUSTOM_VOL_LIMIT_AT_VOL_DEF)
#undef MAX_VOL
#define MAX_VOL 		MAX_VOL_SHOW
#define VOL_LIMIT 	VOLUME_DEFUALT
#elif defined(USE_VOL_LIMTATION)
#undef MAX_VOL
#define MAX_VOL MAX_VOL_SHOW
#define VOL_LIMIT 28
#elif defined(USE_VOL_LIMTATION_AT_25)
#undef MAX_VOL
#define MAX_VOL MAX_VOL_SHOW
#define VOL_LIMIT 25
#elif defined(VOLUME_CUSTOMER_DEFINE)||defined(VOLUME_CUSTOMER_DEFINE_1)
#undef MAX_VOL
#define MAX_VOL MAX_VOL_SHOW
#define VOL_LIMIT 30
#elif defined(NEW_CUSTOMED_VOLUME_DIVIDED_METHOD)
#undef MAX_VOL
#define MAX_VOL MAX_VOL_SHOW
#define VOL_LIMIT 28
#elif defined(VOLUME_CUSTOMER_DEFINE_16)
#undef MAX_VOL
#define MAX_VOL MAX_VOL_SHOW
#define VOL_LIMIT 28
#elif defined(VOLUME_CUSTOMER_DEFINE_63)
#undef MAX_VOL
#define MAX_VOL MAX_VOL_SHOW
#define VOL_LIMIT 28
#else
#define VOL_LIMIT MAX_VOL	//4 不限制音量
#define MAX_VOL_SHOW MAX_VOL
#endif

#endif
