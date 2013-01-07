/************************************************************
*	SYSTEM GLOBAL OPTIONS
*************************************************************/
//#define USE_AUTO_FREQ
//#define AC209_28PIN		//28 PIN IC GPIO CONFIG

//#define SYS_CRYSTAL_USE_24M
//#define SYS_CRYSTAL_USE_12M

//#define USE_LONG_PLAY_KEY_TO_SWITCH_MODE

//#define USE_SYS_MODE_RECOVER		//系统上电模式记忆功能

//#define USE_BAT_MANAGEMENT

//#define OTP_MUSIC_FUNC_ENABLE

//#define VOLUME_CUSTOMER_DEFINE

//#define KEY_100_ENABLE

//#define NO_VOLUME_LIMITE

//#define VOLUME_DEFUALT 	0
/************************************************************
*	GPIO CTRL  OPTIONS
*************************************************************/
//#define ADKEY_NEW_METHOD

//#define EXTENDED_ADKEY_NUM

//#define TWO_ADKEY_ENABLE

//#define _KEY_TONE_ENABEL_

//#define USE_POWER_KEY

//#define INDEPENDENT_VOLUME_KEY

//#define  IR_MUTE_USE_NORMAL

/************************************************************
*	GPIO CTRL  OPTIONS
*************************************************************/
/*UART PORT ENABLE DEFINE*/
//#define   UART_ENABLE
#ifdef UART_ENABLE
#define UART_ENABLE_MAIN_FLOW

//#define UART_ENABLE_FM
//#define UART_ENABLE_RTC
//#define UART_ENABLE_EEPROM
//#define UART_ENABLE_PT2313
#define UART_ENABLE_M62429

#define 	_USE_UART_P2_
//#define _USE_UART_P0_
#endif

#define KPL_MSG_COMPATIBLE

//#define TURN_ON_PLAY_BREAK_POINT_MEM
#define EEPROM_RTC_RAM_COMPATIBLE

/*MUTE PORT DEFINE*/
#define	MUTE_PORT_USE_P01
//#define   MUTE_PORT_USE_P00
//#define MUTE_PORT_USE_P03
#define MUTE_CTRL_LEVEL_NORMAL
#define LED_CTRL_LEVEL_NORMAL

#define IIC_GPIO_USE_P02_P03	//4 Default IIC GPIO
//#define IIC_GPIO_USE_P00_P01

//#define ADKEY_USE_P07_PORT

/*PLAY STATUS LED PORT DEFINE*/
//#define PLAY_STATUS_LED_P07
//#define PLAY_STATUS_LED_P27
//DEFAULT GPIO P07

//#define USE_ADKEY_FOR_AUX_HP_DETECTION
//#define USE_GPIO_DETECT_EARPHONE_PLUGGED
//#define LINE_IN_DETECT_SHARE_LED_STATUS_PORT

/************************************************************
*	AUDIO DECODE  OPTIONS
*************************************************************/
//#define USB_SD_PLAY_INFO_DIV

#define USE_USB_AUDIO

//#define FF_FR_TURN_ON_MUSIC

//#define DECODE_STOP_MODE_ENABLE

//#define PLAY_MODE_MEM_RECOVER	//播放模式记忆功能
/************************************************************
*	FM REV OPTIONS
*************************************************************/
#define USE_RDAs_FM
#define USE_BK1080_FM
//#define USE_CL6017G_FM
//#define USE_SP3777_FM
#define USE_QN8035_FM
//#define FM_USE_KT0830EG
//#define FM_USE_KT0913
//#define FM_USE_AR1015
//#define FM_USE_KT0913
//#define FM_USE_BK1086
//#define USE_CL5767_FM

//#define RADIO_AM_WM_ENABLE

//#define USE_FM_GPIO

/*FM CRYSTAL DEFINE*/
//#define          _SHARE_CRYSTAL_24MHz_   	//共用24MHz晶振，请打开此宏
//#define       _SHARE_CRYSTAL_12MHz_   	//共用12MHz晶振，请打开此宏
//#define       _SHARE_CRYSTAL_32KHz_   	//4共用32KHz晶振，请打开此宏
//#define       FM_STEP_50K           		//50K步进，请打开此宏

//#define RADIO_AM_WM_ENABLE
//#define KEEP_SILENT_WHEN_SCAN_CHANNEL

//#define ADKEY_PLAY_SHORT_SCAN_FRE
//#define SEMI_AUTO_SCAN_FREQ	//半自动搜台

//#define IR_PLAY_KEY_SCAN_FREQ_DISABLE
//#define IR_NEXT_PREV_SHORT_AUTO_SCAN
//#define IR_NEXT_PREV_SHORT_ADJ_CH
//#define IR_NEXT_PREV_HOLD_AUTO_SCAN

//#define ADKEY_NEXT_ADJST_FREQ
//#define ADKEY_NEXT_PREV_SHORT_ADJ_CH
//#define ADKEY_NEXT_PREV_HOLD_AUTO_SCAN

//#define FM_TRANSMITTER
/************************************************************
*	AUX  OPTIONS
*************************************************************/
//#define EXCHANGE_LINE_IN_CHANNEL	//交换LINE IN 通道

//#define USE_MANUAL_IDLE_FUNC		//手动切换到IDLE

//#define NOT_USE_LINE_IN_FUNC	//打开此宏来关闭AUX功能

//#define USE_LINE_IN_DETECT_FUNC	//打开此宏来启动LINE IN 检测功能

//#define ADC_DETECT_LINE_IN

//#define FM_BY_PASS

//#define LINE_IN_PLAY_KEY_PAUSE

//#define IPONE_INDEPENDENT_MODE

//#define IPONE_DOCK_FUNC_ENABLE

/************************************************************
*	RTC  OPTIONS
*************************************************************/

//#define USE_RTC_RAM_FUNC

//#define USE_RTC_FUNCTION

//#define USE_RTC_TIME_ONLY

//#define USE_RTC_YEAR_FUNCTION

//#define USE_RTC_ALARM_FUNCTION
/************************************************************
*	IR  OPTIONS
*************************************************************/
//#default: IR_USER_CODE_0xFF00

//#define IR_USER_CODE_0x7F80

//#define IR_REMOTER_WITH_POWER_MUTE_PRINT
//#define IR_REMOTER_WITH_CHANEL_SELECT

//#define IR_TYPE_DEFINE	NORMAL

/************************************************************
*	DISPLAY OPTIONS,LED TYPE SELECT
*************************************************************/
//#define DISPLAY_NO_DEV_WHEN_NO_SD_USB

#define LED_GPIO_DRV				//GPIO直接驱动LED
//#define LED_DRV_USE_SM1628		// SM 1628 驱动IC
//#define LCD_GPIO_DRV				//GPIO直接驱动LCD
//#define USE_LCD_DRV_HT1621
//#define USE_LCD_DRV_TM1721

//#define NO_LED_DISPLAY
//#define LED_USE_PLAY_STATUS	//默认LED 模组
//#define LED_USE_PLAY_MODE
//#define LED_USE_PLAY_MODE_MIXED
//#define LED_USE_1X888
//#define LED_USE_ROUND_LED

//#define LED_DRV_IN_COM_CATHODE	//LED 共阴类型
//#define LED_DRV_IN_COM_ANODE		//LED共阳类型

#if 1
/************************************************************
*	OTHER CUSTOMED OPTIONS
*************************************************************/
//#define POWE_KEY_PLAY_KEY_IN_ONE_KEY	//PLAY POWER 共用一个按键
//#define  POWER_KEY_ON_WAIT_FOR_3_SEC
//#define  SYS_GO_IN_IDLE_IN_30_SEC
//#define  GPIO_SWITCH_SELECT_MODE
//#define JOG_STICK_FUNC
//#define NO_ADKEY_FUNC
//#define  USE_AMP_MODE_SELECT
/************************************************************
*	OTHER CUSTOMED OPTIONS  END
*************************************************************/
/**Customer & version **/
#if 0
#define   UART_ENABLE

#define NO_LED_DISPLAY
#define FM_TRANSMITTER
#define IIC_GPIO_USE_P00_P01
#ifdef IIC_GPIO_USE_P02_P03
#undef IIC_GPIO_USE_P02_P03
#endif

#endif
//4 SW 声音级别限制到28
//#define SW_V001		
//#define SW_V002		//4 长按搜索，短按CH
//#define SW_V002_RTC		//4 长按搜索，短按CH
//#define SW_V002_CUSTOMED_V001		//4 长按搜索，短按CH
//#define SW_V002_CUSTOMED_V002
//#define SW_V002_CUSTOMED_V003
//#define SW_V002_747		//4 长按搜索，短按CH
//#define SW_V003_747
//#define K003_V001		//K026_XXX_V001
//#define SW_V007_502K
//#define Kxxx_931_V001
//#define K2116_SW_017KT_V001
//#define K015_SW_005B_V001


//4 按 主板编号定义宏
/***/
//#define K005_987_V001
//#define K009_968_SW006_V001	//(921)
//#define K009_968_MY_1008_V001	//(921)
//#define K009_968_SW006_ZHUOXIN_V001
//#define K010_931_V001
//#define K010_YJH_931_V001
//#define K010_XFW_931_V001
//#define K010_QDX_PM21_V001
//#define K013_980_V001
//#define K015_983_SW005_V001
//#define K015_983_SW005_WQ747_V001
//#define K015_983_SW005_AMFM_V001
//#define K015_983_SW005_ZX_V001
//#define K015_983_JLH_V001
//#define K015_983_JLH_V002
//#define K015_983_JLH_A2016_V001
//#define K015_983_JLH_A2016_V002
//#define K015_983_JLH_SW005D_V001
//#define K015_983_JLH_VOL50_V001
//#define K015_983_SW005_V8
//#define K015_983_1_SW005_V001
//#define K015_983_SW005_ZhuoXin_V001
//#define K015_983_SW005_ZhuoXin_V002
//#define K015_983_SW005_ZhuoXin_KL001_V001
//#define K015_983_SW005_ZhuoXin_KL001_V002
//#define K015_983_SW005_ZhuoXin_FB001_V001
//#define K015_983_SW005_ZhuoXin_KL002_V001
//#define K015_983_SW005_ZhuoXin_JR001_V001
//#define K002_SW_002_Zhuoxin_V001
//#define K031_XXX_V001
//#define K020_WEIQI_V001
//#define K021_XXX_V001
//#define K023_971_V001
//#define K011_011_V001
//#define K025_XXX_V001
//#define K080_YJH_985_V001
//#define K081_YJH_973_V001
//#define K026_XXX_V001
//#define K037_XXX_V001
//#define K077_BoDa_V001
//#define K085_YJH_085_V001
//#define K063_YJH_063_V001
//#define K116_FXK_V001
//#define K005_987_FOR_JLH_V001
//#define K101_TianCheng_101_V001
//#define K128_YJH_128_V001
//#define K133_QDX_133_V001
//#define K162_QDX_162_V001
//#define K105_SWD_2901_V001
//#define K105_SWD_2901A_V001
//#define K122_SWD_122_V001
//#define K196_MN_196_V001
//#define K180_LY_180_V001
//#define K181_LY_181_V001
//#define K181_YJH_181_V001
//#define K186_ZHHB_S30_V001
//#define K186_LM_186_V001
//#define K189_JM_201_V001
//#define K000_RS_228U_V001
//****************#define K208_ZY_KL208_V001
//#define K171_YJH_171_V001
//#define K171_SW_012_V001
//#define K171_ZX_SW012_ET1013FM_V001
//#define K171_LanQin_012_V001
//#define K171_LT_171_V001
//#define K170_ZHUOXIN_UK3_V001
//#define K170_ZK_170_V001
//#define K170_YJH_170_V001
//#define K170_LanQin_170_V001
//#define K170_YDS_170_V001
//#define K170_QDX_170_V001
//#define K170_QDX_PM_A01_V001
//#define K170_HAO_SHENG_170_V001
//#define K015_JLH_2946_V001
//#define K610_YJH_803_V001
//#define K619_FXK_619_V001
//#define K223_BTL_CP153_V001
//#define K305_ZhuoXin_305_V001
//#define K000_Zhongwei_SP_016_V001
//#define K307_ZX_307_V001
//#define K637_ZX_306_V001
//#define K643_FW_643_V001
//#define K532_YJH_532_V001
//#define K272_JH_272_V001
//#define K646_ZhuoXing_308_V001
//#define K523_DeYun_523_V001
//#define K202_JiaMei_202_V001
//#define K316_ZhuoXing_316_V001
//#define K317_ZhuoXing_317_V001
//#define K316_MONO_316_V001
//#define K704_JM_502_V001
//#define K704_JM_503_V001
//#define K709_AOKAILIN_709_V001
//#define K572_AOKAILIN_811_V001
//#define K573_AOKAILIN_812_V001
//#define K686_ZhengYang_686_V001
//#define K812_DingChuangXin_D903_V001
//#define K801_DingChuangXin_801_V001
//#define K668_YJH_815_V001
//#define K693_YJH_693_V001
//#define K719_YJH_719_V001
//#define K716_RiYueTong_716_V001
//#define K321_Zhuoxing_321_LED_V001
//#define K321_Zhuoxing_321_LCD_V001
//#define K720_YJH_720_V001
//#define K723_LUOMAO_723_V001
//#define K728_SUOERSI_728_V001
//#define K737_JinYiHeLi_737_V001
//#define K756_JinYiHeLi_756_V001
//#define K1007_JinYiHeLi_1007_V001
//#define K000_JLH_309F_V001
//#define K731_YJH_731_V001
//#define K731_YJH_820_V001
//#define K733_JM_733_V001
///////////////////////////////////#define K585_YJH_585_V001
//#define K586_DCX_586_V001
//#define K565_FXK_565_V001
//#define K566_JinRui_566_V001
//#define K566_JLH_566_V001
//#define K566_SWD_566_V001
//#define K565_JLH_565_V001
//#define K568_JinRui_568_V001
//#define K568_ZX_568_V001
//#define K568_ZX_568_V002
//#define K000_ZhuoYue_003_V001
//#define K739_YJH_739_V001
//#define K760_YJH_760_V001
//#define K745_SUOERSI_745_V001
//#define K591_JiaLe_591_V001
//#define K592_YJH_592_V001
//#define K593_YJH_593_V001
//#define K000_AOKAILIN_G01_V001
//#define K000_AOKAILIN_508_V001
//#define K000_XingChuang_x819_V001
//#define K000_XingChuang_x821_V001
//#define K000_XingChuang_x821_V002
//#define K000_XingChuang_x821_V003
//#define K000_XingChuang_x832_V001
//#define K000_XC_BC_BT_V001
//#define K000_KT_AMFM_V001
//#define K766_YJH_766_V001
//#define K771_YJH_771_V001
//#define K762_JinYiHeLi_762_V001
//#define K763_JinYiHeLi_763_V001
//#define K769_JinRui_769_V001
//#define K769_JinRui_769_V002
//#define K000_HG_898_V001
//#define K777_SW_777_V001
//#define K807_YJH_807_V001
//#define K779_YJH_779_V001
//#define K773_MingYang_773_V001
//#define K714_FW_016A_V001
//#define K791_YJH_791_V001
//#define K815_FW_815_V001
//#define K795_JinYeHeLi_795_V001
//#define K796_JinYeHeLi_796_V001 
//#define K820_LHD_820_V001
//#define K000_AOKAILIN_537B_V001
//#define K000_AOKAILIN_535B_V001
//#define K000_XINGLEI_2092_V001
//#define K1026_YJH_1026_V001
//#define K1022_WXD_1322_V001
//#define K1025_AIPU_1025_V001
//#define K1029_JINYI_1029_V001
//#define K1028_WOKA_1028_APPLE_V001
//#define K000_JLH_2402_V001
//#define K2018_JINRUI_2018_V001
//#define K000_XinLei_LC2092_V001
//#define K000_XinLei_LC2092_V002
//#define K000_XinLei_LC2092_V003
//#define K000_XinLei_LC2092_V004
//#define K000_XinLei_LC2092_V005
//#define K000_XinLei_LC2092_V006
//#define K000_XinLei_LC2092_V005_A8B
//#define K0000_XL_A2_V001
//#define K1032_JIAMEI_1032_V001
//#define K1032_YJH_1032_V001
//#define K1032_HF_1032_V001
//#define K1032_AJE_1032_V001
//#define K1032_AJE_LS094_V001
//#define K1032_WK_1032_V001
//#define K1032_ZHONGKAI_1032_V001
//#define K1032_AP_1032_V001
//#define K1032_YHD_005_V001
//#define K1051_JIAMEI_1051_V001
//#define K1051_JIAMEI_1051C_V001
//#define K1058_ZX_1058_V001
//#define K1009_DCX_915_V001
//#define K2035_SES_2035_V001
//#define K2035_SES_2035_V002
//#define K1055_HSL_1055_V001
//#define K1069_ZK_982_V001
//#define K1069_AJE_1069_V001
//#define K1069_AJE_1069_V002
//#define K2038_DCX_2038_V001
//#define K1079_BHT_1079_V001
//#define K000_JLH_938_V001
//#define K1078_ZK_1078_V001
//#define K2041_XFW_2041_V001
//#define K2041_XFW_2041_V002
//#define K000_JR_210_V001
//#define K1091_XFW_1091_V001
//#define K1097_WK_1097_V001
//#define K2044_YJH_2044_V001
//#define K2044_JM_850_V001
//#define K2044_ZX_2044_V001
//#define K2045_AJR_2045_V001
//#define K0000_XFW_FW_29_V001
//#define K1100_JY_1100_V001
//#define K0000_MC_Q16A_V001
//#define K0000_MC_DYJ_V001
//#define K0000_MC_M73A_V001
//#define K0000_MC_H2_V001
//#define K0000_MC_L2A_V001
//#define K0000_MC_Q18A_V001
//#define K0000_MC_Q18A_V002
//#define K0000_MC_Q21_V001
//#define K0000_MC_TK19_V001
//#define K0000_MC_AP16_V001
//#define K0000_MC_FMC3_V001
//#define K0000_MC_K16_V001
//#define K0000_MC_K16_V002
//#define K1107_DCX_991_V001
//#define K0000_XXX_SX_V001
//#define K1111_SES_1111_V001
//#define K1111_YHD_Y882_V001
//#define K1203_SES_A26_V001
//#define K1111_ZK_1111_V001
//#define K1115_WXD_1115_V001
//#define K1102_JM_836_V001
//#define K2056_AJE_2056_V001
//#define K1116_WXD_1116_V001/
//#define K1118_YJH_1118_V001
//#define K0000_WK_S638_V001
//#define K1119_LS_1119_V001
//#define K0000_SRS_6032_V001
//#define K0000_SW_6032_V001
//#define K0000_SRS_6032_V002
//#define K0000_XDS_6032_V002
//#define K1123_WXD_1123_V001
//#define K2321_JM_2321_V001
//#define K0000_ZHIXING_00XX_V001
//#define K0000_KDL_6032_V001
//#define K1132_ZK_963_V001
//#define K0000_BT_CHT909_V001
//#define K0000_BT_CHT909_V002
//#define K0000_BT_CHT909_V003
//#define K1135_HF_1135_V001
//#define K3015_XFW_931_V001
//#define K1154_YJH_1154_V001
//#define K1154_YJH_858_V001
//#define K1154_YJH_858_V002
//#define K1154_YJH_858_V003
//#define K1154_WXD_62_V001
//#define K1154_ZK_858_V001
//#define K1154_HF_054_V001
//#define K1144_DCX_956_V001
//#define K1140_AJR_1140_V001
//#define K2056_AJR_2056_V001
//#define K2067_JGY_2067_V001
//#define K0000_GW_118B_V001
//#define K0000_GW_ZX015_V001
//#define K0000_GW_238_V001
//#define K0000_GW_168C_V001
//#define K1143_DCX_D953_V001
//#define K1147_DCX_D955_V001
//#define K1147_JLH_1234_V001
//#define K0000_JK_TEMP_FAN_V001
//#define K0000_JK_PORTABLE_CHARGER_V001
//#define K0000_JK_KHT_842_BT_V001
//#define K0000_JK_KHT_830D_V001
//#define K0000_JK_KHT_830E_V001
//#define K5008_JK_5008_V001
//#define K5068_JK_5068_V001
//#define K5058_JK_5058_V001
//#define K5038_JK_5038_V001
//#define K5018_JK_5018_V001
//#define K0000_ZG_BT260_V001
//#define K0000_XP_TN891_V001
//#define K0000_XP_TN891_V002
//#define K1159_DCX_D962_V001
//#define K2078_MY_2078_V001
//#define K1157_ZK_ALK933_V001
//#define K1161_ZK_ALK935_V001
//#define K1161_YJH_1161_V001
//#define K1161_YJH_1161_V002
//#define K1161_YJH_861_V001
//#define K1161_YHD_839_V001
//#define K1161_YHD_888_V001
//#define K1161_HF_ADA8_V001
//#define K1165_YHD_Y002_V001
//#define K1168_YHD_Y003_V001
//#define K1164_YDT_1164_V001
//#define K1150_LS_1150_V001
//#define K2083_KPL_2083_V001
//#define K2083_KPL_2083_V002
//#define K2083_KPL_2083_V003
//#define K2083_SW_2083_V001
//#define K2083_SW_2083_V002
//#define K1166_ZK_ALK980_V001
//#define K1166_JM_YT_V001
//#define K1166_FW_16_V001
//#define K1166_FW_16_V002
//#define K1166_YJH_1234_V001
//#define K1167_ZK_ALK967_V001
//#define K1169_ZK_ALK982_V001
//#define K1173_ZK_ALK936_V001
//#define K1174_SES_2012_V001
//#define K1204_SES_2012_V001
//#define K2086_AJR_LS091_V001
//#define K2094_DYT_2094_V001
//#define K2094_DYT_2094_V002
//#define K1177_HF_BJD_V3_V001
//#define K6037_SES_6037_V001
//#define K2059_SES_6038_V001
//#define K1182_YJH_1182_V001
//#define K1182_YJH_867_V001
//#define K1182_YL_1182_V001
//#define K1182_ZK_1182_V001
//#define K1182_ZK_985B_V002
//#define K1186_YJH_1186_V001
//#define K1186_YJH_866_V001
//#define K1186_ZK_990_V001
//#define K3021_AP_LG836_V001
//#define K0000_MY_FT18_BT_V001
//#define K0000_MY_FT18_V001
//#define K3025_YL_3025_V001
//#define K1195_YJH_11830_V001
//#define K1197_DCX_855_V001
//#define K1197_JM_4444_V001
//#define K1197_DCX_893_V001
//#define K1197_LS_L10A_V001
//#define K1197_KM_855_V001
//#define K1197_AJR_855_V001
//#define K0000_KM_LBJN_V001
//#define K0000_HF_6001_V001
//#define K2121_WXD_2121_V001
//#define K1224_YJH_1224_V001
//#define K1224_ALK_510_V001
//#define K1229_WXD_1229_V001
//#define K3031_AP_668_V001
//#define K2131_AJR_1234_V001
//#define K2136_ZX_1234_V001
//#define K1247_YHD_Y900_V001
//#define K4006_SES_4321_V001
//#define K2091_YJH_863_V001
//#define K1258_WXD_1258_V001
//#define K4009_MY_1258_V001
//#define K4010_MY_1258_V001
//#define K2150_HF_1234_V001
//#define K4005_AJR_105_V001
//#define K2081_DM_007_V001








/************************************************************
*	28PIN BOARD DEFINE
************************************************************/
//#define K088_JLH_23108_V001
//#define K113_SW_113_V001
//#define K115_SW_115_V001
//#define K163_ZHHB_163_V001
//#define K169_KR_169_V001
//#define K188_YJH_188_V001
//#define K188_YJH_188_V002
//#define K188_YJH_188_V003	//FOR YJH  JIELONG
//#define K188_YJH_188_V004
//#define K139_JLH_xxx_V001
//#define K139_FuWei_xxx_V001
//#define K139_YDS_xxx_V001
//#define K000_DT_078_V001
//#define K109_SW001D_V001
//#define K198_SW198_V001
//#define K608_TC_608_V001
//#define K608_TC_608_V002
//#define K801_TC_801_V001
//#define K801_TC_801_V001_XC
//#define K801_TC_801_V002
//#define K801_TC_801_V003
//#define K987_YJH_987_V001
//#define K172_AJE_172_V001
//#define K200_KY_021_V001
//#define K209_WS_GKD209_V001
//#define K202_WS_01_V001
//#define K202_WEISI_KL202_V001
//#define K609_KL_609_V001
//#define K505_CJB_505_V001
//#define K507_YJH_507_V001
//#define K617_LHGC_617_V001
//#define K627_LHGC_627_V001
//#define K639_YJH_639_V001
//#define K519_DCX_880_V001
//#define K519_YHD_880_V001
//#define K519_YJH_808_V001
//#define K519_YJH_808_V002
//#define K519_YHD_801D_V002
//#define K232_GKD_232_V001
//#define K525_DeYun_525_V001
//#define K667_YJH_667_V001
//#define K302_ZhengYang_ZY302_V001
//#define K071_ZhengYang_ZY071_V001
//#define K676_FXK_676_V001
//#define K555_FXK_555_V001
//#define K703_JM_YX006_V001
//#define K711_JM_YX450_V001
//#define K711_JM_836_V001
//#define K711_JM_KSM_V001
//#define K705_YJH_705_V001
//#define K679_YJH_679_V001
//#define K560_YJH_560_V001
//#define K710_AoKaiLin_710_V001
//#define K811_DingChuangXin_811_V001
//#define K692_YHD_832_V001
//#define K692_SES_692_V001
//#define K695_SES_695_V001
//#define K120_YJH_120_V001
//#define K120_SW_015_V001
//#define K562_QDX_562_V001
//#define K800_MingYang_800_V001
//////////#define K319_ZhuoXing_319_V001
//#define K320_ZhuoXing_320_V001
//#define K722_YJH_722_V001
//#define K806_LiHaoDe_806_V001
//#define K727_LiHaoDe_727_V001
//#define K583_ZX_583_V001
/////#define K586_LHD_LT30_V001
//#define K738_LHD_LTB1_V001
//#define K740_LHD_916_V001
//#define K000_XingChuang_X816_V001
//#define K000_XingChuang_X824_V001
//#define K000_XingChuang_X831_V001
//#define K000_XingChuang_YQ001_V001
//#define K736_TaiYangSheng_736_V001
//#define K589_JYHL_589_V001
//#define K746_JIALE_746_V001
//#define K755_JinYeHeLi_755_V001
//#define K755_AnJieEr_755_V001
//#define K765_YJH_765_V001
//#define K598_YJH_598_V001
//#define K599_JinRui_599_V001
//#define K770_JinRui_770_V001
//#define K000_MingYang_1003A_V001
//#define K086_JLH_2096_V001
//#define K776_CaiRun_776_V001
//#define K783_JinYeHeLi_783_V001
//#define K535_DingChuangXin_803E_V001
//#define K535_DingChuangXin_803E_2_V001
//#define K535_DingChuangXin_803E_3_V001
//#define K1019_DingChuangXin_D806_V001
//#define K735_JIAMEI_JM007_V001
//#define K2023_JIELONG_2023_V001
//#define K000_TIANYUN_2096_V001
//#define K1031_DingChuangXin_808_V001
//#define K1031_YHD_910_V001
//#define K1037_JinRUI_1037_V001
//#define K2012_MY_M90_V001
//#define K1053_YJH_1053_V001
//#define K1056_SUOERSI_1056_V001
//#define K1057_SUOERSI_1057_V001
//#define K1072_SUOERSI_1072_V001
//#define K1073_SUOERSI_1073_V001
//#define K000_QY_200_V001
//#define K1076_DCX_801C_V001
//#define K2036_WK_2036_V001
//#define K1067_MY_1067_V001
//#define K2039_LHGC_2039_V001
//#define K000_TC_901_V001
//#define K000_TC_3006_V001
//#define K2048_WK_2048_V001
//#define K1101_JY_1101_V001
//#define K0000_AKL_522_V001
//#define K0000_GW_300G_V001
//#define K0000_GW_138B_V001
//#define K3002_WXS_K6_V001
//#define K0000_UST_U51_V001
//#define K0000_MC_A6B_V001
//#define K0000_MC_TYM1_V001
//#define K1129_ZK_962_V001
//#define K0000_YH_082_V001
//#define K1138_ZK_966_V001
//#define K1146_ZK_968_V001
//#define K1106_SD_1106_V001
//#define K000_QG_Q6_V001
//#define K1149_AJR_LSV8_V001
//#define K1162_AJR_1162_V001
//#define K1162_DCX_1162_V001
//#define K2070_YJH_2070_V001
//#define K000_SLAVE_V001
//#define K0000_JK_QGAC18_V001
//#define K1301_JK_1301_V001
//#define K000_ZG_HA8918_NOR_V001
//#define K000_ZG_HA8919_BT_V001
//#define K000_JK_BTONLY_V001
//#define K000_JK_LBR_BT_V001
//#define K000_JK_ZHCX_V001
//#define K000_JK_HY_SM001_V001
//#define K000_JK_HY_WM2428B_V001
//#define K1163_DYT_1163_V001
//#define K0000_XC_X813_V001
//#define K2084_BY_S14_V001
//#define K2082_HF_2082_V001
//#define K1176_LS_1176_V001
//#define K1172_ALK_969B_V001
//#define K1172_DCX_D968_V001
//#define K000_XFW_GL005_V001
//#define K3018_AP_751_V001
//#define K1226_AP_750_V001
//#define K2125_AP_751C_V001
//#define K0000_JGY_SXXX_V001
//#define K1188_ZX_1188_V001
//#define K1192_FW_60_V001
//#define K1196_YHD_852_V001
//#define K2110_YHD_856_V001
//#define K2114_XFW_FW70_V001
//#define K1222_WXD_1222_V001
//#define K401_KM_401_V001
//#define K2129_WXD_1234_V001
//#define K1251_YHD_Y902_V001
//#define K1BBB_YHD_Y909_V001
//#define K1254_BHT_1080_V001
//#define K2158_YJH_2158_V001


/*****************测试验证******************/
#if 0
#ifdef IIC_GPIO_USE_P02_P03
#undef IIC_GPIO_USE_P02_P03
#endif
#define IIC_GPIO_USE_P00_P01
#ifdef MUTE_PORT_USE_P01
#undef  MUTE_PORT_USE_P01
#endif
 #define MUTE_PORT_USE_P03

#define ADKEY_NEW_METHOD
#define USE_ADKEY_FOR_AUX_HP_DETECTION
#define USE_ADKEY_DETECT_AUX

#define USE_ADKEY_DETECT_HP

#define USE_LINE_IN_DETECT_FUNC

#define USE_GPIO_DETECT_EARPHONE_PLUGGED

#endif

/*****************按 主板编号定义宏******************/

#ifdef K2081_DM_007_V001

#ifdef IIC_GPIO_USE_P02_P03
#undef IIC_GPIO_USE_P02_P03
#endif

#define IIC_GPIO_USE_P00_P01

#define IR_USER_CODE_0x7F80

#ifdef MUTE_PORT_USE_P01
#undef  MUTE_PORT_USE_P01
#endif
#define MUTE_PORT_USE_P03

#ifdef LED_GPIO_DRV
#undef LED_GPIO_DRV
#endif
#define LED_DRV_USE_SM1628
#define LED_DRV_USE_SM1628_KEY_FUNC
#define CUSTOMER_DEFINED_FUNC_CYCLE
#undef MUTE_CTRL_LEVEL_NORMAL

#define EXCHANGE_LINE_IN_CHANNEL	//交换LINE IN 通道
#define NEW_SD_DETECT_MOD
#define ADKEY_PLAY_SHORT_SCAN_FRE
#define NO_PLAY_STATUS_LED

#define DISP_AUX_STRING

#define JOG_STICK_FUNC
#define SUPPORT_PT2313
#define SUPPORT_M62429
#define GPIO_SEL_M62429_FUNC
#define NO_PT_STR_DISPLAY

#define NO_ADKEY_FUNC
#define INDEPENDENT_VOLUME_KEY
#define LED_DRV_MUTE_ON_FLASH_WHOLE_SCREEN
#define CUSTOM_DEFINED_PT_2313_CONFIG_CYCLE

#define VOLUME_CUSTOMER_DEFINE_63
#define PT_2313_OUT_GAIN_11DB
#define SPECTRUM_FUNC_ENABLE
#define USE_2CH_FUNC
/////////#define USE_SPECTRUM_PARTTERN
#define IR_INFO_EQ_DOWN_SCAN
#define IR_PLAY_KEY_SCAN_FREQ_DISABLE
#define ADKEY_PLAY_SHORT_SCAN_FRE
#define IR_PLAY_KEY_LONG_SCAN_FREQ

#define SEMI_AUTO_SCAN_FREQ
#define ADKEY_NEXT_PREV_HOLD_AUTO_SCAN
#define FM_PATH_SHARE_SAME_MP3_PT_CHAN

#undef USE_QN8035_FM
//#undef USE_BK1080_FM
#endif

#ifdef K4005_AJR_105_V001

#ifdef IIC_GPIO_USE_P02_P03
#undef IIC_GPIO_USE_P02_P03
#endif
#define IIC_GPIO_USE_P00_P01

#ifdef MUTE_PORT_USE_P01
#undef  MUTE_PORT_USE_P01
#endif
#define MUTE_PORT_USE_P03

#define EXTENED_LED_NUM_SCAN

#define EXCHANGE_LINE_IN_CHANNEL	//交换LINE IN 通道

#define CUSTOMER_DEFINED_ADKEY_RESISTOR
#define ADKEY_NEW_METHOD
#define EXTENDED_ADKEY_NUM


#define USE_MODE_LONG_FOR_RTC_SETTING
#define USE_RTC_FUNCTION
#define USE_RTC_TIME_ONLY
#define RTC_SETTING_NO_CYC
#define USE_RTC_ALARM_FUNCTION
#define USE_RTC_ALM_CUSTOM_INIT
#define RTC_SETTING_OP_TIMER_ENABLE
#define DISABLE_P05_OSC_OUTPUT
#define FM_BY_PASS
#if 1
#define USE_POWER_KEY
#define USE_ONLY_POWER_HOLD_CTRL
#define PWR_CTRL_WKUP
#define USE_PWR_KEY_LONG_PWR_ON
#define PWR_ON_DELAY_1_SECOND
#endif

#if 1
#define BLUE_TOOTH_FUNC
#define BLUETOOTH_GPIO_CTRL
#define BT_USE_AUX_1
#define BLUE_TOOTH_NO_SYS_MUTE_CTRL
#define DISP_BLUE_STR
#define BLUE_TOOTH_KEY_DELAY_25MS
#endif

#endif

#ifdef K2150_HF_1234_V001

#ifdef IIC_GPIO_USE_P02_P03
#undef IIC_GPIO_USE_P02_P03
#endif
#define IIC_GPIO_USE_P00_P01

#ifdef MUTE_PORT_USE_P01
#undef  MUTE_PORT_USE_P01
#endif
#define MUTE_PORT_USE_P03

#define LED_USE_PLAY_MODE
#define LED_USE_PLAY_MODE_NORMAL

#define LED_GPIO_PORT_CUSTOMERIZED

#define EXCHANGE_LINE_IN_CHANNEL	//交换LINE IN 通道

#define USE_POWER_KEY_SHORT_SCAN
#define POWE_KEY_PLAY_KEY_IN_ONE_KEY
#define PLAY_MODE_USE_REP_ONE_ALL
#define DISP_OFF_STR_AT_PWR_DOWN
#define DISP_PAU_STRING

#define CUSTOMER_DEFINED_ADKEY_RESISTOR


#define LINE_IN_PLAY_KEY_PAUSE
#define USE_POWER_KEY_FOR_AUX_PLAY
#define DISP_PAUS_STRING
#define USE_IR_POWER_KEY_TO_POWER_OFF
#define DISP_VOL_V_CHAR
#if 1
#define USE_POWER_KEY
#define USE_ONLY_POWER_HOLD_CTRL
#define PWR_CTRL_P02
#define USE_PWR_KEY_LONG_PWR_ON
#define PWR_ON_DELAY_1_SECOND
#endif

#define RADIO_MODE_HOT_KEY_ENABLE

#define USE_LINE_IN_DETECT_FUNC
#define AUX_DETECT_USE_P34

#define USE_BAT_MANAGEMENT
#define BAT_LEVEL_LED_ICON_IND
#define CHARGER_DETECT_INDICATOR
#define CHARGER_DET_USE_P04
#define CHARGER_FLASH_TYPE_2


#define USE_MODE_LONG_FOR_RTC_SETTING
#define USE_RTC_FUNCTION
#define USE_RTC_TIME_ONLY
#define RTC_SETTING_NO_CYC
#define USE_RTC_ALARM_FUNCTION
#define USE_RTC_ALM_CUSTOM_INIT
#define RTC_SETTING_OP_TIMER_ENABLE
#define LOW_VOLT_SPARK_BAT_ICON
#define DEFAULT_GO_TO_TIME_MODE
#if 0 
#undef USE_RDAs_FM
#undef USE_QN8035_FM
#define Lamborghini_voice
#define OTP_MUSIC_FUNC_ENABLE
#endif

#endif


#ifdef K4010_MY_1258_V001

#ifdef LED_GPIO_DRV
#undef LED_GPIO_DRV
#define LCD_GPIO_DRV
#define LCD_SEGMENT_USE_8_SEGS_5_COMS
#define LCD_BACKLIGHT_USE_PORT_P04
#endif

#ifdef IIC_GPIO_USE_P02_P03
#undef IIC_GPIO_USE_P02_P03
#endif

#define IIC_GPIO_USE_P00_P01

#ifdef MUTE_PORT_USE_P01
#undef  MUTE_PORT_USE_P01
#endif
#define MUTE_PORT_USE_P03

#define LED_USE_PLAY_MODE_MIXED

#define USE_GPIO_DETECT_EARPHONE_PLUGGED
#define EARPHONE_DETECT_USE_P01
#define HP_DETECT_SHARE_WITH_IIC_SCL

#define DISP_LINE_STRING
#define DISP_PAUS_STRING
#define LED_GPIO_PORT_CUSTOMERIZED
#define VOLUME_DEFUALT			30

#define EXCHANGE_LINE_IN_CHANNEL	//交换LINE IN 通道
#define NEW_SD_DETECT_MOD
#define SYS_POWER_ON_NODEV_SEL_MODE
#define SYS_POWER_ON_NODEV_SEL_MODE_AT_TIME_MODE
//#define RTC_ALRM_MEM_LAST_WORK_MODE
#define DISP_BACKLIGHT_AUTO_SAVE_POWER

#if 1
#define CUSTOMER_DEFINED_ADKEY_RESISTOR
#define TWO_ADKEY_ENABLE
#define TWO_ADKEY_USE_PORT_P07
#define EXTENDED_ADKEY_NUM
#endif

#if 1
#define USE_POWER_KEY
#define USE_ONLY_POWER_HOLD_CTRL
#define PWR_CTRL_P02
#define USE_PWR_KEY_LONG_PWR_ON
#endif

#define INDEPENDENT_VOLUME_KEY
#define USE_LONG_PLAY_KEY_PLAY_MODE
#define PLAY_MODE_USE_REP_ONE_ALL
#define DEFAULT_GO_TO_TIME_MODE
#define RTC_MODE_HOT_KEY_ENABLE
#define MODE_KEY_LONG_FOR_RTC_HOTKEY

#define USE_PLAY_LONG_FOR_RTC_SETTING
#define USE_RTC_FUNCTION
#define USE_RTC_TIME_ONLY
#define RTC_SETTING_NO_CYC
#define USE_RTC_ALARM_FUNCTION
#define USE_RTC_ALM_CUSTOM_INIT
#define RTC_SETTING_OP_TIMER_ENABLE

#if 1
#define USE_BAT_MANAGEMENT
#define NEW_BAT_ICON_DISP_AT_LEVEL_THREE
#define CHARGER_DETECT_INDICATOR
#define CHARGER_DET_USE_VPP
#define CUSTOM_BAT_ICON_DISP
#endif

#undef USE_RDAs_FM
#endif

#ifdef K4009_MY_1258_V001

#ifdef IIC_GPIO_USE_P02_P03
#undef IIC_GPIO_USE_P02_P03
#endif

#define IIC_GPIO_USE_P00_P01

#ifdef MUTE_PORT_USE_P01
#undef  MUTE_PORT_USE_P01
#endif
#define MUTE_PORT_USE_P03

#define LED_USE_PLAY_MODE_MIXED

#define USE_GPIO_DETECT_EARPHONE_PLUGGED
#define EARPHONE_DETECT_USE_P04

#define LED_GPIO_PORT_CUSTOMERIZED
#define VOLUME_DEFUALT			30

#define EXCHANGE_LINE_IN_CHANNEL	//交换LINE IN 通道
#define NEW_SD_DETECT_MOD
#define SYS_POWER_ON_NODEV_SEL_MODE
#define SYS_POWER_ON_NODEV_SEL_MODE_AT_TIME_MODE
//#define RTC_ALRM_MEM_LAST_WORK_MODE

#if 1
#define CUSTOMER_DEFINED_ADKEY_RESISTOR
#define TWO_ADKEY_ENABLE
#define TWO_ADKEY_USE_PORT_P07
#define EXTENDED_ADKEY_NUM
#endif

#if 1
#define USE_POWER_KEY
#define USE_ONLY_POWER_HOLD_CTRL
#define PWR_CTRL_P02
#define USE_PWR_KEY_LONG_PWR_ON
#endif

#define INDEPENDENT_VOLUME_KEY
#define USE_LONG_PLAY_KEY_PLAY_MODE
#define PLAY_MODE_USE_REP_ONE_ALL
#define DEFAULT_GO_TO_TIME_MODE
#define RTC_MODE_HOT_KEY_ENABLE
#define MODE_KEY_LONG_FOR_RTC_HOTKEY

#define USE_PLAY_LONG_FOR_RTC_SETTING
#define USE_RTC_FUNCTION
#define USE_RTC_TIME_ONLY
#define RTC_SETTING_NO_CYC
#define USE_RTC_ALARM_FUNCTION
#define USE_RTC_ALM_CUSTOM_INIT
#define RTC_SETTING_OP_TIMER_ENABLE

#if 0
#define USE_BAT_MANAGEMENT
#define BAT_LEVEL_LED_ICON_IND
#define CHARGER_DETECT_INDICATOR
#define CHARGER_DET_USE_P04
#define CHARGER_FLASH_TYPE_2
#endif
#undef USE_RDAs_FM
#endif

#ifdef K1258_WXD_1258_V001

#ifdef IIC_GPIO_USE_P02_P03
#undef IIC_GPIO_USE_P02_P03
#endif

#define IIC_GPIO_USE_P00_P01

#ifdef MUTE_PORT_USE_P01
#undef  MUTE_PORT_USE_P01
#endif
#define MUTE_PORT_USE_P03

#define LED_USE_ROUND_LED
#define LED_USE_PLAY_MODE
#define LED_USE_PLAY_MODE_NORMAL

#define USE_GPIO_DETECT_EARPHONE_PLUGGED
#define EARPHONE_DETECT_USE_P17

#define EXCHANGE_LINE_IN_CHANNEL	//交换LINE IN 通道
#define NEW_SD_DETECT_MOD
#define ADKEY_PLAY_SHORT_SCAN_FRE
#define USE_LONG_PLAY_KEY_TO_SWITCH_MODE

#define USE_BAT_MANAGEMENT
#define BAT_LEVEL_LED_ICON_IND
#define CHARGER_DETECT_INDICATOR
#define CHARGER_DET_USE_P04
#define CHARGER_FLASH_TYPE_2
#endif

#ifdef K015_SW_005B_V001

#ifdef IIC_GPIO_USE_P02_P03
#undef IIC_GPIO_USE_P02_P03
#endif

#define IIC_GPIO_USE_P00_P01

#ifdef MUTE_PORT_USE_P01
#undef  MUTE_PORT_USE_P01
#endif
#define MUTE_PORT_USE_P03

#define NO_PLAY_STATUS_LED
#define LED_USE_PLAY_MODE

#define LED_GPIO_PORT_CUSTOMERIZED

#define KEY_100_ENABLE
#define FM_BY_PASS

#define CUSTOM_OUTPUT_LIMIT

#define EXCHANGE_LINE_IN_CHANNEL	//交换LINE IN 通道
#define NEW_SD_DETECT_MOD
#define CUSTOMER_DEFINED_ADKEY_RESISTOR

#if 1
#define BLUE_TOOTH_FUNC
#define BLUETOOTH_GPIO_CTRL
#define BT_USE_AUX_1
#define BLUE_TOOTH_NO_SYS_MUTE_CTRL
#define DISP_BLUE_STR
#define BLUE_TOOTH_KEY_DELAY_25MS
#endif

#endif

#ifdef K4006_SES_4321_V001

#ifdef IIC_GPIO_USE_P02_P03
#undef IIC_GPIO_USE_P02_P03
#endif

#define IIC_GPIO_USE_P00_P01

#ifdef MUTE_PORT_USE_P01
#undef  MUTE_PORT_USE_P01
#endif
#define MUTE_PORT_USE_P03

#define LED_USE_ROUND_LED

#define EXCHANGE_LINE_IN_CHANNEL	//交换LINE IN 通道
#define NEW_SD_DETECT_MOD
#define JINRUI_IR_REMOTE_TYPE
#define CUSTOMER_DEFINED_ADKEY_RESISTOR
#define INDEPENDENT_VOLUME_KEY
#define DEFAULT_GO_TO_AUX

#define ADKEY_PLAY_SHORT_SCAN_FRE
#define ADKEY_PLAY_SHORT_SCAN_FRE_DISABLE
#define USE_STOP_KEY_SHORT_SCAN
#define DECODE_STOP_MODE_ENABLE
#define USE_LONG_EQ_KEY_PLAY_MODE

#define USE_BAT_MANAGEMENT
#define BAT_LEVEL_LED_ICON_IND
#define CHARGER_DETECT_INDICATOR
#define CHARGER_DET_USE_P02
#define CHARGER_FLASH_TYPE_2
#define BAT_LEVEL_MEASURE_BY_GPIO
#define BAT_MEASURE_USE_P04_PORT

#define FM_USE_AR1015
#endif

#ifdef K1247_YHD_Y900_V001

#ifdef IIC_GPIO_USE_P02_P03
#undef IIC_GPIO_USE_P02_P03
#endif

#define IIC_GPIO_USE_P00_P01

#ifdef MUTE_PORT_USE_P01
#undef  MUTE_PORT_USE_P01
#endif
#define MUTE_PORT_USE_P03


#define DISP_PAUS_STRING
#define PLAY_STATUS_LED_P17
#define ADKEY_USE_P07_PORT

#define PROTECT_P17_FROM_LED_SCAN

#define EXCHANGE_LINE_IN_CHANNEL	//交换LINE IN 通道

#define EXCHANGE_FM_MP3_ICON

#define DEFAULT_GO_TO_IDLE
#define NO_DEV_SHOW_HI_STR
#define DISP_HIFI_STR_AT_POWER_ON
#define DISP_VOL_V_CHAR
#define FM_BY_PASS
#define LINE_IN_PLAY_KEY_PAUSE
#define DISP_PAUS_STRING
#define FM_PLAY_KEY_PAUSE
#define USE_MODE_KEY_LONG_SCAN
#define ADKEY_PLAY_SHORT_SCAN_FRE
#define IPONE_DOCK_FUNC_ENABLE
#define IPONE_INDEPENDENT_MODE
#define IPHONE_TX_USE_P06
#define IPHONE_DETECT_IN_USE
#define IPHONE_DETECT_USE_P02
#define TURN_ON_MUSIC_WHEN_IPHONE_DOCK

#endif

#ifdef K2136_ZX_1234_V001

#ifdef IIC_GPIO_USE_P02_P03
#undef IIC_GPIO_USE_P02_P03
#endif
#define IIC_GPIO_USE_P00_P01

#define NEW_SD_DETECT_MOD
#define LED_GPIO_PORT_CUSTOMERIZED
#define LED_COMMON_SCAN_COM_USE_P17
#define LED_USE_PLAY_MODE
#define LED_USE_PLAY_MODE_NORMAL

#ifdef MUTE_PORT_USE_P01
#undef  MUTE_PORT_USE_P01
#endif

#define DISP_PAUS_STRING
#define NO_PLAY_STATUS_LED

#define USE_MANUAL_IDLE_FUNC
#define DEFAULT_GO_TO_IDLE
#define ADKEY_PLAY_SHORT_SCAN_FRE
#define MUTE_PORT_USE_P03
#define USE_LONG_MODE_KEY_PLAY_MODE

#define EXCHANGE_LINE_IN_CHANNEL	//交换LINE IN 通道

#define USE_BAT_MANAGEMENT
#define BAT_LEVEL_LED_ICON_IND

#define CHARGER_DETECT_INDICATOR
#define CHARGER_DET_USE_P02
#define CHARGER_FLASH_TYPE_2

#define USE_GPIO_DETECT_EARPHONE_PLUGGED
#define EARPHONE_DETECT_USE_P34
#define IDLE_MODE_NO_MUTE

#define USE_AMP_MODE_SELECT
#define AMP_MODE_SELECT_PORT_USE_P04

#define FM_USE_AR1015
#endif

#ifdef K2131_AJR_1234_V001

#ifdef IIC_GPIO_USE_P02_P03
#undef IIC_GPIO_USE_P02_P03
#endif
#define IIC_GPIO_USE_P00_P01

#define LED_GPIO_PORT_CUSTOMERIZED
#define LED_COMMON_SCAN_COM_USE_P17
//#define LED_USE_PLAY_MODE
#define COMMON_CATHODE
#define EXCHANGE_FM_MP3_ICON

#undef MUTE_CTRL_LEVEL_NORMAL
#ifdef MUTE_PORT_USE_P01
#undef  MUTE_PORT_USE_P01
#endif

#define DISP_PAUS_STRING
#define NO_PLAY_STATUS_LED

#define USE_LONG_PLAY_KEY_TO_SWITCH_MODE
#define ADKEY_PLAY_SHORT_SCAN_FRE
#define MUTE_PORT_USE_P03

#define EXCHANGE_LINE_IN_CHANNEL	//交换LINE IN 通道

#define LED_ROLLING_WITH_MIC_DETETION
#endif

#ifdef K3031_AP_668_V001

#define LED_GPIO_PORT_CUSTOMERIZED

#define EXCHANGE_LINE_IN_CHANNEL	//交换LINE IN 通道
#define DISP_HIFI_ANIMIATION_AT_PWR_ON
#define DISP_OFF_ANIMIATION_AT_PWR_DOWN
#define FM_DISP_CH_STR
#define MP3_DISP_LOAD_STRING
#define RIGHT_ALIGN_DISP
#define DISP_ALM_UP_SPARK_TIME
#define DISP_VOL_V_CHAR_ALIGN_LEFT
#define LED_USE_PLAY_MODE_MIXED

#define DISP_PAUS_STRING
#define FM_PLAY_KEY_PAUSE
#define SEMI_AUTO_SCAN_FREQ
#define ADKEY_NEXT_PREV_HOLD_AUTO_SCAN
#define USE_SYS_MODE_RECOVER
#define RTC_ALRM_MEM_LAST_WORK_MODE
#define LARGE_RES_VALUE_FOR_AD_AUX_HP_DETECTION
#define DISP_PAU_STRING_ONLY_IN_FM_MODE
#define CUSTOMER_DEFINED_ADKEY_RESISTOR
#define ADKEY_NEW_METHOD
#define TWO_ADKEY_ENABLE
#define TWO_ADKEY_USE_PORT_P07
#define EXTENDED_ADKEY_NUM
#define USE_ADKEY_FOR_AUX_HP_DETECTION
#define USE_GPIO_DETECT_EARPHONE_PLUGGED
#define USE_ADKEY_DETECT_HP

#define INDEPENDENT_VOLUME_KEY
#define VOLUME_DEFUALT			22
#if 1
#define USE_POWER_KEY
//#define USE_ONLY_POWER_HOLD_CTRL
#define PWR_CTRL_WKUP
//#define USE_PWR_KEY_LONG_PWR_ON
//#define POWER_KEY_ON_WAIT_FOR_3_SEC
#endif
#define FM_MAX_CHANNAL_50
#define USE_PLAY_LONG_FOR_RTC_SETTING
#define RTC_MODE_HOT_KEY_ENABLE
#define DONT_MOUNT_RTC_FUNC
#define USE_RTC_FUNCTION
#define USE_RTC_TIME_ONLY
//#define RTC_SETTING_NO_CYC
#define USE_RTC_ALARM_FUNCTION
#define USE_RTC_ALM_CUSTOM_INIT
#define ADJ_TIME_USE_VOL_KEY
#define RTC_SETTING_OP_TIMER_ENABLE
#endif


#ifdef K1224_ALK_510_V001


#ifdef IIC_GPIO_USE_P02_P03
#undef IIC_GPIO_USE_P02_P03
#endif
#define IIC_GPIO_USE_P00_P01


#ifdef MUTE_PORT_USE_P01
#undef  MUTE_PORT_USE_P01
#endif

#define MUTE_PORT_USE_P03

#define DISP_OFF_STR_AT_PWR_DOWN
#define DISP_VOL_V_CHAR

#define EXCHANGE_LINE_IN_CHANNEL	//交换LINE IN 通道


#define CUSTOMER_DEFINED_ADKEY_RESISTOR
#define USE_MODE_KEY_LONG_SCAN
#define DEFAULT_GO_TO_IDLE
#define NO_DEV_SHOW_HI_STR
#define USE_POWER_KEY_FOR_FM_PLAY
#define POWE_KEY_PLAY_KEY_IN_ONE_KEY
#define FM_PLAY_KEY_PAUSE

#define LINE_IN_PLAY_KEY_PAUSE
#define USE_POWER_KEY_FOR_AUX_PLAY

#if 1
#define USE_POWER_KEY
#define USE_ONLY_POWER_HOLD_CTRL
#define PWR_CTRL_P02
#define USE_PWR_KEY_LONG_PWR_ON
#endif


#define USE_RTC_FUNCTION
#define USE_RTC_TIME_ONLY
#define RTC_SETTING_NO_CYC

#undef USE_RDAs_FM
#undef USE_QN8035_FM
#define Lamborghini_voice
#define OTP_MUSIC_FUNC_ENABLE


#define USE_LINE_IN_DETECT_FUNC
#define AUX_DETECT_USE_P17
#endif

#ifdef K1224_YJH_1224_V001


#ifdef IIC_GPIO_USE_P02_P03
#undef IIC_GPIO_USE_P02_P03
#endif
#define IIC_GPIO_USE_P00_P01


#ifdef MUTE_PORT_USE_P01
#undef  MUTE_PORT_USE_P01
#endif

#define MUTE_PORT_USE_P03


#define EXCHANGE_LINE_IN_CHANNEL	//交换LINE IN 通道


#define CUSTOMER_DEFINED_ADKEY_RESISTOR
#define USE_MODE_KEY_LONG_SCAN

#define USE_POWER_KEY_FOR_FM_PLAY
#define POWE_KEY_PLAY_KEY_IN_ONE_KEY
#define FM_PLAY_KEY_PAUSE

#define LINE_IN_PLAY_KEY_PAUSE
#define USE_POWER_KEY_FOR_AUX_PLAY

#if 1
#define USE_POWER_KEY
#define USE_ONLY_POWER_HOLD_CTRL
#define PWR_CTRL_P02
#define USE_PWR_KEY_LONG_PWR_ON
#endif


#define USE_RTC_FUNCTION
#define USE_RTC_TIME_ONLY
#define RTC_SETTING_NO_CYC

#endif

#ifdef K000_XC_BC_BT_V001

#define EXCHANGE_LINE_IN_CHANNEL	//交换LINE IN 通道

#define NO_LED_DISPLAY
#define ADKEY_USE_P07_PORT
#undef LED_CTRL_LEVEL_NORMAL
#define NO_DEV_LED_IMPROVE

#if 1
#define BLUE_TOOTH_FUNC
#define BLUETOOTH_GPIO_CTRL
#define BT_VOL_USE_NEXT_PREV_KEY
#define BLUE_TOOTH_PP_NOT_EXT_MUTE
#define BLUE_TOOTH_DISABLE_GPIO_VOL_ADJ
#define BLUE_TOOTH_NO_SYS_MUTE_CTRL
#define BLUE_TOOTH_MUTE_DETECT_FUNC
#define PP_KEY_LONG_CONFIG_BT
#define BLUE_TOOTH_KEY_DELAY_25MS
#define USE_BT_GPIO_DETECTION
#define BT_GPIO_DETECTION_USE_PORT_P33
#define BLUE_TOOTH_DETECTION_FOR_POWER_OFF
#define BLUE_TOOTH_GPIO_STATUS
#define BT_USE_AUX_1
#define BLUE_TOOTH_LINK_IDLE_POWER_OFF
#endif
#define DEFAULT_GO_TO_IDLE

#if 1
#define CUSTOMER_DEFINED_ADKEY_RESISTOR
#define USE_POWER_KEY
#define USE_ONLY_POWER_HOLD_CTRL
#define PWR_CTRL_P04
#define USE_PWR_KEY_LONG_PWR_ON
#define PWR_ON_DELAY_1_SECOND
#endif

#define NEW_CUSTOMIZED_LED_METHOD
#define EXTENDED_WORK_MODE_USE_TWO_GPIO_CTRL

#define USE_GPIO_DETECT_EARPHONE_PLUGGED
#define EARPHONE_DETECT_USE_P34

//#define VOLUME_CUSTOMER_DEFINE_16

#define DISABLE_DEVICE_HOT_PLUG_AND_PLAY
#define USE_SYS_MODE_RECOVER
#define SYS_BT_TURN_OFF_PWR_CHECK
#define DEFAULT_HOLD_IN_DECODE_MODE
#define DEVICE_AUTO_PLAY_IN_CURR_MODE_ONLY
#define FORCE_MOUNT_SD_CARD_DEV
//#define USE_LINE_IN_DETECT_FUNC
//#define AUX_DETECT_USE_P03
//#define AUX_DETECT_SHARE_WITH_IIC_SCL

#endif


#ifdef K1229_WXD_1229_V001

#ifdef IIC_GPIO_USE_P02_P03
#undef IIC_GPIO_USE_P02_P03
#endif
#define IIC_GPIO_USE_P00_P01

#ifdef MUTE_PORT_USE_P01
#undef  MUTE_PORT_USE_P01
#endif
#define MUTE_PORT_USE_P03

#define NO_PLAY_STATUS_LED
#define LED_USE_ROUND_LED
#define LED_USE_PLAY_MODE
#define LED_USE_PLAY_MODE_NORMAL
#define EXCHANGE_LINE_IN_CHANNEL	//交换LINE IN 通道

#define DEFINE_LOWER_BAT_FULL_VOL
#define DISP_OFF_STR_AT_PWR_DOWN
#define DISP_PAU_STRING
#define DISP_AUX_STRING

#define DISP_HIFI_STR_AT_POWER_ON
#define DEFAULT_GO_TO_AUX
#define LINE_IN_PLAY_KEY_PAUSE
#define FM_PLAY_KEY_PAUSE
#define DISP_PAUS_STRING
#define MP3_SELECT_SONG_WHILE_PLAY
#define MP3_HOT_KEY_LONG_SELECT_SONG
#define DISP_VOL_V_CHAR
#define FM_DISP_CH_STR



#define MUSIC_MODE_HOT_KEY_SHORT_FOR_USB_SD_SEL
#define CUSTOMER_DEFINED_ADKEY_RESISTOR
#define MUSIC_MODE_HOT_KEY_ENABLE
#define AUX_MODE_HOT_KEY_ENABLE
#define AUX_MODE_HOT_KEY_USE_PLAY_LONG
#define RADIO_MODE_HOT_KEY_ENABLE
#define RADIO_MODE_HOT_KEY_LONG_SCAN

#define VOLUME_CUSTOMER_DEFINE_16
#define CUSTOM_DEFINE_ADPORT_FOR_VOLUME_ADJ
#define DECODE_STOP_MODE_ENABLE
#define INDEPENDENT_VOLUME_KEY

#define NEXT_PREV_REPLAY_IN_STOP_DECODE_MODE
#define SEMI_AUTO_SCAN_FREQ
#define ADKEY_NEXT_PREV_HOLD_AUTO_SCAN
#if 0
#define USE_POWER_KEY
#define USE_ONLY_POWER_HOLD_CTRL
#define PWR_CTRL_P02
#define USE_PWR_KEY_LONG_PWR_ON
#define PWR_ON_DELAY_1_SECOND
#endif

#define USE_GPIO_DETECT_EARPHONE_PLUGGED
#define EARPHONE_DETECT_USE_P02


#define USE_BAT_MANAGEMENT
#define BAT_LEVEL_LED_ICON_IND

#define CHARGER_DETECT_INDICATOR
#define CHARGER_DET_USE_P04
#define CHARGER_FLASH_TYPE_2


#endif

#ifdef K2121_WXD_2121_V001

#ifdef IIC_GPIO_USE_P02_P03
#undef IIC_GPIO_USE_P02_P03
#endif
#define IIC_GPIO_USE_P00_P01

#ifdef MUTE_PORT_USE_P01
#undef  MUTE_PORT_USE_P01
#endif
#define MUTE_PORT_USE_P03

#define LED_GPIO_PORT_CUSTOMERIZED
#define LED_COMMON_SCAN_COM_USE_P17

#define EXCHANGE_LINE_IN_CHANNEL	//交换LINE IN 通道

#define USE_POWER_KEY_SHORT_SCAN
#define POWE_KEY_PLAY_KEY_IN_ONE_KEY

#define DISP_OFF_STR_AT_PWR_DOWN
#define DISP_PAU_STRING

#define CUSTOMER_DEFINED_ADKEY_RESISTOR

#define LINE_IN_PLAY_KEY_PAUSE
#define USE_POWER_KEY_FOR_AUX_PLAY
#define DISP_PAUS_STRING

#if 1
#define USE_POWER_KEY
#define USE_ONLY_POWER_HOLD_CTRL
#define PWR_CTRL_P02
#define USE_PWR_KEY_LONG_PWR_ON
#define PWR_ON_DELAY_1_SECOND
#endif

#define USE_GPIO_DETECT_EARPHONE_PLUGGED
#define EARPHONE_DETECT_USE_P04

#define USE_LINE_IN_DETECT_FUNC
#define AUX_DETECT_USE_P34

#define USE_BAT_MANAGEMENT
#define BAT_LEVEL_LED_ICON_IND
#define CHARGER_DETECT_INDICATOR
#define CHARGER_DET_USE_P04
#define CHARGER_FLASH_TYPE_2


#undef USE_RDAs_FM
#undef USE_QN8035_FM
#define Lamborghini_voice
#define OTP_MUSIC_FUNC_ENABLE

#endif

#ifdef K0000_HF_6001_V001

#ifdef IIC_GPIO_USE_P02_P03
#undef IIC_GPIO_USE_P02_P03
#endif
#define IIC_GPIO_USE_P00_P01

#ifdef MUTE_PORT_USE_P01
#undef  MUTE_PORT_USE_P01
#endif
#define MUTE_PORT_USE_P03

#define LED_USE_1X888

#define EXCHANGE_LINE_IN_CHANNEL	//交换LINE IN 通道

#define USE_POWER_KEY_SHORT_SCAN
#define POWE_KEY_PLAY_KEY_IN_ONE_KEY

#define DISP_OFF_STR_AT_PWR_DOWN
#define DISP_PAU_STRING

#define CUSTOMER_DEFINED_ADKEY_RESISTOR

#define LINE_IN_PLAY_KEY_PAUSE
#define USE_POWER_KEY_FOR_AUX_PLAY

#if 1
#define USE_POWER_KEY
#define USE_ONLY_POWER_HOLD_CTRL
#define PWR_CTRL_P02
#define USE_PWR_KEY_LONG_PWR_ON
#define PWR_ON_DELAY_1_SECOND
#endif

#define USE_GPIO_DETECT_EARPHONE_PLUGGED
#define EARPHONE_DETECT_USE_P04

//#define USE_LINE_IN_DETECT_FUNC
//#define AUX_DETECT_USE_P34


//#define Lamborghini_voice
//#define OTP_MUSIC_FUNC_ENABLE
#endif


#ifdef K0000_KM_LBJN_V001

#ifdef MUTE_PORT_USE_P01
#undef  MUTE_PORT_USE_P01
#endif
#define MUTE_PORT_USE_P00

#define LED_USE_PLAY_MODE
#define LED_USE_ROUND_LED
#define LED_MODE_EXCHANGE_TF_USB_ICON
#define PROTECT_P17_FROM_LED_SCAN

#define PLAY_STATUS_LED_P17


#define EXCHANGE_LINE_IN_CHANNEL	//交换LINE IN 通道

#define USE_MODE_KEY_LONG_SCAN
#define POWE_KEY_PLAY_KEY_IN_ONE_KEY

#define DISP_OFF_STR_AT_PWR_DOWN
#define DISP_PAUS_STRING

#define CUSTOMER_DEFINED_ADKEY_RESISTOR
#define DISP_VOL_V_CHAR
#define ADKEY_INTERNAL_RES_PULLUP
#if 1
#define USE_POWER_KEY
#define USE_ONLY_POWER_HOLD_CTRL
#define PWR_CTRL_P04
#define USE_PWR_KEY_LONG_PWR_ON
#define PWR_ON_DELAY_1_SECOND
//#define PWR_OFF_NO_RESP_WHEN_CHARGER_PLUGGED
#endif

#define TURN_ON_PLAY_BREAK_POINT_MEM
#define USE_BAT_MANAGEMENT
#define BAT_LEVEL_LED_ICON_IND
#define CHARGER_DETECT_INDICATOR
#define CHARGER_DET_USE_P01
#define CHARGER_FLASH_TYPE_2

#define USE_GPIO_DETECT_EARPHONE_PLUGGED
#define EARPHONE_DETECT_USE_P07

#undef USE_RDAs_FM
#undef USE_QN8035_FM
#define Lamborghini_voice
#define OTP_MUSIC_FUNC_ENABLE
#endif


#ifdef K2116_SW_017KT_V001

#define LED_USE_PLAY_MODE

#ifdef IIC_GPIO_USE_P02_P03
#undef IIC_GPIO_USE_P02_P03
#endif
#define IIC_GPIO_USE_P00_P01

#ifdef MUTE_PORT_USE_P01
#undef  MUTE_PORT_USE_P01
#endif
#define MUTE_PORT_USE_P03

#define NO_LED_DISPLAY
#define LED_GPIO_PORT_CUSTOMERIZED

#define EXCHANGE_LINE_IN_CHANNEL	//交换LINE IN 通道

#define FM_USE_KT0913
#define RADIO_AM_WM_ENABLE
#undef USE_RDAs_FM
#undef USE_QN8035_FM
#undef USE_BK1080_FM

#endif


#ifdef K5038_JK_5038_V001

#ifdef IIC_GPIO_USE_P02_P03
#undef IIC_GPIO_USE_P02_P03
#endif
#define IIC_GPIO_USE_P00_P01

#ifdef MUTE_PORT_USE_P01
#undef  MUTE_PORT_USE_P01
#endif
#define MUTE_PORT_USE_P04

#ifdef LED_GPIO_DRV
#undef  LED_GPIO_DRV
#endif
#define LCD_GPIO_DRV
#define LCD_SEGMENT_USE_8_SEGS_5_COMS

#define EXCHANGE_LINE_IN_CHANNEL	//交换LINE IN 通道

#define DISP_VOL_V_CHAR
#define NO_PLAY_STATUS_LED
#define SEMI_AUTO_SCAN_FREQ
#define ADKEY_NEXT_PREV_HOLD_AUTO_SCAN

#define DISP_PAUS_STRING
#define VOLUME_DEFUALT 	30
#define INDEPENDENT_VOLUME_KEY

#define SUPERIOR_CUSTOMER
#undef KPL_MSG_COMPATIBLE

#if 1
#define CUSTOMER_DEFINED_ADKEY_RESISTOR

#define USE_POWER_KEY
#define USE_ONLY_POWER_HOLD_CTRL
#define PWR_CTRL_WKUP
#define USE_PWR_KEY_LONG_PWR_ON
#define PWR_ON_DELAY_1_SECOND
#endif


#define ADKEY_NEW_METHOD
#define USE_ADKEY_FOR_AUX_HP_DETECTION
#define USE_ADKEY_DETECT_AUX
#define LARGE_RES_VALUE_FOR_AD_AUX_HP_DETECTION

#define USE_LINE_IN_DETECT_FUNC

#define JOG_STICK_FUNC
#define VOL_TUNE_FREQ_ONLY

#define LINE_IN_PLAY_KEY_PAUSE
#define FM_PLAY_KEY_PAUSE

#define USE_POWER_KEY_TO_SWITCH_MODE

#define RADIO_MODE_HOT_KEY_ENABLE
//#define RADIO_MODE_HOT_KEY_LONG_SCAN
#define USE_IR_VPP_PORT_FOR_DETECTION

#define USE_SPECTRUM_PARTTERN
#if 0
#define NO_DEV_SHOW_HI_STR
#define DEFAULT_GO_TO_IDLE
#endif
#if 0
#define USE_RTC_FUNCTION
#define USE_RTC_TIME_ONLY
#define RTC_SETTING_NO_CYC

#define DEFAULT_GO_TO_TIME_MODE
#endif

#define USE_BAT_MANAGEMENT
#define DC_CHARGE_GPIO_DRV_LED_IND
#define DC_CHARGE_GPIO_DRV_LED_VPP
#define CHARGER_DETECT_INDICATOR
#define CHARGER_DET_USE_P07


#endif

#ifdef K5018_JK_5018_V001

#ifdef IIC_GPIO_USE_P02_P03
#undef IIC_GPIO_USE_P02_P03
#endif
#define IIC_GPIO_USE_P00_P01

#ifdef MUTE_PORT_USE_P01
#undef  MUTE_PORT_USE_P01
#endif
#define MUTE_PORT_USE_P04

#ifdef LED_GPIO_DRV
#undef  LED_GPIO_DRV
#endif
#define LCD_GPIO_DRV
#define LCD_SEGMENT_USE_8_SEGS_5_COMS

#define EXCHANGE_LINE_IN_CHANNEL	//交换LINE IN 通道

#define ADKEY_PLAY_SHORT_ADJ_CH
#define DISP_VOL_V_CHAR
#define NO_PLAY_STATUS_LED
#define SEMI_AUTO_SCAN_FREQ
#define ADKEY_NEXT_PREV_HOLD_AUTO_SCAN

#define DISP_PAUS_STRING
#define VOLUME_DEFUALT 	30
#define INDEPENDENT_VOLUME_KEY

#define FM_USE_KT0913
#define RADIO_AM_WM_ENABLE
#define SUPERIOR_CUSTOMER
#undef KPL_MSG_COMPATIBLE

#if 0
#define CUSTOMER_DEFINED_ADKEY_RESISTOR

#define USE_POWER_KEY
#define USE_ONLY_POWER_HOLD_CTRL
#define PWR_CTRL_P17
#define USE_PWR_KEY_LONG_PWR_ON
#define PWR_ON_DELAY_1_SECOND
#endif

#define USE_LINE_IN_DETECT_FUNC
#define AUX_DETECT_USE_P07
#define JOG_STICK_FUNC


#define USE_RTC_FUNCTION
#define USE_RTC_TIME_ONLY
#define RTC_SETTING_NO_CYC

#define DEFAULT_GO_TO_TIME_MODE
#undef USE_RDAs_FM
#undef USE_QN8035_FM
#undef USE_BK1080_FM
#endif


#ifdef K5058_JK_5058_V001

#ifdef IIC_GPIO_USE_P02_P03
#undef IIC_GPIO_USE_P02_P03
#endif
#define IIC_GPIO_USE_P00_P01

#ifdef MUTE_PORT_USE_P01
#undef  MUTE_PORT_USE_P01
#endif
#define MUTE_PORT_USE_P04
#define COMMON_CATHODE
#define EXCHANGE_FM_MP3_ICON

#define PROTECT_P17_FROM_LED_SCAN

#define SYS_LED_PROTECTION_UNTILL_PWR_ON
#define AUX_LED_PROTECTION_BEFORE_PWR_ON
#define NO_DEV_LED_IMPROVE

#define NO_DEV_SHOW_HI_STR
#define DEFAULT_GO_TO_IDLE
#define MP3_DISP_LOAD_STRING

#define EXCHANGE_LINE_IN_CHANNEL	//交换LINE IN 通道

#define DISP_OFF_STR_AT_PWR_DOWN
#define DISP_PAUS_STRING
#define FM_PLAY_KEY_PAUSE
#define LINE_IN_PLAY_KEY_PAUSE

//#define ADKEY_PLAY_SHORT_ADJ_CH
#define DISP_VOL_V_CHAR
#define NO_PLAY_STATUS_LED
#define SEMI_AUTO_SCAN_FREQ
#define ADKEY_NEXT_PREV_HOLD_AUTO_SCAN

#define VOLUME_DEFUALT 	30
#define INDEPENDENT_VOLUME_KEY
#if 1
#define CUSTOMER_DEFINED_ADKEY_RESISTOR

#define USE_POWER_KEY
#define USE_ONLY_POWER_HOLD_CTRL
#define SUPERIOR_CUSTOMER
#define PWR_CTRL_P17
#define USE_PWR_KEY_LONG_PWR_ON
#define PWR_ON_DELAY_1_SECOND
#endif

#define USE_LINE_IN_DETECT_FUNC
#define AUX_DETECT_USE_P07
#define JOG_STICK_FUNC
#define VOL_TUNE_FREQ_ONLY

#define USE_POWER_KEY_TO_SWITCH_MODE

#endif

#ifdef K5068_JK_5068_V001

#ifdef IIC_GPIO_USE_P02_P03
#undef IIC_GPIO_USE_P02_P03
#endif
#define IIC_GPIO_USE_P00_P01

#ifdef MUTE_PORT_USE_P01
#undef  MUTE_PORT_USE_P01
#endif
#define MUTE_PORT_USE_P04

#define PLAY_STATUS_LED_P02

#define COMMON_CATHODE
#define EXCHANGE_FM_MP3_ICON

#define PROTECT_P17_FROM_LED_SCAN

#define EXCHANGE_LINE_IN_CHANNEL	//交换LINE IN 通道

#define NO_DEV_SHOW_HI_STR
#define DEFAULT_GO_TO_IDLE
#define MP3_DISP_LOAD_STRING
#define DISP_OFF_STR_AT_PWR_DOWN
#define DISP_PAUS_STRING
#define FM_PLAY_KEY_PAUSE
#define LINE_IN_PLAY_KEY_PAUSE

#define SYS_LED_PROTECTION_UNTILL_PWR_ON
#define AUX_LED_PROTECTION_BEFORE_PWR_ON
#define NO_DEV_LED_IMPROVE

#define DISP_VOL_V_CHAR
#define NO_PLAY_STATUS_LED
#define SEMI_AUTO_SCAN_FREQ
#define ADKEY_NEXT_PREV_HOLD_AUTO_SCAN
#define USE_POWER_KEY_TO_SWITCH_MODE

#define VOLUME_DEFUALT 	30
#define INDEPENDENT_VOLUME_KEY
#if 1
#define CUSTOMER_DEFINED_ADKEY_RESISTOR

#define USE_POWER_KEY
#define USE_ONLY_POWER_HOLD_CTRL
#define SUPERIOR_CUSTOMER
#define PWR_CTRL_P17
#define USE_PWR_KEY_LONG_PWR_ON
#define PWR_ON_DELAY_1_SECOND
#endif

#define USE_LINE_IN_DETECT_FUNC
#define AUX_DETECT_USE_P07
//#define JOG_STICK_FUNC

#endif

#ifdef K5008_JK_5008_V001

#ifdef IIC_GPIO_USE_P02_P03
#undef IIC_GPIO_USE_P02_P03
#endif
#define IIC_GPIO_USE_P00_P01

#ifdef MUTE_PORT_USE_P01
#undef  MUTE_PORT_USE_P01
#endif
#define MUTE_PORT_USE_P04
#define COMMON_CATHODE
#define EXCHANGE_FM_MP3_ICON

#define PROTECT_P17_FROM_LED_SCAN

#define EXCHANGE_LINE_IN_CHANNEL	//交换LINE IN 通道

#define NO_DEV_SHOW_HI_STR
#define DEFAULT_GO_TO_IDLE
#define MP3_DISP_LOAD_STRING
#define DISP_OFF_STR_AT_PWR_DOWN
#define DISP_PAUS_STRING
#define FM_PLAY_KEY_PAUSE
#define LINE_IN_PLAY_KEY_PAUSE

#define SYS_LED_PROTECTION_UNTILL_PWR_ON
#define AUX_LED_PROTECTION_BEFORE_PWR_ON
#define NO_DEV_LED_IMPROVE

#define DISP_VOL_V_CHAR
#define NO_PLAY_STATUS_LED
#define SEMI_AUTO_SCAN_FREQ
#define ADKEY_NEXT_PREV_HOLD_AUTO_SCAN

#define VOLUME_DEFUALT 	30
#define INDEPENDENT_VOLUME_KEY
#if 1
#define CUSTOMER_DEFINED_ADKEY_RESISTOR

#define USE_POWER_KEY
#define USE_ONLY_POWER_HOLD_CTRL
#define SUPERIOR_CUSTOMER
#define PWR_CTRL_P17
#define USE_PWR_KEY_LONG_PWR_ON
#define PWR_ON_DELAY_1_SECOND
#endif

#define USE_LINE_IN_DETECT_FUNC
#define AUX_DETECT_USE_P07
#define JOG_STICK_FUNC

#endif

#ifdef K1197_AJR_855_V001

#ifdef IIC_GPIO_USE_P02_P03
#undef IIC_GPIO_USE_P02_P03
#endif
#define IIC_GPIO_USE_P00_P01

#ifdef MUTE_PORT_USE_P01
#undef  MUTE_PORT_USE_P01
#endif
#define MUTE_PORT_USE_P03

#define LED_GPIO_PORT_CUSTOMERIZED
#define LED_USE_PLAY_MODE
#define LED_USE_PLAY_MODE_NORMAL

#define PROTECT_P17_FROM_LED_SCAN

#define EXCHANGE_LINE_IN_CHANNEL	//交换LINE IN 通道

#define USE_MODE_KEY_LONG_SCAN
#define POWE_KEY_PLAY_KEY_IN_ONE_KEY

#define DISP_OFF_STR_AT_PWR_DOWN
#define DISP_PAUS_STRING
//#define FM_MAX_CHANNAL_50
#define ADKEY_PLAY_SHORT_ADJ_CH
#define CUSTOMER_DEFINED_ADKEY_RESISTOR
#define LOW_VOLT_SPARK_BAT_ICON
#define DISP_VOL_V_CHAR

#define LINE_IN_PLAY_KEY_PAUSE
#define USE_POWER_KEY_FOR_AUX_PLAY
#define FM_PLAY_KEY_PAUSE
#define USE_POWER_KEY_FOR_FM_PLAY


#define VOLUME_DEFUALT 	20
#define DISP_FM_STR_WHEN_PAUS

#if 1
#define USE_POWER_KEY
#define USE_ONLY_POWER_HOLD_CTRL
#define PWR_CTRL_P02
#define USE_PWR_KEY_LONG_PWR_ON
#define PWR_ON_DELAY_1_SECOND
//#define PWR_OFF_NO_RESP_WHEN_CHARGER_PLUGGED
#endif

#define TURN_ON_PLAY_BREAK_POINT_MEM
#define USE_BAT_MANAGEMENT
#define BAT_LEVEL_LED_ICON_IND
#define CHARGER_DETECT_INDICATOR
#define CHARGER_DET_USE_P04
#define CHARGER_FLASH_TYPE_2

#define IR_REMOTER_WITH_POWER_MUTE_PRINT
#define USE_IR_POWER_KEY_TO_POWER_OFF
#define POWER_KEY_SHORT_PWR_DOWN
#define USE_GPIO_DETECT_EARPHONE_PLUGGED
#define EARPHONE_DETECT_USE_P17

#undef USE_RDAs_FM
#undef USE_QN8035_FM
#define OTP_MUSIC_FUNC_ENABLE
#define OTP_DECODE_PLAY_FOLLOW_SYS_VOL
#define SAIL_START
#endif

#ifdef K1197_KM_855_V001

#ifdef IIC_GPIO_USE_P02_P03
#undef IIC_GPIO_USE_P02_P03
#endif
#define IIC_GPIO_USE_P00_P01

#ifdef MUTE_PORT_USE_P01
#undef  MUTE_PORT_USE_P01
#endif
#define MUTE_PORT_USE_P03

#define LED_GPIO_PORT_CUSTOMERIZED
#define LED_USE_PLAY_MODE
#define LED_USE_PLAY_MODE_NORMAL
#define PROTECT_P17_FROM_LED_SCAN

#define EXCHANGE_LINE_IN_CHANNEL	//交换LINE IN 通道

#define USE_MODE_KEY_LONG_SCAN
#define POWE_KEY_PLAY_KEY_IN_ONE_KEY

#define DISP_OFF_STR_AT_PWR_DOWN
#define DISP_PAUS_STRING
//#define FM_MAX_CHANNAL_50
#define ADKEY_PLAY_SHORT_ADJ_CH
#define CUSTOMER_DEFINED_ADKEY_RESISTOR
#define LOW_VOLT_SPARK_BAT_ICON
#define DISP_VOL_V_CHAR
#define DEFAULT_GO_TO_IDLE
#define DISP_HIFI_STR_AT_POWER_ON
#define NO_DEV_SHOW_HI_STR

#define LINE_IN_PLAY_KEY_PAUSE
#define USE_POWER_KEY_FOR_AUX_PLAY
#define FM_PLAY_KEY_PAUSE
#define USE_POWER_KEY_FOR_FM_PLAY


#define VOLUME_DEFUALT 	20
#define DISP_FM_STR_WHEN_PAUS

#if 1
#define USE_POWER_KEY
#define USE_ONLY_POWER_HOLD_CTRL
#define PWR_CTRL_P02
#define USE_PWR_KEY_LONG_PWR_ON
#define PWR_ON_DELAY_1_SECOND
//#define PWR_OFF_NO_RESP_WHEN_CHARGER_PLUGGED
#endif

#define TURN_ON_PLAY_BREAK_POINT_MEM
#define USE_BAT_MANAGEMENT
#define BAT_LEVEL_LED_ICON_IND
#define CHARGER_DETECT_INDICATOR
#define CHARGER_DET_USE_P04
#define CHARGER_FLASH_TYPE_2

#define IR_REMOTER_WITH_POWER_MUTE_PRINT
#define USE_IR_POWER_KEY_TO_POWER_OFF
#define POWER_KEY_SHORT_PWR_DOWN
#define USE_GPIO_DETECT_EARPHONE_PLUGGED
#define EARPHONE_DETECT_USE_P17

#undef USE_RDAs_FM
#undef USE_QN8035_FM
#define OTP_MUSIC_FUNC_ENABLE
#define OTP_DECODE_PLAY_FOLLOW_SYS_VOL
#define SAIL_START
#endif


#ifdef K1197_LS_L10A_V001

#ifdef IIC_GPIO_USE_P02_P03
#undef IIC_GPIO_USE_P02_P03
#endif
#define IIC_GPIO_USE_P00_P01

#ifdef MUTE_PORT_USE_P01
#undef  MUTE_PORT_USE_P01
#endif
#define MUTE_PORT_USE_P03

#define LED_GPIO_PORT_CUSTOMERIZED
#define LED_USE_PLAY_MODE
#define LED_MODE_EXCHANGE_TF_USB_ICON
#define PROTECT_P17_FROM_LED_SCAN

#define EXCHANGE_LINE_IN_CHANNEL	//交换LINE IN 通道

#define USE_MODE_KEY_LONG_SCAN
#define POWE_KEY_PLAY_KEY_IN_ONE_KEY

#define DISP_OFF_STR_AT_PWR_DOWN
#define DISP_PAUS_STRING
//#define FM_MAX_CHANNAL_50
#define ADKEY_PLAY_SHORT_ADJ_CH
#define CUSTOMER_DEFINED_ADKEY_RESISTOR
#define LOW_VOLT_SPARK_BAT_ICON
#define DISP_VOL_V_CHAR
//#define DEFAULT_GO_TO_IDLE
#define DISP_HIFI_STR_AT_POWER_ON
#define NO_DEV_SHOW_HI_STR

#define LINE_IN_PLAY_KEY_PAUSE
#define USE_POWER_KEY_FOR_AUX_PLAY
#define FM_PLAY_KEY_PAUSE
#define USE_POWER_KEY_FOR_FM_PLAY


#define VOLUME_DEFUALT 	20
#define DISP_FM_STR_WHEN_PAUS

#if 1
#define USE_POWER_KEY
#define USE_ONLY_POWER_HOLD_CTRL
#define PWR_CTRL_P02
#define USE_PWR_KEY_LONG_PWR_ON
#define PWR_ON_DELAY_1_SECOND
//#define PWR_OFF_NO_RESP_WHEN_CHARGER_PLUGGED
#endif

#define TURN_ON_PLAY_BREAK_POINT_MEM
#define USE_BAT_MANAGEMENT
#define BAT_LEVEL_LED_ICON_IND
#define CHARGER_DETECT_INDICATOR
#define CHARGER_DET_USE_P04
#define CHARGER_FLASH_TYPE_2

#define IR_REMOTER_WITH_POWER_MUTE_PRINT
#define USE_IR_POWER_KEY_TO_POWER_OFF
#define POWER_KEY_SHORT_PWR_DOWN
#define USE_GPIO_DETECT_EARPHONE_PLUGGED
#define EARPHONE_DETECT_USE_P17

//#undef USE_RDAs_FM
#undef USE_BK1080_FM
#undef USE_QN8035_FM
#define OTP_MUSIC_FUNC_ENABLE
#define OTP_DECODE_PLAY_FOLLOW_SYS_VOL
#define SAIL_START
#endif

#ifdef K1197_DCX_893_V001

#ifdef IIC_GPIO_USE_P02_P03
#undef IIC_GPIO_USE_P02_P03
#endif
#define IIC_GPIO_USE_P00_P01

#ifdef MUTE_PORT_USE_P01
#undef  MUTE_PORT_USE_P01
#endif
#define MUTE_PORT_USE_P03

#define LED_GPIO_PORT_CUSTOMERIZED
#define LED_USE_PLAY_MODE
#define LED_MODE_EXCHANGE_TF_USB_ICON
#define PROTECT_P17_FROM_LED_SCAN

#define EXCHANGE_LINE_IN_CHANNEL	//交换LINE IN 通道

#define USE_MODE_KEY_LONG_SCAN
#define POWE_KEY_PLAY_KEY_IN_ONE_KEY

#define DISP_OFF_STR_AT_PWR_DOWN
#define DISP_PAUS_STRING
//#define FM_MAX_CHANNAL_50
#define ADKEY_PLAY_SHORT_ADJ_CH
#define CUSTOMER_DEFINED_ADKEY_RESISTOR
#define LOW_VOLT_SPARK_BAT_ICON
#define DISP_VOL_V_CHAR
#define DEFAULT_GO_TO_IDLE
#define DISP_HIFI_STR_AT_POWER_ON
#define NO_DEV_SHOW_HI_STR

#define LINE_IN_PLAY_KEY_PAUSE
#define USE_POWER_KEY_FOR_AUX_PLAY
#define FM_PLAY_KEY_PAUSE
#define USE_POWER_KEY_FOR_FM_PLAY


#define VOLUME_DEFUALT 	20
#define DISP_FM_STR_WHEN_PAUS

#if 1
#define USE_POWER_KEY
#define USE_ONLY_POWER_HOLD_CTRL
#define PWR_CTRL_P02
#define USE_PWR_KEY_LONG_PWR_ON
#define PWR_ON_DELAY_1_SECOND
//#define PWR_OFF_NO_RESP_WHEN_CHARGER_PLUGGED
#endif

#define TURN_ON_PLAY_BREAK_POINT_MEM
#define USE_BAT_MANAGEMENT
#define BAT_LEVEL_LED_ICON_IND
#define CHARGER_DETECT_INDICATOR
#define CHARGER_DET_USE_P04
#define CHARGER_FLASH_TYPE_2

#define IR_REMOTER_WITH_POWER_MUTE_PRINT
#define USE_IR_POWER_KEY_TO_POWER_OFF
#define POWER_KEY_SHORT_PWR_DOWN
#define USE_GPIO_DETECT_EARPHONE_PLUGGED
#define EARPHONE_DETECT_USE_P17

#undef USE_RDAs_FM
#undef USE_QN8035_FM
#define OTP_MUSIC_FUNC_ENABLE
#define OTP_DECODE_PLAY_FOLLOW_SYS_VOL
#define Lamborghini_voice
#endif

#ifdef K1197_JM_4444_V001

#ifdef IIC_GPIO_USE_P02_P03
#undef IIC_GPIO_USE_P02_P03
#endif
#define IIC_GPIO_USE_P00_P01

#ifdef MUTE_PORT_USE_P01
#undef  MUTE_PORT_USE_P01
#endif
#define MUTE_PORT_USE_P03

#define LED_GPIO_PORT_CUSTOMERIZED
#define LED_USE_PLAY_MODE
#define LED_USE_PLAY_MODE_NORMAL
#define PROTECT_P17_FROM_LED_SCAN

#define EXCHANGE_LINE_IN_CHANNEL	//交换LINE IN 通道

#define USE_MODE_KEY_LONG_SCAN
#define POWE_KEY_PLAY_KEY_IN_ONE_KEY

#define DISP_OFF_STR_AT_PWR_DOWN
#define DISP_PAUS_STRING
//#define FM_MAX_CHANNAL_50
#define ADKEY_PLAY_SHORT_ADJ_CH
#define CUSTOMER_DEFINED_ADKEY_RESISTOR
#define LOW_VOLT_SPARK_BAT_ICON
#define DISP_VOL_V_CHAR
#define DEFAULT_GO_TO_IDLE
#define DISP_HIFI_STR_AT_POWER_ON
#define NO_DEV_SHOW_HI_STR

#define LINE_IN_PLAY_KEY_PAUSE
#define USE_POWER_KEY_FOR_AUX_PLAY
#define FM_PLAY_KEY_PAUSE
#define USE_POWER_KEY_FOR_FM_PLAY


#define VOLUME_DEFUALT 	20
#define DISP_FM_STR_WHEN_PAUS

#if 1
#define USE_POWER_KEY
#define USE_ONLY_POWER_HOLD_CTRL
#define PWR_CTRL_P02
#define USE_PWR_KEY_LONG_PWR_ON
#define PWR_ON_DELAY_1_SECOND
//#define PWR_OFF_NO_RESP_WHEN_CHARGER_PLUGGED
#endif

#define TURN_ON_PLAY_BREAK_POINT_MEM
#define USE_BAT_MANAGEMENT
#define BAT_LEVEL_LED_ICON_IND
#define CHARGER_DETECT_INDICATOR
#define CHARGER_DET_USE_P04
#define CHARGER_FLASH_TYPE_2

#define IR_REMOTER_WITH_POWER_MUTE_PRINT
#define USE_IR_POWER_KEY_TO_POWER_OFF
#define POWER_KEY_SHORT_PWR_DOWN
#define USE_GPIO_DETECT_EARPHONE_PLUGGED
#define EARPHONE_DETECT_USE_P17

#undef USE_RDAs_FM
#undef USE_QN8035_FM
#define OTP_MUSIC_FUNC_ENABLE
#define OTP_DECODE_PLAY_FOLLOW_SYS_VOL
#define SAIL_YACHT_START
#endif

#ifdef K1197_DCX_855_V001

#ifdef IIC_GPIO_USE_P02_P03
#undef IIC_GPIO_USE_P02_P03
#endif
#define IIC_GPIO_USE_P00_P01

#ifdef MUTE_PORT_USE_P01
#undef  MUTE_PORT_USE_P01
#endif
#define MUTE_PORT_USE_P03

#define LED_GPIO_PORT_CUSTOMERIZED
#define LED_USE_PLAY_MODE
#define LED_MODE_EXCHANGE_TF_USB_ICON
#define PROTECT_P17_FROM_LED_SCAN

#define EXCHANGE_LINE_IN_CHANNEL	//交换LINE IN 通道

#define USE_MODE_KEY_LONG_SCAN
#define POWE_KEY_PLAY_KEY_IN_ONE_KEY

#define DISP_OFF_STR_AT_PWR_DOWN
#define DISP_PAUS_STRING
//#define FM_MAX_CHANNAL_50
#define ADKEY_PLAY_SHORT_ADJ_CH
#define CUSTOMER_DEFINED_ADKEY_RESISTOR
#define LOW_VOLT_SPARK_BAT_ICON
#define DISP_VOL_V_CHAR
#define DEFAULT_GO_TO_IDLE
#define DISP_HIFI_STR_AT_POWER_ON
#define NO_DEV_SHOW_HI_STR

#define LINE_IN_PLAY_KEY_PAUSE
#define USE_POWER_KEY_FOR_AUX_PLAY
#define FM_PLAY_KEY_PAUSE
#define USE_POWER_KEY_FOR_FM_PLAY


#define VOLUME_DEFUALT 	20
#define DISP_FM_STR_WHEN_PAUS

#if 1
#define USE_POWER_KEY
#define USE_ONLY_POWER_HOLD_CTRL
#define PWR_CTRL_P02
#define USE_PWR_KEY_LONG_PWR_ON
#define PWR_ON_DELAY_1_SECOND
//#define PWR_OFF_NO_RESP_WHEN_CHARGER_PLUGGED
#endif

#define TURN_ON_PLAY_BREAK_POINT_MEM
#define USE_BAT_MANAGEMENT
#define BAT_LEVEL_LED_ICON_IND
#define CHARGER_DETECT_INDICATOR
#define CHARGER_DET_USE_P04
#define CHARGER_FLASH_TYPE_2

#define IR_REMOTER_WITH_POWER_MUTE_PRINT
#define USE_IR_POWER_KEY_TO_POWER_OFF
#define POWER_KEY_SHORT_PWR_DOWN
#define USE_GPIO_DETECT_EARPHONE_PLUGGED
#define EARPHONE_DETECT_USE_P17

#undef USE_RDAs_FM
#undef USE_QN8035_FM
#define OTP_MUSIC_FUNC_ENABLE
#define OTP_DECODE_PLAY_FOLLOW_SYS_VOL
#define SAIL_START
#endif


#ifdef K1195_YJH_11830_V001

#ifdef IIC_GPIO_USE_P02_P03
#undef IIC_GPIO_USE_P02_P03
#endif
#define IIC_GPIO_USE_P00_P01

#ifdef MUTE_PORT_USE_P01
#undef  MUTE_PORT_USE_P01
#endif
#define MUTE_PORT_USE_P03


//#define LED_USE_PLAY_MODE
//#define LED_MODE_EXCHANGE_TF_USB_ICON

#define EXCHANGE_LINE_IN_CHANNEL	//交换LINE IN 通道


#define DISP_VOL_V_CHAR

#define LINE_IN_PLAY_KEY_PAUSE

#define USE_LONG_PLAY_MODE_KEY_TO_SWITCH_MODE

#define USE_BAT_MANAGEMENT
#define BAT_LEVEL_LED_ICON_IND
#define CHARGER_DETECT_INDICATOR
#define CHARGER_DET_USE_P17
#define CHARGER_FLASH_TYPE_2
#define LOW_VOLT_SPARK_BAT_ICON

#define USE_LINE_IN_DETECT_FUNC
#define AUX_DETECT_USE_P07
#endif

#ifdef K3025_YL_3025_V001

#ifdef IIC_GPIO_USE_P02_P03
#undef IIC_GPIO_USE_P02_P03
#endif
#define IIC_GPIO_USE_P00_P01

#ifdef MUTE_PORT_USE_P01
#undef  MUTE_PORT_USE_P01
#endif
#define MUTE_PORT_USE_P03


//#define LED_USE_PLAY_MODE
//#define LED_MODE_EXCHANGE_TF_USB_ICON

#define EXCHANGE_LINE_IN_CHANNEL	//交换LINE IN 通道
//#define DEFAULT_GO_TO_IDLE

#define USE_MODE_KEY_LONG_SCAN
#define POWE_KEY_PLAY_KEY_IN_ONE_KEY

#define DISP_OFF_STR_AT_PWR_DOWN
#define DISP_PAUS_STRING
#define ADKEY_PLAY_SHORT_ADJ_CH
#define CUSTOMER_DEFINED_ADKEY_RESISTOR
#define LOW_VOLT_SPARK_BAT_ICON
#define DISP_VOL_V_CHAR

#define LINE_IN_PLAY_KEY_PAUSE
#define USE_POWER_KEY_FOR_AUX_PLAY

//#define DISP_HIFI_STR_AT_POWER_ON
//#define VOLUME_CUSTOMER_DEFINE_32

#if 1
#define USE_POWER_KEY
#define USE_ONLY_POWER_HOLD_CTRL
#define PWR_CTRL_P02
#define USE_PWR_KEY_LONG_PWR_ON
#define PWR_ON_DELAY_1_SECOND
//#define PWR_OFF_NO_RESP_WHEN_CHARGER_PLUGGED
#endif

#define USE_BAT_MANAGEMENT
#define BAT_LEVEL_LED_ICON_IND
#define CHARGER_DETECT_INDICATOR
#define CHARGER_DET_USE_P04
#define CHARGER_FLASH_TYPE_2
#define LOW_VOLT_SPARK_BAT_ICON

#define USE_GPIO_DETECT_EARPHONE_PLUGGED
#define EARPHONE_DETECT_USE_P07
#define USE_LINE_IN_DETECT_FUNC
#define AUX_DETECT_USE_VPP
#define PLAY_STATUS_LED_P17

#endif


#ifdef K3021_AP_LG836_V001

#define LED_GPIO_PORT_CUSTOMERIZED
#define LED_USE_PLAY_MODE_MIXED
#define USE_GPIO_DETECT_EARPHONE_PLUGGED
#define XINLEI_LED_DRIVE_TYPE
#define EARPHONE_DETECT_USE_P03
#define USE_LINE_IN_DETECT_FUNC
#define AUX_DETECT_USE_P07
#define EXCHANGE_LINE_IN_CHANNEL	//交换LINE IN 通道

#define CUSTOMER_DEFINED_ADKEY_RESISTOR
#define ADKEY_NEW_METHOD
#define EXTENDED_ADKEY_NUM
#define FM_MAX_CHANNAL_50
#define PAUSE_FLASH_WHOLE_SCREEN

#define LINE_IN_PLAY_KEY_PAUSE
#define FM_PLAY_KEY_PAUSE
#define PAUSE_FLASH_WHOLE_SCREEN
#define NO_FLASH_MP3_SCREEN
#define DISP_SCH_AT_FM_SCAN
#define DISP_PAU_STRING_ONLY_IN_FM_MODE
#define INDEPENDENT_VOLUME_KEY
#define ADKEY_NEXT_PREV_15_SONG
#define NO_VOLUME_LIMITE

#endif

#ifdef K1186_ZK_990_V001

#ifdef IIC_GPIO_USE_P02_P03
#undef IIC_GPIO_USE_P02_P03
#endif
#define IIC_GPIO_USE_P00_P01

#ifdef MUTE_PORT_USE_P01
#undef  MUTE_PORT_USE_P01
#endif
#define MUTE_PORT_USE_P03

#define LED_GPIO_PORT_CUSTOMERIZED

#define LED_USE_PLAY_MODE
#define LED_MODE_EXCHANGE_TF_USB_ICON

#define EXCHANGE_LINE_IN_CHANNEL	//交换LINE IN 通道
#define DEFAULT_GO_TO_IDLE

#define USE_MODE_KEY_LONG_SCAN
#define POWE_KEY_PLAY_KEY_IN_ONE_KEY

#define DISP_OFF_STR_AT_PWR_DOWN
#define NO_DEV_SHOW_HI_STR
#define DISP_PAUS_STRING
#define ADKEY_PLAY_SHORT_ADJ_CH
#define CUSTOMER_DEFINED_ADKEY_RESISTOR
#define LOW_VOLT_SPARK_BAT_ICON
#define DISP_VOL_V_CHAR

#define LINE_IN_PLAY_KEY_PAUSE
#define FM_PLAY_KEY_PAUSE
#define USE_POWER_KEY_FOR_AUX_PLAY
#define USE_POWER_KEY_FOR_FM_PLAY

#define DISP_HIFI_STR_AT_POWER_ON
#define VOLUME_CUSTOMER_DEFINE_32
#define DISP_FM_STR_WHEN_PAUS

#if 1
#define USE_POWER_KEY
#define USE_ONLY_POWER_HOLD_CTRL
#define PWR_CTRL_P02
#define USE_PWR_KEY_LONG_PWR_ON
#define PWR_ON_DELAY_1_SECOND
//#define PWR_OFF_NO_RESP_WHEN_CHARGER_PLUGGED
#endif

#define USE_BAT_MANAGEMENT
#define BAT_LEVEL_LED_ICON_IND
#define CHARGER_DETECT_INDICATOR
#define CHARGER_DET_USE_P04
#define CHARGER_FLASH_TYPE_2
#define LOW_VOLT_SPARK_BAT_ICON

#define Lamborghini_voice
#define OTP_MUSIC_FUNC_ENABLE
#endif

#ifdef K1186_YJH_866_V001

#ifdef IIC_GPIO_USE_P02_P03
#undef IIC_GPIO_USE_P02_P03
#endif
#define IIC_GPIO_USE_P00_P01

#ifdef MUTE_PORT_USE_P01
#undef  MUTE_PORT_USE_P01
#endif
#define MUTE_PORT_USE_P03

#define LED_GPIO_PORT_CUSTOMERIZED

#define LED_USE_PLAY_MODE
#define LED_USE_PLAY_MODE_NORMAL

#define EXCHANGE_LINE_IN_CHANNEL	//交换LINE IN 通道


#define USE_MODE_KEY_LONG_SCAN
#define POWE_KEY_PLAY_KEY_IN_ONE_KEY

#define DISP_OFF_STR_AT_PWR_DOWN
#define NO_DEV_SHOW_HI_STR
#define DISP_PAUS_STRING
#define ADKEY_PLAY_SHORT_ADJ_CH
#define CUSTOMER_DEFINED_ADKEY_RESISTOR
#define LOW_VOLT_SPARK_BAT_ICON
#define DISP_VOL_V_CHAR

#define LINE_IN_PLAY_KEY_PAUSE
#define FM_PLAY_KEY_PAUSE
#define USE_POWER_KEY_FOR_AUX_PLAY
#define USE_POWER_KEY_FOR_FM_PLAY

#define DISP_HIFI_STR_AT_POWER_ON
#define VOLUME_CUSTOMER_DEFINE_32
#define DISP_FM_STR_WHEN_PAUS

#if 1
#define USE_POWER_KEY
#define USE_ONLY_POWER_HOLD_CTRL
#define PWR_CTRL_P02
#define USE_PWR_KEY_LONG_PWR_ON
#define PWR_ON_DELAY_1_SECOND
//#define PWR_OFF_NO_RESP_WHEN_CHARGER_PLUGGED
#endif

#define USE_BAT_MANAGEMENT
#define BAT_LEVEL_LED_ICON_IND
#define CHARGER_DETECT_INDICATOR
#define CHARGER_DET_USE_P04
#define CHARGER_FLASH_TYPE_2

#if 1
#undef USE_RDAs_FM
#undef USE_QN8035_FM
#define OTP_MUSIC_FUNC_ENABLE
#define OTP_DECODE_PLAY_FOLLOW_SYS_VOL
#define XIAO_SAN_MADA
#endif

#define DEFAULT_GO_TO_TIME_MODE

#define USE_RTC_FUNCTION
#define USE_RTC_TIME_ONLY
#define USE_RTC_ALARM_FUNCTION
#define USE_RTC_ALM_CUSTOM_INIT
#define USE_MODE_LONG_FOR_RTC_SETTING
#define USE_POWER_KEY_TO_ADJ_HOUR_AND_MIN
#endif

#ifdef K1186_YJH_1186_V001

#ifdef IIC_GPIO_USE_P02_P03
#undef IIC_GPIO_USE_P02_P03
#endif
#define IIC_GPIO_USE_P00_P01

#ifdef MUTE_PORT_USE_P01
#undef  MUTE_PORT_USE_P01
#endif
#define MUTE_PORT_USE_P03

#define LED_GPIO_PORT_CUSTOMERIZED

#define LED_USE_PLAY_MODE
#define LED_USE_PLAY_MODE_NORMAL

#define EXCHANGE_LINE_IN_CHANNEL	//交换LINE IN 通道
#define DEFAULT_GO_TO_IDLE

#define USE_MODE_KEY_LONG_SCAN
#define POWE_KEY_PLAY_KEY_IN_ONE_KEY

#define DISP_OFF_STR_AT_PWR_DOWN
#define NO_DEV_SHOW_HI_STR
#define DISP_PAUS_STRING
#define ADKEY_PLAY_SHORT_ADJ_CH
#define CUSTOMER_DEFINED_ADKEY_RESISTOR
#define LOW_VOLT_SPARK_BAT_ICON
#define DISP_VOL_V_CHAR

#define LINE_IN_PLAY_KEY_PAUSE
#define FM_PLAY_KEY_PAUSE
#define USE_POWER_KEY_FOR_AUX_PLAY
#define USE_POWER_KEY_FOR_FM_PLAY

#define DISP_HIFI_STR_AT_POWER_ON
#define VOLUME_CUSTOMER_DEFINE_32
#define DISP_FM_STR_WHEN_PAUS

#if 1
#define USE_POWER_KEY
#define USE_ONLY_POWER_HOLD_CTRL
#define PWR_CTRL_P02
#define USE_PWR_KEY_LONG_PWR_ON
#define PWR_ON_DELAY_1_SECOND
//#define PWR_OFF_NO_RESP_WHEN_CHARGER_PLUGGED
#endif

#define USE_BAT_MANAGEMENT
#define BAT_LEVEL_LED_ICON_IND
#define CHARGER_DETECT_INDICATOR
#define CHARGER_DET_USE_P04
#define CHARGER_FLASH_TYPE_2

#endif

#ifdef K1182_ZK_985B_V002

#ifdef IIC_GPIO_USE_P02_P03
#undef IIC_GPIO_USE_P02_P03
#endif
#define IIC_GPIO_USE_P00_P01

#ifdef MUTE_PORT_USE_P01
#undef  MUTE_PORT_USE_P01
#endif
#define MUTE_PORT_USE_P03

#define LED_GPIO_PORT_CUSTOMERIZED

#define LED_USE_PLAY_MODE
#define LED_MODE_EXCHANGE_TF_USB_ICON

#define EXCHANGE_LINE_IN_CHANNEL	//交换LINE IN 通道
#define DEFAULT_GO_TO_IDLE
#define FM_MAX_CHANNAL_50

#define POWE_KEY_PLAY_KEY_IN_ONE_KEY

#define DISP_OFF_STR_AT_PWR_DOWN
#define NO_DEV_SHOW_HI_STR
#define DISP_PAUS_STRING
#define ADKEY_PLAY_SHORT_ADJ_CH
#define CUSTOMER_DEFINED_ADKEY_RESISTOR
#define LOW_VOLT_SPARK_BAT_ICON
#define DISP_VOL_V_CHAR

#define LINE_IN_PLAY_KEY_PAUSE
//#define FM_PLAY_KEY_PAUSE
#define USE_POWER_KEY_FOR_AUX_PLAY
#define USE_POWER_KEY_SHORT_SCAN

#define VOLUME_CUSTOMER_DEFINE_32
#define DISP_FM_STR_WHEN_PAUS

#if 1
#define USE_POWER_KEY
#define USE_ONLY_POWER_HOLD_CTRL
#define PWR_CTRL_P02
#define USE_PWR_KEY_LONG_PWR_ON
#define PWR_ON_DELAY_1_SECOND
//#define PWR_OFF_NO_RESP_WHEN_CHARGER_PLUGGED
#endif

#define USE_BAT_MANAGEMENT
#define BAT_LEVEL_LED_ICON_IND
#define CHARGER_DETECT_INDICATOR
#define CHARGER_DET_USE_P04
#define CHARGER_FLASH_TYPE_2

#define USE_LINE_IN_DETECT_FUNC
#define AUX_DETECT_USE_P34


#define Lamborghini_voice
#define OTP_MUSIC_FUNC_ENABLE

#endif

#ifdef K1182_ZK_1182_V001

#ifdef IIC_GPIO_USE_P02_P03
#undef IIC_GPIO_USE_P02_P03
#endif
#define IIC_GPIO_USE_P00_P01

#ifdef MUTE_PORT_USE_P01
#undef  MUTE_PORT_USE_P01
#endif
#define MUTE_PORT_USE_P03

#define LED_GPIO_PORT_CUSTOMERIZED

#define LED_USE_PLAY_MODE
#define LED_MODE_EXCHANGE_TF_USB_ICON

#define EXCHANGE_LINE_IN_CHANNEL	//交换LINE IN 通道
#define DEFAULT_GO_TO_IDLE

#define USE_MODE_KEY_LONG_SCAN
#define POWE_KEY_PLAY_KEY_IN_ONE_KEY

#define DISP_OFF_STR_AT_PWR_DOWN
#define NO_DEV_SHOW_HI_STR
#define DISP_PAUS_STRING
#define ADKEY_PLAY_SHORT_ADJ_CH
#define CUSTOMER_DEFINED_ADKEY_RESISTOR
#define LOW_VOLT_SPARK_BAT_ICON
#define DISP_VOL_V_CHAR

#define LINE_IN_PLAY_KEY_PAUSE
#define FM_PLAY_KEY_PAUSE
#define USE_POWER_KEY_FOR_AUX_PLAY
#define USE_POWER_KEY_FOR_FM_PLAY

#define VOLUME_CUSTOMER_DEFINE_32
#define DISP_FM_STR_WHEN_PAUS

#if 1
#define USE_POWER_KEY
#define USE_ONLY_POWER_HOLD_CTRL
#define PWR_CTRL_P02
#define USE_PWR_KEY_LONG_PWR_ON
#define PWR_ON_DELAY_1_SECOND
//#define PWR_OFF_NO_RESP_WHEN_CHARGER_PLUGGED
#endif

#define USE_BAT_MANAGEMENT
#define BAT_LEVEL_LED_ICON_IND
#define CHARGER_DETECT_INDICATOR
#define CHARGER_DET_USE_P04
#define CHARGER_FLASH_TYPE_2

#define USE_LINE_IN_DETECT_FUNC
#define AUX_DETECT_USE_P34


#define Lamborghini_voice
#define OTP_MUSIC_FUNC_ENABLE

#endif

#ifdef K1182_YL_1182_V001

#ifdef IIC_GPIO_USE_P02_P03
#undef IIC_GPIO_USE_P02_P03
#endif
#define IIC_GPIO_USE_P00_P01

#ifdef MUTE_PORT_USE_P01
#undef  MUTE_PORT_USE_P01
#endif
#define MUTE_PORT_USE_P03

#define LED_GPIO_PORT_CUSTOMERIZED

#define LED_USE_PLAY_MODE
#define LED_USE_PLAY_MODE_NORMAL

#define EXCHANGE_LINE_IN_CHANNEL	//交换LINE IN 通道
#define DEFAULT_GO_TO_IDLE

#define USE_MODE_KEY_LONG_SCAN
#define POWE_KEY_PLAY_KEY_IN_ONE_KEY

#define DISP_OFF_STR_AT_PWR_DOWN
#define NO_DEV_SHOW_HI_STR
#define DISP_PAUS_STRING
#define ADKEY_PLAY_SHORT_ADJ_CH
#define CUSTOMER_DEFINED_ADKEY_RESISTOR
#define LOW_VOLT_SPARK_BAT_ICON
#define DISP_VOL_V_CHAR

#define LINE_IN_PLAY_KEY_PAUSE
#define FM_PLAY_KEY_PAUSE
#define USE_POWER_KEY_FOR_AUX_PLAY
#define USE_POWER_KEY_FOR_FM_PLAY

#define DISP_HIFI_STR_AT_POWER_ON
#define VOLUME_CUSTOMER_DEFINE_32
#define DISP_FM_STR_WHEN_PAUS

#if 1
#define USE_POWER_KEY
#define USE_ONLY_POWER_HOLD_CTRL
#define PWR_CTRL_P02
#define USE_PWR_KEY_LONG_PWR_ON
#define PWR_ON_DELAY_1_SECOND
//#define PWR_OFF_NO_RESP_WHEN_CHARGER_PLUGGED
#endif

#define USE_BAT_MANAGEMENT
#define BAT_LEVEL_LED_ICON_IND
#define CHARGER_DETECT_INDICATOR
#define CHARGER_DET_USE_P04
#define CHARGER_FLASH_TYPE_2

#define USE_LINE_IN_DETECT_FUNC
#define AUX_DETECT_USE_P34

#define Lamborghini_voice
#define OTP_MUSIC_FUNC_ENABLE
#endif

#ifdef K1182_YJH_867_V001

#ifdef IIC_GPIO_USE_P02_P03
#undef IIC_GPIO_USE_P02_P03
#endif
#define IIC_GPIO_USE_P00_P01

#ifdef MUTE_PORT_USE_P01
#undef  MUTE_PORT_USE_P01
#endif
#define MUTE_PORT_USE_P03

#define LED_GPIO_PORT_CUSTOMERIZED

#define LED_USE_PLAY_MODE
#define LED_USE_PLAY_MODE_NORMAL

#define EXCHANGE_LINE_IN_CHANNEL	//交换LINE IN 通道
#define DEFAULT_GO_TO_IDLE

#define USE_MODE_KEY_LONG_SCAN
#define POWE_KEY_PLAY_KEY_IN_ONE_KEY

#define DISP_OFF_STR_AT_PWR_DOWN
#define NO_DEV_SHOW_HI_STR
#define DISP_PAUS_STRING
#define ADKEY_PLAY_SHORT_ADJ_CH
#define CUSTOMER_DEFINED_ADKEY_RESISTOR
#define LOW_VOLT_SPARK_BAT_ICON
#define DISP_VOL_V_CHAR

#define LINE_IN_PLAY_KEY_PAUSE
#define FM_PLAY_KEY_PAUSE
#define USE_POWER_KEY_FOR_AUX_PLAY
#define USE_POWER_KEY_FOR_FM_PLAY

#define DISP_HIFI_STR_AT_POWER_ON
#define VOLUME_CUSTOMER_DEFINE_32
#define DISP_FM_STR_WHEN_PAUS

#if 1
#define USE_POWER_KEY
#define USE_ONLY_POWER_HOLD_CTRL
#define PWR_CTRL_P02
#define USE_PWR_KEY_LONG_PWR_ON
#define PWR_ON_DELAY_1_SECOND
//#define PWR_OFF_NO_RESP_WHEN_CHARGER_PLUGGED
#endif

#define USE_BAT_MANAGEMENT
#define BAT_LEVEL_LED_ICON_IND
#define CHARGER_DETECT_INDICATOR
#define CHARGER_DET_USE_P04
#define CHARGER_FLASH_TYPE_2

#define USE_LINE_IN_DETECT_FUNC
#define AUX_DETECT_USE_P34

#if 1
#undef USE_RDAs_FM
#undef USE_QN8035_FM
#define OTP_MUSIC_FUNC_ENABLE
#define OTP_DECODE_PLAY_FOLLOW_SYS_VOL
#define XIAO_SAN_MADA
#endif

#define USE_RTC_FUNCTION
#define USE_RTC_TIME_ONLY
#define USE_RTC_ALARM_FUNCTION
#define USE_RTC_ALM_CUSTOM_INIT

#define USE_MODE_LONG_FOR_RTC_SETTING
#define USE_POWER_KEY_TO_ADJ_HOUR_AND_MIN

#endif
#ifdef K1182_YJH_1182_V001

#ifdef IIC_GPIO_USE_P02_P03
#undef IIC_GPIO_USE_P02_P03
#endif
#define IIC_GPIO_USE_P00_P01

#ifdef MUTE_PORT_USE_P01
#undef  MUTE_PORT_USE_P01
#endif
#define MUTE_PORT_USE_P03

#define LED_GPIO_PORT_CUSTOMERIZED

#define LED_USE_PLAY_MODE
#define LED_USE_PLAY_MODE_NORMAL

#define EXCHANGE_LINE_IN_CHANNEL	//交换LINE IN 通道
#define DEFAULT_GO_TO_IDLE

#define USE_MODE_KEY_LONG_SCAN
#define POWE_KEY_PLAY_KEY_IN_ONE_KEY

#define DISP_OFF_STR_AT_PWR_DOWN
#define NO_DEV_SHOW_HI_STR
#define DISP_PAUS_STRING
#define ADKEY_PLAY_SHORT_ADJ_CH
#define CUSTOMER_DEFINED_ADKEY_RESISTOR
#define LOW_VOLT_SPARK_BAT_ICON
#define DISP_VOL_V_CHAR

#define LINE_IN_PLAY_KEY_PAUSE
#define FM_PLAY_KEY_PAUSE
#define USE_POWER_KEY_FOR_AUX_PLAY
#define USE_POWER_KEY_FOR_FM_PLAY

#define DISP_HIFI_STR_AT_POWER_ON
#define VOLUME_CUSTOMER_DEFINE_32
#define DISP_FM_STR_WHEN_PAUS

#if 1
#define USE_POWER_KEY
#define USE_ONLY_POWER_HOLD_CTRL
#define PWR_CTRL_P02
#define USE_PWR_KEY_LONG_PWR_ON
#define PWR_ON_DELAY_1_SECOND
//#define PWR_OFF_NO_RESP_WHEN_CHARGER_PLUGGED
#endif

#define USE_BAT_MANAGEMENT
#define BAT_LEVEL_LED_ICON_IND
#define CHARGER_DETECT_INDICATOR
#define CHARGER_DET_USE_P04
#define CHARGER_FLASH_TYPE_2

#define USE_LINE_IN_DETECT_FUNC
#define AUX_DETECT_USE_P34

#endif

#ifdef K2059_SES_6038_V001

#ifdef IIC_GPIO_USE_P02_P03
#undef IIC_GPIO_USE_P02_P03
#endif
#define IIC_GPIO_USE_P00_P01

#ifdef MUTE_PORT_USE_P01
#undef  MUTE_PORT_USE_P01
#endif
#define MUTE_PORT_USE_P03

#define LED_GPIO_PORT_CUSTOMERIZED
#define LED_COMMON_SCAN_COM_USE_P17

#define PLAY_STATUS_LED_P04

#define DISP_PAUS_STRING
#define DISP_VOL_V_CHAR
#define VOLUME_DEFUALT 	30
#define DISP_PC_STR
#define CUSTOMER_DEFINED_ADKEY_RESISTOR
#define INDEPENDENT_VOLUME_KEY
#define RADIO_MODE_HOT_KEY_ENABLE
#define JINRUI_IR_REMOTE_TYPE
#define VOL_TUNE_FREQ_ONLY
#define DECODE_STOP_MODE_ENABLE
//#define JOG_STICK_FUNC
#define FM_MAX_CHANNAL_50
#define FAST_BAND_SCAN_SPEED

#define EXCHANGE_FM_MP3_ICON

#define ADKEY_PLAY_SHORT_SCAN_FRE

#define EXCHANGE_LINE_IN_CHANNEL	//交换LINE IN 通道

#define USE_GPIO_DETECT_EARPHONE_PLUGGED
#define EARPHONE_DETECT_USE_P07

#define USE_AMP_MODE_SELECT
#define AMP_MODE_SELECT_PORT_USE_P34
#define INVERT_LED_IN_USE
#define TURN_ON_PLAY_BREAK_POINT_MEM


#endif

#ifdef K6037_SES_6037_V001

#ifdef IIC_GPIO_USE_P02_P03
#undef IIC_GPIO_USE_P02_P03
#endif
#define IIC_GPIO_USE_P00_P01

#ifdef MUTE_PORT_USE_P01
#undef  MUTE_PORT_USE_P01
#endif
#define MUTE_PORT_USE_P03

#define LED_GPIO_PORT_CUSTOMERIZED
#define LED_COMMON_SCAN_COM_USE_P17

#define NO_PLAY_STATUS_LED

#define DISP_PAUS_STRING
#define DISP_VOL_V_CHAR
#define VOLUME_DEFUALT 	30
#define DISP_PC_STR
#define CUSTOMER_DEFINED_ADKEY_RESISTOR
#define INDEPENDENT_VOLUME_KEY
#define RADIO_MODE_HOT_KEY_ENABLE
#define JINRUI_IR_REMOTE_TYPE
#define VOL_TUNE_FREQ_ONLY
#define DECODE_STOP_MODE_ENABLE
#define JOG_STICK_FUNC
#define FM_MAX_CHANNAL_50
#define FAST_BAND_SCAN_SPEED

#define EXCHANGE_FM_MP3_ICON

#define ADKEY_PLAY_SHORT_SCAN_FRE

#define EXCHANGE_LINE_IN_CHANNEL	//交换LINE IN 通道

#define USE_GPIO_DETECT_EARPHONE_PLUGGED
#define EARPHONE_DETECT_USE_P07

#define USE_AMP_MODE_SELECT
#define AMP_MODE_SELECT_PORT_USE_P34
#define TURN_ON_PLAY_BREAK_POINT_MEM

#endif

#ifdef K1177_HF_BJD_V3_V001

#ifdef IIC_GPIO_USE_P02_P03
#undef IIC_GPIO_USE_P02_P03
#endif
#define IIC_GPIO_USE_P00_P01
#ifdef MUTE_PORT_USE_P01
#undef  MUTE_PORT_USE_P01
#endif
#define MUTE_PORT_USE_P03
#define EXCHANGE_LINE_IN_CHANNEL	//交换LINE IN 通道

#define LED_GPIO_PORT_CUSTOMERIZED
//#define LED_COMMON_SCAN_COM_USE_P17
#define LED_USE_PLAY_MODE
#define LED_USE_PLAY_MODE_NORMAL

#define DISP_PAUS_STRING
#define DISP_VOL_V_CHAR

#define DISP_OFF_STR_AT_PWR_DOWN
#define ADKEY_PLAY_SHORT_SCAN_FRE
//#define JOG_STICK_FUNC
//#define USE_GPIO_DETECT_EARPHONE_PLUGGED
#define USE_AMP_MODE_SELECT
#define USE_IR_POWER_KEY_TO_POWER_OFF
#if 1
#define USE_POWER_KEY
#define USE_ONLY_POWER_HOLD_CTRL
#define PWR_CTRL_P02
#define USE_PWR_KEY_LONG_PWR_ON
#define PWR_ON_DELAY_1_SECOND
#endif

#if 1
#define USE_BAT_MANAGEMENT
#define BAT_LEVEL_LED_ICON_IND
#define CHARGER_DETECT_INDICATOR
#define CHARGER_DET_USE_P04
#define CHARGER_FLASH_TYPE_1
#define PROTECT_P17_FROM_LED_SCAN
#define LOW_VOLT_SPARK_BAT_ICON
#endif

#define Lamborghini_voice
#define OTP_MUSIC_FUNC_ENABLE

#define POWE_KEY_PLAY_KEY_IN_ONE_KEY
#define USE_POWER_KEY_SHORT_SCAN

#define CUSTOMER_DEFINED_ADKEY_RESISTOR
#endif


#ifdef K2094_DYT_2094_V002

#ifdef IIC_GPIO_USE_P02_P03
#undef IIC_GPIO_USE_P02_P03
#endif
#define IIC_GPIO_USE_P00_P01

#ifdef MUTE_PORT_USE_P01
#undef  MUTE_PORT_USE_P01
#endif
#define MUTE_PORT_USE_P03

#define LED_GPIO_PORT_CUSTOMERIZED
#define LED_COMMON_SCAN_COM_USE_P17

//#define NO_PLAY_STATUS_LED
#define PLAY_STATUS_LED_WAKP_PIN
#define DISP_PAUS_STRING
#define DISP_VOL_V_CHAR
#define VOLUME_DEFUALT 	30
#define DISP_PC_STR
#define CUSTOMER_DEFINED_ADKEY_RESISTOR


#define ADKEY_PLAY_SHORT_SCAN_FRE
#define EXCHANGE_LINE_IN_CHANNEL	//交换LINE IN 通道

//#define INDEPENDENT_VOLUME_KEY
#define FM_BY_PASS

#define LINE_IN_PLAY_KEY_PAUSE

#if 1
#define USE_POWER_KEY
#define USE_ONLY_POWER_HOLD_CTRL
#define PWR_CTRL_P02
#define USE_PWR_KEY_LONG_PWR_ON
#define PWR_ON_DELAY_1_SECOND
#endif


#define USE_RTC_FUNCTION
#define USE_RTC_TIME_ONLY
#define USE_RTC_ALARM_FUNCTION
#define USE_RTC_ALM_CUSTOM_INIT
#if 0
#define BLUE_TOOTH_FUNC
#define BLUETOOTH_GPIO_CTRL
#define DISP_BLUE_STR
#define BLUE_TOOTH_KEY_DELAY_25MS
#endif

#endif
#ifdef K2094_DYT_2094_V001

#ifdef IIC_GPIO_USE_P02_P03
#undef IIC_GPIO_USE_P02_P03
#endif
#define IIC_GPIO_USE_P00_P01

#ifdef MUTE_PORT_USE_P01
#undef  MUTE_PORT_USE_P01
#endif
#define MUTE_PORT_USE_P03

#define LED_GPIO_PORT_CUSTOMERIZED
#define LED_COMMON_SCAN_COM_USE_P17

#define NO_PLAY_STATUS_LED

#define DISP_PAUS_STRING
#define DISP_VOL_V_CHAR
#define VOLUME_DEFUALT 	30
#define DISP_PC_STR
#define CUSTOMER_DEFINED_ADKEY_RESISTOR


#define ADKEY_PLAY_SHORT_SCAN_FRE
#define EXCHANGE_LINE_IN_CHANNEL	//交换LINE IN 通道

//#define INDEPENDENT_VOLUME_KEY
#define FM_BY_PASS

#define LINE_IN_PLAY_KEY_PAUSE

#if 1
#define USE_POWER_KEY
#define USE_ONLY_POWER_HOLD_CTRL
#define PWR_CTRL_P02
#define USE_PWR_KEY_LONG_PWR_ON
#define PWR_ON_DELAY_1_SECOND
#endif


#define USE_RTC_FUNCTION
#define USE_RTC_TIME_ONLY
#define USE_RTC_ALARM_FUNCTION
#define USE_RTC_ALM_CUSTOM_INIT
#if 1
#define BLUE_TOOTH_FUNC
#define BLUETOOTH_GPIO_CTRL
#define DISP_BLUE_STR
#define BLUE_TOOTH_KEY_DELAY_25MS
#endif

#endif

#ifdef K2086_AJR_LS091_V001

#ifdef IIC_GPIO_USE_P02_P03
#undef IIC_GPIO_USE_P02_P03
#endif
#define IIC_GPIO_USE_P00_P01

#ifdef MUTE_PORT_USE_P01
#undef  MUTE_PORT_USE_P01
#endif
#define MUTE_PORT_USE_P03

#define LED_GPIO_PORT_CUSTOMERIZED
#define LED_COMMON_SCAN_COM_USE_P17
#define COMMON_CATHODE

#define NO_PLAY_STATUS_LED


#define DISP_PAUS_STRING
#define DISP_VOL_V_CHAR
#define VOLUME_DEFUALT 	30
#define DISP_PC_STR
#define CUSTOMER_DEFINED_ADKEY_RESISTOR

#define NEW_SD_DETECT_MOD
#define EXCHANGE_FM_MP3_ICON
#define RADIO_AM_WM_ENABLE
#define FM_USE_BK1086

#define FM_MAX_CHANNAL_60

#define ADKEY_PLAY_SHORT_SCAN_FRE
#define RADIO_MODE_HOT_KEY_ENABLE
#define RADIO_AM_WM_SEL_IN_ONE_KEY

#define EXCHANGE_LINE_IN_CHANNEL	//交换LINE IN 通道
#define USE_GPIO_DETECT_EARPHONE_PLUGGED
#define EARPHONE_DETECT_USE_P34
#define INDEPENDENT_VOLUME_KEY

#define LINE_IN_PLAY_KEY_PAUSE

#if 0
#define USE_BAT_MANAGEMENT
#define BAT_LEVEL_LED_ICON_IND
#define CHARGER_DETECT_INDICATOR
#define CHARGER_DET_USE_P07
#endif

#define NEXT_PREV_HOLD_FOR_MUSIC_FFR
#define JOG_STICK_FUNC
#define VOL_TUNE_FREQ_ONLY

#endif

#ifdef K1173_ZK_ALK936_V001

#ifdef IIC_GPIO_USE_P02_P03
#undef IIC_GPIO_USE_P02_P03
#endif
#define IIC_GPIO_USE_P00_P01

#ifdef MUTE_PORT_USE_P01
#undef  MUTE_PORT_USE_P01
#endif
#define MUTE_PORT_USE_P03

#define PLAY_STATUS_LED_P02

#define LED_GPIO_PORT_CUSTOMERIZED
#define LED_COMMON_SCAN_COM_USE_P17

#define USE_GPIO_DETECT_EARPHONE_PLUGGED
#define EARPHONE_DETECT_USE_P04

#define EXCHANGE_LINE_IN_CHANNEL	//交换LINE IN 通道

#define CUSTOMER_DEFINED_ADKEY_RESISTOR
#define TWO_ADKEY_ENABLE
#define TWO_ADKEY_USE_PORT_P07


#define DISP_VOL_V_CHAR
#define NO_DEV_SHOW_HI_STR
#define DISP_PAUS_STRING
#define FM_MAX_CHANNAL_50
#define ADKEY_PLAY_SHORT_ADJ_CH
#define DEFAULT_GO_TO_IDLE
#define DISP_OFF_STR_AT_PWR_DOWN

#if 0
#define USE_POWER_KEY
#define USE_ONLY_POWER_HOLD_CTRL
#define PWR_CTRL_P17
#define USE_PWR_KEY_LONG_PWR_ON
#define PWR_ON_DELAY_1_SECOND
#endif

#if 0
#define USE_BAT_MANAGEMENT
#define BAT_LEVEL_LED_ICON_IND
#define CHARGER_DETECT_INDICATOR
#define PROTECT_P17_FROM_LED_SCAN
#define CHARGER_DET_USE_P17
#define CHARGER_FLASH_TYPE_2
#define LOW_VOLT_SPARK_BAT_ICON
#endif

#endif


#ifdef K1174_SES_2012_V001

#ifdef IIC_GPIO_USE_P02_P03
#undef IIC_GPIO_USE_P02_P03
#endif
#define IIC_GPIO_USE_P00_P01

#ifdef MUTE_PORT_USE_P01
#undef  MUTE_PORT_USE_P01
#endif
#define MUTE_PORT_USE_P03

#define LED_GPIO_PORT_CUSTOMERIZED
#define LED_COMMON_SCAN_COM_USE_P17

#define NO_PLAY_STATUS_LED

#define DISP_PAUS_STRING
#define DISP_VOL_V_CHAR
#define VOLUME_DEFUALT 	30
#define DISP_PC_STR

#define EXCHANGE_LINE_IN_CHANNEL	//交换LINE IN 通道

#define LINE_IN_PLAY_KEY_PAUSE

#define EXCHANGE_FM_MP3_ICON
//#define USE_LINE_IN_DETECT_FUNC
//#define AUX_DETECT_USE_P02
#define LINE_IN_PLAY_KEY_PAUSE


#define USE_GPIO_DETECT_EARPHONE_PLUGGED
#define EARPHONE_DETECT_USE_P04
#endif

#ifdef K1204_SES_2012_V001

#define AC209_28PIN
#define LED_1651_DRV
#ifdef LED_GPIO_DRV
#undef LED_GPIO_DRV
#endif

#ifdef IIC_GPIO_USE_P02_P03
#undef IIC_GPIO_USE_P02_P03
#endif
#define IIC_GPIO_USE_P00_P01

#ifdef MUTE_PORT_USE_P01
#undef  MUTE_PORT_USE_P01
#endif
#define MUTE_PORT_USE_P26


#define NO_PLAY_STATUS_LED

#define DISP_PAUS_STRING
#define DISP_VOL_V_CHAR
#define VOLUME_DEFUALT 	30
#define DISP_PC_STR

#define EXCHANGE_LINE_IN_CHANNEL	//交换LINE IN 通道
#define FM_BY_PASS
#define TURN_ON_PLAY_BREAK_POINT_MEM

#define EXCHANGE_FM_MP3_ICON
//#define USE_LINE_IN_DETECT_FUNC
//#define AUX_DETECT_USE_P02
#define LINE_IN_PLAY_KEY_PAUSE


#endif


#ifdef K0000_ZG_BT260_V001

#ifdef IIC_GPIO_USE_P02_P03
#undef IIC_GPIO_USE_P02_P03
#endif
#define IIC_GPIO_USE_P00_P01

#ifdef MUTE_PORT_USE_P01
#undef  MUTE_PORT_USE_P01
#endif
#define MUTE_PORT_USE_P03

#define NO_LED_DISPLAY

#define CUSTOMER_DEFINED_ADKEY_RESISTOR

#if 1
#define USE_POWER_KEY
#define USE_ONLY_POWER_HOLD_CTRL
#define PWR_CTRL_P17
#define USE_PWR_KEY_LONG_PWR_ON
#define PWR_ON_DELAY_1_SECOND
#define SUPERIOR_CUSTOMER
#endif

#define NEW_CUSTOMIZED_LED_METHOD
//efine EXTENDED_WORK_MODE_USE_TWO_GPIO_CTRL


#define EXCHANGE_LINE_IN_CHANNEL	//交换LINE IN 通道

#define LINE_IN_PLAY_KEY_PAUSE

 
#define BLUE_TOOTH_FUNC
#define BLUETOOTH_GPIO_CTRL

#endif

#ifdef K0000_JK_KHT_830E_V001

#ifdef MUTE_PORT_USE_P01
#undef  MUTE_PORT_USE_P01
#endif
#define MUTE_PORT_USE_DUMP

#define PLAY_STATUS_LED_P01

#define EXCHANGE_LINE_IN_CHANNEL	//交换LINE IN 通道
#define MID_SPEED_BAND_SCAN
#define NO_LED_DISPLAY
#define SUPERIOR_CUSTOMER
//#define VOLUME_DEFUALT   20
#define NO_VOLUME_LIMITE
#define VOL_ADJ_SPARK_LED
#if 1
#define CUSTOMER_DEFINED_ADKEY_RESISTOR
#define USE_POWER_KEY
#define USE_ONLY_POWER_HOLD_CTRL
#define PWR_CTRL_WKUP
#define USE_PC_DC_POWER_ON_ONLY
#define PWR_CTRL_WKUP_POWER_ONLY
#define USE_PWR_KEY_LONG_PWR_ON
#define PWR_ON_DELAY_1_SECOND
#define POWE_KEY_PLAY_KEY_IN_ONE_KEY
#define USE_POWER_KEY_SHORT_SCAN
#define FAST_DEV_INIT
#define DC_HW_POWER_UP_IN_IDLE_MODE
#endif

#define LOW_POWER_DIDI_ALERT
#define NO_DEV_LED_IMPROVE
#define USE_LINE_IN_DETECT_FUNC
#define AUX_DETECT_USE_P07
#define LINE_DETECT_INDEPENDENT_MODE
#define LED_STATUS_FLASH_VERY_FAST_AT_FM_SCAN

#define INDEPENDENT_VOLUME_KEY
#define FF_FR_TURN_ON_MUSIC
#if 1
#define USE_BAT_MANAGEMENT
#define DC_CHARGE_GPIO_DRV_LED_IND_2
#define DC_CHARGE_GPIO_DRV_LED_P10
#define CHARGER_DETECT_INDICATOR
#define CHARGER_DET_USE_P11
#define BAT_MEASURE_USE_P04_PORT
#define LOW_BAT_POWER_OFF_MODE
#define RES_AVRG_DIV_VOLT
#endif

#define IMPROVED_BAT_MEASURE

#if 0
#define BLUE_TOOTH_FUNC
#define BLUETOOTH_GPIO_CTRL
#define BT_MODE_HOT_KEY_ENABLE
#define USE_BT_GPIO_DETECTION
#define BT_GPIO_DETECTION_USE_PORT_P15
#define BT_CONFIG_POWER_ON_ENABLE
#define BT_USE_AUX_0

#endif

#endif

#ifdef K0000_JK_KHT_830D_V001

#ifdef MUTE_PORT_USE_P01
#undef  MUTE_PORT_USE_P01
#endif
#define MUTE_PORT_USE_DUMP

#define PLAY_STATUS_LED_P01

#define EXCHANGE_LINE_IN_CHANNEL	//交换LINE IN 通道
#define MID_SPEED_BAND_SCAN
#define NO_LED_DISPLAY
#define SUPERIOR_CUSTOMER
//#define VOLUME_DEFUALT   20
#define NO_VOLUME_LIMITE
#define VOL_ADJ_SPARK_LED
#if 1
#define CUSTOMER_DEFINED_ADKEY_RESISTOR
#define USE_POWER_KEY
#define USE_ONLY_POWER_HOLD_CTRL
#define PWR_CTRL_WKUP
#define USE_PC_DC_POWER_ON_ONLY
#define PWR_CTRL_WKUP_POWER_ONLY
#define USE_PWR_KEY_LONG_PWR_ON
#define PWR_ON_DELAY_1_SECOND
#define POWE_KEY_PLAY_KEY_IN_ONE_KEY
#define USE_POWER_KEY_SHORT_SCAN
#define FAST_DEV_INIT
#define DC_HW_POWER_UP_IN_IDLE_MODE
#endif

#define LOW_POWER_DIDI_ALERT
#define NO_DEV_LED_IMPROVE
#define USE_LINE_IN_DETECT_FUNC
#define AUX_DETECT_USE_P07
#define LINE_DETECT_INDEPENDENT_MODE
#define LED_STATUS_FLASH_VERY_FAST_AT_FM_SCAN

#if 1
#define USE_BAT_MANAGEMENT
#define DC_CHARGE_GPIO_DRV_LED_IND_2
#define DC_CHARGE_GPIO_DRV_LED_P10
#define CHARGER_DETECT_INDICATOR
#define CHARGER_DET_USE_P11
#define BAT_MEASURE_USE_P04_PORT
#define LOW_BAT_POWER_OFF_MODE
#define RES_AVRG_DIV_VOLT
#endif

#define IMPROVED_BAT_MEASURE

#if 0
#define BLUE_TOOTH_FUNC
#define BLUETOOTH_GPIO_CTRL
#define BT_MODE_HOT_KEY_ENABLE
#define USE_BT_GPIO_DETECTION
#define BT_GPIO_DETECTION_USE_PORT_P15
#define BT_CONFIG_POWER_ON_ENABLE
#define BT_USE_AUX_0

#endif

#endif

#ifdef K0000_JK_KHT_842_BT_V001

#ifdef MUTE_PORT_USE_P01
#undef  MUTE_PORT_USE_P01
#endif
#define MUTE_PORT_USE_DUMP

#define PLAY_STATUS_LED_P01

#define EXCHANGE_LINE_IN_CHANNEL	//交换LINE IN 通道

#define NO_LED_DISPLAY
#define SUPERIOR_CUSTOMER
#define VOLUME_DEFUALT   30
#define NO_VOLUME_LIMITE

#if 1
#define CUSTOMER_DEFINED_ADKEY_RESISTOR
#define USE_POWER_KEY
#define USE_ONLY_POWER_HOLD_CTRL
#define PWR_CTRL_WKUP
#define PWR_CTRL_WKUP_POWER_ONLY
#define USE_PWR_KEY_LONG_PWR_ON
#define PWR_ON_DELAY_1_SECOND
#define POWE_KEY_PLAY_KEY_IN_ONE_KEY
#define USE_POWER_KEY_SHORT_SCAN
#endif

#define USE_LINE_IN_DETECT_FUNC
#define AUX_DETECT_USE_P07
#define LINE_DETECT_INDEPENDENT_MODE

#if 1
#define USE_BAT_MANAGEMENT
#define DC_CHARGE_GPIO_DRV_LED_IND
#define DC_CHARGE_GPIO_DRV_LED_P00
#define CHARGER_DETECT_INDICATOR
#define CHARGER_DET_USE_P04
#endif

#define IMPROVED_BAT_MEASURE
#if 1
#define BLUE_TOOTH_FUNC
#define BLUETOOTH_GPIO_CTRL
#define BT_MODE_HOT_KEY_ENABLE
#define USE_BT_GPIO_DETECTION
#define BT_GPIO_DETECTION_USE_PORT_P15
#define BT_CONFIG_POWER_ON_ENABLE
#define BT_USE_AUX_0

#endif

#endif

#ifdef K0000_JK_PORTABLE_CHARGER_V001

#ifdef IIC_GPIO_USE_P02_P03
#undef IIC_GPIO_USE_P02_P03
#endif
#define IIC_GPIO_USE_P00_P01

#ifdef MUTE_PORT_USE_P01
#undef  MUTE_PORT_USE_P01
#endif
#define MUTE_PORT_USE_P04

#undef LED_CTRL_LEVEL_NORMAL
#define PLAY_STATUS_LED_P10

#define EXCHANGE_LINE_IN_CHANNEL	//交换LINE IN 通道

#define NO_LED_DISPLAY
#define SUPERIOR_CUSTOMER
#define SYS_DEFAULT_IN_PWR_OFF_FOR_LED_PROTECTION
#define SYS_DEFAULT_IN_PWR_OFF_FOR_LED_PROTECTION_WHEN_CHARGER_LEVEL_0
#define CUSTOMIZED_KEY_FUNC_ENABLE
#if 1
#define CUSTOMER_DEFINED_ADKEY_RESISTOR
#define USE_POWER_KEY
#define USE_ONLY_POWER_HOLD_CTRL
#define PWR_CTRL_P34
#define USE_PWR_KEY_LONG_PWR_ON
#define PWR_ON_DELAY_1_SECOND
#endif

#define USE_BAT_MANAGEMENT
#define BAT_MEASURE_USE_P02_PORT

#define NO_DEV_LED_IMPROVE
#define DEFAULT_GO_TO_IDLE
#define IMPROVED_BAT_MEASURE
#define USB_SD_PORTABLE_BAT_CHARGER

#endif

#ifdef K1169_ZK_ALK982_V001

#ifdef IIC_GPIO_USE_P02_P03
#undef IIC_GPIO_USE_P02_P03
#endif
#define IIC_GPIO_USE_P00_P01

#ifdef MUTE_PORT_USE_P01
#undef  MUTE_PORT_USE_P01
#endif
#define MUTE_PORT_USE_P03

#define PLAY_STATUS_LED_P02

#define USE_GPIO_DETECT_EARPHONE_PLUGGED
#define EARPHONE_DETECT_USE_P02

#define EXCHANGE_LINE_IN_CHANNEL	//交换LINE IN 通道

#define CUSTOMER_DEFINED_ADKEY_RESISTOR
#define ADKEY_NEW_METHOD
#define TWO_ADKEY_ENABLE
#define TWO_ADKEY_USE_PORT_P07
#define EXTENDED_ADKEY_NUM


#define DISP_VOL_V_CHAR
#define NO_DEV_SHOW_HI_STR
#define DISP_PAUS_STRING
//#define FM_MAX_CHANNAL_50
#define ADKEY_PLAY_SHORT_ADJ_CH
#define DEFAULT_GO_TO_IDLE
#define DISP_OFF_STR_AT_PWR_DOWN

#if 1
#define USE_POWER_KEY
#define USE_ONLY_POWER_HOLD_CTRL
#define PWR_CTRL_P17
#define USE_PWR_KEY_LONG_PWR_ON
#define PWR_ON_DELAY_1_SECOND
#define USE_POWER_KEY_TO_SWITCH_MODE
#endif

#if 0
#define USE_BAT_MANAGEMENT
#define BAT_LEVEL_LED_ICON_IND
#define CHARGER_DETECT_INDICATOR
#define PROTECT_P17_FROM_LED_SCAN
#define CHARGER_DET_USE_P17
#define CHARGER_FLASH_TYPE_2
#define LOW_VOLT_SPARK_BAT_ICON
#endif

#define RADIO_MODE_HOT_KEY_ENABLE
#define RTC_MODE_HOT_KEY_ENABLE

#define USE_RTC_FUNCTION
#define USE_RTC_TIME_ONLY
#define USE_RTC_ALARM_FUNCTION
#define USE_RTC_ALM_CUSTOM_INIT
#endif

#ifdef K1167_ZK_ALK967_V001

#ifdef IIC_GPIO_USE_P02_P03
#undef IIC_GPIO_USE_P02_P03
#endif
#define IIC_GPIO_USE_P00_P01

#ifdef MUTE_PORT_USE_P01
#undef  MUTE_PORT_USE_P01
#endif
#define MUTE_PORT_USE_P03

#define LED_USE_1X888

#define EXCHANGE_LINE_IN_CHANNEL	//交换LINE IN 通道


#define DISP_VOL_V_CHAR
#define NO_DEV_SHOW_HI_STR
#define DISP_PAU_STRING
#define FM_MAX_CHANNAL_50
#define ADKEY_PLAY_SHORT_ADJ_CH


#endif

#ifdef K1166_FW_16_V001

#ifdef IIC_GPIO_USE_P02_P03
#undef IIC_GPIO_USE_P02_P03
#endif
#define IIC_GPIO_USE_P00_P01

#ifdef MUTE_PORT_USE_P01
#undef  MUTE_PORT_USE_P01
#endif
#define MUTE_PORT_USE_P03

#define LED_USE_PLAY_MODE

#define LED_USE_ROUND_LED

#define EXCHANGE_LINE_IN_CHANNEL	//交换LINE IN 通道
#define DEFAULT_GO_TO_IDLE
#define LED_MODE_EXCHANGE_TF_USB_ICON

#define DISP_VOL_V_CHAR
//#define NO_DEV_SHOW_HI_STR
#define DISP_PAUS_STRING
#define FM_MAX_CHANNAL_50
#define ADKEY_PLAY_SHORT_ADJ_CH

#if 0
#define USE_POWER_KEY
#define USE_ONLY_POWER_HOLD_CTRL
#define PWR_CTRL_P02
#define USE_PWR_KEY_LONG_PWR_ON
#define PWR_ON_DELAY_1_SECOND
#define PWR_OFF_NO_RESP_WHEN_CHARGER_PLUGGED
#endif

#define USE_BAT_MANAGEMENT
#define BAT_LEVEL_LED_ICON_IND
#define CHARGER_DETECT_INDICATOR
#define PROTECT_P17_FROM_LED_SCAN
#define CHARGER_DET_USE_P02
#define CHARGER_FLASH_TYPE_2
#define LOW_VOLT_SPARK_BAT_ICON

#define USE_LINE_IN_DETECT_FUNC
#define AUX_DETECT_USE_P17
#define DEFAULT_GO_TO_TIME_MODE

#define USE_RTC_FUNCTION
#define USE_RTC_TIME_ONLY

#undef USE_RDAs_FM
#undef USE_QN8035_FM
#define Lamborghini_voice
#define OTP_MUSIC_FUNC_ENABLE
#endif


#ifdef K1166_YJH_1234_V001

#ifdef IIC_GPIO_USE_P02_P03
#undef IIC_GPIO_USE_P02_P03
#endif
#define IIC_GPIO_USE_P00_P01

#ifdef MUTE_PORT_USE_P01
#undef  MUTE_PORT_USE_P01
#endif
#define MUTE_PORT_USE_P03

#define LED_USE_PLAY_MODE
#define LED_USE_PLAY_MODE_NORMAL
#define LED_USE_ROUND_LED

#define EXCHANGE_LINE_IN_CHANNEL	//交换LINE IN 通道
#define DEFAULT_GO_TO_IDLE

#define DISP_VOL_V_CHAR
#define FM_PLAY_KEY_PAUSE
#define LINE_IN_PLAY_KEY_PAUSE
//#define NO_DEV_SHOW_HI_STR
#define DISP_PAUS_STRING
#define FM_MAX_CHANNAL_50
//#define ADKEY_PLAY_SHORT_SCAN_FRE

#if 0
#define USE_POWER_KEY
#define USE_ONLY_POWER_HOLD_CTRL
#define PWR_CTRL_P02
#define USE_PWR_KEY_LONG_PWR_ON
#define PWR_ON_DELAY_1_SECOND
#define PWR_OFF_NO_RESP_WHEN_CHARGER_PLUGGED
#endif

#define USE_BAT_MANAGEMENT
#define BAT_LEVEL_LED_ICON_IND
#define CHARGER_DETECT_INDICATOR
#define PROTECT_P17_FROM_LED_SCAN
#define CHARGER_DET_USE_P17
#define CHARGER_FLASH_TYPE_2
#define LOW_VOLT_SPARK_BAT_ICON

//#define USE_LINE_IN_DETECT_FUNC
//#define AUX_DETECT_USE_P02
//#define AUX_DETECT_HIGH_LEVEL
#define DEFAULT_GO_TO_TIME_MODE

#define USE_RTC_FUNCTION
#define USE_RTC_TIME_ONLY

#undef USE_RDAs_FM
#undef USE_QN8035_FM
#define Lamborghini_voice
#define OTP_MUSIC_FUNC_ENABLE
#endif

#ifdef K1166_FW_16_V002

#ifdef IIC_GPIO_USE_P02_P03
#undef IIC_GPIO_USE_P02_P03
#endif
#define IIC_GPIO_USE_P00_P01

#ifdef MUTE_PORT_USE_P01
#undef  MUTE_PORT_USE_P01
#endif
#define MUTE_PORT_USE_P03

#define LED_USE_PLAY_MODE

//#define LED_USE_ROUND_LED

#define EXCHANGE_LINE_IN_CHANNEL	//交换LINE IN 通道
#define DEFAULT_GO_TO_IDLE
#define LED_MODE_EXCHANGE_TF_USB_ICON

#define DISP_VOL_V_CHAR
//#define NO_DEV_SHOW_HI_STR
#define DISP_PAUS_STRING
#define FM_MAX_CHANNAL_50
#define ADKEY_PLAY_SHORT_ADJ_CH

#if 0
#define USE_POWER_KEY
#define USE_ONLY_POWER_HOLD_CTRL
#define PWR_CTRL_P02
#define USE_PWR_KEY_LONG_PWR_ON
#define PWR_ON_DELAY_1_SECOND
#define PWR_OFF_NO_RESP_WHEN_CHARGER_PLUGGED
#endif

#define USE_BAT_MANAGEMENT
#define BAT_LEVEL_LED_ICON_IND
#define CHARGER_DETECT_INDICATOR
#define PROTECT_P17_FROM_LED_SCAN
#define CHARGER_DET_USE_P17
#define CHARGER_FLASH_TYPE_2
#define LOW_VOLT_SPARK_BAT_ICON

#define USE_LINE_IN_DETECT_FUNC
#define AUX_DETECT_USE_P02
#define AUX_DETECT_HIGH_LEVEL
#define DEFAULT_GO_TO_TIME_MODE

#define USE_RTC_FUNCTION
#define USE_RTC_TIME_ONLY

#undef USE_RDAs_FM
#undef USE_QN8035_FM
#define Lamborghini_voice
#define OTP_MUSIC_FUNC_ENABLE
#endif


#ifdef K1166_JM_YT_V001

#ifdef IIC_GPIO_USE_P02_P03
#undef IIC_GPIO_USE_P02_P03
#endif
#define IIC_GPIO_USE_P00_P01

#ifdef MUTE_PORT_USE_P01
#undef  MUTE_PORT_USE_P01
#endif
#define MUTE_PORT_USE_P03

#define LED_USE_PLAY_MODE
#define LED_USE_PLAY_MODE_NORMAL
#define LED_USE_ROUND_LED

#define EXCHANGE_LINE_IN_CHANNEL	//交换LINE IN 通道
#define DEFAULT_GO_TO_IDLE
#define ENABLE_GPIO_PORT_CHARGER_DETECT_PULL_UP

#define DISP_VOL_V_CHAR
#define NO_DEV_SHOW_HI_STR
#define DISP_PAUS_STRING
#define FM_MAX_CHANNAL_50
#define ADKEY_PLAY_SHORT_ADJ_CH

#define USE_MODE_KEY_LONG_SCAN

#define FM_PLAY_KEY_PAUSE
#define LINE_IN_PLAY_KEY_PAUSE

#if 0
#define USE_POWER_KEY
#define USE_ONLY_POWER_HOLD_CTRL
#define PWR_CTRL_P02
#define USE_PWR_KEY_LONG_PWR_ON
#define PWR_ON_DELAY_1_SECOND
#define PWR_OFF_NO_RESP_WHEN_CHARGER_PLUGGED
#endif

#define USE_BAT_MANAGEMENT
#define BAT_LEVEL_LED_ICON_IND
#define CHARGER_DETECT_INDICATOR
#define PROTECT_P17_FROM_LED_SCAN
#define CHARGER_DET_USE_P17
#define CHARGER_FLASH_TYPE_2
#define LOW_VOLT_SPARK_BAT_ICON

#define USE_LINE_IN_DETECT_FUNC
#define AUX_DETECT_USE_P02

#define Lamborghini_voice
#define OTP_MUSIC_FUNC_ENABLE
#endif

#ifdef K1166_ZK_ALK980_V001

#ifdef IIC_GPIO_USE_P02_P03
#undef IIC_GPIO_USE_P02_P03
#endif
#define IIC_GPIO_USE_P00_P01

#ifdef MUTE_PORT_USE_P01
#undef  MUTE_PORT_USE_P01
#endif
#define MUTE_PORT_USE_P03

#define LED_USE_PLAY_MODE

#define LED_USE_ROUND_LED



#define EXCHANGE_LINE_IN_CHANNEL	//交换LINE IN 通道
#define DEFAULT_GO_TO_IDLE


#define DISP_VOL_V_CHAR
#define NO_DEV_SHOW_HI_STR
#define DISP_PAUS_STRING
#define FM_MAX_CHANNAL_50
#define ADKEY_PLAY_SHORT_ADJ_CH

#if 0
#define USE_POWER_KEY
#define USE_ONLY_POWER_HOLD_CTRL
#define PWR_CTRL_P02
#define USE_PWR_KEY_LONG_PWR_ON
#define PWR_ON_DELAY_1_SECOND
#define PWR_OFF_NO_RESP_WHEN_CHARGER_PLUGGED
#endif

#define USE_BAT_MANAGEMENT
#define BAT_LEVEL_LED_ICON_IND
#define CHARGER_DETECT_INDICATOR
#define PROTECT_P17_FROM_LED_SCAN
#define CHARGER_DET_USE_P17
#define CHARGER_FLASH_TYPE_2
#define LOW_VOLT_SPARK_BAT_ICON

#define USE_LINE_IN_DETECT_FUNC
#define AUX_DETECT_USE_P02
#endif


#ifdef K1150_LS_1150_V001

#ifdef LED_GPIO_DRV
#undef  LED_GPIO_DRV
#endif
#define LCD_GPIO_DRV

#ifdef IIC_GPIO_USE_P02_P03
#undef IIC_GPIO_USE_P02_P03
#endif
#define IIC_GPIO_USE_P00_P01

#ifdef MUTE_PORT_USE_P01
#undef  MUTE_PORT_USE_P01
#endif
#define MUTE_PORT_USE_DUMP

#define LCD_BACKLIGHT_USE_PORT_WKUP
#define WKUP_PIN_USE_ENABLE
#define DISP_BACKLIGHT_AUTO_SAVE_POWER

#define DISP_PAU_STRING
#define DISP_VOL_V_CHAR
#define VOLUME_DEFUALT 	20
#define DISP_PC_STR

#define EXCHANGE_LINE_IN_CHANNEL	//交换LINE IN 通道

#define INDEPENDENT_VOLUME_KEY

#define USE_LINE_IN_DETECT_FUNC
#define AUX_DETECT_USE_P03
#define PALY_MODE_USE_RAN_ALL_ONE

#define USE_BAT_MANAGEMENT
#define NEW_BAT_ICON_DISP_AT_LEVEL_FOUR
#define CHARGER_DETECT_INDICATOR
#define CHARGER_DET_USE_P04
#define CUSTOM_BAT_ICON_DISP
#define IMPROVED_BAT_MEASURE

#endif


#ifdef K1164_YDT_1164_V001

#ifdef IIC_GPIO_USE_P02_P03
#undef IIC_GPIO_USE_P02_P03
#endif
#define IIC_GPIO_USE_P00_P01

#ifdef MUTE_PORT_USE_P01
#undef  MUTE_PORT_USE_P01
#endif
#define MUTE_PORT_USE_P03

#define LED_GPIO_PORT_CUSTOMERIZED
#define LED_COMMON_SCAN_COM_USE_P17
#define LED_USE_PLAY_MODE_MIXED

#define NO_PLAY_STATUS_LED

#define DISP_PAUS_STRING
#define DISP_VOL_V_CHAR
#define VOLUME_DEFUALT 	34
#define DISP_PC_STR
#define GUOWEI_IR_REMOTE
#define EQ_DOWN_SCAN_ALL
#define IR_PLAY_KEY_SCAN_FREQ_DISABLE

#define TURN_ON_PLAY_BREAK_POINT_MEM
#define EXCHANGE_LINE_IN_CHANNEL	//交换LINE IN 通道

#define LINE_IN_PLAY_KEY_PAUSE
#define FM_PLAY_KEY_PAUSE
#define USB_SD_PLAY_INFO_DIV
#define VOLUME_CUSTOMER_DEFINE_34
#define INDEPENDENT_VOLUME_KEY

#define USE_LINE_IN_DETECT_FUNC
#define AUX_DETECT_USE_P02

#endif

#ifdef K2083_SW_2083_V001

#ifdef IIC_GPIO_USE_P02_P03
#undef IIC_GPIO_USE_P02_P03
#endif
#define IIC_GPIO_USE_P00_P01

#ifdef MUTE_PORT_USE_P01
#undef  MUTE_PORT_USE_P01
#endif
#define MUTE_PORT_USE_P03

#define LED_USE_PLAY_MODE
#define KPL_BIG_LED_MODULE

#define CUSTOMER_DEFINED_ADKEY_RESISTOR
#define NO_PLAY_STATUS_LED


#define DISP_PAUS_STRING
#define DISP_VOL_V_CHAR
//#define VOLUME_DEFUALT 	30
#define DISP_PC_STR

#define RADIO_AM_WM_ENABLE
#define FM_USE_KT0913
//#define ADKEY_PLAY_SHORT_SCAN_FRE
//#define RADIO_MODE_HOT_KEY_ENABLE
#define FM_MAX_CHANNAL_60
#define NEW_SD_DETECT_MOD
#define SEMI_AUTO_SCAN_FREQ
#define ADKEY_NEXT_PREV_HOLD_AUTO_SCAN
#define INDEPENDENT_VOLUME_KEY
//#define DEFAULT_GO_TO_TIME_MODE
#define SEMI_SCAN_BAND_BREAK_AT_FREQ_LIMIT

#define EXCHANGE_LINE_IN_CHANNEL	//交换LINE IN 通道

#define USE_GPIO_DETECT_EARPHONE_PLUGGED
#define PLAY_MODE_USE_REP_ONE_ALL
#define EARPHONE_DETECT_USE_VPP


#define LINE_IN_PLAY_KEY_PAUSE

#define USE_BAT_MANAGEMENT
#define NEW_BAT_ICON_DISP_AT_LEVEL_THREE
#define CHARGER_DETECT_INDICATOR
#define CHARGER_DET_USE_P07


#define NEXT_PREV_HOLD_FOR_MUSIC_FFR
#define JOG_STICK_FUNC
//#define VOL_TUNE_NEW_VOLUME_KEY_FEATURE
#define VOL_TUNE_VOL_DEFAULT_TUNE_FREQ_POP

#define FM_MINI_FRE_875

#if 0
#define USE_RTC_FUNCTION
#define USE_RTC_TIME_ONLY
#define RTC_MODE_HOT_KEY_ENABLE
#define MODE_KEY_LONG_FOR_RTC_HOTKEY
#define USE_MODE_LONG_FOR_RTC_SETTING
#define USE_RTC_ALARM_FUNCTION
#define RTC_VOL_FIXIED
#define USE_RTC_ALM_CUSTOM_INIT
#define RTC_SETTING_NO_CYC
#define AUX_ICON_FOR_RTC_ALM
#endif

#undef USE_QN8035_FM
#undef USE_RDAs_FM
#endif

#ifdef K2083_SW_2083_V002

#ifdef IIC_GPIO_USE_P02_P03
#undef IIC_GPIO_USE_P02_P03
#endif
#define IIC_GPIO_USE_P00_P01

#ifdef MUTE_PORT_USE_P01
#undef  MUTE_PORT_USE_P01
#endif
#define MUTE_PORT_USE_P03


#ifdef LED_GPIO_DRV
#undef LED_GPIO_DRV
#define LCD_GPIO_DRV
#define LCD_SEGMENT_USE_8_SEGS_5_COMS
#endif

//#define LED_USE_PLAY_MODE
//#define KPL_BIG_LED_MODULE

#define CUSTOMER_DEFINED_ADKEY_RESISTOR
#define NO_PLAY_STATUS_LED


#define DISP_PAUS_STRING
#define DISP_VOL_V_CHAR
//#define VOLUME_DEFUALT 	30
#define DISP_PC_STR

#define RADIO_AM_WM_ENABLE
#define FM_USE_KT0913
//#define ADKEY_PLAY_SHORT_SCAN_FRE
//#define RADIO_MODE_HOT_KEY_ENABLE
#define FM_MAX_CHANNAL_60
#define NEW_SD_DETECT_MOD
#define SEMI_AUTO_SCAN_FREQ
#define ADKEY_NEXT_PREV_HOLD_AUTO_SCAN
#define INDEPENDENT_VOLUME_KEY
//#define DEFAULT_GO_TO_TIME_MODE
#define SEMI_SCAN_BAND_BREAK_AT_FREQ_LIMIT

#define EXCHANGE_LINE_IN_CHANNEL	//交换LINE IN 通道

#define USE_GPIO_DETECT_EARPHONE_PLUGGED
#define PLAY_MODE_USE_REP_ONE_ALL
#define EARPHONE_DETECT_USE_VPP


#define LINE_IN_PLAY_KEY_PAUSE

#define USE_BAT_MANAGEMENT
#define NEW_BAT_ICON_DISP_AT_LEVEL_THREE
#define CHARGER_DETECT_INDICATOR
#define CHARGER_DET_USE_P07
#define CUSTOM_BAT_ICON_DISP


#define NEXT_PREV_HOLD_FOR_MUSIC_FFR
#define JOG_STICK_FUNC
#define VOL_TUNE_NEW_VOLUME_KEY_FEATURE
#define FM_MINI_FRE_875

#if 0
#define USE_RTC_FUNCTION
#define USE_RTC_TIME_ONLY
#define RTC_MODE_HOT_KEY_ENABLE
#define MODE_KEY_LONG_FOR_RTC_HOTKEY
#define USE_MODE_LONG_FOR_RTC_SETTING
#define USE_RTC_ALARM_FUNCTION
#define RTC_VOL_FIXIED
#define USE_RTC_ALM_CUSTOM_INIT
#define RTC_SETTING_NO_CYC
#define AUX_ICON_FOR_RTC_ALM
#endif

#undef USE_QN8035_FM
#undef USE_RDAs_FM
#undef USE_BK1080_FM

#endif


#ifdef K2083_KPL_2083_V003

#ifdef IIC_GPIO_USE_P02_P03
#undef IIC_GPIO_USE_P02_P03
#endif
#define IIC_GPIO_USE_P00_P01

#ifdef MUTE_PORT_USE_P01
#undef  MUTE_PORT_USE_P01
#endif
#define MUTE_PORT_USE_P03

#ifdef LED_GPIO_DRV
#undef LED_GPIO_DRV
#define LCD_GPIO_DRV
#define LCD_SEGMENT_USE_8_SEGS_5_COMS
#endif

#define AM_BAND_522_TO_1720
#define KT_INDEPENDENT_CRY
//#define LED_USE_PLAY_MODE
//#define KPL_BIG_LED_MODULE

#define CUSTOMER_DEFINED_ADKEY_RESISTOR
#define NO_PLAY_STATUS_LED
#define DISP_BACKLIGHT_AUTO_SAVE_POWER
#define DISABLE_P05_OSC_OUTPUT
#define LCD_BACKLIGHT_USE_PORT_P05
//#define WKUP_PIN_USE_ENABLE

#define DISP_PC_STR
#define PLAY_MODE_USE_REP_ONE_ALL

#define DISP_PAUS_STRING
#define DISP_VOL_V_CHAR
//#define VOLUME_DEFUALT 	30
#define DISP_PC_STR

#undef USE_RDAs_FM
#undef USE_BK1080_FM
#undef USE_QN8035_FM

#define RADIO_AM_WM_ENABLE
#define FM_USE_KT0913
//#define ADKEY_PLAY_SHORT_SCAN_FRE
//#define RADIO_MODE_HOT_KEY_ENABLE
//#define FM_MAX_CHANNAL_60
#define NEW_SD_DETECT_MOD
#define SEMI_AUTO_SCAN_FREQ
#define ADKEY_NEXT_PREV_HOLD_AUTO_SCAN
#define INDEPENDENT_VOLUME_KEY
#define DEFAULT_GO_TO_TIME_MODE
#define SEMI_SCAN_BAND_BREAK_AT_FREQ_LIMIT

#define EXCHANGE_LINE_IN_CHANNEL	//交换LINE IN 通道

#define USE_GPIO_DETECT_EARPHONE_PLUGGED
#define EARPHONE_DETECT_USE_VPP

#define FM_PLAY_KEY_PAUSE
#define LINE_IN_PLAY_KEY_PAUSE


#define USE_BAT_MANAGEMENT
#define NEW_BAT_ICON_DISP_AT_LEVEL_THREE
#define CHARGER_DETECT_INDICATOR
#define CHARGER_DET_USE_P07
#define CUSTOM_BAT_ICON_DISP

#define NEXT_PREV_HOLD_FOR_MUSIC_FFR
#define JOG_STICK_FUNC
#define VOL_TUNE_VOL_DEFAULT_TUNE_FREQ_POP
//#define VOL_TUNE_NEW_VOLUME_KEY_FEATURE
//#define FM_MINI_FRE_875
//#define QN_SCAN_HIGH_SENSE

#define USE_RTC_FUNCTION
#define USE_RTC_TIME_ONLY
#define RTC_MODE_HOT_KEY_ENABLE
#define MODE_KEY_LONG_FOR_RTC_HOTKEY
#define USE_MODE_LONG_FOR_RTC_SETTING
#define USE_RTC_ALARM_FUNCTION
#define RTC_VOL_FIXIED
#define USE_RTC_ALM_CUSTOM_INIT
#define RTC_SETTING_NO_CYC
#define AUX_ICON_FOR_RTC_ALM

#endif

#ifdef K2083_KPL_2083_V002

#ifdef IIC_GPIO_USE_P02_P03
#undef IIC_GPIO_USE_P02_P03
#endif
#define IIC_GPIO_USE_P00_P01

#ifdef MUTE_PORT_USE_P01
#undef  MUTE_PORT_USE_P01
#endif
#define MUTE_PORT_USE_P03

#define LED_USE_PLAY_MODE
#define KPL_BIG_LED_MODULE

#define CUSTOMER_DEFINED_ADKEY_RESISTOR
#define NO_PLAY_STATUS_LED


#define DISP_PAUS_STRING
#define DISP_VOL_V_CHAR
//#define VOLUME_DEFUALT 	30
#define DISP_PC_STR

//#define RADIO_AM_WM_ENABLE
//#define FM_USE_KT0913
//#define ADKEY_PLAY_SHORT_SCAN_FRE
//#define RADIO_MODE_HOT_KEY_ENABLE
//#define FM_MAX_CHANNAL_60
#define NEW_SD_DETECT_MOD
#define SEMI_AUTO_SCAN_FREQ
#define ADKEY_NEXT_PREV_HOLD_AUTO_SCAN
#define INDEPENDENT_VOLUME_KEY
#define DEFAULT_GO_TO_TIME_MODE
#define SEMI_SCAN_BAND_BREAK_AT_FREQ_LIMIT

#define EXCHANGE_LINE_IN_CHANNEL	//交换LINE IN 通道

#define USE_GPIO_DETECT_EARPHONE_PLUGGED
#define EARPHONE_DETECT_USE_VPP

#define FM_PLAY_KEY_PAUSE
#define LINE_IN_PLAY_KEY_PAUSE


#define USE_BAT_MANAGEMENT
#define NEW_BAT_ICON_DISP_AT_LEVEL_THREE
#define CHARGER_DETECT_INDICATOR
#define CHARGER_DET_USE_P07

#define NEXT_PREV_HOLD_FOR_MUSIC_FFR
#define JOG_STICK_FUNC
//#define VOL_TUNE_NEW_VOLUME_KEY_FEATURE
#define VOL_TUNE_VOL_DEFAULT_TUNE_FREQ_POP

#define FM_MINI_FRE_875
#define QN_SCAN_HIGH_SENSE

#define USE_RTC_FUNCTION
#define USE_RTC_TIME_ONLY
#define RTC_MODE_HOT_KEY_ENABLE
#define MODE_KEY_LONG_FOR_RTC_HOTKEY
#define USE_MODE_LONG_FOR_RTC_SETTING
#define USE_RTC_ALARM_FUNCTION
#define RTC_VOL_FIXIED
#define USE_RTC_ALM_CUSTOM_INIT
#define RTC_SETTING_NO_CYC
#define AUX_ICON_FOR_RTC_ALM


#endif

#ifdef K2083_KPL_2083_V001

#ifdef IIC_GPIO_USE_P02_P03
#undef IIC_GPIO_USE_P02_P03
#endif
#define IIC_GPIO_USE_P00_P01

#ifdef MUTE_PORT_USE_P01
#undef  MUTE_PORT_USE_P01
#endif
#define MUTE_PORT_USE_P03

#define LED_USE_PLAY_MODE
#define KPL_BIG_LED_MODULE

#define CUSTOMER_DEFINED_ADKEY_RESISTOR
#define NO_PLAY_STATUS_LED
#define DISP_PC_STR
#define PLAY_MODE_USE_REP_ONE_ALL

#define DISP_PAUS_STRING
#define DISP_VOL_V_CHAR
//#define VOLUME_DEFUALT 	30
#define DISP_PC_STR

#define AM_BAND_522_TO_1720
#define KT_INDEPENDENT_CRY

#define RADIO_AM_WM_ENABLE
#define FM_USE_KT0913
//#define ADKEY_PLAY_SHORT_SCAN_FRE
//#define RADIO_MODE_HOT_KEY_ENABLE
#define FM_MAX_CHANNAL_60
#define NEW_SD_DETECT_MOD
#define SEMI_AUTO_SCAN_FREQ
#define ADKEY_NEXT_PREV_HOLD_AUTO_SCAN
#define INDEPENDENT_VOLUME_KEY
#define DEFAULT_GO_TO_TIME_MODE
#define SEMI_SCAN_BAND_BREAK_AT_FREQ_LIMIT

#define EXCHANGE_LINE_IN_CHANNEL	//交换LINE IN 通道

#define USE_GPIO_DETECT_EARPHONE_PLUGGED
#define EARPHONE_DETECT_USE_VPP

#define FM_PLAY_KEY_PAUSE

#define LINE_IN_PLAY_KEY_PAUSE

#define USE_BAT_MANAGEMENT
#define NEW_BAT_ICON_DISP_AT_LEVEL_THREE
#define CHARGER_DETECT_INDICATOR
#define CHARGER_DET_USE_P07

#define NEXT_PREV_HOLD_FOR_MUSIC_FFR
#define JOG_STICK_FUNC
#define VOL_TUNE_VOL_DEFAULT_TUNE_FREQ_POP

//efine VOL_TUNE_NEW_VOLUME_KEY_FEATURE
#define FM_MINI_FRE_875

#define USE_RTC_FUNCTION
#define USE_RTC_TIME_ONLY
#define RTC_MODE_HOT_KEY_ENABLE
#define MODE_KEY_LONG_FOR_RTC_HOTKEY
#define USE_MODE_LONG_FOR_RTC_SETTING
#define USE_RTC_ALARM_FUNCTION
#define RTC_VOL_FIXIED
#define USE_RTC_ALM_CUSTOM_INIT
#define RTC_SETTING_NO_CYC
#define AUX_ICON_FOR_RTC_ALM

#undef USE_QN8035_FM
#undef USE_RDAs_FM
#endif

#ifdef K1168_YHD_Y003_V001

#ifdef IIC_GPIO_USE_P02_P03
#undef IIC_GPIO_USE_P02_P03
#endif
#define IIC_GPIO_USE_P00_P01

#ifdef MUTE_PORT_USE_P01
#undef  MUTE_PORT_USE_P01
#endif
#define MUTE_PORT_USE_P03

#define LED_GPIO_PORT_CUSTOMERIZED
#define LED_COMMON_SCAN_COM_USE_P17
#define LED_USE_PLAY_MODE

#define CUSTOMER_DEFINED_ADKEY_RESISTOR
#define NO_PLAY_STATUS_LED
#define TWO_ADKEY_ENABLE
#define TWO_ADKEY_USE_PORT_P07
#define FF_FR_TURN_ON_MUSIC

#define DISP_PAUS_STRING
#define DISP_VOL_V_CHAR
#define VOLUME_DEFUALT 	20
#define DISP_PC_STR
#define NEXT_PREV_HOLD_FOR_MUSIC_FFR
#define LED_MODE_EXCHANGE_TF_AUX_ICON
#define TURN_ON_PLAY_BREAK_POINT_MEM
#define EXCHANGE_LINE_IN_CHANNEL	//交换LINE IN 通道

#define USE_GPIO_DETECT_EARPHONE_PLUGGED
#define EARPHONE_DETECT_USE_P04

#define ADKEY_PLAY_SHORT_SCAN_FRE
#define LINE_IN_PLAY_KEY_PAUSE


#define USE_BAT_MANAGEMENT
#define BAT_LEVEL_LED_ICON_IND
#define CHARGER_DETECT_INDICATOR
#define CHARGER_DET_USE_P02
#define CHARGER_FLASH_TYPE_2
#define LOW_VOLT_SPARK_BAT_ICON

#endif

#ifdef K1165_YHD_Y002_V001

#ifdef IIC_GPIO_USE_P02_P03
#undef IIC_GPIO_USE_P02_P03
#endif
#define IIC_GPIO_USE_P00_P01

#ifdef MUTE_PORT_USE_P01
#undef  MUTE_PORT_USE_P01
#endif
#define MUTE_PORT_USE_P03

#define PLAY_STATUS_LED_P04
#define ROUND_LED_USE_OFFEN

#define DISP_PAUS_STRING
#define LINE_IN_PLAY_KEY_NO_PAUSE_ICON_INDICATOR
#define AUX_PAUSE_LED_INDICATOR_FLASH_WHEN_PLAY
#define LINE_IN_NO_DISP_PAUS

#define DISP_VOL_V_CHAR
#define VOLUME_DEFUALT 	20
#define DISP_PC_STR

#define LED_GPIO_PORT_CUSTOMERIZED
//#define LED_COMMON_SCAN_COM_USE_P17

#define EXCHANGE_LINE_IN_CHANNEL	//交换LINE IN 通道
#define USE_GPIO_DETECT_EARPHONE_PLUGGED
#define EARPHONE_DETECT_USE_P02

#define TURN_ON_PLAY_BREAK_POINT_MEM
#define ADKEY_PLAY_SHORT_SCAN_FRE

#define USE_LINE_IN_DETECT_FUNC
#define AUX_DETECT_USE_P34

#define LINE_IN_PLAY_KEY_PAUSE

#endif


#ifdef K1161_HF_ADA8_V001

#ifdef IIC_GPIO_USE_P02_P03
#undef IIC_GPIO_USE_P02_P03
#endif
#define IIC_GPIO_USE_P00_P01

#ifdef MUTE_PORT_USE_P01
#undef  MUTE_PORT_USE_P01
#endif
#define MUTE_PORT_USE_P03

#define LED_USE_PLAY_MODE

#define LED_USE_ROUND_LED
#define LED_USE_PLAY_MODE_NORMAL

#define EXCHANGE_LINE_IN_CHANNEL	//交换LINE IN 通道
//#define DEFAULT_GO_TO_IDLE

#define USE_POWER_KEY_SHORT_SCAN
#define POWE_KEY_PLAY_KEY_IN_ONE_KEY

#define DISP_OFF_STR_AT_PWR_DOWN
//#define NO_DEV_SHOW_HI_STR
#define DISP_PAUS_STRING
#define FM_MAX_CHANNAL_50
#define ADKEY_PLAY_SHORT_ADJ_CH
#define CUSTOMER_DEFINED_ADKEY_RESISTOR
#define LOW_VOLT_SPARK_BAT_ICON
#define DISP_VOL_V_CHAR

#define LINE_IN_PLAY_KEY_PAUSE
#define USE_POWER_KEY_FOR_AUX_PLAY

//#define DISP_HIFI_STR_AT_POWER_ON
//#define VOLUME_CUSTOMER_DEFINE_32
#define DISP_FM_STR_WHEN_PAUS

#if 1
#define USE_POWER_KEY
#define USE_ONLY_POWER_HOLD_CTRL
#define PWR_CTRL_P02
#define USE_PWR_KEY_LONG_PWR_ON
#define PWR_ON_DELAY_1_SECOND
//#define PWR_OFF_NO_RESP_WHEN_CHARGER_PLUGGED
#endif

#define TURN_ON_PLAY_BREAK_POINT_MEM
#define USE_BAT_MANAGEMENT
#define BAT_LEVEL_LED_ICON_IND
#define CHARGER_DETECT_INDICATOR
#define CHARGER_DET_USE_P17
#define CHARGER_FLASH_TYPE_2
#define PROTECT_P17_FROM_LED_SCAN

#define Lamborghini_voice
#define OTP_MUSIC_FUNC_ENABLE
#endif


#ifdef K1161_YHD_888_V001

#ifdef IIC_GPIO_USE_P02_P03
#undef IIC_GPIO_USE_P02_P03
#endif
#define IIC_GPIO_USE_P00_P01

#ifdef MUTE_PORT_USE_P01
#undef  MUTE_PORT_USE_P01
#endif
#define MUTE_PORT_USE_P03

#define LED_USE_ROUND_LED
#define LED_USE_PLAY_MODE
#define LED_MODE_EXCHANGE_TF_USB_ICON

#define EXCHANGE_LINE_IN_CHANNEL	//交换LINE IN 通道

#define DISP_HIFI_STR_AT_POWER_ON
#define NO_DEV_SHOW_HI_STR
#define DEFAULT_GO_TO_IDLE
#define USE_POWER_KEY_SHORT_SCAN
#define POWE_KEY_PLAY_KEY_IN_ONE_KEY

#define DISP_OFF_STR_AT_PWR_DOWN
#define DISP_PAUS_STRING
#define FM_MAX_CHANNAL_50
#define ADKEY_PLAY_SHORT_ADJ_CH
#define CUSTOMER_DEFINED_ADKEY_RESISTOR
#define LOW_VOLT_SPARK_BAT_ICON
#define DISP_VOL_V_CHAR

#define LINE_IN_PLAY_KEY_PAUSE
#define USE_POWER_KEY_FOR_AUX_PLAY


#define VOLUME_DEFUALT 	25
#define DISP_FM_STR_WHEN_PAUS

#if 1
#define USE_POWER_KEY
#define USE_ONLY_POWER_HOLD_CTRL
#define PWR_CTRL_P02
#define USE_PWR_KEY_LONG_PWR_ON
#define PWR_ON_DELAY_1_SECOND
//#define PWR_OFF_NO_RESP_WHEN_CHARGER_PLUGGED
#endif

#define TURN_ON_PLAY_BREAK_POINT_MEM
#define USE_BAT_MANAGEMENT
#define BAT_LEVEL_LED_ICON_IND
#define CHARGER_DETECT_INDICATOR
#define CHARGER_DET_USE_P17
#define CHARGER_FLASH_TYPE_2

#define IR_REMOTER_WITH_POWER_MUTE_PRINT
#define USE_IR_POWER_KEY_TO_POWER_OFF
#define POWER_KEY_SHORT_PWR_DOWN

#if 1
#undef USE_RDAs_FM
#undef USE_QN8035_FM
#define OTP_MUSIC_FUNC_ENABLE
#define OTP_DECODE_PLAY_FOLLOW_SYS_VOL
#define PLANE_ENGINE
#endif
#endif

#ifdef K1161_YHD_839_V001

#ifdef IIC_GPIO_USE_P02_P03
#undef IIC_GPIO_USE_P02_P03
#endif
#define IIC_GPIO_USE_P00_P01

#ifdef MUTE_PORT_USE_P01
#undef  MUTE_PORT_USE_P01
#endif
#define MUTE_PORT_USE_P03

#define LED_USE_ROUND_LED
#define LED_USE_PLAY_MODE
#define LED_MODE_EXCHANGE_TF_USB_ICON

#define EXCHANGE_LINE_IN_CHANNEL	//交换LINE IN 通道

#define USE_POWER_KEY_SHORT_SCAN
#define POWE_KEY_PLAY_KEY_IN_ONE_KEY

#define DISP_OFF_STR_AT_PWR_DOWN
#define DISP_PAUS_STRING
#define FM_MAX_CHANNAL_50
#define ADKEY_PLAY_SHORT_ADJ_CH
#define CUSTOMER_DEFINED_ADKEY_RESISTOR
#define LOW_VOLT_SPARK_BAT_ICON
#define DISP_VOL_V_CHAR

#define LINE_IN_PLAY_KEY_PAUSE
#define USE_POWER_KEY_FOR_AUX_PLAY


#define VOLUME_DEFUALT 	25
#define DISP_FM_STR_WHEN_PAUS

#if 1
#define USE_POWER_KEY
#define USE_ONLY_POWER_HOLD_CTRL
#define PWR_CTRL_P02
#define USE_PWR_KEY_LONG_PWR_ON
#define PWR_ON_DELAY_1_SECOND
//#define PWR_OFF_NO_RESP_WHEN_CHARGER_PLUGGED
#endif

#define TURN_ON_PLAY_BREAK_POINT_MEM
#define USE_BAT_MANAGEMENT
#define BAT_LEVEL_LED_ICON_IND
#define CHARGER_DETECT_INDICATOR
#define CHARGER_DET_USE_P17
#define CHARGER_FLASH_TYPE_2

#define IR_REMOTER_WITH_POWER_MUTE_PRINT
#define USE_IR_POWER_KEY_TO_POWER_OFF
#define POWER_KEY_SHORT_PWR_DOWN

#if 1
#undef USE_RDAs_FM
#undef USE_BK1080_FM
#define OTP_MUSIC_FUNC_ENABLE
#define OTP_DECODE_PLAY_FOLLOW_SYS_VOL
#define Lamborghini_voice
#endif
#endif


#ifdef K1161_YJH_861_V001

#ifdef IIC_GPIO_USE_P02_P03
#undef IIC_GPIO_USE_P02_P03
#endif
#define IIC_GPIO_USE_P00_P01

#ifdef MUTE_PORT_USE_P01
#undef  MUTE_PORT_USE_P01
#endif
#define MUTE_PORT_USE_P03

#define LED_USE_PLAY_MODE

#define LED_USE_ROUND_LED
#define LED_USE_PLAY_MODE_NORMAL

#define EXCHANGE_LINE_IN_CHANNEL	//交换LINE IN 通道
#define DEFAULT_GO_TO_IDLE

#define USE_MODE_KEY_LONG_SCAN
#define POWE_KEY_PLAY_KEY_IN_ONE_KEY

#define DISP_OFF_STR_AT_PWR_DOWN
#define NO_DEV_SHOW_HI_STR
#define DISP_PAUS_STRING
#define FM_MAX_CHANNAL_50
#define ADKEY_PLAY_SHORT_ADJ_CH
#define CUSTOMER_DEFINED_ADKEY_RESISTOR
#define LOW_VOLT_SPARK_BAT_ICON
#define DISP_VOL_V_CHAR

#define LINE_IN_PLAY_KEY_PAUSE
#define FM_PLAY_KEY_PAUSE
#define USE_POWER_KEY_FOR_AUX_PLAY
#define USE_POWER_KEY_FOR_FM_PLAY

#define DISP_HIFI_STR_AT_POWER_ON
#define VOLUME_CUSTOMER_DEFINE_32
#define DISP_FM_STR_WHEN_PAUS

#if 1
#define USE_POWER_KEY
#define USE_ONLY_POWER_HOLD_CTRL
#define PWR_CTRL_P02
#define USE_PWR_KEY_LONG_PWR_ON
#define PWR_ON_DELAY_1_SECOND
//#define PWR_OFF_NO_RESP_WHEN_CHARGER_PLUGGED
#endif

#define USE_BAT_MANAGEMENT
#define BAT_LEVEL_LED_ICON_IND
#define CHARGER_DETECT_INDICATOR
#define CHARGER_DET_USE_P17
#define CHARGER_FLASH_TYPE_2


#if 1
#undef USE_RDAs_FM
#undef USE_QN8035_FM
#define OTP_MUSIC_FUNC_ENABLE
#define OTP_DECODE_PLAY_FOLLOW_SYS_VOL
#define XIAO_SAN_MADA
#endif

#endif

#ifdef K2091_YJH_863_V001

#ifdef IIC_GPIO_USE_P02_P03
#undef IIC_GPIO_USE_P02_P03
#endif
#define IIC_GPIO_USE_P00_P01

#ifdef MUTE_PORT_USE_P01
#undef  MUTE_PORT_USE_P01
#endif
#define MUTE_PORT_USE_P03


#define LED_GPIO_PORT_CUSTOMERIZED
#define LED_USE_PLAY_MODE

#define IR_PLAY_KEY_SCAN_FREQ_ALL
#define LED_USE_PLAY_MODE_NORMAL
#define USE_IR_POWER_KEY_TO_POWER_OFF

#define IR_POWER_KEY_SHORT_TRUE_POWER_OFF
#define EXCHANGE_LINE_IN_CHANNEL	//交换LINE IN 通道
#define DEFAULT_GO_TO_IDLE

//#define ADKEY_PLAY_SHORT_SCAN_FRE
#define POWE_KEY_PLAY_KEY_IN_ONE_KEY
#define PLAY_MODE_USE_REP_ONE_ALL
#define DISP_EQ_STR

#define DISP_OFF_STR_AT_PWR_DOWN
#define NO_DEV_SHOW_HI_STR
#define DISP_PAUS_STRING
#define FM_MAX_CHANNAL_50
#define ADKEY_PLAY_SHORT_ADJ_CH
#define CUSTOMER_DEFINED_ADKEY_RESISTOR
#define LOW_VOLT_SPARK_BAT_ICON
#define DISP_VOL_V_CHAR
#define DISP_OFF_STR_AT_PWR_DOWN

#define LINE_IN_PLAY_KEY_PAUSE
#define USE_POWER_KEY_SHORT_SCAN
#define USE_POWER_KEY_FOR_AUX_PLAY
//#define USE_POWER_KEY_FOR_FM_PLAY

#define DISP_HIFI_STR_AT_POWER_ON
#define VOLUME_CUSTOMER_DEFINE_32
#define DISP_FM_STR_WHEN_PAUS

#if 1
#define USE_POWER_KEY
#define USE_ONLY_POWER_HOLD_CTRL
#define PWR_CTRL_P02
#define USE_PWR_KEY_LONG_PWR_ON
#define PWR_ON_DELAY_1_SECOND
//#define PWR_OFF_NO_RESP_WHEN_CHARGER_PLUGGED
#endif

#define USE_BAT_MANAGEMENT
#define BAT_LEVEL_LED_ICON_IND
#define CHARGER_DETECT_INDICATOR
#define CHARGER_DET_USE_P04
#define CHARGER_FLASH_TYPE_2

#define USE_LINE_IN_DETECT_FUNC
#define AUX_DETECT_USE_P34

#if 1
#undef USE_RDAs_FM
#undef USE_QN8035_FM
#define OTP_MUSIC_FUNC_ENABLE
#define OTP_DECODE_PLAY_FOLLOW_SYS_VOL
#define Lamborghini_voice
#endif

#endif

#ifdef K1161_YJH_1161_V002

#ifdef IIC_GPIO_USE_P02_P03
#undef IIC_GPIO_USE_P02_P03
#endif
#define IIC_GPIO_USE_P00_P01

#ifdef MUTE_PORT_USE_P01
#undef  MUTE_PORT_USE_P01
#endif
#define MUTE_PORT_USE_P03

#define LED_USE_PLAY_MODE

#define LED_USE_ROUND_LED
#define IR_PLAY_KEY_SCAN_FREQ_ALL
#define LED_USE_PLAY_MODE_NORMAL
#define USE_IR_POWER_KEY_TO_POWER_OFF

#define IR_POWER_KEY_SHORT_TRUE_POWER_OFF
#define EXCHANGE_LINE_IN_CHANNEL	//交换LINE IN 通道
#define DEFAULT_GO_TO_IDLE

//#define ADKEY_PLAY_SHORT_SCAN_FRE
#define POWE_KEY_PLAY_KEY_IN_ONE_KEY
#define PLAY_MODE_USE_REP_ONE_ALL
#define DISP_EQ_STR

#define DISP_OFF_STR_AT_PWR_DOWN
#define NO_DEV_SHOW_HI_STR
#define DISP_PAUS_STRING
#define FM_MAX_CHANNAL_50
#define ADKEY_PLAY_SHORT_ADJ_CH
#define CUSTOMER_DEFINED_ADKEY_RESISTOR
#define LOW_VOLT_SPARK_BAT_ICON
#define DISP_VOL_V_CHAR

#define LINE_IN_PLAY_KEY_PAUSE
#define USE_POWER_KEY_SHORT_SCAN
#define USE_POWER_KEY_FOR_AUX_PLAY
//#define USE_POWER_KEY_FOR_FM_PLAY

#define DISP_HIFI_STR_AT_POWER_ON
#define VOLUME_CUSTOMER_DEFINE_32
#define DISP_FM_STR_WHEN_PAUS

#if 1
#define USE_POWER_KEY
#define USE_ONLY_POWER_HOLD_CTRL
#define PWR_CTRL_P02
#define USE_PWR_KEY_LONG_PWR_ON
#define PWR_ON_DELAY_1_SECOND
//#define PWR_OFF_NO_RESP_WHEN_CHARGER_PLUGGED
#endif

#define USE_BAT_MANAGEMENT
#define BAT_LEVEL_LED_ICON_IND
#define CHARGER_DETECT_INDICATOR
#define CHARGER_DET_USE_P17
#define CHARGER_FLASH_TYPE_2


#if 1
#undef USE_RDAs_FM
#undef USE_QN8035_FM
#define OTP_MUSIC_FUNC_ENABLE
#define OTP_DECODE_PLAY_FOLLOW_SYS_VOL
#define Lamborghini_voice
#endif

#endif

#ifdef K1161_YJH_1161_V001

#ifdef IIC_GPIO_USE_P02_P03
#undef IIC_GPIO_USE_P02_P03
#endif
#define IIC_GPIO_USE_P00_P01

#ifdef MUTE_PORT_USE_P01
#undef  MUTE_PORT_USE_P01
#endif
#define MUTE_PORT_USE_P03

#define LED_USE_PLAY_MODE

#define LED_USE_ROUND_LED
#define LED_USE_PLAY_MODE_NORMAL

#define EXCHANGE_LINE_IN_CHANNEL	//交换LINE IN 通道
#define DEFAULT_GO_TO_IDLE

#define USE_MODE_KEY_LONG_SCAN
#define POWE_KEY_PLAY_KEY_IN_ONE_KEY

#define DISP_OFF_STR_AT_PWR_DOWN
#define NO_DEV_SHOW_HI_STR
#define DISP_PAUS_STRING
#define FM_MAX_CHANNAL_50
#define ADKEY_PLAY_SHORT_ADJ_CH
#define CUSTOMER_DEFINED_ADKEY_RESISTOR
#define LOW_VOLT_SPARK_BAT_ICON
#define DISP_VOL_V_CHAR

#define LINE_IN_PLAY_KEY_PAUSE
#define FM_PLAY_KEY_PAUSE
#define USE_POWER_KEY_FOR_AUX_PLAY
#define USE_POWER_KEY_FOR_FM_PLAY

#define DISP_HIFI_STR_AT_POWER_ON
#define VOLUME_CUSTOMER_DEFINE_32
#define DISP_FM_STR_WHEN_PAUS

#if 1
#define USE_POWER_KEY
#define USE_ONLY_POWER_HOLD_CTRL
#define PWR_CTRL_P02
#define USE_PWR_KEY_LONG_PWR_ON
#define PWR_ON_DELAY_1_SECOND
//#define PWR_OFF_NO_RESP_WHEN_CHARGER_PLUGGED
#endif

#define USE_BAT_MANAGEMENT
#define BAT_LEVEL_LED_ICON_IND
#define CHARGER_DETECT_INDICATOR
#define CHARGER_DET_USE_P17
#define CHARGER_FLASH_TYPE_2


#if 1
#undef USE_RDAs_FM
#undef USE_QN8035_FM
#define OTP_MUSIC_FUNC_ENABLE
#define OTP_DECODE_PLAY_FOLLOW_SYS_VOL
#define Lamborghini_voice
#endif

#endif


#ifdef K1161_ZK_ALK935_V001

#ifdef IIC_GPIO_USE_P02_P03
#undef IIC_GPIO_USE_P02_P03
#endif
#define IIC_GPIO_USE_P00_P01

#ifdef MUTE_PORT_USE_P01
#undef  MUTE_PORT_USE_P01
#endif
#define MUTE_PORT_USE_P03

#define LED_USE_PLAY_MODE

#define LED_USE_ROUND_LED


#define EXCHANGE_LINE_IN_CHANNEL	//交换LINE IN 通道
#define DEFAULT_GO_TO_IDLE

#define USE_POWER_KEY_SHORT_SCAN
#define POWE_KEY_PLAY_KEY_IN_ONE_KEY

#define DISP_OFF_STR_AT_PWR_DOWN
#define NO_DEV_SHOW_HI_STR
#define DISP_PAUS_STRING
#define FM_MAX_CHANNAL_50
#define ADKEY_PLAY_SHORT_ADJ_CH
#define CUSTOMER_DEFINED_ADKEY_RESISTOR
#define LOW_VOLT_SPARK_BAT_ICON
#define DISP_VOL_V_CHAR

#if 1
#define USE_POWER_KEY
#define USE_ONLY_POWER_HOLD_CTRL
#define PWR_CTRL_P02
#define USE_PWR_KEY_LONG_PWR_ON
#define PWR_ON_DELAY_1_SECOND
//#define PWR_OFF_NO_RESP_WHEN_CHARGER_PLUGGED
#endif


#define SYS_POWER_ON_DEFAULT_RTC_MODE
#define USE_BAT_MANAGEMENT
#define BAT_LEVEL_LED_ICON_IND
#define CHARGER_DETECT_INDICATOR
#define CHARGER_DET_USE_P17
#define CHARGER_FLASH_TYPE_2

#define USE_MODE_LONG_FOR_RTC_SETTING
#define USE_POWER_KEY_TO_ADJ_HOUR_AND_MIN
#define ALARM_ADJ_FLASH_ON_OFF
#define USE_RTC_FUNCTION
#define RTC_SETTING_OP_TIMER_ENABLE
#define NEW_RTC_SETTING_CTRL

#define OTP_MUSIC_FUNC_ENABLE
//#define OTP_DECODE_PLAY_FOLLOW_SYS_VOL
#define Lamborghini_voice
#undef USE_QN8035_FM
#undef USE_RDAs_FM

#endif

#ifdef K1157_ZK_ALK933_V001

#ifdef IIC_GPIO_USE_P02_P03
#undef IIC_GPIO_USE_P02_P03
#endif
#define IIC_GPIO_USE_P00_P01

#ifdef MUTE_PORT_USE_P01
#undef  MUTE_PORT_USE_P01
#endif
#define MUTE_PORT_USE_P03

#define LED_GPIO_PORT_CUSTOMERIZED
#define LED_COMMON_SCAN_COM_USE_P17

#define EXCHANGE_LINE_IN_CHANNEL	//交换LINE IN 通道
#define DEFAULT_GO_TO_IDLE

#define NO_DEV_SHOW_HI_STR
#define DISP_PAUS_STRING
#define FM_MAX_CHANNAL_50
#define ADKEY_PLAY_SHORT_ADJ_CH

#define USE_GPIO_DETECT_EARPHONE_PLUGGED
#define EARPHONE_DETECT_USE_P04

#endif

#ifdef K0000_MY_FT18_BT_V001

#ifdef IIC_GPIO_USE_P02_P03
#undef IIC_GPIO_USE_P02_P03
#endif
#define IIC_GPIO_USE_P01_P00

#ifdef MUTE_PORT_USE_P01
#undef  MUTE_PORT_USE_P01
#endif
#define MUTE_PORT_USE_P03
#define VOLUME_DEFUALT 30

#define INDEPENDENT_VOLUME_KEY

#define EXCHANGE_LINE_IN_CHANNEL	//交换LINE IN 通道
#define NO_LED_DISPLAY
#define USE_LONG_PLAY_KEY_TO_SWITCH_MODE
//#define NOT_USE_LINE_IN_FUNC
#if 1
#define FM_BY_PASS
#define BLUE_TOOTH_FUNC
#define BLUETOOTH_GPIO_CTRL
#define BLUE_TOOTH_NO_SYS_MUTE_CTRL
#define BLUE_TOOTH_KEY_DELAY_25MS
#endif

//#define USE_BAT_MANAGEMENT
//#define DC_CHARGE_GPIO_DRV_LED_IND
//#define CHARGER_DETECT_INDICATOR
//#define CHARGER_DET_USE_P02
//#define DC_CHARGE_GPIO_DRV_LED_IND_2
//#define CHARGE_STATE_FOR_LED_PROTECTION
//#define DC_CHARGE_GPIO_DRV_LED_P07
//#define TURN_OFF_PLAY_STATUS_LED_IN_BLUETOOTH_MODE
#endif


#ifdef K0000_MY_FT18_V001

#ifdef IIC_GPIO_USE_P02_P03
#undef IIC_GPIO_USE_P02_P03
#endif
#define IIC_GPIO_USE_P01_P00

#ifdef MUTE_PORT_USE_P01
#undef  MUTE_PORT_USE_P01
#endif
#define MUTE_PORT_USE_P03

#define BLUE_TOOTH_NO_SYS_MUTE_CTRL

#define INDEPENDENT_VOLUME_KEY
//#define DECODE_STOP_MODE_ENABLE
//#define PLAY_LONG_PRESS_STOP
#define USE_LONG_PLAY_KEY_TO_SWITCH_MODE
#define EXCHANGE_LINE_IN_CHANNEL	//交换LINE IN 通道
#define NO_LED_DISPLAY
#if 0
#define FM_BY_PASS
#define BLUE_TOOTH_FUNC
#define BLUETOOTH_GPIO_CTRL
#define BLUE_TOOTH_KEY_DELAY_25MS
#endif
#endif

#ifdef K2078_MY_2078_V001

#ifdef IIC_GPIO_USE_P02_P03
#undef IIC_GPIO_USE_P02_P03
#endif
#define IIC_GPIO_USE_P01_P00

#ifdef MUTE_PORT_USE_P01
#undef  MUTE_PORT_USE_P01
#endif
#define MUTE_PORT_USE_P03

#define BLUE_TOOTH_NO_SYS_MUTE_CTRL
#define ADKEY_PLAY_SHORT_SCAN_FRE
#define USE_LONG_PLAY_KEY_TO_SWITCH_MODE

#define EXCHANGE_LINE_IN_CHANNEL	//交换LINE IN 通道
#define NO_LED_DISPLAY
#define FM_BY_PASS
#define BLUE_TOOTH_FUNC
#define BLUETOOTH_GPIO_CTRL
#define BLUE_TOOTH_KEY_DELAY_25MS
#endif

#ifdef K0000_XP_TN891_V002

#ifdef IIC_GPIO_USE_P02_P03
#undef IIC_GPIO_USE_P02_P03
#endif
#define IIC_GPIO_USE_P00_P01

#ifdef MUTE_PORT_USE_P01
#undef  MUTE_PORT_USE_P01
#endif
#define MUTE_PORT_USE_P03

#define NO_LED_DISPLAY
#define NOT_USE_LINE_IN_FUNC
#define CUSTOM_DEFINE_ADPORT_FUNC
#define DISABLE_DEVICE_HOT_PLUG_AND_PLAY

#endif

#ifdef K0000_XP_TN891_V001

#ifdef IIC_GPIO_USE_P02_P03
#undef IIC_GPIO_USE_P02_P03
#endif
#define IIC_GPIO_USE_P00_P01

#ifdef MUTE_PORT_USE_P01
#undef  MUTE_PORT_USE_P01
#endif
#define MUTE_PORT_USE_P03

#define NO_LED_DISPLAY
#define NOT_USE_LINE_IN_FUNC
#define USE_CUSTOMIED_GPIO_KEY
#define NO_ADKEY_FUNC
#define FAST_DEV_INIT
#define NO_DEV_LED_IMPROVE
#define NO_PLAY_STATUS_LED
#define NO_VOLUME_LIMITE
#define DECODE_STOP_MODE_ENABLE
#define MUSIC_STANDBY_AT_POWER_ON
#define NO_FM_CHIP_ON_BOARD
#define NEXT_PREV_REPLAY_IN_STOP_DECODE_MODE
#define CUSTOM_WAIT_FOR_MCU_CMD_FOR_NEXT_MUSIC_HOLD_IN_STOP_MODE
#define PLAY_MODE_REPEAT_ONE
#endif

#ifdef K0000_JK_TEMP_FAN_V001

#ifdef IIC_GPIO_USE_P02_P03
#undef IIC_GPIO_USE_P02_P03
#endif
#define IIC_GPIO_USE_P00_P01

#ifdef MUTE_PORT_USE_P01
#undef  MUTE_PORT_USE_P01
#endif
#define MUTE_PORT_USE_P03

#define NOT_USE_LINE_IN_FUNC

#define DISP_VOL_V_CHAR
#define DISP_PAUS_STRING
#define DISP_PC_STR

#define EXTENED_LED_NUM_SCAN
#define AD_MEASURE_TEMP_FUNC
#define PROTECT_P17_FROM_LED_SCAN

#define USE_RTC_FUNCTION
#define USE_RTC_TIME_ONLY
#define SYS_POWER_ON_DEFAULT_RTC_MODE

#if 0
#define USE_BAT_MANAGEMENT
#define BAT_LEVEL_LED_ICON_IND
#define CHARGER_DETECT_INDICATOR
#define CHARGER_DET_USE_P17
#define CHARGER_FLASH_TYPE_1
#define PROTECT_P17_FROM_LED_SCAN
#endif

#endif

#ifdef K1159_DCX_D962_V001

#ifdef IIC_GPIO_USE_P02_P03
#undef IIC_GPIO_USE_P02_P03
#endif
#define IIC_GPIO_USE_P00_P01

#ifdef MUTE_PORT_USE_P01
#undef  MUTE_PORT_USE_P01
#endif
#define MUTE_PORT_USE_P03

#define LED_USE_ROUND_LED
#define ROUND_LED_USE_OFFEN
#define DISP_VOL_V_CHAR
#define DISP_PAUS_STRING
#define VOLUME_DEFUALT 	20
#define DISP_PC_STR

#define NO_PLAY_STATUS_LED

#define CUSTOMER_DEFINED_ADKEY_RESISTOR

#define EXCHANGE_LINE_IN_CHANNEL	//交换LINE IN 通道

#if 1
#define USE_POWER_KEY
#define USE_ONLY_POWER_HOLD_CTRL
#define PWR_CTRL_P02
#define USE_PWR_KEY_LONG_PWR_ON
#define PWR_ON_DELAY_1_SECOND

#define PWR_OFF_NO_RESP_WHEN_CHARGER_PLUGGED

//#define USE_USB_HOTPLUG_FUNC
#define DC_HW_POWER_UP
#endif

#define USE_POWER_KEY_SHORT_SCAN
#define POWE_KEY_PLAY_KEY_IN_ONE_KEY

#define LINE_IN_PLAY_KEY_PAUSE
#define USE_POWER_KEY_FOR_AUX_PLAY

#undef USE_USB_AUDIO
#if 0
#define USE_BAT_MANAGEMENT
#define BAT_LEVEL_LED_ICON_IND
#define CHARGER_DETECT_INDICATOR
#define CHARGER_DET_USE_P17
#define CHARGER_FLASH_TYPE_1
#define PROTECT_P17_FROM_LED_SCAN
#endif

//#define USE_TIMER_POWER_OFF_FUNC
//#define USE_SNOOZE_FUNC

#endif

#ifdef K1147_JLH_1234_V001

#ifdef IIC_GPIO_USE_P02_P03
#undef IIC_GPIO_USE_P02_P03
#endif
#define IIC_GPIO_USE_P00_P01

#ifdef MUTE_PORT_USE_P01
#undef  MUTE_PORT_USE_P01
#endif
#define MUTE_PORT_USE_P03

#define EXCHANGE_FM_MP3_ICON

#define DISP_VOL_V_CHAR
#define DISP_PAUS_STRING
#define VOLUME_DEFUALT 	20
#define DISP_PC_STR

#define NO_PLAY_STATUS_LED
#define ADKEY_NEW_METHOD
#define TWO_ADKEY_ENABLE
#define TWO_ADKEY_USE_PORT_P07
#define EXTENDED_ADKEY_NUM
#define DEFAULT_GO_TO_TIME_MODE
#define CUSTOMER_DEFINED_ADKEY_RESISTOR
#define INDEPENDENT_VOLUME_KEY

#define EXCHANGE_LINE_IN_CHANNEL	//交换LINE IN 通道
#define USE_GPIO_DETECT_EARPHONE_PLUGGED
#define EARPHONE_DETECT_USE_P04
#define ADKEY_PLAY_SHORT_SCAN_FRE_DISABLE
#define ADKEY_PLAY_SHORT_SCAN_FRE
#if 1
#define USE_POWER_KEY
#define USE_ONLY_POWER_HOLD_CTRL
#define PWR_CTRL_WKUP
//#define PWR_CTRL_P02
#define USE_PWR_KEY_LONG_PWR_ON
#define PWR_ON_DELAY_1_SECOND

//#define PWR_OFF_NO_RESP_WHEN_CHARGER_PLUGGED

//#define USE_USB_HOTPLUG_FUNC
#define DC_HW_POWER_UP
#endif
#define MP3_MODE_EQ_DOWN_DO_NOTHING

//#define USE_POWER_KEY_SHORT_SCAN
//#define POWE_KEY_PLAY_KEY_IN_ONE_KEY

#if 0
#define USE_BAT_MANAGEMENT
#define BAT_LEVEL_LED_ICON_IND
#define CHARGER_DETECT_INDICATOR
#define CHARGER_DET_USE_P17
#define CHARGER_FLASH_TYPE_1
#define PROTECT_P17_FROM_LED_SCAN
#endif

#define USE_RTC_FUNCTION
#define USE_RTC_TIME_ONLY
//#define USE_RTC_ALARM_FUNCTION
//#define USE_RTC_ALM_CUSTOM_INIT
//#define ADJ_TIME_USE_VOL_KEY

//#define INDEPENDENT_KEY_ADJ_TIME
#define RTC_SETTING_NO_CYC

//#define ALARM_ADJ_FLASH_ON_OFF
#define DISP_CH_NUM_IN_RADIO_AT_FISRT

#define USE_LONG_MODE_KEY_PLAY_MODE
//#define USE_SNOOZE_FUNC
#define EQ_DOWN_SCAN_ALL
#define RTC_VOL_FIXIED

#endif

#ifdef K1147_DCX_D955_V001

#ifdef IIC_GPIO_USE_P02_P03
#undef IIC_GPIO_USE_P02_P03
#endif
#define IIC_GPIO_USE_P00_P01

#ifdef MUTE_PORT_USE_P01
#undef  MUTE_PORT_USE_P01
#endif
#define MUTE_PORT_USE_P03

#define EXCHANGE_FM_MP3_ICON

#define DISP_VOL_V_CHAR
#define DISP_PAUS_STRING
#define VOLUME_DEFUALT 	20
#define DISP_PC_STR

#define NO_PLAY_STATUS_LED
#define ADKEY_NEW_METHOD
#define TWO_ADKEY_ENABLE
#define TWO_ADKEY_USE_PORT_P07
#define EXTENDED_ADKEY_NUM

#define CUSTOMER_DEFINED_ADKEY_RESISTOR
#define INDEPENDENT_VOLUME_KEY

#define EXCHANGE_LINE_IN_CHANNEL	//交换LINE IN 通道
#define USE_GPIO_DETECT_EARPHONE_PLUGGED
#define EARPHONE_DETECT_USE_P04

#if 1
#define USE_POWER_KEY
#define USE_ONLY_POWER_HOLD_CTRL
#define PWR_CTRL_WKUP
//#define PWR_CTRL_P02
#define USE_PWR_KEY_LONG_PWR_ON
#define PWR_ON_DELAY_1_SECOND
#define PWR_OFF_WAKEUP_FUNC

#define PWR_OFF_NO_RESP_WHEN_CHARGER_PLUGGED

#define USE_USB_HOTPLUG_FUNC
#define DC_HW_POWER_UP
#endif

//#define USE_POWER_KEY_SHORT_SCAN
//#define POWE_KEY_PLAY_KEY_IN_ONE_KEY

#if 0
#define USE_BAT_MANAGEMENT
#define BAT_LEVEL_LED_ICON_IND
#define CHARGER_DETECT_INDICATOR
#define CHARGER_DET_USE_P17
#define CHARGER_FLASH_TYPE_1
#define PROTECT_P17_FROM_LED_SCAN
#endif

#define RTC_MODE_HOT_KEY_ENABLE
#define USE_RTC_FUNCTION
#define USE_RTC_TIME_ONLY
#define USE_RTC_ALARM_FUNCTION
#define USE_RTC_ALM_CUSTOM_INIT
#define ADJ_TIME_USE_VOL_KEY

#define INDEPENDENT_KEY_ADJ_TIME
#define RTC_SETTING_NO_CYC

#define SYS_POWER_ON_DEFAULT_RTC_MODE
#define ALARM_ADJ_FLASH_ON_OFF
#define DISP_CH_NUM_IN_RADIO_AT_FISRT

//#define USE_TIMER_POWER_OFF_FUNC
//#define USE_SNOOZE_FUNC

#endif

#ifdef K1143_DCX_D953_V001

#define LED_USE_ROUND_LED
#define LED_USE_PLAY_MODE
#define LED_USE_PLAY_MODE_NORMAL

#ifdef IIC_GPIO_USE_P02_P03
#undef IIC_GPIO_USE_P02_P03
#endif

#define IIC_GPIO_USE_P00_P01

#ifdef MUTE_PORT_USE_P01
#undef  MUTE_PORT_USE_P01
#endif

#define MUTE_PORT_USE_P03

#define NOT_USE_LINE_IN_FUNC

#define DISP_VOL_V_CHAR
#define DISP_PAUS_STRING
#define VOLUME_DEFUALT 	20
#define DISP_PC_STR

#define CUSTOMER_DEFINED_ADKEY_RESISTOR
#define USE_MODE_LONG_FOR_FM_PLAY

#define EXCHANGE_LINE_IN_CHANNEL	//交换LINE IN 通道

#if 1
#define USE_POWER_KEY
#define USE_ONLY_POWER_HOLD_CTRL
#define PWR_CTRL_WKUP
//#define PWR_CTRL_P02
#define USE_PWR_KEY_LONG_PWR_ON
#define PWR_ON_DELAY_1_SECOND
#endif

#define USE_POWER_KEY_SHORT_SCAN
#define POWE_KEY_PLAY_KEY_IN_ONE_KEY

#define USE_BAT_MANAGEMENT
#define BAT_LEVEL_LED_ICON_IND
#define CHARGER_DETECT_INDICATOR
#define CHARGER_DET_USE_P17
#define CHARGER_FLASH_TYPE_1
#define PROTECT_P17_FROM_LED_SCAN
#define FULL_BAT_DISP_ALL_ICON
#define FM_MAX_CHANNAL_50

#define USE_RTC_FUNCTION
#define USE_RTC_TIME_ONLY
#define USE_RTC_ALARM_FUNCTION
#define USE_RTC_ALM_CUSTOM_INIT
#define USE_PREV_LONG_FOR_RTC_SETTING
#define USE_NEXT_LONG_FOR_ALM_SETTING

#define USE_POWER_KEY_TO_ADJ_HOUR_AND_MIN
#define DEFAULT_GO_TO_TIME_MODE

#define USE_NEXT_PREV_KEY_HOLD_FUNC_SKIP
#define PWR_OFF_WAKEUP_FUNC
#define USE_TIMER_POWER_OFF_FUNC
#define USE_SNOOZE_FUNC
#define ALARM_ADJ_VOL
#define PWR_OFF_GOTO_RTC_MODE_WHEN_CHARGER_PLUGGED
#define TURN_OFF_PLAY_STATUS_LED_IN_RTC_MODE
#define PWR_OFF_IN_RTC_MODE_AFTER_30_MIN

//#define USE_USB_HOTPLUG_FUNC
#define DC_HW_POWER_UP


#endif


#ifdef K0000_GW_ZX015_V001000

//#define LED_USE_PLAY_MODE
//#define LED_MODE_EXCHANGE_TF_AUX_ICON

#ifdef IIC_GPIO_USE_P02_P03
#undef IIC_GPIO_USE_P02_P03
#endif

#define IIC_GPIO_USE_P00_P01

#ifdef MUTE_PORT_USE_P01
#undef  MUTE_PORT_USE_P01
#endif
#define MUTE_PORT_USE_P03

#define LED_GPIO_PORT_CUSTOMERIZED

#define GUOWEI_IR_REMOTE
#define CUSTOMER_DEFINED_ADKEY_RESISTOR
#define NEW_RES_VALUE_CACULATING
#define CUSTOME_GW_RES_VALUE_2
#define EXCHANGE_LED_BAT_ICON

#define EXCHANGE_LINE_IN_CHANNEL	//交换LINE IN 通道

#if 0
#define USE_BAT_MANAGEMENT
#define BAT_LEVEL_LED_ICON_IND
#define BAT_MEASURE_USE_P02_PORT
#endif
#define PLAY_MODE_USE_INTRO_MODE
#define IR_INFO_EQ_DOWN_FOR_INTRO_MODE

#define MUTE_ON_FLASH_WHOLE_SCREEN

#define USE_LINE_IN_GPIO_SEL_MODE
//#define DEFAULT_GO_TO_AUX
#define LOW_VOLT_SPARK_BAT_ICON

#define IMPROVED_BAT_MEASURE
#define EXCHANGE_FM_MP3_ICON
#define USB_SD_PLAY_INFO_DIV
#define VOLUME_DEFUALT 	30
#define DISP_PAUS_STRING

#define PLAY_MODE_USE_REP_ALL_PLAY_IN_SEQUENCE

#define PLAY_MODE_USE_REP_ONE_ALL
#define LED_RUN_FAST_WHEN_PLAY_MODE_AT_REP_ONE

#define ADKEY_PLAY_SHORT_ADJ_CH

#define SEMI_AUTO_SCAN_FREQ
#define ADKEY_NEXT_PREV_HOLD_AUTO_SCAN
#define IR_NEXT_PREV_HOLD_AUTO_SCAN
#define IR_PLAY_SHORT_CH_UP
#define USE_EQ_KEY_SHORT_CH_UP

#define IR_NEXT_PREV_HOLD_AUTO_SCAN
#define EQ_DOWN_SCAN_ALL

#endif

#ifdef K0000_GW_168C_V001

#define LED_USE_PLAY_MODE
//#define LED_MODE_EXCHANGE_TF_AUX_ICON

#ifdef IIC_GPIO_USE_P02_P03
#undef IIC_GPIO_USE_P02_P03
#endif

#define IIC_GPIO_USE_P00_P01

#ifdef MUTE_PORT_USE_P01
#undef  MUTE_PORT_USE_P01
#endif
#define MUTE_PORT_USE_P03

#define GUOWEI_IR_REMOTE
#define CUSTOMER_DEFINED_ADKEY_RESISTOR
#define NEW_RES_VALUE_CACULATING
#define CUSTOME_GW_RES_VALUE_2
#define EXCHANGE_LED_BAT_ICON

#define EXCHANGE_LINE_IN_CHANNEL	//交换LINE IN 通道

#define USE_BAT_MANAGEMENT
#define BAT_LEVEL_LED_ICON_IND
#define BAT_MEASURE_USE_P02_PORT
#define PLAY_MODE_USE_INTRO_MODE
#define IR_INFO_EQ_DOWN_FOR_INTRO_MODE

#define MUTE_ON_FLASH_WHOLE_SCREEN

#define USE_LINE_IN_GPIO_SEL_MODE
//#define DEFAULT_GO_TO_AUX
#define LOW_VOLT_SPARK_BAT_ICON

#define IMPROVED_BAT_MEASURE
#define EXCHANGE_FM_AUX_PRIO
#define USB_SD_PLAY_INFO_DIV
#define VOLUME_DEFUALT 	30
#define DISP_PAUS_STRING

#define PLAY_MODE_USE_REP_ALL_PLAY_IN_SEQUENCE

#define PLAY_MODE_USE_REP_ONE_ALL
#define LED_RUN_FAST_WHEN_PLAY_MODE_AT_REP_ONE

#define ADKEY_PLAY_SHORT_ADJ_CH

#define SEMI_AUTO_SCAN_FREQ
#define ADKEY_NEXT_PREV_HOLD_AUTO_SCAN
#define IR_NEXT_PREV_HOLD_AUTO_SCAN
#define IR_PLAY_SHORT_CH_UP
#define USE_EQ_KEY_SHORT_CH_UP

#define IR_NEXT_PREV_HOLD_AUTO_SCAN
#define EQ_DOWN_SCAN_ALL
//#define KEY_NEXT_PREV_HOLD_ADJ_VOL_IN_AUX

#endif

#ifdef K2067_JGY_2067_V001

#ifdef IIC_GPIO_USE_P02_P03
#undef IIC_GPIO_USE_P02_P03
#endif

#define IIC_GPIO_USE_P00_P01

#ifdef MUTE_PORT_USE_P01
#undef  MUTE_PORT_USE_P01
#endif
#define MUTE_PORT_USE_P03
#define DISP_VOL_V_CHAR

#define LED_GPIO_PORT_CUSTOMERIZED
#define LED_COMMON_SCAN_COM_USE_P17
#define ADKEY_PLAY_SHORT_SCAN_FRE

#define EXCHANGE_LINE_IN_CHANNEL	//交换LINE IN 通道

#define NO_PLAY_STATUS_LED
#define USE_LONG_PLAY_KEY_TO_SWITCH_MODE
#define USE_GPIO_DETECT_EARPHONE_PLUGGED
#define DISP_PAUS_STRING

#define LINE_IN_PLAY_KEY_PAUSE

#define USE_LINE_IN_DETECT_FUNC
#define AUX_DETECT_USE_P02

#endif

#ifdef K2056_AJR_2056_V001

#define LED_USE_PLAY_MODE
#define LED_USE_PLAY_MODE_NORMAL

#ifdef IIC_GPIO_USE_P02_P03
#undef IIC_GPIO_USE_P02_P03
#endif

#define IIC_GPIO_USE_P00_P01

#ifdef MUTE_PORT_USE_P01
#undef  MUTE_PORT_USE_P01
#endif
#define MUTE_PORT_USE_P03


#define LED_GPIO_PORT_CUSTOMERIZED
//#define LED_COMMON_SCAN_COM_USE_P17

#define DISP_VOL_V_CHAR
#define DISP_PAUS_STRING
#define VOLUME_DEFUALT 	20

#define SEMI_AUTO_SCAN_FREQ
#define ADKEY_NEXT_PREV_HOLD_AUTO_SCAN

#define CUSTOMER_DEFINED_ADKEY_RESISTOR

#define EXCHANGE_LINE_IN_CHANNEL	//交换LINE IN 通道

#if 1
#define USE_POWER_KEY
#define USE_ONLY_POWER_HOLD_CTRL
#define PWR_CTRL_P02
#define USE_PWR_KEY_LONG_PWR_ON
#define PWR_ON_DELAY_1_SECOND
#endif

#define USE_POWER_KEY_SHORT_SCAN
#define POWE_KEY_PLAY_KEY_IN_ONE_KEY

#define USE_BAT_MANAGEMENT
#define BAT_LEVEL_LED_ICON_IND
#define CHARGER_DETECT_INDICATOR
#define CHARGER_DET_USE_P04
#define CHARGER_FLASH_TYPE_1

#endif

#ifdef K1140_AJR_1140_V001

#define LED_USE_PLAY_MODE

#ifdef IIC_GPIO_USE_P02_P03
#undef IIC_GPIO_USE_P02_P03
#endif
#define IIC_GPIO_USE_P00_P01
#ifdef MUTE_PORT_USE_P01
#undef  MUTE_PORT_USE_P01
#endif
#define MUTE_PORT_USE_P03
#define PLAY_STATUS_LED_P04

#define LED_GPIO_PORT_CUSTOMERIZED

#define DISP_VOL_V_CHAR

#define SEMI_AUTO_SCAN_FREQ
#define ADKEY_NEXT_PREV_HOLD_AUTO_SCAN

#define CUSTOMER_DEFINED_ADKEY_RESISTOR

#define EXCHANGE_LINE_IN_CHANNEL	//交换LINE IN 通道
#define VOLUME_DEFUALT 	30


#define USE_GPIO_DETECT_EARPHONE_PLUGGED
#define EARPHONE_DETECT_USE_P34

#define USE_AMP_MODE_SELECT
#define USE_BAT_MANAGEMENT
#define BAT_LEVEL_LED_ICON_IND
#define CHARGER_DETECT_INDICATOR
#define CHARGER_DET_USE_P02
#define CHARGER_FLASH_TYPE_1

#define FM_USE_AR1015
#endif

#ifdef K1144_DCX_956_V001

#define ROUND_LED_USE_OFFEN

#define NO_PLAY_STATUS_LED
#ifdef IIC_GPIO_USE_P02_P03
#undef IIC_GPIO_USE_P02_P03
#endif
#define IIC_GPIO_USE_P00_P01
#ifdef MUTE_PORT_USE_P01
#undef  MUTE_PORT_USE_P01
#endif
#define MUTE_PORT_USE_P03

#define LED_GPIO_PORT_CUSTOMERIZED
#define LED_COMMON_SCAN_COM_USE_P17
#define INDEPENDENT_VOLUME_KEY

#define LINE_IN_PLAY_KEY_PAUSE
#define USE_POWER_KEY_FOR_AUX_PLAY
#define LINE_IN_PLAY_KEY_NO_PAUSE_ICON_INDICATOR

#define DISP_VOL_V_CHAR
#define DISP_PAUS_STRING
#define VOLUME_DEFUALT 	20

#define SEMI_AUTO_SCAN_FREQ
#define ADKEY_NEXT_PREV_HOLD_AUTO_SCAN

#define CUSTOMER_DEFINED_ADKEY_RESISTOR

#define EXCHANGE_LINE_IN_CHANNEL	//交换LINE IN 通道

#if 1
#define USE_POWER_KEY
#define USE_ONLY_POWER_HOLD_CTRL
#define PWR_CTRL_P02
#define USE_PWR_KEY_LONG_PWR_ON
#define PWR_ON_DELAY_1_SECOND
#endif

#define USE_POWER_KEY_SHORT_SCAN
#define POWE_KEY_PLAY_KEY_IN_ONE_KEY

#define USE_GPIO_DETECT_EARPHONE_PLUGGED
#define EARPHONE_DETECT_USE_P04

#define USE_LINE_IN_DETECT_FUNC
#define AUX_DETECT_USE_P07

#endif



#ifdef K1135_HF_1135_V001

#ifdef IIC_GPIO_USE_P02_P03
#undef IIC_GPIO_USE_P02_P03
#endif
#define IIC_GPIO_USE_P00_P01
#ifdef MUTE_PORT_USE_P01
#undef  MUTE_PORT_USE_P01
#endif
#define MUTE_PORT_USE_P03
#define EXCHANGE_LINE_IN_CHANNEL	//交换LINE IN 通道

#if 1
#define LED_USE_ROUND_LED

#define USE_POWER_KEY
#define PWR_CTRL_P02
#define USE_ONLY_POWER_HOLD_CTRL
#define USE_PWR_KEY_LONG_PWR_ON
#define POWE_KEY_PLAY_KEY_IN_ONE_KEY
#define CUSTOMER_DEFINED_ADKEY_RESISTOR
#define USE_POWER_KEY_SHORT_SCAN

#endif

#define FM_BY_PASS

#define BLUE_TOOTH_FUNC

#define USE_LINE_IN_DETECT_FUNC
#define AUX_DETECT_USE_P04
#define DISABLE_QN_SCAN_ST
#define QN_SHARE_MCU_CRYSTAL

#endif

#ifdef K0000_BT_CHT909_V003

#define LED_LIGHT_ON_ENABLE_IN_IDLE_MODE
#define NO_LED_DISPLAY
#undef LED_CTRL_LEVEL_NORMAL
#define NEW_CUSTOMIZED_LED_METHOD
#define USE_PT_2313_EQ_ONLY
#define STOP_REPLAY_FROM_FIRST_FILE
#define PT_2313_OUT_GAIN_11DB

#define BT_PRO_IR_REMOTE
#define AUX_PATH_SHARE_SAME_MP3_PT_CHAN
#define USE_AUX_2
#define BLUETOOTH_GPIO_CTRL
#define SUPPORT_PT2313
#define BT_PRO_IR_REMOTE
#define IR_USER_CODE_0x00FF
#define IR_INFO_EQ_DOWN_SCAN

#define USE_LONG_PLAY_KEY_PLAY_MODE
#define CUSTOMIZED_KEY_FUNC_ENABLE

#ifdef IIC_GPIO_USE_P02_P03
#undef IIC_GPIO_USE_P02_P03
#endif
#define IIC_GPIO_USE_P00_P01

#ifdef MUTE_PORT_USE_P01
#undef  MUTE_PORT_USE_P01
#endif
#define MUTE_PORT_USE_P03

#define DISP_VOL_V_CHAR
#define SUPERIOR_CUSTOMER

#define EXCHANGE_LINE_IN_CHANNEL	//交换LINE IN 通道

#define SYS_DEFAULT_IN_IDLE_POWER_DOWN_MODE

//#define BLUE_TOOTH_FUNC

#define ADKEY_USE_P07_PORT
#define CUSTOMER_DEFINED_ADKEY_RESISTOR


#define ADKEY_PLAY_SHORT_ADJ_CH
#define SEMI_AUTO_SCAN_FREQ
#define ADKEY_NEXT_PREV_HOLD_AUTO_SCAN
#define IR_NEXT_PREV_HOLD_AUTO_SCAN
#define IR_PLAY_SHORT_CH_UP

#define DECODE_STOP_MODE_ENABLE
#define EXTENDED_WORK_MODE_USE_TWO_GPIO_CTRL
//#define AUX_MODE_HOT_KEY_ENABLE
//#define MUSIC_MODE_HOT_KEY_ENABLE
//#define RADIO_MODE_HOT_KEY_ENABLE
//#define BT_MODE_HOT_KEY_ENABLE

#endif


#ifdef K0000_BT_CHT909_V002

#define LED_LIGHT_ON_ENABLE_IN_IDLE_MODE
#define NO_LED_DISPLAY
#undef LED_CTRL_LEVEL_NORMAL
#define NEW_CUSTOMIZED_LED_METHOD
#define USE_PT_2313_EQ_ONLY
#define STOP_REPLAY_FROM_FIRST_FILE
#define PT_2313_OUT_GAIN_11DB

#define BT_PRO_IR_REMOTE
#define AUX_PATH_SHARE_SAME_MP3_PT_CHAN
#define USE_AUX_2
#define BLUETOOTH_GPIO_CTRL
#define SUPPORT_PT2313
#define BT_PRO_IR_REMOTE
#define IR_USER_CODE_0x00FF
#define IR_INFO_EQ_DOWN_SCAN

#define DECODE_STOP_MODE_ENABLE

#ifdef IIC_GPIO_USE_P02_P03
#undef IIC_GPIO_USE_P02_P03
#endif
#define IIC_GPIO_USE_P00_P01

#ifdef MUTE_PORT_USE_P01
#undef  MUTE_PORT_USE_P01
#endif
#define MUTE_PORT_USE_P03

#define DISP_VOL_V_CHAR
#define SUPERIOR_CUSTOMER

#define EXCHANGE_LINE_IN_CHANNEL	//交换LINE IN 通道

#define SYS_DEFAULT_IN_IDLE_POWER_DOWN_MODE

#define BLUE_TOOTH_FUNC

#define ADKEY_USE_P07_PORT
#define CUSTOMER_DEFINED_ADKEY_RESISTOR


#define ADKEY_PLAY_SHORT_ADJ_CH
#define SEMI_AUTO_SCAN_FREQ
#define ADKEY_NEXT_PREV_HOLD_AUTO_SCAN
#define IR_NEXT_PREV_HOLD_AUTO_SCAN
#define IR_PLAY_SHORT_CH_UP

#define DECODE_STOP_MODE_ENABLE
#define EXTENDED_WORK_MODE_USE_TWO_GPIO_CTRL
//#define AUX_MODE_HOT_KEY_ENABLE
//#define MUSIC_MODE_HOT_KEY_ENABLE
//#define RADIO_MODE_HOT_KEY_ENABLE
//#define BT_MODE_HOT_KEY_ENABLE

#endif


#ifdef K0000_BT_CHT909_V001

//#undef LED_GPIO_DRV
#define NO_LED_DISPLAY
#undef LED_CTRL_LEVEL_NORMAL
#define NEW_CUSTOMIZED_LED_METHOD
#define USE_PT_2313_EQ_ONLY
#define STOP_REPLAY_FROM_FIRST_FILE
#define PT_2313_OUT_GAIN_11DB

#define BT_PRO_IR_REMOTE
#define AUX_PATH_SHARE_SAME_MP3_PT_CHAN
#define USE_AUX_2
#define BLUETOOTH_GPIO_CTRL
#define SUPPORT_PT2313
#define BT_PRO_IR_REMOTE
#define IR_USER_CODE_0x00FF
#define IR_INFO_EQ_DOWN_SCAN

#define DECODE_STOP_MODE_ENABLE

#ifdef IIC_GPIO_USE_P02_P03
#undef IIC_GPIO_USE_P02_P03
#endif
#define IIC_GPIO_USE_P00_P01

#ifdef MUTE_PORT_USE_P01
#undef  MUTE_PORT_USE_P01
#endif
#define MUTE_PORT_USE_P03

#define DISP_VOL_V_CHAR
#define SUPERIOR_CUSTOMER

#define EXCHANGE_LINE_IN_CHANNEL	//交换LINE IN 通道

#define SYS_DEFAULT_IN_IDLE_POWER_DOWN_MODE

#define BLUE_TOOTH_FUNC

#define ADKEY_USE_P07_PORT
#define CUSTOMER_DEFINED_ADKEY_RESISTOR


#define ADKEY_PLAY_SHORT_ADJ_CH
#define SEMI_AUTO_SCAN_FREQ
#define ADKEY_NEXT_PREV_HOLD_AUTO_SCAN
#define IR_NEXT_PREV_HOLD_AUTO_SCAN
#define IR_PLAY_SHORT_CH_UP


//#define AUX_MODE_HOT_KEY_ENABLE
//#define MUSIC_MODE_HOT_KEY_ENABLE
//#define RADIO_MODE_HOT_KEY_ENABLE
//#define BT_MODE_HOT_KEY_ENABLE

#endif

#ifdef K1132_ZK_963_V001

#define ROUND_LED_USE_OFFEN

#ifdef IIC_GPIO_USE_P02_P03
#undef IIC_GPIO_USE_P02_P03
#endif
#define IIC_GPIO_USE_P00_P01

#ifdef MUTE_PORT_USE_P01
#undef  MUTE_PORT_USE_P01
#endif
#define MUTE_PORT_USE_P03

#define DISP_VOL_V_CHAR

#define EXCHANGE_LINE_IN_CHANNEL	//交换LINE IN 通道

#define LED_GPIO_PORT_CUSTOMERIZED
#define LED_COMMON_SCAN_COM_USE_P17
#define NO_DEV_SHOW_HI_STR
#define DEFAULT_GO_TO_IDLE
#define DISP_PAU_STRING


#define FM_MAX_CHANNAL_50

#define TWO_ADKEY_ENABLE
#define TWO_ADKEY_USE_PORT_P07
#define INDEPENDENT_VOLUME_KEY

#define CUSTOMER_DEFINED_ADKEY_RESISTOR
#define SEMI_AUTO_SCAN_FREQ

#define USE_GPIO_DETECT_EARPHONE_PLUGGED
#define EARPHONE_DETECT_USE_P04
#endif


#ifdef K0000_GW_ZX015_V001

#ifdef IIC_GPIO_USE_P02_P03
#undef IIC_GPIO_USE_P02_P03
#endif
#define IIC_GPIO_USE_P00_P01
#ifdef MUTE_PORT_USE_P01
#undef  MUTE_PORT_USE_P01
#endif
#define MUTE_PORT_USE_P03
#define PLAY_MODE_REPEAT_ALL

#define LED_GPIO_PORT_CUSTOMERIZED

#define EXCHANGE_LINE_IN_CHANNEL	//交换LINE IN 通道
#undef MUTE_CTRL_LEVEL_NORMAL

#define GUOWEI_IR_REMOTE
#define EXCHANGE_FM_AUX_PRIO

#define CUSTOMER_DEFINED_ADKEY_RESISTOR
#define NEW_RES_VALUE_CACULATING
#define CUSTOME_GW_RES_VALUE

#define SEMI_AUTO_SCAN_FREQ
#define IR_NEXT_PREV_SHORT_AUTO_SCAN
#define ADKEY_NEXT_PREV_SHORT_AUTO_SCAN

#define IR_NEXT_PREV_KEY_LONG_SEL_DIR
#define USE_FOLDER_SELECT_FUNC
#define PLAY_MODE_USE_REP_ONE_ALL

#define IR_NEXT_PREV_KEY_HOLD_DO_NOTHING

#define EXCHANGE_FM_MP3_ICON
#define VOLUME_DEFUALT 30
#define ADKEY_PLAY_SHORT_ADJ_CH
#define VOLUME_CUSTOMER_DEFINE_32

#define USE_AMP_MODE_SELECT
#define AMP_MODE_SELECT_PORT_USE_P04
#define LINE_IN_PLAY_KEY_PAUSE
#define LINE_IN_FLASH_WHOLE_SCREEN
#define NO_MUTE_WHEN_PAUSE
#define NO_AUX_MUTE_WHEN_PAUSE

//#define IR_PLAY_KEY_SCAN_FREQ_DISABLE
#define EQ_DOWN_SCAN_ALL
#define IR_PLAY_SHORT_CH_UP
#define USE_EQ_KEY_SHORT_CH_UP
#undef USE_USB_AUDIO
#define REMOVE_USE_DEVICE_MODE

#endif

#ifdef K0000_GW_118B_V001

#ifdef IIC_GPIO_USE_P02_P03
#undef IIC_GPIO_USE_P02_P03
#endif
#define IIC_GPIO_USE_P00_P01
#ifdef MUTE_PORT_USE_P01
#undef  MUTE_PORT_USE_P01
#endif
#define MUTE_PORT_USE_P03
#define PLAY_MODE_REPEAT_ALL

#define EXCHANGE_LINE_IN_CHANNEL	//交换LINE IN 通道
#undef LED_CTRL_LEVEL_NORMAL
#undef MUTE_CTRL_LEVEL_NORMAL

#define GUOWEI_IR_REMOTE
#define EXCHANGE_FM_AUX_PRIO

#define CUSTOMER_DEFINED_ADKEY_RESISTOR
#define NEW_RES_VALUE_CACULATING
#define CUSTOME_GW_RES_VALUE

#define SEMI_AUTO_SCAN_FREQ
#define IR_NEXT_PREV_SHORT_AUTO_SCAN
#define ADKEY_NEXT_PREV_SHORT_AUTO_SCAN

#define IR_NEXT_PREV_KEY_LONG_SEL_DIR
#define USE_FOLDER_SELECT_FUNC
#define PLAY_MODE_USE_REP_ONE_ALL

#define IR_NEXT_PREV_KEY_HOLD_DO_NOTHING

#define EXCHANGE_FM_MP3_ICON
#define VOLUME_DEFUALT 30
#define ADKEY_PLAY_SHORT_ADJ_CH
#define VOLUME_CUSTOMER_DEFINE_32

#define USE_AMP_MODE_SELECT
#define AMP_MODE_SELECT_PORT_USE_P04
#define LINE_IN_PLAY_KEY_PAUSE
#define LINE_IN_FLASH_WHOLE_SCREEN
#define NO_MUTE_WHEN_PAUSE
#define NO_AUX_MUTE_WHEN_PAUSE

#define IR_PLAY_KEY_SCAN_FREQ_DISABLE
#define EQ_DOWN_SCAN_ALL

#endif

#ifdef K0000_ZHIXING_00XX_V001

#ifdef LED_GPIO_DRV
#undef  LED_GPIO_DRV
#endif
#define LCD_GPIO_DRV

#define IR_USER_CODE_0x7F80
#define IR_REMOTER_WITH_POWER_MUTE_PRINT
#undef MUTE_CTRL_LEVEL_NORMAL
#endif

#ifdef K2321_JM_2321_V001

#ifdef IIC_GPIO_USE_P02_P03
#undef IIC_GPIO_USE_P02_P03
#endif
#define IIC_GPIO_USE_P00_P01
#ifdef MUTE_PORT_USE_P01
#undef  MUTE_PORT_USE_P01
#endif
#define MUTE_PORT_USE_P03

#define LED_USE_COMMON_4X8
#define LED_GPIO_PORT_CUSTOMERIZED

#define EXCHANGE_LINE_IN_CHANNEL	//交换LINE IN 通道

#define CUSTOMER_DEFINED_ADKEY_RESISTOR
#define ADKEY_NEW_METHOD
#define DISABLE_P05_OSC_OUTPUT

#define IR_USER_CODE_0x7F80
#define IR_REMOTER_WITH_POWER_MUTE_PRINT

#define ADKEY_PLAY_SHORT_SCAN_FRE
#define VOLUME_CUSTOMER_DEFINE_32

#define JOG_STICK_FUNC

#endif


#ifdef K1123_WXD_1123_V001

#define ROUND_LED_USE_OFFEN

#ifdef IIC_GPIO_USE_P02_P03
#undef IIC_GPIO_USE_P02_P03
#endif
#define IIC_GPIO_USE_P00_P01
#ifdef MUTE_PORT_USE_P01
#undef  MUTE_PORT_USE_P01
#endif
#define MUTE_PORT_USE_P03

#define LED_GPIO_PORT_CUSTOMERIZED
//#define LED_COMMON_SCAN_COM_USE_P17
#define EXCHANGE_LINE_IN_CHANNEL	//交换LINE IN 通道

#define CUSTOMER_DEFINED_ADKEY_RESISTOR
#define DEFAULT_GO_TO_IDLE

#if 1
#define USE_POWER_KEY
#define USE_ONLY_POWER_HOLD_CTRL
#define PWR_CTRL_P02
#define USE_PWR_KEY_LONG_PWR_ON
#define PWR_ON_DELAY_1_SECOND
#endif

#define POWE_KEY_PLAY_KEY_IN_ONE_KEY
#define ADKEY_PLAY_SHORT_SCAN_FRE
#define USE_POWER_KEY_SHORT_SCAN

#define TWO_ADKEY_ENABLE
#define TWO_ADKEY_USE_PORT_P07
#define INDEPENDENT_VOLUME_KEY

#define JOG_STICK_FUNC

#endif

#ifdef K0000_KDL_6032_V001

#ifdef IIC_GPIO_USE_P02_P03
#undef IIC_GPIO_USE_P02_P03
#endif
#define IIC_GPIO_USE_P00_P01
#ifdef MUTE_PORT_USE_P01
#undef  MUTE_PORT_USE_P01
#endif
#define MUTE_PORT_USE_P03

#define DECODE_STOP_MODE_ENABLE
#define JINRUI_IR_REMOTE_TYPE
#define FAST_LOW_BAT_PWR_OFF

#define USE_PLAY_MODE_LONG_FOR_RTC_SETTING
#define USE_LONG_PLAY_KEY_TO_SWITCH_MODE
#define ADKEY_PLAY_SHORT_SCAN_FRE
#define SEMI_AUTO_SCAN_FREQ
#define ADKEY_NEXT_PREV_HOLD_FREQ_ADJ

#define EXCHANGE_LINE_IN_CHANNEL	//交换LINE IN 通道
#define FM_MAX_CHANNAL_50
#define NO_PLAY_STATUS_LED
#define PLAY_MODE_USE_REP_ONE_ALL
#define EXCHANGE_FM_MP3_ICON
#define JINRUI_IR_REMOTE_TYPE

//#define INDEPENDENT_VOLUME_KEY
#define VOLUME_DEFUALT		28
#define VOLUME_CUSTOMER_DEFINE_28

#define LINE_IN_PLAY_KEY_PAUSE
#define DISP_PAUS_STRING
#define FM_USE_AR1015

#define USE_AMP_MODE_SELECT
#define AMP_MODE_SELECT_PORT_USE_P04
#define TURN_ON_PLAY_BREAK_POINT_MEM

#define USE_MICPHONE_GPIO_DETECTION
#define MICPHONE_GPIO_DET_USE_P17
#define PROTECT_P17_FROM_LED_SCAN

#define USE_BAT_MANAGEMENT
#define LOW_BAT_POWER_OFF_MODE

#define USE_RTC_FUNCTION
#define USE_RTC_TIME_ONLY
#define DEFAULT_GO_TO_TIME_MODE
#endif

#ifdef K0000_XDS_6032_V002

#ifdef IIC_GPIO_USE_P02_P03
#undef IIC_GPIO_USE_P02_P03
#endif
#define IIC_GPIO_USE_P00_P01
#ifdef MUTE_PORT_USE_P01
#undef  MUTE_PORT_USE_P01
#endif
#define MUTE_PORT_USE_P03

#define DECODE_STOP_MODE_ENABLE

#define USE_PLAY_MODE_LONG_FOR_RTC_SETTING
#define USE_LONG_PLAY_KEY_TO_SWITCH_MODE
#define ADKEY_PLAY_SHORT_SCAN_FRE
#define SEMI_AUTO_SCAN_FREQ
#define ADKEY_NEXT_PREV_HOLD_FREQ_ADJ

#define EXCHANGE_LINE_IN_CHANNEL	//交换LINE IN 通道
#define FM_MAX_CHANNAL_50
//#define NO_PLAY_STATUS_LED
#define PLAY_MODE_USE_REP_ONE_ALL
#define EXCHANGE_FM_MP3_ICON
#define JINRUI_IR_REMOTE_TYPE

#define INDEPENDENT_VOLUME_KEY
#define VOLUME_DEFUALT		28

#define LINE_IN_PLAY_KEY_PAUSE
#define DISP_PAUS_STRING
#define FM_USE_AR1015
#define PLAY_MODE_REPEAT_ONE

#define SEMI_AUTO_SCAN_FREQ
#define IR_NEXT_PREV_HOLD_AUTO_SCAN
#define IR_NEXT_PREV_SHORT_ADJ_CH

#define USE_AMP_MODE_SELECT
#define AMP_MODE_SELECT_PORT_USE_P04
#define TURN_ON_PLAY_BREAK_POINT_MEM

#define USE_MICPHONE_GPIO_DETECTION
#define MICPHONE_GPIO_DET_USE_P17
#define PROTECT_P17_FROM_LED_SCAN

#define DEFAULT_GO_TO_AUX
//#define USE_RTC_FUNCTION
//#define USE_RTC_TIME_ONLY
//#define DEFAULT_GO_TO_TIME_MODE
#endif

#ifdef K0000_SRS_6032_V002

#ifdef IIC_GPIO_USE_P02_P03
#undef IIC_GPIO_USE_P02_P03
#endif
#define IIC_GPIO_USE_P00_P01
#ifdef MUTE_PORT_USE_P01
#undef  MUTE_PORT_USE_P01
#endif
#define MUTE_PORT_USE_P03

#define DECODE_STOP_MODE_ENABLE

#define USE_PLAY_MODE_LONG_FOR_RTC_SETTING
#define USE_LONG_PLAY_KEY_TO_SWITCH_MODE
#define ADKEY_PLAY_SHORT_SCAN_FRE
#define SEMI_AUTO_SCAN_FREQ
#define ADKEY_NEXT_PREV_HOLD_FREQ_ADJ

#define EXCHANGE_LINE_IN_CHANNEL	//交换LINE IN 通道
#define FM_MAX_CHANNAL_50
//#define NO_PLAY_STATUS_LED
#define PLAY_MODE_USE_REP_ONE_ALL
#define EXCHANGE_FM_MP3_ICON
#define JINRUI_IR_REMOTE_TYPE

#define INDEPENDENT_VOLUME_KEY
#define VOLUME_DEFUALT		28

#define LINE_IN_PLAY_KEY_PAUSE
#define DISP_PAUS_STRING
#define FM_USE_AR1015

#define SEMI_AUTO_SCAN_FREQ
#define IR_NEXT_PREV_HOLD_AUTO_SCAN
#define IR_NEXT_PREV_SHORT_ADJ_CH

#define USE_AMP_MODE_SELECT
#define AMP_MODE_SELECT_PORT_USE_P04
#define TURN_ON_PLAY_BREAK_POINT_MEM

#define USE_MICPHONE_GPIO_DETECTION
#define MICPHONE_GPIO_DET_USE_P17
#define PROTECT_P17_FROM_LED_SCAN

#define DEFAULT_GO_TO_AUX
//#define USE_RTC_FUNCTION
//#define USE_RTC_TIME_ONLY
//#define DEFAULT_GO_TO_TIME_MODE
#endif

#ifdef K0000_SW_6032_V001

#ifdef IIC_GPIO_USE_P02_P03
#undef IIC_GPIO_USE_P02_P03
#endif
#define IIC_GPIO_USE_P00_P01
#ifdef MUTE_PORT_USE_P01
#undef  MUTE_PORT_USE_P01
#endif
#define MUTE_PORT_USE_P03

#define DECODE_STOP_MODE_ENABLE

#define USE_PLAY_MODE_LONG_FOR_RTC_SETTING
#define USE_LONG_PLAY_KEY_TO_SWITCH_MODE
#define ADKEY_PLAY_SHORT_SCAN_FRE
#define SEMI_AUTO_SCAN_FREQ
#define ADKEY_NEXT_PREV_HOLD_FREQ_ADJ

#define EXCHANGE_LINE_IN_CHANNEL	//交换LINE IN 通道
#define FM_MAX_CHANNAL_50
//#define NO_PLAY_STATUS_LED
#define PLAY_MODE_USE_REP_ONE_ALL
#define EXCHANGE_FM_MP3_ICON
//#define JINRUI_IR_REMOTE_TYPE

#define INDEPENDENT_VOLUME_KEY
#define VOLUME_DEFUALT		28

#define LINE_IN_PLAY_KEY_PAUSE
#define DISP_PAUS_STRING
#define STOP_MODE_SHOW_STOP
#define FM_USE_AR1015

#define USE_AMP_MODE_SELECT
#define AMP_MODE_SELECT_PORT_USE_P04
#define TURN_ON_PLAY_BREAK_POINT_MEM

#define USE_MICPHONE_GPIO_DETECTION
#define MICPHONE_GPIO_DET_USE_P17
#define PROTECT_P17_FROM_LED_SCAN

#define KEY_100_ENABLE
#define DEFAULT_GO_TO_AUX
//#define IR_REMOTER_WITH_POWER_MUTE_PRINT
#define LED_USE_PLAY_MODE
//#define USE_RTC_TIME_ONLY
//#define DEFAULT_GO_TO_TIME_MODE
#endif

#ifdef K0000_SRS_6032_V001

#ifdef IIC_GPIO_USE_P02_P03
#undef IIC_GPIO_USE_P02_P03
#endif
#define IIC_GPIO_USE_P00_P01
#ifdef MUTE_PORT_USE_P01
#undef  MUTE_PORT_USE_P01
#endif
#define MUTE_PORT_USE_P03

#define DECODE_STOP_MODE_ENABLE

#define USE_PLAY_MODE_LONG_FOR_RTC_SETTING
#define USE_LONG_PLAY_KEY_TO_SWITCH_MODE
#define ADKEY_PLAY_SHORT_SCAN_FRE
#define SEMI_AUTO_SCAN_FREQ
#define ADKEY_NEXT_PREV_HOLD_FREQ_ADJ

#define EXCHANGE_LINE_IN_CHANNEL	//交换LINE IN 通道
#define FM_MAX_CHANNAL_50
//#define NO_PLAY_STATUS_LED
#define PLAY_MODE_USE_REP_ONE_ALL
#define EXCHANGE_FM_MP3_ICON
#define JINRUI_IR_REMOTE_TYPE

#define INDEPENDENT_VOLUME_KEY
#define VOLUME_DEFUALT		28

#define LINE_IN_PLAY_KEY_PAUSE
#define DISP_PAUS_STRING
#define STOP_MODE_SHOW_STOP
#define FM_USE_AR1015

#define USE_AMP_MODE_SELECT
#define AMP_MODE_SELECT_PORT_USE_P04
#define TURN_ON_PLAY_BREAK_POINT_MEM

#define USE_MICPHONE_GPIO_DETECTION
#define MICPHONE_GPIO_DET_USE_P17
#define PROTECT_P17_FROM_LED_SCAN

#define DEFAULT_GO_TO_AUX
//#define USE_RTC_FUNCTION
//#define USE_RTC_TIME_ONLY
//#define DEFAULT_GO_TO_TIME_MODE
#endif

#ifdef K1119_LS_1119_V001

#define LED_USE_PLAY_MODE
#define IR_USER_CODE_0xDF20

#ifdef IIC_GPIO_USE_P02_P03
#undef IIC_GPIO_USE_P02_P03
#endif
#define IIC_GPIO_USE_P00_P01

#ifdef MUTE_PORT_USE_P01
#undef  MUTE_PORT_USE_P01
#endif
#define MUTE_PORT_USE_P03

#define EXCHANGE_LINE_IN_CHANNEL	//交换LINE IN 通道
#define MP3_MODE_EQ_DOWN_DO_NOTHING
#define IR_NEXT_PREV_KEY_HOLD_DO_NOTHING

#define DISP_VOL_V_CHAR

#define DEFAULT_GO_TO_AUX

#define LED_GPIO_PORT_CUSTOMERIZED
#define LED_COMMON_SCAN_COM_USE_P17


#define INDEPENDENT_SKIP_KEY_AT_MINUS_PLUS
#define ADKEY_NEXT_ADJST_FREQ
#define SEMI_AUTO_SCAN_FREQ
#define IR_NEXT_PREV_DO_NOTHING
#define INDEPENDENT_KEY_TUNE_FREQ
#define IR_PLAY_KEY_SCAN_FREQ_DISABLE
#define IR_INFO_EQ_DOWN_SCAN

#endif

#ifdef K0000_WK_S638_V001

#define LED_USE_PLAY_MODE
#ifdef IIC_GPIO_USE_P02_P03
#undef IIC_GPIO_USE_P02_P03
#endif
#define IIC_GPIO_USE_P00_P01
#ifdef MUTE_PORT_USE_P01
#undef  MUTE_PORT_USE_P01
#endif
#define MUTE_PORT_USE_P03

#define ADKEY_PLAY_SHORT_SCAN_FRE
#define SEMI_AUTO_SCAN_FREQ
#define ADKEY_NEXT_PREV_HOLD_AUTO_SCAN

#define EXCHANGE_LINE_IN_CHANNEL	//交换LINE IN 通道

#define NO_PLAY_STATUS_LED
#define PLAY_MODE_USE_REP_ONE_ALL

#define INDEPENDENT_VOLUME_KEY
#define VOLUME_DEFUALT		28

#define USE_BAT_MANAGEMENT
#define BAT_LEVEL_LED_ICON_IND

#define CHARGER_DETECT_INDICATOR
#define CHARGER_DET_USE_P02
#define CHARGER_FLASH_TYPE_2

#define USE_GPIO_DETECT_EARPHONE_PLUGGED
#define EARPHONE_DETECT_USE_P04

#endif

#ifdef K1116_WXD_1116_V001

#ifdef IIC_GPIO_USE_P02_P03
#undef IIC_GPIO_USE_P02_P03
#endif
#define IIC_GPIO_USE_P00_P01

#ifdef MUTE_PORT_USE_P01
#undef  MUTE_PORT_USE_P01
#endif
#define MUTE_PORT_USE_P03

#if 1
#define USE_POWER_KEY
#define USE_ONLY_POWER_HOLD_CTRL
#define PWR_CTRL_P02
#define USE_PWR_KEY_LONG_PWR_ON
#define PWR_ON_DELAY_1_SECOND
#endif

#define LED_GPIO_PORT_CUSTOMERIZED
#define LED_COMMON_SCAN_COM_USE_P17
#define CUSTOMER_DEFINED_ADKEY_RESISTOR

#define EXCHANGE_LINE_IN_CHANNEL	//交换LINE IN 通道

#define TWO_ADKEY_ENABLE
#define TWO_ADKEY_USE_PORT_P07
#define INDEPENDENT_VOLUME_KEY


#define USE_GPIO_DETECT_EARPHONE_PLUGGED
#define EARPHONE_DETECT_USE_P04
#endif

#ifdef K0000_XL_A2_V001

//#define LED_GPIO_PORT_CUSTOMERIZED

#define PLAY_STATUS_LED_P00

#define EXCHANGE_LINE_IN_CHANNEL	//交换LINE IN 通道

#define FM_MAX_CHANNAL_50
#define VOLUME_CUSTOMER_DEFINE_16
#define NEW_CUSTOMED_VOLUME_DIVIDED_METHOD

#define DISP_BAR_ICON

#if 1
#define USE_POWER_KEY
#define PWR_CTRL_WKUP
#define POWER_KEY_ON_WAIT_FOR_3_SEC
#define PWR_ON_DELAY_1_SECOND
#endif

#define DEFAULT_GO_TO_IDLE
#define POWE_KEY_PLAY_KEY_IN_ONE_KEY

#define CUSTOMER_DEFINED_ADKEY_RESISTOR

#define ADKEY_PLAY_SHORT_SCAN_FRE
#define DISABLE_QN_SCAN_ST
#define USE_POWER_KEY_SHORT_SCAN

#define USE_LINE_IN_DETECT_FUNC
#define AUX_DETECT_USE_P04

//#define USE_GPIO_DETECT_EARPHONE_PLUGGED
//#define EARPHONE_DETECT_USE_P03
//#define PLAY_STATUS_LED_SHARE_WITH_IIC_SCL

#define USE_HEADHPONE_DISABLE_FUNC

//#define USE_BAT_MANAGEMENT

#define CHARGER_DETECT_INDICATOR
#define CHARGER_FLASH_TYPE_1

#define DISP_VOL_V_CHAR
#define FM_DISP_CH_STR
#define QN_SCAN_HIGH_SENSE


#endif

#ifdef K2056_AJE_2056_V001

#ifdef IIC_GPIO_USE_P02_P03
#undef IIC_GPIO_USE_P02_P03
#endif
#define IIC_GPIO_USE_P00_P01

#ifdef MUTE_PORT_USE_P01
#undef  MUTE_PORT_USE_P01
#endif
#define MUTE_PORT_USE_P03

#define LED_GPIO_PORT_CUSTOMERIZED
#define LED_COMMON_SCAN_COM_USE_P17

#define CUSTOMER_DEFINED_ADKEY_RESISTOR

#define EXCHANGE_LINE_IN_CHANNEL	//交换LINE IN 通道


#if 1
#define USE_POWER_KEY
#define USE_ONLY_POWER_HOLD_CTRL
#define PWR_CTRL_P02
#define USE_PWR_KEY_LONG_PWR_ON
#define PWR_ON_DELAY_1_SECOND
#endif
#define USE_POWER_KEY_SHORT_SCAN
#define POWE_KEY_PLAY_KEY_IN_ONE_KEY

//#define USE_LINE_IN_DETECT_FUNC
//#define AUX_DETECT_USE_P02

#endif

#ifdef K1102_JM_836_V001

#ifdef IIC_GPIO_USE_P02_P03
#undef IIC_GPIO_USE_P02_P03
#endif
#define IIC_GPIO_USE_P00_P01

#ifdef MUTE_PORT_USE_P01
#undef  MUTE_PORT_USE_P01
#endif
#define MUTE_PORT_USE_P03

#define CUSTOMER_DEFINED_ADKEY_RESISTOR

#define EXCHANGE_LINE_IN_CHANNEL	//交换LINE IN 通道

#define ADKEY_PLAY_SHORT_SCAN_FRE
//#define USE_LINE_IN_DETECT_FUNC
//#define AUX_DETECT_USE_P02

#endif

#ifdef K1115_WXD_1115_V001

#ifdef IIC_GPIO_USE_P02_P03
#undef IIC_GPIO_USE_P02_P03
#endif
#define IIC_GPIO_USE_P00_P01

#ifdef MUTE_PORT_USE_P01
#undef  MUTE_PORT_USE_P01
#endif
#define MUTE_PORT_USE_P03

#define LED_GPIO_PORT_CUSTOMERIZED
#define LED_COMMON_SCAN_COM_USE_P17
#define CUSTOMER_DEFINED_ADKEY_RESISTOR

#define EXCHANGE_LINE_IN_CHANNEL	//交换LINE IN 通道

#define TWO_ADKEY_ENABLE
#define TWO_ADKEY_USE_PORT_P07
#define INDEPENDENT_VOLUME_KEY


#define USE_GPIO_DETECT_EARPHONE_PLUGGED
#define EARPHONE_DETECT_USE_P04
#endif

#ifdef K0000_GW_238_V001

#ifdef IIC_GPIO_USE_P02_P03
#undef IIC_GPIO_USE_P02_P03
#endif
#define IIC_GPIO_USE_P00_P01

#ifdef MUTE_PORT_USE_P01
#undef  MUTE_PORT_USE_P01
#endif
#define MUTE_PORT_USE_P03
#define EXCHANGE_FM_MP3_ICON

#define CUSTOMER_DEFINED_ADKEY_RESISTOR
#define NEW_RES_VALUE_CACULATING
#define CUSTOME_GW_RES_VALUE

#define DEFAULT_GO_TO_CUSTOM_MODE
#define NEW_SD_DETECT_MOD

#define EXCHANGE_FM_AUX_PRIO
#define USB_SD_PLAY_INFO_DIV
#define USE_LONG_PLAY_KEY_PLAY_MODE
#define EQ_ADJ_USE_MODE_KEY_LONG
#define PLAY_MODE_USE_REP_ALL_PLAY_IN_SEQUENCE
#define DISABLE_FM_CH_SEL_MUTE

#define EXCHANGE_LINE_IN_CHANNEL	//交换LINE IN 通道
#define PLAY_MODE_USE_REP_ONE_ALL
#define NEXT_PREV_KEY_RESTART_WHEN_REP_ONE
#define IR_PLAY_SHORT_CH_UP
#define IR_NEXT_PREV_KEY_HOLD_DO_NOTHING

#define ADKEY_NEXT_ADJST_FREQ
#define SEMI_AUTO_SCAN_FREQ
//#define MUTE_EXAMP_AT_FM_NEXT_PREV
#define ADKEY_NEXT_PREV_HOLD_AUTO_SCAN
//#define MUTE_EXAMP_AT_FM_NEXT_PREV_IMPROVE

#define IR_NEXT_PREV_HOLD_AUTO_SCAN
#define EQ_DOWN_SCAN_ALL

#define USE_GPIO_DETECT_EARPHONE_PLUGGED
#define EARPHONE_DETECT_USE_P07
#define PLAY_STATUS_LED_SHARE_WITH_DET

#define MUTE_EXAMP_AT_NEXT_PREV
#endif


#ifdef K1111_ZK_1111_V001

#define PLAY_STATUS_LED_P05

#ifdef IIC_GPIO_USE_P02_P03
#undef IIC_GPIO_USE_P02_P03
#endif
#define IIC_GPIO_USE_P00_P01

#ifdef MUTE_PORT_USE_P01
#undef  MUTE_PORT_USE_P01
#endif
#define MUTE_PORT_USE_P03
#define FAST_BAND_SCAN_SPEED

#define EXCHANGE_LINE_IN_CHANNEL	//交换LINE IN 通道
#define VOLUME_DEFUALT 		25

#define DEFAULT_GO_TO_IDLE
#define NO_DEV_SHOW_HI_STR
//#define SEMI_AUTO_SCAN_FREQ
//#define ADKEY_NEXT_PREV_HOLD_AUTO_SCAN

#define USE_GPIO_DETECT_EARPHONE_PLUGGED

#endif

#ifdef K1203_SES_A26_V001

#define AC209_28PIN
#define LED_1651_DRV
#ifdef LED_GPIO_DRV
#undef LED_GPIO_DRV
#endif

#ifdef IIC_GPIO_USE_P02_P03
#undef IIC_GPIO_USE_P02_P03
#endif
#define IIC_GPIO_USE_P00_P01

#ifdef MUTE_PORT_USE_P01
#undef  MUTE_PORT_USE_P01
#endif
#define MUTE_PORT_USE_P03
#define FAST_BAND_SCAN_SPEED
#define EXCHANGE_FM_MP3_ICON

#define EXCHANGE_LINE_IN_CHANNEL	//交换LINE IN 通道
#define VOLUME_DEFUALT 		25

#define LINE_IN_PLAY_KEY_PAUSE
#define DISP_PAUS_STRING
#define DISP_VOL_V_CHAR
//#define SEMI_AUTO_SCAN_FREQ
#define TURN_ON_PLAY_BREAK_POINT_MEM

#define USE_GPIO_DETECT_EARPHONE_PLUGGED
#define EARPHONE_DETECT_USE_VPP
#endif

#ifdef K1111_YHD_Y882_V001

#define PLAY_STATUS_LED_P05

#ifdef IIC_GPIO_USE_P02_P03
#undef IIC_GPIO_USE_P02_P03
#endif
#define IIC_GPIO_USE_P00_P01

#ifdef MUTE_PORT_USE_P01
#undef  MUTE_PORT_USE_P01
#endif
#define MUTE_PORT_USE_P03
#define FAST_BAND_SCAN_SPEED
#define EXCHANGE_FM_MP3_ICON

#define EXCHANGE_LINE_IN_CHANNEL	//交换LINE IN 通道
#define VOLUME_DEFUALT 		20

//#define SEMI_AUTO_SCAN_FREQ
//#define ADKEY_NEXT_PREV_HOLD_AUTO_SCAN

#define DISP_PAUS_STRING
#define DISP_VOL_V_CHAR
#define USE_GPIO_DETECT_EARPHONE_PLUGGED

#define LINE_IN_PLAY_KEY_PAUSE

#define USE_LINE_IN_DETECT_FUNC
#define AUX_DETECT_USE_P04

#endif

#ifdef K1111_SES_1111_V001

#define PLAY_STATUS_LED_P05

#ifdef IIC_GPIO_USE_P02_P03
#undef IIC_GPIO_USE_P02_P03
#endif
#define IIC_GPIO_USE_P00_P01

#ifdef MUTE_PORT_USE_P01
#undef  MUTE_PORT_USE_P01
#endif
#define MUTE_PORT_USE_P03
#define FAST_BAND_SCAN_SPEED
#define EXCHANGE_FM_MP3_ICON

#define EXCHANGE_LINE_IN_CHANNEL	//交换LINE IN 通道
#define VOLUME_DEFUALT 		25

//#define SEMI_AUTO_SCAN_FREQ
//#define ADKEY_NEXT_PREV_HOLD_AUTO_SCAN

#define USE_GPIO_DETECT_EARPHONE_PLUGGED

#endif

#ifdef K0000_MC_K16_V002

#define PLAY_STATUS_LED_P17
#define PROTECT_P17_FROM_LED_SCAN

#define MEICHENG_IR_REMOTE

#define EXCHANGE_FM_MP3_ICON
#undef MUTE_CTRL_LEVEL_NORMAL

#ifdef IIC_GPIO_USE_P02_P03
#undef IIC_GPIO_USE_P02_P03
#endif
#define IIC_GPIO_USE_P00_P01

#ifdef MUTE_PORT_USE_P01
#undef  MUTE_PORT_USE_P01
#endif
#define MUTE_PORT_USE_P03

#define USE_AMP_MODE_SELECT
#define USE_MICPHONE_GPIO_DETECTION
#define MICPHONE_GPIO_DET_USE_P02

#define EXCHANGE_LINE_IN_CHANNEL	//交换LINE IN 通道

//#define USE_LONG_PLAY_KEY_TO_SWITCH_MODE
#define PLAY_MODE_USE_REP_ONE_ALL

#define INDEPENDENT_VOLUME_KEY

#define TURN_ON_PLAY_BREAK_POINT_MEM

#define VOLUME_DEFUALT 		30

//#define ADKEY_PLAY_SHORT_SCAN_FRE
#define SEMI_AUTO_SCAN_FREQ
#define ADKEY_NEXT_PREV_HOLD_AUTO_SCAN

#define DISP_PAUS_STRING
//#define MIC_HIGH_LEVEL_DETECT_FUNC
#define FM_PLAY_KEY_PAUSE
#define LINE_IN_PLAY_KEY_PAUSE
#define NO_DEV_LED_IMPROVE

#define DEFAULT_GO_TO_IDLE
#define USE_BAT_MANAGEMENT
#define LOW_BAT_POWER_OFF_MODE
#endif

#ifdef K0000_MC_K16_V001

#define PLAY_STATUS_LED_P17
#define PROTECT_P17_FROM_LED_SCAN

#define MEICHENG_IR_REMOTE

#define EXCHANGE_FM_MP3_ICON
#undef MUTE_CTRL_LEVEL_NORMAL

#ifdef IIC_GPIO_USE_P02_P03
#undef IIC_GPIO_USE_P02_P03
#endif
#define IIC_GPIO_USE_P00_P01

#ifdef MUTE_PORT_USE_P01
#undef  MUTE_PORT_USE_P01
#endif
#define MUTE_PORT_USE_P03

#define USE_AMP_MODE_SELECT
#define USE_MICPHONE_GPIO_DETECTION
#define MICPHONE_GPIO_DET_USE_P02

#define EXCHANGE_LINE_IN_CHANNEL	//交换LINE IN 通道

#define USE_LONG_PLAY_KEY_TO_SWITCH_MODE
#define PLAY_MODE_USE_REP_ONE_ALL

#define INDEPENDENT_VOLUME_KEY

#define TURN_ON_PLAY_BREAK_POINT_MEM

#define VOLUME_DEFUALT 		30

#define ADKEY_PLAY_SHORT_SCAN_FRE
#define SEMI_AUTO_SCAN_FREQ
#define ADKEY_NEXT_PREV_HOLD_AUTO_SCAN

#define DISP_PAUS_STRING
//#define MIC_HIGH_LEVEL_DETECT_FUNC
#define LINE_IN_PLAY_KEY_PAUSE
#define NO_DEV_LED_IMPROVE

#define DEFAULT_GO_TO_IDLE
#define USE_BAT_MANAGEMENT
#define LOW_BAT_POWER_OFF_MODE
#endif


#ifdef K000_JLH_938_V001

#ifdef MUTE_PORT_USE_P01
#undef  MUTE_PORT_USE_P01
#endif
 #define MUTE_PORT_USE_P04

#define EXCHANGE_LINE_IN_CHANNEL	//交换LINE IN 通道

#define DISP_HIFI_ANIMIATION_AT_PWR_ON
#define DISP_OFF_ANIMIATION_AT_PWR_DOWN
#define EXCHANGE_FM_MP3_ICON
#define DISP_PAUS_STRING

#define CUSTOMER_DEFINED_ADKEY_RESISTOR

#define ADKEY_NEW_METHOD

#define TWO_ADKEY_ENABLE
#define TWO_ADKEY_USE_PORT_P07
#define INDEPENDENT_VOLUME_KEY
#define EXTENDED_ADKEY_NUM

#define USE_ADKEY_FOR_AUX_HP_DETECTION_AT_SECOND_ADKEY
#define USE_ADKEY_FOR_AUX_HP_DETECTION
#define USE_LINE_IN_DETECT_FUNC
#define USE_ADKEY_DETECT_AUX
#define USE_GPIO_DETECT_EARPHONE_PLUGGED
#define USE_ADKEY_DETECT_HP

#endif


#ifdef K0000_XXX_SX_V001

#define NO_PLAY_STATUS_LED
#ifdef IIC_GPIO_USE_P02_P03
#undef IIC_GPIO_USE_P02_P03
#endif
#define IIC_GPIO_USE_P00_P01
#ifdef MUTE_PORT_USE_P01
#undef  MUTE_PORT_USE_P01
#endif
 #define MUTE_PORT_USE_P03
#define LED_GPIO_PORT_CUSTOMERIZED

#define CUSTOMER_DEFINED_ADKEY_RESISTOR

#define EXCHANGE_LINE_IN_CHANNEL	//交换LINE IN 通道
#define FAST_BAND_SCAN_SPEED

#define TWO_ADKEY_ENABLE
#define TWO_ADKEY_USE_PORT_P07
#define EXCHANGE_FM_MP3_ICON
#if 1
#define USE_POWER_KEY
#define USE_ONLY_POWER_HOLD_CTRL
#define PWR_CTRL_P02
#define USE_PWR_KEY_LONG_PWR_ON
#define PWR_ON_DELAY_1_SECOND
#endif

#define USE_POWER_KEY_SHORT_SCAN
#define POWE_KEY_PLAY_KEY_IN_ONE_KEY

#define USE_GPIO_DETECT_EARPHONE_PLUGGED
#define EARPHONE_DETECT_USE_P04

#endif

#ifdef K1107_DCX_991_V001

#ifdef IIC_GPIO_USE_P02_P03
#undef IIC_GPIO_USE_P02_P03
#endif
#define IIC_GPIO_USE_P00_P01
#ifdef MUTE_PORT_USE_P01
#undef  MUTE_PORT_USE_P01
#endif
 #define MUTE_PORT_USE_P03
#define LED_GPIO_PORT_CUSTOMERIZED

#define EXCHANGE_LINE_IN_CHANNEL	//交换LINE IN 通道

#define USE_GPIO_DETECT_EARPHONE_PLUGGED
#define EARPHONE_DETECT_USE_P02
#define DISP_PC_STR
#define DISP_VOL_V_CHAR
#define DISP_PAUS_STRING

#define ENABLE_MODE_KEY_AT_USB_AUDIO

#define VOLUME_DEFUALT	20

#define LINE_IN_PLAY_KEY_PAUSE
#define USE_LINE_IN_DETECT_FUNC
#define AUX_DETECT_USE_P07

#endif

#ifdef K0000_MC_FMC3_V001

#define LED_USE_PLAY_MODE

#define JOG_STICK_FUNC
#define USE_IR_VPP_PORT_FOR_DETECTION
#define PROTECT_P17_FROM_LED_SCAN

#ifdef IIC_GPIO_USE_P02_P03
#undef IIC_GPIO_USE_P02_P03
#endif
#define IIC_GPIO_USE_P00_P01
#ifdef MUTE_PORT_USE_P01
#undef  MUTE_PORT_USE_P01
#endif
 #define MUTE_PORT_USE_P03
//#define LED_GPIO_PORT_CUSTOMERIZED
//#define COMMON_CATHODE
#define DISP_BAR_ICON
#define DISP_PC_STR
#define CUSTOMER_DEFINED_ADKEY_RESISTOR

#if 1
#define USE_POWER_KEY
#define USE_ONLY_POWER_HOLD_CTRL
#define PWR_CTRL_P02
#define USE_PWR_KEY_LONG_PWR_ON
#define PWR_ON_DELAY_1_SECOND
#endif
#define USE_POWER_KEY_SHORT_SCAN
#define POWE_KEY_PLAY_KEY_IN_ONE_KEY

#define EXCHANGE_LINE_IN_CHANNEL	//交换LINE IN 通道

#define VOLUME_DEFUALT	30

#define USE_GPIO_DETECT_EARPHONE_PLUGGED
#define EARPHONE_DETECT_USE_P07
#define INDEPENDENT_VOLUME_KEY
#define PLAY_MODE_USE_REP_ONE_ALL
#define USE_LONG_PLAY_KEY_PLAY_MODE

#define NOT_MOUNT_FM_DEV
#define RADIO_MODE_HOT_KEY_ENABLE
#define SEMI_AUTO_SCAN_FREQ
#define ADKEY_NEXT_PREV_HOLD_AUTO_SCAN
#define FM_PLAY_KEY_PAUSE
#define DISP_FM_PAUS_STRING

#define TURN_ON_PLAY_BREAK_POINT_MEM

#define DISP_PAUS_STRING
#define NOT_USE_LINE_IN_FUNC
#define DEFAULT_GO_TO_IDLE

#define USE_BAT_MANAGEMENT
#define CHARGER_DETECT_INDICATOR
#define CHARGER_DET_USE_P04
#define CHARGER_FLASH_TYPE_3
#define BAT_LEVEL_LED_ICON_IND
#define LOW_VOLT_SPARK_BAT_ICON
#define LOW_BAT_POWER_OFF_MODE

#define DISP_OFF_STR_AT_PWR_DOWN
#define DISP_HIFI_STR_AT_POWER_ON
#endif

#ifdef K0000_MC_L2A_V001

#define LED_USE_PLAY_MODE
#define LED_GPIO_PORT_CUSTOMERIZED

#define IMPROVED_BAT_MEASURE
#ifdef IIC_GPIO_USE_P02_P03
#undef IIC_GPIO_USE_P02_P03
#endif
#define IIC_GPIO_USE_P00_P01

#define FM_MINI_FRE_875
#ifdef MUTE_PORT_USE_P01
#undef  MUTE_PORT_USE_P01
#endif
 #define MUTE_PORT_USE_P03

#define DISP_PC_STR
#define DISP_VOL_V_CHAR

#define EXCHANGE_LINE_IN_CHANNEL	//交换LINE IN 通道

#define VOLUME_DEFUALT	20

#define CUSTOMER_DEFINED_ADKEY_RESISTOR
#define ADKEY_NEW_METHOD
#define TWO_ADKEY_ENABLE
#define TWO_ADKEY_USE_PORT_P02
#define EXTENDED_ADKEY_NUM

#define USE_GPIO_DETECT_EARPHONE_PLUGGED
#define EARPHONE_DETECT_USE_P07
#define INDEPENDENT_VOLUME_KEY
#define PLAY_MODE_USE_REP_ONE_ALL
#define USE_LONG_PLAY_KEY_PLAY_MODE
#define EQ_ADJ_USE_MODE_KEY_LONG

//#define CUSTOM_RADIO_FREQ_875
//#define RADIO_MODE_HOT_KEY_ENABLE
#define SEMI_AUTO_SCAN_FREQ
#define ADKEY_NEXT_PREV_HOLD_AUTO_SCAN
#define FM_PLAY_KEY_PAUSE

#define LINE_IN_PLAY_KEY_PAUSE

#define TURN_ON_PLAY_BREAK_POINT_MEM

#define DISP_PAUS_STRING
#define DEFAULT_GO_TO_IDLE

#define USE_LINE_IN_DETECT_FUNC
#define AUX_DETECT_USE_P17

#define USE_BAT_MANAGEMENT
#define CHARGER_DETECT_INDICATOR
#define CHARGER_DET_USE_P04
#define CHARGER_FLASH_TYPE_3
#define BAT_LEVEL_LED_ICON_IND
#define LOW_VOLT_SPARK_BAT_ICON
#define LOW_BAT_POWER_OFF_MODE

#define DISP_OFF_STR_AT_PWR_DOWN
#define DISP_HIFI_STR_AT_POWER_ON
#endif

#ifdef K0000_MC_H2_V001

#define LED_USE_PLAY_MODE
//#define LED_GPIO_PORT_CUSTOMERIZED

#define IMPROVED_BAT_MEASURE
#ifdef IIC_GPIO_USE_P02_P03
#undef IIC_GPIO_USE_P02_P03
#endif

#define FM_MINI_FRE_875
#define IIC_GPIO_USE_P00_P01
#ifdef MUTE_PORT_USE_P01
#undef  MUTE_PORT_USE_P01
#endif
 #define MUTE_PORT_USE_P03

#define DISP_PC_STR


#define EXCHANGE_LINE_IN_CHANNEL	//交换LINE IN 通道

#define VOLUME_DEFUALT	30

#define CUSTOMER_DEFINED_ADKEY_RESISTOR
#define ADKEY_NEW_METHOD
//#define TWO_ADKEY_ENABLE
//#define TWO_ADKEY_USE_PORT_P02
#define EXTENDED_ADKEY_NUM

#define USE_GPIO_DETECT_EARPHONE_PLUGGED
#define EARPHONE_DETECT_USE_P07
#define INDEPENDENT_VOLUME_KEY
//#define PLAY_MODE_USE_REP_ONE_ALL
//#define USE_LONG_PLAY_KEY_PLAY_MODE

//#define NOT_MOUNT_FM_DEV
#define RADIO_MODE_HOT_KEY_ENABLE
#define SEMI_AUTO_SCAN_FREQ
#define ADKEY_NEXT_PREV_HOLD_AUTO_SCAN
#define FM_PLAY_KEY_PAUSE
#define DISP_FM_PAUS_STRING

#define TURN_ON_PLAY_BREAK_POINT_MEM

#define DISP_PAUS_STRING
#define DEFAULT_GO_TO_IDLE

#define USE_LINE_IN_DETECT_FUNC
#define AUX_DETECT_USE_P17

#define USE_BAT_MANAGEMENT
#define CHARGER_DETECT_INDICATOR
#define CHARGER_DET_USE_P04
#define CHARGER_FLASH_TYPE_3
#define BAT_LEVEL_LED_ICON_IND
#define LOW_VOLT_SPARK_BAT_ICON
#define LOW_BAT_POWER_OFF_MODE

#define DISP_OFF_STR_AT_PWR_DOWN
#define DISP_HIFI_STR_AT_POWER_ON
#endif

#ifdef K0000_MC_DYJ_V001

#define LED_USE_PLAY_MODE
#define LED_GPIO_PORT_CUSTOMERIZED

#define IMPROVED_BAT_MEASURE
#ifdef IIC_GPIO_USE_P02_P03
#undef IIC_GPIO_USE_P02_P03
#endif

#define FM_MINI_FRE_875
#define IIC_GPIO_USE_P00_P01
#ifdef MUTE_PORT_USE_P01
#undef  MUTE_PORT_USE_P01
#endif
 #define MUTE_PORT_USE_P03

#define DISP_PC_STR
#define JOG_STICK_FUNC

#define EXCHANGE_LINE_IN_CHANNEL	//交换LINE IN 通道

#define VOLUME_DEFUALT	20

#define CUSTOMER_DEFINED_ADKEY_RESISTOR
#define ADKEY_NEW_METHOD
#define EXTENDED_ADKEY_NUM

#define USE_GPIO_DETECT_EARPHONE_PLUGGED
#define EARPHONE_DETECT_USE_P07
#define INDEPENDENT_VOLUME_KEY
#define PLAY_MODE_USE_REP_ONE_ALL
#define USE_LONG_PLAY_KEY_PLAY_MODE

#define FAST_BAND_SCAN_SPEED
#define RADIO_MODE_HOT_KEY_ENABLE
#define VOL_TUNE_FREQ_VOL
#define RADIO_MODE_HOT_KEY_ENABLE
#define SEMI_AUTO_SCAN_FREQ
#define ADKEY_NEXT_PREV_HOLD_AUTO_SCAN
#define FM_PLAY_KEY_PAUSE
#define DISP_FM_PAUS_STRING

#define TURN_ON_PLAY_BREAK_POINT_MEM

#define DISP_PAUS_STRING
#define DEFAULT_GO_TO_IDLE

#define NOT_USE_LINE_IN_FUNC
//#define INDEPENDENT_KEY_TUNE_FREQ

#define USE_BAT_MANAGEMENT
#define CHARGER_DETECT_INDICATOR
#define CHARGER_DET_USE_P04
#define CHARGER_FLASH_TYPE_3
#define BAT_LEVEL_LED_ICON_IND
#define LOW_VOLT_SPARK_BAT_ICON
#define LOW_BAT_POWER_OFF_MODE

#define DISP_OFF_STR_AT_PWR_DOWN
#define DISP_HIFI_STR_AT_POWER_ON
#endif

#ifdef K0000_MC_M73A_V001

#define LED_USE_PLAY_MODE
#define LED_GPIO_PORT_CUSTOMERIZED

#define IMPROVED_BAT_MEASURE
#ifdef IIC_GPIO_USE_P02_P03
#undef IIC_GPIO_USE_P02_P03
#endif

#define FM_MINI_FRE_875
#define IIC_GPIO_USE_P00_P01
#ifdef MUTE_PORT_USE_P01
#undef  MUTE_PORT_USE_P01
#endif
 #define MUTE_PORT_USE_P03

#define DISP_PC_STR


#define EXCHANGE_LINE_IN_CHANNEL	//交换LINE IN 通道

#define VOLUME_DEFUALT	30

#define CUSTOMER_DEFINED_ADKEY_RESISTOR
#define ADKEY_NEW_METHOD
#define TWO_ADKEY_ENABLE
#define TWO_ADKEY_USE_PORT_P02
#define EXTENDED_ADKEY_NUM

#define USE_GPIO_DETECT_EARPHONE_PLUGGED
#define EARPHONE_DETECT_USE_P07
#define INDEPENDENT_VOLUME_KEY
//#define PLAY_MODE_USE_REP_ONE_ALL
//#define USE_LONG_PLAY_KEY_PLAY_MODE

//#define NOT_MOUNT_FM_DEV
#define RADIO_MODE_HOT_KEY_ENABLE
#define SEMI_AUTO_SCAN_FREQ
#define ADKEY_NEXT_PREV_HOLD_AUTO_SCAN
#define FM_PLAY_KEY_PAUSE
#define DISP_FM_PAUS_STRING

#define TURN_ON_PLAY_BREAK_POINT_MEM

#define DISP_PAUS_STRING
#define DEFAULT_GO_TO_IDLE

#define USE_LINE_IN_DETECT_FUNC
#define AUX_DETECT_USE_P17

#define USE_BAT_MANAGEMENT
#define CHARGER_DETECT_INDICATOR
#define CHARGER_DET_USE_P04
#define CHARGER_FLASH_TYPE_3
#define BAT_LEVEL_LED_ICON_IND
#define LOW_VOLT_SPARK_BAT_ICON
#define LOW_BAT_POWER_OFF_MODE

#define DISP_OFF_STR_AT_PWR_DOWN
#define DISP_HIFI_STR_AT_POWER_ON
#endif

#ifdef K0000_MC_Q18A_V002

#define USE_USB_HOTPLUG_FUNC

#define LED_USE_PLAY_MODE
#define IMPROVED_BAT_MEASURE

#ifdef IIC_GPIO_USE_P02_P03
#undef IIC_GPIO_USE_P02_P03
#endif
#define IIC_GPIO_USE_P00_P01
#ifdef MUTE_PORT_USE_P01
#undef  MUTE_PORT_USE_P01
#endif
 #define MUTE_PORT_USE_P03

#define DISP_PC_STR


#define EXCHANGE_LINE_IN_CHANNEL	//交换LINE IN 通道

#define VOLUME_DEFUALT	30

#if 1
#define LED_GPIO_PORT_CUSTOMERIZED
#define COMMON_CATHODE
#define CUSTOMER_DEFINED_ADKEY_RESISTOR
#define ADKEY_NEW_METHOD
#define TWO_ADKEY_ENABLE
#define TWO_ADKEY_USE_PORT_P07
#define EXTENDED_ADKEY_NUM

#define USE_GPIO_DETECT_EARPHONE_PLUGGED
#define EARPHONE_DETECT_USE_P04
#define INDEPENDENT_VOLUME_KEY
#define PLAY_MODE_USE_REP_ONE_ALL
#define USE_LONG_PLAY_KEY_PLAY_MODE
#endif
#define NOT_MOUNT_FM_DEV
#define RADIO_MODE_HOT_KEY_ENABLE
#define SEMI_AUTO_SCAN_FREQ
#define ADKEY_NEXT_PREV_HOLD_AUTO_SCAN
#define FM_PLAY_KEY_PAUSE
#define DISP_FM_PAUS_STRING

#define TURN_ON_PLAY_BREAK_POINT_MEM

#define DISP_PAUS_STRING
#define NOT_USE_LINE_IN_FUNC
#define DEFAULT_GO_TO_IDLE


#define USE_BAT_MANAGEMENT
#define CHARGER_DETECT_INDICATOR
#define CHARGER_DET_USE_P02
#define CHARGER_FLASH_TYPE_3
#define BAT_LEVEL_LED_ICON_IND
#define LOW_VOLT_SPARK_BAT_ICON
#define LOW_BAT_POWER_OFF_MODE

#define DISP_OFF_STR_AT_PWR_DOWN
#define DISP_HIFI_STR_AT_POWER_ON
#endif


#ifdef K0000_MC_AP16_V001

//#define NO_LED_DISPLAY
#define PLAY_STATUS_LED_P04
//#define LED_USE_PLAY_MODE
#define IMPROVED_BAT_MEASURE

#ifdef IIC_GPIO_USE_P02_P03
#undef IIC_GPIO_USE_P02_P03
#endif
#define IIC_GPIO_USE_P00_P01
#ifdef MUTE_PORT_USE_P01
#undef  MUTE_PORT_USE_P01
#endif
 #define MUTE_PORT_USE_P03

#define MEI_CHENG_BAT_PARA

#define EXCHANGE_LINE_IN_CHANNEL	//交换LINE IN 通道

#define VOLUME_DEFUALT	20

//#define ADKEY_NEW_METHOD

#if 1
#define USE_POWER_KEY
#define USE_ONLY_POWER_HOLD_CTRL
#define PWR_CTRL_P02
#define USE_PWR_KEY_LONG_PWR_ON
#endif

#define CUSTOMER_DEFINED_ADKEY_RESISTOR

#define POWE_KEY_PLAY_KEY_IN_ONE_KEY
#define USE_POWER_KEY_SHORT_SCAN

#define TURN_ON_PLAY_BREAK_POINT_MEM

#define USE_BAT_MANAGEMENT

#define LOW_BAT_POWER_OFF_MODE

#define USE_LINE_IN_DETECT_FUNC
#define AUX_DETECT_USE_P34
#endif

#ifdef K0000_MC_TK19_V001

#define LED_USE_PLAY_MODE
#define IMPROVED_BAT_MEASURE

#ifdef IIC_GPIO_USE_P02_P03
#undef IIC_GPIO_USE_P02_P03
#endif
#define IIC_GPIO_USE_P00_P01
#ifdef MUTE_PORT_USE_P01
#undef  MUTE_PORT_USE_P01
#endif
 #define MUTE_PORT_USE_P03
#define LED_GPIO_PORT_CUSTOMERIZED
#define COMMON_CATHODE
#define DISP_PC_STR

#define MEI_CHENG_BAT_PARA

#define EXCHANGE_LINE_IN_CHANNEL	//交换LINE IN 通道

#define VOLUME_DEFUALT	30

#if 1
#define USE_POWER_KEY
#define USE_ONLY_POWER_HOLD_CTRL
#define PWR_CTRL_P02
#define USE_PWR_KEY_LONG_PWR_ON
#endif


//#define ENABLE_MODE_KEY_AT_USB_AUDIO
#define CUSTOMER_DEFINED_ADKEY_RESISTOR
#define ADKEY_NEW_METHOD
#define EXTENDED_ADKEY_NUM

#define USE_GPIO_DETECT_EARPHONE_PLUGGED
#define EARPHONE_DETECT_USE_P07
#define INDEPENDENT_VOLUME_KEY
#define PLAY_MODE_USE_REP_ONE_ALL
#define USE_LONG_PLAY_KEY_PLAY_MODE

//#define NOT_MOUNT_FM_DEV
//#define RADIO_MODE_HOT_KEY_ENABLE
#define SEMI_AUTO_SCAN_FREQ
#define ADKEY_NEXT_PREV_HOLD_AUTO_SCAN
#define FM_PLAY_KEY_PAUSE
#define DISP_FM_PAUS_STRING

#define TURN_ON_PLAY_BREAK_POINT_MEM

#define DISP_PAUS_STRING
#define NOT_USE_LINE_IN_FUNC
#define DEFAULT_GO_TO_IDLE

#define USE_BAT_MANAGEMENT
#define CHARGER_DETECT_INDICATOR
#define CHARGER_DET_USE_P04
#define CHARGER_FLASH_TYPE_3
#define BAT_LEVEL_LED_ICON_IND
#define LOW_VOLT_SPARK_BAT_ICON
#define LOW_BAT_POWER_OFF_MODE

#define DISP_OFF_STR_AT_PWR_DOWN
#define DISP_HIFI_STR_AT_POWER_ON

#define USE_AMP_MODE_SELECT
#define AMP_MODE_SELECT_PORT_USE_P17
#endif


#ifdef K0000_MC_Q21_V001

#define LED_USE_PLAY_MODE
#define IMPROVED_BAT_MEASURE

#ifdef IIC_GPIO_USE_P02_P03
#undef IIC_GPIO_USE_P02_P03
#endif
#define IIC_GPIO_USE_P00_P01
#ifdef MUTE_PORT_USE_P01
#undef  MUTE_PORT_USE_P01
#endif
 #define MUTE_PORT_USE_P03
#define LED_GPIO_PORT_CUSTOMERIZED
#define COMMON_CATHODE
#define DISP_PC_STR

#define MEI_CHENG_BAT_PARA

#define EXCHANGE_LINE_IN_CHANNEL	//交换LINE IN 通道

#define VOLUME_DEFUALT	30

//#define ENABLE_MODE_KEY_AT_USB_AUDIO
#define CUSTOMER_DEFINED_ADKEY_RESISTOR
#define ADKEY_NEW_METHOD
#define TWO_ADKEY_ENABLE
#define TWO_ADKEY_USE_PORT_P07
#define EXTENDED_ADKEY_NUM

#define USE_GPIO_DETECT_EARPHONE_PLUGGED
#define EARPHONE_DETECT_USE_P04
#define INDEPENDENT_VOLUME_KEY
#define PLAY_MODE_USE_REP_ONE_ALL
#define USE_LONG_PLAY_KEY_PLAY_MODE

//#define NOT_MOUNT_FM_DEV
//#define RADIO_MODE_HOT_KEY_ENABLE
#define SEMI_AUTO_SCAN_FREQ
#define ADKEY_NEXT_PREV_HOLD_AUTO_SCAN
#define FM_PLAY_KEY_PAUSE
#define DISP_FM_PAUS_STRING

#define TURN_ON_PLAY_BREAK_POINT_MEM

#define DISP_PAUS_STRING
#define NOT_USE_LINE_IN_FUNC
#define DEFAULT_GO_TO_IDLE

#define USE_BAT_MANAGEMENT
#define CHARGER_DETECT_INDICATOR
#define CHARGER_DET_USE_P02
#define CHARGER_FLASH_TYPE_3
#define BAT_LEVEL_LED_ICON_IND
#define LOW_VOLT_SPARK_BAT_ICON
#define LOW_BAT_POWER_OFF_MODE

#define DISP_OFF_STR_AT_PWR_DOWN
#define DISP_HIFI_STR_AT_POWER_ON
#endif

#ifdef K0000_MC_Q18A_V001

#define LED_USE_PLAY_MODE
#define IMPROVED_BAT_MEASURE

#ifdef IIC_GPIO_USE_P02_P03
#undef IIC_GPIO_USE_P02_P03
#endif
#define IIC_GPIO_USE_P00_P01
#ifdef MUTE_PORT_USE_P01
#undef  MUTE_PORT_USE_P01
#endif
 #define MUTE_PORT_USE_P03
#define LED_GPIO_PORT_CUSTOMERIZED
#define COMMON_CATHODE
#define DISP_PC_STR


#define EXCHANGE_LINE_IN_CHANNEL	//交换LINE IN 通道

#define VOLUME_DEFUALT	30

#define CUSTOMER_DEFINED_ADKEY_RESISTOR
#define ADKEY_NEW_METHOD
#define TWO_ADKEY_ENABLE
#define TWO_ADKEY_USE_PORT_P07
#define EXTENDED_ADKEY_NUM

#define USE_GPIO_DETECT_EARPHONE_PLUGGED
#define EARPHONE_DETECT_USE_P04
#define INDEPENDENT_VOLUME_KEY
#define PLAY_MODE_USE_REP_ONE_ALL
#define USE_LONG_PLAY_KEY_PLAY_MODE

#define NOT_MOUNT_FM_DEV
#define RADIO_MODE_HOT_KEY_ENABLE
#define SEMI_AUTO_SCAN_FREQ
#define ADKEY_NEXT_PREV_HOLD_AUTO_SCAN
#define FM_PLAY_KEY_PAUSE
#define DISP_FM_PAUS_STRING

#define TURN_ON_PLAY_BREAK_POINT_MEM

#define DISP_PAUS_STRING
#define NOT_USE_LINE_IN_FUNC
#define DEFAULT_GO_TO_IDLE

#define USE_BAT_MANAGEMENT
#define CHARGER_DETECT_INDICATOR
#define CHARGER_DET_USE_P02
#define CHARGER_FLASH_TYPE_3
#define BAT_LEVEL_LED_ICON_IND
#define LOW_VOLT_SPARK_BAT_ICON
#define LOW_BAT_POWER_OFF_MODE

#define DISP_OFF_STR_AT_PWR_DOWN
#define DISP_HIFI_STR_AT_POWER_ON
#endif

#ifdef K0000_MC_Q16A_V001

#define LED_USE_PLAY_MODE

#ifdef IIC_GPIO_USE_P02_P03
#undef IIC_GPIO_USE_P02_P03
#endif
#define IIC_GPIO_USE_P00_P01
#ifdef MUTE_PORT_USE_P01
#undef  MUTE_PORT_USE_P01
#endif
 #define MUTE_PORT_USE_P03
#define LED_GPIO_PORT_CUSTOMERIZED
#define COMMON_CATHODE
#define DISP_PC_STR

#define EXCHANGE_LINE_IN_CHANNEL	//交换LINE IN 通道

#define VOLUME_DEFUALT	30
//#define ENABLE_MODE_KEY_AT_USB_AUDIO
#define CUSTOMER_DEFINED_ADKEY_RESISTOR

#define USE_GPIO_DETECT_EARPHONE_PLUGGED
#define EARPHONE_DETECT_USE_P07
#define INDEPENDENT_VOLUME_KEY
#define PLAY_MODE_USE_REP_ONE_ALL
#define USE_LONG_PLAY_KEY_PLAY_MODE

#define NOT_MOUNT_FM_DEV
#define RADIO_MODE_HOT_KEY_ENABLE
#define SEMI_AUTO_SCAN_FREQ
#define ADKEY_NEXT_PREV_HOLD_AUTO_SCAN
#define FM_PLAY_KEY_PAUSE
#define DISP_FM_PAUS_STRING

#define TURN_ON_PLAY_BREAK_POINT_MEM

#define DISP_PAUS_STRING
#define NOT_USE_LINE_IN_FUNC
#define DEFAULT_GO_TO_IDLE

#define IMPROVED_BAT_MEASURE

#define USE_BAT_MANAGEMENT
#define CHARGER_DETECT_INDICATOR
#define CHARGER_DET_USE_P04
#define CHARGER_FLASH_TYPE_3
#define BAT_LEVEL_LED_ICON_IND
#define LOW_VOLT_SPARK_BAT_ICON
#define LOW_BAT_POWER_OFF_MODE

#define DISP_OFF_STR_AT_PWR_DOWN
#define DISP_HIFI_STR_AT_POWER_ON
#endif


#ifdef K1100_JY_1100_V001

#ifdef IIC_GPIO_USE_P02_P03
#undef IIC_GPIO_USE_P02_P03
#endif
#define IIC_GPIO_USE_P00_P01
#ifdef MUTE_PORT_USE_P01
#undef  MUTE_PORT_USE_P01
#endif
 #define MUTE_PORT_USE_P03

#define EXCHANGE_LINE_IN_CHANNEL	//交换LINE IN 通道

#if 1
#define USE_POWER_KEY
#define USE_ONLY_POWER_HOLD_CTRL
#define PWR_CTRL_P17
#define USE_PWR_KEY_LONG_PWR_ON
#endif

#define USE_POWER_KEY_SHORT_SCAN
#define POWE_KEY_PLAY_KEY_IN_ONE_KEY

#define CUSTOMER_DEFINED_ADKEY_RESISTOR

#define USE_GPIO_DETECT_EARPHONE_PLUGGED
#define EARPHONE_DETECT_USE_P04

#endif

#ifdef K0000_XFW_FW_29_V001

#ifdef IIC_GPIO_USE_P02_P03
#undef IIC_GPIO_USE_P02_P03
#endif
#define IIC_GPIO_USE_P00_P01
#ifdef MUTE_PORT_USE_P01
#undef  MUTE_PORT_USE_P01
#endif
#define MUTE_PORT_USE_P03

#define EXCHANGE_LINE_IN_CHANNEL	//交换LINE IN 通道

#if 1
#define USE_POWER_KEY
#define USE_ONLY_POWER_HOLD_CTRL
#define PWR_CTRL_P02
#define USE_PWR_KEY_LONG_PWR_ON
#endif

#define CUSTOMER_DEFINED_ADKEY_RESISTOR

#define USE_GPIO_DETECT_EARPHONE_PLUGGED

#define USE_LINE_IN_DETECT_FUNC
#define AUX_DETECT_USE_P17
#endif

#ifdef K2045_AJR_2045_V001

#ifdef LED_GPIO_DRV
#undef  LED_GPIO_DRV
#endif
#define LCD_GPIO_DRV
#define LCD_SEGMENT_USE_10_SEGS_4_COMS


#ifdef IIC_GPIO_USE_P02_P03
#undef IIC_GPIO_USE_P02_P03
#endif
#define IIC_GPIO_USE_P00_P01
#ifdef MUTE_PORT_USE_P01
#undef  MUTE_PORT_USE_P01
#endif
#define MUTE_PORT_USE_P03

#define CUSTOMER_DEFINED_ADKEY_RESISTOR
//#define 

#define EXCHANGE_LINE_IN_CHANNEL	//交换LINE IN 通道

#define ADKEY_PLAY_SHORT_SCAN_FRE
#define USE_GPIO_DETECT_EARPHONE_PLUGGED

#define WKUP_PIN_USE_ENABLE

#define RTC_MODE_HOT_KEY_ENABLE
#define USE_RTC_FUNCTION
#define USE_RTC_TIME_ONLY
#endif


#ifdef K2044_ZX_2044_V001

#ifdef IIC_GPIO_USE_P02_P03
#undef IIC_GPIO_USE_P02_P03
#endif
#define IIC_GPIO_USE_P00_P01
#ifdef MUTE_PORT_USE_P01
#undef  MUTE_PORT_USE_P01
#endif
#define MUTE_PORT_USE_P03

#define DEFAULT_GO_TO_IDLE

#define SPECTRUM_FUNC_ENABLE
#define EXTENDED_LED_SPECTURM
#define LED_ROLLING_FUNC
#define LED_ROLLING_TYPE_1
#define DISP_PAUS_STRING

#define EXCHANGE_LINE_IN_CHANNEL	//交换LINE IN 通道
#define NO_VOLUME_LIMITE

#undef LED_CTRL_LEVEL_NORMAL

#define ADKEY_PLAY_SHORT_SCAN_FRE
#define REVERSE_LED_FLASH_DIR

#define USE_LINE_IN_DETECT_FUNC
#define AUX_DETECT_USE_P17
#endif

#ifdef K2044_JM_850_V001

#ifdef IIC_GPIO_USE_P02_P03
#undef IIC_GPIO_USE_P02_P03
#endif
#define IIC_GPIO_USE_P00_P01
#ifdef MUTE_PORT_USE_P01
#undef  MUTE_PORT_USE_P01
#endif
#define MUTE_PORT_USE_P03

#define DEFAULT_GO_TO_IDLE

#define SPECTRUM_FUNC_ENABLE
#define EXTENDED_LED_SPECTURM
#define LED_ROLLING_FUNC
#define LED_ROLLING_TYPE_1
#define DISP_PAUS_STRING

#define EXCHANGE_LINE_IN_CHANNEL	//交换LINE IN 通道

#undef LED_CTRL_LEVEL_NORMAL

//#define ADKEY_PLAY_SHORT_SCAN_FRE
#define REVERSE_LED_FLASH_DIR
#define LINE_IN_PLAY_KEY_PAUSE
#define LINE_IN_NO_DISP_PAUS
#define FAST_BAND_SCAN_SPEED

#define USE_LINE_IN_DETECT_FUNC
#define AUX_DETECT_USE_P17
#endif

#ifdef K2044_YJH_2044_V001

#ifdef IIC_GPIO_USE_P02_P03
#undef IIC_GPIO_USE_P02_P03
#endif
#define IIC_GPIO_USE_P00_P01
#ifdef MUTE_PORT_USE_P01
#undef  MUTE_PORT_USE_P01
#endif
#define MUTE_PORT_USE_P03

#define DEFAULT_GO_TO_IDLE

#define SPECTRUM_FUNC_ENABLE
#define EXTENDED_LED_SPECTURM
#define LED_ROLLING_FUNC
#define LED_ROLLING_TYPE_1
#define DISP_PAUS_STRING

#define EXCHANGE_LINE_IN_CHANNEL	//交换LINE IN 通道

#undef LED_CTRL_LEVEL_NORMAL

#define ADKEY_PLAY_SHORT_SCAN_FRE
#define REVERSE_LED_FLASH_DIR

#define USE_LINE_IN_DETECT_FUNC
#define AUX_DETECT_USE_P17
#endif


#ifdef K1097_WK_1097_V001

#ifdef IIC_GPIO_USE_P02_P03
#undef IIC_GPIO_USE_P02_P03
#endif
#define IIC_GPIO_USE_P00_P01
#ifdef MUTE_PORT_USE_P01
#undef  MUTE_PORT_USE_P01
#endif
#define MUTE_PORT_USE_P03

#define EXCHANGE_LINE_IN_CHANNEL	//交换LINE IN 通道

#define NO_PLAY_STATUS_LED
#define SUPERIOR_CUSTOMER
#if 0
#define USE_POWER_KEY
#define USE_ONLY_POWER_HOLD_CTRL
#define PWR_CTRL_P17
#define USE_PWR_KEY_LONG_PWR_ON
#endif

#define CUSTOMER_DEFINED_ADKEY_RESISTOR

#define TWO_ADKEY_ENABLE
#define TWO_ADKEY_USE_PORT_P07
#define INDEPENDENT_VOLUME_KEY


//#define ADKEY_NEXT_PREV_HOLD_AUTO_SCAN
#define USE_GPIO_DETECT_EARPHONE_PLUGGED
#define EARPHONE_DETECT_USE_P04

#define USE_LINE_IN_DETECT_FUNC
#define AUX_DETECT_USE_P02
#endif


#ifdef K1091_XFW_1091_V001

#ifdef IIC_GPIO_USE_P02_P03
#undef IIC_GPIO_USE_P02_P03
#endif
#define IIC_GPIO_USE_P00_P01
#ifdef MUTE_PORT_USE_P01
#undef  MUTE_PORT_USE_P01
#endif
#define MUTE_PORT_USE_P03

#define EXCHANGE_LINE_IN_CHANNEL	//交换LINE IN 通道

#define NO_PLAY_STATUS_LED

#if 1
#define USE_POWER_KEY
#define USE_ONLY_POWER_HOLD_CTRL
#define PWR_CTRL_P17
#define USE_PWR_KEY_LONG_PWR_ON
#endif

#define CUSTOMER_DEFINED_ADKEY_RESISTOR

#define TWO_ADKEY_ENABLE
#define TWO_ADKEY_USE_PORT_P07
//#define ADKEY_NEW_METHOD
//#define EXTENDED_ADKEY_NUM

#define USE_POWER_KEY_TO_SWITCH_MODE

//#define ADKEY_NEXT_PREV_HOLD_AUTO_SCAN
#define USE_GPIO_DETECT_EARPHONE_PLUGGED
#define EARPHONE_DETECT_USE_P04

//#define USE_LINE_IN_DETECT_FUNC
//#define AUX_DETECT_USE_P04
#endif

#ifdef K000_JR_210_V001

#ifdef IIC_GPIO_USE_P02_P03
#undef IIC_GPIO_USE_P02_P03
#endif
#define IIC_GPIO_USE_P00_P01
#ifdef MUTE_PORT_USE_P01
#undef  MUTE_PORT_USE_P01
#endif
#define MUTE_PORT_USE_P03

#define LED_USE_COMMON_4X8

#define LED_GPIO_PORT_CUSTOMERIZED

#define DISABLE_P05_OSC_OUTPUT
#define CUSTOM_MAIN_DISP_VOL

#define CUSTOMER_DEFINED_ADKEY_RESISTOR

#define JOG_STICK_FUNC
#define SUPPORT_PT2313
#define FAST_DEV_INIT
#define FM_PATH_SHARE_SAME_MP3_PT_CHAN
#define FILE_SELECT_NOISE_IMPROVEMENT

#define MUTE_ON_FLASH_WHOLE_SCREEN

#define DISP_PAU_STRING
#define DISP_AUX_STRING
#define DISP_DEV_AT_PLAY
#define VOLUME_CUSTOMER_DEFINE_32
#define VOLUME_DEFUALT	16

#define IR_PLAY_KEY_SCAN_FREQ_DISABLE
#define IR_NEXT_PREV_DO_NOTHING

#define FM_MAX_CHANNAL_50
#define DEFAULT_GO_TO_AUX
#define MULTI_MEDIA_BOX

#define USE_LONG_MODE_FOR_POWER_KEY
#define EQ_DOWN_SCAN_ALL
#define USE_TWO_IR_REMOTE
#define NO_PT_STR_DISPLAY
#define SYS_DEFAULT_IN_IDLE_POWER_DOWN_MODE
#define INDEPENDENT_KEY_TUNE_FREQ
#define SEMI_AUTO_SCAN_FREQ

#define DISP_VOL_V_CHAR
#define IR_USER_CODE_0xFE01
#define QN_SHARE_MCU_CRYSTAL
#define DISABLE_QN_SCAN_ST
#endif

#ifdef K2041_XFW_2041_V002

#ifdef IIC_GPIO_USE_P02_P03
#undef IIC_GPIO_USE_P02_P03
#endif
#define IIC_GPIO_USE_P00_P01
#ifdef MUTE_PORT_USE_P01
#undef  MUTE_PORT_USE_P01
#endif
#define MUTE_PORT_USE_P03

#define EXCHANGE_LINE_IN_CHANNEL	//交换LINE IN 通道

#define LED_USE_ROUND_LED
#define LED_USE_PLAY_MODE
#define LED_USE_PLAY_MODE_NORMAL
#if 1
#define USE_POWER_KEY
#define USE_ONLY_POWER_HOLD_CTRL
#define PWR_CTRL_P02
#define USE_PWR_KEY_LONG_PWR_ON
#endif
#define CUSTOMER_DEFINED_ADKEY_RESISTOR

#define USE_BAT_MANAGEMENT
#define BAT_LEVEL_LED_ICON_IND
#define CHARGER_DETECT_INDICATOR
#define CHARGER_DET_USE_P04
#define CHARGER_FLASH_TYPE_2

#define POWE_KEY_PLAY_KEY_IN_ONE_KEY
#define USE_POWER_KEY_SHORT_SCAN

#define USE_GPIO_DETECT_EARPHONE_PLUGGED

#define USE_RTC_FUNCTION
#define USE_RTC_TIME_ONLY
//#define SYS_POWER_ON_DEFAULT_RTC_MODE
#define DEFAULT_GO_TO_TIME_MODE
#define USE_MODE_LONG_FOR_RTC_SETTING
//#define USE_LINE_IN_DETECT_FUNC
#define DISP_VOL_V_CHAR
#define LINE_IN_PLAY_KEY_PAUSE
#define USE_POWER_KEY_FOR_AUX_PLAY
//#define AUX_DETECT_USE_P04
#define LINE_IN_PLAY_KEY_NO_PAUSE_ICON_INDICATOR

#define OTP_DECODE_PLAY_CUSTOMED_VOL

#undef USE_RDAs_FM
#undef USE_QN8035_FM
#define OTP_MUSIC_FUNC_ENABLE
#define ENGINE_START_VOICE

#endif


#ifdef K2041_XFW_2041_V001

#ifdef IIC_GPIO_USE_P02_P03
#undef IIC_GPIO_USE_P02_P03
#endif
#define IIC_GPIO_USE_P00_P01
#ifdef MUTE_PORT_USE_P01
#undef  MUTE_PORT_USE_P01
#endif
#define MUTE_PORT_USE_P03

#define EXCHANGE_LINE_IN_CHANNEL	//交换LINE IN 通道

#define LED_USE_ROUND_LED
#define LED_USE_PLAY_MODE
#define BAT_LEVEL_LED_ICON_IND
#if 1
#define USE_POWER_KEY
#define USE_ONLY_POWER_HOLD_CTRL
#define PWR_CTRL_P02
#define USE_PWR_KEY_LONG_PWR_ON
#endif
#define CUSTOMER_DEFINED_ADKEY_RESISTOR

#define USE_BAT_MANAGEMENT
#define CHARGER_DETECT_INDICATOR
#define CHARGER_DET_USE_P17

#define POWE_KEY_PLAY_KEY_IN_ONE_KEY
#define USE_POWER_KEY_SHORT_SCAN

#define USE_GPIO_DETECT_EARPHONE_PLUGGED

#define USE_RTC_FUNCTION
#define USE_RTC_TIME_ONLY
//#define SYS_POWER_ON_DEFAULT_RTC_MODE
#define DEFAULT_GO_TO_TIME_MODE
#define USE_MODE_LONG_FOR_RTC_SETTING
#define USE_LINE_IN_DETECT_FUNC
#define DISP_VOL_V_CHAR
#define LINE_IN_PLAY_KEY_PAUSE
#define USE_POWER_KEY_FOR_AUX_PLAY
#define AUX_DETECT_USE_P04
#define LINE_IN_PLAY_KEY_NO_PAUSE_ICON_INDICATOR

#define EQ_MODE_DEFUALT_ROCK

#undef USE_RDAs_FM
#undef USE_QN8035_FM
#define OTP_MUSIC_FUNC_ENABLE
#define ENGINE_START_VOICE

#endif

#ifdef K1078_ZK_1078_V001

#ifdef IIC_GPIO_USE_P02_P03
#undef IIC_GPIO_USE_P02_P03
#endif
#define IIC_GPIO_USE_P00_P01
#ifdef MUTE_PORT_USE_P01
#undef  MUTE_PORT_USE_P01
#endif
#define MUTE_PORT_USE_P03


#define EXCHANGE_LINE_IN_CHANNEL	//交换LINE IN 通道

#define ADKEY_PLAY_SHORT_SCAN_FRE

#endif



#ifdef K2038_DCX_2038_V001

#ifdef IIC_GPIO_USE_P02_P03
#undef IIC_GPIO_USE_P02_P03
#endif
#define IIC_GPIO_USE_P00_P01
#ifdef MUTE_PORT_USE_P01
#undef  MUTE_PORT_USE_P01
#endif
#define MUTE_PORT_USE_P03

#ifdef LED_GPIO_DRV
#undef  LED_GPIO_DRV
#endif
#define LCD_GPIO_DRV

#define WKUP_PIN_USE_ENABLE
#define EXCHANGE_LINE_IN_CHANNEL	//交换LINE IN 通道

#define ADKEY_PLAY_SHORT_SCAN_FRE

#define USE_GPIO_DETECT_EARPHONE_PLUGGED

#endif


#ifdef K1069_AJE_1069_V002

#ifdef IIC_GPIO_USE_P02_P03
#undef IIC_GPIO_USE_P02_P03
#endif
#define IIC_GPIO_USE_P00_P01
#ifdef MUTE_PORT_USE_P01
#undef  MUTE_PORT_USE_P01
#endif
#define MUTE_PORT_USE_P03

#define EXCHANGE_LINE_IN_CHANNEL	//交换LINE IN 通道
#define RADIO_MODE_HOT_KEY_ENABLE
#define ADKEY_PLAY_SHORT_SCAN_FRE
#define PLAY_STATUS_LED_P02
#define PLAY_STATUS_LED_SHARE_WITH_DET
#define FAST_FORWARD_STEP_ONE_SEC
#define FF_FR_TURN_ON_MUSIC
#if 1
#define USE_POWER_KEY
#define USE_ONLY_POWER_HOLD_CTRL
#define PWR_CTRL_P17
#define USE_PWR_KEY_LONG_PWR_ON

#define CUSTOMER_DEFINED_ADKEY_RESISTOR
#define COMMON_CATHODE

#define TWO_ADKEY_ENABLE
#define TWO_ADKEY_USE_PORT_P07
#define ADKEY_NEW_METHOD
#define EXTENDED_ADKEY_NUM

#endif


#define SEMI_AUTO_SCAN_FREQ
#define ADKEY_NEXT_PREV_HOLD_AUTO_SCAN
#define USE_LONG_PLAY_KEY_PLAY_MODE
#define USE_POWER_KEY_TO_SWITCH_MODE

#define INDEPENDENT_KEY_TUNE_FREQ
#define INDEPENDENT_VOLUME_KEY

#define DISP_PAUS_STRING
#define DISP_VOL_V_CHAR


#define USE_GPIO_DETECT_EARPHONE_PLUGGED
#define EARPHONE_DETECT_USE_P02

#define USE_RTC_FUNCTION
#define USE_RTC_TIME_ONLY
#define RTC_MODE_HOT_KEY_ENABLE

#endif

#ifdef K1069_ZK_982_V001

#ifdef IIC_GPIO_USE_P02_P03
#undef IIC_GPIO_USE_P02_P03
#endif
#define IIC_GPIO_USE_P00_P01
#ifdef MUTE_PORT_USE_P01
#undef  MUTE_PORT_USE_P01
#endif
#define MUTE_PORT_USE_P03

#define EXCHANGE_LINE_IN_CHANNEL	//交换LINE IN 通道
#define RADIO_MODE_HOT_KEY_ENABLE
#define ADKEY_PLAY_SHORT_SCAN_FRE
#define PLAY_STATUS_LED_P02
#define PLAY_STATUS_LED_SHARE_WITH_DET


#if 1
#define USE_POWER_KEY
#define USE_ONLY_POWER_HOLD_CTRL
#define PWR_CTRL_P17
#define USE_PWR_KEY_LONG_PWR_ON

#define CUSTOMER_DEFINED_ADKEY_RESISTOR

#define TWO_ADKEY_ENABLE
#define TWO_ADKEY_USE_PORT_P07
#define ADKEY_NEW_METHOD
#define EXTENDED_ADKEY_NUM

#endif


#define SEMI_AUTO_SCAN_FREQ
#define ADKEY_NEXT_PREV_HOLD_AUTO_SCAN
#define USE_LONG_PLAY_KEY_PLAY_MODE
#define USE_POWER_KEY_TO_SWITCH_MODE

#define INDEPENDENT_KEY_TUNE_FREQ
#define INDEPENDENT_VOLUME_KEY

#define DISP_PAUS_STRING
#define DISP_VOL_V_CHAR


#define USE_GPIO_DETECT_EARPHONE_PLUGGED
#define EARPHONE_DETECT_USE_P02

#define USE_RTC_FUNCTION
#define USE_RTC_TIME_ONLY
#define RTC_MODE_HOT_KEY_ENABLE
#define USE_RTC_ALARM_FUNCTION
#define USE_RTC_ALM_CUSTOM_INIT
#endif


#ifdef K1069_AJE_1069_V001

#ifdef IIC_GPIO_USE_P02_P03
#undef IIC_GPIO_USE_P02_P03
#endif
#define IIC_GPIO_USE_P00_P01
#ifdef MUTE_PORT_USE_P01
#undef  MUTE_PORT_USE_P01
#endif
#define MUTE_PORT_USE_P03

#define EXCHANGE_LINE_IN_CHANNEL	//交换LINE IN 通道

#define ADKEY_PLAY_SHORT_SCAN_FRE

#define NO_PLAY_STATUS_LED
#if 1
#define USE_POWER_KEY
#define USE_ONLY_POWER_HOLD_CTRL
#define PWR_CTRL_P17
#define USE_PWR_KEY_LONG_PWR_ON
#endif

#define CUSTOMER_DEFINED_ADKEY_RESISTOR

#define TWO_ADKEY_ENABLE
#define TWO_ADKEY_USE_PORT_P07
#define ADKEY_NEW_METHOD
#define EXTENDED_ADKEY_NUM


#define SEMI_AUTO_SCAN_FREQ
//#define USE_POWER_KEY_SHORT_SCAN
#define INDEPENDENT_KEY_TUNE_FREQ

//#define ADKEY_NEXT_PREV_HOLD_AUTO_SCAN

#define USE_RTC_FUNCTION
#define USE_RTC_TIME_ONLY
#endif


#ifdef K1055_HSL_1055_V001

#ifdef IIC_GPIO_USE_P02_P03
#undef IIC_GPIO_USE_P02_P03
#endif

#define IIC_GPIO_USE_P00_P01

#ifdef MUTE_PORT_USE_P01
#undef  MUTE_PORT_USE_P01
#endif

#define LED_USE_PLAY_MODE_MIXED
#define MUTE_PORT_USE_P03

#define VOLUME_DEFUALT	30

#define EXCHANGE_LINE_IN_CHANNEL	//交换LINE IN 通道

#define ADKEY_PLAY_SHORT_SCAN_FRE

#define DISABLE_QN_SCAN_ST
#endif

#ifdef K2035_SES_2035_V002

#define LED_USE_PLAY_MODE
#define LED_MODE_EXCHANGE_TF_AUX_ICON
#define USE_BAT_MANAGEMENT
#define CHARGER_DETECT_INDICATOR
#define CHARGER_DET_USE_P02
#define CHARGER_FLASH_TYPE_2
#define BAT_LEVEL_LED_ICON_IND
#define BAT_MEASURE_USE_P04_PORT

#ifdef IIC_GPIO_USE_P02_P03
#undef IIC_GPIO_USE_P02_P03
#endif
#define IIC_GPIO_USE_P00_P01
#ifdef MUTE_PORT_USE_P01
#undef  MUTE_PORT_USE_P01
#endif
#define MUTE_PORT_USE_P03

#define IR_PLAY_KEY_LONG_SCAN_FREQ
#define IR_PLAY_SHORT_CH_UP

#define CUSTOMER_DEFINED_ADKEY_RESISTOR
#define VOLUME_DEFUALT	30

#define EXCHANGE_LINE_IN_CHANNEL	//交换LINE IN 通道
#define NO_PLAY_STATUS_LED

#define DECODE_STOP_MODE_ENABLE
#define STOP_MODE_SHOW_STOP
#define NEW_SD_DETECT_MOD

#define FM_USE_AR1015
#define PLAY_MODE_USE_REP_ONE_ALL
#define USE_LONG_EQ_KEY_PLAY_MODE

#define DEFAULT_GO_TO_IDLE

#define USE_MANUAL_IDLE_FUNC

#define ADKEY_NEXT_ADJST_FREQ
#define SEMI_AUTO_SCAN_FREQ
#define ADKEY_NEXT_PREV_HOLD_AUTO_SCAN

#define USE_AMP_MODE_SELECT
#define IDLE_MODE_NO_MUTE
#endif

#ifdef K2035_SES_2035_V001

#define LED_USE_PLAY_MODE
#define LED_MODE_EXCHANGE_TF_AUX_ICON

#define USE_BAT_MANAGEMENT
#define CHARGER_DETECT_INDICATOR
#define CHARGER_DET_USE_P02
#define CHARGER_FLASH_TYPE_2
#define BAT_LEVEL_LED_ICON_IND
#define BAT_MEASURE_USE_P04_PORT

#ifdef IIC_GPIO_USE_P02_P03
#undef IIC_GPIO_USE_P02_P03
#endif
#define IIC_GPIO_USE_P00_P01
#ifdef MUTE_PORT_USE_P01
#undef  MUTE_PORT_USE_P01
#endif
#define MUTE_PORT_USE_P03

#define VOLUME_DEFUALT	30

#define IR_PLAY_KEY_LONG_SCAN_FREQ
#define IR_PLAY_SHORT_CH_UP

#define EXCHANGE_LINE_IN_CHANNEL	//交换LINE IN 通道

#define ADKEY_PLAY_SHORT_SCAN_FRE


#define DECODE_STOP_MODE_ENABLE
#define STOP_MODE_SHOW_STOP

#define FM_USE_AR1015

#define USE_LONG_EQ_KEY_PLAY_MODE

#define DEFAULT_GO_TO_IDLE

#define USE_MANUAL_IDLE_FUNC

#define SEMI_AUTO_SCAN_FREQ
#define ADKEY_NEXT_ADJST_FREQ
#define ADKEY_NEXT_PREV_HOLD_CH_SEL

#define NO_PLAY_STATUS_LED

#define USE_AMP_MODE_SELECT
#define IDLE_MODE_NO_MUTE
#endif

#ifdef K1009_DCX_915_V001

#define LED_REVERSE_VIEW
#define LED_USE_PLAY_MODE_MIXED

#ifdef IIC_GPIO_USE_P02_P03
#undef IIC_GPIO_USE_P02_P03
#endif
#define IIC_GPIO_USE_P00_P01
#ifdef MUTE_PORT_USE_P01
#undef  MUTE_PORT_USE_P01
#endif
#define MUTE_PORT_USE_P03

#define SPECTRUM_FUNC_ENABLE
#define EXTENDED_LED_SPECTURM

#define EXCHANGE_LINE_IN_CHANNEL	//交换LINE IN 通道

#define ADKEY_PLAY_SHORT_SCAN_FRE


#endif

#ifdef K1058_ZX_1058_V001

#ifdef IIC_GPIO_USE_P02_P03
#undef IIC_GPIO_USE_P02_P03
#endif
#define IIC_GPIO_USE_P00_P01
#ifdef MUTE_PORT_USE_P01
#undef  MUTE_PORT_USE_P01
#endif
#define MUTE_PORT_USE_P03

#define EXCHANGE_LINE_IN_CHANNEL	//交换LINE IN 通道

//#define EQ_USE_DSP_FUNC
//#define EQ_MODE_DEFUALT_ROCK

#define VOLUME_DEFUALT	16
//#define NO_VOLUME_LIMITE

//#define USE_GPIO_DETECT_EARPHONE_PLUGGED
//#define EARPHONE_DETECT_USE_P04

#endif

#ifdef K1051_JIAMEI_1051C_V001

#ifdef IIC_GPIO_USE_P02_P03
#undef IIC_GPIO_USE_P02_P03
#endif
#define IIC_GPIO_USE_P00_P01
#ifdef MUTE_PORT_USE_P01
#undef  MUTE_PORT_USE_P01
#endif
#define MUTE_PORT_USE_P03

#define EXCHANGE_LINE_IN_CHANNEL	//交换LINE IN 通道

#define IR_PLAY_KEY_SCAN_FREQ_DISABLE

#define SEMI_AUTO_SCAN_FREQ
#define IR_NEXT_PREV_HOLD_AUTO_SCAN

#define USE_TWO_IR_REMOTE
#define EQ_DOWN_SCAN_ALL

#define USE_GPIO_DETECT_EARPHONE_PLUGGED
#define EARPHONE_DETECT_USE_P04

#endif

#ifdef K1051_JIAMEI_1051_V001

#ifdef IIC_GPIO_USE_P02_P03
#undef IIC_GPIO_USE_P02_P03
#endif
#define IIC_GPIO_USE_P00_P01
#ifdef MUTE_PORT_USE_P01
#undef  MUTE_PORT_USE_P01
#endif
#define MUTE_PORT_USE_P03

#define EXCHANGE_LINE_IN_CHANNEL	//交换LINE IN 通道

#define ADKEY_PLAY_SHORT_SCAN_FRE


#define USE_GPIO_DETECT_EARPHONE_PLUGGED
#define EARPHONE_DETECT_USE_P04

#define USE_RTC_FUNCTION

#define USE_RTC_TIME_ONLY
#define USE_RTC_ALARM_FUNCTION
#endif


#ifdef K1032_YHD_005_V001

#ifdef IIC_GPIO_USE_P02_P03
#undef IIC_GPIO_USE_P02_P03
#endif
#define IIC_GPIO_USE_P00_P01
#ifdef MUTE_PORT_USE_P01
#undef  MUTE_PORT_USE_P01
#endif
#define MUTE_PORT_USE_P03
#define EXCHANGE_LINE_IN_CHANNEL	//交换LINE IN 通道
#define DEFAULT_GO_TO_IDLE
#define NO_DEV_SHOW_HI_STR
#define DISP_PAUS_STRING
#define FM_MAX_CHANNAL_50
#define NO_VOLUME_LIMITE

#define VOLUME_DEFUALT		25


#if 1
#define LED_USE_ROUND_LED

#define USE_POWER_KEY
#define PWR_CTRL_P02
#define USE_ONLY_POWER_HOLD_CTRL
#define USE_PWR_KEY_LONG_PWR_ON
#define POWE_KEY_PLAY_KEY_IN_ONE_KEY
#define CUSTOMER_DEFINED_ADKEY_RESISTOR
#define USE_MODE_KEY_LONG_SCAN
//#define FM_PLAY_KEY_PAUSE
#define LINE_IN_PLAY_KEY_PAUSE
#define USE_POWER_KEY_FOR_AUX_PLAY
#endif

#define DISP_OFF_STR_AT_PWR_DOWN

#define USE_BAT_MANAGEMENT
#define BAT_LEVEL_LED_ICON_IND
#define NO_DEV_SHOW_HI_STR
#define DISP_VOL_V_CHAR
#define CHARGER_FLASH_TYPE_1
#define LOW_VOLT_SPARK_BAT_ICON
#define CHARGER_DETECT_INDICATOR
#define CHARGER_DET_USE_VPP

//#define USE_LINE_IN_DETECT_FUNC
//#define AUX_DETECT_USE_P04
#define DISABLE_QN_SCAN_ST
#define QN_SHARE_MCU_CRYSTAL

#if 1
#undef USE_RDAs_FM
#undef USE_BK1080_FM
#define OTP_MUSIC_FUNC_ENABLE
#define OTP_DECODE_PLAY_FOLLOW_SYS_VOL
#define Lamborghini_voice
#endif

#endif

#ifdef K1032_AP_1032_V001

#ifdef IIC_GPIO_USE_P02_P03
#undef IIC_GPIO_USE_P02_P03
#endif
#define IIC_GPIO_USE_P00_P01
#ifdef MUTE_PORT_USE_P01
#undef  MUTE_PORT_USE_P01
#endif
#define MUTE_PORT_USE_P03
#define EXCHANGE_LINE_IN_CHANNEL	//交换LINE IN 通道
//#define DEFAULT_GO_TO_TIME_MODE
#define DISP_HIFI_STR_AT_POWER_ON
#define NO_DEV_SHOW_HI_STR
#define DISP_PAUS_STRING
#define FM_MAX_CHANNAL_50
#define NO_VOLUME_LIMITE

//#define AUX_ICON_FOR_RTC_ALM

#define DISP_FILE_NUM_NEW_TYPE

#if 1
#define LED_USE_ROUND_LED
#define LED_USE_PLAY_MODE
#define LED_USE_PLAY_MODE_NORMAL

#define USE_POWER_KEY
#define PWR_CTRL_P02
#define USE_ONLY_POWER_HOLD_CTRL
#define USE_PWR_KEY_LONG_PWR_ON
#define POWE_KEY_PLAY_KEY_IN_ONE_KEY
#define CUSTOMER_DEFINED_ADKEY_RESISTOR
#define USE_MODE_KEY_LONG_SCAN
#define FM_PLAY_KEY_PAUSE
#define LINE_IN_PLAY_KEY_PAUSE
#endif

#define DISP_OFF_STR_AT_PWR_DOWN

#define USE_BAT_MANAGEMENT
#define BAT_LEVEL_LED_ICON_IND
//#define NO_DEV_SHOW_HIFI_STR
#define DISP_VOL_V_CHAR
#define LOW_VOLT_SPARK_BAT_ICON
#define CHARGER_DETECT_INDICATOR
#define CHARGER_DET_USE_P04
#define CHARGER_FLASH_TYPE_2

//#define USE_LINE_IN_DETECT_FUNC
//#define AUX_DETECT_USE_P04
#define DISABLE_QN_SCAN_ST
#define QN_SHARE_MCU_CRYSTAL


#undef USE_RDAs_FM
#undef USE_BK1080_FM
#define OTP_MUSIC_FUNC_ENABLE
#define Lamborghini_voice
#if 0

#define SYS_POWER_ON_DEFAULT_RTC_MODE 
#define USE_RTC_FUNCTION
#define USE_RTC_TIME_ONLY
//#define ALARM_SEL_SOURCE
#define USE_MODE_LONG_FOR_RTC_SETTING
#define USE_POWER_KEY_TO_ADJ_HOUR_AND_MIN
#define USE_RTC_ALARM_FUNCTION
#endif
#endif

#ifdef K1032_ZHONGKAI_1032_V001

#ifdef IIC_GPIO_USE_P02_P03
#undef IIC_GPIO_USE_P02_P03
#endif
#define IIC_GPIO_USE_P00_P01
#ifdef MUTE_PORT_USE_P01
#undef  MUTE_PORT_USE_P01
#endif
#define MUTE_PORT_USE_P03
#define EXCHANGE_LINE_IN_CHANNEL	//交换LINE IN 通道
#define DEFAULT_GO_TO_IDLE
#define NO_DEV_SHOW_HI_STR
#define DISP_PAU_STRING
#define FM_MAX_CHANNAL_50
#define NO_VOLUME_LIMITE


#if 1
#define LED_USE_ROUND_LED

#define USE_POWER_KEY
#define PWR_CTRL_P02
#define USE_ONLY_POWER_HOLD_CTRL
#define USE_PWR_KEY_LONG_PWR_ON
#define POWE_KEY_PLAY_KEY_IN_ONE_KEY
#define CUSTOMER_DEFINED_ADKEY_RESISTOR
#define USE_MODE_KEY_LONG_SCAN
#define FM_PLAY_KEY_PAUSE
#define LINE_IN_PLAY_KEY_PAUSE
#endif

#define DISP_OFF_STR_AT_PWR_DOWN

#define USE_BAT_MANAGEMENT
#define BAT_LEVEL_LED_ICON_IND
#define NO_DEV_SHOW_HI_STR
#define DISP_VOL_V_CHAR
#define LOW_VOLT_SPARK_BAT_ICON

#define USE_LINE_IN_DETECT_FUNC
#define AUX_DETECT_USE_P04
#define DISABLE_QN_SCAN_ST
#define QN_SHARE_MCU_CRYSTAL

#endif

#ifdef K1032_WK_1032_V001
#define LED_USE_ROUND_LED

#ifdef IIC_GPIO_USE_P02_P03
#undef IIC_GPIO_USE_P02_P03
#endif
#define IIC_GPIO_USE_P00_P01
#ifdef MUTE_PORT_USE_P01
#undef  MUTE_PORT_USE_P01
#endif
#define MUTE_PORT_USE_P03
#define EXCHANGE_LINE_IN_CHANNEL	//交换LINE IN 通道
#define NO_DEV_SHOW_HI_STR
#define DEFAULT_GO_TO_IDLE

#define USE_POWER_KEY
#define PWR_CTRL_P02
#define USE_ONLY_POWER_HOLD_CTRL
#define USE_PWR_KEY_LONG_PWR_ON
#define POWE_KEY_PLAY_KEY_IN_ONE_KEY
#define CUSTOMER_DEFINED_ADKEY_RESISTOR

#define USE_MODE_KEY_LONG_SCAN
#define USE_LONG_MODE_KEY_PLAY_MODE
#define USE_BAT_MANAGEMENT
#define USE_PWR_KEY_FOR_SCAN_STOP

#define FM_PLAY_KEY_PAUSE
#define LINE_IN_PLAY_KEY_PAUSE
#define USE_POWER_KEY_FOR_AUX_PLAY
#define USE_POWER_KEY_FOR_FM_PLAY

#define USE_LINE_IN_DETECT_FUNC
#define AUX_DETECT_USE_P04
#define DISABLE_QN_SCAN_ST
#define QN_SHARE_MCU_CRYSTAL

#endif

#ifdef K1032_AJE_LS094_V001
#define LED_USE_ROUND_LED

#ifdef IIC_GPIO_USE_P02_P03
#undef IIC_GPIO_USE_P02_P03
#endif
#define IIC_GPIO_USE_P00_P01
#ifdef MUTE_PORT_USE_P01
#undef  MUTE_PORT_USE_P01
#endif
#define MUTE_PORT_USE_P03
#define EXCHANGE_LINE_IN_CHANNEL	//交换LINE IN 通道


#define USE_POWER_KEY
#define PWR_CTRL_P02
#define USE_ONLY_POWER_HOLD_CTRL
#define USE_PWR_KEY_LONG_PWR_ON
#define POWE_KEY_PLAY_KEY_IN_ONE_KEY
#define CUSTOMER_DEFINED_ADKEY_RESISTOR

#define USE_POWER_KEY_SHORT_SCAN

#define USE_BAT_MANAGEMENT
#define BAT_LEVEL_LED_ICON_IND
#define LOW_VOLT_SPARK_BAT_ICON
#define CHARGER_DETECT_INDICATOR
#define CHARGER_DET_USE_P17
#define CHARGER_FLASH_TYPE_2

#define USE_LINE_IN_DETECT_FUNC
#define AUX_DETECT_USE_P04
#define DISABLE_QN_SCAN_ST
#define QN_SHARE_MCU_CRYSTAL

#endif

#ifdef K1032_AJE_1032_V001
#define LED_USE_ROUND_LED

#ifdef IIC_GPIO_USE_P02_P03
#undef IIC_GPIO_USE_P02_P03
#endif
#define IIC_GPIO_USE_P00_P01
#ifdef MUTE_PORT_USE_P01
#undef  MUTE_PORT_USE_P01
#endif
#define MUTE_PORT_USE_P03
#define EXCHANGE_LINE_IN_CHANNEL	//交换LINE IN 通道


#define USE_POWER_KEY
#define PWR_CTRL_P02
#define USE_ONLY_POWER_HOLD_CTRL
#define USE_PWR_KEY_LONG_PWR_ON
#define POWE_KEY_PLAY_KEY_IN_ONE_KEY
#define CUSTOMER_DEFINED_ADKEY_RESISTOR

#define USE_POWER_KEY_SHORT_SCAN

#define USE_BAT_MANAGEMENT
#define BAT_LEVEL_LED_ICON_IND
#define LOW_VOLT_SPARK_BAT_ICON
#define CHARGER_DETECT_INDICATOR
#define CHARGER_DET_USE_P17
#define CHARGER_FLASH_TYPE_2

#define USE_LINE_IN_DETECT_FUNC
#define AUX_DETECT_USE_P04
#define DISABLE_QN_SCAN_ST
#define QN_SHARE_MCU_CRYSTAL

#endif

#ifdef K1032_HF_1032_V001

#define LED_USE_ROUND_LED
#define LED_USE_PLAY_MODE
#define LED_USE_PLAY_MODE_NORMAL

#ifdef IIC_GPIO_USE_P02_P03
#undef IIC_GPIO_USE_P02_P03
#endif
#define IIC_GPIO_USE_P00_P01
#ifdef MUTE_PORT_USE_P01
#undef  MUTE_PORT_USE_P01
#endif
#define MUTE_PORT_USE_P03
#define EXCHANGE_LINE_IN_CHANNEL	//交换LINE IN 通道


#define USE_POWER_KEY
#define PWR_CTRL_P02_KEY_P04
#define USE_ONLY_POWER_HOLD_CTRL
#define USE_PWR_KEY_LONG_PWR_ON
#define POWE_KEY_PLAY_KEY_IN_ONE_KEY
#define CUSTOMER_DEFINED_ADKEY_RESISTOR

#define USE_POWER_KEY_SHORT_SCAN

#define DISP_AUX_STRING

//#define USE_GPIO_DETECT_EARPHONE_PLUGGED

//#define USE_LINE_IN_DETECT_FUNC
//#define AUX_DETECT_USE_P04
#define DISABLE_QN_SCAN_ST
#define QN_SHARE_MCU_CRYSTAL


#define USE_BAT_MANAGEMENT
#define BAT_LEVEL_LED_ICON_IND

#endif

#ifdef K1032_YJH_1032_V001
#define LED_USE_ROUND_LED

#ifdef IIC_GPIO_USE_P02_P03
#undef IIC_GPIO_USE_P02_P03
#endif
#define IIC_GPIO_USE_P00_P01
#ifdef MUTE_PORT_USE_P01
#undef  MUTE_PORT_USE_P01
#endif
#define MUTE_PORT_USE_P03
#define EXCHANGE_LINE_IN_CHANNEL	//交换LINE IN 通道


#define USE_POWER_KEY
#define PWR_CTRL_P02_KEY_P04
#define USE_ONLY_POWER_HOLD_CTRL
#define USE_PWR_KEY_LONG_PWR_ON
#define POWE_KEY_PLAY_KEY_IN_ONE_KEY
#define CUSTOMER_DEFINED_ADKEY_RESISTOR

#define USE_POWER_KEY_SHORT_SCAN

#define DISP_AUX_STRING

//#define USE_GPIO_DETECT_EARPHONE_PLUGGED

//#define USE_LINE_IN_DETECT_FUNC
//#define AUX_DETECT_USE_P04
#define DISABLE_QN_SCAN_ST
#define QN_SHARE_MCU_CRYSTAL

#endif

#ifdef K1032_JIAMEI_1032_V001
#define LED_USE_ROUND_LED
#define LED_USE_PLAY_MODE
#define LED_USE_PLAY_MODE_NORMAL
#ifdef IIC_GPIO_USE_P02_P03
#undef IIC_GPIO_USE_P02_P03
#endif
#define IIC_GPIO_USE_P00_P01
#ifdef MUTE_PORT_USE_P01
#undef  MUTE_PORT_USE_P01
#endif
#define MUTE_PORT_USE_P03
#define EXCHANGE_LINE_IN_CHANNEL	//交换LINE IN 通道


#define USE_POWER_KEY
#define PWR_CTRL_P02
#define USE_ONLY_POWER_HOLD_CTRL
#define USE_PWR_KEY_LONG_PWR_ON
#define POWE_KEY_PLAY_KEY_IN_ONE_KEY
#define CUSTOMER_DEFINED_ADKEY_RESISTOR

#define USE_POWER_KEY_SHORT_SCAN

#define USE_BAT_MANAGEMENT
#define BAT_LEVEL_LED_ICON_IND

//#define USE_GPIO_DETECT_EARPHONE_PLUGGED

#define USE_LINE_IN_DETECT_FUNC
#define AUX_DETECT_USE_P04
#define DISABLE_QN_SCAN_ST
#define QN_SHARE_MCU_CRYSTAL

#endif


#ifdef K2018_JINRUI_2018_V001
#define LED_USE_ROUND_LED
#ifdef IIC_GPIO_USE_P02_P03
#undef IIC_GPIO_USE_P02_P03
#endif
#define IIC_GPIO_USE_P00_P01
#ifdef MUTE_PORT_USE_P01
#undef  MUTE_PORT_USE_P01
#endif
#define MUTE_PORT_USE_P03
#define EXCHANGE_LINE_IN_CHANNEL	//交换LINE IN 通道
#define USE_LONG_PLAY_KEY_TO_SWITCH_MODE

#define ADKEY_PLAY_SHORT_SCAN_FRE
#define IR_NEXT_PREV_SHORT_ADJ_CH
#define VOLUME_CUSTOMER_DEFINE

#define STOP_MODE_SHOW_STOP

#define NO_PLAY_STATUS_LED
#define JINRUI_IR_REMOTE_TYPE
//#define USE_GPIO_DETECT_EARPHONE_PLUGGED
//#define EARPHONE_DETECT_USE_P02
#define DECODE_STOP_MODE_ENABLE

#endif

#ifdef K000_JLH_2402_V001

#define NO_PLAY_STATUS_LED
#define LED_USE_COMMON_4X8

#ifdef IIC_GPIO_USE_P02_P03
#undef IIC_GPIO_USE_P02_P03
#endif
#define IIC_GPIO_USE_P00_P01

#ifdef MUTE_PORT_USE_P01
#undef  MUTE_PORT_USE_P01
#endif

#define CUSTOM_FUNC_POLLING

#define MUTE_PORT_USE_P04
#define CUSTOMIZED_VOL_LIMITATION

#define CUSTOMER_DEFINED_ADKEY_RESISTOR
#define PALY_MODE_USE_RAN_ALL_ONE
#define EXCHANGE_LINE_IN_CHANNEL	//交换LINE IN 通道

//#define SEMI_AUTO_SCAN_FREQ
//#define ADKEY_NEXT_PREV_HOLD_AUTO_SCAN
#define USE_LOW_BAT_SLEEP_MODE

#define NOT_USE_LINE_IN_FUNC
#define USE_LONG_MODE_FOR_POWER_KEY

#define USE_RTC_FUNCTION
#define USE_RTC_TIME_ONLY
#define ALARM_SEL_SOURCE
#define USE_RTC_ALARM_FUNCTION

#define EARPHONE_DETECT_USE_VPP
#define FLASH_LIGHT_FUNC
#define PWM3_IN_USE

#define USE_BAT_MANAGEMENT
#define BAT_LEVEL_GPIO_DRV_LED_IND

#endif

#ifdef K1028_WOKA_1028_APPLE_V001

#ifdef IIC_GPIO_USE_P02_P03
#undef IIC_GPIO_USE_P02_P03
#endif
#define IIC_GPIO_USE_P00_P01
#ifdef MUTE_PORT_USE_P01
#undef  MUTE_PORT_USE_P01
#endif
#define MUTE_PORT_USE_P03
#define EXCHANGE_LINE_IN_CHANNEL	//交换LINE IN 通道

#define PLAY_STATUS_LED_P04
#define ADKEY_PLAY_SHORT_SCAN_FRE

#define USE_GPIO_DETECT_EARPHONE_PLUGGED
#define INDEPENDENT_EARPHONE_DETECT_GPIO

#endif

#ifdef K1029_JINYI_1029_V001

#ifdef IIC_GPIO_USE_P02_P03
#undef IIC_GPIO_USE_P02_P03
#endif
#define IIC_GPIO_USE_P00_P01
#ifdef MUTE_PORT_USE_P01
#undef  MUTE_PORT_USE_P01
#endif
#define MUTE_PORT_USE_P03
#define EXCHANGE_LINE_IN_CHANNEL	//交换LINE IN 通道

#define ADKEY_PLAY_SHORT_SCAN_FRE

#define NO_PLAY_STATUS_LED
#define TWO_ADKEY_ENABLE
#define TWO_ADKEY_USE_PORT_P04

#define CUSTOMER_DEFINED_ADKEY_RESISTOR


#define USE_GPIO_DETECT_EARPHONE_PLUGGED
#define EARPHONE_DETECT_USE_P02
#endif

#ifdef K1025_AIPU_1025_V001
#define LED_USE_ROUND_LED
#define LED_USE_PLAY_MODE

#ifdef IIC_GPIO_USE_P02_P03
#undef IIC_GPIO_USE_P02_P03
#endif
#define IIC_GPIO_USE_P00_P01
#ifdef MUTE_PORT_USE_P01
#undef  MUTE_PORT_USE_P01
#endif
#define MUTE_PORT_USE_P03
#define EXCHANGE_LINE_IN_CHANNEL	//交换LINE IN 通道

#define ADKEY_PLAY_SHORT_SCAN_FRE
#define NO_PLAY_STATUS_LED

#define DEFAULT_GO_TO_AUX

#define USE_POWER_KEY
#define PWR_CTRL_P02_KEY_P04
#define USE_ONLY_POWER_HOLD_CTRL
#define USE_PWR_KEY_LONG_PWR_ON
#define POWE_KEY_PLAY_KEY_IN_ONE_KEY
#define CUSTOMER_DEFINED_ADKEY_RESISTOR

#define USE_POWER_KEY_SHORT_SCAN

#define USE_BAT_MANAGEMENT

#define USE_GPIO_DETECT_EARPHONE_PLUGGED

#define USB_SD_PLAY_INFO_DIV
#define FM_USE_KT0830EG


#define USE_LINE_IN_DETECT_FUNC
#define AUX_DETECT_USE_P04
#define LINE_IN_PLAY_KEY_PAUSE
#define LINE_IN_PLAY_KEY_NO_PAUSE_ICON_INDICATOR
#define USE_POWER_KEY_FOR_AUX_PLAY
#define DISABLE_QN_SCAN_ST

#endif

#ifdef K1022_WXD_1322_V001

#define LED_USE_ROUND_LED

#ifdef IIC_GPIO_USE_P02_P03
#undef IIC_GPIO_USE_P02_P03
#endif

#define IIC_GPIO_USE_P00_P01

#ifdef MUTE_PORT_USE_P01
#undef  MUTE_PORT_USE_P01
#endif
#define MUTE_PORT_USE_P03

#define NEW_SD_DETECT_MOD

#define EXCHANGE_LINE_IN_CHANNEL	//交换LINE IN 通道

#define USE_POWER_KEY
#define PWR_CTRL_P02_KEY_P04
#define USE_ONLY_POWER_HOLD_CTRL
#define USE_PWR_KEY_LONG_PWR_ON
#define CUSTOMER_DEFINED_ADKEY_RESISTOR

//#define INDEPENDENT_VOLUME_KEY
#define NOT_USE_LINE_IN_FUNC
#define USE_GPIO_DETECT_EARPHONE_PLUGGED

#endif


#ifdef K1026_YJH_1026_V001

#define LED_USE_ROUND_LED

#ifdef IIC_GPIO_USE_P02_P03
#undef IIC_GPIO_USE_P02_P03
#endif
#define IIC_GPIO_USE_P00_P01

#define PLAY_STATUS_LED_P04

#ifdef MUTE_PORT_USE_P01
#undef  MUTE_PORT_USE_P01
#endif
#define MUTE_PORT_USE_P03
#define EXCHANGE_LINE_IN_CHANNEL	//交换LINE IN 通道

#define ADKEY_PLAY_SHORT_SCAN_FRE

#define USE_GPIO_DETECT_EARPHONE_PLUGGED

#endif

#ifdef K000_XinLei_LC2092_V001

#define LED_GPIO_PORT_CUSTOMERIZED
#define LED_USE_PLAY_MODE

#ifdef MUTE_PORT_USE_P01
#undef  MUTE_PORT_USE_P01
#endif
#define MUTE_PORT_USE_P04

#define PLAY_STATUS_LED_P00
#define ADKEY_USE_P07_PORT

#define EXCHANGE_LINE_IN_CHANNEL	//交换LINE IN 通道

#define USE_POWER_KEY
#define PWR_CTRL_WKUP
#define POWE_KEY_PLAY_KEY_IN_ONE_KEY
#define POWER_KEY_ON_WAIT_FOR_3_SEC
#define PWR_ON_DELAY_2_SECOND
#define CUSTOMER_DEFINED_ADKEY_RESISTOR

#define USE_POWER_KEY_SHORT_SCAN
#define DISABLE_QN_SCAN_ST

#define USE_GPIO_DETECT_EARPHONE_PLUGGED
#define EARPHONE_DETECT_USE_P03
#define PLAY_STATUS_LED_SHARE_WITH_IIC_SCL

#define USE_BAT_MANAGEMENT

#define USE_LINE_IN_DETECT_FUNC
#define AUX_DETECT_USE_P06
#define AUX_DETECT_FUNC_WITH_MANUAL_SEL

//#define QN_SCAN_HIGH_SENSE

#endif

#ifdef K000_XinLei_LC2092_V002

#define LED_GPIO_PORT_CUSTOMERIZED
#define LED_USE_PLAY_MODE

#ifdef MUTE_PORT_USE_P01
#undef  MUTE_PORT_USE_P01
#endif
#define MUTE_PORT_USE_P04

#define PLAY_STATUS_LED_P00
#define ADKEY_USE_P07_PORT

#define EXCHANGE_LINE_IN_CHANNEL	//交换LINE IN 通道

#define USE_POWER_KEY
#define PWR_CTRL_WKUP
#define POWE_KEY_PLAY_KEY_IN_ONE_KEY
#define POWER_KEY_ON_WAIT_FOR_3_SEC
#define PWR_ON_DELAY_1_SECOND

#define CUSTOMER_DEFINED_ADKEY_RESISTOR

#define USE_POWER_KEY_SHORT_SCAN
#define DISABLE_QN_SCAN_ST

#define USE_GPIO_DETECT_EARPHONE_PLUGGED
#define EARPHONE_DETECT_USE_P03
#define PLAY_STATUS_LED_SHARE_WITH_IIC_SCL

#define USE_BAT_MANAGEMENT

#define USE_LINE_IN_DETECT_FUNC
#define AUX_DETECT_USE_P06
#define AUX_DETECT_FUNC_WITH_MANUAL_SEL

//#define FM_MAX_CHANNAL_50
//#define QN_SCAN_HIGH_SENSE

#endif

#ifdef K000_XinLei_LC2092_V003

#define LED_GPIO_PORT_CUSTOMERIZED
//#define LED_USE_PLAY_MODE

#ifdef MUTE_PORT_USE_P01
#undef  MUTE_PORT_USE_P01
#endif
#define MUTE_PORT_USE_P04

#define PLAY_STATUS_LED_P00
#define ADKEY_USE_P07_PORT

#define EXCHANGE_LINE_IN_CHANNEL	//交换LINE IN 通道

#define FM_MAX_CHANNAL_50
//#define PWR_CTRL_WKUP
//#define POWE_KEY_PLAY_KEY_IN_ONE_KEY
//#define POWER_KEY_ON_WAIT_FOR_3_SEC
//#define CUSTOMER_DEFINED_ADKEY_RESISTOR

#define ADKEY_PLAY_SHORT_SCAN_FRE
#define DISABLE_QN_SCAN_ST

#define USE_GPIO_DETECT_EARPHONE_PLUGGED
#define EARPHONE_DETECT_USE_P03
#define PLAY_STATUS_LED_SHARE_WITH_IIC_SCL

//#define USE_BAT_MANAGEMENT

#define USE_LINE_IN_DETECT_FUNC
#define AUX_DETECT_USE_P06
#define AUX_DETECT_FUNC_WITH_MANUAL_SEL

//#define FM_MAX_CHANNAL_50
//#define QN_SCAN_HIGH_SENSE

#endif


#ifdef K000_XinLei_LC2092_V004

#define LED_GPIO_PORT_CUSTOMERIZED

#ifdef MUTE_PORT_USE_P01
#undef  MUTE_PORT_USE_P01
#endif
#define MUTE_PORT_USE_P04

#define PLAY_STATUS_LED_P00
#define ADKEY_USE_P07_PORT

#define EXCHANGE_LINE_IN_CHANNEL	//交换LINE IN 通道

#define FM_MAX_CHANNAL_50
#define LED_USE_PLAY_MODE

//#define POWE_KEY_PLAY_KEY_IN_ONE_KEY
//#define POWER_KEY_ON_WAIT_FOR_3_SEC
//#define CUSTOMER_DEFINED_ADKEY_RESISTOR

#define ADKEY_PLAY_SHORT_SCAN_FRE
#define DISABLE_QN_SCAN_ST

#define USE_GPIO_DETECT_EARPHONE_PLUGGED
#define EARPHONE_DETECT_USE_P03
#define PLAY_STATUS_LED_SHARE_WITH_IIC_SCL

#define USE_BAT_MANAGEMENT

#define USE_LINE_IN_DETECT_FUNC
#define AUX_DETECT_USE_P06
#define AUX_DETECT_FUNC_WITH_MANUAL_SEL

//#define FM_MAX_CHANNAL_50
//#define QN_SCAN_HIGH_SENSE

#endif

#ifdef K000_XinLei_LC2092_V006

#define LED_GPIO_PORT_CUSTOMERIZED

#ifdef MUTE_PORT_USE_P01
#undef  MUTE_PORT_USE_P01
#endif
#define MUTE_PORT_USE_P17

#define PLAY_STATUS_LED_P00

#define EXCHANGE_LINE_IN_CHANNEL	//交换LINE IN 通道

#define FM_MAX_CHANNAL_50
#define VOLUME_CUSTOMER_DEFINE_16
#define NEW_CUSTOMED_VOLUME_DIVIDED_METHOD

#define DISP_BAR_ICON

#if 1
#define USE_POWER_KEY
#define PWR_CTRL_WKUP
#define POWER_KEY_ON_WAIT_FOR_3_SEC
#define PWR_ON_DELAY_1_SECOND
#endif

#define DEFAULT_GO_TO_IDLE
#define POWE_KEY_PLAY_KEY_IN_ONE_KEY

#define CUSTOMER_DEFINED_ADKEY_RESISTOR
#define PLAY_ICON_FLASH
#define TWO_ADKEY_ENABLE
#define TWO_ADKEY_USE_PORT_P07
#define INDEPENDENT_VOLUME_KEY

#define ADKEY_PLAY_SHORT_SCAN_FRE
#define DISABLE_QN_SCAN_ST
#define USE_POWER_KEY_SHORT_SCAN

#define USE_GPIO_DETECT_EARPHONE_PLUGGED
#define EARPHONE_DETECT_USE_P03
#define PLAY_STATUS_LED_SHARE_WITH_IIC_SCL

#define USE_HEADHPONE_DISABLE_FUNC

#define USE_BAT_MANAGEMENT

#define CHARGER_DETECT_INDICATOR
#define CHARGER_FLASH_TYPE_1

#define DISP_VOL_V_CHAR
#define FM_DISP_CH_STR
#define QN_SCAN_HIGH_SENSE

#endif

#ifdef K000_XinLei_LC2092_V005_A8B

#define LED_GPIO_PORT_CUSTOMERIZED
#define XINLEI_LED_DRIVE_TYPE
#define EXCHANGE_FM_MP3_ICON

#ifdef MUTE_PORT_USE_P01
#undef  MUTE_PORT_USE_P01
#endif
#define MUTE_PORT_USE_DUMP

#define PLAY_STATUS_LED_P00

#define EXCHANGE_LINE_IN_CHANNEL	//交换LINE IN 通道

#define FM_MAX_CHANNAL_50

#if 1
#define USE_POWER_KEY
#define PWR_CTRL_WKUP
#define POWE_KEY_PLAY_KEY_IN_ONE_KEY
#define POWER_KEY_ON_WAIT_FOR_3_SEC
#define PWR_ON_DELAY_1_SECOND

#endif 

#define POWE_KEY_PLAY_KEY_IN_ONE_KEY

#define CUSTOMER_DEFINED_ADKEY_RESISTOR

#define TWO_ADKEY_ENABLE
#define TWO_ADKEY_USE_PORT_P07
#define INDEPENDENT_VOLUME_KEY

#define ADKEY_PLAY_SHORT_SCAN_FRE
#define DISABLE_QN_SCAN_ST
#define USE_POWER_KEY_SHORT_SCAN

#define USE_GPIO_DETECT_EARPHONE_PLUGGED
#define EARPHONE_DETECT_USE_P03
#define PLAY_STATUS_LED_SHARE_WITH_IIC_SCL

#define USE_HEADHPONE_DISABLE_FUNC
#define USE_AMP_MODE_SELECT
#define AMP_MODE_SELECT_PORT_USE_P04

//#define USE_LINE_IN_DETECT_FUNC
//#define AUX_DETECT_USE_P06
//#define AUX_DETECT_FUNC_WITH_MANUAL_SEL

//#define FM_MAX_CHANNAL_50
//#define QN_SCAN_HIGH_SENSE

#endif

#ifdef K000_XinLei_LC2092_V005

#define LED_GPIO_PORT_CUSTOMERIZED

#ifdef MUTE_PORT_USE_P01
#undef  MUTE_PORT_USE_P01
#endif
#define MUTE_PORT_USE_P04

#define PLAY_STATUS_LED_P00

#define EXCHANGE_LINE_IN_CHANNEL	//交换LINE IN 通道

#define FM_MAX_CHANNAL_50

#if 1
#define USE_POWER_KEY
#define PWR_CTRL_WKUP
#define POWE_KEY_PLAY_KEY_IN_ONE_KEY
#define POWER_KEY_ON_WAIT_FOR_3_SEC
#define PWR_ON_DELAY_1_SECOND

#endif 

#define POWE_KEY_PLAY_KEY_IN_ONE_KEY

#define CUSTOMER_DEFINED_ADKEY_RESISTOR

#define TWO_ADKEY_ENABLE
#define TWO_ADKEY_USE_PORT_P07
#define INDEPENDENT_VOLUME_KEY

#define ADKEY_PLAY_SHORT_SCAN_FRE
#define DISABLE_QN_SCAN_ST
#define USE_POWER_KEY_SHORT_SCAN

#define USE_GPIO_DETECT_EARPHONE_PLUGGED
#define EARPHONE_DETECT_USE_P03
#define PLAY_STATUS_LED_SHARE_WITH_IIC_SCL

#define USE_HEADHPONE_DISABLE_FUNC

//#define USE_LINE_IN_DETECT_FUNC
//#define AUX_DETECT_USE_P06
//#define AUX_DETECT_FUNC_WITH_MANUAL_SEL

//#define FM_MAX_CHANNAL_50
//#define QN_SCAN_HIGH_SENSE

#endif

#ifdef K000_XINGLEI_2092_V002

#define LED_GPIO_PORT_CUSTOMERIZED

#ifdef MUTE_PORT_USE_P01
#undef  MUTE_PORT_USE_P01
#endif
#define MUTE_PORT_USE_P04

#define PLAY_STATUS_LED_P00
#define ADKEY_USE_P07_PORT

#define EXCHANGE_LINE_IN_CHANNEL	//交换LINE IN 通道

#define ADKEY_PLAY_SHORT_SCAN_FRE
#define DISABLE_QN_SCAN_ST

#define USE_GPIO_DETECT_EARPHONE_PLUGGED
#define EARPHONE_DETECT_USE_P03
#define PLAY_STATUS_LED_SHARE_WITH_IIC_SCL

#define USE_LINE_IN_DETECT_FUNC
#define AUX_DETECT_USE_P06
#define FM_MAX_CHANNAL_50
#define QN_SCAN_HIGH_SENSE

#define INDEPENDENT_VOLUME_KEY

#endif


#ifdef K820_LHD_820_V001

#ifdef LED_GPIO_DRV
#undef  LED_GPIO_DRV
#endif
#define LCD_GPIO_DRV

#ifdef IIC_GPIO_USE_P02_P03
#undef IIC_GPIO_USE_P02_P03
#endif

#define IIC_GPIO_USE_P00_P01

#ifdef MUTE_PORT_USE_P01
#undef  MUTE_PORT_USE_P01
#endif
#define MUTE_PORT_USE_P03

#define EXCHANGE_LINE_IN_CHANNEL	//交换LINE IN 通道

#define ADKEY_PLAY_SHORT_SCAN_FRE

#define VOLUME_DEFUALT	28

#define CUSTOMER_DEFINED_ADKEY_RESISTOR
//#define NO_PLAY_STATUS_LED


#define PLAY_MODE_USE_REP_ONE_ALL

#define SEMI_AUTO_SCAN_FREQ
#define ADKEY_NEXT_PREV_HOLD_AUTO_SCAN

#define ADKEY_USE_P05_PORT
#define DISABLE_P05_OSC_OUTPUT

#define _KEY_TONE_ENABEL_
#define INDEPENDENT_VOLUME_KEY

#define USE_RTC_FUNCTION

#define USE_RTC_TIME_ONLY

#define CUSTOMIZED_KEY_FUNC_ENABLE
//#define MANUAL_SWITCH_TIME_DISPLAY

//#define NOT_USE_LINE_IN_FUNC
#define IPONE_LINE_IN_CHANNEL_USE_AUX0

#define DEFAULT_GO_TO_TIME_MODE
#if 0
#define IPONE_DOCK_FUNC_ENABLE
#define IPONE_INDEPENDENT_MODE
#define IPHONE_TX_USE_P06
#define TURN_ON_MUSIC_WHEN_IPHONE_DOCK
#endif
#endif

#ifdef K795_JinYeHeLi_795_V001

#ifdef IIC_GPIO_USE_P02_P03
#undef IIC_GPIO_USE_P02_P03
#endif

#define IIC_GPIO_USE_P00_P01

#ifdef MUTE_PORT_USE_P01
#undef  MUTE_PORT_USE_P01
#endif
#define MUTE_PORT_USE_P03

#define EXCHANGE_LINE_IN_CHANNEL	//交换LINE IN 通道

#define ADKEY_PLAY_SHORT_SCAN_FRE

#define NO_PLAY_STATUS_LED
#define NEW_SD_DETECT_MOD

#define CUSTOMER_DEFINED_ADKEY_RESISTOR
#define LED_USE_ROUND_LED
#define LED_USE_PLAY_MODE
#define USE_BAT_MANAGEMENT
//#define INDEPENDENT_VOLUME_KEY

#define USE_GPIO_DETECT_EARPHONE_PLUGGED

#define USB_SD_PLAY_INFO_DIV

#define LINE_IN_PLAY_KEY_PAUSE
#define LINE_IN_PLAY_KEY_NO_PAUSE_ICON_INDICATOR
#define FM_USE_KT0830EG

#endif


#ifdef K796_JinYeHeLi_796_V001
#define LED_USE_ROUND_LED
#define LED_USE_PLAY_MODE

#ifdef IIC_GPIO_USE_P02_P03
#undef IIC_GPIO_USE_P02_P03
#endif
#define IIC_GPIO_USE_P00_P01
#ifdef MUTE_PORT_USE_P01
#undef  MUTE_PORT_USE_P01
#endif
#define MUTE_PORT_USE_P03
#define EXCHANGE_LINE_IN_CHANNEL	//交换LINE IN 通道

#define ADKEY_PLAY_SHORT_SCAN_FRE
#define NO_PLAY_STATUS_LED

#define USE_POWER_KEY
#define PWR_CTRL_P02_KEY_P04
#define USE_ONLY_POWER_HOLD_CTRL
#define USE_PWR_KEY_LONG_PWR_ON
#define POWE_KEY_PLAY_KEY_IN_ONE_KEY
#define CUSTOMER_DEFINED_ADKEY_RESISTOR

#define USE_POWER_KEY_SHORT_SCAN

#define USE_BAT_MANAGEMENT

#define USE_GPIO_DETECT_EARPHONE_PLUGGED

#define USB_SD_PLAY_INFO_DIV
#define FM_USE_KT0830EG

#define LINE_IN_PLAY_KEY_PAUSE
#define LINE_IN_PLAY_KEY_NO_PAUSE_ICON_INDICATOR
#define USE_POWER_KEY_FOR_AUX_PLAY
#define DISABLE_QN_SCAN_ST

#endif


#ifdef K815_FW_815_V001

#define NO_PLAY_STATUS_LED

#ifdef IIC_GPIO_USE_P02_P03
#undef IIC_GPIO_USE_P02_P03
#endif
#define IIC_GPIO_USE_P00_P01

#ifdef MUTE_PORT_USE_P01
#undef  MUTE_PORT_USE_P01
#endif
#define MUTE_PORT_USE_P03
#define EXCHANGE_LINE_IN_CHANNEL	//交换LINE IN 通道

#define INDEPENDENT_VOLUME_KEY

#define ADKEY_PLAY_SHORT_SCAN_FRE
#define SEMI_AUTO_SCAN_FREQ
#define ADKEY_NEXT_PREV_HOLD_AUTO_SCAN


#endif

#ifdef K791_YJH_791_V001

#define NO_PLAY_STATUS_LED

#ifdef IIC_GPIO_USE_P02_P03
#undef IIC_GPIO_USE_P02_P03
#endif
#define IIC_GPIO_USE_P00_P01
#ifdef MUTE_PORT_USE_P01
#undef  MUTE_PORT_USE_P01
#endif
#define MUTE_PORT_USE_P03
#define EXCHANGE_LINE_IN_CHANNEL	//交换LINE IN 通道

#define CUSTOMER_DEFINED_ADKEY_RESISTOR

#define TWO_ADKEY_ENABLE

#define INDEPENDENT_VOLUME_KEY

#define ADKEY_PLAY_SHORT_SCAN_FRE
#define SEMI_AUTO_SCAN_FREQ
#define ADKEY_NEXT_PREV_HOLD_AUTO_SCAN
#define IR_NEXT_PREV_HOLD_AUTO_SCAN

#endif

#ifdef K773_MingYang_773_V001

#define NO_LED_DISPLAY

#ifdef IIC_GPIO_USE_P02_P03
#undef IIC_GPIO_USE_P02_P03
#endif
#define IIC_GPIO_USE_P00_P01
#ifdef MUTE_PORT_USE_P01
#undef  MUTE_PORT_USE_P01
#endif
#define MUTE_PORT_USE_P03
#define EXCHANGE_LINE_IN_CHANNEL	//交换LINE IN 通道
#define ADKEY_USE_P04_PORT

#define DECODE_STOP_MODE_ENABLE
#define PLAY_LONG_PRESS_STOP

#define FM_BY_PASS
#define SEMI_AUTO_SCAN_FREQ
#define ADKEY_NEXT_PREV_HOLD_AUTO_SCAN
#define ADKEY_PLAY_SHORT_SCAN_FRE

#define INDEPENDENT_VOLUME_KEY

#define IPONE_DOCK_FUNC_ENABLE
#define IPONE_INDEPENDENT_MODE
#define IPHONE_TX_USE_P06
#define TURN_ON_MUSIC_WHEN_IPHONE_DOCK

#endif


#ifdef K714_FW_016A_V001

#ifdef IIC_GPIO_USE_P02_P03
#undef IIC_GPIO_USE_P02_P03
#endif
#define IIC_GPIO_USE_P00_P01
#ifdef MUTE_PORT_USE_P01
#undef  MUTE_PORT_USE_P01
#endif
#define MUTE_PORT_USE_P03
#define EXCHANGE_LINE_IN_CHANNEL	//交换LINE IN 通道

#define ADKEY_PLAY_SHORT_SCAN_FRE
#define USE_GPIO_DETECT_EARPHONE_PLUGGED

//#define INDEPENDENT_VOLUME_KEY
#define LED_USE_1X888
#define USE_LONG_PLAY_KEY_TO_SWITCH_MODE

#define USE_LINE_IN_DETECT_FUNC
#define AUX_DETECT_USE_P02

#endif

#ifdef K779_YJH_779_V001

#ifdef IIC_GPIO_USE_P02_P03
#undef IIC_GPIO_USE_P02_P03
#endif
#define IIC_GPIO_USE_P00_P01
#ifdef MUTE_PORT_USE_P01
#undef  MUTE_PORT_USE_P01
#endif
#define MUTE_PORT_USE_P03

#define NO_PLAY_STATUS_LED

#define EXCHANGE_LINE_IN_CHANNEL	//交换LINE IN 通道

#define ADKEY_PLAY_SHORT_SCAN_FRE
#define SEMI_AUTO_SCAN_FREQ
#define ADKEY_NEXT_PREV_HOLD_AUTO_SCAN
#define CUSTOMER_DEFINED_ADKEY_RESISTOR
#define CUSTOMIZED_KEY_FUNC_ENABLE

#define INDEPENDENT_VOLUME_KEY

#define DEFAULT_GO_TO_TIME_MODE

#define USE_RTC_FUNCTION
#define USE_RTC_TIME_ONLY

#define VOLUME_DEFUALT	27

#endif

#ifdef K807_YJH_807_V001

#define LED_USE_ROUND_LED

#ifdef IIC_GPIO_USE_P02_P03
#undef IIC_GPIO_USE_P02_P03
#endif
#define IIC_GPIO_USE_P00_P01
#ifdef MUTE_PORT_USE_P01
#undef  MUTE_PORT_USE_P01
#endif
#define MUTE_PORT_USE_P03
#define NEW_SD_DETECT_MOD

#define EXCHANGE_LINE_IN_CHANNEL	//交换LINE IN 通道

//#define FM_PLAY_KEY_PAUSE
#define FM_PLAY_KEY_PAUSE

#define SEMI_AUTO_SCAN_FREQ
#define ADKEY_NEXT_PREV_HOLD_AUTO_SCAN

#define INDEPENDENT_VOLUME_KEY
//#define NOT_USE_LINE_IN_FUNC
#define USE_GPIO_DETECT_EARPHONE_PLUGGED


#endif

#ifdef K777_SW_777_V001

#define NO_PLAY_STATUS_LED
#define LED_USE_PLAY_MODE

#ifdef IIC_GPIO_USE_P02_P03
#undef IIC_GPIO_USE_P02_P03
#endif
#define IIC_GPIO_USE_P00_P01
#ifdef MUTE_PORT_USE_P01
#undef  MUTE_PORT_USE_P01
#endif
#define MUTE_PORT_USE_P03
#define EXCHANGE_LINE_IN_CHANNEL	//交换LINE IN 通道

#define CUSTOMER_DEFINED_ADKEY_RESISTOR
#define ADKEY_NEW_METHOD
#define TWO_ADKEY_ENABLE
#define EXTENDED_ADKEY_NUM
#define KEY_100_ENABLE
#define CUSTOMIZED_EQ_MODE
#define INDEPENDENT_VOLUME_KEY
//#define IR_REMOTER_WITH_POWER_MUTE_PRINT

#define SEMI_AUTO_SCAN_FREQ
#define ADKEY_NEXT_PREV_HOLD_AUTO_SCAN
#define IR_NEXT_PREV_HOLD_AUTO_SCAN

#endif

#ifdef K000_HG_898_V001

#ifdef IIC_GPIO_USE_P02_P03
#undef IIC_GPIO_USE_P02_P03
#endif
#define IIC_GPIO_USE_P00_P01
#ifdef MUTE_PORT_USE_P01
#undef  MUTE_PORT_USE_P01
#endif
#define MUTE_PORT_USE_DUMP

#define MP3_PUASE_FLASH_FIGURE
#define DECODE_STOP_MODE_ENABLE
#define EQ_ADJ_USE_STOP_KEY_LONG

#define CUSTOMER_DEFINED_ADKEY_RESISTOR

#define PLAY_MODE_USE_REP_ONE_ALL
#define USE_LONG_PLAY_KEY_PLAY_MODE

#define NO_PLAY_STATUS_LED
#define USE_USB_AUDIO
#define MP3_DISP_LOAD_STRING
#define DEFAULT_GO_TO_IDLE

#define VOLUME_DEFUALT 30

#define FORCE_GO_TO_MP3_MODE
#define USE_MANUAL_IDLE_FUNC
#define MUTE_ON_FLASH_WHOLE_SCREEN

#define ADKEY_NEXT_ADJST_FREQ
#define EQ_DOWN_SCAN_ALL

#define IR_PLAY_KEY_SCAN_FREQ_DISABLE

#define NOT_USE_LINE_IN_FUNC

#endif

#ifdef K769_JinRui_769_V002

#define LED_USE_PLAY_MODE_MIXED
#define LED_GPIO_PORT_CUSTOMERIZED

#ifdef IIC_GPIO_USE_P02_P03
#undef IIC_GPIO_USE_P02_P03
#endif
#define IIC_GPIO_USE_P00_P01
#ifdef MUTE_PORT_USE_P01
#undef  MUTE_PORT_USE_P01
#endif
#define MUTE_PORT_USE_P03
#define EXCHANGE_LINE_IN_CHANNEL	//交换LINE IN 通道

#define ADKEY_PLAY_SHORT_SCAN_FRE


#define DISP_VOL_V_CHAR
#define JINRUI_IR_REMOTE_TYPE

#define NEW_CUSTOMED_VOLUME_DIVIDED_METHOD
#define DECODE_STOP_MODE_ENABLE
#define STOP_MODE_SHOW_STOP
#define IR_NEXT_PREV_SHORT_ADJ_CH
#define LINE_IN_PLAY_KEY_PAUSE
#define LINE_IN_PLAY_KEY_NO_PAUSE_ICON_INDICATOR

#endif


#ifdef K769_JinRui_769_V001

#define LED_USE_PLAY_MODE
//#define LED_GPIO_PORT_CUSTOMERIZED

#ifdef IIC_GPIO_USE_P02_P03
#undef IIC_GPIO_USE_P02_P03
#endif
#define IIC_GPIO_USE_P00_P01
#ifdef MUTE_PORT_USE_P01
#undef  MUTE_PORT_USE_P01
#endif
#define MUTE_PORT_USE_P03
#define EXCHANGE_LINE_IN_CHANNEL	//交换LINE IN 通道

#define ADKEY_PLAY_SHORT_SCAN_FRE


//#define USE_GPIO_DETECT_EARPHONE_PLUGGED
//#define NO_PLAY_STATUS_LED
//#define USE_USB_AUDIO

#define NEW_CUSTOMED_VOLUME_DIVIDED_METHOD
#define DECODE_STOP_MODE_ENABLE
#define STOP_MODE_SHOW_STOP
#define IR_NEXT_PREV_SHORT_ADJ_CH
#define LINE_IN_PLAY_KEY_PAUSE
#define LINE_IN_PLAY_KEY_NO_PAUSE_ICON_INDICATOR

#endif


#ifdef K771_YJH_771_V001

#ifdef IIC_GPIO_USE_P02_P03
#undef IIC_GPIO_USE_P02_P03
#endif
#define IIC_GPIO_USE_P00_P01
#ifdef MUTE_PORT_USE_P01
#undef  MUTE_PORT_USE_P01
#endif
#define MUTE_PORT_USE_P03
#define EXCHANGE_LINE_IN_CHANNEL	//交换LINE IN 通道

#define ADKEY_PLAY_SHORT_SCAN_FRE
//#define USE_GPIO_DETECT_EARPHONE_PLUGGED

#endif
#ifdef K766_YJH_766_V001

#define LED_USE_1X888

#ifdef IIC_GPIO_USE_P02_P03
#undef IIC_GPIO_USE_P02_P03
#endif
#define IIC_GPIO_USE_P00_P01
#ifdef MUTE_PORT_USE_P01
#undef  MUTE_PORT_USE_P01
#endif
#define MUTE_PORT_USE_P03
#define EXCHANGE_LINE_IN_CHANNEL	//交换LINE IN 通道

#define ADKEY_PLAY_SHORT_SCAN_FRE
#define NO_PLAY_STATUS_LED

#define USE_GPIO_DETECT_EARPHONE_PLUGGED

#endif

#ifdef K000_KT_AMFM_V001
#define FM_USE_KT0913

#ifdef USE_BK1080_FM
#undef USE_BK1080_FM
#endif

#ifdef USE_QN8035_FM
#undef USE_QN8035_FM
#endif

#ifdef LED_GPIO_DRV
#undef  LED_GPIO_DRV
#endif
#define LCD_GPIO_DRV

#ifdef IIC_GPIO_USE_P02_P03
#undef IIC_GPIO_USE_P02_P03
#endif
#define IIC_GPIO_USE_P00_P01

#ifdef MUTE_PORT_USE_P01
#undef  MUTE_PORT_USE_P01
#endif
#define MUTE_PORT_USE_WKUP

//#define MUTE_ON_FLASH_WHOLE_SCREEN
//#define IR_REMOTER_WITH_POWER_MUTE_PRINT

//#define PLAY_STATUS_LED_P04

#define RADIO_AM_WM_ENABLE

//#define ADKEY_USE_P07_PORT
//#define TWO_ADKEY_ENABLE
#define CUSTOMER_DEFINED_ADKEY_RESISTOR
#define DECODE_STOP_MODE_ENABLE
#define EXCHANGE_LINE_IN_CHANNEL	//交换LINE IN 通道

#define FM_BY_PASS
#define ADKEY_PLAY_SHORT_SCAN_FRE
#define ADKEY_NEXT_ADJST_FREQ

#define USE_RTC_FUNCTION
#define USE_RTC_TIME_ONLY
#define USE_RTC_ALARM_FUNCTION

#define SPECTRUM_FUNC_ENABLE
#define JOG_STICK_FUNC
#endif


#ifdef K000_AOKAILIN_508_V001

#ifdef IIC_GPIO_USE_P02_P03
#undef IIC_GPIO_USE_P02_P03
#endif
#define IIC_GPIO_USE_P00_P01

#ifdef MUTE_PORT_USE_P01
#undef  MUTE_PORT_USE_P01
#endif
#define MUTE_PORT_USE_P04
#define EXCHANGE_LINE_IN_CHANNEL	//交换LINE IN 通道
#define ADKEY_USE_P07_PORT

#define ADKEY_PLAY_SHORT_SCAN_FRE
#define NO_PLAY_STATUS_LED

#define LED_GPIO_PORT_CUSTOMERIZED


#define USE_POWER_KEY
#define PWR_CTRL_WKUP
//#define USE_ONLY_POWER_HOLD_CTRL
#define POWE_KEY_PLAY_KEY_IN_ONE_KEY
#define CUSTOMER_DEFINED_ADKEY_RESISTOR

#define USE_POWER_KEY_SHORT_SCAN

#define USE_LINE_IN_DETECT_FUNC
#define AUX_DETECT_USE_P06
#define USE_BAT_MANAGEMENT
//#define CHARGER_DETECT_INDICATOR
#define USE_USB_AUDIO
#define FM_USE_KT0830EG

#endif

#ifdef K000_AOKAILIN_535B_V001

#define LED_USE_PLAY_MODE

#ifdef IIC_GPIO_USE_P02_P03
#undef IIC_GPIO_USE_P02_P03
#endif
#define IIC_GPIO_USE_P00_P01
#ifdef MUTE_PORT_USE_P01
#undef  MUTE_PORT_USE_P01
#endif
#define MUTE_PORT_USE_P03
#define EXCHANGE_LINE_IN_CHANNEL	//交换LINE IN 通道
#define TWO_ADKEY_ENABLE
#define TWO_ADKEY_USE_PORT_P04

#define ADKEY_PLAY_SHORT_SCAN_FRE
#define NO_PLAY_STATUS_LED

#define USE_POWER_KEY
#define PWR_CTRL_P02_KEY_P04
#define USE_ONLY_POWER_HOLD_CTRL
#define POWE_KEY_PLAY_KEY_IN_ONE_KEY
#define USE_PWR_KEY_LONG_PWR_ON
#define CUSTOMER_DEFINED_ADKEY_RESISTOR

#define USE_POWER_KEY_SHORT_SCAN
#define USE_GPIO_DETECT_EARPHONE_PLUGGED

//#define USE_LINE_IN_DETECT_FUNC
//#define AUX_DETECT_USE_P07
#define USE_BAT_MANAGEMENT
#define CHARGER_DETECT_INDICATOR
#define USE_USB_AUDIO
#define VOLUME_CUSTOMER_DEFINE_32
#define CUSTOMIZED_VOL_LIMITATION
#define FM_USE_AR1015

#endif



#ifdef K000_AOKAILIN_537B_V001

#define LED_USE_PLAY_MODE

#ifdef IIC_GPIO_USE_P02_P03
#undef IIC_GPIO_USE_P02_P03
#endif
#define IIC_GPIO_USE_P00_P01
#ifdef MUTE_PORT_USE_P01
#undef  MUTE_PORT_USE_P01
#endif
#define MUTE_PORT_USE_P03
#define EXCHANGE_LINE_IN_CHANNEL	//交换LINE IN 通道

#define ADKEY_PLAY_SHORT_SCAN_FRE
#define NO_PLAY_STATUS_LED

#define USE_BAT_MANAGEMENT
#define CHARGER_DETECT_INDICATOR
#define USE_GPIO_DETECT_EARPHONE_PLUGGED

#define VOLUME_CUSTOMER_DEFINE_32
#define CUSTOMIZED_VOL_LIMITATION
#endif

#ifdef K000_AOKAILIN_G01_V001

#define LED_USE_PLAY_MODE

#ifdef IIC_GPIO_USE_P02_P03
#undef IIC_GPIO_USE_P02_P03
#endif
#define IIC_GPIO_USE_P00_P01
#ifdef MUTE_PORT_USE_P01
#undef  MUTE_PORT_USE_P01
#endif
#define MUTE_PORT_USE_P03
#define EXCHANGE_LINE_IN_CHANNEL	//交换LINE IN 通道

#define ADKEY_PLAY_SHORT_SCAN_FRE
#define NO_PLAY_STATUS_LED

#define USE_POWER_KEY
#define PWR_CTRL_P02
#define USE_ONLY_POWER_HOLD_CTRL
#define POWE_KEY_PLAY_KEY_IN_ONE_KEY
#define USE_PWR_KEY_LONG_PWR_ON
#define CUSTOMER_DEFINED_ADKEY_RESISTOR

#define USE_POWER_KEY_SHORT_SCAN

#define USE_LINE_IN_DETECT_FUNC
#define AUX_DETECT_USE_P07
#define USE_BAT_MANAGEMENT
#define CHARGER_DETECT_INDICATOR
#define USE_USB_AUDIO
#define VOLUME_CUSTOMER_DEFINE_32
#define CUSTOMIZED_VOL_LIMITATION
#endif

#ifdef K593_YJH_593_V001

#define LED_USE_ROUND_LED

#ifdef IIC_GPIO_USE_P02_P03
#undef IIC_GPIO_USE_P02_P03
#endif
#define IIC_GPIO_USE_P00_P01
#ifdef MUTE_PORT_USE_P01
#undef  MUTE_PORT_USE_P01
#endif
#define MUTE_PORT_USE_P03
#define EXCHANGE_LINE_IN_CHANNEL	//交换LINE IN 通道

#define ADKEY_PLAY_SHORT_SCAN_FRE
#define PLAY_STATUS_LED_P04

#define USE_USB_AUDIO

#endif

#ifdef K592_YJH_592_V001

#define LED_USE_1X888

#ifdef IIC_GPIO_USE_P02_P03
#undef IIC_GPIO_USE_P02_P03
#endif
#define IIC_GPIO_USE_P00_P01
#ifdef MUTE_PORT_USE_P01
#undef  MUTE_PORT_USE_P01
#endif
#define MUTE_PORT_USE_P03
#define EXCHANGE_LINE_IN_CHANNEL	//交换LINE IN 通道

#define ADKEY_PLAY_SHORT_SCAN_FRE
#define NO_PLAY_STATUS_LED

#define USE_USB_AUDIO

#endif

#ifdef K760_YJH_760_V001

#ifdef IIC_GPIO_USE_P02_P03
#undef IIC_GPIO_USE_P02_P03
#endif
#define IIC_GPIO_USE_P00_P01
#ifdef MUTE_PORT_USE_P01
#undef  MUTE_PORT_USE_P01
#endif
#define MUTE_PORT_USE_P03
#define EXCHANGE_LINE_IN_CHANNEL	//交换LINE IN 通道

#define ADKEY_PLAY_SHORT_SCAN_FRE
#define NO_PLAY_STATUS_LED

#define USE_GPIO_DETECT_EARPHONE_PLUGGED
#define USE_USB_AUDIO

#endif

#ifdef K739_YJH_739_V001

#ifdef IIC_GPIO_USE_P02_P03
#undef IIC_GPIO_USE_P02_P03
#endif
#define IIC_GPIO_USE_P00_P01
#ifdef MUTE_PORT_USE_P01
#undef  MUTE_PORT_USE_P01
#endif
#define MUTE_PORT_USE_P03
#define EXCHANGE_LINE_IN_CHANNEL	//交换LINE IN 通道

#define ADKEY_PLAY_SHORT_SCAN_FRE
#define NO_PLAY_STATUS_LED

#define USE_GPIO_DETECT_EARPHONE_PLUGGED
#define USE_USB_AUDIO

#endif


#ifdef K000_XingChuang_x832_V001

#define ADKEY_USE_P07_PORT

#define NO_LED_DISPLAY
#define PLAY_STATUS_LED_P10
#undef LED_CTRL_LEVEL_NORMAL

//#define NOT_MOUNT_USB_SD_DEV

#undef MUTE_CTRL_LEVEL_NORMAL

#define FM_BY_PASS
#define EXCHANGE_LINE_IN_CHANNEL	//交换LINE IN 通道

#define IPONE_DOCK_FUNC_ENABLE
#define IPONE_INDEPENDENT_MODE
#define IPHONE_TX_USE_P06
#define IPHONE_DETECT_USE_P04
#define IPHONE_DETECT_IN_USE
#define IPHONE_DOCKING_PRO
#define TURN_ON_MUSIC_WHEN_IPHONE_DOCK

#define INDEPENDENT_VOLUME_KEY

//#define USE_AMP_MODE_SELECT
//#define AMP_MODE_SELECT_PORT_USE_P10
//#define ONE_WIRE_TUNE_ENABLE


#define USE_GPIO_DETECT_EARPHONE_PLUGGED
#define EARPHONE_DETECT_USE_P11

#define USE_LONG_PLAY_KEY_TO_SWITCH_MODE


#define USE_LINE_IN_DETECT_FUNC
#define AUX_DETECT_USE_P03
#define AUX_DETECT_SHARE_WITH_IIC_SCL

#endif

#ifdef K000_XingChuang_x821_V003

#define ADKEY_USE_P07_PORT

#define NO_LED_DISPLAY
#define NO_PLAY_STATUS_LED

#define NOT_MOUNT_USB_SD_DEV

#undef MUTE_CTRL_LEVEL_NORMAL

#define FM_BY_PASS
#define EXCHANGE_LINE_IN_CHANNEL	//交换LINE IN 通道

#define IPONE_DOCK_FUNC_ENABLE
#define IPONE_INDEPENDENT_MODE
#define IPHONE_TX_USE_P06
#define IPHONE_DETECT_USE_P04
#define IPHONE_DETECT_IN_USE
#define IPHONE_DOCKING_PRO
#define TURN_ON_MUSIC_WHEN_IPHONE_DOCK

#define INDEPENDENT_VOLUME_KEY

#define USE_AMP_MODE_SELECT
#define AMP_MODE_SELECT_PORT_USE_P10
#define ONE_WIRE_TUNE_ENABLE

#endif


#ifdef K000_XingChuang_x821_V002

#define ADKEY_USE_P07_PORT
#define NO_PLAY_STATUS_LED

#ifdef LED_GPIO_DRV
#undef  LED_GPIO_DRV
#endif
#define USE_LCD_DRV_HT1621

#define BT_VOL_USE_NEXT_PREV_KEY
#define FM_BY_PASS
#define SWD_NEW_LCD_BOARD
#define DISP_MUSIC_TOTAL_FILE
#define XC_MINI_IR_REMOTE
#define USE_BT_ACTIVATED_PIN

#define BLUE_TOOTH_FUNC
#define BLUE_TOOTH_PATH_DIRECT_IN_PA
//#define USE_BT_GPIO_DETECTION
#define BT_DISP_CONNECT_TIME
#define BLUETOOTH_GPIO_CTRL
#define BLUE_TOOTH_INDEPENDENT_VOLUME
#define BLUE_TOOTH_DISP_VOL_DIR
#define BLUE_TOOTH_INDEPENDENT_VOLUME_KEY
#define FREQ_WITH_CH_NO_DISP
#define INDEPENDENT_KEY_TUNE_FREQ
#define INDEPENDENT_KEY_FAST_TUNE_FREQ
#define SEPARATED_FAST_FORDWORD_KEY
#define BLUE_TOOTH_NO_SYS_MUTE_CTRL
#define EXCHANGE_LINE_IN_CHANNEL	//交换LINE IN 通道
#define CUSTOMER_DEFINED_ADKEY_RESISTOR


#define PALY_MODE_USE_RAN_ONE_ALL
//#define IR_REMOTER_WITH_POWER_MUTE_PRINT
#define KEY_100_ENABLE
#define PLAY_MODE_NO_STR_DISP
#define SEMI_AUTO_SCAN_FREQ
#define IR_NEXT_PREV_HOLD_AUTO_SCAN
#define IR_NEXT_PREV_SHORT_ADJ_CH
#define INDEPENDENT_KEY_TUNE_FREQ

#define IPONE_DOCK_FUNC_ENABLE
#define IPONE_INDEPENDENT_MODE
#define IPHONE_TX_USE_P06
#define IPHONE_DETECT_USE_P04
#define IPHONE_DETECT_IN_USE
#define IPHONE_DOCKING_PRO
#define TURN_ON_MUSIC_WHEN_IPHONE_DOCK
#define TURN_OFF_IPOD_WHEN_LEAVE_IPHONE_DOCK

#define LED_STATUS_STOP_AT_VALID_STATION
#ifdef  MUTE_CTRL_LEVEL_NORMAL
#undef MUTE_CTRL_LEVEL_NORMAL
#endif
#ifdef  LED_CTRL_LEVEL_NORMAL
#undef LED_CTRL_LEVEL_NORMAL
#endif
#define DISP_PAU_STRING
#define USE_BAT_MANAGEMENT
#define NEW_BAT_ICON_DISP
#define CHARGER_DETECT_INDICATOR
#define DC_DETECT_USE_P33
#define DEFINE_LOWER_BAT_FULL_VOL

#define ONE_WIRE_TUNE_ENABLE
#define NEW_CUSTOMIZED_LED_METHOD
#define ADKEY_PLAY_SHORT_SCAN_FRE

#define USE_LINE_IN_DETECT_FUNC
#define AUX_DETECT_USE_P03

#define USE_SPECTRUM_PARTTERN

#endif

#ifdef K000_XingChuang_x821_V001

#define ADKEY_USE_P07_PORT

#ifdef LED_GPIO_DRV
#undef  LED_GPIO_DRV
#endif
#define LCD_GPIO_DRV

#define FM_BY_PASS

#define EXCHANGE_LINE_IN_CHANNEL	//交换LINE IN 通道
#define CUSTOMER_DEFINED_ADKEY_RESISTOR
//#define INDEPENDENT_VOLUME_KEY
#define IR_REMOTER_WITH_POWER_MUTE_PRINT
#define KEY_100_ENABLE

#define IPONE_DOCK_FUNC_ENABLE
#define IPONE_INDEPENDENT_MODE
#define IPHONE_TX_USE_P06
#define IPHONE_DETECT_USE_P04
#define IPHONE_DETECT_IN_USE
#define IPHONE_DOCKING_PRO
#define TURN_ON_MUSIC_WHEN_IPHONE_DOCK

#define LED_STATUS_STOP_AT_VALID_STATION
#ifdef  MUTE_CTRL_LEVEL_NORMAL
#undef MUTE_CTRL_LEVEL_NORMAL
#endif
#ifdef  LED_CTRL_LEVEL_NORMAL
#undef LED_CTRL_LEVEL_NORMAL
#endif

#define ONE_WIRE_TUNE_ENABLE
#define NEW_CUSTOMIZED_LED_METHOD
#define ADKEY_PLAY_SHORT_SCAN_FRE

#define USE_LINE_IN_DETECT_FUNC
#define AUX_DETECT_USE_P03

#define USE_SPECTRUM_PARTTERN

#define USE_BAT_MANAGEMENT
#define WKUP_PIN_USE_ENABLE
#endif

#ifdef K000_XingChuang_x819_V001

#define ADKEY_USE_P07_PORT

#define NO_LED_DISPLAY
#define FM_BY_PASS

#define EXCHANGE_LINE_IN_CHANNEL	//交换LINE IN 通道
#define CUSTOMER_DEFINED_ADKEY_RESISTOR
#define INDEPENDENT_VOLUME_KEY
#define IR_REMOTER_WITH_POWER_MUTE_PRINT
#define KEY_100_ENABLE

#define IPONE_DOCK_FUNC_ENABLE
#define IPONE_INDEPENDENT_MODE
#define IPHONE_TX_USE_P06
#define IPHONE_DETECT_USE_P04
#define IPHONE_DETECT_IN_USE
#define IPHONE_DOCKING_PRO
#define TURN_ON_MUSIC_WHEN_IPHONE_DOCK

#define LED_STATUS_STOP_AT_VALID_STATION
#ifdef  MUTE_CTRL_LEVEL_NORMAL
#undef MUTE_CTRL_LEVEL_NORMAL
#endif
#ifdef  LED_CTRL_LEVEL_NORMAL
#undef LED_CTRL_LEVEL_NORMAL
#endif

#define ONE_WIRE_TUNE_ENABLE
#define NEW_CUSTOMIZED_LED_METHOD
#define ADKEY_PLAY_SHORT_SCAN_FRE

#endif

#ifdef K000_ZhuoYue_003_V001

#ifdef IIC_GPIO_USE_P02_P03
#undef IIC_GPIO_USE_P02_P03
#endif
#define IIC_GPIO_USE_P00_P01
#ifdef MUTE_PORT_USE_P01
#undef  MUTE_PORT_USE_P01
#endif
#define MUTE_PORT_USE_P03

#ifdef LED_GPIO_DRV
#undef  LED_GPIO_DRV
#endif
#define LCD_GPIO_DRV

#define NO_PLAY_STATUS_LED
#define EXCHANGE_LINE_IN_CHANNEL	//交换LINE IN 通道
#define IPONE_DOCK_FUNC_ENABLE
#define IPONE_INDEPENDENT_MODE
#define ADKEY_PLAY_SHORT_SCAN_FRE
#define ADKEY_USE_P07_PORT
#define IPHONE_TX_USE_P06
#define TIME_FORCE_SHOW_ON_SCREEN
//#define PWR_CTRL_P04_KEY_P02
#define DONT_MOUNT_AUX_FUNC
#define SPECTRUM_FUNC_ENABLE
#define IPHONE_USE_LINE_IN_CHANNEL_AUX0

#define USE_RTC_FUNCTION
#define USE_RTC_TIME_ONLY
#define USE_RTC_ALARM_FUNCTION
//#define USE_SPECTRUM_PARTTERN
#endif

#ifdef K568_ZX_568_V002

#ifdef IIC_GPIO_USE_P02_P03
#undef IIC_GPIO_USE_P02_P03
#endif
#define IIC_GPIO_USE_P00_P01
#ifdef MUTE_PORT_USE_P01
#undef  MUTE_PORT_USE_P01
#endif
#define MUTE_PORT_USE_P03
#define EXCHANGE_LINE_IN_CHANNEL	//交换LINE IN 通道

#define ADKEY_PLAY_SHORT_SCAN_FRE
//#define VOLUME_DEFUALT		 30
#define LED_GPIO_PORT_CUSTOMERIZED
#define KEY_10_ENABLE
#define DISP_VOL_V_CHAR

#define NEW_CUSTOMED_VOLUME_DIVIDED_METHOD
#define DECODE_STOP_MODE_ENABLE
#define STOP_MODE_SHOW_STOP
#define IR_NEXT_PREV_SHORT_ADJ_CH
#define LINE_IN_PLAY_KEY_PAUSE
#define LINE_IN_PLAY_KEY_NO_PAUSE_ICON_INDICATOR

#define TURN_ON_PLAY_BREAK_POINT_MEM

#define USE_TWO_IR_REMOTE

#endif

#ifdef K568_ZX_568_V001

#ifdef IIC_GPIO_USE_P02_P03
#undef IIC_GPIO_USE_P02_P03
#endif
#define IIC_GPIO_USE_P00_P01
#ifdef MUTE_PORT_USE_P01
#undef  MUTE_PORT_USE_P01
#endif
#define MUTE_PORT_USE_P03
#define EXCHANGE_LINE_IN_CHANNEL	//交换LINE IN 通道

#define ADKEY_PLAY_SHORT_SCAN_FRE
//#define VOLUME_DEFUALT		 30
#define LED_GPIO_PORT_CUSTOMERIZED

#define DISP_VOL_V_CHAR

#define NEW_CUSTOMED_VOLUME_DIVIDED_METHOD
#define DECODE_STOP_MODE_ENABLE
#define STOP_MODE_SHOW_STOP
#define IR_NEXT_PREV_SHORT_ADJ_CH
#define LINE_IN_PLAY_KEY_PAUSE
#define LINE_IN_PLAY_KEY_NO_PAUSE_ICON_INDICATOR

#endif

#ifdef K568_JinRui_568_V001

#ifdef IIC_GPIO_USE_P02_P03
#undef IIC_GPIO_USE_P02_P03
#endif
#define IIC_GPIO_USE_P00_P01
#ifdef MUTE_PORT_USE_P01
#undef  MUTE_PORT_USE_P01
#endif
#define MUTE_PORT_USE_P03
#define EXCHANGE_LINE_IN_CHANNEL	//交换LINE IN 通道

#define ADKEY_PLAY_SHORT_SCAN_FRE

//#define USE_GPIO_DETECT_EARPHONE_PLUGGED
//#define USE_USB_AUDIO
#define NEW_CUSTOMED_VOLUME_DIVIDED_METHOD
#define DECODE_STOP_MODE_ENABLE
#define STOP_MODE_SHOW_STOP
#define IR_NEXT_PREV_SHORT_ADJ_CH
#define LINE_IN_PLAY_KEY_PAUSE
#define LINE_IN_PLAY_KEY_NO_PAUSE_ICON_INDICATOR

#endif

#ifdef K566_SWD_566_V001

#define EXCHANGE_FM_MP3_ICON
//#define EXCHANGE_LINE_IN_CHANNEL	//交换LINE IN 通道

#define ADKEY_PLAY_SHORT_SCAN_FRE
#define MUTE_ON_FLASH_WHOLE_SCREEN
#define IR_PLAY_KEY_SCAN_FREQ_DISABLE
#define MP3_MODE_EQ_DOWN_DO_NOTHING
#define DISP_VOL_V_CHAR

#define LINE_IN_PLAY_KEY_PAUSE

#define NO_PLAY_STATUS_LED
//#define USE_USB_AUDIO
#define NEW_CUSTOMED_VOLUME_DIVIDED_METHOD
#define DECODE_STOP_MODE_ENABLE
#define STOP_MODE_SHOW_STOP
#define IR_NEXT_PREV_SHORT_ADJ_CH
#define LINE_IN_PLAY_KEY_PAUSE
#define LINE_IN_PLAY_KEY_NO_PAUSE_ICON_INDICATOR
#define IR_USER_CODE_0x7F80
#define EQ_DOWN_SCAN_ALL

#endif

#ifdef K566_JLH_566_V001

#ifdef IIC_GPIO_USE_P02_P03
//#undef IIC_GPIO_USE_P02_P03
#endif
//#define IIC_GPIO_USE_P00_P01
#ifdef MUTE_PORT_USE_P01
//#undef  MUTE_PORT_USE_P01
#endif
//#define MUTE_PORT_USE_P03
//#define EXCHANGE_LINE_IN_CHANNEL	//交换LINE IN 通道

#define ADKEY_PLAY_SHORT_SCAN_FRE

//#define USE_GPIO_DETECT_EARPHONE_PLUGGED
#define NO_PLAY_STATUS_LED
//#define USE_USB_AUDIO
#define NEW_CUSTOMED_VOLUME_DIVIDED_METHOD
#define DECODE_STOP_MODE_ENABLE
#define STOP_MODE_SHOW_STOP
#define IR_NEXT_PREV_SHORT_ADJ_CH
#define LINE_IN_PLAY_KEY_PAUSE
#define LINE_IN_PLAY_KEY_NO_PAUSE_ICON_INDICATOR
#define IR_USER_CODE_0x7F80
#define EQ_DOWN_SCAN_ALL

#endif

#ifdef K566_JinRui_566_V001

#ifdef IIC_GPIO_USE_P02_P03
//#undef IIC_GPIO_USE_P02_P03
#endif
//#define IIC_GPIO_USE_P00_P01
#ifdef MUTE_PORT_USE_P01
//#undef  MUTE_PORT_USE_P01
#endif
//#define MUTE_PORT_USE_P03
//#define EXCHANGE_LINE_IN_CHANNEL	//交换LINE IN 通道

#define ADKEY_PLAY_SHORT_SCAN_FRE

//#define USE_GPIO_DETECT_EARPHONE_PLUGGED
#define NO_PLAY_STATUS_LED
//#define USE_USB_AUDIO
#define NEW_CUSTOMED_VOLUME_DIVIDED_METHOD
#define DECODE_STOP_MODE_ENABLE
#define STOP_MODE_SHOW_STOP
#define IR_NEXT_PREV_SHORT_ADJ_CH
#define LINE_IN_PLAY_KEY_PAUSE
#define LINE_IN_PLAY_KEY_NO_PAUSE_ICON_INDICATOR

#endif


#ifdef K586_DCX_586_V001

#define PROTECT_P17_FROM_LED_SCAN

#ifdef IIC_GPIO_USE_P02_P03
#undef IIC_GPIO_USE_P02_P03
#endif
#define IIC_GPIO_USE_P00_P01
#ifdef MUTE_PORT_USE_P01
#undef  MUTE_PORT_USE_P01
#endif
#define MUTE_PORT_USE_P03

#define EXCHANGE_LINE_IN_CHANNEL	//交换LINE IN 通道

#define ADKEY_PLAY_SHORT_SCAN_FRE
#define ALARM_ADJ_VOL
#define RTC_SETTING_NO_CYC
#define PWR_OFF_NO_RESP_WHEN_CHARGER_PLUGGED
#define FULL_BAT_DISP_ALL_ICON
#if 1
#define LED_USE_PLAY_MODE
#define PWR_OFF_WAKEUP_FUNC

#define LED_USE_ROUND_LED

#define USE_POWER_KEY
#define PWR_CTRL_WKUP
//#define PWR_CTRL_P02
#define USE_ONLY_POWER_HOLD_CTRL
#define USE_PWR_KEY_LONG_PWR_ON
#define PWR_ON_DELAY_1_SECOND
#define DC_HW_POWER_UP
#endif

#undef USE_QN8035_FM

#define POWE_KEY_PLAY_KEY_IN_ONE_KEY
#define CUSTOMER_DEFINED_ADKEY_RESISTOR
#define NO_PLAY_STATUS_LED

#define TWO_ADKEY_ENABLE
#define TWO_ADKEY_USE_PORT_P07
#define INDEPENDENT_VOLUME_KEY

#define SEMI_AUTO_SCAN_FREQ
#define USE_POWER_KEY_SHORT_SCAN
#define ADKEY_NEXT_PREV_HOLD_AUTO_SCAN
#define NOT_USE_LINE_IN_FUNC

#define USE_BAT_MANAGEMENT
#define BAT_LEVEL_LED_ICON_IND
#define CHARGER_DETECT_INDICATOR
#define CHARGER_DET_USE_P17
#define CHARGER_FLASH_TYPE_1
#define LOW_VOLT_SPARK_BAT_ICON

//#define DISP_PAUS_STRING
#define DISP_VOL_V_CHAR
#define DISP_PC_STR

#define USE_USB_AUDIO

#define USE_RTC_FUNCTION
#define USE_RTC_TIME_ONLY
#define USE_RTC_ALARM_FUNCTION
#define USE_RTC_ALM_CUSTOM_INIT

#define ALM_UP_DISP_TIME
#define SYS_POWER_ON_DEFAULT_RTC_MODE
#define USE_TIMER_POWER_OFF_FUNC
#define USE_SNOOZE_FUNC
#define MINI_DIGIT_BOX
#define ADJ_TIME_USE_VOL_KEY
#define ALM_ON_FLASH_SCR
#define RTC_ADJ_VOL
#define MP3_DISP_LOAD_STRING
#define USE_GPIO_DETECT_EARPHONE_PLUGGED
#define EARPHONE_DETECT_USE_P04
#define MP3_PUASE_FLASH_FIGURE
#endif

#ifdef K585_YJH_585_V001

#define LED_USE_PLAY_MODE
#define USE_BAT_MANAGEMENT

#ifdef IIC_GPIO_USE_P02_P03
#undef IIC_GPIO_USE_P02_P03
#endif
#define IIC_GPIO_USE_P00_P01
#ifdef MUTE_PORT_USE_P01
#undef  MUTE_PORT_USE_P01
#endif
#define MUTE_PORT_USE_P03

#define EXCHANGE_LINE_IN_CHANNEL	//交换LINE IN 通道

#define ADKEY_PLAY_SHORT_SCAN_FRE

#define USE_POWER_KEY
#define PWR_CTRL_P02_KEY_P04
#define USE_ONLY_POWER_HOLD_CTRL
#define USE_PWR_KEY_LONG_PWR_ON

#define POWE_KEY_PLAY_KEY_IN_ONE_KEY
#define CUSTOMER_DEFINED_ADKEY_RESISTOR
#define NO_PLAY_STATUS_LED
#define TWO_ADKEY_ENABLE
#define TWO_ADKEY_USE_PORT_P07
#define INDEPENDENT_VOLUME_KEY
#define SEMI_AUTO_SCAN_FREQ
#define USE_POWER_KEY_SHORT_SCAN
#define ADKEY_NEXT_PREV_HOLD_AUTO_SCAN
#define NOT_USE_LINE_IN_FUNC
#define USE_USB_AUDIO

#define USE_RTC_FUNCTION
#define USE_RTC_ALARM_FUNCTION
#endif


#ifdef K733_JM_733_V001

#ifdef IIC_GPIO_USE_P02_P03
#undef IIC_GPIO_USE_P02_P03
#endif
#define IIC_GPIO_USE_P00_P01
#ifdef MUTE_PORT_USE_P01
#undef  MUTE_PORT_USE_P01
#endif
#define MUTE_PORT_USE_P03
#define EXCHANGE_LINE_IN_CHANNEL	//交换LINE IN 通道
#define INDEPENDENT_VOLUME_KEY
#define ADKEY_PLAY_SHORT_SCAN_FRE
#define SEMI_AUTO_SCAN_FREQ
#define ADKEY_NEXT_PREV_HOLD_AUTO_SCAN
#define NO_PLAY_STATUS_LED
#define ROUND_LED_USE_OFFEN
#define USE_USB_AUDIO

#endif
#ifdef K731_YJH_731_V001

#ifdef IIC_GPIO_USE_P02_P03
#undef IIC_GPIO_USE_P02_P03
#endif
#define IIC_GPIO_USE_P00_P01
#ifdef MUTE_PORT_USE_P01
#undef  MUTE_PORT_USE_P01
#endif
#define MUTE_PORT_USE_P03
#define EXCHANGE_LINE_IN_CHANNEL	//交换LINE IN 通道

#define ADKEY_PLAY_SHORT_SCAN_FRE

#define USE_GPIO_DETECT_EARPHONE_PLUGGED
#define NO_PLAY_STATUS_LED
#define USE_USB_AUDIO
#define LED_GPIO_PORT_CUSTOMERIZED
#define NO_VOLUME_LIMITE

#endif
#ifdef K731_YJH_820_V001

#ifdef IIC_GPIO_USE_P02_P03
#undef IIC_GPIO_USE_P02_P03
#endif
#define IIC_GPIO_USE_P00_P01
#ifdef MUTE_PORT_USE_P01
#undef  MUTE_PORT_USE_P01
#endif
#define MUTE_PORT_USE_P03
#define EXCHANGE_LINE_IN_CHANNEL	//交换LINE IN 通道

#define ADKEY_PLAY_SHORT_SCAN_FRE

#define USE_GPIO_DETECT_EARPHONE_PLUGGED
#define NO_PLAY_STATUS_LED
#define USE_USB_AUDIO
#define LED_GPIO_PORT_CUSTOMERIZED
#define NO_VOLUME_LIMITE

#endif

#ifdef K000_JLH_309F_V001

#define LED_USE_PLAY_MODE
#define EXCHANGE_LINE_IN_CHANNEL		//交换LINE IN 通道

#define ADKEY_USE_P07_PORT
#define NO_PLAY_STATUS_LED
#define EXCHANGE_FM_AUX_PRIO
#define VOLUME_DEFUALT	32
#define VOLUME_CUSTOMER_DEFINE_32

#define SEMI_AUTO_SCAN_FREQ
#define ADKEY_NEXT_PREV_HOLD_AUTO_SCAN
#define ADKEY_NEXT_ADJST_FREQ
#define IR_NEXT_PREV_HOLD_AUTO_SCAN
#define PLAY_MODE_USE_REP_ONE_ALL
#define LED_GPIO_PORT_CUSTOMERIZED
#define CUSTOMER_DEFINED_ADKEY_RESISTOR
#define USE_IR_VPP_PORT_FORDETECTION
#define KEY_100_ENABLE
#define DEFAULT_GO_TO_FM
#endif

#ifdef K763_JinYiHeLi_763_V001

#ifdef IIC_GPIO_USE_P02_P03
#undef IIC_GPIO_USE_P02_P03
#endif
#define IIC_GPIO_USE_P00_P01
#ifdef MUTE_PORT_USE_P01
#undef  MUTE_PORT_USE_P01
#endif
#define MUTE_PORT_USE_P03

#define EXCHANGE_LINE_IN_CHANNEL	//交换LINE IN 通道

#define ADKEY_PLAY_SHORT_SCAN_FRE

#define NO_PLAY_STATUS_LED

//#define LED_USE_ROUND_LED
#define LED_USE_PLAY_MODE
#define USE_BAT_MANAGEMENT
#define INDEPENDENT_VOLUME_KEY

#define USE_GPIO_DETECT_EARPHONE_PLUGGED


#define USB_SD_PLAY_INFO_DIV

//#define LINE_IN_PLAY_KEY_PAUSE
//#define LINE_IN_PLAY_KEY_NO_PAUSE_ICON_INDICATOR
//#define USE_POWER_KEY_FOR_AUX_PLAY
#endif

#ifdef K762_JinYiHeLi_762_V001

#ifdef IIC_GPIO_USE_P02_P03
#undef IIC_GPIO_USE_P02_P03
#endif
#define IIC_GPIO_USE_P00_P01
#ifdef MUTE_PORT_USE_P01
#undef  MUTE_PORT_USE_P01
#endif
#define MUTE_PORT_USE_P03
#define EXCHANGE_LINE_IN_CHANNEL	//交换LINE IN 通道

#define ADKEY_PLAY_SHORT_SCAN_FRE

#define NO_PLAY_STATUS_LED
#define TWO_ADKEY_ENABLE
#define TWO_ADKEY_USE_PORT_P04

#define POWER_KEY_LONG_POWER_OFF
#define POWE_KEY_PLAY_KEY_IN_ONE_KEY
#define USE_POWER_KEY_SHORT_SCAN

#define CUSTOMER_DEFINED_ADKEY_RESISTOR
//#define LED_USE_ROUND_LED
#define LED_USE_PLAY_MODE
#define USE_BAT_MANAGEMENT
#define INDEPENDENT_VOLUME_KEY

#define USE_GPIO_DETECT_EARPHONE_PLUGGED

//#define USE_LINE_IN_DETECT_FUNC
//#define AUX_DETECT_USE_P07
#define USB_SD_PLAY_INFO_DIV

#define LINE_IN_PLAY_KEY_PAUSE
#define LINE_IN_PLAY_KEY_NO_PAUSE_ICON_INDICATOR
#define USE_POWER_KEY_FOR_AUX_PLAY
#endif

#ifdef K1007_JinYiHeLi_1007_V001

#ifdef IIC_GPIO_USE_P02_P03
#undef IIC_GPIO_USE_P02_P03
#endif
#define IIC_GPIO_USE_P00_P01

#ifdef MUTE_PORT_USE_P01
#undef  MUTE_PORT_USE_P01
#endif
#define MUTE_PORT_USE_P03
#define EXCHANGE_LINE_IN_CHANNEL	//交换LINE IN 通道

#define ADKEY_PLAY_SHORT_SCAN_FRE

#define LED_GPIO_PORT_CUSTOMERIZED
#define NO_PLAY_STATUS_LED
#define TWO_ADKEY_ENABLE
#define TWO_ADKEY_USE_PORT_P04

#define USE_POWER_KEY
#define PWR_CTRL_P02_KEY_P04
#define USE_ONLY_POWER_HOLD_CTRL

#define POWER_KEY_LONG_POWER_OFF
#define POWE_KEY_PLAY_KEY_IN_ONE_KEY
#define USE_POWER_KEY_SHORT_SCAN

#define CUSTOMER_DEFINED_ADKEY_RESISTOR
//#define LED_USE_ROUND_LED
#define LED_USE_PLAY_MODE
#define USE_BAT_MANAGEMENT
#define INDEPENDENT_VOLUME_KEY

#define USE_GPIO_DETECT_EARPHONE_PLUGGED

#define FM_USE_KT0830EG
//#define AUX_DETECT_USE_P07
#define USB_SD_PLAY_INFO_DIV

#define LINE_IN_PLAY_KEY_PAUSE
#define LINE_IN_PLAY_KEY_NO_PAUSE_ICON_INDICATOR
#define USE_POWER_KEY_FOR_AUX_PLAY
#endif

#ifdef K756_JinYiHeLi_756_V001

#ifdef IIC_GPIO_USE_P02_P03
#undef IIC_GPIO_USE_P02_P03
#endif
#define IIC_GPIO_USE_P00_P01
#ifdef MUTE_PORT_USE_P01
#undef  MUTE_PORT_USE_P01
#endif
#define MUTE_PORT_USE_P03
#define EXCHANGE_LINE_IN_CHANNEL	//交换LINE IN 通道

#define ADKEY_PLAY_SHORT_SCAN_FRE

#define NO_PLAY_STATUS_LED
#define TWO_ADKEY_ENABLE
#define TWO_ADKEY_USE_PORT_P04

#define POWER_KEY_LONG_POWER_OFF
#define POWE_KEY_PLAY_KEY_IN_ONE_KEY
#define USE_POWER_KEY_SHORT_SCAN

#define CUSTOMER_DEFINED_ADKEY_RESISTOR
//#define LED_USE_ROUND_LED
#define LED_USE_PLAY_MODE
#define USE_BAT_MANAGEMENT
#define INDEPENDENT_VOLUME_KEY

#define USE_GPIO_DETECT_EARPHONE_PLUGGED

//#define USE_LINE_IN_DETECT_FUNC
//#define AUX_DETECT_USE_P07
#define USB_SD_PLAY_INFO_DIV

#define LINE_IN_PLAY_KEY_PAUSE
#define LINE_IN_PLAY_KEY_NO_PAUSE_ICON_INDICATOR
#define USE_POWER_KEY_FOR_AUX_PLAY
#endif

#ifdef K737_JinYiHeLi_737_V001

#ifdef IIC_GPIO_USE_P02_P03
#undef IIC_GPIO_USE_P02_P03
#endif
#define IIC_GPIO_USE_P00_P01
#ifdef MUTE_PORT_USE_P01
#undef  MUTE_PORT_USE_P01
#endif
#define MUTE_PORT_USE_P03
#define EXCHANGE_LINE_IN_CHANNEL	//交换LINE IN 通道

#define ADKEY_PLAY_SHORT_SCAN_FRE

#define USE_POWER_KEY
#define PWR_CTRL_P02_KEY_P04
#define USE_ONLY_POWER_HOLD_CTRL
#define USE_PWR_KEY_LONG_PWR_ON

#define POWE_KEY_PLAY_KEY_IN_ONE_KEY
#define CUSTOMER_DEFINED_ADKEY_RESISTOR
#define LED_USE_ROUND_LED
#define LED_USE_PLAY_MODE
#define USE_POWER_KEY_SHORT_SCAN
#define USE_BAT_MANAGEMENT

#define USE_LINE_IN_DETECT_FUNC
#define AUX_DETECT_USE_P07
#define NO_PLAY_STATUS_LED
#define LINE_IN_PLAY_KEY_PAUSE
#define LINE_IN_PLAY_KEY_NO_PAUSE_ICON_INDICATOR
#define USE_POWER_KEY_FOR_AUX_PLAY
#define NEW_SD_DETECT_MOD
#define USB_SD_PLAY_INFO_DIV

#endif

#ifdef K728_SUOERSI_728_V001

#ifdef IIC_GPIO_USE_P02_P03
#undef IIC_GPIO_USE_P02_P03
#endif
#define IIC_GPIO_USE_P00_P01
#ifdef MUTE_PORT_USE_P01
#undef  MUTE_PORT_USE_P01
#endif
#define MUTE_PORT_USE_P03
#define EXCHANGE_LINE_IN_CHANNEL	//交换LINE IN 通道

#define ADKEY_PLAY_SHORT_SCAN_FRE

#define USE_POWER_KEY
#define PWR_CTRL_P02_KEY_P04
#define USE_ONLY_POWER_HOLD_CTRL
#define POWE_KEY_PLAY_KEY_IN_ONE_KEY
#define CUSTOMER_DEFINED_ADKEY_RESISTOR
#define LED_USE_ROUND_LED
#define USE_POWER_KEY_SHORT_SCAN

#define USE_LINE_IN_DETECT_FUNC
#define AUX_DETECT_USE_P07
#define NO_PLAY_STATUS_LED
#define FM_MAX_CHANNAL_50
#define USE_BAT_MANAGEMENT
#endif

#ifdef K745_SUOERSI_745_V001

#ifdef IIC_GPIO_USE_P02_P03
#undef IIC_GPIO_USE_P02_P03
#endif
#define IIC_GPIO_USE_P00_P01
#ifdef MUTE_PORT_USE_P01
#undef  MUTE_PORT_USE_P01
#endif
#define MUTE_PORT_USE_P03
#define EXCHANGE_LINE_IN_CHANNEL	//交换LINE IN 通道

#define ADKEY_PLAY_SHORT_SCAN_FRE

#define USE_POWER_KEY
#define PWR_CTRL_P04_KEY_P02
#define POWE_KEY_PLAY_KEY_IN_ONE_KEY	//PLAY POWER 共用一个按键
#define POWER_KEY_ON_WAIT_FOR_3_SEC
#define USE_POWER_KEY_SHORT_SCAN

#define NO_PLAY_STATUS_LED
#define FM_MAX_CHANNAL_50
#define USE_BAT_MANAGEMENT
#define CHARGER_DETECT_INDICATOR
#define CHARGER_FLASH_TYPE_1

#endif

#ifdef K723_LUOMAO_723_V001

#ifdef IIC_GPIO_USE_P02_P03
#undef IIC_GPIO_USE_P02_P03
#endif
#define IIC_GPIO_USE_P00_P01
#ifdef MUTE_PORT_USE_P01
#undef  MUTE_PORT_USE_P01
#endif
#define MUTE_PORT_USE_P03
#define EXCHANGE_LINE_IN_CHANNEL	//交换LINE IN 通道

#define ADKEY_PLAY_SHORT_SCAN_FRE

#define USE_POWER_KEY
#define PWR_CTRL_P04_KEY_P02
#define USE_GPIO_DETECT_EARPHONE_PLUGGED
#define USE_POWER_KEY_TO_SWITCH_MODE
#define USE_USB_AUDIO

#define USE_BAT_MANAGEMENT
#define CHARGER_DETECT_INDICATOR
#define CHARGER_FLASH_TYPE_1
#define DEFAULT_GO_TO_IDLE

#endif

#ifdef K101_TianCheng_101_V001
#define ADKEY_PLAY_SHORT_SCAN_FRE
#define LED_USE_PLAY_MODE
#define MUTE_PORT_USE_P01

#define SEMI_AUTO_SCAN_FREQ
#define VOLUME_DEFUALT 25
#define DEFAULT_GO_TO_AUX
#define TianCheng_Remote
#define LED_REVERSE_VIEW
//#define COMMON_CATHODE
#define SEMI_AUTO_SCAN_FREQ
#define ADKEY_NEXT_PREV_HOLD_AUTO_SCAN
#endif

#ifdef K321_Zhuoxing_321_LCD_V001

#ifdef IIC_GPIO_USE_P02_P03
#undef IIC_GPIO_USE_P02_P03
#endif
#define IIC_GPIO_USE_P00_P01
#ifdef MUTE_PORT_USE_P01
#undef  MUTE_PORT_USE_P01
#endif

#ifdef LED_GPIO_DRV
#undef  LED_GPIO_DRV
#endif
#define LCD_GPIO_DRV
#define MUTE_PORT_USE_P03
#define EXCHANGE_LINE_IN_CHANNEL	//交换LINE IN 通道

#define ADKEY_PLAY_SHORT_SCAN_FRE

#define USE_POWER_KEY
#define PWR_CTRL_P04_KEY_P02

#endif

#ifdef K321_Zhuoxing_321_LED_V001

#ifdef IIC_GPIO_USE_P02_P03
#undef IIC_GPIO_USE_P02_P03
#endif
#define IIC_GPIO_USE_P00_P01
#ifdef MUTE_PORT_USE_P01
#undef  MUTE_PORT_USE_P01
#endif
#define MUTE_PORT_USE_P03
#define EXCHANGE_LINE_IN_CHANNEL	//交换LINE IN 通道

#define ADKEY_PLAY_SHORT_SCAN_FRE

#define USE_POWER_KEY
#define PWR_CTRL_P04_KEY_P02

#endif

#ifdef K716_RiYueTong_716_V001

#ifdef IIC_GPIO_USE_P02_P03
#undef IIC_GPIO_USE_P02_P03
#endif
#define IIC_GPIO_USE_P00_P01
#ifdef MUTE_PORT_USE_P01
#undef  MUTE_PORT_USE_P01
#endif
#define MUTE_PORT_USE_P03
#define EXCHANGE_LINE_IN_CHANNEL	//交换LINE IN 通道
#define USE_GPIO_DETECT_EARPHONE_PLUGGED
#define USE_LONG_PLAY_KEY_TO_SWITCH_MODE
#define ADKEY_PLAY_SHORT_SCAN_FRE
#define _KEY_TONE_ENABEL_
#endif


#ifdef K720_YJH_720_V001

#ifdef IIC_GPIO_USE_P02_P03
#undef IIC_GPIO_USE_P02_P03
#endif
#define IIC_GPIO_USE_P00_P01
#ifdef MUTE_PORT_USE_P01
#undef  MUTE_PORT_USE_P01
#endif

#define MUTE_PORT_USE_P03
#define EXCHANGE_LINE_IN_CHANNEL	//交换LINE IN 通道

#define ADKEY_PLAY_SHORT_SCAN_FRE
#define USE_GPIO_DETECT_EARPHONE_PLUGGED
#define USE_POWER_KEY
#define PWR_CTRL_P04_KEY_P02
#define FM_USE_KT0830EG
#define POWE_KEY_PLAY_KEY_IN_ONE_KEY	//PLAY POWER 共用一个按键
#define INDEPENDENT_VOLUME_KEY
#define USE_POWER_KEY_SHORT_SCAN

#endif

#ifdef K719_YJH_719_V001

#ifdef IIC_GPIO_USE_P02_P03
#undef IIC_GPIO_USE_P02_P03
#endif
#define IIC_GPIO_USE_P00_P01
#ifdef MUTE_PORT_USE_P01
#undef  MUTE_PORT_USE_P01
#endif
#define MUTE_PORT_USE_P03
#define EXCHANGE_LINE_IN_CHANNEL	//交换LINE IN 通道

#define ADKEY_PLAY_SHORT_SCAN_FRE
#define USE_GPIO_DETECT_EARPHONE_PLUGGED


#endif
#ifdef K693_YJH_693_V001

#ifdef IIC_GPIO_USE_P02_P03
#undef IIC_GPIO_USE_P02_P03
#endif
#define IIC_GPIO_USE_P00_P01
#ifdef MUTE_PORT_USE_P01
#undef  MUTE_PORT_USE_P01
#endif
#define MUTE_PORT_USE_P03
#define EXCHANGE_LINE_IN_CHANNEL	//交换LINE IN 通道

#define ADKEY_PLAY_SHORT_SCAN_FRE
#define VOLUME_CUSTOMER_DEFINE_16

#endif


#ifdef K668_YJH_815_V001

#ifdef IIC_GPIO_USE_P02_P03
#undef IIC_GPIO_USE_P02_P03
#endif
#define IIC_GPIO_USE_P00_P01
#ifdef MUTE_PORT_USE_P01
#undef  MUTE_PORT_USE_P01
#endif
#define MUTE_PORT_USE_P03
#define EXCHANGE_LINE_IN_CHANNEL	//交换LINE IN 通道

#define ADKEY_PLAY_SHORT_SCAN_FRE
#define USE_LINE_IN_DETECT_FUNC	//打开此宏来启动LINE IN 检测功能
#define AUX_DETECT_USE_P02
#define VOLUME_CUSTOMER_DEFINE
#define MAX_VOL_SHOW 16
#endif

#ifdef K801_DingChuangXin_801_V001

#ifdef IIC_GPIO_USE_P02_P03
#undef IIC_GPIO_USE_P02_P03
#endif
#define IIC_GPIO_USE_P00_P01
#ifdef MUTE_PORT_USE_P01
#undef  MUTE_PORT_USE_P01
#endif
#define MUTE_PORT_USE_P03
#define EXCHANGE_LINE_IN_CHANNEL	//交换LINE IN 通道

#define ADKEY_PLAY_SHORT_SCAN_FRE
#define USE_GPIO_DETECT_EARPHONE_PLUGGED

#define INDEPENDENT_VOLUME_KEY
#define LED_USE_1X888
#define USE_LONG_PLAY_KEY_TO_SWITCH_MODE

#endif

#ifdef K812_DingChuangXin_D903_V001

#ifdef IIC_GPIO_USE_P02_P03
#undef IIC_GPIO_USE_P02_P03
#endif
#define IIC_GPIO_USE_P00_P01
#ifdef MUTE_PORT_USE_P01
#undef  MUTE_PORT_USE_P01
#endif
#define MUTE_PORT_USE_P03
#define EXCHANGE_LINE_IN_CHANNEL	//交换LINE IN 通道

//#define ADKEY_PLAY_SHORT_SCAN_FRE
#define USE_LINE_IN_DETECT_FUNC	//打开此宏来启动LINE IN 检测功能
#define AUX_DETECT_USE_P02

#endif


#ifdef K686_ZhengYang_686_V001

#ifdef LED_GPIO_DRV
#undef LED_GPIO_DRV
#endif
#define LCD_GPIO_DRV				//GPIO直接驱动LCD

#ifdef IIC_GPIO_USE_P02_P03
#undef IIC_GPIO_USE_P02_P03
#endif
#define IIC_GPIO_USE_P00_P01
#ifdef MUTE_PORT_USE_P01
#undef  MUTE_PORT_USE_P01
#endif
#define MUTE_PORT_USE_P03
#define EXCHANGE_LINE_IN_CHANNEL	//交换LINE IN 通道

#define ADKEY_PLAY_SHORT_SCAN_FRE

#define USE_POWER_KEY
#define PWR_CTRL_P04_KEY_P02
#define POWE_KEY_PLAY_KEY_IN_ONE_KEY	//PLAY POWER 共用一个按键

#define USE_POWER_KEY_SHORT_SCAN

#define USE_LINE_IN_DETECT_FUNC	//打开此宏来启动LINE IN 检测功能
#define AUX_DETECT_USE_P07
#define NO_PLAY_STATUS_LED

#define NEW_VOLUME_KEY_FEATURE
#define VOLUME_DEFUALT 28

#define USE_RTC_FUNCTION

#define USE_RTC_TIME_ONLY

#endif

#ifdef K565_FXK_565_V001

#ifdef IIC_GPIO_USE_P02_P03
#undef IIC_GPIO_USE_P02_P03
#endif
#define IIC_GPIO_USE_P00_P01
#ifdef MUTE_PORT_USE_P01
#undef  MUTE_PORT_USE_P01
#endif
#define MUTE_PORT_USE_P03
#define PLAY_STATUS_LED_P04
#define ADKEY_USE_P07_PORT

#define EXCHANGE_LINE_IN_CHANNEL	//交换LINE IN 通道

#define ADKEY_PLAY_SHORT_SCAN_FRE
#define FM_BY_PASS

#define IPONE_INDEPENDENT_MODE
#define IPONE_DOCK_FUNC_ENABLE
#define IPHONE_TX_USE_P06
//#define IPHONE_DETECT_USE_TX
#define IPHONE_CTRL_FAKE
//#define IPHONE_PP_FLASH

#endif
#ifdef K573_AOKAILIN_812_V001

#ifdef IIC_GPIO_USE_P02_P03
#undef IIC_GPIO_USE_P02_P03
#endif
#define IIC_GPIO_USE_P00_P01
#ifdef MUTE_PORT_USE_P01
#undef  MUTE_PORT_USE_P01
#endif
#define MUTE_PORT_USE_P03
#define EXCHANGE_LINE_IN_CHANNEL	//交换LINE IN 通道

#define ADKEY_PLAY_SHORT_SCAN_FRE
#define NEW_SD_DETECT_MOD
//#define JOG_STICK_FUNC

#endif

#ifdef K572_AOKAILIN_811_V001

#define ADKEY_PLAY_SHORT_SCAN_FRE
#define NEW_SD_DETECT_MOD
#define AUX_MODE_HOT_KEY_ENABLE
#endif

#ifdef K709_AOKAILIN_709_V001

#ifdef IIC_GPIO_USE_P02_P03
#undef IIC_GPIO_USE_P02_P03
#endif
#define IIC_GPIO_USE_P00_P01
#ifdef MUTE_PORT_USE_P01
#undef  MUTE_PORT_USE_P01
#endif
#define MUTE_PORT_USE_P03
#define EXCHANGE_LINE_IN_CHANNEL	//交换LINE IN 通道

#define ADKEY_PLAY_SHORT_SCAN_FRE
#define NOT_USE_LINE_IN_FUNC

#endif


#ifdef K704_JM_502_V001

#ifdef IIC_GPIO_USE_P02_P03
#undef IIC_GPIO_USE_P02_P03
#endif
#define IIC_GPIO_USE_P00_P01
#ifdef MUTE_PORT_USE_P01
#undef  MUTE_PORT_USE_P01
#endif
#define MUTE_PORT_USE_P03
#define EXCHANGE_LINE_IN_CHANNEL	//交换LINE IN 通道

#define ADKEY_PLAY_SHORT_SCAN_FRE

#endif

#ifdef K704_JM_503_V001

#ifdef IIC_GPIO_USE_P02_P03
#undef IIC_GPIO_USE_P02_P03
#endif
#define IIC_GPIO_USE_P00_P01
#ifdef MUTE_PORT_USE_P01
#undef  MUTE_PORT_USE_P01
#endif
#define MUTE_PORT_USE_P03
#define EXCHANGE_LINE_IN_CHANNEL	//交换LINE IN 通道

#define ADKEY_PLAY_SHORT_SCAN_FRE
#define USE_GPIO_DETECT_EARPHONE_PLUGGED
#define EARPHONE_DETECT_USE_P02
#define INDEPENDENT_EARPHONE_DETECT_GPIO

#define ROUND_LED_USE_OFFEN

#endif


#ifdef K317_ZhuoXing_317_V001

#ifdef IIC_GPIO_USE_P02_P03
#undef IIC_GPIO_USE_P02_P03
#endif
#define IIC_GPIO_USE_P00_P01
#ifdef MUTE_PORT_USE_P01
#undef  MUTE_PORT_USE_P01
#endif
#define MUTE_PORT_USE_P03
#define EXCHANGE_LINE_IN_CHANNEL	//交换LINE IN 通道

#define ADKEY_PLAY_SHORT_SCAN_FRE
#define USE_LINE_IN_DETECT_FUNC	//打开此宏来启动LINE IN 检测功能
#define AUX_DETECT_USE_P02

#endif

#ifdef K202_JiaMei_202_V001

#ifdef IIC_GPIO_USE_P02_P03
#undef IIC_GPIO_USE_P02_P03
#endif
#define IIC_GPIO_USE_P00_P01
#ifdef MUTE_PORT_USE_P01
#undef  MUTE_PORT_USE_P01
#endif
#define MUTE_PORT_USE_P03
#define EXCHANGE_LINE_IN_CHANNEL	//交换LINE IN 通道

#define ADKEY_PLAY_SHORT_SCAN_FRE

#define USE_POWER_KEY
#define PWR_CTRL_P04_KEY_P02
#define POWE_KEY_PLAY_KEY_IN_ONE_KEY	//PLAY POWER 共用一个按键
//#define POWER_KEY_ON_WAIT_FOR_3_SEC
#define USE_POWER_KEY_SHORT_SCAN
#endif

#ifdef K316_ZhuoXing_316_V001

#ifdef IIC_GPIO_USE_P02_P03
#undef IIC_GPIO_USE_P02_P03
#endif
#define IIC_GPIO_USE_P00_P01
#ifdef MUTE_PORT_USE_P01
#undef  MUTE_PORT_USE_P01
#endif
#define MUTE_PORT_USE_P03
#define EXCHANGE_LINE_IN_CHANNEL	//交换LINE IN 通道

#define ADKEY_PLAY_SHORT_SCAN_FRE

#define USE_POWER_KEY
#define PWR_CTRL_P04_KEY_P02
#define POWE_KEY_PLAY_KEY_IN_ONE_KEY	//PLAY POWER 共用一个按键
//#define POWER_KEY_ON_WAIT_FOR_3_SEC
#define USE_POWER_KEY_SHORT_SCAN
#endif

#ifdef K316_MONO_316_V001

#ifdef IIC_GPIO_USE_P02_P03
#undef IIC_GPIO_USE_P02_P03
#endif
#define IIC_GPIO_USE_P00_P01
#ifdef MUTE_PORT_USE_P01
#undef  MUTE_PORT_USE_P01
#endif
#define MUTE_PORT_USE_P03
#define EXCHANGE_LINE_IN_CHANNEL	//交换LINE IN 通道

#define ADKEY_PLAY_SHORT_SCAN_FRE

#define USE_POWER_KEY
#define PWR_CTRL_P04_KEY_P02
#define POWE_KEY_PLAY_KEY_IN_ONE_KEY	//PLAY POWER 共用一个按键
//#define POWER_KEY_ON_WAIT_FOR_3_SEC
#define USE_POWER_KEY_SHORT_SCAN
#endif


#ifdef K523_DeYun_523_V001

#ifdef IIC_GPIO_USE_P02_P03
#undef IIC_GPIO_USE_P02_P03
#endif
#define IIC_GPIO_USE_P00_P01
#ifdef MUTE_PORT_USE_P01
#undef  MUTE_PORT_USE_P01
#endif
#define MUTE_PORT_USE_P17

#define EXCHANGE_LINE_IN_CHANNEL	//交换LINE IN 通道
#define JOG_STICK_FUNC
#define ADKEY_NEXT_ADJST_FREQ

#endif


#ifdef K646_ZhuoXing_308_V001

#ifdef IIC_GPIO_USE_P02_P03
#undef IIC_GPIO_USE_P02_P03
#endif
#define IIC_GPIO_USE_P00_P01
#ifdef MUTE_PORT_USE_P01
#undef  MUTE_PORT_USE_P01
#endif
#define MUTE_PORT_USE_P03

#define EXCHANGE_LINE_IN_CHANNEL	//交换LINE IN 通道
#define USE_LINE_IN_DETECT_FUNC	//打开此宏来启动LINE IN 检测功能

#define AUX_DETECT_USE_P02
#define USE_BAT_MANAGEMENT

#define IR_REMOTER_WITH_POWER_MUTE_PRINT
#define KEY_100_ENABLE
#define USE_USB_AUDIO
#define IR_NEXT_PREV_SHORT_ADJ_CH
#define USB_SD_PLAY_INFO_DIV
#define MUTE_ON_FLASH_WHOLE_SCREEN

#endif




#ifdef K272_JH_272_V001
#define NO_LED_DISPLAY
#ifdef IIC_GPIO_USE_P02_P03
#undef IIC_GPIO_USE_P02_P03
#endif
#define IIC_GPIO_USE_P00_P01
#ifdef MUTE_PORT_USE_P01
#undef  MUTE_PORT_USE_P01
#endif
#define MUTE_PORT_USE_P03
#define EXCHANGE_LINE_IN_CHANNEL	//交换LINE IN 通道

#define POWE_KEY_PLAY_KEY_IN_ONE_KEY	//PLAY POWER 共用一个按键

#define USE_POWER_KEY
#define PWR_CTRL_P10_KEY_P02
#define USE_USB_AUDIO
#define USE_POWER_KEY_SHORT_SCAN

#endif

#ifdef K532_YJH_532_V001

#ifdef IIC_GPIO_USE_P02_P03
#undef IIC_GPIO_USE_P02_P03
#endif
#define IIC_GPIO_USE_P00_P01
#ifdef MUTE_PORT_USE_P01
#undef  MUTE_PORT_USE_P01
#endif
#define MUTE_PORT_USE_P03
#define EXCHANGE_LINE_IN_CHANNEL	//交换LINE IN 通道

#define ADKEY_PLAY_SHORT_SCAN_FRE
//#define JOG_STICK_FUNC
//#define USE_GPIO_DETECT_EARPHONE_PLUGGED
//#define USE_AMP_MODE_SELECT
#define USE_LINE_IN_DETECT_FUNC	//打开此宏来启动LINE IN 检测功能
#define LINE_IN_DETECT_SHARE_LED_STATUS_PORT
#endif

#ifdef K643_FW_643_V001

#ifdef IIC_GPIO_USE_P02_P03
#undef IIC_GPIO_USE_P02_P03
#endif
#define IIC_GPIO_USE_P00_P01
#ifdef MUTE_PORT_USE_P01
#undef  MUTE_PORT_USE_P01
#endif
#define MUTE_PORT_USE_P03

#define LED_USE_PLAY_MODE
#define EXCHANGE_LINE_IN_CHANNEL	//交换LINE IN 通道

//#define USE_LINE_IN_DETECT_FUNC	//打开此宏来启动LINE IN 检测功能
//#define AUX_DETECT_USE_P04
//#define USE_GPIO_DETECT_EARPHONE_PLUGGED
//#define EARPHONE_DETECT_USE_P02

#endif


#ifdef K637_ZX_306_V001

#ifdef IIC_GPIO_USE_P02_P03
#undef IIC_GPIO_USE_P02_P03
#endif
#define IIC_GPIO_USE_P00_P01
#ifdef MUTE_PORT_USE_P01
#undef  MUTE_PORT_USE_P01
#endif
#define MUTE_PORT_USE_P03
#define USE_BAT_MANAGEMENT

#define IR_REMOTER_WITH_POWER_MUTE_PRINT
#define KEY_100_ENABLE
//#define LED_USE_PLAY_MODE
#define EXCHANGE_LINE_IN_CHANNEL	//交换LINE IN 通道

//#define USE_LINE_IN_DETECT_FUNC	//打开此宏来启动LINE IN 检测功能
//#define AUX_DETECT_USE_P04
#define USE_GPIO_DETECT_EARPHONE_PLUGGED
#define EARPHONE_DETECT_USE_P02
#define INDEPENDENT_EARPHONE_DETECT_GPIO
#define IR_NEXT_PREV_SHORT_ADJ_CH
#define USB_SD_PLAY_INFO_DIV
#define MUTE_ON_FLASH_WHOLE_SCREEN
//#define SHORT_TIME_RETURN

#endif

#ifdef  K307_ZX_307_V001

#ifdef IIC_GPIO_USE_P02_P03
#undef IIC_GPIO_USE_P02_P03
#endif
#define IIC_GPIO_USE_P00_P01
#ifdef MUTE_PORT_USE_P01
#undef  MUTE_PORT_USE_P01
#endif
#define MUTE_PORT_USE_P03

#define LED_USE_PLAY_MODE
//#define EXCHANGE_LINE_IN_CHANNEL	//交换LINE IN 通道
#define NOT_USE_LINE_IN_FUNC	//打开此宏来关闭AUX功能

#endif

#ifdef K000_Zhongwei_SP_016_V001

#define EXCHANGE_LINE_IN_CHANNEL	//交换LINE IN 通道
#define NO_LED_DISPLAY
#define NOT_USE_LINE_IN_FUNC	//打开此宏来关闭AUX功能
#define USE_MANUAL_IDLE_FUNC		//手动切换到IDLE
#define VOLUME_DEFUALT 30

#endif


#ifdef K305_ZhuoXin_305_V001

#ifdef IIC_GPIO_USE_P02_P03
#undef IIC_GPIO_USE_P02_P03
#endif
#define IIC_GPIO_USE_P00_P01
#ifdef MUTE_PORT_USE_P01
#undef  MUTE_PORT_USE_P01
#endif
#define MUTE_PORT_USE_P03

#define LED_USE_PLAY_STATUS
#define EXCHANGE_LINE_IN_CHANNEL	//交换LINE IN 通道

//#define ADKEY_PLAY_SHORT_SCAN_FRE
#endif

#ifdef K223_BTL_CP153_V001

#ifdef IIC_GPIO_USE_P02_P03
#undef IIC_GPIO_USE_P02_P03
#endif
#define IIC_GPIO_USE_P00_P01
#ifdef MUTE_PORT_USE_P01
#undef  MUTE_PORT_USE_P01
#endif
#define MUTE_PORT_USE_P03
#define EXCHANGE_LINE_IN_CHANNEL	//交换LINE IN 通道
#define USE_BAT_MANAGEMENT

#define USE_POWER_KEY_SHORT_SCAN

//#define ADKEY_PLAY_SHORT_SCAN_FRE
//#define USE_GPIO_DETECT_EARPHONE_PLUGGED
//#define  GPIO_SWITCH_SELECT_MODE
//#define LED_USE_ROUND_LED
#define NO_PLAY_STATUS_LED
#define PWR_CTRL_P02_KEY_P04
#define USE_POWER_KEY
#define LED_USE_PLAY_MODE
#define POWE_KEY_PLAY_KEY_IN_ONE_KEY
#define POWER_KEY_ON_WAIT_FOR_3_SEC
#define INDEPENDENT_VOLUME_KEY

#define KEEP_SILENT_WHEN_SCAN_CHANNEL
//#define SEMI_AUTO_SCAN_FREQ	//半自动搜台
//#define ADKEY_NEXT_PREV_SHORT_AUTO_SCAN
//#define ADKEY_PLAY_SHORT_ADJ_CH
#endif

#ifdef K619_FXK_619_V001

#ifdef IIC_GPIO_USE_P02_P03
#undef IIC_GPIO_USE_P02_P03
#endif
#define IIC_GPIO_USE_P00_P01
#ifdef MUTE_PORT_USE_P01
#undef  MUTE_PORT_USE_P01
#endif
#define MUTE_PORT_USE_P03
//#define EXCHANGE_LINE_IN_CHANNEL	//交换LINE IN 通道

//#define ADKEY_PLAY_SHORT_SCAN_FRE
#define USE_GPIO_DETECT_EARPHONE_PLUGGED
//#define  GPIO_SWITCH_SELECT_MODE
#define LED_USE_ROUND_LED
#define NO_PLAY_STATUS_LED

#define USE_LINE_IN_DETECT_FUNC	//打开此宏来启动LINE IN 检测功能
#define SEMI_AUTO_SCAN_FREQ	//半自动搜台
#define NO_VOLUME_LIMITE
#define USE_USB_AUDIO
#define USE_CL6017G_FM
#define ADKEY_NEXT_PREV_SHORT_AUTO_SCAN
#define ADKEY_PLAY_SHORT_ADJ_CH
#endif

#ifdef K610_YJH_803_V001

#ifdef IIC_GPIO_USE_P02_P03
#undef IIC_GPIO_USE_P02_P03
#endif
#define IIC_GPIO_USE_P00_P01
#ifdef MUTE_PORT_USE_P01
#undef  MUTE_PORT_USE_P01
#endif
#define MUTE_PORT_USE_P03
#define EXCHANGE_LINE_IN_CHANNEL	//交换LINE IN 通道

#define ADKEY_PLAY_SHORT_SCAN_FRE
#define USE_GPIO_DETECT_EARPHONE_PLUGGED
#define  GPIO_SWITCH_SELECT_MODE

#endif

#ifdef K015_JLH_2946_V001
#define EXCHANGE_LINE_IN_CHANNEL	//交换LINE IN 通道
#define NOT_USE_LINE_IN_FUNC	//打开此宏来关闭AUX功能
#define NO_ADKEY_FUNC
#define LED_USE_PLAY_MODE
#define MATRIX_KEY_ENABLE
#define PLAY_STATUS_LED_P04
#define VOLUME_DEFUALT 30
#define MAX_VOL_SHOW 30
#define USE_VOL_LIMTATION
#define MUTE_PORT_USE_P01
#endif

#ifdef K170_HAO_SHENG_170_V001

#ifdef IIC_GPIO_USE_P02_P03
#undef IIC_GPIO_USE_P02_P03
#endif
#define IIC_GPIO_USE_P00_P01
#ifdef MUTE_PORT_USE_P01
#undef  MUTE_PORT_USE_P01
#endif
#define MUTE_PORT_USE_P03
#define EXCHANGE_LINE_IN_CHANNEL	//交换LINE IN 通道
#define INDEPENDENT_VOLUME_KEY
#define USE_LONG_PLAY_KEY_TO_SWITCH_MODE
#define USE_LINE_IN_DETECT_FUNC	//打开此宏来启动LINE IN 检测功能
#define LINE_IN_DETECT_SHARE_LED_STATUS_PORT
#define ADKEY_PLAY_SHORT_SCAN_FRE
#define USE_RTC_FUNCTION

#endif

#ifdef K010_QDX_PM21_V001

#ifdef IIC_GPIO_USE_P02_P03
#undef IIC_GPIO_USE_P02_P03
#endif
#define IIC_GPIO_USE_P00_P01
#ifdef MUTE_PORT_USE_P01
#undef  MUTE_PORT_USE_P01
#endif
#define MUTE_PORT_USE_P03
#define EXCHANGE_LINE_IN_CHANNEL	//交换LINE IN 通道

#define ADKEY_PLAY_SHORT_SCAN_FRE
#define JOG_STICK_FUNC
#define USE_GPIO_DETECT_EARPHONE_PLUGGED
#define USE_AMP_MODE_SELECT

#endif


#ifdef K1154_ZK_858_V001

#ifdef IIC_GPIO_USE_P02_P03
#undef IIC_GPIO_USE_P02_P03
#endif
#define IIC_GPIO_USE_P00_P01
#ifdef MUTE_PORT_USE_P01
#undef  MUTE_PORT_USE_P01
#endif
#define MUTE_PORT_USE_P03
#define EXCHANGE_LINE_IN_CHANNEL	//交换LINE IN 通道

#define LED_USE_PLAY_MODE
#define LED_MODE_EXCHANGE_TF_USB_ICON

#define DISP_PAUS_STRING
#define DISP_OFF_STR_AT_PWR_DOWN
#define ADKEY_PLAY_SHORT_SCAN_FRE
#define DISP_VOL_V_CHAR
//#define DISP_HIFI_STR_AT_POWER_ON
//#define VOL_DISP_COL_ICON
#define DISP_FILE_NUM_NEW_TYPE
#define VOLUME_CUSTOMER_DEFINE_32
#define NO_DEV_SHOW_HI_STR
#define DEFAULT_GO_TO_IDLE

#define USE_AMP_MODE_SELECT
#define USE_IR_POWER_KEY_TO_POWER_OFF

#if 1
#define LED_GPIO_PORT_CUSTOMERIZED

#define CUSTOMER_DEFINED_ADKEY_RESISTOR
#define USE_POWER_KEY
#define USE_ONLY_POWER_HOLD_CTRL
#define PWR_CTRL_P02
#define USE_PWR_KEY_LONG_PWR_ON
#define PWR_ON_DELAY_1_SECOND
#endif

#if 1
#define USE_BAT_MANAGEMENT
#define BAT_LEVEL_LED_ICON_IND
#define CHARGER_DETECT_INDICATOR
#define CHARGER_DET_USE_P17
#define CHARGER_FLASH_TYPE_1
#define PROTECT_P17_FROM_LED_SCAN
#define LOW_VOLT_SPARK_BAT_ICON
#endif

//#define USE_LINE_IN_DETECT_FUNC
//#define AUX_DETECT_USE_P04
#define POWE_KEY_PLAY_KEY_IN_ONE_KEY
#define USE_MODE_KEY_LONG_SCAN
#define DISP_DEV_STR_BEFOR_PLAY
#define USE_PWR_KEY_FOR_SCAN_STOP

#define LINE_IN_PLAY_KEY_PAUSE
#define NO_AUX_ICON_DISP
#define DISP_FM_STR_WHEN_PAUS

#define FM_PLAY_KEY_PAUSE
#define USE_POWER_KEY_FOR_AUX_PLAY
#define USE_POWER_KEY_FOR_FM_PLAY

#define USE_LINE_IN_DETECT_FUNC
#define AUX_DETECT_USE_P04
#if 0
#define DEFAULT_GO_TO_TIME_MODE
#define DEFAULT_GO_TO_CUSTOM_MODE
#define DEFAULT_GO_TO_CUSTOM_MODE_POWER_ON_FIRST_TIME_IN_RTC_MODE
#define USE_MODE_LONG_FOR_RTC_SETTING
#define USE_POWER_KEY_TO_ADJ_HOUR_AND_MIN
#define ALARM_ADJ_FLASH_ON_OFF
#define USE_RTC_FUNCTION
#define RTC_SETTING_OP_TIMER_ENABLE
#define NEW_RTC_SETTING_CTRL
#endif
#endif

#ifdef K1154_YJH_858_V002

#ifdef IIC_GPIO_USE_P02_P03
#undef IIC_GPIO_USE_P02_P03
#endif
#define IIC_GPIO_USE_P00_P01
#ifdef MUTE_PORT_USE_P01
#undef  MUTE_PORT_USE_P01
#endif
#define MUTE_PORT_USE_P03
#define EXCHANGE_LINE_IN_CHANNEL	//交换LINE IN 通道

#define LED_USE_PLAY_MODE
#define LED_USE_PLAY_MODE_NORMAL

#define DEFAULT_GO_TO_CUSTOM_MODE
#define DEFAULT_GO_TO_CUSTOM_MODE_POWER_ON_FIRST_TIME_IN_RTC_MODE
#define DISP_AUX_STRING
#define DISP_PAUS_STRING
#define DISP_OFF_STR_AT_PWR_DOWN
#define ADKEY_PLAY_SHORT_SCAN_FRE
#define DISP_VOL_V_CHAR
#define DISP_HIFI_STR_AT_POWER_ON
#define VOL_DISP_COL_ICON
#define DISP_FILE_NUM_NEW_TYPE
#define VOLUME_CUSTOMER_DEFINE_32

#define USE_AMP_MODE_SELECT
#define USE_IR_POWER_KEY_TO_POWER_OFF

#if 1
#define LED_GPIO_PORT_CUSTOMERIZED

#define CUSTOMER_DEFINED_ADKEY_RESISTOR
#define USE_POWER_KEY
#define USE_ONLY_POWER_HOLD_CTRL
#define PWR_CTRL_P02
#define USE_PWR_KEY_LONG_PWR_ON
#define PWR_ON_DELAY_1_SECOND
#endif

#if 1
#define USE_BAT_MANAGEMENT
#define BAT_LEVEL_LED_ICON_IND
#define CHARGER_DETECT_INDICATOR
#define CHARGER_DET_USE_P17
#define CHARGER_FLASH_TYPE_1
#define PROTECT_P17_FROM_LED_SCAN
#define LOW_VOLT_SPARK_BAT_ICON
#endif

#define USE_LINE_IN_DETECT_FUNC
#define AUX_DETECT_USE_P04
#define POWE_KEY_PLAY_KEY_IN_ONE_KEY
#define USE_MODE_KEY_LONG_SCAN
#define DISP_DEV_STR_BEFOR_PLAY
#define USE_PWR_KEY_FOR_SCAN_STOP

#define LINE_IN_PLAY_KEY_PAUSE
#define NO_AUX_ICON_DISP
#define DISP_FM_STR_WHEN_PAUS
#define FM_LINE_IN_ONLY_ONE_MODE_EXIST
#define FM_PLAY_KEY_PAUSE
#define USE_POWER_KEY_FOR_AUX_PLAY
#define USE_POWER_KEY_FOR_FM_PLAY
#define DEFAULT_GO_TO_TIME_MODE

#define USE_MODE_LONG_FOR_RTC_SETTING
#define USE_POWER_KEY_TO_ADJ_HOUR_AND_MIN
#define ALARM_ADJ_FLASH_ON_OFF
#define USE_RTC_FUNCTION
#define RTC_SETTING_OP_TIMER_ENABLE
#define NEW_RTC_SETTING_CTRL

#endif

#ifdef K1154_YJH_858_V001

#ifdef IIC_GPIO_USE_P02_P03
#undef IIC_GPIO_USE_P02_P03
#endif
#define IIC_GPIO_USE_P00_P01
#ifdef MUTE_PORT_USE_P01
#undef  MUTE_PORT_USE_P01
#endif
#define MUTE_PORT_USE_P03
#define EXCHANGE_LINE_IN_CHANNEL	//交换LINE IN 通道

#define LED_GPIO_PORT_CUSTOMERIZED
#define LED_USE_PLAY_MODE
#define LED_USE_PLAY_MODE_NORMAL

#define DISP_PAUS_STRING
#define DISP_OFF_STR_AT_PWR_DOWN
#define ADKEY_PLAY_SHORT_SCAN_FRE
//#define JOG_STICK_FUNC
//#define USE_GPIO_DETECT_EARPHONE_PLUGGED
#define USE_AMP_MODE_SELECT
#define USE_IR_POWER_KEY_TO_POWER_OFF
#if 1
#define USE_POWER_KEY
#define USE_ONLY_POWER_HOLD_CTRL
#define PWR_CTRL_P02
#define USE_PWR_KEY_LONG_PWR_ON
#define PWR_ON_DELAY_1_SECOND
#endif

#if 1
#define USE_BAT_MANAGEMENT
#define BAT_LEVEL_LED_ICON_IND
#define CHARGER_DETECT_INDICATOR
#define CHARGER_DET_USE_P17
#define CHARGER_FLASH_TYPE_1
#define PROTECT_P17_FROM_LED_SCAN
#define LOW_VOLT_SPARK_BAT_ICON
#endif
#define OTP_MUSIC_FUNC_ENABLE
#define Lamborghini_voice
//#define USE_LINE_IN_DETECT_FUNC
//#define AUX_DETECT_USE_P04
#define POWE_KEY_PLAY_KEY_IN_ONE_KEY
#define USE_POWER_KEY_SHORT_SCAN

#define CUSTOMER_DEFINED_ADKEY_RESISTOR
#endif


#ifdef K1154_WXD_62_V001

#ifdef IIC_GPIO_USE_P02_P03
#undef IIC_GPIO_USE_P02_P03
#endif
#define IIC_GPIO_USE_P00_P01
#ifdef MUTE_PORT_USE_P01
#undef  MUTE_PORT_USE_P01
#endif
#define MUTE_PORT_USE_P03
#define EXCHANGE_LINE_IN_CHANNEL	//交换LINE IN 通道

#define LED_GPIO_PORT_CUSTOMERIZED
#define LED_USE_PLAY_MODE
#define LED_USE_PLAY_MODE_NORMAL

#define DISP_PAUS_STRING
#define DISP_OFF_STR_AT_PWR_DOWN
#define ADKEY_PLAY_SHORT_SCAN_FRE
//#define JOG_STICK_FUNC
//#define USE_GPIO_DETECT_EARPHONE_PLUGGED
#define USE_AMP_MODE_SELECT
#define USE_IR_POWER_KEY_TO_POWER_OFF
#if 1
#define USE_POWER_KEY
#define USE_ONLY_POWER_HOLD_CTRL
#define PWR_CTRL_P02
#define USE_PWR_KEY_LONG_PWR_ON
#define PWR_ON_DELAY_1_SECOND
#endif

#if 1
#define USE_BAT_MANAGEMENT
#define BAT_LEVEL_LED_ICON_IND
#define CHARGER_DETECT_INDICATOR
#define CHARGER_DET_USE_P17
#define CHARGER_FLASH_TYPE_2
#define PROTECT_P17_FROM_LED_SCAN
#define LOW_VOLT_SPARK_BAT_ICON
#endif

//#define USE_LINE_IN_DETECT_FUNC
//#define AUX_DETECT_USE_P04
#define POWE_KEY_PLAY_KEY_IN_ONE_KEY
#define USE_MODE_KEY_LONG_SCAN

#define LINE_IN_PLAY_KEY_PAUSE
#define DISP_FM_STR_WHEN_PAUS
#define FM_LINE_IN_ONLY_ONE_MODE_EXIST
#define FM_PLAY_KEY_PAUSE
#define USE_POWER_KEY_FOR_AUX_PLAY
#define USE_POWER_KEY_FOR_FM_PLAY


#define CUSTOMER_DEFINED_ADKEY_RESISTOR

#if 1
//#undef USE_RDAs_FM
//#undef USE_QN8035_FM
#define OTP_MUSIC_FUNC_ENABLE
#define OTP_DECODE_PLAY_CUSTOMED_VOL
#define Lamborghini_voice
#endif

#endif

#ifdef K1154_YJH_858_V003

#ifdef IIC_GPIO_USE_P02_P03
#undef IIC_GPIO_USE_P02_P03
#endif
#define IIC_GPIO_USE_P00_P01
#ifdef MUTE_PORT_USE_P01
#undef  MUTE_PORT_USE_P01
#endif
#define MUTE_PORT_USE_P03
#define EXCHANGE_LINE_IN_CHANNEL	//交换LINE IN 通道

#define LED_GPIO_PORT_CUSTOMERIZED
#define LED_USE_PLAY_MODE
#define LED_USE_PLAY_MODE_NORMAL

#define DISP_PAUS_STRING
#define DISP_OFF_STR_AT_PWR_DOWN
#define ADKEY_PLAY_SHORT_SCAN_FRE
//#define JOG_STICK_FUNC
//#define USE_GPIO_DETECT_EARPHONE_PLUGGED
#define USE_AMP_MODE_SELECT
#define USE_IR_POWER_KEY_TO_POWER_OFF
#if 1
#define USE_POWER_KEY
#define USE_ONLY_POWER_HOLD_CTRL
#define PWR_CTRL_P02
#define USE_PWR_KEY_LONG_PWR_ON
#define PWR_ON_DELAY_1_SECOND
#endif

#if 1
#define USE_BAT_MANAGEMENT
#define BAT_LEVEL_LED_ICON_IND
#define CHARGER_DETECT_INDICATOR
#define CHARGER_DET_USE_P17
#define CHARGER_FLASH_TYPE_2
#define PROTECT_P17_FROM_LED_SCAN
#define LOW_VOLT_SPARK_BAT_ICON
#endif

//#define USE_LINE_IN_DETECT_FUNC
//#define AUX_DETECT_USE_P04
#define POWE_KEY_PLAY_KEY_IN_ONE_KEY
#define USE_MODE_KEY_LONG_SCAN

#define LINE_IN_PLAY_KEY_PAUSE
#define DISP_FM_STR_WHEN_PAUS
#define FM_LINE_IN_ONLY_ONE_MODE_EXIST
#define FM_PLAY_KEY_PAUSE
#define USE_POWER_KEY_FOR_AUX_PLAY
#define USE_POWER_KEY_FOR_FM_PLAY


#define CUSTOMER_DEFINED_ADKEY_RESISTOR
#endif

#ifdef K1154_HF_054_V001

#ifdef IIC_GPIO_USE_P02_P03
#undef IIC_GPIO_USE_P02_P03
#endif
#define IIC_GPIO_USE_P00_P01
#ifdef MUTE_PORT_USE_P01
#undef  MUTE_PORT_USE_P01
#endif
#define MUTE_PORT_USE_P03
#define EXCHANGE_LINE_IN_CHANNEL	//交换LINE IN 通道

#define LED_GPIO_PORT_CUSTOMERIZED
#define LED_USE_PLAY_MODE
#define LED_USE_PLAY_MODE_NORMAL

#define DISP_PAUS_STRING
#define DISP_OFF_STR_AT_PWR_DOWN
#define ADKEY_PLAY_SHORT_SCAN_FRE
//#define JOG_STICK_FUNC
//#define USE_GPIO_DETECT_EARPHONE_PLUGGED
#define USE_AMP_MODE_SELECT
#define USE_IR_POWER_KEY_TO_POWER_OFF
#if 1
#define USE_POWER_KEY
#define USE_ONLY_POWER_HOLD_CTRL
#define PWR_CTRL_P02
#define USE_PWR_KEY_LONG_PWR_ON
#define PWR_ON_DELAY_1_SECOND
#endif

#if 1
#define USE_BAT_MANAGEMENT
#define BAT_LEVEL_LED_ICON_IND
#define CHARGER_DETECT_INDICATOR
#define CHARGER_DET_USE_P17
#define CHARGER_FLASH_TYPE_1
#define PROTECT_P17_FROM_LED_SCAN
#define LOW_VOLT_SPARK_BAT_ICON
#endif

//#define USE_LINE_IN_DETECT_FUNC
//#define AUX_DETECT_USE_P04
#define POWE_KEY_PLAY_KEY_IN_ONE_KEY
#define USE_POWER_KEY_SHORT_SCAN

#define CUSTOMER_DEFINED_ADKEY_RESISTOR
#endif


#ifdef K1154_YJH_1154_V001

#ifdef IIC_GPIO_USE_P02_P03
#undef IIC_GPIO_USE_P02_P03
#endif
#define IIC_GPIO_USE_P00_P01
#ifdef MUTE_PORT_USE_P01
#undef  MUTE_PORT_USE_P01
#endif
#define MUTE_PORT_USE_P03
#define EXCHANGE_LINE_IN_CHANNEL	//交换LINE IN 通道

#define LED_GPIO_PORT_CUSTOMERIZED
#define ROUND_LED_USE_OFFEN

#define ADKEY_PLAY_SHORT_SCAN_FRE
#define JOG_STICK_FUNC
#define USE_GPIO_DETECT_EARPHONE_PLUGGED
#define USE_AMP_MODE_SELECT
#define USE_IR_POWER_KEY_TO_POWER_OFF
#if 1
#define USE_POWER_KEY
#define USE_ONLY_POWER_HOLD_CTRL
#define PWR_CTRL_P02
#define USE_PWR_KEY_LONG_PWR_ON
#define PWR_ON_DELAY_1_SECOND
#endif

#define POWE_KEY_PLAY_KEY_IN_ONE_KEY
#define USE_POWER_KEY_SHORT_SCAN

#define CUSTOMER_DEFINED_ADKEY_RESISTOR
#endif

#ifdef K3015_XFW_931_V001

#ifdef IIC_GPIO_USE_P02_P03
#undef IIC_GPIO_USE_P02_P03
#endif
#define IIC_GPIO_USE_P00_P01
#ifdef MUTE_PORT_USE_P01
#undef  MUTE_PORT_USE_P01
#endif
#define MUTE_PORT_USE_P03
#define EXCHANGE_LINE_IN_CHANNEL	//交换LINE IN 通道

#define LED_GPIO_PORT_CUSTOMERIZED
#define LED_COMMON_SCAN_COM_USE_P17

#define ADKEY_PLAY_SHORT_SCAN_FRE
#define JOG_STICK_FUNC
#define USE_GPIO_DETECT_EARPHONE_PLUGGED
#define USE_AMP_MODE_SELECT
#define USE_IR_POWER_KEY_TO_POWER_OFF
#if 0
#define USE_POWER_KEY
#define USE_ONLY_POWER_HOLD_CTRL
#define PWR_CTRL_P02
#define USE_PWR_KEY_LONG_PWR_ON
#define PWR_ON_DELAY_1_SECOND
#endif

#define SEMI_AUTO_SCAN_FREQ
#define IR_NEXT_PREV_HOLD_AUTO_SCAN
#define IR_NEXT_PREV_SHORT_ADJ_CH
#define IR_REMOTER_WITH_POWER_MUTE_PRINT
#define KEY_100_ENABLE
#define USE_POWER_KEY_TO_SWITCH_MODE
#define CUSTOMER_DEFINED_ADKEY_RESISTOR
#endif


#ifdef K010_XFW_931_V001

#ifdef IIC_GPIO_USE_P02_P03
#undef IIC_GPIO_USE_P02_P03
#endif
#define IIC_GPIO_USE_P00_P01
#ifdef MUTE_PORT_USE_P01
#undef  MUTE_PORT_USE_P01
#endif
#define MUTE_PORT_USE_P03
#define EXCHANGE_LINE_IN_CHANNEL	//交换LINE IN 通道

#define LED_GPIO_PORT_CUSTOMERIZED
#define LED_COMMON_SCAN_COM_USE_P17

#define ADKEY_PLAY_SHORT_SCAN_FRE
#define JOG_STICK_FUNC
#define USE_GPIO_DETECT_EARPHONE_PLUGGED
#define USE_AMP_MODE_SELECT
#define USE_IR_POWER_KEY_TO_POWER_OFF
#if 1
#define USE_POWER_KEY
#define USE_ONLY_POWER_HOLD_CTRL
#define PWR_CTRL_P02
#define USE_PWR_KEY_LONG_PWR_ON
#define PWR_ON_DELAY_1_SECOND
#endif

#define USE_POWER_KEY_TO_SWITCH_MODE
#define CUSTOMER_DEFINED_ADKEY_RESISTOR
#endif

#ifdef K010_YJH_931_V001

#ifdef IIC_GPIO_USE_P02_P03
#undef IIC_GPIO_USE_P02_P03
#endif
#define IIC_GPIO_USE_P00_P01
#ifdef MUTE_PORT_USE_P01
#undef  MUTE_PORT_USE_P01
#endif
#define MUTE_PORT_USE_P03
#define EXCHANGE_LINE_IN_CHANNEL	//交换LINE IN 通道

#define ADKEY_PLAY_SHORT_SCAN_FRE
#define JOG_STICK_FUNC
#define USE_GPIO_DETECT_EARPHONE_PLUGGED
#define USE_AMP_MODE_SELECT

#endif

#ifdef K170_QDX_PM_A01_V001

#ifdef IIC_GPIO_USE_P02_P03
#undef IIC_GPIO_USE_P02_P03
#endif
#define IIC_GPIO_USE_P00_P01
#ifdef MUTE_PORT_USE_P01
#undef  MUTE_PORT_USE_P01
#endif
#define MUTE_PORT_USE_P03
#define EXCHANGE_LINE_IN_CHANNEL	//交换LINE IN 通道
//#define INDEPENDENT_VOLUME_KEY
#define USE_LONG_PLAY_KEY_TO_SWITCH_MODE
//#define USE_LINE_IN_DETECT_FUNC	//打开此宏来启动LINE IN 检测功能
#define LINE_IN_DETECT_SHARE_LED_STATUS_PORT
#define ADKEY_PLAY_SHORT_SCAN_FRE
#define LINE_IN_PLAY_KEY_PAUSE

#define USE_USB_AUDIO

#endif

#ifdef K170_QDX_170_V001

#ifdef IIC_GPIO_USE_P02_P03
#undef IIC_GPIO_USE_P02_P03
#endif
#define IIC_GPIO_USE_P00_P01
#ifdef MUTE_PORT_USE_P01
#undef  MUTE_PORT_USE_P01
#endif
#define MUTE_PORT_USE_P03
#define EXCHANGE_LINE_IN_CHANNEL	//交换LINE IN 通道
#define INDEPENDENT_VOLUME_KEY
#define USE_LONG_PLAY_KEY_TO_SWITCH_MODE
//#define USE_LINE_IN_DETECT_FUNC	//打开此宏来启动LINE IN 检测功能
#define LINE_IN_DETECT_SHARE_LED_STATUS_PORT
#define ADKEY_PLAY_SHORT_SCAN_FRE
#define LINE_IN_PLAY_KEY_PAUSE
#define NEXT_PREV_HOLD_SEL_FILE
#define USE_USB_AUDIO

#endif

#ifdef K170_YDS_170_V001

#ifdef IIC_GPIO_USE_P02_P03
#undef IIC_GPIO_USE_P02_P03
#endif
#define IIC_GPIO_USE_P00_P01
#ifdef MUTE_PORT_USE_P01
#undef  MUTE_PORT_USE_P01
#endif
#define MUTE_PORT_USE_P03
#define EXCHANGE_LINE_IN_CHANNEL	//交换LINE IN 通道
//#define INDEPENDENT_VOLUME_KEY
#define USE_LONG_PLAY_KEY_TO_SWITCH_MODE
//#define USE_LINE_IN_DETECT_FUNC	//打开此宏来启动LINE IN 检测功能
//#define LINE_IN_DETECT_SHARE_LED_STATUS_PORT
#define ADKEY_PLAY_SHORT_SCAN_FRE

#define USE_USB_AUDIO

#endif

#ifdef K170_LanQin_170_V001

#ifdef IIC_GPIO_USE_P02_P03
#undef IIC_GPIO_USE_P02_P03
#endif
#define IIC_GPIO_USE_P00_P01
#ifdef MUTE_PORT_USE_P01
#undef  MUTE_PORT_USE_P01
#endif
#define MUTE_PORT_USE_P03
#define EXCHANGE_LINE_IN_CHANNEL	//交换LINE IN 通道
#define INDEPENDENT_VOLUME_KEY
#define USE_LONG_PLAY_KEY_TO_SWITCH_MODE
//#define USE_LINE_IN_DETECT_FUNC	//打开此宏来启动LINE IN 检测功能
//#define LINE_IN_DETECT_SHARE_LED_STATUS_PORT
#define ADKEY_PLAY_SHORT_SCAN_FRE

#define USE_USB_AUDIO

#endif

#ifdef K170_YJH_170_V001

#ifdef IIC_GPIO_USE_P02_P03
#undef IIC_GPIO_USE_P02_P03
#endif
#define IIC_GPIO_USE_P00_P01
#ifdef MUTE_PORT_USE_P01
#undef  MUTE_PORT_USE_P01
#endif
#define MUTE_PORT_USE_P03
#define EXCHANGE_LINE_IN_CHANNEL	//交换LINE IN 通道
#define INDEPENDENT_VOLUME_KEY
#define USE_LONG_PLAY_KEY_TO_SWITCH_MODE
//#define USE_LINE_IN_DETECT_FUNC	//打开此宏来启动LINE IN 检测功能
//#define LINE_IN_DETECT_SHARE_LED_STATUS_PORT
#define ADKEY_PLAY_SHORT_SCAN_FRE

#define USE_USB_AUDIO

#endif

#ifdef K170_ZK_170_V001

#ifdef IIC_GPIO_USE_P02_P03
#undef IIC_GPIO_USE_P02_P03
#endif
#define IIC_GPIO_USE_P00_P01
#ifdef MUTE_PORT_USE_P01
#undef  MUTE_PORT_USE_P01
#endif
#define MUTE_PORT_USE_P03
#define EXCHANGE_LINE_IN_CHANNEL	//交换LINE IN 通道


//#define USE_LINE_IN_DETECT_FUNC	//打开此宏来启动LINE IN 检测功能
//#define LINE_IN_DETECT_SHARE_LED_STATUS_PORT

#define USE_USB_AUDIO

#endif

#ifdef K170_ZHUOXIN_UK3_V001

#ifdef IIC_GPIO_USE_P02_P03
#undef IIC_GPIO_USE_P02_P03
#endif
#define IIC_GPIO_USE_P00_P01
#ifdef MUTE_PORT_USE_P01
#undef  MUTE_PORT_USE_P01
#endif
#define MUTE_PORT_USE_P03
#define EXCHANGE_LINE_IN_CHANNEL	//交换LINE IN 通道


#define USE_LINE_IN_DETECT_FUNC	//打开此宏来启动LINE IN 检测功能
#define LINE_IN_DETECT_SHARE_LED_STATUS_PORT

#define USE_USB_AUDIO

#endif

#ifdef K171_LT_171_V001

#ifdef IIC_GPIO_USE_P02_P03
#undef IIC_GPIO_USE_P02_P03
#endif
#define IIC_GPIO_USE_P00_P01
#ifdef MUTE_PORT_USE_P01
#undef  MUTE_PORT_USE_P01
#endif
#define MUTE_PORT_USE_P03
#define EXCHANGE_LINE_IN_CHANNEL	//交换LINE IN 通道
//#define LINE_IN_PLAY_KEY_PAUSE
//#define ADKEY_PLAY_SHORT_SCAN_FRE
//#define USE_GPIO_DETECT_EARPHONE_PLUGGED
#define ADKEY_PLAY_SHORT_SCAN_FRE
#define USE_LINE_IN_DETECT_FUNC	//打开此宏来启动LINE IN 检测功能
#define LINE_IN_DETECT_SHARE_LED_STATUS_PORT

#endif

#ifdef K171_LanQin_012_V001

#ifdef IIC_GPIO_USE_P02_P03
#undef IIC_GPIO_USE_P02_P03
#endif
#define IIC_GPIO_USE_P00_P01
#ifdef MUTE_PORT_USE_P01
#undef  MUTE_PORT_USE_P01
#endif
//#define LED_USE_PLAY_MODE

#define MUTE_PORT_USE_P03
#define EXCHANGE_LINE_IN_CHANNEL	//交换LINE IN 通道
//#define LINE_IN_PLAY_KEY_PAUSE
//#define ADKEY_PLAY_SHORT_SCAN_FRE
//#define USE_GPIO_DETECT_EARPHONE_PLUGGED
//#define ADKEY_PLAY_SHORT_SCAN_FRE
#define USE_LINE_IN_DETECT_FUNC	//打开此宏来启动LINE IN 检测功能
#define LINE_IN_DETECT_SHARE_LED_STATUS_PORT
//#define VOLUME_CUSTOMER_DEFINE_28
#define VOLUME_DEFUALT 30
#define NO_VOLUME_LIMITE

#endif

#ifdef K171_ZX_SW012_ET1013FM_V001

#ifdef IIC_GPIO_USE_P02_P03
#undef IIC_GPIO_USE_P02_P03
#endif
#define IIC_GPIO_USE_P00_P01
#ifdef MUTE_PORT_USE_P01
#undef  MUTE_PORT_USE_P01
#endif
#define LED_USE_PLAY_MODE

#define MUTE_PORT_USE_P03
#define EXCHANGE_LINE_IN_CHANNEL	//交换LINE IN 通道
//#define LINE_IN_PLAY_KEY_PAUSE
//#define ADKEY_PLAY_SHORT_SCAN_FRE
//#define USE_GPIO_DETECT_EARPHONE_PLUGGED
//#define ADKEY_PLAY_SHORT_SCAN_FRE
#define USE_LINE_IN_DETECT_FUNC	//打开此宏来启动LINE IN 检测功能
#define LINE_IN_DETECT_SHARE_LED_STATUS_PORT
//#define VOLUME_CUSTOMER_DEFINE_28
#define USE_BAT_MANAGEMENT
#define USB_SD_PLAY_INFO_DIV
#endif


#ifdef K171_SW_012_V001

#ifdef IIC_GPIO_USE_P02_P03
#undef IIC_GPIO_USE_P02_P03
#endif
#define IIC_GPIO_USE_P00_P01
#ifdef MUTE_PORT_USE_P01
#undef  MUTE_PORT_USE_P01
#endif
#define LED_USE_PLAY_MODE

#define MUTE_PORT_USE_P03
#define EXCHANGE_LINE_IN_CHANNEL	//交换LINE IN 通道
//#define LINE_IN_PLAY_KEY_PAUSE
//#define ADKEY_PLAY_SHORT_SCAN_FRE
//#define USE_GPIO_DETECT_EARPHONE_PLUGGED
//#define ADKEY_PLAY_SHORT_SCAN_FRE
#define USE_LINE_IN_DETECT_FUNC	//打开此宏来启动LINE IN 检测功能
#define LINE_IN_DETECT_SHARE_LED_STATUS_PORT
#define VOLUME_CUSTOMER_DEFINE_28

#endif

#ifdef K171_YJH_171_V001

#ifdef IIC_GPIO_USE_P02_P03
#undef IIC_GPIO_USE_P02_P03
#endif
#define IIC_GPIO_USE_P00_P01
#ifdef MUTE_PORT_USE_P01
#undef  MUTE_PORT_USE_P01
#endif
#define MUTE_PORT_USE_P03
#define EXCHANGE_LINE_IN_CHANNEL	//交换LINE IN 通道
//#define LINE_IN_PLAY_KEY_PAUSE
//#define ADKEY_PLAY_SHORT_SCAN_FRE
//#define USE_GPIO_DETECT_EARPHONE_PLUGGED
#define ADKEY_PLAY_SHORT_SCAN_FRE
#define USE_LINE_IN_DETECT_FUNC	//打开此宏来启动LINE IN 检测功能
#define LINE_IN_DETECT_SHARE_LED_STATUS_PORT

#endif


#if 0//def K208_ZY_KL208_V001

#ifdef IIC_GPIO_USE_P02_P03
#undef IIC_GPIO_USE_P02_P03
#endif
#define IIC_GPIO_USE_P00_P01
#ifdef MUTE_PORT_USE_P01
#undef  MUTE_PORT_USE_P01
#endif
#define MUTE_PORT_USE_P03
#define EXCHANGE_LINE_IN_CHANNEL	//交换LINE IN 通道
//#define LINE_IN_PLAY_KEY_PAUSE
//#define ADKEY_PLAY_SHORT_SCAN_FRE
#define USE_RTC_FUNCTION
#define USE_RTC_TIME_ONLY
#define USE_RTC_ALARM_FUNCTION

#define SEMI_AUTO_SCAN_FREQ
#define ADKEY_NEXT_PREV_HOLD_AUTO_SCAN
#define IR_NEXT_PREV_HOLD_AUTO_SCAN

#endif

#ifdef K000_RS_228U_V001
#define NO_LED_DISPLAY
#define ADKEY_USE_P07_PORT
#define NOT_USE_LINE_IN_FUNC	//打开此宏来关闭AUX功能
#define VOLUME_DEFUALT 27

#endif

#ifdef K189_JM_201_V001

#ifdef IIC_GPIO_USE_P02_P03
#undef IIC_GPIO_USE_P02_P03
#endif
#define IIC_GPIO_USE_P00_P01
#ifdef MUTE_PORT_USE_P01
#undef  MUTE_PORT_USE_P01
#endif
#define MUTE_PORT_USE_P03
#define EXCHANGE_LINE_IN_CHANNEL	//交换LINE IN 通道
#define LINE_IN_PLAY_KEY_PAUSE
#define ADKEY_PLAY_SHORT_SCAN_FRE
#define USE_EQ_TABLE_CUSTOM
#endif

#ifdef K063_YJH_063_V001
#define NO_LED_DISPLAY

#ifdef MUTE_PORT_USE_P01
#undef  MUTE_PORT_USE_P01
#endif
#define MUTE_PORT_USE_P00
//#define LED_USE_ROUND_LED
#define POWE_KEY_PLAY_KEY_IN_ONE_KEY
#define SEMI_AUTO_SCAN_FREQ
#define IR_NEXT_PREV_HOLD_AUTO_SCAN
#define USE_POWER_KEY
#define PWR_CTRL_P10_KEY_P04
#define EXCHANGE_LINE_IN_CHANNEL	//交换LINE IN 通道
//#define INDEPENDENT_VOLUME_KEY
#define USE_POWER_KEY_SHORT_SCAN
#define USE_LINE_IN_DETECT_FUNC	//打开此宏来启动LINE IN 检测功能
#define FM_USE_KT0830EG
#define USE_GPIO_DETECT_EARPHONE_PLUGGED

#endif

#ifdef K020_WEIQI_V001
#define NO_LED_DISPLAY

#endif


#ifdef  K186_LM_186_V001
#ifdef IIC_GPIO_USE_P02_P03
#undef IIC_GPIO_USE_P02_P03
#endif
#define IIC_GPIO_USE_P00_P01
#ifdef MUTE_PORT_USE_P01
#undef  MUTE_PORT_USE_P01
#endif
#define MUTE_PORT_USE_P03
//#define LED_USE_ROUND_LED

#define USE_POWER_KEY
#define PWR_CTRL_P02_KEY_P04
#define EXCHANGE_LINE_IN_CHANNEL	//交换LINE IN 通道
#define INDEPENDENT_VOLUME_KEY
#define USE_GPIO_DETECT_EARPHONE_PLUGGED
//#define EQ_MODE_DEFUALT_ROCK
#define USE_USB_AUDIO

#endif

#ifdef  K186_ZHHB_S30_V001
#ifdef IIC_GPIO_USE_P02_P03
#undef IIC_GPIO_USE_P02_P03
#endif
#define IIC_GPIO_USE_P00_P01
#ifdef MUTE_PORT_USE_P01
#undef  MUTE_PORT_USE_P01
#endif
#define MUTE_PORT_USE_P03
//#define LED_USE_ROUND_LED

#define USE_POWER_KEY
#define PWR_CTRL_P02_KEY_P04
#define EXCHANGE_LINE_IN_CHANNEL	//交换LINE IN 通道
#define INDEPENDENT_VOLUME_KEY
#define USE_GPIO_DETECT_EARPHONE_PLUGGED
//#define EQ_MODE_DEFUALT_ROCK
#endif

#ifdef K181_YJH_181_V001

#ifdef IIC_GPIO_USE_P02_P03
#undef IIC_GPIO_USE_P02_P03
#endif
#define IIC_GPIO_USE_P00_P01
#ifdef MUTE_PORT_USE_P01
#undef  MUTE_PORT_USE_P01
#endif
#define MUTE_PORT_USE_P03
#define EXCHANGE_LINE_IN_CHANNEL	//交换LINE IN 通道
#define LED_USE_1X888
#define NOT_USE_LINE_IN_FUNC	//无LINE 功能

#define ADKEY_PLAY_SHORT_SCAN_FRE

//#define IR_REMOTER_WITH_POWER_MUTE_PRINT
#define IR_NEXT_PREV_SHORT_ADJ_CH
#define IR_NEXT_PREV_HOLD_AUTO_SCAN

#define CUSTOMER_DEFINED_ADKEY_RESISTOR
#define SEMI_AUTO_SCAN_FREQ
#define KEY_100_ENABLE

#endif

#ifdef K181_LY_181_V001

#ifdef IIC_GPIO_USE_P02_P03
#undef IIC_GPIO_USE_P02_P03
#endif
#define IIC_GPIO_USE_P00_P01
#ifdef MUTE_PORT_USE_P01
#undef  MUTE_PORT_USE_P01
#endif
#define MUTE_PORT_USE_P03
#define EXCHANGE_LINE_IN_CHANNEL	//交换LINE IN 通道
#define LED_USE_1X888
#define NOT_USE_LINE_IN_FUNC	//无LINE 功能

#define ADKEY_PLAY_SHORT_SCAN_FRE

#define IR_REMOTER_WITH_POWER_MUTE_PRINT
#define IR_NEXT_PREV_SHORT_ADJ_CH
#define IR_NEXT_PREV_HOLD_AUTO_SCAN

#define CUSTOMER_DEFINED_ADKEY_RESISTOR
#define SEMI_AUTO_SCAN_FREQ
#endif

#ifdef K180_LY_180_V001

#ifdef IIC_GPIO_USE_P02_P03
#undef IIC_GPIO_USE_P02_P03
#endif
#define IIC_GPIO_USE_P00_P01
#ifdef MUTE_PORT_USE_P01
#undef  MUTE_PORT_USE_P01
#endif
#define MUTE_PORT_USE_P03
#define EXCHANGE_LINE_IN_CHANNEL	//交换LINE IN 通道
#define LED_USE_1X888
#define NOT_USE_LINE_IN_FUNC	//无LINE 功能

#define ADKEY_PLAY_SHORT_SCAN_FRE

#define IR_REMOTER_WITH_POWER_MUTE_PRINT
#define IR_NEXT_PREV_SHORT_ADJ_CH
#define IR_NEXT_PREV_HOLD_AUTO_SCAN
#define CUSTOMER_DEFINED_ADKEY_RESISTOR
#define SEMI_AUTO_SCAN_FREQ
#endif


#ifdef K077_BoDa_V001
#define NO_LED_DISPLAY
//#define FM_TRANSMITTER
#define IIC_GPIO_USE_P00_P01
#ifdef IIC_GPIO_USE_P02_P03
#undef IIC_GPIO_USE_P02_P03
#endif
#endif

#ifdef K003_V001
#define ADKEY_PLAY_SHORT_SCAN_FRE
#define	MUTE_PORT_USE_P01
#endif

#ifdef K010_931_V001
#define ADKEY_PLAY_SHORT_SCAN_FRE
#define	MUTE_PORT_USE_P01
#endif

#ifdef SW_V001
#define NO_LED_DISPLAY
#undef ADKEY_PLAY_SHORT_SCAN_FRE
#define	MUTE_PORT_USE_P01
#define USE_VOL_LIMTATION
#ifdef USE_VOL_LIMTATION
#define MAX_VOL_SHOW 28
#endif
#define LED_RUN_FAST_WHEN_PLAY_MODE_CHANGE
#define CUSTOMER_DEFINED_ADKEY_RESISTOR
#define VOLUME_DEFUALT 27
#endif

#ifdef SW_V003_747
//#define LED_USE_PLAY_MODE
#define AC209_28PIN		//28 PIN IC GPIO CONFIG

#define IIC_GPIO_USE_P00_P01
#ifdef IIC_GPIO_USE_P02_P03
#undef IIC_GPIO_USE_P02_P03
#endif

#undef ADKEY_PLAY_SHORT_SCAN_FRE
//#define ADKEY_NEXT_ADJST_FREQ
#ifdef MUTE_PORT_USE_P01
#undef MUTE_PORT_USE_P01
#endif
#define MUTE_PORT_USE_P26
#define PLAY_STATUS_LED_P27

#define IR_NEXT_PREV_HOLD_AUTO_SCAN

#define EXCHANGE_LINE_IN_CHANNEL
#define FM_BY_PASS

#define KEY_100_ENABLE
#define LIMIT_AGC_VOL_AT_26
#define USE_VOL_LIMTATION
#ifdef USE_VOL_LIMTATION
#define MAX_VOL_SHOW 50
#endif
#define LED_RUN_FAST_WHEN_PLAY_MODE_CHANGE
#define CUSTOMER_DEFINED_ADKEY_RESISTOR
#define VOLUME_CUSTOMER_DEFINE

#ifdef LED_GPIO_DRV
#undef LED_GPIO_DRV
#endif
#define LED_1651_DRV
//#define DISPLAY_TEST
#endif

#ifdef SW_V002_747
#define LED_USE_PLAY_MODE

#undef ADKEY_PLAY_SHORT_SCAN_FRE
#define ADKEY_NEXT_ADJST_FREQ
#define MUTE_PORT_USE_P01
#define SEMI_AUTO_SCAN_FREQ
#define IR_NEXT_PREV_HOLD_AUTO_SCAN
#define ADKEY_NEXT_PREV_HOLD_AUTO_SCAN
#define KEY_100_ENABLE

#define NO_VOLUME_LIMITE
//#ifdef USE_VOL_LIMTATION
#define MAX_VOL_SHOW 50
//#endif
#define VOLUME_DEFUALT 50
#define LED_RUN_FAST_WHEN_PLAY_MODE_CHANGE
#define CUSTOMER_DEFINED_ADKEY_RESISTOR
#define VOLUME_CUSTOMER_DEFINE

#endif

#ifdef SW_V002
#define LED_USE_PLAY_MODE

#undef ADKEY_PLAY_SHORT_SCAN_FRE
#define ADKEY_NEXT_ADJST_FREQ
#define MUTE_PORT_USE_P01
#define SEMI_AUTO_SCAN_FREQ
#define IR_NEXT_PREV_HOLD_AUTO_SCAN
#define ADKEY_NEXT_PREV_HOLD_AUTO_SCAN
#define KEY_100_ENABLE
#define VOLUME_CUSTOMER_DEFINE_28
#ifdef USE_VOL_LIMTATION
//#define MAX_VOL_SHOW 28
#endif
#define LED_RUN_FAST_WHEN_PLAY_MODE_CHANGE
#define CUSTOMER_DEFINED_ADKEY_RESISTOR
#define EXCHANGE_LINE_IN_CHANNEL	//交换LINE IN 通道

#endif

#ifdef SW_V002_CUSTOMED_V001
#define LED_USE_PLAY_MODE

#define PLAY_MODE_REPEAT_ONE
//#define DECODE_STOP_MODE_ENABLE

#undef ADKEY_PLAY_SHORT_SCAN_FRE
#define ADKEY_NEXT_ADJST_FREQ
#define MUTE_PORT_USE_P01
#define SEMI_AUTO_SCAN_FREQ
#define IR_NEXT_PREV_HOLD_AUTO_SCAN
#define ADKEY_NEXT_PREV_HOLD_AUTO_SCAN
#define KEY_100_ENABLE
#define VOLUME_CUSTOMER_DEFINE_28
#ifdef USE_VOL_LIMTATION
//#define MAX_VOL_SHOW 28
#endif
#define LED_RUN_FAST_WHEN_PLAY_MODE_CHANGE
#define CUSTOMER_DEFINED_ADKEY_RESISTOR

#endif

#ifdef SW_V002_CUSTOMED_V002
#define LED_USE_PLAY_MODE

#define DEFAULT_GO_TO_AUX
#undef ADKEY_PLAY_SHORT_SCAN_FRE
#define ADKEY_NEXT_ADJST_FREQ
#define MUTE_PORT_USE_P01
#define SEMI_AUTO_SCAN_FREQ
#define IR_NEXT_PREV_HOLD_AUTO_SCAN
#define ADKEY_NEXT_PREV_HOLD_AUTO_SCAN
#define KEY_100_ENABLE
#define VOLUME_CUSTOMER_DEFINE_28
#ifdef USE_VOL_LIMTATION
//#define MAX_VOL_SHOW 28
#endif
#define LED_RUN_FAST_WHEN_PLAY_MODE_CHANGE
#define CUSTOMER_DEFINED_ADKEY_RESISTOR

#endif

#ifdef SW_V002_CUSTOMED_V003
#define LED_USE_PLAY_MODE

#undef ADKEY_PLAY_SHORT_SCAN_FRE
#define ADKEY_NEXT_ADJST_FREQ
#define MUTE_PORT_USE_P01
#define SEMI_AUTO_SCAN_FREQ
#define IR_NEXT_PREV_HOLD_AUTO_SCAN
#define ADKEY_NEXT_PREV_HOLD_AUTO_SCAN
#define KEY_100_ENABLE
#define NEW_CUSTOMED_VOLUME_DIVIDED_METHOD
#ifdef USE_VOL_LIMTATION
//#define MAX_VOL_SHOW 28
#endif
#define LED_RUN_FAST_WHEN_PLAY_MODE_CHANGE
#define CUSTOMER_DEFINED_ADKEY_RESISTOR

#endif


#ifdef SW_V002_RTC
#define LED_USE_PLAY_MODE

#undef ADKEY_PLAY_SHORT_SCAN_FRE
#define ADKEY_NEXT_ADJST_FREQ
#define MUTE_PORT_USE_P01
#define SEMI_AUTO_SCAN_FREQ
#define IR_NEXT_PREV_HOLD_AUTO_SCAN
#define ADKEY_NEXT_PREV_HOLD_AUTO_SCAN
#define KEY_100_ENABLE
#define VOLUME_CUSTOMER_DEFINE_28
#ifdef USE_VOL_LIMTATION
//#define MAX_VOL_SHOW 28
#endif
#define LED_RUN_FAST_WHEN_PLAY_MODE_CHANGE
#define CUSTOMER_DEFINED_ADKEY_RESISTOR

#define USE_RTC_FUNCTION
#define USE_RTC_TIME_ONLY
#define SYS_POWER_ON_DEFAULT_RTC_MODE

#endif

#ifdef K002_SW_002_Zhuoxin_V001
//#define LED_USE_PLAY_MODE
//#define SW_V002
#undef ADKEY_PLAY_SHORT_SCAN_FRE
#define ADKEY_NEXT_ADJST_FREQ
#define MUTE_PORT_USE_P01
#define SEMI_AUTO_SCAN_FREQ
#define IR_NEXT_PREV_HOLD_AUTO_SCAN
#define ADKEY_NEXT_PREV_HOLD_AUTO_SCAN
#define KEY_100_ENABLE
#define USE_VOL_LIMTATION
#ifdef USE_VOL_LIMTATION
#define MAX_VOL_SHOW 28
#endif
#define LED_RUN_FAST_WHEN_PLAY_MODE_CHANGE
#define CUSTOMER_DEFINED_ADKEY_RESISTOR

#endif

#ifdef K003_V001
#undef SW_V001
#undef SW_V002
#endif
#ifdef SW_V007
#undef _SHORT_PLAY_SCAN_FRE_
#define   MUTE_PORT_USE_P01
#define USE_VOL_LIMTATION
#ifdef USE_VOL_LIMTATION
#define MAX_VOL_SHOW 30
#endif
#endif

#ifdef SW_V007_502K
#undef _SHORT_PLAY_SCAN_FRE_
#define   MUTE_PORT_USE_P01
#define   NOT_USE_LINE_IN_FUNC
#define USE_VOL_LIMTATION
#ifdef USE_VOL_LIMTATION
#define MAX_VOL_SHOW 30
#endif
#endif

/*****************按 主板编号定义宏******************/
#ifdef K005_987_V001
#define ADKEY_PLAY_SHORT_SCAN_FRE
#define MUTE_PORT_USE_P01
#define NO_LED_DISPLAY
#endif

#ifdef K005_987_FOR_JLH_V001
#define ADKEY_PLAY_SHORT_SCAN_FRE
#define MUTE_PORT_USE_P01
#define DECODE_STOP_MODE_ENABLE
#define CUSTOMER_DEFINED_ADKEY_RESISTOR
//#define NO_LED_DISPLAY
#endif

#ifdef K009_968_MY_1008_V001

#ifdef IIC_GPIO_USE_P02_P03
#undef IIC_GPIO_USE_P02_P03
#endif
#define IIC_GPIO_USE_P00_P01
#ifdef MUTE_PORT_USE_P01
#undef  MUTE_PORT_USE_P01
#endif
#define MUTE_PORT_USE_P03

#define EXCHANGE_LINE_IN_CHANNEL	//交换LINE IN 通道

#define LED_USE_PLAY_MODE_MIXED
//#define MUTE_PORT_USE_P01
//#define ADKEY_PLAY_SHORT_SCAN_FRE
#define USE_VOL_LIMTATION
#define IR_REMOTER_WITH_POWER_MUTE_PRINT

#ifdef USE_VOL_LIMTATION
#define MAX_VOL_SHOW 30
#endif
#endif

#ifdef K009_968_SW006_V001
#define LED_USE_PLAY_STATUS
#define MUTE_PORT_USE_P01
//#define ADKEY_PLAY_SHORT_SCAN_FRE
#define USE_VOL_LIMTATION
#ifdef USE_VOL_LIMTATION
#define MAX_VOL_SHOW 30
#endif
#endif

#ifdef K009_968_SW006_ZHUOXIN_V001
#define LED_USE_PLAY_STATUS
#define MUTE_PORT_USE_P01
//#define ADKEY_PLAY_SHORT_SCAN_FRE
#define USE_VOL_LIMTATION
#define VOLUME_CUSTOMER_DEFINE_1
#ifdef USE_VOL_LIMTATION
#define MAX_VOL_SHOW 50
#endif
#endif

#ifdef K021_XXX_V001
#define ADKEY_PLAY_SHORT_SCAN_FRE
#define MUTE_PORT_USE_P01
#define NO_LED_DISPLAY
#endif

#ifdef K023_971_V001
#define MUTE_PORT_USE_P01
#define USE_GPIO_DETECT_EARPHONE_PLUGGED
#define INDEPENDENT_VOLUME_KEY
#define ADKEY_PLAY_SHORT_SCAN_FRE
#define USE_VOL_LIMTATION
#ifdef USE_VOL_LIMTATION
#define MAX_VOL_SHOW 30
#endif

#define USE_RTC_FUNCTION
#define USE_RTC_ALARM_FUNCTION

#endif

#ifdef K013_980_V001
#define USE_GPIO_DETECT_EARPHONE_PLUGGED
#define MUTE_PORT_USE_P01
#define NO_LED_DISPLAY
#endif


#ifdef K015_983_1_SW005_V001
#define LED_USE_PLAY_STATUS
#define MUTE_PORT_USE_P01
//#define ADKEY_PLAY_SHORT_SCAN_FRE
//#define IR_USER_CODE_0x7F80
//#define IR_REMOTER_WITH_POWER_MUTE_PRINT
#define KEY_100_ENABLE

#endif

#ifdef K015_983_JLH_VOL50_V001
#define LED_USE_PLAY_STATUS
#define MUTE_PORT_USE_P01
//#define ADKEY_PLAY_SHORT_SCAN_FRE
#define USE_USB_AUDIO

#define IR_NEXT_PREV_SHORT_ADJ_CH
#define IR_NEXT_PREV_HOLD_AUTO_SCAN
#define SEMI_AUTO_SCAN_FREQ
#define NEW_CUSTOMED_VOLUME_DIVIDED_METHOD

#endif

#ifdef K015_983_JLH_SW005D_V001
#define LED_USE_PLAY_MODE
#define MUTE_PORT_USE_P01
//#define ADKEY_PLAY_SHORT_SCAN_FRE
#define VOLUME_CUSTOMER_DEFINE_28
#define KEY_100_ENABLE

#define ADKEY_PLAY_SHORT_ADJ_CH
//#define IR_NEXT_PREV_SHORT_ADJ_CH
#define IR_NEXT_PREV_HOLD_AUTO_SCAN
#define SEMI_AUTO_SCAN_FREQ
#define ADKEY_NEXT_PREV_HOLD_AUTO_SCAN
#define ADKEY_NEXT_ADJST_FREQ
#endif

#ifdef K015_983_JLH_A2016_V002
#define LED_USE_PLAY_STATUS
#define MUTE_PORT_USE_P01
#define DEFAULT_GO_TO_AUX
#define USE_USB_AUDIO
#define KEY_100_ENABLE
#define EQ_MODE_DEFUALT_POP
//#define IR_NEXT_PREV_HOLD_AUTO_SCAN
//#define SEMI_AUTO_SCAN_FREQ

#endif

#ifdef K015_983_JLH_A2016_V001
#define LED_USE_PLAY_STATUS
#define MUTE_PORT_USE_P01
#define DEFAULT_GO_TO_AUX
#define USE_USB_AUDIO
#define KEY_100_ENABLE
//#define IR_NEXT_PREV_SHORT_ADJ_CH
//#define IR_NEXT_PREV_HOLD_AUTO_SCAN
//#define SEMI_AUTO_SCAN_FREQ

#endif

#ifdef K015_983_JLH_V002
#define LED_USE_PLAY_STATUS
#define MUTE_PORT_USE_P01
//#define ADKEY_PLAY_SHORT_SCAN_FRE
#define USE_USB_AUDIO
#define KEY_100_ENABLE

#define IR_NEXT_PREV_SHORT_ADJ_CH
#define IR_NEXT_PREV_HOLD_AUTO_SCAN
#define SEMI_AUTO_SCAN_FREQ

#endif

#ifdef K015_983_JLH_V001
#define LED_USE_PLAY_STATUS
#define MUTE_PORT_USE_P01
//#define ADKEY_PLAY_SHORT_SCAN_FRE
#define USE_USB_AUDIO
#define KEY_100_ENABLE

#define IR_NEXT_PREV_SHORT_ADJ_CH
#define IR_NEXT_PREV_HOLD_AUTO_SCAN
#define SEMI_AUTO_SCAN_FREQ

#endif


#ifdef K015_983_SW005_AMFM_V001

#define LED_USE_PLAY_STATUS
#define MUTE_PORT_USE_P01
#define RADIO_AM_WM_ENABLE
#define FM_USE_KT0913
//#define ADKEY_PLAY_SHORT_SCAN_FRE

#endif

#ifdef K015_983_SW005_WQ747_V001
#define LED_USE_PLAY_STATUS
#define MUTE_PORT_USE_P01
#define DEFAULT_GO_TO_IDLE
#define VOLUME_DEFUALT 30
#endif

#ifdef K015_983_SW005_V001
#define LED_USE_PLAY_STATUS
#define MUTE_PORT_USE_P01
//#define ADKEY_PLAY_SHORT_SCAN_FRE
#endif

#ifdef K015_983_SW005_ZX_V001
#define LED_USE_PLAY_STATUS
#define MUTE_PORT_USE_P01
//#define ADKEY_PLAY_SHORT_SCAN_FRE
#define USB_SD_PLAY_INFO_DIV
#define VOLUME_DEFUALT 30
#endif

#ifdef K015_983_SW005_V8
#define LED_USE_PLAY_STATUS
#define MUTE_PORT_USE_P01
//#define ADKEY_PLAY_SHORT_SCAN_FRE
#define USE_GPIO_DETECT_EARPHONE_PLUGGED
#define EARPHONE_DETECT_USE_P04
#endif


#ifdef K015_983_SW005_ZhuoXin_V002
#define LED_USE_PLAY_STATUS
#define MUTE_PORT_USE_P01
//#define ADKEY_PLAY_SHORT_SCAN_FRE
#define VOLUME_CUSTOMER_DEFINE_1
#define MAX_VOL_SHOW 50
//#define VOLUME_DEFUALT 50
#define USB_SD_PLAY_INFO_DIV
#define TURN_ON_PLAY_BREAK_POINT_MEM
#define KEY_10_ENABLE
//#define IR_REMOTER_WITH_POWER_MUTE_PRINT
#define USE_TWO_IR_REMOTE
#endif

#ifdef K015_983_SW005_ZhuoXin_V001
#define LED_USE_PLAY_STATUS
#define MUTE_PORT_USE_P01
//#define ADKEY_PLAY_SHORT_SCAN_FRE
#define VOLUME_CUSTOMER_DEFINE_1
#define MAX_VOL_SHOW 50
#define VOLUME_DEFUALT 50
#define USB_SD_PLAY_INFO_DIV
#define TURN_ON_PLAY_BREAK_POINT_MEM
#define IR_REMOTER_WITH_POWER_MUTE_PRINT
#endif

#ifdef K015_983_SW005_ZhuoXin_FB001_V001
#define LED_USE_PLAY_STATUS
#define MUTE_PORT_USE_P01
//#define ADKEY_PLAY_SHORT_SCAN_FRE
//#define VOLUME_CUSTOMER_DEFINE_1
//#define MAX_VOL_SHOW 50
//#define IR_REMOTER_WITH_POWER_MUTE_PRINT
#define SEMI_AUTO_SCAN_FREQ
//#define IR_NEXT_PREV_HOLD_AUTO_SCAN
//#define IR_NEXT_PREV_SHORT_ADJ_CH
#define USB_SD_PLAY_INFO_DIV
//#define USE_BAT_MANAGEMENT
//#define NOT_USE_LINE_IN_FUNC	//打开此宏来关闭AUX功能
#define USE_VOL_LIMTATION
#define MAX_VOL_SHOW 30
#define VOLUME_DEFUALT 27
#define IR_USER_CODE_0xBF00
#define KEY_10_ENABLE
//#define INDEPENDENT_VOLUME_KEY
#define IR_NEXT_PREV_SHORT_ADJ_CH

#endif
#ifdef K015_983_SW005_ZhuoXin_KL001_V002
#define LED_USE_PLAY_STATUS
#define MUTE_PORT_USE_P01
#define DAC_MUTE_IN_IDLE_MODE
//#define VOLUME_CUSTOMER_DEFINE_1
//#define MAX_VOL_SHOW 50
#define IR_REMOTER_WITH_POWER_MUTE_PRINT
#define SEMI_AUTO_SCAN_FREQ
//#define IR_NEXT_PREV_HOLD_AUTO_SCAN
//#define IR_NEXT_PREV_SHORT_ADJ_CH
#define USB_SD_PLAY_INFO_DIV
//#define USE_BAT_MANAGEMENT
#define NOT_USE_LINE_IN_FUNC	//打开此宏来关闭AUX功能
#define USE_VOL_LIMTATION
#define MAX_VOL_SHOW 30
#define VOLUME_DEFUALT 27

#endif

#ifdef K015_983_SW005_ZhuoXin_KL001_V001
#define LED_USE_PLAY_STATUS
#define MUTE_PORT_USE_P01
//#define ADKEY_PLAY_SHORT_SCAN_FRE
//#define VOLUME_CUSTOMER_DEFINE_1
//#define MAX_VOL_SHOW 50
#define IR_REMOTER_WITH_POWER_MUTE_PRINT
#define SEMI_AUTO_SCAN_FREQ
//#define IR_NEXT_PREV_HOLD_AUTO_SCAN
//#define IR_NEXT_PREV_SHORT_ADJ_CH
#define USB_SD_PLAY_INFO_DIV
//#define USE_BAT_MANAGEMENT
#define NOT_USE_LINE_IN_FUNC	//打开此宏来关闭AUX功能
#define USE_VOL_LIMTATION
#define MAX_VOL_SHOW 30
#define VOLUME_DEFUALT 27

#endif
#ifdef K015_983_SW005_ZhuoXin_KL002_V001
#define LED_USE_PLAY_STATUS
#define MUTE_PORT_USE_P01
//#define ADKEY_PLAY_SHORT_SCAN_FRE
//#define VOLUME_CUSTOMER_DEFINE_1
//#define MAX_VOL_SHOW 50
#define IR_REMOTER_WITH_POWER_MUTE_PRINT
#define SEMI_AUTO_SCAN_FREQ
//#define IR_NEXT_PREV_HOLD_AUTO_SCAN
//#define IR_NEXT_PREV_SHORT_ADJ_CH
#define USB_SD_PLAY_INFO_DIV
//#define USE_BAT_MANAGEMENT
//#define NOT_USE_LINE_IN_FUNC	//打开此宏来关闭AUX功能
#define USE_VOL_LIMTATION
#define MAX_VOL_SHOW 30
#define VOLUME_DEFUALT 27

#endif

#ifdef K015_983_SW005_ZhuoXin_JR001_V001
#define LED_USE_PLAY_STATUS
#define MUTE_PORT_USE_P01
//#define ADKEY_PLAY_SHORT_SCAN_FRE
#define VOLUME_CUSTOMER_DEFINE_1
#define MAX_VOL_SHOW 50
#define IR_REMOTER_WITH_POWER_MUTE_PRINT
#define SEMI_AUTO_SCAN_FREQ
#define IR_NEXT_PREV_HOLD_AUTO_SCAN
#define IR_NEXT_PREV_SHORT_ADJ_CH
#define USB_SD_PLAY_INFO_DIV
#define USE_BAT_MANAGEMENT
#endif

#ifdef Kxxx_931_V001
#define LED_USE_PLAY_STATUS
#define MUTE_PORT_USE_P01
#define ADKEY_PLAY_SHORT_SCAN_FRE
#endif

#ifdef K011_011_V001
#define MUTE_PORT_USE_P01
#define ADKEY_PLAY_SHORT_SCAN_FRE
#define USE_GPIO_DETECT_EARPHONE_PLUGGED
//#define INDEPENDENT_VOLUME_KEY
#define USE_VOL_LIMTATION
#define USE_USB_AUDIO

#ifdef USE_VOL_LIMTATION
#define MAX_VOL_SHOW 30
#endif
#define LED_USE_1X888
#endif

#ifdef K080_YJH_985_V001
#define MUTE_PORT_USE_P01
#define ADKEY_PLAY_SHORT_SCAN_FRE
#define USE_GPIO_DETECT_EARPHONE_PLUGGED
#define INDEPENDENT_VOLUME_KEY
#define USE_VOL_LIMTATION
#define EXCHANGE_LINE_IN_CHANNEL	//交换LINE IN 通道
#define NO_PLAY_STATUS_LED
#define _KEY_TONE_ENABEL_

#ifdef USE_VOL_LIMTATION
#define MAX_VOL_SHOW 30
#endif
#define LED_USE_1X888
#endif

#ifdef K081_YJH_973_V001
#define MUTE_PORT_USE_P01
#define ADKEY_PLAY_SHORT_SCAN_FRE
#define USE_GPIO_DETECT_EARPHONE_PLUGGED
//#define INDEPENDENT_VOLUME_KEY
#define USE_VOL_LIMTATION
#define EXCHANGE_LINE_IN_CHANNEL	//交换LINE IN 通道
#define NO_PLAY_STATUS_LED
#define _KEY_TONE_ENABEL_

#ifdef USE_VOL_LIMTATION
#define MAX_VOL_SHOW 30
#endif
#define LED_USE_1X888
#endif

#ifdef K025_XXX_V001
#define MUTE_PORT_USE_P01
#define ADKEY_PLAY_SHORT_SCAN_FRE
#define USE_GPIO_DETECT_EARPHONE_PLUGGED
//#define INDEPENDENT_VOLUME_KEY
#define USE_VOL_LIMTATION

#ifdef USE_VOL_LIMTATION
#define MAX_VOL_SHOW 30
#endif
#define LED_USE_1X888
#endif


#ifdef K037_XXX_V001
#define MUTE_PORT_USE_P01
#define ADKEY_PLAY_SHORT_SCAN_FRE
//#define USE_GPIO_DETECT_EARPHONE_PLUGGED
#define INDEPENDENT_VOLUME_KEY
#define USE_VOL_LIMTATION
#define DECODE_STOP_MODE_ENABLE

#ifdef USE_VOL_LIMTATION
#define MAX_VOL_SHOW 30
#endif
#define LED_USE_1X888
#endif


#ifdef K026_XXX_V001
#define MUTE_PORT_USE_P01
#define USE_GPIO_DETECT_EARPHONE_PLUGGED
#define NO_LED_DISPLAY
#endif

#ifdef K031_XXX_V001
#define MUTE_PORT_USE_P01
#define NO_LED_DISPLAY
#define NOT_USE_LINE_IN_FUNC
#define ADKEY_PLAY_SHORT_SCAN_FRE
#define USE_LONG_PLAY_KEY_TO_SWITCH_MODE
#endif

#ifdef K085_YJH_085_V001
#define ADKEY_PLAY_SHORT_SCAN_FRE
#define MUTE_PORT_USE_P01
#define NOT_USE_LINE_IN_FUNC
#define POWE_KEY_PLAY_KEY_IN_ONE_KEY
#define NO_LED_DISPLAY
#endif

#ifdef K116_FXK_V001
#ifdef MUTE_PORT_USE_P01
#undef  MUTE_PORT_USE_P01
#endif
#define MUTE_PORT_USE_P03
#define USE_GPIO_DETECT_EARPHONE_PLUGGED
//#define USE_LONG_PLAY_KEY_TO_SWITCH_MODE
#ifdef IIC_GPIO_USE_P02_P03
#undef IIC_GPIO_USE_P02_P03
#endif
#define IIC_GPIO_USE_P00_P01
#define NO_PLAY_STATUS_LED
#define USE_LINE_IN_DETECT_FUNC	//打开此宏来启动LINE IN 检测功能
#define SEMI_AUTO_SCAN_FREQ	//半自动搜台
#define NO_VOLUME_LIMITE
#define USE_USB_AUDIO
#define USE_CL6017G_FM
#define ADKEY_NEXT_PREV_SHORT_AUTO_SCAN
#define ADKEY_PLAY_SHORT_ADJ_CH
#define USE_SYS_MODE_RECOVER
#endif

#ifdef K128_YJH_128_V001
#ifdef IIC_GPIO_USE_P02_P03
#undef IIC_GPIO_USE_P02_P03
#endif
#define IIC_GPIO_USE_P00_P01
#ifdef MUTE_PORT_USE_P01
#undef  MUTE_PORT_USE_P01
#endif
#define MUTE_PORT_USE_P03

#define ADKEY_PLAY_SHORT_SCAN_FRE
#define USE_GPIO_DETECT_EARPHONE_PLUGGED
//#define INDEPENDENT_VOLUME_KEY
#define USE_VOL_LIMTATION
#define EXCHANGE_LINE_IN_CHANNEL	//交换LINE IN 通道

#ifdef USE_VOL_LIMTATION
#define MAX_VOL_SHOW 30
#endif
#define LED_USE_1X888
#define  GPIO_SWITCH_SELECT_MODE

#endif

#ifdef K133_QDX_133_V001
#define LED_GPIO_DRV		//GPIO直接驱动LED
#ifdef IIC_GPIO_USE_P02_P03
#undef IIC_GPIO_USE_P02_P03
#endif
#define IIC_GPIO_USE_P00_P01
#ifdef MUTE_PORT_USE_P01
#undef MUTE_PORT_USE_P01
#endif
#define MUTE_PORT_USE_P03
#define LED_USE_ROUND_LED
#define EXCHANGE_LINE_IN_CHANNEL	//交换LINE IN 通道

#endif


#ifdef K591_JiaLe_591_V001

#define LED_GPIO_DRV		//GPIO直接驱动LED
#ifdef IIC_GPIO_USE_P02_P03
#undef IIC_GPIO_USE_P02_P03
#endif
#define IIC_GPIO_USE_P00_P01
#ifdef MUTE_PORT_USE_P01
#undef MUTE_PORT_USE_P01
#endif
#define MUTE_PORT_USE_P03
#define LED_USE_ROUND_LED
#define LED_USE_PLAY_MODE

#define EXCHANGE_LINE_IN_CHANNEL	//交换LINE IN 通道
#define PLAY_MODE_REPEAT_ALL
//#define EQ_MODE_DEFUALT_ROCK
#define USE_GPIO_DETECT_EARPHONE_PLUGGED
//#define INDEPENDENT_VOLUME_KEY
#define VOLUME_DEFUALT 25

#define CHARGER_DETECT_INDICATOR
#define USE_BAT_MANAGEMENT

#endif

#ifdef K162_QDX_162_V001
#define LED_GPIO_DRV		//GPIO直接驱动LED
#ifdef IIC_GPIO_USE_P02_P03
#undef IIC_GPIO_USE_P02_P03
#endif
#define IIC_GPIO_USE_P00_P01
#ifdef MUTE_PORT_USE_P01
#undef MUTE_PORT_USE_P01
#endif
#define MUTE_PORT_USE_P03
#define LED_USE_ROUND_LED
#define EXCHANGE_LINE_IN_CHANNEL	//交换LINE IN 通道
#define PLAY_MODE_REPEAT_ALL
#define EQ_MODE_DEFUALT_ROCK
#define USE_GPIO_DETECT_EARPHONE_PLUGGED

#endif

#ifdef K105_SWD_2901_V001
#ifdef LED_GPIO_DRV
#undef LED_GPIO_DRV
#endif
#define USE_LCD_DRV_HT1621
#define ADKEY_PLAY_SHORT_SCAN_FRE
#define LINE_IN_PLAY_KEY_PAUSE
#define IR_USER_CODE_0x7F80
#define IR_REMOTER_WITH_POWER_MUTE_PRINT
#define IR_NEXT_PREV_SHORT_ADJ_CH
#define IR_NEXT_PREV_HOLD_AUTO_SCAN
#define IR_PLAY_KEY_SCAN_FREQ_DISABLE
#define SEMI_AUTO_SCAN_FREQ

#endif

#ifdef K105_SWD_2901A_V001
#ifdef LED_GPIO_DRV
#undef LED_GPIO_DRV
#endif
#define USE_LCD_DRV_HT1621
#define ADKEY_PLAY_SHORT_SCAN_FRE
#define LINE_IN_PLAY_KEY_PAUSE
#define IR_USER_CODE_0x7F80
#define IR_REMOTER_WITH_POWER_MUTE_PRINT
#define IR_NEXT_PREV_SHORT_ADJ_CH
#define IR_NEXT_PREV_HOLD_AUTO_SCAN
#define IR_PLAY_KEY_SCAN_FREQ_DISABLE
#define SEMI_AUTO_SCAN_FREQ
#define SWD_NEW_LCD_BOARD
#endif

#ifdef K122_SWD_122_V001
#ifdef IIC_GPIO_USE_P02_P03
#undef IIC_GPIO_USE_P02_P03
#endif
#define IIC_GPIO_USE_P00_P01
#ifdef MUTE_PORT_USE_P01
#undef  MUTE_PORT_USE_P01
#endif
#define MUTE_PORT_USE_P03
#define EXCHANGE_LINE_IN_CHANNEL	//交换LINE IN 通道
#define LED_USE_1X888
#define USE_CL6017G_FM
#define NOT_USE_LINE_IN_FUNC	//无LINE 功能
#define IR_USER_CODE_0x7F80
#define IR_REMOTER_WITH_POWER_MUTE_PRINT
#define IR_NEXT_PREV_SHORT_ADJ_CH
#define IR_NEXT_PREV_HOLD_AUTO_SCAN
#define IR_PLAY_KEY_SCAN_FREQ_DISABLE
#define USE_QN8035_FM

#endif

#ifdef K196_MN_196_V001

#ifdef IIC_GPIO_USE_P02_P03
#undef IIC_GPIO_USE_P02_P03
#endif
#define IIC_GPIO_USE_P00_P01

#ifdef MUTE_PORT_USE_P01
#undef  MUTE_PORT_USE_P01
#endif
#define MUTE_PORT_USE_P03
#define EXCHANGE_LINE_IN_CHANNEL	//交换LINE IN 通道
#define LED_USE_PLAY_STATUS

#define IR_REMOTER_WITH_POWER_MUTE_PRINT
#define IR_NEXT_PREV_SHORT_ADJ_CH
#define IR_NEXT_PREV_HOLD_AUTO_SCAN
#define IR_PLAY_KEY_SCAN_FREQ_DISABLE
//#define INDEPENDENT_VOLUME_KEY

#endif

/************************************************************
*	28PIN BOARD DEFINE
************************************************************/
#ifdef  K088_JLH_23108_V001
#define AC209_28PIN		//28 PIN IC GPIO CONFIG
#define EXCHANGE_LINE_IN_CHANNEL	//交换LINE IN 通道
#undef USE_BK1080_FM
//#define NO_LED_DISPLAY
#define USE_POWER_KEY
#define NOT_USE_LINE_IN_FUNC	//无LINE 功能
#define POWE_KEY_PLAY_KEY_IN_ONE_KEY	//PLAY POWER 共用一个按键
#define VOLUME_DEFUALT 27
#define USE_RTC_RAM_FUNC
#ifdef MUTE_CTRL_LEVEL_NORMAL
#undef MUTE_CTRL_LEVEL_NORMAL
#endif
#define  POWER_KEY_ON_WAIT_FOR_3_SEC
#define  SYS_GO_IN_IDLE_IN_30_SEC

#ifdef MUTE_CTRL_LEVEL_NORMAL
#undef MUTE_CTRL_LEVEL_NORMAL
#endif
#endif

#ifdef  K113_SW_113_V001
#define AC209_28PIN		//28 PIN IC GPIO CONFIG
//#define NO_LED_DISPLAY
#ifdef IIC_GPIO_USE_P02_P03
#undef IIC_GPIO_USE_P02_P03
#endif
#define IIC_GPIO_USE_P00_P01
#ifdef MUTE_PORT_USE_P01
#undef MUTE_PORT_USE_P01
#endif
#define PLAY_STATUS_LED_P27
#define VOLUME_DEFUALT 27
#define NOT_USE_LINE_IN_FUNC
#define USE_MANUAL_IDLE_FUNC		//手动切换到IDLE

#endif

#ifdef  K115_SW_115_V001
#define AC209_28PIN		//28 PIN IC GPIO CONFIG
//#define NO_LED_DISPLAY
#ifdef IIC_GPIO_USE_P02_P03
#undef IIC_GPIO_USE_P02_P03
#endif
#define IIC_GPIO_USE_P00_P01
#ifdef MUTE_PORT_USE_P01
#undef MUTE_PORT_USE_P01
#endif
#define PLAY_STATUS_LED_P27
#define LINE_IN_DETECT_SHARE_LED_STATUS_PORT	//打开此宏来启动LINE IN 检测功能
#define VOLUME_DEFUALT 27
#define FM_BY_PASS

#endif

#ifdef  K163_ZHHB_163_V001
#define AC209_28PIN		//28 PIN IC GPIO CONFIG
//#define NO_LED_DISPLAY
#ifdef IIC_GPIO_USE_P02_P03
#undef IIC_GPIO_USE_P02_P03
#endif
#define IIC_GPIO_USE_P00_P01
#ifdef MUTE_PORT_USE_P01
#undef MUTE_PORT_USE_P01
#endif
#define PLAY_STATUS_LED_P27
#define AUX_DETECT_USE_P02
#define FM_BY_PASS

#endif


#ifdef  K169_KR_169_V001
#define AC209_28PIN		//28 PIN IC GPIO CONFIG
//#define NO_LED_DISPLAY
#ifdef IIC_GPIO_USE_P02_P03
#undef IIC_GPIO_USE_P02_P03
#endif
#define IIC_GPIO_USE_P00_P01
#ifdef MUTE_PORT_USE_P01
#undef MUTE_PORT_USE_P01
#endif
#define PLAY_STATUS_LED_P27
#define NOT_USE_LINE_IN_FUNC
#undef USE_BK1080_FM

#endif

#ifdef  K000_DT_078_V001

#define AC209_28PIN		//28 PIN IC GPIO CONFIG

#ifdef IIC_GPIO_USE_P02_P03
#undef IIC_GPIO_USE_P02_P03
#endif
#define IIC_GPIO_USE_P01_P02

#ifdef MUTE_PORT_USE_P01
#undef MUTE_PORT_USE_P01
#endif
#define MUTE_PORT_USE_P00

#define PLAY_STATUS_LED_P27
#define EXCHANGE_LINE_IN_CHANNEL	//交换LINE IN 通道
//#define SYS_CRYSTAL_USE_24M
#define FM_BY_PASS

#endif

#ifdef  K188_YJH_188_V002
#define AC209_28PIN		//28 PIN IC GPIO CONFIG
//#define NO_LED_DISPLAY
#ifdef IIC_GPIO_USE_P02_P03
#undef IIC_GPIO_USE_P02_P03
#endif
#define IIC_GPIO_USE_P00_P01
#ifdef MUTE_PORT_USE_P01
#undef MUTE_PORT_USE_P01
#endif
#define PLAY_STATUS_LED_P27
//#define AUX_DETECT_USE_P02
//#define USE_LINE_IN_DETECT_FUNC	//打开此宏来启动LINE IN 检测功能
//#define USE_GPIO_DETECT_EARPHONE_PLUGGED
//#define INDEPENDENT_VOLUME_KEY

#define VOLUME_DEFUALT 16
#define FM_BY_PASS
#define USE_LONG_PLAY_KEY_TO_SWITCH_MODE
#define ADKEY_PLAY_SHORT_SCAN_FRE
#define _KEY_TONE_ENABEL_

#endif

#ifdef  K188_YJH_188_V001
#define AC209_28PIN		//28 PIN IC GPIO CONFIG
//#define NO_LED_DISPLAY
#ifdef IIC_GPIO_USE_P02_P03
#undef IIC_GPIO_USE_P02_P03
#endif
#define IIC_GPIO_USE_P00_P01
#ifdef MUTE_PORT_USE_P01
#undef MUTE_PORT_USE_P01
#endif
#define PLAY_STATUS_LED_P27
#define CUSTOMER_DEFINED_ADKEY_RESISTOR
//#define USE_LINE_IN_DETECT_FUNC	//打开此宏来启动LINE IN 检测功能
//#define USE_GPIO_DETECT_EARPHONE_PLUGGED
#define INDEPENDENT_VOLUME_KEY

#define VOLUME_DEFUALT 16
#define FM_BY_PASS
#define USE_LONG_PLAY_KEY_TO_SWITCH_MODE
#define ADKEY_PLAY_SHORT_SCAN_FRE
#define _KEY_TONE_ENABEL_

#define TURN_ON_PLAY_BREAK_POINT_MEM

#endif

#ifdef  K188_YJH_188_V004

#define AC209_28PIN		//28 PIN IC GPIO CONFIG
//#define NO_LED_DISPLAY
#ifdef IIC_GPIO_USE_P02_P03
#undef IIC_GPIO_USE_P02_P03
#endif
#define IIC_GPIO_USE_P00_P01
#ifdef MUTE_PORT_USE_P01
#undef MUTE_PORT_USE_P01
#endif
#define MUTE_PORT_USE_P26

#define PLAY_STATUS_LED_P27

#define EXCHANGE_LINE_IN_CHANNEL	//交换LINE IN 通道

#define CUSTOMER_DEFINED_ADKEY_RESISTOR

#define INDEPENDENT_VOLUME_KEY

#define VOLUME_DEFUALT 16
#define FM_BY_PASS
#define USE_LONG_PLAY_KEY_TO_SWITCH_MODE
#define ADKEY_PLAY_SHORT_SCAN_FRE
#define _KEY_TONE_ENABEL_

#define DEFAULT_GO_TO_IDLE

//#define TURN_ON_PLAY_BREAK_POINT_MEM

#endif


#ifdef  K188_YJH_188_V003
#define AC209_28PIN		//28 PIN IC GPIO CONFIG
//#define NO_LED_DISPLAY
#ifdef IIC_GPIO_USE_P02_P03
#undef IIC_GPIO_USE_P02_P03
#endif
#define IIC_GPIO_USE_P00_P01
#ifdef MUTE_PORT_USE_P01
#undef MUTE_PORT_USE_P01
#endif
#define PLAY_STATUS_LED_P27
#define CUSTOMER_DEFINED_ADKEY_RESISTOR
//#define USE_LINE_IN_DETECT_FUNC	//打开此宏来启动LINE IN 检测功能
//#define USE_GPIO_DETECT_EARPHONE_PLUGGED
#define INDEPENDENT_VOLUME_KEY

#define VOLUME_DEFUALT 16
#define FM_BY_PASS
//#define USE_LONG_PLAY_KEY_TO_SWITCH_MODE
#define USE_LONG_PLAY_KEY_TO_RESET_SONG_NUM

#define ADKEY_PLAY_SHORT_SCAN_FRE
#define _KEY_TONE_ENABEL_

#define NOT_USE_LINE_IN_FUNC

//#define TURN_ON_PLAY_BREAK_POINT_MEM

#endif


#ifdef  K139_YDS_xxx_V001
#define AC209_28PIN		//28 PIN IC GPIO CONFIG
#ifdef IIC_GPIO_USE_P02_P03
#undef IIC_GPIO_USE_P02_P03
#endif
#define IIC_GPIO_USE_P00_P01

#ifdef MUTE_PORT_USE_P01
#undef MUTE_PORT_USE_P01
#endif
#define DECODE_STOP_MODE_ENABLE
#define PLAY_LONG_PRESS_STOP
#define INDEPENDENT_VOLUME_KEY
#define VOLUME_DEFUALT 27
#define PLAY_STATUS_LED_P27
#define FM_BY_PASS
#define AUX_DETECT_USE_P02
#define USE_LINE_IN_DETECT_FUNC	//打开此宏来启动LINE IN 检测功能
#endif

#ifdef  K139_FuWei_xxx_V001
#define AC209_28PIN		//28 PIN IC GPIO CONFIG
#ifdef IIC_GPIO_USE_P02_P03
#undef IIC_GPIO_USE_P02_P03
#endif
#define IIC_GPIO_USE_P00_P01

#ifdef MUTE_PORT_USE_P01
#undef MUTE_PORT_USE_P01
#endif
#define INDEPENDENT_VOLUME_KEY
#define VOLUME_DEFUALT 27
#define PLAY_STATUS_LED_P27
#define FM_BY_PASS
//#define AUX_DETECT_USE_P02
//#define USE_LINE_IN_DETECT_FUNC	//打开此宏来启动LINE IN 检测功能
#endif

#ifdef  K139_JLH_xxx_V001
#define AC209_28PIN		//28 PIN IC GPIO CONFIG
#ifdef IIC_GPIO_USE_P02_P03
#undef IIC_GPIO_USE_P02_P03
#endif
#define IIC_GPIO_USE_P00_P01

#ifdef MUTE_PORT_USE_P01
#undef MUTE_PORT_USE_P01
#endif

#define VOLUME_DEFUALT 27
#define PLAY_STATUS_LED_P27
#define FM_BY_PASS
#define AUX_DETECT_USE_P02
#define USE_LINE_IN_DETECT_FUNC	//打开此宏来启动LINE IN 检测功能
#endif

#ifdef K109_SW001D_V001
#define AC209_28PIN		//28 PIN IC GPIO CONFIG
#define VOLUME_DEFUALT 	27
#define NO_LED_DISPLAY
//#define ADC_DETECT_LINE_IN
#define FM_BY_PASS
#undef ADKEY_PLAY_SHORT_SCAN_FRE
#define CUSTOMER_DEFINED_ADKEY_RESISTOR
#define LED_RUN_FAST_WHEN_PLAY_MODE_CHANGE

#ifdef IIC_GPIO_USE_P02_P03
#undef IIC_GPIO_USE_P02_P03
#endif
#define IIC_GPIO_USE_P00_P01
#ifdef MUTE_PORT_USE_P01
#undef MUTE_PORT_USE_P01
#endif

#define PLAY_STATUS_LED_P27

#endif


#ifdef K198_SW198_V001
#define AC209_28PIN		//28 PIN IC GPIO CONFIG
#ifdef IIC_GPIO_USE_P02_P03
#undef IIC_GPIO_USE_P02_P03
#endif
#define IIC_GPIO_USE_P00_P01

#ifdef MUTE_PORT_USE_P01
#undef MUTE_PORT_USE_P01
#endif

//#define VOLUME_DEFUALT 27
#define PLAY_STATUS_LED_P27
#define FM_BY_PASS
#define NOT_USE_LINE_IN_FUNC

#endif

#ifdef K801_TC_801_V002
#define AC209_28PIN		//28 PIN IC GPIO CONFIG
#ifdef IIC_GPIO_USE_P02_P03
#undef IIC_GPIO_USE_P02_P03
#endif
#define IIC_GPIO_USE_P00_P01
#define TianCheng_Remote
#ifdef MUTE_PORT_USE_P01
#undef MUTE_PORT_USE_P01
#endif
#define MUTE_PORT_USE_P27
#define USE_FM_GPIO
#define MUTE_GPIO_FM_GPIO_COMPATIBALE

#define VOLUME_DEFUALT 27
//#define PLAY_STATUS_LED_P02
#define PLAY_MODE_USE_REP_ONE_ALL
#define DEFAULT_GO_TO_AUX

//#define INDEPENDENT_VOLUME_KEY
//#define NEXT_PREV_HOLD_DO_NOTHING

#define EXCHANGE_LINE_IN_CHANNEL	//交换LINE IN 通道
//#define CUSTOMER_DEFINED_ADKEY_RESISTOR

#define SEMI_AUTO_SCAN_FREQ
#define ADKEY_NEXT_PREV_HOLD_AUTO_SCAN
#define IR_NEXT_PREV_HOLD_AUTO_SCAN
#define IR_NEXT_PREV_SHORT_ADJ_CH
#endif

#ifdef K801_TC_801_V001_XC
#define AC209_28PIN		//28 PIN IC GPIO CONFIG
#ifdef IIC_GPIO_USE_P02_P03
#undef IIC_GPIO_USE_P02_P03
#endif
#define IIC_GPIO_USE_P00_P01
#define TianCheng_Remote
#ifdef MUTE_PORT_USE_P01
#undef MUTE_PORT_USE_P01
#endif
#define MUTE_PORT_USE_P27
#define USE_FM_GPIO
#define MUTE_GPIO_FM_GPIO_COMPATIBALE

#define VOLUME_DEFUALT 27
#define NEXT_PREV_HOLD_DO_NOTHING
#define PLAY_MODE_USE_REP_ONE_ALL


#define EXCHANGE_LINE_IN_CHANNEL	//交换LINE IN 通道
#define INDEPENDENT_VOLUME_KEY

#define SEMI_AUTO_SCAN_FREQ
#define ADKEY_NEXT_PREV_HOLD_AUTO_SCAN
#define IR_NEXT_PREV_HOLD_AUTO_SCAN
#define IR_NEXT_PREV_SHORT_ADJ_CH
#endif

#ifdef K801_TC_801_V003
#define AC209_28PIN		//28 PIN IC GPIO CONFIG
#ifdef IIC_GPIO_USE_P02_P03
#undef IIC_GPIO_USE_P02_P03
#endif
#define IIC_GPIO_USE_P00_P01
#define TianCheng_Remote
#ifdef MUTE_PORT_USE_P01
#undef MUTE_PORT_USE_P01
#endif
#define MUTE_PORT_USE_P27
#define USE_FM_GPIO
#define MUTE_GPIO_FM_GPIO_COMPATIBALE

#define VOLUME_DEFUALT 27
//#define PLAY_STATUS_LED_P02
#define PLAY_MODE_USE_REP_ONE_ALL
#define TURN_ON_PLAY_BREAK_POINT_MEM


#define EXCHANGE_LINE_IN_CHANNEL	//交换LINE IN 通道
//#define CUSTOMER_DEFINED_ADKEY_RESISTOR
#define ADKEY_PLAY_SHORT_SCAN_FRE
#define USE_LONG_PLAY_KEY_TO_SWITCH_MODE

#define SEMI_AUTO_SCAN_FREQ
#define ADKEY_NEXT_PREV_HOLD_AUTO_SCAN
#define IR_NEXT_PREV_HOLD_AUTO_SCAN
#define IR_NEXT_PREV_SHORT_ADJ_CH
#endif


#ifdef K801_TC_801_V001
#define AC209_28PIN		//28 PIN IC GPIO CONFIG
#ifdef IIC_GPIO_USE_P02_P03
#undef IIC_GPIO_USE_P02_P03
#endif
#define IIC_GPIO_USE_P00_P01
#define TianCheng_Remote
#ifdef MUTE_PORT_USE_P01
#undef MUTE_PORT_USE_P01
#endif
#define MUTE_PORT_USE_P27
#define USE_FM_GPIO
#define MUTE_GPIO_FM_GPIO_COMPATIBALE

#define VOLUME_DEFUALT 27
//#define PLAY_STATUS_LED_P02
#define PLAY_MODE_USE_REP_ONE_ALL
#define TURN_ON_PLAY_BREAK_POINT_MEM


#define EXCHANGE_LINE_IN_CHANNEL	//交换LINE IN 通道
//#define CUSTOMER_DEFINED_ADKEY_RESISTOR

#define SEMI_AUTO_SCAN_FREQ
#define ADKEY_NEXT_PREV_HOLD_AUTO_SCAN
#define IR_NEXT_PREV_HOLD_AUTO_SCAN
#define IR_NEXT_PREV_SHORT_ADJ_CH
#endif

#ifdef K608_TC_608_V001
#define AC209_28PIN		//28 PIN IC GPIO CONFIG
#ifdef IIC_GPIO_USE_P02_P03
#undef IIC_GPIO_USE_P02_P03
#endif
#define IIC_GPIO_USE_P00_P01
#define TianCheng_Remote

#ifdef MUTE_PORT_USE_P01
#undef MUTE_PORT_USE_P01
#endif

#define VOLUME_DEFUALT 27
#define PLAY_STATUS_LED_P27
#define FM_BY_PASS
#define EXCHANGE_LINE_IN_CHANNEL	//交换LINE IN 通道
#define CUSTOMER_DEFINED_ADKEY_RESISTOR

#define SEMI_AUTO_SCAN_FREQ
#define ADKEY_NEXT_PREV_HOLD_AUTO_SCAN
#define IR_NEXT_PREV_HOLD_AUTO_SCAN
#define IR_NEXT_PREV_SHORT_ADJ_CH
#endif

#ifdef K608_TC_608_V002
#define AC209_28PIN		//28 PIN IC GPIO CONFIG
#ifdef IIC_GPIO_USE_P02_P03
#undef IIC_GPIO_USE_P02_P03
#endif
#define IIC_GPIO_USE_P00_P01
#define TianCheng_Remote

#ifdef MUTE_PORT_USE_P01
#undef MUTE_PORT_USE_P01
#endif

#define VOLUME_DEFUALT 27
#define PLAY_STATUS_LED_P27
#define FM_BY_PASS
#define EXCHANGE_LINE_IN_CHANNEL	//交换LINE IN 通道
#define CUSTOMER_DEFINED_ADKEY_RESISTOR
#define DEFAULT_GO_TO_AUX

#define SEMI_AUTO_SCAN_FREQ
#define ADKEY_NEXT_PREV_HOLD_AUTO_SCAN
#define IR_NEXT_PREV_HOLD_AUTO_SCAN
#define IR_NEXT_PREV_SHORT_ADJ_CH
#endif

#ifdef K987_YJH_987_V001

#define AC209_28PIN		//28 PIN IC GPIO CONFIG
#ifdef IIC_GPIO_USE_P02_P03
#undef IIC_GPIO_USE_P02_P03
#endif
#define IIC_GPIO_USE_P00_P01

#ifdef MUTE_PORT_USE_P01
#undef MUTE_PORT_USE_P01
#endif

#define VOLUME_DEFUALT 27
#define PLAY_STATUS_LED_P27
#define FM_BY_PASS
#define EXCHANGE_LINE_IN_CHANNEL	//交换LINE IN 通道
//#define CUSTOMER_DEFINED_ADKEY_RESISTOR
#define USE_GPIO_DETECT_EARPHONE_PLUGGED
#define INDEPENDENT_EARPHONE_DETECT_GPIO
//#define SEMI_AUTO_SCAN_FREQ
//#define ADKEY_NEXT_PREV_HOLD_AUTO_SCAN
#endif

#ifdef K172_AJE_172_V001

#define AC209_28PIN		//28 PIN IC GPIO CONFIG
#ifdef IIC_GPIO_USE_P02_P03
#undef IIC_GPIO_USE_P02_P03
#endif
#define IIC_GPIO_USE_P00_P01

#ifdef MUTE_PORT_USE_P01
#undef MUTE_PORT_USE_P01
#endif
#define USE_QN8035_FM

#define VOLUME_DEFUALT 27
#define PLAY_STATUS_LED_P27
#define FM_BY_PASS
#define EXCHANGE_LINE_IN_CHANNEL	//交换LINE IN 通道
//#define USE_GPIO_DETECT_EARPHONE_PLUGGED

//#define SEMI_AUTO_SCAN_FREQ
//#define ADKEY_NEXT_PREV_HOLD_AUTO_SCAN
#endif

#ifdef K200_KY_021_V001

#define AC209_28PIN		//28 PIN IC GPIO CONFIG
#ifdef IIC_GPIO_USE_P02_P03
#undef IIC_GPIO_USE_P02_P03
#endif
#define IIC_GPIO_USE_P00_P01

#ifdef MUTE_PORT_USE_P01
#undef MUTE_PORT_USE_P01
#endif

#define VOLUME_DEFUALT 27
#define PLAY_STATUS_LED_P27
//#define FM_BY_PASS
//#define EXCHANGE_LINE_IN_CHANNEL	//交换LINE IN 通道
//#define USE_GPIO_DETECT_EARPHONE_PLUGGED
#define FM_USE_KT0830EG
#define ADKEY_PLAY_SHORT_SCAN_FRE
#define USE_LONG_PLAY_KEY_TO_SWITCH_MODE
#define USE_USB_AUDIO
#define EQ_MODE_DEFUALT_ROCK
#define USE_RTC_RAM_FUNC
//#define SEMI_AUTO_SCAN_FREQ
//#define ADKEY_NEXT_PREV_HOLD_AUTO_SCAN
#endif

#ifdef K209_WS_GKD209_V001

#define AC209_28PIN		//28 PIN IC GPIO CONFIG
#ifdef IIC_GPIO_USE_P02_P03
#undef IIC_GPIO_USE_P02_P03
#endif
#define IIC_GPIO_USE_P00_P01

#ifdef MUTE_PORT_USE_P01
#undef MUTE_PORT_USE_P01
#endif

#define VOLUME_DEFUALT 27
#define PLAY_STATUS_LED_P27
#define FM_BY_PASS
#define EXCHANGE_LINE_IN_CHANNEL	//交换LINE IN 通道

#define AUX_DETECT_USE_P02
#define USE_LINE_IN_DETECT_FUNC	//打开此宏来启动LINE IN 检测功能

#define USE_LONG_PLAY_KEY_TO_SWITCH_MODE
#define ADKEY_PLAY_SHORT_SCAN_FRE

//#define SEMI_AUTO_SCAN_FREQ
//#define ADKEY_NEXT_PREV_HOLD_AUTO_SCAN
#endif


#ifdef K202_WS_01_V001

#define AC209_28PIN		//28 PIN IC GPIO CONFIG
#ifdef IIC_GPIO_USE_P02_P03
#undef IIC_GPIO_USE_P02_P03
#endif
#define IIC_GPIO_USE_P00_P01

#ifdef MUTE_PORT_USE_P01
#undef MUTE_PORT_USE_P01
#endif

#define VOLUME_DEFUALT 27
#define FM_BY_PASS
#define LED_MODE_INDICATOR_ENABLE
#define ADKEY_PLAY_SHORT_SCAN_FRE

#endif

#ifdef K609_KL_609_V001

#define AC209_28PIN		//28 PIN IC GPIO CONFIG
#ifdef IIC_GPIO_USE_P02_P03
#undef IIC_GPIO_USE_P02_P03
#endif
#define IIC_GPIO_USE_P00_P01

#ifdef MUTE_PORT_USE_P01
#undef MUTE_PORT_USE_P01
#endif

#define VOLUME_DEFUALT 27
#define FM_BY_PASS
#define LED_MODE_INDICATOR_ENABLE
#define ADKEY_PLAY_SHORT_SCAN_FRE
#define LED_DRVER_USE_SM1628	// SM 1628 驱动IC

#endif

#ifdef K505_CJB_505_V001

#define AC209_28PIN		//28 PIN IC GPIO CONFIG
#ifdef IIC_GPIO_USE_P02_P03
#undef IIC_GPIO_USE_P02_P03
#endif
#define IIC_GPIO_USE_P00_P01

#ifdef MUTE_PORT_USE_P01
#undef MUTE_PORT_USE_P01
#endif

#define PLAY_STATUS_LED_P27
//#define AUX_DETECT_USE_P02
#define FM_BY_PASS
#define ADKEY_PLAY_SHORT_SCAN_FRE
#define INDEPENDENT_VOLUME_KEY

#endif


#ifdef K507_YJH_507_V001

#define AC209_28PIN		//28 PIN IC GPIO CONFIG
#ifdef IIC_GPIO_USE_P02_P03
#undef IIC_GPIO_USE_P02_P03
#endif
#define IIC_GPIO_USE_P00_P01

#ifdef MUTE_PORT_USE_P01
#undef MUTE_PORT_USE_P01
#endif

#define PLAY_STATUS_LED_P27

#define USE_POWER_KEY
#define PWR_CTRL_P24_KEY_P25
#define USE_GPIO_DETECT_EARPHONE_PLUGGED

#endif

#ifdef K617_LHGC_617_V001

#define AC209_28PIN		//28 PIN IC GPIO CONFIG
#ifdef IIC_GPIO_USE_P02_P03
#undef IIC_GPIO_USE_P02_P03
#endif
#define IIC_GPIO_USE_P00_P01

#ifdef MUTE_PORT_USE_P01
#undef MUTE_PORT_USE_P01
#endif
#ifdef LED_CTRL_LEVEL_NORMAL
#undef LED_CTRL_LEVEL_NORMAL
#endif

#define VOLUME_DEFUALT	   24
#define PLAY_STATUS_LED_P02
#define PLAY_MODE_USE_REP_ONE_ALL
#define NOT_USE_LINE_IN_FUNC	//打开此宏来关闭AUX功能

#endif


#ifdef K627_LHGC_627_V001

#define AC209_28PIN		//28 PIN IC GPIO CONFIG
#ifdef IIC_GPIO_USE_P02_P03
#undef IIC_GPIO_USE_P02_P03
#endif
#define IIC_GPIO_USE_P00_P01

#ifdef MUTE_PORT_USE_P01
#undef MUTE_PORT_USE_P01
#endif
#ifdef LED_CTRL_LEVEL_NORMAL
#undef LED_CTRL_LEVEL_NORMAL
#endif

#define VOLUME_DEFUALT	   24
#define PLAY_STATUS_LED_P02
#define PLAY_MODE_USE_REP_ONE_ALL
#define NOT_USE_LINE_IN_FUNC	//打开此宏来关闭AUX功能
#define MATRIX_KEY_ENABLE

#endif

#ifdef K639_YJH_639_V001

#define AC209_28PIN		//28 PIN IC GPIO CONFIG

#ifdef IIC_GPIO_USE_P02_P03
#undef IIC_GPIO_USE_P02_P03
#endif
#define IIC_GPIO_USE_P00_P01

#ifdef MUTE_PORT_USE_P01
#undef MUTE_PORT_USE_P01
#endif

#define PLAY_STATUS_LED_P27

#define NOT_USE_LINE_IN_FUNC	//打开此宏来关闭AUX功能
#define FM_TRANSMITTER

#endif


#ifdef  K519_YHD_880_V001

#define AC209_28PIN		//28 PIN IC GPIO CONFIG
//#define NO_LED_DISPLAY
#ifdef IIC_GPIO_USE_P02_P03
#undef IIC_GPIO_USE_P02_P03
#endif
#define IIC_GPIO_USE_P00_P01
#ifdef MUTE_PORT_USE_P01
#undef MUTE_PORT_USE_P01
#endif
#define PLAY_STATUS_LED_P27
//#define AUX_DETECT_USE_P02
//#define USE_LINE_IN_DETECT_FUNC	//打开此宏来启动LINE IN 检测功能
#define USE_LONG_PLAY_KEY_TO_RESET_SONG_NUM
#define INDEPENDENT_VOLUME_KEY
#define NOT_USE_LINE_IN_FUNC

#define VOLUME_DEFUALT 30
#define FM_BY_PASS
#define USE_LONG_PLAY_KEY_TO_SWITCH_MODE
#define ADKEY_PLAY_SHORT_SCAN_FRE
//#define _KEY_TONE_ENABEL_

#endif

#ifdef  K519_DCX_880_V001

#define AC209_28PIN		//28 PIN IC GPIO CONFIG
//#define NO_LED_DISPLAY
#ifdef IIC_GPIO_USE_P02_P03
#undef IIC_GPIO_USE_P02_P03
#endif
#define IIC_GPIO_USE_P00_P01
#ifdef MUTE_PORT_USE_P01
#undef MUTE_PORT_USE_P01
#endif
#define PLAY_STATUS_LED_P27
//#define AUX_DETECT_USE_P02
//#define USE_LINE_IN_DETECT_FUNC	//打开此宏来启动LINE IN 检测功能
#define USE_LONG_PLAY_KEY_TO_RESET_SONG_NUM
#define INDEPENDENT_VOLUME_KEY
#define NOT_USE_LINE_IN_FUNC

#define VOLUME_DEFUALT 30
#define FM_BY_PASS
#define USE_LONG_PLAY_KEY_TO_SWITCH_MODE
#define ADKEY_PLAY_SHORT_SCAN_FRE
#define _KEY_TONE_ENABEL_

#endif

#ifdef  K519_YJH_808_V001

#define AC209_28PIN		//28 PIN IC GPIO CONFIG
//#define NO_LED_DISPLAY
#ifdef IIC_GPIO_USE_P02_P03
#undef IIC_GPIO_USE_P02_P03
#endif
#define IIC_GPIO_USE_P00_P01
#ifdef MUTE_PORT_USE_P01
#undef MUTE_PORT_USE_P01
#endif
#define PLAY_STATUS_LED_P27
//#define AUX_DETECT_USE_P02
//#define USE_LINE_IN_DETECT_FUNC	//打开此宏来启动LINE IN 检测功能
//#define USE_GPIO_DETECT_EARPHONE_PLUGGED
#define INDEPENDENT_VOLUME_KEY

#define VOLUME_DEFUALT 30
#define FM_BY_PASS
#define USE_LONG_PLAY_KEY_TO_SWITCH_MODE
#define ADKEY_PLAY_SHORT_SCAN_FRE
#define _KEY_TONE_ENABEL_

#endif

#ifdef  K519_YJH_808_V002

#define AC209_28PIN		//28 PIN IC GPIO CONFIG
//#define NO_LED_DISPLAY
#ifdef IIC_GPIO_USE_P02_P03
#undef IIC_GPIO_USE_P02_P03
#endif
#define IIC_GPIO_USE_P00_P01
#ifdef MUTE_PORT_USE_P01
#undef MUTE_PORT_USE_P01
#endif
#define PLAY_STATUS_LED_P27
//#define AUX_DETECT_USE_P02
//#define USE_LINE_IN_DETECT_FUNC	//打开此宏来启动LINE IN 检测功能
//#define USE_GPIO_DETECT_EARPHONE_PLUGGED
#define INDEPENDENT_VOLUME_KEY

#define VOLUME_DEFUALT 30
#define FM_BY_PASS
#define USE_LONG_PLAY_KEY_TO_SWITCH_MODE
#define ADKEY_PLAY_SHORT_SCAN_FRE
#define _KEY_TONE_ENABEL_
#define USE_USB_AUDIO
#endif


#ifdef  K519_YHD_801D_V002

#define AC209_28PIN		//28 PIN IC GPIO CONFIG
//#define NO_LED_DISPLAY
#ifdef IIC_GPIO_USE_P02_P03
#undef IIC_GPIO_USE_P02_P03
#endif
#define IIC_GPIO_USE_P00_P01
#ifdef MUTE_PORT_USE_P01
#undef MUTE_PORT_USE_P01
#endif
#define PLAY_STATUS_LED_P27
//#define AUX_DETECT_USE_P02
//#define USE_LINE_IN_DETECT_FUNC	//打开此宏来启动LINE IN 检测功能
//#define USE_GPIO_DETECT_EARPHONE_PLUGGED
#define INDEPENDENT_VOLUME_KEY
#define EXCHANGE_LINE_IN_CHANNEL	//交换LINE IN 通道

#define VOLUME_DEFUALT 30
#define FM_BY_PASS
#define USE_LONG_PLAY_KEY_TO_SWITCH_MODE
#define ADKEY_PLAY_SHORT_SCAN_FRE
#define _KEY_TONE_ENABEL_
#define TURN_ON_PLAY_BREAK_POINT_MEM
#define LINE_IN_PLAY_KEY_PAUSE
#define USE_USB_AUDIO
#endif

#ifdef K232_GKD_232_V001

#define AC209_28PIN		//28 PIN IC GPIO CONFIG
#ifdef IIC_GPIO_USE_P02_P03
#undef IIC_GPIO_USE_P02_P03
#endif
#define IIC_GPIO_USE_P00_P01

#ifdef MUTE_PORT_USE_P01
#undef MUTE_PORT_USE_P01
#endif

#define PLAY_STATUS_LED_P27
#define AUX_DETECT_USE_P02
#define USE_LINE_IN_DETECT_FUNC	//打开此宏来启动LINE IN 检测功能

#define FM_BY_PASS
#define ADKEY_PLAY_SHORT_SCAN_FRE
//#define INDEPENDENT_VOLUME_KEY

#endif

#ifdef K525_DeYun_525_V001

#define AC209_28PIN		//28 PIN IC GPIO CONFIG
#ifdef IIC_GPIO_USE_P02_P03
#undef IIC_GPIO_USE_P02_P03
#endif
#define IIC_GPIO_USE_P00_P01

#ifdef MUTE_PORT_USE_P01
#undef MUTE_PORT_USE_P01
#endif

#define PLAY_STATUS_LED_P27

#define FM_BY_PASS
#define ADKEY_PLAY_SHORT_SCAN_FRE
//#define INDEPENDENT_VOLUME_KEY
#define EXCHANGE_LINE_IN_CHANNEL	//交换LINE IN 通道

#endif

#ifdef K667_YJH_667_V001


#define AC209_28PIN		//28 PIN IC GPIO CONFIG
#ifdef IIC_GPIO_USE_P02_P03
#undef IIC_GPIO_USE_P02_P03
#endif
#define IIC_GPIO_USE_P00_P01

#ifdef MUTE_PORT_USE_P01
#undef MUTE_PORT_USE_P01
#endif

#define PLAY_STATUS_LED_P27

#define FM_BY_PASS
#define ADKEY_PLAY_SHORT_SCAN_FRE
//#define INDEPENDENT_VOLUME_KEY
#define EXCHANGE_LINE_IN_CHANNEL	//交换LINE IN 通道
#define AUX_DETECT_USE_P02
#define USE_LINE_IN_DETECT_FUNC	//打开此宏来启动LINE IN 检测功能
#define USE_LONG_PLAY_KEY_TO_SWITCH_MODE
#endif

#ifdef K071_ZhengYang_ZY071_V001

#define AC209_28PIN		//28 PIN IC GPIO CONFIG
#ifdef IIC_GPIO_USE_P02_P03
#undef IIC_GPIO_USE_P02_P03
#endif
#define IIC_GPIO_USE_P01_P02

#ifdef MUTE_PORT_USE_P01
#undef MUTE_PORT_USE_P01
#endif

#define PLAY_STATUS_LED_P01
#define PLAY_STATUS_LED_SHARE_WITH_IIC_SCL

#define FM_BY_PASS
#define ADKEY_PLAY_SHORT_SCAN_FRE
#define EXCHANGE_LINE_IN_CHANNEL	//交换LINE IN 通道
#define VOLUME_DEFUALT 28
#define USE_USB_AUDIO
#define USE_LONG_PLAY_MODE_KEY_TO_SWITCH_MODE
#define NEW_SD_DETECT_MOD
#endif


#ifdef K302_ZhengYang_ZY302_V001

#define AC209_28PIN		//28 PIN IC GPIO CONFIG
#ifdef IIC_GPIO_USE_P02_P03
#undef IIC_GPIO_USE_P02_P03
#endif
#define IIC_GPIO_USE_P01_P02

#ifdef MUTE_PORT_USE_P01
#undef MUTE_PORT_USE_P01
#endif

#define KEY_100_ENABLE

#define PLAY_STATUS_LED_P27

#define ADKEY_PLAY_SHORT_SCAN_FRE
#define IR_REMOTER_WITH_POWER_MUTE_PRINT

#define FM_BY_PASS
//#define ADKEY_PLAY_SHORT_SCAN_FRE
//#define INDEPENDENT_VOLUME_KEY
#define EXCHANGE_LINE_IN_CHANNEL	//交换LINE IN 通道
#define VOLUME_DEFUALT 28
#define DEFAULT_GO_TO_AUX
#define CUSTOMER_DEFINED_ADKEY_RESISTOR
#define DECODE_STOP_MODE_ENABLE
#define USE_QN8035_FM
#define KEY_PRESS_LED_INDICATOR
#define IR_NEXT_PREV_SHORT_ADJ_CH

#define USE_TWO_IR_REMOTE

#endif


#ifdef K676_FXK_676_V001

#define AC209_28PIN		//28 PIN IC GPIO CONFIG
#ifdef IIC_GPIO_USE_P02_P03
#undef IIC_GPIO_USE_P02_P03
#endif
#define IIC_GPIO_USE_P00_P01

#ifdef MUTE_PORT_USE_P01
#undef MUTE_PORT_USE_P01
#endif

#define PLAY_STATUS_LED_P27

#define FM_BY_PASS
#define ADKEY_PLAY_SHORT_SCAN_FRE
#define NOT_USE_LINE_IN_FUNC	//打开此宏来关闭AUX功能

#endif

#ifdef K555_FXK_555_V001

#define AC209_28PIN		//28 PIN IC GPIO CONFIG
#ifdef IIC_GPIO_USE_P02_P03
#undef IIC_GPIO_USE_P02_P03
#endif
#define IIC_GPIO_USE_P00_P01

#ifdef MUTE_PORT_USE_P01
#undef MUTE_PORT_USE_P01
#endif

#define PLAY_STATUS_LED_P27

#define FM_BY_PASS
#define ADKEY_PLAY_SHORT_SCAN_FRE
#define EXCHANGE_LINE_IN_CHANNEL	//交换LINE IN 通道

#endif

#ifdef K711_JM_KSM_V001

#define AC209_28PIN		//28 PIN IC GPIO CONFIG
#ifdef IIC_GPIO_USE_P02_P03
#undef IIC_GPIO_USE_P02_P03
#endif
#define IIC_GPIO_USE_P00_P01

#ifdef MUTE_PORT_USE_P01
#undef MUTE_PORT_USE_P01
#endif

#define PLAY_STATUS_LED_P27

#define FM_BY_PASS
#define ADKEY_PLAY_SHORT_SCAN_FRE
#define EXCHANGE_LINE_IN_CHANNEL	//交换LINE IN 通道
#define USE_LONG_PLAY_KEY_TO_SWITCH_MODE

#endif

#ifdef K711_JM_836_V001

#define AC209_28PIN		//28 PIN IC GPIO CONFIG
#ifdef IIC_GPIO_USE_P02_P03
#undef IIC_GPIO_USE_P02_P03
#endif
#define IIC_GPIO_USE_P00_P01

#ifdef MUTE_PORT_USE_P01
#undef MUTE_PORT_USE_P01
#endif

#define PLAY_STATUS_LED_P27

#define FM_BY_PASS
#define ADKEY_PLAY_SHORT_SCAN_FRE
#define EXCHANGE_LINE_IN_CHANNEL	//交换LINE IN 通道
//#define USE_LONG_PLAY_KEY_TO_SWITCH_MODE

#endif

#ifdef K711_JM_YX450_V001

#define AC209_28PIN		//28 PIN IC GPIO CONFIG
#ifdef IIC_GPIO_USE_P02_P03
#undef IIC_GPIO_USE_P02_P03
#endif
#define IIC_GPIO_USE_P00_P01

#ifdef MUTE_PORT_USE_P01
#undef MUTE_PORT_USE_P01
#endif

#define PLAY_STATUS_LED_P27

#define FM_BY_PASS
#define ADKEY_PLAY_SHORT_SCAN_FRE
#define EXCHANGE_LINE_IN_CHANNEL	//交换LINE IN 通道
#define USE_LONG_PLAY_KEY_TO_SWITCH_MODE

#endif
#ifdef K703_JM_YX006_V001


#define AC209_28PIN		//28 PIN IC GPIO CONFIG
#ifdef IIC_GPIO_USE_P02_P03
#undef IIC_GPIO_USE_P02_P03
#endif
#define IIC_GPIO_USE_P00_P01

#ifdef MUTE_PORT_USE_P01
#undef MUTE_PORT_USE_P01
#endif

#define PLAY_STATUS_LED_P27

#define FM_BY_PASS
#define ADKEY_PLAY_SHORT_SCAN_FRE
#define EXCHANGE_LINE_IN_CHANNEL	//交换LINE IN 通道
#define USE_LONG_PLAY_KEY_TO_SWITCH_MODE

#endif

#ifdef K705_YJH_705_V001

#define AC209_28PIN		//28 PIN IC GPIO CONFIG
#ifdef IIC_GPIO_USE_P02_P03
#undef IIC_GPIO_USE_P02_P03
#endif
#define IIC_GPIO_USE_P00_P01

#ifdef MUTE_PORT_USE_P01
#undef MUTE_PORT_USE_P01
#endif

#define PLAY_STATUS_LED_P27

#define FM_BY_PASS
#define ADKEY_PLAY_SHORT_SCAN_FRE
#define EXCHANGE_LINE_IN_CHANNEL	//交换LINE IN 通道
//#define USE_GPIO_DETECT_EARPHONE_PLUGGED

#endif

#ifdef K679_YJH_679_V001

#define AC209_28PIN		//28 PIN IC GPIO CONFIG
#ifdef IIC_GPIO_USE_P02_P03
#undef IIC_GPIO_USE_P02_P03
#endif
#define IIC_GPIO_USE_P00_P01

#ifdef MUTE_PORT_USE_P01
#undef MUTE_PORT_USE_P01
#endif

#define PLAY_STATUS_LED_P27

#define FM_BY_PASS
#define ADKEY_PLAY_SHORT_SCAN_FRE
#define EXCHANGE_LINE_IN_CHANNEL	//交换LINE IN 通道
//#define USE_GPIO_DETECT_EARPHONE_PLUGGED
#define USE_LONG_PLAY_KEY_TO_SWITCH_MODE

#endif

#ifdef K560_YJH_560_V001

#define AC209_28PIN		//28 PIN IC GPIO CONFIG
#ifdef IIC_GPIO_USE_P02_P03
#undef IIC_GPIO_USE_P02_P03
#endif
#define IIC_GPIO_USE_P00_P01

#ifdef MUTE_PORT_USE_P01
#undef MUTE_PORT_USE_P01
#endif

#define PLAY_STATUS_LED_P27

#define FM_BY_PASS
#define ADKEY_PLAY_SHORT_SCAN_FRE
#define EXCHANGE_LINE_IN_CHANNEL	//交换LINE IN 通道
//#define USE_GPIO_DETECT_EARPHONE_PLUGGED
#define USE_LONG_PLAY_KEY_TO_SWITCH_MODE
#define USE_RTC_RAM_FUNC

#endif


#ifdef K710_AoKaiLin_710_V001

#define AC209_28PIN		//28 PIN IC GPIO CONFIG
#ifdef IIC_GPIO_USE_P02_P03
#undef IIC_GPIO_USE_P02_P03
#endif
#define IIC_GPIO_USE_P00_P01

#ifdef MUTE_PORT_USE_P01
#undef MUTE_PORT_USE_P01
#endif

#define PLAY_STATUS_LED_P27

#define FM_BY_PASS
#define ADKEY_PLAY_SHORT_SCAN_FRE
#define EXCHANGE_LINE_IN_CHANNEL	//交换LINE IN 通道
#define USE_LINE_IN_DETECT_FUNC	//打开此宏来启动LINE IN 检测功能
#define AUX_DETECT_USE_P02

#endif

#ifdef K811_DingChuangXin_811_V001

#define AC209_28PIN		//28 PIN IC GPIO CONFIG
#ifdef IIC_GPIO_USE_P02_P03
#undef IIC_GPIO_USE_P02_P03
#endif
#define IIC_GPIO_USE_P00_P01

#ifdef MUTE_PORT_USE_P01
#undef MUTE_PORT_USE_P01
#endif

#define PLAY_STATUS_LED_P27

#define FM_BY_PASS
#define ADKEY_PLAY_SHORT_SCAN_FRE
#define EXCHANGE_LINE_IN_CHANNEL	//交换LINE IN 通道
#define USE_LINE_IN_DETECT_FUNC	//打开此宏来启动LINE IN 检测功能
#define AUX_DETECT_USE_P02

#endif


#if defined(K692_YHD_832_V001)//||defined(K695_SES_695_V001)

#define AC209_28PIN		//28 PIN IC GPIO CONFIG
#ifdef IIC_GPIO_USE_P02_P03
#undef IIC_GPIO_USE_P02_P03
#endif
#define IIC_GPIO_USE_P00_P01

#ifdef MUTE_PORT_USE_P01
#undef MUTE_PORT_USE_P01
#endif

#define PLAY_STATUS_LED_P27
#define VOLUME_DEFUALT 	28

#define FM_BY_PASS
#define ADKEY_PLAY_SHORT_SCAN_FRE
#define EXCHANGE_LINE_IN_CHANNEL	//交换LINE IN 通道
#define USE_LONG_PLAY_KEY_TO_SWITCH_MODE
#define USE_RTC_RAM_FUNC

#define TURN_ON_PLAY_BREAK_POINT_MEM
#define LINE_IN_PLAY_KEY_PAUSE

//#define DISPLAY_TEST

#endif

#if defined(K692_SES_692_V001)//||defined(K695_SES_695_V001)

#define AC209_28PIN		//28 PIN IC GPIO CONFIG
#ifdef IIC_GPIO_USE_P02_P03
#undef IIC_GPIO_USE_P02_P03
#endif
#define IIC_GPIO_USE_P00_P01

#ifdef MUTE_PORT_USE_P01
#undef MUTE_PORT_USE_P01
#endif

#define PLAY_STATUS_LED_P27
#define VOLUME_DEFUALT 	28

#define FM_BY_PASS
#define ADKEY_PLAY_SHORT_SCAN_FRE
#define EXCHANGE_LINE_IN_CHANNEL	//交换LINE IN 通道
#define USE_LONG_PLAY_KEY_TO_SWITCH_MODE
#define USE_RTC_RAM_FUNC

#define FM_USE_AR1015

#endif
 
 #ifdef K120_SW_015_V001

#define AC209_28PIN		//28 PIN IC GPIO CONFIG
#ifdef IIC_GPIO_USE_P02_P03
#undef IIC_GPIO_USE_P02_P03
#endif
#define IIC_GPIO_USE_P00_P01

#ifdef MUTE_PORT_USE_P01
#undef MUTE_PORT_USE_P01
#endif
#define MUTE_PORT_USE_P26

#define EXCHANGE_LINE_IN_CHANNEL	//交换LINE IN 通道

#define PLAY_STATUS_LED_P27
#define VOLUME_DEFUALT 	27
#define NO_LED_DISPLAY
//#define ADC_DETECT_LINE_IN
#define FM_BY_PASS
#undef ADKEY_PLAY_SHORT_SCAN_FRE
#define CUSTOMER_DEFINED_ADKEY_RESISTOR
#define LED_RUN_FAST_WHEN_PLAY_MODE_CHANGE
#endif

#ifdef K120_YJH_120_V001

#define AC209_28PIN		//28 PIN IC GPIO CONFIG
#ifdef IIC_GPIO_USE_P02_P03
#undef IIC_GPIO_USE_P02_P03
#endif
#define IIC_GPIO_USE_P00_P01

#ifdef MUTE_PORT_USE_P01
#undef MUTE_PORT_USE_P01
#endif

#define PLAY_STATUS_LED_P27
#define USB_DAC_CHANNEL_DELAY_OPEN

#define USE_RTC_RAM_FUNC

#define VOLUME_DEFUALT 30
//#define VOLUME_DEFUALT 28

#define NO_VOLUME_LIMITE
#define FM_BY_PASS
#define ADKEY_PLAY_SHORT_SCAN_FRE
#define EXCHANGE_LINE_IN_CHANNEL	//交换LINE IN 通道
#define CUSTOMER_DEFINED_ADKEY_RESISTOR
#define IR_PLAY_KEY_SCAN_FREQ_DISABLE
#define IR_NEXT_PREV_SHORT_ADJ_CH
#define SEMI_AUTO_SCAN_FREQ
#define IR_NEXT_PREV_HOLD_AUTO_SCAN
#define NEW_SD_DETECT_MOD
#define NEXT_PREV_HOLD_USE_VOL_TUNE
#define CUSTOM_KEY_FEATURE_USE
#endif


#ifdef K562_QDX_562_V001

#define AC209_28PIN		//28 PIN IC GPIO CONFIG
#ifdef IIC_GPIO_USE_P02_P03
#undef IIC_GPIO_USE_P02_P03
#endif
#define IIC_GPIO_USE_P00_P01

#ifdef MUTE_PORT_USE_P01
#undef MUTE_PORT_USE_P01
#endif

#define PLAY_STATUS_LED_P27

#define FM_BY_PASS
#define ADKEY_PLAY_SHORT_SCAN_FRE
#define EXCHANGE_LINE_IN_CHANNEL	//交换LINE IN 通道
#define USE_LONG_PLAY_KEY_TO_SWITCH_MODE
#define USE_RTC_RAM_FUNC

#endif

#ifdef K800_MingYang_800_V001

#define AC209_28PIN		//28 PIN IC GPIO CONFIG
#ifdef IIC_GPIO_USE_P02_P03
#undef IIC_GPIO_USE_P02_P03
#endif
#define IIC_GPIO_USE_P00_P01

#ifdef MUTE_PORT_USE_P01
#undef MUTE_PORT_USE_P01
#endif
#define MUTE_PORT_USE_DUMP

#define PLAY_STATUS_LED_P27

#define FM_BY_PASS
#define ADKEY_PLAY_SHORT_SCAN_FRE
#define EXCHANGE_LINE_IN_CHANNEL	//交换LINE IN 通道
//#define USE_LONG_PLAY_KEY_TO_SWITCH_MODE
#define USE_POWER_KEY
#define USE_ONLY_POWER_HOLD_CTRL
#define USE_LONG_MODE_FOR_CUSTOM_FUNC
#define VOLUME_DEFUALT 28
#define USE_USB_AUDIO
#define CUSTOMER_DEFINED_ADKEY_RESISTOR

#endif

#ifdef K319_ZhuoXing_319_V001

#define AC209_28PIN		//28 PIN IC GPIO CONFIG
#ifdef IIC_GPIO_USE_P02_P03
#undef IIC_GPIO_USE_P02_P03
#endif
#define IIC_GPIO_USE_P00_P01

#ifdef MUTE_PORT_USE_P01
#undef MUTE_PORT_USE_P01
#endif

#define PLAY_STATUS_LED_P27

#define FM_BY_PASS
#define ADKEY_PLAY_SHORT_SCAN_FRE
#define EXCHANGE_LINE_IN_CHANNEL	//交换LINE IN 通道

#define USE_POWER_KEY
#define PWR_CTRL_P25_KEY_P24

#endif


#ifdef K320_ZhuoXing_320_V001

#define AC209_28PIN		//28 PIN IC GPIO CONFIG
#ifdef IIC_GPIO_USE_P02_P03
#undef IIC_GPIO_USE_P02_P03
#endif
#define IIC_GPIO_USE_P00_P01

#ifdef MUTE_PORT_USE_P01
#undef MUTE_PORT_USE_P01
#endif

#define PLAY_STATUS_LED_P27

#define FM_BY_PASS
#define ADKEY_PLAY_SHORT_SCAN_FRE
#define EXCHANGE_LINE_IN_CHANNEL	//交换LINE IN 通道

#define USE_LINE_IN_DETECT_FUNC	//打开此宏来启动LINE IN 检测功能
#define AUX_DETECT_USE_P02

#endif

#ifdef K722_YJH_722_V001

#define AC209_28PIN		//28 PIN IC GPIO CONFIG
#ifdef IIC_GPIO_USE_P02_P03
#undef IIC_GPIO_USE_P02_P03
#endif
#define IIC_GPIO_USE_P00_P01

#ifdef MUTE_PORT_USE_P01
#undef MUTE_PORT_USE_P01
#endif
#define USE_MUTE_LED_INDICATOR
#define PLAY_STATUS_LED_P27
#define TWO_PLAY_LED_IN_USE

#define FM_BY_PASS
//#define ADKEY_PLAY_SHORT_SCAN_FRE
#define EXCHANGE_LINE_IN_CHANNEL	//交换LINE IN 通道
#define IR_USER_CODE_0x7F80

#define IR_PLAY_KEY_LONG_SCAN_FREQ
#define IR_NEXT_PREV_SHORT_ADJ_CH
#define SEMI_AUTO_SCAN_FREQ
#define IR_PLAY_KEY_SCAN_FREQ_DISABLE
#define LINE_IN_PLAY_KEY_PAUSE
#define AUX_PAUSE_LED_INDICATOR
#define DEFAULT_GO_TO_AUX
#define FM_PLAY_KEY_PAUSE
#define FM_PAUSE_LED_INDICATOR
#define VOLUME_DEFUALT 28

#endif


#ifdef K806_LiHaoDe_806_V001

#define AC209_28PIN		//28 PIN IC GPIO CONFIG
#ifdef IIC_GPIO_USE_P02_P03
#undef IIC_GPIO_USE_P02_P03
#endif
#define IIC_GPIO_USE_P00_P01

#ifdef MUTE_PORT_USE_P01
#undef MUTE_PORT_USE_P01
#endif

#define PLAY_STATUS_LED_P02
#define VOLUME_DEFUALT 28

#define USE_RTC_RAM_FUNC
#define NOT_USE_LINE_IN_FUNC

#endif


#ifdef K727_LiHaoDe_727_V001

#define AC209_28PIN		//28 PIN IC GPIO CONFIG
#ifdef IIC_GPIO_USE_P02_P03
#undef IIC_GPIO_USE_P02_P03
#endif
#define IIC_GPIO_USE_P00_P01

#ifdef MUTE_PORT_USE_P01
#undef MUTE_PORT_USE_P01
#endif

#define PLAY_STATUS_LED_P27
#define VOLUME_DEFUALT 28

#define USE_RTC_RAM_FUNC
#define NOT_USE_LINE_IN_FUNC
#define _KEY_TONE_ENABEL_
#endif

#ifdef K202_WEISI_KL202_V001

#define AC209_28PIN		//28 PIN IC GPIO CONFIG
#ifdef IIC_GPIO_USE_P02_P03
#undef IIC_GPIO_USE_P02_P03
#endif
#define IIC_GPIO_USE_P00_P01

#ifdef MUTE_PORT_USE_P01
#undef MUTE_PORT_USE_P01
#endif

//#define NO_PLAY_STATUS_LED
//efine VOLUME_DEFUALT 28

#define FM_BY_PASS

#define NOT_USE_LINE_IN_FUNC
#define NEW_CUSTOMIZED_LED_METHOD

#endif


#ifdef K583_ZX_583_V001

#define AC209_28PIN		//28 PIN IC GPIO CONFIG
#ifdef IIC_GPIO_USE_P02_P03
#undef IIC_GPIO_USE_P02_P03
#endif
#define IIC_GPIO_USE_P00_P01

#ifdef MUTE_PORT_USE_P01
#undef MUTE_PORT_USE_P01
#endif
#define MUTE_PORT_USE_P26

#define EXCHANGE_LINE_IN_CHANNEL	//交换LINE IN 通道
#define FM_BY_PASS

#define PLAY_STATUS_LED_P27
#define PLAY_STATUS_LED_SHARE_WITH_IIC_SCL
#define TWO_PLAY_LED_IN_USE
#define TWO_PLAY_LED_USE_PORT_P00
#define CUSTOMER_DEFINED_ADKEY_RESISTOR
#define VOLUME_DEFUALT 28

#define USE_RTC_RAM_FUNC
#define USE_POWER_KEY
#define USE_ONLY_POWER_HOLD_CTRL
#define PWR_CTRL_P02
#define POWE_KEY_PLAY_KEY_IN_ONE_KEY

#define USE_POWER_KEY_SHORT_SCAN
#endif


#ifdef K586_LHD_LT30_V001

#define AC209_28PIN		//28 PIN IC GPIO CONFIG
#ifdef IIC_GPIO_USE_P02_P03
#undef IIC_GPIO_USE_P02_P03
#endif
#define IIC_GPIO_USE_P00_P01

#ifdef MUTE_PORT_USE_P01
#undef MUTE_PORT_USE_P01
#endif
#define MUTE_PORT_USE_P26
//#define NO_PLAY_STATUS_LED
#define PLAY_STATUS_LED_P27
#define VOLUME_DEFUALT 28

//#define FM_BY_PASS
#define _KEY_TONE_ENABEL_
#define NOT_USE_LINE_IN_FUNC
//#define LED_MODE_INDICATOR_ENABLE

#endif

#ifdef K738_LHD_LTB1_V001

#define AC209_28PIN		//28 PIN IC GPIO CONFIG
#ifdef IIC_GPIO_USE_P02_P03
#undef IIC_GPIO_USE_P02_P03
#endif
#define IIC_GPIO_USE_P00_P01

#ifdef MUTE_PORT_USE_P01
#undef MUTE_PORT_USE_P01
#endif
#define MUTE_PORT_USE_DUMP
//#define NO_PLAY_STATUS_LED
#define PLAY_STATUS_LED_P02
#define VOLUME_DEFUALT 	28
#define EXCHANGE_LINE_IN_CHANNEL	//交换LINE IN 通道
#define _KEY_TONE_ENABEL_
#define RDA5807SP_DISENABLE_ST
#define RDA5807_DISENABLE_RSSI
//#define DEFAULT_GO_TO_IDLE	//????????????????????????

#define INDEPENDENT_VOLUME_KEY
//#define NOT_USE_LINE_IN_FUNC
//#define LED_MODE_INDICATOR_ENABLE
#endif

#ifdef K740_LHD_916_V001

#define AC209_28PIN		//28 PIN IC GPIO CONFIG
#ifdef IIC_GPIO_USE_P02_P03
#undef IIC_GPIO_USE_P02_P03
#endif
#define IIC_GPIO_USE_P00_P01

#ifdef MUTE_PORT_USE_P01
#undef MUTE_PORT_USE_P01
#endif
#define FM_USE_AR1015

//#define NO_PLAY_STATUS_LED
#define PLAY_STATUS_LED_P27

#define VOLUME_DEFUALT 	28
//#define EXCHANGE_LINE_IN_CHANNEL	//交换LINE IN 通道
#define USE_LONG_PLAY_KEY_TO_SWITCH_MODE
#define ADKEY_PLAY_SHORT_SCAN_FRE
#define SEMI_AUTO_SCAN_FREQ
#define ADKEY_NEXT_PREV_HOLD_AUTO_SCAN
//#define FM_BY_PASS
#define NOT_USE_LINE_IN_FUNC
#define _KEY_TONE_ENABEL_
#define INDEPENDENT_VOLUME_KEY

//#define LED_MODE_INDICATOR_ENABLE
#endif

#ifdef K000_XingChuang_YQ001_V001
#define AC209_28PIN		//28 PIN IC GPIO CONFIG
#ifdef IIC_GPIO_USE_P02_P03
#undef IIC_GPIO_USE_P02_P03
#endif
#define IIC_GPIO_USE_P01_P02

#ifdef MUTE_PORT_USE_P01
#undef MUTE_PORT_USE_P01
#endif
#define MUTE_PORT_USE_DUMP

//#define NO_PLAY_STATUS_LED
#define PLAY_STATUS_LED_P01
#define PLAY_STATUS_LED_SHARE_WITH_IIC_SCL
#define EXCHANGE_LINE_IN_CHANNEL	//交换LINE IN 通道
#define CUSTOMER_DEFINED_ADKEY_RESISTOR

#define VOLUME_DEFUALT 28
#define USE_LONG_PLAY_KEY_TO_SWITCH_MODE
//#define USE_GPIO_DETECT_EARPHONE_PLUGGED
#define SEMI_AUTO_SCAN_FREQ
#define IR_NEXT_PREV_HOLD_AUTO_SCAN
#define ADKEY_PLAY_SHORT_SCAN_FRE
#define INDEPENDENT_VOLUME_KEY

//#define USE_LINE_IN_DETECT_FUNC
//#define AUX_DETECT_USE_P02
#endif


#ifdef K000_XingChuang_X831_V001
#define AC209_28PIN		//28 PIN IC GPIO CONFIG

#ifdef IIC_GPIO_USE_P02_P03
#undef IIC_GPIO_USE_P02_P03
#endif
#define IIC_GPIO_USE_DUMMY

#ifdef MUTE_PORT_USE_P01
#undef MUTE_PORT_USE_P01
#endif
#define MUTE_PORT_USE_P00

#undef MUTE_CTRL_LEVEL_NORMAL

#define PLAY_STATUS_LED_P01

#define EXCHANGE_LINE_IN_CHANNEL	//交换LINE IN 通道

#define VOLUME_DEFUALT 20
#define USE_LONG_PLAY_KEY_TO_SWITCH_MODE


#define USE_LINE_IN_DETECT_FUNC
#define AUX_DETECT_USE_P26
#endif

#ifdef K000_XingChuang_X824_V001
#define AC209_28PIN		//28 PIN IC GPIO CONFIG
#ifdef IIC_GPIO_USE_P02_P03
#undef IIC_GPIO_USE_P02_P03
#endif
#define IIC_GPIO_USE_P01_P00

#ifdef MUTE_PORT_USE_P01
#undef MUTE_PORT_USE_P01
#endif
#define MUTE_PORT_USE_DUMP

//#define NO_PLAY_STATUS_LED
#define PLAY_STATUS_LED_P01
#define PLAY_STATUS_LED_SHARE_WITH_IIC_SCL
#define EXCHANGE_LINE_IN_CHANNEL	//交换LINE IN 通道
#define CUSTOMER_DEFINED_ADKEY_RESISTOR

//#define VOLUME_DEFUALT 28
#define USE_LONG_PLAY_KEY_TO_SWITCH_MODE
//#define USE_GPIO_DETECT_EARPHONE_PLUGGED
#define SEMI_AUTO_SCAN_FREQ
#define IR_NEXT_PREV_HOLD_AUTO_SCAN
#define ADKEY_PLAY_SHORT_SCAN_FRE

#define USE_LINE_IN_DETECT_FUNC
#define AUX_DETECT_USE_P02
#endif

#ifdef K000_XingChuang_X816_V001
#define AC209_28PIN		//28 PIN IC GPIO CONFIG
#ifdef IIC_GPIO_USE_P02_P03
#undef IIC_GPIO_USE_P02_P03
#endif
#define IIC_GPIO_USE_P01_P02

#ifdef MUTE_PORT_USE_P01
#undef MUTE_PORT_USE_P01
#endif
#define MUTE_PORT_USE_P00

//#define NO_PLAY_STATUS_LED
#define PLAY_STATUS_LED_P01
#define PLAY_STATUS_LED_SHARE_WITH_IIC_SCL
#define EXCHANGE_LINE_IN_CHANNEL	//交换LINE IN 通道

#define VOLUME_DEFUALT 28
#define USE_LONG_PLAY_KEY_TO_SWITCH_MODE
#define USE_GPIO_DETECT_EARPHONE_PLUGGED
#define EARPHONE_DETECT_USE_VPP
#define ADKEY_PLAY_SHORT_SCAN_FRE
#endif

#ifdef K736_TaiYangSheng_736_V001

#define AC209_28PIN		//28 PIN IC GPIO CONFIG
#ifdef IIC_GPIO_USE_P02_P03
#undef IIC_GPIO_USE_P02_P03
#endif
#define IIC_GPIO_USE_P00_P01

#ifdef MUTE_PORT_USE_P01
#undef MUTE_PORT_USE_P01
#endif

//#define NO_PLAY_STATUS_LED
#define PLAY_STATUS_LED_P27
#define VOLUME_DEFUALT 	28
#define EXCHANGE_LINE_IN_CHANNEL	//交换LINE IN 通道

#define FM_BY_PASS
//#define NOT_USE_LINE_IN_FUNC
//#define LED_MODE_INDICATOR_ENABLE
#endif


#ifdef K589_JYHL_589_V001

#define AC209_28PIN		//28 PIN IC GPIO CONFIG
#ifdef IIC_GPIO_USE_P02_P03
#undef IIC_GPIO_USE_P02_P03
#endif
#define IIC_GPIO_USE_P00_P01

#ifdef MUTE_PORT_USE_P01
#undef MUTE_PORT_USE_P01
#endif
#define MUTE_PORT_USE_P26

#define EXCHANGE_LINE_IN_CHANNEL	//交换LINE IN 通道
#define FM_BY_PASS
#define PLAY_STATUS_LED_P27

#define INDEPENDENT_VOLUME_KEY

#define VOLUME_DEFUALT 28
#define CUSTOMER_DEFINED_ADKEY_RESISTOR
#define USE_POWER_KEY
#define USE_ONLY_POWER_HOLD_CTRL
#define PWR_CTRL_P02
#define POWE_KEY_PLAY_KEY_IN_ONE_KEY
#define LINE_IN_PLAY_KEY_PAUSE
#define USE_POWER_KEY_SHORT_SCAN
#define USE_PWR_KEY_LONG_PWR_ON

#define SEMI_AUTO_SCAN_FREQ
#define ADKEY_NEXT_PREV_HOLD_AUTO_SCAN


#endif


#ifdef K746_JIALE_746_V001

#define AC209_28PIN		//28 PIN IC GPIO CONFIG
#ifdef IIC_GPIO_USE_P02_P03
#undef IIC_GPIO_USE_P02_P03
#endif
#define IIC_GPIO_USE_P00_P01

#ifdef MUTE_PORT_USE_P01
#undef MUTE_PORT_USE_P01
#endif
#define MUTE_PORT_USE_P26

#define PLAY_STATUS_LED_P27
#define EXCHANGE_LINE_IN_CHANNEL	//交换LINE IN 通道
#define FM_BY_PASS

#define VOLUME_DEFUALT 28

#define ADKEY_PLAY_SHORT_SCAN_FRE

#endif

#ifdef K755_AnJieEr_755_V001

#define AC209_28PIN		//28 PIN IC GPIO CONFIG
#ifdef IIC_GPIO_USE_P02_P03
#undef IIC_GPIO_USE_P02_P03
#endif
#define IIC_GPIO_USE_P00_P01

#ifdef MUTE_PORT_USE_P01
#undef MUTE_PORT_USE_P01
#endif
#define MUTE_PORT_USE_P27
#define FM_BY_PASS
#define EXCHANGE_LINE_IN_CHANNEL	//交换LINE IN 通道

#define PLAY_STATUS_LED_P02

#define VOLUME_DEFUALT 28
#define CUSTOMER_DEFINED_ADKEY_RESISTOR
#define USE_POWER_KEY
#define USE_ONLY_POWER_HOLD_CTRL
#define ADKEY_PLAY_SHORT_SCAN_FRE
#define INDEPENDENT_VOLUME_KEY

#define POWE_KEY_PLAY_KEY_IN_ONE_KEY
#define USE_POWER_KEY_SHORT_SCAN
#define NEXT_PREV_HOLD_DO_NOTHING

#define USE_PWR_KEY_LONG_PWR_ON

#define FM_USE_KT0830EG
#endif

#ifdef K783_JinYeHeLi_783_V001

#define AC209_28PIN		//28 PIN IC GPIO CONFIG
#ifdef IIC_GPIO_USE_P02_P03
#undef IIC_GPIO_USE_P02_P03
#endif
#define IIC_GPIO_USE_P00_P01

#ifdef MUTE_PORT_USE_P01
#undef MUTE_PORT_USE_P01
#endif
#define MUTE_PORT_USE_P27
#define FM_BY_PASS
#define EXCHANGE_LINE_IN_CHANNEL	//交换LINE IN 通道

#define PLAY_STATUS_LED_P02

#define VOLUME_DEFUALT 28
#define CUSTOMER_DEFINED_ADKEY_RESISTOR
#define USE_POWER_KEY
#define USE_ONLY_POWER_HOLD_CTRL
#define ADKEY_PLAY_SHORT_SCAN_FRE

#define POWE_KEY_PLAY_KEY_IN_ONE_KEY
#define USE_POWER_KEY_SHORT_SCAN
#define NEXT_PREV_HOLD_DO_NOTHING

#define USE_PWR_KEY_LONG_PWR_ON

#define FM_USE_KT0830EG
#endif

#ifdef K755_JinYeHeLi_755_V001

#define AC209_28PIN		//28 PIN IC GPIO CONFIG
#ifdef IIC_GPIO_USE_P02_P03
#undef IIC_GPIO_USE_P02_P03
#endif
#define IIC_GPIO_USE_P00_P01

#ifdef MUTE_PORT_USE_P01
#undef MUTE_PORT_USE_P01
#endif
#define MUTE_PORT_USE_P27
#define FM_BY_PASS
#define EXCHANGE_LINE_IN_CHANNEL	//交换LINE IN 通道

#define PLAY_STATUS_LED_P02

#define VOLUME_DEFUALT 28
#define CUSTOMER_DEFINED_ADKEY_RESISTOR
#define USE_POWER_KEY
#define USE_ONLY_POWER_HOLD_CTRL
#define ADKEY_PLAY_SHORT_SCAN_FRE
#define INDEPENDENT_VOLUME_KEY

#define POWE_KEY_PLAY_KEY_IN_ONE_KEY
#define USE_POWER_KEY_SHORT_SCAN
#define NEXT_PREV_HOLD_DO_NOTHING

#define USE_PWR_KEY_LONG_PWR_ON

#define FM_USE_KT0830EG
#endif


#ifdef K765_YJH_765_V001


#define AC209_28PIN		//28 PIN IC GPIO CONFIG
#ifdef IIC_GPIO_USE_P02_P03
#undef IIC_GPIO_USE_P02_P03
#endif
#define IIC_GPIO_USE_P00_P01

#ifdef MUTE_PORT_USE_P01
#undef MUTE_PORT_USE_P01
#endif
#define MUTE_PORT_USE_P26

#define NO_PLAY_STATUS_LED

//#define PLAY_STATUS_LED_P27
#define EXCHANGE_LINE_IN_CHANNEL	//交换LINE IN 通道
#define FM_BY_PASS

#define VOLUME_DEFUALT 28

#define ADKEY_PLAY_SHORT_SCAN_FRE

#define USE_GPIO_DETECT_EARPHONE_PLUGGED
#define EARPHONE_DETECT_USE_P02

#endif

#ifdef K598_YJH_598_V001

#define AC209_28PIN		//28 PIN IC GPIO CONFIG
#ifdef IIC_GPIO_USE_P02_P03
#undef IIC_GPIO_USE_P02_P03
#endif
#define IIC_GPIO_USE_P00_P01

#ifdef MUTE_PORT_USE_P01
#undef MUTE_PORT_USE_P01
#endif
#define MUTE_PORT_USE_P26

//#define PLAY_STATUS_LED_P27

#define EXCHANGE_LINE_IN_CHANNEL	//交换LINE IN 通道
#define FM_BY_PASS

#define USE_POWER_KEY
#define USE_ONLY_POWER_HOLD_CTRL
#define PWR_CTRL_P02
#define POWE_KEY_PLAY_KEY_IN_ONE_KEY

#define USE_POWER_KEY_SHORT_SCAN

#define VOLUME_DEFUALT 28
#define BATT_DETECT_FUNC

#endif

#ifdef K599_JinRui_599_V001

#define AC209_28PIN		//28 PIN IC GPIO CONFIG
#ifdef IIC_GPIO_USE_P02_P03
#undef IIC_GPIO_USE_P02_P03
#endif
#define IIC_GPIO_USE_P00_P01

#ifdef MUTE_PORT_USE_P01
#undef MUTE_PORT_USE_P01
#endif
#define MUTE_PORT_USE_DUMP

//#define PLAY_STATUS_LED_P27

#define EXCHANGE_LINE_IN_CHANNEL	//交换LINE IN 通道
#define DECODE_STOP_MODE_ENABLE

#define VOLUME_DEFUALT 28

#endif


#ifdef K770_JinRui_770_V001

#define AC209_28PIN		//28 PIN IC GPIO CONFIG
#ifdef IIC_GPIO_USE_P02_P03
#undef IIC_GPIO_USE_P02_P03
#endif
#define IIC_GPIO_USE_P00_P01

#ifdef MUTE_PORT_USE_P01
#undef MUTE_PORT_USE_P01
#endif
#define MUTE_PORT_USE_P26

#define PLAY_STATUS_LED_P27

#define VOLUME_DEFUALT 28

#define NOT_USE_LINE_IN_FUNC
#endif

#ifdef K000_MingYang_1003A_V001


#define AC209_28PIN		//28 PIN IC GPIO CONFIG
#ifdef IIC_GPIO_USE_P02_P03
#undef IIC_GPIO_USE_P02_P03
#endif
#define IIC_GPIO_USE_P00_P01

#ifdef MUTE_PORT_USE_P01
#undef MUTE_PORT_USE_P01
#endif
#define MUTE_PORT_USE_P26

#define PLAY_STATUS_LED_P27
#define EXCHANGE_LINE_IN_CHANNEL	//交换LINE IN 通道
#define FM_BY_PASS

#define VOLUME_DEFUALT 28

#define ADKEY_PLAY_SHORT_SCAN_FRE
#define LED_STATUS_STOP_AT_VALID_STATION

#define NEW_SD_DETECT_MOD

#define USE_LINE_IN_DETECT_FUNC
#define LINE_IN_DETECT_SHARE_LED_STATUS_PORT

#endif

#ifdef K086_JLH_2096_V001

#define AC209_28PIN		//28 PIN IC GPIO CONFIG
#ifdef IIC_GPIO_USE_P02_P03
#undef IIC_GPIO_USE_P02_P03
#endif
#define IIC_GPIO_USE_P00_P01

#ifdef MUTE_PORT_USE_P01
#undef MUTE_PORT_USE_P01
#endif
#define MUTE_PORT_USE_P26

#define NO_PLAY_STATUS_LED

#define CUSTOMIZED_VOL_LIMITATION
#define VOLUME_DEFUALT 26

#define NOT_USE_LINE_IN_FUNC
#endif

#ifdef K776_CaiRun_776_V001

#define AC209_28PIN		//28 PIN IC GPIO CONFIG
#ifdef IIC_GPIO_USE_P02_P03
#undef IIC_GPIO_USE_P02_P03
#endif
#define IIC_GPIO_USE_P00_P01

#ifdef MUTE_PORT_USE_P01
#undef MUTE_PORT_USE_P01
#endif
#define MUTE_PORT_USE_P26

#define PLAY_STATUS_LED_P27

#define ADKEY_PLAY_SHORT_SCAN_FRE

#define EXCHANGE_LINE_IN_CHANNEL	//交换LINE IN 通道
#define FM_BY_PASS

#define VOLUME_DEFUALT 30

#define NO_VOLUME_LIMITE

#define USE_LONG_PLAY_KEY_TO_SWITCH_MODE

#define NOT_USE_LINE_IN_FUNC
#endif


#ifdef K535_DingChuangXin_803E_V001

#define AC209_28PIN		//28 PIN IC GPIO CONFIG
#ifdef IIC_GPIO_USE_P02_P03
#undef IIC_GPIO_USE_P02_P03
#endif
#define IIC_GPIO_USE_P00_P01

#ifdef MUTE_PORT_USE_P01
#undef MUTE_PORT_USE_P01
#endif
#define MUTE_PORT_USE_P26

#define PLAY_STATUS_LED_P27

#define ADKEY_PLAY_SHORT_SCAN_FRE

#define EXCHANGE_LINE_IN_CHANNEL	//交换LINE IN 通道
#define FM_BY_PASS

#define VOLUME_DEFUALT 30

#define NO_VOLUME_LIMITE

#define USE_LONG_PLAY_KEY_TO_SWITCH_MODE
#define INDEPENDENT_VOLUME_KEY
#define LINE_IN_PLAY_KEY_PAUSE

#endif

#ifdef K535_DingChuangXin_803E_2_V001

#define AC209_28PIN		//28 PIN IC GPIO CONFIG
#ifdef IIC_GPIO_USE_P02_P03
#undef IIC_GPIO_USE_P02_P03
#endif
#define IIC_GPIO_USE_P00_P01

#ifdef MUTE_PORT_USE_P01
#undef MUTE_PORT_USE_P01
#endif
#define MUTE_PORT_USE_P26

#define PLAY_STATUS_LED_P27

#define ADKEY_PLAY_SHORT_SCAN_FRE

#define EXCHANGE_LINE_IN_CHANNEL	//交换LINE IN 通道
#define FM_BY_PASS

#define VOLUME_DEFUALT 30

#define NO_VOLUME_LIMITE
#define LINE_IN_PLAY_KEY_PAUSE

#define USE_EQ_TABLE_CUSTOM

//#define USE_LONG_PLAY_KEY_TO_SWITCH_MODE
//#define INDEPENDENT_VOLUME_KEY

#endif

#ifdef K535_DingChuangXin_803E_3_V001

#define AC209_28PIN		//28 PIN IC GPIO CONFIG
#ifdef IIC_GPIO_USE_P02_P03
#undef IIC_GPIO_USE_P02_P03
#endif
#define IIC_GPIO_USE_P00_P01

#ifdef MUTE_PORT_USE_P01
#undef MUTE_PORT_USE_P01
#endif
#define MUTE_PORT_USE_P26

#define PLAY_STATUS_LED_P27

#define ADKEY_PLAY_SHORT_SCAN_FRE

#define EXCHANGE_LINE_IN_CHANNEL	//交换LINE IN 通道
#define FM_BY_PASS

#define VOLUME_DEFUALT 30

#define NO_VOLUME_LIMITE
#define LINE_IN_PLAY_KEY_PAUSE

#define USE_EQ_TABLE_CUSTOM

//#define USE_LONG_PLAY_KEY_TO_SWITCH_MODE
//#define INDEPENDENT_VOLUME_KEY

#endif

#ifdef K1019_DingChuangXin_D806_V001

#define AC209_28PIN		//28 PIN IC GPIO CONFIG
#ifdef IIC_GPIO_USE_P02_P03
#undef IIC_GPIO_USE_P02_P03
#endif
#define IIC_GPIO_USE_P00_P01

#ifdef MUTE_PORT_USE_P01
#undef MUTE_PORT_USE_P01
#endif
#define MUTE_PORT_USE_P26

#define PLAY_STATUS_LED_P27

#define ADKEY_PLAY_SHORT_SCAN_FRE

#define EXCHANGE_LINE_IN_CHANNEL	//交换LINE IN 通道
#define FM_BY_PASS

#define VOLUME_DEFUALT 30

#define NO_VOLUME_LIMITE
#define LINE_IN_PLAY_KEY_PAUSE

#define USE_LONG_PLAY_KEY_TO_SWITCH_MODE
//#define INDEPENDENT_VOLUME_KEY

#endif

#ifdef K735_JIAMEI_JM007_V001

#define AC209_28PIN		//28 PIN IC GPIO CONFIG
#ifdef IIC_GPIO_USE_P02_P03
#undef IIC_GPIO_USE_P02_P03
#endif
#define IIC_GPIO_USE_P00_P01

#ifdef MUTE_PORT_USE_P01
#undef MUTE_PORT_USE_P01
#endif
#define MUTE_PORT_USE_P26

#define PLAY_STATUS_LED_P27

#define ADKEY_PLAY_SHORT_SCAN_FRE

#define EXCHANGE_LINE_IN_CHANNEL	//交换LINE IN 通道
#define FM_BY_PASS

#define VOLUME_DEFUALT 30

//#define NO_VOLUME_LIMITE
//#define LINE_IN_PLAY_KEY_PAUSE

//#define USE_LONG_PLAY_KEY_TO_SWITCH_MODE
#define INDEPENDENT_VOLUME_KEY

#endif

#ifdef K2013_JIELONG_2013_V001

#define AC209_28PIN		//28 PIN IC GPIO CONFIG
#ifdef IIC_GPIO_USE_P02_P03
#undef IIC_GPIO_USE_P02_P03
#endif
#define IIC_GPIO_USE_P00_P01

#ifdef MUTE_PORT_USE_P01
#undef MUTE_PORT_USE_P01
#endif
#define MUTE_PORT_USE_P26

#define PLAY_STATUS_LED_P27

#define ADKEY_PLAY_SHORT_SCAN_FRE

#define EXCHANGE_LINE_IN_CHANNEL	//交换LINE IN 通道
#define FM_BY_PASS

#define VOLUME_DEFUALT 30

#define USE_LONG_PLAY_KEY_TO_RESET_SONG_NUM
#define CUSTOMER_DEFINED_ADKEY_RESISTOR

#define DEFAULT_GO_TO_IDLE
#define INDEPENDENT_VOLUME_KEY
#define NEXT_PREV_HOLD_DO_NOTHING

#endif

#ifdef K000_TIANYUN_2096_V001


#define AC209_28PIN		//28 PIN IC GPIO CONFIG
#ifdef IIC_GPIO_USE_P02_P03
#undef IIC_GPIO_USE_P02_P03
#endif
#define IIC_GPIO_USE_P00_P01

#ifdef MUTE_PORT_USE_P01
#undef MUTE_PORT_USE_P01
#endif
#define MUTE_PORT_USE_P26

#define PLAY_STATUS_LED_P02

#define ADKEY_PLAY_SHORT_SCAN_FRE

#define EXCHANGE_LINE_IN_CHANNEL	//交换LINE IN 通道
#define CUSTOMER_DEFINED_ADKEY_RESISTOR

#define VOLUME_DEFUALT 30
#define DECODE_STOP_MODE_ENABLE

#define DEFAULT_GO_TO_AUX
#endif


#ifdef K1031_YHD_910_V001

#define AC209_28PIN		//28 PIN IC GPIO CONFIG
#ifdef IIC_GPIO_USE_P02_P03
#undef IIC_GPIO_USE_P02_P03
#endif
#define IIC_GPIO_USE_P00_P01

#ifdef MUTE_PORT_USE_P01
#undef MUTE_PORT_USE_P01
#endif
#define MUTE_PORT_USE_P26

#define PLAY_STATUS_LED_P27

#define USE_MODE_KEY_LONG_SCAN
#define ADKEY_PLAY_SHORT_SCAN_FRE

#define EXCHANGE_LINE_IN_CHANNEL	//交换LINE IN 通道
#define FM_BY_PASS

#define CUSTOMER_DEFINED_ADKEY_RESISTOR

#define VOLUME_DEFUALT 30

#define LINE_IN_PLAY_KEY_PAUSE
#define FM_PLAY_KEY_PAUSE

#define MUTE_EXAMP_AT_NEXT_PREV
//#define INDEPENDENT_VOLUME_KEY

//#define USE_LINE_IN_DETECT_FUNC
//#define AUX_DETECT_USE_P02
#endif

#ifdef K1031_DingChuangXin_808_V001

#define AC209_28PIN		//28 PIN IC GPIO CONFIG
#ifdef IIC_GPIO_USE_P02_P03
#undef IIC_GPIO_USE_P02_P03
#endif
#define IIC_GPIO_USE_P00_P01

#ifdef MUTE_PORT_USE_P01
#undef MUTE_PORT_USE_P01
#endif
#define MUTE_PORT_USE_P26

#define PLAY_STATUS_LED_P27

#define ADKEY_PLAY_SHORT_SCAN_FRE

#define EXCHANGE_LINE_IN_CHANNEL	//交换LINE IN 通道
#define FM_BY_PASS

#define CUSTOMER_DEFINED_ADKEY_RESISTOR

#define VOLUME_DEFUALT 30
#define INDEPENDENT_VOLUME_KEY
#define MUTE_EXAMP_AT_NEXT_PREV
#define USB_SD_PLAY_INFO_DIV
#define USE_LINE_IN_DETECT_FUNC
#define AUX_DETECT_USE_P02
#endif

#ifdef K1037_JinRUI_1037_V001

#define AC209_28PIN		//28 PIN IC GPIO CONFIG
#ifdef IIC_GPIO_USE_P02_P03
#undef IIC_GPIO_USE_P02_P03
#endif
#define IIC_GPIO_USE_P00_P01

#ifdef MUTE_PORT_USE_P01
#undef MUTE_PORT_USE_P01
#endif
#define MUTE_PORT_USE_P26

#define PLAY_STATUS_LED_P27

#define ADKEY_PLAY_SHORT_SCAN_FRE

#define EXCHANGE_LINE_IN_CHANNEL	//交换LINE IN 通道

#define FM_BY_PASS


#endif


#ifdef K2012_MY_M90_V001

#define AC209_28PIN		//28 PIN IC GPIO CONFIG
#ifdef IIC_GPIO_USE_P02_P03
#undef IIC_GPIO_USE_P02_P03
#endif
#define IIC_GPIO_USE_P00_P01

#ifdef MUTE_PORT_USE_P01
#undef MUTE_PORT_USE_P01
#endif
#define MUTE_PORT_USE_P26

#define PLAY_STATUS_LED_P27

#define ADKEY_PLAY_SHORT_SCAN_FRE

#define EXCHANGE_LINE_IN_CHANNEL	//交换LINE IN 通道
#define VOLUME_DEFUALT 28
//#define EQ_MODE_DEFUALT_POP

#define FM_BY_PASS

#define EQ_MODE_DEFUALT_ROCK

#ifdef LED_CTRL_LEVEL_NORMAL
#undef LED_CTRL_LEVEL_NORMAL
#endif

#define USB_SD_PLAY_INFO_DIV

#define INDEPENDENT_VOLUME_KEY
#define KEY_100_ENABLE
#define FF_LARGE_STEP
#define NO_FM_FUNC
#define NO_FM_FUNC
#define FF_FR_TURN_ON_MUSIC
#define NO_DEV_LED_IMPROVE
#define REP_ONE_SELECT_SONG_IMPROVE

#define PLAY_MODE_USE_REP_ONE_ALL
#define IR_REMOTER_WITH_POWER_MUTE_PRINT
#define LED_RUN_FAST_WHEN_PLAY_MODE_AT_REP_ONE

#endif

#ifdef K2070_YJH_2070_V001

#define AC209_28PIN		//28 PIN IC GPIO CONFIG
#ifdef IIC_GPIO_USE_P02_P03
#undef IIC_GPIO_USE_P02_P03
#endif
#define IIC_GPIO_USE_P00_P01

#ifdef MUTE_PORT_USE_P01
#undef MUTE_PORT_USE_P01
#endif
#define MUTE_PORT_USE_P26

#define PLAY_STATUS_LED_P27

#define LED_RUN_FAST_WHEN_PLAY_MODE_AT_REP_ONE

#define EXCHANGE_LINE_IN_CHANNEL	//交换LINE IN 通道

#define FM_BY_PASS
#define FM_PLAY_KEY_PAUSE
#define LINE_IN_PLAY_KEY_PAUSE

#define PLAY_MODE_USE_REP_ONE_ALL
#define USE_LONG_MODE_KEY_PLAY_MODE


#define TURN_ON_PLAY_BREAK_POINT_MEM
//#define AUX_DETECT_USE_P02

#define INDEPENDENT_VOLUME_KEY

#endif

#ifdef K1053_YJH_1053_V001

#define AC209_28PIN		//28 PIN IC GPIO CONFIG
#ifdef IIC_GPIO_USE_P02_P03
#undef IIC_GPIO_USE_P02_P03
#endif
#define IIC_GPIO_USE_P00_P01

#ifdef MUTE_PORT_USE_P01
#undef MUTE_PORT_USE_P01
#endif
#define MUTE_PORT_USE_P26

#define PLAY_STATUS_LED_P27

#define ADKEY_PLAY_SHORT_SCAN_FRE

#define EXCHANGE_LINE_IN_CHANNEL	//交换LINE IN 通道

#define FM_BY_PASS

#define USE_LINE_IN_DETECT_FUNC
#define AUX_DETECT_USE_P02

#define INDEPENDENT_VOLUME_KEY

#endif

#ifdef K1056_SUOERSI_1056_V001

#define AC209_28PIN		//28 PIN IC GPIO CONFIG
#ifdef IIC_GPIO_USE_P02_P03
#undef IIC_GPIO_USE_P02_P03
#endif
#define IIC_GPIO_USE_P00_P01

#ifdef MUTE_PORT_USE_P01
#undef MUTE_PORT_USE_P01
#endif
#define MUTE_PORT_USE_P26

#define PLAY_STATUS_LED_P27

#define ADKEY_PLAY_SHORT_SCAN_FRE

#define EXCHANGE_LINE_IN_CHANNEL	//交换LINE IN 通道

#define FM_BY_PASS

#define USE_GPIO_DETECT_EARPHONE_PLUGGED
#define EARPHONE_DETECT_USE_P02
#define USE_LONG_PLAY_KEY_TO_SWITCH_MODE


//#define INDEPENDENT_VOLUME_KEY
#endif

#ifdef K1057_SUOERSI_1057_V001

#define AC209_28PIN		//28 PIN IC GPIO CONFIG
#ifdef IIC_GPIO_USE_P02_P03
#undef IIC_GPIO_USE_P02_P03
#endif
#define IIC_GPIO_USE_P00_P01

#ifdef MUTE_PORT_USE_P01
#undef MUTE_PORT_USE_P01
#endif
#define MUTE_PORT_USE_P26

#define PLAY_STATUS_LED_P27

#define ADKEY_PLAY_SHORT_SCAN_FRE

#define EXCHANGE_LINE_IN_CHANNEL	//交换LINE IN 通道

#define FM_BY_PASS

//#define USE_LONG_PLAY_KEY_TO_SWITCH_MODE

#define USE_LINE_IN_DETECT_FUNC
#define AUX_DETECT_USE_P02

#define FM_USE_AR1015

#endif

#ifdef K1072_SUOERSI_1072_V001

#define AC209_28PIN		//28 PIN IC GPIO CONFIG
#ifdef IIC_GPIO_USE_P02_P03
#undef IIC_GPIO_USE_P02_P03
#endif
#define IIC_GPIO_USE_P00_P01

#ifdef MUTE_PORT_USE_P01
#undef MUTE_PORT_USE_P01
#endif
#define MUTE_PORT_USE_P26

#define PLAY_STATUS_LED_P27

#define ADKEY_PLAY_SHORT_SCAN_FRE

//#define EXCHANGE_LINE_IN_CHANNEL	//交换LINE IN 通道

#define VOLUME_DEFUALT 28

#define NOT_USE_LINE_IN_FUNC

#define DEFAULT_GO_TO_IDLE

#define USE_MANUAL_IDLE_FUNC

#endif
#ifdef K1073_SUOERSI_1073_V001

#define AC209_28PIN		//28 PIN IC GPIO CONFIG
#ifdef IIC_GPIO_USE_P02_P03
#undef IIC_GPIO_USE_P02_P03
#endif
#define IIC_GPIO_USE_P00_P01

#ifdef MUTE_PORT_USE_P01
#undef MUTE_PORT_USE_P01
#endif
#define MUTE_PORT_USE_P26

#define PLAY_STATUS_LED_P27

#define ADKEY_PLAY_SHORT_SCAN_FRE

#define EXCHANGE_LINE_IN_CHANNEL	//交换LINE IN 通道

#define VOLUME_DEFUALT 28

#define FM_BY_PASS
//#define NOT_USE_LINE_IN_FUNC


#endif

#ifdef K000_QY_200_V001


#define AC209_28PIN		//28 PIN IC GPIO CONFIG
#ifdef IIC_GPIO_USE_P02_P03
#undef IIC_GPIO_USE_P02_P03
#endif
#define IIC_GPIO_USE_P00_P01

#ifdef MUTE_PORT_USE_P01
#undef MUTE_PORT_USE_P01
#endif
#define MUTE_PORT_USE_DUMP

//#define PLAY_STATUS_LED_P27

#define NEW_CUSTOMIZED_LED_METHOD

#define FM_PLAY_KEY_PAUSE

#define EXCHANGE_LINE_IN_CHANNEL	//交换LINE IN 通道

#define FM_LINE_IN_SHARE_SAME_CHANNEL

#define VOLUME_DEFUALT 28
#define USE_EQ_KEY_SHORT_SCAN
#define DEFAULT_GO_TO_IDLE
#define NO_DEV_LED_IMPROVE
#define FM_SCAN_MODE_KEY_SMOOTH_FUNC
#define USE_MANUAL_IDLE_FUNC

#define SEMI_AUTO_SCAN_FREQ
#define ADKEY_NEXT_PREV_HOLD_AUTO_SCAN
#define FM_PAUSE_LED_INDICATOR

#define USE_LINE_IN_DETECT_FUNC
#define AUX_DETECT_USE_P02
#define INDEPENDENT_VOLUME_KEY

#endif


#ifdef K1076_DCX_801C_V001

#define AC209_28PIN		//28 PIN IC GPIO CONFIG
#ifdef IIC_GPIO_USE_P02_P03
#undef IIC_GPIO_USE_P02_P03
#endif
#define IIC_GPIO_USE_P00_P01

#ifdef MUTE_PORT_USE_P01
#undef MUTE_PORT_USE_P01
#endif
#define MUTE_PORT_USE_P26

#define PLAY_STATUS_LED_P27

#define ADKEY_PLAY_SHORT_SCAN_FRE
#define USE_LONG_PLAY_KEY_TO_SWITCH_MODE

#define EXCHANGE_LINE_IN_CHANNEL	//交换LINE IN 通道

#define VOLUME_DEFUALT 28

#define FM_BY_PASS


#endif


#ifdef K2036_WK_2036_V001

#define AC209_28PIN		//28 PIN IC GPIO CONFIG
#ifdef IIC_GPIO_USE_P02_P03
#undef IIC_GPIO_USE_P02_P03
#endif
//#define IIC_GPIO_USE_P01_P00
#define IIC_GPIO_USE_P00_P01

#ifdef MUTE_PORT_USE_P01
#undef MUTE_PORT_USE_P01
#endif
#define MUTE_PORT_USE_P26

#define PLAY_STATUS_LED_P27

#define GPIO_SWITCH_SELECT_MODE

#define LINE_IN_PLAY_KEY_PAUSE
#define FM_PLAY_KEY_PAUSE

#define EXCHANGE_LINE_IN_CHANNEL	//交换LINE IN 通道

#define VOLUME_DEFUALT 25
#define CUSTOM_VOL_LIMIT_AT_VOL_DEF

#define USE_BAT_MANAGEMENT
#define NEW_SD_DETECT_MOD
//#define CHARGER_FLASH_TYPE_1
//#define DC_CHARGE_GPIO_DRV_LED_IND
//#define DISABLE_P05_OSC_OUTPUT
//#define DC_DETECT_USE_P05


#define FM_BY_PASS
#define FM_USE_AR1015

#define USE_GPIO_DETECT_EARPHONE_PLUGGED
#define DEFAULT_GO_TO_IDLE

#define USE_LINE_IN_DETECT_FUNC
#define AUX_DETECT_USE_P02
#define AUX_DETECT_SHARE_WITH_IIC_SCL

#endif

#ifdef K1067_MY_1067_V001

#define AC209_28PIN		//28 PIN IC GPIO CONFIG
#ifdef IIC_GPIO_USE_P02_P03
#undef IIC_GPIO_USE_P02_P03
#endif
#define IIC_GPIO_USE_P00_P01

#ifdef MUTE_PORT_USE_P01
#undef MUTE_PORT_USE_P01
#endif
#define MUTE_PORT_USE_P26

#define PLAY_STATUS_LED_P27

#define ADKEY_PLAY_SHORT_SCAN_FRE
#define NEXT_PREV_HOLD_DO_NOTHING

#define EXCHANGE_LINE_IN_CHANNEL	//交换LINE IN 通道

#define VOLUME_DEFUALT 28

#define DEFAULT_GO_TO_IDLE
#define INDEPENDENT_VOLUME_KEY

#define FM_BY_PASS


#endif

#ifdef K2039_LHGC_2039_V001

#define AC209_28PIN		//28 PIN IC GPIO CONFIG
#ifdef IIC_GPIO_USE_P02_P03
#undef IIC_GPIO_USE_P02_P03
#endif
#define IIC_GPIO_USE_P00_P01

#ifdef MUTE_PORT_USE_P01
#undef MUTE_PORT_USE_P01
#endif
#define MUTE_PORT_USE_P26

#define PLAY_STATUS_LED_P27

#define ADKEY_PLAY_SHORT_SCAN_FRE

#define EXCHANGE_LINE_IN_CHANNEL	//交换LINE IN 通道

#define VOLUME_DEFUALT 28

#define FM_BY_PASS


#endif

#ifdef K000_TC_3006_V001

#define TianCheng_Remote
#define SYS_CRYSTAL_USE_12M

#define AC209_28PIN		//28 PIN IC GPIO CONFIG
#ifdef IIC_GPIO_USE_P02_P03
#undef IIC_GPIO_USE_P02_P03
#endif
#define IIC_GPIO_USE_P05_P02

#ifdef MUTE_PORT_USE_P01
#undef MUTE_PORT_USE_P01
#endif
#define MUTE_PORT_USE_P27

#define PLAY_STATUS_LED_P26


#define NEW_RES_VALUE_CACULATING

#define CUSTOMER_DEFINED_ADKEY_RESISTOR


#define SEMI_AUTO_SCAN_FREQ
#define ADKEY_NEXT_PREV_HOLD_AUTO_SCAN
#define IR_NEXT_PREV_HOLD_AUTO_SCAN

#define IR_PLAY_KEY_SCAN_FREQ_DISABLE
#define IR_PLAY_KEY_LONG_SCAN_FREQ

#define EXCHANGE_LINE_IN_CHANNEL	//交换LINE IN 通道

#define VOLUME_DEFUALT 30

#define FM_BY_PASS
#define DISABLE_P05_OSC_OUTPUT
#define QN_SHARE_MCU_CRYSTAL
#define TURN_ON_PLAY_BREAK_POINT_MEM
#define PLAY_MODE_USE_REP_ONE_ALL
#define IR_NEXT_PREV_KEY_HOLD_TUNE_VOL

#endif

#ifdef K000_TC_901_V001

#define TianCheng_Remote
#define SYS_CRYSTAL_USE_12M

#define AC209_28PIN		//28 PIN IC GPIO CONFIG
#ifdef IIC_GPIO_USE_P02_P03
#undef IIC_GPIO_USE_P02_P03
#endif
#define IIC_GPIO_USE_P05_P02

#ifdef MUTE_PORT_USE_P01
#undef MUTE_PORT_USE_P01
#endif
#define MUTE_PORT_USE_P27

#define PLAY_STATUS_LED_P26


#define NEW_RES_VALUE_CACULATING

#define CUSTOMER_DEFINED_ADKEY_RESISTOR


#define SEMI_AUTO_SCAN_FREQ
#define ADKEY_NEXT_PREV_HOLD_AUTO_SCAN
#define IR_NEXT_PREV_HOLD_AUTO_SCAN

#define IR_PLAY_KEY_SCAN_FREQ_DISABLE
#define IR_PLAY_KEY_LONG_SCAN_FREQ

#define EXCHANGE_LINE_IN_CHANNEL	//交换LINE IN 通道

#define VOLUME_DEFUALT 30

#define FM_BY_PASS
#define DISABLE_P05_OSC_OUTPUT
#define QN_SHARE_MCU_CRYSTAL
#define TURN_ON_PLAY_BREAK_POINT_MEM
#define PLAY_MODE_USE_REP_ONE_ALL
#define IR_NEXT_PREV_KEY_HOLD_TUNE_VOL

#endif

#ifdef K2048_WK_2048_V001

#define AC209_28PIN		//28 PIN IC GPIO CONFIG
#ifdef IIC_GPIO_USE_P02_P03
#undef IIC_GPIO_USE_P02_P03
#endif
#define IIC_GPIO_USE_P00_P01

#ifdef MUTE_PORT_USE_P01
#undef MUTE_PORT_USE_P01
#endif
#define MUTE_PORT_USE_DUMP
#define MUTE_GPIO_FM_GPIO_COMPATIBALE
#define USE_FM_GPIO

#define PLAY_STATUS_LED_P05
#define CUSTOMER_DEFINED_ADKEY_RESISTOR

#define ADKEY_PLAY_SHORT_SCAN_FRE


#define USE_GPIO_DETECT_EARPHONE_PLUGGED
#define EARPHONE_DETECT_USE_VPP

#define EXCHANGE_LINE_IN_CHANNEL	//交换LINE IN 通道

#define VOLUME_DEFUALT 28

#define DISABLE_P05_OSC_OUTPUT
#define USE_LINE_IN_DETECT_FUNC
#define AUX_DETECT_USE_P05

#if 1
#define USE_POWER_KEY
#define USE_ONLY_POWER_HOLD_CTRL
#define PWR_CTRL_P02
#define USE_PWR_KEY_LONG_PWR_ON
#endif

#define USE_POWER_KEY_TO_SWITCH_MODE


#endif

#ifdef K1101_JY_1101_V001

#define AC209_28PIN		//28 PIN IC GPIO CONFIG
#ifdef IIC_GPIO_USE_P02_P03
#undef IIC_GPIO_USE_P02_P03
#endif
#define IIC_GPIO_USE_P00_P01

#ifdef MUTE_PORT_USE_P01
#undef MUTE_PORT_USE_P01
#endif
#define MUTE_PORT_USE_P26

#define PLAY_STATUS_LED_P27

#define CUSTOMER_DEFINED_ADKEY_RESISTOR

#define EXCHANGE_LINE_IN_CHANNEL	//交换LINE IN 通道

#define VOLUME_DEFUALT 28

#if 1
#define USE_POWER_KEY
#define USE_ONLY_POWER_HOLD_CTRL
#define PWR_CTRL_P02
#define USE_PWR_KEY_LONG_PWR_ON
#endif

#define USE_POWER_KEY_SHORT_SCAN
#define POWE_KEY_PLAY_KEY_IN_ONE_KEY


#endif


#ifdef K0000_AKL_522_V001

#define AC209_28PIN		//28 PIN IC GPIO CONFIG
#ifdef IIC_GPIO_USE_P02_P03
#undef IIC_GPIO_USE_P02_P03
#endif
#define IIC_GPIO_USE_P00_P01

#ifdef MUTE_PORT_USE_P01
#undef MUTE_PORT_USE_P01
#endif
#define MUTE_PORT_USE_P26

#define PLAY_STATUS_LED_P27

#define CUSTOMER_DEFINED_ADKEY_RESISTOR

#define EXCHANGE_LINE_IN_CHANNEL	//交换LINE IN 通道

#define VOLUME_DEFUALT 28

#define FM_BY_PASS

#define USE_GPIO_DETECT_EARPHONE_PLUGGED
#define EARPHONE_DETECT_USE_P02

#define USE_LINE_IN_DETECT_FUNC
#define AUX_DETECT_USE_VPP

#define FM_USE_KT0830EG

#endif


#ifdef K0000_GW_300G_V001

//#define SYS_CRYSTAL_USE_12M
//#define QN_SHARE_MCU_CRYSTAL

#define AC209_28PIN		//28 PIN IC GPIO CONFIG
#ifdef IIC_GPIO_USE_P02_P03
#undef IIC_GPIO_USE_P02_P03
#endif
#define IIC_GPIO_USE_P00_P01

#ifdef MUTE_PORT_USE_P01
#undef MUTE_PORT_USE_P01
#endif
#define MUTE_PORT_USE_P02
#define USE_EQ_KEY_SHORT_CH_UP

#define PLAY_STATUS_LED_P01
#define PLAY_STATUS_LED_SHARE_WITH_IIC_SCL

#define CUSTOMER_DEFINED_ADKEY_RESISTOR
//#define FM_BY_PASS

#define EXCHANGE_FM_MP3_ICON

#define CUSTOMER_DEFINED_ADKEY_RESISTOR
#define NEW_RES_VALUE_CACULATING
#define CUSTOME_GW_RES_VALUE_2

#define DEFAULT_GO_TO_FM
#define NEW_SD_DETECT_MOD
#define NEXT_PREV_HOLD_DO_NOTHING
#define EXCHANGE_LINE_IN_CHANNEL	//交换LINE IN 通道
#define PLAY_MODE_USE_REP_ONE_ALL
#define PLAY_MODE_USE_INTRO_MODE
#define IR_INFO_EQ_DOWN_SCAN
#define INDEPENDENT_VOLUME_KEY

#define IR_NEXT_PREV_KEY_HOLD_DO_NOTHING

#define ADKEY_PLAY_SHORT_ADJ_CH
#define IR_PLAY_SHORT_CH_UP
#define IR_NEXT_PREV_SHORT_ADJ_CH
#define SEMI_AUTO_SCAN_FREQ
#define IR_NEXT_PREV_HOLD_AUTO_SCAN
#define ADKEY_NEXT_PREV_HOLD_AUTO_SCAN

#define IR_INFO_EQ_DOWN_FOR_INTRO_MODE
#define LED_RUN_FAST_WHEN_PLAY_MODE_AT_REP_ONE
#define LED_STATUS_STOP_AT_VALID_STATION

#define DECODE_STOP_MODE_ENABLE	
#define STOP_MODE_SHOW_STOP
#define STOP_REPLAY_FROM_FIRST_FILE
#define STOP_KEY_FOR_REPLAY_FROM_START
#define IR_NEXT_PREV_KEY_LONG_SEL_DIR
#define USE_FOLDER_SELECT_FUNC


#define VOLUME_DEFUALT 28


#endif


#ifdef K3002_WXS_K6_V001

#define AC209_28PIN		//28 PIN IC GPIO CONFIG
#ifdef IIC_GPIO_USE_P02_P03
#undef IIC_GPIO_USE_P02_P03
#endif
#define IIC_GPIO_USE_P01_P00

#ifdef MUTE_PORT_USE_P01
#undef MUTE_PORT_USE_P01
#endif
#define MUTE_PORT_USE_P02

#define PLAY_STATUS_LED_SHARE_WITH_IIC_SCL
#define PLAY_MODE_USE_REP_ONE_ALL
#define LED_RUN_FAST_WHEN_PLAY_MODE_AT_REP_ONE

#ifdef  MUTE_CTRL_LEVEL_NORMAL
#undef MUTE_CTRL_LEVEL_NORMAL
#endif
#define PLAY_STATUS_LED_P01

#define DEFAULT_GO_TO_IDLE
#define EXCHANGE_LINE_IN_CHANNEL	//交换LINE IN 通道

#define VOLUME_DEFUALT 28

#define CUSTOMER_DEFINED_ADKEY_RESISTOR
#define FM_PLAY_KEY_PAUSE
#define FM_PAUSE_LED_INDICATOR
#define NEW_RES_VALUE_CACULATING
#define CUSTOME_W_SIR_RES_VALUE


#define TURN_ON_PLAY_BREAK_POINT_MEM
#endif

#ifdef K0000_UST_U51_V001

#define AC209_28PIN		//28 PIN IC GPIO CONFIG
#ifdef IIC_GPIO_USE_P02_P03
#undef IIC_GPIO_USE_P02_P03
#endif
#define IIC_GPIO_USE_P01_P00

#ifdef MUTE_PORT_USE_P01
#undef MUTE_PORT_USE_P01
#endif
#define MUTE_PORT_USE_P27
#define MUTE_GPIO_FM_GPIO_COMPATIBALE
#define USE_FM_GPIO

#define PLAY_STATUS_LED_P01
#define PLAY_STATUS_LED_SHARE_WITH_IIC_SCL

#if 1
#define USE_POWER_KEY
#define USE_ONLY_POWER_HOLD_CTRL
#define PWR_CTRL_P02
#define USE_PWR_KEY_LONG_PWR_ON
#define PWR_ON_DELAY_1_SECOND
#endif



#define EXCHANGE_LINE_IN_CHANNEL	//交换LINE IN 通道

#undef USE_RDAs_FM
#undef USE_BK1080_FM

#define VOLUME_DEFUALT 28
#define DEFAULT_GO_TO_IDLE

#define CUSTOMER_DEFINED_ADKEY_RESISTOR
#define NEW_RES_VALUE_CACULATING
#define DEFAULT_RES_VALUE_3
#define OTP_MUSIC_FUNC_ENABLE

#define USE_LINE_IN_DETECT_FUNC
#define AUX_DETECT_USE_VPP
#endif

#ifdef K0000_MC_A6B_V001

#define AC209_28PIN		//28 PIN IC GPIO CONFIG
#ifdef IIC_GPIO_USE_P02_P03
#undef IIC_GPIO_USE_P02_P03
#endif
#define IIC_GPIO_USE_P00_P01

#ifdef MUTE_PORT_USE_P01
#undef MUTE_PORT_USE_P01
#endif
#define MUTE_PORT_USE_P26

#define FM_BY_PASS

#undef LED_CTRL_LEVEL_NORMAL

#define USE_BAT_MANAGEMENT
#define LOW_BAT_POWER_OFF_MODE

#define PLAY_STATUS_LED_P02
#define TURN_ON_PLAY_BREAK_POINT_MEM

#define EXCHANGE_LINE_IN_CHANNEL	//交换LINE IN 通道
#define ADKEY_PLAY_SHORT_SCAN_FRE

#define LINE_IN_PLAY_KEY_PAUSE

#define USE_LONG_PLAY_KEY_TO_SWITCH_MODE
#define VOLUME_DEFUALT 20

#define CUSTOMER_DEFINED_ADKEY_RESISTOR
#define NEW_RES_VALUE_CACULATING
#define DEFAULT_RES_VALUE_2

#define USE_GPIO_DETECT_EARPHONE_PLUGGED
#define EARPHONE_DETECT_USE_VPP
#endif


#ifdef K1129_ZK_962_V001

#define AC209_28PIN		//28 PIN IC GPIO CONFIG
#ifdef IIC_GPIO_USE_P02_P03
#undef IIC_GPIO_USE_P02_P03
#endif
#define IIC_GPIO_USE_P00_P01

#ifdef MUTE_PORT_USE_P01
#undef MUTE_PORT_USE_P01
#endif
#define MUTE_PORT_USE_P26

#define PLAY_STATUS_LED_P27

//#define EXCHANGE_LINE_IN_CHANNEL	//交换LINE IN 通道
#define ADKEY_PLAY_SHORT_SCAN_FRE
//#define USE_USB_HOTPLUG_FUNC

#define DEFAULT_GO_TO_IDLE
#define USE_LONG_PLAY_KEY_TO_SWITCH_MODE

#define NOT_USE_LINE_IN_FUNC
#define USB_AUDIO_PLAY_LED_FLASH
#define USE_GPIO_DETECT_EARPHONE_PLUGGED
#define EARPHONE_DETECT_USE_P02

#endif


#ifdef K0000_YH_082_V001

#define AC209_28PIN		//28 PIN IC GPIO CONFIG
#ifdef IIC_GPIO_USE_P02_P03
#undef IIC_GPIO_USE_P02_P03
#endif
#define IIC_GPIO_USE_P00_P01

#ifdef MUTE_PORT_USE_P01
#undef MUTE_PORT_USE_P01
#endif
//#define MUTE_PORT_USE_P26
#define NO_PLAY_STATUS_LED
#define CUSTOMIED_LED_GPIO_CTRL
#define USE_CUSTOMIED_GPIO_KEY
#define CUSTOMIZED_KEY_FUNC_ENABLE
#define NO_ADKEY_FUNC
//#define EXCHANGE_LINE_IN_CHANNEL	//交换LINE IN 通道
//#define ADKEY_PLAY_SHORT_SCAN_FRE
//#define USE_USB_HOTPLUG_FUNC
#define VOLUME_DEFUALT	30
//#define USE_LONG_PLAY_KEY_TO_SWITCH_MODE

#define NOT_USE_LINE_IN_FUNC
//#define USB_AUDIO_PLAY_LED_FLASH
//#define USE_GPIO_DETECT_EARPHONE_PLUGGED
//#define EARPHONE_DETECT_USE_P02

#endif


#ifdef K0000_MC_TYM1_V001

#define AC209_28PIN		//28 PIN IC GPIO CONFIG
//#define LED_USE_PLAY_MODE
#define IMPROVED_BAT_MEASURE

#ifdef IIC_GPIO_USE_P02_P03
#undef IIC_GPIO_USE_P02_P03
#endif
#define IIC_GPIO_USE_P00_P01
#ifdef MUTE_PORT_USE_P01
#undef  MUTE_PORT_USE_P01
#endif
#define MUTE_PORT_USE_P26

#define PLAY_STATUS_LED_P27


#define MEI_CHENG_BAT_PARA

#define EXCHANGE_LINE_IN_CHANNEL	//交换LINE IN 通道

#define VOLUME_DEFUALT	20

#define FM_LINE_IN_SHARE_SAME_CHANNEL

#if 1
#define USE_POWER_KEY
#define USE_ONLY_POWER_HOLD_CTRL
#define PWR_CTRL_P02
#define USE_PWR_KEY_LONG_PWR_ON
#endif

#define CUSTOMER_DEFINED_ADKEY_RESISTOR

#define POWE_KEY_PLAY_KEY_IN_ONE_KEY
#define USE_POWER_KEY_SHORT_SCAN

#define TURN_ON_PLAY_BREAK_POINT_MEM

#define USE_BAT_MANAGEMENT

#define LOW_BAT_POWER_OFF_MODE

#define USE_LINE_IN_DETECT_FUNC
#define AUX_DETECT_USE_VPP
#endif

#ifdef K1138_ZK_966_V001

#define AC209_28PIN		//28 PIN IC GPIO CONFIG
#ifdef IIC_GPIO_USE_P02_P03
#undef IIC_GPIO_USE_P02_P03
#endif
#define IIC_GPIO_USE_P00_P01

#ifdef MUTE_PORT_USE_P01
#undef MUTE_PORT_USE_P01
#endif
#define MUTE_PORT_USE_P26

#define PLAY_STATUS_LED_P27

#define EXCHANGE_LINE_IN_CHANNEL	//交换LINE IN 通道
#define FM_BY_PASS

#define ADKEY_PLAY_SHORT_SCAN_FRE

#define DEFAULT_GO_TO_IDLE
#define USE_LONG_PLAY_KEY_TO_SWITCH_MODE
#define FM_MAX_CHANNAL_50

//#define USE_LINE_IN_DETECT_FUNC
//#define AUX_DETECT_USE_P02

#endif


#ifdef K1146_ZK_968_V001

#define AC209_28PIN		//28 PIN IC GPIO CONFIG
#ifdef IIC_GPIO_USE_P02_P03
#undef IIC_GPIO_USE_P02_P03
#endif
#define IIC_GPIO_USE_P00_P01

#ifdef MUTE_PORT_USE_P01
#undef MUTE_PORT_USE_P01
#endif
#define MUTE_PORT_USE_P26

#define PLAY_STATUS_LED_P27

#define EXCHANGE_LINE_IN_CHANNEL	//交换LINE IN 通道
#define FM_BY_PASS

#define ADKEY_PLAY_SHORT_SCAN_FRE

#define DEFAULT_GO_TO_IDLE
#define USE_LONG_PLAY_KEY_TO_SWITCH_MODE
#define FM_MAX_CHANNAL_50
#define VOLUME_DEFUALT	30

#define USE_LINE_IN_DETECT_FUNC
#define AUX_DETECT_USE_P02
//#define DISPLAY_TEST

#endif
 
#ifdef K1106_SD_1106_V001

#define AC209_28PIN		//28 PIN IC GPIO CONFIG
#ifdef IIC_GPIO_USE_P02_P03
#undef IIC_GPIO_USE_P02_P03
#endif
#define IIC_GPIO_USE_P00_P01

#ifdef MUTE_PORT_USE_P01
#undef MUTE_PORT_USE_P01
#endif
#define MUTE_PORT_USE_P26

//#define PLAY_STATUS_LED_P27

#define EXCHANGE_LINE_IN_CHANNEL	//交换LINE IN 通道
#define FM_BY_PASS

#define ADKEY_PLAY_SHORT_SCAN_FRE

#define INDEPENDENT_VOLUME_KEY

#define FM_MAX_CHANNAL_50
#define VOLUME_DEFUALT	30
#define IR_USER_CODE_0x7F80
#define IR_PLAY_KEY_SCAN_FREQ_DISABLE
#define IR_REMOTER_WITH_POWER_MUTE_PRINT

#define NEW_CUSTOMIZED_LED_METHOD
#define PLAY_STATUS_LED_SHARE_WITH_IIC_SCL
#define USE_FM_GPIO
#define MUTE_GPIO_FM_GPIO_COMPATIBALE

//#define DISPLAY_TEST

#endif

#ifdef K0000_GW_138B_V001

//#define SYS_CRYSTAL_USE_12M
//#define QN_SHARE_MCU_CRYSTAL
#define PLAY_MODE_REPEAT_ALL
#define AC209_28PIN		//28 PIN IC GPIO CONFIG
#ifdef IIC_GPIO_USE_P02_P03
#undef IIC_GPIO_USE_P02_P03
#endif
#define IIC_GPIO_USE_P01_P00

#ifdef MUTE_PORT_USE_P01
#undef MUTE_PORT_USE_P01
#endif
#define MUTE_PORT_USE_P02
#undef LED_CTRL_LEVEL_NORMAL

#define PLAY_STATUS_LED_P01
#define PLAY_STATUS_LED_SHARE_WITH_IIC_SCL
#define CUSTOMER_DEFINED_ADKEY_RESISTOR
//#define FM_BY_PASS

#define EXCHANGE_FM_AUX_PRIO

#define GUOWEI_IR_REMOTE

#define DEFAULT_GO_TO_AUX
#define NEW_SD_DETECT_MOD
#define EXCHANGE_LINE_IN_CHANNEL	//交换LINE IN 通道
#define PLAY_MODE_USE_REP_ONE_ALL
//#define IR_PLAY_KEY_LONG_SCAN_FREQ
#define LED_RUN_SLOW_WHEN_PLAY_MODE_AT_REP_ONE

#define ADKEY_PLAY_SHORT_ADJ_CH
#define IR_PLAY_SHORT_CH_UP
#define IR_NEXT_PREV_SHORT_ADJ_CH
#define SEMI_AUTO_SCAN_FREQ
#define IR_NEXT_PREV_KEY_HOLD_DO_NOTHING
#define ADKEY_NEXT_PREV_SHORT_AUTO_SCAN

#define IR_NEXT_PREV_KEY_LONG_SEL_DIR
#define USE_FOLDER_SELECT_FUNC
#define IR_PLAY_KEY_SCAN_FREQ_DISABLE
#define EQ_DOWN_SCAN_ALL
#define NO_MUTE_WHEN_PAUSE

#define VOLUME_DEFUALT 28

//#define DISPLAY_TEST
#endif


#ifdef K000_QG_Q6_V001

#define AC209_28PIN		//28 PIN IC GPIO CONFIG
#ifdef IIC_GPIO_USE_P02_P03
#undef IIC_GPIO_USE_P02_P03
#endif
#define IIC_GPIO_USE_P00_P01

#ifdef MUTE_PORT_USE_P01
#undef MUTE_PORT_USE_P01
#endif
#define MUTE_PORT_USE_P26
#undef MUTE_CTRL_LEVEL_NORMAL

#define USE_BT_GPIO_SEL_MODE
#define PLAY_STATUS_LED_P27

#define EXCHANGE_LINE_IN_CHANNEL	//交换LINE IN 通道

#define USE_LINE_IN_DETECT_FUNC
#define AUX_DETECT_USE_VPP

#define VOLUME_DEFUALT	20
#define USE_LONG_PLAY_KEY_TO_SWITCH_MODE

#define DISABLE_P05_OSC_OUTPUT
#define SUPERIOR_CUSTOMER
#define BLUE_TOOTH_FUNC
#define BLUE_TOOTH_BYPASS
#define BLUETOOTH_GPIO_CTRL

#define LINE_IN_PLAY_KEY_PAUSE

#define CUSTOMER_DEFINED_ADKEY_RESISTOR
#define SYS_DEFAULT_IN_BLUETOOTH_MODE
#define USE_USB_HOTPLUG_FUNC
//#define DISPLAY_TEST

#endif


#ifdef K1162_DCX_1162_V001


#define AC209_28PIN		//28 PIN IC GPIO CONFIG
#ifdef IIC_GPIO_USE_P02_P03
#undef IIC_GPIO_USE_P02_P03
#endif
#define IIC_GPIO_USE_P01_P00

#ifdef MUTE_PORT_USE_P01
#undef MUTE_PORT_USE_P01
#endif
#define MUTE_PORT_USE_P26
//#define QN_SHARE_MCU_CRYSTAL
//#define DISABLE_P05_OSC_OUTPUT

#define PLAY_STATUS_LED_P27

#define EXCHANGE_LINE_IN_CHANNEL	//交换LINE IN 通道
#define CUSTOMER_DEFINED_ADKEY_RESISTOR

#define FM_BY_PASS
#define VOLUME_DEFUALT	30

#if 1
#define USE_POWER_KEY
#define USE_ONLY_POWER_HOLD_CTRL
#define PWR_CTRL_P02
#define USE_PWR_KEY_LONG_PWR_ON
#endif

//#define NEW_CUSTOMIZED_LED_METHOD
//#define EXTENDED_WORK_MODE_USE_TWO_GPIO_CTRL

#define POWE_KEY_PLAY_KEY_IN_ONE_KEY
#define USE_POWER_KEY_SHORT_SCAN

#define USE_LINE_IN_DETECT_FUNC
#define AUX_DETECT_USE_VPP
//#define PLAY_STATUS_LED_SHARE_WITH_IIC_SCL

#define USE_GPIO_DETECT_EARPHONE_PLUGGED
#define EARPHONE_DETECT_USE_P01

#define LINE_IN_PLAY_KEY_PAUSE
#define USE_POWER_KEY_FOR_AUX_PLAY
#define AUX_PAUSE_LED_INDICATOR_FLASH_WHEN_PLAY

//#define DISPLAY_TEST
#endif

#ifdef K1162_AJR_1162_V001


#define AC209_28PIN		//28 PIN IC GPIO CONFIG
#ifdef IIC_GPIO_USE_P02_P03
#undef IIC_GPIO_USE_P02_P03
#endif
#define IIC_GPIO_USE_P01_P00

#ifdef MUTE_PORT_USE_P01
#undef MUTE_PORT_USE_P01
#endif
#define MUTE_PORT_USE_P26
#define QN_SHARE_MCU_CRYSTAL
#define DISABLE_P05_OSC_OUTPUT

//#define PLAY_STATUS_LED_P27

#define EXCHANGE_LINE_IN_CHANNEL	//交换LINE IN 通道
#define CUSTOMER_DEFINED_ADKEY_RESISTOR

#define QN_SHARE_MCU_CRYSTAL

#define FM_BY_PASS
#define VOLUME_DEFUALT	30

#if 1
#define USE_POWER_KEY
#define USE_ONLY_POWER_HOLD_CTRL
#define PWR_CTRL_P02
#define USE_PWR_KEY_LONG_PWR_ON
#endif

#define NEW_CUSTOMIZED_LED_METHOD
#define EXTENDED_WORK_MODE_USE_TWO_GPIO_CTRL

#define POWE_KEY_PLAY_KEY_IN_ONE_KEY
#define USE_POWER_KEY_SHORT_SCAN

#define USE_LINE_IN_DETECT_FUNC
#define AUX_DETECT_USE_VPP
//#define PLAY_STATUS_LED_SHARE_WITH_IIC_SCL

#define LINE_IN_PLAY_KEY_PAUSE
#define USE_POWER_KEY_FOR_AUX_PLAY

#define USE_GPIO_DETECT_EARPHONE_PLUGGED
#define EARPHONE_DETECT_USE_P01
#define HP_DETECT_SHARE_WITH_IIC_SCL

//#define DISPLAY_TEST
#endif

#ifdef K1149_AJR_LSV8_V001


#define AC209_28PIN		//28 PIN IC GPIO CONFIG
#ifdef IIC_GPIO_USE_P02_P03
#undef IIC_GPIO_USE_P02_P03
#endif
#define IIC_GPIO_USE_P00_P01

#ifdef MUTE_PORT_USE_P01
#undef MUTE_PORT_USE_P01
#endif
#define MUTE_PORT_USE_P26

#define PLAY_STATUS_LED_P27

#define EXCHANGE_LINE_IN_CHANNEL	//交换LINE IN 通道
#define CUSTOMER_DEFINED_ADKEY_RESISTOR

#define FM_BY_PASS
#define VOLUME_DEFUALT	28

#if 1
#define USE_POWER_KEY
#define USE_ONLY_POWER_HOLD_CTRL
#define PWR_CTRL_P02
#define USE_PWR_KEY_LONG_PWR_ON
#endif

#define POWE_KEY_PLAY_KEY_IN_ONE_KEY
#define USE_POWER_KEY_SHORT_SCAN

#endif


#ifdef K000_SLAVE_V001

#define AC209_28PIN		//28 PIN IC GPIO CONFIG
#ifdef IIC_GPIO_USE_P02_P03
#undef IIC_GPIO_USE_P02_P03
#endif
#define IIC_GPIO_USE_P00_P01

#ifdef MUTE_PORT_USE_P01
#undef MUTE_PORT_USE_P01
#endif
#define MUTE_PORT_USE_P26

#define NO_ADKEY_FUNC

#define DISABLE_P05_OSC_OUTPUT
#define USE_FOLDER_SELECT_FUNC
#define ADKEY_NEXT_PREV_LONG_SEL_FOLDER
#define NO_PLAY_STATUS_LED
#define NOT_USE_LINE_IN_FUNC
#define DECODE_STOP_MODE_ENABLE

#define AC_SLAVE_ENABLE
#define SYS_DEFAULT_IN_IDLE
#define DEFAULT_GO_TO_IDLE

#define VOLUME_DEFUALT	30

#endif

#ifdef K1163_DYT_1163_V001

#define AC209_28PIN		//28 PIN IC GPIO CONFIG

#ifdef IIC_GPIO_USE_P02_P03
#undef IIC_GPIO_USE_P02_P03
#endif
#define IIC_GPIO_USE_P00_P01

#ifdef MUTE_PORT_USE_P01
#undef  MUTE_PORT_USE_P01
#endif
#define MUTE_PORT_USE_DUMP

#define PLAY_STATUS_LED_P02

#define NO_VOLUME_LIMITE
#define EXCHANGE_LINE_IN_CHANNEL	//交换LINE IN 通道
#define INDEPENDENT_VOLUME_KEY

//#define DISPLAY_TEST
#endif

#ifdef K0000_JK_QGAC18_V001

#define AC209_28PIN		//28 PIN IC GPIO CONFIG

#ifdef IIC_GPIO_USE_P02_P03
#undef IIC_GPIO_USE_P02_P03
#endif
#define IIC_GPIO_USE_P00_P01

#ifdef MUTE_PORT_USE_P01
#undef  MUTE_PORT_USE_P01
#endif
#define MUTE_PORT_USE_P26
#define JINRUI_IR_REMOTE_TYPE

#define DECODE_STOP_MODE_ENABLE
//#define PLAY_STATUS_LED_P27
#define LINE_IN_PLAY_KEY_PAUSE
#define MUTE_EXAMP_AT_NEXT_PREV
#define VOLUME_DEFUALT			30
#define NO_VOLUME_LIMITE
#define EXCHANGE_LINE_IN_CHANNEL	//交换LINE IN 通道

#define NEW_CUSTOMIZED_LED_METHOD
//#define DISPLAY_TEST
#endif

#ifdef K1301_JK_1301_V001

#define AC209_28PIN		//28 PIN IC GPIO CONFIG

#ifdef MUTE_PORT_USE_P01
#undef  MUTE_PORT_USE_P01
#endif

#define MUTE_PORT_USE_P26


#define VOLUME_DEFUALT	30

#define PLAY_STATUS_LED_P02
#define PLAY_STATUS_LED_PLAY_NO_SPARK
#define FM_BY_PASS
#define SUPERIOR_CUSTOMER
//#define NO_VOLUME_LIMITE

#define EXCHANGE_LINE_IN_CHANNEL	//交换LINE IN 通道
//#define CUSTOMER_DEFINED_ADKEY_RESISTOR
#define INDEPENDENT_VOLUME_KEY
//#define USE_LONG_MODE_FOR_POWER_KEY
//#define NO_DEV_LED_IMPROVE
#define NOT_USE_LINE_IN_FUNC
#define LED_RUN_SLOW_WHEN_PLAY_MODE_AT_REP_ONE_ONLY
#define PLAY_MODE_USE_REP_ONE_ALL
#define PLAY_STATUS_LED_OFF_AT_IDLE_NODEV
#define LED_LIGHT_ON_ENABLE_IN_IDLE_MODE
//#define DEVICE_SEL_MANUAL_ONLY
//#define DEFAULT_GO_TO_AUX
//#define DEFAULT_GO_TO_CUSTOM_MODE
//#define DEFAULT_GO_TO_CUSTOM_MODE_POWER_ON_FIRST_TIME_IN_AUX
//#define DEFAULT_GO_TO_CUSTOM_MODE_POWER_ON_AFTER_TIME_IN_IDLE
//#define SYS_DEFAULT_IN_IDLE_POWER_DOWN_MODE
//#define SYS_DEFAULT_IN_PWR_OFF_FOR_LED_PROTECTION
//#define DISPLAY_TEST

#endif

#ifdef K000_ZG_HA8918_NOR_V001

#define AC209_28PIN		//28 PIN IC GPIO CONFIG

#ifdef MUTE_PORT_USE_P01
#undef  MUTE_PORT_USE_P01
#endif

#define MUTE_PORT_USE_P26

#define CUSTOM_OUTPUT_LIMIT

#define VOLUME_DEFUALT	20

#define PLAY_STATUS_LED_P02
#define PLAY_STATUS_LED_IN_SLOW_MODE
#define FM_BY_PASS
#define SUPERIOR_CUSTOMER

#define EXCHANGE_LINE_IN_CHANNEL	//交换LINE IN 通道
#define CUSTOMER_DEFINED_ADKEY_RESISTOR
#define INDEPENDENT_VOLUME_KEY
#define USE_LONG_MODE_FOR_POWER_KEY
#define NO_DEV_LED_IMPROVE

//#define DEVICE_SEL_MANUAL_ONLY
#define DEFAULT_GO_TO_AUX
//#define DEFAULT_GO_TO_CUSTOM_MODE
//#define DEFAULT_GO_TO_CUSTOM_MODE_POWER_ON_FIRST_TIME_IN_AUX
//#define DEFAULT_GO_TO_CUSTOM_MODE_POWER_ON_AFTER_TIME_IN_IDLE
#define SYS_DEFAULT_IN_IDLE_POWER_DOWN_MODE
#define SYS_DEFAULT_IN_PWR_OFF_FOR_LED_PROTECTION
//#define DISPLAY_TEST

#endif

#ifdef K000_ZG_HA8919_BT_V001

#define AC209_28PIN		//28 PIN IC GPIO CONFIG

#ifdef IIC_GPIO_USE_P02_P03
#undef IIC_GPIO_USE_P02_P03
#endif
#define IIC_GPIO_USE_DUMMY

#ifdef MUTE_PORT_USE_P01
#undef  MUTE_PORT_USE_P01
#endif

#define CUSTOM_OUTPUT_LIMIT

#undef LED_CTRL_LEVEL_NORMAL
#define MUTE_PORT_USE_P00

#define PLAY_STATUS_LED_P02
#define PLAY_STATUS_LED_IN_SLOW_MODE

#define VOLUME_DEFUALT	20

#define FM_BY_PASS
#define SUPERIOR_CUSTOMER

#define EXCHANGE_LINE_IN_CHANNEL	//交换LINE IN 通道
#define CUSTOMER_DEFINED_ADKEY_RESISTOR
#define INDEPENDENT_VOLUME_KEY
#define USE_LONG_MODE_FOR_POWER_KEY
#define NO_DEV_LED_IMPROVE
#define TURN_OFF_PLAY_STATUS_LED_IN_BLUETOOTH_MODE


//#define DEVICE_SEL_MANUAL_ONLY
#define DEFAULT_GO_TO_AUX
//#define DEFAULT_GO_TO_CUSTOM_MODE
//#define DEFAULT_GO_TO_CUSTOM_MODE_POWER_ON_FIRST_TIME_IN_AUX
//#define DEFAULT_GO_TO_CUSTOM_MODE_POWER_ON_AFTER_TIME_IN_IDLE
#define SYS_DEFAULT_IN_IDLE_POWER_DOWN_MODE
#define SYS_DEFAULT_IN_PWR_OFF_FOR_LED_PROTECTION

#define BLUE_TOOTH_FUNC
#define BLUETOOTH_GPIO_CTRL
#define DISABLE_P05_OSC_OUTPUT


//#define DISPLAY_TEST

#endif


#ifdef K000_JK_ZHCX_V001

#define AC209_28PIN		//28 PIN IC GPIO CONFIG

#ifdef IIC_GPIO_USE_P02_P03
#undef IIC_GPIO_USE_P02_P03
#endif
#define IIC_GPIO_USE_DUMMY
#define PLAY_STATUS_LED_P00

#define DISABLE_P05_OSC_OUTPUT
#define PLAY_STATUS_LED_P05

#define NO_ADKEY_FUNC
#define PWR_CTRL_P27_KEY_P26

#define EXCHANGE_LINE_IN_CHANNEL	//交换LINE IN 通道
#define MATRIX_KEY_ENABLE


#define USE_LINE_IN_DETECT_FUNC
#define AUX_DETECT_USE_P01

#define BLUE_TOOTH_FUNC
//#define BLUETOOTH_GPIO_CTRL
#define SYS_POWER_ON_DEFAULT_IN_BT_AUX_ALTERNATIVE_MODE
#define BLUE_TOOTH_PATH_DIRECT_IN_PA
#define NOT_MOUNT_USB_SD_DEV
#define DISABLE_USE_DECODE_FUNC
#define DISABLE_SD_MMC_CARD_DECODE_FUNC
#define USE_IR_VPP_PORT_FOR_DETECTION
#define VOLUME_DEFUALT	30

//#define DISPLAY_TEST

#endif

#ifdef K000_JK_HY_WM2428B_V001

#define AC209_28PIN		//28 PIN IC GPIO CONFIG

#ifdef IIC_GPIO_USE_P02_P03
#undef IIC_GPIO_USE_P02_P03
#endif
#define IIC_GPIO_USE_DUMMY

#ifdef MUTE_PORT_USE_P01
#undef  MUTE_PORT_USE_P01
#endif
#define MUTE_PORT_USE_P26

#define DISABLE_P05_OSC_OUTPUT

#define NO_PLAY_STATUS_LED

#define EXCHANGE_LINE_IN_CHANNEL	//交换LINE IN 通道

#define VOLUME_DEFUALT	30
#define INDEPENDENT_VOLUME_KEY

#define USE_LINE_IN_DETECT_FUNC
#define AUX_DETECT_USE_P26
#define FF_FR_TURN_ON_MUSIC

#define USE_LONG_PLAY_KEY_TO_SWITCH_MODE


//#define DISPLAY_TEST

#endif


#ifdef K000_JK_HY_SM001_V001

#define AC209_28PIN		//28 PIN IC GPIO CONFIG

#ifdef IIC_GPIO_USE_P02_P03
#undef IIC_GPIO_USE_P02_P03
#endif
#define IIC_GPIO_USE_P01_P26

#ifdef MUTE_PORT_USE_P01
#undef  MUTE_PORT_USE_P01
#endif
#define MUTE_PORT_USE_P26

#undef LED_CTRL_LEVEL_NORMAL

#define DISABLE_P05_OSC_OUTPUT

#define PLAY_STATUS_LED_P27

#define TWO_PLAY_LED_IN_USE
#define TWO_PLAY_LED_USE_PORT_P01
#define USB_SD_DEV_PLUG_MEM
//#define EXCHANGE_LINE_IN_CHANNEL	//交换LINE IN 通道
#define EQ_LONG_PRESS_FOR_FM_MP3_SEL

#define DEVICE_ON_LINE_LED_IND

#define VOLUME_DEFUALT	30
#define NOT_USE_LINE_IN_FUNC
#define NEXT_PREV_HOLD_SEL_FILE
#define PREV_KEY_SKIP_SONG_DELAY
#define PLAY_STATUS_LED_PLAY_NO_SPARK
#define ASSIGN_GIVEN_DEVICE_AT_PWR_ON
#define DISABLE_DEVICE_HOT_PLUG_AND_PLAY
#define DEFAULT_GO_HOLD_IN_DECODE_MODE

#define NOT_SEL_ALTERNATIVE_DEV
#define USB_SD_PWR_UP_AND_PLUG_NOT_PLAY
#define DECODE_STOP_MODE_ENABLE
#define STOP_REPLAY_FROM_FIRST_FILE
#define NO_ADKEY_FUNC
#define MATRIX_KEY_ENABLE

#define SEMI_AUTO_SCAN_FREQ
#define ADKEY_NEXT_PREV_HOLD_AUTO_SCAN
#define ADKEY_NEXT_ADJST_FREQ
#define USE_STOP_KEY_SHORT_CH_DOWN

#define FM_MINI_FRE_875
//#define FM_STEP_50K 
//#define DISPLAY_TEST

#endif

#ifdef K000_JK_LBR_BT_V001

#define AC209_28PIN		//28 PIN IC GPIO CONFIG

#ifdef IIC_GPIO_USE_P02_P03
#undef IIC_GPIO_USE_P02_P03
#endif
#define IIC_GPIO_USE_P00_P01

#ifdef MUTE_PORT_USE_P01
#undef  MUTE_PORT_USE_P01
#endif
#define MUTE_PORT_USE_P26

#define DISABLE_P05_OSC_OUTPUT
#define PLAY_STATUS_LED_P27

#define EXCHANGE_LINE_IN_CHANNEL	//交换LINE IN 通道

#define BLUE_TOOTH_FUNC
#define BLUETOOTH_GPIO_CTRL
#define BLUE_TOOTH_BYPASS
#define VOLUME_DEFUALT	30

#define FM_BY_PASS

#define USE_AMP_MODE_SELECT
#define AMP_MODE_SELECT_PORT_USE_P05
#define HI_AB_LOW_D_CLASS_LEVEL


#define USE_LINE_IN_DETECT_FUNC
#define AUX_DETECT_USE_VPP


//#define DISPLAY_TEST

#endif

#ifdef K000_JK_BTONLY_V001

#define AC209_28PIN		//28 PIN IC GPIO CONFIG

#ifdef IIC_GPIO_USE_P02_P03
#undef IIC_GPIO_USE_P02_P03
#endif
#define IIC_GPIO_USE_DUMMY

#define DISABLE_P05_OSC_OUTPUT
#define PLAY_STATUS_LED_P05

#define NO_ADKEY_FUNC

#define EXCHANGE_LINE_IN_CHANNEL	//交换LINE IN 通道

#define USE_LINE_IN_DETECT_FUNC
#define AUX_DETECT_USE_VPP

#define BLUE_TOOTH_FUNC
#define BLUETOOTH_GPIO_CTRL
#define SYS_POWER_ON_DEFAULT_IN_BT_AUX_ALTERNATIVE_MODE
#define AUX_PAUSE_LED_INDICATOR_FLASH_WHEN_PLAY
#define NOT_MOUNT_USB_SD_DEV
#define LED_LIGHT_ON_ENABLE_IN_IDLE_MODE
#define SYS_DEFAULT_IN_PWR_OFF_FOR_LED_PROTECTION
#define SYS_DEFAULT_IN_PWR_OFF_FOR_LED_PROTECTION_UNTIL_AUX
#define VOLUME_DEFUALT	30

//#define DISPLAY_TEST

#endif

#ifdef K0000_XC_X813_V001

#define AC209_28PIN		//28 PIN IC GPIO CONFIG

#ifdef IIC_GPIO_USE_P02_P03
#undef IIC_GPIO_USE_P02_P03
#endif
#define IIC_GPIO_USE_P01_P00

#ifdef MUTE_PORT_USE_P01
#undef  MUTE_PORT_USE_P01
#endif

#ifdef MUTE_PORT_USE_P01
#undef  MUTE_PORT_USE_P01
#endif
#define MUTE_PORT_USE_P27
#undef MUTE_CTRL_LEVEL_NORMAL

#define PLAY_STATUS_LED_P01
#define PLAY_STATUS_LED_SHARE_WITH_IIC_SCL

#define FM_BY_PASS

#define ADKEY_PLAY_SHORT_SCAN_FRE

#define EXCHANGE_LINE_IN_CHANNEL	//交换LINE IN 通道

#define USE_LONG_PLAY_KEY_TO_SWITCH_MODE

#define USE_AMP_MODE_SELECT
#define AMP_MODE_SELECT_PORT_USE_P02
//#define DISPLAY_TEST
#define USE_LINE_IN_DETECT_FUNC
#define AUX_DETECT_USE_P26

#define SEMI_AUTO_SCAN_FREQ
#define ADKEY_NEXT_PREV_HOLD_AUTO_SCAN
#endif


#ifdef K2084_BY_S14_V001

#define AC209_28PIN		//28 PIN IC GPIO CONFIG

#ifdef IIC_GPIO_USE_P02_P03
#undef IIC_GPIO_USE_P02_P03
#endif
#define IIC_GPIO_USE_P00_P01

#ifdef MUTE_PORT_USE_P01
#undef  MUTE_PORT_USE_P01
#endif
#define MUTE_PORT_USE_P26

#define PLAY_STATUS_LED_P27

#define FM_BY_PASS

#define ADKEY_PLAY_SHORT_SCAN_FRE

#define EXCHANGE_LINE_IN_CHANNEL	//交换LINE IN 通道

#endif

#ifdef K2082_HF_2082_V001

#define AC209_28PIN		//28 PIN IC GPIO CONFIG

#ifdef IIC_GPIO_USE_P02_P03
#undef IIC_GPIO_USE_P02_P03
#endif
#define IIC_GPIO_USE_P00_P01

#ifdef MUTE_PORT_USE_P01
#undef  MUTE_PORT_USE_P01
#endif
#define MUTE_PORT_USE_P26

#define PLAY_STATUS_LED_P27

#define FM_BY_PASS

#define ADKEY_PLAY_SHORT_SCAN_FRE
#define USE_LONG_PLAY_KEY_TO_SWITCH_MODE

#define EXCHANGE_LINE_IN_CHANNEL	//交换LINE IN 通道

#endif


#ifdef K1176_LS_1176_V001

#define AC209_28PIN		//28 PIN IC GPIO CONFIG

#ifdef IIC_GPIO_USE_P02_P03
#undef IIC_GPIO_USE_P02_P03
#endif
#define IIC_GPIO_USE_P00_P01

#ifdef MUTE_PORT_USE_P01
#undef  MUTE_PORT_USE_P01
#endif
#define MUTE_PORT_USE_P26

#define PLAY_STATUS_LED_P02

#define FM_BY_PASS


#define EXCHANGE_LINE_IN_CHANNEL	//交换LINE IN 通道
#define SYS_DEFAULT_IN_IDLE_POWER_DOWN_MODE
#define USE_PLAY_KEY_TO_POWER_OFF
#define SKIP_PLAY_STATUS_LED_SPARK
#if 0
#define USE_POWER_KEY
#define USE_ONLY_POWER_HOLD_CTRL
#define PWR_CTRL_P02
#define USE_PWR_KEY_LONG_PWR_ON
#endif


#endif

#ifdef K1172_ALK_969B_V001

#define AC209_28PIN		//28 PIN IC GPIO CONFIG

#ifdef IIC_GPIO_USE_P02_P03
#undef IIC_GPIO_USE_P02_P03
#endif
#define IIC_GPIO_USE_P00_P01

#ifdef MUTE_PORT_USE_P01
#undef  MUTE_PORT_USE_P01
#endif
#define MUTE_PORT_USE_P26

#define PLAY_STATUS_LED_P27

#define FM_BY_PASS

#define ADKEY_PLAY_SHORT_SCAN_FRE

#define EXCHANGE_LINE_IN_CHANNEL	//交换LINE IN 通道
#define USE_LONG_PLAY_KEY_TO_SWITCH_MODE

#endif

#ifdef K1172_DCX_D968_V001

#define AC209_28PIN		//28 PIN IC GPIO CONFIG

#ifdef IIC_GPIO_USE_P02_P03
#undef IIC_GPIO_USE_P02_P03
#endif
#define IIC_GPIO_USE_P00_P01

#ifdef MUTE_PORT_USE_P01
#undef  MUTE_PORT_USE_P01
#endif
#define MUTE_PORT_USE_P26

#define PLAY_STATUS_LED_P27

#define FM_BY_PASS

#define ADKEY_PLAY_SHORT_SCAN_FRE

#define EXCHANGE_LINE_IN_CHANNEL	//交换LINE IN 通道

#define LINE_IN_PLAY_KEY_PAUSE

#define VOLUME_DEFUALT  20

#define USE_LINE_IN_DETECT_FUNC
#define AUX_DETECT_USE_P02
#endif




#ifdef K000_XFW_GL005_V001

#define AC209_28PIN		//28 PIN IC GPIO CONFIG

#ifdef IIC_GPIO_USE_P02_P03
#undef IIC_GPIO_USE_P02_P03
#endif
#define IIC_GPIO_USE_P00_P01

#ifdef MUTE_PORT_USE_P01
#undef  MUTE_PORT_USE_P01
#endif
#define MUTE_PORT_USE_P26

#define PLAY_STATUS_LED_P27

#define FM_BY_PASS

#define ADKEY_PLAY_SHORT_SCAN_FRE

#define EXCHANGE_LINE_IN_CHANNEL	//交换LINE IN 通道

#define GUOWEI_IR_REMOTE

#define VOLUME_DEFUALT  20

#define USE_LINE_IN_DETECT_FUNC
#define AUX_DETECT_USE_P02
#define PLAY_MODE_USE_REP_ONE_ALL

#define LED_RUN_FAST_WHEN_PLAY_MODE_AT_REP_ONE

#endif


#ifdef K3018_AP_751_V001

#define AC209_28PIN		//28 PIN IC GPIO CONFIG

#ifdef IIC_GPIO_USE_P02_P03
#undef IIC_GPIO_USE_P02_P03
#endif
#define IIC_GPIO_USE_P00_P01

#ifdef MUTE_PORT_USE_P01
#undef  MUTE_PORT_USE_P01
#endif
#define MUTE_PORT_USE_P26

#define PLAY_STATUS_LED_P27

#define FM_BY_PASS

#define ADKEY_PLAY_SHORT_SCAN_FRE

#define EXCHANGE_LINE_IN_CHANNEL	//交换LINE IN 通道

#define GUOWEI_IR_REMOTE

#define VOLUME_DEFUALT  20

#define PLAY_MODE_USE_REP_ONE_ALL

#if 1
#define USE_POWER_KEY
#define USE_ONLY_POWER_HOLD_CTRL
#define PWR_CTRL_P02
#define USE_PWR_KEY_LONG_PWR_ON
#endif


#endif

#ifdef K2125_AP_751C_V001

#define AC209_28PIN		//28 PIN IC GPIO CONFIG

#ifdef IIC_GPIO_USE_P02_P03
#undef IIC_GPIO_USE_P02_P03
#endif
#define IIC_GPIO_USE_P01_P00

#ifdef MUTE_PORT_USE_P01
#undef  MUTE_PORT_USE_P01
#endif
#define MUTE_PORT_USE_P26

#define PLAY_STATUS_LED_P01
#define PLAY_STATUS_LED_SHARE_WITH_IIC_SCL

//#define DISABLE_P05_OSC_OUTPUT

#define ADKEY_PLAY_SHORT_SCAN_FRE

#define EXCHANGE_LINE_IN_CHANNEL	//交换LINE IN 通道


#define USE_GPIO_DETECT_EARPHONE_PLUGGED
#define EARPHONE_DETECT_USE_VPP


#define LINE_IN_PLAY_KEY_PAUSE
#define USE_MODE_LONG_FOR_FM_CH_UP
#if 0
#define POWE_KEY_PLAY_KEY_IN_ONE_KEY
#define USE_POWER_KEY_SHORT_SCAN

#define USE_POWER_KEY
#define USE_ONLY_POWER_HOLD_CTRL
#define PWR_CTRL_P02
#define USE_PWR_KEY_LONG_PWR_ON
#endif

#define ADKEY_NEW_METHOD
#define USE_ADKEY_FOR_AUX_HP_DETECTION
#define USE_ADKEY_DETECT_AUX
#define NOR_ADKEY_DEFINITION

#define TURN_ON_PLAY_BREAK_POINT_MEM

#define CUSTOMER_DEFINED_ADKEY_RESISTOR

#define MUTE_GPIO_FM_GPIO_COMPATIBALE
#define USE_FM_GPIO
//#define QN_SHARE_MCU_CRYSTAL
//#define BK_SHARE_MCU_CRY

//#define DISPLAY_TEST
#endif

#ifdef K1226_AP_750_V001

//#define DISPLAY_TEST

#define AC209_28PIN		//28 PIN IC GPIO CONFIG

#ifdef IIC_GPIO_USE_P02_P03
#undef IIC_GPIO_USE_P02_P03
#endif
#define IIC_GPIO_USE_P01_P00

#ifdef MUTE_PORT_USE_P01
#undef  MUTE_PORT_USE_P01
#endif
#define MUTE_PORT_USE_P26

#define PLAY_STATUS_LED_P05
#define DISABLE_P05_OSC_OUTPUT
//#undef MUTE_CTRL_LEVEL_NORMAL

//#define FM_BY_PASS

//#define ADKEY_PLAY_SHORT_SCAN_FRE

#define EXCHANGE_LINE_IN_CHANNEL	//交换LINE IN 通道

#define TURN_ON_PLAY_BREAK_POINT_MEM

#define USE_GPIO_DETECT_EARPHONE_PLUGGED
#define EARPHONE_DETECT_USE_VPP

#define USE_LINE_IN_DETECT_FUNC
#define AUX_DETECT_USE_P01
#define AUX_DETECT_SHARE_WITH_IIC_SCL

#define POWE_KEY_PLAY_KEY_IN_ONE_KEY
#define USE_POWER_KEY_SHORT_SCAN

#define LINE_IN_PLAY_KEY_PAUSE
#define USE_POWER_KEY_FOR_AUX_PLAY

#define USE_MODE_LONG_FOR_FM_PLAY
#define ADKEY_PLAY_SHORT_ADJ_CH
#if 1
#define USE_POWER_KEY
#define USE_ONLY_POWER_HOLD_CTRL
#define PWR_CTRL_P02
#define USE_PWR_KEY_LONG_PWR_ON
#endif

#define CUSTOMER_DEFINED_ADKEY_RESISTOR

#define MUTE_GPIO_FM_GPIO_COMPATIBALE
#define USE_FM_GPIO
#define BK_SHARE_MCU_CRY
#endif

#ifdef K0000_JGY_SXXX_V001

#define AC209_28PIN		//28 PIN IC GPIO CONFIG

#ifdef IIC_GPIO_USE_P02_P03
#undef IIC_GPIO_USE_P02_P03
#endif
#define IIC_GPIO_USE_P00_P01

#ifdef MUTE_PORT_USE_P01
#undef  MUTE_PORT_USE_P01
#endif
#define MUTE_PORT_USE_P26

#define PLAY_STATUS_LED_P27

#define FM_BY_PASS
#define DEFAULT_GO_TO_AUX
#define EXCHANGE_FM_AUX_PRIO
#define _KEY_TONE_ENABEL_
#define ADKEY_PLAY_SHORT_SCAN_FRE

#define EXCHANGE_LINE_IN_CHANNEL	//交换LINE IN 通道

#define LINE_IN_PLAY_KEY_PAUSE

#define IR_USER_CODE_0xFD02
#define IR_REMOTE_TYPE_JGY
#endif


#ifdef K1188_ZX_1188_V001

#define AC209_28PIN		//28 PIN IC GPIO CONFIG

#ifdef IIC_GPIO_USE_P02_P03
#undef IIC_GPIO_USE_P02_P03
#endif
#define IIC_GPIO_USE_P00_P01

#ifdef MUTE_PORT_USE_P01
#undef  MUTE_PORT_USE_P01
#endif
#define MUTE_PORT_USE_P26

#define PLAY_STATUS_LED_P27

#define MUTE_EXAMP_AT_NEXT_PREV

#define VOLUME_DEFUALT  26
#define DEFAULT_GO_TO_IDLE
#define IDLE_MODE_NO_MUTE
//#define ADKEY_PLAY_SHORT_SCAN_FRE
#define NOT_USE_LINE_IN_FUNC
#define USE_MANUAL_IDLE_FUNC
#define INDEPENDENT_VOLUME_KEY
//#define EXCHANGE_LINE_IN_CHANNEL	//交换LINE IN 通道

#define TURN_ON_PLAY_BREAK_POINT_MEM
#define FM_USE_AR1015
#endif



#ifdef K1192_FW_60_V001

#define AC209_28PIN		//28 PIN IC GPIO CONFIG

#ifdef IIC_GPIO_USE_P02_P03
#undef IIC_GPIO_USE_P02_P03
#endif
#define IIC_GPIO_USE_P00_P01

#ifdef MUTE_PORT_USE_P01
#undef  MUTE_PORT_USE_P01
#endif
#define MUTE_PORT_USE_P26

#define PLAY_STATUS_LED_P27

#define FM_BY_PASS

#define VOLUME_DEFUALT  26
#define SYS_DEFAULT_IN_AUX_MODE_WITH_DETECTION

#define EXCHANGE_LINE_IN_CHANNEL	//交换LINE IN 通道
#define GPIO_SWITCH_SELECT_MODE
#define DEFAULT_GO_TO_IDLE

#define DEVICE_PLUG_N_PLAY_DISBALE_AUX_MODE

#define USE_BAT_MANAGEMENT
#define DC_CHARGE_GPIO_DRV_LED_IND
#define DC_CHARGE_GPIO_DRV_LED_P05
#define CHARGER_DETECT_INDICATOR
#define CHARGER_DET_USE_P02
#define USE_IR_VPP_PORT_FOR_DETECTION
#define LINE_IN_PLAY_KEY_PAUSE
#define DEFAULT_HOLD_IN_DECODE_MODE
#define REVERSE_DC_CHARGER_LED_IND
//#define DISPLAY_TEST
#endif


#ifdef K1196_YHD_852_V001

#define AC209_28PIN		//28 PIN IC GPIO CONFIG

#ifdef IIC_GPIO_USE_P02_P03
#undef IIC_GPIO_USE_P02_P03
#endif
#define IIC_GPIO_USE_P00_P01

#ifdef MUTE_PORT_USE_P01
#undef  MUTE_PORT_USE_P01
#endif
#define MUTE_PORT_USE_P26

#define PLAY_STATUS_LED_P27

#define FM_BY_PASS

#define VOLUME_DEFUALT  20
#define ADKEY_PLAY_SHORT_SCAN_FRE
#define USE_LONG_PLAY_KEY_TO_SWITCH_MODE

#define EXCHANGE_LINE_IN_CHANNEL	//交换LINE IN 通道
#define LINE_IN_PLAY_KEY_PAUSE
#define IR_NEXT_PREV_SHORT_ADJ_CH
#define TURN_ON_PLAY_BREAK_POINT_MEM
#define IR_REMOTER_WITH_POWER_MUTE_PRINT
#endif


#ifdef K2110_YHD_856_V001

#define AC209_28PIN		//28 PIN IC GPIO CONFIG

#ifdef IIC_GPIO_USE_P02_P03
#undef IIC_GPIO_USE_P02_P03
#endif
#define IIC_GPIO_USE_P00_P01

#define MUTE_PORT_USE_P26

#define PLAY_STATUS_LED_P27

#ifdef LED_GPIO_DRV
#undef LED_GPIO_DRV
#endif
#define LED_1651_DRV

#define USE_LINE_IN_DETECT_FUNC
#define AUX_DETECT_USE_VPP
#define LINE_IN_PLAY_KEY_PAUSE
#define FM_PLAY_KEY_PAUSE
#endif


#ifdef K2114_XFW_FW70_V001

#define AC209_28PIN		//28 PIN IC GPIO CONFIG

#ifdef IIC_GPIO_USE_P02_P03
#undef IIC_GPIO_USE_P02_P03
#endif
#define IIC_GPIO_USE_P00_P01


#ifdef MUTE_PORT_USE_P01
#undef  MUTE_PORT_USE_P01
#endif

#define MUTE_PORT_USE_P26

#define PLAY_STATUS_LED_P05
#define DISABLE_P05_OSC_OUTPUT

#define EXCHANGE_LINE_IN_CHANNEL	//交换LINE IN 通道
#define MUTE_GPIO_FM_GPIO_COMPATIBALE
#define USE_FM_GPIO

#define USE_GPIO_DETECT_EARPHONE_PLUGGED
#define EARPHONE_DETECT_USE_VPP

#define CUSTOMER_DEFINED_ADKEY_RESISTOR
#define ADKEY_PLAY_SHORT_SCAN_FRE

#define POWE_KEY_PLAY_KEY_IN_ONE_KEY
#define USE_POWER_KEY_SHORT_SCAN
#define BK_SHARE_MCU_CRY

#if 1
#define USE_POWER_KEY
#define USE_ONLY_POWER_HOLD_CTRL
#define PWR_CTRL_P02
#define USE_PWR_KEY_LONG_PWR_ON
#endif

#if 1
//#undef USE_RDAs_FM
#undef USE_QN8035_FM
#define OTP_MUSIC_FUNC_ENABLE
#define OTP_DECODE_PLAY_CUSTOMED_VOL
#define Lamborghini_voice
#endif

#endif

#ifdef K1222_WXD_1222_V001

#define AC209_28PIN		//28 PIN IC GPIO CONFIG

#ifdef IIC_GPIO_USE_P02_P03
#undef IIC_GPIO_USE_P02_P03
#endif
#define IIC_GPIO_USE_P00_P01


#ifdef MUTE_PORT_USE_P01
#undef  MUTE_PORT_USE_P01
#endif

#define PLAY_STATUS_LED_P00

#define MUTE_PORT_USE_P02

#define EXCHANGE_LINE_IN_CHANNEL	//交换LINE IN 通道

#define USE_GPIO_DETECT_EARPHONE_PLUGGED
#define EARPHONE_DETECT_USE_VPP


#define LINE_IN_PLAY_KEY_PAUSE
#define FM_PLAY_KEY_PAUSE

#endif


#ifdef K401_KM_401_V001

#define AC209_28PIN		//28 PIN IC GPIO CONFIG

#ifdef IIC_GPIO_USE_P02_P03
#undef IIC_GPIO_USE_P02_P03
#endif
#define IIC_GPIO_USE_P02_P01


#ifdef MUTE_PORT_USE_P01
#undef  MUTE_PORT_USE_P01
#endif
#define MUTE_PORT_USE_P26

#define ADKEY_PLAY_SHORT_SCAN_FRE

#define PLAY_STATUS_LED_P27


#define EXCHANGE_LINE_IN_CHANNEL	//交换LINE IN 通道
//#define NOT_USE_LINE_IN_FUNC
#define FM_BY_PASS

#define CUSTOMER_DEFINED_ADKEY_RESISTOR
#define NEW_RES_VALUE_CACULATING
#define DEFAULT_INTERNAL_PULL_RES_VALUE
#define ADKEY_INTERNAL_RES_PULLUP
#define INDEPENDENT_VOLUME_KEY
#define USE_LONG_PLAY_KEY_TO_SWITCH_MODE
#endif


#ifdef K2129_WXD_1234_V001

#define AC209_28PIN		//28 PIN IC GPIO CONFIG

#ifdef IIC_GPIO_USE_P02_P03
#undef IIC_GPIO_USE_P02_P03
#endif
#define IIC_GPIO_USE_P00_P01


#ifdef MUTE_PORT_USE_P01
#undef  MUTE_PORT_USE_P01
#endif
#define ADKEY_PLAY_SHORT_SCAN_FRE

#define PLAY_STATUS_LED_P02

#define MUTE_PORT_USE_P26

#define MUTE_GPIO_FM_GPIO_COMPATIBALE
#define USE_FM_GPIO
#define NEW_SD_DETECT_MOD
#define DEFAULT_GO_TO_AUX

#define EXCHANGE_LINE_IN_CHANNEL	//交换LINE IN 通道


#define USE_GPIO_DETECT_EARPHONE_PLUGGED
#define EARPHONE_DETECT_USE_VPP

//#define LINE_IN_PLAY_KEY_PAUSE
#define USE_LONG_PLAY_KEY_TO_SWITCH_MODE
#endif



#ifdef K1251_YHD_Y902_V001

#define AC209_28PIN		//28 PIN IC GPIO CONFIG

#ifdef IIC_GPIO_USE_P02_P03
#undef IIC_GPIO_USE_P02_P03
#endif
#define IIC_GPIO_USE_P00_P01

#define MUTE_PORT_USE_P26
#define LED_USE_PLAY_MODE_WITH_BAT_ICON
#define PLAY_STATUS_LED_P27
#define NO_PLAY_STATUS_LED

#ifdef LED_GPIO_DRV
#undef LED_GPIO_DRV
#endif
#define LED_1651_DRV



#define MUTE_GPIO_FM_GPIO_COMPATIBALE
#define USE_FM_GPIO
#define NEW_SD_DETECT_MOD

#define POWE_KEY_PLAY_KEY_IN_ONE_KEY

#define USE_POWER_KEY_FOR_FM_PLAY
#define LINE_IN_PLAY_KEY_PAUSE
#define USE_POWER_KEY_FOR_AUX_PLAY
#define FM_PLAY_KEY_PAUSE
#define USE_MODE_KEY_LONG_SCAN

#define DISP_HIFI_STR_AT_POWER_ON
#define DISP_VOL_V_CHAR
#define DISP_PAUS_STRING
#define DEFAULT_GO_TO_IDLE
#define NO_DEV_SHOW_HI_STR

#define USE_GPIO_DETECT_EARPHONE_PLUGGED
#define EARPHONE_DETECT_USE_VPP

#define EXCHANGE_LINE_IN_CHANNEL	//交换LINE IN 通道
#define TURN_ON_PLAY_BREAK_POINT_MEM
#if 1
#define USE_LINE_IN_DETECT_FUNC
#define AUX_DETECT_USE_P01
#define AUX_DETECT_SHARE_WITH_IIC_SCL
#endif

#define CUSTOMER_DEFINED_ADKEY_RESISTOR
//#define ADKEY_PLAY_SHORT_SCAN_FRE

#define BK_SHARE_MCU_CRY

#if 1
#define USE_POWER_KEY
#define USE_ONLY_POWER_HOLD_CTRL
#define PWR_CTRL_P02
#define USE_PWR_KEY_LONG_PWR_ON
#endif


#define DISABLE_P05_OSC_OUTPUT

#if 1
#define USE_BAT_MANAGEMENT
#define BAT_LEVEL_LED_ICON_IND
#define CHARGER_DETECT_INDICATOR
#define CHARGER_DET_USE_P05
#define CHARGER_FLASH_TYPE_1
#endif

#endif

	
#ifdef K1254_BHT_1080_V001

#define AC209_28PIN
#define LED_1651_DRV
#ifdef LED_GPIO_DRV
#undef LED_GPIO_DRV
#endif

#ifdef IIC_GPIO_USE_P02_P03
#undef IIC_GPIO_USE_P02_P03
#endif
#define IIC_GPIO_USE_P00_P01

#ifdef MUTE_PORT_USE_P01
#undef  MUTE_PORT_USE_P01
#endif
#define MUTE_PORT_USE_P02
#define PLAY_STATUS_LED_P00
#define PLAY_STATUS_LED_SHARE_WITH_IIC_SCL

#define FAST_BAND_SCAN_SPEED
#define EXCHANGE_FM_MP3_ICON

#define EXCHANGE_LINE_IN_CHANNEL	//交换LINE IN 通道
#define VOLUME_DEFUALT 		25

#define LINE_IN_PLAY_KEY_PAUSE
#define DISP_PAUS_STRING
#define DISP_VOL_V_CHAR
#define DECODE_STOP_MODE_ENABLE

#define INDEPENDENT_VOLUME_KEY
#define IR_NEXT_PREV_SHORT_ADJ_CH

#define TURN_ON_PLAY_BREAK_POINT_MEM
#define JINRUI_IR_REMOTE_TYPE
//#define USE_GPIO_DETECT_EARPHONE_PLUGGED
//#define EARPHONE_DETECT_USE_VPP
#endif

#ifdef K2158_YJH_2158_V001

#define AC209_28PIN
#define LED_1651_DRV
#ifdef LED_GPIO_DRV
#undef LED_GPIO_DRV
#endif

#ifdef IIC_GPIO_USE_P02_P03
#undef IIC_GPIO_USE_P02_P03
#endif
#define IIC_GPIO_USE_P00_P01

#ifdef MUTE_PORT_USE_P01
#undef  MUTE_PORT_USE_P01
#endif
#define MUTE_PORT_USE_P26
#define PLAY_STATUS_LED_P27

#define EXCHANGE_FM_MP3_ICON

#define EXCHANGE_LINE_IN_CHANNEL	//交换LINE IN 通道
#define VOLUME_DEFUALT 		25

#define LINE_IN_PLAY_KEY_PAUSE
#define DISP_PAUS_STRING
#define DISP_VOL_V_CHAR

//#define INDEPENDENT_VOLUME_KEY
#define IR_NEXT_PREV_SHORT_ADJ_CH

#define TURN_ON_PLAY_BREAK_POINT_MEM
//#define JINRUI_IR_REMOTE_TYPE
//#define USE_GPIO_DETECT_EARPHONE_PLUGGED
//#define EARPHONE_DETECT_USE_VPP
#endif


#ifdef K1BBB_YHD_Y909_V001

#define AC209_28PIN		//28 PIN IC GPIO CONFIG

#ifdef IIC_GPIO_USE_P02_P03
#undef IIC_GPIO_USE_P02_P03
#endif
#define IIC_GPIO_USE_P00_P01


#ifdef MUTE_PORT_USE_P01
#undef  MUTE_PORT_USE_P01
#endif
#define ADKEY_PLAY_SHORT_SCAN_FRE

#define PLAY_STATUS_LED_P02

#define MUTE_PORT_USE_P26

#define NEW_SD_DETECT_MOD

//#define EXCHANGE_LINE_IN_CHANNEL	//交换LINE IN 通道


#define USE_GPIO_DETECT_EARPHONE_PLUGGED
#define EARPHONE_DETECT_USE_VPP
#define IDLE_MODE_NO_MUTE
#define USE_MANUAL_IDLE_FUNC
//#define LINE_IN_PLAY_KEY_PAUSE
#define NOT_USE_LINE_IN_FUNC
#define USE_AMP_MODE_SELECT
#define AMP_MODE_SELECT_PORT_USE_P27
#define BK_SHARE_MCU_CRY
#define QN_SHARE_MCU_CRYSTAL
#define FM_USE_AR1015
#endif











#endif

