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

//Funcion POP
// Saca una ccion de la pila y devuelve verdadero si pudo sacar devuelve false si la pila está vacía
bool pop(Nodo*& tope, string& textoExtraido){
  if(tope == NULL) {
    return false;
  }
  Nodo* auxiliar = tope;
  textoExtraido = auxiliar->accion;
  tope = tope->siguiente;
  delete auxiliar;
  return true;
}

//Funcion mostrar
//muestra el contenido de la pila
void mostrar(Nodo* tope, string nombrePila) {
  cout << " ================================================="<< endl;
  cout << nombrePila << endl;
  cout << " ================================================="<< endl;

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

//Funcion Limpiar Pila Elimina todos los Nodos
void limpiarPila(Nodo*& tope) {
  Nodo* auxiliar;

  while (tope != NULL) {
      auxiliar = tope;
  tope = tope->siguiente;
  delete auxiliar;
  }
}  

//Funcion Principal
int main() {
    Nodo* pilaAcciones = NULL; // Pila principal
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
  limpiarPila(pilaRehacer);
  cout <<"Accion realizada correctamente. \n";
  cout <<"Accion reahacer fue eliminada. \n";
  break;

case 2:
  if (pop(pilaAcciones, accionMovida)) {
      push(pilaRehacer, accionMovida);
      cout <<" se deshizo la accion: " << accionMovida << endl;
  } else {
      cout << " No hay acciones para deshacer. \n";
  }
  break;

case 3: // REHACER
  if(pop(pilaRehacer, accionMovida)) { // Saca de Rehacer
      push(pilaAcciones, accionMovida); // Mete en Acciones
      cout << "Se rehizo la accion: " << accionMovida << endl;
  } else {
      cout << "No hay acciones para rehacer.\n";
  }
  break;
  
case 4:
    mostrar(pilaAcciones, "Pila de acciones actuales");
    break;

case 5:
    mostrar(pilaRehacer, "pila de Rehacer");
    break;

case 6:
  mostrarEstado(pilaAcciones, pilaRehacer);
  break;

case 7:
  cout << "\nSaliendo del programa ";
  break;

default:
  cout << "Opcion invalida. Intente de nuevo.\n";
  
  }

    } while (opcion != 7);

    // Liberar memoria al finalizar
    limpiarPila(pilaAcciones);
    limpiarPila(pilaRehacer);

    cout << "Memoria liberada correctamente.\n";
    return 0;
}



