#include "DFRobot_DF2301Q.h"
#define Led 8
DFRobot_DF2301Q_I2C asr;

void setup() {
  Serial.begin(115200);
  pinMode(Led, OUTPUT);    
  while (!(asr.begin())) {
    Serial.println("Communication with device failed, please check connection");
    delay(3000);
  }
  Serial.println("Begin ok!");
  asr.setVolume(7);  
  asr.setMuteMode(0);  
  asr.setWakeTime(255);  
  uint8_t wakeTime = 0;
  wakeTime = asr.getWakeTime();
  Serial.print("wakeTime = ");
  Serial.println(wakeTime);
}

void loop() {
  uint8_t CMDID = asr.getCMDID();
  switch (CMDID) {
    case 5:                                                
      digitalWrite(Led, HIGH);                                 
      Serial.println("received 'Turn on the light', command flag '5'");  
      break;
    case 6:                                                 
      digitalWrite(Led, LOW);                                  
      Serial.println("received 'Turn off the light', command flag '6'");  
      break;
    default:
      if (CMDID != 0) {
        Serial.print("CMDID = ");  
        Serial.println(CMDID);
      }
  }
  delay(300);
}
