#include <iostream>
#include <string>
#include <conio.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "pila.h"

/** @brief Constructor de la clase nodo_pila, crea una celda que contiene un valor y un puntero.
*
*   Crea un nuevo nodo aislado, cuyo puntero al siguiente apunta a null y contiene como valor el número 0.
*
**/
nodo_pila::nodo_pila(){//Constructor
	pSiguiente = NULL;//No enlaza con otros nodos, no hay celdas enlazadas.
	valor = 0;//Se le asigna el número 0 al atributo valor, para inicializarlo.

}