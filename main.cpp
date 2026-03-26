#include "ReservationSystem.hpp"


int main (void){
    int capacities[2] = {30, 40};
    ReservationSystem sistema(2, capacities);

    ReservationRequest requisite("calculus", "segunda", 9, 11, 40);
    sistema.reserve(requisite);

    
    ReservationRequest outrarequisite("analisis", "segunda", 7, 9, 30);
    sistema.reserve(outrarequisite);

    ReservationRequest outrarequisite1("Algebra", "segunda", 7, 8, 30);
    sistema.reserve(outrarequisite1);

    ReservationRequest outrarequisite2("Lp", "segunda", 7, 8, 30);
    sistema.reserve(outrarequisite1);

    sistema.printSchedule();
    return 0;
}