/*
* AUTOR: Raúl González Acosta
* FECHA: 01/05/2023
* EMAIL: alu0101543529@ull.edu.es
* VERSION: 1.0
* ASIGNATURA: Algoritmos y Estructuras de Datos
* PRÁCTICA Nº: 6
*/

#ifndef MATRIX_T
#define MATRIX_T

#include "vector_t.hpp"

using namespace std;

/**
* @brief Namespace AED
*/
namespace AED {

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
    vector_t<T> get_row(const int) const; // Getter de una fila completa
    vector_t<T> get_col(const int) const; // Getter de una columna completa
    
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
   * @brief Getter de una fila completa de la matriz.
   * @return Devuelve los elementos de una fila completa de la matriz.
   */
  template <class T>
  vector_t<T> matrix_t<T>::get_row(const int i) const {
    assert(i > 0 && i <= get_m());
    vector_t<T> v(get_n());
    for (int j = 1; j <= get_n(); ++j) {
      v[j - 1] = at(i, j);
    }
    return v;
  }

  /**
   * @brief Getter de una columna completa de la matriz.
   * @return Devuelve los elementos de una columna completa de la matriz.
   */
  template <class T>
  vector_t<T> matrix_t<T>::get_col(const int j) const {
    assert(j > 0 && j <= get_n());
    vector_t<T> v(get_m());
    for (int i = 1; i <= get_m(); ++i) {
      v[i - 1] = at(i, j);
    }
    return v;
  }

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

  // ------------------GETTERS CONSTANTES------------------

  template <class T>
  const T& matrix_t<T>::at (const int i, const int j) const {
    assert(i > 0 && i <= get_m());
    assert(j > 0 && j <= get_n());
    return v_[pos(i, j)];
  }

  template <class T>
  const T& matrix_t<T>::operator () (const int i, const int j) const { return at(i, j); }

  //------OPERACIONES ARITMÉTICAS CON MATRICES------

  /**
   * @brief Tranforma la posición de un elemento específico de la matriz a 0-based.
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
   * @brief sobrecarga del operador de flujo de salida (<<) para la clase matrix_t.
   * @param[in] os: referencia al objeto ostream (flujo de datos de salida).
   * @param[in] m: referencia (constante) a la matriz.
   * @return Devuelve los datos que se introdujeron por el usuario, ya en forma de matriz.
   */
  template <class T>
  ostream& operator << (ostream& os, const matrix_t<T>& m) {
    m.write(os);
    return os;
  }

  /**
   * @brief sobrecarga del operador de flujo de entrada (>>) para la clase matrix_t.
   * @param[in] is: referencia al objeto istream (flujo de datos de entrada).
   * @param[in] m: referencia (constante) a la matriz.
   * @return Devuelve los datos que se introdujeron por el usuario, para ser tratados en el programa.
   */
  template <class T>
  istream& operator >> (istream& is, matrix_t<T>& m) {
    m.read(is);
    return is;
  }

}

#endif