#include <Signals.h>

Signals<> SignalHit100;
uint16_t counter = 0;

void doSerialPrint(){
  Serial.println("Hit 100!");
}

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
}

void loop() {
  //Print the counter value
  Serial.println(counter);
  delay(100);
  
  //Counting...
  counter++;  
    
  //check the counter...
  if (counter == 100){
    //Emit the signal
    counter = 0;
    SignalHit100.emit();
  }

  //connect the signal to other function
  SignalHit100.connect(doSerialPrint);
}
