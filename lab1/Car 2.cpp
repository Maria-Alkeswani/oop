#include "Car.hpp"
#include <iostream>
#include<string>

using namespace std;
using namespace namespace_1;
double namespace_1::Wheel::getter_rpm()
{
	return this->rpm;
}
//-----------------------------------------------------part 1
bool namespace_1::Wheel::setter_rpm(double r)
{
	bool test = false;
	this->rpm = r;
	test=true;
	return test;
}

double namespace_1::Wheel::getter_angle()
{
	return this->angle;
}

bool namespace_1::Wheel::setter_angle(double a)
{
	bool test = false;
	this->angle = a;
	test=true;
	return test;
}

double namespace_1::Wheel::getter_radius()
{
	return this->radius;
}

namespace_1::Wheel::Wheel(double r)
{
	radius = r;
}

namespace_1::Wheel::Wheel()
{
	rpm=0;
	radius=0;
	angle=0;
	pressure=0;

}

//-----------------------------------------------------part 2
bool namespace_1::Wheel::operator== (Wheel a)
{
	double s1, s2;
	s1 = radius*rpm;
	s2 = a.radius*a.rpm;
	if (s1 == s2)
		return true;
	else
		return false;
}

bool namespace_1::Wheel::operator!= (Wheel a)
{
	double s1, s2;
	s1 = radius*rpm;
	s2 = a.radius*a.rpm;
	if (s1 != s2)
		return true;
	else
		return false;
}


bool namespace_1::Wheel::operator>= (Wheel a)
{
	double s1, s2;
	s1 = radius*rpm;
	s2 = a.radius*a.rpm;
	if (s1 >= s2)
		return true;
	else
		return false;
}

bool namespace_1::Wheel::operator<= (Wheel a)
{
	double s1, s2;
	s1 = radius*rpm;
	s2 = a.radius*a.rpm;
	if (s1 <= s2)
		return true;
	else
		return false;
}

bool namespace_1::Wheel::operator< (Wheel a)
{
	double s1, s2;
	s1 = radius*rpm;
	s2 = a.radius*a.rpm;
	if (s1<s2)
		return true;
	else
		return false;
}

bool namespace_1::Wheel::operator> (Wheel a)
{
	double s1, s2;
	s1 = radius*rpm;
	s2 = a.radius*a.rpm;
	if (s1>s2)
		return true;
	else
		return false;
}
//------------------------------------------------------------
void namespace_1::Pump::setPressured(Wheel &a, double k)
{
	a.pressure = k;
}

double namespace_1::Pump::getPressured(Wheel a)
{
	return a.pressure;
}
//------------------------------------------------------------

//------------------------------------------------------------------------Car---------------------



void namespace_1::Car::setter_car(std::string str, Color c, int w, double linear, double angular)
{
	model = str;
	color = c;
	weight = w;
	linearVelocity = linear;
	angularVelocity = angular;
	
	rrWheel->radius=linearVelocity/angularVelocity;
	rlWheel->radius=linearVelocity/angularVelocity;
	flWheel->radius=linearVelocity/angularVelocity;
	frWheel->radius=linearVelocity/angularVelocity;

	rrWheel->rpm=linearVelocity/rrWheel->radius;
	rlWheel->rpm=linearVelocity/rlWheel->radius;
	flWheel->rpm=linearVelocity/flWheel->radius;
	frWheel->rpm=linearVelocity/frWheel->radius;


}

void namespace_1::Car::getter_car()
{

	std::cout << "Model: " << model << std::endl;
	std::cout << "Color: " << get_color(color) << std::endl;
	std::cout << "Weight: " << weight << std::endl;
	std::cout << "linearVelocity: " << linearVelocity << std::endl;
	std::cout << "angularVelocity: " << angularVelocity << std::endl;




}

