/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Garito.h
 * Author: Miguerubsk
 *
 * Created on 19 de febrero de 2020, 20:08
 */

#ifndef GARITO_H
#define GARITO_H
#include<iostream>

class Garito {
public:
    Garito();
    Garito(std::string nombre, std::string direccion);
    Garito(const Garito& orig);
    virtual ~Garito();
    
    std::string GetDireccion() const;
    std::string GetNombre() const;
    
    void SetDireccion(std::string Direccion);
    void SetNombre(std::string Nombre);
    
    std::string toCSV();
    
    static void mostrarGarito(Garito &G);
    static void modificarGarito(Garito &G);
private:
    std::string Nombre = "";
    std::string Direccion = "";

};

#endif /* GARITO_H */

