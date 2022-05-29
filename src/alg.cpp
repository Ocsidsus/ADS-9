// Copyright 2021 NNTU-CS
#include  <iostream>
#include  <fstream>
#include  <locale>
#include  <cstdlib>
#include  "bst.h"

BST<std::string> makeTree(const char* filename) {
    std::ifstream file(filename);
    BST<std::string> tree;
    if (!file) {
        std::cout << "File error!" << std::endl;
        return tree;
    }
    std::string cache = "";
    while (!file.eof())
    {
        int ch = file.get();
        if (ch >= 'a' && ch <= 'z') {
            cache += char(ch);
        } else if (ch >= 'A' && ch <= 'Z') {
            cache += char(ch + ('a' - 'A'));
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
