int trigPin = 7;
int echoPin = 8;
int trigPin1 = 2;
int echoPin1 = 4;
int led = 11;
int led1 = 9;
int ldr = A5;
int vs =9; // vibration sensor


void setup() {
  Serial.begin(9600); 
  pinMode(led, OUTPUT);
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(led1, OUTPUT);
  pinMode(trigPin1, OUTPUT);
  pinMode(echoPin1, INPUT);
  pinMode(vs, INPUT); 
  pinMode(ldr, INPUT);
  // put your setup code here, to run once:

}

void loop() {
  long duration, distance, duration1, distance1;  // initializing all mathematical varialbes...
  digitalWrite(trigPin,HIGH);
  delayMicroseconds(1000);
  digitalWrite(trigPin, LOW);
  duration=pulseIn(echoPin, HIGH);
  distance =(duration/2)/29.1;                    //calculating distance for first sonar
  digitalWrite(trigPin1,HIGH);
  delayMicroseconds(1000);
  digitalWrite(trigPin1, LOW);
  duration1=pulseIn(echoPin1, HIGH);
  distance1 =(duration1/2)/29.1;                  //calculating distance for second sonar
  Serial.print(distance);
  Serial.println("CM");
  Serial.print(distance1);
  Serial.println("CM");
  delay(10);
  int ldrStatus = analogRead (ldr);  
  long measurement =vibration();
  delay(50);
  Serial.println(measurement);              
  if (ldrStatus <= 500)
  {
       if((distance<=60 && distance>=1)) 
       {
          analogWrite(led, 255);
          delay(5000);
          analogWrite(led, 10);
          
       }
         else if(distance>60)
       {
           analogWrite(led, 10); 
       }
       if((distance1<=60 && distance1>=1)) 
       {
          analogWrite(led1, 255);
          delay(5000);
          analogWrite(led1, 10);
          
       }
         else if(distance1>60)
       {
           analogWrite(led1, 10); 
       }
  }
  else 
  {
    analogWrite(led, 0);
    analogWrite(led1, 0);
  }
}


// defining useless function

long vibration()
{

  long measurement=pulseIn (vs, HIGH);  //wait for the pin to get HIGH and returns measurement

  return measurement;

}