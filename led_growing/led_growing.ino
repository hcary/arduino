//Blinking_LED
//turn on the LED for half a second,then off for half a second,repeatedly
//support@sunfounder.com
//www.sunfounder.com
//2015.5.7
/************************************************/
//const int p9 = 9;//the number of the LED pin 9
//const int p10 = 10;//the number of the LED pin 9
//const int p11 = 11;
//const int p12 = 12;

const int dtime = 50;
const int lowPin = 5;
const int highPin = 12;

/************************************************/
void setup()
{

  for(int x = lowPin; x <= highPin; x = x + 1){
    pinMode(x,OUTPUT);
  } 
  
}
/************************************************/
//the loop routine runs over and over again forever
void loop()
{

  for(int x = lowPin; x <= highPin; x = x + 1){
    pinOn(x, HIGH);
  } 

  for(int x = highPin; x >= lowPin; x = x - 1){
    pinOn(x, LOW);
  } 
  
}
/*************************************************/

void pinOn( int pinNum, int level )
{

  digitalWrite(pinNum, level);//turn the LED on
  delay(dtime);
  
}

