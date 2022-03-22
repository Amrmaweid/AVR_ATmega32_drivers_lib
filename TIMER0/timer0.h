/*
 *  	Data_Types.h
 *  	Date     : Aug/ 2021
 *  	Author   : Amr Moawad Mahmoud
 *  	Contacts : 
 *      	      Email  : https://amrmaweid66@gmail.com
 *          	  Mobile : 01550839031  
 */


#ifndef TIMER0_H_
#define TIMER0_H_

#ifndef F_CPU
	#define F_CPU 8000000UL
#endif

#include "../DIO/DIO.h"
#include <avr/interrupt.h>

volatile U16 n_overflows;  // define numbers of overflows

void TMR0_delay_normal_ms(U16 t); // change it to U16
//void TMR0_delay_CTC_ms(U16 t);
void TMR0_delay_INT_ms(U16 t);

#endif