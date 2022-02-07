/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Espada.h
 * Author: Miguerubsk
 *
 * Created on 25 de abril de 2020, 16:24
 */

#ifndef ESPADA_H
#define ESPADA_H

#include "Item.h"


class Espada: public Item {
public:
    Espada() = default;
    Espada(const Espada& orig);
    virtual ~Espada();

    virtual std::string getDescripcion() const;
    bool esEquipable() override;

private:
};

#endif /* ESPADA_H */

