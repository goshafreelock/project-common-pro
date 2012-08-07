/*--------------------------------------------------------------------------
File : dsa.c
Contents : DSA protocol function
--------------------------------------------------------------------------*/
#include "Custom_config.h"
#include "main.h"
#include "key.h"

#ifdef AC_SLAVE_ENABLE

#define DSA_PORT_INIT()		P0DIR &=~(BIT(1)|BIT(5)|BIT(7));P0PU |=(BIT(1)|BIT(5)|BIT(7))
//// GPIOE2 Pin73
#define SET_DATA_READ 		P0DIR &=~(BIT(7));P0PU |=(BIT(7));P07 = 1;P0DIR |=(BIT(7));P0PD&=~(BIT(7))
#define SET_DATA_WRITE 	P0DIR &=~(BIT(7));P0PU |=(BIT(7))
#define SET_DATA_HIGH 		P07 = 1
#define SET_DATA_LOW 		P07 = 0
#define GET_DATA 			P07

//// GPIOE2 Pin74
#define SET_STB_READ 		P0DIR &=~(BIT(1));P0PU |=(BIT(1));P01 = 1;P0DIR |=(BIT(1));P0PD&=~(BIT(1));
#define SET_STB_WRITE 		P0DIR &=~(BIT(1));P0PU |=(BIT(1))
#define SET_STB_HIGH 		P01 = 1
#define SET_STB_LOW		P01 = 0
#define GET_STB 				P01

/// GPIOE0 Pin72
#define SET_ACK_READ 		P0DIR &=~(BIT(5));P0PU |=(BIT(5));P05 = 1;P0DIR |=(BIT(5));P0PD&=~(BIT(5))
#define SET_ACK_WRITE 		P0DIR &=~(BIT(5));P0PU |=(BIT(5))
#define SET_ACK_HIGH 		P05 = 1
#define SET_ACK_LOW 		P05 = 0
#define GET_ACK 				P05


#define DSA_Ideal 0
#define DSA_Sync 1
#define DSA_Comm 2
#define DSA_Ack 3
#define DSA_Ack2 4

#define DSA_Ideal_Send 10
#define DSA_Sync_Send 11
#define DSA_Comm_Send 12
#define DSA_Ack_Send 13
#define DSA_Ack2_Send 14

#define WAITE_ACK_DELAY_TIME 		1200

xd_u8 DSAState,UI2DSA_STATE;
xd_u8 DSA_Count,DSA_Count;
xd_u16 DSA_Timer,DSA_Delay;
xd_u16 DSA_Rdata,DSA_Sdata,DSA_Sdata_backup,DSA_flag;
bool DSA_GETHERING_DATA_ENABLE_BIT=1;
xd_u8 sec;
xd_u8 min;
xd_u32 file_play_time;
xd_u8 gether_info_timer=0;
xd_u16  DSA_DATA[8];


extern _xdata SYS_WORK_MODE work_mode;
extern u8 play_status,play_mode;
extern u16 given_file_number;
extern FSAPIMSG _pdata fs_msg;

u8 _code DSA_Key[][3]={
	
  {0x55,0x00,(0)},
  {0x55,0x01,(1)},
  {0x55,0x02,(2)},
  {0x55,0x03,(3)},
  {0x55,0x04,(4)},
  {0x55,0x05,(5)},
  {0x55,0x06,(6)},
  {0x55,0x07,(7)},
  {0x55,0x08,(8)},
  {0x55,0x09,(9)},
  {0x55,0x0a,(INFO_PLAY|KEY_SHORT_UP)},
  {0x55,0x0b,(INFO_STOP|KEY_SHORT_UP)},
  {0x55,0x0c,(INFO_NEXT_FIL|KEY_SHORT_UP)},
  {0x55,0x0d,(INFO_PREV_FIL|KEY_SHORT_UP)},
  {0x55,0x0e,(INFO_PLAY_MODE|KEY_SHORT_UP)},
  {0x55,0x0F,(MSG_USB_DISK_IN)},
  {0x55,0x10,(INFO_POWER|KEY_SHORT_UP)},
  {0x55,0x11,(0xFF)},
  {0x55,0x12,(INFO_NEXT_FIL | KEY_LONG)},
  {0x55,0x13,(INFO_PREV_FIL | KEY_LONG)},
  {0x55,0x14,(INFO_MUTE |KEY_SHORT_UP)},
  {0x55,0x15,(INFO_MUTE |KEY_SHORT_UP)},
  {0x55,0x16,(INFO_VOL_PLUS)},
  {0x55,0x17,(INFO_VOL_MINUS)},
  {0x55,0x18,(MSG_SDMMC_IN)},
 };
