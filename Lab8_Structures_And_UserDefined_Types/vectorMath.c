#include <stdio.h>
#include <stdlib.h>

#include "vectorMath.h"

/*
 *Perform math on the contents of two vectors and put the result in the third vector
 *The mathematical operator 'op' must be one of '+','-', '*', '/'
 * If the  
 */
Vector *vectorMath ( const Vector v1, const Vector v2, Vector *resultPtr, const char op){
    if(v1.n != v2.n){
        return NULL;
    }
    // setting pointer size of the resultant pointer
    resultPtr->n = v1.n;
    switch(op){
        case '+':
            for(int i=0;i<v1.n;i++){
                resultPtr->x[i] = v1.x[i] + v2.x[i];
            }
            break;
        case '-':
            for(int i=0;i<v1.n;i++){
                resultPtr->x[i] = v1.x[i] - v2.x[i];
            } 
            break;        
        case '*':
            for(int i=0;i<v1.n;i++){
                resultPtr->x[i] = v1.x[i] * v2.x[i];
            }            
            break;    
        case '/':
            for(int i=0;i<v1.n;i++){
                resultPtr->x[i] = v1.x[i] / v2.x[i];
            }            
            break;
        default:
            return NULL;
    }
    return resultPtr;
}

/*
 * Print the values in a Vector using the print format WORD_FORMAT
 * to the specified stream 
 */
void printVector (const Vector v, FILE *stream){
    const double *structArray = v.x; 
    for(int i = 0; i<v.n;i++){
        fprintf(stream,WORD_FORMAT, *structArray++);
    }
    fprintf(stream,"\n");
}

