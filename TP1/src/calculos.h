/*
 * calculos.h
 *
 *  Created on: 25 sept 2022
 *      Author: natal_000
 */
/**
 * \brief obtiene un contador y luego retorna el resultado
 * \param contador obtiene un contador y realiza los calculos
 * \param cantidadJUgadores obtiene la cantidad total de jugadores ingresados
 * \return retorna 0 se realizo el calculo -1 error
 */
int calcular_Promedio(int contador, int cantidadJugadores, float* promedio);
/**
 * \fn int calcular_AumentoCostos(float*, float*, float*, int*, int*, int*, int*, int*, int*)
 * \brief  Incrementa con un calculo el porcentaje de costos de mantenimiento. SI coresponde.
 *
 * \param aumento
 * \param costoFinal
 * \param costoMantenimiento
 * \param contadorAfc
 * \param contadorCaf
 * \param contadorConcaf
 * \param contadorConmebol
 * \param contadorUefa
 * \param contadorOfc
 * \return
 */
int calcular_AumentoCostos(float*aumento,float*costoFinal,float*costoMantenimiento,int*contadorAfc,int*contadorCaf,int*contadorConcaf,int*contadorConmebol,int*contadorUefa,int*contadorOfc);
/**
 * \fn float calcular_PorcentajeFloat(float, float)
 * \brief porcentaje segun tipo float.
 *
 * \param porcentaje
 * \param total
 * \return
 */
float calcular_PorcentajeFloat(float porcentaje,float total);
/**
 * \fn int Calcular_CostosMantenimiento(float, float, float, float*)
 * \brief suma de los gastos ingresados
 *
 * \param gastosTransporte
 * \param gastosHospedaje
 * \param gastosComida
 * \param costoMantenimiento
 * \return
 */
int Calcular_CostosMantenimiento(float gastosTransporte,float gastosHospedaje,float gastosComida,float*costoMantenimiento);

#ifndef CALCULOS_H_
#define CALCULOS_H_
#endif /* CALCULOS_H_ */
