#include "Client.h"

namespace Service{
    Client::Client(const Client &other) {
        name = other.name;
        address = other.address;
        bankNumber = other.bankNumber;
    }

    Client::Client(Client &&other) noexcept :
    name(std::move(other.name)),
    address(std::move(other.address)),
    bankNumber(std::move(other.bankNumber)) {
        other.name = "DefaultName";
        other.address = "DefaultAddress";
        other.bankNumber = "DefaultBankNumber";
    }

    std::string Client::getName() {
        return name;
    }

    std::string Client::getAddress() {
        return address;
    }

    std::string Client::getBankNumber() {
        return bankNumber;
    }

    void Client::setName(const std::string &name) {
        this->name = name;
    }

    void Client::setAddress(const std::string &address) {
        this->address = address;
    }

    void Client::setBankNumber(const std::string &bN) {
        this->bankNumber = bN;
    }

    std::string Client::toString(){
        return name + " - " + address + " - " + bankNumber;
    }

    ClientType Client::getType() {
        return INDIVIDUAL;
    }

    std::string LegalClient::toString() {
        return organization + " - " + name + " - " + address + " - " + bankNumber;
    }

    ClientType LegalClient::getType() {
        return ENTITY;
    }

    LegalClient::LegalClient(const LegalClient &other)  : Client(other) {
        this->organization = other.organization;
    }

    LegalClient::LegalClient(LegalClient &&other) noexcept : Client(other), organization(std::move(other.organization)) {
        other.organization = "DefaultOrganization";
    }

    std::string LegalClient::getOrganization() {
        return organization;
    }

    void LegalClient::setOrganization(const std::string &organization) {
        this->organization = organization;
    }

    std::ostream& operator<< (std::ostream& out, Client& c){
        out << c.toString();
        return out;
    }
}