#include <Signals.h>

Signals<uint16_t> SignalHit100;
uint16_t counter = 0;
uint16_t times = 0;

void doSerialPrint(uint16_t t){
  Serial.print("Hit 100! for ");
  Serial.print(t);
  Serial.println(" time.");
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
    times++;
    counter = 0;
    SignalHit100.emit(times);
  }

  //connect the signal to other function
  SignalHit100.connect(doSerialPrint);
}
