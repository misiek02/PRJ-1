#include <SFML/Graphics.hpp>
#include "stack.h"
#include "queueTab.h"
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

    return 0;
} 