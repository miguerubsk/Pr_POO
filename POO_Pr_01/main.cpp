/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: Miguerubsk
 *
 * Created on 4 de febrero de 2020, 13:59
 */

#include <cstdlib>
#include <iostream>
#include "vehiculo.h"

/*
 * 
 */

/*
 * 
 */
int main(int argc, char** argv) {

    int tam=0;
    while (tam <= 0) {
        std::cout << "Introduce el número de vehiculos: ";
        std::cin>>tam;
    }

    Vehiculo *rodolfo;
    rodolfo = new Vehiculo[tam];

    try {
        Vehiculos::rellenarVector(rodolfo, tam);
    } catch (std::invalid_argument &e) {
        std::cerr << e.what() << std::endl;
    } catch (std::length_error &e) {
        std::cerr << e.what() << std::endl;
    }

    Vehiculos::mostrarEnPantalla(rodolfo, tam);
    Vehiculos::muestraEnPantalla(rodolfo[Vehiculos::maxPrecio(rodolfo, tam)]);

    try {
        Vehiculos::leePorTeclado(rodolfo[Vehiculos::buscarPorMatricula("123456", rodolfo, tam)]);
    } catch (std::domain_error &e) {
        std::cerr << e.what() << std::endl;
    } catch (std::invalid_argument &e) {
        std::cerr << e.what() << std::endl;
    } catch (std::length_error &e) {
        std::cerr << e.what() << std::endl;
    }

    delete rodolfo;

    return 0;
}

