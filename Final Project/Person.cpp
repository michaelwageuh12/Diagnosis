#include "Person.h"

using namespace std ;

Person::Person()
{
    name = " " ;
    mobileNumber = "00000000000" ;
}
Person::Person(string name, string mobileNumber)
{
    this->name =  name ;
    this->mobileNumber = mobileNumber;
}
Person::Person( Person& person)
{
    this->name = person.name;
    this->mobileNumber = person.mobileNumber;
}
void Person::setName(string name)
{
    this->name = name;
}
void Person::setMobileNumber(string mobileNumber)
{
    this-> mobileNumber = mobileNumber;
}
string Person::getName()
{
    return name;
}
string Person::getMobileNumber()
{
    return mobileNumber;
}
Person Person::operator=(Person& person)
{
    this->name = person.name;
    this->mobileNumber = person.mobileNumber;
    return *this;
}
Person::~ Person()
{


}
