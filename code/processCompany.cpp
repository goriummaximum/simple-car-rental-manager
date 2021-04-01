#include "main.h"
#include "processCompany.h"

Time::Time(
    short input_hour = 0,
    short input_day = 0,
    short input_month = 0,
    short input_year = 0
    ) : hour{input_hour},
        day{input_day},
        month{input_month},
        year{input_year}{};

void Time::set_hour(short input_hour)
{
    hour = input_hour;
}
void Time::set_day(short input_day)
{
    day = input_day;
}
void Time::set_month(short input_month)
{
    month = input_month;
}
void Time::set_year(short input_year)
{
    year = input_year;
}

short Time::get_hour()
{
    return hour;
}
short Time::get_day()
{
    return day;
}
short Time::get_month()
{
    return month;
}
short Time::get_year()
{
    return year;
}



Vehicle::Vehicle(
            string input_id = "NA",
            string input_brand = "NA",
            string input_model = "NA",
            string input_color = "NA", 
            short input_n_seats = 0,
            short input_manufacture_hour = 0,
            short input_manufacture_day = 0, 
            short input_manufacture_month = 0,
            short input_manufacture_year = 0,  
            bool input_status = false
        ) : id{input_id},
            brand{input_brand},
            model{input_model},
            color{input_color},
            n_seats{input_n_seats},
            status{input_status}
{
    manufacture_time.set_hour(input_manufacture_hour);
    manufacture_time.set_day(input_manufacture_day);
    manufacture_time.set_month(input_manufacture_month);
    manufacture_time.set_year(input_manufacture_year);
};

Vehicle::~Vehicle()
{

}

void Vehicle::set_id(const int input_id)
{
    id = input_id;
}
void Vehicle::set_status(const int input_status)
{
    status = input_status;
}
void Vehicle::set_brand(const string input_brand)
{
    brand = input_brand;
}
void Vehicle::set_model(const string input_model)
{
    model = input_model;
}
void Vehicle::set_color(const string input_color)
{
    color = input_color;
}
void Vehicle::set_n_seats(const short input_n_seats)
{
    n_seats = input_n_seats;
}
void Vehicle::set_manufacture_time(const Time input_manufacture_time)
{
    manufacture_time = input_manufacture_time;
}

string Vehicle::get_id()
{
    return id;
}
bool Vehicle::get_status()
{
    return status;
}
string Vehicle::get_brand()
{
    return brand;
}
string Vehicle::get_model()
{
    return model;
}
string Vehicle::get_color()
{
    return color;
}
short Vehicle::get_n_seats()
{
    return n_seats;
}
Time Vehicle::get_manufacture_time()
{
    return manufacture_time;
}



Sport::Sport(
        string input_id = "NA",
        string input_brand = "NA",
        string input_model = "NA",
        string input_color = "NA", 
        short input_n_seats = 0,
        short input_manufacture_hour = 0,
        short input_manufacture_day = 0, 
        short input_manufacture_month = 0,
        short input_manufacture_year = 0,  
        bool input_status = false,
        short input_exhaust_pipe_type = 0
    ) : Vehicle{
            input_id,
            input_brand,
            input_model,
            input_color,
            input_n_seats,
            input_manufacture_hour,
            input_manufacture_day,
            input_manufacture_month,
            input_manufacture_year,
            input_status
        }, exhaust_pipe_type{input_exhaust_pipe_type}{};
Sport::~Sport()
{

}

void Sport::set_exhaust_pipe_type(const short input_type)
{
    exhaust_pipe_type = input_type;
}

short Sport::get_exhaust_pipe_type()
{
    return exhaust_pipe_type;
}



Motorcycle::Motorcycle(
        string input_id = "NA",
        string input_brand = "NA",
        string input_model = "NA",
        string input_color = "NA", 
        short input_n_seats = 0,
        short input_manufacture_hour = 0,
        short input_manufacture_day = 0, 
        short input_manufacture_month = 0,
        short input_manufacture_year = 0,  
        bool input_status = false,
        bool input_is_helmet_included = false
    ) : Vehicle{
            input_id,
            input_brand,
            input_model,
            input_color,
            input_n_seats,
            input_manufacture_hour,
            input_manufacture_day,
            input_manufacture_month,
            input_manufacture_year,
            input_status
        }, is_helmet_included{input_is_helmet_included}{};

Motorcycle::~Motorcycle()
{

}

void Motorcycle::set_is_helmet_included(const bool input_is_helmet_included)
{
    is_helmet_included = input_is_helmet_included;
}

short Motorcycle::get_is_helmet_included()
{
    return is_helmet_included;
}



SUV::SUV(
        string input_id = "NA",
        string input_brand = "NA",
        string input_model = "NA",
        string input_color = "NA", 
        short input_n_seats = 0,
        short input_manufacture_hour = 0,
        short input_manufacture_day = 0, 
        short input_manufacture_month = 0,
        short input_manufacture_year = 0,  
        bool input_status = false,
        bool input_is_bag_included = false
    ) : Vehicle{
            input_id,
            input_brand,
            input_model,
            input_color,
            input_n_seats,
            input_manufacture_hour,
            input_manufacture_day,
            input_manufacture_month,
            input_manufacture_year,
            input_status
        }, is_bag_included{input_is_bag_included}{};
SUV::~SUV()
{

}

void SUV::set_is_bag_included(const short input_is_bag_included)
{
    is_bag_included = input_is_bag_included;
}

short SUV::get_is_bag_included()
{
    return is_bag_included;
}



CarFleet::CarFleet()
{
    list_sport = new vector<Sport>();
    list_motorcycle = new vector<Motorcycle>();
    list_SUV = new vector<SUV>();
}

CarFleet::~CarFleet()
{
    delete list_sport;
    delete list_motorcycle;
    delete list_SUV;
}