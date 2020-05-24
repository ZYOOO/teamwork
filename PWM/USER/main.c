#include "sys.h"
#include "delay.h"
#include "usart.h"
#include "led.h"
#include "pwm.h"

/************************************************
 ALIENTEK NANO��STM32F103������ ʵ��9
 PWM���ʵ��-HAL��汾
 ����֧�֣�www.openedv.com
 �Ա����̣� http://eboard.taobao.com 
 ��ע΢�Ź���ƽ̨΢�źţ�"����ԭ��"����ѻ�ȡSTM32���ϡ�
 ������������ӿƼ����޹�˾  
 ���ߣ�����ԭ�� @ALIENTEK
************************************************/

int main(void)
{
	u16 led6pwmval=0;    
	u8 dir=1;
	
    HAL_Init();                    	//��ʼ��HAL��    
    Stm32_Clock_Init(RCC_PLL_MUL9); //����ʱ��,72M
    delay_init(72);                 //��ʼ����ʱ����
	uart_init(9600);				//��ʼ������
    LED_Init();                     //��ʼ��LED 
	TIM3_PWM_Init(899,0);			//����Ƶ��PWMƵ��=72000/(899+1)=80Khz 
	while(1)
	{
		delay_ms(10);	 
		if(dir)led6pwmval++;  //dir==1 led6pwmval����
		else led6pwmval--;	  //dir==0 led6pwmval�ݼ�
 		if(led6pwmval>300)dir=0;//led6pwmval����300�󣬷����Ϊ�ݼ�
		if(led6pwmval==0)dir=1;	//led6pwmval�ݼ���0�󣬷����Ϊ����	   					 
		TIM_SetTIM3Compare1(led6pwmval);//�޸ıȽ�ֵ���޸�ռ�ձ�	   
	}
}

