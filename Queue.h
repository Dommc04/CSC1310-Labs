// Name Dominic McElroy
// Date 10/23/2023
// Purpose - The line eradicator ( can remove or add people in line for the senario of riding rides in this case.)

#ifndef QUEUE_H
#define QUEUE_H

#include <iostream>
#include <iomanip>
using namespace std;

class Queue {
    private:
    // hidden structure of the node 
    struct QueueNode {
        string riderName;
        struct QueueNode *next;
    };
    int numNodes;
    QueueNode *head, *tail;

public:

// the constructor !!!!

Queue() {
    head = NULL;
    tail = NULL;
    numNodes = 0;
}

// now for if/when its empty

bool isEmpty(){
    return head == NULL;
}


// Enqueue

// Adds rider name from txt file given

void enqueue(string riderName){
    QueueNode *new_QueueNode = new QueueNode;
    new_QueueNode->riderName = riderName;
    new_QueueNode->next = NULL;


// checking if it empty!


if (head == NULL){
    head = tail = new_QueueNode;
}
else {
    tail->next = new_QueueNode;
    tail = new_QueueNode;
}
numNodes++;

}

// dequeue - gets rid of rider

string dequeue(){
    if(isEmpty()){
        cout << "Empty Queue!" << endl;
        return "";
    }
    else {
        string riderName = head->riderName;
        QueueNode *tmp = head;
        delete tmp;
        return riderName;
    }
    numNodes--;
}

~Queue (){
    string name = "";
    if(!isEmpty()){
        name = head->riderName;
        cout << "Oh shoot, I am sorry, Our park is closed so ["<< name << "] will not get to ride today.\n";
    }    
}
};

#endif