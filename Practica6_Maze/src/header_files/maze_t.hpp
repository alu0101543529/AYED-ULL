/*
* AUTOR: Raúl González Acosta
* FECHA: 01/05/2023
* EMAIL: alu0101543529@ull.edu.es
* VERSION: 1.0
* ASIGNATURA: Algoritmos y Estructuras de Datos
* PRÁCTICA Nº: 6
*/

#ifndef MAZE_T
#define MAZE_T

#include "matrix_t.hpp"
#include "dll_t.h"
#include "pair_t.h"

#define TRACE(x) cout << (#x) << "= " << (x) << endl

// Caracteres usados para definir el laberinto en la sección de datos
#define PASS_ID  0  // PASS_ID (0) -> PASILLO
#define WALL_ID  1  // WALL_ID (1) -> PARED
#define PATH_ID  2  // PATH_ID (2) -> CAMINO DE SALIDA
#define START_ID 8  // START_ID (8) -> INICIO
#define END_ID   9  // END_ID (1) -> FIN

// Caracteres usados para mostrar el laberinto por pantalla
#define PASS_CHR  " " // PASS_ID ( ) -> PASILLO
#define WALL_CHR  "█" // WALL_CHR (█) -> PARED
#define PATH_CHR  "·" // PATH_CHR (·) -> CAMINO DE SALIDA
#define START_CHR "A" // START_CHR (A) -> INICIO
#define END_CHR   "B" // END_CHR (B) -> FIN

using namespace std;
using namespace AED;

typedef matrix_t<short> matrix_t_short;
typedef matrix_t<bool> matrix_t_bool;

// Enumera las direcciones: Norte (N), Este (E), Sur (S) y Oeste (W), (así como las diagonales Noreste (NE), Noroeste (NW), Sudeste (SE), y Sudoeste (SW)).
enum direction_t {N, E, S, W, NE, NW, SE, SW};

// Define los vectores de desplazamiento en las 4 direcciones (en el eje x (i), y en el y (j)):
//                    N   E  S   W   NE  NW  SE  SW
const short i_d[] = { -1, 0, 1,  0 , -1, -1,  1,  1};
const short j_d[] = {  0, 1, 0, -1 ,  1, -1,  1, -1};


class maze_t {
 public:
  // CONSTRUCTOR
  maze_t(void);
  // DESTRUCTOR
  ~maze_t();

  // MÉTODO PARA RESOLVER EL LABERINTO
  bool solve(void);

  // MÉTODO PARA MOSTRAR LA SOLUCIÓN
  void ShowSolution();

  //------MÉTODOS I/O------
  
  /// Lectura de laberinto
  istream& read(istream& = cin);
  /// Imprimir laberinto
  ostream& write(ostream& = cout) const;
  
 private:
  // Matriz atributo que guarda los valores leídos de la entrada
  matrix_t_short matrix_;
  // Matriz atributo (de booleanos) que guarda si una celda ha sido visitada o no
  matrix_t_bool visited_;
  // Atributos que guardan las filas y columnas de entrada (start) y salida (end)
  int i_start_, j_start_, i_end_, j_end_;

  // Método que comprueba si la celda es válida antes de ser visitada
  bool is_ok_(const int, const int) const;
  // Método recursivo que resuelve el laberinto
  bool solve_(const int, const int);
  // Lista doblemente enlazada que contiene el camino que soluciona el laberinto
  dll_t<pair_t<int>> solution;
};

// Sobrecarga del operador de flujo de entrada (>>) para la clase maze_t.
istream& operator >> (istream&, maze_t&);
// Sobrecarga del operador de flujo de salida (<<) para la clase maze_t.
ostream& operator << (ostream&, const maze_t&);

#endif