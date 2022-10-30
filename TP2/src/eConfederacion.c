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

		listaConfederaciones(tipos,size);
		utn_getNumero(&auxiliar.id, "INGRESE ID: ", "ERROR!INGRESE ID:", 100, 105, 10);
		return auxiliar;
}

int buscarTipos(eConfederacion *tipos,int size,int idSectores,char *descripcion)
{
	int i;
	int retorno = 0;

	if(tipos != NULL && descripcion  != NULL && size > 0)
	{
	for (i = 0; i < size; i++) {
		if ((*(tipos + i)).id == idSectores)
		{
			strcpy(descripcion,(*(tipos+i)).nombre);//DEVUELVE LA DESCRIPCION
		}
	}
	retorno = 1;
	}
	return retorno;
}
void listaConfederaciones(eConfederacion *tipos,int size)
{
	printf("=============================================================================\n"
		   "|%-8s|%-20s|%-28s|%-16s\n",
		   "ID","CONFEDERACION","REGION","AÑO DE CREACION |"
		   "\n----------------------------------------------------------------------------");
	for(int i=0;i<size;i++)
	{
		printf(
			   "|%-8d|%-20s|%-28s|%-16d|\n"
			  ,tipos[i].id,tipos[i].nombre,tipos[i].region,tipos[i].anioCreacion
			   );
	}
	printf("=============================================================================\n");
}



