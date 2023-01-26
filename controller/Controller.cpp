#include "Controller.h"
#include "iostream"
#include "../views/menu.h"
#include "random"

namespace app{

    namespace units{
        int inputInt(int min, int max){
            int res;
            while(true){
                std::cin >> res;
                if(res < min || res > max){
                    std::cout << "ERROR: Point must be in [" << min << ", " << max << "]" << std::endl;
                    std::cout << ">> Enter point >>";
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
                this->service.addNewCallerByID(createCaller(), units::generateID());
                break;
            }
            case 2:{
                showTable();
                editCaller();
                break;
            }
            case 3:{
                double res = getAmountTrafficForCaller();
                std::cout << "Amount Traffic: " << res << std::endl;
                break;
            }
            case 4:{
                vector<int> res = getAmountDuration();
                std::cout << "Telephone Session duration: " << res[0] << std::endl;
                std::cout << "Fax Session duration: " << res[1] << std::endl;
                std::cout << "Internet Session duration: " << res[2] << std::endl;
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
        int size = this->service.getSize();
        std::cout << "======[EDIT MENU]======" << std::endl;
        std::cout << "0) Go back" << std::endl;
        std::cout << "1) Edit caller" << std::endl;
        std::cout << ">> Edit point >>";
        int point = units::inputInt(0, 1);
        switch (point) {
            case 0: return;
            case 1:{
                std::cout << ">> Enter point of caller >> ";
                int p_caller = units::inputInt(1, size);
                auto itr = this->service.getCallers().begin();
                for(int i = 1; i < p_caller; i++, itr++);
                _editCaller(*itr);
                break;
            }
        }
    }

    Caller *Controller::createCaller() {
        std::cout << ">> Enter type of client: INDIVIDUAL(0) or ENTITY(1) >> ";
        std::string name_organization, name, address, bN;
        auto type = static_cast<ClientType>(units::inputInt(0, 1));
        if(type == service::ENTITY){
            std::cout << ">> Enter name of organization >> ";
            getline(std::cin, name_organization);
        }
        std::cout << ">> Enter name >> ";
        getline(std::cin, name);
        std::cout << ">> Enter address >> ";
        getline(std::cin, address);
        std::cout << ">> Enter bank number >> ";
        getline(std::cin, bN);

        Client* client;
        if(type == service::INDIVIDUAL){
            client = new Client(name, address, bN);
        } else {
            client = new LegalClient(name, address, bN, name_organization);
        }

        return new Caller(client);
    }

    Controller::Controller() {
        std::cout << ">> Enter name of service >> " << std::endl;
        std::string name;
        getline(std::cin, name);
        int subPrice, minPrice, MBPrice;
        std::cout << ">> Enter price of subscription >>" << std::endl;
        std::cin >> subPrice;
        std::cout << ">> Enter price of 1 minute >>" << std::endl;
        std::cin >> minPrice;
        std::cout << ">> Enter price of 1 MB >>" << std::endl;
        std::cin >> MBPrice;
        this->service = Service(name, subPrice, minPrice, MBPrice);

    }

    void Controller::showTable() {
        std::cout << service;
    }

    void Controller::_editCaller(CallerData *cd) {
        std::cout << *(cd->getCaller());
        std::cout << "============" << std::endl;
        menu::editCallerMenu(cd->getCaller()->getClientType());
        int a;
        if(cd->getCaller()->getClientType() == service::INDIVIDUAL)
            a = units::inputInt(0, 4);
        else a = units::inputInt(0, 5);
        switch (a) {
            case 0:
                return;
            case 1:{
                if(cd->getCaller()->getClientType() == service::INDIVIDUAL){
                    std::cout << ">> Enter new name >> ";
                    std::string name;
                    getline(std::cin, name);
                    cd->getCaller()->getClient()->setName(name);
                } else {
                    std::cout << ">> Enter new name of organization >> ";
                    std::string name_org;
                    getline(std::cin, name_org);
                    ((LegalClient *)(cd->getCaller()->getClient()))->setOrganization(name_org);
                }
                break;
            }
            case 2:{
                if(cd->getCaller()->getClientType() == service::INDIVIDUAL){
                    std::cout << ">> Enter new address >> ";
                    std::string address;
                    getline(std::cin, address);
                    cd->getCaller()->getClient()->setAddress(address);
                } else {
                    std::cout << ">> Enter new name >> ";
                    std::string name;
                    getline(std::cin, name);
                    cd->getCaller()->getClient()->setName(name);
                }
                break;
            }
            case 3:{
                if(cd->getCaller()->getClientType() == service::INDIVIDUAL){
                    std::cout << ">> Enter new bank number >> ";
                    std::string bank_number;
                    getline(std::cin, bank_number);
                    cd->getCaller()->getClient()->setBankNumber(bank_number);
                } else {
                    std::cout << ">> Enter new address >> ";
                    std::string address;
                    getline(std::cin, address);
                    cd->getCaller()->getClient()->setAddress(address);
                }
                break;
            }
            case 4:{
                if(cd->getCaller()->getClientType() == service::INDIVIDUAL){
                    menu::editTelephoneMenu();
                    std::cout << ">> Enter point >> ";
                    int point = units::inputInt(1, 2);
                    if(point == 1)  editTelephone(nullptr, cd->getCaller());
                    else {
                        std::cout << ">> Enter point of session >> ";
                        int sess = units::inputInt(1, cd->getCaller()->getServices().size());
                        editTelephone(cd->getCaller()->getServices()[sess], nullptr);
                    }
                } else {
                    std::cout << ">> Enter new bank number >> ";
                    std::string bank_number;
                    getline(std::cin, bank_number);
                    cd->getCaller()->getClient()->setBankNumber(bank_number);
                }
                break;
            }
            case 5:{
                menu::editTelephoneMenu();
                std::cout << ">> Enter point >> ";
                int point = units::inputInt(1, 2);
                if(point == 1)  editTelephone(nullptr, cd->getCaller());
                else {
                    std::cout << ">> Enter point of session >> ";
                    int sess = units::inputInt(1, cd->getCaller()->getServices().size());
                    editTelephone(cd->getCaller()->getServices()[sess], nullptr);
                }
                break;
            }
        }
    }

    void Controller::editTelephone(Telephone *telephone, Caller* caller) {
        if(telephone){
            int max_point = (telephone->getType() == service::TELEPHONE? 3: telephone->getType() == service::FAX? 4: 5 );
            int a = units::inputInt(1, max_point);
            switch (a) {
                case 1:{
                    std::cout << ">> Enter new number >> ";
                    std::string number;
                    getline(std::cin, number);
                    telephone->setNumber(number);
                    break;
                }
                case 2:{
                    std::cout << ">> Enter new date >> ";
                    long long date;
                    std::cin >> date;
                    telephone->setDate(date);
                    break;
                }
                case 3:{
                    std::cout << ">> Enter new duration >> ";
                    int duration;
                    std::cin >> duration;
                    telephone->setDuration(duration);
                    break;
                }
                case 4: {
                    std::cout << ">> Enter new traffic >> ";
                    double traffic;
                    std::cin >> traffic;
                    ((Fax *) telephone)->setTraffic(traffic);
                    break;
                }
                case 5: {
                    std::cout << ">> Enter new input traffic >> ";
                    double input_traffic;
                    std::cin >> input_traffic;
                    ((Internet *) telephone)->setInputTraffic(input_traffic);
                    break;
                }
                case 6:{
                    std::cout << ">> Enter new output traffic >> ";
                    double output_traffic;
                    std::cin >> output_traffic;
                    ((Internet *) telephone)->setOutputTraffic(output_traffic);
                    break;
                }
            }
        } else {
            std::cout << ">> Enter type of session: Telephone(0), Fax(1), Internet(2) >> ";
            auto type = static_cast<TelephoneType>(units::inputInt(0, 2));
            std::cout << ">> Enter number >> ";
            std::string number;
            getline(std::cin, number);
            std::cout << ">> Enter date >> ";
            long long date;
            std::cin >> date;
            std::cout << ">> Enter duration >> ";
            int duration;
            std::cin >> duration;
            if(type == TELEPHONE){
                telephone = new Telephone(number, date, duration);
            } else if (type == FAX){
                std::cout << ">> Enter traffic >> ";
                double traffic;
                std::cin >> traffic;
                telephone = new Fax(number, date, duration, traffic);
            } else {
                std::cout << ">> Enter input traffic >> ";
                double input_traffic;
                std::cin >> input_traffic;
                std::cout << ">> Enter output traffic >> ";
                double output_traffic;
                std::cin >> output_traffic;
                telephone = new Internet(number, date, duration, input_traffic, output_traffic);
            }
            caller->addNewService(telephone);
        }
    }

    double Controller::getAmountTrafficForCaller() {
        showTable();
        int size = this->service.getSize();
        std::cout << ">> Enter point of caller >> ";
        int point = units::inputInt(1, size);
        auto itr = this->service.getCallers().begin();
        for(int i = 1; i < point; i++, itr++);
        Caller* caller = (*itr)->getCaller();
        double res = 0;
        for(auto item : caller->getServices()){
            res += item->getTraffic();
        }
        return res;
    }

    vector<int> Controller::getAmountDuration() {
        vector<int> res;
        res[0] = 0; res[1] = 0; res[2] = 0;
        for(auto caller : this->service.getCallers()){
            for(auto session : caller->getCaller()->getServices()){
                res[session->getType()] += session->getDuration();
            }
        }
        return res;
    }

    double Controller::getAmountPrice() {
        double res = 0;
        for(auto caller : this->service.getCallers()){
            for(auto session : caller->getCaller()->getServices()){
                res += session->getDuration() * this->service.getMinutePrice();
                res += session->getTraffic() * this->service.getMbPrice();
            }
        }
        return res;
    }


}