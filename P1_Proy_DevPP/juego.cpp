#include <stdlib.h>
#include <time.h>
#include<iostream>
#include <windows.h>
#include"pila.h"
#include"juego.h"
using namespace std;
 
 
/** @brief Método para iniciar, la generación del número aleatorio, mediante la hora del sistema.
*
*	Usa el método srand() para iniciar la aleatoriedad usando el tiempo del sistema en milisegundos
*	como semilla, para impedir que siempre salgan los mismos números.
*
**/	
void juego::iniciarSemilla(){
	 srand((unsigned)time(0)); 
	//srand(time(NULL));
}

/** @brief Método para obtener un número entero aleatorio entre 1 y 9.
*
*   @return num Un número entero entre 1 y 9.
*
**/	
short juego::obtenerNumero()
{
    /**Variables*/
    /**- num: almacena el número entero obtenido (1-9)*/
	short num;
    //rand();
    num = 1 + rand() % (9);// rand() obtiene un número aleatorio en función de la semilla
    //Mediante la operador módulo obtenemos el resto de la operación (numero aleatorio)/9
	//Obligamos a que este dentro del intervalo entre 1 y 9 al sumarle 1 
      
    //Sleep(500);
    return num;//Devolvemos el número.
}



/** @brief Método para obtener un char, que simboliza la operación.
*
*   @retval + Simboliza suma.
*	@retval - Simboliza resta.
*	@retval / Simboliza división.
*	@retval * Simboliza multiplicación.
*
**/	
char juego::obtenerOperacion()
{
    /**Variables:*/
    /**- operador: almacena el símbolo de la operación*/
	char operador;//almacena el símbolo de la operación
    operador='p';//Inicializamos con p
    
  	/**- num: Almacena un número aleatorio del 1 al 4, en función de este num operador toma un valor*/
  	/** si num=1 operador=*, si num=2 operador=/, si num=3 operador=+, si num=4 operador=-. */
    int num; //Almacena un número aleatorio del 1 al 4, en función de este operador toma valor*/
    
        num = 1 + rand() % (4); //obtenemos el número aleatorio
        
        switch (num){// para cada número asignamos una operación.
        	case 1:
        		operador='*';
        		break;
        		case 2:
        		operador='/';
        		break;
        		case 3:
        		operador='+';
        		break;
        		case 4:
        		operador='-';
        		break;
        }
        
    return operador; //Devolvemos el caracter que simboliza la operación. 
	}



/** @brief Función para realizar una operación, pasando dos enteros y el símblo del operador.
*
*   En función del símbolo del operador aplica una operación matemática, a los dos números pasados,
*
*   @param operacion tipo char con el símbolo de la operación '+', '-', '*', o '/'.
*   @param numeroCinta tipo short segundo termino de la operación.
*   @param cimaMonton tipo short primer termino de la operación.
*   @return resultado un entero que representa el resultado final de la operación cimaMonton[operacion]numeroCinta*/
short juego::obtenerResultado(char operacion, short numeroCinta, short cimaMonton){
	/**Variables*/
	/**- resultado: almacena un entero con el resultado de la operación*/
	short resultado=0;
	 switch(operacion){ //En función del char pasado
               
                case('*'):{
                             //Realizamos la operación multiplicación
                             resultado=cimaMonton*numeroCinta;
                             break;
                             }
                case('/'):{
                             //Realizamos la operación división
                             resultado=cimaMonton/numeroCinta;
                             break;
                             }
                case('-'):{
                             //Realizamos la operación resta
                             resultado=cimaMonton-numeroCinta;
                             if (resultado<0){//Si es menor que cero
                             	//Convertimos a valor absoluto.
                             	resultado=-resultado;
                             }
                             break;
                             }
                case('+'):{
                             //Realizamos la operación suma
                             resultado=cimaMonton+numeroCinta;
                             break;
                             }
           }
	return resultado;//devolvemos el resultado.
}


