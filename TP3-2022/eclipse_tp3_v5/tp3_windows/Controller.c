#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#include "Jugador.h"
#include "Seleccion.h"
#include "LinkedList.h"
#include "parser.h"
#include "utn.h"


/** \brief Carga los datos de los jugadores desde el archivo jugadores.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListJugador LinkedList*
 * \return int
 *
 */

int controller_cargarJugadoresDesdeTexto(char* path , LinkedList* pArrayListJugador)
{
	int retorno = -1;
	FILE *pfile;

	if (path != NULL  && pArrayListJugador != NULL && ll_len(pArrayListJugador)>=0)
	{
		pfile = fopen(path,"r");
		if(pfile != NULL)
		{
			if(parser_JugadorFromText(pfile, pArrayListJugador)!=-1)
			{

			}

		}
		else
		{
			printf("Saliendo...\n");
			retorno =  -1;
		}
	} else
	{
		printf("Archivo encontrado. ");

		retorno = 0;
	}

	return retorno;
}

/** \brief Carga los datos de los jugadores desde el archivo generado en modo binario.
 *
 * \param path char*
 * \param pArrayListJugador LinkedList*
 * \return int
 *
 */
int controller_cargarJugadoresDesdeBinario(char* path , LinkedList* pArrayListJugador)
{
			int retorno = -1;
			FILE* pfile;
			char respuesta ='n';
		    if((pfile = fopen(path, "rb+")) == NULL)
		    {
		        printf("No se ha encontrado el archivo. ");
		        printf("Desea crealo? s/n: ");
		        respuesta = getValidYesNoChar("Desea crealo? y/n: ", "Opcion no valida. ");
		        if(respuesta == 'y')
		        {
		            if((pfile=fopen(path,"wb+"))==NULL)
		            {

		                printf("!! - Error, no se ha podido abrir el archivo.\n");
		                exit(-1);
		            }
		            else
		            {
		                printf("Archivo creado. ");
		                retorno =0;
		            }
		        }
		        else
		        {
		            printf("Saliendo...\n");
		            return 0;                        //0 si no se encontro y no se creo
		        }
		    }
		    else
		    {
		        printf("Archivo encontrado. ");
		        parser_JugadorFromBinary(pfile,pArrayListJugador);
		        retorno = 0;
		    }
    return retorno;
}

/** \brief Alta de jugadores
 *
 * \param path char*
 * \param pArrayListJugador LinkedList*
 * \return int
 *
 */
int controller_agregarJugador(LinkedList* pArrayListJugador)
{
	int retorno = -1;
	Jugador *this;
	char idStr[500];
	char nombreCompletoStr[4096];
	char edadStr[2000];
	char posicionStr[4096];
	char nacionalidadStr[4096];
	char idSelccionStr[500];
	int id = 371;
	int idAux, edadAux;
	idAux = 0;
	id++;

	if (pArrayListJugador != NULL) {
		this = jug_new();

		if (atoi(idStr) >= id)
		{
			id = atoi(idStr) + 1;
		}

	        itoa(id, idStr, 10);
	        utn_getNombre(nombreCompletoStr,"Ingrese nombre: ", "El dato debe tener menos de 4096 caracteres. ",5, 4096);
	        utn_getNumero(&edadAux, "Ingrese Edad : ", "Ingrese Edad Valida : ", 18, 36, 5);
	        itoa(edadAux, edadStr,10);
	        utn_getString(posicionStr, "Ingrese posicion de jugador:", "ERROR!Ingrese posicion de jugador:", 5);
	        utn_getNombre(nacionalidadStr, "Ingrese Nacionalidad de jugador:", " ERROR !Ingrese Nacionalidad de jugador:", 5, 4096);
	        itoa(idAux,idSelccionStr,10);

	        this = jug_newParametros(idStr, nombreCompletoStr, edadStr, posicionStr, nacionalidadStr, idSelccionStr);
	        if(this!= NULL)
	        {
	        	ll_add(pArrayListJugador, this);
	        	retorno = 0;
	        }
	    }

	    return retorno;
}

/** \brief Modificar datos del jugador
 *
 * \param path char*
 * \param pArrayListJugador LinkedList*
 * \return int
 *
 */
