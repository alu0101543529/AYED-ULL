/*
* AUTOR: Raúl González Acosta
* FECHA: 17/04/2023
* EMAIL: alu0101543529@ull.edu.es
* VERSION: 1.0
* ASIGNATURA: Algoritmos y Estructuras de Datos
* PRÁCTICA Nº: 5
*/

#ifndef STACKL_H_
#define STACKL_H_

#include <iomanip>

#include "dll_t.h"

/**
 * @brief Clase Stack_l_t
 * Clase para pilas mediante estructura dinámica
 */
template <class T> 
class stack_l_t {
 public:	
  //-----CONSTRUCTOR (POR DEFECTO)-----
  stack_l_t(void) : l_() {}

  //--DESTRUCTOR--
  ~stack_l_t(void) {}

  //-------OPERACIONES-------

  // Inserta un elemento en una pila representada por una lista enlazada doble (dll)
  void push(const T&);
  // Saca un elemento de una pila representada por una lista enlazada doble (dll)
  void pop(void);
  // Obtiene el elemento superior de una pila representada por una lista enlazada doble (dll)
  const T& top(void) const;
  /// Comprueba si una pila está vacía
  bool empty(void) const;

  //------MÉTODOS I/O------
  /// Imprime por pantalla una pila representada por una lista enlazada doble (dll)
  std::ostream& write(std::ostream& os = std::cout) const;

 private:
  dll_t<T> l_;
};


//-------OPERACIONES-------

/**
 * @brief Inserta un nodo en una pila representada por una lista enlazada doble (dll), siendo este nuevo nodo insertado el elemento superior (top) de esta.
 * @param[in] dato: nodo a insertar en la pila representada por una lista enlazada doble (dll).
 */
template <class T> 
void stack_l_t<T>::push(const T& dato) {
  dll_node_t<T>* nodo = new dll_node_t<T>(dato);
  assert(nodo != NULL);
  l_.push_front(nodo);
}

/**
 * @brief Saca un nodo de una pila representada por una lista enlazada doble (dll).
 * @return Devuelve el nodo que saca de la pila.
 */
template <class T> 
void stack_l_t<T>::pop(void) {
  assert(!empty());
  delete l_.pop_front();
}

/**
 * @brief Obtiene el elemento superior de una pila representada por una lista enlazada doble (dll).
 * @return Devuelve los datos (pair "valor/índice") del elemento superior (top) de una pila representada por una lista enlazada doble (dll).
 */
template <class T> 
const T& stack_l_t<T>::top(void) const {
  assert(!empty());
  return l_.get_head()->get_data();
}

/**
 * @brief Comprueba si una pila representada por una lista enlazada doble (dll) está vacía.
 * @return Devuelve true si está vacía, es decir, que head apunta a NULL.
 */
template <class T> 
bool stack_l_t<T>::empty(void) const { return l_.empty(); }

//------------OPERADORES I/O----------------

/**
 * @brief Imprime por pantalla una pila representada por una lista enlazada doble (dll).
 * @param[in] os: referencia al objeto ostream (flujo de datos de salida).
 * @return: Devuelve la salida por pantalla del valor del pair (solo 2 dígitos) que representa el nodo (valor/índice) de los elementos de una pila.
 */
template <class T> 
std::ostream& stack_l_t<T>::write(std::ostream& os) const {
  dll_node_t<T>* aux = l_.get_head();
  while (aux != NULL) { 
    os << " │ " << std::setw(2) << aux->get_data() << "  │" << std::endl;
    aux = aux->get_next();
  }
  os << " └─────┘" << std::endl;
  return os;
}

#endif  // STACKL_H_
