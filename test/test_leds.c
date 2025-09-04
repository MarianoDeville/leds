#include "unity.h"
#include "leds.h"

void setUp(void) {

}

void tearDown(void) {

}

// iniciar el driver y revisar que todos los leds esten apagados
void test_al_iniciar_todos_los_leds_estan_apagados(void) {

    uint16_t puerto_virtual = 0xFFFF;
    LedsInitDriver(&puerto_virtual);
    TEST_ASSERT_EQUAL_HEX16(0x0000, puerto_virtual);
}

// prender un led y verificar que no cambie el resto
void test_prender_un_led_y_verificar_que_no_cambie_el_resto(void) {

    uint16_t puerto_virtual;

    LedsInitDriver(&puerto_virtual);
    LedsTurnOn(3);
    TEST_ASSERT_EQUAL_HEX16(1 << 2, puerto_virtual);
}