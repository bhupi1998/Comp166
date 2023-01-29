/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.c
 * Author: bhupi
 *
 * Created on January 28, 2023, 6:16 p.m.
 */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

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

//returns the value of acceleration
// inputs: mass, drag coefficient, density, area
double netAcceleration(double dragCoefficient, double density, int mass, double crossArea, double velocity){
    // drag force
    double fDrag= 0.5*dragCoefficient*density*crossArea*pow(velocity,2);
    double fGravity = mass*g;
    // returns acceleration, it will never be negative as it will always be accelerating down or 0
    return (fGravity-fDrag)/mass;
}

double newVelocity(double timeStep, double acceleration, double initVelocity){
    return timeStep*acceleration+initVelocity;
}

double newHeight(double initHeight, double timeStep, double velocity){
    return initHeight-timeStep*velocity;
}
int main() {
    // terminalVelHyper is the terminal velocity found using the formula on hyperphysics
    double dragCoefficient, crossSecArea, timeStep, acceleration, height, terminalVelHyper;
    int mass;
    double velocity=0;
    double time=0;
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
    
    printf("\nTime    Height  Velocity\n");
    for(int i=0; (i<=100000)&&(height>0); i++){
        printf("%0.2lf  %0.1lf  %0.2lf\n",time,height,velocity);    
        acceleration = netAcceleration(dragCoefficient, densityFunction(height), mass, crossSecArea, velocity);
        velocity = newVelocity(timeStep, acceleration, velocity);
        height = newHeight(height, timeStep, velocity);
        time+=timeStep;
    }
    terminalVelHyper = sqrt((2*mass*g)/(dragCoefficient*airDensitySea*crossSecArea));
    printf("Theoretical terminal velocity at sea level is %0.1lf m/s\n", terminalVelHyper);
    return (EXIT_SUCCESS);
}


