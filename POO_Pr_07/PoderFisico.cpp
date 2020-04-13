/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   PoderFisico.cpp
 * Author: Miguerubsk
 * 
 * Created on 13 de abril de 2020, 19:03
 */

#include "PoderFisico.h"

PoderFisico::PoderFisico():Poder() {
}

PoderFisico::PoderFisico(std::string nombre, std::string descripcion, std::string afectaA, float capacidadDestructiva) :
Poder(nombre, descripcion, afectaA, capacidadDestructiva) {
}

PoderFisico::PoderFisico(const PoderFisico& orig):Poder(orig) {
}

PoderFisico& PoderFisico::operator=(const PoderFisico& right) {
    // Check for self-assignment!
    if (this == &right) // Same object?
        return *this; // Yes, so skip assignment, and just return *this.
    // Deallocate, allocate new space, copy values...
    this->Poder::operator =(right);
    return *this;
}


PoderFisico::~PoderFisico() {
}

