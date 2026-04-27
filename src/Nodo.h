#ifndef NODO_H
#define NODO_H

#include "Empleado.h"

class Nodo {
private:
    Empleado dato;
    Nodo* izquierdo;
    Nodo* derecho;

public:
    // Constructor
    Nodo(const Empleado& emp);
    
    // Destructor
    ~Nodo();
    
    // Getters
    Empleado getDato() const;
    Nodo* getIzquierdo() const;
    Nodo* getDerecho() const;
    
    // Setters
    void setDato(const Empleado& emp);
    void setIzquierdo(Nodo* nodo);
    void setDerecho(Nodo* nodo);
    
    // Métodos de utilidad
    void mostrar() const;
    bool esHoja() const;
};

#endif