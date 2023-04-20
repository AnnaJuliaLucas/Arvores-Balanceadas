#ifndef AVLTREE_H
#define AVLTREE_H

class AVLTree {
public:
    AVLTree();
    ~AVLTree();
    void insert(int value);
    void remove(int value);
    void printInOrder();
    void printDiagram();

private:
    struct Node {
        int value;
        int height;
        Node* left;
        Node* right;
        Node(int val) : value(val), height(0), left(nullptr), right(nullptr) {}
    };

    Node* root;

    // métodos de rotação
    Node* rotateLeft(Node* node);
    Node* rotateRight(Node* node);
    Node* rotateLeftRight(Node* node);
    Node* rotateRightLeft(Node* node);

    // outros métodos auxiliares
    Node* insertNode(Node* node, int value);
    Node* removeNode(Node* node, int value);
    Node* findMinNode(Node* node);
    Node* findMaxNode(Node* node);
    int getHeight(Node* node);
    int getBalanceFactor(Node* node);
    void updateHeight(Node* node);
    void printInOrder(Node* node);
    //void print(Node* node, int value);
    void printDiagram(Node* node, int level, std::vector<bool>& lastChildren);
};

#endif