int controller_editarJugador(LinkedList* pArrayListJugador)
{
	int idM;        //id ingresado a modificar
	int option;
	Jugador *this;
	char respuesta = 'n';
	char nombreCompletoStr[4096];
	char posicionStr[4096];
	char nacionalidadStr[4096];
	int edad;
	int retornAux = -1;

	    utn_getNumero(&idM, "Ingrese ID de Jugador a modificar: ", "Ingrese ID  VALIDO de Jugador a modificar: ", 0, 1000, 5);

	        this = (Jugador*) ll_get(pArrayListJugador,idM);
	        if(this != NULL)
	        {
	        	printf("ID INEXISTENTE");
	        	utn_getNumero(&idM, "Ingrese ID de Jugador a modificar: ", "Ingrese ID  VALIDO de Jugador a modificar: ", 0, 1000, 5);
	        }
	        else
	        {
	        	do{

	           utn_getNumero(&option, "\nIngrese dato a modificar: \n"
	            "\t1- nombre\n"
	            "\t2- edad\n"
	            "\t3- posición\n"
	            "\t4- nacionalidad\n"
	            "\t5- Cancelar\n", "OPCION INVALIDA", 1, 5, 10);

	            switch(option){
	            case 1:
	            	utn_getNombre(nombreCompletoStr,"Ingrese nombre: ", "El dato debe tener menos de 4096 caracteres. ",5, 4096);
	                jug_setNombreCompleto(this,nombreCompletoStr);
	                respuesta = getValidYesNoChar("Desea continuar modificando mismx Jugador?\n ", "Opcion no valida. ");
	                if(respuesta == 'n')
	                {
	                	retornAux = 1;
	                }
	                break;
	            case 2:

	            	utn_getNumero(&edad, "Ingrese Edad : ", "Ingrese Edad Valida : ", 18, 36, 5);
	            	jug_setEdad(this, edad);
	            	printf("Desea continuar modificando mismx Jugador? ");
	            	 respuesta = getValidYesNoChar("Desea continuar modificando mismx Jugador?\n ", "Opcion no valida. ");
	            	if (respuesta == 'n')
	            	{
	            		retornAux = 1;
	            	}
	                break;
	            case 3:
	            	utn_getString(posicionStr, "Ingrese posicion de jugador:", "ERROR!Ingrese posicion de jugador:", 5);
	                jug_setPosicion(this, posicionStr);
	                printf("Desea continuar modificando mismx Jugador? ");
	                respuesta = getValidYesNoChar("Desea continuar modificando mismx Jugador?\n ", "Opcion no valida. ");
	                if(respuesta =='n')
	                {
	                	retornAux = 1;
	                }
	                break;
	            case 4:
	            	utn_getNombre(nacionalidadStr, "Ingrese Nacionalidad de jugador:", " ERROR !Ingrese Nacionalidad de jugador:", 5, 4096);
	                jug_setNacionalidad(this, nacionalidadStr);
	                printf("Desea continuar modificando mismo Jugador? ");
	                respuesta = getValidYesNoChar("Desea continuar modificando mismx Jugador?\n ", "Opcion no valida. ");
	                if(respuesta == 'n'){
	                	retornAux = 1;
	                }
	                break;
	            case 5:
	                printf("Modificacion cancelada, volviendo al menu...\n");
	                retornAux = 1;
	                break;
	            default:
	                printf("Opcion no valida\n");
	                break;
	            }
	        }while(respuesta == 's');
	        }

	        return retornAux;
		}




/** \brief Baja del jugador
 *
 * \param path char*
 * \param pArrayListJugador LinkedList*
 * \return int
 *
 */
int controller_removerJugador(LinkedList* pArrayListJugador)
{
	int retorno = -1;
	int idE;
	char conE = 'n';
	Jugador *this;

	utn_getNumero(&idE, "Ingrese ID de Jugador a modificar: ", "Ingrese ID  VALIDO de Jugador a modificar: ", 0, 1000, 5);
			printf("\n|-------------------------------------------------------------------------------------|");
			printf("\n|**Id\t| NOMBRE\t|EDAD\t|\tPOSICION\t|NACIONALIDAD\t|IDSELECCION**|\n");
			printf("|-------------------------------------------------------------------------------------|\n");

	for (int i = 0; i < ll_len(pArrayListJugador); i++)
	{
		this = (Jugador*) ll_get(pArrayListJugador, i);
		if (idE == this->id)
		{
			printf("%4d\t%14s\t%d\t|\t%6s\t|%10s\t|%d\n", this->id, this->nombreCompleto,this->edad,this->posicion
					,this->nacionalidad,this->idSeleccion);
			printf("\nDesea eliminar jugador? ");
			conE = getValidYesNoChar("Ingrese s/n: ", "Dato invalido. ");
			if (conE != 's') {
				printf("Eliminacion cancelada, volviendo al menu...\n");
				retorno = 1;
			} else
			{
				ll_remove(pArrayListJugador, i);
				printf("JUGADOR ELIMINADO CON EXITO %d\n", idE);
				free(this);
				retorno = 0;
			}
		}
		else
		{
			printf("No se ha encontrado jugador con ID %d. \n", idE);
		}
	}

	return retorno;
}

