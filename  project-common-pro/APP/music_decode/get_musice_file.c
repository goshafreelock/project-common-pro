/*--------------------------------------------------------------------------*/
/**@file       get_musice_file.c
   @brief      �ļ�����
   @details
   @author
   @date   2011-3-7
   @note
*/
/*----------------------------------------------------------------------------*/

#include "get_music_file.h"


extern u16 given_file_number;
extern u8 given_device;
extern u8 play_mode;
extern FSAPIMSG _pdata fs_msg;
extern u8 device_active;
extern void clean_playpoint(u8 dev);
extern u16 playpoint_filenum;
#ifdef PLAY_MODE_USE_INTRO_MODE
extern void intro_play_stop(void);
#endif
extern void stop_decode(void);
extern void set_play_flash(u8 led_status);

/*----------------------------------------------------------------------------*/
/**@brief   ��ȡһ�������
   @param   ��
   @return  ��ȡ���������
   @note    u8 ReadLFSR()
*/
/*----------------------------------------------------------------------------*/
u8 ReadLFSR()
{
    u8 tmp ;
    CRCFIFO = T0CNT;
    tmp = CRCFIFO ;
    return tmp;
}

/*----------------------------------------------------------------------------*/
/**@brief    ������һ������һ���ļ������Զ���ȡ��һ��
   @param    dir��0:next file, 1:previous file, 2:auto next,���ܻᵼ���豸���л�
   @return   ��
   @note     void get_music_file1(u8 dir)
*/
/*----------------------------------------------------------------------------*/
void get_music_file1(u8 dir)
{
    if (device_check() == 0)                    //�����ǰ���ŵ��豸�����ߣ�������һ���豸, ����ѡ���һ���ļ����в���
    {
        if (find_device(0))
        {
            put_msg_lifo(INFO_NEXTMODE);                //�Ҳ�����Ч�豸����Ҫ���ص�����ģʽ
            return;
        }
    }

    if (!fs_get_filenum(play_mode, dir))                //���Ҵ����ļ�����Ѿ�������ǰ�豸�ķ�Χ(Ҳ�п����ǵ�ǰ�豸�Ѿ�������)
    {
        if (find_device(0))                            //������һ���豸
        {
            put_msg_lifo(INFO_NEXTMODE);                //�Ҳ�����Ч�豸����Ҫ���ص�����ģʽ
            return;
        }

        if (given_file_number == 0)                     //given_file_number = 0;˵���Ǻ������ļ�
            given_file_number = fs_msg.fileTotal;
    }
    put_msg_lifo(INIT_PLAY);
}
/*----------------------------------------------------------------------------*/
/**@brief   ��ȡָ���豸�е�ָ���ļ�������������������Զ�����һ���ɲ��ŵ��ļ�
   @param   ��
   @return  ��
   @note    void get_music_file2(void)
*/
/*----------------------------------------------------------------------------*/
void get_music_file2(void)
{
    if (!find_device(given_device))
    {
#if defined(DISP_DEV_STR_BEFOR_PLAY)
	    Disp_Con(DISP_CUR_DEV);
#endif

        if ((given_file_number == 0) || (given_file_number > fs_msg.fileTotal))
        {
            given_file_number = 1;
        }

        put_msg_lifo(INIT_PLAY);
    }
    else
    {
        get_music_file3();

    }
}
/*----------------------------------------------------------------------------*/
/**@brief   ����һ���豸�в�����Ч�ļ����в���
   @param   ��
   @return  ��
   @note    void get_music_file3(void)
*/
/*----------------------------------------------------------------------------*/
void get_music_file3(void)
{
    if (find_device(0))
    {
        put_msg_lifo(INFO_NEXTMODE);                //�Ҳ�����Ч�豸����Ҫ���ص�����ģʽ
        return;
    }
    if (read_info(MEM_ACTIVE_DEV) == device_active)
    {
#if defined(USB_SD_PLAY_INFO_DIV)
	if(device_active==0x01){
	    ((u8  *)(&given_file_number))[0] = read_info(MEM_FILENUM_SD);
	    ((u8  *)(&given_file_number))[1] = read_info(MEM_FILENUM_SD+1);
	}
	else if(device_active==0x02){
	    ((u8  *)(&given_file_number))[0] = read_info(MEM_FILENUM_USB);
	    ((u8  *)(&given_file_number))[1] = read_info(MEM_FILENUM_USB+1);
	}
#else
        ((u8  *)(&given_file_number))[0] = read_info(MEM_FILENUM);
        ((u8  *)(&given_file_number))[1] = read_info(MEM_FILENUM+1);
#endif		
    }
    else
    {
#if defined(USB_SD_PLAY_INFO_DIV)
	if(device_active==0x01){
	    ((u8  *)(&given_file_number))[0] = read_info(MEM_FILENUM_SD);
	    ((u8  *)(&given_file_number))[1] = read_info(MEM_FILENUM_SD+1);
	}
	else if(device_active==0x02){
	    ((u8  *)(&given_file_number))[0] = read_info(MEM_FILENUM_USB);
	    ((u8  *)(&given_file_number))[1] = read_info(MEM_FILENUM_USB+1);
	}
#else
        given_file_number = 1;
#endif
    }
    put_msg_lifo(INIT_PLAY);
}
#if defined(USE_FOLDER_SELECT_FUNC)
void select_folder_file(u8 cmd)
{

    if (device_check() == 0)                    //�����ǰ���ŵ��豸�����ߣ�������һ���豸, ����ѡ���һ���ļ����в���
    {
        if (find_device(0))
        {
            put_msg_lifo(INFO_NEXTMODE);                //�Ҳ�����Ч�豸����Ҫ���ص�����ģʽ
            return;
        }
    }
    given_file_number= get_dir_file(cmd);                //���Ҵ����ļ�����Ѿ�������ǰ�豸�ķ�Χ(Ҳ�п����ǵ�ǰ�豸�Ѿ�������)
    put_msg_lifo(INIT_PLAY);
}
#endif
/*----------------------------------------------------------------------------*/
/**@brief   ��ȡ�ļ���
   @param   playmode   ѭ������ģʽ
   @param   searchMode  0����һ���ļ���1����һ���ļ���2����ǿ��REPEAT_ONEģʽ�r��REPEAT_ALLģʽ�²����ļ�
   @return  0:fail 1:success
   @note     bool fs_get_filenum(PLAY_MODE playmode, u8 searchMode)
*/
/*----------------------------------------------------------------------------*/

