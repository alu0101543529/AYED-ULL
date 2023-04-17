/*
* AUTOR: Raúl González Acosta
* FECHA: 14/02/2023
* EMAIL: alu0101543529@ull.edu.es
* VERSION: 1.0
* ASIGNATURA: Algoritmos y Estructuras de Datos
* PRÁCTICA Nº: 1
*/

// Para los comentarios utilice la sintaxis // ó /* */, siempre que sea consistente.

#ifndef RATIONAL_T
#define RATIONAL_T

#include <iostream>
#include <cassert>
#include <cmath>

// Las macros deben nombrarse con mayúsculas y guiones bajos.
# define EPSILON 1e-6     //MACRO EPSILON

using namespace std;

/**
 * @brief Clase Rational_t
 */
class rational_t {
  // Una definición de clase debe comenzar con una public:sección, seguida de protected:, luego private:.
  public:
  //-----CONSTRUCTOR (CON PARÁMETROS)-----
  rational_t (const int = 0, const int = 1);
    // std::cout << "Ejecutado el constructor con parámetros." << std::endl;

  //--DESTRUCTOR--
  ~rational_t() {}
  
  // La indentación por defecto es de 2 espacios.
  //-----GETTERS-----
  int get_num() const;
  int get_den() const;
  
  //------SETTERS------
  void set_num (const int);
  void set_den (const int);

  //------  MÉTODOS------

  /// Calcula el valor del racional
  double value (void) const;

  // FASE II

  /// Comparación de igualación (a = b)
  bool is_equal (const rational_t&, const double precision = EPSILON) const;
  
  /// Comparación de mayoría (a > b)
  bool is_greater (const rational_t&, const double precision = EPSILON) const;

  /// Comparación de minoria (a < b)
  bool is_less (const rational_t&, const double precision = EPSILON) const;

  /// Comparación a 0 (a = 0)
  // bool is_zero (const double precision) const;

  //------------MODIFICACIÓN-------------
  /// Comparación de mayoría a 1 (a > 1)
  bool is_greater_than_1 (const rational_t&) const;

  /// Comparación de minoría a 1 (a < 1)
  bool is_less_than_1 (const rational_t&) const;

  /// Comparación de igualación a 1 (a = 1)
  bool is_equal_1 (const rational_t&) const;

  // FASE III

  /// Suma de racionales
  rational_t add (const rational_t&);

  /// Resta de racionales
  rational_t substract (const rational_t&);

  /// Producto de racionales
  rational_t multiply (const rational_t&);
  
  /// División de racionales
  rational_t divide (const rational_t&);
  
  //------MÉTODOS I/O------

  /// Imprimir racionales
  void write (ostream& = cout) const;

  /// Lectura de racionales
  void read (istream& = cin);
  
  private:
  // Los miembros de datos de las clases, tanto estáticos como no estáticos, se nombran como variables ordinarias que no son miembros, pero con un guión bajo al final.
  int num_, den_; // ATRIBUTOS
};

#endif