#include "sys.h"
#include "delay.h"  
#include "usart.h"   
#include "led.h"
#include "lcd.h" 
#include "adc.h"
//ALIENTEK ̽����STM32F407������ ʵ��18
//ADC ʵ��  
//����֧�֣�www.openedv.com
//������������ӿƼ����޹�˾
    
int main(void)
{      
 	u16 adcx;
	float temp;
	Stm32_Clock_Init(336,8,2,7);//����ʱ��,168Mhz 
	delay_init(168);			//��ʱ��ʼ��  
	uart_init(84,115200);		//��ʼ�����ڲ�����Ϊ115200   
	LED_Init();					//��ʼ��LED 
 	LCD_Init();					//��ʼ��LCD
	Adc_Init(); 				//��ʼ��ADC
	POINT_COLOR=RED; 
	LCD_ShowString(30,50,200,16,16,"Explorer STM32F4");	
	LCD_ShowString(30,70,200,16,16,"ADC TEST");	
	LCD_ShowString(30,90,200,16,16,"ATOM@ALIENTEK");
	LCD_ShowString(30,110,200,16,16,"2014/5/6");	  
	POINT_COLOR=BLUE;//��������Ϊ��ɫ
	LCD_ShowString(30,130,200,16,16,"ADC1_CH5_VAL:");	      
	LCD_ShowString(30,150,200,16,16,"ADC1_CH5_VOL:0.000V");	      
	while(1)
	{
		adcx=Get_Adc_Average(ADC_CH5,20);
		LCD_ShowxNum(134,130,adcx,4,16,0);//��ʾADC��ֵ
		temp=(float)adcx*(3.3/4096); 
		adcx=temp;
		LCD_ShowxNum(134,150,adcx,1,16,0);//��ʾ��ѹֵ
		temp-=adcx;
		temp*=1000;
		LCD_ShowxNum(150,150,temp,3,16,0X80);
		LED0=!LED0;
		delay_ms(250);	
	}
}

















