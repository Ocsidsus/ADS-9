// Copyright 2021 NNTU-CS
#include  <iostream>
#include  <fstream>
#include  <locale>
#include  <cstdlib>
#include  "bst.h"

BST<std::string> makeTree(const char* filename) {
    BST<std::string> tree;
    std::ifstream file(filename);
    if (!file) {
        std::cout << "File error!" << std::endl;
        return tree;
    }
    std::string cache = "";
    while (!file.eof()) {
        int ch = file.get();
        if (static_cast<char>(ch) >= 'a' && static_cast<char>(ch) <= 'z') {
            cache += char(ch);
        } else if (static_cast<char>(ch) >= 'A' && static_cast<char>(ch) <= 'Z') {
            cache += static_cast<char>(ch + ('a' - 'A'));
        } else {
            if (cache != "") {
                tree.add(cache);
            }
            cache.clear();
        }
    }
    if (cache != "") {
        tree.add(cache);
    }
    file.close();
    return tree;
}
