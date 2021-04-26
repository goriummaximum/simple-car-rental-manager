#include "main.h"
#include "processCompany.h"
#include "gui.h"

int main()
{
    CarRentalMgmt *car_manager = new CarRentalMgmt();
    GUI *gui = new GUI();

    gui->run(car_manager);

    delete car_manager;
    delete gui;

    return 0;
}