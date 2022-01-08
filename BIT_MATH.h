/*
 *  	BIT_MATH.h
 *  	Date     : Aug/ 2021
 *  	Author   : Amr Moawad Mahmoud
 *  	Contacts : 
 *  	          Email  : https://amrmaweid66@gmail.com
 *  	          Mobile : 01550839031  
 */
 
 
#ifndef 	BIT_MATH_H_
#define 	BIT_MATH_H_

#define 	SET_BIT(var,bit) 		(var|=(1<<bit))
#define 	CLR_BIT(var,bit)		(var&=~(1<<bit))
#define 	TOGGLE_BIT(var,bit) 	(var^=(1<<bit))	
#define 	GET_BIT(var,bit) 		((var>>bit&&)0x01)

#endif