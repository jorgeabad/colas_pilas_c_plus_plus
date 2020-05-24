/**
* @file main.cpp
* @brief cpp. Contiene la funcion que ejecuta el programa.
* @author Jorge Abad
*/
#include <cstdlib>
#include <iostream>
#include "juego.h"
#include "pila.h"
#include "cola.h"
#include <locale.h>
#include <conio.h>

using namespace std;

/** @brief Funcion que representa el punto de inicio de ejecuci�n del programa.
*
*-	Instancia un objeto de la clase cola, para reperesentar la cinta.
*-	Instancia 4 objetos de la clase pila, para representar los 4 montones.
*-	Llama a los metodos de la clase juego, para realizar  y obtener las operaciones.
*-	Muestra la interfaz grafica que le aparece al usuario mostrando un men� con opciines.
*-	Crea las variables locales necesarias para interactuar con el usuario, como mensajes de aviso y opciones elegidas.
*
**/
int main(int argc, char *argv[])
{

	setlocale(LC_ALL, "spanish");  /*poder representar acentos*/
	juego::iniciarSemilla(); /*iniciamos la semilla para generar los n�meros aleatorios*/
	/**Variables:*/
	/**-	valorReferencia: numero entero que representa el numero m�ximo de elementos que puede haber en un mont�n*/
	const short valorReferencia = 10; //No se permitir� mas de 10 elementos en un mont�n


	/**-	montonSeleccionado: numero entero que representa el monton seleccionado por el usuario*/
	short montonSeleccionado = 0;//inicialmente no hay ning�n mont�n seleccionado, 0.
	/**-	monton1, monton2, monton3, monton4: objetos de la clase pila representan los 4 montones*/
	/*Creamos los montones en donde almacenaremos los numeros, instanciamos objetos de la clase pila*/
	pila monton1;
	pila monton2;
	pila monton3;;
	pila monton4;

	/**-	cinta: objeto de la clase cola, representar� la cinta de numeros*/
	/*Instanciamos un objeto de la clase cola, ser� la cinta d�nde iran apareciendo los nuevos n�meros*/
	cola cinta;

	/*Mediante el m�todo llenarPila(), de la clase pila, llenamos los 4 montones, con numeros aleatorios y con una longitud aleatoria
	para cada pila, los numeros y la longitusd estar�n entre 1 y 9*/
	monton1.llenarPila();
	monton2.llenarPila();
	monton3.llenarPila();
	monton4.llenarPila();

	/*Llenamo la cinta con 5 numeros mediante el m�todo llenarCola() de la clase cola*/
	cinta.llenarCola();

	/**-	op: variable char almacena el s�mbolo de la operci�n generada*/
	char op = ' '; //Almacena el s�mbolo de la operaci�n
	/**-	avisoSistema: variable string Almacena cualquier aviso de error o advertencia, para el usuario al interactuar con el programa*/
	string avisoSistema = ""; //Almacena cualquier aviso de error o advertencia, para el usuario al interactuar con el programa.
	/**-	finJuego: variable string Almacena una cadena con un mensaje de fin de programa, ganar o perder*/
	string finJuego = "fin del programa"; //Avisa del fin del programa.
	/**- 	opcion: variable char que almacena la opci�n seleccionada por el usuario. si es 's' salimos del programa*/
	char opcion = '0';//variable que almacena la opci�n seleccionada por el usuario.Cero no hay opci�n.
	/**-	numeroCinta variable shor almacena el primer numero de la cinta, el que hay que introducir en los montones.*/
	short numeroCinta = 0; // almacena el primer numero de la cinta, el que hay que introducir en los montones.Cero no hay n�mero sacado de la cinta.
	/**-	cima: variable short Almacena el n�mero que es cima del monton seleccionado con el que operaremos.*/
	short cima;//Almacena el n�mero que es cima del monton seleccionado.
	/**- resultado: variable short que almacena el resultado de la operacion entre el primero de la cinta y el �ltimo del mont�n*/
	short resultado = 0;//Almacena el resultado de la operaci�n inicialmente 0.

	/*Mientras la opci�n seleccionada no sea 's' se limpia la pantalla y de nuevo se muestra la situaci�n actual
	y valor actual de las variables oportunas. Mostrar� situaci�n actual de la cinta, de los montones, el monton
	elegido, la operaci�n generada, un men� de opciones, y un mensaje de aviso para interactuar con el juego.*/
	while (opcion != 's')
	{

		system("cls"); //limpiamos la pantalla.

		/*Cabecera presentaci�n.*/
		cout << endl << "    #------------------|* NUMBERIS  -  PRACTICA1 *|-------------------#" << endl;

		system("color 0B");//color del fondo y del texto de la consola.

		numeroCinta = cinta.primero_en_cola(); //Almacenamos el el primer n�mero de la cinta.

		/*Mostramos por pantalla todos los elementos de la cinta, m�todo mostrar() de la clase cola*/
		cout << " Cinta num�rica: ";
		cout << "\n --------------";
		/*Mostramos por pantalla el primer y el resto de n�meros de la cinta, cola*/
		cout << "       Primero: " << numeroCinta
			<< "     Resto: "; cinta.mostrarResto(); //Mostramos el primer numero de la cinta.
		cout << "\n";


		/*Mostramos por pantalla el contenido de los cuatros montones mediante el metodo imprimir() de la
		clase pila, para cada objeto pila que ha sido instanciado.*/
		cout << "\n MONT�N 1-> "; monton1.imprimir();
		cout << "\n";

		cout << " MONT�N 2-> "; monton2.imprimir();
		cout << "\n";

		cout << " MONT�N 3-> "; monton3.imprimir();
		cout << "\n";

		cout << " MONT�N 4-> "; monton4.imprimir();
		cout << "\n";
		/**-  montonStd []: array char almacena el monton elegido para mostrarlo al usuario por la pantalla valores ' ', '1', '2', '3', '4'*/
		char montonStd[] = " ";//Muestra por pantalla el monton elegido. Inicialmente no hay monton seleccionado.
		montonStd[0] = (char)(montonSeleccionado + 48);//convertimos a char el valor de montonSeleccionado y lo almacenamos en la primera posicion del array  
		if (montonSeleccionado == 0){//Si montonSeleccionado es igual a cero, no hay monton seleccionado
			montonStd[0] = ' ';//la primera posici�n es vac�a.
		}

		/*Mostramos informaci�n, con el men�, los valores seleccionados y generados para cada vez que el usuario
		seleccina una opci�n y pulsa intro. Se mostrar� el mont�n elegido por el usuario y la operaci�n que se genera*/
		cout << "\n----------------------------------------------------------------------\n";
		cout << "         OPERACION-> " << op << "     MONTON SELECCIONADO-> " << montonStd << "\n";
		cout << "-----------------------------------------------------------------------\n";

		/*Saca por pantalla las opciones del men�.  */
		cout << "     0- Generar operaci�n " << endl << endl;
		cout << "     1- Colocar el n� en el mont�n 1" << endl <<
			"     2- Colocar el n� en el mont�n 2" << endl <<
			"     3- Colocar el n� en el mont�n 3" << endl <<
			"     4- Colocar el n� en el mont�n 4" << endl <<
			"\n     s- Salir " << endl;

		/*Mostramos un aviso del sistema con otro color de fuente, verde*/
		HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE);
		cout << "Mensaje del Sistema: ";
		SetConsoleTextAttribute(console, 10);/*Fuente de color verde para el siguiente cout<<*/
		cout << avisoSistema;//Mostrara el contenido de la variable para advertir de cualquier error.
		SetConsoleTextAttribute(console, 11);/*volvemos a poner letras en azul claro*/

		cout << "\n Eliga una opci�n: ";
		cin >> opcion; //leer la opci�n elegida y lo almacenamos en la variable opci�n

		system("cls");//despues de leer la opci�n elegida limpiamos pantalla
		system("color 0A");  //color del fondo y del texto de la consola.



		/*En funci�n del valor de opcion y de valores anteriores de las variables op y montonSeleccionado,
		seleccionaremos un monton o generaremos una operaci�n o realizamos la operacion
		con primero de la cinta y la cima de un monton**/
		switch (opcion)
		{
			/*Si opcion es '0', si se puede, generaremos una operaci�n**/
		case '0':{
			if (op != ' '){
				avisoSistema = "Ya hay operaci�n generada no puede solicitar otra, \n pulse una tecla diferente a las opciones";
				break;
			}
			/*Solo generamos la operaci�n si hay un monton seleccionado, si es igual a cero avisamos*/
			if (montonSeleccionado == 0){
				avisoSistema = "No se puede generar una operaci�n, primero ha de elegir un mont�n";
				/*Si el hay un monton seleccionado, montonSeleccionado es distinto de cero ,obtenemos una operaci�n*/
			}
			else{
				op = juego::obtenerOperacion();//Obtenemos un operaci�n aleatoria y la almacenamos.
				avisoSistema = "Pulse una tecla diferente a las opciones para continuar.";
			}
			break;
		}

			/*Opciones para seleccionar un monton*/

			/*opcion es igual a '1'*/
		case '1':{
			/*Comprobamos que op sea igual a vacio, no halla operaci�n generada previamente y que el monton 1 no est� vacio*/
			if (monton1.es_pila_vacia() && op == ' '){
				avisoSistema = "Mont�n 1 vacio no lo puede usar, seleccione otro.";//Avisamos que ese mont�n no puede usarse.
				break;
			}

			/*Si no hay operacion generada, op tiene valor vacio, podemos elegir mont�n*/
			if (op == ' '){
				montonSeleccionado = 1;/*almacenamos el valor 1 en montonSeleccionado*/
				avisoSistema = "Genere una operacion o cambie de mont�n";/*podemos cambiar de mont�n al no haber operaci�n*/

			}
			else{/*Hay una operacion generada, var op diferente vac�o, no podemos intentar cambiar de mont�n*/
				avisoSistema = "Ya hay operaci�n generada no puede cambiar de mont�n, \n pulse una tecla diferente a las opciones para continuar";
			}

			break;

		}
			/*opcion es igual a '2'*/
		case '2':{
			/*Comprobamos que op sea igual a vacio, no halla operaci�n generada previamente y que el monton 2 no est� vacio*/
			if (monton2.es_pila_vacia() && op == ' '){
				avisoSistema = "Monton 2 vacio no lo puede usar, seleccione otro.";//Avisamos que ese mont�n no puede usarse.
				break;
			}
			/*Si no hay operacion generada, op tiene valor vacio, podemos elegir mont�n*/
			if (op == ' '){
				montonSeleccionado = 2;/*almacenamos el valor 2 en montonSeleccionado*/
				avisoSistema = "Genere una operacion o cambie de mont�n";/*podemos cambiar de mont�n al no haber operaci�n*/

			}
			else{ /*Hay una operacion generada, var op diferente vac�o, no podemos intentar cambiar de mont�n*/
				avisoSistema = "Ya hay operaci�n generada no puede cambiar de mont�n, \n pulse una tecla diferente a las opciones para continuar";
			}
			break;
		}

			/*opcion es igual a '3'*/
		case '3':{

			if (monton3.es_pila_vacia() && op == ' '){
				avisoSistema = "Monton 3 vacio no lo puede usar, seleccione otro.";//Avisamos que ese mont�n no puede usarse.
				break;
			}
			/*Si no hay operacion generada, op tiene valor vacio, podemos elegir mont�n*/
			if (op == ' '){
				montonSeleccionado = 3;/*almacenamos el valor 3 en montonSeleccionado*/
				avisoSistema = "Genere una operacion o cambie de mont�n";
			}
			else{
				avisoSistema = "Ya hay operaci�n generada no puede cambiar de mont�n, \n pulse una tecla diferente a las opciones para continuar";
			}
			break;
		}

			/*opcion es igual a '4'*/
		case '4':{

			if (monton4.es_pila_vacia() && op == ' '){
				avisoSistema = "Monton 4 vacio no lo puede usar, seleccione otro.";//Avisamos que ese mont�n no puede usarse.
				break;
			}
			/*Si no hay operacion generada, op tiene valor vacio, podemos elegir mont�n*/
			if (op == ' '){
				montonSeleccionado = 4;
				avisoSistema = "Genere una operacion o cambie de mont�n";

			}
			else{
				avisoSistema = "Ya hay operaci�n generada no puede cambiar de mont�n, \n pulse una tecla diferente a las opciones para continuar";
			}
			break;
		}
			/*opcion es igual a otro valor diferente de '0','1','2','3','4'*/
		default:{
			/*si no hay monton ni operaci�n, montonSeleccionado, op, son cero o vacio respectivamente, salimos*/
			if (montonSeleccionado == 0 || op == ' '){
				avisoSistema = "No hay mont�n seleccionado o una operaci�n creada eliga otra opci�n";


			}
			else{
				/*Hay un mont�n seleccionado, montonSeleccionado es diferente de cero y una operaci�n, op es diferente de ' '*/
				/*Para cada mont�n seleccionado, determinado por el valor montonSeleccionado, actuamos*/
				switch (montonSeleccionado){

				case 1:{
					/*la variable cima toma el valor de la cima del mont�n 1*/
					cima = monton1.cima();
					/*Pasamos los valores,un s�mbolo de operaci�n, y dos n�meros, para operar, y obtener un resultado */
					resultado = juego::obtenerResultado(op, numeroCinta, cima);
					/*Si el resultado es menor que un valor de referencia (10)*/
					if (resultado<valorReferencia){
						/*Colocamos el n�mero de la cinta en la cima del mont�n apilamos */
						monton1.apilar(numeroCinta);
						avisoSistema = " Elemento colocado en mont�n 1";
					}
					else{
						/*En caso contrario procedemos a quitar la cima del mont�n, desapilar*/
						monton1.desapilar();
						avisoSistema = " La cima del mont�n 1 ha sido eliminada ";
					}
					/*Una vez desapilado o apilado comprobamos si el mont�n ha llegado al limite*/
					if (monton1.getNumElementos() == 10){
						/*Al llegar al limite alamacenamos un mensje en la var finJuego*/
						finJuego = "PERDISTE MONTON 1 LLENO";
						/*Provocamos la salida del while, asignando el valor 's' a la var opcion */
						opcion = 's';
					}

					break;
				}
				case 2:{

					cima = monton2.cima();
					resultado = juego::obtenerResultado(op, numeroCinta, cima);
					if (resultado<valorReferencia){
						monton2.apilar(numeroCinta);
						avisoSistema = " Elemento colocado en mont�n 2";
					}
					else{
						monton2.desapilar();
						avisoSistema = " La cima del mont�n 2 ha sido eliminada ";
					}
					if (monton2.getNumElementos() == 10){
						finJuego = "PERDISTE MONTON 2 LLENO";
						opcion = 's';
					}


					break;
				}
				case 3:{

					cima = monton3.cima();
					resultado = juego::obtenerResultado(op, numeroCinta, cima);
					if (resultado<valorReferencia){
						monton3.apilar(numeroCinta);
						avisoSistema = " Elemento colocado en mont�n 3";
					}
					else{
						monton3.desapilar();
						avisoSistema = " La cima del mont�n 3 ha sido eliminada ";
					}
					if (monton3.getNumElementos() == 10){
						finJuego = "PERDISTE MONTON 3 LLENO";
						opcion = 's';
					}

					break;
				}
				case 4:{

					cima = monton4.cima();
					resultado = juego::obtenerResultado(op, numeroCinta, cima);
					if (resultado<valorReferencia){
						monton4.apilar(numeroCinta);
						avisoSistema = " Elemento colocado en mont�n 4";
					}
					else{
						monton4.desapilar();
						avisoSistema = " La cima del mont�n 4 ha sido eliminada ";
					}
					if (monton4.getNumElementos() == 10){
						finJuego = "PERDISTE MONTON 4 LLENO";
						opcion = 's';
					}

					break;
				}

				}

				/*Despues de actuar sobre un mont�n, comprobamos si todos los montones est�n ya vacios*/
				if (monton1.es_pila_vacia() && monton2.es_pila_vacia() && monton3.es_pila_vacia() && monton4.es_pila_vacia())	{
					/*Al estar todos vac�os el juego se gana almacenamos el valor adecuado en la var finJuego*/
					finJuego = "Ganaste el juego todos los montones vacios";
					/*Provocaremos la salida del while asignando el valor 's' a la opci�n*/
					opcion = 's';
				}
				else{
					/*Si no est�n vacios reiniciamos las variables con los valores adecuados*/
					avisoSistema = avisoSistema + ".\n Seleccione un mont�n para continuar jugando";
					montonSeleccionado = 0;
					op = ' ';
					/*Actuamos sobre la cinta, quitando y poniendo n�mero*/
					/*Quitamos el primero de la cinta, desencolamos*/
					cinta.desencolar();
					/*A�adimos un nuevo numero a la cinta por el final, encolamos.*/
					cinta.encolar(juego::obtenerNumero());
				}




			}
		}


		}







	}
	system("cls");



	//Final del programa
	cout << "###################################################" << endl <<
		finJuego << "*" << endl <<
		"###################################################" << endl;
	_getche();


}


