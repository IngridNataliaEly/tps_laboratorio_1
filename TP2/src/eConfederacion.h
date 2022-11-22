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


int altaConfederacion(eConfederacion confederaciones[], int* pId, int size_conf);

int modificarConfederacion(eConfederacion confederaciones[], int size_conf);

int menuModificarConf();

int buscarConfederacionId(eConfederacion confederaciones[],int Id, int size_conf);

int cargarDescripcionConfederacion(eConfederacion confederaciones[], int size,int idConfederacion, char descripcion[]);

void mostrarConfederacion(eConfederacion confederacion);

int mostrarConfederaciones(eConfederacion confederaciones[], int size);

int validarIdConfederacion(int id, eConfederacion confederaciones[], int size);

int eStr_AltaConfederacion(eConfederacion*tipos,int size);


eConfederacion eStr_CargarDatosConfederacion(eConfederacion *tipos,int size);



#endif /* ECONFEDERACION_H_ */
