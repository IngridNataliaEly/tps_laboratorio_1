/*
 * datos.c
 *
 *  Created on: 25 sept 2022
 *      Author: natal_000
 */

#include <stdio.h>
#include <stdlib.h>
#include "datos.h"
/**
 * \fn void mostrarMenu(void)
 * \brief funcion que no retorna encargada de mostrar el menu
 *
 */
void mostrarMenu(void) {
	printf("\n1. Ingreso de los costos de Mantenimiento."

			"\n2. Carga de jugadores:"
			"\n3. Realizar todos los cálculos."
			"\n4. Informar todos los resultados."
			"\n5. Salir");
}
/**
 * \fn int utn_getNumero(char*, char*, int, int)
 * \brief Pide un numero para ingresar a las opciones del menu
 *
 * \param mensaje
 * \param mensajeError
 * \param minimo
 * \param maximo
 * \return el numero ingresado
 */
int utn_getNumero(char *mensaje, char *mensajeError, int minimo, int maximo) {
	int pResultado;
	if (mensaje != NULL) {
		printf("%s\n", mensaje);
		scanf("%d", &pResultado);
		while (pResultado < minimo || pResultado > maximo) {

		}
	}
	return pResultado;
}
/**
 * \fn void ingresoCostos(int*, int*, int*, int*)
 * \brief le pedimos al usuario que seleccione que gasto desea ingresar y cuando lo hace lo acumulamos.
 *
 * \param sumaT acumulador de transporte
 * \param sumaH acumulador de hospedaje
 * \param sumaC acumulador de comida
 * \param costoMantenimiento suma de todos los gastos ingresados
 */
void ingresoCostos( int *sumaT, int *sumaH, int *sumaC,
		int *costoMantenimiento) {

	char respuesta = 's';
	int numeroT;
	int numeroH;
	int numeroC;
	char opcion;


	if ( sumaT != NULL && sumaH != NULL && sumaC != NULL) {
		while (respuesta == 's') {
			utn_validacionCaracter(&opcion);
			printf("Costo de hospedaje -> $ %d\n"
					"Costo de comida -> $%d\n"
					"Costo de transporte -> $%d\n", *sumaH, *sumaC, *sumaT);
			switch (opcion) {
			case 't':
				utn_getNumeroPrecio(&numeroT,"\nIngrese el monto del gasto selecionado: ","ERROR Ingrese un costo valido de 0 a 100000000",0,100000000);
				*sumaT = *sumaT + numeroT;
				break;
			case 'h':
				printf("\nIngrese el monto del gasto selecionado: ");
				scanf("%d", &numeroH);
				*sumaH = *sumaH + numeroH;
				break;
			case 'c':
				printf("\nIngrese el monto del gasto selecionado: ");
				scanf("%d", &numeroC);
				*sumaC = *sumaC + numeroC;
				break;

			}
			printf("¿continuar Ingresando gastos? s/n");
			fflush(stdin);
			scanf("%c", &respuesta);
		}
	}
}
/**
 * \fn void utn_validacionCaracter(char*)
 * \brief Validacion para que ingrese las opciones correctas
 *
 * \param opcion devolvemos la opcion si se ingreso el correcto
 */
void utn_validacionCaracter(char *opcion){
	if (opcion != NULL) {
		printf("Ingrese tipo de gastos"
				"\n't': para Transporte,"
				"\n'h' : para Hospedaje,"
				"\n'c' : para Comida\n");
		fflush(stdin);
		scanf("%c", opcion);
		while (*opcion != 't' && *opcion != 'c' && *opcion != 'h') {
			printf(
					"\nERROR Ingrese gastos't':Transporte,'h':Hospedaje,'c':Comida ");
			fflush(stdin);
			scanf("%c", opcion);
		}
	}
}
/**
 * \fn void utn_getNumeroPrecio(int*, char*, char*, int, int)
 * \brief pedimos que ingrese un numero mayor a 0
 *
 * \param numero
 * \param mensaje
 * \param mensajeError
 * \param minimo
 * \param maximo
 */
