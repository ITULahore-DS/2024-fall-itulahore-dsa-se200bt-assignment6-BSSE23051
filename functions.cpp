//
// Created by hh on 28/09/2024.
//
#include "functions.h"
#include "iostream"
#include "stack"
#include "queue"
using namespace std;
// ____________________________________//

// Constructor
Node::Node() { next= nullptr; }

// Destructor
Node::~Node() {}

// Sets next pointer to provided node
void Node::setNext(Node *val) {

    // The node has been created
    // So no need to create a new node like Node* temp = new node;
    // The val is the temp

    // Sets the next pointer to the provided node val

    next=val;

}

// Return the next node pointer
Node *Node::getNext() { return next; }

// Sets data of node
void Node::setData(int data) { this->data=data; }

// Returns data of node
int Node::getData() { return data; }

// ____________________________________//

// Data Members:

//  Node* top: Pointer to the top node of the stack.
//  int count: The number of elements in the stack.

//  Member Functions to Implement:

//  Constructor: Initializes the stack with top set to nullptr and count to 0.
//  Destructor: Ensures all nodes are properly deleted when the stack is destroyed.
//  bool isEmpty(): Returns true if the stack is empty; otherwise, false.
//  void push(int data): Adds a new node with the given data to the top of the stack.
//  void pop(): Removes and returns the data from the top node of the stack. If the stack is empty,
//handle the error appropriately (e.g., throw an exception or return a sentinel value).
//  int peek(): Returns the data from the top node without removing it. If the stack is empty, handle
//the error appropriately.
//  int size(): Returns the number of elements in the stack.
//  void clear(): Removes all elements from the stack.
// void printStack(): Prints all the elements in the stack from top to bottom

Stack::Stack() {

    top= nullptr;
    count=0;

}

Stack::~Stack()  {
    clear();
}

int Stack::size() {
    return count;
}

bool Stack::isEmpty() {

    if(count==0  || top== nullptr){
        return true;
        // return true is stack is empty
    }
    else
    {
        return false;
        // return false if it's not empty

    }

}


void Stack::push(int data) {

    // add a new node to stack
    Node* newNode = new Node(data);

    newNode->setNext(top);

    top = newNode;
    // update - top pointer

    count++;
    // increment

    cout<<"Data inserted into the stack! \n";

}

void Stack::pop() {

    if(isEmpty()){
        cerr<<"Stack is empty! \n";
        return;
    }

    Node* temp = top;
    top = top->getNext();

    // Move the top to the next node
    delete temp;

    // deletes the "old" top node
    count--;

}

int Stack::peek() {

    if(isEmpty()){
        cerr<<"Empty Stack!"<<endl;
        return  -1;
    }

    // returns top's value
    return top->getData();
}


void Stack::clear() {

    // deletes all elements in the stack
    // utilizes pop functionality

    while (!isEmpty()) {
        pop();
    }

}

void Stack::printStack() {

    // set a current node to stack's top value
    Node* currentNode = top;


    // iterate through while loop
    while (currentNode != nullptr) {

        // retrieve data
        cout << currentNode->getData() << endl;
        // move to next node

        currentNode = currentNode->getNext();
    }

}

// ------------------------------------//



//  bool isEmpty(): Returns true if the queue is empty; otherwise, false.
//  void enqueue(int data): Adds a new node with the given data to end of queue
//  void dequeue(): Removes element from first (starting)
//  int size(): Returns the number of elements in the queue.
//  void printQueue(): Prints all the elements in the queue


Queue::Queue() {
    top= nullptr;
    count=0;
}

Queue::~Queue() {

    while ((!isEmpty())){
        dequeue();
    }

}

void Queue::clear() {

    while ((!isEmpty())){
        dequeue();
    }

}

bool Queue::isEmpty() {

    if(count==0 || top== nullptr){
        return true;
    }
    else{
        return false;
    }

}

int Queue::size() {

    return count;

}


int Queue::peek() {

    // if queue is empty
    if(isEmpty()){
        cerr<<"Empty Queue!"<<endl;
        return  -1;
    }

    // returns top's value
    return top->getData();

}

void Queue::enqueue(int data) {

    // ADDING ELEMENT TO END

    // create a new node to add to queue
    Node* newNode = new Node(data);

    // If the queue is empty, set both top and rear to the new node
    if (isEmpty()) {

        // 1st element = set both top and rear to the new node
        top = rear = newNode;

    } else {
        // set its position to read end
        rear->setNext(newNode);
        rear=newNode;
    }

    // increment
    count++;

    cout<<"Data inserted into the queue! \n";

}

void Queue::dequeue() {

    // REMOVING ELEMENT FROM START!

    if(isEmpty()){
        cerr<<"Stack is empty! \n";
        return;
    }

    // set node position to the starting
    Node* temp = top;
    top = top->getNext();

    // deletes the "old" top node
    delete temp;
    count--;

}

void Queue::printQueue() {

    Node* currentNode = top;
    while (currentNode != nullptr) {

        // prints current node's data
        cout<<currentNode->getData()<<endl;

        // goes to next node in queue
        currentNode = currentNode->getNext();
    }

}