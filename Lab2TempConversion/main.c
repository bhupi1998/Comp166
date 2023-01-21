/* 
 * File:   main.c
 * Author: Bhupinder Singh C0522200
 * Objective: To perform temperature conversions
 * Inputs: Temperature and Letter indicating temp scale used
 * Outputs: Outputs the temperature converted in the 3 different types
 * Created on January 20, 2023, 4:58 p.m.
 */

#include <stdio.h>
#include <stdlib.h>

/*
 * 
 */
int main() {
    double userTemp;
    char tempScale;
    printf("Enter temperature please:");
    scanf("Please enter temperature to convert: %lf%10s",&userTemp, &tempScale);
    printf("temp input is: %lf and scale is %c", userTemp, tempScale);
    return (EXIT_SUCCESS);
}