void utn_getNumeroPrecio(int*numero,char *mensaje,char*mensajeError,int minimo,int maximo)
{
	printf(mensaje);
	scanf("%d", numero);
	while(*numero<minimo||*numero>maximo)
	{
		printf(mensajeError);
		scanf("%d",numero);
	}
}
/**
 * \fn void utn_validacionConfederacion(int*)
 * \brief validamos que solo pueda ingresar las opciones validas para las confederaciones
 *
 * \param opcion devolvemos la opcion si es correcta
 */
void utn_validacionConfederacion(int*opcion){
		if (opcion != NULL){
		printf("\nIngrese la confederacion:"
					"\n1 para AFC en Asia "
					"\n2 para CAF en Africa"
					"\n3 para CONCAF en zona del Norte"
					"\n4 para CONMEBOL en Sudamerica"
					"\n5 para UEFA en Europa"
					"\n6 para OFC en Oceania ");
			fflush(stdin);
			scanf("%d",opcion);
			while (*opcion != 1 && *opcion != 2 && *opcion != 3 &&* opcion != 4&& *opcion != 5 &&* opcion != 6) {
				printf("\nERROR Ingrese la confederacion:"
						"\n1 para AFC en Asia "
						"\n2 para CAF en Africa"
						"\n3 para CONCAF en zona del Norte"
						"\n4 para CONMEBOL en Sudamerica"
						"\n5 para UEFA en Europa"
						"\n6 para OFC en Oceania ");
				fflush(stdin);
				scanf("%d",opcion);
			}
		}
}
/**
 * \fn void ingresarConfederacion(int*, int*, int*, int*, int*, int*)
 * \brief Se carga la confederacion selecionada se va sumando por cada jugador ingresado
 * segun la confederacion ingresada
 *
 * \param contadorAfc
 * \param contadorCaf
 * \param contadorConcaf
 * \param contadorConmebol
 * \param contadorUefa
 * \param contadorOfc
 */
void ingresarConfederacion(int*contadorAfc,int*contadorCaf,int*contadorConcaf,int*contadorConmebol,int*contadorUefa,int*contadorOfc){
	int confederacion;
	utn_validacionConfederacion(&confederacion);
	switch(confederacion){
	case 1:
		(*contadorAfc)++;
		break;
	case 2:
		(*contadorCaf)++;
		break;
	case 3:
		(*contadorConcaf)++;
		break;
	case 4:
		(*contadorConmebol)++;
		break;
	case 5:
		(*contadorUefa)++;
		break;
	case 6:
		(*contadorOfc)++;
		break;
	}
	printf( "\nAFC en Asia ->%d"
			"\nCAF en Africa->%d"
			"\nCONCAF en zona del Norte->%d"
			"\nCONMEBOL en Sudamerica->%d"
			"\nUEFA en Europa->%d"
			"\nOFC en Oceania->%d\n",*contadorAfc,*contadorCaf,*contadorConcaf,*contadorConmebol,*contadorUefa,*contadorOfc);
}
/**
 * \fn void utn_validacionPosicion(int*, char*, char*, int, int)
 * \brief  devuelve por parametro si la opcion fue ingresada entre la opciones validas
 *
 * \param opcion
 * \param mensaje
 * \param mensajeError
 * \param minimo
 * \param maximo
 */
void utn_validacionPosicion(int *opcion,char*mensaje,char*mensajeError,int minimo,int maximo){
	if (opcion != NULL)
	{
		printf(mensaje);
		fflush(stdin);
		scanf("%d",opcion);
		while (*opcion < minimo || *opcion > maximo){
			printf(mensajeError);
			fflush(stdin);
			scanf("%d",opcion);
		}
   }
}
/**
 * \fn void cargaPosicion(int*, int*, int*, int*, int*)
 * \brief  Va contando las posiciones de cada jugador con sus respectivos contadores.
 *
 * \param contadorArqueros
 * \param contadorDefensores
 * \param contadorMediocampistas
 * \param contadorDelanteros
 * \param i contador de juagadores ingresados
 */
