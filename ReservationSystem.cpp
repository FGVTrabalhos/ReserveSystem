#include "ReservationSystem.hpp"


ReservationSystem::ReservationSystem(int room_count, int* room_capacities) : 
    room_count(room_count),
    room_capacities(room_capacities)
    {
    horarios = new list_reserved[room_count][5];
}

ReservationSystem::~ReservationSystem(){
    delete[] horarios;
}

bool ReservationSystem::reserve(ReservationRequest request){
    int day = map_weekday(request.getWeekday());
    bool accepted = false;
    
    for (int i = 0; i < room_count; i++){
        accepted = horarios[i][day].try_reserve(request);

        if (accepted)
            break;
    }
    return accepted;
}


bool ReservationSystem::cancel(std::string course_name){
    return true;
}

void ReservationSystem::printSchedule(){

}