#include "Disease.h"
#include "Symptoms.h"
#include <string>
#include <iostream>

using namespace std;

Disease :: Disease ()
{
    name = "";
    Ratio = 0;
    treatment = new string [2];
}

Disease :: Disease ( string name , Symptoms diseaseSymptoms , Symptoms patientSymptoms , string * treatment )
{
    this -> name = name;
    this -> diseaseSymptoms = diseaseSymptoms;
    this -> patientSymptoms = patientSymptoms;
    this -> treatment = treatment;
}


Disease :: Disease (Disease & disease )
{
    name = disease.name;
    Ratio = disease.Ratio;
    diseaseSymptoms = disease.diseaseSymptoms;
    patientSymptoms = disease.patientSymptoms;
    treatment = new string [2];
    for ( int i = 0 ; i < 2 ; i++ )
    {
        treatment[i] = disease.treatment[i];
    }
}


void Disease :: setName ( string name )
{
    this -> name = name;
}

void Disease :: setRatio ( double Ratio )
{
    this -> Ratio = Ratio;
}

void Disease :: setDiseaseSymptoms ( Symptoms diseaseSymptoms )
{
    this -> diseaseSymptoms = diseaseSymptoms;
}

void Disease :: setPatientSymptoms ( Symptoms patientSymptoms )
{
    this -> patientSymptoms = patientSymptoms;
}

void Disease :: setTreatment ( string * treatment )
{
    this -> treatment = treatment;
}

string Disease :: getName ()
{
    return name;
}

double Disease :: getRatio ()
{
    return Ratio;
}

Symptoms Disease :: getDiseaseSymptoms ()
{
    return diseaseSymptoms;
}

Symptoms Disease :: getPatientSymptoms ()
{
    return patientSymptoms;
}

string * Disease :: getTreatment ()
{
    return treatment;
}

double Disease :: symptomsComparison ()
{
    int symptomsCounter = 0;
    for ( int i = 0 ; i < patientSymptoms.getSymptomsSize() ; i++ ){
        for ( int j = 0 ; j < diseaseSymptoms.getSymptomsSize() ; j++ ){
            if ( patientSymptoms.getSymptoms()[i] == diseaseSymptoms.getSymptoms()[j] ){
                symptomsCounter += 1;
                break;
            }
        }
    }
    Ratio = symptomsCounter*1.0/diseaseSymptoms.getSymptomsSize();

    return Ratio;
}

Disease Disease :: operator = ( Disease &disease )
{
    name = disease.name;
    Ratio = disease.Ratio;
    diseaseSymptoms = disease.diseaseSymptoms;
    patientSymptoms = disease.patientSymptoms;
    treatment = new string [2];
    for ( int i = 0 ; i < 2 ; i++ )
    {
        treatment[i] = disease.treatment[i];
    }
    return *this;
}

Disease :: ~Disease ()
{
    delete [] treatment;
}


