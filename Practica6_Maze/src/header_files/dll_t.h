/*
* AUTOR: Raúl González Acosta
* FECHA: 01/05/2023
* EMAIL: alu0101543529@ull.edu.es
* VERSION: 1.0
* ASIGNATURA: Algoritmos y Estructuras de Datos
* PRÁCTICA Nº: 6 (REUSADA DE LA PRÁCTICA Nº: 5)
*/

#ifndef DLLT_H_
#define DLLT_H_

#include <cassert>

#include "dll_node_t.h"

/**
 * @brief Clase Dll_t
 * Clase para almacenar una lista doblemente enlazada (dll).
 */
template 
<class T> class dll_t {
 public:
  //-----CONSTRUCTOR (POR DEFECTO)-----
  dll_t(void) : head_(NULL), tail_(NULL), sz_(0) {}

  //--DESTRUCTOR--
  ~dll_t(void); 

  //-----GETTERS-----
  /// Getter para obtener la primera posición (head) de una lista enlazada doble (dll)
  dll_node_t<T>* get_head(void) const { return head_; }
  /// Getter para obtener la última posición (tail) de una lista enlazada doble (dll)
  dll_node_t<T>* get_tail(void) const { return tail_; }
  // Getter para obtener el tamaño (size) de una lista enlazada doble (dll)
  int get_size(void) const { return sz_; }

  /// Comprueba si una lista enlazada doble (dll) está vacía
  bool empty(void) const;

  //-------OPERACIONES-------

  // Inserta un nodo después del primer nodo (head) de la lista enlazada doble (dll)
  void push_front(dll_node_t<T>*);

  /// Inserta un nodo antes del último nodo (tail) de la lista enlazada doble (dll).
  void push_back(dll_node_t<T>*);

  /// Inserta un nodo al principio de la lista enlazada doble (dll), siendo este nuevo el primero (head)
  dll_node_t<T>* pop_front(void);
  
  /// Inserta un nodo al final de la lista enlazada doble (dll), siendo este nuevo el último (tail)
  dll_node_t<T>* pop_back(void);

  /// Elimina un nodo de la lista enlazada doble (dll)
  dll_node_t<T>* erase(dll_node_t<T>*);

  //------MÉTODOS I/O------
  /// Escribe el valor introducido en un nodo de la lista enlazada doble (dll)
  std::ostream& write(std::ostream& = std::cout) const;

 private:
  dll_node_t<T>* head_;
  dll_node_t<T>* tail_;
  int            sz_;
};

//----------MÉTODOS DE LA CLASE DLL-------------

/**
 * @brief Destruye un nodo de la lista enlazada doble (dll).
 */
template <class T> 
dll_t<T>::~dll_t(void) {
  while (head_ != NULL) {
    dll_node_t<T>* aux = head_;
    head_ = head_->get_next();
    delete aux;
  }
  sz_ = 0;
  tail_ = NULL;
}

/**
 * @brief Comprueba si la lista enlazada doble (dll) está vacía.
 * @return Devuelve true si está vacía, es decir, que head apunta a NULL.
 */
template <class T> 
bool dll_t<T>::empty(void) const {
  if (head_ == NULL) {
    assert(tail_ == NULL);
    assert(sz_ == 0);
    return true;
  } 
  else {return false;}
}

//-------OPERACIONES-------

/**
 * @brief Inserta un nodo después del primer nodo (head) de la lista enlazada doble (dll).
 * @param[in] nodo: nodo a insertar en la lista enlazada doble (dll).
 */
template <class T> 
void dll_t<T>::push_front(dll_node_t<T>* nodo) {
  assert(nodo != NULL);

  if (empty()) {
    head_ = nodo;
    tail_ = head_;
  } else {
    head_->set_prev(nodo);
    nodo->set_next(head_);
    head_ = nodo;
  }

  sz_++;
}

/**
 * @brief Inserta un nodo antes del último nodo (tail) de la lista enlazada doble (dll).
 * @param[in] nodo: nodo a insertar en la lista enlazada doble (dll).
 */
template <class T> 
void dll_t<T>::push_back(dll_node_t<T>* nodo) {
  assert(nodo != NULL);

  if (empty()) {
    head_ = nodo;
    tail_ = head_;
  } else {
    tail_->set_next(nodo);
    nodo->set_prev(tail_);
    tail_ = nodo;
  }

  sz_++;
}


/**
 * @brief Inserta un nodo al principio, es decir, este nuevo nodo pasa a ser el primer nodo (head) de la lista enlazada doble (dll).
 * @return Devuelve el nodo insertado, es decir, el "nuevo" head.
 */
template <class T> 
dll_node_t<T>* dll_t<T>::pop_front(void) {
  assert(!empty());

  dll_node_t<T>* aux = head_;
  head_ = head_->get_next();

  if (head_ != NULL) { head_->set_prev(NULL); }
  else { tail_ = NULL; }

  sz_--;
  aux->set_next(NULL);
  aux->set_prev(NULL);
  return aux;
}

/**
 * @brief Inserta un nodo al final, es decir, este nuevo nodo pasa a ser el último nodo (tail) de la lista enlazada doble (dll).
 * @return Devuelve el nodo insertado, es decir, el "nuevo" tail.
 */
template <class T> 
dll_node_t<T>* dll_t<T>::pop_back(void) {
  assert(!empty());

  dll_node_t<T>* aux = tail_;
  tail_ = tail_->get_prev();

  if (tail_ != NULL) { tail_->set_next(NULL); }
  else { head_ = NULL; }

  sz_--;
  aux->set_next(NULL);
  aux->set_prev(NULL);
  return aux;
}

/**
 * @brief Elimina un nodo de la lista enlazada doble (dll)
 * @param[in] nodo: nodo a eliminar en la lista enlazada doble (dll).
 * @return Devuelve el nodo eliminado.
 */
template <class T> 
dll_node_t<T>* dll_t<T>::erase(dll_node_t<T>* nodo) {
  assert(nodo != NULL);

  if (nodo->get_prev() != NULL) { nodo->get_prev()->set_next(nodo->get_next()); }
  else { head_ = nodo->get_next(); }

  if (nodo->get_next() != NULL) { nodo->get_next()->set_prev(nodo->get_prev()); }
  else { tail_ = nodo->get_prev(); }

  sz_--;
  nodo->set_prev(NULL);
  nodo->set_next(NULL);
  return nodo;
}

//------------OPERADORES I/O----------------

/**
 * @brief Escribe el valor introducido en un nodo de la lista enlazada doble (dll).
 * @param[in] os: referencia al objeto ostream (flujo de datos de salida).
 * @return: Devuelve la escritura en el nodo de la lista enlazada doble (dll) del valor del pair que representa el nodo (valor/índice).
 */
template <class T> 
std::ostream& dll_t<T>::write(std::ostream& os) const {
  dll_node_t<T>* aux = head_;

  while (aux != NULL) {
    aux->write(os);
    aux = aux->get_next();
  }
  return os;
}

#endif  // DLLT_H_