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
    Temazo temazo1, temazo2("Soldiers", "Nitro Fun", 236, 10);
    Garito garito1("Hogar del Pensionista", "C/Arabial"), garito2(garito1);
    Fecha fecha1, fecha2(19, 7, 2005);
    std::string genero;
    try{
        std::cout << "Introduce el genero del temazo 1: ";
        std::cin >> genero;        
        temazo1.SetGenero(genero);
    }catch(std::invalid_argument &e){
        std::cerr << e.what() << std::endl;
    }
    try{
        std::cout << "Introduce el genero del temazo 2: ";
        std::cin >> genero;
        temazo2.SetGenero(genero);
    }catch(std::invalid_argument &e){
        std::cerr << e.what() << std::endl;
    }
    
    int op;
    do {
        menu();
        std::cin >> op;
        switch (op) {
            case 0:
                break;
            case 1:
                Temazo::mostrarTemazo(temazo1);
                Temazo::mostrarTemazo(temazo2);
                break;
            case 2:
                Garito::mostrarGarito(garito1);
                Garito::mostrarGarito(garito2);
                break;
            case 3:
                Fecha::mostrarFecha(fecha1);
                Fecha::mostrarFecha(fecha2);
                break;
            case 4:
                try {
                    Garito::modificarGarito(garito2);
                } catch (std::invalid_argument &e) {
                    std::cerr << e.what();
                }
                std::cout << "Mostrando el garito tras modificarlo: " << std::endl;
                Garito::mostrarGarito(garito2);
                break;
        }

    } while (op != 0);
    
    Temazo prueba;
    try{
        prueba.SetDuracion(op).SetGenero(genero);
    }catch(std::invalid_argument &e){
        std::cerr << e.what() << std::endl;
    }
    

    return 0;
}

