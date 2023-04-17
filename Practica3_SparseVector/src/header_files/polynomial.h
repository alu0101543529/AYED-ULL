/*
* AUTOR: Raúl González Acosta
* FECHA: 13/03/2023
* EMAIL: alu0101543529@ull.edu.es
* VERSION: 1.0
* ASIGNATURA: Algoritmos y Estructuras de Datos
* PRÁCTICA Nº: 3
*/

#ifndef POLYNOMIAL_H_
#define POLYNOMIAL_H_

#include "sparse_vector_t.h"

/**
 * @brief Clase Polynomial
 * Clase para polinomios basados en vectores densos de valores decimales en punto flotante con doble precisión (double).
 * Hereda la clase vector_t (con el tipo de dato double).
 */
class Polynomial : public vector_t<double> {
 public:
  //-----CONSTRUCTOR "DE POLYNOMIAL" (POR DEFECTO)-----
  Polynomial(const int n = 0) : vector_t<double>(n) {};
  //-----CONSTRUCTOR DE COPIA "DE POLYNOMIAL"-----
  Polynomial(const Polynomial& pol) : vector_t<double>(pol) {};

  //--DESTRUCTOR "DE POLYNOMIAL"--
  ~Polynomial() {};

  //------MÉTODOS I/O "DE POLYNOMIAL"------
  void Write(std::ostream& = std::cout, const double eps = EPS) const;
  
  //-------OPERACIONES "DE POLYNOMIAL"-------
  double Eval(const double) const;
  bool IsEqual(const Polynomial&, const double = EPS) const;
 };

// --------------------------------------------

/**
 * @brief Clase SparsePolynomial
 * Clase para polinomios basados en vectores dispersos.
 * Hereda la clase sparse_vector_t.
 */
class SparsePolynomial : public sparse_vector_t {
 public:
  //-----CONSTRUCTOR "DE SPARSEPOLYNOMIAL" (POR DEFECTO)-----
  SparsePolynomial(const int n = 0) : sparse_vector_t(n) {};
  //-----CONSTRUCTOR DE COPIA "DE SPARSEPOLYNOMIAL"-----
  SparsePolynomial(const Polynomial& pol) : sparse_vector_t(pol) {};
  SparsePolynomial(const SparsePolynomial&);

  //--DESTRUCTOR "DE SPARSEPOLYNOMIAL"--
  ~SparsePolynomial() {};

  //------MÉTODOS I/O "DE SPARSEPOLYNOMIAL"------
  void Write(std::ostream& = std::cout) const;
  
  //-------OPERACIONES "DE SPARSEPOLYNOMIAL"-------
  double Eval(const double) const;
  bool IsEqual(const SparsePolynomial&, const double = EPS) const;
  bool IsEqual(const Polynomial&, const double = EPS) const;

  void CoeficientePar (const SparsePolynomial&) const;
};

//--------------------------------------------------

//------MÉTODOS I/O "DE POLYNOMIAL"------

/**
 * @brief Muestra por pantalla el vector denso, de la forma: tamaño del vector denso, valores.
 * @param[in] os: referencia al objeto ostream (flujo de datos de salida).
 * @param[in] eps: constante de tolerancia de error (1.0e-6).
 */
void Polynomial::Write(std::ostream& os, const double eps) const {
  os << get_size() << ": [ ";
  bool first{true};
  for (int i{0}; i < get_size(); i++)
    if (IsNotZero(at(i), eps)) {
      os << (!first ? " + " : "") << at(i)
	 << (i > 1 ? " x^" : (i == 1) ? " x" : "");
      if (i > 1)
	os << i;
      first = false;
    }
  os << " ]" << std::endl;
}

/**
 * @brief sobrecarga del operador de flujo de salida (<<).
 * @param[in] os: referencia al objeto ostream (flujo de datos de salida).
 * @param[in] p: referencia (constante) al vector denso.
 * @return Devuelve la sobrecarga del operador de indexación (<<) para el método write().
 */
std::ostream& operator << (std::ostream& os, const Polynomial& p) {
  p.Write(os);
  return os;
}

  //-------OPERACIONES "DE POLYNOMIAL"-------

/**
 * @brief Evalua un polinomio representado por un vector denso.
 * @param[in] x: valor por el que va a ser evaluado.
 */
double Polynomial::Eval(const double x) const {
  double result{0.0};
  for (int i = 0; i < get_size(); i++)
    result += at(i) * (std::pow(x,i));
  return result;
}

/**
 * @brief Compara si dos polinomios representados por vectores densos son iguales.
 * @param[in] pol: referencia (constante) del polinomio.
 * @param[in] eps: constante de tolerancia de error (1.0e-6).
 */
