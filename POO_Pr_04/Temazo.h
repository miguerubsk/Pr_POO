/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Temazo.h
 * Author: Miguerubsk
 *
 * Created on 19 de febrero de 2020, 20:08
 */

#ifndef TEMAZO_H
#define TEMAZO_H
#include <iostream>
#include "Fecha.h"

class Temazo {
public:
    Temazo();
    Temazo(std::string titulo, std::string interprete, int duracion, int puntuacion = 0, std::string genero = "Pop");
    Temazo(const Temazo& orig);
    virtual ~Temazo();
    
    int GetPuntuacion() const;
    int GetDuracion() const;
    std::string GetInterprete() const;
    std::string GetTitulo() const;
    std::string GetGenero() const;
    Fecha GetFechaUltimoUso() const;
    std::string GetNombreUltimoGarito() const;
    
    Temazo& SetInterprete(std::string Interprete);
    Temazo& SetDuracion(int Duracion);
    Temazo& SetTitulo(std::string Titulo);
    Temazo& SetGenero(std::string Genero);
    Temazo& SetFechaUltimoUso(Fecha fechaUltimoUso);
    Temazo& SetNombreUltimoGarito(std::string nombreUltimoGarito);
    
    Temazo& operator=(const Temazo& right);
    bool operator<(const Temazo& right) const;
    bool operator==(const Temazo& right) const;

    std::string toCSV();
    void incrementarPuntuacion(int puntos);
    
    static void mostrarTemazo(Temazo &T);
    static void verTemazosMasLargosQue(Temazo v[], int numTemazo, Temazo &temaso);
    static int listaRelleno(Temazo v[], int tamv, Temazo* lista[], int duracion_total);
private:
    std::string Titulo = "";
    std::string Interprete = "";
    std::string Genero = "Pop";
    std::string nombreUltimoGarito = "";
    Fecha fechaUltimoUso;
    int Duracion = 0;
    int Puntuacion = 0;
    int idTemazo;
    static int numTemazos;

};

#endif /* TEMAZO_H */

