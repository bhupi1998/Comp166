/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   makeChange.h
 * Author: bhupi
 *
 * Created on February 4, 2023, 11:55 a.m.
 */

#ifndef MAKECHANGE_H
#define MAKECHANGE_H

#ifdef __cplusplus
extern "C" {
#endif




#ifdef __cplusplus
}
#endif
#include <math.h>
double changeItem (double change, const double itemValue, const char *singleName, const char *pluralName);
double getPurchase (const char prompt[]);
double getTender (const char prompt[], double purchasePrice);
#define CURRENCY_DENOM 7
#endif /* MAKECHANGE_H */

