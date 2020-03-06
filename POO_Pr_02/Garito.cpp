/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Garito.cpp
 * Author: Miguerubsk
 * 
 * Created on 19 de febrero de 2020, 20:08
 */

#include "Garito.h"

Garito::Garito() : Nombre(""), Direccion("") {
}

Garito::Garito(std::string nombre, std::string direccion) : Nombre(nombre), Direccion(direccion) {

}

Garito::Garito(const Garito& orig) {
    Nombre = orig.Nombre;
    Direccion = orig.Direccion;
}

Garito::~Garito() {
}

void Garito::mostrarGarito(Garito& G) {
    std::cout << "Nombre: " << G.GetNombre() << std::endl;
    std::cout << "Dirección: " << G.GetDireccion() << std::endl;
}

void Garito::modificarGarito(Garito& G) {
    std::string aux;

    std::cout << "Introduzca un nombre para el garito: ";
    std::cin >> aux;
    G.SetNombre(aux);

    std::cout << "Introduzca una diracción para el garito: ";
    std::cin >> aux;
    G.SetDireccion(aux);

}

void Garito::SetDireccion(std::string Direccion) {
    if (Direccion == "")
        throw std::invalid_argument("Garito::SetDireccion() -> La direccion no puede estar vacía");
    this->Direccion = Direccion;
}

std::string Garito::GetDireccion() const {
    return Direccion;
}

void Garito::SetNombre(std::string Nombre) {
    if (Nombre == "")
        throw std::invalid_argument("Garito::SetNombre() -> El nombre no puede estar vacío");
    this->Nombre = Nombre;
}

std::string Garito::GetNombre() const {
    return Nombre;
}

