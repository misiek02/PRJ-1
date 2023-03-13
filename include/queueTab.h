#pragma once

template <typename T>
class QueueTab{

    T *tab;
    size_t capacity;
    int q_front;

    public:
        QueueTab() { capacity= 10; tab = new T[capacity]; q_front = -1;} // CONSTRUCTOR without - basic values with no parameters
        QueueTab(std::size_t initialCapacity); // CONSTRUCTOR with parameters
        void enqueue(const T& value); // adding an element to the queue
        T dequeue(); // delete an element from queue
        std::size_t size();  //  shows number of element in the queue
        const T& front(); // returns first element in the queue (doesnt delete it)
};


// CONSTRUCTOR with parameters
template <typename T>
QueueTab<T>::QueueTab(std::size_t initialCapacity)
{
    capacity= initialCapacity;
    tab = new T[capacity];
    q_front = -1;


}



//  ENQUEUE - adding an element to the queue
template <typename T>
void QueueTab<T>::enqueue(const T& value) {
    if(q_front == capacity-1){
        std::cout<<"Overflow\n";
    }

    tab[++q_front]=value;

    
    }

//  FRONT - returns first element in the queue (doesnt delete it)
template <typename T>
const T& QueueTab<T>::front() {
   if(q_front == -1){
       std::cout<<"Underflow\n";
        exit(1);
    }

T static t=tab[0];
return t;
    }

//  SIZE - returns first element in the queue (doesnt delete it)
template <typename T>
std::size_t QueueTab<T>::size() {
   if(q_front == -1){
       std::cout<<"Queue empty\n";
        exit(1);
    }
    std::cout<<"Number of elements :" << ++q_front << std::endl;
    return q_front;

    }