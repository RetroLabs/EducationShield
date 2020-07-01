/* D0 - Used for firmware upload
 * D1 - Used for firmware upload
 * D2 - TX UART
 * D3 - White LED
 * D4 - Hall Sensor
 * D5 - Vibrator
 * D6 - Piezo Buzzer
 * D7 - Switch
 * D8 - Button
 * D9 - Green LED
 * D10 - Blue LED
 * D11 - Red LED
 * D12 - Rx UART
 * D13 - LED Built into Uno
 * 
 * A0 - Potentiometer 
 * A1 - Light Detector
 * A2 - Temp Sensor
 * A3
 * A4 - LCD
 * A5 - LCD
 * 
 * For OLED Screen download libraries from library Manager
 * Adafruit_SSD1306
 * Adafruit_GFX
 * 
 * 
 */

int delayTime = 2000; // In milli seconds, 1000 = 1second

// Declare Analog Pins
int PotentiometerPin = A0;
int lightPin = A1;
int tempPin = A2;

// OLED 
#include <SPI.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

#define SCREEN_WIDTH 128 // OLED display width, in pixels
#define SCREEN_HEIGHT 32 // OLED display height, in pixels

// Declaration for an SSD1306 display connected to I2C (SDA, SCL pins)
#define OLED_RESET     4 // Reset pin # (or -1 if sharing Arduino reset pin)
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);


void setup() {
  
// Outputs
pinMode(2,OUTPUT); // TX UART
pinMode(3,OUTPUT); // White LED
pinMode(5,OUTPUT); // Vibration Motor
pinMode(6,OUTPUT); // Piezo Buzzer
pinMode(9,OUTPUT); // RGB LED Green Led
pinMode(10,OUTPUT); // RGB LED Blue Led
pinMode(11,OUTPUT); // RGB LED RED Led
pinMode(13,INPUT); // LED built into Uno board

// Input
pinMode(4,INPUT_PULLUP); // Hall Sensor
pinMode(7,INPUT); // ON/OFF Slide Switch
pinMode(8,INPUT); // Push Button
pinMode(12,INPUT); // RX Uart

// OLED SETUP
display.begin(SSD1306_SWITCHCAPVCC, 0x3C);

// Boot Screen
display.clearDisplay();
display.setTextSize(2); // Draw 2X-scale text
display.setTextColor(SSD1306_WHITE);
display.setCursor(10, 0);
display.println(F("Education Shield"));
display.display();      // Show initial text

// delay to allow user to see boot screen
delay(2000);

}


