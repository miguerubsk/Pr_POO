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

public:
    Droide();
    Droide(std::string marca, std::string modelo);
    Droide(const Droide& orig);
    virtual ~Droide();
    
    int getIdD() const;
    std::string getModelo() const;
    std::string getMarca() const;
    
    void setMarca(std::string marca);
    void setModelo(std::string modelo);
    
    std::string toCSV() const;
    
    Droide& operator=(const Droide& otro);
};

#endif /* DROIDE_H */

