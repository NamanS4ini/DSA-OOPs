#include <iostream>

class Node{
    public:
        int data;
        Node *next;
        Node(int data) : data(data), next(NULL) {}
};

class Queue{
    private:
    Node * front;
    Node * rear;
    public:
    Queue(){
        front = NULL;
        rear = NULL;
    }
    void enqueue(int value){
        Node* newNode = new Node(value);
        if (front == NULL)
        {
            front = newNode;
            rear = newNode;
            return;
        }
        rear->next = newNode;
        rear = newNode;
    }
    int dequeue(){
        if (isEmpty())
        {
            return -1;
        }
        Node* delNode = front;
        front = front->next;
        if (front == NULL)
        {
            rear= NULL;
        }
        int value = delNode->data;
        delete(delNode);
        return value;        
    }
    bool isEmpty(){
        return front == NULL;
    }
    int peek(){
        if (isEmpty())
        {
            return -1;
        }
        
        return front->data;
    }
    void display(){
        if (isEmpty())
        {
            std::cout << "Queue is Empty";
            return;
        }
        
        Node* temp = front;
        while (temp!= NULL)
        {
            std::cout << temp->data << "    ";
            temp = temp->next;
        }
        std::cout << std::endl;
        
    }
};

int main(){
    Queue l;
    l.enqueue(6);
    l.enqueue(5);
    l.enqueue(4);
    l.enqueue(3);
    l.enqueue(2);
    l.enqueue(1);
    l.display();
    int removed = l.dequeue();
    std::cout << "removed: " << removed << "\n";
    l.display();
}