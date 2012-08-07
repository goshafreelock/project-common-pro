/*********************************************************************
@Filename: KT0830EG.h
@Function: 
@Author:
@Data:2011-04-10
**********************************************************************/
#ifndef _KT_0830_H_
#define _KT_0830_H_


#include "typedef.h"
#include "Custom_config.h"

#if defined(FM_USE_KT0830EG)

#define SEEK_WITH_SNR				// Turn on only if SNR double check is required in SEEK process	
#define AUDIO_LEVEL_BOOST

#define KT0830EG


#define KTFMw_address 	0x6E
#define KTFMr_address 	0x6F

#define IND_MATCH  		90				// Unit is nH
#define CEXT_MATCH 		13000			// Unit if fF
#define INDUCTOR_Q 		1				// 3 for highest Q;0 for lowest Q
#define INIT_FAIL_TH 	3
#define SEEK_UP_LIMIT 	10800
#define SEEK_DOWN_LIMIT 8700
#define LONG_ANT 		1
#define SHORT_ANT 		0
#define CHANNEL_STEP 	10
#define AFCTH_PREV 		10//5				  Range from 0 to 127越大搜台越少
#define AFCTH 			15					//4 Range from 0 to 127越大搜台越多
#define AFCTH_NEXT 		10//5				// Range from 0 to 127越大搜台越少
#define TST_TH 			0x4f00
#define SNR_TH 			0x28		//4越大搜台越少  >0x28

#ifdef __C51__
void KT_FMStandby(void);
void KT_FMWakeUp(void);
void KT_FMMute(bit flag);
void KT_FMTune(u16 Frequency);//, bit flag);
void KT_FMReadRSSI(char *RSSI);
void KT_FMAntTuneOn(void);
u8 KT_FMGetSNR(void);
void KT_FMSetAntType(u8 ant_type);

bool KT0830EG_ValidStop(u16 Frequency) ;
void KT0830EG_PowerOFF(void);
u16 KT0830EG_ChipID(void);
u8 KT_FMInit(void);
#endif
#endif

#endif
