#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#include "LinkedList.h"
#include "Controller.h"
#include "Jugador.h"
#include "parser.h"
#include "Seleccion.h"
#include "utn.h"


int main()
{
	setbuf(stdout,NULL);
    int option = 0;
    //int cantidad;
    LinkedList* listaJugadores = ll_newLinkedList();
    LinkedList* pArrayListSeleccion = ll_newLinkedList();



    do{
    	utn_getNumero(&option, "1.CARGA DE ARCHIVOS: \n2.ALTA DE JUGADOR: \n3. MODIFICACIÓN DE JUGADOR: \n4.BAJA DE JUGADOR: \n5.LISTADOS: \n6.CONVOCAR JUGADORES:"
    			"\n7.ORDENAR Y LISTAR: \n8.GENERAR ARCHIVO BINARIO: \n9.CARGAR ARCHIVO BINARIO: \n10.GUARDAR ARCHIVOS .CSV: \n11.SALIR:", "opcion 1 ", 0, 11, 5);
        switch(option)
        {
            case 1:
            	controller_cargarJugadoresDesdeTexto("jugadores.csv",listaJugadores);
            	controller_listarJugadores(listaJugadores);

            	controller_cargarSeleccionesDesdeTexto("selecciones.csv", pArrayListSeleccion);
            	controller_listarSelecciones(pArrayListSeleccion);


                break;
            case 2:
            	controller_agregarJugador(listaJugadores);
            	break;
            case 3:
            	controller_listarJugadores(listaJugadores);
            	controller_editarJugador(listaJugadores);

            	break;
            case 4:
            	controller_listarJugadores(listaJugadores);
            	controller_removerJugador(listaJugadores);
            	break;

        }
    }while(option != 10);

    return 0;
}

