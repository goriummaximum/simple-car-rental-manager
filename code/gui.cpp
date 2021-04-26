#include "main.h"
#include "gui.h"

GUI::GUI()
{
    st = MAIN_MENU;
}

GUI::~GUI()
{

}

void GUI::run(CarRentalMgmt *car_manager)
{
    while (st != EXIT_PROGRAM)
    {
        switch (st)
        {
            case MAIN_MENU:
                st = process_MAIN_MENU();
                break;
            
            case ACCESS_CAR_FLEET:
                st = process_ACCESS_CAR_FLEET();
                break;
            
            case ACCESS_A_VEHICLE:
                st = process_ACCESS_A_VEHICLE();
                break;
            
            case ADD_A_VEHICLE:
                st = process_ADD_A_VEHICLE(car_manager);
                break;

            case REMOVE_A_VEHICLE:
                st = process_REMOVE_A_VEHICLE();
                break;   

            case PRINT_CAR_FLEET:
                st = process_PRINT_CAR_FLEET(car_manager);
                break;

            case ACCESS_CUSTOMERS_DATA:
                st = process_ACCESS_CUSTOMERS_DATA();
                break;

            case ACCESS_CONTRACTS_DATA:
                st = process_ACCESS_CONTRACTS_DATA();
                break;

            case BOOK:
                st = process_BOOK();
                break;

            case EXIT_PROGRAM:
                st = process_EXIT_PROGRAM();
                break;
                
            default:
                st = MAIN_MENU;
                break;
        }
    }

    system("clear");
    cout << "Good bye!" << endl;
    sleep(1);
    system("clear");
}

state GUI::process_MAIN_MENU()
{
    system("clear");
    cout << "----------" << endl;
    cout << "MAIN MENU" << endl;
    cout << "----------" << endl << endl;

    cout << "1. Access car fleet" << endl;
    cout << "2. Access customers data" << endl;
    cout << "3. Access contracts data" << endl;
    cout << "4. Book a vehicle" << endl;
    cout << "5. Exit program" << endl << endl;

    cout << "Please choose an option: ";
    int option = 0;
    cin >> option;

    switch (option)
    {
        case 1:
            return ACCESS_CAR_FLEET;
        case 2:
            return ACCESS_CUSTOMERS_DATA;
        case 3:
            return ACCESS_CONTRACTS_DATA;
        case 4:
            return BOOK;
        case 5:
            return EXIT_PROGRAM;
        default:
            cout << "Wrong input!. Please input again" << endl;
            sleep(1);
            return MAIN_MENU;
    }
}

state GUI::process_ACCESS_CAR_FLEET()
{
    system("clear");
    cout << "----------" << endl;
    cout << "CAR FLEET" << endl;
    cout << "----------" << endl << endl;

    cout << "1. Print car fleet data" << endl;
    cout << "2. Access a vehicle" << endl;
    cout << "3. Add a vehicle" << endl;
    cout << "4. Remove a vehicle" << endl;
    cout << "5. Return back" << endl << endl;

    cout << "Please choose an option: ";
    int option = 0;
    cin >> option;

    switch (option)
    {
        case 1:
            return PRINT_CAR_FLEET;
        case 2:
            return ACCESS_A_VEHICLE;
        case 3:
            return ADD_A_VEHICLE;
        case 4:
            return REMOVE_A_VEHICLE;
        case 5:
            return MAIN_MENU;
        default:
            cout << "Wrong input!. Please input again" << endl;
            sleep(1);
            return ACCESS_CAR_FLEET;
    }
}

