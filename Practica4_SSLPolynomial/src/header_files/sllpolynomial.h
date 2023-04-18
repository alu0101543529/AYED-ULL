/*
* AUTOR: Raúl González Acosta
* FECHA: 27/03/2023
* EMAIL: alu0101543529@ull.edu.es
* VERSION: 1.0
* ASIGNATURA: Algoritmos y Estructuras de Datos
* PRÁCTICA Nº: 4
*/

#ifndef SLLPOLYNOMIAL_H_
#define SLLPOLYNOMIAL_H_

#include <math.h>

#include "pair_t.h"
#include "sll_t.h"
#include "vector_t.h"

#define EPS 1.0e-6

typedef pair_t<double> pair_double_t;  // Campo data_ de SllPolynomial
typedef sll_node_t<pair_double_t> SllPolyNode;  // Nodos de SllPolynomial

/**
 * @brief Clase SllPolynomial
 * Clase para polinomios basados en listas simples de pares de valores decimales en punto flotante con doble precisión (double).
 * Hereda la clase sll_t (con el tipo de dato pares de double).
 */
class SllPolynomial : public sll_t<pair_double_t> {
 public:
  //-----CONSTRUCTOR (POR DEFECTO)-----
  SllPolynomial(void) : sll_t() {};
  //-----CONSTRUCTOR (CON PARÁMETROS)-----
  SllPolynomial(const vector_t<double>&, const double = EPS);

  //--DESTRUCTOR--
  ~SllPolynomial() {};

  //------MÉTODOS I/O------

  /// Imprimir un polinomio de lista enlazada simple (sllpolynomial)
  void Write(std::ostream& = std::cout) const;
  
  //-------OPERACIONES SLLPOLYNOMIAL-------

  /// Evalua un polinomio disperso representado por una lista enlazada simple (sll)
  double Eval(const double) const;
  /// Compara si dos polinomios dispersos representados por listas enlazadas simples (sll) son iguales.
  bool IsEqual(const SllPolynomial&, const double = EPS) const;
  /// Suma dos polinomios dispersos representados por listas enlazadas simples (sll)
  void Sum(const SllPolynomial&, SllPolynomial&, const double = EPS);

  //MODIFICACIÓN
  /// Resta dos polinomios dispersos representados por listas enlazadas simples (sll)
  void Sust(const SllPolynomial&, SllPolynomial&, const double = EPS);
};


//--------------MÉTODOS DE LA CLASE SLLPOLYNOMIAL-----------------

/**
 * @brief Evalua y toma los valores != 0 del vector denso.
 * @param[in] val: valor del vector que se evalua.
 * @param[in] eps: constante de tolerancia de error (1.0e-6).
 * @return Devuelve true si el valor que lee es != 0
 */
bool IsNotZero(const double val, const double eps = EPS) {
  return fabs(val) > eps;
}

// FASE II

/**
 * @brief Construye una lista enlazada simple (sll) a partir de un vector disperso de números decimales en punto flotante con doble precisión (double).
 * @param[in] v: referencia (constante) al vector parametrizado v.
 * @param[in] eps: constante de tolerancia de error (1.0e-6).
 */
SllPolynomial::SllPolynomial(const vector_t<double>& v, const double eps) {
  SllPolyNode *aux;
  for (int i = v.get_size() - 1; i >= 0; i--) {
      if (IsNotZero(v[i], eps)) { 
        aux = new SllPolyNode(pair_double_t(v[i], i));
        push_front(aux);
      }
  }
}

//------------OPERADORES I/O----------------

/**
 * @brief Imprime por pantalla el polinomio disperso en función de una lista enlazada simple (sll).
 * @param[in] os: referencia al objeto ostream (flujo de datos de salida).
 */
void SllPolynomial::Write(std::ostream& os) const {
  os << "[ ";
  bool first{true};
  SllPolyNode* aux{get_head()};
  while (aux != NULL) {
    int inx{aux->get_data().get_inx()};
    double val{aux->get_data().get_val()};
    if (val > 0)
      os << (!first ? " + " : "") << val;
    else
      os << (!first ? " - " : "-") << fabs(val);
    os << (inx > 1 ? " x^" : (inx == 1) ? " x" : "");
    if (inx > 1)
      os << inx;
    first = false;
    aux = aux->get_next();
  }
  os << " ]" << std::endl;
}

/**
 * @brief sobrecarga del operador de flujo de salida (<<).
 * @param[in] os: referencia al objeto ostream (flujo de datos de salida).
 * @param[in] p: referencia (constante) al polinomio disperso en función de una lista enlazada simple (sll) p.
 * @return Devuelve la sobrecarga del operador de flujo de salida (<<) para el método write().
 */
std::ostream& operator << (std::ostream& os, const SllPolynomial& p) {
  p.Write(os);
  return os;
}

// FASE III
//-------OPERACIONES SLLPOLYNOMIAL-------

/**
 * @brief Evalua un polinomio disperso representado por una lista enlazada simple (sll)
 * @param[in] x: valor por el que va a ser evaluado.
 */
double SllPolynomial::Eval(const double x) const {
  double result{0.0};
  SllPolyNode *aux = get_head();
  while (aux != NULL) {
    result += aux->get_data().get_val() * std::pow(x, aux->get_data().get_inx());
    aux = aux->get_next();
  }
  return result;
}

