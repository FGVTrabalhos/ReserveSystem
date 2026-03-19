#pragma once
#include "ReservationRequest.hpp"
#include <string>
#include <iostream>


struct reserved{
    std::string course_name;
    int start;
    int end;

    reserved();

    reserved(ReservationRequest&);

    bool operator<(const reserved& other);
    bool operator==(const std::string& course);

    void print_reserve();
};


class list_reserved{
    struct node {
        reserved data;
        node* next;
    }* head;
    int size;
    
    void release(node* next);

    void insert(reserved v, node** next);
    void remove(node** next);

    void print_reserves_aux(node* next);
    bool try_reserve_aux(reserved& request, node** next);
    bool try_cancel_aux(std::string& name, node** next);

    public:
        list_reserved();
        ~list_reserved();


        void print_reserves();
        bool try_reserve(ReservationRequest& request);
        bool try_cancel(std::string& name);
        int get_size();
};