void cargaPosicion(int*contadorArqueros,int*contadorDefensores,int*contadorMediocampistas,int*contadorDelanteros,int*i)
{
	int posicion;
		printf("\nArqueros ->%d"
			   "\nDefensores->%d"
			   "\nMediocampistas->%d"
			   "\nDelanteros->%d\n",*contadorArqueros,*contadorDefensores,*contadorMediocampistas,*contadorDelanteros);
	utn_validacionPosicion(&posicion,
		"\nIngrese la posicion: "
			"\n1 :para Arqueros"
			"\n2 :para Defensores"
			"\n3 :para Mediocampistas"
			"\n4 :para Delanteros",
		"\nERRORIngrese la posicion: "
			"\n1 :para Arqueros"
			"\n2 :para Defensores"
			"\n3 :para Mediocampistas"
			"\n4 :para Delanteros",1,4);

	switch(posicion)
	{
		case 1:
			if(*contadorArqueros<2)
			{
				(*i)++;
				(*contadorArqueros)++;
			}
			else
			{
				printf("\nNo se puede continuar cargando Arqueros\n");
			}
			break;
		case 2:
			if(*contadorDefensores<8)
			{
				(*i)++;
				(*contadorDefensores)++;
			}
			else
			{
				printf("\nNo se puede continuar cargando Defensores\n");
			}

			break;
		case 3:
			if(*contadorMediocampistas<8)
			{
				(*i)++;
				(*contadorMediocampistas)++;
			}
			else
			{
				printf("\nNo se puede continuar cargando Mediocampistas\n");
			}
			break;
		case 4:
			if(*contadorDelanteros<4)
			{
				(*i)++;
				(*contadorDelanteros)++;
			}
			else
			{
				printf("\nNo se puede continuar cargando Delanteros");
			}
			break;
		}
		 printf("\nArqueros ->%d"
				"\nDefensores->%d"
				"\nMediocampistas->%d"
				"\nDelanteros->%d\n",*contadorArqueros,*contadorDefensores,*contadorMediocampistas,*contadorDelanteros);
}
/**
 * \fn void utn_validacionCamiseta(void)
 * \brief  Ingresar entre el 0 y 100
 *
 */
void utn_validacionCamiseta(void)
{
			int numero;
			printf("\nIngrese numero de camiseta");
			fflush(stdin);
			scanf("%d",&numero);

				while (numero < 0||numero > 100){
					printf("\nERROR Ingrese numero de 0 a 100 camiseta");
					fflush(stdin);
					scanf("%d",&numero);
				}
}
/**
 * \fn void cargaJugadores(int*, int*, int*, int*, int*, int*, int*, int*, int*, int*, int*)
 * \brief funcion a la que se ingresa en la main donde carga todas la anteriores camiseta, confederacion,posiscion
 *
 * \param contadorAfc
 * \param contadorCaf
 * \param contadorConcaf
 * \param contadorConmebol
 * \param contadorUefa
 * \param contadorOfc
 * \param contadorArqueros
 * \param contadorDefensores
 * \param contadorMediocampistas
 * \param contadorDelanteros
 * \param i
 */
void cargaJugadores(int *contadorAfc,int *contadorCaf,int *contadorConcaf,int *contadorConmebol,int *contadorUefa, int *contadorOfc
					,int*contadorArqueros,int*contadorDefensores,int*contadorMediocampistas,int*contadorDelanteros,int*i)
{

if( contadorAfc!=NULL && contadorCaf!=NULL && contadorConcaf!=NULL && contadorConmebol!=NULL && contadorUefa!=NULL && contadorOfc!=NULL)
{

		utn_validacionCamiseta();
		ingresarConfederacion(contadorAfc,contadorCaf,contadorConcaf,contadorConmebol,contadorUefa,contadorOfc);
		cargaPosicion(contadorArqueros,contadorDefensores,contadorMediocampistas,contadorDelanteros,i);
}
}
