#include <iostream>
#include <string>
#include <conio.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "nodo_cola.h"

/** @brief Constructor de la clase nodo_cola, crea una celda que contiene un valor y un puntero. 
*
*   Crea un nuevo nodo aislado, cuyo puntero al siguiente apunta a null y contiene como valor el número 0.
*
**/
nodo_cola::nodo_cola(){
			pSiguiente=NULL;//la celda no está enlazada con otra. 
            valor=0;//Asignamos el valor 0 como inicial de la celda
                  
}
