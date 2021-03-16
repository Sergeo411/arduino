#include <OneWire.h>
#include <LiquidCrystal_I2C.h>

OneWire ds(2);
int PIN_BUTTON = 4;
boolean l=HIGH;
boolean c;
int i=0;
int p=0;
int k;
unsigned long timing;
unsigned long timing1;
LiquidCrystal_I2C lcd(0x27,16,2);
void setup(){
  pinMode(12, OUTPUT);
  pinMode(A0, INPUT);
  lcd.init(); 
  lcd.backlight();
 /* pinMode(11, OUTPUT);
  pinMode(10, OUTPUT);*/
  Serial.begin(9600);
}

void loop(){
  k=analogRead(A0);
  k=round(1500*(k/1023))+500;
 if (i%2==1){
  byte data[2];
  ds.reset(); 
  ds.write(0xCC); 
  ds.write(0x44); 
  if (millis() - timing1 > k){
      timing1 = millis(); 
  ds.reset();
  ds.write(0xCC); 
  ds.write(0xBE); 
  data[0] = ds.read();
  data[1] = ds.read();}
  float temperature =  ((data[1] << 8) | data[0]) * 0.0625;

  // Выводим полученное значение температуры в монитор порта
  

   if (millis() - timing > k){
      timing = millis(); 
       if (temperature>27){digitalWrite(12, HIGH);} else{
    digitalWrite(12, LOW);
   }  
      
   lcd.setCursor(3,0);
   lcd.print(temperature);
   Serial.println(temperature);}
 /*  if (temperature>27){digitalWrite(12, HIGH);} else{
    digitalWrite(12, LOW);*/
/*      if (temperature>50){digitalWrite(11, HIGH);} else{
    digitalWrite(11, LOW);}
       if (temperature>52){digitalWrite(10, HIGH);} else{
    digitalWrite(10, LOW);}*/
 }
   l=digitalRead(PIN_BUTTON);
  delay(50);
  c=digitalRead(PIN_BUTTON);
    if (Serial.available() > 0) {
    char val = Serial.read();

    if (val == 'y'){
      i=i+1; }}
    
if ((l != c) && l==HIGH) {
 i=i+1;

}}
