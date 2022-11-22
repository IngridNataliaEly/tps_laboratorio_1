#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "Jugador.h"
#include "utn.h"

Jugador* jug_new()
{
	Jugador* auxiliaP = NULL;
	auxiliaP = (Jugador*) malloc(sizeof(Jugador));
	return auxiliaP;
}
Jugador* jug_newParametros(char* idStr,char* nombreCompletoStr,char* edadStr, char* posicionStr, char* nacionalidadStr, char* idSelccionStr)
{
	Jugador *this ;
	this = jug_new();
	if (this != NULL && idStr != NULL && nombreCompletoStr != NULL && edadStr != NULL && posicionStr != NULL && nacionalidadStr != NULL && idSelccionStr != NULL)
	{

			 if(jug_setId(this, atoi(idStr))== -1 ||
				jug_setNombreCompleto(this, nombreCompletoStr)== -1 ||
				jug_setEdad(this,atoi(edadStr)) == -1||
				jug_setPosicion(this, posicionStr)== -1 ||
				jug_setNacionalidad(this, nacionalidadStr)== -1 ||
				jug_setIdSeleccion(this, atoi(idSelccionStr))== -1 )
				{
				 jug_delete(this);
				 this = NULL;
				}
			 else
				{

				}
	}
	return this;
}


void jug_delete(Jugador* this)
{
	if (this != NULL) {
		free(this);
	}
}
int jug_setId(Jugador* this,int id)
{
	int retorno = -1;
	if (this != NULL && id >= 0)
	{

		retorno = 0;
		this->id = id;
	}
	return retorno;
}
int jug_getId(Jugador* this,int* id)
{
	int retorno = -1;
	if (this != NULL && id != NULL) {
		retorno = 0;
		*id = this->id;
	}
	return retorno;
}

int jug_setNombreCompleto(Jugador* this,char* nombreCompleto)
{
	int retorno = -1;
	if (this != NULL && nombreCompleto != NULL) //validar no estar cargando algo que esta mal.
	{

		if (!esNombre(nombreCompleto,100)) {

			retorno = 0;
			strncpy(this->nombreCompleto,nombreCompleto,100); //Unico lugar donde accedo a este campo en ningun otro

		}
	}
	return retorno;
}
int jug_getNombreCompleto(Jugador* this,char* nombreCompleto)
{
	int retorno = -1;

	if (this != NULL && nombreCompleto != NULL)
	{
		retorno = 0;
		strncpy(nombreCompleto, this->nombreCompleto,100);
	}
	return retorno;
}

int jug_setPosicion(Jugador* this,char* posicion)
{
	int retorno = -1;
		if (this != NULL && posicion != NULL) //validar no estar cargando algo que esta mal.
		{

			if (!esPosicion(posicion, 30))
			{

				retorno = 0;
				strncpy(this->posicion,posicion,30); //Unico lugar donde accedo a este campo en ningun otro
			}
		}
		return retorno;
}
int jug_getPosicion(Jugador* this,char* posicion)
{
	int retorno = -1;

	if (this != NULL && posicion != NULL)
		{
			retorno = 0;
			strncpy(posicion, this->posicion,30);
		}
		return retorno;
}

int jug_setNacionalidad(Jugador* this,char* nacionalidad)
{
	int retorno = -1;
	if (this != NULL && nacionalidad != NULL) //validar no estar cargando algo que esta mal.
	{

		if (!esNombre(nacionalidad,30))
		{
			retorno = 0;
			strncpy(this->nacionalidad,nacionalidad,30); //Unico lugar donde accedo a este campo en ningun otro
		}
	}
		return retorno;
}
int jug_getNacionalidad(Jugador* this,char* nacionalidad)
{
	int retorno = -1;

		if (this != NULL && nacionalidad != NULL)
		{
			retorno = 0;
			strncpy(nacionalidad, this->nacionalidad,30);
		}
		return retorno;
}
int jug_setEdad(Jugador* this,int edad)
{
	int retorno = -1;
		if (this != NULL && edad >= 0)
		{
			retorno = 0;
			this->edad = edad;
		}
		return retorno;
}
int jug_getEdad(Jugador* this,int* edad)
{
	int retorno = -1;
		if (this != NULL && edad != NULL) {
			retorno = 0;
			*edad = this->edad;
		}
		return retorno;
}

int jug_setIdSeleccion(Jugador* this,int idSeleccion)
{
	int retorno = -1;
	if (this != NULL && idSeleccion >= 0)
	{
		retorno = 0;
		this->idSeleccion = idSeleccion;
	}
	return retorno;
}
int jug_getSIdSeleccion(Jugador* this,int* idSeleccion)
{
	int retorno = -1;
	if (this != NULL && idSeleccion != NULL) {
		retorno = 0;
		*idSeleccion = this->idSeleccion;
	}
	return retorno;
}


