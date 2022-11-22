/*
 * Informes.c
 *
 *  Created on: 22 nov 2022
 *      Author: natal_000
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

int subMenuInformes(void)
{
	int retorno;
	printf("-------------------------------------------------------------------------------"
	       "\n|1.Listado de los jugadores ordenados alfabéticamente.                        |"
		   "\n|2.Listado de confederaciones con sus jugadores.                              |"
		   "\n|3.Total y promedio de todos los salarios                                     |"
		   "\n|4.Confederación con mayor cantidad de años de contratos total                |"
		   "\n|5.Informar porcentaje de jugadores por cada confederación                    |"
		   "\n|6.Informar cual es la región con más jugadores y el listado de los mismos.   |\n"
		   "-------------------------------------------------------------------------------"
				   );
		utn_getNumero(&retorno, "\n|INGRESE OPCION:                  |\n", "ERROR ! ", 1, 5, 200);




	return retorno;
}
int mostrarInformes(eJugador lista[], int size, eConfederacion confederaciones[], int size_conf){
	int todoOk = 0;
	int opcion;
	utn_getNumero(&opcion, "-------------------------------------------------------------------------------"
		       "\n|1.Listado de los jugadores ordenados alfabéticamente.                        |"
			   "\n|2.Listado de confederaciones con sus jugadores.                              |"
			   "\n|3.Total y promedio de todos los salarios                                     |"
			   "\n|4.Confederación con mayor cantidad de años de contratos total                |"
			   "\n|5.Informar porcentaje de jugadores por cada confederación                    |"
			   "\n|6.Informar cual es la región con más jugadores y el listado de los mismos.   |\n"
			   "--------------------------------------------------------------------------------\n", "ERROR", 1, 6, 11000);
	if(lista != NULL && size > 0 && confederaciones != NULL && size_conf > 0){
		switch(opcion)
		{
			case 1:

				ordenarPersonasConfederacionNombreAlfabeticamente(lista, size, confederaciones, size_conf);
				eStr_MostrarTodos(lista, size, confederaciones, size_conf);
				break;
			case 2:

				informarConfederacionesConJugadores(lista, size, confederaciones, size_conf);
				break;
			case 3:

				informarTotalPromedioSalarios(lista, size);
				break;
			case 4:
				informarConfederacionMayorCantidadAniosContratoTotal(lista, size, confederaciones, size_conf);
				break;
			case 5:
				informarPorcentajeJugadoresPorConfederacion(lista, size, confederaciones, size_conf);
				break;
			case 6:
				informarRegionConMasJugadoresListar(lista, size, confederaciones, size_conf);
				break;
			case 7:
				//OPCION 7: SALIR
				printf("Volvio al menu\n");
				break;
			default:
				printf("Opcion Invalida!!!\n");
		}
		todoOk = 1;
	}
	return todoOk;
}
//OPCION 1:Listado jugadores ordenados alfabeticamente por nombre confederacion y nombre jugador
int ordenarPersonasConfederacionNombreAlfabeticamente(eJugador lista[], int size, eConfederacion confederaciones[], int size_conf){
	int retorno = 0;
	eJugador auxJugador;
	char descConfederacionI[20];
	char descConfederacionJ[20];
	if(lista != NULL && size > 0 && confederaciones != NULL && size_conf > 0){
		for(int i = 0; i < size-1; i++){
			for(int j = i+1; j < size; j++){

				cargarDescripcionConfederacion(confederaciones, size_conf, lista[i].idConfederacion, descConfederacionI);
				cargarDescripcionConfederacion(confederaciones, size_conf, lista[j].idConfederacion, descConfederacionI);
				if( strcmp(descConfederacionI, descConfederacionJ) > 0
				 || (strcmp(descConfederacionI, descConfederacionJ) == 0
				 && strcmp(lista[i].nombre, lista[j].nombre) > 0)	){
				   	auxJugador = lista[i];
					lista[i] = lista[j];
					lista[j] = auxJugador;
				}
			}
		}
		retorno = 1;
	}
	return retorno;
}
//OPCION 2:Listado de confederaciones con sus jugadores
int mostrarPersonasIdConfederacion(int idConfederacion, eJugador lista[], int size, eConfederacion confederaciones[], int size_conf){
	int todoOk = 0;
	char descConfederacion[20];
	int flag = 0;
	if(lista != NULL && size > 0 && confederaciones != NULL && size_conf > 0){
		printf("=====================================================================================================================\n");
		printf("│  ID  │         NOMBRE           │       POSICION      │ N°CAMISETA │   SUELDO   │ CONFEDERACION  │ ANIOS CONTRATO │\n");
		printf("---------------------------------------------------------------------------------------------------------------------\n");
		for(int i = 0; i < size; i++){
			if(lista[i].isEmpty == BUSSY && lista[i].idConfederacion == idConfederacion){
				mostrarPersona(lista[i], confederaciones, size_conf);
				flag = 1;
			}
		}
		if(flag == 0){
			cargarDescripcionConfederacion(confederaciones, size_conf, idConfederacion, descConfederacion);
			printf("No hay personas en %s\n", descConfederacion);
		}
		todoOk = 1;
	}
	return todoOk;
}
//OPCION 2:Listado de confederaciones con sus jugadores
int informarConfederacionesConJugadores(eJugador lista[], int size, eConfederacion confederaciones[], int size_conf){
	int todoOk = 0;
	if(lista != NULL && size > 0 && confederaciones != NULL && size_conf > 0){
		system("cls");
		printf("                                            ***** Jugadores por cada confederacion *****   \n");
		for(int i = 0; i < size_conf; i++){
				printf("\n");
				printf("CONFEDERACION: %s\n", confederaciones[i].nombre);
				mostrarPersonasIdConfederacion(confederaciones[i].id, lista, size, confederaciones, size_conf);
				printf("=====================================================================================================================\n");
		}
		todoOk = 1;
	}
	return todoOk;
}

//OPCION 3: Total y promedio de salarios y listado de jugadores que superan ese salario.
int informarTotalPromedioSalarios(eJugador lista[], int size){
	int todoOk = 0;
	int contador = 0;
	float acumulador = 0;
	float promedio;
	if(lista != NULL && size > 0){
		for(int i = 0; i < size; i++){
			if(lista[i].isEmpty == BUSSY){
				acumulador = acumulador + lista[i].salario;
				contador++;
			}
		}
		printf("       *** Total y promedio de todos los salarios y jugadores que cobran mas que el salario promedio ***     \n\n");
		promedio = acumulador / contador;
		printf("Total sueldos: %.2f\n", acumulador);
		printf("Promedio sueldos: %.2f\n", promedio);
		printf("Nombre jugadores salario mas alto que el promedio: \n");
		for(int i = 0; i < size; i++){
			if(lista[i].isEmpty == BUSSY && lista[i].salario > promedio ){
				printf("%s\n", lista[i].nombre);
			}
		}
		todoOk = 1;
	}
	return todoOk;
}

//OPCION 4: INFORMAR CONFEDERACION CON MAYOR CANTIDAD DE AÑOS DE CONTRATOS TOTAL
int informarConfederacionMayorCantidadAniosContratoTotal(eJugador lista[], int size, eConfederacion confederaciones[], int size_conf){
	int todoOk = 0;
	int acumuladores[] = {0,0,0,0,0,0};
	int maximo;
	int flag = 0;
	if(lista != NULL && size > 0 && confederaciones != NULL && size_conf > 0){
		system("cls");
		printf("                *** Confederacion con mayor cantidad de anios de contratos total ***            \n");
		for(int i = 0; i < size_conf; i++){
			for(int j = 0; j < size; j++){
				if(lista[j].isEmpty == BUSSY && confederaciones[i].id == lista[j].idConfederacion){
					acumuladores[i] = acumuladores[i] + lista[j].aniosContrato;
				}
			}
		}

		for(int i = 0; i < size_conf; i++){
			if(flag == 0 || acumuladores[i] > maximo){
				maximo = acumuladores[i];
				flag = 1;
			}
		}

		for(int i = 0; i < size_conf; i++){
			if(acumuladores[i] == maximo){
				printf("%s\n", confederaciones[i].nombre);
			}
		}
		todoOk = 1;
	}
	return todoOk;
}

//OPCION 5: INFORMAR PORCENTAJE DE JUGADORES POR CADA CONFEDERACION


int informarPorcentajeJugadoresPorConfederacion(eJugador lista[], int size, eConfederacion confederaciones[], int size_conf){
	int todoOk = 0;
	int contadores[] = {0,0,0,0,0,0};
	int contadorTotalJugadores = 0;
	float porcentajePorConfederacion;

	if(lista != NULL && size > 0 && confederaciones != NULL && size_conf > 0){
		system("cls");
		printf("                *** Porcentaje de jugadores por cada Confederacion ***            \n");
		for(int i = 0; i < size_conf; i++){
			for(int j = 0; j < size; j++){
				if(lista[j].isEmpty == BUSSY && confederaciones[i].id == lista[j].idConfederacion){
					contadores[i] ++;
				}
			}
		}
		for(int i = 0; i < size_conf; i++){
			porcentajePorConfederacion = (float)contadores[i] * 100 / contadorTotalJugadores;
			printf("%s: %.2f\n", confederaciones[i].nombre, porcentajePorConfederacion);
		}

		todoOk = 1;
	}
	return todoOk;
}
/*----------------------------------------------------------------------------------*/
//OPCION 6: INFORMAR REGION CON MAS JUGADORES Y LISTADOS DE LOS MISMOS
int informarRegionConMasJugadoresListar(eJugador lista[], int size, eConfederacion confederaciones[], int size_conf){
	int todoOk = 0;
	int contadores[] = {0,0,0,0,0,0};
	int maximo;
	int flag = 0;
	if(lista != NULL && size > 0 && confederaciones != NULL && size_conf > 0){
		system("cls");
		printf("                                             *** Region con mas jugadores ***                       \n");
		for(int i = 0; i < size_conf; i++){
			for(int j = 0; j < size; j++){
				if(lista[j].isEmpty == BUSSY && confederaciones[i].id == lista[j].idConfederacion){
					contadores[i]++;
				}
			}
		}

		for(int i = 0; i < size_conf; i++){
			if(flag == 0 || contadores[i] > maximo){
				maximo = contadores[i];
				flag = 1;
			}
		}

		for(int i = 0; i < size_conf; i++){
			if(contadores[i] == maximo){
				printf("%s\n", confederaciones[i].region);
				mostrarPersonasIdConfederacion(confederaciones[i].id, lista, size, confederaciones, size_conf);
			}
		}
		todoOk = 1;
	}
	return todoOk;
}


