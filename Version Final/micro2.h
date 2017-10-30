#ifndef MICRO2_H
#define MICRO2_H

#define	BIT_MASK	1	//mascara para las funciones del tipo bit...

/***********DEFINICIONES***********/
typedef struct             //definicion del puerto de 16 bits
{
	uint8_t porta;
	uint8_t portb;
} puertod_t;

puertod_t portd;

/*******FUNCIONES DE PUERTO*******/
int bitset( uint8_t * port, uint8_t nbit );
int bitclr(uint8_t * port, uint8_t nbit );
int bitget(uint8_t * port, uint8_t nbit );
void maskOn( uint8_t * port, uint8_t mask);
void maskOff( uint8_t * port, uint8_t mask);

/*****FUNCIONES DE IMPRESION*****/
void print_port(uint8_t cantidad_de_bits, uint8_t* port);
//funcion que imprime el estado del puerto que se quiere ver

#endif
