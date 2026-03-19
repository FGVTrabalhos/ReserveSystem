#include "ReservationSystem.hpp"


int main (void){
    int capacities[4] = {30, 40, 50, 40};
    ReservationSystem sistema(4, capacities);

    ReservationRequest requisite("calculus", "segunda", 9, 11, 30);

    std::cout << sistema.reserve(requisite) << std::endl;

    sistema.printSchedule();
    return 0;
}