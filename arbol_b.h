#include <malloc.h>
#define M 10

typedef struct nodo{
    int cant_elem;
    int elementos[M-1];
    struct nodo *hijos[M];
}Nodo;

typedef struct{
    Nodo *raiz;
}Arbol_B;

void init(Arbol_B *a)
{
    a->raiz = (Nodo*) malloc(sizeof(Nodo));
    a->raiz->cant_elem = 0;
}

void busqueda_binaria()
{
    printf("Búsqueda Binaria\n");
}

void localizacion()
{
    busqueda_binaria();
    printf("Localización!\n");
}

void split()
{
    printf("Split\n");
}

void underflow()
{
    
}
void alta()
{
    printf("Alta\n");
}

void baja()
{
    printf("Baja\n");
}
void evocacion_asociativa()
{
    printf("Evocación Asociativa\n");
}
void mostrar_estructura()
{
    printf("Mostrar Estructura\n");
}
