/*
* AUTOR: Raúl González Acosta
* FECHA: 13/03/2023
* EMAIL: alu0101543529@ull.edu.es
* VERSION: 1.0
* ASIGNATURA: Algoritmos y Estructuras de Datos
* PRÁCTICA Nº: 3
*/

#ifndef SPARSE_VECTORT_H_
#define SPARSE_VECTORT_H_

#include <math.h>

#include "vector_t.h"
#include "pair_t.h"

#define EPS 1.0e-6

typedef pair_t<double> pair_double_t;
typedef vector_t<pair_double_t> pair_vector_t;

/**
 * @brief Clase Sparse_vector_t
 */
class sparse_vector_t {
 public:
  //-----CONSTRUCTOR (POR DEFECTO)-----
  sparse_vector_t(const int = 0);
  //-----CONSTRUCTOR (POR PARÁMETROS)-----
  sparse_vector_t(const vector_t<double>&, const double = EPS);
  //-----CONSTRUCTOR (DE COPIA)-----
  sparse_vector_t(const sparse_vector_t&);

  /// Sobrecarga del operador de asiganción ("=")
  sparse_vector_t& operator = (const sparse_vector_t&);

  //--DESTRUCTOR--
  ~sparse_vector_t();
  
  //-----GETTERS-----
  int get_nz(void) const;
  int get_n(void) const;

  /// Getter para obtener la posición de un elemento en el vector disperso (con pair "valor/indice")
  pair_double_t& at(const int);
  /// Sobrecarga del operador de indexación ("[]")
  pair_double_t& operator [] (const int);
  
  //-----GETTERS CONSTANTES-----
  const pair_double_t& at(const int) const;
  const pair_double_t& operator [] (const int) const;

  //------MÉTODOS I/O------

  /// Imprimir vectores dispersos
  void write(std::ostream& = std::cout) const;

 private:
  pair_vector_t pv_;  // PAIR ("valor/índice")
  int nz_;            // TAMAÑO DEL VECTOR DISPERSO (valores != 0)
  int n_;             // TAMAÑO DEL VECTOR DENSO

  /// Coge valores != 0 del vector denso
  bool IsNotZero(const double, const double = EPS) const;
};


//--------------MÉTODOS DE LA CLASE SPARSEVECTOR-----------------

/**
 * @brief Evalua y toma los valores != 0 del vector denso.
 * @param[in] val: valor del vector que se evalua.
 * @param[in] eps: constante de tolerancia de error (1.0e-6).
 * @return Devuelve true si el valor que lee es != 0
 */
bool IsNotZero(const double val, const double eps = EPS) { return fabs(val) > eps; }

/**
 * @brief Crea un vector disperso en funcion de un vector denso.
 * @param[in] n: tamaño del vector.
 */
sparse_vector_t::sparse_vector_t(const int n) : pv_(n), nz_(0), n_(n) {}

// FASE II

/**
 * @brief Construye un vector disperso parametrizado en función del vector denso parametrizado.
 * @param[in] v: referencia (constante) al vector parametrizado v.
 * @param[in] eps: constante de tolerancia de error (1.0e-6).
 */
sparse_vector_t::sparse_vector_t(const vector_t<double>& v, const double eps)
    : pv_(), nz_(0), n_(0) {
  
  n_ = v.get_size();
  nz_ = 0;
  for (int i = 0; i < n_; i++) {
    if (fabs(v[i]) > eps) {
      nz_++;
    }
  }
  pv_.resize(nz_);
  int j{0};
  for (int i = 0; i < n_; i++) {
    if (fabs(v[i]) > eps) {
      pv_[j++].set(v[i], i);
    }
  }
}

/**
 * @brief Construye un vector disperso de copia en funcion del vector denso de copia.
 * @param[in] w: referencia (constante) al vector w.
 */
sparse_vector_t::sparse_vector_t(const sparse_vector_t& w) {
  *this = w;  // Se invoca directamente al operador de asignación ("=")
}

/**
 * @brief Sobrecarga del operador de asignación ("=") para la clase sparse_vector_t.
 * @return Devuelve el pair del elemento en la posición (i) del vector disperso.
 */
sparse_vector_t& sparse_vector_t::operator = (const sparse_vector_t& w) {
  nz_ = w.get_nz();
  n_ = w.get_n();
  pv_ = w.pv_;

  return *this;
}

/**
 * @brief Destruye un vector disperso.
 */
sparse_vector_t::~sparse_vector_t() {}

/**
 * @brief Obtiene los valores != 0 de un vector denso.
 * @return Devuelve los valores != 0 del vector denso, es decir, los valores del vector disperso.
 */
inline int sparse_vector_t::get_nz() const { return nz_; }

/**
 * @brief Obtiene los valores del vector denso.
 * @return Devuelve los valores del vector denso.
 */
inline int sparse_vector_t::get_n() const { return n_; }

/**
 * @brief Obtiene el valor != 0 del elemento en la posición (i) del vector disperso.
 * @param[in] i: posición del elemento en el vector disperso.
 * @return Devuelve el valor != 0 del elemento en la posición (i) del vector disperso.
 */
pair_double_t& sparse_vector_t::at(const int i) {
  assert(i >= 0 && i < get_nz());     // Se comprueba que la posición es >= 0, pero < que el tamaño del vector disperso.
  return pv_[i];
}

/**
 * @brief Sobrecarga del operador de indexación ("[]") para la clase sparse_vector_t.
 * @return Devuelve el valor != 0 del elemento en la posición (i) del vector disperso.
 */
pair_double_t& sparse_vector_t::operator [] (const int i) { return at(i); }

const pair_double_t& sparse_vector_t::at(const int i) const {
  assert(i >= 0 && i < get_nz());
  return pv_[i];
}

const pair_double_t& sparse_vector_t::operator [] (const int i) const { return at(i); }

//------------OPERADORES I/O----------------

/**
 * @brief Imprime por pantalla el vector disperso.
 * @param[in] os: referencia al objeto ostream (flujo de datos de salida).
 */
void sparse_vector_t::write(std::ostream& os) const { 
  os << get_n() << "(" << get_nz() << "): [ ";
  for (int i = 0; i < get_nz(); i++)
    os << pv_[i] << " ";
	os << "]" << std::endl;
}

/**
 * @brief sobrecarga del operador de flujo de salida (<<).
 * @param[in] os: referencia al objeto ostream (flujo de datos de salida).
 * @param[in] sv: referencia (constante) al vector disperso sv.
 * @return Devuelve la sobrecarga del operador de flujo de salida (<<) para el método write().
 */
std::ostream& operator << (std::ostream& os, const sparse_vector_t& sv) {
  sv.write(os);
  return os;
}

#endif  // SPARSE_VECTORT_H_
