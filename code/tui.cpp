#include "main.h"
#include "tui.h"

TUI::TUI()
{
    st = MAIN_MENU;
}

void TUI::run(CarRentalMgmt *car_manager)
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
                st = process_ACCESS_A_VEHICLE(car_manager);
                break;

            case ADD_A_VEHICLE:
                st = process_ADD_A_VEHICLE(car_manager);
                break;

            case REMOVE_A_VEHICLE:
                st = process_REMOVE_A_VEHICLE(car_manager);
                break;   

            case PRINT_CAR_FLEET:
                st = process_PRINT_CAR_FLEET(car_manager);
                break;

            case ACCESS_CUSTOMERS_DATA:
                st = process_ACCESS_CUSTOMERS_DATA();
                break;

            case PRINT_CUSTOMERS:
                st = process_PRINT_CUSTOMERS(car_manager);
                break;

            case ADD_A_CUSTOMER:
                st = process_ADD_A_CUSTOMER(car_manager);
                break;

            case REMOVE_A_CUSTOMER:
                st = process_REMOVE_A_CUSTOMER(car_manager);
                break;

            case ACCESS_CONTRACTS_DATA:
                st = process_ACCESS_CONTRACTS_DATA();
                break;

            case BOOK:
                st = process_BOOK();
                break;

            case SERVICE_FLEET:
                st = process_SERVICE_FLEET(car_manager);
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

state TUI::process_MAIN_MENU()
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

state TUI::process_ACCESS_CAR_FLEET()
{
    system("clear");
    cout << "----------" << endl;
    cout << "CAR FLEET" << endl;
    cout << "----------" << endl << endl;

    cout << "1. Print car fleet data" << endl;
    cout << "2. Access a vehicle" << endl;
    cout << "3. Add a vehicle" << endl;
    cout << "4. Remove a vehicle" << endl;
    cout << "5. Service fleet" << endl;
    cout << "6. Return back" << endl << endl;

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
            return SERVICE_FLEET;
        case 6:
            return MAIN_MENU;
        default:
            cout << "Wrong input!. Please input again" << endl;
            sleep(1);
            return ACCESS_CAR_FLEET;
    }
}

state TUI::process_PRINT_CAR_FLEET(CarRentalMgmt *car_manager)
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
            << setw(10) << ((vehicle_temp->get_status() == true) ? "UA" : "A")
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
            << setw(10) << ((vehicle_temp->get_status() == true) ? "UA" : "A")
            << setw(10) << vehicle_temp->get_brand()
            << setw(20) << vehicle_temp->get_model()
            << setw(10) << vehicle_temp->get_color()
            << setw(20) << to_string(vehicle_temp->get_manufacture_time().get_day()) 
                            + "/" + to_string(vehicle_temp->get_manufacture_time().get_month())
                            + "/" + to_string(vehicle_temp->get_manufacture_time().get_year())
            << setw(10) << vehicle_temp->get_mileage()
            << setw(10) << ((vehicle_temp->get_is_helmet_included() == true) ? "yes" : "no") << endl;
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
            << setw(10) << ((vehicle_temp->get_status() == true) ? "UA" : "A")
            << setw(10) << vehicle_temp->get_brand()
            << setw(20) << vehicle_temp->get_model()
            << setw(10) << vehicle_temp->get_color()
            << setw(20) << to_string(vehicle_temp->get_manufacture_time().get_day()) 
                            + "/" + to_string(vehicle_temp->get_manufacture_time().get_month())
                            + "/" + to_string(vehicle_temp->get_manufacture_time().get_year())
            << setw(10) << vehicle_temp->get_mileage()
            << setw(10) << ((vehicle_temp->get_is_bag_included() == true) ? "yes" : "no") << endl;
    }

    cout << "\n1. Return back" << endl << endl;

    cout << "Please choose an option: ";
    int option = 0;
    cin >> option;

    return ACCESS_CAR_FLEET;
}

