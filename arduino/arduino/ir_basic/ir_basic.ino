int analogPin = 3;     // Infrared Sensor (Right lead) connected to analog pin 3
                                    // outside leads to ground and +5V
int val;                  // variable to store the value read

void setup()
{
  Serial.begin(9600);          //  setup serial
}

void loop()
{
  val = analogRead(analogPin);    // read the input pin
  Serial.println(val);  // debug value
  delay(100);
  
} 
