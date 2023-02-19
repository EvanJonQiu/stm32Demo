#include "stm32f10x.h"
#include "Delay.h"

int use_register();

int main(void) {
	
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA, ENABLE);
	
	GPIO_InitTypeDef GPIO_InitStructure;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_0;
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	
	GPIO_Init(GPIOA, &GPIO_InitStructure);
	
	while (1) {
		
		GPIO_WriteBit(GPIOA, GPIO_Pin_0, Bit_RESET);
		Delay_ms(500);
		GPIO_WriteBit(GPIOA, GPIO_Pin_0, Bit_SET);
		Delay_ms(500);
	}
}

int use_register() {
	/**
	 *  use register to light led
	 */
	RCC->APB2ENR |= RCC_APB2Periph_GPIOA;
	
	GPIO_TypeDef* p = GPIOA;
	p->CRL &= ~(0x0f << (4 * 0));
	p->CRL |= 0x00000003;
	
	while (1) {
		p->BRR = GPIO_Pin_0;
		Delay_ms(500);
		p->BSRR = GPIO_Pin_0;
		Delay_ms(500);
	}
}