/**
 * @brief Compara si dos polinomios dispersos representados por listas enlazadas simples (sll) son iguales.
 * @param[in] sllpol: referencia (constante) del polinomio disperso representado por una lista enlazada simple (sll).
 * @param[in] eps: constante de tolerancia de error (1.0e-6).
 */
bool SllPolynomial::IsEqual(const SllPolynomial& sllpol,
			                      const double eps) const {
  bool differents = false;
  SllPolyNode *aux = get_head();
  SllPolyNode *auxpol = sllpol.get_head();
  while (aux != NULL) {
    if (auxpol == NULL) { return differents; }
    if (fabs(aux->get_data().get_val() - auxpol->get_data().get_val()) >= eps)
      return differents;
    aux = aux->get_next();
    auxpol = auxpol->get_next();
  }
  if (auxpol != NULL) { return differents; }
  return !differents;
}

// FASE IV

/**
 * @brief Suma dos polinomios dispersos representados por listas enlazadas simples (sll).
 * @param[in] sllpol: referencia (constante) del polinomio disperso representado por una lista enlazada simple (sll) a sumar.
 * @param[in] sllpolsum: referencia del polinomio disperso representado por una lista enlazada simple (sll) que contiene los valores sumados.
 * @param[in] eps: constante de tolerancia de error (1.0e-6).
 */
void SllPolynomial::Sum (const SllPolynomial& sllpol,
			                   SllPolynomial& sllpolsum,
			                   const double eps) {
  SllPolyNode *aux = get_head();
  SllPolyNode *auxpol = sllpol.get_head();

  // Si tienen los mismos índices se suman los valores, y se almacenan en la posición del índice común.
  while (aux != NULL || auxpol != NULL) {
    if (aux != NULL && auxpol != NULL) {
      if (aux->get_data().get_inx() == auxpol->get_data().get_inx()) {
        if (IsNotZero(aux->get_data().get_val() + auxpol->get_data().get_val(), eps)) {
          sllpolsum.push_back(new SllPolyNode(pair_double_t(aux->get_data().get_val() + auxpol->get_data().get_val(),
                                                            aux->get_data().get_inx())));
        }
        aux = aux->get_next();
        auxpol = auxpol->get_next();
      } 
      else if (aux->get_data().get_inx() > auxpol->get_data().get_inx()) {
        sllpolsum.push_back(new SllPolyNode(auxpol->get_data()));
        auxpol = auxpol->get_next();
      } 
      else {
        sllpolsum.push_back(new SllPolyNode(aux->get_data()));
        aux = aux->get_next();
      }
    } 
    // Si uno de los polinomios llega al final, se toman los valores del que más lejos llega en los índices que el otro no abarca.
    else if (aux == NULL) {
      sllpolsum.push_back(new SllPolyNode(auxpol->get_data()));
      auxpol = auxpol->get_next();
    }
    else if (auxpol == NULL) {
      sllpolsum.push_back(new SllPolyNode(auxpol->get_data()));
      aux = aux->get_next();
    }
  }
}

// MODIFICACIÓN
/**
 * @brief Resta dos polinomios dispersos representados por listas enlazadas simples (sll).
 * @param[in] sllpol: referencia (constante) del polinomio disperso representado por una lista enlazada simple (sll) a restar.
 * @param[in] sllpolsust: referencia del polinomio disperso representado por una lista enlazada simple (sll) que contiene los valores restados.
 * @param[in] eps: constante de tolerancia de error (1.0e-6).
 */
void SllPolynomial::Sust(const SllPolynomial& sllpol,
			                   SllPolynomial& sllpolsust,
			                   const double eps) {
  SllPolyNode *aux = get_head();
  SllPolyNode *auxpol = sllpol.get_head();

  // Si tienen los mismos índices se restan los valores, y se almacenan en la posición del índice común.
  while (aux != NULL || auxpol != NULL) {
    if (aux != NULL && auxpol != NULL) {
      if (aux->get_data().get_inx() == auxpol->get_data().get_inx()) {
        if (IsNotZero(aux->get_data().get_val() - auxpol->get_data().get_val(), eps)) {
          sllpolsust.push_back(new SllPolyNode(pair_double_t(aux->get_data().get_val() - auxpol->get_data().get_val(),
                                                             aux->get_data().get_inx())));
        }
        aux = aux->get_next();
        auxpol = auxpol->get_next();
      } 
      else if (aux->get_data().get_inx() > auxpol->get_data().get_inx()) {
        auxpol->get_data().get_val();
        sllpolsust.push_back(new SllPolyNode(pair_double_t(- auxpol->get_data().get_val(),
                                                             auxpol->get_data().get_inx())));
        auxpol = auxpol->get_next();
      } 
      else {
        sllpolsust.push_back(new SllPolyNode(aux->get_data()));
        aux = aux->get_next();
      }
    } 
    // Si uno de los polinomios llega al final, se toman los valores del que más lejos llega en los índices que el otro no abarca.
    else if (aux == NULL) {
       sllpolsust.push_back(new SllPolyNode(pair_double_t(- auxpol->get_data().get_val(),
                                                            auxpol->get_data().get_inx())));
      auxpol = auxpol->get_next();
    }
    else if (auxpol == NULL) {
      sllpolsust.push_back(new SllPolyNode(auxpol->get_data()));
      aux = aux->get_next();
    }
  }
}

#endif  // SLLPOLYNOMIAL_H_