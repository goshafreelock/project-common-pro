#include "Custom_config.h"
#if defined(FM_USE_KT0913)

#include "typedef.h"

//#define LONG_ANTENNA				// Turn on only if the length of antenna exceeds 2m
#define SEEK_WITH_SNR				// Turn on only if SNR double check is required in SEEK process
//#define DISABLE_FAST_GAIN_UP
//#define LOWFM_MODE
//#define MANUAL_SEPARATION				 
//#define AM_SOFTMUTE
//#define FM_SOFTMUTE
//#define AM_GAIN
//#define AUDIO_LEVEL_BOOST
//#define FM_HIGHLEVER_RF_SIGAL_INPUT
//#define AM_ABC
//#define AM_SOFTMUTE_AFCMODE

#define KT0913_CHIP_ID		0x4B54
#define KT0913
//#define KT0915

//#define X32P768K					//32.768KHz crystal
#define R32P768K					//32.768KHz reference clock
//#define X38K						//38KHz crystal
//#define R38K						//38KHz reference clock
//#define R7P6M						//7.6MHz reference clock
//#define R12M						//12MHz reference clock
//#define R13M						//13MHz reference clock
//#define R24M						//24MHz reference clock
//#define R26M						//26MHz reference clock
//#define R12288KHz					//12.288MHz reference clock

#ifdef X32P768K
	//#define C32P768K
#endif
#ifdef R32P768K
	//#define C32P768K
#endif

#define KTAMw_address 	0x6A
#define KTAMr_address 	0x6B

#define MW_MODE 2
#define FM_MODE 1
#define SW_MODE 0
#define INIT_FAIL_TH 3
#define SEEK_UP_LIMIT 10800
#define SEEK_DOWN_LIMIT 8600
#define MW_SEEK_UP_LIMIT 1710
#define MW_SEEK_DOWN_LIMIT 504
#define SW_SEEK_UP_LIMIT 32000
#define SW_SEEK_DOWN_LIMIT 2000
#define SEEKUP 1
#define SEEKDOWN 0
#define CHANNEL_STEP 10
#define MW_CHANNEL_STEP 9
#define SW_CHANNEL_STEP 1
#define FM_AFCTH_PREV 0			//Range from 0 to 127
#define FM_AFCTH 15				//Range from 0 to 127
#define FM_AFCTH_NEXT 0			//Range from 0 to 127
#define TST_TH 0x2800
#define FM_SNR_TH 0x40
#define AM_AFCTH_PREV 6			//Range from 128 to 127
#define AM_AFCTH 4				//Range from 128 to 127
#define AM_AFCTH_NEXT 6			//Range from 128 to 127
#define AM_TUNING_LIGHT_TH 30
#define SEPARATION_POINT -91
#define BLEND_POINT -97

u16 KT_AMFM_Read_ID();
u8 KT_AMFMPreInit(void);
u8 KT_AMFMInit(void);
u8 KT_AMFMStandby(void);
u8 KT_AMFMWakeUp(void);
u8 KT_AMFMVolumeSet(u8 vol);
u8 KT_AMFMMute(void);
u8 KT_AMFMUnMute(void);
u8 KT_AMFMSetMode(u8 AMFM_MODE);
u8 KT_AMSetBW(u8 AMBW);
u8 KT_SWTune(u16 Frequency);
u8 KT_MWTune(u16 Frequency);
u8 KT_FMTune(u16 Frequency);
u8 KT_AMReadRSSI(char *RSSI);
u8 KT_FMReadRSSI(char *RSSI);
char KT_FMGetAFC(void);
char KT_AMGetAFC(void);
u8 KT_FMSeekFromCurrentCh(u16 seekDir, u16 *Frequency);
u8 KT_MWSeekFromCurrentCh(u16 seekDir, u16 *Frequency);
u8 KT_SWSeekFromCurrentCh(u16 seekDir, u16 *Frequency);

u8 KT_AMValidStation(u16 Frequency);
u8 KT_FMValidStation(u16 Frequency);
u16 KT_AMGetFreq(void);
u16 KT_FMGetFreq(void);
u8 KT_FMGetST(void);
u8 KT_FMGetSNR(void);
void KT_Mute_Ctrl(bool m_f);

#ifdef AM_SOFTMUTE
void KT_AM_SOFTMUTE(u16 Frequency);
void KT_AM_SOFTMUTE_SETTING(u8 SMUTEA, u8 SMUTER, u8 AM_SMTH, u8 VOLUMET);
#endif

#ifdef FM_SOFTMUTE
void KT_FM_SOFTMUTE(u16 Frequency);
void KT_FM_SOFTMUTE_SETTING(u8 SMUTEA, u8 SMUTER, u8 FM_SMTH, u8 VOLUMET);
#endif

bit KT_AM_TUNING_LIGHT(void);
bit KT_FM_TUNING_LIGHT(void);
bit KT_FM_ST_Indicator(void);

#ifdef AM_SOFTMUTE_AFCMODE
//void KT_AM_SOFTMUTE_AFCMODE(bit Valid);
void KT_AM_SOFTMUTE_AFCMODE(void);
void KT_AM_AFC_VolumeSet(u8 afc);			//Input: 0~128
#endif

void KT_Bus_Write(u8 Register_Address, u16 Word_Data);
u16 KT_Bus_Read(u8 Register_Address);
#endif
