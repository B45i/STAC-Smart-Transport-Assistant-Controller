#include <SPI.h>
#include <nRF24L01.h>
#include <RF24.h>
#include <Adafruit_GFX.h>
#include <Adafruit_PCD8544.h>


#define LOGO16_GLCD_HEIGHT 16
#define LOGO16_GLCD_WIDTH  16

// pin 7 - Serial clock out (SCLK)
// pin 6 - Serial data out (DIN)
// pin 5 - Data/Command select (D/C)
// pin 4 - LCD chip select (CS)
// pin 3 - LCD reset (RST)
Adafruit_PCD8544 display = Adafruit_PCD8544(7, 6, 5, 4, 3);

RF24 radio(9,10); // CE, CSN
const byte address[6] = "00001";

void displaySTAC() {

  display.clearDisplay();
  display.setTextSize(2);
  display.setTextColor(WHITE, BLACK);
  display.setCursor(0, 0);
  display.println("STAC");
  display.setTextSize(1);
  display.setTextColor(BLACK);
  display.println("Smart Transport Assitance Controller");
  display.display();
  delay(2000);

  display.clearDisplay();
  display.setTextSize(1);
  display.setCursor(0, 0);
  display.setTextColor(WHITE, BLACK);
  display.println("Project By: ");
  display.setTextColor(BLACK);
  display.println("Aravind");
  display.println("Cyriac");
  display.println("Sreejith");
  display.println("Tomson");
  display.display();
  delay(3000);

}

void displayTraffic(String displayText) {

  display.clearDisplay(); // clears the screen and buffer
  
  display.setTextSize(1);
  display.setTextColor(WHITE, BLACK);
  display.setCursor(0, 0); 
  display.println("Traffic is :");

  display.setTextSize(2);
  display.setTextColor(BLACK);
  display.println(displayText);
  display.display();
}

void setup()   {
  Serial.begin(9600);

  radio.begin();
  radio.openReadingPipe(0, address);
  radio.setPALevel(RF24_PA_MIN);
  radio.startListening();

  display.begin(); // Nokia 5110 LCD Initialization.
  display.setContrast(30); // LCD Contrast adjustments
  
  displaySTAC();

}


void loop() {

   if (radio.available()) {
    char text[32] = "";
    radio.read(&text, sizeof(text));
    Serial.println(text);
    displayTraffic(text);
  }
}



