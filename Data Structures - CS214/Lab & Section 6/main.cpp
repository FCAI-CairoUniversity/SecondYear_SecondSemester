#include <bits/stdc++.h>
using namespace std;

template<typename T>
class AVLNode{
private:
    T data;
    AVLNode<T> *left, *right;
    int height;
public:
    AVLNode(){
        this->left = 0;
        this->right = 0;
        this->height = 1;
    }

    explicit AVLNode(T data, AVLNode<T> *left = 0, AVLNode<T> *right = 0, int height = 1){
        this->data = data;
        this->left = left;
        this->right = right;
        this->height = height;
    }

    AVLNode<T>* getLeft() const {return this->left;}
    void setLeft(AVLNode<T>* newLeft) {this->left = newLeft;}

    AVLNode<T>* getRight() const {return this->right;}
    void setRight(AVLNode<T> *newRight) {this->right = newRight;}

    T getData() const {return this->data;}
    void setData(const T& newData) {this->data = newData;}

    int getHeight() const {return this->height;}
    void setHeight(const int& newHeight) {this->height = newHeight;}
};

template<typename T>
class AVL {
private:
    AVLNode<T>* root;

    int findHeight(AVLNode<T>* current) {
        if (!current) return 0;
        return current->getHeight();
    }

    int balanceFactor(AVLNode<T>* current) {
        if (!current) return 0;
        return findHeight(current->getLeft()) - findHeight(current->getRight());
    }

    void updateHeight(AVLNode<T>* current) {
        if (current) {
            current->setHeight(1 + max(findHeight(current->getLeft()), findHeight(current->getRight())));
        }
    }

    AVLNode<T>* rotateRight(AVLNode<T>* y) {
        AVLNode<T>* leftChild = y->getLeft();
        AVLNode<T>* T2 = leftChild->getRight();

        leftChild->setRight(y);
        y->setLeft(T2);

        updateHeight(y);
        updateHeight(leftChild);

        return leftChild;
    }

    AVLNode<T>* rotateLeft(AVLNode<T>* x) {
        AVLNode<T>* rightChild = x->getRight();
        AVLNode<T>* T2 = rightChild->getLeft();

        rightChild->setLeft(x);
        x->setRight(T2);

        updateHeight(x);
        updateHeight(rightChild);

        return rightChild;
    }

    AVLNode<T>* updateBalance(AVLNode<T>* current) {
        updateHeight(current);
        int balance = balanceFactor(current);

        // Left heavy
        if (balance > 1) {
            if (balanceFactor(current->getLeft()) < 0)
                current->setLeft(rotateLeft(current->getLeft()));
            return rotateRight(current);
        }

        // Right heavy
        if (balance < -1) {
            if (balanceFactor(current->getRight()) > 0)
                current->setRight(rotateRight(current->getRight()));
            return rotateLeft(current);
        }

        return current;
    }

    AVLNode<T>* insertNode(AVLNode<T>* node, const T& data) {
        if (!node) return new AVLNode<T>(data);
        if (data < node->getData())
            node->setLeft(insertNode(node->getLeft(), data));
        else if (data > node->getData())
            node->setRight(insertNode(node->getRight(), data));
        else return node;

        return updateBalance(node);
    }

public:
    AVL(){
        this->root = nullptr;
    }

    ~AVL() {
        delete this->root;
    }

    void insert(const T& data) {
        this->root = insertNode(this->root, data);
    }

    void printBreadthFirst(){
        AVLNode<T>* current = this->root;
        queue<AVLNode<T>*> queue;

        if (current){
            queue.push(current);
            while (!queue.empty()){
                current = queue.front();
                cout << current->getData() << " ";
                queue.pop();

                if (current->getLeft())
                    queue.push(current->getLeft());
                if (current->getRight())
                    queue.push(current->getRight());
            }
            cout << endl;
        }
    }
};

int main() {
    auto avl = new AVL<int>();

    avl->insert(22);
    avl->insert(14);
    avl->insert(72);
    avl->insert(44);
    avl->insert(25);
    avl->insert(63);
    avl->insert(85);
    avl->insert(10);

    cout << "AVL Tree: ";
    avl->printBreadthFirst();

    return 0;
}