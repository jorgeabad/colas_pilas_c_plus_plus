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

/** @brief Funcion que representa el punto de inicio de ejecución del programa.
*
*-	Instancia un objeto de la clase cola, para reperesentar la cinta.
*-	Instancia 4 objetos de la clase pila, para representar los 4 montones.
*-	Llama a los metodos de la clase juego, para realizar  y obtener las operaciones.
*-	Muestra la interfaz grafica que le aparece al usuario mostrando un menú con opciines.
*-	Crea las variables locales necesarias para interactuar con el usuario, como mensajes de aviso y opciones elegidas.
*
**/
int main(int argc, char *argv[])
{

	setlocale(LC_ALL, "spanish");  /*poder representar acentos*/
	juego::iniciarSemilla(); /*iniciamos la semilla para generar los números aleatorios*/
	/**Variables:*/
	/**-	valorReferencia: numero entero que representa el numero máximo de elementos que puede haber en un montón*/
	const short valorReferencia = 10; //No se permitirá mas de 10 elementos en un montón


	/**-	montonSeleccionado: numero entero que representa el monton seleccionado por el usuario*/
	short montonSeleccionado = 0;//inicialmente no hay ningún montón seleccionado, 0.
	/**-	monton1, monton2, monton3, monton4: objetos de la clase pila representan los 4 montones*/
	/*Creamos los montones en donde almacenaremos los numeros, instanciamos objetos de la clase pila*/
	pila monton1;
	pila monton2;
	pila monton3;;
	pila monton4;

	/**-	cinta: objeto de la clase cola, representará la cinta de numeros*/
	/*Instanciamos un objeto de la clase cola, será la cinta dónde iran apareciendo los nuevos números*/
	cola cinta;

	/*Mediante el método llenarPila(), de la clase pila, llenamos los 4 montones, con numeros aleatorios y con una longitud aleatoria
	para cada pila, los numeros y la longitusd estarán entre 1 y 9*/
	monton1.llenarPila();
	monton2.llenarPila();
	monton3.llenarPila();
	monton4.llenarPila();

	/*Llenamo la cinta con 5 numeros mediante el método llenarCola() de la clase cola*/
	cinta.llenarCola();

	/**-	op: variable char almacena el símbolo de la operción generada*/
	char op = ' '; //Almacena el símbolo de la operación
	/**-	avisoSistema: variable string Almacena cualquier aviso de error o advertencia, para el usuario al interactuar con el programa*/
	string avisoSistema = ""; //Almacena cualquier aviso de error o advertencia, para el usuario al interactuar con el programa.
	/**-	finJuego: variable string Almacena una cadena con un mensaje de fin de programa, ganar o perder*/
	string finJuego = "fin del programa"; //Avisa del fin del programa.
	/**- 	opcion: variable char que almacena la opción seleccionada por el usuario. si es 's' salimos del programa*/
	char opcion = '0';//variable que almacena la opción seleccionada por el usuario.Cero no hay opción.
	/**-	numeroCinta variable shor almacena el primer numero de la cinta, el que hay que introducir en los montones.*/
	short numeroCinta = 0; // almacena el primer numero de la cinta, el que hay que introducir en los montones.Cero no hay número sacado de la cinta.
	/**-	cima: variable short Almacena el número que es cima del monton seleccionado con el que operaremos.*/
	short cima;//Almacena el número que es cima del monton seleccionado.
	/**- resultado: variable short que almacena el resultado de la operacion entre el primero de la cinta y el último del montón*/
	short resultado = 0;//Almacena el resultado de la operación inicialmente 0.

	/*Mientras la opción seleccionada no sea 's' se limpia la pantalla y de nuevo se muestra la situación actual
	y valor actual de las variables oportunas. Mostrará situación actual de la cinta, de los montones, el monton
	elegido, la operación generada, un menú de opciones, y un mensaje de aviso para interactuar con el juego.*/
	while (opcion != 's')
	{

		system("cls"); //limpiamos la pantalla.

		/*Cabecera presentación.*/
		cout << endl << "    #------------------|* NUMBERIS  -  PRACTICA1 *|-------------------#" << endl;

		system("color 0B");//color del fondo y del texto de la consola.

		numeroCinta = cinta.primero_en_cola(); //Almacenamos el el primer número de la cinta.

		/*Mostramos por pantalla todos los elementos de la cinta, método mostrar() de la clase cola*/
		cout << " Cinta numérica: ";
		cout << "\n --------------";
		/*Mostramos por pantalla el primer y el resto de números de la cinta, cola*/
		cout << "       Primero: " << numeroCinta
			<< "     Resto: "; cinta.mostrarResto(); //Mostramos el primer numero de la cinta.
		cout << "\n";


		/*Mostramos por pantalla el contenido de los cuatros montones mediante el metodo imprimir() de la
		clase pila, para cada objeto pila que ha sido instanciado.*/
		cout << "\n MONTóN 1-> "; monton1.imprimir();
		cout << "\n";

		cout << " MONTóN 2-> "; monton2.imprimir();
		cout << "\n";

		cout << " MONTóN 3-> "; monton3.imprimir();
		cout << "\n";

		cout << " MONTóN 4-> "; monton4.imprimir();
		cout << "\n";
		/**-  montonStd []: array char almacena el monton elegido para mostrarlo al usuario por la pantalla valores ' ', '1', '2', '3', '4'*/
		char montonStd[] = " ";//Muestra por pantalla el monton elegido. Inicialmente no hay monton seleccionado.
		montonStd[0] = (char)(montonSeleccionado + 48);//convertimos a char el valor de montonSeleccionado y lo almacenamos en la primera posicion del array  
		if (montonSeleccionado == 0){//Si montonSeleccionado es igual a cero, no hay monton seleccionado
			montonStd[0] = ' ';//la primera posición es vacía.
		}

		/*Mostramos información, con el menú, los valores seleccionados y generados para cada vez que el usuario
		seleccina una opción y pulsa intro. Se mostrará el montón elegido por el usuario y la operación que se genera*/
		cout << "\n----------------------------------------------------------------------\n";
		cout << "         OPERACION-> " << op << "     MONTON SELECCIONADO-> " << montonStd << "\n";
		cout << "-----------------------------------------------------------------------\n";

		/*Saca por pantalla las opciones del menú.  */
		cout << "     0- Generar operación " << endl << endl;
		cout << "     1- Colocar el nº en el montón 1" << endl <<
			"     2- Colocar el nº en el montón 2" << endl <<
			"     3- Colocar el nº en el montón 3" << endl <<
			"     4- Colocar el nº en el montón 4" << endl <<
			"\n     s- Salir " << endl;

		/*Mostramos un aviso del sistema con otro color de fuente, verde*/
		HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE);
		cout << "Mensaje del Sistema: ";
		SetConsoleTextAttribute(console, 10);/*Fuente de color verde para el siguiente cout<<*/
		cout << avisoSistema;//Mostrara el contenido de la variable para advertir de cualquier error.
		SetConsoleTextAttribute(console, 11);/*volvemos a poner letras en azul claro*/

		cout << "\n Eliga una opción: ";
		cin >> opcion; //leer la opción elegida y lo almacenamos en la variable opción

		system("cls");//despues de leer la opción elegida limpiamos pantalla
		system("color 0A");  //color del fondo y del texto de la consola.



		/*En función del valor de opcion y de valores anteriores de las variables op y montonSeleccionado,
		seleccionaremos un monton o generaremos una operación o realizamos la operacion
		con primero de la cinta y la cima de un monton**/
		switch (opcion)
		{
			/*Si opcion es '0', si se puede, generaremos una operación**/
		case '0':{
			if (op != ' '){
				avisoSistema = "Ya hay operación generada no puede solicitar otra, \n pulse una tecla diferente a las opciones";
				break;
			}
			/*Solo generamos la operación si hay un monton seleccionado, si es igual a cero avisamos*/
			if (montonSeleccionado == 0){
				avisoSistema = "No se puede generar una operación, primero ha de elegir un montón";
				/*Si el hay un monton seleccionado, montonSeleccionado es distinto de cero ,obtenemos una operación*/
			}
			else{
				op = juego::obtenerOperacion();//Obtenemos un operación aleatoria y la almacenamos.
				avisoSistema = "Pulse una tecla diferente a las opciones para continuar.";
			}
			break;
		}

			/*Opciones para seleccionar un monton*/

			/*opcion es igual a '1'*/
		case '1':{
			/*Comprobamos que op sea igual a vacio, no halla operación generada previamente y que el monton 1 no esté vacio*/
			if (monton1.es_pila_vacia() && op == ' '){
				avisoSistema = "Montón 1 vacio no lo puede usar, seleccione otro.";//Avisamos que ese montón no puede usarse.
				break;
			}

			/*Si no hay operacion generada, op tiene valor vacio, podemos elegir montón*/
			if (op == ' '){
				montonSeleccionado = 1;/*almacenamos el valor 1 en montonSeleccionado*/
				avisoSistema = "Genere una operacion o cambie de montón";/*podemos cambiar de montón al no haber operación*/

			}
			else{/*Hay una operacion generada, var op diferente vacío, no podemos intentar cambiar de montón*/
				avisoSistema = "Ya hay operación generada no puede cambiar de montón, \n pulse una tecla diferente a las opciones para continuar";
			}

			break;

		}
			/*opcion es igual a '2'*/
		case '2':{
			/*Comprobamos que op sea igual a vacio, no halla operación generada previamente y que el monton 2 no esté vacio*/
			if (monton2.es_pila_vacia() && op == ' '){
				avisoSistema = "Monton 2 vacio no lo puede usar, seleccione otro.";//Avisamos que ese montón no puede usarse.
				break;
			}
			/*Si no hay operacion generada, op tiene valor vacio, podemos elegir montón*/
			if (op == ' '){
				montonSeleccionado = 2;/*almacenamos el valor 2 en montonSeleccionado*/
				avisoSistema = "Genere una operacion o cambie de montón";/*podemos cambiar de montón al no haber operación*/

			}
			else{ /*Hay una operacion generada, var op diferente vacío, no podemos intentar cambiar de montón*/
				avisoSistema = "Ya hay operación generada no puede cambiar de montón, \n pulse una tecla diferente a las opciones para continuar";
			}
			break;
		}

			/*opcion es igual a '3'*/
		case '3':{

			if (monton3.es_pila_vacia() && op == ' '){
				avisoSistema = "Monton 3 vacio no lo puede usar, seleccione otro.";//Avisamos que ese montón no puede usarse.
				break;
			}
			/*Si no hay operacion generada, op tiene valor vacio, podemos elegir montón*/
			if (op == ' '){
				montonSeleccionado = 3;/*almacenamos el valor 3 en montonSeleccionado*/
				avisoSistema = "Genere una operacion o cambie de montón";
			}
			else{
				avisoSistema = "Ya hay operación generada no puede cambiar de montón, \n pulse una tecla diferente a las opciones para continuar";
			}
			break;
		}

			/*opcion es igual a '4'*/
		case '4':{

			if (monton4.es_pila_vacia() && op == ' '){
				avisoSistema = "Monton 4 vacio no lo puede usar, seleccione otro.";//Avisamos que ese montón no puede usarse.
				break;
			}
			/*Si no hay operacion generada, op tiene valor vacio, podemos elegir montón*/
			if (op == ' '){
				montonSeleccionado = 4;
				avisoSistema = "Genere una operacion o cambie de montón";

			}
			else{
				avisoSistema = "Ya hay operación generada no puede cambiar de montón, \n pulse una tecla diferente a las opciones para continuar";
			}
			break;
		}
			/*opcion es igual a otro valor diferente de '0','1','2','3','4'*/
		default:{
			/*si no hay monton ni operación, montonSeleccionado, op, son cero o vacio respectivamente, salimos*/
			if (montonSeleccionado == 0 || op == ' '){
				avisoSistema = "No hay montón seleccionado o una operación creada eliga otra opción";


			}
			else{
				/*Hay un montón seleccionado, montonSeleccionado es diferente de cero y una operación, op es diferente de ' '*/
				/*Para cada montón seleccionado, determinado por el valor montonSeleccionado, actuamos*/
				switch (montonSeleccionado){

				case 1:{
					/*la variable cima toma el valor de la cima del montón 1*/
					cima = monton1.cima();
					/*Pasamos los valores,un símbolo de operación, y dos números, para operar, y obtener un resultado */
					resultado = juego::obtenerResultado(op, numeroCinta, cima);
					/*Si el resultado es menor que un valor de referencia (10)*/
					if (resultado<valorReferencia){
						/*Colocamos el número de la cinta en la cima del montón apilamos */
						monton1.apilar(numeroCinta);
						avisoSistema = " Elemento colocado en montón 1";
					}
					else{
						/*En caso contrario procedemos a quitar la cima del montón, desapilar*/
						monton1.desapilar();
						avisoSistema = " La cima del montón 1 ha sido eliminada ";
					}
					/*Una vez desapilado o apilado comprobamos si el montón ha llegado al limite*/
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
						avisoSistema = " Elemento colocado en montón 2";
					}
					else{
						monton2.desapilar();
						avisoSistema = " La cima del montón 2 ha sido eliminada ";
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
						avisoSistema = " Elemento colocado en montón 3";
					}
					else{
						monton3.desapilar();
						avisoSistema = " La cima del montón 3 ha sido eliminada ";
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
						avisoSistema = " Elemento colocado en montón 4";
					}
					else{
						monton4.desapilar();
						avisoSistema = " La cima del montón 4 ha sido eliminada ";
					}
					if (monton4.getNumElementos() == 10){
						finJuego = "PERDISTE MONTON 4 LLENO";
						opcion = 's';
					}

					break;
				}

				}

				/*Despues de actuar sobre un montón, comprobamos si todos los montones están ya vacios*/
				if (monton1.es_pila_vacia() && monton2.es_pila_vacia() && monton3.es_pila_vacia() && monton4.es_pila_vacia())	{
					/*Al estar todos vacíos el juego se gana almacenamos el valor adecuado en la var finJuego*/
					finJuego = "Ganaste el juego todos los montones vacios";
					/*Provocaremos la salida del while asignando el valor 's' a la opción*/
					opcion = 's';
				}
				else{
					/*Si no están vacios reiniciamos las variables con los valores adecuados*/
					avisoSistema = avisoSistema + ".\n Seleccione un montón para continuar jugando";
					montonSeleccionado = 0;
					op = ' ';
					/*Actuamos sobre la cinta, quitando y poniendo número*/
					/*Quitamos el primero de la cinta, desencolamos*/
					cinta.desencolar();
					/*Añadimos un nuevo numero a la cinta por el final, encolamos.*/
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


