/*--------------------------------------------------------------------------*/
/**@file   key.c
   @brief  
   @details
   @author
   @date   2011-12-17
   @note
*/
/*----------------------------------------------------------------------------*/
#include "Custom_config.h"
#define slave_spi_data_high()
#define slave_spi_data_low()
#define slave_spi_clk_high()
#define slave_spi_clk_low()

#define slave_cs_init()
#define read_cs_port()
#define slave_clk_init()
#define read_clk_port()

#define slave_data_init_in()
#define slave_data_init_out()
#define read_data_port()

#define SLAVE_SPI_IF

#if defined(SLAVE_SPI_IF)
static xd_u16 timeout_cnt=0;
bool get_cs_start_sigal()
{
	 slave_cs_init();
	if(read_cs_port()){
		return 0;
	}
	else{

		return 1;
	}
}
void slave_timerout_clr()
{
	timeout_cnt =0;
}
bool slave_timeout_err()
{
	_nop_();
	_nop_();	
	if(timeout_cnt++>5000){
		timeout_cnt =0;
		return 1;
	}
	else{
		return 0;
	}
}
void slav_slav_delay_us(u16 dtime)
{
	while(dtime-->0);
}
void slave_spi_send_byte(u8 slave_data)	//3 send data to masters
{
    u8 i=0; 

	slave_data_init_out();
	slave_timerout_clr();
	while(read_clk_port(){
		if(slave_timeout_err()) return;
	}
	_nop_();
	_nop_();
	
	for(i=7;i>=0;i--)
	{
		slave_timerout_clr();
		while(read_clk_port()){			//4 Wait for failing edge 
			if(slave_timeout_err()) return;
		}

		
		if(slave_data&0x80)
			slave_spi_data_high();
		else
			slave_spi_data_low();

		slave_data=slave_data<<1;
		_nop_();
		_nop_();

		slave_timerout_clr();
		while(!read_clk_port()){		
			if(slave_timeout_err()) return;
		}
	}     
}
void slave_spi_read_byte(u8 *slave_data)	//4read data from master mcu protocol
{
    u8 i=0; 

	slave_data_init_in();
	slave_timerout_clr();
	while(read_clk_port(){
		if(slave_timeout_err()) return;
	}
	;
	_nop_();
	_nop_();
	
	for(i=7;i>=0;i--)
	{
		slave_timerout_clr();
		while(!read_clk_port()){			//4 Wait for raising edge 
			if(slave_timeout_err()) return;
		}
		_nop_();
		_nop_();
		_nop_();
		_nop_();
		
		if(read_data_port())
			(*slave_data)|=0x01;
		else
			(*slave_data)<<1;

		slave_timerout_clr();
		while(read_clk_port()){
			if(slave_timeout_err()) return;
		}
	}     
}
#else

#define BK_1085_DATA_HIGH()   	P01=1;
#define BK_1085_DATA_LOW()    	P01=0;
#define BK_1085_DATA_READ()    	P01
#define BK_SDADIROUT()       		P0DIR &= ~(BIT(1));P0PU |= (BIT(1))
#define BK_SDADIRIN()        		P0DIR |= (BIT(1));P0PU |= (BIT(1))

#define BK_SCLDIROUT()        	   P0DIR &= ~(BIT(0));P0PU |= (BIT(0))
#define BK_1085_CLK_HIGH()     P00=1
#define BK_1085_CLK_LOW()      P00=0

void BK_I2C_init(void)
{
    BK_SDADIROUT();                  //SDA output
    BK_SCLDIROUT();                  //SCL output
    BK_1085_CLK_HIGH();
    BK_1085_DATA_HIGH();
}

void BK_I2C_Start(void)
{
    BK_I2C_init();
    slav_delay_us(20);
    BK_1085_DATA_LOW();
    slav_delay_us(20);
    BK_1085_CLK_LOW();
    slav_delay_us(20);
    BK_1085_DATA_HIGH();
}

void BK_I2C_Stop(void)
{
    BK_SDADIROUT();
    BK_1085_DATA_LOW();
    slav_delay_us(20);
    BK_1085_CLK_HIGH();
    slav_delay_us(20);
    BK_1085_DATA_HIGH();
    slav_delay_us(20);
}


void BK_I2C_ack(void)
{
    BK_SDADIROUT();

    BK_1085_CLK_LOW();
    BK_1085_DATA_LOW();
    slav_delay_us(20);

    BK_1085_CLK_HIGH();
    slav_delay_us(20);
    BK_1085_CLK_LOW();
}      

void BK_I2C_nack(void)
{
    BK_SDADIROUT();

    BK_1085_CLK_LOW();
    BK_1085_DATA_HIGH();
    slav_delay_us(20);

    BK_1085_CLK_HIGH();
    slav_delay_us(20);
    BK_1085_CLK_LOW();
}

u8 BK_I2C_ReceiveACK(void)
{
    u32 ackflag;
    BK_SDADIRIN();
    slav_delay_us(20);
    BK_1085_CLK_HIGH();
    slav_delay_us(20);
    ackflag = (u8)BK_1085_DATA_READ();
    BK_1085_CLK_LOW();
    slav_delay_us(20);
    return ackflag;
}

void BK_I2C_sendbyte(u8 I2CSendData)
{
   
    u8  i;
    BK_SDADIROUT();
    slav_delay_us(20);;
    for(i = 0;i < 8;i++)
    {
        if(I2CSendData & 0x80)
        {
            BK_1085_DATA_HIGH();     //if high bit is 1,SDA= 1
        }
        else
            BK_1085_DATA_LOW();                               //else SDA=0

       	slav_delay_us(20);
        BK_1085_CLK_HIGH();
       	slav_delay_us(20);
        I2CSendData <<= 1;                          //shift left 1 bit
        BK_1085_CLK_LOW();
    }                       
}
void bk1085_multi_write(u8 dev_add,u8 *buf,u8 lenth)
{
    u8  byte;

    BK_I2C_Start();                    //I2CÆô¶¯
    BK_I2C_sendbyte(0x1D);             //SEND ID
    BK_I2C_ReceiveACK();
    BK_I2C_sendbyte((dev_add<<1));       //Ð´µØÖ·
    BK_I2C_ReceiveACK();

    for(byte = 0;byte<lenth;byte++){
	BK_I2C_sendbyte(*(buf+byte));             //send data
    	BK_I2C_ReceiveACK();
    }

    BK_I2C_Stop();                     //I2CÍ£Ö¹
}
#endif

void slave_send_data(u8 *fsm_para,u8 len)
{


}
u8 slave_get_data()
{
	xd_u8 read_data=0;
	while(get_cs_start_sigal()){

		slave_spi_read_byte(read_data);
		return read_data;
	}
	return 0xFF;
}
