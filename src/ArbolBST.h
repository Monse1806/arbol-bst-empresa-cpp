#ifndef ARBOLBST_H
#define ARBOLBST_H

#include "Nodo.h"

class ArbolBST {
private:
    Nodo* raiz;
    
    // Métodos privados recursivos - Versión original (sin referencia)
    Nodo* insertarRecursivo(Nodo* nodo, const Empleado& emp, bool& insertado);
    Nodo* buscarRecursivo(Nodo* nodo, int codigo) const;
    void inordenRecursivo(Nodo* nodo) const;
    void preordenRecursivo(Nodo* nodo) const;
    void postordenRecursivo(Nodo* nodo) const;
    int alturaRecursivo(Nodo* nodo) const;
    void mostrarHojasRecursivo(Nodo* nodo) const;
    void liberarArbol(Nodo* nodo);
    int contarNodosRecursivo(Nodo* nodo) const;
    int contarNodosInternosRecursivo(Nodo* nodo) const;

public:
    // Constructor y destructor
    ArbolBST();
    ~ArbolBST();
    
    // Operaciones básicas
    void insertar(const Empleado& emp);
    bool buscar(int codigo, Empleado& empEncontrado) const;
    bool existe(int codigo) const;
    
    // Mostrar información
    void mostrarRaiz() const;
    void mostrarInorden() const;
    void mostrarPreorden() const;
    void mostrarPostorden() const;
    void mostrarAltura() const;
    void mostrarHojas() const;
    
    // Estadísticas
    int getAltura() const;
    int getContadorNodos() const;
    int getContadorNodosInternos() const;
    int getContadorHojas() const;
    
    // Utilidades
    bool estaVacio() const;
    void vaciar();
};

#endif