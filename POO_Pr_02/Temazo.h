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

class Temazo {
public:
    Temazo();
    Temazo(std::string titulo, std::string interprete, int duracion, int puntuacion = 0, std::string genero = "Pop");
    Temazo(const Temazo& orig);
    virtual ~Temazo();
    
    int GetPuntuacion() const;
    Temazo& SetDuracion(int Duracion);
    int GetDuracion() const;
    Temazo& SetInterprete(std::string Interprete);
    std::string GetInterprete() const;
    Temazo& SetTitulo(std::string Titulo);
    std::string GetTitulo() const;
    std::string GetGenero() const;
    Temazo& SetGenero(std::string Genero);

    
    static void mostrarTemazo(Temazo &T);
private:
    std::string Titulo = "";
    std::string Interprete = "";
    std::string Genero = "Pop";
    int Duracion = 0;
    int Puntuacion = 0;

};

#endif /* TEMAZO_H */

