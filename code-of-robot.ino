//Emad Jabbour for EJ Electro 2019
#define MA1 3
#define MA2 5
#define MB1 6
#define MB2 9
int trigPin = 11;
 int echoPin = 12;
long dur;
int dis;
int speed = 80;

void setup() {
pinMode(MA1,1);
pinMode(MA2,1);
pinMode(MB1,1);
pinMode(MB2,1);
pinMode(trigPin, OUTPUT); 
pinMode(echoPin, INPUT); 
Serial.begin(9600);

}

void loop() {


 if(distance()> 15){
  forward(speed);
delay(100);
 }else{
  backward(speed);
  delay(500);
  right(speed);
  delay(500);
  if(distance()> 15){
     right(speed);
  delay(500);
  }
 }




}

byte right( int speed){
analogWrite(MA1,speed);
analogWrite(MA2,0);
analogWrite(MB1,0);
analogWrite(MB2,0);
}
byte left( int speed){
analogWrite(MA1,0);
analogWrite(MA2,0);
analogWrite(MB1,speed);
analogWrite(MB2,0);
}
byte forward( int speed){
analogWrite(MA1,speed);
analogWrite(MA2,0);
analogWrite(MB1,speed);
analogWrite(MB2,0);
}
byte backward( int speed){
analogWrite(MA1,0);
analogWrite(MA2,speed);
analogWrite(MB1,0);
analogWrite(MB2,speed);
}

int distance(){
  digitalWrite(trigPin, LOW);
delayMicroseconds(2);

digitalWrite(trigPin, HIGH);
delayMicroseconds(10);
digitalWrite(trigPin, LOW);

dur = pulseIn(echoPin, HIGH);


return dur*0.034/2;
}
