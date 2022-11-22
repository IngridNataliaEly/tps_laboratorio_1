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
#include "Informes.h"
#define CANTIDAD 3000
#define TIP 6


int main(void) {
	setbuf(stdout, NULL);
	int idJugador=0;
	int flagAlta=0;
	int OK =1;
	eJugador jugador[CANTIDAD];

	eConfederacion tipos[]={
			{100,"CONMEBOL","SUDAMERICA",1916},
			{101,"UEFA","EUROPA",1954},
			{102,"AFC","ASIA",1954},
			{103,"CAF","AFRICA",1957},
			{104,"CONCACAF","NORTE Y CENTRO AMERICA",1961},
			{105,"OFC","OCEANIA",1966},
	};
	eJugador jugadoresTest[15]={
					       {1,"Emiliano Martinez","ARQUERO",1,100,100000,4,OK},
					       {2,"Juan Musso","ARQUERO",12,100,80000,2,OK},
					       {3,"Leo Messi","DELANTERO",10,100,80000,4,OK},
					       {4,"Almirez Ali","DELANTERO",9,100,55000,1,OK},
					       {5,"Harry Maguire","DEFENSOR",2,101,70000,4,OK},
					       {6,"Eric Dier","DEFENSOR",3,101,60000,2,OK},
					       {7,"Harry Kane","DELANTERO",10,101,3000,2,OK},
					       {8,"Alfred Gomis","ARQUERO",1,101,9000,1,OK},
					       {9,"Abdelkarim Hassan","MEDIOCAMPISTA",8,101,48000,1,OK},
					       {10,"Guillermo Ochoa","ARQUERO",1,104,90000,4,OK},
					       {11,"Tecatito","DELANTERO",11,104,100000,3,OK},
					       {12,"Luis Romo","MEDIOCAMPISTA",7,104,100000,2,OK},
					       {13,"Bamba Dieng ","DELANTERO",9,103,100000,2,OK},
					       {14,"Demba Seck","DELANTERO",11,103,6000,2,OK},
					       {15,"Tarek Salman","DEFENSOR",6,102,78000,5,OK}
					   };


	int opcion;
	do {
		opcion = menu();
		switch (opcion) {
		case 1:

			eStr_Alta(jugadoresTest, 15, tipos, TIP, &idJugador);
			flagAlta = 1;
			break;
		case 2:
			if (flagAlta == 1) {
				eStr_Baja(jugadoresTest, 15, tipos, TIP);
			} else {
				printf("Debe dar el alta a un jugador");
			}
			break;
		case 3:
			if (flagAlta == 1) {
				eStr_Modificacion(jugadoresTest, 15, tipos, TIP);
			} else {
				printf("Debe dar el alta a un jugador");
			}
			break;
		case 4:
			if (flagAlta == 1) {
				mostrarInformes(jugadoresTest, 15, tipos, TIP);
			} else {
				printf("Debe dar el alta a un jugador");
			}

			break;

		}
	} while (opcion != 5);

	puts("\n... FIN PROGRAMA");

	return EXIT_SUCCESS;
}
