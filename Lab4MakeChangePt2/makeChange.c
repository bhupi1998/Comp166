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
 * Author: Bhupinder Singh
 * Date: 05/02/2023
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
/*getPurchase prompts a question and validates the user input to make sure it's acceptable
 * 
 * Inputs 
 *  prompt: prompt message to ask the user
 * Returns:
 *  the purchase price entered by the user as a double
 * Outputs:
 *  Prints the prompt to the user and wait for input
 * Author: Bhupinder Singh
 * Date: 05/02/2023
 */
double getPurchase ( const char prompt[] ){
    printf("%s", prompt);
    double purchasePrice;
    // in the input is invalid or it's below 0 keep asking.
    if(( scanf("%lf", &purchasePrice) != 1) || purchasePrice < 0){
        // ensuring the stdin is cleared before using scanf
        while(getchar() != '\n' ){}
        if(purchasePrice < 0 ){
            printf("makeChange Error: The amounts must be positive number\n");
        }else
            printf("makeChange Error: Not a valid value\n");
        
        // Ask his thoughts on recursive functions
        purchasePrice = getPurchase(prompt);
    }
    
    return purchasePrice;
    
}

/*getPurchase prompts a question and validates the user input to make sure it's 
 *  an acceptable input and that enough money is given for the purchase
 * Inputs 
 *  prompt: prompt message to ask the user
 *  purchasePrice: cost of the item the user is buying
 * Returns:
 *  the amount tendered
 * Outputs:
 *  Prints the prompt to the user and wait for input
 * Author: Bhupinder Singh
 * Date: 05/02/2023
 */
double getTender (const char prompt[], double purchasePrice){
    printf("%s", prompt);
    double tendered;
    int inputResult = scanf("%lf", &tendered);
    double change = tendered - purchasePrice;
    // in the input is invalid or it's below 0 keep asking.
    if(( inputResult != 1) || tendered < 0 || change < 0){
        // ensuring the stdin is cleared before using scanf
        while(getchar() != '\n' ){}
        if(tendered < 0 ){
            printf("makeChange Error: The amounts must be positive number\n");
        }else if(change < 0 && inputResult == 1){
            double amountMissing = purchasePrice-tendered;
            printf("makeChange Error: Please give me at least $%0.2lf more cash\n", amountMissing);
        }else
            printf("makeChange Error: Not a valid value\n");
                
        // Ask his thoughts on recursive functions
        tendered = getTender(prompt, purchasePrice);
    }
    
    return tendered;
}