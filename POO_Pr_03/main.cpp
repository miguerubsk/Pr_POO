/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: Miguerubsk
 *
 * Created on 19 de febrero de 2020, 20:07
 */

#include <cstdlib>
#include "Fecha.h"
#include "Garito.h"
#include "Temazo.h"

/*
 *
 */
void menu() {
    std::cout << "========================MENÚ========================" << std::endl;
    std::cout << "0. Salir." << std::endl;
    std::cout << "1. Mostrar datos de los temazos." << std::endl;
    std::cout << "2. Mostrar datos de los garitos." << std::endl;
    std::cout << "3. Mostrar datos de las fechas." << std::endl;
    std::cout << "4. Modificar datos del segundo garito." << std::endl;
    std::cout << "====================================================" << std::endl;
    std::cout << "Elija una opción: ";
}

/*
 * 
 */
int main(int argc, char** argv) {
    Temazo temazos[20];
    Garito *pMiCasa = new Garito("Mi casa", "C/Hornillo");
    Garito *garitos[10];
    
    garitos[0] = new Garito("Hogar del Pensionista", "C/Arabial");
    garitos[1] = new Garito("La fábrica", "C/Cuesta");    
    
    delete pMiCasa;
    pMiCasa = nullptr;
    return 0;
}