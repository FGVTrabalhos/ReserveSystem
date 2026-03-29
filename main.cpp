#include "ReservationSystem.hpp"


#define SALAS 3

// ================================================================================
// Funções para os testes

void testSuccessfulReservations(ReservationSystem& sistema) {
    std::cout << "===================================================================================================" << std::endl;
    std::cout << "Iniciando teste de inserir reservas com sucesso" << std::endl;

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

    sistema.printSchedule();
    sistema.cancel("Vetorial Calculus");
    sistema.cancel("Data Structures");
    sistema.cancel("Numerical Linear Algebra");
    sistema.cancel("Theory of probability");
    sistema.cancel("Ordinary Diferencial Equations");

    std::cout << "Reservas canceladas" << std::endl;
    std::cout << "Teste encerrado" << std::endl;
};


void testRoomCapacityLimit(ReservationSystem& sistema) {
    std::cout << "===================================================================================================" << std::endl;
    std::cout << "Iniciando teste de pedido de reserva que ultrapassa a capacidade de alunos" << std::endl;
    // Tentativa de reserva extrapolando o limite da sala
    ReservationRequest lecture("Lecture with Cesár Camacho", "sexta", 14, 16, 250);
    sistema.reserve(lecture);
    sistema.printSchedule();

    std::cout << "Teste encerrado" << std::endl;
};


void testOverbooking(ReservationSystem& sistema) {
    std::cout << "===================================================================================================" << std::endl;
    std::cout << "Iniciando teste de overbooking" << std::endl;
    // Tentativa de reserva sem disponibilidade (Lotando todas as salas segundas às 7:00)
    ReservationRequest englishclass2("English Class - Book 2", "segunda", 7, 9, 30);
    sistema.reserve(englishclass2);

    ReservationRequest englishclass7("English Class - Book 7", "segunda", 7, 9, 30);
    sistema.reserve(englishclass7);

    ReservationRequest englishclass9("English Class - Book 9", "segunda", 7, 9, 30);
    sistema.reserve(englishclass9);

    // Não funciona (3 salas ocupadas)
    ReservationRequest englishclass10("English Class - Book 10", "segunda", 7, 9, 30);
    sistema.reserve(englishclass10);

    sistema.printSchedule();
    sistema.cancel("English Class - Book 2");
    sistema.cancel("English Class - Book 7");
    sistema.cancel("English Class - Book 9");
    
    std::cout << "Reservas canceladas" << std::endl;
    std::cout << "Teste encerrado" << std::endl;
};


void testCancellation(ReservationSystem& sistema) {
    std::cout << "===================================================================================================" << std::endl;
    std::cout << "Iniciando teste de cancelamento de uma reserva" << std::endl;
    // Cancelamento de reserva
    ReservationRequest calculus("Vetorial Calculus", "segunda", 9, 11, 20);

    sistema.reserve(calculus);
    std::cout << "Reserva feita" << std::endl;
    sistema.printSchedule();

    sistema.cancel("Vetorial Calculus");
    std::cout << "Reserva cancelada" << std::endl;

    sistema.printSchedule();
    std::cout << "Teste encerrado" << std::endl;
};


int main (void){
    // Criação do Sistema
    int capacities[SALAS] = {30, 50, 100}; 
    ReservationSystem sistema(SALAS, capacities);

    // Realizando os Testes
    testSuccessfulReservations(sistema);
    testRoomCapacityLimit(sistema);
    testOverbooking(sistema);
    testCancellation(sistema);
    
    return 0;
}