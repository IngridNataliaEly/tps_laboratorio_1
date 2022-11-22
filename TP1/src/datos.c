/*
 * prueba.c
 *
 *  Created on: 20 sept 2022
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

int Carga_Costos(float *acumuladorCostosMant, float *gastoTrasporte,
		float *gastoHospedaje, float *gastoComida) {

	int respuesta;
	char opcion;
	int retorno = -1;
	if (acumuladorCostosMant != NULL && gastoComida != NULL && gastoHospedaje != NULL && gastoTrasporte !=NULL) {
		do {
			printf("\nCosto de hospedaje -> $%.2f\n"
						"Costo de comida -> $%.2f\n"
						"Costo de transporte -> $%.2f\n", *gastoHospedaje,*gastoComida,
						*gastoTrasporte);
			menu_Costos(&opcion);
			switch (opcion)
			{
			case 't':
				utn_getNumeroFlotante(&(*gastoTrasporte),
						"\nIngrese el monto Gasto de Trasporte: \n",
						"ERROR Ingrese un costo valido de 0 a 100000000", 1,
						100000000,15);
				retorno = 0;
				break;
			case 'h':
				utn_getNumeroFlotante(&(*gastoHospedaje),
						"\nIngrese el monto Gasto de Hospedaje: \n",
						"ERROR Ingrese un costo valido de 0 a 100000000", 1,
						100000000,15);
				retorno = 0;
				break;
			case 'c':
				utn_getNumeroFlotante(&(*gastoComida),
						"\nIngrese el monto Gasto de Comida: \n",
						"ERROR Ingrese un costo valido de 0 a 100000000", 1,
						100000000,15);
				retorno = 0;
				break;
			}
			infome_Costos((*gastoTrasporte),(*gastoHospedaje), (*gastoComida));
			printf("Salgo");
			respuesta = utn_getCaracterSN("\n¿continuar Ingresando gastos? s/n");

		} while (respuesta == 0);
	}
	return retorno;
}

int jug_Alta(int* contadorAfc,int* contadorCaf, int *contadorConcaf,
		int *contadorConmebol, int *contadorUefa, int *contadorOfc,
		int *contadorArqueros, int *contadorDefensores,
		int *contadorMediocampistas, int *contadorDelanteros,
		int *contadorJugadores)
{

	int retorno = -1;
	int numCamiseta;
	if (contadorAfc != NULL && contadorCaf != NULL && contadorConcaf != NULL
			&& contadorConmebol != NULL && contadorUefa != NULL
			&& contadorOfc != NULL && contadorArqueros != NULL
			&& contadorDefensores != NULL && contadorMediocampistas != NULL
			&& contadorDelanteros != NULL) {

		utn_getNumero(&numCamiseta, "\nIngrese numero de camiseta\n",
				"\nIngrese numero de camiseta 0 a 100", 0, 100,5);


	if(!Carga_Posicion(&(*contadorArqueros),&(*contadorDefensores),&(*contadorMediocampistas),&(*contadorDelanteros),&(*contadorJugadores)))
		{
			printf("\nCarga Posicion exitosa");
		} else {
			printf("\nERROR Carga Posicion!");
		}
		if(!Carga_Confederacion(&(*contadorAfc),&(*contadorCaf),&(*contadorConcaf),
				&(*contadorConmebol),&(*contadorUefa),&(*contadorOfc)))
		{
			printf("\nCarga confederacion exitosa");
		} else {
			printf("ERROR Carga confederacion!");
		}
		retorno = 0;
	}

	return retorno;
}


int Carga_Confederacion(int *contadorAfc, int *contadorCaf, int *contadorConcaf,
		int *contadorConmebol, int *contadorUefa, int *contadorOfc) {
	int confederacion;
	int retorno = -1;
	if (contadorAfc != NULL && contadorCaf != NULL && contadorConcaf != NULL
				&& contadorConmebol != NULL && contadorUefa != NULL
				&& contadorOfc != NULL)
	{
	informe_Confederacion(*contadorAfc, *contadorCaf, *contadorConcaf, *contadorConmebol, *contadorUefa, *contadorOfc);
	utn_getNumero(&confederacion, "\nIngrese la confederacion:"
			"\n1.AFC en Asia "
			"\n2.CAF en Africa"
			"\n3.CONCAF en zona del Norte"
			"\n4.CONMEBOL en Sudamerica"
			"\n5.UEFA en Europa"
			"\n6.OFC en Oceania ", "CONFEDERACION INVALIDA", 1, 6,7);


	switch (confederacion) {
	case 1:
		(*contadorAfc)++;
		break;
	case 2:
		(*contadorCaf)++;
		break;
	case 3:
		(*contadorConcaf)++;
		break;
	case 4:
		(*contadorConmebol)++;
		break;
	case 5:
		(*contadorUefa)++;
		break;
	case 6:
		(*contadorOfc)++;
		break;
	}
	informe_Confederacion(*contadorAfc, *contadorCaf, *contadorConcaf, *contadorConmebol, *contadorUefa, *contadorOfc);
	retorno=0;


	}
	return retorno;
}

int Carga_Posicion(int *contadorArqueros, int *contadorDefensores,
		int *contadorMediocampistas, int *contadorDelanteros,
		int *contadorJugadores)
{
	int posicion;
	int retorno = -1;
	if (contadorArqueros != NULL && contadorDefensores != NULL
			&& contadorDelanteros != NULL && contadorMediocampistas != NULL) {
		informe_Posicion((*contadorArqueros),(*contadorDefensores),(*contadorMediocampistas),(*contadorDelanteros));
		utn_getNumero(&posicion, "\nIngrese la posicion: "
				"\n1.Arqueros"
				"\n2.Defensores"
				"\n3.Mediocampistas"
				"\n4.Delanteros", "\nERRORIngrese la posicion: ", 1, 4,5);

		switch (posicion) {
		case 1:
			if (*contadorArqueros < 2) {
				(*contadorArqueros)++;
				(*contadorJugadores)++;
			} else {
				printf("\nNo se puede continuar cargando Arqueros\n");
			}
			break;
		case 2:
			if (*contadorDefensores < 8) {
				(*contadorDefensores)++;
				(*contadorJugadores)++;
			} else {
				printf("\nNo se puede continuar cargando Defensores\n");
			}

			break;
		case 3:
			if (*contadorMediocampistas < 8) {
				(*contadorMediocampistas)++;
				(*contadorJugadores)++;
			} else {
				printf("\nNo se puede continuar cargando Mediocampistas\n");
			}
			break;
		case 4:
			if (*contadorDelanteros < 4) {
				(*contadorDelanteros)++;
				(*contadorJugadores)++;
			} else {
				printf("\nNo se puede continuar cargando Delanteros");
			}
			break;
		}
		informe_Posicion((*contadorArqueros),(*contadorDefensores),(*contadorMediocampistas),(*contadorDelanteros));
		retorno = 0;

	}
	return retorno;
}

