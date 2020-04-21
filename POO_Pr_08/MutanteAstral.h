/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   MutanteAstral.h
 * Author: Miguerubsk
 *
 * Created on 21 de abril de 2020, 18:58
 */

#ifndef MUTANTEASTRAL_H
#define MUTANTEASTRAL_H

#include "Mutante.h"


class MutanteAstral: public Mutante {
public:
    static const int MAX_PODERES = 1;
    MutanteAstral();
    MutanteAstral(const MutanteAstral& orig);
    
    void addPoder(const Poder& poder) override;
    void addPoderPsiquico(const PoderPsiquico& poder) override;
    float capacidadDestructivaTotal() const override;
    void addPoderPsiquico(string nombre, string descripcion, string afectaA, float capacidadD) override;
    
    virtual ~MutanteAstral();
private:
    bool usar = true;
    
};

#endif /* MUTANTEASTRAL_H */

