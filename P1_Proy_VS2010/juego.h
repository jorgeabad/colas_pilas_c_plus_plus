#ifndef JUEGO_H_
#define JUEGO_H_
#include <stdlib.h>
#include <time.h>
#include<iostream>
#include <windows.h>


using namespace std;

/** @brief Clase que proporciona métodos estáticos, para el funcionamiento del juego.
*
*	Proporciona los métodos necesarios para obtener un numero aleatorio entre 1 y 9
*	generar una operación aleatoriamente, y operar para obtener un resultado.
*
**/
class juego {

public:

	static void iniciarSemilla();
	static short obtenerNumero();
	static char obtenerOperacion();
	static short obtenerResultado(char operacion, short numeroCinta, short cimaMonton);

};

#endif /* JUEGO_H_ */