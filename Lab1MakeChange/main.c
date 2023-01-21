/* 
 * File:   Lab1-Make Change
 * Author: Bhupinder Singh C0522200
 * Objective: To return the right amount of change broken down
 *          by currency denomination
 * Inputs: price and amount tendered
 * Created on January 17, 2023, 8:24 a.m.
 */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

/*
 * 
 */
int main(int argc, char** argv) {
    // declaring variables
    double price, tendered,changeDue;
    // declaring currency denominations
    int twenties,tens, fives,toonies, loonies, quarters, dimes, nickels, changeDueCents;
    // getting all initial inputs from user
    printf("Enter total price:");
    scanf("%lf",&price);
    printf("Enter total amount tendered:");
    scanf("%lf",&tendered);    
    // ensuring enough money is given, if not ask for more
    while(tendered<price){
        double moreTendered;
        printf("Need $%lf more\n", price-tendered);
        printf("Please add more:");
        scanf("%lf", &moreTendered);
        tendered += moreTendered;
    }
    changeDue = tendered-price;
    printf("Amount Tendered: %lf \n", tendered);
    printf("Change Due is %.2lf \n", changeDue);
    changeDue = (round(changeDue*20))/20;
    printf("Rounded to the nearest nickel: %0.2lf\n", changeDue);
    
    // calculating change
    // dividing the changeDue by the dollar value returns 
    // the result of the division. Since twenties, tens.. are integers
    // the decimal gets truncated.
    twenties = changeDue/20;
    // calculating new change due
    changeDue=changeDue-twenties*20;
    tens = changeDue/10;
    changeDue = changeDue-tens*10;
    fives= changeDue/5;
    changeDue = changeDue-fives*5;
    toonies = changeDue/2;
    changeDue = changeDue-toonies*2;
    loonies = changeDue/1;
    changeDue = changeDue-loonies*1;
    
    // multiplying the cents by 100 to avoid doing floating point math
    changeDueCents=changeDue*100; //shifting by 2 places
    quarters=changeDueCents/25;
    changeDueCents=changeDueCents-quarters*25;
    dimes=changeDueCents/10;
    changeDueCents= changeDueCents - dimes*10;  
    nickels=changeDueCents/5;
    
    //printing results
    printf("%d Twenties\n%d Tens\n%d Fives\n%d Toonies\n%d Loonies\n%d Quarters\n%d Dimes\n%d Nickels\n",twenties,tens, fives,toonies, loonies, quarters, dimes, nickels);
    return (EXIT_SUCCESS);
}

