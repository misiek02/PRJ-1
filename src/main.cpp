#include <SFML/Graphics.hpp>
#include "stackList.h"
#include "stackTab.h"
#include "queueTab.h"
#include "list.h"
#include "Array.h"
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


    //Stack
    StackTab<int> s;

    // Push the elements of stack
    s.push(11);
    s.push(22);
    s.push(33);
    s.push(44);
/*
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
    list.instertCell(6);

    cout << "Elements of the list are: ";

    // Print the list
    list.printList();
    cout << endl;

    // Delete node at position 2.
    list.deleteCell(2);

    cout << "Elements of the list are: ";
    list.printList();
    cout << endl;

    //Stack
    StackList<int> ss;
    ss.push(2);
    ss.top();


    Array<int> arr(5);

    arr.add(1);
    arr.add(2);
    arr.add(3);


    //Tab

    std::cout << arr[0] << std::endl; // prints "1"
    std::cout << arr[1] << std::endl; // prints "2"
    std::cout << arr[2] << std::endl; // prints "3"

    arr.remove(1);

    std::cout << arr[0] << std::endl; // prints "1"
    std::cout << arr[1] << std::endl; // prints "3"

    std::cout << arr.find(1) << std::endl; // prints "0"
    std::cout << arr.find(2) << std::endl; // prints "-1"
    return 0;
} 