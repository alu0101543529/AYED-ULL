/*
* AUTOR: Raúl González Acosta
* FECHA: 27/03/2023
* EMAIL: alu0101543529@ull.edu.es
* VERSION: 1.0
* ASIGNATURA: Algoritmos y Estructuras de Datos
* PRÁCTICA Nº: 4
*/ 

#ifndef SLLT_H_
#define SLLT_H_

#include <cassert>

#include "sll_node_t.h"

// Clase para almacenar una lista simplemente enlazada
/**
 * @brief Clase Sll_t
 * Clase para almacenar una lista simplemente enlazada.
 */
template <class T> 
class sll_t {
 public:
  //-----CONSTRUCTOR (POR DEFECTO)-----
  sll_t(void) : head_(NULL) {}

  //--DESTRUCTOR--
  ~sll_t(void);

  //-----GETTER-----
  /// Getter para obtener la primera posición (head) de una lista enlazada simple (sll)
  sll_node_t<T>* get_head(void) const { return head_; };
  
  /// Comprueba si una lista simple enlazada (sll) está vacía
  bool empty(void) const;

  //-------OPERACIONES-------

  /// Inserta un nodo después del primer nodo (head) de la lista simple enlazada (sll)
  void push_front(sll_node_t<T>*);

  /// Inserta un nodo al principio de la lista simple enlazada (sll), siendo este nuevo el primero (head)
  sll_node_t<T>* pop_front(void);

  /// Inserta un nodo al final de la lista simple enlazada (sll)
  void push_back(sll_node_t<T>*);

  /// Inserta un nodo después de un nodo determinado en la lista simple enlazada (sll)
  void insert_after(sll_node_t<T>*, sll_node_t<T>*);

  /// Elimina un nodo después de un nodo determinado en la lista simple enlazada (sll)
  sll_node_t<T>* erase_after(sll_node_t<T>*);

  /// Busca un nodo en la lista simple enlazada (sll)
  sll_node_t<T>* search(const T&) const;

  //------MÉTODOS I/O------
  /// Escribe el valor introducido en un nodo de la lista simple enlazada (sll)
  std::ostream& write(std::ostream& = std::cout) const;

 private:
  sll_node_t<T>* head_;
};

//----------MÉTODOS DE LA CLASE SLL-------------

/**
 * @brief Destruye un nodo de la lista simple enlazada (sll).
 */
template <class T> 
sll_t<T>::~sll_t(void) {
  while (!empty()) {
    sll_node_t<T>* aux = head_;
    head_ = head_->get_next();
    delete aux;
  }
}

/**
 * @brief Comprueba si la lista simple enlazada (sll) está vacía.
 * @return Devuelve true si está vacía, es decir, que head apunta a NULL.
 */
template <class T> 
bool sll_t<T>::empty(void) const {
  return head_ == NULL;
}

//-------OPERACIONES-------

/**
 * @brief Inserta un nodo después del primer nodo (head) de la lista simple enlazada (sll).
 * @param[in] n: nodo a insertar en la lista simple enlazada (sll).
 */
template <class T> 
void sll_t<T>::push_front(sll_node_t<T>* n) {
  assert(n != NULL);

  n->set_next(head_);
  head_ = n;
}

/**
 * @brief Inserta un nodo al principio de la lista simple enlazada (sll), siendo este nuevo el primero (head).
 * @return Devuelve el nodo insertado, es decir, el "nuevo" head.
 */
template <class T> 
sll_node_t<T>* sll_t<T>::pop_front(void) { 
  assert(!empty());
  sll_node_t<T>* aux = head_;
  head_ = head_->get_next();
  aux->set_next(NULL);

  return aux;
}

/**
 * @brief Inserta un nodo al final de la lista simple enlazada (sll), siendo el último valor insertado, el último nodo de la lista.
 * @return Devuelve el nodo insertado.
 */
template <class T>
void sll_t<T>::push_back(sll_node_t<T>* n) {
  assert(n != NULL);
  if (empty()) {
    n->set_next(head_);
    head_ = n;
    return;
  }
  sll_node_t<T> *aux = head_;
  while (aux->get_next() != NULL) {
    aux = aux->get_next();
  }
  aux->set_next(n);
}

/**
 * @brief Inserta un nodo después de un nodo determinado en la lista simple enlazada (sll).
 * @param[in] prev: nodo previo al que se va a insertar en la lista simple enlazada (sll).
 * @param[in] n: nodo a insertar en la lista simple enlazada (sll).
 */
template <class T> 
void sll_t<T>::insert_after(sll_node_t<T>* prev,
					                  sll_node_t<T>* n) {
  assert(prev != NULL && n != NULL);

  n->set_next(prev->get_next());
  prev->set_next(n);
}

/**
 * @brief Elimina un nodo después de un nodo determinado en la lista simple enlazada (sll)
 * @param[in] prev: nodo previo al que se va a eliminar en la lista simple enlazada (sll).
 * @return Devuelve el nodo previo al eliminado.
 */
template <class T> 
sll_node_t<T>* sll_t<T>::erase_after(sll_node_t<T>* prev) { 
  assert(!empty());
  assert(prev != NULL);
  sll_node_t<T>* aux = prev->get_next();
  
  assert(aux != NULL);
  prev->set_next(aux->get_next());
  aux->set_next(NULL);

  return aux;
}

/**
 * @brief Busca un nodo en la lista simple enlazada (sll).
 * @param[in] d: dato a buscar en los nodos de la lista simple enlazada (sll).
 * @return Devuelve el nodo que se está buscando en la lista simple enlazada (sll).
 */
template <class T> 
sll_node_t<T>* sll_t<T>::search(const T& d) const {
  sll_node_t<T>* aux = head_;
  while ((aux != NULL) && (aux->get_data() != d))
    aux = aux->get_next();
    
  return aux;
}

//------------OPERADORES I/O----------------

/**
 * @brief Escribe el valor introducido en un nodo de la lista simple enlazada (sll).
 * @param[in] os: referencia al objeto ostream (flujo de datos de salida).
 * @return: Devuelve la escritura en el nodo de la lista simple enlazada (sll) del valor del pair que representa el nodo (valor/índice).
 */
template <class T> 
std::ostream& sll_t<T>::write(std::ostream& os) const {
  sll_node_t<T>* aux = head_;

  while (aux != NULL) {
    aux->write(os);
    aux = aux->get_next();
  }
  return os;
}

#endif  // SLLT_H_