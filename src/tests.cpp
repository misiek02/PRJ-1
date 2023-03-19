#define CATCH_CONFIG_MAIN
#include "catch2/catch.hpp"
#include <SFML/Graphics.hpp>
#include "stackList.h"
#include "stackTab.h"
#include "queueTab.h"
#include "list.h"
#include "Array.h"
#include <iostream>



TEST_CASE( "Stack based on list tests" ) {
    StackList<int> y;
    REQUIRE(y.empty() == 1);
    y.push(2);
    REQUIRE(y.top() == 2 );
    y.push(4);
    REQUIRE(y.top() == 4 );
    y.push(6);
    REQUIRE(y.top() == 6 );
    y.push(7);
    REQUIRE(y.top() == 7 );
    y.pop();
    REQUIRE(y.top() == 6 );
    y.pop();
    REQUIRE(y.top() == 4 );
    REQUIRE(y.empty() == 0);
    REQUIRE(y.pop() == 4);
    REQUIRE(y.pop() == 2);
    REQUIRE(y.empty() == 1);
    
  
  
}


TEST_CASE( "Stack based on list tests II" ) {
    StackList<int> stack;

    stack.push(10);
    stack.push(20);
    stack.push(30);

    REQUIRE(stack.pop() == 30);
    REQUIRE(stack.pop() == 20);
    REQUIRE(stack.pop() == 10);
    REQUIRE(stack.empty() == true);
    stack.push(10);
    stack.push(20);
    REQUIRE(stack.empty() == false);
    stack.pop();
    REQUIRE(stack.empty() == false);
    stack.pop();
    REQUIRE(stack.empty() == true);
    stack.push(10);
    stack.push(20);
    REQUIRE(stack.top() == 20);
    stack.pop();
    REQUIRE(stack.top() == 10);



}