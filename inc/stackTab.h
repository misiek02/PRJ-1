#pragma once
template <typename T>
class StackTab{

    T *tab;
    size_t capacity;
    int s_top; // s_top name beacause of function top !!!

    public:
        // CONSTRUCTORS
        // Default constructor - capacity of 10
        StackTab() { capacity= 10; tab = new T[capacity]; s_top = -1;} 
        // Parameterised Constructor
        StackTab(std::size_t initialCapacity) { capacity=initialCapacity; tab = new T[capacity]; s_top = -1;} 

        // METHODS
        void push(const T& value); // pushes an element at the top 
        bool empty(); // returns 0 if stack is empty
        T pop(); // removes an element from the top
        std::size_t size();  //  shows number of element on the stack
        const T& top(); // returns value from the top (doesn't pop it)
};

// PUSH - pushes an element at the top 
template <typename T>
void StackTab<T>::push(const T& value){
    if(s_top == capacity - 1){
        std::cout<<"Overflow\n";
        exit(1);
    }
    tab[++s_top]=value;
}

// returns 0 if stack is empty
template <typename T>
bool StackTab<T>::empty(){
    if(s_top == -1){
            std::cout<<"Stack is empty\n";
            return 0;
            
    }

 
            std::cout<<"Stack ISN'T empty\n";
            return 1;
}
 


// POP - removes an element from the top
template <typename T>
T StackTab<T>::pop(){
    if(!empty()){
        tab[s_top]=0;
        --s_top;
    }

    else
    empty();

    return T();
}

// SIZE - shows number of element on the stack
template <typename T>
std::size_t StackTab<T>::size(){
    if(s_top == -1){
       std::cout<<"Queue empty\n";
        exit(1);
    }
    std::cout<<"Number of elements :" << ++s_top << std::endl;
    return s_top;
}

// TOP - returns value from the top (doesn't pop it)
template <typename T>
const T& StackTab<T>::top() {

     if(empty()){
        empty();
    }

    T static t=tab[s_top];
    std::cout<<"Top element: "<< t <<std::endl;
    return t;

    }
