/*
 * eConfederacion.c
 *
 *  Created on: 24 oct 2022
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


int menuModificarConf(){
	int opcion;
	printf("Ingrese el dato que desea modificar: \n");
	printf("1- Nombre\n");
	printf("2- Region\n");
	printf("3- Año\n");
	printf("4- Salir\n");
	printf("Ingrese opcion: ");
	scanf("%d", &opcion);

	return opcion;
}
int eStr_AltaConfederacion(eConfederacion*tipos,int size)
{

	int id;
	eConfederacion auxiliar;
	if(tipos != NULL)
	{
		auxiliar = eStr_CargarDatosConfederacion(tipos,size);

				(*tipos).id = auxiliar.id;
				id=(*tipos).id;
	}

	return id;
}

eConfederacion eStr_CargarDatosConfederacion(eConfederacion *tipos,int size)
{
	eConfederacion auxiliar;

		mostrarConfederaciones(tipos,size);
		utn_getNumero(&auxiliar.id, "INGRESE ID: ", "ERROR!INGRESE ID:", 100, 105, 10);
		return auxiliar;
}





int buscarConfederacionId(eConfederacion confederaciones[],int Id, int size_conf){
	int indice = -1;
	if(confederaciones != NULL && size_conf > 0){
		for(int i = 0; i < size_conf; i++){
			if( confederaciones[i].id == Id){
				indice = i;
				break;
			}
		}
	}
	return indice;
}

int cargarDescripcionConfederacion(eConfederacion confederaciones[], int size,int idConfederacion, char descripcion[]){
	int todoOk = -1;
	int flag = 1;
	if(confederaciones != NULL && size > 0 && descripcion != NULL){

		todoOk = 1;
		for(int i = 0; i < size; i++){
			if(confederaciones[i].id == idConfederacion){
				strcpy(descripcion, confederaciones[i].nombre);
				flag = 0;
				break;
			}
		}
		if(flag){
			todoOk = 1;
		}
	}
	return todoOk;
}

void mostrarConfederacion(eConfederacion confederacion){
	printf("│   %d │ %9s    │   %23s  │     %d     │\n",
			confederacion.id,
			confederacion.nombre,
			confederacion.region,
			confederacion.anioCreacion
		   );
}

int mostrarConfederaciones(eConfederacion confederaciones[], int size){
	int todoOk = 0;
	if(confederaciones != NULL && size > 0){
		printf("                  ***** Confederaciones *****     \n");
		printf("====================================================================\n");
		printf("│  ID   │     NOMBRE   │         REGION             │ AÑO CREACION │\n");
		printf("--------------------------------------------------------------------\n");
		for(int i = 0; i < size; i++){
				mostrarConfederacion(confederaciones[i]);
		}
		printf("====================================================================\n");
		todoOk = 1;
	}
	return todoOk;
}

int validarIdConfederacion(int id, eConfederacion confederaciones[], int size){
	int todoOk = 0;
	if(confederaciones != NULL && size > 0){
		for(int i = 0; i < size; i++){
			if(confederaciones[i].id == id){
				todoOk = 1;
			}
		}
	}
	return todoOk;
}

