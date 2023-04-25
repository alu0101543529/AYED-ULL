/*
* AUTOR: Raúl González Acosta
* FECHA: 17/04/2023
* EMAIL: alu0101543529@ull.edu.es
* VERSION: 1.0
* ASIGNATURA: Algoritmos y Estructuras de Datos
* PRÁCTICA Nº: 5
* COMENTARIOS: Clase RPN (Reverse Polish Notation)
*/

#ifndef RPNT_H_
#define RPNT_H_

#include <cctype>
#include <cmath>
//#include <cstdlib>

#include "queue_l_t.h"

/**
 * @brief Clase Rpn_t
 * Clase RPN (Reverse Polish Notation)
 */
template <class T> 
class rpn_t {
 public:
  //-----CONSTRUCTOR (POR DEFECTO)-----
  rpn_t(void) : stack_() {}

  //--DESTRUCTOR--
  ~rpn_t() {}

  //-------OPERACIONES-------

  // Evalua (si es un dígito o un operador) los elementos de una pila representada por una lista enlazada doble (dll)
  const int evaluate(queue_l_t<char>&);

 private: 
  T stack_;

  // Opera (si es un operador) los pertinenetes elementos de una pila representada por una lista enlazada doble (dll)
  void operate_(const char operador);
};


//-------OPERACIONES-------

/**
 * @brief Evalua (si es un dígito o un operador) los elementos de una cola representada por una lista enlazada doble (dll)
 * @param[in] q: cola (de caractéres) a evaluar, representada por una lista enlazada doble (dll).
 */
template <class T> 
const int rpn_t<T>::evaluate(queue_l_t<char>& q) {
  while (!q.empty()) 	{
    char c = q.front();
    
    q.pop();
    std::cout << "Sacamos de la cola un carácter: " << c;

    if (isdigit(c)) {
      int i = (c - '0');
      stack_.push(i);
      std::cout << " (es un dígito)\n   Lo metemos en la pila..." << std::endl;
    } else {
      std::cout << " (es un operador)" << std::endl;
      operate_(c);
    }
  }
  return stack_.top();
}

/**
 * @brief Opera (si es un dígito) los elementos de una pila representada por una lista enlazada doble (dll)
 * @param[in] c: caractér (operador) a operar de una cola representada por una lista enlazada doble (dll).
 */
template <class T> 
void rpn_t<T>::operate_(const char c) {
  assert(c == '+' || c == '-' || c == '*' || c == '/' || c == '^' || c == 'r' || c == 'l' || c == 'c' || c == '>');

  int a, b = stack_.top();
  std::cout << "   Sacamos de la pila un operando: " << b << std::endl;
  stack_.pop();

  if (c != 'r' && c != 'l' && c != 'c') {    // Operadores de aridad 1 (unarios)
    a = stack_.top();
    std::cout << "   Sacamos de la pila otro operando: " << a << std::endl;
    stack_.pop();
  }
  
  switch (c) {
    case '+': {
      stack_.push(a + b);
      break;
    }

    case '-': {
      stack_.push(a - b);
      break;
    }

    case '*': {
      stack_.push(a * b);
      break;
    }

    case '/': {
      stack_.push(a / b);
      break;
    }

    case '^': {
      stack_.push(pow(a, b));
      break;
    } 

    case 'r': {
      stack_.push(sqrt(b));
      break;
    }

    case 'l': {
      stack_.push(log2(b));
      break;
    }

    case 'c': {
      stack_.push(pow(b, 2));
      break;
    }

    // MODIFICACIÓN
    case '>': {
      if (a > b) {
        stack_.push(a);
        break;
      }
      else {
        stack_.push(b);
        break;
      }
    }
  }

  std::cout << "   Metemos en la pila el resultado: " << stack_.top() << std::endl;
}

#endif  // RPNT_H_