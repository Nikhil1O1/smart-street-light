int ir1 = A1;
int ir2 = A2;

int ldr = A5;

int led1 = 2;                 //Assigining master and slave units
int led11 = 3;
int led12 = 4;
int led13 = 5;
int led2 = 8;
int led21 = 9;
int led22 = 10;
int led23 = 11;

int irstat1 = 0;
int irstat2 = 0;



void setup()
{

  Serial.begin (9600);

  pinMode(ir1, INPUT);
  pinMode(ir2, INPUT);


  pinMode (ldr, INPUT);


  pinMode(led1, OUTPUT);
  pinMode(led11, OUTPUT);
  pinMode(led12, OUTPUT);
  pinMode(led13, OUTPUT);
  pinMode(led2, OUTPUT);
  pinMode(led21, OUTPUT);
  pinMode(led22, OUTPUT);
  pinMode(led23, OUTPUT);


}


void loop() {


  Serial.println(analogRead(A5));
  int ldrStatus = analogRead (ldr);
  if (ldrStatus <= 500)
  {
    digitalWrite(led1, HIGH);
    digitalWrite(led11, HIGH);
    digitalWrite(led12, HIGH);
    digitalWrite(led13, HIGH);


    digitalWrite(led2, HIGH);
    digitalWrite(led21, HIGH);
    digitalWrite(led22, HIGH);
    digitalWrite(led23, HIGH);


    irstat1 = digitalRead(ir1);
    irstat2 = digitalRead(ir2);


    if (ldrStatus <= 500)
    {
      digitalWrite(led1, HIGH);
      digitalWrite(led11, HIGH);
      digitalWrite(led12, HIGH);
      digitalWrite(led13, HIGH);

    }
    else
    {
      digitalWrite(led1, LOW);
      digitalWrite(led11, LOW);
      digitalWrite(led12, LOW);
      digitalWrite(led13, LOW);
    }
    if (ldrStatus <= 500)
    {
      digitalWrite(led2, HIGH);
      digitalWrite(led21, HIGH);
      digitalWrite(led22, HIGH);
      digitalWrite(led23, HIGH);
    
    }
    else
    {
      digitalWrite(led2, LOW);
      digitalWrite(led21, LOW);
      digitalWrite(led22, LOW);
      digitalWrite(led23, LOW);

    }


  }
  else                            //TO KEEP LIGHTS OFF IF AMBIENT LIGHT HIGH
  {
      
      digitalWrite(led1, LOW);
      digitalWrite(led11, LOW);
      digitalWrite(led12, LOW);
      digitalWrite(led13, LOW);
      digitalWrite(led2, LOW);
      digitalWrite(led21, LOW);
      digitalWrite(led22, LOW);
      digitalWrite(led23, LOW);

  }


}