state TUI::process_ACCESS_A_VEHICLE(CarRentalMgmt *car_manager)
{
    system("clear");
    cout << "----------" << endl;
    cout << "ACCESS A VEHICLE" << endl;
    cout << "----------" << endl << endl;

    string id;
    cout << "Please input a vehicle ID (string): ";
    cin.ignore();
    getline(cin, id);

    Sport *sport;
    Motorcycle *motor;
    SUV *suv;

    state st_access_a_vehicle = ACCESS_A_SPORT;

    switch (id[0])
    {
    case 'S':
        sport = car_manager->get_Sport_by_id(id);
        if (sport == NULL)
        {
            cout << id + "not found" << endl;
            sleep(1);
            return ACCESS_CAR_FLEET;
        }
        st_access_a_vehicle = ACCESS_A_SPORT;
        break;

    case 'M':
        motor = car_manager->get_Motorcycle_by_id(id);
        if (motor == NULL)
        {
            cout << id + "not found" << endl;
            sleep(1);
            return ACCESS_CAR_FLEET;
        }
        st_access_a_vehicle = ACCESS_A_MOTORCYCLE;
        break;

    case 'U':
        suv = car_manager->get_SUV_by_id(id);
        if (suv == NULL)
        {
            cout << id + "not found" << endl;
            sleep(1);
            return ACCESS_CAR_FLEET;
        }
        st_access_a_vehicle = ACCESS_A_SUV;
        break;

    default:
        st_access_a_vehicle = ACCESS_CAR_FLEET;
        break;
    }

    while(st_access_a_vehicle != ACCESS_CAR_FLEET)
    {
        switch (st_access_a_vehicle)
        {
        case ACCESS_A_SPORT:
            st_access_a_vehicle = process_ACCESS_A_SPORT(sport);
            break;
        
        case ACCESS_A_MOTORCYCLE:
            st_access_a_vehicle = process_ACCESS_A_MOTORCYCLE(motor);
            break;
        
        case ACCESS_A_SUV:
            st_access_a_vehicle = process_ACCESS_A_SUV(suv);
            break;
        
        default:
            return ACCESS_CAR_FLEET;
            break;
        }
    }

    return ACCESS_CAR_FLEET;
}

state TUI::process_ACCESS_A_SPORT(Sport *vehicle)
{
    system("clear");
    cout << "----------" << endl;
    cout << vehicle->get_id() << endl;
    cout << "----------" << endl << endl;

    cout << "1. Add mileage" << endl;
    cout << "2. Print service history" << endl;
    cout << "3. Compute mileage between 2 service records" << endl;
    cout << "4. Export a service record to.json" << endl;
    cout << "5. Export all service history to.json" << endl;
    cout << "6. Return back" << endl;

    cout << "Please choose an option: ";
    int option = 0;
    cin >> option;

    switch (option)
    {   
    case 1:
    {
        system("clear");
        cout << "----------" << endl;
        cout << "ADD MILEAGE" << endl;
        cout << "----------" << endl << endl;
        
        float mileage;
        cout << "Please input mileage (float): ";
        cin >> mileage;

        vehicle->add_mileage(mileage);
        cout << "\nNew mileage: " + to_string(vehicle->get_mileage()) << endl;
        
        break;
    }
    
    case 2:
    {
        system("clear");
        cout << "----------" << endl;
        cout << "SERVICE HISTORY" << endl;
        cout << "----------" << endl << endl;

        cout << "No" 
            << setw(5) << "ID"
            << setw(20) << "Time"
            << setw(10) << "Mileage"
            << setw(20) << "Engine"
            << setw(20) << "Transission"
            << setw(20) << "Tires" << endl;

        for (short i = 0; i < vehicle->get_service_history_size(); i++)
        {
            cout << i 
            << setw(5) << vehicle->get_service_record_at(i)->get_id()
            << setw(20) << vehicle->get_service_record_at(i)->get_service_time().get_hour()
                        << "h:" << vehicle->get_service_record_at(i)->get_service_time().get_day()
                        << "/" << vehicle->get_service_record_at(i)->get_service_time().get_month()
                        << "/" << vehicle->get_service_record_at(i)->get_service_time().get_year()
            << setw(10) << vehicle->get_service_record_at(i)->get_mileage()
            << setw(20) << vehicle->get_service_record_at(i)->get_engine()
            << setw(20) << vehicle->get_service_record_at(i)->get_transmission()
            << setw(20) << vehicle->get_service_record_at(i)->get_tires() << endl;
        }
        break;
    }
    
    case 3:
    {
        system("clear");
        cout << "----------" << endl;
        cout << "COMPUTE MILEAGE BETWEEN 2 SERVICE RECORDS" << endl;
        cout << "----------" << endl << endl;

        short id1;
        cout << "Record 1 ID (int): ";
        cin >> id1;

        short id2;
        cout << "Record 2 ID (int): ";
        cin >> id2;

        float mil = vehicle->compute_mileage_between(id1, id2);

        if (mil == -1)
        {
            cout << "Invalid ID" << endl;
        }

        else
        {
            cout << "Mileage: " << mil << endl;
        }
        break;
    }

    case 4:
    {
        system("clear");
        cout << "----------" << endl;
        cout << "EXPORT A SERVICE RECORD TO .JSON" << endl;
        cout << "----------" << endl << endl;

        short id;
        cout << "Please input a service record ID (int): ";
        cin >> id;

        ServiceRecord *service_record = vehicle->get_service_record_by_id(id);
        if (service_record == NULL)
        {
            cout << id << " not found" << endl;
            sleep(1);
            return ACCESS_A_SPORT;
        }

        else
        {
            vehicle->export_json_record_by_id(id);
            cout << "Exported to file " << vehicle->get_id() << "_" << id << ".json" << endl;
        }

        break;
    }
    
    case 5:
    {
        system("clear");
        cout << "----------" << endl;
        cout << "EXPORT ALL SERVICE HISTORY TO .JSON" << endl;
        cout << "----------" << endl << endl;

        vehicle->export_json_record_all();
        cout << "Exported to file " << vehicle->get_id() << "_all.json" << endl;

        break;
    }

    case 6:
        return ACCESS_CAR_FLEET;
        break;

    default:
        return ACCESS_A_SPORT;
        break;
    }

    cout << "\n1. Return back" << endl;
    cout << "Please choose an option: ";
    int t = 0;
    cin >> t;
    return ACCESS_A_SPORT;
}

