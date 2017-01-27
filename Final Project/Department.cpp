#include <string>
#include "Department.h"
#include "Disease.h"
#include "Doctor.h"

using namespace std ;
Department::Department ()
{
    name = " " ;
}
Department :: Department ( string name , int doctorsSize , Doctor * doctors , int diseasesSize, Disease * diseases )
{
    this -> name = name;
    this -> doctorsSize = doctorsSize;
    this -> doctors = new Doctor [doctorsSize];
    for ( int i = 0 ; i < doctorsSize ; i++ ){
        this -> doctors[i] = doctors[i];
    }
    this -> diseasesSize = diseasesSize;
    this -> diseases = new Disease [diseasesSize];
    for ( int i = 0 ; i < diseasesSize ; i++ ){
        this -> diseases[i] = diseases[i];
    }
}

Department :: Department ( Department &department )
{
    this -> name = department.name ;
    this -> doctorsSize = department.doctorsSize;
    this -> doctors = new Doctor [doctorsSize];
    for ( int i = 0 ; i < doctorsSize ; i++ ){
        doctors[i] = department.doctors[i];
    }
    this -> diseasesSize = department.diseasesSize;
    this -> diseases = new Disease[diseasesSize];
    for ( int i = 0 ; i < diseasesSize ; i++ ){
        diseases[i] = department.diseases[i];
    }
}


void Department :: setName( string name )
{
    this -> name = name ;
}

void Department :: setDoctorsSize ( int doctorsSize )
{
    this -> doctorsSize = doctorsSize;
}

void Department :: setDoctors( Doctor * doctors )
{
    this -> doctors = new Doctor [doctorsSize];
    for ( int i = 0 ; i < doctorsSize ; i++ ){
        this -> doctors[i] = doctors[i];
    }
}

void Department :: setDiseasesSize ( int diseasesSize )
{
    this -> diseasesSize = diseasesSize;
}

void Department :: setDiseases ( Disease * diseases )
{
    this -> diseases = new Disease[diseasesSize];
    for ( int i = 0 ; i < diseasesSize ; i++ ){
        this -> diseases[i] = diseases[i];
    }

}
string  Department ::getName()
{
  return name;

}

int Department :: getDoctorsSize ()
{
    return doctorsSize;
}

Doctor * Department::getDoctors()
{
  return doctors ;
}

int Department :: getDiseasesSize ()
{
    return diseasesSize;
}

Disease * Department :: getDiseases()
{
    return diseases ;
}
Department Department :: operator = ( Department &department )
{
    this -> name = department.name ;
    this -> doctorsSize = department.doctorsSize;
    this -> doctors = new Doctor [doctorsSize];
    for ( int i = 0 ; i < doctorsSize ; i++ ){
        doctors[i] = department.doctors[i];
    }
    this -> diseasesSize = department.diseasesSize;
    this -> diseases = new Disease[diseasesSize];
    for ( int i = 0 ; i < diseasesSize ; i++ ){
        diseases[i] = department.diseases[i];
    }
    return *this ;
}

Department ::~Department ()
{
    delete [] diseases;
    delete [] doctors;

}
