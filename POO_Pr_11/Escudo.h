/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Escudo.h
 * Author: Miguerubsk
 *
 * Created on 5 de mayo de 2020, 18:51
 */

#ifndef ESCUDO_H
#define ESCUDO_H

#include <string>
#include "Item.h"

class Escudo: public Item {
public:
    Escudo();
    Escudo(const Escudo& orig);
    virtual ~Escudo();
    
    std::string getDescripcion() const override;

private:

};

#endif /* ESCUDO_H */