state TUI::process_ACCESS_A_MOTORCYCLE(Motorcycle *vehicle)
{
    system("clear");
    cout << "----------" << endl;
    cout << vehicle->get_id() << endl;
    cout << "----------" << endl << endl;

    cout << "1. Add mileage" << endl;
    cout << "2. Print service history" << endl;
    cout << "3. Compute mileage between 2 service records" << endl;
    cout << "4. Export a service record to.json" << endl;
    cout << "5. Export all service history to.json" << endl;
    cout << "6. Return back" << endl;

    cout << "Please choose an option: ";
    int option = 0;
    cin >> option;

    switch (option)
    {   
    case 1:
    {
        system("clear");
        cout << "----------" << endl;
        cout << "ADD MILEAGE" << endl;
        cout << "----------" << endl << endl;
        
        float mileage;
        cout << "Please input mileage (float): ";
        cin >> mileage;

        vehicle->add_mileage(mileage);
        cout << "\nNew mileage: " + to_string(vehicle->get_mileage()) << endl;
    
        break;
    }
    
    case 2:
    {
        system("clear");
        cout << "----------" << endl;
        cout << "SERVICE HISTORY" << endl;
        cout << "----------" << endl << endl;

        cout << "No" 
            << setw(5) << "ID"
            << setw(20) << "Time"
            << setw(10) << "Mileage"
            << setw(20) << "Engine"
            << setw(20) << "Transission"
            << setw(20) << "Tires" << endl;

        for (short i = 0; i < vehicle->get_service_history_size(); i++)
        {
            cout << i 
            << setw(5) << vehicle->get_service_record_at(i)->get_id()
            << setw(20) << vehicle->get_service_record_at(i)->get_service_time().get_hour()
                        << "h:" << vehicle->get_service_record_at(i)->get_service_time().get_day()
                        << "/" << vehicle->get_service_record_at(i)->get_service_time().get_month()
                        << "/" << vehicle->get_service_record_at(i)->get_service_time().get_year()
            << setw(10) << vehicle->get_service_record_at(i)->get_mileage()
            << setw(20) << vehicle->get_service_record_at(i)->get_engine()
            << setw(20) << vehicle->get_service_record_at(i)->get_transmission()
            << setw(20) << vehicle->get_service_record_at(i)->get_tires() << endl;
        }

        break;
    }

    case 3:
    {
        system("clear");
        cout << "----------" << endl;
        cout << "COMPUTE MILEAGE BETWEEN 2 SERVICE RECORDS" << endl;
        cout << "----------" << endl << endl;

        short id1;
        cout << "Record 1 ID (int): ";
        cin >> id1;

        short id2;
        cout << "Record 2 ID (int): ";
        cin >> id2;

        float mil = vehicle->compute_mileage_between(id1, id2);

        if (mil == -1)
        {
            cout << "Invalid ID" << endl;
        }

        else
        {
            cout << "Mileage: " << mil << endl;
        }

        break;
    }

    case 4:
    {
        system("clear");
        cout << "----------" << endl;
        cout << "EXPORT A SERVICE RECORD TO .JSON" << endl;
        cout << "----------" << endl << endl;

        short id;
        cout << "Please input a service record ID (int): ";
        cin >> id;

        ServiceRecord *service_record = vehicle->get_service_record_by_id(id);
        if (service_record == NULL)
        {
            cout << id << " not found" << endl;
        }

        else
        {
            vehicle->export_json_record_by_id(id);
            cout << "Exported to file " << vehicle->get_id() << "_" << id << ".json" << endl;
        }

        break;
    }
    
    case 5:
    {
        system("clear");
        cout << "----------" << endl;
        cout << "EXPORT ALL SERVICE HISTORY TO .JSON" << endl;
        cout << "----------" << endl << endl;

        vehicle->export_json_record_all();
        cout << "Exported to file " << vehicle->get_id() << "_all.json" << endl;

        break;
    }

    case 6:
        return ACCESS_CAR_FLEET;
        break;

    default:
        return ACCESS_A_MOTORCYCLE;
        break;
    }

    cout << "\n1. Return back" << endl;
    cout << "Please choose an option: ";
    int t = 0;
    cin >> t;
    return ACCESS_A_MOTORCYCLE;
}

