#include "AVLTree.h"
#include <iostream>

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

    // impressões an árvore em ordem
    std::cout << "Árvore AVL em ordem: ";
    tree.printInOrder();
    std::cout << std::endl;

    std::cout << "Diagrama da árvore AVL: " << std::endl << std::endl;
    tree.printDiagram();


    // remove alguns valores da árvore
    tree.remove(20);
    tree.remove(30);
    tree.remove(70);

    // imprime a árvore em ordem novamente
    std::cout << "Árvore AVL em ordem após remoção de valores: ";
    tree.printInOrder();
    std::cout << std::endl;

    std::cout << "Diagrama da árvore AVL tree após a remoção de valores: " << std::endl;
    tree.printDiagram();

    return 0;
};
