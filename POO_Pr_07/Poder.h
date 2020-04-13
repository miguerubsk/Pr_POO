/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Poder.h
 * Author: Miguerubsk
 *
 * Created on 4 de abril de 2020, 14:30
 */

#ifndef PODER_H
#define PODER_H

#include <iostream>

class Poder {
public:
    Poder();
    Poder(std::string nombre, std::string descripcion, std::string afectaA, float capacidadDestructiva);
    Poder(const Poder& orig);
    virtual ~Poder();
    
    std::string GetAfectaA() const;
    float GetCapacidadDestructiva() const;
    std::string GetDescripcion() const;
    std::string GetNombre() const;

    void SetAfectaA(std::string afectaA);
    void SetCapacidadDestructiva(float capacidadDestructiva);
    void SetDescripcion(std::string descripcion);
    void SetNombre(std::string nombre);

    Poder& operator=(const Poder& right);

    std::string toCSV() const;
    
private:
    std::string nombre;
    std::string descripcion;
    std::string afectaA;
    float capacidadDestructiva;
    
};

#endif /* PODER_H */

