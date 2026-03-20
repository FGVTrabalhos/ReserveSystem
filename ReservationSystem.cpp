#include "ReservationSystem.hpp"

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


std::string map_int(int day){
    switch (day){
        case 1:
            return "segunda";
        case 2:
            return "terca";
        case 3:
            return "quarta";
        case 4:
            return "quinta";
        case 5:
            return "sexta";
        default:
            return "";
    }
}


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
    if (! validar_request(request))
        return false;



    int day = map_weekday(request.getWeekday()) - 1;
    bool accepted = false;
    
    std::cout << request.getCourseName() << std::endl;

    for (int i = 0; i < room_count; i++){
        accepted = horarios[i][day].try_reserve(request);

        if (accepted)
            break;
    }
    return accepted;
}


bool ReservationSystem::cancel(std::string course_name){
    bool canceled = false;
    
    for (int i = 0; i < room_count; i++){
        for (int day = 0; day < 5; day++){
            canceled = horarios[i][day].try_cancel(course_name);

            if(canceled)
                break;
        }

        if (canceled)
            break;
    }
    return canceled;
}

void ReservationSystem::printSchedule(){
    for (int i = 0; i < room_count; i++){
        if (true){
            std::cout <<  "Sala" << i + 1 << std::endl;
            
            for (int day = 0; day < 5; day++){
                if (horarios[i][day].get_size() > 0){
                    std::cout << map_int(day + 1) << std::endl;
                    horarios[i][day].print_reserves();
                }
            }
            std::cout << std::endl;
        }
    }
}