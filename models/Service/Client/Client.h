#ifndef OOP_LAB4_CLIENT_H
#define OOP_LAB4_CLIENT_H

#include <string>
#include <iostream>
#include <utility>


namespace service {
    enum ClientType{
        INDIVIDUAL, ENTITY
    };

    class Client {
    protected:
        std::string name;
        std::string address;
        std::string bankNumber;
    public:
        Client() :
        name("DefaultName"),
        address("DefaultAddress"),
        bankNumber("DefaultBankNumber") {};

        Client(std::string name, std::string address, std::string bN) :
        name(std::move(name)),
        address(std::move(address)),
        bankNumber(std::move(bN)) {};

        Client(const Client&);
        Client(Client&&) noexcept;


        std::string getName();
        std::string getAddress();
        std::string getBankNumber();

        void setName(const std::string&);
        void setAddress(const std::string&);
        void setBankNumber(const std::string&);

        virtual std::string toString();
        virtual ClientType getType();

        Client& operator= (const Client&) = default;
        Client& operator= (Client&&) noexcept = default;

        friend std::ostream& operator<< (std::ostream&, Client&);
    };

    std::ostream& operator<< (std::ostream&, Client&);

    class LegalClient: public Client{
        std::string organization;
    public:
        LegalClient(): Client(), organization("DefaultOrganization"){};
        LegalClient(std::string &name, std::string &address, std::string &bN, std::string &org)
            : Client(name, address, bN), organization(std::move(org)){};

        LegalClient(const LegalClient&);
        LegalClient(LegalClient&&) noexcept;

        std::string getOrganization();
        void setOrganization(const std::string&);

        std::string toString() override;
        ClientType getType() override;

        LegalClient& operator= (const LegalClient&) = default;
        LegalClient& operator= (LegalClient&&) noexcept = default;
    };
}

#endif //OOP_LAB4_CLIENT_H
