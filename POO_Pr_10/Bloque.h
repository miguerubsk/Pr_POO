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

#include "ItemApilable.h"

/**@Brief Clase base para bloques de construcción*/
class Bloque: public ItemApilable {
public:
    Bloque();
    Bloque(unsigned int cuantos);
    Bloque(const Bloque& orig);
    virtual ~Bloque();
    virtual std::string getDescripcion() const;
private:
    

};

#endif /* BLOQUE_H */

