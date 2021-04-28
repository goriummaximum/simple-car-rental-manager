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



ServiceRecord::ServiceRecord(
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

void ServiceRecord::set_id(short input_id)
{
    id = input_id;
}
void ServiceRecord::set_service_time(Time input_service_time)
{
    service_time = input_service_time;
}
void ServiceRecord::set_mileage(float input_mileage)
{
    mileage = input_mileage;
}
void ServiceRecord::set_engine(string input_engine)
{
    engine = input_engine;
}
void ServiceRecord::set_transmission(string input_transmission)
{
    transmission = input_transmission;
}
void ServiceRecord::set_tires(string input_tires)
{
    tires = input_tires;
}

short ServiceRecord::get_id()
{
    return id;
}
Time ServiceRecord::get_service_time()
{
    return service_time;
}
float ServiceRecord::get_mileage()
{
    return mileage;
}
string ServiceRecord::get_engine()
{
    return engine;
}
string ServiceRecord::get_transmission()
{
    return transmission;
}
string ServiceRecord::get_tires()
{
    return tires;
}

ServiceRecord ServiceRecord::operator-(const ServiceRecord service2)
{
    ServiceRecord result;
    result.set_mileage(abs(service2.mileage - mileage));
    return result;
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
};

Vehicle::~Vehicle()
{

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
    if(idx1 < 0 || idx1 >= service_history.size() || idx2 < 0 || idx2 >= service_history.size())
    {
        return -1;
    }

    ServiceRecord service1 = service_history.at(idx1);
    ServiceRecord service2 = service_history.at(idx2);
    ServiceRecord mileage_between = service2 - service1; //Operator overloading

    return mileage_between.get_mileage();
}

json Vehicle::export_json_record(ServiceRecord input_record)
{
    json j_out;
    j_out["id"] = input_record.get_id();
    j_out["service_time"]["hour"] = input_record.get_service_time().get_hour();
    j_out["service_time"]["day"] = input_record.get_service_time().get_day();
    j_out["service_time"]["month"] = input_record.get_service_time().get_month();
    j_out["service_time"]["year"] = input_record.get_service_time().get_year();
    j_out["mileage"] = input_record.get_mileage();
    j_out["engine"] = input_record.get_engine();
    j_out["transmission"] = input_record.get_transmission();
    j_out["tires"] = input_record.get_tires();

    return j_out;
}

json Vehicle::export_json_record_by_id(short id)
{
    json j_out;
    j_out[id] = {};
    short i;
    for (i = 0; i < service_history.size(); ++i)
    {
        if (service_history.at(i).get_id() == id)
        {
            j_out[id] = export_json_record(service_history.at(i));
            break;
        }
    }   

    export_json_to_file(id + "_" + to_string(i) + ".json", j_out);

    return j_out;
}

json Vehicle::export_json_record_all()
{
    json j_out;
    j_out[id] = {};
    for (short i = 0; i < service_history.size(); ++i)
    {
        j_out[id].push_back(export_json_record(service_history.at(i)));
    }

    export_json_to_file(id + "_all.json", j_out);

    return j_out;
}

void Vehicle::export_json_to_file(string file_name, json j_out)
{
    ofstream out_file(file_name);
    out_file << j_out.dump(4) << endl;
    out_file.close();
}

ServiceRecord *Vehicle::get_service_record_at(short idx)
{
    if (idx >= service_history.size())
    {
        return NULL;
    }

    return &service_history.at(idx);
}

ServiceRecord *Vehicle::get_service_record_by_id(short id)
{
    for (short i = 0; i < service_history.size(); ++i)
    {
        if (service_history.at(i).get_id() == id)
        {
            return &service_history.at(i);
        }
    }

    return NULL;
}

short Vehicle::get_service_history_size()
{
    return service_history.size();
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

bool Sport::add_service_record()
{
    float mileage = 0;
    if (service_history.size() == 0)
    {
        mileage = get_mileage();
    }

    else
    {
        mileage = abs(get_mileage() - service_history.back().get_mileage());
    }

    if (status == 0)
    {
        ServiceRecord record;
        record.set_id(service_history.size());

        time_t now = time(0);
        tm *ltm = localtime(&now);
        record.set_service_time(Time(5+ltm->tm_hour, ltm->tm_mday, 1 + ltm->tm_mon, 1900 + ltm->tm_year));

        record.set_mileage(mileage);

        if (mileage >= 500 && mileage < 1000)
        {
            record.set_engine("minor");
            record.set_tires("adjustment");
            record.set_transmission("minor");
        }

        else if (mileage >= 1000 && mileage < 2000)
        {
            record.set_engine("oil change");
            record.set_tires("replacement");
            record.set_transmission("fluid change");
        }

        else if (mileage >= 2000)
        {
            record.set_engine("major");
            record.set_tires("replacement");
            record.set_transmission("overhaul");
        }

        service_history.push_back(record);

        return true;
    }

    return false;
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

bool Motorcycle::get_is_helmet_included()
{
    return is_helmet_included;
}

bool Motorcycle::add_service_record()
{
    float mileage = 0;
    if (service_history.size() == 0)
    {
        mileage = get_mileage();
    }

    else
    {
        mileage = abs(get_mileage() - service_history.back().get_mileage());
    }

    if (status == 0)
    {
        ServiceRecord record;
        record.set_id(service_history.size());

        time_t now = time(0);
        tm *ltm = localtime(&now);
        record.set_service_time(Time(5+ltm->tm_hour, ltm->tm_mday, 1 + ltm->tm_mon, 1900 + ltm->tm_year));

        record.set_mileage(mileage);

        if (mileage >= 1000 && mileage < 3000)
        {
            record.set_engine("minor");
            record.set_tires("adjustment");
            record.set_transmission("minor");
        }

        else if (mileage >= 3000 && mileage < 5000)
        {
            record.set_engine("oil change");
            record.set_tires("adjustment");
            record.set_transmission("fluid change");
        }

        else if (mileage >= 5000)
        {
            record.set_engine("major");
            record.set_tires("replacement");
            record.set_transmission("overhaul");
        }

        service_history.push_back(record);

        return true;
    }

    return false;
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

bool SUV::get_is_bag_included()
{
    return is_bag_included;
}

bool SUV::add_service_record()
{
    float mileage = 0;
    if (service_history.size() == 0)
    {
        mileage = get_mileage();
    }

    else
    {
        mileage = abs(get_mileage() - service_history.back().get_mileage());
    }

    if (status == 0)
    {
        ServiceRecord record;
        record.set_id(service_history.size());

        time_t now = time(0);
        tm *ltm = localtime(&now);
        record.set_service_time(Time(5+ltm->tm_hour, ltm->tm_mday, 1 + ltm->tm_mon, 1900 + ltm->tm_year));

        record.set_mileage(mileage);

        if (mileage >= 1000 && mileage < 2000)
        {
            record.set_engine("minor");
            record.set_tires("adjustment");
            record.set_transmission("minor");
        }

        else if (mileage >= 2000 && mileage < 4000)
        {
            record.set_engine("oil change");
            record.set_tires("adjustment");
            record.set_transmission("fluid change");
        }

        else if (mileage >= 4000)
        {
            record.set_engine("major");
            record.set_tires("replacement");
            record.set_transmission("overhaul");
        }

        service_history.push_back(record);

        return true;
    }

    return false;
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


Sport *CarFleet::get_Sport_at(short idx)
{
    if (idx >= list_sport->size())
    {
        return NULL;
    }

    return &list_sport->at(idx);
}

Motorcycle *CarFleet::get_Motorcycle_at(short idx)
{
    if (idx >= list_motorcycle->size())
    {
        return NULL;
    }

    return &list_motorcycle->at(idx);
}

SUV *CarFleet::get_SUV_at(short idx)
{
    if (idx >= list_SUV->size())
    {
        return NULL;
    }

    return &list_SUV->at(idx);
}

Sport *CarFleet::get_Sport_by_id(string id)
{
    for (short i = 0; i < list_sport->size(); ++i)
    {
        if (list_sport->at(i).get_id() == id)
        {
            return &list_sport->at(i);
        }
    }

    return NULL;
}
Motorcycle *CarFleet::get_Motorcycle_by_id(string id)
{
    for (short i = 0; i < list_motorcycle->size(); ++i)
    {
        if (list_motorcycle->at(i).get_id() == id)
        {
            return &list_motorcycle->at(i);
        }
    }

    return NULL;
}
SUV *CarFleet::get_SUV_by_id(string id)
{
    for (short i = 0; i < list_SUV->size(); ++i)
    {
        if (list_SUV->at(i).get_id() == id)
        {
            return &list_SUV->at(i);
        }
    }

    return NULL;
}

bool CarFleet::remove_Sport_by_id(string id)
{
    for (short i = 0; i < list_sport->size(); ++i)
    {
        if (list_sport->at(i).get_id() == id)
        {
            list_sport->erase(list_sport->begin() + i);
            return true;
        }
    }

    return false;
}
bool CarFleet::remove_Motorcycle_by_id(string id)
{
    for (short i = 0; i < list_motorcycle->size(); ++i)
    {
        if (list_motorcycle->at(i).get_id() == id)
        {
            list_motorcycle->erase(list_motorcycle->begin() + i);
            return true;
        }
    }
    return false;
}
bool CarFleet::remove_SUV_by_id(string id)
{
    for (short i = 0; i < list_SUV->size(); ++i)
    {
        if (list_SUV->at(i).get_id() == id)
        {
            list_SUV->erase(list_SUV->begin() + i);
            return true;
        }
    }
    return false;
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


CustomersData::CustomersData()
{
    list_customers = new vector<Customer>();
}
CustomersData::~CustomersData()
{
    delete list_customers;
}

Customer *CustomersData::get_customer_by_id(string id)
{
    for (short i = 0; i < list_customers->size(); i++)
    {
        if (list_customers->at(i).get_id() == id)
        {
            return &list_customers->at(i);
        }
    }

    return NULL;
}

void CustomersData::add_a_customer(Customer customer)
{
    list_customers->push_back(customer);
}

Customer *CustomersData::get_customer_at(short idx)
{
    if (idx >= list_customers->size())
    {
        return NULL;
    }

    return &list_customers->at(idx);
}

short CustomersData::get_list_size()
{
    return list_customers->size();
}

bool CustomersData::remove_a_customer_by_id(string id)
{
    for (short i = 0; i < list_customers->size(); i++)
    {
        if (list_customers->at(i).get_id() == id)
        {
            list_customers->erase(list_customers->begin() + i);
            return true;
        }
    }

    return false;
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



RentalContractsData::RentalContractsData()
{
    list_contracts = new vector<RentalContract>();
}
RentalContractsData::~RentalContractsData()
{
    delete list_contracts;
}

short RentalContractsData::get_list_size()
{
    return list_contracts->size();
}


void RentalContractsData::add_a_contract(RentalContract contract)
{
    list_contracts->push_back(contract);
}

RentalContract *RentalContractsData::get_contract_by_id(string id)
{
    for (short i = 0; i < list_contracts->size(); i++)
    {
        if (list_contracts->at(i).get_id() == id)
        {
            return &list_contracts->at(i);
        }
    }

    return NULL;
}

RentalContract *RentalContractsData::get_contract_at(short idx)
{
    if (idx >= list_contracts->size())
    {
        return NULL;
    }

    return &list_contracts->at(idx);
}

CarRentalMgmt::CarRentalMgmt()
{
    my_fleet = new CarFleet();
    my_customers_data = new CustomersData();
    my_rental_contracts_data = new RentalContractsData();
}
CarRentalMgmt::~CarRentalMgmt()
{
    delete my_fleet;
    delete my_customers_data;
    delete my_rental_contracts_data;
}

short CarRentalMgmt::get_Sport_size()
{
    return my_fleet->get_Sport_size();
}
short CarRentalMgmt::get_Motorcycle_size()
{
    return my_fleet->get_Motorcycle_size();
}
short CarRentalMgmt::get_SUV_size()
{
    return my_fleet->get_SUV_size();
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

Sport *CarRentalMgmt::get_Sport_at(short idx)
{
    return my_fleet->get_Sport_at(idx);
}

Motorcycle *CarRentalMgmt::get_Motorcycle_at(short idx)
{
    return my_fleet->get_Motorcycle_at(idx);
}

SUV *CarRentalMgmt::get_SUV_at(short idx)
{
    return my_fleet->get_SUV_at(idx);
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

bool CarRentalMgmt::remove_vehicle_by_id(string id)
{
    if (id.at(0) == 'S')
    {
        return my_fleet->remove_Sport_by_id(id);
    }

    else if (id.at(0) == 'M')
    {
        return my_fleet->remove_Motorcycle_by_id(id);
    }

    else if (id.at(0) == 'U')
    {
        return my_fleet->remove_SUV_by_id(id);
    }
    return false;
}


void CarRentalMgmt::service_fleet()
{
    for (short i = 0; i < my_fleet->get_Sport_size(); ++i)
    {
        my_fleet->get_Sport_at(i)->add_service_record();
    }

    for (short i = 0; i < my_fleet->get_Motorcycle_size(); ++i)
    {
        my_fleet->get_Motorcycle_at(i)->add_service_record();
    }

    for (short i = 0; i < my_fleet->get_SUV_size(); ++i)
    {
        my_fleet->get_SUV_at(i)->add_service_record();
    }
}

Customer *CarRentalMgmt::get_customer_at(short idx)
{
    return my_customers_data->get_customer_at(idx);
}

Customer *CarRentalMgmt::get_customer_by_id(string id)
{
    return my_customers_data->get_customer_by_id(id);
}

void CarRentalMgmt::add_a_customer(Customer customer)
{
    my_customers_data->add_a_customer(customer);
}

short CarRentalMgmt::get_customers_size()
{
    return my_customers_data->get_list_size();
}

bool CarRentalMgmt::remove_a_customer_by_id(string id)
{
    return my_customers_data->remove_a_customer_by_id(id);
}

RentalContract *CarRentalMgmt::get_contract_by_id(string id)
{
    return my_rental_contracts_data->get_contract_by_id(id);
}

RentalContract *CarRentalMgmt::get_contract_at(short idx)
{
    return my_rental_contracts_data->get_contract_at(idx);
}

short CarRentalMgmt::get_contracts_size()
{
    return my_rental_contracts_data->get_list_size();
}

bool CarRentalMgmt::book_a_vehicle(
                string vehicle_id, 
                string customer_id, 
                short payment_method, 
                Time pickup_time, 
                Time return_time
                )
{

    string vehicle_name;
    string customer_name;

    Customer *cus = my_customers_data->get_customer_by_id(customer_id);
    if (cus == NULL) return false;
    customer_name = cus->get_name();

    if (vehicle_id[0] == 'S')
    {
        Sport *vehicle = my_fleet->get_Sport_by_id(vehicle_id);
        if (vehicle == NULL) return false;
        vehicle_name = vehicle->get_brand() + vehicle->get_model();
    }

    else if (vehicle_id[0] == 'M')
    {
        Motorcycle *vehicle = my_fleet->get_Motorcycle_by_id(vehicle_id);
        if (vehicle == NULL) return false;
        vehicle_name = vehicle->get_brand() + vehicle->get_model();
    }
    
    else if (vehicle_id[0] == 'U')
    {
        SUV *vehicle = my_fleet->get_SUV_by_id(vehicle_id);
        if (vehicle == NULL) return false;
        vehicle_name = vehicle->get_brand() + " " + vehicle->get_model();
    }
    
    temp_contract = RentalContract(
            to_string(my_rental_contracts_data->get_list_size() + 1),
            1,
            customer_id,
            customer_name,
            vehicle_id,
            vehicle_name,
            pickup_time.get_hour(),
            pickup_time.get_day(),
            pickup_time.get_month(),
            pickup_time.get_year(),
            return_time.get_hour(),
            return_time.get_day(),
            return_time.get_month(),
            return_time.get_year()
            );
    
    return true;
}
void CarRentalMgmt::sign_a_contract(string vehicle_id)
{
    if (vehicle_id[0] == 'S')
    {
        Sport *vehicle = my_fleet->get_Sport_by_id(vehicle_id);
        if (vehicle == NULL) return;
        vehicle->set_status(1);
    }

    else if (vehicle_id[0] == 'M')
    {
        Motorcycle *vehicle = my_fleet->get_Motorcycle_by_id(vehicle_id);
        if (vehicle == NULL) return;
        vehicle->set_status(1);
    }
    
    else if (vehicle_id[0] == 'U')
    {
        SUV *vehicle = my_fleet->get_SUV_by_id(vehicle_id);
        if (vehicle == NULL) return;
        vehicle->set_status(1);
    }

    my_rental_contracts_data->add_a_contract(temp_contract);
}