/*
* AUTOR: Raúl González Acosta
* FECHA: 27/02/2023
* EMAIL: alu0101543529@ull.edu.es
* VERSION: 1.0
* ASIGNATURA: Algoritmos y Estructuras de Datos
* PRÁCTICA Nº: 2
*/

#ifndef VECTOR_T
#define VECTOR_T

#include "rational_t.hpp"

using namespace std;

template <class T>

/**
 * @brief Clase Vector_t
 */
class vector_t {
  public:
  //-----CONSTRUCTOR (POR DEFECTO)-----
  vector_t(const int = 0);

  //--DESTRUCTOR--
  ~vector_t();
  
  //---MÉTODO PARA REDIMENSIONAR---
  void resize (const int);
  
  //-----GETTERS-----
  T get_val (const int) const;        // Getter del valor del vector
  int get_size (void) const;          // Getter de el tamaño del vector
  
  //-----SETTERS-----
  void set_val (const int, const T);   // Setter del valor del vector
  
  /// Getter para obtener la posición de un elemento en el vector
  T& at (const int);

  /// Sobrecarga del operador de indexación ("[]")
  T& operator [] (const int);
  
  //-----GETTERS CONSTANTES-----
  const T& at (const int) const;
  const T& operator [] (const int) const;

  //------MÉTODOS I/O------

  /// Imprimir vectores
  void write (ostream& = cout) const;

  /// Lectura de vectores
  void read (istream& = cin);

  // MODIFICACIÓN
  //void suma_vector (const vector_t<T>&) const;

  private:
  T *v_; // ATRIBUTOS (v_ -> vector)
  int sz_;          // sz_ -> size (tamaño del vector)
  
  /// Constructor del vector
  void build (void);

  /// Destructor del vector
  void destroy (void);
};

//----------MÉTODOS DE LA CLASE VECTOR-------------

/**
 * @brief Crea un vector con el tamaño solicitado.
 * @param[in] n: tamaño del vector.
 */
template <class T>
vector_t<T>::vector_t (const int n) { 
  sz_ = n;
  build();
}

/**
 * @brief Destruye un vector.
 */
template <class T>
vector_t<T>::~vector_t() { destroy(); }

/**
 * @brief Crea un vector que apunta a una dirección especifica (!= NULL).
 */
template <class T>
void vector_t<T>::build() {
  v_ = NULL;                  // Se coge un vector que está apuntando a NULL (0).
  if (sz_ != 0) {             
    v_ = new T[sz_];          // Si es distinto de 0, se asigna una nueva dirección de memoria disponible con el tamaño del vector.
    assert(v_ != NULL);       // Se comprueba que esa dirección de memoria es distinta de NULL (si no estaría apuntando a 0).
  }
}

/**
 * @brief Destruye un vector que apunta a una dirección de memoria especifica y la libera
 */
template <class T>
void vector_t<T>::destroy()
{
  if (v_ != NULL) {           // Se coge el vector que se quiere destruir que está apuntando a una direccion específica de memoria (!= NULL).
    delete[] v_;              // Borra todos los elementos del vector.
    v_ = NULL;                // Redirecciona al vector apuntandolo a NULL (0).
  }
  sz_ = 0;                    // Establece el tamaño del vector nuevamente a 0.
}

/**
 * @brief Redimensiona el tamaño de un vector
 * @param[in] n: nuevo tamaño del vector
 */
template <class T>
void vector_t<T>::resize (const int n) {
  destroy();                  // Destruye el vector antiguo
  sz_ = n;                    // Se establece el nuevo tamaño  
  build();                    // Se construye el nuevo vector coon el nuevo tamaño
}

/**
 * @brief Obtiene el valor de un elemento específico en el vector.
 * @param[in] i: posición del elemento en el vector.
 * @return Devuelve el valor del elemento del vector en la posición introducida por el usuario (i).
 */
template <class T>
inline T vector_t<T>::get_val (const int i) const {
  assert (i >= 0 && i < get_size());     // Se comprueba que la posición es >= a 0, pero < que el tamaño del vector.
  return v_[i];
}

