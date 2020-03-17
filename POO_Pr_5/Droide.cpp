/** 
 * @file Droide.cpp
 * @author Casipro Gramo
 * 
 * @date Fecha estelar 20160309
 */

#include <sstream>
#include <iostream>
#include "Droide.h"

using std::string;

int Droide::_numDroides = 0;

Droide::Droide() : Droide("", "", false) {
}

Droide::Droide(string marca, string modelo, bool averiado = false) : _marca(marca), _modelo(modelo), averiado(averiado) {
    _numDroides++;
    _idD = _numDroides;
}

Droide& Droide::setAveriado(bool averiado) {
    this->averiado = averiado;
    return *this;
}


bool Droide::isAveriado() const {
    return averiado;
}


Droide::Droide(const Droide& orig) : _marca(orig._marca), _modelo(orig._modelo), averiado(orig.averiado) {
    _numDroides++;
    _idD = _numDroides;
}

Droide::~Droide() {
}

int Droide::getIdD() const {
    return _idD;
}

Droide& Droide::setModelo(string modelo) {
    this->_modelo = modelo;

    return *this;
}

string Droide::getModelo() const {
    return _modelo;
}

Droide& Droide::setMarca(string marca) {
    this->_marca = marca;

    return *this;
}

string Droide::getMarca() const {
    return _marca;
}

string Droide::toCSV() const {
    std::stringstream aux;

    aux     << _marca << ";"
            << _modelo <<";"
            << averiado;

    return aux.str();
}

Droide& Droide::operator=(const Droide& otro) {
    if (this != &otro) {
        _marca = otro._marca;
        _modelo = otro._modelo;
    }
    return *this;
}

void Droide::fromCSV(std::string csv) {
    std::stringstream ss;
    string marca, modelo, averiado;
    ss << csv;
    getline(ss, marca, ';');
    getline(ss, modelo, ';');
    getline(ss, averiado, ';');
    if(averiado!="1"){
        setAveriado(false);
    }else{
        setAveriado(true);
    }
    setMarca(marca);
    setModelo(modelo);
}
