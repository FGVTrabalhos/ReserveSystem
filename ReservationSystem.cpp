#include "ReservationSystem.hpp"


ReservationSystem::ReservationSystem(int room_c, int* room_capa) : room_count(room_c){
    room_capacities = room_capa;
}

ReservationSystem::~ReservationSystem(){

}

bool ReservationSystem::reserve(ReservationRequest request){
    return true;
}


bool ReservationSystem::cancel(std::string course_name){
    return true;
}

void ReservationSystem::printSchedule(){
    
}