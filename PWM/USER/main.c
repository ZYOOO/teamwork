#include "sys.h"
#include "delay.h"
#include "usart.h"
#include "led.h"
#include "pwm.h"

/************************************************
 ALIENTEK NANO板STM32F103开发板 实验9
 PWM输出实验-HAL库版本
 技术支持：www.openedv.com
 淘宝店铺： http://eboard.taobao.com 
 关注微信公众平台微信号："正点原子"，免费获取STM32资料。
 广州市星翼电子科技有限公司  
 作者：正点原子 @ALIENTEK
************************************************/

int main(void)
{
	u16 led6pwmval=0;    
	u8 dir=1;
	
    HAL_Init();                    	//初始化HAL库    
    Stm32_Clock_Init(RCC_PLL_MUL9); //设置时钟,72M
    delay_init(72);                 //初始化延时函数
	uart_init(9600);				//初始化串口
    LED_Init();                     //初始化LED 
	TIM3_PWM_Init(899,0);			//不分频。PWM频率=72000/(899+1)=80Khz 
	while(1)
	{
		delay_ms(10);	 
		if(dir)led6pwmval++;  //dir==1 led6pwmval递增
		else led6pwmval--;	  //dir==0 led6pwmval递减
 		if(led6pwmval>300)dir=0;//led6pwmval到到300后，方向改为递减
		if(led6pwmval==0)dir=1;	//led6pwmval递减到0后，方向改为递增	   					 
		TIM_SetTIM3Compare1(led6pwmval);//修改比较值，修改占空比	   
	}
}

