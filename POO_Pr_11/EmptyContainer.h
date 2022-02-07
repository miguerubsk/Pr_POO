/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   EmptyContainer.h
 * Author: Miguerubsk
 *
 * Created on 25 de abril de 2020, 16:25
 */

#ifndef EMPTYCONTAINER_H
#define EMPTYCONTAINER_H

#include <stdexcept>

/**@brief Excepción para indicar intentos de extracción sobre un contenedor  vacío*/
class EmptyContainer: public std::domain_error {
public:
    EmptyContainer(std::string error);
    EmptyContainer(const EmptyContainer& orig);
    virtual ~EmptyContainer() noexcept;
private:

};

#endif /* EMPTYCONTAINER_H */

