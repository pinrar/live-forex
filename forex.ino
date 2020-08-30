#include <SPI.h>
#include <Adafruit_GFX.h>
#include <Adafruit_PCD8544.h>

// Software SPI (slower updates, more flexible pin options):
// pin 7 - Serial clock out (SCLK)
// pin 6 - Serial data out (DIN)
// pin 5 - Data/Command select (D/C)
// pin 4 - LCD chip select (CS)
// pin 3 - LCD reset (RST)
Adafruit_PCD8544 display = Adafruit_PCD8544(7, 6, 5, 4, 3);

const int red = 8; // choose pin for each LED
const int yellow = 9;
const int green = 10;

String str = "";
float kurp = 0.0; //previous value
float kurn = 0.0; //next value


void setup() {

  pinMode(red, OUTPUT);
  pinMode(yellow, OUTPUT); 
  pinMode(green, OUTPUT); 

  Serial.begin(9600);

  display.begin();
  display.setContrast(50); //change this if there are problems w display
  display.clearDisplay();   

  display.drawRect(0, 0, 83, 47, 1); //draw border
  display.fillRect(1,1,83,47,0);
  display.drawRect(1,1,83,47,1);
  display.setTextSize(1);
  display.setTextColor(BLACK);
  display.setCursor(4,13);
  display.println("USD/TRY");
  display.display();
  delay(1000);

}

void loop() {
  if (Serial.available()>0){

    str = Serial.readStringUntil(' ');
    str.trim();
    kurn = str.toFloat();
    display.fillRect(4,23,70,15,0); //erase previous value
    display.setCursor(4,23);
    display.println(kurn,4);
    display.display();

    if (kurn == kurp) {
      digitalWrite(red, LOW);
      digitalWrite(yellow, HIGH);
      digitalWrite(green, LOW);
    }
    else if (kurn < kurp) {
      digitalWrite(red, HIGH);
      digitalWrite(yellow, LOW);
      digitalWrite(green, LOW);
    }
    else if (kurn > kurp) {
      digitalWrite(red, LOW);
      digitalWrite(yellow, LOW);
      digitalWrite(green, HIGH);
    }
    else {
      digitalWrite(red, HIGH);
      digitalWrite(yellow, HIGH);
      digitalWrite(green, HIGH);
    }
    kurp = kurn; //update previous value and move on
    delay(5000); 

}

}
