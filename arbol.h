#ifndef ARBOL_H_INCLUDED
#define ARBOL_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct nodoArbol
{
    char nombreLibro[30];
    int cantPaginas;
    char genero[20];
    int Puntaje;
    char NombrePersona[20];
    struct nodoArbol * izq;
    struct nodoArbol * der;
} nodoArbol;

///prototipados
nodoArbol*inicArbol();
nodoArbol*crearNodoArbol(char nombreLibro[30],char genero[20],char nombrePersona[20],int cantPaginas,int puntaje);
nodoArbol*agregarArbol(nodoArbol*arbol,char nombreLibro[30],char genero[20],char nombrePersona[20],int cantPaginas,int puntaje);
nodoArbol*cargaArbol(nodoArbol*arbol);
void inOrder(nodoArbol*arbol);


#endif // ARBOL_H_INCLUDED
