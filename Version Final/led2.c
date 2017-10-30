#include <stdio.h>
#include <unistd.h>
#include "led2.h"

extern puertod_t portd;

/* Titulo: Estructuras, Uniones y bittfields
Programa que simula los LEDS de un puerto A y permite modificarlos mediante diferentes comandos.
Autores: Ariel Martorell, Lucas Migone, Francisco Carricart, Juan Schinocca.
*/

int main(void)
{
  char tecla;
  uint8_t * pa;
  pa=&portd.porta; // puntero al puerto a
  print_instructions();
  int valido=VALIDO;

  while ( valido )
  {



  	tecla=getch();



    switch(tecla)
    {
      case ENCENDIDOS:
      {
        maskOn(pa,ON);
        print_port(8,pa);
        break;
      }
      case APAGADOS:
      {
        maskOff(pa,ON);
        print_port(8,pa);
        break;
      }
        case PARPADEO:
      {
        parpadear(pa);
        print_port(8,pa);
        break;
      }

      case '0': case '1': case '2': case '3': case '4': case '5': case '6': case '7':
      {
        int c = tecla - '0';

        int a;
        a=bitget(pa,c);


        if( a==ENCENDIDO)
     	{

        	bitclr(pa,c);
     	}
     	else if (a==APAGADO)
     	{
     		bitset(pa,c);
     	}
        print_port(8,pa);
        break;
      }
      case ESC:
      {
      	valido=INVALIDO;
      	break;
      }
      default:
      {
        printf("La tecla ingresada no corresponde con una accion del programa\n");
      }

    }
  }



}

void print_instructions(void)
{
  printf("*Bienvenido al simulador de cadena de 8 LEDs*\n");
  printf("Para encender un led presione un numero del 0 al 7\n");
  printf("Los leds estan colocados de esta manera 7 6 5 4 3 2 1 0\n");
  printf("*si desea encenderlos todos presione s\n");
  printf("*si desea apagarlos todos presione c\n");
  printf("*si desea que parpadeen presione b\n");
  printf("Nota: si presiono para que parpadee,\n");
  printf("debera esperar a que termine de parpadear para seguir con el programa\n");
  printf("*si desea cerrar el programa presione ESC\n");
}



void parpadear(uint8_t* port)//no le des pelota al ciclo ni al if fue un intento de hacerlo parar cuando quiera
{
  uint8_t port_aux= (*port);
  int contador = 10;
  while (contador --)
  {
  print_port(8,port);
  sleep(1); //1 segundo
  *port = (*port) & MASK; //apaga leds
  print_port(8,port); //1 segundo
  *port = port_aux; // vuelvo a prender los que estaban prendidos
  sleep(1);
  }
}
