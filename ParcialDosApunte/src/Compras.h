
#include "LinkedList.h"

#ifndef jug_H_INCLUDED
#define jug_H_INCLUDED

typedef struct
{
	int codigoCompra;
	char descripcion[500];
	int origen;
	float precioUnitario;
	int cantidad ;
	float totalCompra;
}Compras;

Compras* comp_new();
Compras* comp_newParametros(char* codigoCompra,char* descripcion,char* origen, char* precioUnitario, char* cantidad, char* totalCompra);


void comp_delete(Compras* this);

int comp_setCodigoCompra(Compras* this,int codigoCompra);
int comp_getCodigoCompra(Compras* this,int* codigoCompra);

int comp_setDescripcion(Compras* this,char* descripcion);
int comp_getDescripcion(Compras* this,char* descripcion);

int comp_setOrigen(Compras* this,int edad);
int comp_getOrigen(Compras* this,int* edad);

int comp_setPrecioUnitario(Compras* this,float precioUnitario);
int comp_getPrecioUnitario(Compras* this,float* precioUnitario);

int comp_setCantidad(Compras* this,int cantidad);
int comp_getCantidad(Compras* this,int* cantidad);

int comp_setTotalCompra(Compras* this,float totalCompra);
int comp_getTotalCompra(Compras* this,float* totalCompra);

int comp_sortByDescripcion(void* compA, void* compB);
void* comp_TotalCompras(void* pElement);

int comp_FilterTipoAdministracion(void* pElement);

int comp_FilterTipoTaller(void* pElement);

int comp_FilterTipoVentas(void* pElement);

int comp_CargaDescripcion(int origen,char* descripcion);


#endif // jug_H_INCLUDED
