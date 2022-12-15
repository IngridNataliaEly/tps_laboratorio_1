#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LinkedList.h"
//esto va a estar en el heap, tengo que crearlo en el heap (Segmento del Heap: En este segmento se guardan
//las variables que han sido creadas dinámicamente en tiempo de ejecución). Esto simplemente es un puntero
//que está en la pila.¿Cómo hago para crearlo en el montón?
//Bueno, hay un constructor.Voy a hacer mi lista igual. Ll todas las funciones del link que empiezan con él
//.Guión bajo.Guión bajo abajo, no guión bajo.New Link.Hora.Entonces, esta función me creo la lista memoria.
//Y yo ahora quiero agregar cosas a la lista, tengo que primero crearla.
static Node* getNode(LinkedList *this, int nodeIndex);
static int addNode(LinkedList *this, int nodeIndex, void *pElement);

/** \brief Crea un nuevo LinkedList en memoria de manera dinamica
 *
 *  \param void
 *  \return LinkedList* Retorna (NULL) en el caso de no conseguir espacio en memoria
 *                      o el puntero al espacio reservado
 */
LinkedList* ll_newLinkedList(void) {//contructor por defecto: asigna memoria por MALLOC y inizializa
	//los campos
	LinkedList *this = NULL;
	this = (LinkedList*) malloc(sizeof(LinkedList));
	if (this != NULL) {
		this->pFirstNode = NULL;
		this->size = 0;
	}
	return this;
}

/** \brief Retorna la cantidad de elementos de la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \return int Retorna (-1) si el puntero es NULL o la cantidad de elementos de la lista
 *
 */
int ll_len(LinkedList *this){
	int returnAux = -1;
	if (this != NULL) {
		returnAux = this->size;
	}
	return returnAux;
}

/** \brief  Obtiene un nodo de la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \param index int Indice del nodo a obtener
 * \return Node* Retorna  (NULL) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
 (pNode) Si funciono correctamente
 *
 */

static Node* getNode(LinkedList *this, int nodeIndex) {//funcion privada me retorna un puntero a Node
	Node *pNode = NULL;

	if (this != NULL && nodeIndex >= 0 && nodeIndex < ll_len(this)){//valido el rango del indice que este entre 0 y - size
		LinkedList listAux = *this;
		pNode = listAux.pFirstNode;//obtengo mi primer nodo para que comienze a iterar(recorrer) la lista
		for (int i = 0; i < nodeIndex; i++) {//recorre hasta el index
			pNode = pNode->pNextNode; //guardo la dirrecion de memoria del Nodo que obtuve
		}
	}

	return pNode;	//retorno el nodo obtenido
}

/** \brief  Permite realizar el test de la funcion getNode la cual es privada
 *
 * \param this LinkedList* Puntero a la lista
 * \param index int Indice del nodo a obtener
 * \return Node* Retorna  (NULL) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
 (pElement) Si funciono correctamente
 *
 */
Node* test_getNode(LinkedList *this, int nodeIndex) {
	return getNode(this, nodeIndex);
}

/** \brief Agrega y enlaza un nuevo nodo a la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion donde se agregara el nuevo nodo
 * \param pElement void* Puntero al elemento a ser contenido por el nuevo nodo
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
 ( 0) Si funciono correctamente
 *
 */
