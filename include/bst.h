// Copyright 2021 NNTU-CS
#ifndef INCLUDE_BST_H_
#define INCLUDE_BST_H_

template <typename T>
class BST {
 public:
    struct Node {
        T value;
        int count;
        Node* left;
        Node* right;
    };

 private:
    Node* root;
    Node* addNode(Node* root, T value) {
        if (root == nullptr) {
            root = new Node;
            root->value = value;
            root->count = 1;
            root->left = root->right = nullptr;
        } else if (root->value.compare(value) > 0) {
            root->left = addNode(root->left, value);
        } else if (root->value.compare(value) < 0) {
            root->right = addNode(root->right, value);
        } else {
            root->count++;
        }
        return root;
    }
    int depthTree(Node* root) {
        if (root == nullptr) {
            return 0;
        } else {
            int l = depthTree(root->left);
            int r = depthTree(root->right);
            return 1 + (l >= r ? l : r);
        }
    }
    int searchNode(Node* root, T value) {
        int check = root->value.compare(value);
        if (check == 0) {
            return root->count;
        } else if (check > 0) {
            if (root->left != nullptr) {
                return searchNode(root->left, value);
            }
            return 0;
        } else {
            if (root->right != nullptr) {
                return searchNode(root->right, value);
            }
            return 0;
        }
    }
    void delTree(Node* root) {
        if (root == nullptr) {
            return;
        } else {
            delTree(root->left);
            delTree(root->right);
            delete root;
        }
    }
    Node* delNode(Node* root, T value) {
        Node* p, * v;
        if (root == nullptr) {
            return root;
        } else if (root->value.compare(value) > 0) {
            root->left = delNode(root->left, value);
        } else if (root->value.compare(value) < 0) {
            root->right = delNode(root->right, value);
        } else {
            p = root;
            if (root->right == nullptr) {
                root = root->left;
            } else if (root->left == nullptr) {
                root = root->right;
            } else {
                v = root->left;
                if (v->right) {
                    while (v->right->right)
                        v = v->right;
                    root->value = v->right->value;
                    root->count = v->right->count;
                    p = v->right;
                    v->right = v->right->left;
                } else {
                    root->value = v->value;
                    root->count = v->count;
                    p = v;
                    root->left = root->left->left;
                }
            }
            delete p;
        }
        return root;
    }

 public:
    BST() : root(nullptr) {}
    void add(T value) {
        root = addNode(root, value);
    }
    int depth() {
        if (root) {
            return depthTree(root) - 1;
        }
        return 0;
    }
    int search(T value) {
        return searchNode(root, value);
    }
    void clear() {
        if (root) {
            delTree(root);
            root = nullptr;
        }
    }
    void remove(T value) {
        if (root)
            root = delNode(root, value);
    }
};

#endif  // INCLUDE_BST_H_
