#include <iostream>
#include <string>
#include <conio.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "cola.h"
#include "nodo_cola.h"
#include "juego.h"

//CONSTRUCTORAS
/** @brief Constructor para crear una cola vac�a.
*
*   No hay ning�n nodo_cola creado, no hay celdas en la cola, ambos punteros
*	primero y ultimo son �Null�.
*
**/
cola::cola()
{           //Declaramos el valor inicial de las variables. Cola vacia.
            primero=NULL;
            ultimo=NULL;
}

//CONSTRUCTORAS
/** @brief Destructor de la clase cola
*
*   Elimina todas las celdas de la cola, recorriendo la cola desde la primera celda a la �ltima,
*   llama a la funci�n desencolar(), hasta que el puntero primero es igual a NULL, ya no hay mas celdas
*   @see desencolar()
*
**/
cola::~cola(){
	while (primero!=NULL){//Mientras primero apunte a una celda hay elementos.
	desencolar();//quitamos el primer elemento.
	}
	//Despues de eliminar las celdas
	//liberamos los punteros que ahora apuntan a null, tanto el primero como el �ltimo.
	delete primero;
	delete ultimo;
	cout<<"cola eliminada";
	
}

/** @brief Comprueba si una cola, cinta, est� vac�a.
*
*   Comprueba si el puntero, primero,  de la clase nodo_cola apunta a un nodo o a null. (primero==NULL)
*	si es igual a null devuelve true en caso contrario devuelve false.
*	@retval true la cola est� vac�a.
*	@retval false la cola tiene celdas, no est� vac�a.
**/
bool cola::es_cola_vacia() //Devuelve true si est� vac�a, false en caso else
{
     if (primero==NULL)
     {
      return true;
     }
     else
     {
      return false;
     }
}

/** @brief Inserta un nuevo n�mero en la cinta, cola.
*
*   Inserta una nueva celda por el extremo �ltimo, un nuevo nodo_cola, con atributo valor=elemento
*   y cuyo puntero a siguiente es igual a NULL
*
*	@param elemento n�mero entero a insertar en la cola.
*
**/
void cola::encolar(short elemento) //inserta datos de clase persona.
{
	/**
	*Variables:
	**/
	/**- p: puntero de la clase nodo_cola, el nodo al que apunta es la nueva celda a insertar.*/
     nodo_cola*p=new nodo_cola();//puntero a nodo_cola. Nodo a insertar.
     p->valor=elemento;//Al atributo valor, del nodo a insertar, le asignamos el n�mero almacenado en elemento.
     p->pSiguiente=NULL;//El puntero del nodo a insertar toma el valor de NULL, pues ser� el �ltimo nodo.
     
     //Comprobara si la cola esta o no vac�a, para colocar el nuevo nodo.
     if (es_cola_vacia()) //en caso de no haber ning�n elemento.
     {
     primero=p;//El puntero primero de la cola apuntara al nuevo nodo creado.                                     
     }
     else // ya hay elementos en la cola.
      {
	  ultimo->pSiguiente=p; //El puntero del nodo �ltimo apuntara al nuevo nodo creado.  
      }
     
    //una vez colocado el nodo actualizamos el puntero de la cola que apunta a la �ltima celda.
      ultimo=p;//El puntero �ltimo de la cola apuntara al nuevo nodo creado e introducido.
	   
}



/** @brief Devuelve el n�mero que est� almacenado en la primera celda de la cola, primero de la cinta.
*
*   Devuelve el n�mero que est� almacenado en el atributo valor, del primer nodo_cola, que pertenece a la cola.
*	Mediante el puntero primero de la cola accedemos al valor del primer nodo.
*	
*	@return valor un entero comprendido entre  el 1 y el 9.
*
**/
short cola::primero_en_cola() //Muestra el primer elemento de la cola.
{	/**Variables*/
	/**-	e: Variable de tipo entero que almacena el valor del n�mero primero */
	short e = 0;//Variable de tipo entero que almacena el valor del n�mero primero.
	try{
		
     if (es_cola_vacia()){ //Si est� vac�a lanzamos la excepci�n
     throw es_cola_vacia();

     }//fif
     else//Si est� llena devuelve el numero del atributo valor del primer elemento
      {        
                          e=primero->valor;//almacenamos en e
      }//felse
      }catch(bool){//Capturamos la excepci�n
      	cout<<"La cola est� vac�a";
      }
	return e;
}//fvoid

