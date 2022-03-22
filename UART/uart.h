/*
 *  	Data_Types.h
 *  	Date     : Aug/ 2021
 *  	Author   : Amr Moawad Mahmoud
 *  	Contacts : 
 *      	      Email  : https://amrmaweid66@gmail.com
 *          	  Mobile : 01550839031  
 */


#ifndef UART_H
#define UART_H

#include "../DIO/DIO.h"

#ifndef F_CPU
#define F_CPU 8000000ul
#endif

void UART_init(U16);
void UART_write(U8);
void UART_write_string(U8 *str);
U8 UART_read();

#endif