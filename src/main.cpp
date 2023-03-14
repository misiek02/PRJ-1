#include <SFML/Graphics.hpp>
#include "stack.h"
#include "queueTab.h"
#include "list.h"
#include <iostream>

int main()
{
    QueueTab<int> y(4);
    y.enqueue(2.011);
    y.enqueue(4.99);
    y.enqueue(4.99);
    y.enqueue(4.99);
    float g = y.size();
    std::cout<<g<<std::endl;

    Linkedlist<int> list;

/*
    //Stack
    Stack<int> s;

    // Push the elements of stack
    s.push(11);
    s.push(22);
    s.push(33);
    s.push(44);

    // Display stack elements
    s.display();

    // Print top element of stack
    cout << "\nTop element is " << s.peek() << endl;

    // Delete top elements of stack
    s.pop();
    s.pop();

    // Display stack elements
    s.display();

    // Print top element of stack
    cout << "\nTop element is " << s.peek() << endl;
    */

    //List

    list.instertCell(1);
    list.instertCell(2);
    list.instertCell(3);
    list.instertCell(4);

    cout << "Elements of the list are: ";

    // Print the list
    list.printList();
    cout << endl;

    // Delete node at position 2.
    list.deleteCell(2);

    cout << "Elements of the list are: ";
    list.printList();
    cout << endl;

    return 0;
} 