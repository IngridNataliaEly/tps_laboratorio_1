/*
 * eJugador.h
 *
 *  Created on: 24 oct 2022
 *      Author: natal_000
 */


#ifndef EJUGADOR_H_
#define EJUGADOR_H_
#define BUSSY 1
#define FREE 0
#define BAJA -1
#define TAM 50
#define TIPOS 6
#include "eConfederacion.h"
#include "eJugador.h"

typedef struct{

	int id;
	char nombre[TAM];
	char posicion[TAM];
	short numeroCamiseta;
	int idConfederacion;
	float salario;
	short aniosContrato;
	short isEmpty;

}eJugador;


int menu(void);
int menuModificacion(void);
//ABM
int eStr_Alta(eJugador*unJugador,int tam,eConfederacion *tipos,int size);
int eStr_Baja(eJugador *jugador, int size, eConfederacion *tipos,int tam);
eJugador eStr_CargarDatos(void);
int eStr_BuscarPorID(eJugador* unJugador,int tam,int iD);
eJugador eStr_ModificarUno(eJugador unJugador);
int eStr_Modificacion(eJugador* unJugador,int tam,eConfederacion*tipos,int size);





void eStr_MostrarUno(eJugador unJugador,eConfederacion*tipos,int tam);
int eStr_MostrarTodos(eJugador*unJugador,int tam,eConfederacion*tipos,int size);
int subMenuInformes(void);
int eStr_ObtenerIndexLibre(eJugador *unJugador,int tam);
int eStr_BuscarPorID(eJugador *unJugador,int tam, int iD);



void mostrarInformes(int opcion);
#endif /* EJUGADOR_H_ */
