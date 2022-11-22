/*
 * prueba.h
 *
 *  Created on: 20 sept 2022
 *      Author: natal_000
 */
/**
 * \fn int Carga_Costos(float*, float*, float*, float*)
 * \brief Carga  y validacion de gastos  ingresesados.
 *
 * \param gastoTrasporte
 * \param gastoHospedaje
 * \param gastoComida
 * \return
 */
int Carga_Costos(float* gastoTrasporte,float* gastoHospedaje,float* gastoComida);
/**
 * \fn int jug_Alta(int*, int*, int*, int*, int*, int*, int*, int*, int*, int*, int*)
 * \brief alta de jugador carga de camiseta, posicion y confederacion
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
 * \param contadorJugadores
 * \return
 */
int jug_Alta(int *contadorAfc, int *contadorCaf, int *contadorConcaf,
		int *contadorConmebol, int *contadorUefa, int *contadorOfc,
		int *contadorArqueros, int *contadorDefensores,
		int *contadorMediocampistas, int *contadorDelanteros,
		int *contadorJugadores);
/**
 * \fn int Carga_Confederacion(int*, int*, int*, int*, int*, int*)
 * \brief contadores por cada confederacion que se van incrementado por jugador
 *
 * \param contadorAfc
 * \param contadorCaf
 * \param contadorConcaf
 * \param contadorConmebol
 * \param contadorUefa
 * \param contadorOfc
 * \return
 */
int Carga_Confederacion(int*contadorAfc,int*contadorCaf,int*contadorConcaf,int*contadorConmebol,int*contadorUefa,int*contadorOfc);
/***
 * \fn int Carga_Posicion(int*, int*, int*, int*, int*)
 * \brief  selecion de  la posicion del jugador
 *
 * \param contadorArqueros
 * \param contadorDefensores
 * \param contadorMediocampistas
 * \param contadorDelanteros
 * \param contadorJugadores
 * \return
 */
int Carga_Posicion(int*contadorArqueros,int*contadorDefensores,int*contadorMediocampistas,int*contadorDelanteros,int* contadorJugadores);





#ifndef PRUEBA_H_
#define PRUEBA_H_

#endif /* PRUEBA_H_ */
