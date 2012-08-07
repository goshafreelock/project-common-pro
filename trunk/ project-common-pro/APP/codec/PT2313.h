#include "Custom_config.h"

#ifndef _PT2313_H_
#define _PT2313_H_


///#define SOUND_EFFECT_USE_EPPROM
//#define USE_FRONT_CHANNEL
#define USE_REAR_CHANNEL
//*************************************************AUDIO
#define	PT_2313_ADDR			0X88
#define	PT_MAIN_VOL_ADDR		0X00

#define	PT_SPK_L_ADDR			0X80
#define	PT_SPK_R_ADDR			0XA0
#define	PT_REAR_L_ADDR		0XC0
#define	PT_REAR_R_ADDR		0XE0

#define	PT_PATH_ADDR			0x40
#define	PT_LOUDNESS_ADDR		0X04

enum
{
#if defined(K0000_BT_CHT909_V001)||defined(K0000_BT_CHT909_V002)||defined(K0000_BT_CHT909_V003)
    AUX_CHAN=0,
    MP3_CHAN,
    FM_CHAN,
#else
    MP3_CHAN =0,
    FM_CHAN,
    AUX_CHAN,
#endif

};
enum
{
    PT_MUTE =0,
    PT_UNMUTE,
};
#define	PT_BASS_ADDR			0X60
#define	PT_TRABLE_ADDR		0X70

#define	PT_BAL_R_ADDR			PT_SPK_R_ADDR
#define	PT_BAL_L_ADDR			PT_SPK_L_ADDR

#define	PT_TABLE_MAX			14		

typedef enum
{
    CHAN_ADJ,
    MUTE_ADJ,
    VOL_ADJ,
    FADE_ADJ,
    BAL_ADJ,
    BASS_ADJ,
    TRELBE_ADJ,
    EQ_ADJ,
    LOUD_ADJ,
}PT2313_CTRL;

typedef enum
{
    CONFIG_BAS=1,    
    CONFIG_TRE,
    CONFIG_BAL,
    CONFIG_FAD,
    CONFIG_VOL,    
    CONFIG_EQ,
    CONFIG_LUD,        
}PT2313_CONFIG;

typedef enum
{
	PT_UP = 1,
	PT_DW,	
	
}PT_CTRL_CMD;

void PT2313_Config(u8 PT_PARA,PT2313_CTRL PT_CMD);
void PT2313_Init(void);
//bool get_pt_2313_londness_flag();

#endif
