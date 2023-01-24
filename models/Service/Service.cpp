#include "Service.h"

namespace Service{
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
        Service::name = name;
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
        if((*itr)->getId() == ID) throw std::invalid_argument("UnUniqID: ID must be uniq");
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

    std::string Service::toString() {
        std::string res;
        for(auto cd : callers){
            auto client =  cd->getCaller()->getClient();
            res += client.toString() + '\n';
        }
        return res;
    }
}