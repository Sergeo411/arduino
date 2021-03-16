import controlP5.*;
import processing.serial.*;
Serial port;
String received;
ControlP5 cp5;
float f1;
//float f2;
PFont font;
PImage img1;
PImage img2;
int k;
void setup() {
  img1 = loadImage("on1.png");
  img2 = loadImage("off1.png");
  size(330, 450);
  surface.setTitle("Температурка");

  printArray(Serial.list());
  port = new Serial(this, "COM3", 9600);
  port.bufferUntil('\n');
  cp5 = new ControlP5(this);
  font = createFont("calibri light bold", 20);



  cp5.addButton("Press")
    .setPosition(105, 350)
    .setSize(120, 70)
    .setFont(font)
    .setColorBackground(color(22, 255, 0)) //цвет обычно
    .setColorForeground(color(2, 217, 235)); // цвет при наведении
}


void draw() {
  background(39, 39, 39);
  if ( port.available() > 0) { // если есть данные,
    // считываем их и записываем в переменную received
  }

k=round(255*((f1-10)/30));
if ( (f1>=10) && (f1<=40)){
  fill(k,0,255-k);
} else {

  fill(255, 0, 0);
}  
  textFont(font);
  if (received != null) {
    text(received, 135, 300);
  }


  if (f1>27) {
    image(img1, 110, 10);
  } else {
    image(img2, 110, 10);
  }
}
void serialEvent(Serial port) {
  received = port.readStringUntil('\n');
  f1=float(received);
}
void Press() {
  port.write('y');
}
