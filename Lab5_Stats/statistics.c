
#include <math.h>
#include "statistics.h"

// computes mean from sum and count
double mean(const double sum, const int count){
    return sum/count;
}

/* Compute sample standard deviation from sum, sum of squares and count*/
double ssdev(const double sum, const double sumsq, const int count){
    return sqrt((count*(sumsq)- pow(sum,2))/(count*(count-1)));
}