bool fs_get_filenum(PLAY_MODE playmode, u8 searchMode)
{
    u16 fileTotal;

    fileTotal = fs_msg.fileTotal;
    given_file_number = fs_msg.fileNumber;

    if ((playmode == REPEAT_ONE) && (searchMode != 2)){
#if defined(PLAY_MODE_REPEAT_ALL)
        playmode = REPEAT_ALL;					//4�ڵ���ѭ��ģʽ�£�ת����ȫѭ��ģʽ
#else
	playmode = REPEAT_DEV_ALL;
#endif
    }
    switch (playmode)
    {
    case REPEAT_RANDOM:
        CRCREG = T3CNTH;
        CRCREG = T3CNTL;

        ((u8 *)(&given_file_number))[0] = ReadLFSR();
        ((u8 *)(&given_file_number))[1] = ReadLFSR();

        given_file_number = given_file_number % fs_msg.fileTotal + 1;
        break;
    case REPEAT_OFF:
#if defined(PLAY_MODE_REPEAT_ALL)
    case REPEAT_ALL:
        if (searchMode == 1)					//prev file
        {
            given_file_number--;
            if (given_file_number == 0)
            {
#if defined(TURN_ON_PLAY_BREAK_POINT_MEM)            
		   if(0x03 != (0x03&get_device_online_status()))
		   {
		      	clean_playpoint_info(device_active);
			return 0;
		   }
		   if(BIT(SDMMC) == device_active)
		       clean_playpoint_info(BIT(USB_DISK));
                 if(BIT(USB_DISK) == device_active)
			clean_playpoint_info(BIT(SDMMC));
#endif				 
			return 0;
            }
        }
        else					                //next file
        {
            given_file_number++;
            if (given_file_number > fileTotal)
            {
#if defined(TURN_ON_PLAY_BREAK_POINT_MEM)            
			if(0x03 != (0x03&get_device_online_status()))
			{
			    clean_playpoint_info(device_active);
				return 0;
			}
                	else
			{
			    	clean_playpoint_info(BIT(SDMMC));
				clean_playpoint_info(BIT(USB_DISK));
			}
#endif				
#ifdef PLAY_MODE_USE_INTRO_MODE
		intro_play_stop();
#endif
                given_file_number = 1;
                return 0;
            }
        }
        break;
#else		
    case REPEAT_DEV_ALL:
        if (searchMode == 1)					//prev file
        {
            given_file_number--;
            if (given_file_number == 0)
            {
            	  given_file_number =fileTotal;
            }
        }
        else					                //next file
        {
            given_file_number++;
            if (given_file_number > fileTotal)
            {
#ifdef PLAY_MODE_USE_INTRO_MODE
		intro_play_stop();
#endif            
                given_file_number = 1;

		  if(playmode == REPEAT_OFF){
		  	
	       	set_play_flash(LED_FLASH_ON);
			stop_decode();
	    		Disp_Con(DISP_FILENUM);
		  }
#ifdef PLAY_MODE_USE_REP_ALL_PLAY_IN_SEQUENCE
       	set_play_flash(LED_FLASH_ON);
		stop_decode();
    		Disp_Con(DISP_FILENUM);
#endif            
            }
        }
        break;		
#endif
    case REPEAT_FOLDER:
        if (searchMode == 1)
        {
            given_file_number--;
            if (given_file_number == fs_msg.fileTotalOutDir)
                given_file_number = fs_msg.fileTotalOutDir + fs_msg.fileTotalInDir;
        }
        else					//next file
        {
            given_file_number++;
            if (given_file_number > (fs_msg.fileTotalOutDir + fs_msg.fileTotalInDir))
                given_file_number = fs_msg.fileTotalOutDir + 1;
        }
        break;
    }

    return 1;
}



