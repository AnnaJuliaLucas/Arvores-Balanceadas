#ifndef AVLTREE_H
#define AVLTREE_H
#include <vector>

using namespace std;


class AVLTree {
public:
    AVLTree(); // Construtor
    ~AVLTree(); // Destrutor
    void insert(int value);
    void remove(int value);
    void printDiagram();

private:
    // definição da estrutura Node para os nós da árvore AVL
    struct Node {
        int value;
        int height;
        Node* left;
        Node* right;
        // Construtor
        Node(int val) : value(val), height(0), left(nullptr), right(nullptr) {}
    };

    Node* root;

    // métodos de rotação para balanceamento da árvore
    Node* rotateLeft(Node* node);
    Node* rotateRight(Node* node);
    Node* rotateLeftRight(Node* node);
    Node* rotateRightLeft(Node* node);

    // outros métodos auxiliares para manipulação da árvore AVL
    Node* insertNode(Node* node, int value);
    Node* removeNode(Node* node, int value);
    Node* findMinNode(Node* node);
    Node* findMaxNode(Node* node);
    int getHeight(Node* node);
    int getBalanceFactor(Node* node);
    void updateHeight(Node* node);
    void printDiagram(Node* node, int level, bool last);
};

#endif

