#include "Button.hpp"
   
        Button::Button(uint8_t pin):_pin(pin), _isDown(false){};
    
        void Button::begin(){
            pinMode(_pin, INPUT_PULLUP);
            attachInterruptArg(digitalPinToInterrupt(_pin), isr, this, CHANGE);
        }

        bool Button::isDown(){
            return _isDown;
        }

        void IRAM_ATTR Button::isr(void* arg){
            Button* btn = static_cast<Button*>(arg);
            /* btn->_pressed = true; */
            btn->_isDown = digitalRead(btn->_pin) == LOW;
        }