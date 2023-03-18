/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.c
 * Author: bhupi
 *
 * Created on March 17, 2023, 4:57 p.m.
 */

#include <stdio.h>
#include <stdlib.h>
#include "complex.h"

/*
 * 
 */
int main(int argc, char** argv) {
    Complex x = {3.7,-1.2};
    Complex y = {4.5,3.7};
    Complex result;
    printf("x   =  " Z_FORMAT "\n", x.re, x.im);
    printf("y   =  " Z_FORMAT "\n", x.re, x.im);
    result = add (x, y);
    printf("Sum   =  " Z_FORMAT "\n", result.re, result.im);
    
    result = subtract (x, y);
    printf("Difference   =  " Z_FORMAT "\n", result.re, result.im);
    
    result = multiply (x, y);
    printf("Product   =  " Z_FORMAT "\n", result.re, result.im);
    
    result = divide (x, y);
    printf("Quotient   =  " Z_FORMAT "\n", result.re, result.im);
    
    result = conjugate (x);
    printf("x Conjugate   =  " Z_FORMAT "\n", result.re, result.im);
    
    result = conjugate (y);
    printf("y Conjugate   =  " Z_FORMAT "\n", result.re, result.im);
    
    double magnitudeVec, angleVec;
    magnitudeVec = magnitude(x);
    angleVec = angle(x);
    printf("x: Magnitude = %lf, Angle = %lf rads\n", magnitudeVec, angleVec);
    
    magnitudeVec = magnitude(y);
    angleVec = angle(y);
    printf("y: Magnitude = %lf, Angle = %lf rads\n", magnitudeVec, angleVec);    
    return (EXIT_SUCCESS);
}

