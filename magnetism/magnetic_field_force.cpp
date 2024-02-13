#include <iostream>
#include <cmath>

//function overloading
float degree2Radians(const float degree);


int main(){

	// We are going to investigate how the Force exerted on a magnetic field changes with 
	// varying angle. From rigt hand rule the resultant force is perpendicular to the direction 
	// of the magnetic field and the velocity of the charged particle.
	// 
	// Hence F = (B X V)q , where the symbols have their usual meanings. 
	// F = Bqvsin@ where @ = angle theta. This gives the magnitude of the force
	// 
	// With this simulation, the angles will be varied while the other parameters remain constant.
	
	//declaring variables
	//
	std::cout<<"----------------------------------------------------------------------\n"
			<<"| SIMULATION OF FORCE AND ANGLE OF CHARGE PARTICLE IN A MAGNETIC FIELD|\n"
			<<"-----------------------------------------------------------------------\n\n";
	
	float angleStart;
	float angleEnd;
	float interval;
	double magnetForce;
	double fieldStrength;
	float velocity;
	float chargeMagnitude;

	std::cout<<"\nStarting angle(degrees): ";
	std::cin>>angleStart;

	std::cout<<"\nEnding angle(degrees): ";
	std::cin>>angleEnd;

	std::cout<<"\nAngle interval: ";
	std::cin>>interval;

	std::cout<<"Velocity(m/s) : ";
	std::cin>>velocity;

	std::cout<<"Magnitude of the charge(C): ";
	std::cin>>chargeMagnitude;

	std::cout<<"Magnetic field strength (T): ";
	std::cin>>fieldStrength;



	int simulationCountTotal = (angleEnd - angleStart)/interval; //total simulations that will run
	int simulationCount = 1 ; //tracks the simulation 

	std::cout<<"Force   |"<<"Angle  \n";

	while(angleStart != interval && simulationCount <= simulationCountTotal){

		float degreeAngle = (angleStart+(interval*simulationCount));

		//calculate force
		float radian  = degree2Radians(degreeAngle);

		magnetForce = fieldStrength*sin(radian)*chargeMagnitude*velocity;

		std::cout<<magnetForce<<"  |"<< degreeAngle<<"\n";

		simulationCount++;


	}

	std::cout<<"Simulation done\n Analyse your data.\n";

	return 0;
}

float degree2Radians(const float degree){
	const float PI = 3.142;
	return (degree/180)*PI;
}

