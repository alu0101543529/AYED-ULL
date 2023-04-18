/*
* AUTOR: Raúl González Acosta
* FECHA: 27/03/2023
* EMAIL: alu0101543529@ull.edu.es
* VERSION: 1.0
* ASIGNATURA: Algoritmos y Estructuras de Datos
* PRÁCTICA Nº: 4
*/

#ifndef SLL_NODET_H_
#define SLL_NODET_H_

#include <iostream>

/**
 * @brief Clase Sll_Node_t
 * Clase para nodos de listas enlazadas simples.
 */
template <class T> class sll_node_t {
 public:
  //-----CONSTRUCTOR (POR DEFECTO)-----
  sll_node_t(void) : data_(), next_(NULL) {}
  //-----CONSTRUCTOR (CON PARÁMETROS)-----
  sll_node_t(const T& data) : data_(data), next_(NULL) {}

  //--DESTRUCTOR--
  ~sll_node_t(void) {};

  //-----GETTERS-----
  /// Getter para obtener el siguiente nodo (sucesor).
  sll_node_t<T>* get_next(void) const { return next_; }
  /// Getter para obtener los valores del pair del nodo (valor/índice).
  const T& get_data(void) const { return data_; }

  //-----SETTERS-----
  /// Setter para establecer el siguiente nodo (sucesor).
  void set_next(sll_node_t<T>* next) { next_ = next; }
  /// Setter para estbalecer los valores del pair del nodo (valor/índice).
  void set_data(const T& data) { data_ = data; }

  //------MÉTODOS I/O------
  /// Imprimir nodo
  std::ostream& write(std::ostream& = std::cout) const;

 private:
  T data_;
  sll_node_t<T>* next_;
};


//------------OPERADORES I/O----------------

/**
 * @brief Imprime por pantalla el nodo.
 * @param[in] os: referencia al objeto ostream (flujo de datos de salida).
 * @return: Devuelve la salida por pantalla del valor del pair que representa el nodo (valor/índice).
 */
template <class T> 
std::ostream& sll_node_t<T>::write(std::ostream& os) const {
  os << data_;
  return os;
}

#endif  // SLL_NODET_H_