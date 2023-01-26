#include "menu.h"
#include "iostream"

namespace app::menu{
    using namespace std;

    void mainMenu() {
        cout << "=[TELEPHONE SERVICE]=" << endl;
        cout << "=====[MAIN MENU]=====" << endl;
        cout << "0) Exit" << endl;
        cout << "1) Add new caller" << endl;
        cout << "2) Show list of caller and edit them" << endl;
        cout << "3) Get amount traffic for the caller" << endl;
        cout << "4) Get amount duration usage by type" << endl;
        cout << "5) Get amount price" << endl;
        cout << ">> Enter point >> ";
    }

    void editCallerMenu(service::ClientType type) {
        int i = 0;
        cout << "=====[EDIT CALLER MENU]=====" << endl;
        cout << i++ << ") Go back" << endl;
        if (type == service::ClientType::ENTITY)
            cout << i++ << ") Edit name of organization" << endl;
        cout << i++ << ") Edit name" << endl;
        cout << i++ << ") Edit address" << endl;
        cout << i++ << ") Edit bank number" << endl;
        cout << i++ << ") Edit history of usage service" << endl;
        cout << ">> Enter point >> ";
    }

    void editTelephoneMenu() {
        int i = 1;
        cout << "=====[EDIT HISTORY OF USAGE]=====" << endl;
        cout << i++ << ") Add new" << endl;
        cout << i++ << ") Edit exists" << endl;
        cout << ">> Enter point >> ";
    }

    void editTelephoneDataMenu(service::TelephoneType type) {
        cout << "=====[EDIT HISTORY OF USAGE]=====" << endl;
        cout << "1) Edit number" << endl;
        cout << "2) Edit date" << endl;
        cout << "3) Edit duration" << endl;
        if (type == service::FAX){
            cout << "4) Edit traffic" << endl;
        } else if (type == service::INTERNET){
            cout << "4) Edit input traffic" << endl;
            cout << "5) Edit output traffic" << endl;
        }
        cout << ">> Enter point >> ";
    }

}