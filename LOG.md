***
#2da Entrada:

Planificación: 

- La siguiente funcionalidad a trabajar es el alta. El alta de un elemento se realiza siempre en un nodo externo del árbol. 

- Alta:
    + INPUT
        - x, elemento a insertar
        - arbol, árbol-B donde se quiere insertar el elemento
    + OUTPUT
        - EXITO/FRACASO según el resultado de la operación.
    + PROCEDIMIENTO
        - localizar x,
            - Si x está en la estructura, retornar FRACASO
            - Sino, asignar a pos la posición de x dentro de un nodo. La localización utilizará una pila como estructura complementaria para almacenar todos los nodos, en el recorrido desde la raiz hasta la hoja.
        - Comprobar la cardinalidad de elementos del nodo donde se encuentra x. 
            - Si Hay lugar disponible en el nodo para un nuevo elemento -> se inserta el elemento en el nodo con los corrimientos necesarios para mantener el orden.
            - Si No hay lugar en el nodo 
                - Comprobar si el nodo es raiz, en tal caso, crear un nuevo nodo, asignarlo como raiz del árbol                 
                -> SPLIT(). /* Si el nodo es raiz, se debe crear un nuevo nodo, para que actue de nodo padre, con el primer puntero apuntando a Nodo*/
- SPLIT: 
    + INPUT
        - Nodo el nodo externo del Árbol B donde se quiere realizar la inserción, 
        - Nodo_Padre el nodo padre de Nodo; (si Nodo=raiz, entonces NodoPadre debe ser un nuevo nodo creado) 
        - punteroPadre el puntero de Nodo_Padre que apunta a Nodo. 
        - pos, posición en la que va el elemento 
        - x, el elemento a insertar
        - p-der, puntero a nodo, que debe ir en pos+1. No es necesario para cuando se agrega un nodo nuevo (se puede pasar como valor NULL), pero impresindible en el caso recursivo.
    + PROCEDIMIENTO
        1. Sea N el conjunto resultante de la unión de los elementos de Nodo y {x}. Se ordenan los m elementos de N. Así N={X_1,X_2,...,X_m-1,X_m} (en realidad, no es necesario ordenar porque los elementos ya se encontraban ordenados. Solamente hay que insertar el elemento en la posición que devuelve la localización y correr los elementos más grandes);
        2. Se particiona N en 3 conjuntos, a saber: N_1={X_1,X_2,...,X_⌈m/2⌉-1}, N_2={X_⌈m/2⌉}, N_3={⌈m/2⌉+1,...,X_m-1,X_m}
        3. Se reemplazan los elementos de Nodo por los elementos de N_1, 
        4. Se crea un nodo Nuevo_Nodo.
        5. Se asignan a Nodo_Nuevo los elementos de N_3.
        6. Se inserta el único elemento de N_2 en Nodo_Padre. 
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

