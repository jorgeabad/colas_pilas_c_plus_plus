#ifndef PILA_H_
#define PILA_H_
#include <iostream>
#include <string>
#include <conio.h>
#include <stdlib.h>
#include <stdio.h>
#include "nodo_pila.h"
using namespace std;

/** @brief Estructura lineal para almacenar los números de los montones.
*
*	Sigue una implementación de celdas enlazadas, la pila se representa mediante un puntero a una celda, pPila.
*   Cada celda es un objeto nodo_pila por lo que contiene un valor y un puntero a la siguiente celda.
*   Estas celdas son colocadas una encima de la otra, la celda que entra en la pila, se coloca en la parte superior,
* 	siguiendo la estructura LIFO (Last In, First Out), la celda superior, es el último nodo_pila en entrar 
*	y se le llama cima, las inserciones, las consultas y las eliminaciones solo se permiten sobre la cima*/ 
class pila
{
	
     
   /**@var pPila
     *@brief Puntero de la clase nodo_pila, apunta al nodo que es cima de la pila. Representa la pila.
     *@var numElementos
     *@brief Almacena el número de elementos que contiene la pila.*/
     
     //Atributos privados
     private:
	       
	       nodo_pila* pPila; //puntero de la clase nodo_pila apunta al nodo que es la cima de la pila.
	       short numElementos; //almacena el número de elementos que tiene la pila
     
     //Métodos publicos
     public:
            
            //CONSTRUCTORAS
            pila(); // Crea un objeto de la clase pila, una pila vacia sin elementos.
            ~pila();// Destructor de la pila
            void apilar(short elemento); //inserta un elemento en la cima de la pila
            void llenarPila();//llena la pila con n elementos.
            void Vaciarpila();//vacía por completo la pila, partiendo de la cima, eliminando todos los elementos.
            
            //OBSERVADORAS
            bool es_pila_vacia();//Comprueba si la pila está vacía
            short cima();//Devuelve el valor del último elemento de la pila, de su cima.
            void imprimir();//Muestra el contenido de la pila el contenido del atributo valor de cada nodo
            short getNumElementos(); //devuelve el numero de elementos que contiene la pila
            
            //MODIFICADORAS
           void desapilar();//Elimina el nodo que es cima de la pila.
           
           
};

#endif /* PILAS_H_ */
