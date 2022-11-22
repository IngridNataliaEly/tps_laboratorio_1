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
#include "datos.h"
#include "calculos.h"
#include "utn.h"
#include "Informes.h"


#define MAXIMO 22
int main(void) {
	setbuf(stdout, NULL);
	int opcionMenu;
	int banderaCostos=0;
	int banderaCarga=0;
	int banderaCalculos=0;
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
	int contadorJugadores;
	float transporteFinal;
	float hospedajeFinal;
	float comidaFinal;
	float costoMantenimiento;


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
	contadorJugadores = 0;
	contadorAfc=0;
	contadorCaf=0;
	contadorConcaf=0;
	contadorConmebol=0;
	contadorUefa=0;
	contadorOfc=0;
	costoMantenimiento=0;
	transporteFinal = 0;
	hospedajeFinal = 0;
	comidaFinal = 0;

		do{
			utn_getNumero(&opcionMenu,"\n1. Ingreso de los costos de Mantenimiento."
						"\n2. Carga de jugadores:"
						"\n3. Realizar todos los cálculos."
						"\n4. Informar todos los resultados."
						"\n5. Salir", "OPCION INVALIDA", 1, 5,10);
			switch(opcionMenu)
			{
			case 1:
			if (!Carga_Costos(&costoFinal,&transporteFinal,&hospedajeFinal,&comidaFinal) && contadorJugadores <= MAXIMO){
				printf("Carga de costos exitosa");
				banderaCostos = 1;
			}

			else {
				printf("\nSe a ingresado maximo de jugadores");
			}
				break;
			case 2:
				if(banderaCostos==1)
				{
						if(!jug_Alta(&contadorAfc,&contadorCaf,&contadorConcaf,
								&contadorConmebol,&contadorUefa,&contadorOfc,
								&contadorArqueros,&contadorDefensores,
								&contadorMediocampistas,&contadorDelanteros,
								&contadorJugadores))
					{
						banderaCarga=1;
					}
				}
				else {
					printf("Ingrese costos");
				}
				break;
			case 3:
				if(banderaCostos==1&&banderaCarga==1 && contadorJugadores > 0)
				{

					if(!calcular_Promedio(contadorAfc, contadorJugadores,&promedioAfc)&&
					   !calcular_Promedio(contadorCaf, contadorJugadores,&promedioCaf)&&
					   !calcular_Promedio(contadorConcaf, contadorJugadores,&promedioConcaf)&&
					   !calcular_Promedio(contadorConmebol, contadorJugadores,&promedioConmebol)&&
					   !calcular_Promedio(contadorOfc, contadorJugadores,&promedioOfc)&&
					   !calcular_Promedio(contadorUefa, contadorJugadores,&promedioUefa))
					{
						printf("\nSe realizaron correctamente los  Promedios");
						banderaCalculos=1;
					}

					if(!Calcular_CostosMantenimiento(transporteFinal, hospedajeFinal, comidaFinal,&costoMantenimiento))
					{
						printf("\nSe realizaron correctamente los  Costos");
					}
					if(!calcular_AumentoCostos(&aumento,&costoFinal,&costoMantenimiento,&contadorAfc,&contadorCaf,&contadorConcaf,
							&contadorConmebol,&contadorUefa,&contadorOfc))
					{
						printf("Se realizo el aumento");
					}
				}
				else
				{
					printf("\nDebe Ingresar los costos de Mantenimiento y Cargar jugadores");
				}
				break;
			case 4:
			if (banderaCalculos == 1 && hospedajeFinal > 0 && comidaFinal > 0
					&& transporteFinal > 0) {

				informe_Promedio(promedioAfc, promedioCaf, promedioConcaf,
						promedioConmebol, promedioUefa, promedioOfc);
				if (!calcular_AumentoCostos(&aumento, &costoFinal, &costoMantenimiento,&contadorAfc, &contadorCaf, &contadorConcaf,
						&contadorConmebol, &contadorUefa, &contadorOfc)) {
					printf("Aumento de");
				} else {
					informar_CostoMantenimiento(&costoMantenimiento);
				}
			} else {
				if (comidaFinal == 0) {
					printf(
							"\n***Error, no cargó los costos de la comida, ingreselos y vuelva a intentarlo***");
					if (hospedajeFinal == 0)
						printf(
								"\n***Error, no cargó los costos del hospedaje, ingreselos y vuelva a intentarlo***");
					if (costoMantenimiento == 0)
						printf(
								"\n***Error, no cargó los costos de mantenimiento, ingreselos y vuelva a intentarlo***");
					if (transporteFinal == 0)
						printf(
								"\n***Error, no cargó los costos de transporte, ingreselos y vuelva a intentarlo***");

					if (banderaCalculos != 1)
						printf(
								"\n***Error, se debe realizar los calculos en la opción 3 antes de mostrarlos, realicelos y vuelva a intentarlo***");
					printf("\n");
				}

			}
				break;
			}
		}
		while(opcionMenu!=5);

	return 0;

}
