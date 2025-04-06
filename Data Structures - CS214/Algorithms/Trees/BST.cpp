#include <iostream>
#include <queue>
#include <stack>
using namespace std;

template <typename T>
class BSTNode {
public:
    T data;
    BSTNode* left;
    BSTNode* right;

    BSTNode(const T& value) : data(value), left(nullptr), right(nullptr) {}
};

template <typename T>
class BST {
private:
    BSTNode<T>* root;

    void insert(BSTNode<T>*& node, const T& value) {
        if (!node) {
            node = new BSTNode<T>(value);
        } else if (value < node->data) {
            insert(node->left, value);
        } else {
            insert(node->right, value);
        }
    }

    void clear(BSTNode<T>*& node) {
        if (node) {
            clear(node->left);
            clear(node->right);
            delete node;
            node = nullptr;
        }
    }

    BSTNode<T>* search(BSTNode<T>* node, const T& key) const {
        if (!node || node->data == key) return node;
        return key < node->data ? search(node->left, key) : search(node->right, key);
    }

    void inorder(BSTNode<T>* node) const {
        if (node) {
            inorder(node->left);
            cout << node->data << " ";
            inorder(node->right);
        }
    }

    void preorder(BSTNode<T>* node) const {
        if (node) {
            cout << node->data << " ";
            preorder(node->left);
            preorder(node->right);
        }
    }

    void postorder(BSTNode<T>* node) const {
        if (node) {
            postorder(node->left);
            postorder(node->right);
            cout << node->data << " ";
        }
    }

    // Delete by Copying
    void deleteByCopying(BSTNode<T>*& node, const T& value) {
        if (!node) return;

        if (value < node->data) {
            deleteByCopying(node->left, value);
        } else if (value > node->data) {
            deleteByCopying(node->right, value);
        } else { // Node found
            if (!node->left && !node->right) {
                delete node;
                node = nullptr;
            } else if (!node->left) {
                BSTNode<T>* toDelete = node;
                node = node->right;
                delete toDelete;
            } else if (!node->right) {
                BSTNode<T>* toDelete = node;
                node = node->left;
                delete toDelete;
            } else {
                // Find rightmost in left subtree (inorder predecessor)
                BSTNode<T>* parentOfPred = node;
                BSTNode<T>* pred = node->left;
                while (pred->right) {
                    parentOfPred = pred;
                    pred = pred->right;
                }
                node->data = pred->data; // Copy predecessor data to current node

                if (parentOfPred == node)
                    parentOfPred->left = pred->left;
                else
                    parentOfPred->right = pred->left;

                delete pred;
            }
        }
    }

public:
    BST() : root(nullptr) {}
    ~BST() { clear(); }

    void insert(const T& value) {
        insert(root, value);
    }

    void deleteByCopying(const T& value) {
        deleteByCopying(root, value);
    }

    bool isEmpty() const {
        return root == nullptr;
    }

    void clear() {
        clear(root);
    }

    BSTNode<T>* getLeft() const {
        return root ? root->left : nullptr;
    }

    BSTNode<T>* getRight() const {
        return root ? root->right : nullptr;
    }

    BSTNode<T>* getRoot() const {
        return root;
    }

    BSTNode<T>* search(const T& key) const {
        return search(root, key);
    }

    // Traversals
    void printInOrder() const {
        cout << "In-order Traversal (LVR): ";
        inorder(root);
        cout << endl;
    }

    void printPreOrder() const {
        cout << "Pre-order Traversal (VLR): ";
        preorder(root);
        cout << endl;
    }

    void printPostOrder() const {
        cout << "Post-order Traversal (LRV): ";
        postorder(root);
        cout << endl;
    }

    void breadthFirstTraversal() const {
        if (!root) {
            cout << "Breadth-First Traversal: Tree is empty.\n";
            return;
        }

        queue<BSTNode<T>*> q;
        q.push(root);

        cout << "Breadth-First Traversal: ";
        while (!q.empty()) {
            BSTNode<T>* current = q.front();
            q.pop();
            cout << current->data << " ";

            if (current->left) q.push(current->left);
            if (current->right) q.push(current->right);
        }

        cout << endl;
    }

    void depthFirstTraversal() const {
        if (!root) {
            cout << "Depth-First Traversal (Pre-order using stack): Tree is empty.\n";
            return;
        }

        stack<BSTNode<T>*> s;
        s.push(root);

        cout << "Depth-First Traversal (VLR using Stack): ";
        while (!s.empty()) {
            BSTNode<T>* current = s.top();
            s.pop();
            cout << current->data << " ";

            if (current->right) s.push(current->right);
            if (current->left) s.push(current->left);
        }

        cout << endl;
    }
};
