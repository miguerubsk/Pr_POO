/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   ContenedorItems.h
 * Author: Miguerubsk
 *
 * Created on 5 de mayo de 2020, 13:24
 */

#ifndef CONTENEDORITEMS_H
#define CONTENEDORITEMS_H

#include "EmptyContainer.h"
#include <stdexcept>
#include <string>

template <typename T>
class ContenedorItems {
public:
    ContenedorItems<T>();
    ContenedorItems<T>(int cuantosCaben);
    ContenedorItems<T>(const ContenedorItems& orig);
    virtual ~ContenedorItems();
    int cuantosCaben();
    int cuantosHay() const;
    virtual void mete(T *item);
    T& consulta(int cual);
    T* saca(int cual);
protected:
    int _maxItems = 27; ///< Tamaño del vector de punteros
    T* *_items = nullptr; ///< Vector de punteros creado dinámicamente
    int _numItems = 0; ///< Primeras posiciones del vector ocupadas (máximo maxItems)
};

template <typename T>
ContenedorItems<T>::ContenedorItems(): ContenedorItems(27){}

template <typename T>
ContenedorItems<T>::ContenedorItems(int cuantosCaben):_maxItems(cuantosCaben),_numItems(0) {    
    _items=new T*[cuantosCaben];
    for (int i = 0; i < cuantosCaben; i++) {
        _items[i]=nullptr;
    }
}

/**Crea un Cofre vacío del mismo tamaño del original*/
template <typename T>
ContenedorItems<T>::ContenedorItems(const ContenedorItems& orig) 
    :_maxItems(orig._maxItems)
    ,_numItems(orig._numItems) {

    _items=new T*[_maxItems];
    for (int i = 0; i < _maxItems; i++) {
        _items[i]=nullptr;
    }
}

template <typename T>
ContenedorItems<T>::~ContenedorItems() {
    delete [] _items;
}

template <typename T>
int ContenedorItems<T>::cuantosHay() const {
    return _numItems;
}

template <typename T>
int ContenedorItems<T>::cuantosCaben() {
    return _maxItems;
}

template <typename T>
void ContenedorItems<T>::mete(T* item) {
    if (!item) 
        throw std::invalid_argument ("[ContenedorItems::mete] Intento de asignar puntero 0");
    if (_numItems==_maxItems)
        throw std::out_of_range("[ContenedorItems::mete] No caben más elementos en el cofre");
    _items[_numItems++]=item;
}

/**@param cual nº orden del elemento a consultar
 * @return Referencia al objeto indicado del cofre
   @throw std::out_of_range si el elemento no existe
   @throw EmptyContainer si el cofre está vacío*/
template <typename T>
T& ContenedorItems<T>::consulta(int cual) {
    if (_numItems==0) 
        throw EmptyContainer("[ContenedorItems::consulta] El cofre está vacío");
    if (cual<=0 || cual >_numItems)
        throw std::out_of_range("[ContenedorItems::consulta] El elemento indicado no existe");
    return *_items[cual-1];
}


/**@param cual nº orden del elemento a extraer
 * @return Extrae del cofre y devuelve el puntero al Item indicado
   @throw std::out_of_range si el elemento no existe
   @throw EmptyContainer si el cofre está vacío*/
template <typename T>
T* ContenedorItems<T>::saca(int cual) {
    if (_numItems==0) 
        throw EmptyContainer("[ContenedorItems::saca] El cofre está vacío");
    if (cual<=0 || cual >_numItems)
        throw std::out_of_range("[ContenedorItems::mete] El elemento indicado no existe");
    Item* elemento = _items[cual-1];
    _numItems--;
    if (_numItems>0)
        _items[cual-1]=_items[_numItems];
    return elemento;
}

#endif /* CONTENEDORITEMS_H */

