#ifndef LED2_H_
#define LED2_H_


#include <stdint.h>
#include "micro2.h"
#include <stdlib.h>
#include "constantes.h"
#include "termlib.h"

/******Instrucciones******/
void print_instructions(void);

/*****Control de LEDs****/
void parpadear(uint8_t* port);

#endif
