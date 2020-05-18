/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   ServicioInvalido.h
 * Author: Miguerubsk
 *
 * Created on 18 de mayo de 2020, 17:37
 */

#ifndef SERVICIOINVALIDO_H
#define SERVICIOINVALIDO_H

#include <stdexcept>


class ServicioInvalido: public std::domain_error {
public:
    ServicioInvalido(std::string error);
    ServicioInvalido(const ServicioInvalido& orig);
    virtual ~ServicioInvalido() noexcept;
private:

};

#endif /* SERVICIOINVALIDO_H */

