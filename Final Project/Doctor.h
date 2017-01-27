#ifndef DOCTOR_H
#define DOCTOR_H
#include "Person.h"

class Doctor : public Person
{
    public:
        Doctor ();
        Doctor( int ) ;
        Doctor ( Doctor& );
        void setID ( int );
        int getID();
        ~Doctor();
    private:
        int ID;           // Static
};

#endif // DOCTOR_H
