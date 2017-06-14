int trig1Pin =7;         //define the ultra sensor pins 

int echo1Pin =8;

int trig2Pin =9;

int echo2Pin =10;
 
int motorpin1 = 3;                  //define digital output pin no.

int motorpin2 = 4;                  //define digital output pin no.

int motorpin3 = 5;

int motorpin4 = 6;

int ir1=A0;//IR sensor pin (analog)

int ir2=A1;

int value1=0;//set the value of IR input as 0

int value2=0;

long duration, inches, cm;//for ultra time measurement 


void setup()
{
 Serial.begin(9600);   // initialize the data rate in bits per second

 pinMode(motorpin1,OUTPUT); //set the motor pin as output
 pinMode(motorpin2,OUTPUT); 
 pinMode(motorpin3,OUTPUT); 
 pinMode(motorpin4,OUTPUT); 


 pinMode(ir1,INPUT);
 pinMode(ir2,INPUT);
  
}



/*void ultra2()//calling for second sensor

{
 pinMode(trig2Pin,OUTPUT);    //  
 digitalWrite(trig2Pin,LOW);
 delayMicroseconds(2);       // delay recomended from datasheet
 digitalWrite(trig2Pin,HIGH);
 delayMicroseconds(5);       // delay recomended from datasheet
 digitalWrite(trig2Pin,LOW);
 pinMode(echo2Pin,INPUT);
 duration =pulseIn(echo2Pin,HIGH);
 
 inches = microsecondsToInches(duration); // converting time into distance
 cm = microsecondsToCentimeters(duration);
  
}*/

void forward()//moving the motor forward
{
  
 digitalWrite(motorpin1,HIGH);

 digitalWrite(motorpin2,LOW);

 digitalWrite(motorpin3, HIGH);

 digitalWrite(motorpin4, LOW);

}

void stoped()//stop the motor
{
  
 digitalWrite(motorpin1,LOW);

 digitalWrite(motorpin2,LOW);

 digitalWrite(motorpin3, LOW);

 digitalWrite(motorpin4, LOW);

}

void reverse()//moving the motor reverse
{
  
 digitalWrite(motorpin1,LOW);

 digitalWrite(motorpin2,HIGH);

 digitalWrite(motorpin3, LOW);

 digitalWrite(motorpin4, HIGH);

}




void loop()         // function which will run continuously
{
    
    
    forward();
 
pinMode(trig1Pin,OUTPUT);    //  
 digitalWrite(trig1Pin,LOW);
 delayMicroseconds(2);       // delay recomended from datasheet
 digitalWrite(trig1Pin,HIGH);
 delayMicroseconds(5);       // delay recomended from datasheet
 digitalWrite(trig1Pin,LOW);
 pinMode(echo1Pin,INPUT);
 duration =pulseIn(echo1Pin,HIGH);
 
 inches = microsecondsToInches(duration); // converting time into distance
 cm = microsecondsToCentimeters(duration);

/*delay(100);
{

  if (inches <= 2) // if there is an obstacle at 15 inches or belowjdsjdsjdklsjdlksjdi
{

  stoped();
  delay(5000);
}
}
  forward();  
}*/
 
 
 value1=analogRead(ir1);
 value2=analogRead(ir2);

 Serial.println("the value of sensor =");
 Serial.print(value1);
 
  delay(10);
 
 Serial.println(inches);
 Serial.print("in, ");
 Serial.print(cm);
 Serial.print("cm");
 Serial.println();
  


 if (value1<300)//caliberate it for the ir reading ,vnsjvsdjvsdjdkddodlamlaja
 {
   stoped();//reverse mechanism 
  delay(100);
  reverse();
  
   //ultra2();

   //ultramov();
  

  
  
  
  
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

