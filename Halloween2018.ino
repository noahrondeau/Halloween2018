

#include <Servo.h>
#define MOTOR_PIN (9)
#define MOTOR_START_LIMIT (150) // all the way counter clockwise
#define MOTOR_END_LIMIT (5) // all the way clockwise
#define MOTOR_STEP_SIZE (20)

#define BUTTON1 (2)
#define BUTTON2 (3)
#define BUTTON_PRESSED (1)


Servo motor;
int motorAngle;

void startupSequence();
void waitButtons();
void lightShow();
void dropNextMatch();

// we go clockwise
bool endReached = false;
int match_count = 0;
int current_angle;




void setup() {
  motor.attach(MOTOR_PIN);
  Serial.begin(9600);

  pinMode(BUTTON1, INPUT);
  pinMode(BUTTON2, INPUT);

  delay(2000);
  startupSequence();
  delay(2000);
  
}

void loop() {
  Serial.print("Motor Angle: ")
  Serial.println(angle);

  waitButtons();
  delay(1000);
  lightShow();
  delay(1000);
  dropNextMatch();
}

void startupSequence()
{
  // nothing now
}

void waitButtons()
{
   
}

void dropNextMatch();
{
  if (!endReached)
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
    
    if (match_count == 8)
    {
      // we just did the last one, now lets move to the start pos
      motor.write(MOTOR_START_LIMIT);
      
    }
  }
}
