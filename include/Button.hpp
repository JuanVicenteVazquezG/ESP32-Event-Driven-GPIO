#pragma once
#include <Arduino.h>
#include <functional>

class Button
{
private:
    const uint8_t _pin;
    volatile bool _pressed;
    volatile bool _isDown;

public:
    Button(uint8_t pin);

    int checkPin;
    void begin();
    /*  bool wasPressed(); */
    bool isDown();

    static void IRAM_ATTR isr(void *arg);
};