/** 
 * @file Piloto.h
 * @author Yoyapro Gramo
 *
 * @date Fecha estelar 20160309
 */

#ifndef PILOTO_H
#define PILOTO_H

#include <string>
#include "StarFighter.h"

/**
 * @brief
 */
class Piloto {
private:
    static int _numPilotos; ///< Número de objetos Piloto que han sido instanciados
    int _idP = 0; ///< Identificador único del Piloto
    std::string _nombre; ///< Nombre del Piloto
    std::string _nacionalidad; ///< Nacionalidad del Piloto
    int _numMisiones = 0; ///< Número de misiones en que ha participado
    long _fechaUltimaMision = 0; ///< Fecha estelar de su última misión
    std::string _incidenciasUltimaMision; ///< Incidencias reportadas por el piloto en su última misión.
    StarFighter* nave; ///< Nave del piloto

public:
    Piloto();
    Piloto(std::string nombre);
    Piloto(const Piloto& orig);
    virtual ~Piloto();
    
    int getIdP() const;
    int getNumMisiones() const;
    long getFechaUltimaMision() const;
    std::string getIncidenciasUltimaMision() const;
    std::string getNacionalidad() const;
    std::string getNombre() const;
    StarFighter* getNave() const;
    
    void setNacionalidad(std::string nacionalidad);
    void setIncidenciasUltimaMision(std::string incidenciasUltimaMision);
    void setNombre(std::string nombre);
    void setFechaUltimaMision(long fechaUltimaMision);
    void setNumMisiones(int numMisiones);
    void setNave(StarFighter* nave);
    
    std::string toCSV() const;
    
    Piloto& operator=(const Piloto& otro);
};

#endif /* PILOTO_H */

