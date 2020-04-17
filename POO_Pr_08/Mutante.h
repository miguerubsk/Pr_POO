/**
 * @file Mutante.h
 * @author algarcia
 *
 * @date 6 de abril de 2016, 19:52
 */

#ifndef MUTANTE_H
#define MUTANTE_H

#include <string>

#include "Poder.h"
#include "PoderPsiquico.h"
#include "PoderFisico.h"

using std::string;

/**
 * @brief Clase Muntante
 */
class Mutante {
public:
    static const int MAX_PODERES = 10; ///< Max. moderes de un mutante

public:
    Mutante() = default;
    Mutante(string nombre, string apodo, int fechaN,string nacionalidad);
    Mutante(const Mutante& orig);
    virtual ~Mutante();
    string getNombreReal() const;
    string getNacionalidad() const;
    int getFechaDeNacimiento() const;
    string getApodo() const;
    Poder* getPoder(int cual);
    int getNumPoderes() const;
    
    void setNombreReal(string nombreReal);
    void setNacionalidad(string nacionalidad);
    void setFechaDeNacimiento(int fechaDeNacimiento);
    void setApodo(string apodo);
    
    void addPoder(string nombre, string descripcion, string afectaA, float capacidadD);
    void addPoderPsiquico(string nombre, string descripcion, string afectaA, float capacidadD);
    void addPoderFisico(string nombre, string descripcion, string afectaA, float capacidadD);
    void borraPoder(int cual);
    void addPoder(const Poder &poder);
    void addPoderPsiquico(const PoderPsiquico &poder);
    void addPoderFisico(const PoderFisico &poder);
    float capacidadDestructivaTotal();

    string toCSV() const;

    Mutante& operator=(const Mutante& orig);

private:
    string _nombreReal = "---";
    string _apodo = "---";
    int _fechaDeNacimiento = 0;
    string _nacionalidad = "---";
    Poder *poderes[MAX_PODERES];
    int numPoderes = 0;

};

#endif /* MUTANTE_H */

