/*
* AUTOR: Raúl González Acosta
* FECHA: 01/05/2023
* EMAIL: alu0101543529@ull.edu.es
* VERSION: 1.0
* ASIGNATURA: Algoritmos y Estructuras de Datos
* PRÁCTICA Nº: 6
*/

#include "header_files/maze_t.hpp"
#include "header_files/pair_t.h"

/**
 * @brief Constructor de laberinto.
 */
maze_t::maze_t():
matrix_(),
visited_(), 
i_start_(-1),
j_start_(-1), 
i_end_(-1),
j_end_(-1)
{}

/**
 * @brief Destructor de laberinto.
 */
maze_t::~maze_t() {}

/**
 * @brief Método que resuelve el laberinto.
 * @param[in] i_start_: atributo que guarda la posición de partida (en las filas de la matriz) para resolver el laberinto.
 * @param[in] j_start_: atributo que guarda la posición de partida (en las columnas de la matriz) para resolver el laberinto.
 */
bool maze_t::solve() { return solve_(i_start_, j_start_); }

/**
 * @brief Lee el laberinto, de forma matricial, aportado por el usuario desde el segmento de datos.
 * @param[in] is: referencia al objeto istream (flujo de datos de entrada).
 */
istream& maze_t::read(istream& is) { 
  int m, n;
  is >> m >> n;
  assert(m > 0 && n > 0);   // Se comprueba que tanto filas (m), como columnas (n) son > 0

  matrix_.resize(m, n);     // Se redimensiona la matriz según el número de filas y columnas introducido
  visited_.resize(m, n);    // Así como la matriz booleana, que comprueba si una celda ya ha sido visistada o no.
  for (int i = 1; i <= m; i++) {
    for (int j = 1; j <= n; j++) {
      short s;
      is >> s;

      // Si el dato es un START_ID -> INICIO
      if (s == START_ID) {
        i_start_ = i;
        j_start_ = j;
      }
      // Si el dato es un END_ID -> FIN
      else if (s == END_ID) {
        i_end_ = i;
        j_end_ = j;
      }

      matrix_(i, j) = s;
    }
  }
  // Se comprueba que se han leído correctamente la entrada y la salida    
  assert (i_start_ != -1 && j_start_ != -1 && i_end_ != -1 && j_end_ != -1);
  return is;
}

/**
 * @brief Imprime por pantalla el laberinto resuelto, mostrando el camino usando los caracteres designados por convenio.
 * @param[in] os: referencia al objeto ostream (flujo de datos de salida).
 */
ostream& maze_t::write(ostream& os) const {
  os << matrix_.get_m() << "x" << matrix_.get_n() << endl;
  for (int i = 1; i <= matrix_.get_m(); i++) {
    for (int j = 1; j <= matrix_.get_n(); j++)
      switch (matrix_(i, j)) { 
        case START_ID: os << START_CHR; break;
        case END_ID:   os << END_CHR;   break;
        case WALL_ID:  os << WALL_CHR;  break;
        case PASS_ID:  os << PASS_CHR;  break;
        case PATH_ID:  os << PATH_CHR;  break;
      }
    os << endl;
  }
  return os; 
}

// FASE I
/**
 * @brief Método booleano que comprueba si la celda es válida antes de ser visitada.
 * @param[in] i: entero (constante) que indica la posición de la fila que ocupa la celda a "investigar".
 * @param[in] j: entero (constante) que indica la posición de la columna que ocupa la celda a "investigar".
 */
bool maze_t::is_ok_(const int i, const int j) const { 
  // Retorna true si se cumplen TODAS estas condiciones:
    // - La fila i y la columna j, están dentro de los límites del laberinto.
    if (j < 1 || i < 1 || j > matrix_.get_n() || i > matrix_.get_m()) { return false; }
    // - La celda en (i, j) no puede ser un muro.
    if (matrix_(i,j) == WALL_ID) { return false; }
    // - La celda (i, j) no puede haber sido visitada antes.
    if (visited_(i,j) == true) { return false; }
  
  return true;
}

// FASE II
/**
 * @brief Método recursivo que resuelve el laberinto introducido, de forma matricial, por el segmento de datos.
 * @param[in] i: entero (constante) que indica la posición de la fila que ocupa la celda a "investigar".
 * @param[in] j: entero (constante) que indica la posición de la columna que ocupa la celda a "investigar".
 */
bool maze_t::solve_(const int i, const int j) {
  // CASO BASE: Retorna 'true' si 'i' y 'j' han llegado a la salida, y lo mete en la lista doblemente enlazada para imprimir posteriormente su solución.
  if (matrix_(i,j) == END_ID) { 
    solution.push_front(new dll_node_t<pair_t<int>>(pair_t<int>(i,j)));
    return true; 
  }
  // PASOS A SEGUIR PARA LA RESOLUCIÓN DE LABERINTO:
  // - Marcamos la celda como visitada
  visited_(i,j) = true;
  // - Para cada una de las 4 posibles direcciones (N, E, S, W) ver si es posible el desplazamiento (is_ok_) y, en ese caso, intentar resolver el laberinto llamando recursivamente a 'solve'. 
  //   Si la llamada devuelve 'true', poner en la celda el valor PATH_ID, guardarla en la lista doblemente enlazada para imprimir posteriormente su solución, y propagarla retornando también 'true'.
  for (int D = 0; D < 4; D++) {
    if (is_ok_((i + i_d[D]), (j + j_d[D]))) {
      if (solve_((i + i_d[D]), (j + j_d[D]))) {
        if (matrix_(i + i_d[D],j + j_d[D]) != END_ID) {
          matrix_((i + i_d[D]), (j + j_d[D])) = PATH_ID;
        }
        solution.push_front(new dll_node_t<pair_t<int>>(pair_t<int>(i,j)));
        return true;
      }
    }
  }
  // - Desmarcamos la celda como visitada (denominado "backtracking") y retornamos 'false'
  visited_(i, j) = false;
  return false;
}

// FASE III

/**
 * @brief Método que imprime el camino (las celdas que recorre la solución) que resuelve el laberinto introducido.
 */
void maze_t::ShowSolution() {
  dll_node_t<pair_t<int>>* aux = solution.get_head();

  if (aux == NULL) { 
    cout << endl;
    return; 
  }

  int paso{0};
  cout << "El camino que soluciona el laberinto es el siguiente:" << endl;

  while (aux != NULL) {
    cout << "[" << paso++ << "]:" << "(" << aux->get_data().get_first() << "," << aux->get_data().get_second() << ") ";
    if (aux->get_next() != NULL) { cout << "-> "; }
    aux = aux->get_next();
  }
  cout << endl << endl;
}

/**
 * @brief sobrecarga del operador de flujo de entrada (>>) para la clase maze_t.
 * @param[in] is: referencia al objeto istream (flujo de datos de entrada).
 * @param[in] m: referencia (constante) a la matriz.
 * @return Devuelve los datos que se introdujeron por el usuario, para ser tratados en el programa.
 */
istream& operator >> (istream& is, maze_t& M) { return M.read(is); }

/**
 * @brief sobrecarga del operador de flujo de salida (<<) para la clase maze_t.
 * @param[in] os: referencia al objeto ostream (flujo de datos de salida).
 * @param[in] M: referencia (constante) al laberinto.
 * @return Devuelve los datos que se introdujeron por el usuario en forma de laberinto, para ser impresos por el método write().
 */
ostream& operator << (ostream& os, const maze_t& M) { return M.write(os); }
