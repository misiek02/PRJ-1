#pragma once


template <typename T>
struct PriorityNode{
    T value;
    int priority;
    PriorityNode<T> *next;


    PriorityNode(){this->next = NULL;}
    PriorityNode(T value, int priority, PriorityNode *next=NULL) {this->value=value;this->priority=priority ;this->next=next;}
};


template <typename T>
class PriorityQueue{
    PriorityNode<T> *head;
  
    public:
    PriorityQueue() {this->head = NULL;}
    void insert(const T& newElement, int key); //  inserts elem at the  index position
    void addFront(const T& newElement,int key); // adds first elem if queue is empty
    bool empty() ; // returns 1 if queue is empty
    const T& min() const; // returns elem from queue deosnt delete
    void removeFront(); // removes and returnselem from queue

        

};

template <typename T>
// INSERT - inserts elem at the index position
void PriorityQueue<T>::insert(const T &newElement, int key)
{
    PriorityNode<T>* temp = new PriorityNode<T>;
    PriorityNode<T>* start = new PriorityNode<T>;
    temp->priority=key;
    temp->value=newElement;

    start = head;
if(head!=NULL){
    if(head->priority > key) {
 

        temp->next = head;
        head = temp;
    }

     else {
 
       
        while (start->next != NULL
               && start->next->priority < key) {
            start = start->next;
        }
 
       
        temp->next = start->next;
        start->next = temp;
     }
 }

else
         addFront(newElement,key);
// if(key < 1) 
//     key=1;



// PriorityNode<T> *NEW = new PriorityNode<T>;
// PriorityNode<T> *OLD;
// PriorityNode<T> *temp_node = new PriorityNode<T>;
// NEW->value=newElement;
// NEW->priority=key;


// temp_node=head;

// if(head!=NULL){
//     if(temp_node->priority>=key){
//          OLD=temp_node->next;
//     temp_node->next=NEW;
//     NEW->next=OLD;
//     }
//     else{
//     while(temp_node->next->priority<=key && temp_node->next!=NULL){
//         temp_node=temp_node->next;

        
//     }
//     OLD=temp_node->next;
//     temp_node->next=NEW;
//     NEW->next=OLD;
// }
// }
//     else
//         addFront(newElement,key);
    
}

template <typename T>
void PriorityQueue<T>::addFront(const T &newElement, int key)
{
    head=new PriorityNode(newElement,key,head);
}

template <typename T>
bool PriorityQueue<T>::empty()
{
    return (head==NULL);
}
