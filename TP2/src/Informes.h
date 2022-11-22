/*
 * Informes.h
 *
 *  Created on: 22 nov 2022
 *      Author: natal_000
 */
int subMenuInformes(void);

int mostrarInformes(eJugador lista[], int size, eConfederacion confederaciones[], int size_conf);

int ordenarPersonasConfederacionNombreAlfabeticamente(eJugador lista[], int size, eConfederacion confederaciones[], int size_conf);

int mostrarPersonasIdConfederacion(int idConfederacion, eJugador lista[], int size, eConfederacion confederaciones[], int size_conf);

int informarConfederacionesConJugadores(eJugador lista[], int size, eConfederacion confederaciones[], int size_conf);

int informarTotalPromedioSalarios(eJugador lista[], int size);

int informarConfederacionMayorCantidadAniosContratoTotal(eJugador lista[], int size, eConfederacion confederaciones[], int size_conf);

int informarPorcentajeJugadoresPorConfederacion(eJugador lista[], int size, eConfederacion confederaciones[], int size_conf);

int informarRegionConMasJugadoresListar(eJugador lista[], int size, eConfederacion confederaciones[], int size_conf);