bool Polynomial::IsEqual(const Polynomial& pol, const double eps) const {
  bool differents = false;
  int min_sz, max_sz;
  bool mayor; // Si es 1 el mayor es el invocante, en caso de ser 0 pol es el mayor
  if (get_size() < pol.get_size()) {
    min_sz = get_size();
    max_sz = pol.get_size();
    mayor = 0;
  } else {
    min_sz = pol.get_size();
    max_sz = get_size();
    mayor = 1;
  }
  for (int i = 0; i < min_sz; i++) {    
    if (fabs((pol.get_val(i) - get_val(i))) > eps) {
      return differents;
    }
  }
  for (int i = min_sz; i < max_sz; i++) {
    if (mayor == 0) {
      if (fabs(pol.get_val(i)) > eps) {
        return differents;
      }
    } else {
      if (fabs(get_val(i)) > eps) {
        return differents;
      }
    }
  }
  return !differents;
}

// -----------------------------------------------------------

//-----CONSTRUCTOR DE COPIA "DE SPARSEPOLYNOMIAL"-----
/**
 * @brief Hace un constructor de copia del objeto SparsePolynomial
 * @param[in] spol: referencia (constante) al vector disperso.
 */
SparsePolynomial::SparsePolynomial(const SparsePolynomial& spol) {
  *this = spol;   // Se invoca directamente al operador de asiganción (=)
}

//------MÉTODOS I/O "DE SPARSEPOLYNOMIAL"------

/**
 * @brief Muestra por pantalla el vector disperso (sin ceros), de la forma: tamaño del vector denso, (tamaño del vector disperso), valores.
 * @param[in] os: referencia al objeto ostream (flujo de datos de salida).
 */
void SparsePolynomial::Write(std::ostream& os) const {
  os << get_n() << "(" << get_nz() << "): [ ";
  bool first{true};
  for (int i{0}; i < get_nz(); i++) {
    int inx{at(i).get_inx()};
    os << (!first ? " + " : "") << at(i).get_val()
       << (inx > 1 ? " x^" : (inx == 1) ? " x" : "");
    if (inx > 1)
      os << inx;
    first = false;
  }
  os << " ]" << std::endl;
}

/**
 * @brief sobrecarga del operador de flujo de salida (<<).
 * @param[in] os: referencia al objeto ostream (flujo de datos de salida).
 * @param[in] p: referencia (constante) al vector disperso.
 * @return Devuelve la sobrecarga del operador de flujo de salida (<<) para el método write().
 */
std::ostream& operator << (std::ostream& os, const SparsePolynomial& p) {
  p.Write(os);
  return os;
}

// ----------OPERACIONES "DE SPARSEPOLYNOMIAL"----------

/**
 * @brief Evalua un polinomio representado por vector disperso.
 * @param[in] x: valor (constante) por el que el polinomio disperso va a ser evaluado.
 * @return Devuelve el valor de la suma de los valores evaluados por x en el polinomio disperso.
 */
double SparsePolynomial::Eval(const double x) const {
  double result{0.0};
  for (int i = 0; i < get_nz(); i++)
    result += at(i).get_val() * (std::pow(x,at(i).get_inx()));
  return result;
}

/**
 * @brief Compara si dos polinomios representados por vectores dispersos son iguales.
 * @param[in] spol: referencia (constante) del vector escaso a evaluar.
 * @return Devuelve true si ambos polinomios son iguales, en caso contrario devuelve false.
 */
bool SparsePolynomial::IsEqual(const SparsePolynomial& spol, const double eps) const {
  bool differents = false;
  if (get_nz() != spol.get_nz()) { return differents; }
  for (int i = 0; i < get_nz(); i++) {
    if ((spol.at(i).get_val() != at(i).get_val()) ||
        (spol.at(i).get_inx() != at(i).get_inx())) {
      return differents;
    }
  }
  return !differents;
}

/**
 * @brief Compara si dos polinomios representados por un vector disperso y un vector denso son iguales.
 * @param[in] pol: referencia (constante) del vector denso a evaluar.
 * @return Devuelve true si ambos polinomios son iguales, en caso contrario devuelve false.
 */
bool SparsePolynomial::IsEqual(const Polynomial& pol, const double eps) const {
  bool differents = false;
  int j{0};
  for (int i = 0; i < pol.get_size(); i++) {
    if (fabs(pol.get_val(i)) > eps) { 
      if (at(j).get_val() != pol.get_val(i) ||
          at(j).get_inx() != i) {
        return differents;
      }
      j++;
    }
  }
  return !differents;
}

// MODIFICACIÓN

/**
 * @brief Imprime los monomios de los polinomios dispersos con grado par.
 * @param[in] spol: referencia (constante) del polinomio disperso a evaluar.
 */
void SparsePolynomial::CoeficientePar(const SparsePolynomial& spol) const {
  std::cout << "[ ";
  for (int i = 0; i < spol.get_nz(); i++) {
    if ((spol.at(i).get_inx()) % 2 == 0) {
      std::cout << at(i).get_val() << " ";
    }
  }
  std::cout << "]" << std::endl;
}

#endif  // POLYNOMIAL_H_