state TUI::process_ACCESS_A_SUV(SUV *vehicle)
{
    system("clear");
    cout << "----------" << endl;
    cout << vehicle->get_id() << endl;
    cout << "----------" << endl << endl;

    cout << "1. Add mileage" << endl;
    cout << "2. Print service history" << endl;
    cout << "3. Compute mileage between 2 service records" << endl;
    cout << "4. Export a service record to.json" << endl;
    cout << "5. Export all service history to.json" << endl;
    cout << "6. Return back" << endl;

    cout << "Please choose an option: ";
    int option = 0;
    cin >> option;

    switch (option)
    {   
    case 1:
    {
        system("clear");
        cout << "----------" << endl;
        cout << "ADD MILEAGE" << endl;
        cout << "----------" << endl << endl;
        
        float mileage;
        cout << "Please input mileage (float): ";
        cin >> mileage;

        vehicle->add_mileage(mileage);
        cout << "\nNew mileage: " + to_string(vehicle->get_mileage()) << endl;
        break;
    }
    
    case 2:
    {
        system("clear");
        cout << "----------" << endl;
        cout << "SERVICE HISTORY" << endl;
        cout << "----------" << endl << endl;

        cout << "No" 
            << setw(5) << "ID"
            << setw(20) << "Time"
            << setw(10) << "Mileage"
            << setw(20) << "Engine"
            << setw(20) << "Transission"
            << setw(20) << "Tires" << endl;

        for (short i = 0; i < vehicle->get_service_history_size(); i++)
        {
            cout << i 
            << setw(5) << vehicle->get_service_record_at(i)->get_id()
            << setw(20) << vehicle->get_service_record_at(i)->get_service_time().get_hour()
                        << "h:" << vehicle->get_service_record_at(i)->get_service_time().get_day()
                        << "/" << vehicle->get_service_record_at(i)->get_service_time().get_month()
                        << "/" << vehicle->get_service_record_at(i)->get_service_time().get_year()
            << setw(10) << vehicle->get_service_record_at(i)->get_mileage()
            << setw(20) << vehicle->get_service_record_at(i)->get_engine()
            << setw(20) << vehicle->get_service_record_at(i)->get_transmission()
            << setw(20) << vehicle->get_service_record_at(i)->get_tires() << endl;
        }
        break;
    }

    case 3:
    {
        system("clear");
        cout << "----------" << endl;
        cout << "COMPUTE MILEAGE BETWEEN 2 SERVICE RECORDS" << endl;
        cout << "----------" << endl << endl;

        short id1;
        cout << "Record 1 ID (int): ";
        cin >> id1;

        short id2;
        cout << "Record 2 ID (int): ";
        cin >> id2;

        float mil = vehicle->compute_mileage_between(id1, id2);

        if (mil == -1)
        {
            cout << "Invalid ID" << endl;
        }

        else
        {
            cout << "Mileage: " << mil << endl;
        }
        break;
    }

    case 4:
    {
        system("clear");
        cout << "----------" << endl;
        cout << "EXPORT A SERVICE RECORD TO .JSON" << endl;
        cout << "----------" << endl << endl;

        short id;
        cout << "Please input a service record ID (int): ";
        cin >> id;

        ServiceRecord *service_record = vehicle->get_service_record_by_id(id);
        if (service_record == NULL)
        {
            cout << id << " not found" << endl;
            sleep(1);
            return ACCESS_A_SUV;
        }

        else
        {
            vehicle->export_json_record_by_id(id);
            cout << "Exported to file " << vehicle->get_id() << "_" << id << ".json" << endl;
        }

        break;
    }
    
    case 5:
    {
        system("clear");
        cout << "----------" << endl;
        cout << "EXPORT ALL SERVICE HISTORY TO .JSON" << endl;
        cout << "----------" << endl << endl;

        vehicle->export_json_record_all();
        cout << "Exported to file " << vehicle->get_id() << "_all.json" << endl;

        break;
    }

    case 6:
        return ACCESS_CAR_FLEET;
        break;

    default:
        return ACCESS_A_SUV;
        break;
    }

    cout << "\n1. Return back" << endl;
    cout << "Please choose an option: ";
    int t = 0;
    cin >> t;
    return ACCESS_A_SUV;
}

