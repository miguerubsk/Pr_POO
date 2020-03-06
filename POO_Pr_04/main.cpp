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
    Temazo temazos[5];
    Garito *garitos[10];
    
    garitos[0] = new Garito();
    garitos[1] = new Garito();    
    garitos[0]->SetNombre("Hogar del Pensionista");
    garitos[0]->SetDireccion("C/Arabial");
    garitos[1]->SetNombre("La fábrica");
    garitos[1]->SetDireccion("C/Cuesta");
    
    temazos[0].SetTitulo("Soldiers").SetGenero("House").SetInterprete("Nitro Fun").SetNombreUltimoGarito("La Fábrica").SetDuracion(300);
    temazos[1].SetTitulo("Fourty Nine Yards").SetGenero("LoFi HipHop").SetInterprete("Alex").SetNombreUltimoGarito("La Fábrica").SetDuracion(261);
    temazos[2].SetTitulo("Breath").SetGenero("LoFi HipHop").SetInterprete("Nohone").SetNombreUltimoGarito("Hogar del Pensionista").SetDuracion(420);
    
    for(int i=0; i<5; ++i){
        std::cout << temazos[i].toCSV() << std::endl;;
    }
    
    for(int i = 0; i < 2; ++i){
        std::cout << garitos[i]->toCSV() << std::endl;
    }
    
    return 0;
}