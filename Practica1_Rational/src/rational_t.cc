/*
* AUTOR: Raúl González Acosta
* FECHA: 14/02/2023
* EMAIL: alu0101543529@ull.edu.es
* VERSION: 1.0
* ASIGNATURA: Algoritmos y Estructuras de Datos
* PRÁCTICA Nº: 1
*/

// Para los comentarios utilice la sintaxis // ó /* */, siempre que sea consistente.

#include "header_file/rational_t.h"

/**
 * @brief Comprobación que el denominador es distinto de 0
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
int rational_t::get_num() const {
  return num_;
}

int rational_t::get_den() const {
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
double rational_t::value() const { 
  return  (double(get_num()) / double(get_den()));
}

//------------COMPARACIONES----------------

/**
 * @brief Compara racionales
 * @param[in] r: referencia (constante) al racional.
 * @param[in] precision: numero decimal (constante) con un valor de precisión.
 * @return Devuelve true si son iguales y false si son distintos.
 */
bool rational_t::is_equal (const rational_t& r, const double precision) const { 
  return (fabs(value() - r.value()) < precision);                                   //|a − b| < ϵ
}

/**
 * @brief Compara racionales
 * @param[in] r: referencia (constante) al racional.
 * @param[in] precision: numero decimal (constante) con un valor de precisión.
 * @return Devuelve true si el primer número (a) es mayor que el segundo (b).
 */
bool rational_t::is_greater (const rational_t& r, const double precision) const {    //a − b < ϵ
  return ((value() - r.value()) > precision);
}

/**
 * @brief Compara racionales
 * @param[in] r: referencia (constante) al racional.
 * @param[in] precision: numero decimal (constante) con un valor de precisión.
 * @return Devuelve true si el segundo número (b) es mayor que el primero (a).
 */
bool rational_t::is_less (const rational_t& r, const double precision) const {       //b − a < ϵ
  return ((r.value() - value()) > precision);
}

/**
 * @brief Compara racionales
 * @param[in] precision: numero decimal (constante) con un valor de precisión.
 * @return Devuelve true si el numero racional (a) es igual a 0.
 */
/*
bool rational_t::is_zero (const double precision = EPSILON) const {
  return (fabs(value()) < precision);                                               //|a| < ϵ
}
*/

// -----------------------MODIFICACIÓN PRÁCTICA--------------------

/**
 * @brief Compara racional a 1
 * @param[in] r: referencia (constante) al racional.
 * @return Devuelve true si el numero racional (a) es mayor que 1.
 */
bool rational_t::is_greater_than_1 (const rational_t& r) const {                    //a > 1
  return (r.value() > 1);
}

/**
 * @brief Compara racional a 1
 * @param[in] r: referencia (constante) al racional.
 * @return Devuelve true si el numero racional (a) es menor que 1.
 */
bool rational_t::is_less_than_1 (const rational_t& r) const {                       //a < 1
  return (r.value() < 1);
}

/**
 * @brief Compara racional a 1
 * @param[in] r: referencia (constante) al racional.
 * @return Devuelve true si el numero racional (a) es igual a 1.
 */
bool rational_t::is_equal_1 (const rational_t& r) const {                           //a = 1
  if (r.get_den() == r.get_num()) {
    return true;
  } else {
    return false;
  }
}

/*
//------------IMPLEMENTACION FUNCIÓN MCM (POSIBLE MODIFICACIÓN)----------------

int MCM (int n1, int n2) {
  int mcd, mcm, num_min;
  
  if (n1 > n2) {                            // Seleccionamos el menor de los dos números n1 y n2
    num_min = n2;
  } else {
    num_min = n1;
  }

  for (int i = 1; i <= num_min; i++) {      // Realizamos un ciclo que va desde un valor i = 1 hasta i = min(n1, n2)
    if ((n1 % i == 0) && (n2 % i == 0)) {   // Realizamos una condición, en la cual vamos verificando si el resto de la división de n1 y n2 entre cada uno de los valores que toma i dentro del ciclo.
      mcd = i;                              // Seleccionamos ese valor i = mcd(n1, n2)
      mcm = (n1 * n2) / mcd;
    }
  }
  return mcm;
}

//------------OPERACIONES AVANZADAS (USANDO MCM)----------------
rational_t rational_t::add (const rational_t& r) {
  int denominador_nuevo = MCM (get_den(), r.get_den());
  int numerador_nuevo1 = (denominador_nuevo / den_) * num_ ;
  int numerador_nuevo2 = (denominador_nuevo / r.get_den()) * r.get_num();
  rational_t resultado(numerador_nuevo1 + numerador_nuevo2, denominador_nuevo);
  return resultado;
}


rational_t rational_t::substract (const rational_t& r) {
  int denominador_nuevo = MCM (get_den(), r.get_den());
  int numerador_nuevo1 = (denominador_nuevo / den_) * num_ ;
  int numerador_nuevo2 = (denominador_nuevo / r.get_den()) * r.get_num();
  rational_t resultado(numerador_nuevo1 - numerador_nuevo2, denominador_nuevo);
  return resultado;
}
*/

//-----------------OPERACIONES ARITMÉTICAS-------------------

/**
 * @brief Suma de racionales
 * @param[in] r: referencia (constante) al racional.
 * @return Devuelve el resultado de la suma de racionales.
 */
rational_t rational_t::add (const rational_t& r) {
  int denominador = (get_den() * r.get_den());
  int numerador_nuevo1 = (get_num() * r.get_den());
  int numerador_nuevo2 = (get_den() * r.get_num());
  int numerador = (numerador_nuevo1 + numerador_nuevo2);
  rational_t resultado(numerador, denominador);
  return resultado;
}

/**
 * @brief Resta de racionales
 * @param[in] r: referencia (constante) al racional.
 * @return Devuelve el resultado de la resta de racionales.
 */
rational_t rational_t::substract (const rational_t& r) {
  int denominador = (get_den() * r.get_den());
  int numerador_nuevo1 = (get_num() * r.get_den());
  int numerador_nuevo2 = (get_den() * r.get_num());
  int numerador = (numerador_nuevo1 - numerador_nuevo2);
  rational_t resultado (numerador, denominador);
  return resultado;
}

/**
 * @brief Producto de racionales
 * @param[in] r: referencia (constante) al racional.
 * @return Devuelve el resultado del producto de racionales.
 */
rational_t rational_t::multiply (const rational_t& r) {
  rational_t resultado (get_num() * r.get_num(), get_den() * r.get_den());
  return resultado;
}

/**
 * @brief División de racionales
 * @param[in] r: referencia (constante) al racional.
 * @return Devuelve el resultado de la división de racionales.
 */
rational_t rational_t::divide (const rational_t& r) {
  rational_t resultado (get_num() * r.get_den(), get_den() * r.get_num());
  return resultado;
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
  cout << "Numerador? ";
  is >> num_;
  cout << "Denominador? ";
  is >> den_;
  assert(den_ != 0);
}