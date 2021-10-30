/**
 * @file main.c
 * @author Sultan
 * @brief 
 * @version 0.1
 * @date 2021-10-30
 * 
 * @copyright Copyright (c) 2021
 * 
 */

#include "stm32f407xx.h"


void delay(int d)
{
	for(uint32_t i = 0 ; i < d*5000 ; i ++);
}

int main(void)
{

	GPIO_Handle_t GpioLed, GpioLed2, GpioLed3, GpioLed4, GPIOBtn;

	//this is led gpio configuration
	GpioLed.pGPIOx = GPIOD;
	GpioLed.GPIO_PinConfig.GPIO_PinNumber = GPIO_PIN_NO_12;
	GpioLed.GPIO_PinConfig.GPIO_PinMode = GPIO_MODE_OUT;
	GpioLed.GPIO_PinConfig.GPIO_PinSpeed = GPIO_SPEED_LOW;
	GpioLed.GPIO_PinConfig.GPIO_PinOPType = GPIO_OP_TYPE_PP;
	GpioLed.GPIO_PinConfig.GPIO_PinPuPdControl = GPIO_NO_PUPD;

	GPIO_PeriClockControl(GPIOD,ENABLE);

	GPIO_Init(&GpioLed);

	//this is led gpio configuration
	GpioLed2.pGPIOx = GPIOD;
	GpioLed2.GPIO_PinConfig.GPIO_PinNumber = GPIO_PIN_NO_13;
	GpioLed2.GPIO_PinConfig.GPIO_PinMode = GPIO_MODE_OUT;
	GpioLed2.GPIO_PinConfig.GPIO_PinSpeed = GPIO_SPEED_LOW;
	GpioLed2.GPIO_PinConfig.GPIO_PinOPType = GPIO_OP_TYPE_PP;
	GpioLed2.GPIO_PinConfig.GPIO_PinPuPdControl = GPIO_NO_PUPD;

	GPIO_PeriClockControl(GPIOD,ENABLE);

	GPIO_Init(&GpioLed2);

	//this is led gpio configuration
	GpioLed3.pGPIOx = GPIOD;
	GpioLed3.GPIO_PinConfig.GPIO_PinNumber = GPIO_PIN_NO_14;
	GpioLed3.GPIO_PinConfig.GPIO_PinMode = GPIO_MODE_OUT;
	GpioLed3.GPIO_PinConfig.GPIO_PinSpeed = GPIO_SPEED_LOW;
	GpioLed3.GPIO_PinConfig.GPIO_PinOPType = GPIO_OP_TYPE_PP;
	GpioLed3.GPIO_PinConfig.GPIO_PinPuPdControl = GPIO_NO_PUPD;

	GPIO_PeriClockControl(GPIOD,ENABLE);

	GPIO_Init(&GpioLed3);

	//this is led gpio configuration
	GpioLed4.pGPIOx = GPIOD;
	GpioLed4.GPIO_PinConfig.GPIO_PinNumber = GPIO_PIN_NO_15;
	GpioLed4.GPIO_PinConfig.GPIO_PinMode = GPIO_MODE_OUT;
	GpioLed4.GPIO_PinConfig.GPIO_PinSpeed = GPIO_SPEED_LOW;
	GpioLed4.GPIO_PinConfig.GPIO_PinOPType = GPIO_OP_TYPE_PP;
	GpioLed4.GPIO_PinConfig.GPIO_PinPuPdControl = GPIO_NO_PUPD;

	GPIO_PeriClockControl(GPIOD,ENABLE);

	GPIO_Init(&GpioLed4);

	//this is btn gpio configuration
	GPIOBtn.pGPIOx = GPIOA;
	GPIOBtn.GPIO_PinConfig.GPIO_PinNumber = GPIO_PIN_NO_0;
	GPIOBtn.GPIO_PinConfig.GPIO_PinMode = GPIO_MODE_IT_FT;
	GPIOBtn.GPIO_PinConfig.GPIO_PinSpeed = GPIO_SPEED_FAST;
	GPIOBtn.GPIO_PinConfig.GPIO_PinPuPdControl = GPIO_PIN_PU;

	GPIO_PeriClockControl(GPIOA,ENABLE);

	GPIO_Init(&GPIOBtn);

	GPIO_WriteToOutputPin(GPIOD,GPIO_PIN_NO_12,GPIO_PIN_RESET);
	GPIO_WriteToOutputPin(GPIOD,GPIO_PIN_NO_13,GPIO_PIN_RESET);
	GPIO_WriteToOutputPin(GPIOD,GPIO_PIN_NO_14,GPIO_PIN_RESET);
	GPIO_WriteToOutputPin(GPIOD,GPIO_PIN_NO_15,GPIO_PIN_RESET);
	//IRQ configurations
	GPIO_IRQPriorityConfig(IRQ_NO_EXTI0,NVIC_IRQ_PRI0);
	GPIO_IRQInterruptConfig(IRQ_NO_EXTI0,ENABLE);

    while(1){
        for(uint32_t i=0;i<10;i++){
            GPIO_WriteToOutputPin(GPIOD,GPIO_PIN_NO_12,GPIO_PIN_SET);
            GPIO_WriteToOutputPin(GPIOD,GPIO_PIN_NO_14,GPIO_PIN_SET);
            delay(8000);
            GPIO_WriteToOutputPin(GPIOD,GPIO_PIN_NO_12,GPIO_PIN_RESET);
            GPIO_WriteToOutputPin(GPIOD,GPIO_PIN_NO_14,GPIO_PIN_RESET);
            delay(8000);
        }
        
        for(uint32_t i=0;i<10;i++){
            GPIO_WriteToOutputPin(GPIOD,GPIO_PIN_NO_13,GPIO_PIN_SET);
            GPIO_WriteToOutputPin(GPIOD,GPIO_PIN_NO_15,GPIO_PIN_SET);
            delay(8000);
            GPIO_WriteToOutputPin(GPIOD,GPIO_PIN_NO_13,GPIO_PIN_RESET);
            GPIO_WriteToOutputPin(GPIOD,GPIO_PIN_NO_15,GPIO_PIN_RESET);
            delay(8000);
        }
    }

}
int count=0;
void EXTI0_IRQHandler(void)
{
   /// delay(); //200ms . wait till button de-bouncing gets over
	GPIO_IRQHandling(GPIO_PIN_NO_0); //clear the pending event from exti line
	count++;
	if(count==1){
        for(uint32_t i=0;i<10;i++){
            GPIO_WriteToOutputPin(GPIOD,GPIO_PIN_NO_12,GPIO_PIN_SET);
            GPIO_WriteToOutputPin(GPIOD,GPIO_PIN_NO_13,GPIO_PIN_SET);
            GPIO_WriteToOutputPin(GPIOD,GPIO_PIN_NO_14,GPIO_PIN_SET);
            GPIO_WriteToOutputPin(GPIOD,GPIO_PIN_NO_15,GPIO_PIN_SET);
            delay(8000);
            GPIO_WriteToOutputPin(GPIOD,GPIO_PIN_NO_12,GPIO_PIN_RESET);
            GPIO_WriteToOutputPin(GPIOD,GPIO_PIN_NO_13,GPIO_PIN_RESET);
            GPIO_WriteToOutputPin(GPIOD,GPIO_PIN_NO_14,GPIO_PIN_RESET);
            GPIO_WriteToOutputPin(GPIOD,GPIO_PIN_NO_15,GPIO_PIN_RESET);
            delay(8000);
        }
        for(uint32_t i=0;i<10;i++){
            GPIO_WriteToOutputPin(GPIOD,GPIO_PIN_NO_12,GPIO_PIN_SET);
            GPIO_WriteToOutputPin(GPIOD,GPIO_PIN_NO_14,GPIO_PIN_SET);
            delay(8000);
            GPIO_WriteToOutputPin(GPIOD,GPIO_PIN_NO_12,GPIO_PIN_RESET);
            GPIO_WriteToOutputPin(GPIOD,GPIO_PIN_NO_14,GPIO_PIN_RESET);
            delay(8000);
        }
	}
	else if(count==2){
		for(uint32_t i=0;i<20;i++){
            GPIO_WriteToOutputPin(GPIOD,GPIO_PIN_NO_12,GPIO_PIN_SET);
            GPIO_WriteToOutputPin(GPIOD,GPIO_PIN_NO_13,GPIO_PIN_SET);
            GPIO_WriteToOutputPin(GPIOD,GPIO_PIN_NO_14,GPIO_PIN_SET);
            GPIO_WriteToOutputPin(GPIOD,GPIO_PIN_NO_15,GPIO_PIN_SET);
            delay(4000);
            GPIO_WriteToOutputPin(GPIOD,GPIO_PIN_NO_12,GPIO_PIN_RESET);
            GPIO_WriteToOutputPin(GPIOD,GPIO_PIN_NO_13,GPIO_PIN_RESET);
            GPIO_WriteToOutputPin(GPIOD,GPIO_PIN_NO_14,GPIO_PIN_RESET);
            GPIO_WriteToOutputPin(GPIOD,GPIO_PIN_NO_15,GPIO_PIN_RESET);
            delay(4000);
        }
	}
	else if(count==3){
        count=0;
	}
}
// int a=0;

