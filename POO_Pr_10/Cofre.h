/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   cofre.h
 * Author: Miguerubsk
 *
 * Created on 25 de abril de 2020, 16:25
 */

#include "Item.h"
#include "Contenedor.h"
#include <string>

#ifndef COFRE_H
#define COFRE_H

class Cofre: public Item, public Contenedor<Item> {
public:
    Cofre();
    Cofre(int cuantosCaben);
    Cofre(const Cofre& orig);
    virtual ~Cofre();
    
    void mete(Item* item) override;
    std::string getDescripcion() const override;

};

#endif /* COFRE_H */

