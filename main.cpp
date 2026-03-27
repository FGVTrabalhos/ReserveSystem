#include "ReservationSystem.hpp"


#define SALAS 5

int main (void){
    // Criação do Sistema
    int capacities[SALAS] = {30, 100}; 
    ReservationSystem sistema(SALAS, capacities);

    // Reservas bem sucedidas
    ReservationRequest calculus("Vetorial Calculus", "segunda", 9, 11, 20);
    sistema.reserve(calculus);

    ReservationRequest datastructures("Data Structures", "segunda", 7, 9, 65);
    sistema.reserve(datastructures);

    ReservationRequest algebra("Numerical Linear Algebra", "terca", 11, 13, 65);
    sistema.reserve(algebra);

    ReservationRequest probability("Theory of probability", "segunda", 11, 13, 65);
    sistema.reserve(probability);

    ReservationRequest diferencialequations("Ordinary Diferencial Equations", "terca", 9, 11, 20);
    sistema.reserve(diferencialequations);

    // Tentativa de reserva sem disponibilidade
    ReservationRequest englishclass("English Class - Book 7", "segunda", 7, 9, 30);
    sistema.reserve(englishclass);

    // Tentativa de reserva extrapolando o limite da sala
    ReservationRequest lecture("Lecture with Cesár Camacho", "sexta", 14, 16, 250);
    sistema.reserve(lecture);

    // Cancelamento de reserva
    sistema.cancel("Vetorial Calculus");

    // Visualizando grade
    sistema.printSchedule(); 
    return 0;
}