#include <SPI.h>
#include <RF24.h>

RF24 radio(7, 8);
const byte address[6] = "00001";

const int buzzerPin = 4;

void setup() {
  Serial.begin(9600);
  
  pinMode(buzzerPin, OUTPUT);
  digitalWrite(buzzerPin, LOW);
  
  radio.begin();
  radio.openReadingPipe(0, address);
  radio.setPALevel(RF24_PA_MIN);
  radio.setDataRate(RF24_250KBPS);
  radio.setChannel(76);
  radio.startListening();
  
  Serial.println("RX Ready");
}

void loop() {
  if (radio.available()) {
    char msg;
    radio.read(&msg, sizeof(msg));
    
    Serial.println("Got: A");
    
    // Short quiet beep
    tone(buzzerPin, 200, 50);
  }
}