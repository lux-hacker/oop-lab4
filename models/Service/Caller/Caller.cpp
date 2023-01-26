#include "Caller.h"
namespace service{
    Client* Caller::getClient(){
        return client;
    }

    void Caller::setClient(Client *client) {
        this->client = client;
    }

    vector<Telephone*> &Caller::getServices(){
        return this->services;
    }

    void Caller::setServices(vector<Telephone *> &services) {
        this->services = services;
    }

    void Caller::addNewService(Telephone *service) {
        services[services.size()] = service;
    }

    ClientType Caller::getClientType() {
        return client->getType();
    }

    Telephone* Caller::operator[](int i) const {
        return services[i];
    }
}

