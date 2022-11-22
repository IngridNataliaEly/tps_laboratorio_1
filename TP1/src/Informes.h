/*
 * Informes.h
 *
 *  Created on: 19 nov 2022
 *      Author: natal_000
 */

#ifndef INFORMES_H_
#define INFORMES_H_
/*
 * Informes.c
 *
 *  Created on: 19 nov 2022
 *      Author: natal_000
 */

/**
 * \fn int infome_Costos(float, float, float)
 * \brief  muestra los costos ingresados a medidad que se van cargando
 *
 * \param gastoTrasporte
 * \param gastoHospedaje
 * \param gastoComida
 * \return
 */
int infome_Costos(float gastoTrasporte, float gastoHospedaje, float gastoComida);
/**
 * \fn void informe_Confederacion(int, int, int, int, int, int)
 * \brief  muestra los contadores de las confederaciones que sevan ingresado.
 *
 * \param contadorAfc
 * \param contadorCaf
 * \param contadorConcaf
 * \param contadorConmebol
 * \param contadorUefa
 * \param contadorOfc
 */
void informe_Confederacion(int contadorAfc, int contadorCaf, int contadorConcaf,int contadorConmebol, int contadorUefa, int contadorOfc);
/**
 * \fn void informe_Posicion(int, int, int, int)
 * \brief muestra la posicion de cada jugador a medida que se va actualizadno.
 *
 * \param contadorArqueros
 * \param contadorDefensores
 * \param contadorMediocampistas
 * \param contadorDelanteros
 */
void informe_Posicion(int contadorArqueros,int contadorDefensores,int contadorMediocampistas,int contadorDelanteros);
/**
 * \fn int informe_Promedio(float, float, float, float, float, float)
 * \brief  muestra los promedio de cada confederacion que se calculo en el p3
 *
 * \param promedioAfc
 * \param promedioCaf
 * \param promedioConcaf
 * \param promedioConmebol
 * \param promedioUefa
 * \param promedioOfc
 * \return
 */
int informe_Promedio(float promedioAfc,float promedioCaf,float promedioConcaf,float promedioConmebol,float promedioUefa,float promedioOfc);
/**
 * \fn void informar_CostoMantenimiento(float*)
 * \brief muestra la suma de los gastos de consto de mantenimiento
 *
 * \param costoMantenimiento
 */
void informar_CostoMantenimiento(float* costoMantenimiento);
/**
 * \fn void menu_Costos(char*)
 * \brief
 *
 * \param opcion
 */
void menu_Costos(char *opcion);

#endif /* INFORMES_H_ */
