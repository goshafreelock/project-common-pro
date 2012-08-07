/*--------------------------------------------------------------------------*/
/**@file     entry.h
   @brief    maskrom/BSP接口库函数说明
   @details
   @author
   @date   2010-12-13
   @note
*/
/*----------------------------------------------------------------------------*/

#ifndef __ENTRY_H__
#define __ENTRY_H__

#ifdef __C51__
#include "typedef.h"

/*----------------------------------------------------------------------------*/
/**@brief   延时，最小单位为调用 dec_delay_counter()函数所在的timer
   @param   delay：延时参数
   @return  无
   @note    void delay_10ms(u8 delay)
*/
/*----------------------------------------------------------------------------*/
void delay_10ms(u8 delay);
/*----------------------------------------------------------------------------*/
/**@brief   在MS中断中调用，位BSP提供一个MS的中断
   @param   无
   @return  无
   @note   void dec_delay_counter(void)
*/
/*----------------------------------------------------------------------------*/
void dec_delay_counter(void);  //<
/*----------------------------------------------------------------------------*/
/**@brief   获取设备在线状态
   @param   无
   @return  bit0:SDMMC; bit1:USB disk;  bit4:PC;
   @note    u8 get_device_online_status(void)
*/
/*----------------------------------------------------------------------------*/
u8 get_device_online_status(void);///<
/*----------------------------------------------------------------------------*/
/**@brief   BSP检测函数，实现USB主断开机检测
   @param   无
   @return  无
   @note    void udisk_disconnect_check(void)
*/
/*----------------------------------------------------------------------------*/
void udisk_disconnect_check(void);

/*----------------------------------------------------------------------------*/
/**@brief   USB disk 枚举
   @param   *buf 枚举试读的buffer指针
   @return  0：失败；1：成功；
   @note    bool usb_host_emuerate_devcie(u8 _xdata *buf)
*/
/*----------------------------------------------------------------------------*/
bool usb_host_emuerate_devcie(u8 _xdata *buf);

/*----------------------------------------------------------------------------*/
/**@brief    MASS STORAGE设备读接口
   @param    *buffer : 读BUFFER
   @param    lbaL :lba的低16位
   @param    lbaH :lba的高16位
   @return   1;读取失败；0：读取成功
   @note     bool usb_otp_read(u16 lbaL, u16 lbaH, u8 _xdata * buffer)
*/
/*----------------------------------------------------------------------------*/
bool usb_otp_read(u16 lbaL, u16 lbaH, u8 _xdata * buffer);
/*----------------------------------------------------------------------------*/
/**@brief    SD设备读接口
   @param    *buffer : 读BUFFER
   @param    lbaL :lba的低16位
   @param    lbaH :lba的高16位
   @return   1;读取失败；0：读取成功
   @note     bool sdmmc_otp_read(u16 lbaL, u16 lbaH, u8 _xdata * buffer)
*/
/*----------------------------------------------------------------------------*/
bool sdmmc_otp_read(u16 lbaL, u16 lbaH, u8 _xdata * buffer); // sd存储设备读接口

/*----------------------------------------------------------------------------*/
/**@brief    MASS STORAGE设备读接口
   @param    *buffer : 读BUFFER
   @param    lbaL :lba的低16位
   @param    lbaH :lba的高16位
   @return   1;读取失败；0：读取成功
   @note     bool read_usb(u16 lbaL, u16 lbaH, u8 _xdata * buffer)
*/
/*----------------------------------------------------------------------------*/
bool  read_usb(u16 lbaL, u16 lbaH, u8 _xdata * buffer);    //从USB disk读取数据

/*----------------------------------------------------------------------------*/
/**@brief   获取USB从机sector大小
   @param   无
   @return  512的倍数
   @note    u8 get_usb_device_pkt_size(void)
*/
/*----------------------------------------------------------------------------*/
u8 get_usb_device_pkt_size(void);

