/** 
 * @file main.cpp
 * @author Casipro Gramo 
 * @author Yoyapro GRamo
 *
 * @date Fecha estelar 20160309
 */

#include <cstdlib>
#include <string>
#include <iostream>

#include "Piloto.h"

using namespace std;

int main(int argc, char** argv) {
    string datosPilotos[5] = {"Dameron Poe;Jakku;100;123456;---",
        "Anakin Skywalker;Tatooine;133;126756;Derribados 3 cazas enemigos",
        "Han Solo;Corellia;247;126786;Impacto en motor izquierdo",
        "Chewbacca;Kashyyk;115;136786;---",
        "Leia Organa;Alderaan;3;126336;Derribados 10 cazas enemigos"};
    string datosNaves[5] = {"Kuat Systems;Delta-7;1",
        "Kuat Systems;Delta-7B;1",
        "Incom Corporation;T-65B X-wing;1",
        "Koensayr Manufacturing;Y-wing;2",
        "Kuat Systems;A-wing;1"};
    string datosDroides[5] = {"Industrial Automation;R2-D2;1",
        "Industrial Automation;R2-KT",
        "AccuTronics;R3-D3;",
        "AccuTronics;R3-KT",
        "Arakyd Industries;C3PO;"};


    Piloto pilotos[5];
    Droide droides[5];
    StarFighter naves[5];

    for (int i = 0; i < 5; ++i) {
        pilotos[i].fromCSV(datosPilotos[i]);
        droides[i].fromCSV(datosDroides[i]);
        naves[i].fromCSV(datosNaves[i]);
    }
    try{
        pilotos[0].setAuxiliar(&droides[2]);
    }catch(std::invalid_argument &e){
        std::cerr << e.what() << std::endl;
    }
    pilotos[0].setNave(&naves[1]);
    try{
        pilotos[1].setAuxiliar(&droides[0]);
    }catch(std::invalid_argument &e){
        std::cerr << e.what() << std::endl;
    }
    pilotos[1].setNave(&naves[3]);
    try{
        pilotos[2].setAuxiliar(&droides[1]);
    }catch(std::invalid_argument &e){
        std::cerr << e.what() << std::endl;
    }
    pilotos[2].setNave(&naves[0]);

    Informe i1 = pilotos[0].generaInforme();
    Informe i2 = pilotos[1].generaInforme();
    Informe i3 = pilotos[2].generaInforme();

    std::cout << i1.toCSV() << std::endl << i2.toCSV() << std::endl;
    
    std::cout << droides[0].toCSV();

    return 0;
}

