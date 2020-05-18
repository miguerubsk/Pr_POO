/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   ItemApilable.cpp
 * Author: Miguerubsk
 *
 * Created on 25 de abril de 2020, 16:25
 */

#include "ItemApilable.h"
#include <stdexcept>

ItemApilable::ItemApilable(unsigned int cuantos)
    :_numElementos(cuantos)
{
    if (cuantos==0) throw std::out_of_range("[ItemApilable] Error al crear un ItemApilable con ninguna unidad");
    if (cuantos>64) throw std::out_of_range("[ItemApilable] Error al crear un ItemApilable más de 64 unidades");
}

ItemApilable::ItemApilable(const ItemApilable& orig)
    :_numElementos(orig._numElementos)
{
}

ItemApilable::~ItemApilable() {
}

void ItemApilable::incrementaNumElementos(unsigned int cantidad) {
    if (_numElementos+cantidad>64) throw std::out_of_range("[ItemApilabre::decrementaNumElementos] Un item apilable no puede tener más de 64 unidades");    
    this->_numElementos+= cantidad;
}

void ItemApilable::decrementaNumElementos(unsigned int cantidad) {
    this->_numElementos-=cantidad;
    if (_numElementos<0) //throw std::out_of_range("[ItemApilabre::decrementaNumElementos] Un item apilable no puede tener menos de 1 unidad");
        _numElementos = 0;
}


unsigned int ItemApilable::getNumElementos() const {
    return _numElementos;
}
