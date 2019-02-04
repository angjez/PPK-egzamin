#ifndef funkcje_hpp
#define funkcje_hpp

#include <string>
#include <stdio.h>
#include <iostream>

struct Item
{
    std::string name;
    double price;
    Item * pPrev, * pNext; // pointer to previous and next Item in a double-linked list
};
struct Customer
{
    std::string name, surname;
    Item * pBoughtItems;
    Customer * pLeft , * pRight;
};

/* Function that adds an item (price and name given) to a customer (name and surname given). If a customer is absent, a new customer object is created in the correct localisation. An empty list of items is also possible.
 */
void add (double & price, std::string & productName, std::string & customersName, std::string & surname, Item * & pHead, Item * & pTail, Customer * & pRoot);

/* Define a function remove that removes an item from a customer. Parameters of the function: root of a tree, name and surname of a customer, name and price of an items. The function returns:
    • true if item removed successfully,
    • false otherwise.
    An empty tree is possible.
 */
bool remove (Customer * & pRoot, double & price, std::string & productName, std::string & customersName, std::string & surname);

void addItem (double & price, std::string & productName, Item * & pHead, Item * & pTail);
void show (Customer * pRoot);


#endif /* funkcje_hpp */
