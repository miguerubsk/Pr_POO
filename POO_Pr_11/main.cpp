/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: Miguerubsk
 *
 * Created on 25 de abril de 2020, 16:25
 */

#include <cstdlib>
#include <iostream>

#include "Cofre.h"
#include "Item.h"
#include "Bloque.h"
#include "Espada.h"
#include "Filete.h"
#include "Inventario.h"
#include "PersonajeNJ.h"
#include "Escudo.h"
#include "BancoDeTrabajo.h"
#include "BloqueDeMadera.h"

using namespace std;

/**Inicializa el vector de items inicial
 * @pre v no contiene punteros inicializados
 * @post crea algunos objetos en el vector e inicializa el resto de elementos a 0
 * @return número de posiciones del vector con items creados*/
int inicializaItems(Item* v[], int tamv) {
    int numItems = 0;

    v[numItems++] = new Bloque(5);
    v[numItems++] = new Bloque(8);
    v[numItems++] = new Bloque();
    v[numItems++] = new Espada();
    v[numItems++] = new Filete();
    v[numItems++] = new Escudo();

    //Asigna a nullptr el resto de posiciones no ocupadas
    for (int i = numItems; i < tamv; i++) {
        v[i] = nullptr;
    }
    return numItems;
}

/**Libera los items del vector creados en memoria dinámica*/
void liberaItems(Item* v[], int numItems) {
    for (int i = 0; i < numItems; i++) {
        delete v[i];
        v[i] = nullptr;
    }

}

template <typename T>
void visualiza(Contenedor<T> &c) {
    std::cout << "CONTENIDO DEL CONTENEDOR" << std::endl
            << "===================" << std::endl;
    for (int i = 1; i <= c.cuantosHay(); i++) {
        std::cout << i << ".- "
                << c.consulta(i).getDescripcion() << std::endl;
    }

}

/**@brief Probando los Cofres
 * 
 */
int main(int argc, char** argv) {

    const int MAXITEMS = 10;
    Item * objetos[MAXITEMS];
    Contenedor<PersonajeNJ> personajes;
    personajes.mete(new PersonajeNJ("Creeper"));
    personajes.mete(new PersonajeNJ("Zombie"));
    personajes.mete(new PersonajeNJ("Aldeano"));
    personajes.mete(new PersonajeNJ("Araña"));
    personajes.mete(new PersonajeNJ("Esqueleto"));
    personajes.mete(new PersonajeNJ("Vaca"));
    
    BancoDeTrabajo banco;
    banco.mete(new Bloque());
    banco.mete(new BloqueDeMadera(6));
    
    
//    std::cout << bloque->getDescripcion() << ", cantidad: " << bloque->getNumElementos() << std::endl;
    
    Espada *espada = banco.construirEspada();
    if(espada)
        std::cout << espada->getDescripcion() << std::endl;
    
    BloqueDeMadera *bloque = dynamic_cast<BloqueDeMadera*> (&banco.consulta(2));
    std::cout << bloque->getDescripcion() << ", cantidad: " << bloque->getNumElementos();
    banco.construirEspada();
    std::cout << banco.cuantosHay() << std::endl;
    
    espada = banco.construirEspada();
    if(!espada)
        std::cout << "No se ha podido construir la espada\n";
    
    return 0;
}

