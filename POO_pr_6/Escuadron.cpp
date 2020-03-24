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

Escuadron::Escuadron(std::string nombre, std::string base) :
nombre(nombre), base(base) {
}

Escuadron::Escuadron(const Escuadron& orig) {
}

Escuadron::~Escuadron() {
}

std::string Escuadron::getBase() const {
    return base;
}

std::string Escuadron::getNombre() const {
    return nombre;
}

int Escuadron::getNumPilotos() const {
    return numPilotos;
}

void Escuadron::setBase(std::string base) {
    this->base = base;
}

void Escuadron::setNombre(std::string nombre) {
    this->nombre = nombre;
}

int Escuadron::promedioMisiones() {
    int totalMisiones = 0;
    for (int i = 0; i < numPilotos; ++i) {
        if (integrantes[i])
            totalMisiones += integrantes[i]->getNumMisiones();
    }
    return totalMisiones / numPilotos;
}

Escuadron& Escuadron::addPiloto(Piloto* piloto) {
    integrantes[numPilotos] = piloto;
    ++numPilotos;
    return *this;
}

Escuadron& Escuadron::eliminarPiloto() {
    delete integrantes[numPilotos];
    integrantes[numPilotos] = nullptr;
    --numPilotos;
    return *this;
}
