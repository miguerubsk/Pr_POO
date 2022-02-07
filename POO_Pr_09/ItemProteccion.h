/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   ItemProteccion.h
 * Author: Miguerubsk
 *
 * Created on 28 de abril de 2020, 18:24
 */

#ifndef ITEMPROTECCION_H
#define ITEMPROTECCION_H

#include "Bloque.h"

class ItemProteccion : public Item {
public:

    ItemProteccion(int puntosDeProteccion, int usos) : puntosDeProteccion(puntosDeProteccion), usos(usos) {
    };
    ItemProteccion(const ItemProteccion &orig) = default;
    virtual bool esEquipable() override;
    virtual std::string getDescripcion() const override;
    virtual int reducir(int damage) = 0;

    int getPuntosDeProteccion() const {
        return puntosDeProteccion;
    }

    int getUsos() const {
        return usos;
    }

    virtual ~ItemProteccion() = default;
protected:
    int puntosDeProteccion;
    int usos;
};

#endif /* ITEMPROTECCION_H */

