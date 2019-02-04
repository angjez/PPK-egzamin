#include <iostream>
#include <string>

#include "funkcje.hpp"

int main(int argc, const char * argv[]) {
    Item * pHead = nullptr;
    Item * pTail = nullptr;
    Customer * pRoot = nullptr;
    
    double price1 = 12.34, price2 = 56.78, price3 = 90.12;
    std::string first = "item1", second = "item2", third = "item3", name1 = "Adam", name2 = "Robert", name3 = "Piotr", surname1 = "Adamski", surname2 = "Robertson", surname3 = "Piotrowicz";
    
    add(price2, first, name1, surname1, pHead, pTail, pRoot);
    add(price2, second, name2, surname2, pHead, pTail, pRoot);
    add(price1, first, name3, surname3, pHead, pTail, pRoot);
    add(price3, third, name1, surname1, pHead, pTail, pRoot);

    
    show(pRoot);
    
    return 0;
}
