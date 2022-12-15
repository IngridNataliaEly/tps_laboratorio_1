/*
 * utn.c
 *
 *  Created on: 6 oct 2022
 *      Author: natal_000
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <conio.h>
#include "utn.h"

int utn_getNumero(int* pResultado,char* mensaje,char* mensajeError,int minimo,int maximo,int reintentos)
{
	int retorno = -1;
	int bufferInt;
	if(pResultado != NULL && mensaje != NULL && mensajeError != NULL && minimo <= maximo && reintentos>=0)
	{
		do
		{
			printf("%s", mensaje);
			if(getInt(&bufferInt)==0 && bufferInt>=minimo && bufferInt<=maximo)
			{
				*pResultado=bufferInt;
				retorno=0;
				break;
			}
			else
			{
				printf("%s", mensajeError);
				reintentos--;
			}
		}while(reintentos>=0);
	}
	return retorno;
}
int myGets(char* cadena, int size) //Se asegura de no desbordar el buffer
{
	int retorno=-1;
	char bufferString[4096];
	if(cadena!=NULL && size>0)
	{
		fflush(stdin);
		if(fgets(bufferString, sizeof(bufferString),stdin)!=NULL) //sizeof : nos devuelve el tamaño que tiene bufferString disponible
		{
			if(bufferString[strnlen(bufferString, sizeof(bufferString))-1] =='\n')
			{
				bufferString[strnlen(bufferString,sizeof(bufferString))-1] = '\0';
			}
			if(strnlen(bufferString, sizeof(bufferString))<=size)
			{
				strncpy(cadena,bufferString,size);
				retorno=0;
			}
		}
	}
	return retorno;
}
int esNumerica(char* cadena, int longitud)
{
	int retorno= 1;
	int i;
	if(cadena!=NULL)
	{

		for(i=0; i<longitud && cadena[i]!='\0'; i++)
		{
			if(i==0 && (cadena[i]=='+' || cadena[i]=='-'))
			{
				continue;
			}
			if(cadena[i]<'0'||cadena[i]>'9')
			{
				retorno=0;
				break;
			}
		}
	}
	return retorno;
}
int getValidYesNoChar(char mensaje[], char errorMensaje[]){
    char aux='n';
    do{
        if(isYesNoCharacter(aux)==0)
        {

            aux = getchar();
        }else
        {
            aux = getchar();
        }
    }while (isYesNoCharacter(aux)==0);
    return aux;
}
int isYesNoCharacter(char caracter){
    int retorno = 0;
    if ((caracter == 's') || (caracter == 'n') || (caracter == 'S') || (caracter == 'N') )
        retorno = 1;
    return retorno;
}
int getInt(int* pResultado)
{
	int retorno = -1;
	char bufferString[50];
	if(pResultado!=NULL)
	{
		if(myGets(bufferString, sizeof(bufferString))==0 && esNumerica(bufferString,sizeof(bufferString))==1)
		{
			*pResultado=atoi(bufferString);  //RECIBE UN STRING VALIDADO QUE ES UN NUMERO QUE SE PUEDE CONVERTIR EN ENTERO Y ME DEVUELVE UN ENTERO
											 //DEVUELVE UN INT UN NUMERO YA VALIDADO.
			retorno=0;
		}
	}
	return retorno;
}
int getFloat(float* pResultado)
{
	int retorno = -1;
	char buffer[64];
	if(pResultado!=NULL)
	{
		if(myGets(buffer, sizeof(buffer))==0 && esFlotante(buffer)==1)
		{
			*pResultado=atof(buffer);
			retorno=0;
		}
	}
	return retorno;
}
int esFlotante(char* cadena)
{
	int retorno= 1;
	int i;
	int contadorPunto=0;
	if(cadena!=NULL && strlen(cadena)>0)
	{
		for(i=0; i<(cadena[i]!= '\0') && cadena[i]!='\0'; i++)
		{
			if(i==0 && (cadena[i]=='+' || cadena[i]=='-'))
			{
				continue;
			}
			if(cadena[i]<'0'||cadena[i]>'9')
			{
				if(cadena[i]=='.' && contadorPunto==0)
				{
					contadorPunto++;
				}
				else
				{
				retorno=0;
				break;
				}
			}
		}
	}
	return retorno;
}
int utn_getNumeroFlotante(float* pResultado,char* mensaje,char* mensajeError,float minimo,float maximo,int reintentos)
{
	int retorno = -1;
	float bufferInterno;
	if(pResultado != NULL && mensaje != NULL && mensajeError != NULL && minimo <= maximo && reintentos>0)
	{
		do
		{
			printf("%s", mensaje);
			if(getFloat(&bufferInterno)==0 && bufferInterno>=minimo && bufferInterno<=maximo)
			{
				*pResultado=bufferInterno;
				retorno=0;
				break;
			}
			else
			{
				printf("%s", mensajeError);
				reintentos--;
			}
		}while(reintentos>=0);
	}
	return retorno;
}
int utn_getNombre(char* pResultado, char* mensaje, char* mensajeError,int reintentos, int size)
{
	char bufferString[1000];
	int retorno = -1;

	if(mensaje != NULL && mensajeError != NULL && pResultado != NULL && reintentos >= 0 && size > 0)
	{
		do
		{
			printf("%s",mensaje);
			if(getNombre(bufferString, 1000)==0)
			{
				strncpy(pResultado,bufferString,size);
				retorno = 0;
				break;
			}
			else
			{
				printf("%s",mensajeError);
				reintentos--;
			}
		}while(reintentos>=0);
	}
	return retorno;
}
int utn_getString(char aux[],char* mensaje,char* mensajeError, int reintentos)
{
	int retorno = -1;
	char bufferString[40];

	if(aux != NULL && mensaje != NULL && mensajeError != NULL && reintentos>0)
	{
		do
		{
			printf("%s", mensaje);
			if(myGets(bufferString,40)==0)
			{
				strcpy(aux, bufferString);
				retorno=0;
				break;
			}
			else
			{
				printf("%s", mensajeError);
				reintentos--;
			}
		}while(reintentos>=0);
	}
	return retorno;
}
int getNombre(char* pResultado,int size)
{
	int retorno=-1;
	char buffer[5000];
	if(pResultado!=NULL && size>0)
	{
		if(myGets(buffer, sizeof(buffer))==0 && !esNombre(buffer, sizeof(buffer)) && strnlen(buffer, sizeof(buffer))<=size)
		{
			strncpy(pResultado, buffer, size);
			retorno=0;
		}
	}
	return retorno;
}
int esNombre(char* cadena,int size)
{
	int retorno = 1;

	if(cadena!=NULL && size>0)
	{
		for(int i=0; i<=size ;i++)
		{
			if((cadena[i]<'A' || cadena[i]>'Z') && (cadena[i]<'a' || cadena[i]>'z') && cadena[i] != '.' && cadena[i] != ' ' )
			{
				retorno = 0;
				break;
			}
		}
	}
	return retorno;
}
int esPosicion(char* cadena,int size)
{
	int retorno = 1;

	if(cadena!=NULL && size>0)
	{
		for(int i=0; i<=size ;i++)
		{
			if((cadena[i]<'A' || cadena[i]>'Z') && (cadena[i]<'a' || cadena[i]>'z') && cadena[i] != '.' && cadena[i] != ' ' )
			{

					retorno = 0;

				break;
			}
		}
	}
	return retorno;
}
int numeroTelefonicoConguionmedio(char*pResultado)
{
	int retorno=1;
	int i;

	for(i=0;i<strlen(pResultado);i++)
		{
			if(isdigit(pResultado[i])!=0 )
			{
				if(pResultado[4]=='-')
				{
					retorno=0;
				}
			}
		}
	return retorno;
}
int esTelefonoValido(char* cadena)
{
    int retorno=1;
    int i;
    for(i=0;cadena[i]!='\0';i++)
    {
        if((cadena[i]<'0' || cadena[i]>'9') && (cadena[i]!='-' || cadena[i]!=' '))
        {
            retorno=0;
            break;
        }
    }
    return retorno;
}
int esSoloLetra(char *pResultado)
{
	int retorno = 1;
	int i;

	if(pResultado!=NULL && strlen(pResultado)>0)
	{
		for (i = 0; i<strlen(pResultado); i++)
		{
			if (isalpha(pResultado[i]) == 0)
			{
				retorno = 0;
				break;
			}
		}
	} else {
		retorno = 0;
	}
	return retorno;
}
int inicializarArrays(char arrays[],int cantidad)
{
		int retorno=-1;
		int i;
		if(arrays!= NULL && cantidad>0)
		{
			for(i=0;i<cantidad;i++){
				arrays[i]=0;
			}
		retorno =0;
		}
		return retorno;
}
void formarApellidoNombre(char pNombre[],char pApellido[],char pCompleto[])
{
	int len;

	strcpy(pCompleto, pApellido);
	strcat(pCompleto,", ");
	strcat(pCompleto,pNombre);
	strlwr(pCompleto);

	pCompleto[0] = toupper(pCompleto[0]);

	len = strlen(pCompleto);
	for(int i=0;i<len;i++)
	{
		if(pCompleto[i]==' ')
		{
			pCompleto[i+1] = toupper(pCompleto[i+1]);
		}
	}

	printf("El nombre completo es: %s",pCompleto);
}
void getString(char* mensaje, char imput[])
{
	printf("%s", mensaje);
	gets(imput);
}
void getChar(char* mensaje,char* respuesta)
{
	;
	printf("%s", mensaje);
	fflush(stdin);
	scanf("%c",respuesta);


}

void inicializarArrayChar(char pArray[], int cantidadDeArray)
{
	int i;

	for(i=0; i<cantidadDeArray; i++)
	{
		pArray[i]=' ';
	}
}
int inicializarArrayFlotante(float pArray[], int cantidadDeArray)
{
	int retorno=-1;
	int i;
	   if(pArray!=NULL && cantidadDeArray>0)
	   {
			for(i=0; i<cantidadDeArray; i++)
			{
				pArray[i]=0;
			}
			retorno=0;
	   }
	  return retorno;
}
int imprimirArrayFlotante(float pArray[], int cantidadDeArray)
{
	int retorno=-1;
	int i;
	   if(pArray!=NULL && cantidadDeArray>0)
	   {
			for(i=0; i<cantidadDeArray; i++)
			{
				printf("\nIndice [%d] - Valor %2.f", i, pArray[i]);
			}
			retorno=0;
	   }
	  return retorno;
}
int validarArrayAlfanumerico(char* arraylist,int size)
{
	int retorno=1;
	int contador=0;

	for(int i = 0;i<size;i++)
		{
			if(isdigit(arraylist[i])!=0)
			{
				contador++;
			}
		}
	if(contador>0)
	{
		retorno=0;
	}
	return retorno;
}
int esLetraConEspacio(char *pResultado)
{
	int retorno;
	int i;
	for(i=0;i<strlen(pResultado);i++)
	{
		if(isalpha(pResultado[i])!=0)
		{

			if(pResultado[5]==' ')
			{
				retorno=1;
			}
		}
		else
		{
			retorno=0;
		}
	}
	return retorno;
}
int utn_getCaracterSN(char* mensaje)
{
	int retorno = -1;
	char c;

	getChar(mensaje, &c);

	while(c!='s' && c!='n')
	{
		puts("ERROR. OPCION NO VALIDA");
		getChar("Ingrese 's' o 'n'", &c);

	}
		if(c=='s' || c == 'S')
		{
			retorno = 0;
		}
	return retorno;
}
