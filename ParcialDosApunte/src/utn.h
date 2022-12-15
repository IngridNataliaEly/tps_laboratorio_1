/*
 * utn.h
 *
 *  Created on: 6 oct 2022
 *      Author: natal_000
 */
#ifndef UTN_H_
#define UTN_H_
int getValidYesNoChar(char mensaje[], char errorMensaje[]);
int esPosicion(char* cadena,int size);
int informesMenu(void);
int isYesNoCharacter(char caracter);

/**
 * \fn int utn_getNumero(int*, char*, char*, int, int, int)
 * \brief Pide un numero entero donde validamos el rango. o si no sirve nos devuelve error.
 *
 * \param pResultado le paso la dirrecion de memoria del numero en la main
 * \param mensaje
 * \param mensajeError
 * \param minimo establece un minimo
 * \param maximo establece un maximo
 * \param reintentos Le da  reintentos al usuario
 * \return Si salio todo OK = 0 o hubo ERROR = -1
 */
int utn_getNumero(int* pResultado,char* mensaje,char* mensajeError,int minimo,int maximo,int reintentos);
/**
 * \fn int getInt(int*)
 * \brief  Obtener numero entero.SOLO SALE A BUSCAR NUMERO ENTERO
 *
 * \param pResultado
 * \return
 */
int getInt(int* pResultado);
/**
 * \fn int myGets(char*, int)
 * \brief Recibe un buffer un string carga lo que el usuario ingreso y no me desborda el buffer
 *
 * \param cadena  Me va dejar el string que el usuario ingreso
 * \param size   el tamaño del string
 * \return devuelve OK = 0 , o ERROR = -1;
 */
int myGets(char* cadena, int size);
/**
 * \fn int esNumerica(char*, int)
 * \brief  Le paso el buffer string correctamente cargado y me dice si es un numero
 * Utiliza la funcion ATOI.
 * \param cadena
 * \param longitud
 * \return Devuelve VERDADERO = 0 o FALSO = 1
 */
int esNumerica(char* cadena, int longitud);

int utn_getNumeroFlotante(float* pResultado,char* mensaje,char* mensajeError,float minimo,float maximo,int reintentos);

int getFloat(float* pResultado);

int esFlotante(char* cadena);

int utn_getNombre(char* pResultado,char* mensaje,char* mensajeError,int reintentos,int size);

int utn_getString(char aux[],char* mensaje,char* mensajeError, int reintentos);

int getNombre(char* pResultado,int size);

int esNombre(char* cadena,int size);

int numeroTelefonicoConguionmedio(char*pResultado);

int numeroTelefonico(char*pResultado);

int esSoloLetra(char *pResultado);

int esLetraConEspacio(char *pResultado);

void formarApellidoNombre(char pNombre[],char pApellido[],char pCompleto[]);

void getString(char* mensaje, char imput[]);

void getChar(char* mensaje,char* respuesta);

void inicializarArrayChar(char pArray[], int cantidadDeArray);

int inicializarArrayFlotante(float pArray[], int cantidadDeArray);

int imprimirArrayFlotante(float pArray[], int cantidadDeArray);

int inicializarArrays(char arrays[],int cantidad);

int validarArrayAlfanumerico(char* arraylist,int size);

int utn_getCaracterSN(char* mensaje);









#endif /* UTN_H_ */
