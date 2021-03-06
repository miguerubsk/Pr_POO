/**
 * @file main.cpp
 * @author 
 *
 */

#include <iostream>
#include <fstream>
#include <sstream>
#include <future>
#include "EquipoMutante.h"

using namespace std;

/***@brief Visualiza la información completa de un mutante*/
void visualiza(Mutante& m) {
    std::cout << "MUTANTE: "
            << m.toCSV() << std::endl;
    std::cout << "  Poderes : " << std::endl;
    //ToDo, Mostrar los poderes del mutante
    for (int i = 0; i < m.getNumPoderes(); ++i) {
        std::cout << m.getPoder(i)->GetNombre() << std::endl;
    }
}

void visualiza(Mutante* m) {
    std::cout << "MUTANTE: "
            << m->toCSV() << std::endl;
    std::cout << "  Poderes : " << std::endl;
    //ToDo, Mostrar los poderes del mutante
    for (int i = 0; i < m->getNumPoderes(); ++i) {
        std::cout << "    " << m->getPoder(i)->GetNombre() << std::endl;
    }
}

/***@brief Visualiza los datos de todos los miembros de un equipo mutante*/
void visualiza(EquipoMutante& eq) {
    std::cout << "EQUIPO: " << eq.getNombre()
            << " (Base: " << eq.getBase() << ")" << std::endl
            << "============================"
            << std::endl;
    //ToDo, Mostrar los mutantes del equipo (usar función anterior)
    for (int i = 0; i < eq.getNumMiembros(); ++i) {
        std::cout << eq.getMutante(i)->getApodo() << std::endl;
    }
}

//ToDo, Método para almacenar un vector de punteros a mutantes

void almacenaMutantesCSV(Mutante* v[], int tamv, string nombreArchivo) {
    ofstream fs;
    fs.open(nombreArchivo, ofstream::trunc);
    if (fs.good()) {
//        fs << "NombreReal;Apodo;FechaDeNacimiento;Nacionalidad" << endl;
        for (int i = 0; i < tamv; ++i) {
            fs << v[i]->toCSV() << endl;
        }
        fs.close();
    } else {
        std::cerr << "No se puede crear el fichero" << endl;
    }
}

void recuperaMutantesCSV(Mutante* v[], int tamv, string nombreArchivo){
    ifstream fe;
    string linea;
    string Nombre, apodo, fecha, nacionalidad;
    int total = 0;
    
    fe.open(nombreArchivo);
    if(fe.good()){
//        getline(fe, linea);
        getline(fe, linea);
        while(!fe.eof() && total < tamv){
            stringstream ss;
            ss << linea;
            
            getline(ss, Nombre, ';');
            getline(ss, apodo, ';');
            getline(ss, fecha, ';');
            getline(ss, nacionalidad, ';');
            v[total] = new Mutante(Nombre, apodo, stoi(fecha), nacionalidad);
            getline(fe, linea);
            ++total;
        }
        fe.close();
    }else{
        std::cerr << "No se puede abrir el fichero" << std::endl;
    }
}

void almacenaEquipoCSV(EquipoMutante& eq, string nombreArchivo) {
    ofstream fs;
    fs.open(nombreArchivo, ofstream::trunc);
    if (fs.good()) {
        fs << "EQUIPO: " << eq.getNombre()
                << " (Base: " << eq.getBase() << ")" << std::endl
                << "============================"
                << std::endl;
        //ToDo, Mostrar los mutantes del equipo (usar función anterior)
        for (int i = 0; i < eq.getNumMiembros(); ++i) {
            fs << eq.getMutante(i)->getApodo() << std::endl;
        }
        fs.close();
    }else{
        std::cerr << "No se puede crear el fichero" << endl;
    }
}

int main(int argc, char** argv) {


    // Crea un array de 5 punteros a mutantes, asignándoles los valores a sus
    // atributos directamente en el código fuente

    Mutante *mutantes[5];
    recuperaMutantesCSV(mutantes, 5, "DatosMutantes.txt");
//    mutantes[0] = new Mutante("Lucas", "Riuca", 202006, "Tazmily");
//    mutantes[1] = new Mutante("Claus", "Masked Man", 202006, "Tazmily");
//    mutantes[2] = new Mutante("Ness", "Giygas", 271994, "Onett");
//    mutantes[3] = new Mutante("Kumatora", "Violet", 202006, "Osohe");
//    mutantes[4] = new Mutante("Duster", "Wess", 202006, "Tazmily");

    


    // Añade varios poderes a cada mutante, utilizando los métodos ya
    // implementados: usando datos o objetos de tipo Poder
    mutantes[0]->addPoderPsiquico("PSI Rockin", "Utiliza rocas para atacar", "Todos los enemigos", 640);
    mutantes[0]->addPoderPsiquico("PSI Healing", "Elimina estados alterados", "Un solo aliado", 0);
    mutantes[0]->addPoder("PK Fire", "Lanza fuego", "Un enemigo", 120);

    mutantes[1]->addPoder("PSI Teleport", "Permite teletransportarse", "Usuario", 0);
    mutantes[1]->addPoder("PSI Flash", "Deja ciegos a los enemigos", "Todos los enemigos", 20);
    mutantes[1]->addPoder("PK Freeze", "Congela un objetivo", "Un enemigo", 10);

    mutantes[2]->addPoder("PK Starstorm", "Provoca una lluvia de meteroritos", "Todos los enemigos", 1020);
    mutantes[2]->addPoder("PK Fire", "Lanza fuego", "Un enemigo", 100);
    mutantes[2]->addPoderPsiquico("PSI Rockin", "Utiliza rocas para atacar", "Todos los enemigos", 650);

    mutantes[3]->addPoder("PK Freeze", "Congela un objetivo", "Un enemigo", 120);
    mutantes[3]->addPoder("PK Thunder", "Electrocuta", "Un enemigo", 300);
    mutantes[3]->addPoder("PK Starstorm", "Provoca una lluvia de meteroritos", "Todos los enemigos", 2600);
    mutantes[3]->getPoder(2)->SetInhibido(true);

    mutantes[4]->addPoderPsiquico("PSI LiveUp", "Sana a los aliados", "Un solo aliado", 0);
    mutantes[4]->addPoder("PK Fire", "Lanza fuego", "Un enemigo", 300);
    mutantes[4]->addPoderPsiquico("Asfixia", "Ahoga al enemigo", "biologico", 600);
    //Guardamos datos de mutantes en fichero CSV
    almacenaMutantesCSV(mutantes, 5, "DatosMutantes.txt");
    
    for(int i = 0; i < 5; ++i){
        visualiza(mutantes[i]);
    }
    
    cout << "Poder destructivo: " << mutantes[3]->capacidadDestructivaTotal();

    // Destruye todos los objetos creados en memoria dinámica antes de la
    // finalización del programa
    for (int i = 0; i < 5; ++i){
        delete mutantes[i];
    }


    return 0;
}

