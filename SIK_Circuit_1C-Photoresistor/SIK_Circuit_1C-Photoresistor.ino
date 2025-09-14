/*
  SparkFun Inventor’s Kit
  Circuit 1C-Photoresistor

  Use a photoresistor to monitor how bright a room is, and turn an LED on when it gets dark.

  This sketch was written by SparkFun Electronics, with lots of help from the Arduino community.
  This code is completely free for any use.

  View circuit diagram and instructions at: https://learn.sparkfun.com/tutorials/sparkfun-inventors-kit-experiment-guide---v41
  Download drawings and code at: https://github.com/sparkfun/SIK-Guide-Code

  Notes: According to page 26, as more light shines on the photoresister, so its resistance decreases.
  Therefore assigning a value "photoresister" which decreases as it gets darker is confusing nomenclature - actually the voltage at A0 decreases
  as the photoresister's resinstance increases.
  
  Also confusing on page 26 is the photoresister is referred to as R2, when according to the hookup guide it is installed at the postive voltage
  end of the divider and the fixed resitor at the negative end. Normal convention is the postive end resister is referred to as R1.

  The circuit and code combination work, since as more light shines, so the resistance of the photoresister decreases and voltage out of the 
  divider read at A0 increases, to a maximum ~1018 with a phone LED placed on top  ( so near zero. )

  With the light off and finger placed over the photoresister and paper between the LED and photoresitor, voltage read at A0 according to 10 bit ADC falls
  to minimum value ~16, indicating resistance in dark must be much greater than the 10K ohm fixed resister.
*/

int photoresistor = 0;              //this variable will hold a value based on the brightness of the ambient light
int threshold = 750;                //if the photoresistor reading is below this value the the light will turn on

void setup()
{
  Serial.begin(9600);               //start a serial connection with the computer

  pinMode(13, OUTPUT);              //set pin 13 as an output that can be set to HIGH or LOW
}

void loop()
{
  //read the brightness of the ambient light
  photoresistor = analogRead(A0);   //set photoresistor to a number between 0 and 1023 based on how bright the ambient light is
  Serial.println(photoresistor);    //print the value of photoresistor in the serial monitor on the computer

  //if the photoresistor value is below the threshold turn the light on, otherwise turn it off
  if (photoresistor < threshold) {
    digitalWrite(13, HIGH);         // Turn on the LED
  } else {
    digitalWrite(13, LOW);          // Turn off the LED
  }

  delay(100);                       //short delay to make the printout easier to read
}