state TUI::process_ADD_A_VEHICLE(CarRentalMgmt *car_manager)
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

    string id;
    cout << endl << "ID (string): ";
    cin.ignore();
    getline(cin, id);

    string brand;
    cout << "Brand (string): ";
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
        if (car_manager->get_Sport_by_id("S" + id) != NULL)
        {
            cout << "\nThe ID is have already been taken." << endl;
            cout << "\nAdded unsuccessfully" << endl;
            break;
        }
        car_manager->add_Sport(Sport("S" + id, brand, model, color, seats, hour, day, month, year, false, mileage));
        cout << "\nAdded ccessfully!" << endl;
            break;

        case 2:
        bool helmet;
        cout <<"Include helmet? (bool): ";
        cin >> helmet;
        if (car_manager->get_Motorcycle_by_id("M" + id) != NULL)
        {
            cout << "\nThe ID is have already been taken." << endl;
            cout << "\nAdded unsuccessfully" << endl;
            break;
        }
        car_manager->add_Motorcycle(Motorcycle("M" + id, brand, model, color, seats, hour, day, month, year, false, mileage, helmet));
        cout << "\nAdded ccessfully!" << endl; 
            break;

        case 3:
        bool bag;
        cout <<"Include bag? (bool): ";
        cin >> bag;
        if (car_manager->get_SUV_by_id("U" + id) != NULL)
        {
            cout << "\nThe ID is have already been taken." << endl;
            cout << "\nAdded unsuccessfully" << endl;
            break;
        }
        car_manager->add_SUV(SUV("U" + id, brand, model, color, seats, hour, day, month, year, false, mileage, bag));
        cout << "\nAdded ccessfully!" << endl; 
            break;

        default:
            break;
    }
    
    cout << "\n1. Return back" << endl;
    cout << "Please choose an option: ";
    int t = 0;
    cin >> t;
    return ACCESS_CAR_FLEET;
}

state TUI::process_REMOVE_A_VEHICLE(CarRentalMgmt *car_manager)
{
    system("clear");
    cout << "----------" << endl;
    cout << "REMOVE A VEHICLE" << endl;
    cout << "----------" << endl << endl;

    string id;
    cout << "Please input a vehicle ID: ";
    cin.ignore();
    getline(cin, id);

    if(car_manager->remove_vehicle_by_id(id) == true)
    {
        cout << "\nRemoved successfully!" << endl;
    }

    else
    {
        cout << "\nRemoved unsuccessfully" << endl;
    }

    cout << "\n1. Return back" << endl;
    cout << "Please choose an option: ";
    int t = 0;
    cin >> t;
    return ACCESS_CAR_FLEET;
}

state TUI::process_SERVICE_FLEET(CarRentalMgmt *car_manager)
{
    system("clear");
    cout << "----------" << endl;
    cout << "SERVICE FLEET" << endl;
    cout << "----------" << endl << endl;

    car_manager->service_fleet();
    cout << "Service successfully!" << endl;

    cout << "\n1. Return back" << endl;
    cout << "Please choose an option: ";
    int t = 0;
    cin >> t;

    return ACCESS_CAR_FLEET;
}

