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

/**
 * @file gpio.c
 * @brief Definición de la función principal del programa
 */

/* === Headers files inclusions =============================================================== */

#include <string.h>
#include <stddef.h>
#include <stdlib.h>
#include "gpio.h"

/* === Macros definitions ====================================================================== */

/**
 * @brief Cantidad máxima de instancias de GPIO que se pueden crear
 *
 * Cuando se utiliza memória estática este valor define el número máximo de instancias de GPIO que
 * se pueden crear. Si se utiliza memória dinámica @ref USE_DYNAMIC_MEM, este valor no tiene efecto.
 */
#ifndef GPIO_MAX_INSTANCES
#define GPIO_MAX_INSTANCES 10
#endif

/* === Private data type declarations ========================================================== */

/**
 * @brief Estructura con los atributos de un GPIO
 */
struct gpio_s {
    uint8_t port; /**< Puerto del GPIO */
    uint8_t bit;  /**< Bit del GPIO */
    bool output;  /**< Indica si el GPIO es de salida o entrada */
#ifndef USE_DYNAMIC_MEM
    bool used; /**< Indica que la instancia está utilizada */
#endif
};

/* === Private variable declarations =========================================================== */

/* === Private function declarations =========================================================== */

/* === Public variable definitions ============================================================= */

/* === Private variable definitions ============================================================ */

/* === Private function implementation ========================================================= */

#ifndef USE_DYNAMIC_MEM
static gpio_t allocateInstance() {
    static struct gpio_s instances[GPIO_MAX_INSTANCES] = {0};

    gpio_t result = NULL;
    for (int index = 0; index < GPIO_MAX_INSTANCES; index++) {
        if (!instances[index].used) {
            result = &instances[index];
            result->used = true;
            break;
        }
    }
    return result;
}
#endif
/* === Public function implementation ========================================================== */

gpio_t gpioCreate(uint8_t port, uint8_t bit) {
#ifndef USE_DYNAMIC_MEM
    gpio_t self = malloc(sizeof(struct gpio_s));
#else
    gpio_t self = allocateInstance();
#endif

    if (self) {
        self->port = port;
        self->bit = bit;
        self->output = false;
    }
    return self;
}

void gpioSetOutput(gpio_t self, bool output) {
    self->output = output;
}

void gpioSetState(gpio_t self, bool state) {
}

bool gpioGetState(gpio_t self) {
    return false;
}

/* === End of documentation ==================================================================== */
