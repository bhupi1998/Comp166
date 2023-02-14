/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   statistics.h
 * Author: bhupi
 *
 * Created on February 13, 2023, 5:27 p.m.
 */

#ifndef STATISTICS_H
#define STATISTICS_H

// computes mean from sum and count
double mean(const double sum, const int count);

/* Compute sample standard deviation from sum, sum of squares and count*/
double ssdev(const double sum, const double sumsq, const int count);

//this needs to be in main
/*prints results to dest file.*/
//static void printStats (FILE *dest, const int count, const double theMean, const double stddev);
#endif /* STATISTICS_H */

