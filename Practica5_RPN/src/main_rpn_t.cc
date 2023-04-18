/*
* AUTOR: Raúl González Acosta
* FECHA: 17/04/2023
* EMAIL: alu0101543529@ull.edu.es
* VERSION: 1.0
* ASIGNATURA: Algoritmos y Estructuras de Datos
* PRÁCTICA Nº: 5
* COMENTARIOS: Programa principal para probar la calculadora de expresiones en notación polaca inversa (RPN, Reverse Polish Notation)
* COMPILACIÓN: g++ src/main_rpn_t.cc -o main_rpn_t
* EJECUCIÓN:
            ./main_rpn_t < data/data_rpn_t_1.txt
            ./main_rpn_t < data/data_rpn_t_2.txt
            ./main_rpn_t < data/data_rpn_t_3.txt
*/

#include "header_files/stack_l_t.h"
#include "header_files/queue_l_t.h"
#include "header_files/rpn_t.h"

using namespace std;

int main() {
  rpn_t<stack_l_t<int>> calculadora;
  queue_l_t<char> cola;
	
  while (!cin.eof()) 	{
    cin >> ws;            // Lee los espacios en blanco, que dan problemas
    if (!cin.eof()) {
      char c;
      cin >> c;
      cola.push(c);
    }
  }

  cout << "Expresión a evaluar: ";	
  cola.write();

  int r = calculadora.evaluate(cola);
  cout << "Resultado: " << r << endl;

  return 0;
}