/**
 * @brief Obtiene el tamaño del vector.
 * @return Devuelve el tamaño de vector.
 */
template <class T>
inline int vector_t<T>::get_size() const { return sz_; }

/**
 * @brief Establece el valor en una posición específica del vector.
 * @param[in] i: posición del elemento en el vector.
 * @param[in] d: valor a establecer en la posición (i).
 */
template <class T>
void vector_t<T>::set_val (const int i, const T d) {
  assert (i >= 0 && i < get_size());     // Se comprueba que la posición es >= a 0, pero < que el tamaño del vector.
  v_[i] = d;
}

/**
 * @brief Obtiene el valor del elemento en la posición (i) del vector.
 * @param[in] i: posición del elemento en el vector.
 * @return Devuelve el valor del elemento en la posición (i) del vector.
 */
template <class T>
T& vector_t<T>::at (const int i) {
  assert (i >= 0 && i < get_size());     // Se comprueba que la posición es >= a 0, pero < que el tamaño del vector.
  return v_[i];
}

/**
 * @brief Sobrecarga del operador de indexación ("[]") para la clase vector_t.
 * @return Devuelve el valor del elemento en la posición (i) del vector.
 */
template <class T>
T& vector_t<T>::operator [] (const int i) { return at(i); }


template <class T>
const T& vector_t<T>::at (const int i) const {
  assert (i >= 0 && i < get_size());
  return v_[i];
}

template <class T>
const T& vector_t<T>::operator [] (const int i) const { return at(i); }


//------------OPERADORES I/O----------------

/**
 * @brief Muestra por pantalla la dimensión del vector.
 * @param[in] os: referencia al objeto ostream (flujo de datos de salida).
 */
template <class T>
void vector_t<T>::write (ostream& os) const { 
  os << get_size() << ":\t";
  for (int i = 0; i < get_size(); i++)
    os << at(i) << "\t";
  os << endl;
}

/**
 * @brief Introduce la dimensión de un vector introducida por el usuario.
 * @param[in] is: referencia al objeto istream (flujo de datos de entrada).
 */
template <class T>
void vector_t<T>::read (istream& is) {
  is >> sz_;
  resize (sz_);
  for (int i = 0; i < sz_; ++i)
    is >> at(i);
}


// FASE II: PRODUCTO ESCALAR

/**
 * @brief Hace el producto escalar de dos vectores.
 * @param[in] A: referencia (constante) al vector v.
 * @param[in] B: referencia (constante) al vector w.
 * @return //
 */
template <class T>
T scal_prod (const vector_t<T>& v, const vector_t<T>& w) {
  assert (v.get_size() == w.get_size());           // Se comprueba que los dos vectores tienen el mismo tamaño.
  T resultado;
  for (int i = 0; i < v.get_size(); i++) {
    double producto_escalar = (v[i] * w[i]);
    resultado = resultado + producto_escalar;
  }
  return resultado;
}

/**
 * @brief Hace el producto escalar de dos vectores de números racionales.
 * @param[in] A: referencia (constante) al vector v.
 * @param[in] B: referencia (constante) al vector w.
 * @return Devuelve el valor del producto escalar de dos vectores de números racionales, de la forma de un número decimal en punto flotante con doble precisión.
 */
double scal_prod (const vector_t<rational_t>& v, const vector_t<rational_t>& w) {
  assert (v.get_size() == w.get_size());           // Se comprueba que los dos vectores tienen el mismo tamaño.
  double resultado = 0;
  for (int i = 0; i < v.get_size(); i++) {
    double producto_escalar = (v[i].value() * w[i].value());
    resultado = resultado + producto_escalar;
  }
  return resultado;
}

// ---------MODIFICACIÓN----------
/*
template <class T>
void vector_t<T>::suma_vector (const vector_t<T>& v) const {
  vector_t<T> resultado;
  for (int i = 1; i <= v.get_size(); i++) {
   vector_t suma_2a2 = (v[i-1] + v[i]);
   resultado = suma_2a2; 
  }
  v.write();
}
*/

#endif