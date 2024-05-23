***
#3ra Entrada:
- Algoritmo de alta | Versión 2.
    - Supuestos: 
        - Contamos con un registro Nodo con 3 campos: 
            - cant_elem // entero que representa la cantidad actual de elementos en un nodo.
            - elementos // arreglo con capacidad para m-1 elementos, que almacena cada Nodo. Idealmente una nupla, por simplicidad en esta implementación un entero.
            - hijos // arreglo con capacidad para m punteros a nodo. Estos punteros llevan a los nodos hijo del nodo, por lo que deberían respetar el ordenamiento del Árbol B.
        - Contamos con un registro Árbol con un único campo, raiz:↑Nodo
        - Contamos con una pila Pila_Nodos, accesible globalmente, que almacena tuplas (puntero_a_nodo, posición_de_hijo) que usaremos para almacenar referencias a los nodos recorridos desde la raiz hasta la hoja, en caso de que necesitemos modificarlos al insertar un elemento en un nodo donde cant_elem = m-1.
        - Contamos con un tipo enumerado resultado={EXITO,FRACASO,MEMORIA_INSUFICIENTE} que representa los posibles resultados de las operaciones a realizar en la estructura
        - Contamos con una función localizar(in arbol: ↑Árbol, in x:int, out pos: int, out nodo: Nodo; out resultado: resultado), donde x es el elemento a localizar, pos es la posición donde está (EXITO) o debería estar(fracaso). Asimismo, es en localizar donde la pila Pila_Nodos se va llenando.
        - Contamos con un enumerado operacion={INSERCION, ELIMINACION}
        - Contamos con la función corrimiento(in arr, in x, in pos, in tipo:operacion) que coloca el elemento x en arr[pos], y corre todos los elementos según el tipo de operación.
    - Alta
        + INPUT
            - x: int // elemento a insertar
            - arbol: ↑Árbol //arbol-b donde se quiere insertar el elemento
        + OUTPUT
            - resultado: resultado;
        + Variables Locales
            - pos: int 
            - pos_hijo: int
            - nodoActual: ↑Nodo
            - nodoPadre: ↑Nodo
        + Procedimiento
            1. localizar(arbol, x, &pos, ↑nodoActual,&resultado);
            2. Si (resultado = éxito)
                2.a.    return FRACASO;
            4.  a. Si (nodoActual->cant_elem = m)
                    i.  corrimiento(nodoActual->elementos, x, pos, INSERCION)
                    ii. return EXITO
                b. Sino
                    i.  a. Si (arbol->raiz == nodoActual)
                            1. nodoPadre <- crearNodo();
                                a. Si no hay memoria, return FALTA_MEMORIA
                            2. nodoPadre->hijos[0] <- nodoActual;
                            3. arbol->raiz <- nodoPadre;
                            4. pos_hijo<- 0;                            
                        b. Sino
                            1. (nodoPadre,pos_hijo) <- pop(Pila_Nodos)
                    ii. return split(arbol,nodoActual,nodoPadre,pos_hijo,pos,x,NULL);
***
#2da Entrada:

Planificación: 

