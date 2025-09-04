/************************************************************************************************
Copyright (c) <year>, <copyright holders>

Permission is hereby granted, free of charge, to any person obtaining a copy of this software and
associated documentation files (the "Software"), to deal in the Software without restriction,
including without limitation the rights to use, copy, modify, merge, publish, distribute,
sublicense, and/or sell copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all copies or substantial
portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED, INCLUDING BUT
NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND
NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES
OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN
CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.

SPDX-License-Identifier: MIT
*************************************************************************************************/

#ifndef GPIO_H
#define GPIO_H

/**
 * @file gpio.h
 * @brief Definición de la función principal del programa
 */

/* === Headers files inclusions ================================================================ */

#include <stdint.h>
#include <stdbool.h>

/* === Cabecera C++ ============================================================================ */

#ifdef __cplusplus
extern "C" {
#endif

/* === Public macros definitions =============================================================== */

/* === Public data type declarations =========================================================== */

/**
 * @brief Puntero a estructura que representa un GPIO
 */
typedef struct gpio_s * gpio_t;

/* === Public variable declarations ============================================================ */

/* === Public function declarations ============================================================ */

/**
 * @brief Crea una nueva instancia de un objeto GPIO
 *
 * @param port puerto del GPIO
 * @param bit bit del GPIO
 * @return gpio_t puntero a la instancia del GPIO creada
 */
gpio_t gpioCreate(uint8_t port, uint8_t bit);

/**
 * @brief Configura el GPIO como salida o entrada
 *
 * @param gpio instancia del GPIO (devuelta por /ref gpioCreate "gpioCreate")
 * @param output true si es salida, false si es entrada
 */
void gpioSetOutput(gpio_t gpio, bool output);

/**
 * @brief Setea el estado del GPIO
 *
 * @param gpio instancia del GPIO (devuelta por /ref gpioCreate "gpioCreate")
 * @param state true para salida en alto, false si es bajo
 */
void gpioSetState(gpio_t gpio, bool state);

/**
 * @brief Obtiene el estado del GPIO
 *
 * @param gpio instancia del GPIO (devuelta por /ref gpioCreate "gpioCreate")
 * @return true si el GPIO está en alto, false si está en bajo
 */
bool gpioGetState(gpio_t gpio);

/* === End of documentation ==================================================================== */

#ifdef __cplusplus
}
#endif

#endif
