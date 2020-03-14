#include <stddef.h>
#include "stm32f10x.h"
#include "stm32f10x_gpio.h"
#include "stm32f10x_rcc.h"


int promjeni(int);

void initLED();

int main(void){
	//inicijalizacija
	int x;
	initLED();

	//ciklicki dio programa
	while(1){

8		x=promjeni(x);	//promjena vrijednosti x
		GPIO_WriteBit(GPIOC, GPIO_Pin_13, x);

	}

}



void initLED(){	//PC13 izlazni
	GPIO_InitTypeDef led;

	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOC, ENABLE);

	GPIO_StructInit(&led);

	led.GPIO_Mode = GPIO_Mode_Out_PP;
	led.GPIO_Pin = GPIO_Pin_13;
	led.GPIO_Speed = GPIO_Speed_10MHz;

	GPIO_Init(GPIOC, &led);		//inicijalizira
	GPIO_WriteBit(GPIOC, GPIO_Pin_13, 1);	//postavlja 1 na pocetku

}

int promjeni(int a){
	if(a==0){
		return 1;
	}
	return 0;
}
