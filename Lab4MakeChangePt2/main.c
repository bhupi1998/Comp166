/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.c
 * Author: bhupi
 *
 * Created on February 4, 2023, 11:54 a.m.
 */

#include <stdio.h>
#include <stdlib.h>
#include "makeChange.h"

// I would like more explanation on this from dale
// Array size 8 is {0,1,2,3,4,5,6,7}
// singleName is an array of pointers that points to the first character of each string which is at an address.
const char *singleName[CURRENCY_DENOM] = {"Twenty", "Ten", "Five", "Toonie", "Loonie", "Quarter", "Dime", "Nickel"};
const char *pluralName [CURRENCY_DENOM] = {"Twenties", "Tens", "Fives", "Toonies", "Loonies", "Quarters", "Dimes", "Nickels"};
const double itemValue [CURRENCY_DENOM] = {20,10,5,2,1,0.25,0.10,0.05};
/*
 * 
 */
int main() {
    double change, purchasePrice, amountTendered;
    
    purchasePrice = getPurchase("Enter the amount of the purchase: ");
    amountTendered = getTender("Enter the amount tendered: ", purchasePrice);

    change = amountTendered-purchasePrice;
    printf("Change Due is %.2lf \n", change);
    change = (round(change*20))/20;
    printf("Rounded to the nearest nickel: %0.2lf\n", change);
    
    for(int i=0; i< CURRENCY_DENOM; i++){
        change = changeItem (change, itemValue[i], singleName[i], pluralName[i]);
    }
    return (EXIT_SUCCESS);
}

