

#include <Servo.h>
#define MOTOR_PIN (9)
#define MOTOR_START_LIMIT (0) // all the way counter clockwise
#define MOTOR_END_LIMIT (162) // all the way clockwise
#define MOTOR_STEP_SIZE (21)

#define MOTOR_READ_PIN (A0)

#define BUTTON1 (13)
#define BUTTON2 (2)
#define BUTTON_PRESSED (HIGH)

#define LIGHTLEN (9)

const int lights[] = {3,4,5,6,7,8,10,11,12};


Servo motor;
int motorAngle;

void startupSequence();
void waitButtons();
void lightShow();
void dropNextMatch();
void lightWrite();
void turnOffLights();
void deniedLights();

// we go counter clockwise
bool endReached = false;
int match_count = 0;
int current_angle;

void setup() {
  motor.attach(MOTOR_PIN);
  Serial.begin(9600);

  pinMode(BUTTON1, INPUT);
  pinMode(BUTTON2, INPUT);

  for( int i = 0; i <= LIGHTLEN; i++)
    pinMode(lights[i], OUTPUT);

  delay(2000);
  startupSequence();
  delay(2000);
  
}

void loop() {

  waitButtons();
  delay(1000);
  lightShow();
  delay(1000);
  if (random(0,8) ==4 )
    dropNextMatch();
  else
    deniedLights();
  delay(2000);
  turnOffLights();
}

void startupSequence()
{
  motor.write(MOTOR_START_LIMIT);
}

void waitButtons()
{
  while (digitalRead(BUTTON1) != BUTTON_PRESSED && digitalRead(BUTTON2) != BUTTON_PRESSED);
    delay(2000);
  while(true)
  {
   if(digitalRead(BUTTON1) != BUTTON_PRESSED && digitalRead(BUTTON2) != BUTTON_PRESSED)
    return;
  }
}

void dropNextMatch()
{
    if ( match_count == 0)
    {
      motor.write(MOTOR_START_LIMIT);
      current_angle = MOTOR_START_LIMIT;
 
      delay(100);
    }

    if( match_count < 8)
    {
      current_angle += MOTOR_STEP_SIZE;
      motor.write(current_angle);
      match_count++;
    }
    
    if (match_count == 8)
    {
      // we just did the last one, now lets move to the start pos
      motor.write(MOTOR_START_LIMIT);
      match_count = 0;

    }
}

void lightShow()
{
  for( int j = 0; j < 20; j++)
  {
    for ( int i = 0; i < 20; i++)
      {
      lightWrite(i, HIGH);
      delay(20);
    }

    for ( int i = 0; i < 20; i++)
    {
      lightWrite(i, LOW);
      delay(20);
    }
  }

  lightWrite(0, HIGH);
  lightWrite(1, HIGH);
  lightWrite(2, HIGH);
  lightWrite(3, HIGH);
  lightWrite(4, HIGH);
  lightWrite(5, HIGH);
  lightWrite(6, HIGH);
  lightWrite(7, HIGH);
  lightWrite(8, HIGH);

  delay(500);

  lightWrite(0, LOW);
  lightWrite(1, LOW);
  lightWrite(2, LOW);
  lightWrite(3, LOW);
  lightWrite(4, LOW);
  lightWrite(5, LOW);
  lightWrite(6, LOW);
  lightWrite(7, LOW);
  lightWrite(8, LOW);

  delay(500);

    lightWrite(0, HIGH);
  lightWrite(1, HIGH);
  lightWrite(2, HIGH);
  lightWrite(3, HIGH);
  lightWrite(4, HIGH);
  lightWrite(5, HIGH);
  lightWrite(6, HIGH);
  lightWrite(7, HIGH);
  lightWrite(8, HIGH);

  delay(500);

  lightWrite(0, LOW);
  lightWrite(1, LOW);
  lightWrite(2, LOW);
  lightWrite(3, LOW);
  lightWrite(4, LOW);
  lightWrite(5, LOW);
  lightWrite(6, LOW);
  lightWrite(7, LOW);
  lightWrite(8, LOW);

  delay(500);
  
  lightWrite(0, HIGH);
  lightWrite(1, HIGH);
  lightWrite(2, HIGH);
  lightWrite(3, HIGH);
  lightWrite(4, HIGH);
  lightWrite(5, HIGH);
  lightWrite(6, HIGH);
  lightWrite(7, HIGH);
  lightWrite(8, HIGH);

  delay(500);

  lightWrite(0, LOW);
  lightWrite(1, LOW);
  lightWrite(2, LOW);
  lightWrite(3, LOW);
  lightWrite(4, LOW);
  lightWrite(5, LOW);
  lightWrite(6, LOW);
  lightWrite(7, LOW);
  lightWrite(8, LOW);

  delay(500);

  
  lightWrite(0, HIGH);
  lightWrite(1, HIGH);
  lightWrite(2, HIGH);
  lightWrite(3, HIGH);
  lightWrite(4, HIGH);
  lightWrite(5, HIGH);
  lightWrite(6, HIGH);
  lightWrite(7, HIGH);
  lightWrite(8, HIGH);
}

void lightWrite( int index, int val)
{
  digitalWrite(lights[index], val);
}

void turnOffLights()
{
    lightWrite(0, LOW);
  lightWrite(1, LOW);
  lightWrite(2, LOW);
  lightWrite(3, LOW);
  lightWrite(4, LOW);
  lightWrite(5, LOW);
  lightWrite(6, LOW);
  lightWrite(7, LOW);
  lightWrite(8, LOW);
}

void deniedLights()
{
  lightWrite(0, LOW);
  lightWrite(1, HIGH);
  lightWrite(2, LOW);
  lightWrite(3, HIGH);
  lightWrite(4, LOW);
  lightWrite(5, HIGH);
  lightWrite(6, LOW);
  lightWrite(7, HIGH);
  lightWrite(8, LOW);
}
