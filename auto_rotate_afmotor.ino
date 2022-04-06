// code by JRC


#include <AFMotor.h>
AF_DCMotor motor1(1, MOTOR12_1KHZ); 
AF_DCMotor motor2(2, MOTOR12_1KHZ);
AF_DCMotor motor3(3, MOTOR34_1KHZ);
AF_DCMotor motor4(4, MOTOR34_1KHZ);


int Speed = 200;

int forward_time = 10000;
int turn_time = 2000;
int lengthtime = 1000;


int state = 0;


void setup(){ // put your setup code here, to run once

  motor1.setSpeed(Speed);
  motor2.setSpeed(Speed);
  motor3.setSpeed(Speed);
  motor4.setSpeed(Speed);

}


void loop(){  

forword();
delay(forward_time);
check();

}


void check()
{


  if (state ==0)
  {
    turnRight();
      delay(turn_time);
        forword();
         delay(lengthtime);
          turnRight();
           delay(turn_time);
            state = !state ;
  }
  
forword();
delay(forward_time);
 check();
  
if(state ==1){
    turnLeft();
     delay(turn_time);
       forword();
         delay(lengthtime);
           turnLeft();
             delay(turn_time);
              state = !state ;     
    }
  forword();
delay(forward_time);
 check();
  
}

void forword(){  //forword

    motor1.run(FORWARD);
    motor2.run(FORWARD);
    motor3.run(FORWARD);
    motor4.run(FORWARD);
 
}

void backword(){ //backword

    motor1.run(BACKWARD);
    motor2.run(BACKWARD);
    motor3.run(BACKWARD);
    motor4.run(BACKWARD);
 
}

void turnRight(){ //turnRight

    motor1.run(FORWARD);
    motor2.run(FORWARD);
    motor3.run(BACKWARD);
    motor4.run(BACKWARD);
  
}
void turnLeft(){ //turnLeft

    motor1.run(BACKWARD);
    motor2.run(BACKWARD);
    motor3.run(FORWARD);
    motor4.run(FORWARD);
}
void Stop(){ //stop

    motor1.run(RELEASE);
    motor2.run(RELEASE);
    motor3.run(RELEASE);
    motor4.run(RELEASE);
}
