#ifndef PROCESSCOMPANY_H_
#define PROCESSCOMPANY_H_

#include "main.h"

class Time
{
    private:
        short hour;
        short day;
        short month;
        short year;
    
    public:
        Time(
            short input_hour = 0,
            short input_day = 0,
            short input_month = 0,
            short input_year = 0
        );

        void set_hour(short input_hour);
        void set_day(short input_day);
        void set_month(short input_month);
        void set_year(short input_year);

        short get_hour();
        short get_day();
        short get_month();
        short get_year();
};

class Vehicle
{
    protected:
        string id;
        bool status;
        string brand;
        string model;
        string color;
        short n_seats;
        Time manufacture_time;

    public:
        Vehicle(
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
            );
        ~Vehicle();

        void set_id(const int input_id);
        void set_status(const int input_status);
        void set_brand(const string input_brand);
        void set_model(const string input_model);
        void set_color(const string input_color);
        void set_n_seats(const short input_n_seats);
        void set_manufacture_time(const Time input_manufacture_time);

        string get_id();
        bool get_status();
        string get_brand();
        string get_model();
        string get_color();
        short get_n_seats();
        Time get_manufacture_time();
};

class Sport : public Vehicle {
    private:
        short exhaust_pipe_type;
    
    public:
        public:
         Sport(
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
            );
        ~Sport();

        void set_exhaust_pipe_type(const short input_type);
        short get_exhaust_pipe_type();
};

class Motorcycle : public Vehicle {
    private:
        bool is_helmet_included;
    public:
        Motorcycle(
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
            );
        ~Motorcycle();

        void set_is_helmet_included(const bool input_is_helmet_included);
        short get_is_helmet_included();
};

class SUV : public Vehicle {
    private:
        bool is_bag_included;
    
    public:
        SUV(
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
            );
        ~SUV();

        void set_is_bag_included(const short input_is_bag_included);
        short get_is_bag_included();
};

class CarFleet
{
    private:
        vector<Sport> *list_sport;
        vector<Motorcycle> *list_motorcycle;
        vector<SUV> *list_SUV;
    
    public:
        CarFleet();
        ~CarFleet();
};

class Customer
{
    private:
        string name;
        bool gender;
        Time dob;
        string email;
        string driver_license;
        string phone_number;
    
    public:
        Customer(
            string input_name = "NA",
            bool input_gender = false,
            short hour = 0,
            short day = 0,
            short month = 0,
            short year = 0,
            string input_email = "NA",
            string input_driver_license = "NA",
            string input_phone_number = "NA"
        );
        ~Customer();

        void set_name(const string input_name);
        void set_gender(const bool input_gender);
        void set_dob(const Time input_dob);
        void set_email(const string input_email);
        void set_driver_license(const string input_driver_license);
        void set_phone_number(const string phone_number);

        string get_name();
        bool get_gender();
        Time get_dob();
        string get_email();
        string get_driver_license();
        string get_phone_number();
};

class RentalContract
{
    private:
        string id;
        short status;
        string customer_name;
        string vehicle_model;
        Time pickup_time;
        Time return_time;
        short payment_method;
    
    public:
        RentalContract(
            string input_id = "NA",
            short input_status = 0,
            string input_customer_name = "NA",
            string input_vehicle_model = "NA",
            short input_pickup_hour = 0,
            short input_pickup_day = 0,
            short input_pickup_month = 0,
            short input_pickup_year = 0,
            short input_return_hour = 0,
            short input_return_day = 0,
            short input_return_month = 0,
            short input_return_year = 0,
            short input_payment_method = 0
        );

        ~RentalContract();

        void set_id(const string input_id);
        void set_status(const short input_status);
        void set_customer_name(const string input_customer_name);
        void set_vehicle_model(const string input_vehicle_model);
        void set_pickup_time(const Time input_pickup_time);
        void set_return_time(const Time input_return_time);
        void set_payment_method(const short input_payment_method);

        string get_id();
        short get_status();
        string get_customer_name();
        string get_vehicle_model();
        Time get_pickup_time();
        Time get_return_time();
        short get_payment_method();
};

class BookAndRent
{
    public:
        virtual void book_a_vehicle() = 0;
        virtual void sign_a_contract() = 0;
};

class CarRentalMgmt : public BookAndRent
{
    private:
        CarFleet *my_fleet;
        vector<Customer> *list_customers;
        vector<RentalContract> *list_contracts;
    
    public:
        CarRentalMgmt();
        ~CarRentalMgmt();

        void book_a_vehicle();
        void sign_a_contract();
};

#endif