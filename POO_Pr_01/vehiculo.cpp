/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   vehiculo.cpp
 * Author: Miguerubsk
 * 
 * Created on 12 de febrero de 2020, 16:57
 */

#include "vehiculo.h"

Vehiculo::Vehiculo() {
    Modelo = "AAAAAa";
    Matricula = "111111";
    Marca = "BBBBBBB";
    Fabricacion = 1998;
    Precio = 29836;
}

Vehiculo::Vehiculo(const Vehiculo& orig) {
    Modelo = orig.Modelo;
    Matricula = orig.Matricula;
    Marca = orig.Marca;
    Fabricacion = orig.Fabricacion;
    Precio = orig.Precio;
}

Vehiculo::~Vehiculo() {
}

/**
 * @param _Vehiculo que se quiere modificar
 * @brief modifica los datos de _Vehiculo leyendo los datos por teclado
 * @throw std::invalid_argument
 */
void Vehiculos::leePorTeclado(Vehiculo &_Vehiculo) {
    std::string Marca;
    std::string Modelo;
    std::string Matricula;
    int fabricacion;
    float precio;

    std::cout << "Introduce la marca: ";
    std::cin>>Marca;
    if (Marca.length() < 3 || Marca.length() > 20) throw std::invalid_argument("Vehiculos::leePorTeclado() -> La longitud de la marca debe estar entre 3 y 20 caracteres");
    _Vehiculo.setMarca(Marca);

    std::cout << "Introduce el modelo: ";
    std::cin>>Modelo;
    if (Modelo.length() < 1 || Modelo.length() > 30) throw std::invalid_argument("Vehiculos::leePorTeclado() -> La longitud del modelo debe estar entre 1 y 30 caracteres");
    _Vehiculo.setModelo(Modelo);

    std::cout << "Introduce la matricula: ";
    std::cin>>Matricula;
    if (Matricula.length() != 6) throw std::invalid_argument("Vehiculos::leePorTeclado() -> La longitud de la matricula debe ser de 6 caracteres");
    _Vehiculo.setMatricula(Matricula);

    std::cout << "Introduce el año de fabricación: ";
    std::cin>>fabricacion;
    _Vehiculo.setFabricacion(fabricacion);

    std::cout << "Introduce el precio: ";
    std::cin>>precio;
    if (precio <= 0) throw std::invalid_argument("Vehiculos::leePorTeclado() -> El precio debe ser mayor que 0");
    _Vehiculo.setPrecio(precio);

}

/**
 * @param _Vehiculo que se quiere modificar
 * @brief modifica los datos de _Vehiculo leyendo los datos por teclado
 * @throw std::invalid_argument
 */
void Vehiculos::leePorTeclado(Vehiculo *_Vehiculo) {
    std::string Marca;
    std::string Modelo;
    std::string Matricula;
    int fabricacion;
    float precio;

    std::cout << "Introduce la marca: ";
    std::cin>>Marca;
    if (Marca.length() < 3 || Marca.length() > 20) throw std::invalid_argument("Vehiculos::leePorTeclado() -> La longitud de la marca debe estar entre 3 y 20 caracteres");
    _Vehiculo->setMarca(Marca);

    std::cout << "Introduce el modelo: ";
    std::cin>>Modelo;
    if (Modelo.length() < 1 || Modelo.length() > 30) throw std::invalid_argument("Vehiculos::leePorTeclado() -> La longitud del modelo debe estar entre 1 y 30 caracteres");
    _Vehiculo->setModelo(Modelo);

    std::cout << "Introduce la matricula: ";
    std::cin>>Matricula;
    if (Matricula.length() != 6) throw std::invalid_argument("Vehiculos::leePorTeclado() -> La longitud de la matricula debe ser de 6 caracteres");
    _Vehiculo->setMatricula(Matricula);

    std::cout << "Introduce el año de fabricación: ";
    std::cin>>fabricacion;
    _Vehiculo->setFabricacion(fabricacion);

    std::cout << "Introduce el precio: ";
    std::cin>>precio;
    if (precio <= 0) throw std::invalid_argument("Vehiculos::leePorTeclado() -> El precio debe ser mayor que 0");
    _Vehiculo->setPrecio(precio);
}

/**
 * @brief muestra por la salida estándar los datos de _Vehiculo
 * @param _Vehiculo que se quiere mostrar por pantalla
 */
void Vehiculos::muestraEnPantalla(Vehiculo &_Vehiculo) {
    std::cout << "Marca: " << _Vehiculo.getMarca()
            << " - Modelo: " << _Vehiculo.getModelo()
            << " - Matricula: " << _Vehiculo.getMatricula()
            << " - Año de fabricación: " << _Vehiculo.getFabricacion()
            << " - Precio: " << _Vehiculo.getPrecio() << std::endl;
}

/**
 * @brief muestra por la salida estándar los datos de _Vehiculo
 * @param _Vehiculo
 */
void Vehiculos::muestraEnPantalla(Vehiculo *_Vehiculo) {
    std::cout << "Marca: " << _Vehiculo->getMarca()
            << " - Modelo: " << _Vehiculo->getModelo()
            << " - Matricula: " << _Vehiculo->getMatricula()
            << " - Año de fabricación: " << _Vehiculo->getFabricacion()
            << " - Precio: " << _Vehiculo->getPrecio() << std::endl;
}

