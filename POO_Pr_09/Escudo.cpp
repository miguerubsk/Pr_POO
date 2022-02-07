/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Escudo.cpp
 * Author: Miguerubsk
 * 
 * Created on 28 de abril de 2020, 19:17
 */

#include "Escudo.h"
#include "ProteccionDestruida.h"

Escudo::Escudo():ItemProteccion(3, 5) {
}

bool Escudo::esEquipable() {
    return true;
}

std::string Escudo::getDescripcion() const {
    return "Un escudo";
}

int Escudo::reducir(int damage) {
    if(--usos <= 0)
        throw ProteccionDestruida("Escudo.cpp - El escudo se ha roto");
    return damage - puntosDeProteccion;
}

