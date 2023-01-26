#include <list>
#include "Service.h"

namespace service{
    Caller *CallerData::getCaller(){
        return caller;
    }

    void CallerData::setCaller(Caller *caller) {
        this->caller = caller;
    }

    [[nodiscard]] const std::string &CallerData::getId() const {
        return ID;
    }

    void CallerData::setId(const std::string &id) {
        ID = id;
    }

    const std::string &Service::getName() const {
        return name;
    }

    void Service::setName(const std::string &name) {
        this->name = name;
    }

    const list<CallerData *> &Service::getCallers() {
        return callers;
    }

    int Service::getSubscribePrice() const {
        return subscribePrice;
    }

    void Service::setSubscribePrice(int subscribePrice) {
        this->subscribePrice = subscribePrice;
    }

    int Service::getMinutePrice() const {
        return minutePrice;
    }

    void Service::setMinutePrice(int minutePrice) {
        this->minutePrice = minutePrice;
    }

    int Service::getMbPrice() const {
        return MBPrice;
    }

    void Service::setMbPrice(int mbPrice) {
        MBPrice = mbPrice;
    }

    void Service::addNewCallerByID(Caller *caller, const std::string& ID) {
        auto itr = callers.begin();
        while(itr != callers.end() && (*itr)->getId().compare(ID) < 0)
            itr++;
        if(*itr != nullptr){
            if ((*itr)->getId() == ID) throw std::invalid_argument("UnUniqID: ID must be uniq");
        }
        auto new_caller = new CallerData(caller, ID);
        callers.insert(itr, new_caller);
    }

    Caller *Service::findCallerByID(const std::string& ID) {
        for(CallerData* cd:callers){
            if(cd->getId() == ID)
                return cd->getCaller();
        }
        return nullptr;
    }

    Service &Service::operator=(const Service &other) {
        this->callers = other.callers;
        this->name = other.name;
        this->subscribePrice = other.subscribePrice;
        this->minutePrice = other.minutePrice;
        this->MBPrice = other.MBPrice;
        return *this;
    }

    std::string Service::toString() {
        std::string res;
        int i = 1;
        for(CallerData* cd : callers){
            res += std::to_string(i++) + ") " + cd->getId() + " - " + cd->getCaller()->getClient()->getName() + "\n";
        }
        return res;
    }

    std::ostream &operator<<(std::ostream &out, Service & s) {
        out << s.toString();
        return out;
    }
}