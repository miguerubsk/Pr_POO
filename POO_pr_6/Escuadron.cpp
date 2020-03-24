/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Escuadron.cpp
 * Author: Miguerubsk
 * 
 * Created on 23 de marzo de 2020, 13:50
 */

#include "Escuadron.h"

Escuadron::Escuadron() {
}

Escuadron::Escuadron(const Escuadron& orig) {
}

Escuadron::~Escuadron() {
}

int Escuadron::promedioMisiones() {
    int totalMisiones = 0;
    for(int i = 0; i < MAX_PILOTOS; ++i){
        if(integrantes[i])
            totalMisiones += integrantes[i]->getNumMisiones();
    }
    return totalMisiones/numPilotos;
}

void Escuadron::addPiloto(Piloto* piloto) {
    integrantes[numPilotos] = piloto;
    ++numPilotos;
}

void Escuadron::eliminarPiloto() {
    delete integrantes[numPilotos];
    integrantes[numPilotos] = nullptr;
    --numPilotos;
}
