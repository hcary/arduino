//led_growing
// Harvey Cary
// hdcary3@gmail.com
// https://github.com/hcary/arduino
// 8/2016

const int delay_time1   = 50;     // Delay time
const int delay_time2   = 10;     // Second delay time
const int blinkDelay    = 500;    // Blink delay
const int lowPin        = 5;      // Lowest pin used
const int highPin       = 12;     // Highest pin used
const int ledStart1     = 8;      // Middle low pin
const int ledStart2     = 9;      // Middlw high pin
const int interation    = 2;      // Number of times to loop through each sequence

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

  for(int j = 1; j <= interation; j = j + 1)
  {
    for(int j = lowPin; j <= highPin; j = j + 1)
    {
      glowOn(j);
    }
  
    delay(500);
  
    for(int j = lowPin; j <= highPin; j = j + 1)
    {
      glowOff(j);
    }
  }
  
  allOff();

  for(int j = 1; j <= interation; j = j + 1)
  {
    logToHigh();
  }

  allOff();
  
  for(int j = 1; j <= interation + 2; j = j + 1)
  {
    cylon();
  }

  allOff();

  for(int j = 1; j <= interation; j = j + 1)
  {
    highToLow();
  }

  for(int j = 1; j <= interation + 2; j = j + 1)
  {
    insideOut();
  }
  
  for(int j = 1; j <= interation; j = j + 1)
  {
    allOnOff();
  }
  
}
/*************************************************/

void setPinAnalog()
{

  for(int x = lowPin; x <= highPin; x = x + 1){
    pinMode(x,OUTPUT);
  } 
    
}

void cylon()
{

  Serial.print(" Cylon Loop  ");
  Serial.println(); 

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

void allOff()
{

  Serial.print(" Turn Off All LEDs  ");
  Serial.println(); 

  // Turn all LEDs off
  for(int x = lowPin; x <= highPin; x = x + 1)
  {
    pinSwitch(x, LOW, 0);
  }
    
}

void allOn()
{

  Serial.print(" Turn On All LEDs  ");
  Serial.println(); 

  // Turn all LEDs off
  for(int x = lowPin; x <= highPin; x = x + 1)
  {
    pinSwitch(x, HIGH, 0);
  }
    
}

void logToHigh()
{

  Serial.print(" Grow Loop  ");
  Serial.println();

  for(int x = lowPin; x <= highPin; x = x + 1){
    pinSwitch(x, HIGH, delay_time1);
  } 
  
  for(int x = highPin; x >= lowPin; x = x - 1){
    pinSwitch(x, LOW, delay_time1);
  } 
}

void highToLow()
{

  Serial.print(" Low to High  ");
  Serial.println();


  for(int x = highPin; x >= lowPin; x = x - 1){
    pinSwitch(x, HIGH, delay_time1);
  } 
  
  
  for(int x = lowPin; x <= highPin; x = x + 1){
    pinSwitch(x, LOW, delay_time1);
  } 
  
}

void allOnOff()
{

  //delay(blinkDelay);

  allOff();
  delay(blinkDelay);

  allOn();
  delay(blinkDelay);
  
}

void insideOut()
{

  Serial.print(" Inside Out ");
  Serial.println();
  
  int direction = 0;
  int led1 = ledStart1;
  int led2 = ledStart2;
  
  for(int x = 0; x <= 3; x = x + 1)
  {
    pinSwitch(led1, HIGH, delay_time1);
    pinSwitch(led2, HIGH, delay_time1);   
    led1 = led1 - 1;
    led2 = led2 + 1;
  }
    
  for(int x = 0; x <= 4; x = x + 1)
  {
  
    pinSwitch(led1, LOW, delay_time1);
    pinSwitch(led2, LOW, delay_time1);  
    led1 = led1 + 1;
    led2 = led2 - 1;      
  } // for(int x = 0; x <= 3; x = x + 1) 

}

void glowOn( int myPin )
{

  Serial.print(" Glow On ");
  Serial.print(myPin);
  Serial.println();
  
  for (int a=0; a<=255;a++)               //loop from 0 to 255
  {
    analogWrite(myPin, a);               // set the brightness of pin 9:
    delay(5);                             //wait for 8 ms            
  }

  //delay(800); 
}

void glowOff( int myPin )
{

  Serial.print(" Glow Off ");
  Serial.print(myPin);
  Serial.println();
  
  for (int a=255; a>=0;a--)             //loop from 255 down to 0
  {
    analogWrite(myPin, a);               // set the brightness of pin 9:
    delay(5);                             //wait for 8 ms  
  }
}





