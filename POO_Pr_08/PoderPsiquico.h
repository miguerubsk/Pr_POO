/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   PoderPsiquico.h
 * Author: Miguerubsk
 *
 * Created on 13 de abril de 2020, 19:03
 */

#ifndef PODERPSIQUICO_H
#define PODERPSIQUICO_H

#include "Poder.h"
#include <sstream>

class PoderPsiquico: public Poder {
public:
    PoderPsiquico();
    PoderPsiquico(std::string nombre, std::string descripcion, std::string afectaA, float capacidadDestructiva);
    PoderPsiquico(const PoderPsiquico& orig);
    
    float GetLucidez() const;
    float GetCapacidadDestructiva() const override;
    
    void SetLucidez(float lucidez);
    
    PoderPsiquico& operator=(const PoderPsiquico& right);
    bool operator>(const Poder& right) const override;
    
    std::string toCSV() const override;
    
    virtual ~PoderPsiquico();
private:
    float lucidez = 1;
};

#endif /* PODERPSIQUICO_H */

