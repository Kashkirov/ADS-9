// Copyright 2021 NNTU-CS
#include  <iostream>
#include  <fstream>
#include  <locale>
#include  <cstdlib>
#include  "bst.h"
std::string ComposeWord(std::ifstream& in) {
    std::string out;
    do {
        char lt = in.get();
        if ((lt > 64 && lt < 91) || (lt > 96 && lt < 123)) {
            if (lt > 64 && lt < 91) {
                lt += 32;
            }
            out += lt;
        } else {
            break;
        }
    } while (1);
    return out;
}
BST<std::string> makeTree(const char* filename) {
    BST <std::string> resultTree;
    std::ifstream file(filename);
    if (!file) {
        std::cout << "Unfortuantely can't open file " << std::endl;
        return BST<std::string>();
    }
    while (!file.eof()) {
        std::string composed = ComposeWord(file);
        if (!composed.empty()) {
            resultTree.addNode(composed);
        } else {
            continue;
        }
    }
    file.close();
    return resultTree;
}
