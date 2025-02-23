//  Module 3
//
//  Created by Luke Contreras on 2/23/25.
//
// linkedList.cpp
#include <iostream>
using namespace std;

// Define the Node struct with an integer data field and a pointer to the next node.
struct Node {
    int data;
    Node* next;
};

// Insert a node with the given value at the end of the list.
void insertNode(Node*& head, int value) {
    Node* newNode = new Node;
    newNode->data = value;
    newNode->next = nullptr;

    if (head == nullptr) {
        head = newNode;
    } else {
        Node* current = head;
        while (current->next != nullptr) {
            current = current->next;
        }
        current->next = newNode;
    }
}

// Delete the first node that contains the specified value.
void deleteNode(Node*& head, int value) {
    if (head == nullptr) {
        return;
    }
    
    // If the head node holds the value.
    if (head->data == value) {
        Node* temp = head;
        head = head->next;
        delete temp;
        return;
    }
    
    Node* current = head;
    while (current->next != nullptr && current->next->data != value) {
        current = current->next;
    }
    
    // If found, remove the node from the list.
    if (current->next != nullptr) {
        Node* temp = current->next;
        current->next = current->next->next;
        delete temp;
    }
}

// Display all nodes in the list.
void displayList(Node* head) {
    Node* current = head;
    while (current != nullptr) {
        cout << current->data << " -> ";
        current = current->next;
    }
    cout << "NULL" << endl;
}

int main() {
    Node* head = nullptr; // Start with an empty list.

    // Insert nodes into the linked list.
    insertNode(head, 10);
    insertNode(head, 20);
    insertNode(head, 30);
    insertNode(head, 40);

    cout << "Linked List after insertion:" << endl;
    displayList(head);

    // Delete a node by value.
    cout << "\nDeleting node with value 20..." << endl;
    deleteNode(head, 20);
    cout << "Linked List after deletion:" << endl;
    displayList(head);

    // Insert another node to demonstrate further usage.
    cout << "\nInserting node with value 50..." << endl;
    insertNode(head, 50);
    cout << "Linked List after further insertion:" << endl;
    displayList(head);

    // Clean up memory: delete remaining nodes.
    while (head != nullptr) {
        Node* temp = head;
        head = head->next;
        delete temp;
    }

    return 0;
}

