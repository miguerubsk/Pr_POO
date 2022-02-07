/** 
 * @file   Usuario.cpp
 * @author jrbalsas
 * @date  21 de marzo de 2020
 */

#include "Usuario.h"

Usuario::Usuario(std::string identificador, bool oculto)
    :identificador(identificador), oculto(oculto) {
}

std::string Usuario::getIdentificador() const {
    return identificador;
}

void Usuario::setIdentificador(std::string identificador) {
    if (identificador.length()<5 || identificador.length()>15)
        throw std::length_error("[Usuario::setIdentificador] longitud de identificador no válida");
    this->identificador = identificador;
}

bool Usuario::isOculto() const {
    return oculto;
}

void Usuario::setOculto(bool oculto) {
    this->oculto = oculto;
}

/** Llamar a otro usuario 
 * @param otro Usuario al que se va a llamar
 * @post Establece una llamada con el usuario indicado si está disponible
 * @post La llamada no se establece si el otro usuario está oculto o ya se encuentra llamando
 * @return true si se establece la llamada y false en caso contrario
 */
bool Usuario::llamarA(Usuario* otro) {
    if (otro==nullptr || otro->llamandoA()!=nullptr || otro->isOculto() ) {
        return false;
    }
    llamando_a=otro;
    return true;
}

bool Usuario::llamarAContacto(std::string identificador) {
    for(int i = 1; i <= nContactos; ++i){
        if(getContacto(i)->getIdentificador() == identificador)
            return llamarA(getContacto(i));
    }
    return false;
}

void Usuario::colgar() {
    llamando_a=nullptr;
}

Usuario* Usuario::llamandoA() {
    return llamando_a;
}

void Usuario::nuevoContacto(Usuario* contacto) {
    if (nContactos==MAX_CONTACTOS) throw std::out_of_range("[Usuario::nuevoContacto]  agenda completa");
    if (contacto==nullptr || contacto->isOculto()) throw std::invalid_argument("[Usuario::nuevoContacto]  No es posible añadir al contacto");
    contactos[nContactos]=contacto;
    nContactos++;
}

Usuario* Usuario::getContacto(int cual) {
    if (cual<1 || cual>nContactos) throw std::out_of_range("[Usuario::getContacto] Contacto no válido");
    return contactos[cual-1];
}

int Usuario::numContactos() {
    return nContactos;
}

Usuario& Usuario::operator=(const Usuario& orig) {
    // Check for self-assignment!
    if (this == &orig) // Same object?
        return *this; // Yes, so skip assignment, and just return *this.        
    // Deallocate, allocate new space, copy values...
    for (int i = 0; i < orig.nContactos; i++) {
        contactos[i] = orig.contactos[i];
    }
    nContactos = orig.nContactos;
    identificador = orig.identificador;
    llamando_a = orig.llamando_a;
    oculto = orig.oculto;
    return *this;
}

int Usuario::contactosDisponibles() {
    int total=0;
    for (int i = 0; i < nContactos; i++) {
        if (contactos[i]->llamandoA()==nullptr && contactos[i]->isOculto()==false) {
            total++;
        }
    }
    return total;
}

bool Usuario::LlamadasVoz() const {
    return false;
}
