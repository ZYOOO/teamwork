#include "pwm.h"
#include "led.h"
//////////////////////////////////////////////////////////////////////////////////	 
//本程序只供学习使用，未经作者许可，不得用于其它任何用途
//ALIENTEK STM32F103开发板
//定时器中断驱动代码	   
//正点原子@ALIENTEK
//技术论坛:www.openedv.com
//创建日期:2017/6/12
//版本：V1.0
//版权所有，盗版必究。
//Copyright(C) 广州市星翼电子科技有限公司 2014-2024
//All rights reserved									  
////////////////////////////////////////////////////////////////////////////////// 	
TIM_HandleTypeDef 	TIM3_Handler;      	//定时器句柄 
TIM_OC_InitTypeDef 	TIM3_CH1Handler;	//定时器3通道1句柄


//TIM1 PWM部分初始化 
//arr：自动重装值。
//psc：时钟预分频数
//定时器溢出时间计算方法:Tout=((arr+1)*(psc+1))/Ft us.
//Ft=定时器工作频率,单位:Mhz
void TIM3_PWM_Init(u16 arr,u16 psc)
{  
    TIM3_Handler.Instance=TIM3;         	//定时器1
    TIM3_Handler.Init.Prescaler=psc;       	//定时器分频
    TIM3_Handler.Init.CounterMode=TIM_COUNTERMODE_UP;//向上计数模式
    TIM3_Handler.Init.Period=arr;          	//自动重装载值
    TIM3_Handler.Init.ClockDivision=TIM_CLOCKDIVISION_DIV1;//分频因子
	TIM3_Handler.Init.AutoReloadPreload = TIM_AUTORELOAD_PRELOAD_ENABLE;//使能自动重载
    HAL_TIM_PWM_Init(&TIM3_Handler);       	//初始化PWM
    
    TIM3_CH1Handler.OCMode=TIM_OCMODE_PWM1; //模式选择PWM1
    TIM3_CH1Handler.Pulse=arr/2;            //设置比较值,此值用来确定占空比，默认比较值为自动重装载值的一半,即占空比为50%
    TIM3_CH1Handler.OCPolarity=TIM_OCPOLARITY_LOW; //输出比较极性为低 
    HAL_TIM_PWM_ConfigChannel(&TIM3_Handler,&TIM3_CH1Handler,TIM_CHANNEL_1);//配置TIM3通道1
	
    HAL_TIM_PWM_Start(&TIM3_Handler,TIM_CHANNEL_1);//开启PWM通道1
	 	   
}

//定时器底层驱动，时钟使能，引脚配置
//此函数会被HAL_TIM_PWM_Init()调用
//htim:定时器句柄
void HAL_TIM_PWM_MspInit(TIM_HandleTypeDef *htim)
{
	GPIO_InitTypeDef GPIO_Initure;
	
    if(htim->Instance==TIM3)
	{
		__HAL_RCC_TIM3_CLK_ENABLE();			//使能定时器3
		__HAL_AFIO_REMAP_TIM3_ENABLE();		    //TIM3通道引脚完全重映射使能
		__HAL_RCC_GPIOC_CLK_ENABLE();			//开启GPIOC时钟
		
		GPIO_Initure.Pin=GPIO_PIN_6;           	//PC6
		GPIO_Initure.Mode=GPIO_MODE_AF_PP;  	//复用推挽输出
		GPIO_Initure.Pull=GPIO_PULLUP;          //上拉
		GPIO_Initure.Speed=GPIO_SPEED_HIGH;     //高速
		HAL_GPIO_Init(GPIOC,&GPIO_Initure); 	
	}
}

//设置TIM3通道1的占空比
//compare:比较值
void TIM_SetTIM3Compare1(u32 compare)
{
	TIM3->CCR1=compare; 
}

//定时器3中断服务函数
void TIM3_IRQHandler(void)
{
    HAL_TIM_IRQHandler(&TIM3_Handler);
}

