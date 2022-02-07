/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   BancoDeTrabajo.h
 * Author: Miguerubsk
 *
 * Created on 9 de mayo de 2020, 18:48
 */

#ifndef BANCODETRABAJO_H
#define BANCODETRABAJO_H

#include "Contenedor.h"
#include "Item.h"
#include "Espada.h"


class BancoDeTrabajo: public Contenedor<Item> {
public:
    BancoDeTrabajo();
    BancoDeTrabajo(const BancoDeTrabajo& orig);
    virtual ~BancoDeTrabajo();
    
    Espada* construirEspada();
    
private:

};

#endif /* BANCODETRABAJO_H */

