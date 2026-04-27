#include "ArbolBST.h"
#include <iostream>
#include <algorithm>
using namespace std;

// Constructor
ArbolBST::ArbolBST() : raiz(nullptr) {}

// Destructor
ArbolBST::~ArbolBST() {
    vaciar();
}

// Insertar recursivo (privado) - Versión con flag bool por referencia
Nodo* ArbolBST::insertarRecursivo(Nodo* nodo, const Empleado& emp, bool& insertado) {
    if (nodo == nullptr) {
        insertado = true;
        return new Nodo(emp);
    }
    
    if (emp.getCodigo() < nodo->getDato().getCodigo()) {
        nodo->setIzquierdo(insertarRecursivo(nodo->getIzquierdo(), emp, insertado));
    } 
    else if (emp.getCodigo() > nodo->getDato().getCodigo()) {
        nodo->setDerecho(insertarRecursivo(nodo->getDerecho(), emp, insertado));
    } 
    else {
        cout << "❌ El codigo " << emp.getCodigo() << " ya existe. No se inserto.\n";
        insertado = false;
    }
    
    return nodo;
}

// Insertar público - VERSIÓN CORREGIDA
void ArbolBST::insertar(const Empleado& emp) {
    bool insertado = false;
    raiz = insertarRecursivo(raiz, emp, insertado);
    
    if (insertado) {
        cout << " Empleado insertado correctamente.\n";
    }
}

// Buscar recursivo (privado)
Nodo* ArbolBST::buscarRecursivo(Nodo* nodo, int codigo) const {
    if (nodo == nullptr || nodo->getDato().getCodigo() == codigo) {
        return nodo;
    }
    
    if (codigo < nodo->getDato().getCodigo()) {
        return buscarRecursivo(nodo->getIzquierdo(), codigo);
    } else {
        return buscarRecursivo(nodo->getDerecho(), codigo);
    }
}

// Buscar público
bool ArbolBST::buscar(int codigo, Empleado& empEncontrado) const {
    Nodo* resultado = buscarRecursivo(raiz, codigo);
    
    if (resultado != nullptr) {
        empEncontrado = resultado->getDato();
        return true;
    }
    return false;
}

// Existe (versión simplificada)
bool ArbolBST::existe(int codigo) const {
    Empleado temp;
    return buscar(codigo, temp);
}

// Recorridos privados
void ArbolBST::inordenRecursivo(Nodo* nodo) const {
    if (nodo != nullptr) {
        inordenRecursivo(nodo->getIzquierdo());
        nodo->mostrar();
        inordenRecursivo(nodo->getDerecho());
    }
}

void ArbolBST::preordenRecursivo(Nodo* nodo) const {
    if (nodo != nullptr) {
        nodo->mostrar();
        preordenRecursivo(nodo->getIzquierdo());
        preordenRecursivo(nodo->getDerecho());
    }
}

void ArbolBST::postordenRecursivo(Nodo* nodo) const {
    if (nodo != nullptr) {
        postordenRecursivo(nodo->getIzquierdo());
        postordenRecursivo(nodo->getDerecho());
        nodo->mostrar();
    }
}

// Altura recursivo (privado)
int ArbolBST::alturaRecursivo(Nodo* nodo) const {
    if (nodo == nullptr) {
        return 0;
    }
    int alturaIzq = alturaRecursivo(nodo->getIzquierdo());
    int alturaDer = alturaRecursivo(nodo->getDerecho());
    return 1 + max(alturaIzq, alturaDer);
}

// Mostrar hojas recursivo (privado)
void ArbolBST::mostrarHojasRecursivo(Nodo* nodo) const {
    if (nodo != nullptr) {
        if (nodo->esHoja()) {
            nodo->mostrar();
        }
        mostrarHojasRecursivo(nodo->getIzquierdo());
        mostrarHojasRecursivo(nodo->getDerecho());
    }
}

// Liberar árbol (privado)
void ArbolBST::liberarArbol(Nodo* nodo) {
    if (nodo != nullptr) {
        liberarArbol(nodo->getIzquierdo());
        liberarArbol(nodo->getDerecho());
        delete nodo;
    }
}

// Contar nodos (privado)
int ArbolBST::contarNodosRecursivo(Nodo* nodo) const {
    if (nodo == nullptr) return 0;
    return 1 + contarNodosRecursivo(nodo->getIzquierdo()) + contarNodosRecursivo(nodo->getDerecho());
}

// Contar nodos internos (privado)
int ArbolBST::contarNodosInternosRecursivo(Nodo* nodo) const {
    if (nodo == nullptr || nodo->esHoja()) return 0;
    return 1 + contarNodosInternosRecursivo(nodo->getIzquierdo()) + contarNodosInternosRecursivo(nodo->getDerecho());
}

// Métodos públicos de mostrar
void ArbolBST::mostrarRaiz() const {
    if (raiz != nullptr) {
        cout << "\n Raiz del arbol:\n";
        raiz->mostrar();
    } else {
        cout << "\n El arbol esta vacio.\n";
    }
}

void ArbolBST::mostrarInorden() const {
    if (raiz == nullptr) {
        cout << "\n El arbol esta vacio.\n";
        return;
    }
    cout << "\n Recorrido Inorden (ordenado por codigo):\n";
    cout << "----------------------------------------\n";
    inordenRecursivo(raiz);
    cout << "----------------------------------------\n";
}

void ArbolBST::mostrarPreorden() const {
    if (raiz == nullptr) {
        cout << "\n El arbol esta vacio.\n";
        return;
    }
    cout << "\n Recorrido Preorden:\n";
    cout << "----------------------------------------\n";
    preordenRecursivo(raiz);
    cout << "----------------------------------------\n";
}

void ArbolBST::mostrarPostorden() const {
    if (raiz == nullptr) {
        cout << "\n El arbol esta vacio.\n";
        return;
    }
    cout << "\n Recorrido Postorden:\n";
    cout << "----------------------------------------\n";
    postordenRecursivo(raiz);
    cout << "----------------------------------------\n";
}

void ArbolBST::mostrarAltura() const {
    cout << "\n Altura del arbol: " << alturaRecursivo(raiz) << endl;
}

void ArbolBST::mostrarHojas() const {
    if (raiz == nullptr) {
        cout << "\n El arbol esta vacio.\n";
        return;
    }
    cout << "\n Nodos hoja (sin hijos):\n";
    cout << "----------------------------------------\n";
    mostrarHojasRecursivo(raiz);
    cout << "----------------------------------------\n";
    cout << "Total de hojas: " << getContadorHojas() << endl;
}

// Estadísticas públicas
int ArbolBST::getAltura() const {
    return alturaRecursivo(raiz);
}

int ArbolBST::getContadorNodos() const {
    return contarNodosRecursivo(raiz);
}

int ArbolBST::getContadorNodosInternos() const {
    return contarNodosInternosRecursivo(raiz);
}

int ArbolBST::getContadorHojas() const {
    return getContadorNodos() - getContadorNodosInternos();
}

// Utilidades
bool ArbolBST::estaVacio() const {
    return raiz == nullptr;
}

void ArbolBST::vaciar() {
    liberarArbol(raiz);
    raiz = nullptr;
    cout << " Arbol vaciado correctamente.\n";
}