#include <Arduino.h>

// --- DEFINICIONES DE HARDWARE (C++20 Style) ---
// Usamos constexpr para constantes en tiempo de compilación.
constexpr int PIN_BOTON = 18;  // Tu Entrada (GPIO 18)
constexpr int PIN_LED   = 23;  // Tu Salida (GPIO 23)

void setup() {
    // 1. Arrancar el puerto serie para ver los "ojos" del sistema
    Serial.begin(115200);
    
    // 2. Configurar Pines
    // IMPORTANTE: Usamos 'INPUT' normal porque tú ya pusiste 
    // la resistencia y el condensador en la protoboard.
    pinMode(PIN_BOTON, INPUT);
    pinMode(PIN_LED, OUTPUT);

    Serial.println("--- INICIO TEST DE HARDWARE ---");
    Serial.println("Si pulsas, el LED debe encenderse.");
}

void loop() {
    // LEER EL MUNDO FÍSICO
    int estado = digitalRead(PIN_BOTON);

    // ACTUAR (Reflejo directo)
    digitalWrite(PIN_LED, estado);

    // REPORTAR (Solo si hay actividad para no saturar la pantalla)
    if (estado == HIGH) {
        Serial.println("[OK] Botón Pulsado -> Energía detectada (3.3V)");
        delay(50); // Pequeña pausa para estabilidad visual del log
    }
}