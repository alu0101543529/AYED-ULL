/*
* AUTOR: Raúl González Acosta
* FECHA: 13/03/2023
* EMAIL: alu0101543529@ull.edu.es
* VERSION: 1.0
* ASIGNATURA: Algoritmos y Estructuras de Datos
* PRÁCTICA Nº: 3
*/

#ifndef PAIRT_H_
#define PAIRT_H_

#include <iostream>


template<class T> 

/**
 * @brief Clase Pair_t
 */
class pair_t {
 public:
  //-----CONSTRUCTOR (POR DEFECTO)-----
  pair_t(void);
  //-----CONSTRUCTOR (CON PARÁMETROS)-----
  pair_t(T, int);

  //--DESTRUCTOR--
  ~pair_t(void);

  //-----GETTERS-----

  /// Getter para obtener el valor (first) de un pair en el vector escaso.
  T get_val(void) const;
  /// Getter para obtener el índice (second) de un pair en el vector escaso.
  int get_inx(void) const;

  //-----SETTERS-----
  void set(T, int);

  //------MÉTODOS I/O------

  /// Lectura de pair
  std::istream& read(std::istream& is = std::cin);
  /// Imprimir pair
  std::ostream& write(std::ostream& os = std::cout) const;

 private:
  T val_;     // Valor del pair (first): puede ser cualquier tipo, genérico T
  int inx_;   // Índice del pair (second)
};

//----------MÉTODOS DE LA CLASE PAIR-------------

/**
 * @brief Construye un pair por defecto.
 */
template <class T> 
pair_t<T>::pair_t() : val_(), inx_(-1) {}

/**
 * @brief Crea un pair con los valores solicitados.
 * @param[in] val: valor del pair (first).
 * @param[in] inx: índice del pair (second).
 */
template <class T> 
pair_t<T>::pair_t(T val, int inx) : val_(val), inx_(inx) {}

/**
 * @brief Destruye un pair.
 */
template <class T> 
pair_t<T>::~pair_t() {}

/**
 * @brief Establece los valores del pair ("setter").
 * @param[in] val: valor del pair (first).
 * @param[in] inx: índice del pair (second).
 */
template <class T> 
void pair_t<T>::set(T val, int inx) {
  val_ = val;
  inx_ = inx;
}

/**
 * @brief Obtiene el índice de un pair ("second").
 * @return Devuelve el índice de un pair ("second").
 */
template <class T> 
int pair_t<T>::get_inx() const {
  return inx_;
}

/**
 * @brief Obtiene el valor de un pair ("first").
 * @return Devuelve el valor de un pair ("first").
 */
template <class T> 
T pair_t<T>::get_val() const {
  return val_;
}

//------------OPERADORES I/O----------------

/**
 * @brief Lee por pantalla los valores de un pair. 
 * @param[in] is: referencia al objeto istream (flujo de datos de entrada).
 * @return: Devuelve la entrada del pair (de la forma: índice/valor).
 */
template <class T> 
std::istream& pair_t<T>::read(std::istream& is) {
  return is >> inx_ >> val_;
}

/**
 * @brief Imprime por pantalla el pair.
 * @param[in] os: referencia al objeto ostream (flujo de datos de salida).
 * @return: Devuelve la salida por pantalla del pair (de la forma: "(índice:valor)").
 */
template <class T> 
std::ostream& pair_t<T>::write(std::ostream& os) const {
  return os << "(" << inx_ << ":" << val_ << ")";
}

/**
 * @brief sobrecarga del operador de flujo de salida (<<).
 * @param[in] os: referencia al objeto ostream (flujo de datos de salida).
 * @param[in] p: referencia (constante) al pair p.
 * @return Devuelve la sobrecarga del operador de flujo de salida (<<) para el método write().
 */
template <class T> 
std::ostream& operator << (std::ostream& os, const pair_t<T>& p) {
  p.write(os);
  return os;
}

#endif  // PAIRT_H_
