/** 
 * @file   main.cpp
 * @author PON_AQUÍ_TU_NOMBRE
 * @date  mayo de 2020
 */

#include <iostream>
#include <fstream>
#include <sstream>
#include <stdexcept>

#include "Usuario.h"
#include "UsuarioMovil.h"
#include "UsuarioIP.h"
using namespace std;

void visualizaContactos(Usuario& u) {
    std::cout << "CONTACTOS de: " << u.getIdentificador() << std::endl
            << "_________________________________" << std::endl;
    for (int i = 1; i <= u.numContactos(); i++) {
        std::cout << i << ".- " << u.getContacto(i)->getIdentificador() << std::endl;
    }
}

void guardaContactos(Usuario& u, std::string fichero) {
    ofstream fs;
    fs.open(fichero, ofstream::trunc);
    if (fs.good()) {
        fs << "CONTACTOS de: " << u.getIdentificador() << std::endl
                << "_________________________________" << std::endl;
        for (int i = 1; i <= u.numContactos(); i++) {
            UsuarioIP *user = dynamic_cast<UsuarioIP*> (u.getContacto(i));
            if(user){
                fs << i << ".- " << "Contacto ip: " << u.getContacto(i)->getIdentificador() << std::endl;
            }else{
                fs << i << ".- " << "Contacto móvil: " << u.getContacto(i)->getIdentificador() << std::endl;
            }
        }
        fs.close();
    }else{
        std::cerr << "No se puede crear el fichero" << endl;
    }
}

/**  Pruebas MoviPOO
 */
int main(int argc, char** argv) {

    // PRUEBA 1

    std::cout << "====================PRUEBA 1====================\n";

    Usuario *manu = new UsuarioMovil("manu", false, true);
    Usuario *maria = new UsuarioIP("maria", false, false);


    manu->nuevoContacto(maria);
    maria->nuevoContacto(manu);

    if (manu->llamarA(maria) == true) {
        std::cout << manu->getIdentificador() << " llamando a: " << manu->llamandoA()->getIdentificador() << std::endl;
        manu->colgar();
    } else {
        std::cout << "La llamada no se ha podido completar" << std::endl;
    }


    if (maria->llamarA(manu) == true) {
        std::cout << maria->getIdentificador() << " llamando a: " << maria->llamandoA()->getIdentificador() << std::endl;
        maria->colgar();
    } else {
        std::cout << "La llamada no se ha podido completar" << std::endl;
    }







    // PRUEBA 2

    std::cout << "\n\n====================PRUEBA 2====================\n";

    Usuario *anonimo1 = new UsuarioIP("anonimo1", true, true);
    *anonimo1 = *maria;

    Usuario *anonimo2 = new UsuarioMovil("anonimo2", false, false);

    anonimo1->nuevoContacto(anonimo2);

    try {
        if (anonimo1->llamarA(manu) == true) {
            std::cout << anonimo1->getIdentificador() << " llamando a: " << anonimo1->llamandoA()->getIdentificador() << std::endl;
            anonimo1->colgar();
        } else {
            std::cout << "La llamada no se ha podido completar" << std::endl;
        }
        anonimo1->colgar();
    } catch (std::exception &e) {
        std::cerr << e.what() << std::endl;
    }

    try {
        if (anonimo1->llamarA(anonimo2) == true) {
            std::cout << anonimo1->getIdentificador() << " llamando a: " << anonimo1->llamandoA()->getIdentificador() << std::endl;
            anonimo1->colgar();
        } else {
            std::cout << "La llamada no se ha podido completar" << std::endl;
        }
        anonimo1->colgar();
    } catch (std::exception &e) {
        std::cerr << e.what() << std::endl;
    }


    // PRUEBA 3

    std::cout << "\n\n====================PRUEBA 3====================\n";
    
    if (maria->llamarAContacto("manu") == true) {
        std::cout << maria->getIdentificador() << " llamando a: " << maria->llamandoA()->getIdentificador() << std::endl;
        maria->colgar();
    } else {
        std::cout << "La llamada no se ha podido completar" << std::endl;
    }
    
    guardaContactos(*manu, "contactos.txt");


    return 0;
}

