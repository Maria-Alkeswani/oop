
#include <iostream>
#include <fstream>
#include <string>
#include "Car.hpp"
using namespace std;
using namespace namespace_1;

int main()
{

 // Exercise 1: Vehicles
cout<<endl<<"Exercise 1: Vehicles"<<endl<<endl;

Car x1;

Bike x2;

Vehicle x3;

x1.print();

x2.print();
    
x3.print();


 // Exercise 2: Figuring Out What the Code Does...
cout<<endl<<"Exercise 2: Figuring Out What the Code Does..."<<endl<<endl;

Vehicle *v1= new Car();

Vehicle *v2= new Bike();

v1->print();
v2->print();

 // Exercise 3: Deadly Diamonds
cout<<endl<<"Exercise 3: Deadly Diamonds"<<endl<<endl;
Amphicar y1;
y1.print();


 // Exercise 4: Streams and Files
cout<<endl<<"Exercise 4: Streams and Files"<<endl<<endl;

ifstream file("vehicles.txt");

Vehicle *arr[100];

string str;

int i=0;

while(getline(file,str))
{

//cout<<str<<endl;

if(str=="car") arr[i++]=new Car();
if(str=="bike") arr[i++]=new Bike();
if(str=="amphicar") arr[i++]=new Amphicar();

}

	return 0;
}



