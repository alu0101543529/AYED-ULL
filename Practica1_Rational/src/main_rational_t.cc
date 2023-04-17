/*
* AUTOR: Raúl González Acosta
* FECHA: 14/02/2023
* EMAIL: alu0101543529@ull.edu.es
* VERSION: 1.0
* ASIGNATURA: Algoritmos y Estructuras de Datos
* PRÁCTICA Nº: 1
* COMPILACIÓN: g++ -g rational_t.cc main_rational_t.cc -o main_rational_t
*/

// Para los comentarios utilice la sintaxis // ó /* */, siempre que sea consistente.

#include <iostream>
#include <cmath>

// Todos los archivos de encabezado de un proyecto deben enumerarse como descendientes del directorio de origen del proyecto sin usar alias de directorio UNIX.
// Se deja un espacio para separar las cabeceras de las librerías del sistema, con las cabeceras propias del proyecto
#include "header_file/rational_t.h"

using namespace std;

int main () {

  rational_t a(1, 2), b(3), c;

  //FASE I
  cout << "a.value()= " << a.value() << endl; // Devuelve el valor de a
  cout << "b.value()= " << b.value() << endl; // Devuelve el valor de b
  cout << "c.value()= " << c.value() << endl; // Devuelve el valor de c

  cout << "a: ";
  a.write();                                  // Muestra por pantalla el número racional a, y su resultado en decimal
  cout << "b: ";
  b.write();                                  // Muestra por pantalla el número racional b, y su resultado en decimal

  c.read();                                   // Se inserta por pantalla el numerador y el denominador del número racional c
  cout << "c: ";
  c.write();                                  // Muestra por pantalla el número racional c, y su resultado en decimal

  // FASE II
  rational_t x(2, 3), y(2, 3);
  x.write();                                  // Muestra por pantalla el número racional x, y su resultado en decimal
  y.write();                                  // Muestra por pantalla el número racional y, y su resultado en decimal
  
  //-----------------------COMPARACIONES---------------------------
  cout << "x == y? " << (x.is_equal(y) ? "true" : "false") << endl;                           // Compara si los numeros racionales x e y son iguales
  cout << "x < y? " << (x.is_greater(y) ? "true" : "false") << endl;                          // Compara si el numero racional x es mayor que y.
  cout << "x > y? " << (x.is_less(y) ? "true" : "false") << endl;                             // Compara si el numero racional x es menor que y.

  // ---------------------MODIFICACIÓN PRÁCTICA--------------------
  cout << "a > 1? " << (rational_t().is_greater_than_1(c) ? "true" : "false") << endl;        // Compara si el número racional c (introducido) es mayor que 1.
  cout << "a < 1? " << (rational_t().is_less_than_1(c) ? "true" : "false") << endl;           // Compara si el número racional c (introducido) es menor que 1.
  cout << "a = 1? " << (rational_t().is_equal_1(c) ? "true" : "false") << endl;               // Compara si el número racional c (introducido) es igual a 1.

  // FASE III
  cout << "a + b: ";              // Suma los números racionales a y b, y saca el resultado en numero racional, y en decimal
  a.add(b).write();
  
  cout << "b - a: ";              // Resta los números racionales b y a, y saca el resultado en numero racional, y en decimal
  b.substract(a).write();

  cout << "a * b: ";              // Multiplica los números racionales a y b, y saca el resultado en numero racional, y en decimal
  a.multiply(b).write();
  
  cout << "a / b: ";              // Divide los números racionales a y b, y saca el resultado en numero racional, y en decimal
  a.divide(b).write();

  return 0;
}