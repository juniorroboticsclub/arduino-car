#include <SoftwareSerial.h>
SoftwareSerial BT_Serial(2, 3); // RX, TX


#include <AFMotor.h>
AF_DCMotor motor1(1);
AF_DCMotor motor2(2);
AF_DCMotor motor3(3);
AF_DCMotor motor4(4);

int Speed = 90;
int cutter = A0;
   
int bt_ir_data; // variable to receive data from the serial port and IRremote

void setup(){ // put your setup code here, to run once

  motor1.setSpeed(Speed);
  motor2.setSpeed(Speed);
  motor3.setSpeed(Speed);
  motor4.setSpeed(Speed);

Serial.begin(9600); // start serial communication at 9600bps
BT_Serial.begin(9600); 
   
   pinMode(cutter,OUTPUT);
   digitalWrite(cutter, LOW);

}


void loop(){  

if(BT_Serial.available() > 0){  //if some date is sent, reads it and saves in state     
bt_ir_data = BT_Serial.read(); 
Serial.println(bt_ir_data);          
}


     if(bt_ir_data == 1){forword(); }  // if the bt_data is '1' the DC motor will go forward
else if(bt_ir_data == 2){backword();}  // if the bt_data is '2' the motor will Reverse
else if(bt_ir_data == 3){turnLeft();}  // if the bt_data is '3' the motor will turn left
else if(bt_ir_data == 4){turnRight();} // if the bt_data is '4' the motor will turn right
else if(bt_ir_data == 5){Stop(); }     // if the bt_data '5' the motor will Stop
else if(bt_ir_data == 9){digitalWrite(cutter, HIGH);} //cutter on  LF pressed 
else if(bt_ir_data ==10){digitalWrite(cutter, LOW);} //cutter off  OA pressed 

delay(10);
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
