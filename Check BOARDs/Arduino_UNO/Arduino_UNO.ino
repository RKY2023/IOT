// the setup function runs once when you press reset or power the board
int random_variable;
int static_variable = 500;
int incomingByte = 0; // for incoming serial data\

void setup ( )
{
Serial.begin(9600);
// initialize digital pin 13 as an output.
pinMode ( 13 , OUTPUT ) ;
}
// the loop function runs over and over again forever
void loop ( )
{
// checkPIN();
checkSerial2();
}
// void checkPIN(){
// digitalWrite ( 13 , HIGH ) ;
// // turn the LED on (HIGH is the voltage level)
// delay ( 3000 ) ; // wait for a second
// digitalWrite ( 13 , LOW ) ;
// // turn the LED off by making the voltage LOW
// delay ( 3000 ) ; // wait for a second

// }
void checkSerial(){
  Serial.println("Hello World!@");
  delay(1000);
  random_variable = random(0, 1000);

  Serial.print("Variable_1:");
  Serial.print(random_variable);
  Serial.print(",");
  Serial.print("Variable_2:");
  Serial.println(static_variable);
}
void checkSerial2(){
  // send data only when you receive data:
  if (Serial.available() > 0) {
    // read the incoming byte:
    String wer = Serial.readString();

    // say what you got:
    Serial.print("I received: "+wer);
    // for loop number
    // int num = parseInt(wer);
    for(int i=0; i<100; i++){
      Serial.println(i);
    }
    // Serial.println(wer);
  }
}
