#include "Telephone.h"
namespace service{
    const std::string & Telephone::getNumber() const {
        return number;
    }

    void Telephone::setNumber(const std::string &number) {
        this->number = number;
    }

    long long int Telephone::getDate() const {
        return date;
    }

    void Telephone::setDate(long long int date) {
        this->date = date;
    }

    int Telephone::getDuration() const {
        return duration;
    }

    void Telephone::setDuration(int duration) {
        this->duration = duration;
    }

    std::string Telephone::toString() {
        return "TelephoneSession: " + number + " - " + std::to_string(date) + " - " + std::to_string(duration);
    }

    TelephoneType Telephone::getType() {
        return TELEPHONE;
    }

    Telephone::Telephone(Telephone &&other) noexcept
    : number(std::move(other.number)), date(other.date), duration(other.duration){
        other.number = "DefaultNUmber";
        other.duration = 0;
        other.date = 0L;
    }

    double Fax::getTraffic() {
        return traffic;
    }

    void Fax::setTraffic(double traffic) {
        Fax::traffic = traffic;
    }

    std::string Fax::toString() {
        return "FaxSession: " +  number + " - " + std::to_string(date) + " - "
        + std::to_string(duration) + " - " + std::to_string(traffic);
    }

    TelephoneType Fax::getType() {
        return FAX;
    }

    double Internet::getInputTraffic() const {
        return inputTraffic;
    }

    void Internet::setInputTraffic(double inputTraffic) {
        this->inputTraffic = inputTraffic;
    }

    double Internet::getOutputTraffic() const {
        return outputTraffic;
    }

    void Internet::setOutputTraffic(double outputTraffic) {
        this->outputTraffic = outputTraffic;
    }

    std::string Internet::toString() {
        return "InternetSession: " + number + " - " + std::to_string(date) + " - " + std::to_string(duration) +
        " - " + std::to_string(inputTraffic) + " - " + std::to_string(outputTraffic);
    }

    TelephoneType Internet::getType() {
        return INTERNET;
    }

    double Internet::getTraffic() {
        return inputTraffic + outputTraffic;
    }

    std::ostream& operator<<(std::ostream& out, Telephone& t){
        out << t.toString();
        return out;
    }


}