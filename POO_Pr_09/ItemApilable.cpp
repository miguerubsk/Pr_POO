/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   ItemApilable.cpp
 * Author: Miguerubsk
 * 
 * Created on 25 de abril de 2020, 16:28
 */

#include "ItemApilable.h"
#include <iostream>
#include <stdexcept>

ItemApilable::ItemApilable(int cuantos) : numElementos(cuantos) {
    if (cuantos == 0)
        throw std::out_of_range("ItemApilable() - No se puede crear un ItemApilable sin unidades");
    if (cuantos > 64)
        throw std::out_of_range("ItemApilable() - No se puede crear un ItemApilable con más de 64 unidades");
}

ItemApilable::ItemApilable(const ItemApilable& orig) : numElementos(orig.numElementos) {
}

ItemApilable::~ItemApilable() {
}

void ItemApilable::incrementaNumElementos(int cantidad) {
    if (numElementos + cantidad > 64)
        throw std::out_of_range("ItemApilabre.cpp - incrementaNumElementos() - Un item apilable no puede tener más de 64 unidades");
    numElementos += cantidad;
}

void ItemApilable::decrementaNumElementos(int cantidad) {
    if (numElementos - cantidad < 1)
        throw std::out_of_range("ItemApilabre.cpp - decrementaNumElementos() - Un item apilable no puede tener menos de 1 unidad");
    numElementos -= cantidad;
}

unsigned int ItemApilable::getNumElementos() const {
    return numElementos;
}

std::string ItemApilable::getDescripcion() const {
    return "Un coso";
}
