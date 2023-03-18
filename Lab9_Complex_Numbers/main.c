/* 
 * File:   main.c
 * Author: bhupi
 *
 * Created on March 17, 2023, 4:57 p.m.
 */

#include <stdio.h>
#include <stdlib.h>
#include <libgen.h>
#include "complex.h"

/*
 * 
 */
int main(int argc, char** argv) {
    char mustBeIorJ[2];
    Complex x, y;
    Complex result;
    if (argc != 3) {
        fprintf(stderr, "Usage %s vectorReal(+-)vectorImaginary vectorReal(+-)vectorImaginary\n", basename(argv[0]));
        return EXIT_FAILURE;
    }
    if(sscanf(argv[1], "%lf%lf%1[ij]", &x.re, &x.im, mustBeIorJ) != 3){
        fprintf(stderr, "%s: Invalid number format", basename(argv[0]));
        return EXIT_FAILURE;
    }
    if(sscanf(argv[2], "%lf%lf%1[ij]", &y.re, &y.im, mustBeIorJ) != 3){
        fprintf(stderr, "%s: Invalid number format", basename(argv[0]));
        return EXIT_FAILURE;
    }

    printf("x            =  " Z_FORMAT "\n", x.re, x.im);
    printf("y            =  " Z_FORMAT "\n", y.re, y.im);
    result = add(x, y);
    printf("Sum          =  " Z_FORMAT "\n", result.re, result.im);

    result = subtract(x, y);
    printf("Difference   =  " Z_FORMAT "\n", result.re, result.im);

    result = multiply(x, y);
    printf("Product      =  " Z_FORMAT "\n", result.re, result.im);

    result = divide(x, y);
    printf("Quotient     =  " Z_FORMAT "\n", result.re, result.im);

    result = conjugate(x);
    printf("x Conjugate  =  " Z_FORMAT "\n", result.re, result.im);

    result = conjugate(y);
    printf("y Conjugate  =  " Z_FORMAT "\n", result.re, result.im);

    double magnitudeVec, angleVec;
    magnitudeVec = magnitude(x);
    angleVec = angle(x);
    printf("x: Magnitude =  %9.4lf, Angle = %9.4lf rads\n", magnitudeVec, angleVec);

    magnitudeVec = magnitude(y);
    angleVec = angle(y);
    printf("y: Magnitude =  %9.4lf, Angle = %9.4lf rads\n", magnitudeVec, angleVec);
    return (EXIT_SUCCESS);
}

