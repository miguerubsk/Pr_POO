/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   PoderPsiquico.cpp
 * Author: Miguerubsk
 * 
 * Created on 13 de abril de 2020, 19:03
 */

#include "PoderPsiquico.h"

PoderPsiquico::PoderPsiquico(): Poder() {
}

PoderPsiquico::PoderPsiquico(std::string nombre, std::string descripcion, std::string afectaA, float capacidadDestructiva) :
Poder(nombre, descripcion, afectaA, capacidadDestructiva) {
}


PoderPsiquico::PoderPsiquico(const PoderPsiquico& orig): Poder(orig) {
}

PoderPsiquico& PoderPsiquico::operator=(const PoderPsiquico& right) {
    // Check for self-assignment!
    if (this == &right) // Same object?
        return *this; // Yes, so skip assignment, and just return *this.
    // Deallocate, allocate new space, copy values...
    this->Poder::operator =(right);
    this->lucidez = right.lucidez;
    return *this;
}

float PoderPsiquico::GetLucidez() const {
    return lucidez;
}

void PoderPsiquico::SetLucidez(float lucidez) {
    if(lucidez < 0 || lucidez > 1)
        throw std::invalid_argument("PoderPsiquico.cpp - SetLucidez() - debe ser un valor entre 0 y 1");
    this->lucidez = lucidez;
}


PoderPsiquico::~PoderPsiquico() {
}

float PoderPsiquico::GetCapacidadDestructiva() const {
    return lucidez*this->Poder::GetCapacidadDestructiva();
}


std::string PoderPsiquico::toCSV() const {
    std::stringstream ss;
    ss << this->Poder::GetNombre() << ";" << this->Poder::GetDescripcion() << ";" << this->Poder::GetAfectaA() << ";" << this->Poder::GetCapacidadDestructiva() << ";" << lucidez;
    
    return ss.str();
}

bool PoderPsiquico::operator>(const Poder& right) const {
    return this->GetCapacidadDestructiva() > right.GetCapacidadDestructiva() ? true : false;
}
