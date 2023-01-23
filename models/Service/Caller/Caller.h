#ifndef OOP_LAB4_CALLER_H
#define OOP_LAB4_CALLER_H

#include "../Client/Client.h"
#include "../Telephone/Telephone.h"
#include "../../collection/vector.h"

namespace Service {
    using namespace collection;

    class Caller {
        Client client;
        vector<Telephone*> services;
    public:
        Caller(): client(), services(){}
        Caller(Client client, vector<Telephone*> vector): client(std::move(client)), services(std::move(vector)) {};


        [[nodiscard]] const Client &getClient() const;
        void setClient(const Client &client);
        [[nodiscard]] const vector <Telephone*> &getServices() const;
        void setServices(const vector <Telephone*> &services);

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
