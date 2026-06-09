#include <reg51.h>
#include "interrupcion.h"

sbit boton_subir = P3^4;
sbit boton_bajar = P3^5;

int main(void){
	
	interrupcion_init();
	led_arriba = 1;
	led_abajo = 0; /// led abajo encendido

  while(1){
		
		if(sensor_arriba == 0 && sensor_abajo == 0){
			pin_bajar = 0;
			pin_subir = 0;
		}
		
		if(boton_subir == 0 && boton_bajar == 1){
			pin_subir = 1;
			pin_bajar = 0;
		}
		if(boton_subir == 1 && boton_bajar == 0){
			pin_subir = 0;
			pin_bajar = 1;
		}
		
	}		
	
}
	