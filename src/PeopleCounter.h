//
// Created by George on 7/7/2024.
//

#ifndef PEOPLECOUNTER_LIBRARY_PEOPLECOUNTER_H
#define PEOPLECOUNTER_LIBRARY_PEOPLECOUNTER_H
#include "Arduino.h"
#include "PeopleCounter_config.h"
class PeopleCounter{
public:
    PeopleCounter();
    PeopleCounter(uint8_t s1Pin, uint8_t s2Pin, MODE mode);
    void setSensor1Pin(uint8_t s1Pin);
    void setSensor2Pin(uint8_t s1Pin);
    void setMode(MODE mode);
    bool begin();
private:
    bool areValidPins();
    static void action1();
    static void action2();
    uint8_t sensor1Pin;
    uint8_t sensor2Pin;
    MODE mode;
    volatile bool sensor1Val; //Default Value : depends on the mode
    volatile bool sensor2Val; //Default Value : depends on the mode
    bool flag2In = false; //Default Value : false
    bool flag2Out = false; //Default Value : false
    static PeopleCounter* instance; // Static pointer to instance, Default Value : nullptr
};

#endif //PEOPLECOUNTER_LIBRARY_PEOPLECOUNTER_H

