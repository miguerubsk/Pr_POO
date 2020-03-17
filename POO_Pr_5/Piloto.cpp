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
    nave = nullptr;
}

Piloto::~Piloto() {
}

Piloto& Piloto::setNumMisiones(int numMisiones) {
    if (numMisiones <= 0)
        throw std::invalid_argument("El número de misiones no puede ser menor o igual a 0");
    this->_numMisiones = numMisiones;
    
    return *this;
}

int Piloto::getNumMisiones() const {
    return _numMisiones;
}

Piloto& Piloto::setNacionalidad(string nacionalidad) {
    this->_nacionalidad = nacionalidad;
    
    return *this;
}

string Piloto::getNacionalidad() const {
    return _nacionalidad;
}

Piloto& Piloto::setNombre(string nombre) {
    this->_nombre = nombre;
    
    return *this;
}

string Piloto::getNombre() const {
    return _nombre;
}

int Piloto::getIdP() const {
    return _idP;
}

Piloto& Piloto::setIncidenciasUltimaMision(string incidenciasUltimaMision) {
    if(_numMisiones == 0)
        throw std::invalid_argument("El piloto no puede tener incidencias si no ha realizado ninguna misión");
    this->_incidenciasUltimaMision = incidenciasUltimaMision;
    
    return *this;
}

string Piloto::getIncidenciasUltimaMision() const {
    return _incidenciasUltimaMision;
}

Piloto& Piloto::setFechaUltimaMision(long fechaUltimaMision) {
    if(_numMisiones == 0)
        throw std::invalid_argument("El piloto no ha realizado ninguna misión");
    this->_fechaUltimaMision = fechaUltimaMision;
    
    return *this;
}

long Piloto::getFechaUltimaMision() const {
    if(_numMisiones == 0)
        throw std::invalid_argument("El piloto no ha realizado ninguna misión");
    return _fechaUltimaMision;
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

Piloto& Piloto::setNave(StarFighter* nave) {
    if(!nave)
        throw std::invalid_argument("La nave no existe");
    this->nave = nave;
    
    return *this;
}

Droide* Piloto::getAuxiliar() const {
    return auxiliar;
}

Piloto& Piloto::setAuxiliar(Droide* auxiliar) {
    if(!auxiliar)
        throw std::invalid_argument("No existe el droide");
    if(auxiliar->isAveriado())
        throw std::invalid_argument("No se puede asignar un droide averiado");
    this->auxiliar = auxiliar;
    
    return *this;
}

Informe Piloto::generaInforme() {
    std::stringstream aux;
    if(nave){
        aux <<"ID StarFighter: " << nave->getIdSF() << ";";
    }else{
        aux << "ID StarFighter: ---" << ";";
    }
    if(auxiliar){
    aux     << "ID Droide auxiliar: " << auxiliar->getIdD() << ";";
    }else{
        aux << "ID Droide auxiliar: ---" << ";";
    }
    aux << "Incidencias durante la misión: " << _incidenciasUltimaMision;
    Informe informe;
    informe.setIdPiloto(_idP);
    informe.setFechaEstelar(_fechaUltimaMision);
    informe.setDatosInforme(aux.str());
    
    return informe;
}

string Piloto::toCSV() const {
    std::stringstream aux;

    aux << _nombre << ";"
            << _nacionalidad << ";"
            << _numMisiones << ";"
            << _fechaUltimaMision << ";"
            << _incidenciasUltimaMision;

    return aux.str();
}

void Piloto::fromCSV(std::string csv) {
    std::stringstream aux;
    string nombre, nacionalidad, incidenciasUltimaMision, numMisiones, fechaUltimamision;
    aux << csv;
    getline(aux, nombre, ';');
    getline(aux, nacionalidad, ';');
    getline(aux, numMisiones, ';');
    getline(aux, fechaUltimamision, ';');
    getline(aux, incidenciasUltimaMision, ';');
    
    setNombre(nombre).setNacionalidad(nacionalidad).setNumMisiones(stoi(numMisiones))
            .setFechaUltimaMision(stol(fechaUltimamision)).setIncidenciasUltimaMision(incidenciasUltimaMision);
}
