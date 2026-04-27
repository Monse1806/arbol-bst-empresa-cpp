#include "Nodo.h"
using namespace std;

// Constructor
Nodo::Nodo(const Empleado& emp) : dato(emp), izquierdo(nullptr), derecho(nullptr) {}

// Destructor
Nodo::~Nodo() {
    // No eliminamos los hijos aquí para evitar eliminación en cascada
    // La clase ArbolBST se encargará de la limpieza
}

// Getters
Empleado Nodo::getDato() const { return dato; }
Nodo* Nodo::getIzquierdo() const { return izquierdo; }
Nodo* Nodo::getDerecho() const { return derecho; }

// Setters
void Nodo::setDato(const Empleado& emp) { dato = emp; }
void Nodo::setIzquierdo(Nodo* nodo) { izquierdo = nodo; }
void Nodo::setDerecho(Nodo* nodo) { derecho = nodo; }

// Mostrar nodo
void Nodo::mostrar() const {
    dato.mostrar();
    cout << endl;
}

// Verificar si es hoja
bool Nodo::esHoja() const {
    return (izquierdo == nullptr && derecho == nullptr);
}