#ifndef PATIENT_H
#define PATIENT_H
#include <bits/stdc++.h>
#include "Person.h"
#include "Symptoms.h"
#include "Patient.h"

using namespace std;

class Patient : public Person
{
    private:
        int age;
        char gender;
        Symptoms symptoms;
    public:
        Patient();
        Patient(int , char , Symptoms);
        Patient(Patient &patient);
        void setAge(int);
        void setGender(char);
        void setSymptoms(Symptoms);
        int getAge();
        char getGender();
        Symptoms getSymptoms();
        Patient operator = (Patient &patient);
        ~Patient();
        protected:

};

#endif
