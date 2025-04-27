#include <bits/stdc++.h>
using namespace std;

class BSTNode{
public:
    int data{};
    BSTNode* right;
    BSTNode* left;

    BSTNode(){
        this->left = nullptr;
        this->right = nullptr;
    }

    explicit BSTNode(int data){
        this->data = data;
        this->left = nullptr;
        this->right = nullptr;
    }
};

class BST {
private:
    BSTNode* root;
public:
    BST() {
        this->root = nullptr;
    }

    ~BST(){
        delete[] this->root;
    }

    void insert(const int& data){
        auto* newNode = new BSTNode(data);

        if (!this->root) {
            this->root = newNode;
            return;
        }

        BSTNode* current = this->root;

        while (true) {
            if (data < current->data) {
                if (!current->left) {
                    current->left = newNode;
                    break;
                }
                current = current->left;
            }
            else if (data > current->data) {
                if (!current->right) {
                    current->right = newNode;
                    break;
                }
                current = current->right;
            }
            else {
                delete newNode;
                break;
            }
        }
    }

    void postOrder(BSTNode* current) {
        if (current) {
            postOrder(current->left);
            postOrder(current->right);
            cout << current->data << " ";
        }
    }

    void printDFS() {
        postOrder(this->root);
    }
};

void fun() {
    auto* bst = new BST();

    bst->insert(5);
    bst->insert(3);
    bst->insert(2);
    bst->insert(8);
    bst->insert(1);

    bst->printDFS();
}

int main() {
    int t;
    t = 1;
//    cin >> t;
    while (t--) fun();
    return 0;
}