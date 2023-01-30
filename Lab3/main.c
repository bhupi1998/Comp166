/* 
 * File:   main.c
 * Author: bhupinder singh
 *
 * Created on January 28, 2023, 6:16 p.m.
 * Objective: Computes height and velocity of a falling object
 *  including the effects of atmospheric drag
 * Inputs from user: drop height, mass, drag coefficient, cross-sectional
 *  area and time step size
 * Outputs: Height and velocity of the falling object at requested time interval
 */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// defining global values
#define g 9.807 //m/s^2
#define airDensitySea 1.225 //kg/m^3
// tried to import as header file but it didn't work. i ask next time
/*
 * Compute the density of dry air in SI units.
 * (Uses the global gravitational constant g).
 *
 * @param altitude Altitude in metres above mean sea level
 *
 * @return Density in SI units
 * 
 * Author: Dale
 */
double densityFunction(double altitude) {
  const double p0 = 101.325e3; // Sea-level std atmospheric pressure, Pascals
  const double T0 = 288.15;    // Sea-level std temperature, Kelvins
  const double L  = 0.0065;    // Temperature lapse rate, K/m
  const double R  = 8.31447;   // Ideal gas constant, J/(mol.K)
  const double M  = 0.0289644; // Molar mass of dry air, kg/mol
  double p, T;
  T = T0 - L*altitude;
  p = p0 * pow((1 - (L*altitude)/T0), (g*M)/(R*L));
  return p*M/(R*T);
}

// inputs: mass, drag coefficient, density, area, velocity(to calculate drag)
// returns: The acceleration experienced by the object.
// calculates the acceleration by finding the net force experienced
//  by the object.
double netAcceleration(double dragCoefficient, double density, int mass, double crossArea, double velocity){
    // drag force
    double fDrag= 0.5*dragCoefficient*density*crossArea*pow(velocity,2);
    double fGravity = mass*g;
    // returns acceleration, it will never be negative as it will always be accelerating down or 0
    return (fGravity-fDrag)/mass;
}

// Inputs: timeStep, acceleration, initial velocity
// Returns: Object's velocity
// It uses the time interval and acceleration to calculate delta velocity
//  and adds it to the previous known velocity to find the new velocity
double newVelocity(double timeStep, double acceleration, double initVelocity){
    return timeStep*acceleration+initVelocity;
}

// Inputs: initial height, time step, velocity
// returns: new height
// Calculates the distance travelled by the object using time and velocity.
//  The distance travelled is subtracted by the object's current height
//      to find the new height
double newHeight(double currentHeight, double timeStep, double velocity){
    return currentHeight-timeStep*velocity;
}
int main() {
    // terminalVelHyper is the terminal velocity found using the formula on hyperphysics
    double dragCoefficient, crossSecArea, timeStep, acceleration, height, terminalVelHyper;
    int mass;
    // setting initial values for object
    double velocity=0;
    double time=0;
    
    // if something goes wrong this gets set to 1 and stops the loop.
    int error=0;
    //  requesting all inputs
    printf("Enter the height in metres: ");
    scanf("%lf", &height);
    printf("\nEnter the mass in kg: ");
    scanf("%d", &mass);
    printf("\nEnter the drag coefficient: ");
    scanf("%lf", &dragCoefficient);
    printf("\nEnter the cross-sectional area: "); 
    scanf("%lf", &crossSecArea);
    printf("\nEnter the time step size: ");
    scanf("%lf", &timeStep);   
    
    // invalid input has been entered. Stop the program
    if(getchar() != '\n'){
        while(getchar() != '\n'){
        }
        printf("\nInvalid Input. Goodbye\n");
        error=1;
    }
    // if there's an error, stop the program
    if(error){
        exit(0);
    }
    // display the data and do the calculations while height is above 0
    printf("\nTime    Height  Velocity\n");
    for(int i=0; (i<=100000)&&(height>0); i++){
        printf("%6.2lf  %6.1lf  %6.2lf\n",time,height,velocity);    
        acceleration = netAcceleration(dragCoefficient, densityFunction(height), mass, crossSecArea, velocity);
        velocity = newVelocity(timeStep, acceleration, velocity);
        height = newHeight(height, timeStep, velocity);
        time+=timeStep;
    }
    // theoretical terminal velocity using the formula provided by
    //  hyperphysics @ http://hyperphysics.phy-astr.gsu.edu/hbase/airfri2.html
    terminalVelHyper = sqrt((2*mass*g)/(dragCoefficient*airDensitySea*crossSecArea));
    printf("Theoretical terminal velocity at sea level is %0.1lf m/s\n", terminalVelHyper);
    return (EXIT_SUCCESS);
}


