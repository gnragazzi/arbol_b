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
***