/** @brief Devuelve el n�mero que est� almacenado en la �ltima celda de la cola, �ltimo de la cinta.
*
*   Devuelve el n�mero que est� almacenado en el atributo valor, del �ltimo nodo_cola, que pertenece a la cola.
*   Mediante el puntero ultimo de la cola accedemos al valor del �ltimo nodo.
*
*	@return valor un entero comprendido entre  el 1 y el 9.
*
**/
short cola::ultimo_en_cola() //Muestra el primer elemento de la cola.
{
	/**Variables*/
	/**-	e: Variable de tipo entero que almacena el valor del n�mero ultimo */
	short e = 0;//Variable de tipo entero que almacena el valor del n�mero ultimo.
	try{
	
     if (es_cola_vacia()){ //Si est� vac�a lanzamos la excepci�n
     throw es_cola_vacia();
     }//fif
     else//Si contiene celdas devolvemos el valor de la �ltima.
      {                  
                          e=ultimo->valor;//almacenamos en e
      }//felse
      
  }catch(bool){//Capturamos la excepci�n
  	cout<<"La cola est� vac�a";
  }
	return e;
}//fvoid



/** @brief Elimina el primer elemento de la cinta, cola.
*
*   Elimina la primera celda de la cola, actualizando los punteros primero y �ltimo.
*
**/
void cola::desencolar() //elimina el primer elemento de la cola.
{
	/**
	*Variables:
	**/
	/**- p: puntero de la clase nodo_cola, apuntara al nodo que queremos eliminar*/
     nodo_cola*p=new nodo_cola();
     
     //Comprobamos la situaci�n de la cola
     if (es_cola_vacia()) //si esta vac�a informa de ello.
     {                    cout<<" La COLA est� Vacia "<<endl;
                        
     }//fif
     else//al estar llena
      {
                     p=primero;// p apunta al primer nodo
                     primero=primero->pSiguiente;// El punetero primero se actualiza apuntando al siguiente 
                     if(primero==NULL){//cola ya esta vacia
                     ultimo=NULL;
                     }
                     
      }//felse
      
      //Se elimina ele elemento
      p->pSiguiente=NULL; //por seguridad
      delete (p);
      
     return;
}


/** @brief Funci�n que llena la cola con un n�mero n=5 de elementos.
*
*    Desde 1 hasta n, genera un nuevo n�mero aleatorio(entre 1-9) 
*   'numeroAleatorio' y procede a encolarlo en la cola, llamando a la funci�n encolar.
*	 @see encolar(short numeroAleatorio)
*
**/
void cola::llenarCola(){
/**
*Variables:
*/
/**- n: N�mero de elementos a encolar, celdas que tendr� la cola ->5*/
/**- c: Variable que cuenta cada iteraci�n del bucle hasta llegar a n*/
/**- numeroAleatorio: n�mero entero que est� entre 1 y 9 obtenido aleatoriamente.*/
	int n=5; //numero de elementos para encolar 5
	int c=0; //Contador
for(c = 1; c <= n; c++){ //Desde 1 hasta llegar a 5
int numeroAleatorio=juego::obtenerNumero(); //Obtenemos un n�mero entre 1 y 9
encolar(numeroAleatorio); //Se procede a encolar el n�mero obtenido
}
}


/** @brief Funci�n que muestra por pantalla, todos los elementos de la cola menos el primero.
*
*   Recorre la cola desde el primer nodo hasta el �ltimo mediante un puntero auxiliar
*	que va apuntando a los diferentes nodos de la cola, para cada nodo obtenemos el n�mero
*	que contiene su atributo valor y lo mostramos por pantalla, menos en el caso del primer
*	nodo que no lo mostramos
*
**/
void cola::mostrarResto() //imprime los elementos de la cola, menos el primero.
    {
    	/**Variables*/
    	/**- auxiliar: puntero a nodo_cola que va cambiando de valor, 
		apuntando a los diferentes nodos de la cola, seg�n avanza el recorrido*/
        nodo_cola *auxiliar;
        
        auxiliar=primero; //inicializamos la variable auxiliar apuntando al 1� elemento.
 
        while(auxiliar!=NULL) //mientras no apunte a NULL la cola continua. Hay nodos.
        {                               
                        
            //En el caso de que auxiliar no apunte al primer nodo, imprimimos:
            if (auxiliar!=primero){
        	//imprimimos los datos que nos dan los m�todos del objeto al que apunta el auxiliar.    
             cout<<auxiliar->valor<<" ";
            }
            //auxiliar pasa a apuntar al siguiente nodo, avanza el recorrido.
            auxiliar=auxiliar->pSiguiente;
            //if (auxiliar==NULL) break; //si auxiliar es igual a NULL ya no hay mas nodos salimos
        }
        
        delete auxiliar; //al salir de bucle liberamos el puntero.
       
    }