/*----------------------------------------------------------------------------*/
/**@brief    从USB disk读取当前簇剩余的数据
   @param
   @return
   @note     void read_usb_remain_data(void)
*/
/*----------------------------------------------------------------------------*/
void read_usb_remain_data(void);   //
//FILE SYSTEM
/*----------------------------------------------------------------------------*/
/**@brief    设置查找文件的类型
   @param    * str 指向一个放在CODE区的数组，数组中存放文件格式的字符串
   @return   无
   @note     void fs_ext_setting(u8 _code * str)
*/
/*----------------------------------------------------------------------------*/
void fs_ext_setting(u8 _code * str); //

/*----------------------------------------------------------------------------*/
/**@brief    获得文件大小
   @param    无
   @return   u32 以字节为单位的文件大小
   @note     u32 f_tell_fsize(void)
*/
/*----------------------------------------------------------------------------*/
u32 f_tell_fsize(void);

/*----------------------------------------------------------------------------*/
/**@brief    获取文件读指针
   @param    无
   @return   无
   @note     u32 f_tell_fptr(void)
*/
/*----------------------------------------------------------------------------*/
u32 f_tell_fptr(void);    //

/*----------------------------------------------------------------------------*/
/**@brief     查找文件系统
   @param     无
   @return    0:成功：其他：失败
   @note      u8 f_mount(void)
*/
/*----------------------------------------------------------------------------*/
u8 f_mount(void);  ///<查找文件系统

/*----------------------------------------------------------------------------*/
/**@brief   文件系统初始化
   @param   * buf ：为文件系统读提供的BUFF
   @param   io_read ：设备读指针
   @param   sector_sizeof512 ： 512的倍数
   @return  无效
   @note    u8 f_init(u8 _xdata * buf, u16 io_read, u8 sector_sizeof512)
*/
/*----------------------------------------------------------------------------*/
u8 f_init(u8 _xdata * buf, u16 io_read, u8 sector_sizeof512);  //文件系统初始化

/*----------------------------------------------------------------------------*/
/**@brief   全设备查找文件
   @param   无
   @return  无
   @note    void fs_scan_disk(void)
*/
/*----------------------------------------------------------------------------*/
void fs_scan_disk(void);

//根据播放模式获取文件序号
//u16 fs_get_filenumber(u8 playmode, u8 searchMode);

/*----------------------------------------------------------------------------*/
/**@brief   根据文件序号找文件
   @param   fileNumber ： 查找的文件的文件序号
   @return  无
   @note    bool fs_getfile_bynumber(u16 fileNumber)
*/
/*----------------------------------------------------------------------------*/
bool fs_getfile_bynumber(u16 fileNumber);

/*----------------------------------------------------------------------------*/
/**@brief   获取当前文件的长文件名
   @param   *buffer ：存放长文件名的BUFE的指针
   @return  1:成功获取长文件名； 0:没有长文件名
   @note    bool fs_getfile_longname(u8 _xdata *buffer)
*/
/*----------------------------------------------------------------------------*/
bool fs_getfile_longname(u8 _xdata *buffer);
/*----------------------------------------------------------------------------*/
/**@brief  音频文件解码流程处理
   @param
   @return   1：解码正常；0:解码出错
   @note   bool mad_decode(void)
*/
/*----------------------------------------------------------------------------*/
//MUSIC PLAY
bool mad_decode(void);

/*----------------------------------------------------------------------------*/
/**@brief    解码控制
   @param    cmd  : 解码控制命令
   @param    para : 解码控制参数
   @return
   @note    bool mad_control(u8 cmd, s16 para)
*/
/*----------------------------------------------------------------------------*/
bool mad_control(u8 cmd, s16 para);

/*----------------------------------------------------------------------------*/
/**@brief   获取播放实时时间
   @param
   @return
   @note    u32 get_music_play_time(void)
*/
/*----------------------------------------------------------------------------*/
u32 get_music_play_time(void);

