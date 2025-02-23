//  Module 3
//
//  Created by Luke Contreras on 2/23/25.
//
// doublyLinkedList.cpp
#include <iostream>
using namespace std;

// Define the Node struct with pointers to both the next and previous nodes.
struct Node {
    int data;
    Node* next;
    Node* prev;
};

// Insert a node with the given value at the end of the doubly linked list.
void insertNode(Node*& head, int value) {
    Node* newNode = new Node;
    newNode->data = value;
    newNode->next = nullptr;
    newNode->prev = nullptr;
    
    if (head == nullptr) {
        head = newNode;
    } else {
        Node* current = head;
        // Traverse to the end of the list.
        while (current->next != nullptr) {
            current = current->next;
        }
        current->next = newNode;
        newNode->prev = current;
    }
}

// Delete the first node that contains the specified value.
void deleteNode(Node*& head, int value) {
    if (head == nullptr)
        return;
    
    Node* current = head;
    // Traverse to find the node with the matching value.
    while (current != nullptr && current->data != value) {
        current = current->next;
    }
    
    if (current == nullptr)
        return; // Value not found.
    
    // If the node to delete is the head.
    if (current == head) {
        head = current->next;
        if (head != nullptr)
            head->prev = nullptr;
    } else {
        // Adjust the previous node's next pointer.
        if (current->prev != nullptr)
            current->prev->next = current->next;
        // Adjust the next node's previous pointer.
        if (current->next != nullptr)
            current->next->prev = current->prev;
    }
    
    delete current;
}

// Display the list from head to tail.
void displayListForward(Node* head) {
    Node* current = head;
    cout << "Forward: ";
    while (current != nullptr) {
        cout << current->data << " <-> ";
        current = current->next;
    }
    cout << "NULL" << endl;
}

// Display the list from tail to head.
void displayListBackward(Node* head) {
    if (head == nullptr)
        return;
    
    // Move to the tail of the list.
    Node* current = head;
    while (current->next != nullptr) {
        current = current->next;
    }
    
    cout << "Backward: ";
    while (current != nullptr) {
        cout << current->data << " <-> ";
        current = current->prev;
    }
    cout << "NULL" << endl;
}

int main() {
    Node* head = nullptr;
    
    // Insert nodes into the doubly linked list.
    insertNode(head, 5);
    insertNode(head, 15);
    insertNode(head, 25);
    insertNode(head, 35);
    
    cout << "Doubly Linked List after insertion:" << endl;
    displayListForward(head);
    displayListBackward(head);
    
    // Delete a node by value.
    cout << "\nDeleting node with value 25..." << endl;
    deleteNode(head, 25);
    
    cout << "Doubly Linked List after deletion:" << endl;
    displayListForward(head);
    displayListBackward(head);
    
    // Clean up memory: delete remaining nodes.
    while (head != nullptr) {
        Node* temp = head;
        head = head->next;
        delete temp;
    }
    
    return 0;
}
