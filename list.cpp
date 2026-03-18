#include "list.hpp"


// ============================================================================
// Reserved

reserved::reserved(): course_name(""), start(0), end(21) {}

reserved::reserved(ReservationRequest& request): 
    course_name(request.getCourseName()),
    start(request.getStartHour()),
    end(request.getEndHour())
    {}

bool reserved::operator==(const std::string& s){
    return course_name == s;
}


bool reserved::operator<(const reserved& other){
    return end < other.end;
}


void reserved::print_reserve(){
    std::cout << start << "~" << end << ": " << course_name << std::endl;
}

// ============================================================================
// Lista


list_reserved::list_reserved(): head(nullptr), size(0) {}


list_reserved::~list_reserved(){
    release(head);
}


void list_reserved::release(list_reserved::node* next){
    if (next == nullptr)
        return;
    
    release(next->next);
    delete next;
}


// ============================================================================


void list_reserved::insert(reserved v, list_reserved::node **next){
    node* novo = new node;
    
    novo->data = v;
    novo->next = *next;

    *next = novo;
}


void list_reserved::remove(list_reserved::node **next){
    node* tmp = *next;

    if (tmp != nullptr){
        *next = tmp->next;
        delete tmp;
    }
}


// ============================================================================


void list_reserved::print_reserves_aux(list_reserved::node* next){
    if (next == nullptr)
        return;

    next->data.print_reserve();
    print_reserves_aux(next->next);
}

bool list_reserved::try_reserve_aux(reserved &request, list_reserved::node **next){
    if (*next == nullptr)
        return false;

    if ((*next)->data < request)
        return true;

    return try_reserve_aux(request, &((*next)->next));
}


bool list_reserved::try_cancel_aux(std::string& name, list_reserved::node **next){
    if (*next == nullptr)
        return false;
    
    if ((*next)->data == name){
        remove(next);
        return true;
    }

    return try_cancel_aux(name, &((*next)->next));
}


// ============================================================================


void list_reserved::print_reserves(){
    print_reserves_aux(head);
}

bool list_reserved::try_reserve(ReservationRequest &request){
    reserved n(request); 
    return try_reserve_aux(n, &head);
}

bool list_reserved::try_cancel(std::string& s){
    return try_cancel_aux(s, &head);
}