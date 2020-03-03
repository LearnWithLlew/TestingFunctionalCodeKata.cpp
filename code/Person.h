#ifndef TESTINGFUNCTIONALCODEKATA_PERSON_H
#define TESTINGFUNCTIONALCODEKATA_PERSON_H

#include <string>
#include <ostream>
#include <sstream>

#include "Macros.h"

class Person
{
public:
    const std::string name_;
    int age_;
    double heightInM_;
    int weightInLbs_;
    const std::string street_;
    const std::string town_;
    const std::string county_;
    const std::string country_;
    const std::string continent_;

    Person(const std::string& name,
           int age,
           double heightInM,
           int weightInLbs,
           const std::string& street,
           const std::string& town,
           const std::string& county,
           const std::string& country,
           const std::string& continent)
        : name_(name)
        , age_(age)
        , heightInM_(heightInM)
        , weightInLbs_(weightInLbs)
        , street_(street)
        , town_(town)
        , county_(county)
        , country_(country)
        , continent_(continent)
    {
    }

    friend std::ostream& operator<<(std::ostream& os, const Person& person)
    {
        os << "name: " << person.name_ << " age: " << person.age_
           << " heightInM: " << person.heightInM_
           << " weightInLbs: " << person.weightInLbs_
           << " street: " << person.street_ << " town: " << person.town_
           << " county: " << person.county_ << " country: " << person.country_
           << " continent: " << person.continent_;
        return os;
    }

    std::string toString() const
    {
        std::stringstream s;
        s << *this;
        return s.str();
    }

    void appleSauce()
    {
        DO_STUFF
    }

    static Person getAveragePerson(const std::string& name)
    {
        return Person(name,
                      35,
                      1.8,
                      195,
                      "4 Privet Drive",
                      "Little Whinging",
                      "Surrey",
                      "England",
                      "Europe");
    }
};

#endif //TESTINGFUNCTIONALCODEKATA_PERSON_H