static int addNode(LinkedList *this, int nodeIndex, void *pElement) {
	//es una funcion estatica que se llama dentro del programa,retorna un entero y recibe por referencia
	//puntero a la lista de tipo ll. un nodoindex de tipo int y un p element de tipo puntero a void.
	int returnAux = -1;
	Node *nodoAux; //declaro una variable depuntero de tipo node
	Node *nodoNew; //declaro una variable depuntero de tipo node

	if (this != NULL && nodeIndex <= ll_len(this) && nodeIndex >= 0) {//valido la lista y el rango de index
		//nodeIndex <= ll_len(this)= puedo agregar un nodo al final;
		nodoNew = (Node*) malloc(sizeof(Node)); //asigno memoria dinamica para el nuevo nodo.
		if (nodoNew != NULL) { //valido qe se haya reservado la memoria porque use malloc.
			nodoNew->pElement = pElement;//le asigno el elemetno reccibido por referencia por unica vez
										 // al nuevo nodo de la lista.

			//una vez que tengo todo validado y el pElment de el nuevo nodo cargado
			//veo si se va a agregar a la primer poscion de mi lista
			if (nodeIndex == 0) {//

				nodoNew->pNextNode = this->pFirstNode; //cargo la direccion de memoria del primer nodo(pFirstNode)
														//al nuevo
				this->pFirstNode = nodoNew;	// quiero guardar la dirrecion de memoria del nuevo nodo
											// en pFirstNode (en pFirstNode)

			} else {
				nodoAux = getNode(this, nodeIndex - 1);//obtengo la dirrecion de memoria del nodo anterior
				if(nodoAux != NULL){//valido que sea distinto de null
				nodoNew->pNextNode = nodoAux->pNextNode; //le asigno al nuevo nodo la dirrecion de memoria del
														//siguiente nodo
				nodoAux->pNextNode = nodoNew;			//al nodo anterior le asigno mi nuevo nodo
				}
			}
			this->size++; //mi  campo size de linkedlist se incrementa en 1,agregando un nuevo nodo.
			returnAux = 0;//retorno 0 todo ok
		}

	}

	return returnAux;
}
/** \brief Permite realizar el test de la funcion addNode la cual es privada
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion donde se agregara el nuevo nodo
 * \param pElement void* Puntero al elemento a ser contenido por el nuevo nodo
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
 ( 0) Si funciono correctamente
 *
 */
int test_addNode(LinkedList *this, int nodeIndex, void *pElement) {
	return addNode(this, nodeIndex, pElement);
}

/** \brief  Agrega un elemento a la lista
 * \param pList LinkedList* Puntero a la lista
 * \param pElement void* Puntero al elemento a ser agregado
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
 ( 0) Si funciono correctamente
 *
 */
int ll_add(LinkedList *this, void *pElement){//retorna un entero recibe por parametro una lista puntero
											//tipo llinkedllist y un puntero de tipo void (pelemnt)
	int returnAux = -1;//declaro variable tipo int para el retorno
	if (this != NULL) { //valido que la liusta sea distinta null
		if (!addNode(this, ll_len(this), pElement)) {//si me retorna 0 se añadio el elemnto(nodo) a lista
			returnAux = 0;//retorno 0 todo ok
		}
	}

	return returnAux;
}

/** \brief Permite realizar el test de la funcion addNode la cual es privada
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion del elemento a obtener
 * \return void* Retorna    (NULL) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
 (pElement) Si funciono correctamente
 *
 */
void* ll_get(LinkedList *this, int index){//retorna un puntero tipo void recibe por parametro
	//un puntero a la lita y indice tipo entero.
	void *returnAux = NULL;
	Node *pNode = NULL;
	if (this != NULL && index < ll_len(this) && index >= 0) {
		pNode = getNode(this, index);//pido que me retorne el puntero a nodo en poscicion del index
		if (pNode != NULL) {//verifico e nodo ok
			returnAux = pNode->pElement; //le asigno el elmento al puntero void
		}
	}
	return returnAux;//retorno el elemnto

}

/** \brief Modifica un elemento de la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion del elemento a modificar
 * \param pElement void* Puntero al nuevo elemento
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
 ( 0) Si funciono correctamente
 *
 */
int ll_set(LinkedList *this, int index, void *pElement) {
	int returnAux = -1;
	Node *pNode = NULL;
	if (this != NULL && index < ll_len(this) && index >= 0) {
		pNode = getNode(this, index);
		if (pNode != NULL) {
			pNode->pElement = pElement;//le asigna el elemnto * pelement recibido por parametros
			returnAux = 0;//todo ok retorna 0
		}
	}
	return returnAux;

}

/** \brief Elimina un elemento de la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion del elemento a eliminar
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
 ( 0) Si funciono correctamente
 *
 */
