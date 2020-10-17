
/*
 * Used to send AT commands to WiFi device on EducationShield
 * 
 * Use the serial monitor to send commands
 * 
 * if you and send AT and recieve OK then you have it setup correctly
 */


#include <SoftwareSerial.h>

SoftwareSerial mySerial(2, 12); // RX, TX

void setup() {
  // Open serial communications and wait for port to open:
  Serial.begin(115200);
  while (!Serial) {
    ; // wait for serial port to connect. Needed for native USB port only
    Serial.println("Serial Not Working");
    delay("1000");
  }

  Serial.println("Arduino Serial is working");
  
  mySerial.begin(115200);
  mySerial.println("Software Serial is working");
  
  delay(100);
}

void loop() { 
  
    if (mySerial.available()) {
      Serial.write(mySerial.read());
    }
    if (Serial.available()) {
      mySerial.write(Serial.read());
    }

}
