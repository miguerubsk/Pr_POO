/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   UsuarioIP.h
 * Author: Miguerubsk
 *
 * Created on 18 de mayo de 2020, 17:07
 */

#ifndef USUARIOIP_H
#define USUARIOIP_H

#include "Usuario.h"


class UsuarioIP: public Usuario {
public:
    UsuarioIP(std::string identificador, bool oculto, bool llamadasVoz);
    UsuarioIP(const UsuarioIP& orig);
    virtual ~UsuarioIP();
    
    bool soportaDatos() const;
    bool llamarA(Usuario* otro) override;
    bool LlamadasVoz() const override;
    
    Usuario& operator=(const Usuario& orig) override;
    
private:
    bool llamadasVoz = false;
};

#endif /* USUARIOIP_H */

