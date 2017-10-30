#include <stdio.h>
#include <stdint.h>
#include "micro2.h"



int bitset( uint8_t * port, uint8_t nbit )
{
	uint8_t bit=BIT_MASK;

	bit<<=nbit;	//corro el 1 n veces a la izquierda asi obtengo el bit que quiero prender


	*port=((*port)|(bit));	//realizo la siguiente operacion logica para poder prender ese bit y dejar los otros como estan

	return 0;



}

int bitclr(uint8_t * port, uint8_t nbit )
{
	uint8_t bit=BIT_MASK;	//asigno un bit en 0 para poder

	bit<<=nbit;	//corro el 1 n veces a la izquierda asi obtengo el bit que quiero prender

	*port=((*port)&(~bit));

	return 0;
}


int bitget(uint8_t * port, uint8_t nbit )
{
	uint8_t bit=BIT_MASK;

	uint8_t a;

	bit<<=nbit;


	a=((*port)&(bit))?1:0;

	return a;

}



void maskOn( uint8_t * port, uint8_t mask)
{
	*port=((*port)| mask);
}

void maskOff( uint8_t * port, uint8_t mask)
{
	*port=((*port) & (~mask));
}

void maskToggle( uint8_t * port, uint8_t mask)
{
	*port=((*port) ^(mask));
}

void print_port(uint8_t cantidad_de_bits, uint8_t* port)
{
	int i;
	uint16_t bit,bitp;

	for(i=(cantidad_de_bits-1),bit=1;i >= 0;i-- )
	{
		bit=1;		//reinicio en cada ciclo el numero para asi cuando shifteo no aparecen problemas
		bit<<=i;
		printf("%d ",bitp=(((*port)& bit )?1:0));
	}

	printf("\n");


}
