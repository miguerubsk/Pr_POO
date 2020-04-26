/**
 * @file Mutante.cpp
 * @author algarcia
 *
 */

#include <stdexcept>
#include <sstream>

#include "Mutante.h"
#include "PoderFisico.h"
#include "PoderPsiquico.h"

Mutante::Mutante(string nombre, string apodo, int fechaN, string nacionalidad) 
    : _nombreReal(nombre),
      _apodo(apodo),
      _fechaDeNacimiento(fechaN),
      _nacionalidad(nacionalidad)
      {
    
}

Mutante::Mutante(const Mutante& orig)
    : _nombreReal(orig._nombreReal),
    _apodo(orig._apodo),
    _fechaDeNacimiento(orig._fechaDeNacimiento),
    _nacionalidad(orig._nacionalidad)
 {
    
}

Mutante::~Mutante() {
    for(int i = 0; i < numPoderes; ++i){
        delete poderes[i];
    }
}

void Mutante::setNombreReal(string nombreReal) {
    this->_nombreReal = nombreReal;
}

string Mutante::getNombreReal() const {
    return _nombreReal;
}

void Mutante::setNacionalidad(string nacionalidad) {
    this->_nacionalidad = nacionalidad;
}

string Mutante::getNacionalidad() const {
    return _nacionalidad;
}

void Mutante::setFechaDeNacimiento(int fechaDeNacimiento) {
    this->_fechaDeNacimiento = fechaDeNacimiento;
}

int Mutante::getFechaDeNacimiento() const {
    return _fechaDeNacimiento;
}

void Mutante::setApodo(string apodo) {
    this->_apodo = apodo;
}

string Mutante::getApodo() const {
    return _apodo;
}

Poder* Mutante::getPoder(int cual) {
    return poderes[cual];
}

int Mutante::getNumPoderes() const {
    return numPoderes;
}

/**@brief Representación CSV de un mutante
   @post  Genera la representación básica en CSV, sin incluir los poderes*/
string Mutante::toCSV() const{
    std::stringstream aux;
    aux << _nombreReal << ";"
            << _apodo << ";"
            << _fechaDeNacimiento << ";"
            << _nacionalidad;

    return aux.str();
}

Mutante& Mutante::operator=(const Mutante& orig) {
    if (this != &orig) {
        _nombreReal = orig._nombreReal;
        _apodo = orig._apodo;
        _fechaDeNacimiento = orig._fechaDeNacimiento;
        _nacionalidad = orig._nacionalidad;

    }

    return  *this;
}

void Mutante::addPoder(string nombre, string descripcion, string afectaA, float capacidadD) {
    if (numPoderes == MAX_PODERES)
        throw std::overflow_error("Mutante.cpp - addPoder() - No es posible añadir más poderes al mutante");
    poderes[numPoderes] = new Poder(nombre, descripcion, afectaA, capacidadD);
    ++numPoderes;
}

void Mutante::borraPoder(int cual) {
    if(cual-1 > MAX_PODERES || poderes[cual] == nullptr)
        throw std::range_error("Mutante.cpp - borraPoder() - No se puede acceder al poder indicado");
    delete poderes[cual];
    --cual;
}

float Mutante::capacidadDestructivaTotal(){
    float temp = 0;
    for (int i = 0; i < numPoderes; ++i){
        if(!poderes[i]->IsInhibido())
            temp += poderes[i]->GetCapacidadDestructiva();
    }
    return temp;
}

void Mutante::addPoderFisico(string nombre, string descripcion, string afectaA, float capacidadD) {
    if (numPoderes == MAX_PODERES)
        throw std::overflow_error("Mutante.cpp - addPoder() - No es posible añadir más poderes al mutante");
    poderes[numPoderes] = new PoderFisico(nombre, descripcion, afectaA, capacidadD);
    ++numPoderes;
}

void Mutante::addPoderPsiquico(string nombre, string descripcion, string afectaA, float capacidadD) {
    if (numPoderes == MAX_PODERES)
        throw std::overflow_error("Mutante.cpp - addPoder() - No es posible añadir más poderes al mutante");
    poderes[numPoderes] = new PoderPsiquico(nombre, descripcion, afectaA, capacidadD);
    ++numPoderes;
}

void Mutante::addPoder(const Poder& poder) {
    if (numPoderes == MAX_PODERES)
        throw std::overflow_error("Mutante.cpp - addPoder() - No es posible añadir más poderes al mutante");
    poderes[numPoderes] = new Poder(poder);
    ++numPoderes;
}

void Mutante::addPoderFisico(const PoderFisico& poder) {
    if (numPoderes == MAX_PODERES)
        throw std::overflow_error("Mutante.cpp - addPoder() - No es posible añadir más poderes al mutante");
    poderes[numPoderes] = new PoderFisico(poder);
    ++numPoderes;
}

void Mutante::addPoderPsiquico(const PoderPsiquico& poder) {
    if (numPoderes == MAX_PODERES)
        throw std::overflow_error("Mutante.cpp - addPoder() - No es posible añadir más poderes al mutante");
    poderes[numPoderes] = new PoderPsiquico(poder);
    ++numPoderes;
}

bool Mutante::operator<(const Mutante& right) const {
    if(right.capacidadDestructivaTotal() < capacidadDestructivaTotal())
        return true;
    return false;
}
