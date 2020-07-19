#include <Servo.h>

Servo serX;
Servo serY;

String serialData;

//ardiono needs to interpret commands in Cshapr
void setup() {
  serX.attach(10);//Pin 10 of the arduino
  serY.attach(11);//Pin 11 of arduino
  Serial.begin(9600);//Default Rate
  Serial.setTimeout(10);
  
}

void loop() {
  //We aren't using a loop, but arduino requires it
  //We want to use event listeners
}

void SerialEvent(){
  serialData = Serial.readString();

  serX.write(parseDataX(serialData));
  serY.write(parseDataY(serialData));
}

int parseDataX(String data){
  data.remove(data.indexOf("Y"));//Removes string after this point "Why?" -> "Wh"
  data.remove(data.indexOf("X"), 1);

  return data.toInt();
}


int parseDataY(String data){
  data.remove(0, data.indexOf("Y")+1);

  return data.toInt();
}
