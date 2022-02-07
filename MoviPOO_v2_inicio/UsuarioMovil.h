/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   UsuarioMovil.h
 * Author: Miguerubsk
 *
 * Created on 18 de mayo de 2020, 17:07
 */

#ifndef USUARIOMOVIL_H
#define USUARIOMOVIL_H

#include "Usuario.h"


class UsuarioMovil: public Usuario {
public:
    UsuarioMovil(std::string identificador, bool oculto, bool datos);
    UsuarioMovil(const UsuarioMovil& orig);
    virtual ~UsuarioMovil();
    
    Usuario& operator=(const Usuario& orig) override;

    bool soportaDatos() const;
    
private:
    bool datos = false;
};

#endif /* USUARIOMOVIL_H */

