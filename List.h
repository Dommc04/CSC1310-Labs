#ifndef LIST_H
#define LIST_H

#include <iostream>
using namespace std;

struct ListNode {
    string data; // stores da data
    ListNode* next; // looks at the next node of the list

    // Constructorinator 
    ListNode(const string& value) : data(value), next(nullptr) {};

};

class List {
    private:
    ListNode* head; // pointer to first node in list
    ListNode* tail; // final node in the list

    public:
    // Constructinator V2
    List() : head(nullptr), tail(nullptr) {}

    // Destructinator
    ~List(){
        while (head != nullptr) {
            ListNode* temp = head;
            head=head->next;
            delete[] temp;

        }
    }

    void appendNode(const string& value); 
    void insertNode(const string& value);
    void deleteNode(const string& value);
    void displayList();
};

void List::appendNode(const string& value) {
    ListNode* newNode = new ListNode(value);
    if (tail == nullptr) {
        // if list empty sets the head and tail to new node
        head = newNode;
        tail = newNode;
    }
    else {
        // append node to end , update tail
        tail->next = newNode;
        tail = newNode;
    }
}

//alphabetically insert new node 

void List::insertNode(const string& value) {
    ListNode* newNode = new ListNode (value);
    if (head == nullptr || value < head->data) {
        newNode->next = head;
        head = newNode;
    }
    else {
        ListNode* prev = nullptr;
        ListNode* current = head;
        while (current != nullptr && value >= current->data) {
            prev = current;
            current = current->next;
        }
        //Insert New node between a current or previous node
        prev->next = newNode;
        newNode->next = current;
    }
}

//Delete a node list
void List::deleteNode(const string& value) {
    if(head == nullptr) {
        // if list is empty it won't delete anything
        return;
    }
    if(head->data == value) {
        //value to delete is the head
        ListNode* temp = head;
        head = head->next;
        delete temp;
        if (head == nullptr) {
            // if empty list updates tail
            tail = nullptr;
        }
        return;
    }
    ListNode* prev = nullptr;
    ListNode* current = head;
    while (current != nullptr && current->data != value) {
        prev = current;
        current = current->next;
    }
    if (current != nullptr) {
        // if value found update the new pointer
        prev->next = current->next;

    if (current == tail) {
        // deleted node was tail , update tail
        tail = prev;
    }
    delete current;
        
    }
}

//display values in all nodes

void List::displayList () {
    ListNode* current = head;
    while (current != nullptr) {
        cout << current->data << endl;
        current = current->next;
    }
}

#endif  