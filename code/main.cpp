#include "main.h"
#include "processCompany.h"

int main()
{
    CarRentalMgmt *car_manager = new CarRentalMgmt();

    Motorcycle my_motor("123");

    car_manager->add_Motorcycle(my_motor);
    car_manager->get_Motorcycle_by_id("123")->set_brand("Ford");
    cout << car_manager->get_Motorcycle_by_id("123")->get_brand();

    delete car_manager;

    return 0;
}