/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   vehiculo.h
 * Author: Miguerubsk
 *
 * Created on 12 de febrero de 2020, 16:57
 */

#ifndef VEHICULO_H
#define VEHICULO_H

#include <iostream>
#include <cstdlib>

class Vehiculo {
public:
    Vehiculo();
    Vehiculo(const Vehiculo& orig);
    virtual ~Vehiculo();
    
    void setPrecio(float precio);
    float getPrecio() const;
    void setFabricacion(int fabricacion);
    int getFabricacion() const;
    void setMatricula(std::string Matricula);
    std::string getMatricula() const;
    void setModelo(std::string Modelo);
    std::string getModelo() const;
    void setMarca(std::string Marca);
    std::string getMarca() const;
    

private:
    std::string Marca; ///< Marca del vehículo
    std::string Modelo; ///< Modelo del vehículo
    std::string Matricula; ///< Matrícula europea
    int Fabricacion; ///< Año de fabricación del vehículo
    float Precio; ///< Precio del vehículo en euros

};

namespace Vehiculos {
    int rellenarVector(Vehiculo v[], int tamv);
    void mostrarEnPantalla(Vehiculo v[], int tamv);
    int buscarPorMatricula(std::string mat, Vehiculo v[], int tamv);
    int maxPrecio(Vehiculo v[], int tamv);
    void leePorTeclado(Vehiculo &_Vehiculo);
    void leePorTeclado(Vehiculo *_Vehiculo);
    void muestraEnPantalla(Vehiculo &_Vehiculo);
    void muestraEnPantalla(Vehiculo *_Vehiculo);
    void incrementaPrecios(Vehiculo vehiculos[], int numvehiculos, float porcentaje);
    Vehiculo *buscarSubcadena(Vehiculo vehiculos[], int numVehiculos, std::string sub);
};

#endif /* VEHICULO_H */

