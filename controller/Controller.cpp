#include "Controller.h"
#include "iostream"
#include "../views/menu.h"
#include "random"

namespace app{
    using namespace std;

    namespace units{
        int inputInt(int min, int max){
            int res;
            while(true){
                cin >> res;
                if(res < min || res > max){
                    cout << "ERROR: Point must be in [" << min << ", " << max << "]" << endl;
                    cout << ">> Enter point >>";
                } else break;
            }
            return res;
        }
        std::string generateID(){
            std::srand(time(nullptr));
            char alpha[36] = { 'a', 'b', 'c', 'd', 'e', 'f', 'g',
                                   'h', 'i', 'j', 'k', 'l', 'm', 'n',
                                   'o', 'p', 'q', 'r', 's', 't', 'u',
                                   'v', 'w', 'x', 'y', 'z', '0', '1',
                                   '2', '3', '4', '5', '6', '7', '8', '9'};
            std::string res;
            for(int i = 0; i < 10; i++)
                res += alpha[std::rand() % 36];
            return res;
        }
    }

    int Controller::run() {
        menu::mainMenu();
        int a = units::inputInt(0, 5);
        switch (a) {
            case 0: return 0;
            case 1:{
                createCaller();
                break;
            }
            case 2:{
                showTable();
                editCaller();
                break;
            }
            case 3:{
                int res = getAmountTrafficForCaller();
                break;
            }
            case 4:{
                int* res = getAmountDuration();
                break;
            }
            case 5:{
                double res = getAmountPrice();
                break;
            }
        }
        return 1;
    }

    void Controller::editCaller() {
        
    }

    void Controller::editTelephone() {

    }

    Caller *Controller::createCaller() {
        cout << ">> Enter type of client: INDIVIDUAL(0) or ENTITY(1) >> ";
        std::string name_organization, name, address, bN;
        auto type = static_cast<ClientType>(units::inputInt(0, 1));
        if(type == service::ENTITY){
            cout << ">> Enter name of organization >> ";
            getline(cin, name_organization);
        }
        cout << ">> Enter name >> ";
        getline(cin, name);
        cout << ">> Enter address >> ";
        getline(cin, address);
        cout << ">> Enter bank number >> ";
        getline(cin, bN);

        Client* client;
        if(type == service::INDIVIDUAL){
            client = new Client(name, address, bN);
        } else {
            client = new LegalClient(name, address, bN, name_organization);
        }

        return new Caller(client);
    }

    Controller::Controller() {
        cout << ">> Enter name of service >> " << endl;
        std::string name;
        getline(cin, name);
        int subPrice, minPrice, MBPrice;
        cout << ">> Enter price of subscription >>" << endl;
        cin >> subPrice;
        cout << ">> Enter price of 1 minute >>" << endl;
        cin >> minPrice;
        cout << ">> Enter price of 1 MB >>" << endl;
        cin >> MBPrice;
        this->service = Service(name, subPrice, minPrice, MBPrice);

    }

    void Controller::showTable() {
        cout << service;
    }
}