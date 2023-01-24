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
    double userTemp, fTemp, cTemp, kTemp; // user temperature entered by user
    char tempScaleInput[5]; //stores user input
    char upperScaleInput[0]; //stores upper case converted input
    char stdinCharacter[1024]; // used to purge stdin for scanf
    //putting main program in loop so user can keep inputting
    while(1){
    printf("Enter a temperature followed by F, C or K. e.g., 24.5F :");
    scanf("%lf%2s",&userTemp,tempScaleInput);
    upperScaleInput[0] = toupper(tempScaleInput[0]);
    // if input is not valid, ask again
    while(upperScaleInput[0] != 'F' && upperScaleInput[0] != 'C' && upperScaleInput[0] != 'K' && !isdigit(userTemp)){
        fgets(stdinCharacter, 1024, stdin); //clears buffer so that scanf can wait for user input
        printf("\nInvalid input!");
        printf("\nEnter a temperature followed by F, C or K. e.g., 24.5F : ");
        scanf("%lf%2s",&userTemp,tempScaleInput);
        upperScaleInput[0] = toupper(tempScaleInput[0]);
    }
    printf("input string is: %0.1lf %s\n", userTemp, upperScaleInput);
    
    // converting input temperature to the other scales
    switch(upperScaleInput[0]){
        case 'F':
            fTemp=userTemp;
            cTemp=(userTemp-32)*5/9;
            kTemp=cTemp+273.15;
            break;
        case 'C':
            cTemp=userTemp;
            fTemp= cTemp*9/5+32;
            kTemp= cTemp+273.15;
            break;
        case 'K':
            kTemp=userTemp;
            fTemp=(kTemp-273.15)*9/5+32;
            cTemp=(fTemp-32)*5/9;
            break;
        default:
            printf("something went wrong");
    }
    // output temps
    printf("%0.3lfK = %0.3lfC = %0.3lfF\n",kTemp, cTemp, fTemp);
    }
    return (EXIT_SUCCESS);
}

