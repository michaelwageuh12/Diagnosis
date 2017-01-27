#ifndef DISEASE_H
#define DISEASE_H
#include "Symptoms.h"
#include <string>

using namespace std;


class Disease
{
    public:
        Disease();
        Disease( string , Symptoms , Symptoms , string * );
        Disease ( Disease & disease );
        void setName ( string );
        void setRatio ( double );
        void setDiseaseSymptoms ( Symptoms );
        void setPatientSymptoms ( Symptoms );
        void setTreatment ( string * );
        string getName ();
        double getRatio ();
        Symptoms getDiseaseSymptoms ();
        Symptoms getPatientSymptoms ();
        string * getTreatment ();
        double symptomsComparison ();
        Disease operator = ( Disease & );
        ~Disease ();
    private:
        string name;
        double Ratio;
        Symptoms diseaseSymptoms;
        Symptoms patientSymptoms;
        string * treatment;
};

#endif // DISEASE_H
