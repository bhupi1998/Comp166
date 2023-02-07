/* 
 * File:   makeChange.h
 * Author: bhupi
 *
 * Created on February 4, 2023, 11:55 a.m.
 */

#ifndef MAKECHANGE_H
#define MAKECHANGE_H

    #include <math.h>
    #define CURRENCY_DENOM 8
    double changeItem (double change, const double itemValue, const char *singleName, const char *pluralName);
    double getPurchase (const char prompt[]);
    double getTender (const char prompt[], double purchasePrice);
#endif /* MAKECHANGE_H */

