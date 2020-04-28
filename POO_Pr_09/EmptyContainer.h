/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   EmptyContainer.h
 * Author: Miguerubsk
 *
 * Created on 26 de abril de 2020, 18:49
 */

#ifndef EMPTYCONTAINER_H
#define EMPTYCONTAINER_H

#include <stdexcept>


class EmptyContainer: public std::domain_error {
public:
    EmptyContainer(std::string error):std::domain_error(error){};
    EmptyContainer(const EmptyContainer& orig):std::domain_error(orig){};
    virtual ~EmptyContainer() noexcept{};
private:

};

#endif /* EMPTYCONTAINER_H */

