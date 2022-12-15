/*
 ============================================================================
 Name        : 1JSP.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 Alumna : Ingrid Natalia Ely
 ============================================================================
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "LinkedList.h"
#include "Controller.h"
#include "Compras.h"
#include "parser.h"
#include "utn.h"

int main() {
	setbuf(stdout, NULL);
	int option = 0;
	int flag = 1;
	int flagSort = 1;
	int respuesta = 1;
	LinkedList* listaCompras = ll_newLinkedList();
	do {
		utn_getNumero(&option,
				"\n*---------Menu----------*\n"
						"|1.CARGA DE ARCHIVOS: \t|\n|2.LISTAR COMPRAS:  "
						" \t|\n|3.ASIGNAR TOTALES:\t|\n|4.FILTRAR POR TIPOS: \t|"
						"\n|5.ORDENAR COMPRAS: \t|\n|6.GUARDAR COMPRAS:\t|\n|7.SALIR:\t\t|\n"

						"*-----------------------*\n"
				"OPCION: ", "INGRESE OPCION VALIDA ",
				1, 7, 7);
		switch (option) {
		case 1:
			controller_cargarComprasDesdeTexto("data.csv", listaCompras);
			flag = 0;
			break;
		case 2:
			if (!flag) {
				controller_listarCompras(listaCompras);
			} else {
				puts("DEBE CARGAR LOS ARCHIVOS");
			}
			break;
		case 3:
			if (!flag) {
				controller_mapCompras(listaCompras);
				controller_listarCompras(listaCompras);
			} else {
				puts("DEBE CARGAR LOS ARCHIVOS");
			}
			break;
		case 4:
			if (!flag) {
				controller_filterCompras(listaCompras);
			} else {
				puts("DEBE CARGAR LOS ARCHIVOS");
			}
			break;
		case 5:
			if (!flag) {
				flagSort = 0;
				controller_ordenarCompras(listaCompras);
				controller_listarCompras(listaCompras);
			} else {
				puts("DEBE CARGAR LOS ARCHIIVOS");
			}
			break;
		case 6:
			if (!flagSort) {
				controller_guardarComprasModoTexto("dataSort.csv",
						listaCompras);
			} else {
				puts("DEBE ORDENAR LAS COMPRAS, OPCION 5");
			}
			break;
		case 7:
			respuesta = utn_getCaracterSN(
					"\n¿DESEA SALIR DEL SISTEMA? S o N : \n");
			break;
		}
	} while (respuesta != 0);
	puts("\nHa finalizado el programa.");
	ll_clear(listaCompras);
	ll_deleteLinkedList(listaCompras);
	return 0;
}
