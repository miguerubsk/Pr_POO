/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   BloqueDeMadera.h
 * Author: Miguerubsk
 *
 * Created on 9 de mayo de 2020, 20:46
 */

#ifndef BLOQUEDEMADERA_H
#define BLOQUEDEMADERA_H

#include "ItemApilable.h"


class BloqueDeMadera: public ItemApilable {
public:
    BloqueDeMadera();
    BloqueDeMadera(unsigned int cuantos);
    BloqueDeMadera(const BloqueDeMadera& orig);
    virtual ~BloqueDeMadera();
    std::string getDescripcion() const override;

private:

};

#endif /* BLOQUEDEMADERA_H */

