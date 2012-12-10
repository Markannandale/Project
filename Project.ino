//==========================================================================
//	Author		    : CYTRON TECHNOLOGIES SDN BHD (Modified by rbigelow)
//	Program description : This program demonstrates how to display text to the LCD screen and read data from the 5 push buttons. 
//==========================================================================
/* The circuit uses the following pins:
 * LCD RS pin to digital pin 8
 * LCD Enable pin to digital pin 9
 * LCD D4 pin to digital pin 4
 * LCD D5 pin to digital pin 5
 * LCD D6 pin to digital pin 6
 * LCD D7 pin to digital pin 7
 * LCD R/W pin to ground
*/

#include <LiquidCrystal.h>

//Define the pins that are used by the LCD.
LiquidCrystal lcd(8, 9, 4, 5, 6, 7);  

int analogPin = A0;  //Analog 0 input is used by the push buttons. 
int adc_key_old;
int adc_key_in;
int NUM_KEYS = 5;
int key=-1;
int adc_key_val[5] ={30, 150, 360, 535, 760 };  //Each push button returns a different value. 
  
char msgs[5][15] = {"Yes          ",   //This stores the 5 messages that are displaye
                    "No           ",
                    "Absolutly    ",
                    "Maybe        ",
                    "Uncertain    "};
                    
void setup ()
{
  Serial.begin(9600);
  lcd.begin(16, 2);                         // set the lcd dimension
  lcd.clear();                              // LCD screen clear
  lcd.print("Georgian College");              // display text
  lcd.setCursor(0,1);                       // set lcd.setCursor  position (column,row) 
  lcd.print("Computer Studies");    
  delay(3000);                              // delay for 3000ms
  lcd.clear();                              //Clear the screen
  lcd.setCursor(0,0);                       //Set the cursor back at the start (Will over-write perviously displayed text)
  lcd.print("Hello COMP1045");              // display text
  lcd.setCursor(0,1);                       //Set the cursor position at the start of the second row.
   
}

void loop()
{
  adc_key_in = analogRead(analogPin);     // read ADC value
  //adc_key_in = get_key(adc_key_in);
  lcd.setCursor(0, 0); 
 Serial.println(adc_key_in); 
  if(adc_key_in == 0)                    //Sets board to take input from only the right button
  {
  lcd.print(msgs[random(5)] );           //Chooses a random message and displays it
  delay(5000);  //display message key
  }else{
    lcd.print("         ");
}
}
 