state GUI::process_PRINT_CAR_FLEET(CarRentalMgmt *car_manager)
{
    system("clear");
    cout << "----------" << endl;
    cout << "PRINT CAR FLEET" << endl;
    cout << "----------" << endl << endl;

    cout << "Total vehicle: " << car_manager->get_Motorcycle_size() + car_manager->get_Sport_size() + car_manager->get_SUV_size() << endl;
    cout << "Total Sport cars: " <<  car_manager->get_Sport_size() << endl;
    cout << "Total Motorcycle: " <<  car_manager->get_Motorcycle_size() << endl;
    cout << "Total SUV car: " <<  car_manager->get_SUV_size() << endl << endl;

    cout << "----------" << endl;
    cout << "Sport" << endl;
    cout << "----------" << endl;

    cout << "No" 
        << setw(5) << "ID"
        << setw(10) << "Status"
        << setw(10) << "Brand"
        << setw(20) << "Model"
        << setw(10) << "color"
        << setw(20) << "manufacturing time"
        << setw(10) << "mileage" << endl;

    for (short i = 0; i < car_manager->get_Sport_size(); i++)
    {
        Sport *vehicle_temp = car_manager->get_Sport_at(i);
        cout << i + 1 
            << setw(5) << vehicle_temp->get_id()
            << setw(10) << vehicle_temp->get_status()
            << setw(10) << vehicle_temp->get_brand()
            << setw(20) << vehicle_temp->get_model()
            << setw(10) << vehicle_temp->get_color()
            << setw(20) << to_string(vehicle_temp->get_manufacture_time().get_day()) 
                            + "/" + to_string(vehicle_temp->get_manufacture_time().get_month())
                            + "/" + to_string(vehicle_temp->get_manufacture_time().get_year())
            << setw(10) << vehicle_temp->get_mileage() << endl;
    }

    cout << "\n----------" << endl;
    cout << "Motorcycle" << endl;
    cout << "----------" << endl << endl;
    cout << "No" 
        << setw(5) << "ID"
        << setw(10) << "Status"
        << setw(10) << "Brand"
        << setw(20) << "Model"
        << setw(10) << "color"
        << setw(20) << "manufacturing time"
        << setw(10) << "mileage"
        << setw(10) << "Helmet?" << endl;

    for (short i = 0; i < car_manager->get_Motorcycle_size(); i++)
    {
        Motorcycle *vehicle_temp = car_manager->get_Motorcycle_at(i);
        cout << i + 1 
            << setw(5) << vehicle_temp->get_id()
            << setw(10) << vehicle_temp->get_status()
            << setw(10) << vehicle_temp->get_brand()
            << setw(20) << vehicle_temp->get_model()
            << setw(10) << vehicle_temp->get_color()
            << setw(20) << to_string(vehicle_temp->get_manufacture_time().get_day()) 
                            + "/" + to_string(vehicle_temp->get_manufacture_time().get_month())
                            + "/" + to_string(vehicle_temp->get_manufacture_time().get_year())
            << setw(10) << vehicle_temp->get_mileage()
            << setw(10) << vehicle_temp->get_is_helmet_included() << endl;
    }

    cout << "\n----------" << endl;
    cout << "SUV" << endl;
    cout << "----------" << endl << endl;
    cout << "No" 
        << setw(5) << "ID"
        << setw(10) << "Status"
        << setw(10) << "Brand"
        << setw(20) << "Model"
        << setw(10) << "color"
        << setw(20) << "manufacturing time"
        << setw(10) << "mileage"
        << setw(10) << "Bag?" << endl;

    for (short i = 0; i < car_manager->get_SUV_size(); i++)
    {
        SUV *vehicle_temp = car_manager->get_SUV_at(i);
        cout << i + 1 
            << setw(5) << vehicle_temp->get_id()
            << setw(10) << vehicle_temp->get_status()
            << setw(10) << vehicle_temp->get_brand()
            << setw(20) << vehicle_temp->get_model()
            << setw(10) << vehicle_temp->get_color()
            << setw(20) << to_string(vehicle_temp->get_manufacture_time().get_day()) 
                            + "/" + to_string(vehicle_temp->get_manufacture_time().get_month())
                            + "/" + to_string(vehicle_temp->get_manufacture_time().get_year())
            << setw(10) << vehicle_temp->get_mileage()
            << setw(10) << vehicle_temp->get_is_bag_included() << endl;
    }

    cout << "\n1. Return back" << endl << endl;

    cout << "Please choose an option: ";
    int option = 0;
    cin >> option;

    return ACCESS_CAR_FLEET;
}

state GUI::process_ACCESS_A_VEHICLE()
{
    return ACCESS_CAR_FLEET;
}

state GUI::process_ADD_A_VEHICLE(CarRentalMgmt *car_manager)
{
    system("clear");
    cout << "----------" << endl;
    cout << "ADD A VEHICLE" << endl;
    cout << "----------" << endl << endl;

    cout << "1. Add a Sport car" << endl;
    cout << "2. Add a Motorcycle" << endl;
    cout << "3. Add a SUV" << endl << endl;

    cout << "Please choose an option: ";
    int option = 0;
    cin >> option;

    short id;
    cout << endl << "ID (int): ";
    cin >> id;

    string brand;
    cout << "Brand (string): ";
    cin.ignore();
    getline(cin, brand);

    string model;
    cout << "Model (string): ";
    getline(cin, model);

    string color;
    cout << "Color (string): ";
    getline(cin, color);

    short seats;
    cout << "Number of seats (int): ";
    cin >> seats;

    short hour;
    cout << "Manufacturing hour (int): ";
    cin >> hour;

    short day;
    cout << "Manufacturing day (int): ";
    cin >> day;

    short month;
    cout << "Manufacturing month (int): ";
    cin >> month;

    short year;
    cout << "Manufacturing year (int): ";
    cin >> year;

    float mileage;
    cout << "Mileage (float): ";
    cin >> mileage;

    switch (option)
    {
        case 1:
        car_manager->add_Sport(Sport("S" + to_string(id), brand, model, color, seats, hour, day, month, year, false, mileage));
            break;

        case 2:
        bool helmet;
        cout <<"Include helmet? (bool): ";
        cin >> helmet;
        car_manager->add_Motorcycle(Motorcycle("M" + to_string(id), brand, model, color, seats, hour, day, month, year, false, mileage, helmet));
            break;

        case 3:
        bool bag;
        cout <<"Include bag? (bool): ";
        cin >> bag;
        car_manager->add_SUV(SUV("U" + to_string(id), brand, model, color, seats, hour, day, month, year, false, mileage, bag));
            break;

        default:
            break;
    }

    return ACCESS_CAR_FLEET;
}

state GUI::process_REMOVE_A_VEHICLE()
{
    return ACCESS_CAR_FLEET;
}

state GUI::process_ACCESS_CUSTOMERS_DATA()
{
    return MAIN_MENU;
}

state GUI::process_ACCESS_CONTRACTS_DATA()
{
    return MAIN_MENU;
}

state GUI::process_BOOK()
{
    return MAIN_MENU;
}

state GUI::process_EXIT_PROGRAM()
{
    return EXIT_PROGRAM;
}
