/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   UsuarioIP.cpp
 * Author: Miguerubsk
 * 
 * Created on 18 de mayo de 2020, 17:07
 */

#include "UsuarioIP.h"
#include "ServicioInvalido.h"

UsuarioIP::UsuarioIP(std::string identificador, bool oculto, bool llamadasVoz): Usuario(identificador, oculto), llamadasVoz(llamadasVoz) {
}

UsuarioIP::UsuarioIP(const UsuarioIP& orig) {
}

UsuarioIP::~UsuarioIP() {
}

bool UsuarioIP::soportaDatos() const {
    return true;
}

bool UsuarioIP::llamarA(Usuario* otro) {
    if(otro->soportaDatos() || llamadasVoz)
        return Usuario::llamarA(otro);
    throw ServicioInvalido("[UsuarioIP::llamarA]  El servicio no es viable");
}

bool UsuarioIP::LlamadasVoz() const {
    return llamadasVoz;
}


Usuario& UsuarioIP::operator=(const Usuario& right) {
    // Check for self-assignment!
    if (this == &right) // Same object?
        return *this; // Yes, so skip assignment, and just return *this.
    // Deallocate, allocate new space, copy values...
    Usuario::operator =(right);
    llamadasVoz = right.LlamadasVoz();
    return *this;
}
