/*
 *  	Data_Types.h
 *  	Date     : Aug/ 2021
 *  	Author   : Amr Moawad Mahmoud
 *  	Contacts : 
 *      	      Email  : https://amrmaweid66@gmail.com
 *          	  Mobile : 01550839031  
 */


#ifndef I2C_H
#define  I2C_H

#include "../DIO/DIO.h"
#include <math.h>

#ifndef F_CPU
#define F_CPU 8000000UL
#endif 

#define PRESCALER_PW 0
#define F_SCK 8000000UL

void I2C_master_init();
void I2C_start();
void I2C_master_transmit(U8 ch);
U8 I2C_read(U8 single_byte);
void I2C_stop();
void I2C_slave_init(U8 slave_address);
void I2C_slave_transmit(U8 ch);

#endif