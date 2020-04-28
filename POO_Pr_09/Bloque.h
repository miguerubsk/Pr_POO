/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Bloque.h
 * Author: Miguerubsk
 *
 * Created on 25 de abril de 2020, 16:25
 */

#ifndef BLOQUE_H
#define BLOQUE_H

#include "Item.h"
#include "ItemApilable.h"


class Bloque: public ItemApilable {
public:
    Bloque();
    Bloque(unsigned int cuantos);
    Bloque(const Bloque& orig);
    virtual ~Bloque();
    virtual std::string getDescripcion() const;
    bool esEquipable() override;

private:
    

};

#endif /* BLOQUE_H */

