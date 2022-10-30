/*
 * eConfederacion.h
 *
 *  Created on: 24 oct 2022
 *      Author: natal_000
 */

#ifndef ECONFEDERACION_H_
#define ECONFEDERACION_H_

#include "eJugador.h"



typedef struct{

	int id;
	char nombre[50];
	char region[50];
	int anioCreacion;

}eConfederacion;

int buscarTipos(eConfederacion *tipos,int size,int idSectores,char *descripcion);

int eStr_AltaConfederacion(eConfederacion *tipos,int size);
void listaConfederaciones(eConfederacion *tipos,int size);
eConfederacion eStr_CargarDatosConfederacion(eConfederacion*tipos,int size);


#endif /* ECONFEDERACION_H_ */
