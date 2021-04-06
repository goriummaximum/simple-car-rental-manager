#include "main.h"
#include "processCompany.h"

int main()
{
    CarRentalMgmt *car_manager = new CarRentalMgmt();

    car_manager->add_Motorcycle(Motorcycle("M0", "Honda", "Wave Alpha", "red", 2, 0, 1, 1, 2015, false, 0, false));
    car_manager->add_Motorcycle(Motorcycle("M1", "Yamaha", "Exciter", "blue", 2, 0, 1, 1, 2017, false, 0, false));
    car_manager->add_Sport(Sport("S0", "Lambo", "2013", "blue", 2, 0, 22, 4, 2013, false, 0));
    car_manager->add_SUV(SUV("U0", "Toyota", "Camri", "white", 2, 0, 22, 4, 2014, false, 0));

    car_manager->get_Motorcycle_by_id("M0")->add_mileage(100);
    car_manager->get_Motorcycle_by_id("M1")->add_mileage(200);

    car_manager->add_a_customer(Customer("00", "Ho Hoang Thien Long","NA", 1, 29, 2, 2000, "NA", "09123", "123"));
    car_manager->add_a_customer(Customer("01", "Tien Doan","NA", 1, 29, 2, 2000, "NA", "2435345", "34"));
    car_manager->add_a_customer(Customer("02", "Tinh Nguyen","NA", 1, 29, 2, 2000, "NA", "087929123", "874"));

    if (car_manager->get_customer_by_id("00") == NULL)
    {
        cout << "0";
    }

    delete car_manager;

    return 0;
}