#define DSA_KEYNUM (sizeof(DSA_Key)/3)

#define FLAG0 			0x90  
#define F_READ_TOC	 	0x80
#define F_READ_DEVICE	0x80
#define F_TOC_OK  	 	0x40
#define F_MP3     		 	0x20
#define F_WMA     	 	0x10
#define F_CD     		 	0x08
#define F_PLAY   		 	0x04
#define F_STOP  		 	0x02
#define F_PAUSE   		0x01

#define FLAG1 			0x91
#define F_FORWARD		0x80
#define F_BACKWARD		0x40
#define F_PROG 			0x20
#define F_REP_ONE 		0x10
#define F_REP_DIR 		0x08
#define F_REP_ALL 		0x04
#define F_RANDOM 		0x02
#define F_INTRO 			0x01

#define FLAG2 			0x92
#define F_TRACK_END	 	0x80
#define F_DISC_END 		0x40
#define F_HOSTSD_END	0x40
#define F_MUTE_ON 		0x20
#define F_MUTE_OFF 		0x10
#define F_NO_DISC  		0x08
#define F_NO_DEVICE 	0x08
#define F_ERR_DISC		0x04
#define F_NO_FILE 		0x04
#define F_STOP_DISC		0x02
#define F_ID3_EXIST 		0x01

#define FLAG3			0x93
#define CD_SOURCE		0x80
#define USB_SOURCE		0x40
#define SD_SOURCE		0x20

#define DSA_DEBUG
void DSA_init(void)
{
 	u8 i;
	
	for(i=0;i<8;i++)
		DSA_DATA[i]=0x00;
 	SET_DATA_READ;
 	SET_STB_READ;
 	SET_ACK_READ;
 	DSAState=DSA_Ideal;
	UI2DSA_STATE=0;
	DSA_Sdata = 0;
}

