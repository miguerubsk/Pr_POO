/** 
 * @file   main.cpp
 * @author TU_NOMBRE
 * @date   marzo de 2020
 */

#include <iostream>

#include "Usuario.h"

using namespace std;

/**  Pruebas MoviPOO
 */
int main(int argc, char** argv) {
    
    //a) Crear dos usuarios diferentes, ambos visibles
    Usuario user1("Mario", false), user2("Angela", false);
    //b) Añadir a cada usuario al otro como contacto
    user1.nuevoContacto(user2);
    user2.nuevoContacto(user1);
    //c) El primer usuario llama al segundo. Si la llamada tiene éxito
    //  mostrar los datos del usuario al que llama
    if(user1.llamarA(user2))
        std::cout << "Identificador: " << user2.getIdentificador() << std::endl;
    //d) Crear un tercer usuario como oculto e intentar añadirlo como contacto
    //   al primero capturando y mostrando la excepción
    Usuario user3("Pedro", true);
    try{
        user1.nuevoContacto(user3);
    }catch (std::invalid_argument &e){
        std::cerr << e.what();
    }
    //e) Asignar (con operador = ) el primer usuario al tercero. Con el tercer usuario
    user3 = user1;
    // visualizar su identificador, nº de contactos disponibles (pueden ser llamados)
    std::cout << "Identificador: " << user3.getIdentificador();
    std::cout << "\nContactos disponibles: " << user3.contactosDisponibles();
    // y el identificador de su primer contacto
    std::cout << "\nIdentificador del contacto 1: " << user3.getContacto(0).getIdentificador();
    //f) liberar los recursos que sea necesario

    return 0;
}

