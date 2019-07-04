//led_growing
// Harvey Cary
// hdcary3@gmail.com
// https://github.com/hcary/arduino
// 8/2016

const int delay_time1 = 50;     // Delay time
const int delay_time2 = 30;
const int lowPin = 5;     // Lowest pin used
const int highPin = 12;   // Highest pin used

/************************************************/
void setup()
{

  Serial.begin(9600);  
  // Loop from lowest pin to highest pin setting pin mode
  for(int x = lowPin; x <= highPin; x = x + 1){
    pinMode(x,OUTPUT);
  } 
  
}
/************************************************/
//the loop routine runs over and over again forever
void loop()
{

  for(int j = 0; j <= 5; j = j + 1){
    for(int x = lowPin; x <= highPin; x = x + 1){
      pinSwitch(x, HIGH, delay_time1);
    } 
  
    for(int x = highPin; x >= lowPin; x = x - 1){
      pinSwitch(x, LOW, delay_time1);
    } 
  }

  for(int j = 0; j <= 5; j = j + 1){

    for(int x = lowPin; x <= highPin; x = x + 1){
      pinSwitch(x, HIGH, delay_time2);
      if( x < highPin ) 
      {
        pinSwitch(x, LOW, delay_time2);
      } 
    } 
  
    pinSwitch(highPin, HIGH, delay_time1);
    
    for(int x = highPin; x >= lowPin; x = x - 1){
      pinSwitch(x, HIGH, delay_time2);
      if( x > lowPin ) 
      {
        pinSwitch(x, LOW, delay_time2);
      }
      
    
    } 
  
    pinSwitch(lowPin, HIGH, delay_time2);
  
  }

  for(int j = 0; j <= 5; j = j + 1){
    Serial.print(j, 2);
    Serial.println();
    for(int x = highPin; x <= lowPin; x = x - 1){
        pinSwitch(x, LOW, 0);
    }
    
    for(int x = highPin; x <= lowPin; x = x - 1){
      Serial.print(x,2);
      pinSwitch(x, HIGH, delay_time1);
      if( x > lowPin ) 
      {
        pinSwitch(x, LOW, delay_time1);
        Serial.print(" LED OFF");
      } 
    } 
  
    pinSwitch(lowPin, HIGH, delay_time1);
    
    for(int x = lowPin; x >= highPin; x = x + 1){
      pinSwitch(x, HIGH, delay_time1);
      if( x < highPin ) 
      {
        pinSwitch(x, LOW, delay_time1);
      }
      
    
    } 
  
    pinSwitch(highPin, HIGH, delay_time1);
  
  }

}
/*************************************************/

void pinSwitch( int pinNum, int level, int myDelay )
{

  digitalWrite(pinNum, level);//turn the LED on
  delay(myDelay);
  
}

