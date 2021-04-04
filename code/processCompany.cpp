#include "main.h"
#include "processCompany.h"

Time::Time(
        short input_hour,
        short input_day,
        short input_month,
        short input_year
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



ServiceHistory::ServiceHistory(
                short input_id,
                short input_hour,
                short input_day,
                short input_month,
                short input_year,
                float input_mileage,
                string input_engine,
                string input_transmission,
                string input_tires
        ) : id{input_id},
            mileage{input_mileage},
            engine{input_engine},
            transmission{input_transmission},
            tires{input_tires}
        {
            service_time.set_hour(input_hour);
            service_time.set_day(input_day);
            service_time.set_month(input_month);
            service_time.set_year(input_year);
        }

void ServiceHistory::set_id(short input_id)
{
    id = input_id;
}
void ServiceHistory::set_service_time(Time input_service_time)
{
    service_time = input_service_time;
}
void ServiceHistory::set_engine(string input_engine)
{
    engine = input_engine;
}
void ServiceHistory::set_transmission(string input_transmission)
{
    transmission = input_transmission;
}
void ServiceHistory::set_tires(string input_tires)
{
    tires = input_tires;
}

short ServiceHistory::get_id()
{
    return id;
}
Time ServiceHistory::get_service_time()
{
    return service_time;
}
float ServiceHistory::get_mileage()
{
    return mileage;
}
string ServiceHistory::get_engine()
{
    return engine;
}
string ServiceHistory::get_transmission()
{
    return transmission;
}
string ServiceHistory::get_tires()
{
    return tires;
}


Vehicle::Vehicle(
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
        ) : id{input_id},
            brand{input_brand},
            model{input_model},
            color{input_color},
            n_seats{input_n_seats},
            status{input_status},
            mileage{input_mileage}
{
    manufacture_time.set_hour(input_manufacture_hour);
    manufacture_time.set_day(input_manufacture_day);
    manufacture_time.set_month(input_manufacture_month);
    manufacture_time.set_year(input_manufacture_year);

    //service_history = new vector<ServiceHistory>();
};

Vehicle::~Vehicle()
{
    //delete service_history;
}

void Vehicle::set_id(const string input_id)
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
void Vehicle::add_mileage(const float input_mileage)
{
    mileage = mileage + input_mileage;
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
float Vehicle::get_mileage()
{
    return mileage;
}

float Vehicle::compute_mileage_between(short idx1, short idx2)
{
    if(idx1 < 0 || idx1 >= service_history->size() || idx2 < 0 || idx2 >= service_history->size())
    {
        return -1;
    }

    return abs(service_history->at(idx1).get_mileage() - service_history->at(idx2).get_mileage());
}



Sport::Sport(
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
            input_status,
            input_mileage
        }{};
Sport::~Sport()
{

}

void Sport::add_service_history(ServiceHistory input_history)
{
    if (mileage > 1000)
    {
        service_history->push_back(input_history);
    }
}

Motorcycle::Motorcycle(
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
            input_status,
            input_mileage
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

void Motorcycle::add_service_history(ServiceHistory input_history)
{
    if (mileage > 2000)
    {
        service_history->push_back(input_history);
        mileage = 0;
    }
}

SUV::SUV(
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
            input_status,
            input_mileage
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

void SUV::add_service_history(ServiceHistory input_history)
{
    if (mileage > 3000)
    {
        service_history->push_back(input_history);
        mileage = 0;
    }
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

short CarFleet::find_idx_of_id_Sport(string id)
{
    for (short i = 0; i < list_sport->size(); ++i)
    {
        if (list_sport->at(i).get_id() == id)
        {
            return i;
        }
    }

    return -1;
}
short CarFleet::find_idx_of_id_Motorcycle(string id)
{
    for (short i = 0; i < list_motorcycle->size(); ++i)
    {
        if (list_motorcycle->at(i).get_id() == id)
        {
            return i;
        }
    }

    return -1;
}
short CarFleet::find_idx_of_id_SUV(string id)
{
    for (short i = 0; i < list_SUV->size(); ++i)
    {
        if (list_SUV->at(i).get_id() == id)
        {
            return i;
        }
    }

    return -1;
}

short CarFleet::get_Sport_size()
{
    return list_sport->size();
}
short CarFleet::get_Motorcycle_size()
{
    return list_motorcycle->size();
}
short CarFleet::get_SUV_size()
{
    return list_SUV->size();
}

void CarFleet::add_Sport(Sport input_Sport)
{
    list_sport->push_back(input_Sport);
}
void CarFleet::add_Motorcycle(Motorcycle input_Motorcycle)
{
    list_motorcycle->push_back(input_Motorcycle);
}
void CarFleet::add_SUV(SUV input_SUV)
{
    list_SUV->push_back(input_SUV);
}


Sport *CarFleet::get_Sport_by_id(string id)
{
    short idx = find_idx_of_id_Sport(id);

    if (idx != -1)
    {
        return &list_sport->at(idx);
    }

    return NULL;
}
Motorcycle *CarFleet::get_Motorcycle_by_id(string id)
{
    short idx = find_idx_of_id_Motorcycle(id);

    if (idx != -1)
    {
        return &list_motorcycle->at(idx);
    }

    return NULL;
}
SUV *CarFleet::get_SUV_by_id(string id)
{
    short idx = find_idx_of_id_SUV(id);

    if (idx != -1)
    {
        return &list_SUV->at(idx);
    }

    return NULL;
}

void CarFleet::remove_Sport_by_id(string id)
{
    short idx = find_idx_of_id_Sport(id);
    
    if (idx != -1)
    {
        list_sport->erase(list_sport->begin() + idx);
    }
}
void CarFleet::remove_Motorcycle_by_id(string id)
{
    short idx = find_idx_of_id_Motorcycle(id);
    
    if (idx != -1)
    {
        list_motorcycle->erase(list_motorcycle->begin() + idx);
    }
}
void CarFleet::remove_SUV_by_id(string id)
{
    short idx = find_idx_of_id_SUV(id);
    
    if (idx != -1)
    {
        list_SUV->erase(list_SUV->begin() + idx);
    }
}

Customer::Customer(
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
        ) : id{input_id},
            name{input_name},
            gender{input_gender},
            email{input_email},
            driver_license_id{input_driver_license_id},
            phone_number{input_phone_number}
        {
            dob.set_hour(hour);
            dob.set_day(day);
            dob.set_month(month);
            dob.set_year(year);
        }
Customer::~Customer(){

}

void Customer::set_id(const string input_id)
{
    id = input_id;
}

void Customer::set_name(const string input_name)
{
    name = input_name;
}
void Customer::set_gender(const bool input_gender)
{
    gender = input_gender;
}
void Customer::set_dob(const Time input_dob)
{
    dob = input_dob;
}
void Customer::set_email(const string input_email)
{
    email = input_email;
}
void Customer::set_driver_license_id(const string input_driver_license_id)
{
    driver_license_id = input_driver_license_id;
}
void Customer::set_phone_number(const string input_phone_number)
{
    phone_number = input_phone_number;
}

string Customer::get_id()
{
    return id;
}
string Customer::get_name()
{
    return name;
}
bool Customer::get_gender()
{
    return gender;
}
Time Customer::get_dob()
{
    return dob;
}
string Customer::get_email()
{
    return email;
}
string Customer::get_driver_license_id()
{
    return driver_license_id;
}
string Customer::get_phone_number()
{
    return phone_number;
}

RentalContract::RentalContract(
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

        ) : id{input_id},
            status{input_status},
            customer_id{input_customer_id},
            customer_name{input_customer_name},
            vehicle_id{input_vehicle_id},
            vehicle_model{input_vehicle_model},
            payment_method{input_payment_method}

        {
            pickup_time.set_hour(input_pickup_hour);
            pickup_time.set_day(input_pickup_day);
            pickup_time.set_month(input_pickup_month);
            pickup_time.set_year(input_pickup_year);

            return_time.set_hour(input_return_hour);
            return_time.set_day(input_return_day);
            return_time.set_month(input_return_month);
            return_time.set_year(input_return_year);
        }
RentalContract::~RentalContract(){

}

void RentalContract::set_id(const string input_id)
{
    id = input_id;
}
void RentalContract::set_status(const short input_status)
{
    status = input_status;
}

void RentalContract::set_pickup_time(const Time input_pickup_time)
{
    pickup_time = input_pickup_time;
}
void RentalContract::set_return_time(const Time input_return_time)
{
    return_time = input_return_time;
}
void RentalContract::set_payment_method(const short input_payment_method)
{
    payment_method = input_payment_method;
}

string RentalContract::get_id()
{
    return id;
}
short RentalContract::get_status()
{
    return status;
}
string RentalContract::get_customer_id()
{
    return customer_id;
}
string RentalContract::get_customer_name()
{
    return customer_name;
}
string RentalContract::get_vehicle_id()
{
    return vehicle_id;
}
string RentalContract::get_vehicle_model()
{
    return vehicle_model;
}
Time RentalContract::get_pickup_time()
{
    return pickup_time;
}
Time RentalContract::get_return_time()
{
    return return_time;
}
short RentalContract::get_payment_method()
{
    return payment_method;
}



CarRentalMgmt::CarRentalMgmt()
{
    my_fleet = new CarFleet();
    list_customers = new vector<Customer>();
    list_contracts = new vector<RentalContract>();
}
CarRentalMgmt::~CarRentalMgmt()
{
    delete my_fleet;
    delete list_customers;
    delete list_contracts;
}

Sport *CarRentalMgmt::get_Sport_by_id(string id)
{
    return my_fleet->get_Sport_by_id(id);
}
Motorcycle *CarRentalMgmt::get_Motorcycle_by_id(string id)
{
    return my_fleet->get_Motorcycle_by_id(id);
}
SUV *CarRentalMgmt::get_SUV_by_id(string id)
{
    return my_fleet->get_SUV_by_id(id);
}

void CarRentalMgmt::add_Sport(Sport input_Sport)
{
    my_fleet->add_Sport(input_Sport);
}
void CarRentalMgmt::add_Motorcycle(Motorcycle input_Motorcycle)
{
    my_fleet->add_Motorcycle(input_Motorcycle);
}
void CarRentalMgmt::add_SUV(SUV input_SUV)
{
    my_fleet->add_SUV(input_SUV);
}

void CarRentalMgmt::remove_vehicle_by_id(string id)
{
    if (id.at(0) == 'S')
    {
        my_fleet->remove_Sport_by_id(id);
    }

    else if (id.at(0) == 'M')
    {
        my_fleet->remove_Motorcycle_by_id(id);
    }

    else if (id.at(0) == 'U')
    {
        my_fleet->remove_SUV_by_id(id);
    }
}

void CarRentalMgmt::service_fleet()
{
    
}

void CarRentalMgmt::book_a_vehicle()
{

}
void CarRentalMgmt::sign_a_contract()
{

}