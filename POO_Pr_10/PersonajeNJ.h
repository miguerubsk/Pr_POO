/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   PersonajeNJ.h
 * Author: Miguerubsk
 *
 * Created on 5 de mayo de 2020, 18:37
 */

#ifndef PERSONAJENJ_H
#define PERSONAJENJ_H

#include <string>

class PersonajeNJ {
public:
    PersonajeNJ();
    PersonajeNJ(std::string descripcion);
    PersonajeNJ(const PersonajeNJ& orig);
    virtual ~PersonajeNJ();
    
    std::string getDescripcion() const;
    void SetDescripcion(std::string descripcion);
    
private:
    std::string descripcion;
};

#endif /* PERSONAJENJ_H */

