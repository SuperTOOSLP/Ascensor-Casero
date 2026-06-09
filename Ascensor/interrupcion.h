#ifndef INTERRUPCION_H
#define INTERRUPCION_H
	
#include <reg51.h>
	
sbit pin_subir = P1^0;
sbit pin_bajar = P1^2;
sbit led_arriba = P2^2;
sbit led_abajo = P2^0;
sbit sensor_arriba = P3^2;
sbit sensor_abajo = P3^3;

void interrupcion_init(void);

#endif