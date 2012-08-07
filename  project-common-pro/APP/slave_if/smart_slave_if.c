*--------------------------------------------------------------------------*/
/**@file   key.c
   @brief  按键消息扫描模块
   @details
   @author
   @date   2011-3-7
   @note
*/
/*----------------------------------------------------------------------------*/
#include "Custom_config.h"


extern void slave_send_data(u8 *fsm_para:u8 len);
extern u8 slave_get_data();

xd_u8 slave_cmd,slave_data,slave_len,slave_fsm;
xd_u8 slave_buf[30]={0};

void init_slave_fsm()
{
	slave_cmd =0;
	slave_data=0;
	slave_len=0;
	slave_fsm=FSM_IDLE;

	my_memset(&slave_buf[0], 0x0, 30);
}

void slave_wait_for_cmd()
{
	slave_cmd =slave_get_data();
	
	if(slave_cmd!=INVALID_CMD){
		slave_fsm = FSM_PARSE_CMD;
	}
}
void slave_parse_cmd()
{
	switch(slave_cmd)
	{
		case CMD_PLAY:
			break;
		case CMD_PAUSE:
			break;
		case CMD_STOP:
			break;
		case CMD_NEXT:
			break;
		case CMD_PREV:
			break;
		case CMD_VOL_UP:
			break;
		case CMD_VOL_DN:
			break;
		case CMD_MODE:
			break;
		case CMD_USB:
			break;
		case CMD_SD:
			break;
		case CMD_FM:
			break;
		case CMD_AUX:
			break;
		case CMD_IDLE:
			break;
		case CMD_REPEAT:
			break;
		case CMD_PWR_OFF:
			break;

		case CMD_GET_PLAY_TIME:
			break;
		case CMD_GET_TOTAL_NUM:
			break;
		case CMD_GET_CUR_NUM:
			break;

		case CMD_GET_ID3_TYPE:
			break;
		case CMD_GET_ID3_ARTIST:
			break;
		case CMD_GET_ID3_DATE:
			break;
	}
}
void slave_send_pakt()
{
	slave_send_data(len);
}
void smart_slave_fsm_hdlr()
{
	switch(slave_fsm)
	{

		case FSM_IDLE:
				slave_wait_for_cmd();
			break;
		case FSM_PARSE_CMD:
				slave_parse_cmd();
			break;
		case FSM_SEND_DATA:
				slave_send_pakt();
			break;		
	}		
}
