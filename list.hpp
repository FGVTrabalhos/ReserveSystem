#include "ReservationRequest.hpp"
#include <string>



struct reserved{
    std::string course_name;
    int start;
    int end;

    bool operator<(const reserved& other);
    bool operator==(const std::string& course);

    void print_reserve();
};


class list_reserved{
    struct node {
        reserved data;
        node* next;
    }* head;
    std::string weekday;
    int size;


    void print_reserves_aux(node* head);


    public:

        void print_reserves();
        bool try_reserve(ReservationRequest& request);
        bool try_cancel(std::string name);
};