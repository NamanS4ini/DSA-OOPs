#include <iostream>

class Node
{
public:
    int data;
    Node *left;
    Node *right;
    Node(int data) : data(data), left(NULL), right(NULL) {}
};

class BinarySearchTree
{
private:
    Node *root;
    Node *findParent(Node *temp, int key)
    {
        if (temp == NULL)
        {
            return NULL;
        }

        if ((temp->left == NULL && key < temp->data) || (temp->right == NULL && key > temp->data))
        {
            return temp;
        }

        if (key < temp->data)
        {
            temp = findParent(temp->left, key);
        }

        else if (key > temp->data)
        {
            temp = findParent(temp->right, key);
        }

        return temp;
    }

public:
    BinarySearchTree() : root(NULL) {}

    void insert(int value)
    {
        if (root == NULL)
        {
            root = new Node(value);
            return;
        }
        Node *parent = findParent(root, value);
        if (value < parent->data)
        {
            parent->left = new Node(value);
        }
        else
        {
            parent->right = new Node(value);
        }
        
    }
};

int main()
{
}