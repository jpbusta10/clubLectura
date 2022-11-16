#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "arbol.h"
#include "lista.h"
int main()
{
    char continuar;
    int validos = 0;
    int dimencion = 10;
    celda personas[dimencion];

    nodoArbol*arbol = inicArbol();
    arbol = cargaArbol(arbol);

    inOrder(arbol);
    printf("\n");
   validos = pasajeArbolArreglo(arbol,personas,validos,dimencion);
    muestraArreglo(personas,validos);




    return 0;
}
