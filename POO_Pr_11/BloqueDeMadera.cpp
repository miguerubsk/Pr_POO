/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   BloqueDeMadera.cpp
 * Author: Miguerubsk
 * 
 * Created on 9 de mayo de 2020, 20:46
 */

#include "BloqueDeMadera.h"

BloqueDeMadera::BloqueDeMadera():BloqueDeMadera(1) {
}

BloqueDeMadera::BloqueDeMadera(unsigned int cuantos) :
ItemApilable(cuantos) {
}


BloqueDeMadera::BloqueDeMadera(const BloqueDeMadera& orig) {
}

BloqueDeMadera::~BloqueDeMadera() {
}

std::string BloqueDeMadera::getDescripcion() const {
    return "Una maera";
}
