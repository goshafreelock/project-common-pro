/*--------------------------------------------------------------------------*/
/**@file     bk1085.c
   @brief    FM transmiter
   @details
   @author
   @date   2011-3-7
   @note
*/
/*----------------------------------------------------------------------------*/
#include "Custom_config.h"
#include "bk1085.h"
#include "iic.h"

#ifdef FM_TRANSMITTER

#define bk1085_spi_gpio_init()	P3DIR &= ~(BIT(1)|BIT(1)|BIT(1));P3PU |=(BIT(1)|BIT(1)|BIT(1))

#define GPIO_SPI_CS_HIGH()		
#define GPIO_SPI_CS_LOW()

#define GPIO_SPI_CLK_HIGH()
#define GPIO_SPI_CLK_LOW()

#define GPIO_SPI_DATA_HIGH()
#define GPIO_SPI_DATA_LOW()

xd_u8 BK_reg[4]; 
xd_u16 BK_reg_2_shadow=0; 
xd_u16 BK_reg_3_shadow=0; 

static void delay_us(u16 dtime)
{
	while(dtime-->0);
}
#ifdef BK_1085_SPI_DRV
void gpio_spi_write_byte(u8 data)
{
    u8 i; 
	for(i=7;i>=0;i--)
	{
		if(data&(0x80))
			GPIO_SPI_DATA_HIGH();
		else
			GPIO_SPI_DATA_LOW();

		GPIO_SPI_CLK_HIGH();
		delay_us(20);
		data=data<<1;
		GPIO_SPI_CLK_LOW();
		delay_us(20);
	}     
}
void bk1085_multi_write(u8 dev_add,u8 *buf,u8 lenth)
{
 	u8 i=0;
	GPIO_SPI_CS_LOW();

	dev_add<<1;
	gpio_spi_write_byte(dev_add);
	
	for(i=0;i<lenth;i++)
		gpio_spi_write_byte(*(buf+i));

	GPIO_SPI_CS_HIGH();
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
    delay_us(20);
    BK_1085_DATA_LOW();
    delay_us(20);
    BK_1085_CLK_LOW();
    delay_us(20);
    BK_1085_DATA_HIGH();
}

void BK_I2C_Stop(void)
{
    BK_SDADIROUT();
    BK_1085_DATA_LOW();
    delay_us(20);
    BK_1085_CLK_HIGH();
    delay_us(20);
    BK_1085_DATA_HIGH();
    delay_us(20);
}


void BK_I2C_ack(void)
{
    BK_SDADIROUT();

    BK_1085_CLK_LOW();
    BK_1085_DATA_LOW();
    delay_us(20);

    BK_1085_CLK_HIGH();
    delay_us(20);
    BK_1085_CLK_LOW();
}      

void BK_I2C_nack(void)
{
    BK_SDADIROUT();

    BK_1085_CLK_LOW();
    BK_1085_DATA_HIGH();
    delay_us(20);

    BK_1085_CLK_HIGH();
    delay_us(20);
    BK_1085_CLK_LOW();
}

u8 BK_I2C_ReceiveACK(void)
{
    u32 ackflag;
    BK_SDADIRIN();
    delay_us(20);
    BK_1085_CLK_HIGH();
    delay_us(20);
    ackflag = (u8)BK_1085_DATA_READ();
    BK_1085_CLK_LOW();
    delay_us(20);
    return ackflag;
}

void BK_I2C_sendbyte(u8 I2CSendData)
{
   
    u8  i;
    BK_SDADIROUT();
    delay_us(20);;
    for(i = 0;i < 8;i++)
    {
        if(I2CSendData & 0x80)
        {
            BK_1085_DATA_HIGH();     //if high bit is 1,SDA= 1
        }
        else
            BK_1085_DATA_LOW();                               //else SDA=0

       	delay_us(20);
        BK_1085_CLK_HIGH();
       	delay_us(20);
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
void set_freq(para)
{
    u32 freq_temp=0;
    freq_temp = (para*0x100000)/19;
    BK_reg[0] = (u8)(freq_temp>>8);  //86 R1-->D15-D8
    BK_reg[1] = (u8)(freq_temp);     //bd R1-->D7-D0
    BK_reg[2] = (u8)(freq_temp>>24); //02 R0-->D15-D8
    BK_reg[3] = (u8)(freq_temp>>16); //e2 r0-->D7-D0
    
    bk1085_multi_write(BK_FREQ_ADD,BK_reg,4);     
}
void set_bk_power(u16 para)
{
	para = para&BK_REG3_PWR_MASK;
	
	BK_reg[0] = 	para>>8;
	BK_reg[1] = 	para&0x00FF;
	
	bk1085_multi_write(BK_REG_3,BK_reg,2);     
          
}
void set_bk_stereo(u16 para)
{
	BK_reg_2_shadow &= ~BK_REG2_MONO_MASK;
	para = para&BK_REG2_MONO_MASK;
	BK_reg_2_shadow |=para;
	
	BK_reg[0] = 	BK_reg_2_shadow>>8;
	BK_reg[1] = 	BK_reg_2_shadow&0x00FF;
	
	bk1085_multi_write(BK_REG_2,BK_reg,2);     
}
void set_bk_gain(u16 para)
{
	BK_reg_2_shadow &= ~BK_REG2_GAIN_MASK;
	para = para&BK_REG2_GAIN_MASK;
	BK_reg_2_shadow |=para;
	
	BK_reg[0] = 	BK_reg_2_shadow>>8;
	BK_reg[1] = 	BK_reg_2_shadow&0x00FF;
	
	bk1085_multi_write(BK_REG_2,BK_reg,2);     
}
void set_bk_pmu(u16 para)
{

}
void BK1085_Config(u16 para,BK_CMD bk_cmd)
{
	switch(bk_cmd)
	{
		case BK_FREQ:
			set_freq(para);
			break;
		case BK_TRAN_PWR:
			set_bk_power(para);
			break;
		case BK_GAIN:
			set_bk_gain(para);
			break;
		case BK_ST:
			set_bk_stereo(para);			
			break;
		case BK_BY_PASS:
			break;
		case BK_PM:
			set_bk_pmu(para);
			break;
		default:break;

	}
}
void bk1085_init(void)
{
#if 0
	P1DIR &=~(BIT(0)|BIT(1)|BIT(2)|BIT(3));
	P1PU |=(BIT(0)|BIT(1)|BIT(2)|BIT(3));
	P10 =0;
	delay_us(600);
	delay_us(600);
	delay_us(600);
	P10 = 1;
	P11=1;
	P12= 1;
	P15= 0;
	delay_us(600);
	delay_us(600);
#endif	
	BK1085_Config(1080,BK_FREQ);
	BK1085_Config(PWR_LEVEL_2dBm,BK_TRAN_PWR);


}
#endif

