#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "LinkedList.h"
#include "Jugador.h"
#include "Seleccion.h"
#include "utn.h"

/** \brief Parsea los datos de los jugadores desde el archivo jugadores.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListJugador LinkedList*
 * \return int
 */
int parser_JugadorFromText(FILE* pFile , LinkedList* pArrayListJugador)
{
	Jugador* this=NULL;
	int retornoAux = -1;
	char idStr[500];
	char nombreCompletoStr[4096];
	char edadStr[2000];
	char posicionStr[4096];
	char nacionalidadStr[4096];
	char idSelccionStr[500];
	int i;
	i=0;
	pFile = fopen("jugadores.csv","r");
	if(pFile != NULL)
	{//id,nombreCompleto,edad,posicion,nacionalidad,idSelecion
		fscanf(pFile,"%[^,],%[^,],%[^,],%[^,],%[^,],%[^\n]\n",idStr,nombreCompletoStr,edadStr,posicionStr,nacionalidadStr,idSelccionStr);//lectura fantasma
		do
		{
			if(fscanf(pFile,"%[^,],%[^,],%[^,],%[^,],%[^,],%[^\n]\n",idStr,nombreCompletoStr,edadStr,posicionStr,nacionalidadStr,idSelccionStr) == 6)
			{
				retornoAux = 0;
				this = jug_newParametros(idStr, nombreCompletoStr, edadStr, posicionStr, nacionalidadStr, idSelccionStr);
				if(this!= NULL)
				{
					ll_add(pArrayListJugador, this);
					i ++;
				}
			}
		}
		while(!feof(pFile));
		fclose(pFile);
		printf("\nFinal del archivo. Bytes leidos %d", i);
		system("pause");
	}
    return retornoAux;
}

/** \brief Parsea los datos de los jugadores desde el archivo binario.
 *
 * \param path char*
 * \param pArrayListJugador LinkedList*
 * \return int
 *
 */
int parser_JugadorFromBinary(FILE* pFile , LinkedList* pArrayListJugador)
{
	Jugador auxiliarP;
	int cant, i = 0;

	if(pFile != NULL && pArrayListJugador != NULL)
	{
		cant = fread(&auxiliarP, sizeof(auxiliarP), 1, pFile);

	    while(!feof(pFile))
	    {
	    	Jugador* this = jug_new();

	    				 if(jug_setId(this,auxiliarP.id)== -1 ||
	    					jug_setNombreCompleto(this, auxiliarP.nombreCompleto)== -1 ||
							jug_setEdad(this, auxiliarP.edad) == -1||
	    					jug_setPosicion(this, auxiliarP.posicion)== -1 ||
	    					jug_setNacionalidad(this, auxiliarP.nacionalidad)== -1 ||
	    					jug_setIdSeleccion(this,auxiliarP.idSeleccion)== -1 )
	    					{

	    					 jug_delete(this);
	    					 this = NULL;
	    					}
	    				 else
	    					{
	    						 printf("\ncarga OK\n ");
	    					}
	    if(cant == 1)
	    {
	            ll_add(pArrayListJugador,this);
	            fread(&auxiliarP, sizeof(auxiliarP), 1, pFile);
	            i++;
	    }else
	    {
	            if(!feof(pFile))
	            {
	                printf("\n!!! - Se ha producido un error llegando al final del archivo.");
	                system("pause");
	                break;
	            }else{
	                printf("\nFinal del archivo. Bytes leidos %d", i);
	            }
	        }
	    }
	}
	    printf("Datos cargados correctamente.\n");
	    fclose(pFile);
	    return i;
}

/** \brief Parsea los datos de los selecciones desde el archivo selecciones.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListSeleccion LinkedList*
 * \return int
 *
 */
int parser_SeleccionFromText(FILE* pFile , LinkedList* pArrayListSeleccion)
{
	int retornoAux = -1;
	char id[500];
	char pais[2000];
	char confederacion[2000];
	char convocados[2000];
	Seleccion* this=NULL;
	int i;
	i = 0;
		pFile = fopen("selecciones.csv","r");
		if(pFile != NULL)
		{//id,nombreCompleto,edad,posicion,nacionalidad,idSelecion
		fscanf(pFile, "%[^,],%[^,],%[^,],%[^\n]\n", id, pais, confederacion,convocados); //lectura fantasma
		do {
			if (fscanf(pFile, "%[^,],%[^,],%[^,],%[^\n]\n", id, pais,
					confederacion, convocados) == 4) {
				retornoAux = 0;
				this = selec_newParametros(id, pais, confederacion, convocados);
				if (this != NULL) {
					ll_add(pArrayListSeleccion, this);
					i++;
					printf("ALTA SELECCION OK");
				}
			}
		}

		while(!feof(pFile));
			fclose(pFile);
			printf("\nFinal del archivo. Bytes leidos %d", i);

		}
	    return retornoAux;
}
