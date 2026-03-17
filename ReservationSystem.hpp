#include "ReservationRequest.hpp"
#include "list.hpp"


int map_weekday(std::string weekday){
    if (weekday == "segunda")
        return 1;
    if (weekday == "terca")
        return 2;
    if (weekday == "quarta")
        return 3;
    if (weekday == "quinta")
        return 4;
    if (weekday == "sexta")
        return 5;
        
    return 0;
}


class ReservationSystem {
    private:
        int room_count;
        int* room_capacities;

        list_reserved** horarios; // ponteiro para cada sala e então para cada dia da semana
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