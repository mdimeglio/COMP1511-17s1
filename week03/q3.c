#include <stdio.h>

#define M_PER_KM 999
#define ML_PER_L 1000

int main(void) {
    int numKm = 3;
    int numL = 5;

    int numM = M_PER_KM*numKm;
    int numML = ML_PER_L*numL;

    return 0;
}