/*----------------------------------------------------------------------------*/
/**@brief   获取文件总播放时间
   @param   无
   @return  以秒为单位的时间
   @note    u32 get_music_total_time(void)
*/
/*----------------------------------------------------------------------------*/
u32 get_music_total_time(void);
/*----------------------------------------------------------------------------*/
/**@brief   实现sdmmc IO检测功能，默认使用CMD检测
   @param   flag  0 : remove sd;1 : insert sd;
   @return  void
   @note    void sdmmc_chk_io(u8 flag)
*/
/*----------------------------------------------------------------------------*/
void sdmmc_chk_io(u8 flag);
/*----------------------------------------------------------------------------*/
/**@brief   DSP config
   @param   ~
   @return  ~
   @note    void write_dsp(u8 ,u8, u8)
*/
/*----------------------------------------------------------------------------*/
void write_dsp(u8 ,u8, u8);  ///<
/*----------------------------------------------------------------------------*/
/**@brief   关闭解码中断
   @param   无
   @return  无
   @note    void disable_decode_isr(void
*/
/*----------------------------------------------------------------------------*/
void disable_decode_isr(void);

/*----------------------------------------------------------------------------*/
/**@brief   打开解码中断
   @param   无
   @return  无
   @note    void enable_decode_isr(void)
*/
/*----------------------------------------------------------------------------*/
void enable_decode_isr(void);

/*----------------------------------------------------------------------------*/
/**@brief     判断播放文件的格式
   @param     *buf : 提供的解码BUFF
   @return    0：不支持， 1: MP3, 2:WAV
   @note      u8 musice_format_check(u8 _xdata *buf)
*/
/*----------------------------------------------------------------------------*/
u8 musice_format_check(u8 _xdata *buf);  ///<

/*----------------------------------------------------------------------------*/
/**@brief   设置解码EQ音效
   @param   * table 解码音效表指针
   @return
   @note    void set_decode_eq(u8 * table)
*/
/*----------------------------------------------------------------------------*/
void set_decode_eq(u8 * table);

/*----------------------------------------------------------------------------*/
/**@brief   SD在线检测
   @param   无
   @return  无
   @note    void sd_online_check(void)
*/
/*----------------------------------------------------------------------------*/
void sd_online_check(void);
/*----------------------------------------------------------------------------*/
/**@brief   SD鉴定
   @param
   @return  1:成功；0：失败
   @note    bool init_sd(void)
*/
/*----------------------------------------------------------------------------*/
bool init_sd(void);
/*----------------------------------------------------------------------------*/
/**@brief   SD 卡读接口函数
   @param   lbaL: LBA的低16位
   @param   lbaH: LBA的高16位
   @param   *buf 读BUFF
   @return  0：成功读取；其他读取失败
   @note    bool sdmmc_read(u16 lbal, u16 lbah, u8 _xdata *buf)
*/
/*----------------------------------------------------------------------------*/
bool sdmmc_read(u16 lbal, u16 lbah, u8 _xdata *buf);
/*----------------------------------------------------------------------------*/
/**@brief   SD 卡寫接口函数
   @param   lbaL: LBA的低16位
   @param   lbaH: LBA的高16位
   @param   *buf 读BUFF
   @return  0：成功读取；其他读取失败
   @note    bool sd_write(u16 lbal, u16 lbah, u8 _xdata *buf)
*/
/*----------------------------------------------------------------------------*/
bool sd_write(u16 lbal, u16 lbah, u8 _xdata *buf);
/*----------------------------------------------------------------------------*/
/**@brief   SD模块初始化，初始化参数已经寄存器
   @param   无
   @return  无
   @note     void init_port_sd(void)
*/
/*----------------------------------------------------------------------------*/
void init_port_sd(void);

/*----------------------------------------------------------------------------*/
/**@brief  初始化USB PHY到从机状态
   @param
   @return
   @note    void init_usb_device_hardware(void)
*/
/*----------------------------------------------------------------------------*/
//USB DEVICE
void init_usb_device_hardware(void);
/*----------------------------------------------------------------------------*/
/**@brief   USB UFI massstorage 处理
   @param   无
   @return  1:massstorage正在传送数据， 0：massstorage处于空闲
   @note     void UFI_massstorage(void)
*/
/*----------------------------------------------------------------------------*/
bool UFI_massstorage(void);
/*----------------------------------------------------------------------------*/
/**@brief   获取文件中ID3V2信息的总长度
   @param   * buf ：提供給函數读所用的BUFF
   @return
   @note    void ff_cal_id3v2_tag_len(const u8 _xdata * buf)
*/
/*----------------------------------------------------------------------------*/
void ff_cal_id3v2_tag_len(const u8 _xdata * buf);

