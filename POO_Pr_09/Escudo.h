/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Escudo.h
 * Author: Miguerubsk
 *
 * Created on 28 de abril de 2020, 19:17
 */

#ifndef ESCUDO_H
#define ESCUDO_H

#include "ItemProteccion.h"


class Escudo: public ItemProteccion {
public:
    Escudo();
    Escudo(const Escudo& orig) = default;
    virtual ~Escudo() = default;
    bool esEquipable() override;
    std::string getDescripcion() const override;
    int reducir(int damage) override;



private:

};

#endif /* ESCUDO_H */

