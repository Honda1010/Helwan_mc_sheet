/*
 * ADC_func.h
 *
 * Created: 4/20/2024 12:54:44 PM
 *  Author: mohaned
 */ 


#ifndef ADC_FUNC_H_
#define ADC_FUNC_H_
void ADC_inti();
uint8_t ADC_read_8bit(uint8_t ch);
uint16_t ADC_read_10bit(uint8_t ch);
#endif /* ADC_FUNC_H_ */