/** \brief Listar jugadores
 *
 * \param path char*
 * \param pArrayListJugador LinkedList*
 * \return int
 *
 */
int controller_listarJugadores(LinkedList* pArrayListJugador)
{

	int retorno = -1;
	Jugador *this;
	if ((ll_len(pArrayListJugador)) > 0)
	{
		printf("\n|-------------------------------------------------------------------------------------------------|");
		printf("\n|**Id| \t\tNOMBRE \t\t|EDAD\t|\tPOSICION\t|NACIONALIDAD\t|IDSELECCION**|\n");
		printf("|---------------------------------------------------------------------------------------------------|\n");

		for (int i = 0; i < ll_len(pArrayListJugador); i++) {
			this = ll_get(pArrayListJugador, i);
			if (this != NULL)
			{
				printf("%4d |     %-12s\t|\t%-4d\t|\t%-10s\t\t%-14s\t\t%-4d\n", this->id, this->nombreCompleto,this->edad,this->posicion
						,this->nacionalidad,this->idSeleccion);
			}
			printf("|-------------------------------------------------------------------------------------|\n");
		}
	} else {
		printf(
				"Archivo cargado con 0 jugadores, cargar nuevo archivo (1, 2) o agregar empleadx (3). ");
	}
	printf("\n");
	return retorno;
}

/** \brief Ordenar jugadores
 *
 * \param path char*
 * \param pArrayListJugador LinkedList*
 * \return int
 *
 */
int controller_ordenarJugadores(LinkedList* pArrayListJugador)
{
/*
	Jugador* pAux;
	A) JUGADORES POR NACIONALIDAD.
	B) SELECCIONES POR CONFEDERACIÓN.
	C) JUGADORES POR EDAD.
	D) JUGADORES POR NOMBRE.
			int retorno = -1;
		    int option;


		    printf("Seleeccionar ordenamiento por: \n");
		    printf("\tA- JUGADORES POR NACIONALIDAD.\n");
		    printf("\t2- SELECCIONES POR CONFEDERACIÓN\n");
		    printf("\t3- Horas trabajadas forma ascendente\n");
		    printf("\t4- Salario forma ascendente\n\n");
		    printf("\t5- Id forma descendente\n");
		    printf("\t6- Nombre forma descendente\n");
		    printf("\t7- Horas trabajadas forma descendente\n");
		    printf("\t8- Salario forma descendente\n");
		    scanf("%d", &option);

		    switch(option){         //sependiendo de la opcion ordena
		    case 1:
		    	ll_sort(pArrayListJugador,, 1);
		    	printf("Ordenamiento descendente por nombre realizado!\n");
		    	controller_listarJugadores(pArrayListJugador);
		        break;
		    case 2:
		        ll_sort(pArrayListJugador, , 0);
		        printf("Ordenamiento ascendente por nombre realizado!\n");
		        break;
		    case 3:
		        ll_sort(pArrayListEmployee, employeeSortByHours, 0);
		        printf("Ordenamiento ascendente por horas trabajadas realizado!\n");
		        break;
		    case 4:
		        ll_sort(pArrayListEmployee, employeeSortBySalary, 0);
		        printf("Ordenamiento ascendente por salario realizado!\n");
		        break;
		    case 5:
		        ll_sort(pArrayListEmployee, employeeSortById, 1);
		        printf("Ordenamiento descendente por id realizado!\n");
		        break;
		    case 6:
		        ll_sort(pArrayListEmployee, employeeSortByName, 1);
		        printf("Ordenamiento descendente por nombre realizado!\n");
		        break;
		    case 7:
		        ll_sort(pArrayListEmployee, employeeSortByHours, 1);
		        printf("Ordenamiento descendente por horas trabajadas realizado!\n");
		        break;
		    case 8:
		        ll_sort(pArrayListEmployee, employeeSortBySalary, 1);
		        printf("Ordenamiento descendente por salario realizado!\n");
		        break;
		    default:
		        printf("Opcion no valida\n");
		        break;
		    }
		    return retorno;
		    */
    return 1;
}

