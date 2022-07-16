
#include "system.h"
#include "iic.h"
#include "ssd1306.h"
#include "ssd1306_tests.h"


//==========================================================================
#define Timer0_Reload   (65536UL -(MAIN_Fosc / 1000))       //Timer 0 中断频率, 1000次/秒

/*************  本地常量声明    **************/
//typedef struct 
//{
//	const uint8_t Font;    /*!< Font width in pixels */
//	const uint16_t *p_data; /*!< Pointer to data font data array */
//} Hlell;

//Hlell hello_type;

/*************  IO口定义    **************/

/*************  本地变量声明    **************/

uint8  ledIndex;  //显示位索引
int flag = 0;
uint32_t sysTick = 0;
/*************  本地函数声明    **************/



/****************  外部函数声明和外部变量声明 *****************/


/******************** 主函数 **************************/
void main(void)
{
    WTST = 0;  //设置程序指令延时参数，赋值为0可将CPU执行指令的速度设置为最快
    EAXFR = 1; //扩展寄存器(XFR)访问使能
    CKCON = 0; //提高访问XRAM速度

    P0M1 = 0x00;   P0M0 = 0x00;   //设置为准双向口
    P1M1 = 0x00;   P1M0 = 0x00;   //设置为准双向口
    P2M1 = 0x00;   P2M0 = 0x00;   //设置为准双向口
    P3M1 = 0x00;   P3M0 = 0x00;   //设置为准双向口
    P4M1 = 0x00;   P4M0 = 0x00;   //设置为准双向口
    P5M1 = 0x00;   P5M0 = 0x00;   //设置为准双向口
    P6M1 = 0x00;   P6M0 = 0x00;   //设置为准双向口
    P7M1 = 0x00;   P7M0 = 0x00;   //设置为准双向口

    P40 = 0;		//LED Power On

		AUXR = 0x80;    //Timer0 set as 1T, 16 bits timer auto-reload, 
		TH0 = (u8)(Timer0_Reload / 256);
		TL0 = (u8)(Timer0_Reload % 256);
		ET0 = 1;    //Timer0 interrupt enable
		TR0 = 1;    //Tiner0 run
	
		EA = 1;     //打开总中断
		
    //HAL_I2C_Init();
		iic_init();
		ssd1306_Init();
		//ssd1306_TestFonts();
		ssd1306_TestAll();
    while(1)
    {
				flag = !flag;
        P34 = flag;	//输出低驱动
        ledIndex++;

        HAL_Delay(500);
    }
}

void timer0 (void) interrupt 1
{
    //DisplayScan();  //1ms扫描显示一位
    //B_1ms = 1;      //1ms标志
	sysTick++;
	if(sysTick >= 0xFFFFE)
	{
		sysTick = 0;
	}
}

uint32_t HAL_GetTick()
{
	return  (sysTick );
}