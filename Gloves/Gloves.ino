//Transmitter Code (Glove) - Mert Arduino and Tech

#include <SPI.h>                      //the communication interface with the modem
#include <RF24.h>                     //the library which helps us to control the radio modem

int msg[3]; //Total number of data to be sent (data package)

//define the flex sensor input pins
int flex_5 = A5;  
int flex_3 = A3;
int flex_1 = A1;

//define variables for flex sensor values
int flex_5_val;
int flex_3_val;
int flex_1_val;

RF24 radio(9,10);                     //9 and 10 are a digital pin numbers to which signals CE and CSN are connected.
                                      
const uint64_t pipe = 0xE8E8F0F0E1LL; //the address of the modem, that will receive data from Arduino.


void setup(void){
  Serial.begin(9600);
  radio.begin();                      //it activates the modem.
  radio.openWritingPipe(pipe);        //sets the address of the receiver to which the program will send data.
}

void loop(void){

  flex_5_val = analogRead(flex_5); 
  flex_5_val = map(flex_5_val, 122, 177, 0, 180); //in the middle the middle right 4
 
  flex_3_val = analogRead(flex_3);
  flex_3_val = map(flex_3_val, 177, 204, 180, 0); //left of the middle 2 thumb with lift of the middle
  
  flex_1_val = analogRead(flex_1);
  flex_1_val = map(flex_1_val, 180, 200, 0, 175); //little 
  
  msg[0] = flex_5_val;
  msg[2] = flex_3_val;
  msg[4] = flex_1_val;
  radio.write(msg, sizeof(msg));
}
