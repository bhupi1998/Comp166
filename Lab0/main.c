
/* 
 * File:   main.c
 * Author: C0522200
 *
 * Created on January 10, 2023, 8:38 a.m.
 */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

const int N_POWERS = 5; //Declare an integer constant
// Every C program has a function named "main". It is the starting point when it runs.
int main(void) {
    // Variables must be declared before they can be used
    double a, b, sum, diff, z;
    
    //prompt user to enter two numbers
    printf("Enter two numbers: ");
    // Read those two numbers into the variable a and b
    scanf("%lf%lf", &a, &b);
    
    //Do some math
    sum = a + b;
    diff = a-b;
    
    //Print the results to the console
    printf("The sum of %lf and %lf is %lf\n", a, b, sum);
    printf("The difference of %lf and %lf is %lf\n", a, b, diff);
    
    // Use a for loop to repeatedly perform similar computations
    for (int k=0; k<=N_POWERS; k++) {
        z = pow(a, k ); // uses the math library function pow();
        printf("%lf raised to the power of %d is %lf\n", a, k, z);
    }
    double r;
    printf("Enter a radius: ");
    scanf("%lf", &r);
    double circleArea = 3.14*r*r;
    printf("The area of a circle is %lf\n", circleArea);
    return (EXIT_SUCCESS);
}

