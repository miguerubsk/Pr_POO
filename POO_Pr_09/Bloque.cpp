/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Bloque.cpp
 * Author: Miguerubsk
 * 
 * Created on 25 de abril de 2020, 16:25
 */

#include "Bloque.h"
#include <sstream>

Bloque::Bloque():Bloque(1){
}

Bloque::Bloque(unsigned int cuantos):ItemApilable(cuantos){
}

Bloque::Bloque(const Bloque& orig):ItemApilable(orig){
}

Bloque::~Bloque() {
}

std::string Bloque::getDescripcion() const {
    std::stringstream ss;
    ss << "Bloque de granito (" 
       << getNumElementos() << ") ";    
    return ss.str();
}
