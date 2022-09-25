/*
 * datos.h
 *
 *  Created on: 25 sept 2022
 *      Author: natal_000
 */
void mostrarMenu(void);
int utn_getNumero(char* mensaje,char* mensajeError,int minimo,int maximo);
void utn_validacionCaracter(char *opcion);
void ingresoCostos(int* sumaT,int* sumaH,int* sumaC,int*costoMantenimiento);
void utn_validacionCamiseta(void);
void utn_validacionConfederacion(int*opcion);
void utn_validacionPosicion(int *opcion,char*mensaje,char*mensajeError,int minimo,int maximo);
void ingresarConfederacion(int*contadorAfc,int*contadorCaf,int*contadorConcaf,int*contadorConmebol,int*contadorUefa,int*contadorOfc);
void cargaPosicion(int*contadorArqueros,int*contadorDefensores,int*contadorMediocampistas,int*contadorDelanteros,int*i);
void cargaJugadores(int*contadorAfc,int*contadorCaf,int*contadorConcaf,int*contadorConmebol,int*contadorUefa, int *contadorOfc
					,int*contadorArqueros,int*contadorDefensores,int*contadorMediocampistas,int*contadorDelanteros,int*i);
void utn_getNumeroPrecio(int*numero,char*mensaje,char*mensajeError,int minimo,int maximo);

#ifndef DATOS_H_
#define DATOS_H_



#endif /* DATOS_H_ */
