#ifndef funkcje_hpp
#define funkcje_hpp

#include <stdio.h>
#include <string>
#include <iostream>

struct Passenger
{
    std::string name, surname;
    Passenger * pNext;
};

struct Cruise
{
    std::string start_harbour, end_harbour;
    std::string date;
    Passenger * pPassengers;
    Cruise * pPrev , * pNext ;
};

/* The function searches for a cruise defined with a date, start harbour, and end harbour in a list of cruises pH. The function returns an address of the found cruise. If there is not matching cruise, the function returns NULL (or nullptr or 0). */
Cruise * findCruise (Cruise * pH, const std::string & start_harbour, const std::string & end_harbour, const std::string & date);

/* The function adds in a non descending order a new cruise to a list of cruises (head: pH, tail pT). The adding of a new cruise keeps the non descending order by date. The function returns an address of an added cruise. It is possible that the list is empty. The function adds a new cruise iteratively. */
Cruise * addCruise (Cruise * & pHead, Cruise * & pTail, const std::string & date, const std::string start_harbour, const std::string & end_harbour);

/* The function adds a new passenger to a singly linked list of passengers (head pH). The function returns a head of a modified list. The function keeps the non descending order by surnames of passengers. An empty list is possible. The function adds passenger recursively. */
Passenger * addPassenger (Passenger * & pH, const std::string & name, const std::string & surname);

/* The function adds a passenger (name, surname given) to a doubly linked list of cruises (with head pH and tail pT). If a cruise is missing, it is added so that the ordering of the list is kept. It is possible that the list of cruised is empty. Cruises with no passengers are also possible. Function uses the functions defined above. */
void addPassengerToCruise (Cruise * & pH, Cruise * & pT, const std::string & date, const std::string & start_harbour, const std::string & end_harbour, const std::string & name, const std::string & surname);

/* The function returns an address of a cruise with the maximal length of passengers. Passed parameters: an address of the head of the list pH. If the list of cruises is empty, the function returns NULL (or nullptr or 0). If several cruises have the same lengths of passengers, the function returns an address of any of cruises with maximal length of passengers. */
Cruise * favourite (Cruise * & pH);

/* Additional functions */
void showPassengers (Passenger * pHead);
void showCruises (Cruise * pHead);

#endif /* funkcje_hpp */
