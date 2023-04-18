/*
* AUTOR: Raúl González Acosta
* FECHA: 17/04/2023
* EMAIL: alu0101543529@ull.edu.es
* VERSION: 1.0
* ASIGNATURA: Algoritmos y Estructuras de Datos
* PRÁCTICA Nº: 5
* COMENTARIOS: Clase TAD cola implementada con una lista
*/

#ifndef QUEUE_H_
#define QUEUE_H_

#include "dll_t.h"

/**
 * @brief Clase Queue_l_t
 * Clase TAD cola implementada con una lista doblemmete enlazada (dll).
 */
template <class T> 
class queue_l_t {
 public:
  // CONSTRUCTOR (POR DEFECTO)
  queue_l_t(void) : l_() {}

  //--DESTRUCTOR--
  ~queue_l_t(void) {}

  //-------OPERACIONES-------

  /// Comprueba si una cola está vacía
  bool empty(void) const;
  /// Getter para obtener el tamaño de una cola representada por una lista enlazada doble (dll)
  int size(void) const;
  // Inserta un elemento en una cola representada por una lista enlazada doble (dll)
  void push(const T& dato);
  // Saca un elemento de una cola representada por una lista enlazada doble (dll)
  void pop(void);
  // Obtiene el primer elemento de una cola representada por una lista enlazada doble (dll)
  const T& front(void) const;
  // Obtiene el último elemento de una cola representada por una lista enlazada doble (dll)
  const T& back(void) const;

  //------MÉTODOS I/O------
  /// Imprime por pantalla una cola representada por una lista enlazada doble (dll)
  std::ostream& write(std::ostream& os = std::cout) const;
 
 private:
  dll_t<T> l_;
};


//-------OPERACIONES-------

/**
 * @brief Comprueba si una cola representada por una lista enlazada doble (dll) está vacía.
 * @return Devuelve true si está vacía, es decir, que head apunta a NULL.
 */
template <class T> 
bool queue_l_t<T>::empty(void) const { return l_.empty(); }

/**
 * @brief Determina el tamaño de una cola representada por una lista enlazada doble (dll).
 * @return Devuelve el tamaño de una cola representada por una lista enlazada doble (dll)..
 */
template <class T> 
int queue_l_t<T>::size(void) const { return l_.get_size(); }

/**
 * @brief Inserta un nodo en una cola representada por una lista enlazada doble (dll), siendo este nuevo nodo insertado el último elemento de esta.
 * @param[in] dato: nodo a insertar en la cola representada por una lista enlazada doble (dll).
 */
template <class T> 
void queue_l_t<T>::push(const T& dato) {
  dll_node_t<T>* node = new dll_node_t<T>(dato);
  assert(node != NULL);
  l_.push_front(node);
}

/**
 * @brief Saca un nodo de una cola representada por una lista enlazada doble (dll).
 * @return Devuelve el nodo que saca de la cola.
 */
template <class T> 
void queue_l_t<T>::pop(void) {
  assert(!empty());
  delete l_.pop_back();
}

/**
 * @brief Obtiene el primer elemento de una cola representada por una lista enlazada doble (dll).
 * @return Devuelve los datos (pair "valor/índice") del primer nodo de una cola representada por una lista enlazada doble (dll).
 */
template <class T> 
const T& queue_l_t<T>::front(void) const {
  assert(!empty());
  return (l_.get_tail()->get_data());
}

/**
 * @brief Obtiene el último elemento de una cola representada por una lista enlazada doble (dll).
 * @return Devuelve los datos (pair "valor/índice") del último nodo de una cola representada por una lista enlazada doble (dll).
 */
template <class T> 
const T& queue_l_t<T>::back(void) const {
  assert(!empty());
  return (l_.get_head()->get_data());
}

//------------OPERADORES I/O----------------

/**
 * @brief Imprime por pantalla una cola representada por una lista enlazada doble (dll).
 * @param[in] os: referencia al objeto ostream (flujo de datos de salida).
 * @return: Devuelve la salida por pantalla del valor del pair que representa el nodo (valor/índice) de los elementos de una cola.
 */
template <class T> 
std::ostream& queue_l_t<T>::write(std::ostream& os) const {
  dll_node_t<T>* aux = l_.get_head();
  while (aux != NULL) {
    os << aux->get_data() << " ";
    aux = aux->get_next();
  }
  os << std::endl;
  return os;
}

/**
 * @brief sobrecarga del operador de flujo de salida (<<).
 * @param[in] os: referencia al objeto ostream (flujo de datos de salida).
 * @param[in] p: referencia (constante) a la cola q.
 * @return Devuelve la sobrecarga del operador de flujo de salida (<<) para el método write().
 */
template <class T> 
std::ostream& operator << (std::ostream& os, const queue_l_t<T>& q) {
  q.write(os);
  return os;
}

#endif  // QUEUE_H_
