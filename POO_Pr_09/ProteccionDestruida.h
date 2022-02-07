/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   ProteccionDestruida.h
 * Author: Miguerubsk
 *
 * Created on 28 de abril de 2020, 18:41
 */

#ifndef PROTECCIONDESTRUIDA_H
#define PROTECCIONDESTRUIDA_H

#include <stdexcept>


class ProteccionDestruida: public std::domain_error {
public:
    ProteccionDestruida(std::string error):std::domain_error(error){};
    ProteccionDestruida(const ProteccionDestruida& orig):std::domain_error(orig){};
    virtual ~ProteccionDestruida() noexcept {};
private:

};

#endif /* PROTECCIONDESTRUIDA_H */

