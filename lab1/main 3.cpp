#include <iostream>
#include "Car.hpp"
using namespace std;

int main()
{
	//-----------------------Wheel---------------------------
	// Exersize II:
	
	namespace_1::Wheel x1(4);
	x1.setter_rpm(50);
	x1.setter_angle(25);
	cout<<"x1(radius)= "<< x1.getter_radius()<<endl;
	cout << "x1(rpm)= " << x1.getter_rpm() << endl;
	cout << "x1(angle)= " << x1.getter_angle() << endl;
	

	// Exersize III: Make Friends
	namespace_1::Pump x2;
	double p = 235;
	x2.setPressured(x1, p);
	cout << "x1(pressured)= " << x2.getPressured(x1) << endl;
	// Exersize IV: Compare Wheels

	//Wheel y1
	namespace_1::Wheel y1(3);   // speed=2*3=6
	y1.setter_rpm(2);

	//Wheel y2
	namespace_1::Wheel y2(8);   // speed=8*4=32
	y2.setter_rpm(4);

	//Compare Wheels
	cout << endl << endl << "Compare Wheels (y1,y2):" << endl;

	cout << "------------------------------------------------------------" << endl;
	cout << "y1 == y2 :";
	if (y1==y2) cout << "yes" << endl; else cout << "no" << endl;
	
	cout << "-----------------------" << endl;
	cout << "y1 != y2 :";
	if (y1 != y2) cout << "yes" << endl; else cout << "no" << endl;

	cout << "-----------------------" << endl;
	cout << "y1 > y2 :";
	if (y1 > y2) cout << "yes" << endl; else cout << "no" << endl;

	cout << "-----------------------" << endl;
	cout << "y1 < y2 :";
	if (y1 < y2) cout << "yes" << endl; else cout << "no" << endl;

	cout << "-----------------------" << endl;
	cout << "y1 >= y2 :";
	if (y1 >= y2) cout << "yes" << endl; else cout << "no" << endl;

	cout << "-----------------------" << endl;
	cout << "y1 <= y2 :";
	if (y1 <= y2) cout << "yes" << endl; else cout << "no" << endl;

	cout << endl << endl;

	//------------------------Car---------------------------------

	// Exersize V: Create a Car && Exersize VI: Custom Constructors

	namespace_1::Car car1;            //Default Constructor >>>  linear and angular speed equal 0

	namespace_1::Car car2(car1);      //Copy Constructor 

	namespace_1::Car car3;
	car3 = car1;         //Copy Assignment Operator.


	// -----------------------------------

	namespace_1::Car car4("Honda");

	car1.setter_car("PMW",black, 120, 10, 2);    //setter for Car

	car1.getter_car();                   // getter for Car

	cout << "-----------------------" << endl;
	cout << "setSpeed(speed):";
	if (car1.setSpeed(7)) cout << "yes" << endl; else cout << "no" << endl;
	
	cout << "setSpeed(speed):";
	if (car1.setSpeed(15)) cout << "yes" << endl; else cout << "no" << endl;

	cout << "setSpeed(speed):";
	if (car1.setSpeed(10)) cout << "yes" << endl; else cout << "no" << endl;


	cout << "setTurningAngle(angle):";
	if (car1.setTurningAngle(30)) cout << "yes" << endl; else cout << "no" << endl;

	cout << "setTurningAngle(angle):";
	if (car1.setTurningAngle(60)) cout << "yes" << endl; else cout << "no" << endl;

	
	//Exercise VII: Shallow vs Deep

	cout<<endl<<"--------------------Car11-------------------------"<<endl<<endl;
	namespace_1::Car *car11=new namespace_1::Car;
	(*car11).setter_car("honda",red,140,10,2);

	cout << "Car11 setSpeed(speed):";
	if (car11->setSpeed(18)) cout << "yes" << endl; else cout << "no" << endl;
	cout << "Car11 setTurningAngle(angle):";
	if (car11->setTurningAngle(30)) cout << "yes" << endl; else cout << "no" << endl;

	car11->get_rpm_radius();

	cout<<endl<<"--------------------Car22-------------------------"<<endl<<endl;

	namespace_1::Car car22(*car11);

	cout << "Car22 setSpeed(speed):";
	if (car22.setSpeed(6)) cout << "yes" << endl; else cout << "no" << endl;
	cout << "Car22 setTurningAngle(angle):";
	if (car22.setTurningAngle(10)) cout << "yes" << endl; else cout << "no" << endl;

	car22.get_rpm_radius();
	

	cout<<endl<<"--------------------Delete Car11-------------------------"<<endl<<endl;
	delete car11;
	
	car22.get_rpm_radius();
	

	
	return 0;
}
