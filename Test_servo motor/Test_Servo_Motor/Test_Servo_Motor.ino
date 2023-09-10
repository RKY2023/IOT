#include<Servo.h>

Servo s1;

void setup() {
  // put your setup code here, to run once:
s1.attach(9);
s1.write(180);
delay(10000);



// s1.write(80);
// delay(1000);
// s1.write(90);

// s1.write(0);
// delay(1000);
// s1.write(90);

// s1.write(0);
// delay(1000);
// s1.write(90);

// s1.write(0);
// delay(1000);
// s1.write(90);
}

void C180A180(){
  for(int i=0; i < 180; i+=1){
    s1.write(i);
    delay(10);
  }
  for(int i=180; i >= 1; i-=1){
    s1.write(i);
    delay(10);
  }
}

void loop() {
  // put your main code here, to run repeatedly:
  C180A180();
  delay(10000);
// s1.write(0);
// delay(5000);
// s1.write(90);
// delay(10000);
// s1.write(180);
// delay(15);
// s1.write(270);
// delay(10000);

// delay(1000);
  // for(int i=0; i<=360; i+=1){
  //   s1.write(i);
  //   delay(100);
  // }
  // for(int i=180; i>=0; i-=1){
  //   s1.write(i);
  //   delay(15);
  // }
}
