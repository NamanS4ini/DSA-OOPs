#include <iostream>

class Node{
public:
    int data;
    Node *left;
    Node *right;
    Node(int data) : data(data), left(NULL), right(NULL) {}
};

class BinarySearchTree{
    private:
    Node *root;
    Node *findParent(Node *temp, int key){
        if (temp == NULL){
            return NULL;
        }

        if ((temp->left == NULL && key < temp->data) || (temp->right == NULL && key > temp->data)){
            return temp;
        }

        if (key < temp->data){
            temp = findParent(temp->left, key);
        }

        else if (key > temp->data){
            temp = findParent(temp->right, key);
        }

        return temp;
    }
    void inOrder(Node * root){
        if (root == NULL)
        {
            return;
        }
        inOrder(root->left);
        std::cout << root->data << " ";
        inOrder(root->right);
    }
    void preOrder(Node * root){
        if (root == NULL)
        {
            return;
        }
        std::cout << root->data << " ";
        preOrder(root->left);
        preOrder(root->right);
    }
    void postOrder(Node * root){
        if (root == NULL)
        {
            return;
        }
        postOrder(root->left);
        postOrder(root->right);
        std::cout << root->data << " ";
    }
    // Complete this function
    Node* deleteByKey(Node* root, int key){

    }

public:
    BinarySearchTree() : root(NULL) {}

    void insert(int value){
        if (root == NULL){
            root = new Node(value);
            return;
        }
        Node *parent = findParent(root, value);
        if (value < parent->data){
            parent->left = new Node(value);
        }
        else{
            parent->right = new Node(value);
        }
    }
    void inOrderTraversal() {
        inOrder(root);

        std::cout << "\n";
    }
    void preOrderTraversal() {
        preOrder(root);
        std::cout << "\n";
    }
    void postOrderTraversal() {
        postOrder(root);
        std::cout << "\n";
    }
    Node* deleteNode(int key){
        return deleteByKey(root, key);
    }
};

int main(){
    BinarySearchTree tree;
    tree.insert(1);
    tree.insert(6);
    tree.insert(3);
    tree.insert(7);
    tree.insert(4);
    tree.insert(5);
    tree.insert(2);
    tree.insert(9);
    tree.insert(8);
    std::cout << "InOrder: ";
    tree.inOrderTraversal();
    std::cout << "preOrder: ";
    tree.preOrderTraversal();
    std::cout << "postOrder: ";
    tree.postOrderTraversal();
    tree.deleteNode(5);
    std::cout << "inOrder: ";
    tree.inOrderTraversal();
}