int ll_remove(LinkedList *this, int index) {//le damos una poscion y elimina el elemnto de ese index
	int returnAux = -1;
	Node *pNodeEliminado = NULL;
	Node *rNodeAux = NULL;
	if (this != NULL && index >= 0 && index < ll_len(this)) //index nunca va a ser igual llen
			{

		if (index == 0) {
			pNodeEliminado = getNode(this, index);
			this->pFirstNode = pNodeEliminado->pNextNode;
			returnAux = 0;

		} else {
			rNodeAux = getNode(this, index - 1);
			pNodeEliminado = getNode(this, index);
			rNodeAux->pNextNode = pNodeEliminado->pNextNode;

			returnAux = 0;
		}
		free(pNodeEliminado);
		free(rNodeAux);
		this->size--;
	}

	return returnAux;
}

/** \brief Elimina todos los elementos de la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
 ( 0) Si funciono correctamente
 *
 */
int ll_clear(LinkedList *this) {
	int returnAux = -1;
	if (this != NULL) {

		for (int i = ll_len(this); i >= 0; i--) {
			ll_remove(this, i); //va removiendo de atras para adelante para no perder el registro uno a uno
			break;
		}
		this->size = 0;
		returnAux = 0;
	}
	return returnAux;
}
/** \brief Elimina todos los elementos de la lista y la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
 ( 0) Si funciono correctamente
 *
 */
int ll_deleteLinkedList(LinkedList *this) {
	int returnAux = -1;

	if (this != NULL) {//borra de memoria la lista (1 se hace un clear despues un delete).borre el lugar donde guardaba la lista.
		ll_clear(this); //aun si es funcional, de forma logica hacer la baja en sentido de this->size 0, no estaria liberando espacio, por eso es necesario el clear
		free(this);
		returnAux = 0;
	}
	return returnAux;
}

/** \brief Busca el indice de la primer ocurrencia del elemento pasado como parametro
 *
 * \param this LinkedList* Puntero a la lista
 * \param pElement void* Puntero al elemento
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
 (indice del elemento) Si funciono correctamente
 *
 */
int ll_indexOf(LinkedList *this, void *pElement) {
	int returnAux = -1;
	int i;
	Node *elemetnIndex = NULL;
	if (this != NULL) //index nunca va a ser igual llen
	{
		for (i = 0; i < ll_len(this); i++) {//itero con lista recorriendo cada nodo con getNode
			elemetnIndex = getNode(this, i);
			if (elemetnIndex->pElement == pElement) {//cuando hay coincidencia de el elemnto del nodo y
				                                     //el elemto pasado por referencia puntero  tipo  void
				returnAux = i; //le asignamos a return aux la poscion de el elemnto
				break;//rompe el bucle
			}
		}
	}
	return returnAux;//retornamos la posicion.
}

/** \brief Indica si la lista esta o no vacia
 *
 * \param this LinkedList* Puntero a la lista
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
 ( 0) Si la lista NO esta vacia
 ( 1) Si la lista esta vacia
 *
 */
int ll_isEmpty(LinkedList *this) {

	int returnAux = -1;

	if (this != NULL) {
		returnAux = 0;
		if (this->size == 0) {
			returnAux = 1;
		}
	}
	return returnAux;
}

/** \brief Inserta un nuevo elemento en la lista en la posicion indicada
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion donde se agregara el nuevo elemento
 * \param pElement void* Puntero al nuevo elemento
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
 ( 0) Si funciono correctamente
 *
 */
int ll_push(LinkedList *this, int index, void *pElement) {//Elegir un lugar para agregar un elemento
									//(me permite insertar un elemento en en una poscion determinada)
	int returnAux = -1;				//permite poner entre el 1 y dos un elemento
	if (this != NULL && index >= 0 && index <= ll_len(this)) {
		returnAux = addNode(this, index, pElement);//me retona 0 si el elemento se agrego en la pos indicada
	}
	return returnAux;
}

/** \brief Elimina el elemento de la posicion indicada y retorna su puntero
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion del elemento eliminar
 * \return void* Retorna    (NULL) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
 (pElement) Si funciono correctamente
 *
 */
