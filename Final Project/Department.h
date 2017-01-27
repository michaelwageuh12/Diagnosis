#ifndef DEPARTMENT _H
#define DEPARTMENT _H
#include <string>
#include "Doctor.h"
#include "Disease.h"

using namespace std ;

class Department
{
    public:
        Department();
        Department( string , int , Doctor * , int , Disease * ) ;
        Department( Department & ) ;
        void setName( string ) ;
        void setDoctorsSize ( int );
        void setDoctors( Doctor * ) ;
        void setDiseasesSize ( int );
        void setDiseases( Disease *);
        string getName() ;
        int getDoctorsSize();
        Doctor * getDoctors ();
        int getDiseasesSize ();
        Disease * getDiseases () ;
        Department operator =( Department& ) ;
        ~Department ();
    private:
        string name;
        Doctor * doctors;
        Disease * diseases;
        int diseasesSize;
        int doctorsSize;
};

#endif // DEPARTMENT _H
