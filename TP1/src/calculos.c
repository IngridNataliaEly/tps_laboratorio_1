/*
 * calculos.c
 *
 *  Created on: 25 sept 2022
 *      Author: natal_000
 */

#include "Informes.h"
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include "datos.h"
#include "Informes.h"
#include "calculos.h"
#include "utn.h"



int calcular_Promedio(int contador ,int cantidadJugadores,float* promedio)
{
	int retorno=-1;
	if(contador >= 0 && cantidadJugadores > 0 )
	{
		*promedio = (float)( contador / cantidadJugadores );
		printf("promedio %f",*promedio);
		retorno = 0;
	}
	return retorno;
}



int Calcular_CostosMantenimiento(float gastosTransporte,float gastosHospedaje,float gastosComida,float*costoMantenimiento)
{
	int retorno = -1;

	if(costoMantenimiento!=NULL && gastosTransporte > 0 && gastosHospedaje > 0 && gastosComida > 0 )
	{
		*costoMantenimiento =  gastosTransporte + gastosHospedaje+ gastosComida;
		retorno=0;
	}

	return retorno;
}

int calcular_AumentoCostos(float*aumento,float*costoFinal,float*costoMantenimiento,int*contadorAfc,int*contadorCaf,int*contadorConcaf,int*contadorConmebol,int*contadorUefa,int*contadorOfc)
{
	int retorno=-1;
	if((*contadorUefa)>(*contadorAfc) && (*contadorUefa)>(*contadorCaf) && (*contadorUefa)>(*contadorConcaf) && (*contadorUefa)>(*contadorConmebol) && (*contadorUefa)>(*contadorOfc) )
	{
		*aumento = calcular_PorcentajeFloat(35,(*costoMantenimiento));
		*costoFinal = *costoMantenimiento + *aumento;
		printf("\nMayor parte plantel compuesto por UEFA"
			   "\nValor Original: %.2f"
			   "\nEl valor del aumento: %.2f"
			   "\nEl valor actualizado con el aumento agregado: %.2f",*costoMantenimiento,*aumento,*costoFinal);
		retorno =0;
	}
	return retorno;
}
float calcular_PorcentajeFloat(float porcentaje,float total)
{
	float resultado;
	if(porcentaje > 0 && total > 0)
	{
		resultado = (total * porcentaje)/100;
	}
	return resultado;
}
