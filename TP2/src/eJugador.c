/*
 * eJugador.c
 *
 *  Created on: 25 oct 2022
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


//MENU
int menu(void)
{
	int opcion;
	printf("-----------------------------------"
			   "\n|1.ALTA DE JUGADOR                |"
			   "\n|2.BAJA DE JUGADOR                |"
			   "\n|3.MODIFICACION DE JUGADOR        |"
			   "\n|4.INFORMES                       |"
			   "\n|5.SALIR:                         |"
			   );
	utn_getNumero(&opcion, "\n|INGRESE OPCION:                  |\n", "ERROR ! ", 1, 5, 200);

	return opcion;
}
int eStr_Alta(eJugador* puntJugador,int tamJugador,eConfederacion *pTipos,int tamConfe,int* id)
{
	int rtn = 0;
	eJugador auxJugador;
	int index;

	if(puntJugador != NULL && pTipos != NULL && tamConfe >= 0 && tamJugador >= 0)
	{
		index = eStr_ObtenerIndexLibre(puntJugador,tamJugador);

	    if (index != -1)
		{
			auxJugador = eStr_CargarDatos();
			auxJugador.idConfederacion = eStr_AltaConfederacion(pTipos,tamConfe);
			auxJugador.id = (*id)++;
			auxJugador.isEmpty = BUSSY;
			*(puntJugador+index) = auxJugador;

			puts("¿DESEA CONTINUAR CON LA ALTA?");

			if(utn_getCaracterSN()==0)
			{
				eStr_MostrarTodos(puntJugador,tamJugador,pTipos,tamConfe);
			rtn = 1;
			}
		}
	}
	return rtn;
}
int eStr_Baja(eJugador *jugador, int size, eConfederacion *tipos,int tam)
{
	int rtn = 0;
	int idJugador;
	int index;
	int flag = 0;
	if (jugador != NULL && tipos !=NULL && tam > 0 && size > 0 )
	{

	if (eStr_MostrarTodos(jugador, size, tipos, tam)) {

		flag = 1;
	}
	if (flag)
	{
		utn_getNumero(&idJugador, "\nINGRESE ID DEL JUGADOR A DAR BAJA: ","\nERROR ! INGRESE ID DE JUGADOR A DAR BAJA: ", 0, 5000,100);

		while (eStr_BuscarPorID(jugador, size, idJugador) == -1)
		{
			puts("NO EXISTE ID.");
			utn_getNumero(&idJugador, "\nINGRESE ID JUGADOR A DAR BAJA: ","\nERROR!INGRESE ID JUGADOR A DAR BAJA: ", 1000, 4000,20);
		}
		index = eStr_BuscarPorID(jugador, size,idJugador);
		puts("¿DESEA CONTINUAR CON LA BAJA?");
		if (utn_getCaracterSN() == 0)
		{
			(*(jugador + index)).isEmpty = BAJA;
			rtn = 1;
		}
	}
	}
	else
	{
		printf("PRIMERO DEBE DAR UN ALTA");
	}

	return rtn;
}
int eStr_ObtenerIndexLibre(eJugador*unJugador,int tam)
{
	int rtn = -1;
	int i;
	if (unJugador != NULL && tam > 0)
	{
		for (i = 0; i < tam; i++) {
			if ((*(unJugador + i)).isEmpty == FREE)
			{
				rtn = i;
				break;
			}
		}
	}
	return rtn;
}
eJugador eStr_CargarDatos(void) {
	eJugador auxiliar;
	int posicion;
		utn_getNombre(auxiliar.nombre, "\nINGRESE NOMBRE DE JUGADOR: ", "ERROR!", 3, 50);

		utn_getNumero(&posicion, "1. Arquero\n2. Defensor\n3. Mediocampista\n4. Delantero\nIngrese numero de posicion: ", "Error, reingrese numero de posicion: ", 1, 4,200);
			switch(posicion)
			{
			case 1:
				strcpy(auxiliar.posicion, "Arquero");
				break;
			case 2:
				strcpy(auxiliar.posicion, "Defensor");
				break;
			case 3:
				strcpy(auxiliar.posicion, "Mediocampista");
				break;
			case 4:
				strcpy(auxiliar.posicion, "Delantero");
				break;
			}
		utn_getShort(&auxiliar.numeroCamiseta, "\nINGRESE NUMERO DE CAMISETA: ", "\nERROR!INGRESE NUMERO DE CAMISETA;",0,100,5);

		utn_getNumeroFlotante(&auxiliar.salario, "\nINGRESE SALARIO: ","ERROR! \nINGRESE SALARIO: ",0, 32100000, 50);

		utn_getShort(&auxiliar.aniosContrato,"\nINGRESE ANIOS DE CONTRATO: ", "\nINGRESE ANIOS DE CONTRATO: ", 0, 100, 20);

		return auxiliar;
}
void eStr_MostrarUno(eJugador unJugador,eConfederacion*tipos,int tam)
{
	char descripcion[70];

	if (unJugador.isEmpty == BUSSY && tipos != NULL && tam > 0 )
	{
		{
		if (cargarDescripcionConfederacion(tipos,tam,unJugador.idConfederacion,descripcion)== 1)
		{
			printf("| %d  | %-50s | %-20s | %-15d | %-15.2f | %-20s |  %-15d|\n"
					,unJugador.id, unJugador.nombre, unJugador.posicion
					,unJugador.numeroCamiseta,unJugador.salario,descripcion,unJugador.aniosContrato);

			}
		}
	}
}
int eStr_MostrarTodos(eJugador*unJugador,int tam,eConfederacion*tipos,int size)
{
	int i;
	int rtn = 0;
	int cantidad = 0;

	printf("                                          *** LISTA DE JUGADORES ***\n");
		printf("--------------------------------------------------------------------------------------------------------------------------------------------------------------\n");
		printf("| ID |                     NOMBRE                         |       POSICION       |  N DE CAMISETA  |     SUELDO      |     CONFEDERACION    | ANIOS CONTRATO |\n");
		printf("--------------------------------------------------------------------------------------------------------------------------------------------------------------\n");

	if (unJugador != NULL && tipos !=NULL&& tam > 0) {
		for (i = 0; i < tam; i++) {
			if ((*(unJugador + i)).isEmpty == BUSSY)
			{
				eStr_MostrarUno((*(unJugador + i)),tipos,size);
				cantidad++;
			}
		}
		printf("--------------------------------------------------------------------------------------------------------------------------------------------------------------\n");
	}
	if (cantidad > 0) {
		rtn = 1;
	}

	return rtn;
}

eJugador eStr_ModificarUno(eJugador unJugador)
{
	eJugador auxiliar = unJugador;
	int opcion;
	int posicion;
	opcion = menuModificacion();
	switch (opcion)
	{
	case 1:
		utn_getNombre(auxiliar.nombre,"\nIngrese Nombre: ","\nERROR!Ingrese Nombre Valido: ", 100, 50);
		break;
	case 2:
		utn_getNumero(&posicion, "1. Arquero\n2. Defensor\n3. Mediocampista\n4. Delantero\nIngrese numero de posicion: ", "Error, reingrese numero de posicion: ", 1, 4,1000);
					switch(posicion)
					{
					case 1:
						strcpy(auxiliar.posicion, "Arquero");
						break;
					case 2:
						strcpy(auxiliar.posicion, "Defensor");
						break;
					case 3:
						strcpy(auxiliar.posicion, "Mediocampista");
						break;
					case 4:
						strcpy(auxiliar.posicion, "Delantero");
						break;
					}
		break;
	case 3:
		utn_getShort(&auxiliar.numeroCamiseta, "\nIngrese Numero de Camiseta: ", "\nIngrese Numero de Camiseta: ",0,100,5);
		break;
	case 4:
		utn_getNumero(&auxiliar.id, "Funcion de confederacion ", "ERROR!! Funcion de confederacion ", 100, 105, 10);
		break;
	case 5:
		utn_getNumeroFlotante(&auxiliar.salario, "\nIngrese Salario: ","\nERROR! Ingrese Salario: ",0, 32100000, 50);
		break;
	case 6:
		utn_getShort(&auxiliar.aniosContrato,"\nINGRESE AÑOS DE CONTRATO: ", "\nINGRESE ANIOS DE CONTRATO: ", 0, 100, 20);
		break;
	}
	return auxiliar;
}

int eStr_Modificacion(eJugador* unJugador,int tam,eConfederacion*tipos,int size)
{
	int rtn = 0;
	int iD;
	int index;
	int flag = 0;
	eJugador auxiliar;

	if( unJugador != NULL && tipos !=NULL && tam > 0 && size > 0 )
	{
		if (eStr_MostrarTodos(unJugador,tam,tipos,size))
		{
		//BANDERA EN 1 SI HAY JUGADORES DADOS DE ALTA PARA LISTAR
			flag = 1;
		}
		if (flag)
		{
		printf("\nINGRESE ID DE JUAGADOR A MODIFICAR: ");
		getInt(&iD);


		while (eStr_BuscarPorID(unJugador,size,iD) == -1) {
			puts("\nNO EXISTE ID.");

			utn_getNumero(&iD,"\nINGRESE ID DE JUAGADOR A MODIFICAR: ","\nERROR INGRESE ID DE JUAGADOR A MODIFICAR: ",0, 99999999,5000);
		}
		index = eStr_BuscarPorID(unJugador, size, iD);
		auxiliar = eStr_ModificarUno((*(unJugador + index)));
		puts("¿DESEA CONTINUAR LA MODIFICACION?");
			if (utn_getCaracterSN() == 0)
			{
			*(unJugador + index) = auxiliar;
			rtn = 1;
			}
		}
	}
	return rtn;
}
int eStr_BuscarPorID(eJugador* unJugador,int tam,int iD)
{
	int rtn = -1;
	int i;

	if (unJugador != NULL && tam > 0) {
		for (i = 0; i < tam; i++)
		{
			if ((*(unJugador + i)).id == iD&& (*(unJugador + i)).isEmpty == BUSSY)
			{
				rtn = i;
				break;
			}
		}
	}

	return rtn;
}
int menuModificacion(void)
{
	int opcion;
	utn_getNumero(&opcion, "Menu modificaciones\n "
			   "\n1.Modificar Nombre"
			   "\n2.Modificar Posicion"
			   "\n3.Modificar Numero de Camiseta"
			   "\n4.Modificar Confederacion"
			   "\n5.Modificar Salario"
			   "\n6.Modificar Años de Contrato"
			   "\nINGRESE UNA OPCION: ", "ERROR! Ingrese opcion valida:",1,6,20);

	return opcion;
}
void mostrarPersona(eJugador p, eConfederacion confederaciones[], int size_conf){
	char descConfederacion[20];

	if(cargarDescripcionConfederacion(confederaciones, size_conf, p.idConfederacion, descConfederacion) == 1){

	printf("│  %2d  │  %20s    │   %15s   │    %2d      │  %8.2f  │  %13s │      %2d        │\n",
			p.id,
			p.nombre,
			p.posicion,
			p.numeroCamiseta,
			p.salario,
			descConfederacion,
			p.aniosContrato
		   );
	}
}
int mostrarPersonas(eJugador lista[], int size, eConfederacion confederaciones[], int size_conf){
	int todoOk = 1;
	int flag = 1;
	if(lista != NULL && size > 0 && confederaciones != NULL && size_conf > 0){
		/*system("cls");*/
		printf("                                               ***** Lista de jugadores *****     \n");
		printf("=====================================================================================================================\n");
		printf("│  ID  │         NOMBRE           │       POSICION      │ N°CAMISETA │   SUELDO   │ CONFEDERACION  │ ANIOS CONTRATO │\n");
		printf("---------------------------------------------------------------------------------------------------------------------\n");
		for(int i = 0; i < size; i++){
			if(lista[i].isEmpty == 0){
				mostrarPersona(lista[i], confederaciones, size_conf);
				flag = 0;
			}
		}
		if(flag == 1){
			printf("No hay jugadores para mostrar\n");
		}
		printf("======================================================================================================================\n");
		todoOk = 1;
	}
	return todoOk;
}