/**
 * @brief los precios de los vehiculos contenidos en el vector se incrementan el porcentaje que se especifique
 * @param vehiculos vector del cual se van a modificar los precios
 * @param numvehiculos numero de vehiculos que hay en el vector
 * @param porcentaje porcentaje que se van a incrementar los precios en el vector
 * @throw std::invalid_argument
 */
void Vehiculos::incrementaPrecios(Vehiculo vehiculos[], int numvehiculos, float porcentaje) {
    if (porcentaje <= 0 && porcentaje >= 5)
        throw std::invalid_argument("Vehiculos::incrementaPrecios() -> El porcentaje debe estar entre 0 y 5");
    for (int i = 0; i < numvehiculos; ++i) {
        vehiculos[i].setPrecio(vehiculos[i].getPrecio() * porcentaje);
    }
}

/**
 * @brief Busca una subcadena en las marcas de los vehicuos de un vector de vehículos
 * @param vehiculos vector que contiene los vehiculos
 * @param numVehiculos numero de vehículos en el vector
 * @param sub subcadena a buscar en en la marca
 * @return Un puntero al vehiculo encontrado o nullptr si no lo ha encontrado
 */
Vehiculo* Vehiculos::buscarSubcadena(Vehiculo vehiculos[], int numVehiculos, std::string sub) {
    for (int i = 0; i < numVehiculos; ++i) {
        std::size_t found = vehiculos[i].getMarca().find(sub);
        if (found != std::string::npos)
            return &vehiculos[i];
    }
    return nullptr;
}

/**
 * @brief Introduce en un vector los vehiculos con los datos que se solicitan al usuario
 * @param v vector que se quiere rellenar
 * @param tamv tamaño del vector que se quiere rellenar
 * @return Número de vehiculos introducidos por el usuario
 * @throw std::length_error
 * @throw std::invalid_argument
 */
int Vehiculos::rellenarVector(Vehiculo v[], int tamv) {

    int parada = 0, i = 0;
    while (parada != -1 && i < tamv) {

        if (sizeof (v) < i)
            throw std::length_error("Vehiculos::rellenarVector() -> se ha superado el tamaño máximo del vector");

        Vehiculos::leePorTeclado(v[i]);

        ++i;
        std::cout << "-1 para salir 0 para continuar: ";
        std::cin>>parada;
        std::cout << std::endl;
    }
    return i;
}

/**
 * @brief Muestra por pantalla los vehiculos contenidos en un vector, de 5 en 5, uno por línea
 * @param v vector que se quiere visualizar
 * @param tamv tamaño del vector
 */
void Vehiculos::mostrarEnPantalla(Vehiculo v[], int tamv) {
    int i = 0;
    while (i < tamv) {
        Vehiculos::muestraEnPantalla(v[i]);
        ++i;
        Vehiculos::muestraEnPantalla(v[i]);
        ++i;
        Vehiculos::muestraEnPantalla(v[i]);
        ++i;
        Vehiculos::muestraEnPantalla(v[i]);
        ++i;
        Vehiculos::muestraEnPantalla(v[i]);
        ++i;
        std::cout << "Pulse ENTER para continuar..." << std::endl;
        system("read");
    }
}

/**
 * @brief busca en un vector un vehículo con una matrícula concreta
 * @param mat matricula que se quiere buscar
 * @param v vector en el que se quiere buscar
 * @param tamv tamaño del vector
 * @return Posición del vehiculo en caso de encontrarlo
 * @throw std::domain_error
 */
int Vehiculos::buscarPorMatricula(std::string mat, Vehiculo v[], int tamv) {
    for (int i = 0; i < tamv; ++i) {
        if (v[i].getMatricula() == mat)
            return i;
    }
    throw std::domain_error("Vehiculo::buscarSubcadena() -> Vehiculo no encontrado en el vector");
}

/**
 * @brief busca en n vector el vehiculo más caro de los que contiene
 * @param v vector en el que se quiere buscar
 * @param tamv tanaño del vector
 * @return Posición del vehiculo más caro
 */
int Vehiculos::maxPrecio(Vehiculo v[], int tamv) {
    int max = 0;
    for (int i = 0; i < tamv; ++i) {
        if (v[i].getPrecio() > max)
            max = v[i].getPrecio();

        if (i == tamv - 1)
            return i;
    }
}

void Vehiculo::setPrecio(float precio) {
    this->Precio = precio;
}

float Vehiculo::getPrecio() const {
    return Precio;
}

void Vehiculo::setFabricacion(int fabricacion) {
    this->Fabricacion = fabricacion;
}

int Vehiculo::getFabricacion() const {
    return Fabricacion;
}

void Vehiculo::setMatricula(std::string Matricula) {
    this->Matricula = Matricula;
}

std::string Vehiculo::getMatricula() const {
    return Matricula;
}

void Vehiculo::setModelo(std::string Modelo) {
    this->Modelo = Modelo;
}

std::string Vehiculo::getModelo() const {
    return Modelo;
}

void Vehiculo::setMarca(std::string Marca) {
    this->Marca = Marca;
}

std::string Vehiculo::getMarca() const {
    return Marca;
}