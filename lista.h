#ifndef LISTA_H_INCLUDED
#define LISTA_H_INCLUDED
#include "arbol.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct
{
     char nombreLibro[30];
      int cantPaginas;
     char genero[20];
     int Puntaje;
     struct nodoListaLibro* sig;
}nodoListaLibro;

typedef struct celda
{
   char NombrePersona[20];
   struct nodoListaLibro * listaLibros;
}celda;


///prototipado
nodoListaLibro*inicLista();
nodoListaLibro*crearNodoLista(char nombreLisbro[30],char genero[20],int cantPaginas,int puntaje);
nodoListaLibro*agregarOrdenado(nodoListaLibro*lista,char nombreLibro[30],char genero[20],int cantPaginas,int puntaje);
void mostrarLista(nodoListaLibro*lista);
int buscarPosArreglo(celda arreglo [10],char nombrePersona[20],int validos);
int alta(nodoArbol*arbol,celda arreglo[10],int dimencion,int validos);
int pasajeArbolArreglo(nodoArbol*arbol,celda arreglo[10],int validos,int dimencion);
void muestraArreglo(celda arreglo [10],int validos);

#endif // LISTA_H_INCLUDED
