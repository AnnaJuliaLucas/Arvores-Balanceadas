# Implementação de Árvore AVL 

A árvore AVL é uma árvore de pesquisa binária de **autobalanceamento** que garante complexidade de tempo O(logN) para operações de inserção, exclusão e pesquisa.

Esta versão é implementada em linguagem C++, e permite múltiplos elementos com os mesmos valores

#### Como usá-la:

| Função | Definição | Complexidade de tempo |
| --- | --- | --- |
| `AVLTree()` | construtor padrão que inicializa a raiz com nulo | O(1) |
| `~AVLTree()` | destrutor padrão. | O(1) |
| `insert()` | insere um novo nó na árvore AVL | O(log n) |
| `remove()` | remove um nó existente na árvore AVL| O(log n) |
| `rotateLeft()` | executa uma rotação à esquerda | O(1) |
| `rotateRight()` | executa uma rotação à direita | O(1) |
| `rotateLeftRight()` | executa uma rotação à esquerda seguida de uma rotação à direita | O(1) |
| `rotateRightLeft()` | tamanho da árvore de retorno | O(1) |
| `insertNode()` | Insere um novo nó. Se a árvore estiver desequilibrada após a inserção, são realizadas rotações para equilibrá-la. | O(log n)|
| `removeNode()` | Remove um nó existente. Se a árvore estiver desequilibrada após a remoção, são realizadas rotações para equilibrá-la | O(log n) |
| `findMinNode)` | encontra o menor nó na árvore AVL a partir do nó fornecido | O(log n) |
| `findMaxNode()` | encontra o maior nó na árvore AVL a partir do nó fornecido | O(log n) |
| `getHeight()` | obtém a altura do nó fornecido | O(1) |
| `getBalanceFactor()` | obtém o fator de equilíbrio do nó fornecido | O(1) |
| `updateHeight()` | atualiza a altura do nó fornecido | O(1) |
| `printDiagram()` | imprime a árvore AVL em forma de diagrama | O(log n) |



#### Como compilar e executar o programa:

-> Para compilar o código:
      
      g++ main.cpp AVLTree.cpp -o program
       
-> Para executar o programa:
       
       ./program


