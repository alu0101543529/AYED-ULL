/*
* AUTOR: Raúl González Acosta
* FECHA: 27/02/2023
* EMAIL: alu0101543529@ull.edu.es
* VERSION: 1.0
* ASIGNATURA: Algoritmos y Estructuras de Datos
* PRÁCTICA Nº: 2
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
  // Una definición de clase debe comenzar con una sección public:, seguida de protected:, luego private:.
  public:
  //-----CONSTRUCTOR (POR DEFECTO)-----
  rational_t(const int = 0, const int = 1);
    // std::cout << "Ejecutado el constructor por defecto." << std::endl;

  //--DESTRUCTOR--
  ~rational_t() {}
  
  // La indentación por defecto es de 2 espacios.
  //-----GETTERS-----
  int get_num() const;
  int get_den() const;
  
  //------SETTERS------
  void set_num (const int);
  void set_den (const int);

  //------MÉTODOS------

  /// Calcula el valor del número racional
  double value (void) const;

  /// Calcula el opuesto del número racional
  rational_t opposite (void) const;
  
  /// Calcula el inverso/recíproco del número racional
  rational_t reciprocal (void) const;

  //------COMPARACIONES------

  /// Comparación de igualación (a = b)
  bool is_equal (const rational_t&, const double precision = EPSILON) const;
  
  /// Comparación de mayoría (a > b)
  bool is_greater (const rational_t&, const double precision = EPSILON) const;

  /// Comparación de minoria (a < b)
  bool is_less (const rational_t&, const double precision = EPSILON) const;

  //------OPERACIONES ARITMÉTICAS CON NÚMEROS RACIONALES------

  /// Suma de racionales
  rational_t add (const rational_t&) const;

  /// Resta de racionales
  rational_t substract (const rational_t&) const;

  /// Producto de racionales
  rational_t multiply (const rational_t&) const;
  
  /// División de racionales
  rational_t divide (const rational_t&) const;

  //------MÉTODOS I/O------

  /// Imprimir racionales
  void write (ostream& = cout) const;

   /// Lectura de racionales
  void read (istream& = cin);
  
  private:
  // Los miembros de datos de las clases, tanto estáticos como no estáticos, se nombran como variables ordinarias que no son miembros, pero con un guión bajo al final.
  int num_, den_; // ATRIBUTOS
};

//--------SOBRECARGA DE LOS OPERADORES DE I/O--------

/// Sobrecarga del operador de flujo de salida (<<) para la clase rational_t.
ostream& operator << (ostream& os, const rational_t&);

/// Sobrecarga del operador de flujo de entrada (>>) para la clase rational_t.
istream& operator >> (istream& is, rational_t&);

//---------SOBRECARGA DE LOS OPERADORES ARITMÉTICOS---------

/// Sobrecarga del operador suma (+) para la clase rational_t.
rational_t operator + (const rational_t&, const rational_t&);

/// Sobrecarga del operador resta (-) para la clase rational_t.
rational_t operator - (const rational_t&, const rational_t&);

/// Sobrecarga del operador producto (*) para la clase rational_t.
rational_t operator * (const rational_t&, const rational_t&);

/// Sobrecarga del operador división (/) para la clase rational_t.
rational_t operator / (const rational_t&, const rational_t&);

#endif
