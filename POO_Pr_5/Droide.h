/** 
 * @file Droide.h
 * @author Casipro Gramo
 *
 * @date Fecha estelar 20160309
 */

#ifndef DROIDE_H
#define DROIDE_H

#include <string>

/**
 * @brief
 */
class Droide {
private:
    static int _numDroides; ///< Número de droides instanciados
    int _idD = 0; ///< Identificador del droide
    std::string _marca; ///< Marca del droide
    std::string _modelo; ///< Modelo de droide
    bool averiado = false; ///< Indica si el droide está averiado

public:
    Droide();
    Droide(std::string marca, std::string modelo, bool averiado);
    Droide(const Droide& orig);
    virtual ~Droide();
    
    int getIdD() const;
    std::string getModelo() const;
    std::string getMarca() const;
    bool isAveriado() const;

    
    Droide& setMarca(std::string marca);
    Droide& setModelo(std::string modelo);
    Droide& setAveriado(bool averiado);

    
    std::string toCSV() const;
    void fromCSV(std::string csv);
    
    Droide& operator=(const Droide& otro);
};

#endif /* DROIDE_H */

