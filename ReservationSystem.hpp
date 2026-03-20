#pragma once
#include "ReservationRequest.hpp"
#include "list.hpp"


int map_weekday(std::string weekday);
std::string map_int(int day);


class ReservationSystem {
    private:
        int room_count;
        int* room_capacities;

        list_reserved (*horarios)[5]; // ponteiro para cada sala e então para cada dia da semana
        // Estruturas internas escolhidas pelos alunos
        // para armazenar e gerenciar as reservas, os horários, ...

    public:

        ReservationSystem(int room_count, int* room_capacities);
        ~ReservationSystem();

        bool reserve(ReservationRequest request);// Deveria ser por referência?
        bool cancel(std::string course_name);

        void printSchedule();

        bool validar_request(ReservationRequest& request);
};