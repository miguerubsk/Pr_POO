/** 
 * @file StarFighter.h
 * @author Casipro Gramo
 *
 * @date Fecha estelar 20160309
 */

#ifndef STARFIGHTER_H
#define STARFIGHTER_H

#include <string>
#include "Pieza.h"

/**
 * @brief
 */
class StarFighter {
private:
    static const int MAX_PIEZAS = 100;
    int numPiezas = 0;
    static int _numStarFighters; ///< Número de objetos de esta clase instanciados
    int _idSF = 0; ///< Identificador único de la nave
    std::string _marca; ///< Marca de la nave (parece que las VW contaminan más)
    std::string _modelo; ///< Modelo de la nava
    int _numPlazas; ///< Número de plazas de la nave
    Pieza *piezas[MAX_PIEZAS];

public:
    StarFighter();
    StarFighter(std::string marca, std::string modelo);
    StarFighter(const StarFighter& orig);
    virtual ~StarFighter();
    
    std::string getMarca() const;
    int getNumPlazas() const;
    int getIdSF() const;
    std::string getModelo() const;
    
    StarFighter& setMarca(std::string marca);
    StarFighter& setNumPlazas(int numPlazas);
    StarFighter& setModelo(std::string modelo);
    
    std::string toCSV() const;
    void fromCSV(std::string csv);
    void addPieza(std::string _nombre, float _peso, std::string _descripcion);
    void eliminarPieza(std::string _nombre);
    int calcularPeso();
    
    StarFighter& operator=(const StarFighter& otro);
};

#endif /* STARFIGHTER_H */

