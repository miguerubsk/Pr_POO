/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   ItemApilable.h
 * Author: Miguerubsk
 *
 * Created on 25 de abril de 2020, 16:28
 */

#ifndef ITEMAPILABLE_H
#define ITEMAPILABLE_H

#include "Item.h"

class ItemApilable : public Item {
public:
    ItemApilable() = default;
    ItemApilable(int cuantos);
    ItemApilable(const ItemApilable& orig);
    virtual ~ItemApilable();

    void incrementaNumElementos(int cantidad);
    void decrementaNumElementos(int cantidad);
    unsigned int getNumElementos() const;

    virtual std::string getDescripcion() const = 0;

protected:
    int numElementos = 1;

};

#endif /* ITEMAPILABLE_H */