std::string namespace_1::Car::get_color(Color c)
{

	switch (c)
	{
	case red: return "red"; break;
	case green: return "green"; break;
	case blue: return "blue"; break;
	case black: return "black"; break;

	}
	return "not found";

}
/*
void * operator new(size_t size)
{
    cout << "New operator overloading " << endl;
    void * p = malloc(size);
    return p;
}
 */



namespace_1::Car::Car()
{
	std::cout << "Default Constructor" << std::endl;

	linearVelocity = 0;    //speed linear equal 0
	angularVelocity = 0;   //speed angular equal 0

	



	color = black;
	weight = 0;
	model = "NULL";
	rrWheel=new namespace_1::Wheel;
	rlWheel=new namespace_1::Wheel;
	flWheel=new namespace_1::Wheel;
	frWheel=new namespace_1::Wheel;

	rrWheel->radius=1;
	rlWheel->radius=1;
	flWheel->radius=1;
	frWheel->radius=1;

	rrWheel->rpm=0;
	rlWheel->rpm=0;
	flWheel->rpm=0;
	frWheel->rpm=0;


	std::cout << "Model: " << model << std::endl;
}

namespace_1::Car::Car(Car &ob)
{
	std::cout << "Copy Constructor" << std::endl;

	linearVelocity = ob.linearVelocity;
	angularVelocity = ob.angularVelocity;
	color = ob.color;
	weight = ob.weight;
	model = ob.model;

	rrWheel=ob.rrWheel;
	rlWheel=ob.rlWheel;
	flWheel=ob.flWheel;
	frWheel=ob.frWheel;


	std::cout << "Model: " << model << std::endl;

}


namespace_1::Car::Car(std::string str)
{
	std::cout << "Non-Default Constructor" << std::endl;
	linearVelocity = 0;    //speed linear equal 0
	angularVelocity = 0;   //speed angular equal 0

	rrWheel=new namespace_1::Wheel;
	rlWheel=new namespace_1::Wheel;
	flWheel=new namespace_1::Wheel;
	frWheel=new namespace_1::Wheel;

	rrWheel->radius=1;
	rlWheel->radius=1;
	flWheel->radius=1;
	frWheel->radius=1;

	rrWheel->rpm=0;
	rlWheel->rpm=0;
	flWheel->rpm=0;
	frWheel->rpm=0;


	color = black;
	weight = 0;
	model = str;



	std::cout << "Model: " << model << std::endl;
}


bool namespace_1::Car::setSpeed(double speed)
{
	double s1,s2,s3,s4;
	int s=0;
	s1=flWheel->radius * flWheel->rpm;
	s2=frWheel->radius * frWheel->rpm;
	s3=rlWheel->radius * rlWheel->rpm;
	s4=rrWheel->radius * rrWheel->rpm;
	
	if(s1>=speed) s++;
	if(s2>=speed) s++;
	if(s3>=speed) s++;
	if(s4>=speed) s++;

	if(s==4)
	{
		flWheel->rpm=speed/flWheel->radius;
		frWheel->rpm=speed/frWheel->radius;
		rlWheel->rpm=speed/rlWheel->radius;
		rrWheel->rpm=speed/rrWheel->radius;
		return true;

	}
	else 
	return false;

}

	bool namespace_1::Car::setTurningAngle(double ang)
	{
	if(ang<=45 && ang>=-45)
	{flWheel->setter_angle(ang);
	frWheel->setter_angle(ang);
	return true;
	}
	else
	return false;
	}


	void namespace_1::Car::get_rpm_radius()
	{
		cout<<"flWheel: rpm= "<<flWheel->rpm<<"  ,  radius= "<<flWheel->radius<<endl;
		cout<<"frWheel: rpm= "<<frWheel->rpm<<"  ,  radius= "<<frWheel->radius<<endl;
		cout<<"rlWheel: rpm= "<<rlWheel->rpm<<"  ,  radius= "<<rlWheel->radius<<endl;
		cout<<"rrWheel: rpm= "<<rrWheel->rpm<<"  ,  radius= "<<rrWheel->radius<<endl;

	}

