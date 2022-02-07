/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   EmptyContainer.cpp
 * Author: Miguerubsk
 *
 * Created on 25 de abril de 2020, 16:25
 */

#include <string>

#include "EmptyContainer.h"

EmptyContainer::EmptyContainer(std::string error)
    :std::domain_error(error){
}

EmptyContainer::EmptyContainer(const EmptyContainer& orig)
    :std::domain_error(orig) {
}

EmptyContainer::~EmptyContainer() noexcept {
}

