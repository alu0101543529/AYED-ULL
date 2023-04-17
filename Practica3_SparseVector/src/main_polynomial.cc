/*
* AUTOR: Raúl González Acosta
* FECHA: 13/03/2023
* EMAIL: alu0101543529@ull.edu.es
* VERSION: 1.0
* ASIGNATURA: Algoritmos y Estructuras de Datos
* PRÁCTICA Nº: 3
* COMPILACIÓN: g++ -g main_polynomial.cc -o main_polynomial
* EJECUCIÓN: ./main_polynomial < data_polynomial.txt
*/

#include "header_files/polynomial.h"

using namespace std;

int main () {
  Polynomial p1, p2, p3;
  
  cin >> p1 >> p2 >> p3;                                                        // Se leen los polinomio de la forma: tamaño, valores.
  cout << "p1= " << p1;                                                         // Se imprimen los polinimios densos (con ceros) evaluados.
  cout << "p2= " << p2;
  cout << "p3= " << p3;
  cout << endl;

  // FASE II

    //--CONVERSIÓN DE VECTORES DENSOS A DISPERSOS (SPARSE)--

  SparsePolynomial sp1(p1), sp2(p2), sp3(p3);                                 // Los polinomios densos se convierten en polinomios dispersos (sin ceros)
  cout << "sp1= " << sp1;                                                     // Se imprimen los polinomios evaluados, de la forma: tamaño del vector denso, (tamaño del vector disperso), valores.
  cout << "sp2= " << sp2;
  cout << "sp3= " << sp3;
  cout << endl;

  // FASE III

    //--------EVALUACIÓN DE POLINOMIOS DENSOS--------

  double x1, x2, x3;
  cin >> x1 >> x2 >> x3;                                                      // Se leen los valores por los que se van a evaluar los polinomios.
  cout << "p1(" << x1 << ")= " << p1.Eval(x1) << endl;                        // Se evaluan los tres polinomios densos por los valores introducidos, y se imprime el valor por pantalla.
  cout << "p1(" << x2 << ")= " << p1.Eval(x2) << endl;
  cout << "p1(" << x3 << ")= " << p1.Eval(x3) << endl;
  cout << "p2(" << x1 << ")= " << p2.Eval(x1) << endl;
  cout << "p2(" << x2 << ")= " << p2.Eval(x2) << endl;
  cout << "p2(" << x3 << ")= " << p2.Eval(x3) << endl;
  cout << "p3(" << x1 << ")= " << p3.Eval(x1) << endl;
  cout << "p3(" << x2 << ")= " << p3.Eval(x2) << endl;
  cout << "p3(" << x3 << ")= " << p3.Eval(x3) << endl;
  cout << endl;

    //--------EVALUACIÓN DE POLINOMIOS DISPERSOS--------

  cout << "sp1(" << x1 << ")= " << sp1.Eval(x1) << endl;                      // Se evaluan los tres polinomios dispersos por los valores introducidos, y se imprime el valor por pantalla.
  cout << "sp1(" << x2 << ")= " << sp1.Eval(x2) << endl;
  cout << "sp1(" << x3 << ")= " << sp1.Eval(x3) << endl;
  cout << "sp2(" << x1 << ")= " << sp2.Eval(x1) << endl;
  cout << "sp2(" << x2 << ")= " << sp2.Eval(x2) << endl;
  cout << "sp2(" << x3 << ")= " << sp2.Eval(x3) << endl;
  cout << "sp3(" << x1 << ")= " << sp3.Eval(x1) << endl;
  cout << "sp3(" << x2 << ")= " << sp3.Eval(x2) << endl;
  cout << "sp3(" << x3 << ")= " << sp3.Eval(x3) << endl;
  cout << endl;

  // FASE IV

    //--------COMPARACIONES DE IGUALDAD DE POLINOMIOS DENSOS--------
  
  cout << "p1 == p1? " << (p1.IsEqual(p1) ? "true" : "false") << endl;         // Se hace una comparación de igualdad (==) entre los polinomios densos (en todos sus posibles casos).
  cout << "p2 == p2? " << (p2.IsEqual(p2) ? "true" : "false") << endl;
  cout << "p3 == p3? " << (p3.IsEqual(p3) ? "true" : "false") << endl;
  cout << "p1 == p2? " << (p1.IsEqual(p2) ? "true" : "false") << endl;
  cout << "p2 == p1? " << (p2.IsEqual(p1) ? "true" : "false") << endl;
  cout << "p1 == p3? " << (p1.IsEqual(p3) ? "true" : "false") << endl;
  cout << "p3 == p1? " << (p3.IsEqual(p1) ? "true" : "false") << endl;
  cout << "p2 == p3? " << (p2.IsEqual(p3) ? "true" : "false") << endl;
  cout << "p3 == p2? " << (p3.IsEqual(p2) ? "true" : "false") << endl;
  cout << endl;

    //----------COMPARACIONES DE IGUALDAD DE POLINOMIOS DISPERSOS----------

  cout << "sp1 == sp1? " << (sp1.IsEqual(sp1) ? "true" : "false") << endl;    // Se hace una comparación de igualdad (==) entre los polinomios dispersos (en todos sus posibles casos).
  cout << "sp2 == sp2? " << (sp2.IsEqual(sp2) ? "true" : "false") << endl;
  cout << "sp3 == sp3? " << (sp3.IsEqual(sp3) ? "true" : "false") << endl;
  cout << "sp1 == sp2? " << (sp1.IsEqual(sp2) ? "true" : "false") << endl;
  cout << "sp2 == sp1? " << (sp2.IsEqual(sp1) ? "true" : "false") << endl;
  cout << "sp1 == sp3? " << (sp1.IsEqual(sp3) ? "true" : "false") << endl;
  cout << "sp3 == sp1? " << (sp3.IsEqual(sp1) ? "true" : "false") << endl;
  cout << "sp2 == sp3? " << (sp2.IsEqual(sp3) ? "true" : "false") << endl;
  cout << "sp3 == sp2? " << (sp3.IsEqual(sp2) ? "true" : "false") << endl;
  cout << endl;

    //---COMPARACIONES DE IGUALDAD DE POLINOMIOS DISPERSOS CON POLINOMIOS DENSOS---

  cout << "sp1 == p1? " << (sp1.IsEqual(p1) ? "true" : "false") << endl;      // Se hace una comparación de igualdad (==) entre los polinomios, tanto dispersos como densos (en todos sus posibles casos).
  cout << "sp2 == p2? " << (sp2.IsEqual(p2) ? "true" : "false") << endl;
  cout << "sp3 == p3? " << (sp3.IsEqual(p3) ? "true" : "false") << endl;
  cout << "sp1 == p2? " << (sp1.IsEqual(p2) ? "true" : "false") << endl;
  cout << "sp2 == p1? " << (sp2.IsEqual(p1) ? "true" : "false") << endl;
  cout << "sp1 == p3? " << (sp1.IsEqual(p3) ? "true" : "false") << endl;
  cout << "sp3 == p1? " << (sp3.IsEqual(p1) ? "true" : "false") << endl;
  cout << "sp2 == p3? " << (sp2.IsEqual(p3) ? "true" : "false") << endl;
  cout << "sp3 == p2? " << (sp3.IsEqual(p2) ? "true" : "false") << endl;
  cout << endl;

    //---MODIFICACIÓN-----
  (sp1.CoeficientePar(sp1));
  (sp2.CoeficientePar(sp2));
  (sp3.CoeficientePar(sp3));

  return 0;
}
