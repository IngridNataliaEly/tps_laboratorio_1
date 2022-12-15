#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "LinkedList.h"
#include "Compras.h"
#include "utn.h"

/** \brief Parsea los datos de los Compras desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListCompras LinkedList*
 * \return int
 */
int parser_ComprasFromText(FILE *pFile, LinkedList* pArrarListCompras) {
	Compras *unaCompra = NULL;//creo un puntero de tipo compras y lo inicializo
	int retornoAux = -1;
	char codigoCompra[500];
	char descripcion[500];
	char origen[500];
	char precioUnitario[500];
	char cantidad[500];
	char totalCompra[500];
	int i;
	i = 0;

	if (pFile != NULL){
		fscanf(pFile, "%[^,],%[^,],%[^,],%[^,],%[^,],%[^\n]\n", codigoCompra,//lee hasta la come y la excluye y hace un salto de linea
				descripcion, origen, precioUnitario, cantidad, totalCompra); //lectura fantasma
		do {
			if (fscanf(pFile, "%[^,],%[^,],%[^,],%[^,],%[^,],%[^\n]\n",
					codigoCompra, descripcion, origen, precioUnitario, cantidad,
					totalCompra) == 6) {
				retornoAux = 0;
				unaCompra = comp_newParametros(codigoCompra, descripcion, origen,
						precioUnitario, cantidad, totalCompra);
				if (unaCompra != NULL) {
					ll_add(pArrarListCompras, unaCompra);
					i++;
				}
			}
		} while (!feof(pFile));//lee hasata el final del archivo
		fclose(pFile);

		printf("\nARCHIVO CARGADO EXITOSAMENTE. Bytes leidos %d\n", i);

	}
	return retornoAux;
}

