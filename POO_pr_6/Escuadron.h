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
    Escuadron(const Escuadron& orig);
    virtual ~Escuadron();
    
    int promedioMisiones();
    void addPiloto(Piloto* piloto);
    
private:
    static const int MAX_PILOTOS = 50;
    std::string nombre;
    int numPilotos;
    std::string base;
    Piloto *integrantes[MAX_PILOTOS];
};

#endif /* ESCUADRON_H */

