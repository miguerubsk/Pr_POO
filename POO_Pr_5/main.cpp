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
    string datosDroides[5] = {"Industrial Automation;R2-D2",
        "Industrial Automation;R2-KT",
        "AccuTronics;R3-D3",
        "AccuTronics;R3-KT",
        "Arakyd Industries;C3PO"};


    Piloto pilotos[5];
    Droide droides[5];
    StarFighter naves[5];

    for (int i = 0; i < 5; ++i) {
        pilotos[i].fromCSV(datosPilotos[i]);
        droides[i].fromCSV(datosDroides[i]);
        naves[i].fromCSV(datosNaves[i]);
    }

    pilotos[1].setNave(&naves[2]).setAuxiliar(&droides[3]);
    pilotos[2].setAuxiliar(&droides[1]).setNave(&naves[2]);
    pilotos[3].setAuxiliar(&droides[2]).setNave(&naves[1]);

    Informe i1 = pilotos[1].generaInforme();
    Informe i2 = pilotos[2].generaInforme();

    std::cout << i1.toCSV() << std::endl << i2.toCSV() << std::endl;

    return 0;
}

