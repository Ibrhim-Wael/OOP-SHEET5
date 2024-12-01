#include <iostream>
using namespace std;

class VehicleManagment{
private:
int vehicle_id;
string model_name;
double mileage;
static int numberOfvehicles;
public:
VehicleManagment(int id,string name,double mileag):vehicle_id(id),model_name(name),mileage(mileag){
    numberOfvehicles++;
}// Constructor Initializes the members with increases static member
void drive(double driven);
double getmileage()const;
static int getnumber(){
    return numberOfvehicles;
}//static function to return number of vehicles
};
int VehicleManagment::numberOfvehicles=10; //Given the static an initail value of 10.
void VehicleManagment::drive(double driven){mileage+=driven;}//drive function increases miles diven
double VehicleManagment::getmileage()const{return mileage;}//return mileage


int main(){
    VehicleManagment v1(765,"Porche",800);
    cout<<VehicleManagment::getnumber()<<endl;//11
    v1.drive(500);
    cout<<v1.getmileage()<<endl;//500+800=1300
    VehicleManagment v2(766,"Hyundai",988);
    cout<<VehicleManagment::getnumber()<<endl;//12
    v2.drive(112);
    cout<<v2.getmileage()<<endl;//988+112=1100
    const VehicleManagment v3(8263,"Mercedes",10000);
    //*v3.drive(900);* can not be done beacuse drive is not const
    cout<<v3.getmileage()<<endl;//it will work beacuse the function getmiealge is const also
    cout<<VehicleManagment::getnumber()<<endl;//13
}
