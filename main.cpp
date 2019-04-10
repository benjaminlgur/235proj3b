#include <iostream>
#include "LinkedList.hpp"

int main(){
    LinkedList<int> foo;
    //foo.insert(1,20);
    //foo.insert(2,12);
    //foo.insert(3,10);
    //foo.insert(4,15);
    //foo.insert(5, 2);
    //foo.selectionSort();
    for (int i = 1; i < foo.getLength()+1; i++){
        std::cout << foo.getEntry(i) << std::endl;
    }
    
}