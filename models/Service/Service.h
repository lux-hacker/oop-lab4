#ifndef OOP_LAB4_SERVICE_H
#define OOP_LAB4_SERVICE_H

#include "Caller/Caller.h"
#include "../collection/list.h"

namespace Service {
    class CallerData {
        Caller *caller;
        std::string ID;
    public:
        CallerData() : caller(nullptr), ID("DefaultID") {};
        CallerData(Caller *caller, std::string ID) : caller(caller), ID(std::move(ID)) {};

        [[nodiscard]] Caller *getCaller();
        void setCaller(Caller *caller);
        [[nodiscard]] const std::string &getId() const;
        void setId(const std::string &id);
    };

    class Service {
        std::string name;
        list<CallerData *> callers;
        int subscribePrice;
        int minutePrice;
        int MBPrice;
    public:
        Service() : name("DefaultName"), callers(), subscribePrice(0), minutePrice(0), MBPrice(0) {};

        Service(std::string name, int subscribePrice, int minutePrice, int MBPrice)
                : name(std::move(name)), callers(), subscribePrice(subscribePrice), minutePrice(minutePrice),
                  MBPrice(MBPrice) {};


        [[nodiscard]] const std::string &getName() const;
        void setName(const std::string &name);
        [[nodiscard]] const list<CallerData *> &getCallers();
        [[nodiscard]] int getSubscribePrice() const;
        void setSubscribePrice(int subscribePrice);
        [[nodiscard]] int getMinutePrice() const;
        void setMinutePrice(int minutePrice);
        [[nodiscard]] int getMbPrice() const;
        void setMbPrice(int mbPrice);

        void addNewCallerByID(Caller*, const std::string&);
        Caller* findCallerByID(const std::string&);
        std::string toString();
    };
}


#endif //OOP_LAB4_SERVICE_H
