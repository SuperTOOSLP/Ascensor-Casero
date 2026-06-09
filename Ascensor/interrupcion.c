#include "interrupcion.h"

/// INT0 sensor arriba
/// INT1 sensor abajo (mayor prioridad)


void interrupcion_init(void){
	/// habilitar interrupciones 0B10000101
	IE |= 0x85;
	/// asignar prioridades 0B00000100
	IP |= 0x04;
	/// definir flanco de interrupcion (nivel bajo)
	IT1 = 0;
	IT0 = 0;
	
	/// iniciar con motor apagado
	pin_subir = 0;
	pin_bajar = 0;
	
}

void ISR_INT0_sensor_arriba(void) interrupt 0 {
	pin_subir = 0; /// detener por seguridad
	led_arriba = 0; /// encender
	led_abajo = 1; /// apagar
}

void ISR_INT1_sensor_abajo(void) interrupt 2 {
	pin_bajar = 0; /// detener por seguridad
	led_arriba = 1; /// apagar
	led_abajo = 0; /// encender
}