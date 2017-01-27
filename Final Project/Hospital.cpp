#include <string>
#include "hospital.h"
#include "Department.h"

using namespace std ;

Hospital::Hospital()
{

}

Hospital:: Hospital( string name , int departmentsSize , Department * departments )
{
    this -> name = name ;
    this -> departmentsSize = departmentsSize;
    this -> departments = new Department [departmentsSize];
    for ( int i = 0 ; i < departmentsSize ; i++ ){
        this -> departments[i] = departments[i];
    }
}

Hospital::Hospital( Hospital &hospital )
{
    this -> name = hospital.name ;
    this -> departmentsSize = hospital.departmentsSize;
    this -> departments = new Department[departmentsSize];
    for ( int i = 0 ; i < departmentsSize ; i++ ){
        this -> departments[i] = hospital.departments[i];
    }
}

void Hospital:: setName(string name)
{
    this -> name = name ;
}

void Hospital :: setDepartmentsSize ( int departmentsSize )
{
    this -> departmentsSize = departmentsSize;
}


void Hospital :: setDepartments( Department * departments )
{
    this -> departments = new Department [departmentsSize];
    for ( int i = 0 ; i < departmentsSize ; i++ ){
        this -> departments[i] = departments[i];
    }
}

string Hospital::getName()
{
    return this -> name ;
}

int Hospital :: getDepartmentsSize ()
{
    return departmentsSize;
}

Department * Hospital :: getDepartments()
{
    return departments;
}

Hospital Hospital::operator = ( Hospital &hospital )
{
    this -> name = hospital.name ;
    this -> departmentsSize = hospital.departmentsSize;
    this -> departments = new Department[departmentsSize];
    for ( int i = 0 ; i < departmentsSize ; i++ ){
        departments[i] = hospital.departments[i];
    }

    return *this ;
}

Hospital::~Hospital()
{
    delete [] departments;
}
