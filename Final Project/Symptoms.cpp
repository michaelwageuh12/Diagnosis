#include <iostream>
#include <string>
#include "Symptoms.h"
using namespace std ;

Symptoms::Symptoms()
{

}

Symptoms::Symptoms( string * symptoms )
{
    this -> symptoms = new string [symptomsSize];
    for ( int i = 0 ; i < symptomsSize ; i++ ){
        this -> symptoms[i] = symptoms[i];
    }
}
Symptoms::Symptoms(Symptoms &Symptoms1 )
{
    symptomsSize = Symptoms1.symptomsSize;
    symptoms = new string [symptomsSize];
    for ( int i = 0 ; i < symptomsSize ; i++ )
    {
        symptoms[i] = Symptoms1.symptoms[i];
    }
}

void Symptoms::setSymptomsSize ( int symptomsSize )
{
    this -> symptomsSize = symptomsSize;
}

void Symptoms::setSymptoms( string * symptoms )
{
    this -> symptoms = new string [symptomsSize];
    for ( int i = 0 ; i < symptomsSize ; i++ )
    {
        this -> symptoms[i] = symptoms[i];
    }
}

int Symptoms::getSymptomsSize ()
{
    return symptomsSize;
}

string* Symptoms::getSymptoms()
{
    return symptoms ;
}
Symptoms Symptoms :: operator = ( Symptoms &s )
{
    symptomsSize = s.symptomsSize;
    symptoms = new string[symptomsSize] ;
    for ( int i = 0 ; i < symptomsSize ; i++ )
    {
         symptoms[i] = s.symptoms[i];
    }
    return *this ;
}
Symptoms::~Symptoms()
{

}
