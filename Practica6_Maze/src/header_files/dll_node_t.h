/*
* AUTOR: Raúl González Acosta
* FECHA: 01/05/2023
* EMAIL: alu0101543529@ull.edu.es
* VERSION: 1.0
* ASIGNATURA: Algoritmos y Estructuras de Datos
* PRÁCTICA Nº: 6 (REUSADA DE LA PRÁCTICA Nº: 5)
*/

#ifndef DLL_NODET_H_
#define DLL_NODET_H_

#include <iostream>

/**
 * @brief Clase Dll_node_t
 * Clase para nodos de listas doblemente enlazadas
 */
template <class T> 
class dll_node_t {
 public:
  //-----CONSTRUCTOR (POR DEFECTO)-----
  dll_node_t() : prev_(NULL), data_(), next_(NULL) {}
  //-----CONSTRUCTOR (CON PARÁMETROS)-----
  dll_node_t(const T& data) : prev_(NULL), data_(data), next_(NULL) {}

  //--DESTRUCTOR--
  ~dll_node_t(void) {}

  //-----GETTERS-----
  /// Getter para obtener la siguiente posición (next) de una lista enlazada doble (dll)
  dll_node_t<T>* get_next(void) const { return next_; }
  /// Getter para obtener la posición previa (prev) de una lista enlazada doble (dll)
  dll_node_t<T>* get_prev(void) const { return prev_; }
  /// Getter para obtener los valores del pair del nodo (first/second).
  const T& get_data(void) const { return data_; }
  
  //-----SETTERS-----
  /// Setter para establecer el valor de la siguiente posición (next) de una lista enlazada doble (dll)
  void set_next(dll_node_t<T>* next) { next_ = next; }
  /// Setter para establecer el valor de la posición previa (prev) de una lista enlazada doble (dll)
  void set_prev(dll_node_t<T>* prev) { prev_ = prev; }
  /// Setter para establecer los valores del pair del nodo (first/second).
  void set_data(const T& data) { data_ = data; }
  
  //------MÉTODOS I/O------
  /// Imprimir nodo
  std::ostream& write(std::ostream& = std::cout) const;

 private:
  dll_node_t<T>* next_;
  dll_node_t<T>* prev_;
  T data_;
};

  
//------------OPERADORES I/O----------------

/**
 * @brief Imprime por pantalla el nodo.
 * @param[in] os: referencia al objeto ostream (flujo de datos de salida).
 * @return: Devuelve la salida por pantalla del valor del pair que representa el nodo (valor/índice).
 */
template <class T> 
std::ostream& dll_node_t<T>::write(std::ostream& os) const {
  os << data_;
  return os;
}

#endif  // DLL_NODET_H_
