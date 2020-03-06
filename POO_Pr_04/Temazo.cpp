/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Temazo.cpp
 * Author: Miguerubsk
 * 
 * Created on 19 de febrero de 2020, 20:08
 */

#include "Temazo.h"
#include "ParametroNoValido.h"

Temazo::Temazo(): Titulo("N/A"), Interprete("N/A"), Genero("Pop"), fechaUltimoUso(), nombreUltimoGarito("N/A"), Duracion(0), Puntuacion(0){
    numTemazos++;
    idTemazo=numTemazos;
}

int Temazo::numTemazos(0);

Temazo::Temazo(std::string titulo, std::string interprete, int duracion, int puntuacion, std::string genero): 
    Titulo(titulo), Interprete(interprete), Duracion(duracion), Puntuacion(puntuacion){
    SetGenero(genero);
    numTemazos++;
    idTemazo=numTemazos;
}

Temazo::Temazo(const Temazo& orig) {
    Duracion = orig.Duracion;
    Interprete = orig.Interprete;
    Genero = orig.Genero;
    fechaUltimoUso = orig.fechaUltimoUso;
    nombreUltimoGarito = orig.nombreUltimoGarito;
    Duracion = orig.Puntuacion;
    Puntuacion = orig.Puntuacion;
    numTemazos++;
    idTemazo=numTemazos;
}

void Temazo::mostrarTemazo(Temazo &T){
    std::cout << "Título: " << T.Titulo << std::endl;
    std::cout << "Intérprete: " << T.Interprete << std::endl;
    std::cout << "Género: " << T.Genero << std::endl;
    std::cout << "Fecha del último uso: ";
    Fecha::mostrarFecha(T.fechaUltimoUso);
    std::cout << "Último garito en el que se usó: " << T.nombreUltimoGarito << std::endl;
    std::cout << "Duración: " << T.Duracion << " segundos" << std::endl;
    std::cout << "Puntuación: " << T.Puntuacion << std::endl;
    std::cout << "Id: " << T.idTemazo << std::endl;
}

Temazo::~Temazo() {}

int Temazo::GetPuntuacion() const { return Puntuacion; }

Temazo& Temazo::SetDuracion(int Duracion) { 
    this->Duracion = Duracion; 
    return *this;
}

int Temazo::GetDuracion() const { return Duracion; }

Temazo& Temazo::SetInterprete(std::string Interprete) { 
    this->Interprete = Interprete;
    return *this;
}

std::string Temazo::GetInterprete() const { return Interprete; }

Temazo& Temazo::SetTitulo(std::string Titulo) { 
    this->Titulo = Titulo;
    return *this;
}

std::string Temazo::GetTitulo() const { return Titulo; }

std::string Temazo::GetGenero() const {
    return Genero;
}

Temazo& Temazo::SetGenero(std::string Genero) {
    if(Genero.length() < 2)
        throw ParametroNoValido("Temazo.cpp", "SetGenero()", "El género debe tener más de 2 caracteres");
    this->Genero = Genero;
    return *this;
}

std::string Temazo::GetNombreUltimoGarito() const {
    return nombreUltimoGarito;
}

Fecha Temazo::GetFechaUltimoUso() const {
    return fechaUltimoUso;
}

Temazo& Temazo::SetFechaUltimoUso(Fecha fechaUltimoUso) {
    this->fechaUltimoUso = fechaUltimoUso;
    return *this;
}

Temazo& Temazo::SetNombreUltimoGarito(std::string nombreUltimoGarito) {
    this->nombreUltimoGarito = nombreUltimoGarito;
    return *this;
}

void Temazo::incrementarPuntuacion(int puntos) {
    if (puntos < -10 || puntos > 10)
        throw ParametroNoValido("Temazo.cpp", "incrementarPuntuacion()", "Los puntos deben estar en el rango [-10, 10]");
    Puntuacion += puntos;
}

std::string Temazo::toCSV() {
    return std::to_string(idTemazo)+";"+Titulo+";"+Interprete+";"+std::to_string(Duracion)+";"+std::to_string(Puntuacion)+";"+nombreUltimoGarito+";"+fechaUltimoUso.toCSV();
}

Temazo& Temazo::operator=(const Temazo& right) {
    if (this == &right)
        return *this;

    Titulo = right.Titulo;
    Duracion = right.Duracion;
    Interprete = right.Interprete;
    Genero = right.Genero;
    fechaUltimoUso = right.fechaUltimoUso;
    nombreUltimoGarito = right.nombreUltimoGarito;
    Duracion = right.Puntuacion;
    Puntuacion = right.Puntuacion;

    return *this;
}

bool Temazo::operator<(const Temazo& right) const {
    if (Duracion < right.Duracion)
        return true;
    return false;
}

bool Temazo::operator==(const Temazo& right) const {
    if (Duracion == right.Duracion)
        return true;
    return false;
}

void Temazo::verTemazosMasLargosQue(Temazo v[], int numTemazo, Temazo& temaso) {
    for(int i = 0; i < numTemazo; ++i){
        if(temaso<v[i])
            Temazo::mostrarTemazo(v[i]);  
    }
//    std::cout<<"Ningun temazo coincide"<<std::endl;
}

int Temazo::listaRelleno(Temazo v[], int tamv, Temazo* lista[], int duracion_total) {
    int dur_aux=0;
    for ( int i = 0; i < tamv; ++i){
        if(dur_aux<duracion_total){
            lista[i] = &v[i];
            dur_aux+=v[i].Duracion;
        }else{
            lista[i]=nullptr;
        }
    }
    return tamv;
}