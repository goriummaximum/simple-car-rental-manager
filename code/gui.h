#ifndef GUI_H_
#define GUI_H_

#include "processCompany.h"

enum state {
    MAIN_MENU,
    ACCESS_CAR_FLEET,
    PRINT_CAR_FLEET,
    ACCESS_A_VEHICLE,
    ADD_A_VEHICLE,
    REMOVE_A_VEHICLE,
    ACCESS_CUSTOMERS_DATA,
    ACCESS_CONTRACTS_DATA,
    BOOK,
    SIGN,
    EXIT_PROGRAM
};

class GUI
{
    private:
        state st;
        state process_MAIN_MENU();
        state process_ACCESS_CAR_FLEET();
        state process_PRINT_CAR_FLEET(CarRentalMgmt *car_manager);
        state process_ACCESS_A_VEHICLE();
        state process_ADD_A_VEHICLE(CarRentalMgmt *car_manager);
        state process_REMOVE_A_VEHICLE();
        state process_ACCESS_CUSTOMERS_DATA();
        state process_ACCESS_CONTRACTS_DATA();
        state process_BOOK();
        state process_SIGN();
        state process_EXIT_PROGRAM();

    public:
        GUI();
        ~GUI();
        void run(CarRentalMgmt *car_manager);
};

#endif