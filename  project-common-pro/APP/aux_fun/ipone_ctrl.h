#ifndef _IPONE_CTRL_H_
#define	_IPONE_CTRL_H_

#include "Custom_config.h"

#if defined(IPONE_DOCK_FUNC_ENABLE)

void iPodCommand(u8 button,u8 len);
void close_uart_ctrl();
void open_uart_ctrl();

#define IPOD_RELEASE           			iPodCommand(0X00,3)

#define IPOD_PLAY           				iPodCommand(0X01,3)
#define IPOD_VOLUME_UP           		iPodCommand(0X02,3)
#define IPOD_VOLUME_DOWN           	iPodCommand(0X04,3)
#define IPOD_NEXT_TRACK           		iPodCommand(0X08,3)
#define IPOD_PREVIOUS_TRACK          	iPodCommand(0X10,3)
#define IPOD_NEXT_ALBUM           		iPodCommand(0X20,3)
#define IPOD_PREVIOUS_ALBUM         	iPodCommand(0X40,3)
#define IPOD_STOP           				iPodCommand(0X80,3)

#define IPOD_PLAY_RESUME           		iPodCommand(0X01,4)
#define IPOD_PAUSE           			iPodCommand(0X02,4)
#define IPOD_MUTE_TOGGLE           	iPodCommand(0X04,4)
#define IPOD_NEXT_CHAPTER           	iPodCommand(0X08,4)
#define IPOD_PREVIOUS_CHAPTER      	iPodCommand(0X10,4)
#define IPOD_NEXT_PLAYLIST           	iPodCommand(0X20,4)
#define IPOD_PREVIOUS_PLAYLIST     	iPodCommand(0X40,4)
#define IPOD_SHUFFLE           			iPodCommand(0X80,4)

#define IPOD_REPEAT          			iPodCommand(0X01,5)
#define IPOD_POWER_ON       			iPodCommand(0X02,5)
#define IPOD_POWER_OFF           		iPodCommand(0X04,5)
#define IPOD_BACKLIGHT_30SEC         	iPodCommand(0X08,5)
#define IPOD_BEGIN_FASTFORWARD   	iPodCommand(0X10,5)
#define IPOD_BEGIN_REWIND           	iPodCommand(0X20,5)
#define IPOD_MENU           			iPodCommand(0X40,5)
#define IPOD_SELECT           			iPodCommand(0X80,5)

#define IPOD_UP_ARROW           		iPodCommand(0X01,6)
#define IPOD_DOWN_ARROW       		iPodCommand(0X02,6)

#endif

#endif

