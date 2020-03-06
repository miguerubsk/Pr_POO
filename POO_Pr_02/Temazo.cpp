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

Temazo::Temazo(): Titulo("N/A"), Interprete("N/A"), Genero("Pop"), Duracion(0), Puntuacion(0){}

Temazo::Temazo(std::string titulo, std::string interprete, int duracion, int puntuacion, std::string genero): 
    Titulo(titulo), Interprete(interprete), Duracion(duracion), Puntuacion(puntuacion){
    SetGenero(genero);
}

Temazo::Temazo(const Temazo& orig) {
    Duracion = orig.Duracion;
    Interprete = orig.Interprete;
    Genero = orig.Genero;
    Duracion = orig.Puntuacion;
    Puntuacion = orig.Puntuacion;
}

void Temazo::mostrarTemazo(Temazo &T){
    std::cout << "Título: " << T.Titulo << std::endl;
    std::cout << "Intérprete: " << T.Interprete << std::endl;
    std::cout << "Género: " << T.Genero << std::endl;
    std::cout << "Duración: " << T.Duracion << " segundos" << std::endl;
    std::cout << "Puntuación: " << T.Puntuacion << std::endl;
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

std::string Temazo::GetTitulo() const { return Titulo;
}

std::string Temazo::GetGenero() const {
    return Genero;
}

Temazo& Temazo::SetGenero(std::string Genero) {
    if(Genero.length() < 2)
        throw std::invalid_argument("SetGenero() -> El género debe tener más de 2 caracteres");
    this->Genero = Genero;
    return *this;
}
