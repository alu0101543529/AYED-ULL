/*
* AUTOR: Raúl González Acosta
* FECHA: 27/02/2023
* EMAIL: alu0101543529@ull.edu.es
* VERSION: 1.0
* ASIGNATURA: Algoritmos y Estructuras de Datos
* PRÁCTICA Nº: 2
* COMPILACIÓN: g++ -g rational_t.cpp main_p2.cpp -o main_p2
*/

// Para los comentarios utilice la sintaxis // ó /* */, siempre que sea consistente.


// Todos los archivos de encabezado de un proyecto deben enumerarse como descendientes del directorio de origen del proyecto sin usar alias de directorio UNIX.
// Se deja un espacio para separar las cabeceras de las librerías del sistema, con las cabeceras propias del proyecto

#include "header_files/matrix_t.hpp"

using namespace std;

int main () {
  
  rational_t a(1, 2), b(3);

  // FASE I

  //------------- OPERACIONES ARITMÉTICAS CON NÚMEROS RACIONALES -------------

  // Suma de racionales
  cout << "a + b: ";
  (a + b).write();          // Muestra por pantalla el valor de la suma de los números racionales a y b.

  // Resta de racionales
  cout << "b - a: ";
  (b - a).write();          // Muestra por pantalla el valor de la resta de los números racionales b y a.

  // Producto de racionales
  cout << "a * b: ";
  (a * b).write();          // Muestra por pantalla el valor del producto de los números racionales a y b.

  // División de racionales
  cout << "a / b: ";
  (a / b).write();          // Muestra por pantalla el valor de la división de los números racionales a y b.
  
  cout << endl;
  
  // FASE II
  //------------- OPERADORES I/O DE LA CLASE VECTOR -------------
  vector_t <double> v, w;
  v.read(), v.write();    // Lee y muestra por pantalla el valor del vector de números decimales en punto flotante con doble precisión v.
  w.read(), w.write();    // Lee y muestra por pantalla el valor del vector de números decimales en punto flotante con doble precisión w.
  
  cout << "Producto escalar de vector_t <double>: " << scal_prod(v, w) << endl << endl;   // Muestra el valor por pantalla del producto escalar entre los vectores de números decimales en punto flotante con doble precisión v y w.
  
  //--------MODIFICACIÓN----------
  //v.suma_vector(v);

  vector_t <rational_t> x, y;
  x.read(), x.write();    // Lee y muestra por pantalla el valor del vector de números racionales x.
  y.read(), y.write();    // Lee y muestra por pantalla el valor del vector de números racionales y.
  
  cout << "Producto escalar de vector_t <rational_t>: " << scal_prod(x, y) << endl << endl; // Muestra el valor por pantalla del producto escalar entre los vectores de números racionales x e y.

  // FASE III

  //------------- OPERADORES I/O DE LA CLASE MATRIZ -------------
  matrix_t <double> A, B, C;
  A.read(), A.write();    // Lee y muestra por pantalla el valor de la matriz de números decimales en punto flotante con doble precisión A.
  B.read(), B.write();    // Lee y muestra por pantalla el valor de la matriz de números decimales en punto flotante con doble precisión B.
  
  // Multiplicación de matrices
  C.multiply (A, B);       // Multiplica las matrices de números decimales en punto flotante con doble precisión A y B.
  cout << "Multiplicación de matrices A y B: " << endl;
  C.write();              // Muestra por pantalla el valor de la multiplicación de las matrices de números decimales en punto flotante con doble precisión A y B.


  return 0;
}