void   DSA_Detect(void)
{
	xd_u8 key_temp=0;
DSA_Loop:       
	switch (DSAState)
	{
	     case DSA_Ideal:
		   //sys_printf(" DSA_Ideal ");
	          DSA_Timer=0;
                 SET_DATA_READ;
		   SET_STB_READ;
 	          SET_ACK_READ;
		   for (DSA_Delay=0;DSA_Delay<5;DSA_Delay++);
		   
		   DSA_Delay=0;
		   while((GET_DATA)&&(DSA_Delay<20))
		   	DSA_Delay++;

	          if (!GET_DATA) 
	          { 
	          	    DSAState++;
	                  goto DSA_Loop;
	          }
	          break;
	     case DSA_Sync:
#ifdef DSA_DEBUG			  
		   sys_printf(" DSA_Sync ");
#endif		 	
	          if (DSA_Timer>3) 
	          {
	          	DSAState=DSA_Ideal;
	              break;
	          }
	          SET_ACK_WRITE;
	          SET_ACK_LOW;


		   DSA_Delay=0;
		   while((!GET_DATA)&&(DSA_Delay<10))
		   	DSA_Delay++;
	          if (GET_DATA) 
	          {
	           	DSAState++;
	           	SET_ACK_HIGH;
	           	goto DSA_Loop;
	          }
		   else 
		   {
		   	DSA_Timer++;
		   }	  
	          break;
	     case DSA_Comm:	 
#ifdef DSA_DEBUG			  
		   sys_printf(" DSA_Comm ");
#endif
                 SET_DATA_READ;
	          SET_ACK_WRITE;		   
		   SET_STB_READ;
		   //for (DSA_Delay=0;DSA_Delay<5;DSA_Delay++);
		   
	          DSA_Rdata=0;
	          for (DSA_Count=0;DSA_Count<16;DSA_Count++)
	           {
	           	DSA_Timer=0;
	           	while ((GET_STB)&&(DSA_Timer<200)){
	           	             DSA_Timer++;
	           	}
	           	if (DSA_Timer>=200)             
	              {
	              	DSAState=DSA_Ideal;
	                        goto DSA_Loop;
	               }
	
	           	DSA_Rdata<<=1;	  
	           	if (GET_DATA)
	           	    DSA_Rdata |=0x01;         	
	                SET_ACK_LOW;
			for (DSA_Delay=0;DSA_Delay<8;DSA_Delay++)
				;
			DSA_Timer=0;
	           	while ((!GET_STB)&&(DSA_Timer<300))
	           	             DSA_Timer++;
	           	if (DSA_Timer>=300)             
			{
		  		EA =1;
				DSAState=DSA_Ideal;
	                     goto DSA_Loop;
			}
	               SET_ACK_HIGH;           
	           }
#ifdef DSA_DEBUG			  
		    printf(" dsa -DSA_Rdata--->%x \r\n",DSA_Rdata);
#endif
		   if(((DSA_Rdata&0xFF00)==0x5500))
		   {
			 for (DSA_Delay=0;DSA_Delay<DSA_KEYNUM;DSA_Delay++)
			 {
				if ((u8)(DSA_Rdata&0x00ff)==DSA_Key[DSA_Delay][1]){
					key_temp=DSA_Key[DSA_Delay][2];
#ifdef DSA_DEBUG
					  printf(" dsa -DSA_Rdata  key--->%x \r\n",(u16)key_temp);
#endif
					  put_msg_lifo(key_temp);			  
		   		}
			 }
		   }

	          DSAState++; 
	          DSA_Timer=0;
	          goto DSA_Loop;
	          break;
	     case DSA_Ack:	      
#ifdef DSA_DEBUG
		   sys_printf(" DSA_Ack ");
#endif			
	          if (DSA_Timer>3) 
		   {
		   	DSAState=DSA_Ideal;
	              break;
		   }
	          SET_ACK_READ;
		  DSA_Delay=0;
		   while ((DSA_Delay<200)&&(GET_ACK))
		   	DSA_Delay++; 
	          if (GET_ACK)
	          {
	          	DSA_Timer++;
			  break;
	          }
	          SET_DATA_WRITE;
	          SET_DATA_HIGH;
	          for (DSA_Delay=0;DSA_Delay<5;DSA_Delay++)
			  ;
	          SET_STB_WRITE;
	          SET_STB_LOW;
	          DSA_Timer=0;
	          DSAState++; 
	          goto DSA_Loop;
	          break;
	    case DSA_Ack2:      
#ifdef DSA_DEBUG
		   sys_printf(" DSA_Ack2 ");
#endif			
	    	  if (DSA_Timer>3) 
	         {
	         	DSAState=DSA_Ideal;
	              break;
		  }
              	DSA_Delay=0;       
	         	while ((DSA_Delay<200)&&(!GET_ACK))
		   	DSA_Delay++; 	          
	          if (!GET_ACK)
	          {
	          	DSA_Timer++;
			  break;
	          }
	          SET_DATA_READ;
 	          SET_STB_READ;
 	          SET_ACK_READ;
	          DSAState=DSA_Ideal;
	          break;	          	          	     
        default:
	          DSAState=DSA_Ideal;
	          break;	          	          	     
        }
}

