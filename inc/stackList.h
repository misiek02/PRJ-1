#pragma once
#include <iostream>

// https://www.youtube.com/watch?v=Cy7cuQUNt6Y
// https://www.geeksforgeeks.org/implement-a-stack-using-singly-linked-list/

template <typename T>
struct Node {
    T value;
    Node<T> *next;

    Node(T value, Node *next=NULL) {this->value=value; this->next=next;}
};

template <typename T>
class StackList{
        Node<T> *s_top; // s_top name beacause of function top !!!
    public:
        StackList() {s_top=NULL;} // Default constructor
        void push(const T& v); // pushes an element at the top 
        T pop(); // removes an element from the top
        bool empty(); // returns 0 if stack is empty
        const T& top(); // returns value from the top (doesn't pop it)
};

// PUSH - pushing v - value on the stack
template <typename T>
void StackList<T>::push(const T& v) {
    // next = top
    // value = v
    s_top = new Node(v,s_top);
    }

//  POP - removes and returnes an element from the top
template <typename T>
T StackList<T>::pop() {
    

    if(s_top == NULL){
        std::cout<<"Stack underflow\n";
        exit(1);
    }

    Node<T> *temp  = s_top;
    s_top=s_top->next;
    delete temp; // calling free and the destructor

return T();
   
}

//  EMPTY - returns 0 if stack is empty
template <typename T>
bool StackList<T>::empty() {
    if(s_top == NULL){
            std::cout<<"Stack is empty\n";
            return s_top == NULL;
            
    }

 
            std::cout<<"Stack ISN'T empty\n";
            return !(s_top == NULL);
            
    
 }

// TOP - returns value from the top (doesn't pop it)
template <typename T>
const T& StackList<T>::top() {

     if(s_top == NULL){
        std::cout<<"Stack underflow\n";
        exit(1);
    }

    T static t=s_top->value;
    std::cout<<"Top element: "<< t <<std::endl;
    return t;

    }


