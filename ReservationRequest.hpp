#pragma once

#include <string>

class ReservationRequest{
        std::string course_name;
        std::string weekday;
        int start_hour;
        int end_hour;
        int student_count;
    public:

        ReservationRequest(std::string course_name, std::string weekday, int start_hour, int end_hour, int student_count);
        ~ReservationRequest() = default;

        int getStartHour();
        int getEndHour();
        std::string getCourseName();
        std::string getWeekday();
        int getStudentCount();
};