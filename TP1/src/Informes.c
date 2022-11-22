/*
 * Informes.c
 *
 *  Created on: 19 nov 2022
 *      Author: natal_000
 */


#include "Informes.h"
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include "datos.h"
#include "Informes.h"
#include "calculos.h"
#include "utn.h"


int infome_Costos(float gastoTrasporte, float gastoHospedaje, float gastoComida)
{
	int retorno  = -1;
	if(gastoComida >= 0 && gastoHospedaje >= 0 && gastoTrasporte >= 0)
	{
		printf("\nCosto de hospedaje -> $ %.2f\n"
			"Costo de comida -> $%.2f\n"
			"Costo de transporte -> $%.2f\n", gastoHospedaje, gastoComida,
			gastoTrasporte);
		retorno = 0;
	}
return retorno;
}
void informe_Confederacion(int contadorAfc, int contadorCaf, int contadorConcaf,
		int contadorConmebol, int contadorUefa, int contadorOfc)
{
	printf("\nAFC en Asia ->%d"
			"\nCAF en Africa->%d"
			"\nCONCAF en zona del Norte->%d"
			"\nCONMEBOL en Sudamerica->%d"
			"\nUEFA en Europa->%d"
			"\nOFC en Oceania->%d\n", contadorAfc, contadorCaf, contadorConcaf,
			contadorConmebol,contadorUefa,contadorOfc);
}
void informe_Posicion(int contadorArqueros,int contadorDefensores,int contadorMediocampistas,int contadorDelanteros)
{
	printf("\nArqueros ->%d"
			"\nDefensores->%d"
			"\nMediocampistas->%d"
			"\nDelanteros->%d\n", contadorArqueros,contadorDefensores,
			contadorMediocampistas,contadorDelanteros);

}
int informe_Promedio(float promedioAfc,float promedioCaf,float promedioConcaf,float promedioConmebol,float promedioUefa,float promedioOfc)
{
	int retorno =-1;
	if(promedioAfc >= 0 && promedioCaf >= 0 && promedioConcaf >= 0 && promedioConmebol >= 0 && promedioUefa >= 0 && promedioOfc >= 0)
	{
		printf("\n Informar todos los Resultados"
					"\nPromedio de AFC ->%.2f"
					"\nPromedio de CAF ->%.2f"
					"\nPromedio de CONCAF ->%.2f"
					"\nPromedio de CONMEBOL ->%.2f"
					"\nPromedio de UEFA ->%.2f"
					"\nPromedio de OFC ->%.2f",promedioAfc,promedioCaf,promedioConcaf,promedioConmebol,promedioUefa,promedioOfc);
		retorno = 0;
	}
	return retorno;
}
void informar_CostoMantenimiento(float* costoMantenimiento)
{
	if(costoMantenimiento!=NULL)
	{
		printf("\nEl costo de mantenimiento: %.2f\n",*costoMantenimiento);
	}
}
void menu_Costos(char *opcion){
	if (opcion != NULL) {
		printf("Ingrese tipo de gastos"
				"\n't': para Transporte,"
				"\n'h' : para Hospedaje,"
				"\n'c' : para Comida\n");
		fflush(stdin);
		scanf("%c", opcion);
		while (*opcion != 't' && *opcion != 'c' && *opcion != 'h') {
			printf(
					"\nERROR Ingrese gastos't':Transporte,'h':Hospedaje,'c':Comida ");
			fflush(stdin);
			scanf("%c", opcion);
		}
	}
}

