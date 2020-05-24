
#include <iostream>
#include <sstream>
#include <string>
#include <conio.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <windows.h>
#include <iostream> 
#include "pila.h"
#include "nodo_pila.h"
#include "juego.h"

//CONSTRUCTORAS
/** @brief Constructor para crear una pila vac�a.
*
*   No hay ning�n nodo_pila creado, no hay celdas en la pila, por lo que el puntero a la cima,
*	que reperesenta a la pila, toma el valor de null y numero de elementos que contiene la pila toma el valor de cero.
*
**/
pila::pila(){
	pPila = NULL;//inicialmente no hay nodo_pila que sea cima, el puntero toma valor null
	numElementos = 0;//inicialmente no hay elementos en la pila, el contador toma valor igual a cero
}


/** @brief Destructor de la clase pila
*
*   Elimina todos los nodos creados y libera pPila, puntero de la clase nodo_pila a la cima, que representa la cima.
*
**/
pila::~pila(){

	Vaciarpila();//Funci�n que elimina los nodos creados, partiendo del nodo al que apunta el puntero pPila, cima.
	delete pPila;//Una vez eliminados los nodos liberamos la pila.
	cout << "Pila eliminada";//informamos de la eliminaci�n de la pila.
}


/** @brief Funci�n que elimina todos los nodos creados. Eliminaci�n de las celdas enlazadas.
*
*   Elimina todos los nodos creados y libera el puntero pPila, nodo_pila a la cima. Llama a
*	llama a la funci�n desapilar hasta que no quede ninguna celda @see desapilar()
*
**/
void pila::Vaciarpila(){

	//nodo_pila*q=new nodo_pila();//var q: enlace-pila
	if (es_pila_vacia()){
		cout << "La pila est� vac�a";//si es_pila_vacia(p) entonces error(Pila vacia)               
	}
	else{//si no

		while (pPila != NULL){

			desapilar();
		}
	}//fsi


}




/** @brief Funci�n que pone un elemento, colocandolo como cima de la pila.
*
*   Coloca un nuevo objeto nodo_pila en la cima de la pila, el puntero
*   pSiguiente, de este nuevo nodo apunta al siguiente elemento de la pila y
*   el puntero de la pila pPila apunta a este nuevo nodo que es la nueva cima.
*
*   @param elemento n�mero entero que queremos almacenar en la pila.
**/
void pila::apilar(short elemento) //apilar
{
	//proc apilar(p:pila, E e:elemento)
	nodo_pila*q = new nodo_pila();//var q: enlace-pila; puntero a nodo_pila, nuevo nodo a introducir.
	//reservar(q)
	q->valor = elemento;//q^.valor<-e El atributo valor del nuevo nodo, toma el valor del n�mero que ha sido pasado. 
	q->pSiguiente = pPila;//q^.sig<-p El puntero, pSiguiente, del nuevo nodo, apunta al nodo que ahora es cima, toma el valor de pPila.
	pPila = q;//p<-q; el puntero de la pila, pPila, apunta al nuevo nodo introducido, quedando as� como cima.
	numElementos++;// aumentamos en uno el valor del atributo numElementos que determina el n�mero de elementos que tiene la pila
	//fproc          
}


/** @brief Funci�n que llena una pila con un n�mero N (aleatorio) de elementos.
*
*   Obtiene un n�mero aleatoriao N entre 1 y 9 que determina el n�mero de elementos
*   que tendr� la pila. Desde 1 hasta N, genera un nuevo n�mero aleatorio(entre 1-9)
*   'numeroAleatorio' apilando este n�mero.
*
**/
void pila::llenarPila() // llena una pila
{
	/**- n: Almacena el numero de elementos que ha de contener la pila. */
	int n = juego::obtenerNumero();//Obtenemos un numero entre 1-9 y lo asignamos a n.
	/**- c: Contador para iterar el n�mero n de elementos a introducir.*/
	int c = 0; //Contador para el n�mero N de elementos a introducir.
	for (c = 1; c <= n; c++){//desde 1 hasta el numero de elementos a apilar
		/**- numAleatorio: Es un entero que almacena el n�mero que ha de ser apilado*/
		int numeroAleatorio = juego::obtenerNumero();//Obtenemos un n�mero del 1 al 9
		apilar(numeroAleatorio);//apilamos el n�mero.
	}

}

/** @brief Funci�n que comprueba si una pila esta vac�a.
*
*   En funci�n del valor de puntero pPila, determina si est� vac�a, si tiene
*   valor null es una pila vac�a.
*
*   @retval true si la pila est� vacia.
*   @retval false si la pila no est� vac�a
*
**/
bool pila::es_pila_vacia(){
	/**	Variables:*/
	/**- b: variable booleana que alamacena el valor del resultado (pPila==NULL)
	**/
	bool b;//almacena valor true o false
	b = (pPila == NULL);//en funci�n de si es true o false (pPila==NULL)
	return b;//devolvemos valor de b
}


