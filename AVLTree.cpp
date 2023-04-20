#include "AVLTree.h"
#include <iostream>
#include <vector>

AVLTree::AVLTree() {
    root = nullptr;
}

AVLTree::~AVLTree() {
    
}

void AVLTree::insert(int value) {
    root = insertNode(root, value);
}

void AVLTree::remove(int value) {
    root = removeNode(root, value);
}

void AVLTree::printInOrder() {
    printInOrder(root);
}

AVLTree::Node* AVLTree::rotateLeft(Node* node) {
    Node* newRoot = node->right;
    node->right = newRoot->left;
    newRoot->left = node;
    updateHeight(node);
    updateHeight(newRoot);
    return newRoot;
}

AVLTree::Node* AVLTree::rotateRight(Node* node) {
    Node* newRoot = node->left;
    node->left = newRoot->right;
    newRoot->right = node;
    updateHeight(node);
    updateHeight(newRoot);
    return newRoot;
}

AVLTree::Node* AVLTree::rotateLeftRight(Node* node) {
    node->left = rotateLeft(node->left);
    return rotateRight(node);
}

AVLTree::Node* AVLTree::rotateRightLeft(Node* node) {
    node->right = rotateRight(node->right);
    return rotateLeft(node);
}

AVLTree::Node* AVLTree::insertNode(Node* node, int value) {
         if (node == nullptr) {
        node = new Node(value);
        node->value = value;
        node->left = nullptr;
        node->right = nullptr;
        node->height = 0;
    }
    
    else if (value < node->value) {
        node->left = insertNode(node->left, value);
        if (getBalanceFactor(node) == 2) {
            if (getBalanceFactor(node->left) == 1) {
                node = rotateRight(node);
            }
            else {
                node = rotateLeftRight(node);
            }
        }
    }
    else if (value > node->value) {
        node->right = insertNode(node->right, value);
        if (getBalanceFactor(node) == -2) {
            if (getBalanceFactor(node->right) == -1) {
                node = rotateLeft(node);
            }
            else {
                node = rotateRightLeft(node);
            }
        }
    }
    updateHeight(node);
    return node;
}

AVLTree::Node* AVLTree::removeNode(Node* node, int value) {
    if (node == nullptr) {
        return nullptr;
    }
    if (value < node->value) {
        node->left = removeNode(node->left, value);
    }
    else if (value > node->value) {
        node->right = removeNode(node->right, value);
    }
    else {
        if (node->left == nullptr && node->right == nullptr) {
            delete node;
            return nullptr;
        }
        else if (node->left == nullptr) {
            Node* temp = node->right;
            delete node;
            return temp;
        }
        else if (node->right == nullptr) {
            Node* temp = node->left;
            delete node;
            return temp;
        }
        else {
            Node* minNode = findMinNode(node->right);
            node->value = minNode->value;
            node->right = removeNode(node->right, minNode->value);
        }
    }
    if (node == nullptr) {
        return nullptr;
    }
    if (getBalanceFactor(node) == 2) {
        if (getBalanceFactor(node->left) == 1) {
            return rotateRight(node);
        }
        else {
            return rotateLeftRight(node);
        }
    }
    else if (getBalanceFactor(node) == -2) {
        if (getBalanceFactor(node->right) == -1) {
            return rotateLeft(node);
        }
        else {
            return rotateRightLeft(node);
        }
    }
    updateHeight(node);
    return node;
}

AVLTree::Node* AVLTree::findMinNode(Node* node) {
    while (node->left != nullptr) {
        node = node->left;
    }
    return node;
}

AVLTree::Node* AVLTree::findMaxNode(Node* node) {
    while (node->right != nullptr) {
        node = node->right;
    }
    return node;
}

int AVLTree::getHeight(Node* node) {
    if (node == nullptr) {
        return -1;
    }
    return node->height;
}

int AVLTree::getBalanceFactor(Node* node) {
    return getHeight(node->left) - getHeight(node->right);
}

void AVLTree::updateHeight(Node* node) {
    node->height = 1 + std::max(getHeight(node->left), getHeight(node->right));
}

void AVLTree::printInOrder(Node* node) {
    if (node == nullptr) {
        return;
    }
    printInOrder(node->left);
    std::cout << node->value << " ";
    printInOrder(node->right);
}

void AVLTree::printDiagram() {
    if (root == nullptr) {
        std::cout << "Empty tree\n";
        return;
    }
    std::vector<bool> lastChildren;
    printDiagram(root, 0, lastChildren);
}

void AVLTree::printDiagram(Node* node, int level, std::vector<bool>& lastChildren) {
    if (node == nullptr) {
        return;
    }
    lastChildren.push_back(false);
    printDiagram(node->right, level + 1, lastChildren);
    for (int i = 0; i < level; i++) {
        if (i == level - 1) {
            std::cout << (lastChildren[i] ? "└───" : "├───");
        } else {
            std::cout << (lastChildren[i] ? "    " : "│   ");
        }
    }
    std::cout << node->value << std::endl;
    lastChildren[level] = (node->right == nullptr);
    printDiagram(node->left, level + 1, lastChildren);
    lastChildren.pop_back();
}