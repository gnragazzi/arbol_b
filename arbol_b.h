#include <malloc.h>
#define M 10

enum bool {TRUE=1, FALSE};
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

int localizacion(Nodo n, int x, int *exito)
{
    int li, ls, m;
    li = 0;
    ls = n.cant_elem -1; //ls inclusivo
    m = (li + ls)/2;
    while(n.elementos[m]!=x && li<=ls)
    {
        if(n.elementos[m]<x)
            li = m + 1;
        else
            ls = m - 1;
        m = (li + ls)/2;
    }
    if(li<=ls)
    {
        *exito = TRUE;
        return m;
    }
    else 
    {
        *exito = FALSE;
        return li;
    }
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
int evocacion_asociativa(int x, enum bool *exito)
{
    //localizacion()   
}
void mostrar_estructura()
{
    printf("Mostrar Estructura\n");
}
