#ifndef LEDS_H
#define LEDS_H

#include <stdint-gcc.h>

#define ALL_LED_OFF         0X0000
#define ALL_LED_ON          ~ALL_LED_OFF

void LedsInitDriver(uint16_t * puerto_virtual);

void LedsTurnOn(int led);

void LedsTurnOff(int led);

void LedsAllTurnOn(void);

void LedsAllTurnOff(void);

#endif
