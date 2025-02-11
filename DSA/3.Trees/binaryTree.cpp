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
};
int main(){

}