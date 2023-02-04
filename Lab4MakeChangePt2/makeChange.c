/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
#include "makeChange.h"

/*
 *changeItems computes the number of bills or coins based on itemValue
 *Input parameters:
 *  change: current amount of change due
 *  itemValue: value of the current bill of coin
 *  singleName: the name for a single bill or coin
 *  pluralName: the name for multiple bills or coins 
 * Returns: Amount of change left
 * 
 * It computes and prints how many bills in change should be returned in the given
 *  cash value.
 */
double changeItem (double change, const double itemValue, const char *singleName, const char *pluralName){
    //billsToGive indicates how many coins or bills in the given 
    //  currency denomination to return
    int billsToGive = change/itemValue;
    double changeLeft = change - billsToGive*itemValue;
    if ( billsToGive == 1 ){
        printf("%d %s\n", billsToGive, singleName);
    }
    else if( billsToGive >1 ) {
        printf("%d %s\n", billsToGive, pluralName);
    }
    return changeLeft;
}

double getPurchase (const char prompt[]){
    printf("%s", prompt);
    double purchasePrice;
    if(scanf("%lf", &purchasePrice) != 1){
        while(getchar() != '\n' ){}
        printf("makeChange Error: Not a valid value\n");
        
        // Ask his thoughts on recursive functions
        purchasePrice = getPurchase(prompt);
    }
    
    return purchasePrice;
    
}
double getTendered (const char prompt[], double purchasePrice){
    printf("%s", prompt);
    double tendered;
    scanf("%lf", &tendered);
    return tendered;
}