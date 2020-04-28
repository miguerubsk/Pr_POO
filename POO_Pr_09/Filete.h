/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Filete.h
 * Author: Miguerubsk
 *
 * Created on 25 de abril de 2020, 16:24
 */

#ifndef FILETE_H
#define FILETE_H

#include "Item.h"


class Filete: public Item {
public:
    Filete();
    Filete(const Filete& orig);
    virtual ~Filete();
    
    std::string getDescripcion() const override;
    bool esEquipable() override;
    
private:
    std::string descripcion;
};

#endif /* FILETE_H */