void   DSA_Send(void)
{

DSA_Loop2:       
	switch (DSAState)
	{		
	     case DSA_Ideal_Send:
#ifdef DSA_DEBUG
		   sys_printf(" DSA_Ideal_Send ");
#endif
	          SET_ACK_READ;	          
	          DSA_Timer=0;
		   for (DSA_Delay=0;DSA_Delay<10;DSA_Delay++);
	          if (GET_ACK)
	          {
	          	SET_DATA_READ;		
  		     	for (DSA_Delay=0;DSA_Delay<20;DSA_Delay++);
	          	if (!GET_DATA)
			{
				DSAState=DSA_Ideal;
		           	break;
	           	}
	          }
	        SET_DATA_WRITE;
 	        SET_STB_WRITE;		
		 for (DSA_Delay=0;DSA_Delay<15;DSA_Delay++)
			;
		SET_STB_HIGH;		
		SET_DATA_LOW;
		
           		DSA_Delay=0;			
			while ((DSA_Delay<WAITE_ACK_DELAY_TIME)&&(GET_ACK))
			       DSA_Delay++;

		        if (!GET_ACK) 
		        { 
		        
		        	DSAState++;
				goto DSA_Loop2;
		        }		 
			else
			{
				DSAState=0;
			}
	          break;
	     case DSA_Sync_Send:
#ifdef DSA_DEBUG
		  sys_printf(" DSA_Sync_Send ");
#endif		 	
	         if (DSA_Timer>3) 
	         {
	         	DSAState=DSA_Ideal_Send;
                  	break;
		   }
	          SET_DATA_HIGH;
           	  	DSA_Delay=0;
		   while ((DSA_Delay<5000)&&(!GET_ACK))
		   	DSA_Delay++; 
	          if (GET_ACK) 
	          {
	           	DSAState++;
	           	goto DSA_Loop2;
	          }
		   else
		   {
		   	DSA_Timer++;
		   }	  
	          break;
	     case DSA_Comm_Send:
#ifdef DSA_DEBUG
		 sys_printf(" DSA_Comm_Send ");
#endif
	        SET_DATA_WRITE;
 	        SET_STB_WRITE;		
          	 SET_ACK_READ;	        

#ifdef DSA_DEBUG
			printf(" dsa -DSA_Comm_Send--->%x \r\n",DSA_Sdata);
#endif			 
	          DSA_Sdata_backup=DSA_Sdata;
	          for (DSA_Count=0;DSA_Count<16;DSA_Count++)
	           {

	           	DSA_Timer=0;
	           	if (DSA_Sdata&0x8000)
	           	   SET_DATA_HIGH;
	           	   else  
	           	   SET_DATA_LOW;
	           	DSA_Sdata<<=1;		           	
	           	SET_STB_LOW;	           	
	           	while ((GET_ACK)&&(DSA_Timer<300))
	           	{
	           	             DSA_Timer++;
	           	}
	           	if (DSA_Timer>=300) 
			{
				DSAState=DSA_Ideal;
	            	          DSA_Sdata=DSA_Sdata_backup;
	                          goto DSA_Loop2;
			}
	                SET_STB_HIGH;
	           	while ((!GET_ACK)&&(DSA_Timer<300))
	           	             DSA_Timer++;
	           	if (DSA_Timer>=300)
			{
				DSAState=DSA_Ideal;
	            	          DSA_Sdata=DSA_Sdata_backup;
	                          goto DSA_Loop2;
			}
	           }
		   DSA_Sdata =0;
	          DSAState++; 
	          DSA_Timer=0;
	          goto DSA_Loop2;
	          break;
	     case DSA_Ack_Send:
#ifdef DSA_DEBUG
		   sys_printf(" DSA_Ack_Send ");
#endif		 	
	          if (DSA_Timer>3) 
	          {
	          	DSAState=DSA_Ideal;
         	          DSA_Sdata=DSA_Sdata_backup;
	              break;
	          }
	          SET_STB_READ;
	          SET_DATA_READ;		   
	          SET_ACK_WRITE;
		   for (DSA_Delay=0;DSA_Delay<10;DSA_Delay++);
	          SET_ACK_LOW;	
              DSA_Delay=0;  
		   while ((DSA_Delay<WAITE_ACK_DELAY_TIME)&&(GET_STB))
			  DSA_Delay++; 
   	          if (GET_STB) break;	                	          
                  if (!GET_DATA) 
           	          DSA_Sdata=DSA_Sdata_backup;
	          SET_ACK_HIGH;
	          DSA_Timer=0;
	          DSAState++; 
	          goto DSA_Loop2;
	          break;
	    case DSA_Ack2_Send: 
#ifdef DSA_DEBUG
		   sys_printf(" DSA_Ack2_Send ");
#endif			
	    	  if (DSA_Timer>3) 
	         {
	         	DSAState=DSA_Ideal;
	              break;
	          }
	          for (DSA_Delay=0;DSA_Delay<200;DSA_Delay++);          

	           SET_DATA_READ;
 	           SET_STB_READ;
 	           SET_ACK_READ;
 	           
	          DSAState=DSA_Ideal;
	          break;	         
        default:
               DSAState=DSA_Ideal;
               break; 	          	     
        }	
}	
void UI_2_DSA(void)
{
	if (DSA_Sdata==0)
	{	
		DSA_flag=0;
#ifdef DSA_DEBUG
		printf(" -UI_2_DSA--->%x \r\n",(u16)UI2DSA_STATE);
#endif
		switch(UI2DSA_STATE)	
		{
			case 0xFA:
				DSA_flag|=0xFA<<8;
				
				if(work_mode == SYS_MP3DECODE_USB)
				{
					DSA_flag |= 0x01;
				}
				else if(work_mode == SYS_MP3DECODE_SD){
					DSA_flag |= 0x02;
				}
				else{
					DSA_flag |= 0x04;
				}

				if(play_status == MUSIC_PLAY){
					DSA_flag |=0x08;
				}
				else if(play_status == MUSIC_STOP){
					DSA_flag |=0x20;
				}

				if(play_mode == REPEAT_ONE){
					DSA_flag |=0x40;
				}
				else if(play_mode == REPEAT_FOLDER){
					DSA_flag |=0x80;
				}
				else if(play_mode == REPEAT_ALL){
					DSA_flag |=0xC0;
				}

				if(DSA_DATA[0] != DSA_flag)
				DSA_Sdata =	DSA_flag;       
				DSA_DATA[0] = DSA_flag;
				UI2DSA_STATE=0x10;
				break;
				
			case 0xFB:
				DSA_flag|=0xFB<<8;
			
				DSA_flag |=0x01;

				if(DSA_DATA[1] != DSA_flag)
				DSA_Sdata=DSA_flag;
				DSA_DATA[1] = DSA_flag;
				UI2DSA_STATE=0x30;
				break;
			
			case 0xF9:
				DSA_flag|=0xF9<<8;				

    				file_play_time = get_music_play_time();
					
    				min = (u8)((file_play_time/60) % 60);
					
				DSA_flag |= min;
				
				if(DSA_DATA[2] != DSA_flag)
				DSA_Sdata=DSA_flag;  
				DSA_DATA[2] = DSA_flag;
				
				UI2DSA_STATE=0xF7;
				break;

			case 0xF7:
				DSA_flag|=0xF7<<8;
				
   				file_play_time = get_music_play_time();
    				sec = (u8)(file_play_time%60);
				DSA_flag |= sec;

				if(DSA_DATA[3]!= DSA_flag)
				DSA_Sdata=	 DSA_flag;    		
				DSA_DATA[3] = DSA_flag;
				UI2DSA_STATE=0xFA;
				break;
				
			case 0x10:
				DSA_flag|=0x10<<8;
				
				DSA_flag |= (given_file_number&0x0FFF);

				if(DSA_DATA[4]!= DSA_flag)
				DSA_Sdata=	 DSA_flag;    		
				DSA_DATA[4] = DSA_flag;
				UI2DSA_STATE=0x20;
				break;

			case 0x20:
				DSA_flag|=0x20<<8;
				
				DSA_flag |= 0x01;

				if(DSA_DATA[5]!= DSA_flag)
				DSA_Sdata=	 DSA_flag;    		
				DSA_DATA[5] = DSA_flag;
				UI2DSA_STATE=0xF9;
				break;

			case 0x30:
				DSA_flag|=0x30<<8;
				
				DSA_flag |= (fs_msg.fileTotal)&0x0FFF;

				if(DSA_DATA[6]!= DSA_flag)
				DSA_Sdata=	 DSA_flag;    		
				DSA_DATA[6] = DSA_flag;
				UI2DSA_STATE=0x40;
				break;	

			case 0x40:
				DSA_flag|=0x40<<8;

				DSA_flag |= (fs_msg.dirTotal)&0x0FFF;;

				if(DSA_DATA[7]!= DSA_flag)
				DSA_Sdata=	 DSA_flag;    		
				DSA_DATA[7] = DSA_flag;
				UI2DSA_STATE=0xFA;
				break;					
			default:
				UI2DSA_STATE=0xFB;
				break;

			}	
		}	

}
void DSA_if_hdlr(void)
{
	//EA =0;
	DSA_Detect();

	if ((DSA_Sdata)&&(DSAState==0))
	{
		DSAState=10;
		DSA_Send();
	}
	else
	{
		DSA_Send();
	}	

	//EA =1;
	if(gether_info_timer++>10){
		gether_info_timer =0;

		//if(work_mode <SYS_FMREV)
			UI_2_DSA();
	}
}
#endif
