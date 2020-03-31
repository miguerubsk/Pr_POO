/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Usuario.h
 * Author: Miguerubsk
 *
 * Created on 31 de marzo de 2020, 17:45
 */

#ifndef USUARIO_H
#define USUARIO_H

#include <iostream>

class Usuario {
public:
    Usuario();
    Usuario(const Usuario& orig);
    Usuario(std::string identificador, bool oculto);
    virtual ~Usuario();
    
    std::string getIdentificador() const;
    bool isOculto() const;
    
    void setIdentificador(std::string identificador);

    void setNumContactos(int numContactos);

    
    bool llamarA(Usuario user);
    Usuario* llamandoA();
    void colgar();
    void nuevoContacto(Usuario user);
    Usuario getContacto(int cual);
    int numContactos();
    int contactosDisponibles();
    bool isDiponible();
    
    Usuario& operator=(const Usuario& right);
    
private:
    std::string identificador = "anonimo";
    bool oculto = false;
    Usuario *contactos[10];
    Usuario *llamando_a;
    int numContacto = 0;

};

#endif /* USUARIO_H */

