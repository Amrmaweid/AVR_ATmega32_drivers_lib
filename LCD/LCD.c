/*
 *  	Data_Types.h
 *  	Date     : Aug/ 2021
 *  	Author   : Amr Moawad Mahmoud
 *  	Contacts : 
 *      	      Email  : https://amrmaweid66@gmail.com
 *          	  Mobile : 01550839031  
 */
 
 

 #include	"DRIVERS_LCD_LCD_H_"
 
 
 void LCD_lcd_init(void)
 {
	 _delay_ms(20);
	 Data_Dir_LCD_control |= ( 1<<EN_switch | 1<<ReadWrite | 1<<RS_switch );
	 LCD_control &= ~( 1<<EN_switch | 1<<ReadWrite | 1<<RS_switch );
	 
	 DataDir_LCD_port = 0xff;
	 _delay_ms(15);
	 
	 LCD_clear_screen ();
	 
 #ifdef EIGHT_BIT_MODE
	 LCD_Send_A_Command(LCD_FUNCTION_8BIT_2LINES);
 #endif
 
 #ifdef FOUR_BIT_MODE
	 LCD_Send_A_Command(0x02);
	
	 LCD_Send_A_Command(LCD_FUNCTION_4BIT_2LINES);
	
 #endif
 
 	 LCD_Send_A_Command(LCD_ENTRY_MODE);
 	 LCD_Send_A_Command(LCD_BEGIN_AT_FIRST_RAW);
 	 LCD_Send_A_Command(LCD_DISP_ON_CURSOR_BLINK );
 
 }
 
 
void LCD_check_lcd_isbusy()
{
	
	DataDir_LCD_port &= ~(0xff<<DATA_shift) ;
	LCD_control |= (1<<ReadWrite); // read
	LCD_control &= ~ (1<<RS_switch);      // reset RS  : 0 for RS : selecting command register


	while (LCD_port >= 0x80)
	{
	LCD_lcd_kick ();
	}


	//_delay_ms (500) ;
	DataDir_LCD_port = 0xFF; //0xFF means 0b11111111
	LCD_control &= ~ (1<<ReadWrite); //write

}
 
 
 void LCD_lcd_kick (void)
 {
	 LCD_control &= ~( 1 << EN_switch );
	 
	 asm volatile ("nop");
	 asm volatile ("nop");
	 _delay_ms(50);
	 
	 LCD_control |= ( 1<< EN_switch );
 }
 
 
 
 
 void LCD_Send_A_Command(unsigned char command)
 {
 #ifdef EIGHT_BIT_MODE
	 
	 LCD_check_lcd_isbusy();
	 LCD_port = command;
	 LCD_control &= ~( (1<<ReadWrite) | (1<<RS_switch) );
	 LCD_lcd_kick();
	 LCD_port = 0;
 
 #endif
 
 #ifdef FOUR_BIT_MODE
 
	 LCD_check_lcd_isbusy();
	 LCD_port &= 0x0f;
	 LCD_port |= ( command & 0xf0 );
	 LCD_control &= ~(( 1 << ReadWrite )|( 1 << RS_switch ));
	 LCD_lcd_kick();
	 
	 LCD_port &= 0x0f;
	 LCD_port |= ((command << 4 ) & 0xf0 );
	 LCD_lcd_kick();
	 LCD_port = 0;
	
 #endif
 
 }
 
 
 
 void LCD_Send_A_Command_4mode(unsigned char command)
{
	LCD_check_lcd_isbusy();
	LCD_port&= 0x0F;
	LCD_port |= (command&0xF0);
	LCD_control &= ~ ((1<<ReadWrite)|(1<<RS_switch));
	LCD_lcd_kick ();
	LCD_control &= 0x0F;  // Make Data Nibble as 0000
	LCD_control |= ((command<<4)&0xF0);
	LCD_lcd_kick ();
	LCD_port = 0;
}
 
 
 
 void LCD_Send_A_Character(unsigned char character)
 {
	 
 #ifdef EIGHT_BIT_MODE
 
	 LCD_check_lcd_isbusy();
	 LCD_control |= ( 1 << RS_switch );
	 LCD_control &= ~( 1<< ReadWrite );
	 LCD_port = ((character) << (DATA_shift));
	 
	 
	 LCD_lcd_kick();
	 LCD_port = 0;
 
 #endif
 
 
 #ifdef FOUR_BIT_MODE
	 
	 LCD_check_lcd_isbusy();
	 LCD_control |= ( 1 << RS_switch );
	 LCD_control &= ~( 1<< ReadWrite );
	 LCD_port &= 0x0f;
	 LCD_port |= ( character & 0xf0 );
	 LCD_lcd_kick();
	 
	 LCD_port &= 0x0f;
	 LCD_port |= ( character << 4 );
	 LCD_control |= ( 1 << RS_switch );
	 LCD_control &= ~( 1<< ReadWrite );
	 LCD_lcd_kick();
	 
 #endif
 
 }
 
 
 
 void LCD_Send_A_String(char *string)
 {
	 
	 int count = 0;
	 
	 while( *string > 0 )
	 {
		 count++;
		 LCD_Send_A_Character(*string++);
		 if( count == 16 )
		 {
			 LCD_GotoXY( 1, 0 );
		 }			 
		 else if( (count == 33) || (count == 32) )
		 {
			 LCD_clear_screen();
			 LCD_GotoXY( 0 , 0 );
			 count = 0;
		 }
	 }
	 
 }
 
 
 void LCD_clear_screen()
 {
	 LCD_Send_A_Command(LCD_CLEAR_SCREEN);
	 
	  
 }
 
 
 void LCD_GotoXY(unsigned char line, unsigned char position )
 {
	 
	 if( line == 0 )
	 {
		 if( position < 16 && position >= 0 )
			 LCD_Send_A_Command( 0x80 + position );
	 }
	 else if( line == 1 )
	 {
		 if( position<16 && position >=0 )
			 LCD_Send_A_Command( 0xc0 + position );
	 }
	 
 }
 
 
 
 void LCD_display_number (int Number )
 {
	 char str[7];
	 
	 sprintf(str ,"%d" ,Number );
	 
	 LCD_Send_A_String( str );
	 
 }
 
 
 void LCD_display_real_number (double  Number )
 {
	 str[16];
	 
	 
	 char *sign = ( Number < 0 ) ? "-" : "" ;
	 float val = ( Number < 0 ) ? -Number : Number;
	 
	 int num1 = val;
	 float frac = val - num ;
	 int num2 = frac * 10000;
	 
	 sprintf( str,"%s%d%.04d",sing,num1,num2 );
	 
	 LCD_Send_A_String(str);
	 
	 
 }