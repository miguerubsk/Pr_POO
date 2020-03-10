/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   ParametroNoValido.cpp
 * Author: Miguerubsk
 * 
 * Created on 6 de marzo de 2020, 11:30
 */

#include "ParametroNoValido.h"

ParametroNoValido::ParametroNoValido() {
}

ParametroNoValido::ParametroNoValido(const ParametroNoValido& orig) {
}

ParametroNoValido::~ParametroNoValido() {
}

ParametroNoValido::ParametroNoValido(std::string fichero, std::string funcion, std::string descripcion) : fichero(fichero), funcion(funcion), descripcion(descripcion) {}

std::string ParametroNoValido::queOcurre() {
    return "Fichero: "+fichero+" - Función: "+funcion+" - Descripción: "+descripcion;
}
