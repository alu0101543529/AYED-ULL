/*
* AUTOR: Raúl González Acosta
* FECHA: 01/05/2023
* EMAIL: alu0101543529@ull.edu.es
* VERSION: 1.0
* ASIGNATURA: Algoritmos y Estructuras de Datos
* PRÁCTICA Nº: 6
* COMPILACIÓN: g++ src/main_maze_t.cpp src/maze_t.cpp -o main_maze_t
* EJECUCIÓN:
            ./main_maze_t < data/data_maze_1.txt
            ./main_maze_t < data/data_maze_2.txt
            ./main_maze_t < data/data_maze_3.txt
            ./main_maze_t < data/data_maze_fail.txt
*/

#include "header_files/maze_t.hpp"

using namespace std;

int main() { 
  maze_t M;
  cin >> M;
  cout << M << endl;
  
  if (M.solve()) { 
    cout << "¡¡ Se ha encontrado una salida al laberinto !!" << endl;
    cout << M << endl;
  }
  else { cout << "No se ha podido encontrar la salida del laberinto..." << endl; }
  
  M.ShowSolution();

  return 0;
}