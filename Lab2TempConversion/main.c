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
#include <ctype.h>
/*
 * 
 */
int main() {
    double userTemp; // user temperature entered by user
    char tempScaleInput[5]; //stores user input
    char upperScaleInput[0]; //stores upper case converted input
    printf("Enter a temperature followed by F, C or K. e.g., 24.5F :");
    scanf("%lf%2s",&userTemp,tempScaleInput);
    upperScaleInput[0] = toupper(tempScaleInput[0]);
    // if input does not have a valid ask again
    while(upperScaleInput[0] != 'F' && upperScaleInput[0] != 'C' && upperScaleInput[0] != 'K'){
        userTemp=0;
        printf("\nInvalid input!");
        printf("\nEnter a temperature followed by F, C or K. e.g., 24.5F :");
        scanf("%lf%2s",&userTemp,tempScaleInput);
        upperScaleInput[0] = toupper(tempScaleInput[0]);
    }
    printf("input string is: %0.1lf %s\n", userTemp, upperScaleInput);
    
    return (EXIT_SUCCESS);
}

