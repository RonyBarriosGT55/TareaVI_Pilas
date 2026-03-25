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
//Funcion mostrar estado actual
void mostrarEstado(Nodo* acciones, Nodo* rehacer) {
    mostrar(acciones, "Pila de acciones actuales");
    mostrar(rehacer, "Pila de Reacher");
}
//Funcion Principal
int main() {
    Nodo* pilaAcciones = NULLL; // Pila principal
    Nodo* pilaRehacer = NULL; // Pilas de acciones desechas.

    int opcion;
    string accion;
    string accionMovida;

cout <<"=============================================";
cout <<"  Simulador de deshacer /Rehacer ";
cout <<" Rony Alexander Barrios Carnet: 9941 99 127";

do {
    cout << "\n=========== MENU ===========\n";
        cout << "1. Realizar accion\n";
        cout << "2. Deshacer ultima accion (UNDO)\n";
        cout << "3. Rehacer accion (REDO)\n";
        cout << "4. Mostrar acciones actuales\n";
        cout << "5. Mostrar pila de rehacer\n";
        cout << "6. Mostrar ambas pilas\n";
        cout << "7. Salir\n";
        cout << "Seleccione una opcion: ";
        cin >> opcion;
        cin.ignore();

  switch (opcion) {
case 1:
    cout <<"Ingresa la accion a realizar:";
    getline(cin, accion);

    push(pilaAcciones, accion);
  // cada vez que se realiza la accion nueva se limpa la pila de rehacer
  limpiar pila(pilaRehacer);
  cout <<"Accion realizada correctamente. \n";
  cout <<"Accion rreahacer fue eliminada." \n";
  break;

case 2:
  if (pop(pilaAcciones, accionMovida)) {
      push(pilaRehacer, accionMovida);
      cout <<" se deshizo la ccion: " << accionMovida << endl;
  } else {
      cout << " No hay acciones para deshacer. \n";
  }
  break;

case 3:
  if(pop(pilaAcciones, accionMovida)) {
      push(pilaRehacer, accionMovida);
      cout << "se Deshizo la accion:"  << accionMovida <<endl;
  }  else {
        cout << " No hay acciones para deshacer. \n";
  }
    break;
  

cout



