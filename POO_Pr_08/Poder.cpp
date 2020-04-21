/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Poder.cpp
 * Author: Miguerubsk
 * 
 * Created on 4 de abril de 2020, 14:30
 */

#include "Poder.h"
#include <sstream>

Poder::Poder() {
}

Poder::Poder(std::string nombre, std::string descripcion, std::string afectaA, float capacidadDestructiva, bool inhibido):
nombre(nombre), descripcion(descripcion), afectaA(afectaA), capacidadDestructiva(capacidadDestructiva), inhibido(inhibido) {
}

Poder::Poder(const Poder& orig) {
    nombre = orig.nombre;
    descripcion = orig.descripcion;
    afectaA = orig.afectaA;
    capacidadDestructiva = orig.capacidadDestructiva;
    inhibido = orig.inhibido;
}

Poder::~Poder() {
}

std::string Poder::GetAfectaA() const {
    return afectaA;
}

float Poder::GetCapacidadDestructiva() const {
    return capacidadDestructiva;
}

std::string Poder::GetDescripcion() const {
    return descripcion;
}

std::string Poder::GetNombre() const {
    return nombre;
}

bool Poder::IsInhibido() const {
    return inhibido;
}

void Poder::SetInhibido(bool inhibido) {
    this->inhibido = inhibido;
}

void Poder::SetAfectaA(std::string afectaA) {
    this->afectaA = afectaA;
}

void Poder::SetCapacidadDestructiva(float capacidadDestructiva) {
    this->capacidadDestructiva = capacidadDestructiva;
}

void Poder::SetDescripcion(std::string descripcion) {
    this->descripcion = descripcion;
}

void Poder::SetNombre(std::string nombre) {
    this->nombre = nombre;
}

Poder& Poder::operator=(const Poder& right) {
    // Check for self-assignment!
    if (this == &right) // Same object?
        return *this; // Yes, so skip assignment, and just return *this.
    // Deallocate, allocate new space, copy values...
    nombre = right.nombre;
    descripcion = right.descripcion;
    afectaA = right.afectaA;
    capacidadDestructiva = right.capacidadDestructiva;
    return *this;
}

std::string Poder::toCSV() const {
    std::stringstream ss;
    ss << nombre << ";" << descripcion << ";" << afectaA << ";" << capacidadDestructiva;
    
    return ss.str();
}

bool Poder::operator>(const Poder& right) const {
    return this->capacidadDestructiva > right.capacidadDestructiva ? true : false;
}
