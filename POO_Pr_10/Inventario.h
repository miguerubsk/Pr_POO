/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Inventario.h
 * Author: Miguerubsk
 *
 * Created on 5 de mayo de 2020, 13:55
 */

#ifndef INVENTARIO_H
#define INVENTARIO_H

#include "Item.h"
#include "Contenedor.h"


class Inventario: public Contenedor<Item> {
public:
    Inventario();
    Inventario(const Inventario& orig);
    virtual ~Inventario();
    
    void mete(Item* item) override;

private:

};

#endif /* INVENTARIO_H */

