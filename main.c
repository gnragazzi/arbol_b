#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "arbol_b.h"
#ifdef __linux__
    char clear[] = "clear";
#else
    char clear[] = "cls";
#endif

void confirmacion(char []);

int main()
{
    int menu;
    Arbol_B arb;
    init(&arb);
    char msj[50];
    do
    {
        system(clear);
        printf("***Árbol B***\nOperaciones:\n\t1. Agregar Elemento\n\t2. Eliminar Elemento\n\t3. Evocar Elemento\n\t4. Ver Estructura\n\t***\n\t0. Salir\n?- ");
        scanf("%d",&menu);
        switch(menu)
        {
            case 1: alta();confirmacion("");break;
            case 2: baja();confirmacion("");break;
            case 3: 
            {
                int elemento = 0;
                enum bool exito = FALSE;
                system(clear);
                printf("Ingrese el elemento que desea buscar en la estructura.\n-? ");
                scanf("%d",&elemento);
                evocacion_asociativa(elemento, &exito);
                if(exito == TRUE) strcpy(msj, "El elemento se encuentra en la estructura.\n");
                else strcpy(msj, "El elemento no se encuentra en la estructura.\n");
                confirmacion(msj);
                break;
            }
            case 4: mostrar_estructura();confirmacion("");break;
            case 0: confirmacion("Saliendo");exit(1);
            default: printf("Opción inválida\n");confirmacion("");break;
        }
    }while(1);
}

void confirmacion(char str[])
{
    char c;
    if(strlen(str)>0) printf("%s\n",str);
    while ((c = getchar()) != '\n');
    printf("\nPulse ENTER para continuar...\n");
    while ((c = getchar()) != '\n');
    system(clear);
}
