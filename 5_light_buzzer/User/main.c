#include "stm32f10x.h"
#include "Delay.h"
#include "Buzzer.h"
#include "LightSensor.h"

int main(void) {
	Buzzer_Init();
	LightSensor_Init();
	
	while (1) {
		if (LightSensor_Get() == 1) {
			Buzzer_OFF();
		} else {
			Buzzer_ON();
		}
	}
}
