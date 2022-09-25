/*
 * prueba.c
 *
 *  Created on: 20 sept 2022
 *      Author: natal_000
 */

#include <stdio.h>
#include <stdlib.h>
#include "prueba.h"

void mostrarMenu(void) {
	printf("\n1. Ingreso de los costos de Mantenimiento."

			"\n2. Carga de jugadores:"
			"\n3. Realizar todos los cálculos."
			"\n4. Informar todos los resultados."
			"\n5. Salir");
}
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
void ingresoCostos(int *bandera, int *sumaT, int *sumaH, int *sumaC,
		int *costoMantenimiento) {

	char respuesta = 's';
	int numeroT;
	int numeroH;
	int numeroC;
	char opcion;

	*bandera = 1;
	if (bandera != NULL && sumaT != NULL && sumaH != NULL && sumaC != NULL) {
		while (respuesta == 's') {
			utn_validacionCaracter(&opcion);
			printf("Costo de hospedaje -> $ %d\n"
					"Costo de comida -> $%d\n"
					"Costo de transporte -> $%d\n", *sumaH, *sumaC, *sumaT);
			switch (opcion) {
			case 't':
				utn_validacioPrecio(&numeroT,"\nIngrese el monto del gasto selecionado: ","ERROR Ingrese un costo valido de 0 a 100000000",0,100000000);
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
void utn_validacioPrecio(int*numero,char *mensaje,char*mensajeError,int minimo,int maximo)
{
	printf(mensaje);
	scanf("%d", numero);
	while(*numero<minimo||*numero>maximo)
	{
		printf(mensajeError);
		scanf("%d",numero);
	}
}

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
void cargaJugadores(int*banderaCostos,int *banderaCarga,int *contadorAfc,int *contadorCaf,int *contadorConcaf,int *contadorConmebol,int *contadorUefa, int *contadorOfc
					,int*contadorArqueros,int*contadorDefensores,int*contadorMediocampistas,int*contadorDelanteros,int*i)
{

if(banderaCostos!=NULL && banderaCarga!=NULL && contadorAfc!=NULL && contadorCaf!=NULL && contadorConcaf!=NULL && contadorConmebol!=NULL && contadorUefa!=NULL && contadorOfc!=NULL)
{
	if(*banderaCostos==1)
	{
		*banderaCarga=1;
		utn_validacionCamiseta();
		ingresarConfederacion(contadorAfc,contadorCaf,contadorConcaf,contadorConmebol,contadorUefa,contadorOfc);
		cargaPosicion(contadorArqueros,contadorDefensores,contadorMediocampistas,contadorDelanteros,i);
	}
}
}
void realizarCalculos(int*banderaCostos,int*banderaCarga,int*banderaCalculos,int*banderadaCalculos,int*i,int*contadorAfc,int*contadorCaf,int*contadorConcaf,int*contadorConmebol,int*contadorUefa,int*contadorOfc,float*promedioAfc,float* promedioCaf,float*promedioConcaf,float*promedioConmebol,float*promedioUefa,float*promedioOfc)
{
	if(banderaCostos!=NULL&&banderaCarga!=NULL&&*banderaCostos==1&&*banderaCarga==1)
		{
		   if(utn_promedioMercados(i,contadorAfc,contadorCaf,contadorConcaf,contadorConmebol,contadorUefa,contadorOfc,promedioAfc,promedioCaf,promedioConcaf,promedioConmebol,promedioUefa,promedioOfc)==0)
		   {
			   printf("\nSe realizaron correctamente los  Promedios");

		   }
		else
		{
			printf("\nDebe Ingresar los costos de Mantenimiento y Cargar jugadores");
		}
		}
}
int utn_promedioMercados(int*i,int*contadorAfc,int*contadorCaf,int*contadorConcaf,int*contadorConmebol,int*contadorUefa,int*contadorOfc,float*promedioAfc,float* promedioCaf,float*promedioConcaf,float*promedioConmebol,float*promedioUefa,float*promedioOfc)
{
	int retorno;
	retorno=1;
	if(contadorAfc!=NULL && contadorCaf!=NULL && contadorConcaf!=NULL && contadorConmebol !=NULL && contadorUefa !=NULL && contadorOfc !=NULL)
	{
	*promedioAfc = (float)(*contadorAfc)*100/(*i);
	*promedioCaf = (float)(*contadorCaf)*100/(*i);
	*promedioConcaf = (float)(*contadorConcaf)*100/(*i);
	*promedioConmebol = (float)(*contadorConmebol)*100/(*i);
	*promedioUefa = (float)(*contadorUefa)*100/(*i);
	*promedioOfc = (float)(*contadorOfc)*100/(*i);
	}
	return retorno=0;
	}
void utn_mostrarPromedio(float*promedioAfc,float*promedioCaf,float*promedioConcaf,float*promedioConmebol,float*promedioUefa,float*promedioOfc)
{
					printf("\n Informar todos los Resultados"
					"\nPorcentaje de AFC ->%.2f"
					"\nPorcentaje de AFC ->%.2f"
					"\nPorcentaje de AFC ->%.2f"
					"\nPorcentaje de AFC ->%.2f"
					"\nPorcentaje de AFC ->%.2f"
					"\nPorcentaje de AFC ->%.2f",*promedioAfc,*promedioCaf,*promedioConcaf,*promedioConmebol,*promedioUefa,*promedioOfc);
}
void realizarCostos(int*banderaCostos,int*banderaCarga,int*banderaCalculos,int*sumaT,int*sumaH,int*sumaC,int*costoMantenimiento)
{
	if(banderaCostos!=NULL&&banderaCarga!=NULL&&*banderaCostos==1&&*banderaCarga==1)
	{
		if(utn_CostosMantenimiento(banderaCostos,banderaCarga,banderaCalculos,sumaT,sumaH,sumaC,costoMantenimiento)==0)
		{
			printf("\nSe realizaron correctamente los  CostosMantenimiento");
		}
}
}
int utn_CostosMantenimiento(int*banderaCostos,int*banderaCarga,int*banderaCalculos,int*sumaT,int*sumaH,int*sumaC,int*costoMantenimiento)
{
	int retorno;
	retorno=1;
	if(banderaCostos!=NULL&&banderaCarga!=NULL&&banderaCalculos!=NULL&&sumaT!=NULL&&sumaH!=NULL&&sumaC!=NULL&&costoMantenimiento!=NULL)
	{
		*costoMantenimiento = *costoMantenimiento + *sumaT + *sumaH+ *sumaC;
	}
	retorno=0;
	return retorno;
}
void utn_mostrarCosto(int*costoMantenimiento)
{
	if(costoMantenimiento!=NULL)
	{
		printf("\nEl costo de mantenimiento: %d",*costoMantenimiento);
	}
}
void utn_mayorContador(float*aumento,float*costoFinal,int*costoMantenimiento,int*contadorAfc,int*contadorCaf,int*contadorConcaf,int*contadorConmebol,int*contadorUefa,int*contadorOfc)
{
	if((*contadorUefa)>(*contadorAfc) && (*contadorUefa)>(*contadorCaf) && (*contadorUefa)>(*contadorConcaf) && (*contadorUefa)>(*contadorConmebol) && (*contadorUefa)>(*contadorOfc) )
	{
		*aumento = (*costoMantenimiento*35)/100;

		*costoFinal = *costoMantenimiento + *aumento;
		printf("\nMayor parte plantel compuesto por UEFA"
			   "\nValor Original: %d"
			   "\nEl valor del aumento: %.2f"
			   "\nEl valor actualizado con el aumento agregado: %.2f",*costoMantenimiento,*aumento,*costoFinal);
	}
}
