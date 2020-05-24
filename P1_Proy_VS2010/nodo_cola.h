
#ifndef NODO_COLA_H_
#define NODO_COLA_H_

using namespace std;

/** @brief Representa una celda de la cola. Almacena cada uno de los números que componenen la cinta.
*
*   Cada celda contiene un valor, un número entero y puntero a la siguiente celda de la cola. (Cola de celdas enlazadas)*/
class nodo_cola
{
	/**@var valor
	*@brief Contiene un número entero. El número almacenado en esa celda o nodo.
	*@var pSiguiente
	*@brief Puntero de la clase nodo_cola que a apunta al siguiente nodo_cola o celda de la cola*/
	friend class cola;
	//para que pueda acceder a sus atributos, la clase cola.
	//atributos
private:
	short valor; //Contiene valor.
	nodo_cola* pSiguiente; //puntero al siguiente de la clase NodoCola.
public:
	nodo_cola();//Constructor de la clase nodo_cola crea un nuevo nodo aislado.
};
#endif