#include <bits/stdc++.h>
#include "Hospital.h"
#include "Department.h"
#include "Person.h"
#include "Doctor.h"
#include "Patient.h"
#include "Symptoms.h"
#include "Disease.h"

using namespace std;

string dotConverter( string );
void printList();
string departmentAndDisease ( int , int );
void printTreatment ( Symptoms , Department * , int , int );


int main()
{
    Hospital hospital;
    Department * departments = new Department [4];
    Disease * diseases = new Disease [7];
    Doctor * doctors = new Doctor [7];
    Patient patient;
    Symptoms patientSymptoms;

    string * currentPatientSymptoms = new string [29];
    int symptomsSize , diseasesSize , doctorsSize , age , doctorID;
    string diseaseName , departmentName , doctorName , mobileNumber , patientName;
    char gender;

    ifstream myFile1 , myFile2 , myFile3 , myFile4;
    ofstream myFile5 ;
    myFile1.open("Diseases.txt");
    myFile2.open("Symptoms Size.txt");
    myFile3.open("Departments.txt");
    myFile4.open("Doctors.txt");
    myFile5.open("Patients.txt" , ios::out | ios::app );


    for ( int i = 0 ; i < 7 ; i++ ){
        myFile2 >> symptomsSize;
        Symptoms symptomsObject;
        string * diseaseSymptoms = new string [symptomsSize];
        string * diseaseTreatment = new string [2];
        myFile1 >> diseaseName;
        for ( int j = 0 ; j < symptomsSize ; j++ ){
            myFile1 >> diseaseSymptoms[j];
            diseaseSymptoms[j] = dotConverter(diseaseSymptoms[j]) ;
        }
        symptomsObject.setSymptomsSize(symptomsSize);
        symptomsObject.setSymptoms(diseaseSymptoms);
        for ( int j = 0 ; j < 2 ; j++ ){
            myFile1 >> diseaseTreatment[j];
            diseaseTreatment[j] = dotConverter(diseaseTreatment[j]);
        }
        diseases[i].setName(diseaseName);
        diseases[i].setDiseaseSymptoms(symptomsObject);
        diseases[i].setTreatment( diseaseTreatment );
        delete [] diseaseSymptoms;
    }

    int diseasesCounter = 0;

    for ( int i = 0 ; i < 4 ; i++ ){
        myFile3 >> departmentName;
        myFile3 >> diseasesSize;
        Disease * diseasesTemp = new Disease [diseasesSize];
        departments[i].setName(dotConverter(departmentName));
        departments[i].setDiseasesSize(diseasesSize);
        for ( int j = 0 ; j < diseasesSize ; j++ ){
            diseasesTemp[j] = diseases[diseasesCounter];
            diseasesCounter += 1;
        }
        departments[i].setDiseases(diseasesTemp);
        delete [] diseasesTemp;
    }

    for ( int i = 0 ; i < 4 ; i++ ){
        myFile4 >> doctorsSize;
        Doctor * doctorsTemp = new Doctor [doctorsSize];
        for ( int j = 0 ; j < doctorsSize ; j++ ){
            myFile4 >> doctorName;
            myFile4 >> mobileNumber;
            myFile4 >> doctorID;
            doctorsTemp[j].setName(dotConverter(doctorName));
            doctorsTemp[j].setMobileNumber(mobileNumber);
            doctorsTemp[j].setID(doctorID);
        }
        departments[i].setDoctorsSize(doctorsSize);
        departments[i].setDoctors(doctorsTemp);
    }

    hospital.setDepartmentsSize(4);
    hospital.setDepartments(departments);
    cout << "                            -------------------------" << endl;
    cout << "                             Welcome to Our Hospital" << endl;
    cout << "                            -------------------------" << endl;
    cout << "Please, enter your name: ";
    getline(cin,patientName);
    cout << "Please, enter your gender: ";
    cin >> gender;
    try
    {
        if ( gender != 'm' && gender != 'f' && gender != 'M' && gender != 'F' )
            throw "You have entered a wrong gender!" ;
    }
    catch( const char* msg )
    {
        cout << "---------------------------------------" << endl;
        cout << msg << endl ;
        cout << "---------------------------------------" << endl;

        cout << "Please, enter m or f only: ";
        cin >> gender ;
    }
    cout << "Please, enter your age: ";
    cin >> age;
    try
    {
        if ( age <= 0 )
            throw "You have entered a wrong age!" ;
    }
    catch ( const char* msg )
    {
        cout << "---------------------------------------" << endl;
        cout << msg << endl ;
        cout << "---------------------------------------" << endl;
        cout << "Please, enter your age again: ";
        cin >> age;
    }

    cout << "Please, enter your mobile number : ";
    cin >> mobileNumber;

    system ("CLS");

    cout << "----------------------------------------------------------------------" << endl;
    cout << "Please, choose your symptoms and when you finish write the word done : " << endl;
    cout << "----------------------------------------------------------------------" << endl;
    printList();
    cout << endl;
    for ( int i = 0 ; i < 29 ; i++ ){
        getline(cin,currentPatientSymptoms[i]);
        if ( currentPatientSymptoms[i] == "done" ){
            patientSymptoms.setSymptomsSize(i);
            patientSymptoms.setSymptoms(currentPatientSymptoms);
            break;
        }
    }
    patient.setName(patientName);
    patient.setGender(gender);
    patient.setAge(age);
    patient.setMobileNumber(mobileNumber);
    patient.setSymptoms(patientSymptoms);
    printTreatment( patientSymptoms , hospital.getDepartments() , 4 , 7 );


    if(myFile5.is_open())
    {
        myFile5 << endl ;
        myFile5 << "Name : " << patient.getName() << '\n';
        myFile5 << "Gender : " << patient.getGender() << endl;
        myFile5 << "Age : " << patient.getAge() << endl;
        myFile5 << "Mobile Number : " << patient.getMobileNumber() << endl;
        cout << endl;
    }

    myFile1.close();
    myFile2.close();
    myFile3.close();
    myFile4.close();
    myFile5.close();

    delete [] departments;
    delete [] diseases;
    delete [] doctors;
    delete [] currentPatientSymptoms;

    return 0;
}

