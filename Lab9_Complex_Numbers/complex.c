#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "complex.h"

Complex add (const Complex a, const Complex b){
    Complex result = {a.re+b.re, a.im+b.im};
    return  result;
}
Complex subtract (const Complex a, const Complex b){
    Complex result = {a.re-b.re, a.im-b.im};
    return  result;
}
Complex multiply (const Complex a, const Complex b){
    Complex result;
    result.re = (a.re)*(b.re)-(a.im)*(b.im);
    result.im = (a.re)*(b.im)+(a.im)*(b.re);
    return  result;
}
Complex divide (const Complex a, const Complex b){
    Complex result;
    result.re = ((b.re)*(a.re)+(b.im)*(a.im))/((b.im)*(b.im)+(b.re)*(b.re));
    result.im = ((b.re)*(a.im)-(a.re)*(b.im))/((b.im)*(b.im)+(b.re)*(b.re));
    return  result;
}
Complex conjugate (const Complex a){
    Complex result;
    result.re = a.re;
    result.im = (-1)*(a.im);
    return  result;
}
double magnitude (const Complex a){
    return sqrt((a.im)*(a.im)+(a.re)*(a.re));
}
/* Returned angle must be in the correct quadrant! */
double angle (const Complex a){
    return atan2(a.im,a.re);
}