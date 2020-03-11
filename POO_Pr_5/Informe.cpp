/** 
 * @file Informe.cpp
 * @author Casipro Gramo
 * 
 * @date Fecha estelar 20160309
 */

#include <stdexcept>
#include <sstream>
#include "Informe.h"

using std::string;

long Informe::_numInformes = 0;

Informe::Informe() : Informe(0) {
}

Informe::Informe(long fecha) : _fechaEstelar(fecha) {
    _numInformes++;
    _idI = _numInformes;
}

Informe::Informe(const Informe& orig) : _idPiloto(orig._idPiloto), _fechaEstelar(orig._fechaEstelar), _datosInforme(orig._datosInforme) {
    _numInformes++;
    _idI = _numInformes;
}

Informe::~Informe() {
}

Informe& Informe::setDatosInforme(string datosInforme) {
    this->_datosInforme = datosInforme;
    return *this;
}

string Informe::getDatosInforme() const {
    return _datosInforme;
}

Informe& Informe::setFechaEstelar(long fechaEstelar) {
    if(fechaEstelar < 0)
        throw std::invalid_argument("La fecha estelar no puede ser negativa");
    this->_fechaEstelar = fechaEstelar;
    return *this;
}

long Informe::getFechaEstelar() const {
    return _fechaEstelar;
}

Informe& Informe::setIdPiloto(int idPiloto) {
    if(idPiloto < 0)
        throw std::invalid_argument("l id del piloto no puede ser negativo");
    this->_idPiloto = idPiloto;
    return ( *this);
}

int Informe::getIdPiloto() const {
    return _idPiloto;
}

int Informe::getIdI() const {
    return _idI;
}

string Informe::toCSV() const {
    std::stringstream aux;

    aux << "Fecha estelar: " << _fechaEstelar << " ; "
            << "id de piloto: " << _idPiloto << " ; "
            << _datosInforme;

    return aux.str();
}

Informe& Informe::operator=(const Informe& otro) {
    if (this != &otro) {
        _idPiloto = otro._idPiloto;
        _fechaEstelar = otro._fechaEstelar;
        _datosInforme = otro._datosInforme;
    }

    return *this;
}
