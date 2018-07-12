#include <SoftwareSerial.h> // Arduino IDE <1.6.6
#include <PZEM004T.h>

PZEM004T pzem(10,11);  // RX,TX
IPAddress ip(192,168,1,1);

/*
 * PDAControl
 * Documentation PDAControl English:
 * http://pdacontrolen.com/meter-pzem-004t-with-arduino-esp32-esp8266-python-raspberry-pi/
 * Documentacion PDAControl Español:
 * http://pdacontroles.com/medidor-pzem-004t-con-arduino-esp32-esp8266-python-raspberry-pi/
 * Video Tutorial : https://youtu.be/qt32YT_1oH8
 * 
 */

void setup() {
  Serial.begin(115200);
  pzem.setAddress(ip);
    
}

void loop() {

  Serial.println("");
   
   float v = pzem.voltage(ip);
  if(v >= 0.0){ Serial.print(v);Serial.print("V; "); }
   
  float i = pzem.current(ip);
  if(i >= 0.0){ Serial.print(i);Serial.print("A; "); }
   
  float p = pzem.power(ip);
  if(p >= 0.0){ Serial.print(p);Serial.print("W; "); }

  float e = pzem.energy(ip);
  if(e >= 0.0){ Serial.print(e);Serial.print("Wh; "); }  

  Serial.println();


}
