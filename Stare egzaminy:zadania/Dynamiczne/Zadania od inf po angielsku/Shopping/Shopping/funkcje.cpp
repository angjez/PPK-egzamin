#include "funkcje.hpp"

void add (double & price, std::string & productName, std::string & customersName, std::string & surname, Item * & pHead, Item * & pTail, Customer * & pRoot)
{
    if(pRoot == nullptr)
        pRoot = new Customer {customersName, surname, nullptr, nullptr};
    Customer * tmp = pRoot;
    while (tmp) {
        if(tmp->name == customersName && tmp->surname == surname) {
            addItem(price, productName, tmp->pBoughtItems, pTail);
            break;
        }
        else {
            if(tmp->surname > surname) {
                if(tmp->pLeft == nullptr) {
                    tmp->pLeft = new Customer {customersName, surname, nullptr, nullptr, nullptr};
                    addItem(price, productName, tmp->pBoughtItems, pTail);
                    break;
                }
                else
                    tmp = tmp->pLeft;
            }
            
            if(tmp->surname < surname) {
                if(tmp->pRight == nullptr) {
                    tmp->pRight = new Customer {customersName, surname, nullptr, nullptr, nullptr};
                    addItem(price, productName, tmp->pBoughtItems, pTail);
                    break;
                }
                else
                    tmp = tmp->pRight;
            }
            
            if(tmp->surname == surname) {
                if(tmp->name > customersName) {
                    if(tmp->pLeft == nullptr)
                        tmp->pLeft = new Customer {customersName, surname, nullptr, nullptr, nullptr};
                    else
                        tmp = tmp->pLeft;
                }
                if(tmp->name < customersName) {
                    if(tmp->pRight == nullptr)
                        tmp->pRight = new Customer {customersName, surname, nullptr, nullptr, nullptr};
                    else
                        tmp = tmp->pRight;
                }
            }
        }
    }
}

void addItem (double & price, std::string & productName, Item * & pHead, Item * & pTail)
{
    Item * current = pHead;
    
    if (pHead == nullptr){
        pHead = new Item {productName, price, pTail, pHead};
        pTail = pHead;
    }
    
    // nowy wskaźnik będzie dodany na początek listy
    else if (pHead->price >= price){
        pHead = new Item {productName, price, nullptr, pHead};
        pHead->pNext->pPrev = pHead;
    }
    
    else {
        //szukamy miejsca do umieszczenia elementu
        while (current->pNext != nullptr && current->pNext->price < price)
            current = current->pNext;
        
        //element należy dodać na koniec- korzystamy z uprzednio zdefiniowanej funkcji
        if (current->pNext == nullptr){
            pTail = new Item {productName, price, pTail, nullptr};
            pTail->pPrev->pNext = pTail;
        }
        else{
            Item * newElem = new Item {productName, price, current, current->pNext};
            current->pNext = newElem;
            newElem->pNext->pPrev = newElem;
        }
    }
}

bool remove (Customer * pRoot, double & price, std::string & productName, std::string & customersName, std::string & surname);

void show (Customer * pRoot)
{
    if (pRoot)  // jezeli drzewo jest niepuste
    {
        show(pRoot->pLeft);
        std::cout << pRoot->name << " " << pRoot->surname << std::endl;
        while(pRoot->pBoughtItems) {
                std::cout << pRoot->pBoughtItems->name << " " << pRoot->pBoughtItems->price << std::endl;
                pRoot->pBoughtItems = pRoot->pBoughtItems->pNext;
            }
        show(pRoot->pRight);
    }
}
