#include <iostream>

#include "funkcje.hpp"

int main(int argc, const char * argv[]) {
    
    Cruise * pHeadCruise = nullptr, * pTailCruise = nullptr;
    Passenger * pHeadPass = nullptr;
    
    addPassenger(pHeadPass, "Moritz", "Haber");
    addPassenger(pHeadPass, "Franz", "Nogay");
    addPassenger(pHeadPass, "Jan", "Kaniowski");
    
    showPassengers(pHeadPass);
    
    addCruise(pHeadCruise, pTailCruise, "2019-01-03", "Dover", "Helsinki");
    addCruise(pHeadCruise, pTailCruise, "2017-05-29", "Naples", "Calais");
    addCruise(pHeadCruise, pTailCruise, "2018-02-14", "Messina", "Dover");
    addCruise(pHeadCruise, pTailCruise, "2019-11-05", "Helsinki", "Naples");
    
    showCruises(pHeadCruise);
    
    return 0;
}
