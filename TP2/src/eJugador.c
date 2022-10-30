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




static int eStr_ObtenerID(void);
static int eStr_ObtenerID(void) {
	static int idjugador = 0;
	return idjugador++;
}
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
int eStr_Alta(eJugador*unJugador,int tam,eConfederacion *tipos,int size)
{
	int rtn = 0;
	eJugador auxJugador;
	int index;

	if(unJugador != NULL)
	{
		index = eStr_ObtenerIndexLibre(unJugador,tam);

	    if (index != -1)
		{
			auxJugador = eStr_CargarDatos();
			auxJugador.idConfederacion = eStr_AltaConfederacion(tipos,size);
			auxJugador.id = eStr_ObtenerID();
			auxJugador.isEmpty = BUSSY;
			*(unJugador+index) = auxJugador;

			puts("¿DESEA CONTINUAR CON LA ALTA?");

			if(utn_getCaracterSN()==0)
			{
				eStr_MostrarTodos(unJugador,tam,tipos,size);
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

		utn_getNombre(auxiliar.nombre, "\nINGRESE NOMBRE DE JUGADOR: ", "ERROR!", 3, 50);

		utn_getNombre(auxiliar.posicion, "\nINGRESE POSICION DEL JUGADOR: ","\nERROR! INGRESE POSICION DEL JUGADOR:  ", 5,25);

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
		if (buscarTipos(tipos,tam,unJugador.id,descripcion)== 1)
		{
			printf("\n|%-8d|%-16s|%-10s|%-8h|%-20c|%-8s|%-8h|"
					,unJugador.id, unJugador.nombre, unJugador.posicion
					,unJugador.numeroCamiseta,descripcion,unJugador.salario,unJugador.aniosContrato);
			}
		}
	}
}
int eStr_MostrarTodos(eJugador*unJugador,int tam,eConfederacion*tipos,int size)
{
	int i;
	int rtn = 0;
	int cantidad = 0;

	puts("\n\t> LISTADO DE JUGADORES");
	printf("================================================================================================\n"
		   "|%-8s|%-16s|%-10s|%-4s|%-16s|%-8s|%-20s|",
		   "ID","NOMBRE","POSICION","N º CAMISETA","CONFEDERACION","SALARIO","AÑOS de CONTRATO"
		 "\n------------------------------------------------------------------------------------------------");
	if (unJugador != NULL && tipos !=NULL&& tam > 0) {
		for (i = 0; i < tam; i++) {
			if ((*(unJugador + i)).isEmpty == BUSSY)
			{
				eStr_MostrarUno((*(unJugador + i)),tipos,size);
				cantidad++;
			}
		}
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
	opcion = menuModificacion();
	switch (opcion)
	{
	case 1:
		utn_getNombre(auxiliar.nombre,"\nIngrese Nombre: ","\nERROR!Ingrese Nombre Valido: ", 100, 50);
		break;
	case 2:
		utn_getString(auxiliar.posicion, "\nIngrese Posicion: ", "\nERROR!Ingrese Posicion Valida: ", 100);
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
void mostrarInformes(int opcion){

}
int litadoConfederaciones(eJugador* unJugador,int tam,eConfederacion*tipos,int size)
{
	printf("|%-16s|%-20s |"
			,"CONFEDERACION","NOMBRE JUGADOR"
			"\n-----------------------------------------------------");
	for (int i=0;i<size;i++)
		{
			printf("|%-16s|%-20s|",);
		}
}
