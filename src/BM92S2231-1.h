/*****************************************************************
File:             BM92S2231-1.h
Author:           BEST MODULES CORP.
Description:      Define classes and required variables
Version:          V1.0.2   -- 2025-04-02
******************************************************************/
#ifndef BM92S2231_1_H
#define BM92S2231_1_H

#include "Arduino.h"
#include "SoftwareSerial.h"
#define BM92S2231_1_NO_KEY 0

class BM92S2231_1
{
  public:
    
    BM92S2231_1(uint8_t keyoutPin=2,HardwareSerial *theSerial = &Serial);
    BM92S2231_1(uint8_t keyoutPin,uint8_t rxPin, uint8_t txPin);
    void begin(unsigned long baud = 115200);

    int8_t InputEnrollID(int16_t ID); 
    uint8_t enroll();
    bool stopEnroll();

    uint8_t getKeyout();
    int16_t identify();
    bool stopIdentify();

    uint8_t deleteID(uint16_t id);
    bool deleteAll();
    
    bool StandbyMode();
    bool changeBaud(unsigned long baud);    
    uint8_t getDeviceInformation();
    bool getModuleSettingsInformation(uint8_t inforArray[]);
    bool getImageSettingInformation(uint8_t inforArray[]);
    
    bool userSet(uint16_t score,uint8_t checkAngle,uint8_t numberTemplates );
    bool imageSet(uint16_t imageThreshold,uint16_t imagePercentage);
   

  private:
    uint8_t _rxPin;
    uint8_t _txPin;
    uint8_t _keyoutPin;
    HardwareSerial *_serial = NULL;
    SoftwareSerial *_softSerial = NULL;
    bool firmwareUpdate();
    void writeBytes(uint8_t wbuf[] ,uint8_t wlen);
    uint8_t readBytes(uint8_t response[], uint8_t length,uint16_t timeout = 500);
    bool check(uint8_t receivebuf[]);
    bool checkData(uint8_t receivebuf[],uint16_t receivenum);
};
#endif
