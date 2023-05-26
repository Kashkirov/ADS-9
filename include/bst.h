// Copyright 2021 NNTU-CS
#ifndef INCLUDE_BST_H_
#define INCLUDE_BST_H_
#include <algorithm>
template <typename T>
class BST {
private:
    struct Node {
        T info;
        int sum;
        Node* left, * right;
        Node() :left(nullptr), right(nullptr) {}
    };
    Node* m_root = nullptr;
    int gatherNodeAmount(Node* localRoot) {
        if (!localRoot) {
            return 0;
        }
        return 1 + std::max(gatherNodeAmount(localRoot->left), gatherNodeAmount(localRoot->right));
    }
    void addNode(Node* localRoot, T& word) {
        if (word < localRoot->info) {
            if (localRoot->left) {
                addNode(localRoot->left, word);
                return;
            }
            else {
                localRoot->left = new Node;
                localRoot->left->info = word;
                localRoot->left->sum = 1;
                return;
            }
        }
        if (word > localRoot->info) {
            if (localRoot->right) {
                addNode(localRoot->right, word);
                return;
            }
            else {
                localRoot->right = new Node;
                localRoot->right->info = word;
                localRoot->right->sum = 1;
                return;
            }
        }
        localRoot->sum += 1;
        return;
    }
    int Compare(Node* localRoot, T word) {
        if (word > localRoot->info) {
            return Compare(localRoot->right, word);
        }
        if (word < localRoot->info) {
            return Compare(localRoot->left, word);
        }
        else if (word == localRoot->info) {
            return localRoot->sum;
        }
        else {
            return 0;
        }
    }

public:
    void addNode(T& word) {
        if (m_root == nullptr) {
            m_root = new Node;
            m_root->info = word;
            m_root->sum = 1;
        }
        else {
            addNode(m_root, word);
        }
    }
    int depth() {
        return gatherNodeAmount(m_root) - 1;
    }
    int search(const T& word) {
        if (!m_root) {
            return 0;
        }
        return Compare(m_root, word);
    }
};
#endif  // INCLUDE_BST_H_
