/*
 ============================================================================
 Name        : prueba.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include "prueba.h"


#define TAM 5
int main(void) {
	setbuf(stdout, NULL);
	int opcionMenu;
	int banderaCostos=0;
	int banderaCarga=0;
	int banderaCalculos=0;
	int banderadaCalculos=0;

	int contadorArqueros;
	int contadorDefensores;
	int contadorMediocampistas;;
	int contadorDelanteros;

	int contadorAfc;
	int contadorCaf;
	int contadorConcaf;
	int contadorConmebol;
	int contadorUefa;
	int contadorOfc;

	int sumaT;
	int sumaH;
	int sumaC;
	int costoMantenimiento;
	int i;

	float promedioAfc;
	float promedioCaf;
	float promedioConcaf;
	float promedioConmebol;
	float promedioUefa;
	float promedioOfc;

	float aumento;
	float costoFinal;

	contadorArqueros=0;
	contadorDefensores=0;
	contadorMediocampistas=0;
	contadorDelanteros=0;

	contadorAfc=0;
	contadorCaf=0;
	contadorConcaf=0;
	contadorConmebol=0;
	contadorUefa=0;
	contadorOfc=0;

	sumaT=0;
	sumaH=0;
	sumaC=0;
	costoMantenimiento=0;
	i=0;


		do{
			mostrarMenu();
			opcionMenu = utn_getNumero("\nIngrese una opcion","ERROR ingrese opcion valida 1-5",1,7);
			switch(opcionMenu)
			{
			case 1:
				ingresoCostos(&banderaCostos,&sumaT,&sumaH,&sumaC,&costoMantenimiento);
				break;
			case 2:
				cargaJugadores(&banderaCostos,&banderaCarga,&contadorAfc,&contadorCaf,&contadorConcaf,&contadorConmebol,&contadorUefa,&contadorOfc,&contadorArqueros,&contadorDefensores,&contadorMediocampistas,&contadorDelanteros,&i);
				break;
			case 3:
				realizarCalculos(&banderaCostos,&banderaCarga,&banderaCalculos,&banderadaCalculos,&i,&contadorAfc,&contadorCaf,&contadorConcaf,&contadorConmebol,&contadorUefa,&contadorOfc,&promedioAfc,&promedioCaf,&promedioConcaf,&promedioConmebol,&promedioUefa,&promedioOfc);
				realizarCostos(&banderaCostos,&banderaCarga,&banderaCalculos,&sumaT,&sumaH,&sumaC,&costoMantenimiento);

				break;
			case 4:
				utn_mostrarPromedio(&promedioAfc,&promedioCaf,&promedioConcaf,&promedioConmebol,&promedioUefa,&promedioOfc);
				utn_mostrarCosto(&costoMantenimiento);
				utn_mayorContador(&aumento,&costoFinal,&costoMantenimiento,&contadorAfc,&contadorCaf,&contadorConcaf,&contadorConmebol,&contadorUefa,&contadorOfc);
				break;
			}
		}
		while(opcionMenu!=5);

	return EXIT_SUCCESS;
}
