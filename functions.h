//
// Created by hh on 28/09/2024.
//

#ifndef INC_2024_FALL_ITULAHORE_DSA_SE200BT_ASSIGNMENT6_BSSE23051_FUNCTIONS_H
#define INC_2024_FALL_ITULAHORE_DSA_SE200BT_ASSIGNMENT6_BSSE23051_FUNCTIONS_H


class Node{

    int data;
    Node* next;

public:

    Node();
    ~Node();
    void setNext(Node* val);
    Node* getNext();
    void setData(int data);
    int getData();

    // Parameterised constructor
    Node(int data) : data(data), next(nullptr) {}

};

// ----------------------------//

class Stack{

    Node* top;
    int count;

public:

    Stack();
    ~Stack();

    int size();
    bool isEmpty();
    int peek();
    void push(int data);
    void pop();
    void clear();
    void printStack();


};

// ------------------------------//

class Queue{

    Node* top;
    Node* rear;
    int count;

public:

    // Member functions

    Queue();
    ~Queue();
    bool isEmpty();
    void clear();
    int peek();
    void enqueue(int data);
    void dequeue();
    int size();
    void printQueue();


};

// --------------------------//


#endif //INC_2024_FALL_ITULAHORE_DSA_SE200BT_ASSIGNMENT6_BSSE23051_FUNCTIONS_H
