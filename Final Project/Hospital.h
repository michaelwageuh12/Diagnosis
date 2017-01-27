#ifndef HOSPITAL_H
#define HOSPITAL_H
#include<string>
#include "Department.h"

using namespace std ;
class Hospital
{
    public:
        Hospital();
        Hospital(string , int , Department* ) ;
        Hospital(Hospital&) ;
        void setName(string name) ;
        void setDepartmentsSize ( int );
        void setDepartments( Department * ) ;
        string getName() ;
        int getDepartmentsSize ();
        Department * getDepartments() ;
        Hospital operator = (Hospital&);
        virtual ~Hospital();
    private:
        string name ;
        Department * departments;
        int departmentsSize;
};

#endif // HOSPITAL_H
