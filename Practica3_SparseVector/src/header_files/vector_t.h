/*
* AUTOR: Raúl González Acosta
* FECHA: 13/03/2023
* EMAIL: alu0101543529@ull.edu.es
* VERSION: 1.0
* ASIGNATURA: Algoritmos y Estructuras de Datos
* PRÁCTICA Nº: 3
*/

#ifndef VECTORT_H_
#define VECTORT_H_

#include <iostream>
#include <cassert>

template<class T> 

/**
 * @brief Clase Vector_t
 */
class vector_t {
 public:
  //-----CONSTRUCTOR (POR DEFECTO)-----
  vector_t(const int = 0);
  //-----CONSTRUCTOR (DE COPIA)-----
  vector_t(const vector_t&);

  /// Sobrecarga del operador de asiganción ("=")
  vector_t<T>& operator = (const vector_t<T>&);

  //--DESTRUCTOR--
  ~vector_t();
  
  //-----GETTERS-----
  T get_val(const int) const;
  int get_size(void) const;
  
  //-----SETTERS-----
  void set_val(const int, const T);
  
  /// Getter para obtener la posición de un elemento en el vector
  T& at(const int);
  /// Sobrecarga del operador de indexación ("[]")
  T& operator [] (const int);
  
  //-----GETTERS CONSTANTES-----
  const T& at(const int) const;
  const T& operator[](const int) const;

  //---MÉTODO PARA REDIMENSIONAR---
  void resize(const int);
  
  //------MÉTODOS I/O------
  
  /// Lectura de vectores
  void read(std::istream& = std::cin);
  /// Imprimir vectores
  void write(std::ostream& = std::cout) const;

 private:
  T *v_;            // ATRIBUTOS (v_ -> vector)
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
template<class T> 
vector_t<T>::vector_t(const int n) : v_(NULL), sz_(n) { build(); }

/**
 * @brief Construye un vector de copia con el tamaño solicitado.
 * @param[in] w: referencia (constante) al vector w.
 */
template<class T> 
vector_t<T>::vector_t(const vector_t<T>& w) : v_(NULL), sz_(0) {
  *this = w; // Se invoca directamente al operador de asignación ("=")
}

/**
 * @brief Sobrecarga del operador de asignación ("=") para la clase vector_t.
 * @return Devuelve el valor del elemento en la posición (i) del vector.
 */
template<class T> 
vector_t<T>& vector_t<T>::operator = (const vector_t<T>& w) {
  resize(w.get_size());
  for (int i = 0; i < get_size(); i++)
    at(i) = w.at(i);
  
  return *this;
}

/**
 * @brief Destruye un vector.
 */
template<class T> 
vector_t<T>::~vector_t() { destroy(); }

/**
 * @brief Crea un vector que apunta a una dirección especifica (!= NULL).
 */
template<class T>
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
  assert (i >= 0 && i < get_size());     // Se comprueba que la posición es >= 0, pero < que el tamaño del vector.
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
 * @brief Introduce la dimensión de un vector introducida por el usuario.
 * @param[in] is: referencia al objeto istream (flujo de datos de entrada).
 */
template <class T>
void vector_t<T>::read(std::istream& is) {
  is >> sz_;
  resize (sz_);
  for (int i = 0; i < sz_; ++i)
    is >> at(i);
}

/**
 * @brief Imprime por pantalla el vector.
 * @param[in] os: referencia al objeto ostream (flujo de datos de salida).
 */
template<class T> void vector_t<T>::write(std::ostream& os) const {
  os << get_size() << ": [ ";
  for (int i = 0; i < get_size(); i++)
    os << at(i) << (i != get_size() - 1 ? "\t" : "");
  os << " ]" << std::endl;
}

/**
 * @brief sobrecarga del operador de flujo de entrada (>>).
 * @param[in] is: referencia al objeto istream (flujo de datos de entrada).
 * @param[in] v: referencia (constante) al vector v.
 * @return Devuelve la sobrecarga del operador de flujo de entrada (>>) para el método read().
 */
template<class T> 
std::istream& operator >> (std::istream& is, vector_t<T>& v) {
  v.read(is);
  return is;
}

/**
 * @brief sobrecarga del operador de flujo de salida (<<).
 * @param[in] os: referencia al objeto ostream (flujo de datos de salida).
 * @param[in] v: referencia (constante) al vector v.
 * @return Devuelve la sobrecarga del operador de flujo de salida (<<) para el método write().
 */
template<class T> 
std::ostream& operator << (std::ostream& os, const vector_t<T>& v) {
  v.write(os);
  return os;
}

#endif  // VECTORT_H_
