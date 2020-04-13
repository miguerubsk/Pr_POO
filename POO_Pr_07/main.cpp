/**
 * @file main.cpp
 * @author 
 *
 */

#include <iostream>
#include <fstream>
#include <sstream>
#include "EquipoMutante.h"

using namespace std;

/***@brief Visualiza la información completa de un mutante*/
void visualiza( Mutante& m) {
    std::cout << "MUTANTE: " 
              << m.toCSV() << std::endl;
    std::cout << "  Poderes : " << std::endl;
    //ToDo, Mostrar los poderes del mutante
    for(int i = 0; i < m.getNumPoderes(); ++i){
        std::cout << m.getPoder(i)->GetNombre() << std::endl;
    }

}
/***@brief Visualiza los datos de todos los miembros de un equipo mutante*/
void visualiza( EquipoMutante& eq) {
    std::cout << "EQUIPO: " << eq.getNombre() 
              << " (Base: " << eq.getBase()<< ")" <<std::endl
              << "============================"
              << std::endl;
    //ToDo, Mostrar los mutantes del equipo (usar función anterior)
    for(int i = 0; i < eq.getNumMiembros(); ++i){
        std::cout << eq.getMutante(i)->getApodo() << std::endl;
    }
}

//ToDo, Método para almacenar un vector de punteros a mutantes
void almacenaMutantesCSV(Mutante* v[], int tamv, std::string nombreArchivo){
    ofstream fs;
    fs.open(nombreArchivo, ofstream::trunc);
    if (fs.good()) {
        fs << "NombreReal;Apodo;FechaDeNacimiento;Nacionalidad" << endl;
        for(int i = 0; i < tamv; ++i){
            fs << v[i]->toCSV();
        }
        fs.close();
    }else{
        std::cerr << "No se puede crear el fichero" << endl;
    }
}


int main(int argc, char** argv) {

    
   // Crea un array de 5 punteros a mutantes, asignándoles los valores a sus
   // atributos directamente en el código fuente

    
   // Crea dos equipos mutantes, asignando al primero los mutantes que ocupan
   // las posiciones pares del array, y al segundo los de las posiciones impares
    
    
   // Añade varios poderes a cada mutante, utilizando los métodos ya
   // implementados: usando datos o objetos de tipo Poder
   // Muestra por la consola la información de cada equipo mutante en formato CSV

    
   //Guardamos datos de mutantes en fichero CSV
    
    
   // Destruye todos los objetos creados en memoria dinámica antes de la
   // finalización del programa

    
    
    return 0;
}

