int motorpin1 = 3;                  //define digital output pin no.

int motorpin2 = 4;                  //define digital output pin no.

int motorpin3 = 5;

int motorpin4 = 6;

long duration, inches, cm; 


void setup()
{
 Serial.begin(9600);   // initialize the data rate in bits per second

 pinMode(motorpin1,OUTPUT); //set the motor pin as output
 pinMode(motorpin2,OUTPUT); 
 pinMode(motorpin3,OUTPUT); 
 pinMode(motorpin4,OUTPUT); 
  
}

void a()
{
  
digitalWrite(motorpin1,LOW);

 digitalWrite(motorpin2,HIGH);

 digitalWrite(motorpin3, LOW);

 digitalWrite(motorpin4, HIGH);
  
}

void loop()
{
/* digitalWrite(motorpin1,HIGH);

 digitalWrite(motorpin2,LOW);

 digitalWrite(motorpin3, HIGH);

 digitalWrite(motorpin4, LOW);*/

 delay(10);
 a();


 
  
}


