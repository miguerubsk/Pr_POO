/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   ServicioInvalido.cpp
 * Author: Miguerubsk
 * 
 * Created on 18 de mayo de 2020, 17:37
 */

#include "ServicioInvalido.h"

ServicioInvalido::ServicioInvalido(std::string error): std::domain_error(error) {
}

ServicioInvalido::ServicioInvalido(const ServicioInvalido& orig): std::domain_error(orig) {
}

ServicioInvalido::~ServicioInvalido() {
}

