#include <SPI.h>
#include <nRF24L01.h>
#include <RF24.h>


RF24 radio(9, 10); // CE, CSN

const byte address[6] = "00001";

void setup() {

  Serial.begin(9600);

  radio.begin();
  radio.openWritingPipe(address);
  radio.setPALevel(RF24_PA_MIN);
  radio.stopListening();
}

void loop() {
  if(Serial.available()) {
    int i = Serial.parseInt();
    if(i == 1) {
      Serial.println("Low");
      const char text[] = "Low";
      radio.write(&text, sizeof(text));
    }
    else if(i == 2) {
      Serial.println("Medium");
      const char text[] = "Medium";
      radio.write(&text, sizeof(text));
    }
    else {
      Serial.println("High");
      const char text[] = "High";
      radio.write(&text, sizeof(text));
    }
  }
}
