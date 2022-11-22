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


int infome_Costos(float gastoTrasporte, float gastoHospedaje, float gastoComida);

void informe_Confederacion(int contadorAfc, int contadorCaf, int contadorConcaf,int contadorConmebol, int contadorUefa, int contadorOfc);

void informe_Posicion(int contadorArqueros,int contadorDefensores,int contadorMediocampistas,int contadorDelanteros);

int informe_Promedio(float promedioAfc,float promedioCaf,float promedioConcaf,float promedioConmebol,float promedioUefa,float promedioOfc);

void informar_CostoMantenimiento(float* costoMantenimiento);

void menu_Costos(char *opcion);

#endif /* INFORMES_H_ */
