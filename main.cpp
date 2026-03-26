#include "ReservationSystem.hpp"


#define SALAS 5

int main (void){
    int capacities[SALAS] = {30, 100};
    ReservationSystem sistema(SALAS, capacities);

    ReservationRequest calculus("vetorial calculus", "segunda", 9, 11, 20);
    sistema.reserve(calculus);

    ReservationRequest datastructures("data structures", "segunda", 7, 9, 65);
    sistema.reserve(datastructures);

    ReservationRequest algebra("Numerical Linear Algebra", "terca", 11, 13, 65);
    sistema.reserve(algebra);

    ReservationRequest probability("Theory of probability", "segunda", 11, 13, 65);
    sistema.reserve(probability);

    ReservationRequest diferencialequations("Ordinary Diferencial Equations", "terca", 9, 11, 20);
    sistema.reserve(diferencialequations);

    sistema.printSchedule();
    return 0;
}