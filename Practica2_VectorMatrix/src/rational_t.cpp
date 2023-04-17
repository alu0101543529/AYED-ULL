/*
* AUTOR: Raúl González Acosta
* FECHA: 27/02/2023
* EMAIL: alu0101543529@ull.edu.es
* VERSION: 1.0
* ASIGNATURA: Algoritmos y Estructuras de Datos
* PRÁCTICA Nº: 2
*/

// Para los comentarios utilice la sintaxis // ó /* */, siempre que sea consistente.

#include "header_files/rational_t.hpp"

/**
 * @brief Comprobación que el denominador es distinto de 0.
 * @param[in] n: número entero (constante) numerador.
 * @param[in] d: número entero (constante) denominador.
 */
rational_t::rational_t (const int n, const int d) {
  assert(d != 0);                                     // Comprueba que el denominador no es 0, si no sería una indeterminación
  num_ = n, den_ = d;
}

// Se deja 1 línea de separación entre métodos, salvo que hayan comentarios entre medio.

// En la mayoría de los casos, se usa el estilo de declaración de función donde el tipo de retorno va antes del nombre de la función. (A expensas de implemenetar la nueva sintaxis)

//----------GETTERS--------------
inline int rational_t::get_num() const {
  return num_;
}

inline int rational_t::get_den() const {
  return den_;
}

//----------SETTERS--------------
void rational_t::set_num (const int n) {
  num_ = n;
}

void rational_t::set_den (const int d) {
  assert(d != 0);
  den_ = d;
}


//----------MÉTODOS-------------

/**
 * @brief Calcula el valor del número racional.
 * @param[in] get_num: getter del número entero (constante) numerador.
 * @param[in] get_den: getter del número entero (constante) denominador.
 */
inline double rational_t::value() const { 
  return double (get_num()) / get_den();
}

/**
 * @brief Calcula el opuesto del número racional.
 * @param[in] get_num: getter del número entero (constante) numerador.
 * @param[in] get_den: getter del número entero (constante) denominador.
 */
rational_t rational_t::opposite() const { 
  return rational_t ((-1) * get_num(), get_den());
}

/**
 * @brief Calcula el inverso/recíproco del número racional.
 * @param[in] get_num: getter del número entero (constante) numerador.
 * @param[in] get_den: getter del número entero (constante) denominador.
 */
rational_t rational_t::reciprocal() const { 
  return rational_t (get_den(), get_num());
}

//------------COMPARACIONES----------------

/**
 * @brief Compara racionales.
 * @param[in] r: referencia (constante) al racional.
 * @param[in] precision: numero decimal (constante) con un valor de precisión.
 * @return Devuelve true si son iguales y false si son distintos.
 */
bool rational_t::is_equal (const rational_t& r, const double precision) const { 
  return (fabs(value() - r.value()) < precision);                                   //|a − b| < ϵ
}

/**
 * @brief Compara racionales.
 * @param[in] r: referencia (constante) al racional.
 * @param[in] precision: numero decimal (constante) con un valor de precisión.
 * @return Devuelve true si el primer número (a) es mayor que el segundo (b).
 */
bool rational_t::is_greater (const rational_t& r, const double precision) const {    //a − b < ϵ
  return ((value() - r.value()) > precision);
}

/**
 * @brief Compara racionales.
 * @param[in] r: referencia (constante) al racional.
 * @param[in] precision: numero decimal (constante) con un valor de precisión.
 * @return Devuelve true si el segundo número (b) es mayor que el primero (a).
 */
bool rational_t::is_less (const rational_t& r, const double precision) const {
  return r.is_greater(*this, precision);;
}

//------------OPERACIONES ARITMÉTICAS CON NÚMEROS RACIONALES----------------

/**
 * @brief Suma de números racionales.
 * @param[in] r: referencia (constante) al racional.
 * @return Devuelve el resultado de la suma de racionales.
 */
