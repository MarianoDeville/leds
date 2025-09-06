#include <stdbool.h>
#include "leds.h"
#include "errores.h"

#define FIRST_BIT           1
#define LED_TO_BIT_OFFSET   1

static uint16_t * puerto;

static bool IsLedValid(int led) {

    bool result = led >= 1 && led <= 16;

    if(!result) {

        Alerta("El led no es valido");
    }
    return result;
}

static uint16_t LedToMask(int led) {

    if(!IsLedValid(led)) {

        return 0;
    }
    return FIRST_BIT << (led - LED_TO_BIT_OFFSET);
}

void LedsInitDriver(uint16_t * puerto_virtual) {

    puerto = puerto_virtual; // Apagar todos los LEDs al iniciar
    *puerto = ALL_LED_OFF;
}

void LedsTurnOn(int led) {

    *puerto |= LedToMask(led);
}

void LedsTurnOff(int led) {

    *puerto &= ~LedToMask(led);
}

void LedsAllTurnOn(void) {

    *puerto = ALL_LED_ON;
}

void LedsAllTurnOff(void){
    
    *puerto = ALL_LED_OFF;
}

