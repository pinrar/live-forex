# live-forex
Display live USD/TRY rate on 5110 Screen + light up a green led if the rate's going up, red if going down, yellow if stable.

You need to choose the correct COM port in both the Python script & Arduino sketch.

Never open the serial monitor in Arduino IDE or it won't work. Windows doesn't allow two programs to use the same port simultaneously.

## Hardware:
* Arduino Uno
* Nokia 5110 LCD
* 3 x 330 Ohm resistors

## Libraries:
### Arduino:
* Adafruit_GFX.h
* Adafruit_PCD8544.h

### Python:
* BeautifulSoup4
* pySerial


