#include "ReservationRequest.hpp"
#include "list.hpp"


class ReservationSystem {

    private:
        int room_count;
        int* room_capacities;

        list* horarios;
        // Estruturas internas escolhidas pelos alunos
        // para armazenar e gerenciar as reservas, os horários, ...

    public:

        ReservationSystem(int room_count, int* room_capacities);
        ~ReservationSystem();

        bool reserve(ReservationRequest request);// Deveria ser por referência?
        bool cancel(std::string course_name);

        void printSchedule();

        // Outros métodos utilitários necessários
        // para auxiliar nas funções requisitadas
};