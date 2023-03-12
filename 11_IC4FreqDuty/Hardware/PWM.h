#ifndef __PWM_H__
#define __PWM_H__

#include "stdint.h"

void PWM_Init(void);
void PWM_SetCompare1(uint16_t compare);
void PWM_SetPrescaler(uint16_t value);

#endif //__PWM_H__
