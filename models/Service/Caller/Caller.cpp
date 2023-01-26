#include "Caller.h"
namespace service{
    Client* Caller::getClient(){
        return client;
    }

    void Caller::setClient(Client *client) {
        this->client = client;
    }

    const vector<Telephone*> &Caller::getServices() const {
        return services;
    }

    void Caller::setServices(vector<Telephone *> &services) {
        this->services = services;
    }

    void Caller::addNewService(Telephone *service) {
        services[services.getSize()] = service;
    }

    void Caller::setDurationByIndex(int index, int new_duration) {
        services[index]->setDuration(new_duration);
    }

    ClientType Caller::getClientType() {
        return client->getType();
    }

    Telephone* Caller::operator[](int i) const {
        return services[i];
    }

    int Caller::getAmountDurationByType(TelephoneType t_type){
        int res = 0;
        for(Telephone* t : services){
            if(t->getType() == t_type)
                res += t->getDuration();
        }
        return res;
    }

    double Caller::getAmountTrafficByType(TelephoneType t_type) {
        double res = 0;
        for (Telephone *t: services) {
            if (t->getType() == t_type) {
                res += t->getTraffic();
            }
            return res;
        }
    }

    int Caller::getCountServicesByType(TelephoneType t_type) {
        int res = 0;
        for(Telephone* t : services){
            if(t->getType() == t_type)
                res++;
        }
        return res;
    }
}

