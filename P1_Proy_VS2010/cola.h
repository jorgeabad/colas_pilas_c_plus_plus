#ifndef COLA_H_
#define COLA_H_
#include <iostream>
#include <string>
#include <conio.h>
#include <stdlib.h>
#include <stdio.h>
#include "nodo_cola.h"
using namespace std;

/** @brief Estructura lineal para almacenar los n�meros de la cinta.
*
*	Sigue una implementaci�n de celdas enlazadas, cada celda es un objeto nodo_cola.
*	La cola tiene una referencia a la primera celda y a la �ltima:
*
*   	-Si la cola est� vac�a, ambos punteros son �Null�. primero=NULL, ultimo=NULL.
*
* 		-Cada celda contiene un elemento y un puntero a la siguiente celda. (nodo_celda)
*
*	las inserciones de nuevos elementos solo se permiten en uno de los extremos de la cola,
*   llamado �ltimo, y las consultas o eliminaciones solo se permiten en el opuesto, llamado  primero.
*	Sigue la estructura FIFO (First In, First Out)
*
*	*/
class cola
{


	/**@var primero
	*@brief Puntero de la clase nodo_cola para apuntar a la primera celda de la cola
	*@var ultimo
	*@brief Puntero de la clase nodo_cola para apuntar a la �ltima celda de la cola*/

	//Atributos privados
private:
	nodo_cola* primero; //Puntero de la clase nodo_cola para apuntar al inicio de la cola
	nodo_cola* ultimo; //Puntero de la clase nodo para apuntar al final de la cola

	//M�todos publicos
public:
	cola(); //Constructor de la cola cola vacia.
	~cola();//Destructor de la clse cola.
	void encolar(short elemento); //a�adir un elemento. Una nueva celda por el extremo �ltimo. 
	void desencolar(); //Elimina el primer elemento de la cola, elimia la primera celda.
	short primero_en_cola(); //devuelve el n�mero que est� almacenado en la primera celda de la cola.
	short ultimo_en_cola();//devuelve el n�mero que est� almacenado en la �ltima celda de la cola.
	bool es_cola_vacia(); //Comprueba si la cola est� llena o vac�a.
	void llenarCola();//Llena la cola de N elementos aleatorios.
	void mostrarResto();//Imprime por pantalla todos los elementos de la cola menos el primero.
};

#endif /* COLAS_H_ */