string dotConverter( string s ){
    for ( int i = 0 ; i < s.size() ; i++ )
        if ( s[i] == '.') s[i] = ' ' ;
    return s;
}

void printList(){
    ifstream file;
    string sos;
    file.open("Symptoms.txt");
    int x = 10;
    while( x ){
        getline(file , sos);
        cout<< sos << endl;
        x--;
    }
    file.close();
}

string departmentAndDisease ( int i , int j ){
    string s;
    s = i + '0';
    s += j + '0';
    return s;
}

void printTreatment ( Symptoms patientSymptoms , Department * departments , int departmentsSize , int diseasesSize )
{
    double diseasesRatio[diseasesSize];
    vector < pair < double , string > > sortingRatios(diseasesSize);
    int ratioCounter = 0;
    string s;
    for ( int i = 0 ; i < departmentsSize ; i++ ){
        for ( int j = 0 ; j < departments[i].getDiseasesSize() ; j++ ){
            departments[i].getDiseases()[j].setPatientSymptoms( patientSymptoms );
            diseasesRatio[ratioCounter] = departments[i].getDiseases()[j].symptomsComparison();
            s = departmentAndDisease(i,j);
            sortingRatios[ratioCounter].first = diseasesRatio[ratioCounter];
            sortingRatios[ratioCounter].second = s;
            ratioCounter ++;
        }
    }

    sort ( sortingRatios.rbegin() , sortingRatios.rend() );

    int departmentIndex;
    int diseaseIndex;

    for ( int i = 0 ; i < diseasesSize ; i++ ){
        if ( sortingRatios[0].first == 0 ) {
                cout << endl;
                cout << "---------------------------------------------------------------------------" << endl;
                cout << "We are so sorry but we don't have a treatment for your symptoms right now!" << endl;
                cout << "---------------------------------------------------------------------------" << endl;
                break;
        }
        departmentIndex = (sortingRatios[i].second)[0] - '0';
        diseaseIndex = (sortingRatios[i].second)[1] - '0';
        if ( i == 0 ){
            system ( "CLS" );
            cout << "-----------------" << endl;
            cout << "You might have :" << endl;
            cout << "-----------------" << endl;
            cout << endl;
        }
        if ( i > 0 && sortingRatios[i].first != sortingRatios[i-1].first ) break;
        cout << departments[departmentIndex].getDiseases()[diseaseIndex].getName()
             << " By " << sortingRatios[i].first*100.0 << "% of symptoms." << endl;
        cout << endl;
        cout << "------------------------------------------" << endl;
        cout << "The proposed treatment for "
             << departments[departmentIndex].getDiseases()[diseaseIndex].getName()
             << " is: " << endl;
        cout << "------------------------------------------" << endl;

        for ( int k = 0 ; k < 2 ; k++ ){
            cout << departments[departmentIndex].getDiseases()[diseaseIndex].getTreatment()[k] << endl;
        }
        cout << endl;
        cout << "------------------------------------------" << endl;
        cout << "It would be better if you check: " << endl;
        cout << "------------------------------------------" << endl;

        for ( int k = 0 ; k < departments[departmentIndex].getDoctorsSize() ; k++ ){
            cout << "Doctor " << departments[departmentIndex].getDoctors()[k].getName()
                 << "   " << departments[departmentIndex].getDoctors()[k].getMobileNumber()
                 << endl;
        }
        cout << endl;
        cout << "---------------------------------------------" << endl;
        cout << endl;
        cout << endl;
    }
    cout << endl;

}
