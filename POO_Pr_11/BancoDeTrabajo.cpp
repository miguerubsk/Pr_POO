/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   BancoDeTrabajo.cpp
 * Author: Miguerubsk
 * 
 * Created on 9 de mayo de 2020, 18:48
 */

#include "BancoDeTrabajo.h"
#include "BloqueDeMadera.h"

BancoDeTrabajo::BancoDeTrabajo() : Contenedor(9) {
}

BancoDeTrabajo::BancoDeTrabajo(const BancoDeTrabajo& orig) : Contenedor(orig) {
}

BancoDeTrabajo::~BancoDeTrabajo() {
}

Espada* BancoDeTrabajo::construirEspada() {
    for (int i = 0; i < this->cuantosHay(); ++i) {
        BloqueDeMadera *bloque = dynamic_cast<BloqueDeMadera*> (&consulta(i+1));
        if (bloque && bloque->getNumElementos() > 2) {
            bloque->decrementaNumElementos(3);
            if (bloque->getNumElementos() == 0)
                saca(i+1);
            return new Espada();
        }
    }
    return nullptr;
}