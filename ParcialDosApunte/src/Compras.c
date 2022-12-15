#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "Compras.h"
#include "utn.h"

Compras* comp_new(){ //CONSTRUCTOR POR DEFECTO: PIDE MEMORIA DINAMICA E INICIALIZA CADA CAMPO DE LA ENTIDAD LOS ENTEROS EN 0.
	Compras* auxiliarP = NULL;
	auxiliarP = (Compras*) malloc(sizeof(Compras));//MALLOC: MEMORY ALLOCATE (ASIGNAR)
	if(auxiliarP != NULL)
	{
		comp_setCantidad(auxiliarP, 0);
		comp_setCodigoCompra(auxiliarP, 0);
		comp_setDescripcion(auxiliarP,"");
		comp_setOrigen(auxiliarP, 0);
		comp_setPrecioUnitario(auxiliarP, 0);
		comp_setTotalCompra(auxiliarP, 0);
	}
	return auxiliarP;
}
Compras* comp_newParametros(char *codigoCompra, char *descripcion, char *origen,//CONSTRUCTOR  PARAMETRIZADO : ASIGNA LO QUE RECIBE
		char *precioUnitario, char *cantidad, char *totalCompra) { 				//POR PARRAMETRO A LOS CAMPOS DE LA ENTIDAD.
	Compras *this;
	this = comp_new();
	if (this != NULL && codigoCompra != NULL && descripcion != NULL
			&& origen != NULL && precioUnitario != NULL && cantidad != NULL
			&& totalCompra != NULL) {

		if (comp_setCodigoCompra(this, atoi(codigoCompra)) == -1
				|| comp_setDescripcion(this, descripcion) == -1
				|| comp_setOrigen(this, atoi(origen)) == -1
				|| comp_setPrecioUnitario(this, atof(precioUnitario)) == -1
				|| comp_setCantidad(this, atoi(cantidad)) == -1
				|| comp_setTotalCompra(this, atof(totalCompra)) == -1) {

			comp_delete(this);
			this = NULL;
		}
	}
	return this;
}
void comp_delete(Compras *this) {
	if (this != NULL) {
		free(this);
	}
}
int comp_setCodigoCompra(Compras *this, int codigoCompra) {//setea/actualiza/modifica el dato en caso X
	int retorno = -1;
	if (this != NULL && codigoCompra >= 0) {
		retorno = 0;
		this->codigoCompra = codigoCompra;
	}
	return retorno;
}
int comp_getCodigoCompra(Compras *this, int *codigoCompra) {
	int retorno = -1;
	if (this != NULL && codigoCompra != NULL) {
		retorno = 0;
		*codigoCompra = this->codigoCompra;
	}
	return retorno;
}
int comp_setDescripcion(Compras *this, char *descripcion) {
	int retorno = -1;
	if (this != NULL && descripcion != NULL) {
		if (!esNombre(descripcion, 500)) {
			retorno = 0;
			strncpy(this->descripcion, descripcion, 500);
		}
	}
	return retorno;
}
int comp_getDescripcion(Compras *this, char *descripcion) {
	int retorno = -1;

	if (this != NULL && descripcion != NULL) {
		retorno = 0;
		strncpy(descripcion, this->descripcion, 100);
	}
	return retorno;
}
int comp_setOrigen(Compras *this, int origen) {
	int retorno = -1;
	if (this != NULL && origen >= 0) {

		retorno = 0;
		this->origen = origen;
	}
	return retorno;
}
int comp_getOrigen(Compras *this, int *origen) {
	int retorno = -1;
	if (this != NULL && origen != NULL) {
		retorno = 0;
		*origen = this->origen;
	}
	return retorno;
}
int comp_setPrecioUnitario(Compras *this, float precioUnitario) {
	int retorno = -1;
	if (this != NULL && precioUnitario >= 0) {

		retorno = 0;
		this->precioUnitario = precioUnitario;
	}
	return retorno;
}
int comp_getPrecioUnitario(Compras *this, float *precioUnitario) {
	int retorno = -1;
	if (this != NULL && precioUnitario != NULL) {
		retorno = 0;
		*precioUnitario = this->precioUnitario;
	}
	return retorno;
}
int comp_setCantidad(Compras *this, int cantidad) {
	int retorno = -1;
	if (this != NULL && cantidad >= 0) {

		retorno = 0;
		this->cantidad = cantidad;
	}
	return retorno;
}
int comp_getCantidad(Compras *this, int *cantidad) {
	int retorno = -1;
	if (this != NULL && cantidad != NULL) {
		retorno = 0;
		*cantidad = this->cantidad;
	}
	return retorno;
}
int comp_setTotalCompra(Compras *this, float totalCompra) {
	int retorno = -1;
	if (this != NULL && totalCompra >= 0) {

		retorno = 0;
		this->totalCompra = totalCompra;
	}
	return retorno;
}
int comp_getTotalCompra(Compras *this, float *totalCompra) {
	int retorno = -1;
	if (this != NULL && totalCompra != NULL) {
		retorno = 0;
		*totalCompra = this->totalCompra;
	}
	return retorno;
}
/**
 * \fn int comp_sortByDescripcion(void*, void*)
 * \brief compara la descripcion y retorna el orden por int
 *
 * \param compA
 * \param compB
 * \return int + positivo si descripB es mayor que descripA
 * \return int - negativo si descripB es menor que descripA
 */