void* ll_pop(LinkedList *this, int index){//ES LA CONTRACARA DE LL_PUSH
    //Me permite sacar un elemento de la lista pero en el mismo momento que lo estoy
   //sacando de la lista me devuleve ese puntero. hace un get y romove al ,mismo tiempo
	void *returnAux = NULL;
	if (this != NULL && index >= 0 && index < ll_len(this)) {
		returnAux = ll_get(this, index);//obtiene elemento de la lista en el indicce que le paso
		if (returnAux != NULL) {
			ll_remove(this, index);//le damos una poscion y elimina el elemnto de ese index
		}
	}
	return returnAux;
}
/** \brief  Determina si la lista contiene o no el elemento pasado como parametro
 *
 * \param this LinkedList* Puntero a la lista
 * \param pElement void* Puntero del elemento a verificar
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
 ( 1) Si contiene el elemento
 ( 0) si No contiene el elemento
 */
int ll_contains(LinkedList *this, void *pElement) {//verifica si contiene la lista el eemtno que le
	//pasmos por parametro
	//me duvuelvo verdadero si elemento porque pregunto esta contenido en la lista
	int returnAux = -1;
	if (this != NULL) {
		returnAux = 0;
		if (ll_indexOf(this, pElement) != -1) {//busca elemento psasdo por param y me develve la poscion
			returnAux = 1;//si encontro el elemento
		}
	}
	return returnAux;
}

/** \brief  Determina si todos los elementos de la lista (this2)
 estan contenidos en la lista (this)
 *
 * \param this LinkedList* Puntero a la lista
 * \param this2 LinkedList* Puntero a la lista
 * \return int Retorna  (-1) Error: si alguno de los punteros a las listas son NULL
 ( 1) Si los elementos de (this2) estan contenidos en la lista (this)
 ( 0) si los elementos de (this2) NO estan contenidos en la lista (this)
 */
int ll_containsAll(LinkedList *this, LinkedList *this2) {
	//me duvuelvo verdadero si  la lista contiente TODOS los elemtos de la otra lista que le estoy pasando.
	//(si una lista esta contenida en otra)
	int returnAux = -1;
	int tam;
	if (this != NULL && this2 != NULL) {
		returnAux = 1;
		tam = ll_len(this2);
		for (int i = 0; i < tam; i++) {
			if (!ll_contains(this, ll_get(this2, i))) {
				returnAux = 0;
				break;
			}
		}
	}

	return returnAux;
}
/** \brief Crea y retorna una nueva lista con los elementos indicados
 *
 * \param pList LinkedList* Puntero a la lista
 * \param from int Indice desde el cual se copian los elementos en la nueva lista
 * \param to int Indice hasta el cual se copian los elementos en la nueva lista (no incluido)
 * \return LinkedList* Retorna  (NULL) Error: si el puntero a la listas es NULL
 o (si el indice from es menor a 0 o mayor al len de la lista)
 o (si el indice to es menor o igual a from o mayor al len de la lista)
 (puntero a la nueva lista) Si ok
 */
LinkedList* ll_subList(LinkedList *this, int from, int to) {
	LinkedList *cloneArray = NULL;

	if (this != NULL && from >= 0 && to <= ll_len(this)) {
		cloneArray = ll_newLinkedList();//crea y retorna
		if (cloneArray != NULL) {
			while (from <= to) {//desde/hasta
				ll_add(cloneArray, ll_get(this, from));
				from++;
			}
		}
	}
	return cloneArray;
}

/** \brief Crea y retorna una nueva lista con los elementos de la lista pasada como parametro
 *
 * \param pList LinkedList* Puntero a la lista
 * \return LinkedList* Retorna  (NULL) Error: si el puntero a la listas es NULL
 (puntero a la nueva lista) Si ok
 */
LinkedList* ll_clone(LinkedList *this) {//Duplico una lista en memoria.(`para no afecta la original )
	LinkedList *cloneArray = NULL;

	if (this != NULL) {
		cloneArray = ll_newLinkedList();
		if (cloneArray != NULL) {
			cloneArray = ll_subList(this, 0, ll_len(this));//desde this  /hasta 0.
		}
	}

	return cloneArray;
}

/** \brief Ordena los elementos de la lista utilizando la funcion criterio recibida como parametro
 * \param pList LinkedList* Puntero a la lista
 * \param pFunc (*pFunc) Puntero a la funcion criterio
 * \param order int  [1] Indica orden ascendente - [0] Indica orden descendente
 * \return int Retorna  (-1) Error: si el puntero a la listas es NULL
 ( 0) Si ok
 */
