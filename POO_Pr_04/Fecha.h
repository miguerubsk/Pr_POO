/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Fecha.h
 * Author: Miguerubsk
 *
 * Created on 19 de febrero de 2020, 20:09
 */

#ifndef FECHA_H
#define FECHA_H
#include <iostream>
#include <chrono>
#include <ctime> 

class Fecha {
public:
    Fecha();
    Fecha(int dia, int mes, int anio);
    Fecha(const Fecha& orig);
    virtual ~Fecha();
    
    int GetAnio() const;
    int GetDia() const;
    int GetMes() const;
    
    void SetMes(int Mes);
    void SetDia(int Dia);
    void SetAnio(int Anio);
    
    bool operator==(const Fecha& right) const;
    bool operator<(const Fecha& right) const;
    bool operator<=(const Fecha& right) const;
    bool operator>=(const Fecha& right) const;
    bool operator>(const Fecha& right) const;
    bool operator!=(const Fecha& right) const;
    
    static void mostrarFecha(Fecha &F);
    
private:
    int Dia = 0;
    int Mes = 0;
    int Anio = 0;
};

#endif /* FECHA_H */

