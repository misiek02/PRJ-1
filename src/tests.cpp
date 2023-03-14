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
    y.push(2);
    y.push(4);
    y.push(6);
    y.push(7);
    y.pop();
    y.pop();
    REQUIRE(y.top() == 4 );
    REQUIRE(y.empty() == 1);
  
}


TEST_CASE( "Stack based on list tests2" ) {
    StackList<int> y;
    y.push(2);
    y.push(4);
    y.push(6);
    y.push(7);
    y.pop();
    y.pop();
    REQUIRE(y.top() == 4 );
    REQUIRE(y.empty() == 1);
  
}

TEST_CASE( "Stack based on list test2s" ) {
    StackList<int> y;
    y.push(2);
    y.push(4);
    y.push(6);
    y.push(7);
    y.pop();
    y.pop();
    REQUIRE(y.top() == 4 );
    REQUIRE(y.empty() == 1);
  
}
TEST_CASE( "Stack ba532st tes3ts" ) {
    StackList<int> y;
    y.push(2);
    y.push(4);
    y.push(6);
    y.push(7);
    y.pop();
    y.pop();
    REQUIRE(y.top() == 4 );
    REQUIRE(y.empty() == 1);
  
}
TEST_CASE( "Stack532 on li4st tests" ) {
    StackList<int> y;
    y.push(2);
    y.push(4);
    y.push(6);
    y.push(7);
    y.pop();
    y.pop();
    REQUIRE(y.top() == 4 );
    REQUIRE(y.empty() == 1);
  
}


TEST_CASE( "Stack b432st tests" ) {
    StackList<int> y;
    y.push(2);
    y.push(4);
    y.push(6);
    y.push(7);
    y.pop();
    y.pop();
    REQUIRE(y.top() == 4 );
    REQUIRE(y.empty() == 1);
  
}

TEST_CASE( "Stack ba432 tests" ) {
    StackList<int> y;
    y.push(2);
    y.push(4);
    y.push(6);
    y.push(7);
    y.pop();
    y.pop();
    REQUIRE(y.top() == 4 );
    REQUIRE(y.empty() == 1);
  
}

TEST_CASE( "Stack based 43ist tests" ) {
    StackList<int> y;
    y.push(2);
    y.push(4);
    y.push(6);
    y.push(7);
    y.pop();
    y.pop();
    REQUIRE(y.top() == 4 );
    REQUIRE(y.empty() == 1);
  
}