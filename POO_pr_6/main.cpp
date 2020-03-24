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
#include "Escuadron.h"

using namespace std;

int main(int argc, char** argv) {
    string datosPilotos[5] = {
        "Dameron Poe;Jakku;100;123456;---",
        "Anakin Skywalker;Tatooine;133;126756;Derribados 3 cazas enemigos",
        "Han Solo;Corellia;247;126786;Impacto en motor izquierdo",
        "Chewbacca;Kashyyk;115;136786;---",
        "Leia Organa;Alderaan;3;126336;Derribados 10 cazas enemigos"};
    string datosNaves[5] = {
        "Kuat Systems;Delta-7;1",
        "Kuat Systems;Delta-7B;1",
        "Incom Corporation;T-65B X-wing;1",
        "Koensayr Manufacturing;Y-wing;2",
        "Kuat Systems;A-wing;1"};
    string datosDroides[5] = {
        "Industrial Automation;R2-D2;1",
        "Industrial Automation;R2-KT",
        "AccuTronics;R3-D3;",
        "AccuTronics;R3-KT",
        "Arakyd Industries;C3PO;"};


    Piloto pilotos[5];
    StarFighter s1, s2;
    s1.fromCSV(datosNaves[0]);
    s2.fromCSV(datosNaves[1]);
    s1.addPieza("Blaster izquierdo", 12, "Un blaster");
    s1.addPieza("Blaster derecho", 12, "Un blaster");
    s1.addPieza("Escudo de plasma", 23, "Un escudo");
    s2.addPieza("Blaster izquierdo", 12, "Un blaster");
    s2.addPieza("Blaster derecho", 12, "Un blaster");
    s2.addPieza("Bombas de racimo de plasma", 98, "Bombas que funcionan en el espacio");

    for (int i = 0; i < 5; ++i) {
        pilotos[i].fromCSV(datosPilotos[i]);
    }
    
    Escuadron e1("Escuadrón 1", "Tatooie"), e2("Escuadrón 2", "Hoth");
    e1.addPiloto(&pilotos[0]).addPiloto(&pilotos[1]);
    e2.addPiloto(&pilotos[2]).addPiloto(&pilotos[3]).addPiloto(&pilotos[4]);
    
    std::cout << e1.getNombre() << " - Promedio de misiones: " << e1.promedioMisiones() << std::endl;
    std::cout << e2.getNombre() << " - Promedio de misiones: " << e2.promedioMisiones() << std::endl;
    
    std::cout << s1.getModelo() << " - Peso: " << s1.calcularPeso() << "\n";
    std::cout << s2.getModelo() << " - Peso: " << s1.calcularPeso() << "\n";

    return 0;
}

