/*
 * main.c
 *
 *  Created on: 09.01.2019
 *      Author: Filatov Grigorij
 */

#include "stm32f1xx.h"
#include "stm32f10x_gpio.h"
#include "stm32f10x_rcc.h"

// DEFINEs
#define LED_BLUE_ON()		  	(((GPIO_TypeDef *) GPIOB_BASE)->BRR  = GPIO_Pin_3)
#define LED_BLUE_OFF()		  	(((GPIO_TypeDef *) GPIOB_BASE)->BSRR  = GPIO_Pin_3)
#define LED_BLUE_TRIGG()		(((GPIO_TypeDef *) GPIOB_BASE)->ODR ^= GPIO_Pin_3)

void init_cc3d_led()
{
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB |RCC_APB2Periph_AFIO, ENABLE);
	GPIO_PinRemapConfig(GPIO_Remap_SWJ_JTAGDisable, ENABLE);

	GPIO_InitTypeDef    cc3d_led;
	cc3d_led.GPIO_Pin = GPIO_Pin_3;
	cc3d_led.GPIO_Speed = GPIO_Speed_50MHz;
	cc3d_led.GPIO_Mode = GPIO_Mode_Out_PP;
	GPIO_Init(GPIOB, &cc3d_led);
}

int main()
{

	SystemInit();
	init_cc3d_led();
	LED_BLUE_ON();

    while (1){
    	for(int i=0; i<100000 ; i++);
    	LED_BLUE_TRIGG();
    }
}











