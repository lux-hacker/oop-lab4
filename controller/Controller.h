#ifndef OOP_LAB4_CONTROLLER_H
#define OOP_LAB4_CONTROLLER_H

#include "../models/Service/Service.h"

namespace app {
    using namespace service;

    namespace units{
        int inputInt(int=-100000, int=100000);
        std::string generateID();
    }

    class Controller {
        Service service;
    public:
        Controller();

        int run();
        void editCaller();
        void editTelephone();
        Caller* createCaller();
        void showTable();
        int getAmountTrafficForCaller();
        int* getAmountDuration();
        double getAmountPrice();
    };
}


#endif //OOP_LAB4_CONTROLLER_H
