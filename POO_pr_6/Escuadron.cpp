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

#include <stdexcept>

#include "Escuadron.h"

Escuadron::Escuadron() {
}

Escuadron::Escuadron(std::string nombre, std::string base, Piloto* piloto) :
nombre(nombre), base(base) {
    addPiloto(piloto);
}

Escuadron::Escuadron(const Escuadron& orig) {
    base=orig.base;
    nombre=orig.nombre;
    enMision=orig.enMision;
    for(int i = 0; i < orig.numPilotos; ++i){
        addPiloto(orig.integrantes[i]);
    }
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

std::string Escuadron::getNombrePiloto(int pos) {
    return integrantes[pos]->getNombre();
}

bool Escuadron::estaEnMision() const {
    return enMision;
}


void Escuadron::setBase(std::string base) {
    this->base = base;
}

void Escuadron::setNombre(std::string nombre) {
    this->nombre = nombre;
}

Escuadron Escuadron::operator+(Escuadron& right) const {
    Escuadron result(*this);
    for(int i = 0; i < right.numPilotos; ++i){
        result.addPiloto(right.integrantes[i]);
    }
    return result;
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

void Escuadron::comenzarMision() {
    for(int i = 0; i < numPilotos; ++i){
        if(integrantes[i]->getNave()==nullptr || integrantes[i]->getAuxiliar()==nullptr)
            throw std::logic_error("El escuadron no esta praparado para salir en una mision");
    }
    enMision = true;
}
