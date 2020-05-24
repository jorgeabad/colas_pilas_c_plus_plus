#ifndef NODO_PILA_H_
#define NODO_PILA_H_

using namespace std;

/** @brief Representa una celda de la pila. Almacena cada uno de los n�meros que componene un mont�n 
*
*   Cada celda contiene un valor, un n�mero entero y puntero a la celda que contiene lo que est� debajo de ella 
*   (que a su vez es una pila).(Pila de celdas enlazadas)*/ 
class nodo_pila
{
	
	/**@var valor
     *@brief Contiene un n�mero entero. El n�mero almacenado en esa celda o nodo.
     *@var pSiguiente
     *@brief Puntero de la clase nodo_pila que a apunta al siguiente nodo_pila o celda de la pila*/
     
   friend class pila;//para que pueda acceder a sus atributos, la clase pila.
   //atributos
             private:
				int valor; //Contiene valor.
				nodo_pila* pSiguiente; //puntero al siguiente de la clase nodo_pila.
             public:
				nodo_pila();//Crea un nuevo nodo, cuyo puntero al siguiente apunta null y contiene un entero de valor 0.
				
};
#endif
