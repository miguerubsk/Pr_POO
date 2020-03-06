/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Fecha.cpp
 * Author: Miguerubsk
 * 
 * Created on 19 de febrero de 2020, 20:09
 */

#include "Fecha.h"

Fecha::Fecha() {
    std::time_t t = std::time(0);
    std::tm* now = std::localtime(&t);

    Anio = now->tm_year + 1900;
    Mes = now->tm_mon + 1;
    Dia = now->tm_mday;
}

void Fecha::mostrarFecha(Fecha& F) {
    std::cout << F.GetDia() << "/" << F.GetMes() << "/" << F.GetAnio() << std::endl;
}

Fecha::Fecha(int dia, int mes, int anio) : Dia(dia), Mes(mes), Anio(anio) {
}

Fecha::Fecha(const Fecha& orig) {
    Dia = orig.Dia;
    Anio = orig.Anio;
    Mes = orig.Mes;
}

Fecha::~Fecha() {
}

void Fecha::SetAnio(int Anio) {
    this->Anio = Anio;
}

int Fecha::GetAnio() const {
    return Anio;
}

void Fecha::SetMes(int Mes) {
    this->Mes = Mes;
}

int Fecha::GetMes() const {
    return Mes;
}

void Fecha::SetDia(int Dia) {
    this->Dia = Dia;
}

int Fecha::GetDia() const {
    return Dia;
}

