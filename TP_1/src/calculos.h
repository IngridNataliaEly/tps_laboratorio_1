/*
 * calculos.h
 *
 *  Created on: 25 sept 2022
 *      Author: natal_000
 */

void realizarCalculos(int*i,int*contadorAfc,int*contadorCaf,int*contadorConcaf,int*contadorConmebol,int*contadorUefa,int*contadorOfc,float*promedioAfc,float* promedioCaf,float*promedioConcaf,float*promedioConmebol,float*promedioUefa,float*promedioOfc);
int utn_promedioMercados(int*i,int*contadorAfc,int*contadorCaf,int*contadorConcaf,int*contadorConmebol,int*contadorUefa,int*contadorOfc,float*promedioAfc,float* promedioCaf,float*promedioConcaf,float*promedioConmebol,float*promedioUefa,float*promedioOfc);
void utn_mostrarPromedio(float*promedioAfc,float*promedioCaf,float*promedioConcaf,float*promedioConmebol,float*promedioUefa,float*promedioOfc);
void realizarCostos(int*sumaT,int*sumaH,int*sumaC,int*costoMantenimiento);
int utn_CostosMantenimiento(int*sumaT,int*sumaH,int*sumaC,int*costoMantenimiento);
void utn_mostrarCosto(int*costoMantenimiento);
void utn_mayorContador(float*aumento,float*costoFinal,int*costoMantenimiento,int*contadorAfc,int*contadorCaf,int*contadorConcaf,int*contadorConmebol,int*contadorUefa,int*contadorOfc);

#ifndef CALCULOS_H_
#define CALCULOS_H_
#endif /* CALCULOS_H_ */
