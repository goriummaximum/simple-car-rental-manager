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
            short input_hour,
            short input_day,
            short input_month,
            short input_year
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

class ServiceHistory
{
    private:
        short id;
        Time service_time;
        string engine;
        string transmission;
        string tires;

    public:
        ServiceHistory(
                short input_id,
                short input_hour,
                short input_day,
                short input_month,
                short input_year,
                string input_input_engine,
                string input_transmission,
                string input_tires
        );

        void set_id(short input_id);
        void set_service_time(Time input_service_time);
        void set_engine(string input_engine);
        void set_transmission(string input_transmission);
        void set_tires(string input_tires);

        short get_id();
        Time get_service_time();
        string get_engine();
        string get_transmission();
        string get_tires();
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
        float mileage;
        vector<ServiceHistory> *service_history;

    public:
        Vehicle(
            string input_id,
            string input_brand,
            string input_model,
            string input_color, 
            short input_n_seats,
            short input_manufacture_hour,
            short input_manufacture_day, 
            short input_manufacture_month,
            short input_manufacture_year,  
            bool input_status,
            float input_mileage
            );
        ~Vehicle();

        void set_id(const string input_id);
        void set_status(const int input_status);
        void set_brand(const string input_brand);
        void set_model(const string input_model);
        void set_color(const string input_color);
        void set_n_seats(const short input_n_seats);
        void set_manufacture_time(const Time input_manufacture_time);
        void set_mileage(const float input_mileage);

        string get_id();
        bool get_status();
        string get_brand();
        string get_model();
        string get_color();
        short get_n_seats();
        Time get_manufacture_time();
        float get_mileage();

        virtual void add_service_history(ServiceHistory input_history) = 0;
};

class Sport : public Vehicle {
    public:
        Sport(
            string input_id,
            string input_brand,
            string input_model,
            string input_color, 
            short input_n_seats,
            short input_manufacture_hour,
            short input_manufacture_day, 
            short input_manufacture_month,
            short input_manufacture_year,  
            bool input_status,
            float input_mileage
            );
        ~Sport();

        void add_service_history(ServiceHistory input_history);
};

class Motorcycle : public Vehicle {
    private:
        bool is_helmet_included;
    public:
        Motorcycle(
            string input_id,
            string input_brand,
            string input_model,
            string input_color, 
            short input_n_seats,
            short input_manufacture_hour,
            short input_manufacture_day, 
            short input_manufacture_month,
            short input_manufacture_year,  
            bool input_status,
            float input_mileage,
            bool input_is_helmet_included
            );
        ~Motorcycle();

        void set_is_helmet_included(const bool input_is_helmet_included);
        short get_is_helmet_included();

        void add_service_history(ServiceHistory input_history);
};

class SUV : public Vehicle {
    private:
        bool is_bag_included;
    
    public:
        SUV(
            string input_id,
            string input_brand,
            string input_model,
            string input_color, 
            short input_n_seats,
            short input_manufacture_hour,
            short input_manufacture_day, 
            short input_manufacture_month,
            short input_manufacture_year,  
            bool input_status,
            float input_mileage,
            bool input_is_bag_included
            );
        ~SUV();

        void set_is_bag_included(const short input_is_bag_included);
        short get_is_bag_included();

        void add_service_history(ServiceHistory input_history);
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
        string id;
        string name;
        bool gender;
        Time dob;
        string email;
        string driver_license_id;
        string phone_number;
    
    public:
        Customer(
            string input_id,
            string input_name,
            bool input_gender,
            short hour,
            short day,
            short month,
            short year,
            string input_email,
            string input_driver_license_id,
            string input_phone_number
        );
        ~Customer();

        void set_id(const string input_id);
        void set_name(const string input_name);
        void set_gender(const bool input_gender);
        void set_dob(const Time input_dob);
        void set_email(const string input_email);
        void set_driver_license_id(const string input_driver_license_id);
        void set_phone_number(const string input_phone_number);

        string get_id();
        string get_name();
        bool get_gender();
        Time get_dob();
        string get_email();
        string get_driver_license_id();
        string get_phone_number();
};

class RentalContract
{
    private:
        string id;
        short status;
        string customer_id;
        string customer_name;
        string vehicle_id;
        string vehicle_model;
        Time pickup_time;
        Time return_time;
        short payment_method;
    
    public:
        RentalContract(
            string input_id,
            short input_status,
            string input_customer_id,
            string input_customer_name,
            string input_vehicle_id,
            string input_vehicle_model,
            short input_pickup_hour,
            short input_pickup_day,
            short input_pickup_month,
            short input_pickup_year,
            short input_return_hour,
            short input_return_day,
            short input_return_month,
            short input_return_year,
            short input_payment_method
        );

        ~RentalContract();

        void set_id(const string input_id);
        void set_status(const short input_status);
        void set_pickup_time(const Time input_pickup_time);
        void set_return_time(const Time input_return_time);
        void set_payment_method(const short input_payment_method);

        string get_id();
        short get_status();
        string get_customer_id();
        string get_customer_name();
        string get_vehicle_id();
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
    
    protected:
        
        
    public:
        CarRentalMgmt();
        ~CarRentalMgmt();

        void service_fleet();

        void book_a_vehicle();
        void sign_a_contract();
};

#endif