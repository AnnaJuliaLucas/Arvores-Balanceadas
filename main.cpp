#include "AVLTree.h"
#include <iostream>
using namespace std;

int main() {
    AVLTree tree;

    // insere alguns valores na árvore
    tree.insert(10);
    tree.insert(20);
    tree.insert(30);
    tree.insert(40);
    tree.insert(50);
    tree.insert(60);
    tree.insert(70);
    tree.insert(80);

    // impressão 
    std::cout << "Diagrama da árvore AVL: " << std::endl << std::endl;
    tree.printDiagram();
    std::cout << std::endl;


    // remove alguns valores da árvore
    tree.remove(20);
    tree.remove(30);
    tree.remove(70);

    // imprime o diagrama da árvore AVL após a remoção de valores
    std::cout << "Diagrama da árvore AVL  após a remoção de valores: " << std::endl << std::endl;
    tree.printDiagram();
 

    return 0;
};
