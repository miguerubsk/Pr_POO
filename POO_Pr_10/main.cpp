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

    try {

        //Inicializamos algunos objetos de prueba
        int numObjetos = inicializaItems(objetos, MAXITEMS);

        Cofre c; //Creamos un cofre con 27 posiciones
        Inventario i;
        Cofre c2;

        try {
            i.mete(&c);
        } catch (std::exception &e) {
            //Capturamos cualquier excepción de la jerarquía que pueda generar
            //Consulta::mete. Es decir: out_of_range y invalid_argument
            std::cerr << "Error al intentar meter un cofre en el inventario: "
                    << e.what() << std::endl;
        }

        //Metemos todos los objetos en el cofre

        try {
            for (int i = 0; i < numObjetos; i++) {
                c.mete(objetos[i]);
            }
            c.mete(&c2);
        } catch (std::exception &e) {
            //Capturamos cualquier excepción de la jerarquía que pueda generar
            //Consulta::mete. Es decir: out_of_range y invalid_argument
            std::cerr << "Error al intentar meter un objeto en el cofre: "
                    << e.what() << std::endl;
        }

        visualiza(c);
        visualiza(i);
        
        Item *algo = &(i.consulta(i.cuantosHay()));
        
        Cofre *c3;
        c3 = dynamic_cast<Cofre*>(algo);
        
        if(c3)
            visualiza(*c3);

        //Liberamos recursos
        liberaItems(objetos, numObjetos);

    } catch (std::exception &e) {
        //Capturamos cualquier excepción que se haya podido escapar
        //En tiempo de desarrollo
        std::cerr << "Finalización del programa por excepción sin capturar: "
                << e.what() << std::endl;
    }
    return 0;
}

