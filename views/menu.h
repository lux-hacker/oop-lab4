#ifndef OOP_LAB4_MENU_H
#define OOP_LAB4_MENU_H

#include "../models/Service/Service.h"

namespace app{
    namespace menu{
        static void mainMenu();
        static void editCallerMenu(service::ClientType);
        static void editTelephoneMenu();
    };
}

#endif //OOP_LAB4_MENU_H
