#ifndef EMPLEADO_H
#define EMPLEADO_H

#include <iostream>
#include <string>

class Empleado {
private:
    int codigo;
    std::string nombre;
    std::string cargo;

public:
    // Constructores
    Empleado();
    Empleado(int _codigo, const std::string& _nombre, const std::string& _cargo);
    
    // Getters
    int getCodigo() const;
    std::string getNombre() const;
    std::string getCargo() const;
    
    // Setters
    void setCodigo(int _codigo);
    void setNombre(const std::string& _nombre);
    void setCargo(const std::string& _cargo);
    
    // Métodos de utilidad
    void mostrar() const;
    bool operator<(const Empleado& otro) const;
    bool operator>(const Empleado& otro) const;
    bool operator==(const Empleado& otro) const;
};

#endif