int comp_sortByDescripcion(void *compA, void *compB) {//comparar
	int retorno = -1;
	Compras *descripA = NULL;
	Compras *descripB = NULL;

	char descripcionA[100];
	char descripcionB[100];

	if (compA != NULL && compB != NULL) {
		descripA = (Compras*) compA;
		descripB = (Compras*) compB;

		comp_getDescripcion(descripA,descripcionA);
		comp_getDescripcion(descripB,descripcionB);

		retorno = strcmp(descripcionA,descripcionB);
	}
	//devuelve 0 = Si las cadenas son iguales
	//devuelve >0 = Si cadena1 > cadena2
	//devuelve <0 = Si cadena1 < cadena2

	return retorno;
}
/**
 * \fn int comp_MapTotalCompras(void*)
 * \brief
 *
 * \param p
 * \return
 */
void* comp_TotalCompras(void *pElement) {

	float precioUnidad;
	int cantidad;
	float totalCargar;

	Compras *compraUno = NULL;
	if (pElement != NULL) {
		compraUno = (Compras*) pElement;

		comp_getPrecioUnitario(compraUno, &precioUnidad);
		comp_getCantidad(compraUno, &cantidad);

		totalCargar = (float) cantidad * precioUnidad;
		comp_setTotalCompra(compraUno, totalCargar);

		compraUno = (void*) compraUno;

	}
	return compraUno;
}
int comp_FilterTipoAdministracion(void *pElement) {
	int retorno = 0;
	Compras *comUno;
	int origen;
	if (pElement != NULL) {
		comUno = (Compras*) pElement;
		comp_getOrigen(comUno, &origen);
		if (origen == 1) {

			retorno = 1;
		}
	}
	return retorno;
}
int comp_FilterTipoTaller(void *pElement) {
	int retorno = 0;
		Compras *comUno;
		int origen;
		if (pElement != NULL) {
			comUno = (Compras*) pElement;
			comp_getOrigen(comUno, &origen);
			if (origen == 2) {

				retorno = 1;
			}
		}
		return retorno;
	}
int comp_FilterTipoVentas(void *pElement) {
	int retorno = 0;
		Compras *comUno;
		int origen;
		if (pElement != NULL) {
			comUno = (Compras*) pElement;
			comp_getOrigen(comUno, &origen);
			if (origen == 3) {

				retorno = 1;
			}
		}
		return retorno;
	}
int comp_CargaDescripcion(int origen, char *descripcion) {
	int retorno = -1;
	if (descripcion != NULL && origen >= 1 && origen <= 3) {
		if (origen == 1) {
			strcpy(descripcion, "ADMINISTRACION");
		} else if (origen == 2) {
			strcpy(descripcion, "TALLER");
		} else {
			strcpy(descripcion, "VENTAS");
		}
		retorno = 0;
	} else {
		printf("ERROR!En carga de descripcion tipos");
	}
	return retorno;
}
