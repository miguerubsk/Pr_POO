/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Escuadron.h
 * Author: Miguerubsk
 *
 * Created on 23 de marzo de 2020, 13:50
 */

#ifndef ESCUADRON_H
#define ESCUADRON_H

#include <string>
#include "Piloto.h"

class Escuadron {
public:
    Escuadron();
    Escuadron(std::string nombre, std::string base, Piloto* piloto);
    Escuadron(const Escuadron& orig);
    virtual ~Escuadron();
    
    std::string getBase() const;
    std::string getNombre() const;
    int getNumPilotos() const;
    std::string getNombrePiloto(int pos);
    bool estaEnMision() const;
    
    void setBase(std::string base);
    void setNombre(std::string nombre);

    
    int promedioMisiones();
    Escuadron& addPiloto(Piloto* piloto);
    Escuadron& eliminarPiloto();
    void comenzarMision();
    
    Escuadron operator+(Escuadron& right) const;

    
private:
    static const int MAX_PILOTOS = 50;
    std::string nombre;
    int numPilotos = 0;
    std::string base;
    Piloto *integrantes[MAX_PILOTOS];
    bool enMision = false;
};

#endif /* ESCUADRON_H */

