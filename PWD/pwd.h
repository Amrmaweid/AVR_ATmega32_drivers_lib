/*
 *  	Data_Types.h
 *  	Date     : Aug/ 2021
 *  	Author   : Amr Moawad Mahmoud
 *  	Contacts : 
 *      	      Email  : https://amrmaweid66@gmail.com
 *          	  Mobile : 01550839031  
 */


#ifndef PWD_H
#define PWD_H
#include "../DIO/DIO.h"

#ifndef F_CPU
#define F_CPU 8000000ul
#endif

#define OC0_PIN 3

void PWD_get_duty(U8 dt);

#endif