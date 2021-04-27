#include "main.h"
#include "processCompany.h"
#include "tui.h"

int main()
{
    CarRentalMgmt *car_manager = new CarRentalMgmt();
    TUI *tui = new TUI();

    tui->run(car_manager);

    delete car_manager;
    delete tui;

    return 0;
}