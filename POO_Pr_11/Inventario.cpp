/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Inventario.cpp
 * Author: Miguerubsk
 * 
 * Created on 5 de mayo de 2020, 13:55
 */

#include "Inventario.h"
#include "Escudo.h"

Inventario::Inventario() {
}

Inventario::Inventario(const Inventario& orig) {
}

Inventario::~Inventario() {
}

void Inventario::mete(Item* item) {
    if (!item)
        throw std::invalid_argument("[Inventario::mete] Intento de asignar puntero 0");
    if (_numItems == _maxItems)
        throw std::out_of_range("[Inventario::mete] No caben más elementos en el cofre");
    _items[_numItems++] = item;
}

Item* Inventario::getEspada() const {
    return espada;
}

void Inventario::usarItem(Item& item) {
    Espada *esp = dynamic_cast<Espada*> (&item);
    Escudo *esc = dynamic_cast<Escudo*> (&item);
    if (!esp && !esc)
        throw std::invalid_argument("Inventario::usarItem - Sólo se pueden asignar espadas");
    if (esp) {
        if (espada) {
            mete(espada);
            espada = esp;
        } else {
            espada = esp;
        }
    }
    if (esc) {
        if (escudo) {
            mete(escudo);
            escudo = esc;
        } else {
            escudo = esc;
        }
    }

}
