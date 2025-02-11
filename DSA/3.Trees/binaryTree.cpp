#include <iostream>
#include <queue>
class Node{
    public:
    int data;
    Node* right;
    Node* left;
    Node(int data): data(data), right(NULL), left(NULL) {}
};
class BinaryTree{  
    private:
    Node* root;
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
    public:
    BinaryTree(): root(NULL){}
    void insert(int value){
        if (root == NULL)
        {
            root = new Node(value);
            return;
        }
        
        std::queue<Node*> q;
        q.push(root);
        while (!q.empty())
        {
            Node* front = q.front();
            q.pop();
            if (front->left == NULL)
            {
                front->left = new Node(value);
                return;
            }
            q.push(front->left);
            if(front->right == NULL){
                front->right = new Node(value);
                return;
            }
            q.push(front->right);
            
        }
    }
    void levelOrderTraversal(){
        if (root == NULL)
        {
            std::cout << "Tree is empty!" << "\n";
            return;
        }
        std::queue<Node*> q;
        q.push(root);
        while (!q.empty())
        {
            Node* front = q.front();
            q.pop();
            std::cout << front->data << " ";
            if (front-> left != NULL)
            {
                q.push(front->left);
            }
            if (front->right != NULL)
            {
                q.push(front->right);
            }
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

    
};
int main(){
    BinaryTree tree;
    tree.insert(5);
    tree.insert(6);
    tree.insert(7);
    tree.levelOrderTraversal();
    tree.inOrderTraversal();
    tree.preOrderTraversal();
    tree.postOrderTraversal();
}