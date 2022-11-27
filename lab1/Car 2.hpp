
//g++ main.cpp car.cpp car.hpp -o main.exe

#include<iostream>
#include<string>
using namespace std;
enum Color { red, green, blue, black };

namespace namespace_1
{
	
	class Wheel
	{
	private:
		double radius;
		double rpm;
		double angle;
		double pressure;

	public:
		double getter_rpm();
		bool setter_rpm(double r);
		double getter_angle();
		bool setter_angle(double a);
		double getter_radius();
		Wheel(double r);
		Wheel();
		bool operator== (Wheel a);
		bool operator!= (Wheel a);
		bool operator>= (Wheel a);
		bool operator<= (Wheel a);
		bool operator< (Wheel a);
		bool operator> (Wheel a);
		friend class Pump;
		friend class Car;

		

	};


	
	class Pump
	{
	public:
		void setPressured(Wheel &a, double k);
		double getPressured(Wheel a); //without
	};

	

	class Car
	{

	private:

		double linearVelocity;
		double angularVelocity;
		Color color; //Color is enum
		int weight;
		std::string model;
		Wheel * flWheel; //Assume that Wheel is an external class
		Wheel * frWheel;
		Wheel * rlWheel;
		Wheel * rrWheel;

	public:


		bool setSpeed(double speed);
		bool setTurningAngle(double ang);
		void setter_car(std::string str, Color c, int w, double linear, double angular);
		void getter_car();
		std::string get_color(Color c);


		Car();
		Car(Car &ob);
		Car(std::string str);

		void get_rpm_radius();




	};

} // namespace namespace_1
