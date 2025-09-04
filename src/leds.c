#include "leds.h"

static uint16_t * puerto;

void LedsInitDriver(uint16_t * puerto_virtual) {

    puerto = puerto_virtual; // Apagar todos los LEDs al iniciar

    *puerto = 0x0000;
}

void LedsTurnOn(int led) {

    *puerto = 1 << 2;
}




