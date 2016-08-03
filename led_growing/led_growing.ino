//led_growing
// Harvey Cary
// hdcary3@gmail.com
// 8/2016

const int dtime = 50;     // Delay time
const int lowPin = 5;     // Lowest pin used
const int highPin = 12;   // Highest pin used

/************************************************/
void setup()
{

  // Loop from lowest pin to highest pin setting pin mode
  for(int x = lowPin; x <= highPin; x = x + 1){
    pinMode(x,OUTPUT);
  } 
  
}
/************************************************/
//the loop routine runs over and over again forever
void loop()
{

  for(int x = lowPin; x <= highPin; x = x + 1){
    pinSwitch(x, HIGH);
  } 

  for(int x = highPin; x >= lowPin; x = x - 1){
    pinSwitch(x, LOW);
  } 
  
}
/*************************************************/

void pinSwitch( int pinNum, int level )
{

  digitalWrite(pinNum, level);//turn the LED on
  delay(dtime);
  
}

