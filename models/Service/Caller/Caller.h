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
        [[nodiscard]] vector <Telephone*> &getServices();
        void setServices(vector <Telephone*> &services);

        void addNewService(Telephone*);
        ClientType getClientType();
        Telephone* operator[](int) const;

        friend std::ostream& operator << (std::ostream&, const Caller&);
    };

    std::ostream& operator << (std::ostream&, const Caller&);
}


#endif //OOP_LAB4_CALLER_H
