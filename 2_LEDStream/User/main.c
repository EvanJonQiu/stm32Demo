#include "stm32f10x.h"
#include "Delay.h"

int DELAY_MS = 100;

int main(void) {
	
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA, ENABLE);
	
	GPIO_InitTypeDef GPIO_InitStructure;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_All;
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	
	GPIO_Init(GPIOA, &GPIO_InitStructure);
	
	int bits = 0x0001;
	int i = 0;
	while (1) {
		
		for (i = 0; i < 8; i++) {
			GPIO_Write(GPIOA, ~(bits << i));
			Delay_ms(DELAY_MS);
		}
		/*
		GPIO_Write(GPIOA, ~(bits << i));
		Delay_ms(DELAY_MS);
		GPIO_Write(GPIOA, ~0x0002);
		Delay_ms(DELAY_MS);
		GPIO_Write(GPIOA, ~0x0004);
		Delay_ms(DELAY_MS);
		GPIO_Write(GPIOA, ~0x0008);
		Delay_ms(DELAY_MS);
		GPIO_Write(GPIOA, ~0x0010);
		Delay_ms(DELAY_MS);
		GPIO_Write(GPIOA, ~0x0020);
		Delay_ms(DELAY_MS);
		GPIO_Write(GPIOA, ~0x0040);
		Delay_ms(DELAY_MS);
		*/
	}
}
