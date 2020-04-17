/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   PoderFisico.h
 * Author: Miguerubsk
 *
 * Created on 13 de abril de 2020, 19:03
 */

#ifndef PODERFISICO_H
#define PODERFISICO_H

#include "Poder.h"


class PoderFisico: public Poder {
public:
    PoderFisico();
    PoderFisico(std::string nombre, std::string descripcion, std::string afectaA, float capacidadDestructiva);

    PoderFisico(const PoderFisico& orig);
    
    PoderFisico& operator=(const PoderFisico& right);

    
    virtual ~PoderFisico();
private:

};

#endif /* PODERFISICO_H */