- La siguiente funcionalidad a trabajar es el alta. El alta de un elemento se realiza siempre en un nodo externo del árbol. 
- Algoritmo de Alta | Versión 1.
    - Alta:
        + INPUT
            - x, elemento a insertar
            - arbol, árbol-B donde se quiere insertar el elemento
        + OUTPUT
            - EXITO/FRACASO/NO_MEMORIA según el resultado de la operación.
        + PROCEDIMIENTO
            1 localizar x,
                1.a Si x está en la estructura, retornar FRACASO
            2 Asignar a pos la posición devuelta por la localización. La localización utilizará una pila como estructura complementaria para almacenar todos los nodos, en el recorrido desde la raiz hasta la hoja.
            3 Comprobar la cardinalidad de elementos del nodo donde se encuentra x. 
                3.a Si Hay lugar disponible en el nodo para un nuevo elemento -> se inserta el elemento en el nodo con los corrimientos necesarios para mantener el orden.
                3.b Si No hay lugar en el nodo 
                    3.b.i Comprobar si el nodo es raiz, en tal caso, crear un nuevo nodo, asignarlo como raiz del árbol y asignar Nodo como el puntero en la posición 0;
                    3.b.ii SPLIT(). 
            4 Retornar el resultado del SPLIT;
    - SPLIT: 
        + INPUT
            - arbol_b, un puntero al Árbol B donde se realiza la Inserción
            - Nodo el nodo externo del Árbol B donde se quiere realizar la inserción, 
            - Nodo_Padre el nodo padre de Nodo; (si Nodo=raiz, entonces NodoPadre debe ser un nuevo nodo creado) 
            - pos_hijo la posición que ocupa Nodo en la lista de hijos de Nodo_Padre
            - pos, posición en la que va el elemento 
            - x, el elemento a insertar
            - p-der, puntero a nodo, que debe ir en pos+1. No es necesario para cuando se agrega un nodo nuevo (se puede pasar como valor NULL), pero impresindible en el caso recursivo.
        + OUTPUT:
            - EXITO/NO_MEMORIA según el resultado de la operación.
        + PROCEDIMIENTO
            1. Sea N=elementos de Nodo U {x}. (no es necesario ordenar el conjunto resultante, porque los elementos ya se encontraban ordenados, pero si hay que insertar x en pos y correr los elementos cuyo índice > pos en un lugar);
            2. Se particiona N en 3 conjuntos, a saber: N_1={X_1,X_2,...,X_⌈m/2⌉-1}, N_2={X_⌈m/2⌉}, N_3={⌈m/2⌉+1,...,X_m-1,X_m}
            3. Se reemplazan los elementos de Nodo por los elementos de N_1, 
            4. Se crea un nodo Nodo_Nuevo.
            5. Se asignan a Nodo_Nuevo los elementos de N_3.
            6. Si p-der no es NULL /* Si p-der no es NULL, entonces estamos en una llamada recursiva al SPLIT, y tenemos un nuevo nodo proveniente de una invocación previa que es apuntado por p-der  */
                6.a. Se realiza la misma operación que 1, pero con el arreglo de punteros, agregando p-der en la posición correspondiente. 
                6.b. Se particiona en 3 el arreglo de punteros.
                6.c. Se realizan las asignaciones correspondientes al conjunto de punteros de Nodo y Nuevo Nodo
            7. p-der apunta a Nodo_Nuevo
            8.  Si cantidad de elementos de Nodo_Padre < m-1
                    8.a.i. Se inserta el nuevo elemento en Nodo_Padre, realizando los corrimientos necesarios en el arreglo de elementos. 
                    8.a.ii. Se inserta p-der en Nodo_Padre en la posición correspondiente (realizando corrimientos) del arreglo de punteros
                    8.a.iii. Retornar EXITO;
                Sino
                    8.b.i. Nodo <- NodoPadre y Se asigna a Nodo_Padre el próximo elemento de la pila de Nodos. 
                    8.b.ii. En caso de que Nodo_Padre sea nulo, se crea un nuevo nodo, se asigna como raiz del árbol; se establece el puntero a Nodo y el p-der como primer y segundo elementos del arreglo de hijos de la raiz, y se agrega X_⌈m/2⌉ como elemento en la primer posición del arreglo de elementos. Retornar EXITO
                    8.b.iii. Se llama a SPLIT() con x<-X_⌈m/2⌉, 
                    8.b.iiii. Se retorna el resultado de split.
                 
***
# 1era entrada:

Planificación:

- Por simplicidad, y sin perdida de generalidad, el árbol a construir en este proyecto será un árbol-B de int. 
- Un árbol-B de orden m está formado por nodos <A1,x1,A2,...,Ai-1,xi-1,Ai> , donde cada nodo cumple con las siguientes características:
    - 2≤i≤m si es la raiz del árbol
    - ⌈m/2⌉≤i≤m si es no raiz del árbol
    - Es ordenado
    - Es balanceado: h(A1)=h(A2)=...=h(Ai-1)=h(Ai)
    - Ak o es vacío o es nodo interno no raiz con 1≤k≤i
- En un primer momento, trabajaremos con un m fijo (m = 10).
- Cada Nodo debería estar formado por un arreglo de m-1 enteros y un arreglo de m punteros a Nodo. También es importante llevar la cuenta de cuantos elementos hay en un Nodo.
- La localización funciona con trisección en el conjunto de elementos del nodo. 

