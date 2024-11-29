// -*- C++ -*-

/* 
 * File:   funciones.h
 * Author: ANA RONCAL
 *
 * Created on 1 de setiembre de 2024, 20:43
 */

#ifndef FUNCIONES_H
#define FUNCIONES_H

void construir(struct Lista &);
const bool esListaVacia(const struct Lista &);
int longitud(const struct Lista &);

void insertarAlInicio(struct Lista &, char);
void insertarAlFinal(struct Lista &, char);
void insertarEnOrden(struct Lista &, char);

struct Nodo * crearNodo(char elemento, struct Nodo *);
struct Nodo * obtenerUltimoNodo(const struct Lista &);
struct Nodo * obtenerNodoAnterior(const struct Lista &, char);
struct Nodo * seEncuentra(const struct Lista &, char);
char retornaCabeza(const struct Lista & lista);

void eliminaNodo(struct Lista &, char);
void eliminaCabeza(struct Lista &);
void eliminaCola(struct Lista &);

void destruir(struct Lista &);
void imprime(const struct Lista &);

#endif /* FUNCIONES_H */