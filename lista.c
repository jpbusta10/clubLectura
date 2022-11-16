#include "lista.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "arbol.h"
nodoListaLibro*inicLista()
{
    return NULL;
}

nodoListaLibro*crearNodoLista(char nombreLibro[30],char genero[20],int cantPaginas,int puntaje)
{
    nodoListaLibro*nuevoNodo = (nodoListaLibro*)malloc(sizeof(nodoListaLibro));
    strcpy(nuevoNodo->nombreLibro,nombreLibro);
    strcpy(nuevoNodo->genero,genero);
    nuevoNodo->cantPaginas=cantPaginas;
    nuevoNodo->Puntaje=puntaje;
    nuevoNodo->sig=NULL;

    return nuevoNodo;
}

nodoListaLibro*agregarOrdenado(nodoListaLibro* lista,char nombreLibro[30],char genero[20],int cantPaginas,int puntaje)
{
    nodoListaLibro*nuevoNodo = crearNodoLista(nombreLibro,genero,cantPaginas,puntaje);
    if(lista==NULL)
    {
        lista=nuevoNodo;
    }
    else
    {
        if(nuevoNodo->Puntaje<lista->Puntaje)
        {
            nuevoNodo->sig=lista;
            lista=nuevoNodo;
        }
        else
        {
            nodoListaLibro*seguidora = lista;
            nodoListaLibro*anterior = lista;
            while((seguidora!=NULL)&&(puntaje>seguidora->Puntaje))
            {
                anterior = seguidora;
                seguidora=seguidora->sig;
            }
            anterior->sig=nuevoNodo;
            nuevoNodo->sig=seguidora;
        }
    }
    return lista;
}
void mostrarLista(nodoListaLibro*lista)
{
    nodoListaLibro*seguidora=lista;
    while(seguidora!=NULL)
    {
        printf("nombre libro: %s\n",seguidora->nombreLibro);
        printf("genero: %s\n",seguidora->genero);
        printf("cant paginas: %i\n",seguidora->cantPaginas);
        printf("puntaje: %i\n\n",seguidora->Puntaje);
        seguidora = seguidora->sig;
    }
}
int buscarPosArreglo(celda arreglo [10],char nombrePersona[20],int validos)
{
    int rta = -1;
    for(int i=0;i<validos;i++)
    {
        if(strcmp(arreglo[i].NombrePersona,nombrePersona)==0)
        {
            rta=i;
        }
    }
    return rta;
}
int alta(nodoArbol*arbol,celda arreglo[10],int dimencion,int validos)
{
    if((arbol!=NULL)&&(validos<dimencion))
    {
        int indice=0;
        indice = buscarPosArreglo(arreglo,arbol->NombrePersona,validos);
        if(indice == -1 )
        {
            validos++;
            indice = validos - 1;
            arreglo[indice].listaLibros=inicLista();
            strcpy(arreglo[indice].NombrePersona,arbol->NombrePersona);

        }
        arreglo[indice].listaLibros=agregarOrdenado(arreglo[indice].listaLibros,arbol->nombreLibro,arbol->genero,arbol->cantPaginas,arbol->Puntaje);
    }
    return validos;
}
int pasajeArbolArreglo(nodoArbol*arbol,celda arreglo[10],int validos,int dimencion)
{
    if((arbol!=NULL))
    {
        validos = alta(arbol,arreglo,dimencion,validos);
        validos = pasajeArbolArreglo(arbol->izq,arreglo,validos,dimencion);
        validos = pasajeArbolArreglo(arbol->der,arreglo,validos,dimencion);

    }
    return validos;
}

void muestraArreglo(celda arreglo [10],int validos)
{
    for(int i=0;i<validos;i++)
    {
        printf("NOMBRE PERSONA: %s\n",arreglo[i].NombrePersona);
        printf("LISTA:\n");
        mostrarLista(arreglo[i].listaLibros);
        printf("--------------")
    }
}