/** \brief Guarda los datos de los jugadores en el archivo jugadores.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListSeleccion LinkedList*
 * \return int
 *
 */
int controller_guardarJugadoresModoTexto(char* path , LinkedList* pArrayListJugador)
{
	 int retorno = -1;
	    Jugador* this;
	    FILE* lista = fopen(path, "w");

	    if(lista==NULL){
	        printf("Error para guardar\n");
	        return retorno;
	    }
	    fprintf(lista, "id,nombreCompleto,edad,posicion,nacionalidad,idSelecion\n");
	    if(pArrayListJugador!=NULL){
	        for(int i=0; i<ll_len(pArrayListJugador); i++){
	            this = (Jugador*)ll_get(pArrayListJugador, i);
	            fprintf(lista, "%d,%s,%d, %s, %s,%d\n", this->id, this->nombreCompleto, this->edad, this->posicion,this->nacionalidad,this->idSeleccion);
	        }
	        printf("Archivo Guardado.\n");
	        retorno = 1;
	    }
	    fclose(lista);
	    return retorno;
}

/** \brief Guarda los datos de los jugadores en el archivo binario.
 *
 * \param path char*
 * \param pArrayListJugador LinkedList*
 * \return int
 *
 */
int controller_guardarJugadoresModoBinario(char* path , LinkedList* pArrayListJugador)
{
    return 1;
}



/** \brief Carga los datos de los selecciones desde el archivo selecciones.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListSeleccion LinkedList*
 * \return int
 *
 */
int controller_cargarSeleccionesDesdeTexto(char* path , LinkedList* pArrayListSeleccion)
{
	int retorno = -1;
		FILE *pfile;
		char ele = 'n';
		if ((pfile = fopen(path, "r+")) == NULL) {
			printf("No se ha encontrado el archivo. ");
			printf("¿Desea crealo? ");

			ele = getValidYesNoChar("Desea crealo? y/n: ", "Opcion no valida. ");
			if(ele == 'y')
			{
				if ((pfile = fopen(path, "w+")) == NULL) {

					printf("!! - Error, no se ha podido abrir el archivo.\n");
					exit(-1);
				} else {
					printf("Archivo creado. ");
					retorno = 0;
				}
			}
			else
			{
				printf("Saliendo...\n");
				retorno =  -1;
			}
		} else
		{
			printf("Archivo encontrado. ");
			parser_SeleccionFromText(pfile, pArrayListSeleccion);
			retorno = 0;
		}
		return retorno;
}

/** \brief Modificar datos de empleado
 *
 * \param path char*
 * \param pArrayListSeleccion LinkedList*
 * \return int
 *
 */
