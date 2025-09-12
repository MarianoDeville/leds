#ifndef LEDS_H
#define LEDS_H

#include <stdint-gcc.h>

#define ALL_LED_OFF 0X0000
#define ALL_LED_ON  ~ALL_LED_OFF

typedef enum {

    LED_APAGADO,
    LED_PRENDIDO
} LedState_t;

void LedsInitDriver(int * puerto_virtual);

void LedsTurnOn(int led);

void LedsTurnOff(int led);

void LedsAllTurnOn(void);

void LedsAllTurnOff(void);

LedState_t LedGetState(int led);

int LedGetAllState(void);

#endif
