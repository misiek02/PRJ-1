//
// Created by ADMIN on 14.03.2023.
//
//https://www.geeksforgeeks.org/program-to-implement-singly-linked-list-in-c-using-class/

#ifndef PRJ_1_LIST_H
#define PRJ_1_LIST_H
// C++ program for the above approach
#include <iostream>
using namespace std;

// Node class to represent
// a node of the linked list.
template <typename T>
class Cell {
public:
    T data;
    Cell* next;

    // Default constructor
    Cell()
    {
        data = T();
        next = NULL;
    }

    // Parameterised Constructor
    Cell(T data)
    {
        this->data = data;
        this->next = NULL;
    }
};

// Linked list class to
// implement a linked list.
template <typename T>
class Linkedlist {
    Cell<T> *head;

public:
    // Default constructor
    Linkedlist() { head = NULL; }

    // Function to insert a
    // node at the end of the
    // linked list.
    void instertCell(T);

    // Function to print the
    // linked list.
    void printList();

    // Function to delete the
    // node at given position
    void deleteCell(T);
};

// Function to delete the
// node at given position
template <typename T>
void Linkedlist<T>::deleteCell(T CellOffset)
{
    Cell<T> *temp1 = head, *temp2 = NULL;
    T ListLen = 0;

    if (head == NULL) {
        cout << "List empty." << endl;
        return;
    }

    // Find length of the linked-list.
    while (temp1 != NULL) {
        temp1 = temp1->next;
        ListLen++;
    }

    // Check if the position to be
    // deleted is greater than the length
    // of the linked list.
    if (ListLen < CellOffset) {
        cout << "Index out of range"
             << endl;
        return;
    }

    // Declare temp1
    temp1 = head;

    // Deleting the head.
    if (CellOffset == 1) {

        // Update head
        head = head->next;
        delete temp1;
        return;
    }

    // Traverse the list to
    // find the node to be deleted.
    while (CellOffset-- > 1) {

        // Update temp2
        temp2 = temp1;

        // Update temp1
        temp1 = temp1->next;
    }

    // Change the next pointer
    // of the previous node.
    temp2->next = temp1->next;

    // Delete the node
    delete temp1;
}

// Function to insert a new node.
template <typename T>
void Linkedlist<T>::instertCell(T data)
{
    // Create the new Node.
    Cell<T>* newCell = new Cell<T>(data);

    // Assign to head
    if (head == NULL) {
        head = newCell;
        return;
    }

    // Traverse till end of list
    Cell<T>* temp = head;
    while (temp->next != NULL) {

        // Update temp
        temp = temp->next;
    }

    // Insert at the last.
    temp->next = newCell;
}

// Function to print the
// nodes of the linked list.
template <typename T>
void Linkedlist<T>::printList()
{
    Cell<T>* temp = head;

    // Check for empty list.
    if (head == NULL) {
        cout << "List empty" << endl;
        return;
    }

    // Traverse the list.
    while (temp != NULL) {
        cout << temp->data << " ";
        temp = temp->next;
    }
}


#endif //PRJ_1_LIST_H