int controller_editarSeleccion(LinkedList* pArrayListSeleccion)
{
		int idM;        //char* idStr,char* paisStr,char* confederacionStr, char* convocadosStr
		int option;
		Jugador *this;
		char respuesta = 'n';
		char nombreCompletoStr[4096];
		char posicionStr[4096];
		char nacionalidadStr[4096];
		int edad;
		int retornAux = -1;

		    utn_getNumero(&idM, "Ingrese ID de Jugador a modificar: ", "Ingrese ID  VALIDO de Jugador a modificar: ", 0, 1000, 5);
		        this = (Jugador*) ll_get(pArrayListSeleccion,idM);
		        if(this != NULL)
		        {
		        	printf("ID INEXISTENTE");
		        	utn_getNumero(&idM, "Ingrese ID de Jugador a modificar: ", "Ingrese ID  VALIDO de Jugador a modificar: ", 0, 1000, 5);
		        }
		        else
		        {
		        	do{
		           utn_getNumero(&option, "\nIngrese dato a modificar: \n"
		            "\t1- nombre\n"
		            "\t2- edad\n"
		            "\t3- posición\n"
		            "\t4- nacionalidad\n"
		            "\t5- Cancelar\n", "OPCION INVALIDA", 1, 5, 10);

		            switch(option){
		            case 1:
		            	utn_getNombre(nombreCompletoStr,"Ingrese nombre: ", "El dato debe tener menos de 4096 caracteres. ",5, 4096);
		                jug_setNombreCompleto(this,nombreCompletoStr);
		                respuesta = getValidYesNoChar("Desea continuar modificando mismx Jugador?\n ", "Opcion no valida. ");
		                if(respuesta == 'n')
		                {
		                	retornAux = 1;
		                }
		                break;
		            case 2:

		            	utn_getNumero(&edad, "Ingrese Edad : ", "Ingrese Edad Valida : ", 18, 36, 5);
		            	jug_setEdad(this, edad);
		            	printf("Desea continuar modificando mismx Jugador? ");
		            	 respuesta = getValidYesNoChar("Desea continuar modificando mismx Jugador?\n ", "Opcion no valida. ");
		            	if (respuesta == 'n')
		            	{
		            		retornAux = 1;
		            	}
		                break;
		            case 3:
		            	utn_getString(posicionStr, "Ingrese posicion de jugador:", "ERROR!Ingrese posicion de jugador:", 5);
		                jug_setPosicion(this, posicionStr);
		                printf("Desea continuar modificando mismx Jugador? ");
		                respuesta = getValidYesNoChar("Desea continuar modificando mismx Jugador?\n ", "Opcion no valida. ");
		                if(respuesta =='n')
		                {
		                	retornAux = 1;
		                }
		                break;
		            case 4:
		            	utn_getNombre(nacionalidadStr, "Ingrese Nacionalidad de jugador:", " ERROR !Ingrese Nacionalidad de jugador:", 5, 4096);
		                jug_setNacionalidad(this, nacionalidadStr);
		                printf("Desea continuar modificando mismo Jugador? ");
		                respuesta = getValidYesNoChar("Desea continuar modificando mismx Jugador?\n ", "Opcion no valida. ");
		                if(respuesta == 'n'){
		                	retornAux = 1;
		                }
		                break;
		            case 5:
		                printf("Modificacion cancelada, volviendo al menu...\n");
		                retornAux = 1;
		                break;
		            default:
		                printf("Opcion no valida\n");
		                break;
		            }
		        }while(respuesta == 's');
		        }

		        return retornAux;
			}



/** \brief Listar selecciones
 *
 * \param path char*
 * \param pArrayListSeleccion LinkedList*
 * \return int
 *
 */
int controller_listarSelecciones(LinkedList* pArrayListSeleccion)
{
	int retorno = -1;
		Seleccion *this;
		if ((ll_len(pArrayListSeleccion)) > 0)
		{
			printf("\n|-------------------------------------------------------------|");
			printf("\n|**Id| \t\PAIS \t\t|CONFEDEREACION \t|\CONVOCADOS\t|\n");
			printf("|-------------------------------------------------------------|\n");

			for (int i = 0; i < ll_len(pArrayListSeleccion); i++) {
				this = ll_get(pArrayListSeleccion, i);
				if (this != NULL)
				{
					printf("%4d |%-12s\t|\t%-10s\t|\t%-d\t\n", this->id, this->pais, this->confederacion, this->convocados);
				}
				printf("|-------------------------------------------------------------|\n");
			}
		} else {
			printf(
					"Archivo cargado con 0 jugadores, cargar nuevo archivo (1, 2) o agregar empleadx (3). ");
		}
		printf("\n");
		return retorno;
}

/** \brief Ordenar selecciones
 *
 * \param path char*
 * \param pArrayListSeleccion LinkedList*
 * \return int
 *
 */
int controller_ordenarSelecciones(LinkedList* pArrayListSeleccion)
{
	//ll_sort(pArrayListEmployee, employeeSortByHours, 0);
	//printf("Ordenamiento ascendente por horas trabajadas realizado!\n");
}

/** \brief Guarda los datos de los selecciones en el archivo selecciones.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListSeleccion LinkedList*
 * \return int
 *
 */
int controller_guardarSeleccionesModoTexto(char* path , LinkedList* pArrayListSeleccion)
{
	int retorno = -1;
		    Seleccion* this;
		    FILE* lista = fopen(path, "w");

		    if(lista==NULL){
		        printf("Error para guardar\n");
		        return retorno;
		    }
		    fprintf(lista, "id,pais,confederacion,convocados\n");
		    if(pArrayListSeleccion!=NULL){
		        for(int i=0; i<ll_len(pArrayListSeleccion); i++){
		            this = (Seleccion*)ll_get(pArrayListSeleccion, i);
		            fprintf(lista, "%d,%s,%s, %d, \n", this->id, this->pais, this->confederacion, this->convocados);
		        }
		        printf("Archivo Guardado.\n");
		        retorno = 1;
		    }
		    fclose(lista);
		    return retorno;
}


