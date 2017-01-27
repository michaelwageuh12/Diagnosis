#include <string>
#include "Patient.h"

Patient::Patient()
{
   age = 0;
   gender = 'm' ;
}


Patient::Patient(int age , char gender , Symptoms symptoms)
{
    this ->  age = age;
    this ->  gender = gender;
    this ->  symptoms = symptoms;
}

Patient::Patient(Patient &patient)
{
    this -> age = patient.age;
    this -> gender = patient.gender;
    this -> symptoms = patient.symptoms;
}

void Patient::setAge(int age)
{
    this -> age = age ;
}

void Patient::setGender(char gender)
{

     this -> gender = gender;
}


void Patient::setSymptoms( Symptoms symptoms)
{
    this -> symptoms = symptoms ;
}

int Patient::getAge()
{
    return age;
}

char Patient::getGender()
{
    return gender;
}

Symptoms Patient::getSymptoms()
{
    return symptoms;
}


Patient Patient::operator=(Patient & patient)
{
    this -> age      = patient.age;
    this -> gender   = patient.gender;
    this -> symptoms = patient.symptoms;
    return * this;
}


Patient::~Patient()
{

}
