/* 
 * File:   vectorMath.h
 * Author: Bhupinder Singh
 *
 * Created on March 14, 2023, 8:50 a.m.
 */

#ifndef VECTORMATH_H
#define VECTORMATH_H

#include <stdio.h>

#ifndef Word
#define Word double
#endif

#ifndef WORD_FORMAT
#define WORD_FORMAT "%10.4lf"
#endif

#define MAX_LENGTH 10

typedef struct Vector{
    int n; // number of values currently stored in x
    Word x[MAX_LENGTH]; // array that contains lengths of the vector
} Vector;
/*
 *Perform math on the contents of two vectors and put the result in the third vector
 *The mathematical operator 'op' must be one of '+','-', '*', '/'
 * If the  
 */
Vector *vectorMath ( const Vector v1, const Vector v2, Vector *resultPtr, const char op);

/*
 * Print the values in a Vector using the print format WORD_FORMAT
 * to the specified stream 
 */
void printVector (const Vector v, FILE *stream);

// Adds all the length values to the vector
//void addVectorValuesToVector(Vector *v, Word *array);
#endif /* VECTORMATH_H */