void loop() {

// white LED
  display.clearDisplay(); // Clears current showing screen
  display.setTextSize(2); // Draw 2X-scale text
  display.setTextColor(SSD1306_WHITE);
  display.setCursor(10, 0);
  display.println(F("White     LED   "));
  display.display();      // Show initial text
  
digitalWrite(3, HIGH);
delay(delayTime);
digitalWrite(3, LOW);

// Vibration 

  display.clearDisplay(); // Clears current showing screen
  display.setTextSize(2); // Draw 2X-scale text
  display.setTextColor(SSD1306_WHITE);
  display.setCursor(10, 0);
  display.println(F("Vibration Motor"));
  display.display();      // Show initial text
  
digitalWrite(5, HIGH);
delay(delayTime);
digitalWrite(5, LOW);

// Green LED
  display.clearDisplay(); // Clears current showing screen
  display.setTextSize(2); // Draw 2X-scale text
  display.setTextColor(SSD1306_WHITE);
  display.setCursor(10, 0);
  display.println(F("Green     LED   "));
  display.display();      // Show initial text
  
digitalWrite(10, HIGH);
delay(delayTime);
digitalWrite(10, LOW);

// Blue LED

  display.clearDisplay(); // Clears current showing screen
  display.setTextSize(2); // Draw 2X-scale text
  display.setTextColor(SSD1306_WHITE);
  display.setCursor(10, 0);
  display.println(F("Blue      LED   "));
  display.display();      // Show initial text
  
digitalWrite(9, HIGH);
delay(delayTime);
digitalWrite(9, LOW);

// Red LED

  display.clearDisplay(); // Clears current showing screen
  display.setTextSize(2); // Draw 2X-scale text
  display.setTextColor(SSD1306_WHITE);
  display.setCursor(10, 0);
  display.println(F("Red       LED   "));
  display.display();      // Show initial text
  
digitalWrite(11, HIGH);
delay(delayTime);
digitalWrite(11, LOW);

// Buzzer

  display.clearDisplay(); // Clears current showing screen
  display.setTextSize(2); // Draw 2X-scale text
  display.setTextColor(SSD1306_WHITE);
  display.setCursor(10, 0);
  display.println(F("Buzzer    3 beeps   "));
  display.display();      // Show initial text

// Buzz 3 times
    for(int x = 0; x < 3; x++){
      tone(6, 1000); // Send 1KHz sound signal...
      delay(300);    // ... wait for .3 sec
      noTone(6);     // Stop sound...
      delay(300);    // ... wait for .3 sec
}

// ON/OFF Slide Switch

  display.clearDisplay(); // Clears current showing screen
  display.setTextSize(2); // Draw 2X-scale text
  display.setTextColor(SSD1306_WHITE);
  display.setCursor(10, 0);

  if(digitalRead(7)== HIGH ) {
  display.println(F("Switch    ON"));
  }
  else{
       display.println(F("Switch    OFF"));
       }
  
  display.display();      // Show initial text

  //delay
  delay(delayTime);

// Button Press

  display.clearDisplay(); // Clears current showing screen
  display.setTextSize(2); // Draw 2X-scale text
  display.setTextColor(SSD1306_WHITE);
  display.setCursor(10, 0);

  if(digitalRead(8)== HIGH ) {
  display.println(F("Button    ON"));
  }
  else{
       display.println(F("Button    OFF"));
       }
  
  display.display();      // Show initial text

  //delay
  delay(delayTime);

// Potentiometer

  display.clearDisplay(); // Clears current showing screen
  display.setTextSize(2); // Draw 2X-scale text
  display.setTextColor(SSD1306_WHITE);
  display.setCursor(10, 0);
  display.println(F("POT:   "));
  display.print(analogRead(A0));
  display.display();      // Show initial text

  delay(delayTime);

// Light Detector

  display.clearDisplay(); // Clears current showing screen
  display.setTextSize(2); // Draw 2X-scale text
  display.setTextColor(SSD1306_WHITE);
  display.setCursor(10, 0);
  display.println(F("Light:   "));
  display.print(analogRead(A1));
  display.display();      // Show initial text

  delay(delayTime);

// Temperature sensor

  int reading = analogRead(A2);

  float voltage = reading * 5.0;
  voltage /= 1024.0;

  float temperatureC = (voltage - 0.5) * 100 ;

  float temperatureF = (temperatureC * 9.0 / 5.0) + 32.0;
 
  display.clearDisplay(); // Clears current showing screen
  display.setTextSize(2); // Draw 2X-scale text
  display.setTextColor(SSD1306_WHITE);
  display.setCursor(10, 0);
  //display.println(F("TEMP:   "));
  display.print(temperatureC);
  display.println(F(" C"));
  display.print(temperatureF);
  display.println(F(" F"));
  display.display();      // Show initial text

  delay(delayTime);

// Hall Sensor

  display.clearDisplay(); // Clears current showing screen
  display.setTextSize(2); // Draw 2X-scale text
  display.setTextColor(SSD1306_WHITE);
  display.setCursor(10, 0);

  if(digitalRead(4)== LOW) {
  display.println(F("Hall     OFF"));
  }
  else{
       display.println(F("Hall     ON"));
       }
  
  display.display();      // Show initial text

  //delay
  delay(50);
  
}
