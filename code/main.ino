#include <Servo.h>

Servo SAservo;
Servo SBservo;
Servo SCservo;
Servo SDservo;
Servo SEservo;

int Sa = 90;  // default Position
int Sb = 50;  //
int Sc = 40;  //
int Sd = 50;  //
int Se = 50;  //

int period = 1000;
int activite = -1;
unsigned long time_now = 0;
const int EMG = A4;             //set ECG sensor value
const int potentiometer = A5;   //the analog pin input of the potentiometer
unsigned long temps = 0;
int EMG_Value = 0;
int threshold = 0;

void setup() {
  SAservo.attach(8);   //index finger servo
  SBservo.attach(9);   //thumb servo
  SCservo.attach(10);  //ring finger servo
  SDservo.attach(11);  //middle servo
  SEservo.attach(12);  //little finger servo
  
  Serial.begin(115200); // open the serial port and set the baud rate to 9600
}

void loop() {

  time_now = millis();
  threshold = -analogRead(potentiometer);
  EMG_Value = -analogRead(EMG);
  
  Serial.print(EMG_Value);
  Serial.print(" ");
  Serial.println(threshold);
  delay(10);   

   if ((EMG_Value > threshold) && (activite == -1)) {  
    activite = millis();
    SAservo.write(140);
    SBservo.write(140);
    SCservo.write(140);
    SDservo.write(180);
    SEservo.write(140);    
   }
   else if (time_now >= activite + period) {
      activite = -1;
      SAservo.write(80);
      SBservo.write(80);
      SCservo.write(80);
      SDservo.write(60);
      SEservo.write(80);  
    }
}