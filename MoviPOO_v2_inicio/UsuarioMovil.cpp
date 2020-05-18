/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   UsuarioMovil.cpp
 * Author: Miguerubsk
 * 
 * Created on 18 de mayo de 2020, 17:07
 */

#include "UsuarioMovil.h"

UsuarioMovil::UsuarioMovil(std::string identificador, bool oculto, bool datos): Usuario(identificador, oculto), datos(datos) {
}

UsuarioMovil::UsuarioMovil(const UsuarioMovil& orig) {
}

UsuarioMovil::~UsuarioMovil() {
}

bool UsuarioMovil::soportaDatos() const {
    return datos;
}

//UsuarioMovil& UsuarioMovil::operator=(const UsuarioMovil& right) {
//    // Check for self-assignment!
//    if (this == &right) // Same object?
//        return *this; // Yes, so skip assignment, and just return *this.
//    // Deallocate, allocate new space, copy values...
//    Usuario::operator =(right);
//    datos = right.datos;
//    return *this;
//}

Usuario& UsuarioMovil::operator=(const Usuario& right) {
     //Check for self-assignment!
    if (this == &right) // Same object?
        return *this; // Yes, so skip assignment, and just return *this.
    // Deallocate, allocate new space, copy values...
    Usuario::operator =(right);
    datos = right.soportaDatos();
    return *this;
}