/*----------------------------------------------------------------------------*/
/**@brief   USB HID 接口函数
   @param   key：USB HID命令
   @return  无
   @note    void usb_hid_key(u8 key)
*/
/*----------------------------------------------------------------------------*/
void usb_hid_key(u8 key);
/*----------------------------------------------------------------------------*/
/**@brief   推一个先进先出的消息到消息池，低优先级
   @param   msg：低优先级的消息
   @return  无
   @note    void put_msg_fifo(u8 msg)
*/
/*----------------------------------------------------------------------------*/
void put_msg_fifo(u8 msg);
/*----------------------------------------------------------------------------*/
/**@brief   推一个后进先出的消息到消息池，高优先级
   @param   msg：高优先级的消息
   @return
   @note    void put_msg_lifo(u8 msg)
*/
/*----------------------------------------------------------------------------*/
void put_msg_lifo(u8 msg);

/*----------------------------------------------------------------------------*/
/**@brief   获取消息池的消息
   @param   无
   @return  消息
   @note    u8 get_msg(void)
*/
/*----------------------------------------------------------------------------*/
u8 get_msg(void);
/*----------------------------------------------------------------------------*/
/**@brief  清空消息池中的低优先级消息
   @param   无
   @return  无
   @note   void flush_low_msg(void)
*/
/*----------------------------------------------------------------------------*/
void flush_low_msg(void);
/*----------------------------------------------------------------------------*/
/**@brief  清空消息池中的所有消息
   @param   无
   @return  无
   @note   void flush_all_msg(void)
*/
/*----------------------------------------------------------------------------*/
void flush_all_msg(void);
/*----------------------------------------------------------------------------*/
/**@brief    传递文件偏移量
   @param    offset 文件的偏移量，以字节为单位
   @return   无
   @note     void fs_seek_offset(u32 offset)
*/
/*----------------------------------------------------------------------------*/
void fs_seek_offset(u32 offset);
/*----------------------------------------------------------------------------*/
/**@brief   文件系统偏移函数
   @param   type  0(SEEK_SET)：文件指针复位；1(SEEK_CUR):在当前文件指针的基础上按照传递的偏移量做偏移
   @return  无
   @note   u8 fs_seek (u8 type)
*/
/*----------------------------------------------------------------------------*/
u8 fs_seek (u8 type);

/*----------------------------------------------------------------------------*/
/**@brief    读写RTC
   @param    addr:读/写地址
   @return   读取的数据
   @note
*/
/*----------------------------------------------------------------------------*/
u8 irtc_sr_byte(u8 addr);

/*----------------------------------------------------------------------------*/
/**@brief    检测是否连接PC
   @param    无
   @return   1:已经检测到PC，0：没有检测到PC
   @note
*/
/*----------------------------------------------------------------------------*/
bool usb_pcin_detect(void);

/*----------------------------------------------------------------------------*/
/**@brief    检测是否连接U-disk
   @param    无
   @return   1:已经检测到U-disk，0：没有检测到U-disk
   @note
*/
/*----------------------------------------------------------------------------*/
bool usb_diskin_detect(void);

/*----------------------------------------------------------------------------*/
/**@brief    检测PC是否发送静音命令
   @param    无
   @return   1:已经检测到静音命令，0：没有检测到静单命令
   @note
*/
/*----------------------------------------------------------------------------*/
u8 usb_audio_mute_status(void);

/*----------------------------------------------------------------------------*/
/**@brief    禁止USB功能，DP/DM当普通IO使用
   @param    无
   @return   无
   @note
*/
/*----------------------------------------------------------------------------*/
void disable_usb(void);

/*----------------------------------------------------------------------------*/
/**@brief    检测USB Audio通道是否正在传输数据
   @param    无
   @return   1:正在传输数据，0：没有传输数据
   @note
*/
/*----------------------------------------------------------------------------*/
bool usb_audio_working_status(void);

/*----------------------------------------------------------------------------*/
/**@brief    设置SDMMC的写保护
   @param    1：写保护已打开，0：写保护未打开
   @return
   @note
*/
/*----------------------------------------------------------------------------*/
void write_protect_set(u8);

