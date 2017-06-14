
 int trig1pin =8;
                  //define digital output pin no.
 int echo1pin =7;                 

long duration, inches, cm;

void setup()    // function which runs once
{
 Serial.begin(9600);   // initialize the data rate in bits per second



}
void a()
{
  //  function from datasheet of ping sensor
 pinMode(trig1pin,OUTPUT);    //  
 digitalWrite(trig1pin,LOW);
 delayMicroseconds(2);       // delay recomended from datasheet
 digitalWrite(trig1pin,HIGH);
 delayMicroseconds(5);       // delay recomended from datasheet
 digitalWrite(trig1pin,LOW);
 pinMode(echo1pin,INPUT);
 duration =pulseIn(echo1pin,HIGH);
 
 inches = microsecondsToInches(duration); // converting time into distance
 cm = microsecondsToCentimeters(duration);
   
}
void loop()         // function which will run continuously
{
  a();
 Serial.print(inches);
 Serial.print("in, ");
 Serial.print(cm);
 Serial.print("cm");
 Serial.println();
  
 delay(100);
{

  //if (inches <= 2) // if there is an obstacle at 15 inches or below
{

  /*digitalWrite(motorpin1,LOW);

 digitalWrite(motorpin2,LOW);

 digitalWrite(motorpin3, LOW);

 digitalWrite(motorpin4, LOW);*/



  /*for(pos = 0; pos < 180; pos += 1)  // goes from 0 degrees to 180 degrees
 {                                  // in steps of 1 degree
   myservo.write(pos);              // tell servo to go to position in variable 'pos'
   delay(15);                       // waits 15ms for the servo to reach the position
 }
 for(pos = 180; pos>=1; pos-=1)     // goes from 180 degrees to 0 degrees
 {                                
   myservo.write(pos);              // tell servo to go to position in variable 'pos'
   delay(15);  
 }*/
}

 //else                      
{
 
 /*digitalWrite(motorpin1,LOW);

 digitalWrite(motorpin2,HIGH);

 digitalWrite(motorpin3,HIGH);

 digitalWrite(motorpin4,LOW);*/  
   }
 }
}

long microsecondsToInches(long microseconds)

{

 return microseconds / 74 / 2;  

}

long microsecondsToCentimeters(long microseconds)
{
 return microseconds / 29 / 2;
}

