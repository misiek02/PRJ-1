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
        T pop(); // removes an element from the top
        std::size_t size();  //  shows number of element on the stack
        const T& top(); // returns value from the top (doesn't pop it)
};

template <typename T>
void StackTab<T>::StackTab(const T& value){
    if(s_top == capacity - 1){
        std::cout<<"Overflow\n";
        exit(1);
    }
    tab[++s_top]=value;
}