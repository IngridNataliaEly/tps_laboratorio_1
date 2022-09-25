/*
 * calculos.c
 *
 *  Created on: 25 sept 2022
 *      Author: natal_000
 */
#include <stdio.h>
#include <stdlib.h>
#include "calculos.h"
/**
 * \fn void realizarCalculos(int*, int*, int*, int*, int*, int*, int*, float*, float*, float*, float*, float*, float*)
 * \brief muestra un mensaje de carga correcta si el retorno  de la funcion de promedio es 0
 *
 * \param i
 * \param contadorAfc
 * \param contadorCaf
 * \param contadorConcaf
 * \param contadorConmebol
 * \param contadorUefa
 * \param contadorOfc
 * \param promedioAfc
 * \param promedioCaf
 * \param promedioConcaf
 * \param promedioConmebol
 * \param promedioUefa
 * \param promedioOfc
 */
void realizarCalculos(int*i,int*contadorAfc,int*contadorCaf,int*contadorConcaf,int*contadorConmebol,int*contadorUefa,int*contadorOfc,float*promedioAfc,float* promedioCaf,float*promedioConcaf,float*promedioConmebol,float*promedioUefa,float*promedioOfc)
{

		if(utn_promedioMercados(i,contadorAfc,contadorCaf,contadorConcaf,contadorConmebol,contadorUefa,contadorOfc,promedioAfc,promedioCaf,promedioConcaf,promedioConmebol,promedioUefa,promedioOfc)==0)
		 {
			   printf("\nSe realizaron correctamente los  Promedios");

		 }
}
/**
 * \fn int utn_promedioMercados(int*, int*, int*, int*, int*, int*, int*, float*, float*, float*, float*, float*, float*)
 * \brief Encargada de realizar los calculos de promedios de las confederaciones ingreseadas sobre los jugadores.
 *
 * \param i
 * \param contadorAfc
 * \param contadorCaf
 * \param contadorConcaf
 * \param contadorConmebol
 * \param contadorUefa
 * \param contadorOfc
 * \param promedioAfc
 * \param promedioCaf
 * \param promedioConcaf
 * \param promedioConmebol
 * \param promedioUefa
 * \param promedioOfc
 * \return si retorna 0 es que se realizo correctamente.
 */
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
/**
 * \fn void utn_mostrarPromedio(float*, float*, float*, float*, float*, float*)
 * \brief  Muestra el resultado de los promedios si se realizaron coreectamete los calculos.
 *
 * \param promedioAfc
 * \param promedioCaf
 * \param promedioConcaf
 * \param promedioConmebol
 * \param promedioUefa
 * \param promedioOfc
 */
void utn_mostrarPromedio(float*promedioAfc,float*promedioCaf,float*promedioConcaf,float*promedioConmebol,float*promedioUefa,float*promedioOfc)
{
					printf("\n Informar todos los Resultados"
					"\nPorcentaje de AFC ->%.2f"
					"\nPorcentaje de CAF ->%.2f"
					"\nPorcentaje de CONCAF ->%.2f"
					"\nPorcentaje de CONMEBOL ->%.2f"
					"\nPorcentaje de UEFA ->%.2f"
					"\nPorcentaje de OFC ->%.2f",*promedioAfc,*promedioCaf,*promedioConcaf,*promedioConmebol,*promedioUefa,*promedioOfc);
}
/**
 * \fn void realizarCostos(int*, int*, int*, int*)
 * \brief muestra un mensaje de carga correcta si el retorno  de la funcion de Suma de Costos retorna 0
 *
 * \param sumaT
 * \param sumaH
 * \param sumaC
 * \param costoMantenimiento
 */
void realizarCostos(int*sumaT,int*sumaH,int*sumaC,int*costoMantenimiento)
{


		if(utn_CostosMantenimiento(sumaT,sumaH,sumaC,costoMantenimiento)==0)
		{
			printf("\nSe realizaron correctamente los  CostosMantenimiento");
		}
}
/**
 * \fn int utn_CostosMantenimiento(int*, int*, int*, int*)
 * \brief  Realiza la suma final de todos los gastos ingresados
 *
 * \param sumaT
 * \param sumaH
 * \param sumaC
 * \param costoMantenimiento
 * \return si retorna 0 realizo correctamente
 */
int utn_CostosMantenimiento(int*sumaT,int*sumaH,int*sumaC,int*costoMantenimiento)
{
	int retorno;
	retorno=1;
	if(sumaT!=NULL&&sumaH!=NULL&&sumaC!=NULL&&costoMantenimiento!=NULL)
	{
		*costoMantenimiento = *costoMantenimiento + *sumaT + *sumaH+ *sumaC;
	}
	retorno=0;
	return retorno;
}
/**
 * \fn void utn_mostrarCosto(int*)
 * \brief  Mostrar el costo final
 *
 * \param costoMantenimiento
 */
void utn_mostrarCosto(int*costoMantenimiento)
{
	if(costoMantenimiento!=NULL)
	{
		printf("\nEl costo de mantenimiento: %d",*costoMantenimiento);
	}
}
/**
 * \fn void utn_mayorContador(float*, float*, int*, int*, int*, int*, int*, int*, int*)
 * \brief  Verificar si la UEFA fue la confederacion con mas jugadores ingresados comparandola con las demas coonfederacion
 * , esta incrementa un 35 porciento el costo y se encarga de mostrar su resultado.
 *
 * \param aumento cantidad que fue aumentado
 * \param costoFinal  costo de mantenimiento mas este aumento
 * \param costoMantenimiento la suma de los costos de transporte comida y hospedaje
 * \param contadorAfc
 * \param contadorCaf
 * \param contadorConcaf
 * \param contadorConmebol
 * \param contadorUefa
 * \param contadorOfc
 */
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
