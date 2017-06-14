int trig1Pin =7;         //define the ultra sensor pins 

int echo1Pin =8;

int trig2Pin =9;

int echo2Pin =10;
 
int motorpin1 = 1;                  //define digital output pin no.

int motorpin2 = 4;                  //define digital output pin no.

int motorpin3 = 12;

int motorpin4 =13;

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
void ultra1() // calling ultra 1
 
{
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

                     Serial.println(inches);
                     Serial.print("in1, ");
                     Serial.print(cm);
                     Serial.print("cm1");
                     Serial.println();
        
         delay(100);
            {
            
              if (inches <= 2) // if there is an obstacle at 15 inches or belowjdsjdsjdklsjdlksjdi
            {
            
               stoped();
              delay(500);
            }
            }
        
           forward();

          
    }

void ultra2() //calling ultra sonic 2

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
  
             Serial.println(inches);
             Serial.print("in2, ");
             Serial.print(cm);
             Serial.print("cm2");
             Serial.println();
   
  delay(100);
      {
      
        if (inches <= 2) // if there is an obstacle at 15 inches or belowjdsjdsjdklsjdlksjdi
      {
      
        stoped();
        delay(500);
      }
  }
  
       reverse();

 }

 
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
   ultra1();

   value1=analogRead(ir1);

     
     Serial.println("the value of sensor =");
     Serial.print(value1);
        

   if (value1<100)

   {

    void stoped();//reverse mechanism
        
   for( ; ; )
  
   {
      
      value2=analogRead(ir2);
    
  
     Serial.println("the value of sensor 2=");
     Serial.print(value1);
        
      

     digitalWrite(trig1Pin,LOW);//switch off the ultra 1

     ultra2();
     
     delay(1000);
     
     void reverse();

     if (value2>1000)
     
     {

             void stoped();//forward mechanism 
      
             digitalWrite(trig2Pin,LOW);//switch off the ultra 1
      
             Serial.println("the value of sensor =");
             Serial.print(value2);
  
      
      break;
      }
    
   
   }

   }
         

 
  delay(100);
 
 /*Serial.print(inches);
 Serial.print("in, ");
 Serial.print(cm);
 Serial.print("cm");
 Serial.println();*/
  



}

long microsecondsToInches(long microseconds)

{

 return microseconds / 74 / 2;  

}

long microsecondsToCentimeters(long microseconds)
{
 return microseconds / 29 / 2;
}

