/*
* AUTOR: Raúl González Acosta
* FECHA: 27/03/2023
* EMAIL: alu0101543529@ull.edu.es
* VERSION: 1.0
* ASIGNATURA: Algoritmos y Estructuras de Datos
* PRÁCTICA Nº: 4
* COMPILACIÓN: g++ -g main_sllpolynomial.cc -o main_sllpolynomial
* EJECUCIÓN: ./main_sllpolynomial < data_sllpolynomial.txt
*/

#include "header_files/sllpolynomial.h"

using namespace std;

int main() {
  vector_t<double> v1, v2, v3;

  cin >> v1 >> v2 >> v3;                                                               // Se leen los vectores de la forma: tamaño, valores.
  cout << "v1= " << v1;                                                                // Se imprimen los vectores densos (con ceros) leídos.
  cout << "v2= " << v2;
  cout << "v3= " << v3;
  cout << endl;

  // Fase II
  SllPolynomial sllp1(v1), sllp2(v2), sllp3(v3);                                       // Los vectores densos se convierten en polinomios dispersos (sin ceros), representados en listas enlazadas simples (sll).
  cout << "sllp1= " << sllp1;
  cout << "sllp2= " << sllp2;
  cout << "sllp3= " << sllp3;
  cout << endl;

  // Fase III
  double x1, x2, x3;
  cin >> x1 >> x2 >> x3;                                                               // Se leen los valores por los que se van a evaluar los polinomios dispersos (sin ceros), representados en listas enlazadas simples (sll).
  cout << "sllp1(" << x1 << ")= " << sllp1.Eval(x1) << endl;                           // Se evaluan los tres polinomios dispersos por los valores introducidos, y se imprime el valor por pantalla.
  cout << "sllp1(" << x2 << ")= " << sllp1.Eval(x2) << endl;
  cout << "sllp1(" << x3 << ")= " << sllp1.Eval(x3) << endl;
  cout << "sllp2(" << x1 << ")= " << sllp2.Eval(x1) << endl;
  cout << "sllp2(" << x2 << ")= " << sllp2.Eval(x2) << endl;
  cout << "sllp2(" << x3 << ")= " << sllp2.Eval(x3) << endl;
  cout << "sllp3(" << x1 << ")= " << sllp3.Eval(x1) << endl;
  cout << "sllp3(" << x2 << ")= " << sllp3.Eval(x2) << endl;
  cout << "sllp3(" << x3 << ")= " << sllp3.Eval(x3) << endl;
  cout << endl;

  cout << "sllp1 == sllp1? " << (sllp1.IsEqual(sllp1) ? "true" : "false") << endl;     // Se hace una comparación de igualdad (==) entre los polinomios dispersos (en todos sus posibles casos).
  cout << "sllp2 == sllp2? " << (sllp2.IsEqual(sllp2) ? "true" : "false") << endl;
  cout << "sllp3 == sllp3? " << (sllp3.IsEqual(sllp3) ? "true" : "false") << endl;
  cout << "sllp1 == sllp2? " << (sllp1.IsEqual(sllp2) ? "true" : "false") << endl;
  cout << "sllp2 == sllp1? " << (sllp2.IsEqual(sllp1) ? "true" : "false") << endl;
  cout << "sllp1 == sllp3? " << (sllp1.IsEqual(sllp3) ? "true" : "false") << endl;
  cout << "sllp3 == sllp1? " << (sllp3.IsEqual(sllp1) ? "true" : "false") << endl;
  cout << "sllp2 == sllp3? " << (sllp2.IsEqual(sllp3) ? "true" : "false") << endl;
  cout << "sllp3 == sllp2? " << (sllp3.IsEqual(sllp2) ? "true" : "false") << endl;
  cout << endl;

  // Fase IV
  SllPolynomial sllpsum12, sllpsum23;                                                  // Se hace una operación de suma (+) entre los polinomios dispersos (entre los polinomios dispersos "sllp1 + sllp2" y "sllp2 + sllp3").
  sllp1.Sum(sllp2, sllpsum12);
  cout << "sllp1 + sllp2 = " << sllpsum12;
  sllp2.Sum(sllp3, sllpsum23);
  cout << "sllp2 + sllp3 = " << sllpsum23;
  cout << endl;

  // MODIFICACIÓN:
  SllPolynomial sllpsust13;                                                            // Se hace una operación de resta (-) entre los polinomios dispersos "sllp1 - sllp3".
  sllp1.Sust(sllp3, sllpsust13);
  cout << "sllp1 - sllp3 = " << sllpsust13;
  cout << endl;

  return 0;
}