#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#include "Compras.h"
#include "LinkedList.h"
#include "parser.h"
#include "utn.h"

/** \brief Carga los datos de los Compras desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListCompra LinkedList*
 * \return int
 *
 */

int controller_cargarComprasDesdeTexto(char* path,LinkedList* listaCompras) {//esta funcion retorna un entero y recibe por parametro
	int retorno = -1; 														//puntero = apunta y accede a una direcion de memoria(referecia)
	FILE* pfile = NULL;															//sea a una funcion o una vaariable
	//declaro variable de tipo puntero a archivo  y la inicializo en NULL.
	if (path != NULL && listaCompras != NULL && ll_len(listaCompras) >= 0) {
		pfile = fopen(path, "r");
		if (pfile != NULL) {
			if (parser_ComprasFromText(pfile, listaCompras) != -1) { //Lo leo  al archivo linea por linea con parcer
			
			}
		} else {
			printf("Saliendo...\n");
			retorno = -1;
		}
	} else {
		printf("Archivo encontrado. ");

		retorno = 0;
	}

	return retorno;
}
/** \brief Listar compras
 *
 * \param path char*
 * \param pArrayListCompras LinkedList*
 * \return int
 *
 */
int controller_listarCompras(LinkedList *listaCompras) {

	int retorno = -1;
	int codigoCompra;
	int origen;
	int cantifdad;
	int validadorFunc;
	char descripcion[100];
	char origenDeCompra[100];
	float precioUnitario;
	float totalCompra;
	Compras* unaCompra = comp_new();//asigno memoria e inicializo los campos de mi entidad.
	if (listaCompras != NULL && unaCompra != NULL) {

		printf(
				"\n*----------------------------------------------------------------------------------------------*\n");
		printf("%s%s%s%s%s%s", "|  ID  |", " DESCRIPCION              |",
				"   TIPOS        |", " PRECIO * UNIDAD |", " CANTIDAD |",
				" TOTAL COMPRA |");
		printf(
				"\n*----------------------------------------------------------------------------------------------*\n");

		for (int i = 0; i < ll_len(listaCompras); i++) {
			unaCompra= (Compras*) ll_get(listaCompras,i);//recibo un puntero tipo void que me retorno ll_get y
														 //lo casteo para asignarlo a mi puntero una compra
			    		validadorFunc = comp_getCodigoCompra(unaCompra,&codigoCompra);//accede/obtiene// lee el dato/elemnto
			    																	  //y me lo devuelve  por referencia.
			    																	  //dirrecion de memoria
			    		if(validadorFunc == -1){
			    			printf("\nERROR EN ID COMPRA\n");
			    		}
			    		validadorFunc = comp_getDescripcion(unaCompra,descripcion);
			    		if(validadorFunc == -1){
			    			printf("\nERROR EN LA Descripcion\n");
			    		}
			    		validadorFunc=comp_getOrigen(unaCompra,&origen);
			    		if(validadorFunc == -1){
			    			printf("\nERROR EN EL TIPO \n");
			    		}
			    		validadorFunc=comp_getPrecioUnitario(unaCompra,&precioUnitario);
			    		if(validadorFunc==-1){
			    			printf("\nERROR EN EL PRECIO UNITARIO\n");
			    		}
			    		validadorFunc=comp_getCantidad(unaCompra,&cantifdad);
			    		if(validadorFunc==-1){
			    			printf("\nERROR EN LA CANTIDAD\n");
			    		}
			    		validadorFunc=comp_getTotalCompra(unaCompra,&totalCompra);
			    		if(validadorFunc==-1){
			    			printf("\nERROR EN TOTAL DE COMPRA\n");
			    		}
			    		comp_CargaDescripcion(origen,origenDeCompra);

				printf("| %4d | %-24s | %14s | %15.2f | %8d | %12.2f |\n",
						codigoCompra,descripcion,origenDeCompra,precioUnitario,cantifdad,totalCompra);
			}
			printf(
					"|----------------------------------------------------------------------------------------------|\n");
			retorno = 0;
		}

	printf("\n");
	return retorno;
}

/** \brief Guarda los datos de los Compras en el archivo Compras.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListSeleccion LinkedList*
 * \return int
 *
 */
