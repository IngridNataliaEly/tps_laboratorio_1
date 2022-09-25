/*
 * prueba.h
 *
 *  Created on: 20 sept 2022
 *      Author: natal_000
 */

void mostrarMenu(void);
int utn_getNumero(char* mensaje,char* mensajeError,int minimo,int maximo);
void utn_validacionCaracter(char *opcion);
void ingresoCostos(int *bandera,int* sumaT,int* sumaH,int* sumaC,int*costoMantenimiento);
void utn_validacionCamiseta(void);
void utn_validacionConfederacion(int*opcion);
void utn_validacionPosicion(int *opcion,char*mensaje,char*mensajeError,int minimo,int maximo);
void ingresarConfederacion(int*contadorAfc,int*contadorCaf,int*contadorConcaf,int*contadorConmebol,int*contadorUefa,int*contadorOfc);
void cargaPosicion(int*contadorArqueros,int*contadorDefensores,int*contadorMediocampistas,int*contadorDelanteros,int*i);
void cargaJugadores(int*banderaCostos,int*banderaCarga,int*contadorAfc,int*contadorCaf,int*contadorConcaf,int*contadorConmebol,int*contadorUefa, int *contadorOfc
					,int*contadorArqueros,int*contadorDefensores,int*contadorMediocampistas,int*contadorDelanteros,int*i);
void realizarCalculos(int*banderaCostos,int*banderaCarga,int*banderaCalculos,int*banderadaCalculos,int*i,int*contadorAfc,int*contadorCaf,int*contadorConcaf,int*contadorConmebol,int*contadorUefa,int*contadorOfc,float*promedioAfc,float* promedioCaf,float*promedioConcaf,float*promedioConmebol,float*promedioUefa,float*promedioOfc);
int utn_promedioMercados(int*i,int*contadorAfc,int*contadorCaf,int*contadorConcaf,int*contadorConmebol,int*contadorUefa,int*contadorOfc,float*promedioAfc,float* promedioCaf,float*promedioConcaf,float*promedioConmebol,float*promedioUefa,float*promedioOfc);
void utn_mostrarPromedio(float*promedioAfc,float*promedioCaf,float*promedioConcaf,float*promedioConmebol,float*promedioUefa,float*promedioOfc);
void realizarCostos(int*banderaCostos,int*banderaCarga,int*banderaCalculos,int*sumaT,int*sumaH,int*sumaC,int*costoMantenimiento);
int utn_CostosMantenimiento(int*banderaCostos,int*banderaCarga,int*banderaCalculos,int*sumaT,int*sumaH,int*sumaC,int*costoMantenimiento);
void utn_mostrarCosto(int*costoMantenimiento);
void utn_mayorContador(float*aumento,float*costoFinal,int*costoMantenimiento,int*contadorAfc,int*contadorCaf,int*contadorConcaf,int*contadorConmebol,int*contadorUefa,int*contadorOfc);
void utn_validacioPrecio(int*numero,char*mensaje,char*mensajeError,int minimo,int maximo);



#ifndef PRUEBA_H_
#define PRUEBA_H_

#endif /* PRUEBA_H_ */
