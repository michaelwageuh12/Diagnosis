#ifndef SYMPTOMS_H_INCLUDED
#define SYMPTOMS_H_INCLUDED
#include <string>
using namespace std ;


class Symptoms {
private:
    string *  symptoms;
    int symptomsSize;
public:
    Symptoms() ;
    Symptoms( string * ) ;
    Symptoms( Symptoms & ) ;
    void setSymptomsSize ( int );
    void setSymptoms( string * ) ;
    int getSymptomsSize ();
    string * getSymptoms() ;
    Symptoms operator= ( Symptoms &) ;
    ~Symptoms() ;
};

#endif // SYMPTOMS_H_INCLUDED
