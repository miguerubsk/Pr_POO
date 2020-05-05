/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   cofre.cpp
 * Author: Miguerubsk
 *
 * Created on 25 de abril de 2020, 16:25
 */

#include "Cofre.h"
#include "EmptyContainer.h"
#include <stdexcept>

Cofre::Cofre(): ContenedorItems(){}

/**Crea un Cofre vacío del mismo tamaño del original*/
Cofre::Cofre(const Cofre& orig): ContenedorItems(orig){    
}

Cofre::~Cofre() {}

void Cofre::mete(Item* item) {
    if (!item) 
        throw std::invalid_argument ("[Cofre::mete] Intento de asignar puntero 0");
    if (_numItems==_maxItems)
        throw std::out_of_range("[Cofre::mete] No caben más elementos en el cofre");
    _items[_numItems++]=item;
}
