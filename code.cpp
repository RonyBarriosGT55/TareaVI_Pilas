#include <iostream>
#include <string>
using namespace std;
//Estructura del Nodo
struct Nodo{
  string accion;
  Nodo* siguiente;
};
//funcion push
void push(Nodo*& tope, string texto) {
  Nodo* nuevo = new Nodo;
nuevo->accion =texto;
nuevo->siguiente = tope;
tope = nuevo;
}
//Funcion mostrar
//muestra el contenido de la pila
void mostrar(Nodo* tope, string nombrePila) {
  cout << " =================================================";
  cout << nombrePila << endl;
  cout << " =================================================;

    if (tope == NULL) {
  cout << "La pila esta vacia. ";
  return;
  }
  Nodo* auxiliar = tope;
  int posicion = 1;
  while (auxiliar != NULL) {
  cout << posicion << ". " << auxiliar->accion << endl;
  auxiliar = auxiliar->siguiente;
  posicion++;
  }
}
//