/** @brief Funci�n que devuelve el valor del elemento que se encuentra en la cima.
*
*   Devolvemos el valor del atributo valor del nodo_pila al que apunta el puntero pPila,
*   si es una pila vac�a este puntero ser� null, (pPila==Null), en este caso lanzar� una excepci�n.
*
*   @return e El valor del n�mero entero que se encuentra en la cima de la pila.
*
**/
short pila::cima(){
	short e = 0;//Variable de tipo entero que almacena el valor del n�mero que est� en la cima
	try{

		if (es_pila_vacia()){
			throw es_pila_vacia();//Si es una pila vacia lanzamos la excepci�n               
		}
		else{
			e = pPila->valor;//Asignamos el valor a e, del atributo valor del nodo_pila, al que apunta el puntero de la pila. 
		}
	}
	catch (bool){//Capturamos la excepci�n lanzada si la pila est� vac�a.
		cout << "La pila esta vacia";//Si hay excepci�n lo mostramos.
	}
	return e;//Devolvemos el atributo valor del nodo_pila que es cima de la pila.
}

/** @brief Funci�n que devuelve un entero con la longitud de la pila.
*
*   Devuelve un entero que representa el n�mero de elementos que est�n almacenados en la pila.
*
*   @retval numElementos=0 La pila no tiene elementos.
@retval 0<numElementos<=9 Numero entero entre 0 y 9, que representa el n�mero total de celdas que tiene la pila.
*
**/
short pila::getNumElementos(){
	return numElementos;
}

/** @brief Funci�n que elimina el elemento ,(nodo_pila), que es cima de la pila.
*
*   Elimina el nodo_pila que es cima, actulizando el valor del puntero de la pila,
*	pPila, que tomar� el valor del siguiente nodo, adyacente al que que va a ser eliminado.
*
**/
void pila::desapilar(){
	//proc desapilar(p:pila)
	/**Variables*/
	/**- Variable auxiliar q: un puntero a nodo_pila, que apuntar� al nodo_pila a eliminar, la cima, */
	nodo_pila*q = new nodo_pila(); //var q: enlace-pila puntero a nodo_pila.

	if (es_pila_vacia()){
		cout << "La pila est� vac�a";//si es_pila_vacia(p) entonces error(Pila vacia)               
	}
	else{ //si no
		q = pPila; //q<-p q apunta al nodo_pila, cima, que es el nodo a eliminar.
		//Actualizamos el puntero de la pila, una nueva cima.
		pPila = pPila->pSiguiente; //p<-p^.sig Apunta al nodo que est� a continuaci�n del nodo que se va a eliminar.
		q->pSiguiente = NULL; //q^.sig<-nil {por seguridad} El nodo a eliminar no tiene que tener un puntero a ning�n otro nodo
		delete(q); //liberar(q)
		numElementos--; //Descontamos en uno el numero de elementos que tiene la pila.
	} //fsi
	//fproc
}

/** @brief Funci�n que imprime el contenido del atributo valor de los nodos almacenados en la pila.
*
*   Muestra por pantalla el numero que est� contenido en el atributo valor de cada objeto
*   nodo_pila que se almacena en la pila. Recorre la pila desde nodo m�s superior, cima, hasta el nodo
*	mas inferior fondo.
*
*	Se mostrar� de la siguiente manera fondo,...nodos,... cima. Sentido de izquierda a derecha,
*	empezando desde el primer elemento que entro en la pila, fondo, y como �ltimo elemento m�s a la derecha
*	el nodo cima, �ltimo elemento en entrar en la pila.
*
**/
void pila::imprimir(){
	/**Variables:*/
	/**- contenido: una cadena que va almacenando el contenido de la pila seg�n avanza el recorrido por los nodos.*/
	string contenido = "";//No hay contenido
	/** ss: objeto stringstream usamos para almacenar el entero contenido en el atributo valor,
	*	y posteriormente convertirlo en una cadena string*/
	std::stringstream ss;//Almacena los enteros que va recibiendo.

	if (es_pila_vacia()){//Si es pila vac�a no hay datos.
		return;
	}
	/**- q: variable auxiliar puntero a nodo_pila la usamos para ir recorriendo nodo a nodo la pila desde la cima*/
	nodo_pila*q = new nodo_pila();//var q: enlace-pila
	q = pPila;//q apunta inicialmente al nodo que es la cima
	while (q != NULL){    //Mientras existan nodos

		ss << q->valor; //Almacenamos, el n�mero contenido en el atributo valor del nodo, en el objeto ss (stream)
		/**- str: objeto string que almacena el valor del entero, formateado a cadena, que se obtiene en cada nodo del recorrido*/
		std::string str = ss.str();//formateamos el contenido del stream a tipo cadena y lo almacenamos en el objeto string str
		contenido = str + ", " + contenido;//El contenido anterior lo a�adimos por la derecha.
		ss.str("");//Vaciamos el stream

		q = q->pSiguiente;// Ahora q apunta al siguiente nodo de la pila

	}
	delete(q);//liberar(q) al finalizar el recorrido.


	cout << contenido;//Mostramos el contenido por pantalla.
}