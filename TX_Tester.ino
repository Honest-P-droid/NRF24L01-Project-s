#include <SPI.h>
#include <RF24.h>

RF24 radio(7, 8);
const byte address[6] = "00001";

void setup() {
  Serial.begin(9600);
  
  radio.begin();
  radio.openWritingPipe(address);
  radio.setPALevel(RF24_PA_MIN);
  radio.setDataRate(RF24_250KBPS);
  radio.setChannel(76);
  radio.stopListening();
  
  Serial.println("TX Ready");
}

void loop() {
  char msg = 'A';
  bool ok = radio.write(&msg, sizeof(msg));
  
  Serial.println(ok ? "Sent OK" : "Send FAIL");
  delay(1000);
}