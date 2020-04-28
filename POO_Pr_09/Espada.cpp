/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Espada.cpp
 * Author: Miguerubsk
 * 
 * Created on 25 de abril de 2020, 16:24
 */

#include "Espada.h"


Espada::Espada(const Espada& orig) {
}

Espada::~Espada() {
}

std::string Espada::getDescripcion() const {
    return "Una espada";
}

bool Espada::esEquipable() {
    return true;
}
