#ifndef _ADC_H
#define _ADC_H

#include "stm32f4xx.h"

int data;
float data_float;

float ADC_Read(void){
	ADC1->SQR3=3<<0;
	ADC1->SMPR2=1<<9;// Chanel1 In3 sampling period is 15 ADC clock cycle since ADC is to be set to 12 Bit resolution
	ADC1->CR2=(1<<0);// ADC on
	ADC1->CR2|=(0<<1)|(1<<10)// single conversion. At the end of conversion set bit EOC 1.
					|(0<<11)|(1<<30);// Right Elignment. Start conversion of regular channel. 
	while((ADC1->SR&(1<<1))!=(1<<1));// Wait untill reaching End Of Conversion (EOC bit become 1)
	data=ADC1->DR;
	
	data_float=3.3*data/4095; 
	return data_float;
}

#endif
