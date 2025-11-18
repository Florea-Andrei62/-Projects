#include <Servo.h>


Servo front_back;
Servo up_down;
Servo rotate;
Servo gripper;

int front_backan=90;
int up_downan=90;
int rotatean=90;





void setup() {
  // put your setup code here, to run once:


  

Serial.begin(9600);


front_back.attach(9);
rotate.attach(10);
gripper.attach(11);
up_down.attach(6);

pinMode(2,INPUT_PULLUP);

}

void loop() {
  // put your main code here, to run repeatedly:


int x1=analogRead(A0);
int y1=analogRead(A1);



if(x1<400)
front_backan--;
else if(x1>600)
front_backan++;





if(y1<400)

rotatean--;
else if(y1>600)
rotatean++;




if(digitalRead(2)==LOW){
gripper.write(180);

}else{
  gripper.write(90);
}

  char m1 = Serial.read();   

    if (m1 == 'a') {
      up_downan--;                  
    }
    if (m1 == 'd') {
      up_downan++;                  
    }


  front_backan  = constrain(front_backan, 0, 180);
  up_downan  = constrain(up_downan, 0, 180);
  rotatean  = constrain(rotatean, 0, 180);

up_down.write(up_downan);
rotate.write(rotatean);
front_back.write(front_backan);


delay(15);

}