// void EXTI0_IRQHandler(void)
// {
//    /// delay(); //200ms . wait till button de-bouncing gets over
// 	GPIO_IRQHandling(GPIO_PIN_NO_0); //clear the pending event from exti line
// 	a++;
// 	if(a==1){
// 		GPIO_WriteToOutputPin(GPIOD,GPIO_PIN_NO_13,GPIO_PIN_RESET);
// 		GPIO_WriteToOutputPin(GPIOD,GPIO_PIN_NO_14,GPIO_PIN_RESET);
// 		GPIO_WriteToOutputPin(GPIOD,GPIO_PIN_NO_15,GPIO_PIN_RESET);
// 		GPIO_ToggleOutputPin(GPIOD,GPIO_PIN_NO_12);
// 		delay();
// 	}
// 	else if(a==2){
// 		GPIO_WriteToOutputPin(GPIOD,GPIO_PIN_NO_12,GPIO_PIN_RESET);
// 		GPIO_WriteToOutputPin(GPIOD,GPIO_PIN_NO_14,GPIO_PIN_RESET);
// 		GPIO_WriteToOutputPin(GPIOD,GPIO_PIN_NO_15,GPIO_PIN_RESET);
// 		GPIO_ToggleOutputPin(GPIOD,GPIO_PIN_NO_13);
// 	}
// 	else if(a==3){
// 		GPIO_WriteToOutputPin(GPIOD,GPIO_PIN_NO_13,GPIO_PIN_RESET);
// 		GPIO_WriteToOutputPin(GPIOD,GPIO_PIN_NO_12,GPIO_PIN_RESET);
// 		GPIO_WriteToOutputPin(GPIOD,GPIO_PIN_NO_15,GPIO_PIN_RESET);
// 		GPIO_ToggleOutputPin(GPIOD,GPIO_PIN_NO_14);
// 	}
// 	else if(a==4){
// 		GPIO_WriteToOutputPin(GPIOD,GPIO_PIN_NO_13,GPIO_PIN_RESET);
// 		GPIO_WriteToOutputPin(GPIOD,GPIO_PIN_NO_14,GPIO_PIN_RESET);
// 		GPIO_WriteToOutputPin(GPIOD,GPIO_PIN_NO_12,GPIO_PIN_RESET);
// 		GPIO_ToggleOutputPin(GPIOD,GPIO_PIN_NO_15);
// 		a=0;
// 	}
// }