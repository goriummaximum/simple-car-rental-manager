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

class ServiceRecord
{
    private:
        short id;
        Time service_time;
        float mileage;
        string engine;
        string transmission;
        string tires;

    public:
        ServiceRecord(
                short input_id = -1,
                short input_hour = 0,
                short input_day = 0,
                short input_month = 0,
                short input_year = 0,
                float input_mileage = 0,
                string input_engine = "NA",
                string input_transmission = "NA",
                string input_tires = "NA"
        );

        void set_id(short input_id);
        void set_service_time(Time input_service_time);
        void set_mileage(float input_mileage);
        void set_engine(string input_engine);
        void set_transmission(string input_transmission);
        void set_tires(string input_tires);

        short get_id();
        Time get_service_time();
        float get_mileage();
        string get_engine();
        string get_transmission();
        string get_tires();
        ServiceRecord operator-(const ServiceRecord service2);
};

class Vehicle
{
    protected:
        string id;      //Sport: S0; Motor: M123; SUV: U5
        bool status;    //0: available, 1: unavailable
        string brand;
        string model;
        string color;
        short n_seats;
        Time manufacture_time;
        float mileage;
        vector<ServiceRecord> service_history;

    protected:
        json export_json_record(ServiceRecord input_record);

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
            bool input_status = false,
            float input_mileage = 0
            );
        ~Vehicle();

        void set_id(const string input_id);
        void set_status(const int input_status);
        void set_brand(const string input_brand);
        void set_model(const string input_model);
        void set_color(const string input_color);
        void set_n_seats(const short input_n_seats);
        void set_manufacture_time(const Time input_manufacture_time);
        void add_mileage(const float input_mileage);

        string get_id();
        bool get_status();
        string get_brand();
        string get_model();
        string get_color();
        short get_n_seats();
        Time get_manufacture_time();
        float get_mileage();

        float compute_mileage_between(short idx1, short idx2);

        virtual bool add_service_record() = 0;
        ServiceRecord *get_service_record_by_id(short id);
        ServiceRecord *get_service_record_at(short idx);
        short get_service_history_size();

        json export_json_record_by_id(short id);
        json export_json_record_all();
        void export_json_to_file(string file_name, json j_out);
};

class Sport : public Vehicle {
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
            float input_mileage = 0
            );
        ~Sport();

        bool add_service_record();
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
            float input_mileage = 0,
            bool input_is_helmet_included = false
            );
        ~Motorcycle();

        void set_is_helmet_included(const bool input_is_helmet_included);
        bool get_is_helmet_included();

        bool add_service_record();
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
            float input_mileage = 0,
            bool input_is_bag_included = false
            );
        ~SUV();

        void set_is_bag_included(const short input_is_bag_included);
        bool get_is_bag_included();

        bool add_service_record();
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

        short get_Sport_size();
        short get_Motorcycle_size();
        short get_SUV_size();

        void add_Sport(Sport input_Sport);
        void add_Motorcycle(Motorcycle input_Motorcycle);
        void add_SUV(SUV input_SUV);

        Sport *get_Sport_at(short idx);
        Motorcycle *get_Motorcycle_at(short idx);
        SUV *get_SUV_at(short idx);

        Sport *get_Sport_by_id(string id);
        Motorcycle *get_Motorcycle_by_id(string id);
        SUV *get_SUV_by_id(string id);

        bool remove_Sport_by_id(string id);
        bool remove_Motorcycle_by_id(string id);
        bool remove_SUV_by_id(string id);
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
            string input_id = "NA",
            string input_name = "NA",
            bool input_gender = false,
            short hour = 0,
            short day = 0,
            short month = 0,
            short year = 0,
            string input_email = "NA",
            string input_driver_license_id = "NA",
            string input_phone_number = "NA"
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

class CustomersData
{
    private:
        vector<Customer> *list_customers;
    
    public:
        CustomersData();
        ~CustomersData();

        short get_list_size();
        Customer *get_customer_at(short idx);
        Customer *get_customer_by_id(string id);
        void add_a_customer(Customer customer);
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
            string input_id = "NA",
            short input_status = 0,
            string input_customer_id = "NA",
            string input_customer_name = "NA",
            string input_vehicle_id = "NA",
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

class RentalContractsData
{
    private:
        vector<RentalContract> *list_contracts;
    
    public:
        RentalContractsData();
        ~RentalContractsData();

        short get_list_size();
        void add_a_contract(RentalContract contract);
        RentalContract *get_contract_by_id(string id);
};

class BookAndRent
{
    public:
        virtual void book_a_vehicle(
                    string vehicle_id, 
                    string customer_id,
                    short payment_method, 
                    Time pickup_time, 
                    Time return_time) = 0;
        virtual void sign_a_contract(string vehicle_id) = 0;
};

class CarRentalMgmt : public BookAndRent
{
    private:
        CarFleet *my_fleet;
        CustomersData *my_customers_data;
        RentalContractsData *my_rental_contracts_data;
   
    protected:
        RentalContract temp_contract;
   
    public:
        CarRentalMgmt();
        ~CarRentalMgmt();

        //VEHICLE
        short get_Sport_size();
        short get_Motorcycle_size();
        short get_SUV_size();

        Sport *get_Sport_by_id(string id);
        Motorcycle *get_Motorcycle_by_id(string id);
        SUV *get_SUV_by_id(string id);

        Sport *get_Sport_at(short idx);
        Motorcycle *get_Motorcycle_at(short idx);
        SUV *get_SUV_at(short idx);

        void add_Sport(Sport input_Sport);
        void add_Motorcycle(Motorcycle input_Motorcycle);
        void add_SUV(SUV input_SUV);

        bool remove_vehicle_by_id(string id);

        void service_fleet();

        //CUSTOMER
        void print_customers_data();
        Customer *get_customer_by_id(string id);
        void add_a_customer(Customer customer);

        //CONTRACT
        RentalContract *get_contract_by_id(string id);

        void book_a_vehicle(
                    string vehicle_id, 
                    string customer_id,
                    short payment_method, 
                    Time pickup_time, 
                    Time return_time
                    );
        void sign_a_contract(string vehicle_id);
};

#endif