rational_t rational_t::add (const rational_t& r) const {
  return rational_t (get_num() * r.get_den() + get_den() * r.get_num(), 
                     get_den() * r.get_den());
}

/**
 * @brief Resta de números racionales.
 * @param[in] r: referencia (constante) al racional.
 * @return Devuelve el resultado de la resta de racionales.
 */
rational_t rational_t::substract (const rational_t& r) const {
  return add(r.opposite());
}

/**
 * @brief Producto de números racionales
 * @param[in] r: referencia (constante) al racional.
 * @return Devuelve el resultado del producto de racionales.
 */
rational_t rational_t::multiply (const rational_t& r) const {
  return rational_t (get_num() * r.get_num(), get_den() * r.get_den());
}

/**
 * @brief División de números racionales
 * @param[in] r: referencia (constante) al racional.
 * @return Devuelve el resultado de la división de racionales.
 */
rational_t rational_t::divide (const rational_t& r) const {
  return multiply(r.reciprocal());
}


// FASE I: SOBRECARGA DE OPERADORES ARITMÉTICOS

/**
 * @brief sobrecarga del operador suma (+) para la clase rational_t.
 * @param[in] a: referencia (constante) al racional a.
 * @param[in] b: referencia (constante) al racional b.
 * @return Devuelve el resultado de la suma entre los números racionales a y b.
 */
rational_t operator + (const rational_t& a, const rational_t& b) {
  return b.add(a);
}

/**
 * @brief sobrecarga del operador resta (-) para la clase rational_t.
 * @param[in] a: referencia (constante) al racional a.
 * @param[in] b: referencia (constante) al racional b.
 * @return Devuelve el resultado de la resta entre los números racionales a y b.
 */
rational_t operator - (const rational_t& a, const rational_t& b) {
  return a.substract(b);
}


/**
 * @brief sobrecarga del operador producto (*) para la clase rational_t.
 * @param[in] a: referencia (constante) al racional a.
 * @param[in] b: referencia (constante) al racional b.
 * @return Devuelve el resultado del producto entre los números racionales a y b.
 */
rational_t operator * (const rational_t& a, const rational_t& b) {
  return a.multiply(b);
}

/**
 * @brief sobrecarga del operador división (/) para la clase rational_t.
 * @param[in] a: referencia (constante) al racional a.
 * @param[in] b: referencia (constante) al racional b.
 * @return Devuelve el resultado de la división entre los números racionales a y b.
 */
rational_t operator / (const rational_t& a, const rational_t& b) {
  return a.divide(b);
}

//------------OPERADORES I/O----------------

/**
 * @brief Para mostrar racionales por pantalla
 * @param[in] os: referencia al objeto ostream (flujo de datos de salida).
 */
void rational_t::write (ostream& os) const {
  os << get_num() << "/" << get_den() << "=" << value() << endl;
}

/**
 * @brief Para introducir racionales por pantalla
 * @param[in] is: referencia al objeto istream (flujo de datos de entrada).
 */
void rational_t::read (istream& is) {
  is >> num_ >> den_;
  assert(den_ != 0);
}

/**
 * @brief sobrecarga del operador de flujo de salida (<<) para la clase rational_t.
 * @param[in] os: referencia al objeto ostream (flujo de datos de salida).
 * @param[in] r: referencia (constante) al racional.
 * @return Devuelve los datos que se introdujeron por el usuario, ya en forma de número racional.
 */
ostream& operator << (ostream& os, const rational_t& r) {
  r.write(os);
  return os;
}

/**
 * @brief sobrecarga del operador de flujo de entrada (>>) para la clase rational_t.
 * @param[in] is: referencia al objeto istream (flujo de datos de entrada).
 * @param[in] r: referencia (constante) al racional.
 * @return Devuelve los datos que se introdujeron por el usuario, para ser tratados en el programa.
 */
istream& operator >> (istream& is, rational_t& r) {
  r.read(is);
  return is;
}