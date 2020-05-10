#include <Servo.h>
/* define a header file. Special attention here, you can call the servo function directly from Arduino's software menu  bar Sketch>Importlibrary>Servo, or input 
#include <Servo.h>. Make sure there is a space between #include and  <Servo.h>. Otherwise, it will cause compile error.*/
Servo myservo;// define servo variable name
void setup()
{
myservo.attach(9);// select servo pin(9 or 10)
}
void loop() {
  int i;
  i = 0;
  while(1){
    myservo.write(i);// set rotation angle of the motor
    if(i >= 0 && i < 170) {
      i = i + 10;
    } else {
      break;
      }
  
  delay(100);
    
  }

  while(1){
    myservo.write(i);// set rotation angle of the motor
    if(i < 0) {
      break;
    } else {
      i = i - 10;
      }
  delay(100);
    
  }
  
//  delay(100);
}
