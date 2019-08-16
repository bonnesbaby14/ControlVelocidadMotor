
#include <LiquidCrystal.h>


  
  
  LiquidCrystal lcd(52,50,48,46,44,42);
  float _speed=255.00;
  
void setup() {
 
TCCR2B = TCCR2B & B11111000 | B00000110;  
  // put your setup code here, to run once:

lcd.begin(16,2);
pinMode(9,OUTPUT);
pinMode(2,INPUT);
pinMode(3,INPUT);

Serial.begin(9600);
attachInterrupt(digitalPinToInterrupt(2),menus,HIGH);
attachInterrupt(digitalPinToInterrupt(3),more,HIGH);
Serial.println(_speed);



}

void loop() {

  // put your main code here, to run repeatedly:
analogWrite(9,_speed);
lcd.setCursor(1,1);

  

  lcd.print("Velocidad: ");
  lcd.setCursor(12,1);
  lcd.print("   ");
  lcd.setCursor(12,1);
  lcd.print(_speed/255.00*100.00);
  
}
void more(){
  delay(300);
 
  
  _speed>=255.0?_speed=255.0 :_speed+=10.0;
  Serial.println(_speed/255*100);
  
  }
void menus(){
   delay(300);

  _speed<=0.0? _speed=0.00:_speed-=10.0;
  Serial.println(_speed);
  }
