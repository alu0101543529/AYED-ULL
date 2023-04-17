/*
* AUTOR: Raúl González Acosta
* FECHA: 27/02/2023
* EMAIL: alu0101543529@ull.edu.es
* VERSION: 1.0
* ASIGNATURA: Algoritmos y Estructuras de Datos
* PRÁCTICA Nº: 2
*/

#ifndef MATRIX_T
#define MATRIX_T

#include "vector_t.hpp"

using namespace std;

template <class T>

/**
 * @brief Clase Matrix_t
 */
class matrix_t {
  public:
  //-----CONSTRUCTOR (POR DEFECTO)-----
  matrix_t(const int = 0, const int = 0);

  //--DESTRUCTOR--
  ~matrix_t();
  
  //---MÉTODO PARA REDIMENSIONAR---
  void resize (const int, const int);
  
  //-----GETTERS-----
  int get_m (void) const;  // Getter para las filas
  int get_n (void) const;  // Getter para las columnas
  
  /// Getter para obtener la posición de un elemento en la matriz
  T& at (const int, const int);

  /// Sobrecarga del operador de indexación ("()")
  T& operator () (const int, const int);
  
  //-----GETTERS CONSTANTES-----
  const T& at (const int, const int) const;
  const T& operator () (const int, const int) const;
  
  //------OPERACIONES ARITMÉTICAS CON MATRICES------

  /// Multiplicación de matrices
  void multiply (const matrix_t<T>&, const matrix_t<T>&);

  //------MÉTODOS I/O------

  /// Imprimir matrices
  void write (ostream& = cout) const;

  /// Lectura de matrices
  void read (istream& = cin);

  private:
  int m_, n_; // ATRIBUTOS (m_ -> filas; n_ -> columnas)
  vector_t <T> v_;       // v_ -> vector 
  
  int pos(const int, const int) const; // Atributo de posición en una matriz
};

//----------MÉTODOS DE LA CLASE MATRIX-------------

/**
 * @brief Crea una matriz (vector de dimensiones m * n).
 * @param[in] m: número de filas de la matriz.
 * @param[in] n: número de columnas de la matriz.
 */
template <class T> 
matrix_t <T>::matrix_t (const int m, const int n) { 
  m_ = m;
  n_ = n;
  v_.resize (m_ * n_);
}

/**
 * @brief Destructor de la clase Matrix.
 */
template <class T> 
matrix_t<T>::~matrix_t() {}

/**
 * @brief Redimensiona la matriz.
 * @param[in] m: número de filas de la matriz.
 * @param[in] n: número de columnas de la matriz.
 */
template <class T>
void matrix_t<T>::resize (const int m, const int n) {
  assert(m > 0 && n > 0);   // Comprueba que el número de filas y columnas es > 0
  m_ = m;
  n_ = n;
  v_.resize (m_ * n_);
}

/**
 * @brief Getter del atributo designado al número de filas.
 * @return número de filas de la matriz.
 */
template <class T>
inline int matrix_t<T>::get_m() const { return m_; }

/**
 * @brief Getter del atributo designado al número de columnas.
 * @return número de columnas de la matriz.
 */
template <class T>
inline int matrix_t<T>::get_n() const { return n_; }

/**
 * @brief Obtiene la posición de un elemento específico en la matriz dentro del vector que la representa.
 * @param[in] i: número de fila en la que se encuentra el elemento dentro de la matriz.
 * @param[in] j: número de columna en la que se encuentra el elemento dentro de la matriz.
 * @return Devuelve la posición dentro del vector del elemento de la matriz.
 */
template <class T>
T& matrix_t<T>::at (const int i, const int j) {
  assert(i > 0 && i <= get_m());    // Se asegura que el número de fila introducido es > 0, pero <= que el número máximo de filas que tiene la matriz.
  assert(j > 0 && j <= get_n());    // Se asegura que el número de columna introducido es > 0, pero <= que el número máximo de columnas que tiene la matriz.
  return v_[pos(i, j)];
}

/**
 * @brief sobrecarga del operador de indexación ("()") para la clase matrix_t.
 * @param[in] i: número de fila en la que se encuentra el elemento dentro de la matriz.
 * @param[in] j: número de columna en la que se encuentra el elemento dentro de la matriz.
 * @return Devuelve la sobrecarga del operador de indexación ("()") para el método at de la clase matrix_t.
 */
template <class T>
T& matrix_t<T>::operator () (const int i, const int j) { return at(i, j); }


template <class T>
const T& matrix_t<T>::at (const int i, const int j) const {
  assert(i > 0 && i <= get_m());
  assert(j > 0 && j <= get_n());
  return v_[pos(i, j)];
}


template <class T>
const T& matrix_t<T>::operator () (const int i, const int j) const { return at(i, j); }

//------------OPERADORES I/O----------------

/**
 * @brief Muestra por pantalla la dimensión de la matriz.
 * @param[in] os: referencia al objeto ostream (flujo de datos de salida).
 */
template <class T>
void matrix_t<T>::write (ostream& os) const { 
  os << get_m() << "x" << get_n() << endl;
  for (int i = 1; i <= get_m(); ++i) {
    for (int j = 1; j <= get_n(); ++j)
      os << at(i, j) << "\t";
    os << endl;
  }
  os << endl;
}

/**
 * @brief Introduce la dimensión de una matriz introducida por el usuario.
 * @param[in] is: referencia al objeto istream (flujo de datos de entrada).
 */
template <class T>
void matrix_t<T>::read (istream& is) {
  is >> m_ >> n_;
  resize(m_, n_);
  for (int i = 1; i <= get_m(); ++i)
    for (int j = 1; j <= get_n(); ++j)
      is >> at(i, j);
}

/**
 * @brief Obtiene la posición de un elemento específico de la matriz.
 * @param[in] i: referencia al número de fila en la que se encuentra el elemento dentro de la matriz.
 * @param[in] j: referencia al número de columna en la que se encuentra el elemento dentro de la matriz.
 * @return Devuelve la posición dentro del vector del elemento de la matriz que la representa.
 */
template <class T>
inline int matrix_t<T>::pos (const int i, const int j) const {
  assert(i > 0 && i <= get_m());
  assert(j > 0 && j <= get_n());
  return (i - 1) * get_n() + (j - 1);
}


// FASE III: PRODUCTO MATRICIAL

/**
 * @brief Hace el producto de dos matrices.
 * @param[in] A: referencia (constante) a la matriz A.
 * @param[in] B: referencia (constante) a la matriz B.
 */

template <class T> 
void matrix_t<T>::multiply (const matrix_t<T>& A, const matrix_t<T>& B) {
  assert (A.get_n() == B.get_m());
  resize(A.get_m(), B.get_n());
  for (int i = 1; i <= A.get_m(); i++) {
    for (int j = 1; j <= B.get_n(); j++) {
      at(i,j) = 0;
      for (int k = 1; k <= A.get_n(); k++) {
        at(i, j) = at(i, j) + (A (i, k) * B (k, j));
      }
    }
  }  
}

#endif