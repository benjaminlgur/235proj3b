#include <iostream>
#include "LinkedList.hpp"

int main(){
    LinkedList<int> foo;
    for (int i = 1; i < 10; i++){
        foo.insert(i, i);
    }
    foo.testFunc();
    for (int i = 1; i < 10; i++){
        std::cout << foo.getEntry(i) << std::endl;
    }
    
}