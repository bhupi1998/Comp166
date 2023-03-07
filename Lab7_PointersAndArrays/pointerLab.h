/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   pointerLab.h
 * Author: bhupi
 *
 * Created on March 4, 2023, 2:22 p.m.
 */

#ifndef POINTERLAB_H
#define POINTERLAB_H

#include <stdio.h>


typedef double WORD; // format of the values and array
#define WORD_FORMAT "%0.0lf"

#define N_NUMS 20 // number of values in the array
static const WORD START_VAL = 1011; // start value of the array

/* Swap the two values pointed at by x and y*/
void swap (WORD *x, WORD *y);

/* Print all of the values in a 1-D array where the array size is N
*  and WORD_FORMAT has been #define'd*/
void printVector (const WORD *vec, const int N);

/* Print all of the values in a 1-D array one byte at a time where the 
 * array size is N.
 * Prints an extra space after each word*/
void printBytes (const WORD *vec, const int N);

/* Print all of the values in a 1-D array one byte at a time in reverse
 * byte order for each word where the array size is N.
 * Prints an extra space after each word */
void printBytesReverseEndian (const WORD *vec, const int N);
#endif /* POINTERLAB_H */

