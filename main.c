
#include "system.h"
#include "iic.h"
#include "ssd1306.h"
#include "ssd1306_tests.h"


//==========================================================================
#define Timer0_Reload   (65536UL -(MAIN_Fosc / 1000))       //Timer 0 �ж�Ƶ��, 1000��/��

/*************  ���س�������    **************/
//typedef struct 
//{
//	const uint8_t Font;    /*!< Font width in pixels */
//	const uint16_t *p_data; /*!< Pointer to data font data array */
//} Hlell;

//Hlell hello_type;

/*************  IO�ڶ���    **************/

/*************  ���ر�������    **************/

uint8  ledIndex;  //��ʾλ����
int flag = 0;
uint32_t sysTick = 0;
/*************  ���غ�������    **************/



/****************  �ⲿ�����������ⲿ�������� *****************/


/******************** ������ **************************/
void main(void)
{
    WTST = 0;  //���ó���ָ����ʱ��������ֵΪ0�ɽ�CPUִ��ָ����ٶ�����Ϊ���
    EAXFR = 1; //��չ�Ĵ���(XFR)����ʹ��
    CKCON = 0; //��߷���XRAM�ٶ�

    P0M1 = 0x00;   P0M0 = 0x00;   //����Ϊ׼˫���
    P1M1 = 0x00;   P1M0 = 0x00;   //����Ϊ׼˫���
    P2M1 = 0x00;   P2M0 = 0x00;   //����Ϊ׼˫���
    P3M1 = 0x00;   P3M0 = 0x00;   //����Ϊ׼˫���
    P4M1 = 0x00;   P4M0 = 0x00;   //����Ϊ׼˫���
    P5M1 = 0x00;   P5M0 = 0x00;   //����Ϊ׼˫���
    P6M1 = 0x00;   P6M0 = 0x00;   //����Ϊ׼˫���
    P7M1 = 0x00;   P7M0 = 0x00;   //����Ϊ׼˫���

    P40 = 0;		//LED Power On

		AUXR = 0x80;    //Timer0 set as 1T, 16 bits timer auto-reload, 
		TH0 = (u8)(Timer0_Reload / 256);
		TL0 = (u8)(Timer0_Reload % 256);
		ET0 = 1;    //Timer0 interrupt enable
		TR0 = 1;    //Tiner0 run
	
		EA = 1;     //�����ж�
		
    //HAL_I2C_Init();
		iic_init();
		ssd1306_Init();
		//ssd1306_TestFonts();
		ssd1306_TestAll();
    while(1)
    {
				flag = !flag;
        P34 = flag;	//���������
        ledIndex++;

        HAL_Delay(500);
    }
}

void timer0 (void) interrupt 1
{
    //DisplayScan();  //1msɨ����ʾһλ
    //B_1ms = 1;      //1ms��־
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