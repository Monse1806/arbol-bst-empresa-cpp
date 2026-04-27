#include "Empleado.h"
using namespace std;

// Constructor por defecto
Empleado::Empleado() : codigo(0), nombre(""), cargo("") {}

// Constructor con parámetros
Empleado::Empleado(int _codigo, const string& _nombre, const string& _cargo) 
    : codigo(_codigo), nombre(_nombre), cargo(_cargo) {}

// Getters
int Empleado::getCodigo() const { return codigo; }
string Empleado::getNombre() const { return nombre; }
string Empleado::getCargo() const { return cargo; }

// Setters
void Empleado::setCodigo(int _codigo) { codigo = _codigo; }
void Empleado::setNombre(const string& _nombre) { nombre = _nombre; }
void Empleado::setCargo(const string& _cargo) { cargo = _cargo; }

// Mostrar empleado
void Empleado::mostrar() const {
    cout << "Codigo: " << codigo
         << " | Nombre: " << nombre
         << " | Cargo: " << cargo;
}

// Operadores de comparación (útiles para el BST)
bool Empleado::operator<(const Empleado& otro) const {
    return codigo < otro.codigo;
}

bool Empleado::operator>(const Empleado& otro) const {
    return codigo > otro.codigo;
}

bool Empleado::operator==(const Empleado& otro) const {
    return codigo == otro.codigo;
}