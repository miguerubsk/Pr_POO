/** 
 * @file StarFighter.cpp
 * @author Casipro Gramo
 * 
 * @date Fecha estelar 20160309
 */

#include <stdexcept>
#include <sstream>

#include "StarFighter.h"

using std::string;

int StarFighter::_numStarFighters = 0;

StarFighter::StarFighter() : StarFighter("", "") {
    for (int i = 0; i < MAX_PIEZAS; ++i){
        piezas[i] = nullptr;
    }
}

StarFighter::StarFighter(string marca, string modelo) : _marca(marca), _modelo(modelo) {
    _numStarFighters++;
    _idSF = _numStarFighters;
    for (int i = 0; i < MAX_PIEZAS; ++i){
        piezas[i] = nullptr;
    }
}

StarFighter::StarFighter(const StarFighter& orig) : _marca(orig._marca), _modelo(orig._modelo), _numPlazas(orig._numPlazas) {
    _numStarFighters++;
    _idSF = _numStarFighters;
    for (int i = 0; i < MAX_PIEZAS; ++i){
        piezas[i] = nullptr;
    }
}

StarFighter::~StarFighter() {
    for (int i = 0; i < numPiezas; ++i){
         delete piezas[i];
         piezas[i] = nullptr;
    }
}

StarFighter& StarFighter::setNumPlazas(int numPlazas) {
    if (numPlazas <= 0)
        throw std::invalid_argument("El número de plazas no puede ser menor o igual a 0");
    this->_numPlazas = numPlazas;

    return *this;
}

int StarFighter::getNumPlazas() const {
    return _numPlazas;
}

StarFighter& StarFighter::setModelo(string modelo) {
    this->_modelo = modelo;

    return *this;
}

string StarFighter::getModelo() const {
    return _modelo;
}

StarFighter& StarFighter::setMarca(string marca) {
    this->_marca = marca;

    return *this;
}

string StarFighter::getMarca() const {
    return _marca;
}

int StarFighter::getIdSF() const {
    return _idSF;
}

string StarFighter::toCSV() const {
    std::stringstream aux;
    aux << _marca << ";"
            << _modelo << ";"
            << _numPlazas;

    return aux.str();
}

void StarFighter::fromCSV(std::string csv) {
    std::stringstream aux;
    string marca, modelo, numPlazas;
    aux << csv;
    getline(aux, marca, ';');
    getline(aux, modelo, ';');
    getline(aux, numPlazas, ';');
    setMarca(marca).setModelo(modelo).setNumPlazas(stoi(numPlazas));
}

StarFighter& StarFighter::operator=(const StarFighter& otro) {
    if (this != &otro) {
        _marca = otro._marca;
        _modelo = otro._modelo;
        _numPlazas = otro._numPlazas;
    }

    return *this;
}

void StarFighter::addPieza(std::string _nombre, float _peso, std::string _descripcion) {
    piezas[numPiezas] = new Pieza(_nombre, _peso, _descripcion);
    ++numPiezas;
}

void StarFighter::eliminarPieza(std::string _nombre) {
    delete piezas[numPiezas];
    piezas[numPiezas] = nullptr;
    --numPiezas;
}