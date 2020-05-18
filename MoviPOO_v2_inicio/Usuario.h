/** 
 * @file   Usuario.h
 * @author jrbalsas
 * @date  21 de marzo de 2020
 */

#ifndef USUARIO_H
#define USUARIO_H

#include <string>
#include <stdexcept>

class Usuario {
public:
    static const int MAX_CONTACTOS = 10;

    Usuario() = default;
    Usuario(std::string identificador, bool oculto);

    Usuario(const Usuario& orig) = default;
    virtual ~Usuario() = default;

    void setIdentificador(std::string identificador);
    std::string getIdentificador() const;

    void setOculto(bool oculto);
    bool isOculto() const;
    
    virtual bool llamarA(Usuario *otro);
    bool llamarAContacto(std::string identificador);
    void colgar();
    Usuario* llamandoA();
    virtual bool soportaDatos() const = 0;
    virtual bool LlamadasVoz() const;
    
    void nuevoContacto(Usuario *contacto);
    Usuario* getContacto (int cual);
    int numContactos();

    virtual Usuario& operator=(const Usuario& orig);

    int contactosDisponibles();

private:
    std::string identificador = "Anónimo";
    bool oculto = false;
    Usuario* contactos[MAX_CONTACTOS];
    int nContactos= 0;
    Usuario* llamando_a = nullptr;
};

#endif /* USUARIO_H */

