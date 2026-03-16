#include "ReservationRequest.hpp"

ReservationRequest::ReservationRequest(
                                        std::string course_name,
                                        std::string weekday,
                                        int start_hour,
                                        int end_hour,
                                        int student_count
    ){

}


ReservationRequest::~ReservationRequest(){

}

int ReservationRequest::getStartHour(){
    return 0;
}


int ReservationRequest::getEndHour(){
    return 0;
}


std::string ReservationRequest::getCourseName(){
    return "";
}


std::string ReservationRequest::getWeekday(){
    return "";
}


int ReservationRequest::getStudentCount(){
    return 0;
}