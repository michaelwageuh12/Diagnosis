#ifndef PERSON_H
#define PERSON_H
#include <iostream>
#include <string>
using namespace std;

class Person
{
    public:
        Person();
        Person ( string name , string mobileNumber );
        Person( Person &person );
        void setName(string name);
        void setMobileNumber(string mobileNumber);
        string getName();
        string getMobileNumber();
        Person operator=(Person& person);
        ~Person();
    protected:
        string name;
        string mobileNumber;
};

#endif // PERSON_H