int controller_guardarComprasModoTexto(char *path, LinkedList *listaCompras) {
	Compras *this = NULL;
	int retorno = -1;
	int codigoCompra;
	int origen;
	int cantifdad;
	int validadorFunc;
	char descripcion[100];
	float precioUnitario;
	float totalCompra;

	FILE *lista = fopen(path, "w");

	if (lista == NULL) {
		printf("Error para guardar\n");
		return retorno;
	}
	fprintf(lista,
			"codigoCompra,descripcion,origen,precioUnitario,cantidad,totalCompra\n");
	if (listaCompras != NULL) {
		for (int i = 0; i < ll_len(listaCompras); i++) {
			this = (Compras*) ll_get(listaCompras, i);
			validadorFunc = comp_getCodigoCompra(this, &codigoCompra);
			if (validadorFunc == -1) {
				printf("\nERROR EN ID COMPRA\n");
			}
			validadorFunc = comp_getDescripcion(this, descripcion);
			if (validadorFunc == -1) {
				printf("\nERROR EN LA Descripcion\n");
			}
			validadorFunc = comp_getOrigen(this, &origen);
			if (validadorFunc == -1) {
				printf("\nERROR EN EL TIPO \n");
			}
			validadorFunc = comp_getPrecioUnitario(this, &precioUnitario);
			if (validadorFunc == -1) {
				printf("\nERROR EN EL PRECIO UNITARIO\n");
			}
			validadorFunc = comp_getCantidad(this, &cantifdad);
			if (validadorFunc == -1) {
				printf("\nERROR EN LA CANTIDAD\n");
			}
			validadorFunc = comp_getTotalCompra(this, &totalCompra);
			if (validadorFunc == -1) {
				printf("\nERROR EN TOTAL DE COMPRA\n");
			}

			fprintf(lista, "%d,%s,%d, %.2f, %d,%.2f\n", codigoCompra,
					descripcion, origen, precioUnitario, cantifdad,
					totalCompra);
		}
		printf("Archivo Guardado.\n");
		retorno = 1;
	}
	fclose(lista);
	return retorno;
}
/** \brief Realiza un mapeo de Compras
 *
 * \param pArrarListCompras LinkedList*
 * \return int 0 si esta  ok
 *
 */

int controller_mapCompras(LinkedList *listaCompras) {
	int retorno = -1;
	if (listaCompras != NULL) {
		if (ll_map(listaCompras, comp_TotalCompras) == NULL) {//me retorna un puntero a lista mapeada segun la funcion criterio
			printf("No se ha podido realizar el mapeo. \n");
		} else {

			printf("TOTAL DE COMPRAS ACTUALIZADO CON EXITO \n");
			retorno = 0;
		}
	}
	return retorno;
}
/** \brief Filtra Compras
 *
 * \param pArrarListCompras LinkedList*
 * \return int
 *
 */
int controller_filterCompras(LinkedList *listaCompras) {
	int retorno = -1;
	LinkedList *filterList = NULL ;
	int opcion;
	if(listaCompras != NULL ){

	utn_getNumero(&opcion,
			"\n*--------------SubMenu------------------*"
					"\n|1-LISTADO DE COMPRAS DE ADMINISTRACION |\n|2-LISTADO DE COMPRAS DE TALLER         |\n|3-LISTADO DE COMPRAS DE VENTAS         |"
					"\n*---------------------------------------*\n",
			"INGRESE OPCION VALIDA", 0, 3, 5);
	switch (opcion) {
	case 1:
		filterList = ll_filter(listaCompras, comp_FilterTipoAdministracion);
		if (filterList != NULL && ll_len(filterList) > 0) {

				if (!utn_getCaracterSN(
						"Desea guardar la lista filtrada en 'filterTipo.csv?' s/n: ")) {
					controller_guardarComprasModoTexto("dataAdministracion.csv", filterList);

					controller_listarCompras(filterList);
					retorno = 0;
				} else {
					controller_listarCompras(filterList);
					printf("Saliendo sin guardar. \n");
				}
		}
		break;
	case 2:
		filterList = ll_filter(listaCompras, comp_FilterTipoTaller);
		if (filterList != NULL && ll_len(filterList) > 0) {

				if (!utn_getCaracterSN(
						"Desea guardar la lista filtrada en 'filterTipo.csv?' s/n: ")) {
					controller_guardarComprasModoTexto("dataTaller.csv", filterList);
					controller_listarCompras(filterList);
					retorno = 0;
				} else {
					controller_listarCompras(filterList);
					printf("Saliendo sin guardar. \n");
				}
		}
		break;
	case 3:
		filterList = ll_filter(listaCompras, comp_FilterTipoVentas);
		if (filterList != NULL && ll_len(filterList) > 0) {

				if (!utn_getCaracterSN(
						"Desea guardar la lista filtrada en 'filterTipo.csv?' s/n: ")) {
					controller_guardarComprasModoTexto("dataVentas.csv", filterList);

					controller_listarCompras(filterList);
					retorno = 0;
				} else {
					controller_listarCompras(filterList);
					printf("Saliendo sin guardar. \n");
				}
		}
		break;
	default:
		printf("Opcion no valida\n");
		break;
	}

	if(filterList == NULL){
		printf("no se ha podido realizar.\n");
	}
	ll_clear(filterList);
	ll_deleteLinkedList(filterList);
	}

	return retorno;
}
/** \brief Ordenar Compras
 *
 * \param path char*
 * \param pArrayListCompra LinkedList*
 * \return int
 *
 */

int controller_ordenarCompras(LinkedList *listaCompras){
	int retorno = -1;

	if (listaCompras != NULL) {
		printf("ORDENAMIENTO: \n");
		printf("\tDESCRIPCION DE MANERA ASCNDENTE\n");

		ll_sort(listaCompras, comp_sortByDescripcion, 1);
		printf("Ordenamiento ascendente por nombre realizado!\n");
	}
	return retorno;
}
