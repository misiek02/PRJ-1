#include <SFML/Graphics.hpp>
#include "stack.h"
#include <iostream>

int main()
{
    Stack<float> y;
    y.push(2.011);
    y.push(4.99);
    y.empty();
    float g = y.top();
    std::cout<<g<<std::endl;

    return 0;
} 