int ll_sort(LinkedList *this, int (*pFunc)(void*, void*), int order){
	//recibe un puntero a funcion que retorna un int y
	//recibe dos punteros tipo void que son los elementos que voy a comparar en
	//en mi funcion criterio y swapear en la funcion ll_sort
	int returnAux = -1;
	int tamList;
	void *auxElement; //para no perder el elemento.al momento de hacer el swap
					// es puntero de tipo void porque ll_sort generico .
	//this = es la lista de la que voy a tomar los elemento que voy a ordenar-

	if (this != NULL && pFunc != NULL && (order == 1 || order == 0)) {
		tamList = ll_len(this);
		for (int i = 0; i < tamList - 1; i++) {
			for (int j = i; j < tamList; j++) {
	//hace todo menos tomar la decision de cual es el criterio para ordenar , ese criteriolo establece
	//llamando
	//a la funcion que recibe como parametro, esta devuelve un entero  1 (asendente ) o
	//0 (desendente) para indicar cual es mas grande (
	//(void* ,void*) = le paso dos puntero a los que debe comparar
	//Desarollo por fuera : funcion que recibe dos punteros y los compara bajo un criterio.
				if ((pFunc(ll_get(this, i), ll_get(this, j)) > 0 && order)// recibe el tipo de ordenamiento
				 || (pFunc(ll_get(this, i), ll_get(this, j)) < 0 && !order))
				{
					auxElement = ll_get(this, i);
					ll_set(this, i, ll_get(this, j));
					ll_set(this, j, auxElement);
					returnAux = 0;

				}

			}
		}
	}

	return returnAux;
}
/** \brief Filtra los elementos de la lista utilizando la funcion criterio recibida como parametro
 * (crea una nueva linkedlist basandose en un criterio ingresado
 por el usuario)
 * \param pList LinkedList* Puntero a la lista
 * \param pFunc (*pFunc) Puntero a la funcion criterio
 * \return int Retorna  (NULL) Error: si el puntero a la listas es NULL
 (filterList) la lista filtrada
 */
LinkedList* ll_filter(LinkedList *this, int (*pFunc)(void *element)) {//pfunc funcion que evalua al elemento en cuestion
	LinkedList *listaFiltrada = NULL;
	void *element = NULL;
	int tam;

	if (this != NULL) {
		listaFiltrada = ll_newLinkedList();
		if (listaFiltrada != NULL) {
			tam = ll_len(this);
			for (int i = 0; i < tam; i++) {
				element = ll_get(this, i);//retorna el elemtno en la posicion pasada por parametros(especifiicado)
				if (pFunc(element) == 1) //quiere decir que si hay coincidencia( mi funcion criterio retorna 1)
				{
					ll_add(listaFiltrada, element); // agrega a la lista los elementos que obtuve con el ll_get
				}
			}
		}
	}
	return listaFiltrada;
}
/** \brief Mapea los elementos de la lista utilizando la funcion criterio recibida como parametro
 * ( ll_map: recibe un puntero de una funcion, y modifica todos los elementos de una lista,
 y los pega en una nueva)
 * \param pList LinkedList* Puntero a la lista
 * \param pFunc (*pFunc) Puntero a la funcion criterio
 * \return int Retorna
 */
																	//devuelve un punetro linkedlist
LinkedList* ll_map(LinkedList* this,void* (*pFunc)(void* element)) {//recibe puntero a la lista y un  puntero void a mi
	 	 	 	 	 	 	 	 	 	 	 	 	 	 	 	 	 //funcion criterio

	LinkedList* mapList = NULL;
	void* auxElemento = NULL; //variale aux tipo  puntero a void
	if (this != NULL && pFunc != NULL) {
	mapList = ll_newLinkedList();
		if(mapList != NULL)
		{
			for (int i = 0; i < ll_len(this); i++) {//itero todos los elementos de la lista
				auxElemento = ll_get(this, i); //obtengo los elementos de cada nodo y los cargo en auxElement
				ll_add(mapList,pFunc(auxElemento));
				//va agrgando con ll_add a mi lista creada(maplist) los elemntos que la funcion
				//criterio modifica y retorna.
			}
		}
	}
	return mapList;
}
