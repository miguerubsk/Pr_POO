/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Usuario.cpp
 * Author: Miguerubsk
 * 
 * Created on 31 de marzo de 2020, 17:45
 */

#include "Usuario.h"

Usuario::Usuario(): identificador("anonimo"), oculto(false), llamando_a(nullptr) {
    for(int i = 0; i < 10; ++i){
        contactos[i] = nullptr;
    }
}

Usuario::Usuario(const Usuario& orig) {
    identificador = orig.identificador;
    oculto = orig.oculto;
    llamando_a = orig.llamando_a;
    numContacto = orig.numContacto;
    for(int i = 0; i < 10; ++i){
        contactos[i] = orig.contactos[i];
    }
}

Usuario::Usuario(std::string identificador, bool oculto) :
identificador(identificador), oculto(oculto), llamando_a(nullptr) {
    for(int i = 0; i < 10; ++i){
        contactos[i] = nullptr;
    }
}


Usuario::~Usuario() {
}

bool Usuario::isDiponible() {
    if(isOculto() || llamandoA() != nullptr)
        return false;
    return true;
}


bool Usuario::isOculto() const {
    return oculto;
}

std::string Usuario::getIdentificador() const {
    return identificador;
}

void Usuario::setIdentificador(std::string identificador) {
    if(identificador.length() < 5 || identificador.length() > 15)
        throw std::invalid_argument("Usuario.cpp - setIdentificador() - El identificador debe tener entre 5 y 15 caracteres");
    this->identificador = identificador;
}

void Usuario::setNumContactos(int numContactos) {
    this->numContacto = numContactos;
}


void Usuario::colgar() {
    llamando_a = nullptr;
}

int Usuario::contactosDisponibles() {
    int aux = 0;
    for(int i = 0; i < numContacto; ++i){
        if(contactos[i]->isDiponible())
            ++aux;
    }
    return aux;
}

Usuario Usuario::getContacto(int cual) {
    return *contactos[cual];
}

Usuario* Usuario::llamandoA() {
    return llamando_a;
}


/**
 * Llama a un usuario si no está oculto o llamando a otro usuario
 * @param user usuario al que se desea llamar
 * @return true si se ha establecido la llamada
 * @return false si no se ha establecido la llamada
 * @throws std::invalid_argument
 */
bool Usuario::llamarA(Usuario user) {
    if(!user.isDiponible())
        return false;
    llamando_a = &user;
    return true;
}

void Usuario::nuevoContacto(Usuario user) {
    if(user.isOculto())
        throw std::invalid_argument("Usuario.cpp - nuevoContacto() - El usuario está oculto");
    contactos[numContacto] = &user;
    ++numContacto;
}

int Usuario::numContactos() {
    return numContacto;
}

Usuario& Usuario::operator=(const Usuario& right) {
    // Check for self-assignment!
    if (this == &right) // Same object?
        return *this; // Yes, so skip assignment, and just return *this.
    // Deallocate, allocate new space, copy values...
    identificador = right.identificador;
    oculto = right.oculto;
    numContacto = right.numContacto;
    llamando_a = right.llamando_a;
    for(int i = 0; i < 10; ++i){
        contactos[i] = right.contactos[i];
    }
    
    return *this;
}
