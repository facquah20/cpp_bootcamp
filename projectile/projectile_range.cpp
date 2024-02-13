#include <iostream>
#include <cmath>


int main(){

	std::cout<<"Console Application to calculate Projectile Range\n\n";

	//declaring constant
	const float gravity = 9.81; // in m/s^2
	const float PI = 3.142;

	float initialVelocity = 0;
	float projectionAngle = 0.0;

	std::cout<<"\nInitial Velocity: ";
	std::cin>>initialVelocity;

	std::cout<<"\nAngle of Projection: ";
	std::cin>>projectionAngle;


	// we need to convert the projection angle to radians
	// This is because the cos, sin, and tan functions in C++ 
	// accepts angle measurement in radians
	float projectionAngletoRadian = (projectionAngle/180)*PI;

	//calculating the range 
	float range = (2*initialVelocity*sin(projectionAngletoRadian))/gravity;

	std::cout<<"\nThe range of the Projectile is:  "<<range<<"m"<<std::endl;

	return 0;
}