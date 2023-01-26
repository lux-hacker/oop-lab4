#ifndef OOP_LAB4_TELEPHONE_H
#define OOP_LAB4_TELEPHONE_H

#include <string>
#include <iostream>

namespace service {
    enum TelephoneType{
        TELEPHONE, FAX, INTERNET
    };

    class Telephone {
    protected:
        std::string number;
        long long date;
        int duration;
    public:
        Telephone(): number("DefaultNUmber"), date(0L), duration(0){};
        Telephone(std::string& number, long long date, int duration)
        : number(std::move(number)), date(date), duration(duration){};

        Telephone(const Telephone& other)  = default;
        Telephone(Telephone&&) noexcept;

        [[nodiscard]] const std::string &getNumber() const;
        void setNumber(const std::string &number);
        [[nodiscard]] long long int getDate() const;
        void setDate(long long int date);
        [[nodiscard]] int getDuration() const;
        void setDuration(int duration);

        virtual std::string toString();
        virtual TelephoneType getType();
        virtual double getTraffic() {return 0;}

        Telephone& operator= (const Telephone&) = default;
        Telephone& operator= (Telephone&&) noexcept = default;

        friend std::ostream& operator<<(std::ostream&, Telephone&);
    };

    std::ostream& operator<<(std::ostream&, Telephone&);

    class Fax: public Telephone{
        double traffic;
    public:
        Fax(): Telephone(), traffic(0.0){}
        Fax(std::string& number, long long date, int duration, double traffic)
        : Telephone(number, date, duration), traffic(traffic){}

        Fax(const Fax&) = default;
        Fax(Fax&&) noexcept = default;

        double getTraffic() override;
        void setTraffic(double traffic);

        std::string toString() override;
        TelephoneType getType() override;

        Fax& operator= (const Fax&) = default;
        Fax& operator= (Fax&&) noexcept = default;

    };

    class Internet: public Telephone{
        double inputTraffic;
        double outputTraffic;
    public:
        Internet(): Telephone(), inputTraffic(0.0), outputTraffic(0.0){};
        Internet(std::string& number, long long date, int duration, double inputTraffic, double outputTraffic)
        : Telephone(number, date, duration), inputTraffic(inputTraffic), outputTraffic(outputTraffic) {};

        Internet(const Internet&) = default;
        Internet(Internet&&) = default;


        [[nodiscard]] double getInputTraffic() const;
        void setInputTraffic(double inputTraffic);
        [[nodiscard]] double getOutputTraffic() const;
        void setOutputTraffic(double outputTraffic);

        std::string toString() override;
        TelephoneType getType() override;
        double getTraffic() override;

        Internet& operator= (const Internet&) = default;
        Internet& operator= (Internet&&) noexcept = default;
    };
}


#endif //OOP_LAB4_TELEPHONE_H
