#include <iostream>

// Node class for linkedlist
class Node
{
public:
    int data;
    Node *next;
    // constructor to initialize data and next node for Linked List
    Node(int data) : data(data), next(NULL) {}
};

class LinkedList
{
private:
    Node *head;

public:
    // Initialise an empty linked List
    LinkedList() : head(NULL) {}

    // Insers a node
    void insert(int data)
    {
        Node *newNode = new Node(data);
        newNode->next = head;
        head = newNode;
    }

    // displays all the node
    void display()
    {
        if (head == NULL)
        {
            std::cout << "Empty List";
            return;
        }

        Node *temp = head;
        std::cout << "list: ";
        while (temp != NULL)
        {
            std::cout << temp->data << " -> ";
            temp = temp->next;
        }
        std::cout << "NULL" << "\n";
    }

    // remove th node at ndex
    void remove(int index)
    {
        // returns if linkedlist is empty
        if (head == NULL)
        {
            std::cout << "List is Empty!";
            return;
        }

        Node *temp = head;
        // Deleted the Head node if index is 0
        if (index == 0)
        {
            head = head->next;
            delete (temp);
            return;
        }

        // Traverse to the index node or to the last node if index is out of bound
        for (int i = 0; temp != NULL && i < index - 1; i++)
        {
            temp = temp->next;
        }
        // Returns if index is out of bound
        if (temp == NULL || temp->next == NULL)
        {
            std::cout << "Out of Bound" << "\n";
            return;
        }
        // Deletes the node by making the parent nodes Next equal to the Node's (to be deleted) next then freeing the memory
        Node *delNode = temp->next;
        temp->next = delNode->next;
        delete (delNode);
    }
};

int main()
{
    LinkedList l;
    l.insert(6);
    l.insert(5);
    l.insert(4);
    l.insert(3);
    l.insert(2);
    l.insert(1);
    l.display();
    l.remove(5);
    l.display();
}