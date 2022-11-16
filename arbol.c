#include "arbol.h"

nodoArbol*inicArbol()
{
    return NULL;
}

nodoArbol*crearNodoArbol(char nombreLibro[30],char genero[20],char nombrePersona[20],int cantPaginas,int puntaje)
{
    nodoArbol*nuevoNodo=(nodoArbol*)malloc(sizeof(nodoArbol));
    strcpy(nuevoNodo->nombreLibro,nombreLibro);
    strcpy(nuevoNodo->genero,genero);
    strcpy(nuevoNodo->NombrePersona,nombrePersona);
    nuevoNodo->Puntaje = puntaje;
    nuevoNodo->cantPaginas = cantPaginas;
    nuevoNodo->izq=NULL;
    nuevoNodo->der=NULL;

    return nuevoNodo;
}
nodoArbol*agregarArbol(nodoArbol*arbol,char nombreLibro[30],char genero[20],char nombrePersona[20],int cantPaginas,int puntaje)
{
    nodoArbol*nuevoNodo=crearNodoArbol(nombreLibro,genero,nombrePersona,cantPaginas,puntaje);
    if(arbol==NULL)
    {
        arbol=nuevoNodo;
    }
    else
    {
        if(nuevoNodo->Puntaje<arbol->Puntaje)
        {
            arbol->izq=agregarArbol(arbol->izq,nombreLibro,genero,nombrePersona,cantPaginas,puntaje);
        }
        else
        {
            arbol->der=agregarArbol(arbol->der,nombreLibro,genero,nombrePersona,cantPaginas,puntaje);
        }
    }
    return arbol;
}
nodoArbol*cargaArbol(nodoArbol*arbol)
{
    char continuar;
    char nombreLibro[30];
    int cantPaginas;
    char genero[20];
    int Puntaje;
    char NombrePersona[20];
    do{
    printf("ingrese el nombre del libro..\n");
    fflush(stdin);
    gets(nombreLibro);
    printf("ingrese el genero\n");
    fflush(stdin);
    gets(genero);
    printf("ingrese la cantidad de paginas\n");
    scanf("%i",&cantPaginas);
    printf("ingrese el puntaje\n");
    scanf("%i",&Puntaje);
    printf("ingrese el nombre de la persona\n");
    fflush(stdin);
    gets(NombrePersona);
   arbol = agregarArbol(arbol,nombreLibro,genero,NombrePersona,cantPaginas,Puntaje);
    printf("desea continuar?\n");
    fflush(stdin);
    scanf("%c",&continuar);
    }while(continuar=='s');

    return arbol;
}
void inOrder(nodoArbol*arbol)
{
    if(arbol!=NULL)
    {
        inOrder(arbol->izq);
        printf("[%s]",arbol->NombrePersona);
        inOrder(arbol->der);
    }
}