state TUI::process_ACCESS_CUSTOMERS_DATA()
{
    system("clear");
    cout << "----------" << endl;
    cout << "CUSTOMER DATA" << endl;
    cout << "----------" << endl << endl;

    cout << "1. Print customers list" << endl;
    cout << "2. Add a customer" << endl;
    cout << "3. Remove a customer" << endl;
    cout << "4. Return back" << endl << endl;

    cout << "Please choose an option: ";
    int option = 0;
    cin >> option;

    switch (option)
    {
    case 1:
        return PRINT_CUSTOMERS;
        break;
    
    case 2:
        return ADD_A_CUSTOMER;
        break;
    
    case 3:
        return REMOVE_A_CUSTOMER;
        break;

    case 4:
        return MAIN_MENU;
        break;
    
    default:
        return ACCESS_CUSTOMERS_DATA;
        break;
    }

    return ACCESS_CUSTOMERS_DATA;
}

state TUI::process_PRINT_CUSTOMERS(CarRentalMgmt *car_manager)
{
    system("clear");
    cout << "----------" << endl;
    cout << "PRINT CUSTOMERS LIST" << endl;
    cout << "----------" << endl << endl;

    cout << "Total customers: " << car_manager->get_customers_size() << endl << endl;

    cout << "No" 
        << setw(5) << "ID"
        << setw(20) << "Name"
        << setw(10) << "Gender"
        << setw(15) << "DOB"
        << setw(20) << "Email"
        << setw(20) << "Driver license ID"
        << setw(15) << "Phone" << endl;

    for (short i = 0; i < car_manager->get_customers_size(); i++)
    {
        Customer *cus = car_manager->get_customer_at(i);
        cout << i + 1 
            << setw(5) << cus->get_id()
            << setw(20) << cus->get_name()
            << setw(10) << ((cus->get_gender() == true) ? "Male" : "Female")
            << setw(15) << cus->get_dob().get_day() << "/" << cus->get_dob().get_month() << "/" << cus->get_dob().get_year()
            << setw(20) << cus->get_email()
            << setw(20) << cus->get_driver_license_id()
            << setw(15) << cus->get_phone_number() << endl;
    }

    cout << "\n1. Return back" << endl;
    cout << "Please choose an option: ";
    int t = 0;
    cin >> t;

    return ACCESS_CUSTOMERS_DATA;
}

state TUI::process_ADD_A_CUSTOMER(CarRentalMgmt *car_manager)
{
    system("clear");
    cout << "----------" << endl;
    cout << "ADD A CUSTOMER" << endl;
    cout << "----------" << endl << endl;

    string id;
    cout << endl << "ID (string): ";
    cin.ignore();
    getline(cin, id);

    string name;
    cout << "Name (string): ";
    getline(cin, name);

    bool gender;
    cout << "Gender (bool) (0 - Female; 1 - male): ";
    cin >> gender;

    short day;
    cout << "DOB day (int): ";
    cin >> day;

    short month;
    cout << "DOB month (int): ";
    cin >> month;

    short year;
    cout << "DOB year (int): ";
    cin >> year;

    string email;
    cout << "email (string): ";
    cin.ignore();
    getline(cin, email);

    string driver_id;
    cout << "Driver license ID (string): ";
    getline(cin, driver_id);

    string phone;
    cout << "Phone number (string): ";
    getline(cin, phone);

    if (car_manager->get_customer_by_id(id) != NULL)
    {
        cout << "\nThe ID is have already been taken." << endl;
        cout << "\nAdded unsuccessfully" << endl;
    }

    else
    {
        car_manager->add_a_customer(Customer(id, name, gender, 0, day, month, year, email, driver_id, phone));
        cout << "\nAdded successfully!" << endl;
    }

    cout << "\n1. Return back" << endl;
    cout << "Please choose an option: ";
    int t = 0;
    cin >> t;

    return ACCESS_CUSTOMERS_DATA;
}

state TUI::process_REMOVE_A_CUSTOMER(CarRentalMgmt *car_manager)
{
    system("clear");
    cout << "----------" << endl;
    cout << "REMOVE A CUSTOMER" << endl;
    cout << "----------" << endl << endl;

    string id;
    cout << "Please input a customer ID: ";
    cin.ignore();
    getline(cin, id);

    if(car_manager->remove_a_customer_by_id(id) == true)
    {
        cout << "\nRemoved successfully!" << endl;
    }

    else
    {
        cout << "\nRemoved unsuccessfully" << endl;
    }

    cout << "\n1. Return back" << endl;
    cout << "Please choose an option: ";
    int t = 0;
    cin >> t;

    return ACCESS_CUSTOMERS_DATA;
}

state TUI::process_ACCESS_CONTRACTS_DATA()
{
    return MAIN_MENU;
}

state TUI::process_BOOK()
{
    return MAIN_MENU;
}

state TUI::process_EXIT_PROGRAM()
{
    return EXIT_PROGRAM;
}
