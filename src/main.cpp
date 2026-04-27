#include "ArbolBST.h"
#include <iostream>
#include <limits>
using namespace std;

void limpiarBuffer() {
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
}

void mostrarEstadisticas(ArbolBST& arbol) {
    if (!arbol.estaVacio()) {
        cout << "\n ESTADISTICAS DEL ARBOL:\n";
        cout << "   - Total nodos: " << arbol.getContadorNodos() << endl;
        cout << "   - Nodos internos: " << arbol.getContadorNodosInternos() << endl;
        cout << "   - Nodos hoja: " << arbol.getContadorHojas() << endl;
        cout << "   - Altura: " << arbol.getAltura() << endl;
    }
}

int main() {
    ArbolBST arbol;
    int opcion;
    
    cout << "\n BIENVENIDO AL SISTEMA BST EMPRESARIAL \n";
    
    do {
        cout << "\n========================================\n";
        cout << "            MENU PRINCIPAL\n";
        cout << "========================================\n";
        cout << " 1. Insertar empleado\n";
        cout << " 2. Buscar empleado\n";
        cout << " 3. Mostrar raiz\n";
        cout << " 4. Recorrido inorden\n";
        cout << " 5. Recorrido preorden\n";
        cout << " 6. Recorrido postorden\n";
        cout << " 7. Mostrar altura\n";
        cout << " 8. Mostrar hojas\n";
        cout << " 9. Mostrar estadisticas\n";
        cout << "10. Vaciar arbol\n";
        cout << " 0. Salir\n";
        cout << "========================================\n";
        cout << "Seleccione una opcion: ";
        cin >> opcion;
        
        switch(opcion) {
            case 1: {
                int codigo;
                string nombre, cargo;
                
                cout << "\n--- NUEVO EMPLEADO ---\n";
                cout << "Codigo: ";
                cin >> codigo;
                limpiarBuffer();
                
                cout << "Nombre: ";
                getline(cin, nombre);
                
                cout << "Cargo: ";
                getline(cin, cargo);
                
                Empleado emp(codigo, nombre, cargo);
                arbol.insertar(emp);
                break;
            }
            case 2: {
                int codigo;
                cout << "\nIngrese codigo a buscar: ";
                cin >> codigo;
                
                Empleado empEncontrado;
                if (arbol.buscar(codigo, empEncontrado)) {
                    cout << "\n Empleado encontrado:\n   ";
                    empEncontrado.mostrar();
                    cout << endl;
                } else {
                    cout << "\n Empleado con codigo " << codigo << " no encontrado.\n";
                }
                break;
            }
            case 3:
                arbol.mostrarRaiz();
                break;
            case 4:
                arbol.mostrarInorden();
                break;
            case 5:
                arbol.mostrarPreorden();
                break;
            case 6:
                arbol.mostrarPostorden();
                break;
            case 7:
                arbol.mostrarAltura();
                break;
            case 8:
                arbol.mostrarHojas();
                break;
            case 9:
                mostrarEstadisticas(arbol);
                break;
            case 10:
                arbol.vaciar();
                break;
            case 0:
                cout << "\n Gracias por usar el sistema. Hasta luego!\n";
                break;
            default:
                cout << "\n Opcion no valida. Intente de nuevo.\n";
                break;
        }
    } while (opcion != 0);
    
    return 0;
}