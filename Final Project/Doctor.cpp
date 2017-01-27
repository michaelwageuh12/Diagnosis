#include "Doctor.h"
#include "Person.h"
using namespace std;
Doctor::Doctor()
{

}

Doctor::Doctor(int ID)
{
    this->ID = ID ;
}
Doctor::Doctor (Doctor &doctor)
{
    this ->ID = doctor.ID ;
}
void Doctor::setID(int ID)
{
    this -> ID = ID;
}
int Doctor::getID()
{
    return ID;
}
Doctor::~Doctor()
{

}
