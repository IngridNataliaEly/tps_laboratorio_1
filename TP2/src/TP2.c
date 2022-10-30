/*
 ============================================================================
 Name        : TP2.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#include "utn.h"
#include "eJugador.h"
#include "eConfederacion.h"
#define CANTIDAD 3000
#define TIP 6


int main(void) {
	setbuf(stdout, NULL);
	int informes;
	eJugador jugador[CANTIDAD];

	eConfederacion tipos[]={
			{100,"CONMEBOL","SUDAMERICA",1916},
			{101,"UEFA","EUROPA",1954},
			{102,"AFC","ASIA",1954},
			{103,"CAF","AFRICA",1957},
			{104,"CONCACAF","NORTE Y CENTRO AMERICA",1961},
			{105,"OFC","OCEANIA",1966},
	};

	int opcion;
	do {
			opcion = menu();
			switch (opcion)
			{
				case 1:
					eStr_Alta(jugador,CANTIDAD,tipos,TIP);
					break;
				case 2:
					eStr_Baja(jugador,CANTIDAD,tipos,TIP);
					break;
				case 3:
					eStr_Modificacion(jugador,CANTIDAD,tipos,TIP);
					break;
				case 4:
					informes = subMenuInformes();
					 mostrarInformes(informes);
					break;

			}
		} while (opcion != 5);

		puts("\n... FIN PROGRAMA");

	return EXIT_SUCCESS;
}
