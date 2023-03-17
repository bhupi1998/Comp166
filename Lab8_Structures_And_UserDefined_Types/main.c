/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.c
 * Author: bhupi
 *
 * Created on March 14, 2023, 8:47 a.m.
 */

#include <stdio.h>
#include <stdlib.h>

#include "vectorMath.h"

/*
 * 
 */
int main(int argc, char** argv) {

    Vector vec1 = {5,{1.0, 4.0, -7.2, -6.66, 1.23}};
    Vector vec2 = {5,{-5.2, 11.1, 0.1, 9.9, 7.123}};
    Vector vec3 = {7};
    Vector result;
    
    vectorMath (vec1, vec2, &result, '+');
    
    printf("Vector #1  ");
    printVector(vec1, stdout);
    printf("Vector #2  ");
    printVector(vec2, stdout);
    
    vectorMath (vec1, vec2, &result, '+');
    printf("Sum:       ");
    printVector(result, stdout);
    
    vectorMath (vec1, vec2, &result, '-');
    printf("Difference:");
    printVector(result, stdout);
    
    vectorMath (vec1, vec2, &result, '*');
    printf("Product:   ");
    printVector(result, stdout);
    
    vectorMath (vec1, vec2, &result, '/');
    printf("Quotient:  ");
    printVector(result, stdout);
    
   
    return (EXIT_SUCCESS);
}

