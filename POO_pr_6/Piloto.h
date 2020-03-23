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
#include "Droide.h"
#include "Informe.h"

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
    StarFighter* nave = nullptr; ///< Nave del piloto
    Droide* auxiliar = nullptr; ///< Droide que asiste al piloto

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
    Droide* getAuxiliar() const;

    Piloto& setNacionalidad(std::string nacionalidad);
    Piloto& setIncidenciasUltimaMision(std::string incidenciasUltimaMision);
    Piloto& setNombre(std::string nombre);
    Piloto& setFechaUltimaMision(long fechaUltimaMision);
    Piloto& setNumMisiones(int numMisiones);
    Piloto& setNave(StarFighter* nave);
    Piloto& setAuxiliar(Droide* auxiliar);

    std::string toCSV() const;
    void fromCSV(std::string csv);
    Informe generaInforme();
    
    Piloto& operator=(const Piloto& otro);
};

#endif /* PILOTO_H */

