#include "ReservationSystem.hpp"


int main (void){
    int capacities[4] = {30, 40, 50, 40};
    ReservationSystem sistema(4, capacities);

    ReservationRequest requisite("calculus", "segunda", 9, 11, 30);
    sistema.reserve(requisite);

    
    ReservationRequest outrarequisite("analisis", "segunda", 7, 8, 30);
    sistema.reserve(outrarequisite);

    sistema.printSchedule();
    return 0;
}