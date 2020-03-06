/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   ParametroNoValido.h
 * Author: Miguerubsk
 *
 * Created on 6 de marzo de 2020, 11:30
 */

#ifndef PARAMETRONOVALIDO_H
#define PARAMETRONOVALIDO_H

#include <iostream>

class ParametroNoValido {
public:
    ParametroNoValido();
    ParametroNoValido(std::string fichero, std::string funcion, std::string descripcion);
    ParametroNoValido(const ParametroNoValido& orig);
    virtual ~ParametroNoValido();
    
    std::string queOcurre();
    
private:
    std::string fichero;
    std::string funcion;
    std::string descripcion;

};

#endif /* PARAMETRONOVALIDO_H */

