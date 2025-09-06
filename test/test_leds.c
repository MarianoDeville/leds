/*
prender un led y apagarlo en ambos extremos
prender algunos leds mas de una vez y verificar que siguen prendidos
apagar algunos leds mas de una vez y verificar que siguen apagados
prender algunos leds, despues prender todos y comprobar que todos los leds quedan prendidos
prender todos, apagar algunos, apagar todos y comprobar que todos los leds quedan apagados
consultar el estado de un led encendido y comprobar que es correcto
consultar el estado de un led apagado y comprobar que es correcto
agregar prueba para forzar la verificacion de rangos
*/

#include "unity.h"
#include "leds.h"
#include "mock_errores.h"

static uint16_t puerto_virtual;

void setUp(void) {

    LedsInitDriver(&puerto_virtual);
}

void tearDown(void) {

}

// iniciar el driver y revisar que todos los leds esten apagados
void test_al_iniciar_todos_los_leds_estan_apagados(void) {

    puerto_virtual = ALL_LED_ON;

    LedsInitDriver(&puerto_virtual);
    TEST_ASSERT_EQUAL_HEX16(ALL_LED_OFF, puerto_virtual);
}

// prender un led y verificar que no cambie el resto
void test_prender_un_led_y_verificar_que_no_cambie_el_resto(void) {

    LedsTurnOn(3);
    TEST_ASSERT_EQUAL_HEX16(1 << 2, puerto_virtual);
}

// prender un led cualquiera y apagarlo
void test_prender_un_led_cualquiera_y_apagarlo(void) {

    LedsTurnOn(3);
    LedsTurnOff(5);
    TEST_ASSERT_EQUAL_HEX16(1 << 2, puerto_virtual);
}

// prender mas de un led, apagar uno y verificar que el resto siguen sin cambio
void test_prender_mas_de_un_led_apagar_uno_y_verificar_que_el_resto_siguen_sin_cambio(void) {

    LedsTurnOn(3);
    LedsTurnOn(5);
    LedsTurnOff(3);
    TEST_ASSERT_EQUAL_HEX16(1 << 4, puerto_virtual);
}

// tratar de manipular un led fuera de rango y comprobar que se genera un error
void test_tratar_de_manipular_un_led_fuera_de_rango_y_comprobar_que_se_genera_un_error(void) {

    RegistrarMensaje_Expect(ALERTA, "IsLedValid", 0, "El led no es valido");
    RegistrarMensaje_IgnoreArg_linea();
    LedsTurnOn(0);
    TEST_ASSERT_EQUAL_HEX16(ALL_LED_OFF, puerto_virtual);

    RegistrarMensaje_Expect(ALERTA, "IsLedValid", 0, "El led no es valido");
    RegistrarMensaje_IgnoreArg_linea();
    LedsTurnOn(17);
    TEST_ASSERT_EQUAL_HEX16(ALL_LED_OFF, puerto_virtual);
}

// tratar de apagar leds fuera de rango y comprobar que se genera un error
void test_tratar_de_apagar_leds_fuera_de_rango_y_comprobar_que_se_genera_un_error(void) {

    RegistrarMensaje_Expect(ALERTA, "IsLedValid", 0, "El led no es valido");
    RegistrarMensaje_IgnoreArg_linea();
    LedsTurnOff(0);
    TEST_ASSERT_EQUAL_HEX16(ALL_LED_OFF, puerto_virtual);
    
    RegistrarMensaje_Expect(ALERTA, "IsLedValid", 0, "El led no es valido");
    RegistrarMensaje_IgnoreArg_linea();
    LedsTurnOff(17);
    TEST_ASSERT_EQUAL_HEX16(ALL_LED_OFF, puerto_virtual);
}

// prender todos los leds
void test_prender_todos_los_leds(void) {

    LedsAllTurnOn();
    TEST_ASSERT_EQUAL_HEX16(ALL_LED_ON, puerto_virtual);
}

// apagar todos los leds
void test_apagar_todos_los_leds(void) {
    
    LedsAllTurnOn();
    LedsAllTurnOff();
    TEST_ASSERT_EQUAL_HEX16(ALL_LED_OFF, puerto_virtual);
}



