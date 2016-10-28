/*
 * adcutil.h
 *
 *  Created on: Oct 28, 2016
 *      Author: parallels
 */

#ifndef ADCUTIL_H_
#define ADCUTIL_H_

#include <avr/io.h>

void InitADC();
uint16_t ReadADC(uint8_t ch);

#endif /* ADCUTIL_H_ */
