/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   ordena.h
 * Author: Miguerubsk
 *
 * Created on 21 de abril de 2020, 11:59
 */

#ifndef ORDENA_H
#define ORDENA_H

template<typename T>
void ordena(T *vector[], int tamV) {
    std::sort(vector, vector + tamV);
}

#endif /* ORDENA_H */

