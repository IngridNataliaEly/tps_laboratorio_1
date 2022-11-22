/*
 * calculos.h
 *
 *  Created on: 25 sept 2022
 *      Author: natal_000
 */
int Incremento_Costos(float gastoIngresado, float *acumuladorCostosMant);
int calcular_Promedio(int contador, int cantidadJugadores, float* promedio);
int calcular_AumentoCostos(float*aumento,float*costoFinal,float*costoMantenimiento,int*contadorAfc,int*contadorCaf,int*contadorConcaf,int*contadorConmebol,int*contadorUefa,int*contadorOfc);
float calcular_PorcentajeFloat(float porcentaje,float total);
int Calcular_CostosMantenimiento(float gastosTransporte,float gastosHospedaje,float gastosComida,float*costoMantenimiento);

#ifndef CALCULOS_H_
#define CALCULOS_H_
#endif /* CALCULOS_H_ */
