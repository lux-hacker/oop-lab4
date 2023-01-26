#ifndef OOP_LAB4_CALLER_H
#define OOP_LAB4_CALLER_H

#include "../Client/Client.h"
#include "../Telephone/Telephone.h"
#include "../../collection/vector.h"

namespace service {
    using namespace collection;

    class Caller {
        Client* client;
        vector<Telephone*> services;
    public:
        Caller(): client(), services(){}
        Caller(Client* client, vector<Telephone*> vector): client(client), services(std::move(vector)) {};
        Caller(Client* client): client(client), services(vector<Telephone*>()) {};

        ~Caller(){delete client;}

        [[nodiscard]] Client* getClient();
        void setClient(Client *client);
        [[nodiscard]] const vector <Telephone*> &getServices() const;
        void setServices(vector <Telephone*> &services);

        void addNewService(Telephone*);
        void setDurationByIndex(int, int);
        ClientType getClientType();
        Telephone* operator[](int) const;
        int getAmountDurationByType(TelephoneType);
        double getAmountTrafficByType(TelephoneType);
        int getCountServicesByType(TelephoneType);

    };
}


#endif //OOP_LAB4_CALLER_H
