/** 
 * @file Piloto.cpp
 * @author Yoyapro Gramo
 * 
 * @date Fecha estelar 20160309
 */

#include <stdexcept>
#include <sstream>

#include "Piloto.h"

using std::string;

int Piloto::_numPilotos = 0;

Piloto::Piloto() : Piloto("") {
}

Piloto::Piloto(string nombre) : _nombre(nombre) {
    _numPilotos++;
    _idP = _numPilotos;
}

Piloto::Piloto(const Piloto& orig) :
_nombre(orig._nombre), _nacionalidad(orig._nacionalidad), _numMisiones(orig._numMisiones),
_fechaUltimaMision(orig._fechaUltimaMision), _incidenciasUltimaMision(orig._incidenciasUltimaMision) {
    _numPilotos++;
    _idP = _numPilotos;
}

Piloto::~Piloto() {
}

void Piloto::setNumMisiones(int numMisiones) {
    if (numMisiones <= 0)
        throw std::invalid_argument("El número de misiones no puede ser menor o igual a 0");
    this->_numMisiones = numMisiones;
}

int Piloto::getNumMisiones() const {
    return _numMisiones;
}

void Piloto::setNacionalidad(string nacionalidad) {
    this->_nacionalidad = nacionalidad;
}

string Piloto::getNacionalidad() const {
    return _nacionalidad;
}

void Piloto::setNombre(string nombre) {
    this->_nombre = nombre;
}

string Piloto::getNombre() const {
    return _nombre;
}

int Piloto::getIdP() const {
    return _idP;
}

void Piloto::setIncidenciasUltimaMision(string incidenciasUltimaMision) {
    if(_numMisiones == 0)
        throw std::invalid_argument("El piloto no puede tener incidencias si no ha realizado ninguna misión");
    this->_incidenciasUltimaMision = incidenciasUltimaMision;
}

string Piloto::getIncidenciasUltimaMision() const {
    return _incidenciasUltimaMision;
}

void Piloto::setFechaUltimaMision(long fechaUltimaMision) {
    if(_numMisiones == 0)
        throw std::invalid_argument("El piloto no ha realizado ninguna misión");
    this->_fechaUltimaMision = fechaUltimaMision;
}

long Piloto::getFechaUltimaMision() const {
    if(_numMisiones == 0)
        throw std::invalid_argument("El piloto no ha realizado ninguna misión");
    return _fechaUltimaMision;
}

string Piloto::toCSV() const {
    std::stringstream aux;

    aux << _nombre << " ; "
            << _nacionalidad << " ; "
            << _numMisiones << " ; "
            << _fechaUltimaMision << " ; "
            << _incidenciasUltimaMision;

    return aux.str();
}

Piloto& Piloto::operator=(const Piloto& otro) {
    if (this != &otro) {
        _nombre = otro._nombre;
        _nacionalidad = otro._nacionalidad;
        _numMisiones = otro._numMisiones;
        _fechaUltimaMision = otro._fechaUltimaMision;
        _incidenciasUltimaMision = otro._incidenciasUltimaMision;
    }

    return *this;
}

StarFighter* Piloto::getNave() const {
    return nave;
}

void Piloto::setNave(StarFighter* nave) {
    this->nave = nave;
}
