/* 
 * File:   vectorMath.h
 * Author: Bhupinder Singh
 *
 * Created on March 14, 2023, 8:50 a.m.
 */

#ifndef VECTORMATH_H
#define VECTORMATH_H

#define MAX_LENGTH 10
#define Word double

typedef struct Vector{
    int n;
    Word x[MAX_LENGTH];
};
/*
 *Perform math on the contents of two vectors and put the result in the third vector
 *The mathematical operator 'op' must be one of '+','-', '*', '/'
 * If the  
 */
Vector *vectorMath ( const Vector v1, const Vector v2, Vector *resultPtr, const char op);

void printVector (const Vector v, FILE *stream);
#endif /* VECTORMATH_H */

