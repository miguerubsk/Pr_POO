/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   PersonajeNJ.cpp
 * Author: Miguerubsk
 * 
 * Created on 5 de mayo de 2020, 18:37
 */

#include "PersonajeNJ.h"

PersonajeNJ::PersonajeNJ() {
}

PersonajeNJ::PersonajeNJ(std::string descripcion) :
descripcion(descripcion) {
}


PersonajeNJ::PersonajeNJ(const PersonajeNJ& orig) {
}

PersonajeNJ::~PersonajeNJ() {
}

std::string PersonajeNJ::getDescripcion() const {
    return descripcion;
}

void PersonajeNJ::SetDescripcion(std::string descripcion) {
    this->descripcion = descripcion;
}
