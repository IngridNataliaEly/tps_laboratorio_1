#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "Seleccion.h"
#include "utn.h"


Seleccion* selec_new()
{
	Seleccion* auxiliaS = NULL;
	auxiliaS = (Seleccion*) malloc(sizeof(Seleccion));
	return auxiliaS;
}
Seleccion* selec_newParametros(char* idStr,char* paisStr,char* confederacionStr, char* convocadosStr)
{
	Seleccion *this ;
	this = selec_new();
	if (this != NULL && idStr != NULL && paisStr != NULL && confederacionStr != NULL && convocadosStr != NULL )
	{
				 if(selec_setId(this,atoi(idStr))== -1 ||
					selec_setPais(this,paisStr)== -1 ||
					selec_setConfederacion(this, confederacionStr) == -1||
					selec_setConvocados(this,atoi(convocadosStr))== -1  )
					{
					 selec_delete(this);
					 this = NULL;
					 printf("Error carga seleccion");
					}
				 else
					{
					 	 printf("\ncarga OK selecion\n ");
					}
	}
	return this;
}
void selec_delete(Seleccion* this)
{
	if (this != NULL)
	{
		free(this);
	}
}
int selec_setId(Seleccion* this,int id)
{
	int retorno = -1;
		if (this != NULL && id >= 0)
		{
			retorno = 0;
			this->id= id;
		}
		return retorno;
}
int selec_getId(Seleccion* this,int* id)
{
	int retorno = -1;
		if (this != NULL && id != NULL) {
			retorno = 0;
			*id = this->id;
		}
		return retorno;
}

int selec_setPais(Seleccion* this,char* pais)
{
	int retorno = -1;
	if (this != NULL && pais != NULL)
	{
		if (!esNombre(pais, 30))
		{
			retorno = 0;
			strncpy(this->pais, pais, 30);
		}
	}
	return retorno;
}
int selec_getPais(Seleccion* this,char* pais)
{
	int retorno = -1;

			if (this != NULL && pais != NULL)
			{
				retorno = 0;
				strncpy(pais, this->pais,30);
			}
			return retorno;
}

int selec_setConfederacion(Seleccion* this,char* confederacion)
{
	int retorno = -1;
	if (this != NULL && confederacion != NULL)
	{
		if (!esNombre(confederacion, 30)) {
			retorno = 0;
			strncpy(this->confederacion, confederacion, 30);
		}
	}
	return retorno;
}
int selec_getConfederacion(Seleccion* this,char* confederacion)
{
	int retorno = -1;

	if (this != NULL && confederacion != NULL) {
		retorno = 0;
		strncpy(confederacion, this->confederacion, 30);
	}
	return retorno;
}

int selec_setConvocados(Seleccion* this,int convocados)
{
	int retorno = -1;
	if (this != NULL && convocados >= 0) {
		retorno = 0;
		this->convocados = convocados;
	}
	return retorno;
}
int selec_getConvocados(Seleccion* this,int* convocados)
{
	int retorno = -1;
	if (this != NULL && convocados != NULL) {
		retorno = 0;
		*convocados = this->convocados;
	}
	return retorno;
}
