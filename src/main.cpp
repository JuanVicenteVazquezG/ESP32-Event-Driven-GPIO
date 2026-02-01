#include <Arduino.h>
#include "../include/Button.hpp"

constexpr int PIN_LED = 23; // Tu Salida (GPIO 23)
bool ledState = false;

Button btn = Button(18);

void setup()
{
    // 1. Arrancar el puerto serie para ver los "ojos" del sistema
    Serial.begin(115200);
    digitalWrite(PIN_LED, LOW);
    // 2. Configurar Pines
    // IMPORTANTE: Usamos 'INPUT' normal porque tú ya pusiste
    // la resistencia y el condensador en la protoboard.
    btn.begin();
    pinMode(PIN_LED, OUTPUT);
    Serial.println("--- INICIO TEST DE HARDWARE ---");
    Serial.println("Si pulsas, el LED debe encenderse.");
}

void loop()
{
    bool state = btn.isDown();
    digitalWrite(PIN_LED, state);
    if (state)
    {
        Serial.println("[OK] Botón Pulsado -> Energía detectada (3.3V)");
        delay(50); // Pequeña pausa para estabilidad visual del log
    }
}