/*----------------------------------------------------------------------------*/
/**@brief    配置USB从机模式下，枚举成哪些设备
   @param    BIT1：USB_SPEAKER， BIT2：USB_HID， BIT3：USB_MASS， 可以同时配置枚举多个设备
   @return
   @note
*/
/*----------------------------------------------------------------------------*/
void usb_config(u8 mode);

/*----------------------------------------------------------------------------*/
/**@brief    USB AUDIO MUTE控制，每调用一次，会切换mute/unmute
   @param    无
   @return
   @note
*/
/*----------------------------------------------------------------------------*/
void Usb_Audio_Mute_Ctl(void);


/*----------------------------------------------------------------------------*/
/**@brief    设置SD卡的速度参数
   @param    high : SD 卡高速的BAUD; low : SD 卡低速的BAUD;
   @return   无
   @note     void sd_speed_init(u8 high,u8 low)
*/
/*----------------------------------------------------------------------------*/
void sd_speed_init(u8 high,u8 low);
void stop_clock(void);

void Delay(u16 i );

/*----------------------------------------------------------------------------*/
/**@brief  设置断点信息
   @param  无
   @return 文件号
   @note   void set_playpoint_info(u16 clust)
*/
/*----------------------------------------------------------------------------*/
void set_playpoint_info(u16 clust);

/*----------------------------------------------------------------------------*/
/**@brief  全盘扫描过后，获取有断点信息的文件号
   @param  无
   @return 文件号,0:该设备没有断点信息的文件；非0：对应文件号
   @note   u16 get_scan_filenumber(void)
*/
/*----------------------------------------------------------------------------*/
u16	get_scan_filenumber(void);

/*----------------------------------------------------------------------------*/
/**@brief  设置从机模式时是否接受USB标志
   @param  flag,0:接受USB数据；1：不接受USB数据
   @return 无
   @note   void set_usb_audio_receive(u8 flag)
*/
/*----------------------------------------------------------------------------*/
void set_usb_audio_receive(u8 flag);

/*----------------------------------------------------------------------------*/
/**@brief  sdmmc在线检测
   @param  void
   @return void
   @note   void sdmmc_online_chk(void)
*/
/*----------------------------------------------------------------------------*/
void sdmmc_online_chk(void);

/*----------------------------------------------------------------------------*/
/**@brief  sdmmc命令检测方式的时候的使能函数
   @param  flag:Sd_api_cmd
   @return void
   @note   void sd_chk_ctl(u8 flag)
*/
/*----------------------------------------------------------------------------*/
void sd_chk_ctl(u8 flag);

/*----------------------------------------------------------------------------*/
/**@brief  设备相关函数
   @param  para
   @return void
   @note   void set_device(u8 para)
*/
/*----------------------------------------------------------------------------*/
void set_device(u8 para);
/*----------------------------------------------------------------------------*/
/**@brief 	设置UFI设备信息
   @param 	*str：UFI 信息字符串指针
   @return  无
   @note   	void set_scsiinquiry(u8 _code *str)
*/
/*----------------------------------------------------------------------------*/
void set_scsiinquiry(u8 _code *str);
/*----------------------------------------------------------------------------*/
/**@brief 	设置USB模块进入Suspend Mode
   @param	mode 0:退出Suspend Mode；1：进入Suspend Mode
   @return  无
   @note   	void usb_suspend(void)
*/
/*----------------------------------------------------------------------------*/
void usb_suspend(void);
/*----------------------------------------------------------------------------*/
/**@brief 	用户控制强行退出解码
   @param 	cmd 0：正常解码；other：用户控制退出解码
   @return  无
   @note 	u8 decode_user_exit(u8 cmd)
*/
/*----------------------------------------------------------------------------*/
void decode_user_exit(u8 cmd);
/*----------------------------------------------------------------------------*/
/**@brief 	设置SD模块进入Suspend Mode,降低功耗
   @param	无
   @return  无
   @note   	void suspend_sdmmc(void)
*/
/*----------------------------------------------------------------------------*/
void suspend_sdmmc(void);
#endif


#endif