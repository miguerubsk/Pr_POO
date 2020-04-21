/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   MutanteAstral.cpp
 * Author: Miguerubsk
 * 
 * Created on 21 de abril de 2020, 18:58
 */

#include "MutanteAstral.h"

MutanteAstral::MutanteAstral() {
}

MutanteAstral::MutanteAstral(const MutanteAstral& orig) {
}

MutanteAstral::~MutanteAstral() {
    delete poderes[0];
}

void MutanteAstral::addPoderPsiquico(const PoderPsiquico& poder) {
    if(this->getNumPoderes() == 1)
        throw std::out_of_range("MutanteAstral.cpp - addPoderPsiquico() - No se pueden añadir más poderes");
    poderes[numPoderes] = new Poder(poder);
    ++numPoderes;
}

void MutanteAstral::addPoderPsiquico(string nombre, string descripcion, string afectaA, float capacidadD) {
    if(this->getNumPoderes() == 1)
        throw std::out_of_range("MutanteAstral.cpp - addPoderPsiquico() - No se pueden añadir más poderes");
    poderes[numPoderes] = new Poder(nombre, descripcion, afectaA, capacidadD);
    ++numPoderes;
}

float MutanteAstral::capacidadDestructivaTotal() const {
    if(!usar)
        throw std::out_of_range("MutanteAstral.cpp - capacidadDestructivaTotal() - No es posible volver a uasr el poder");
    usar = false;
    return poderes[0]->GetCapacidadDestructiva();
}
