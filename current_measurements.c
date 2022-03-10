#include <stdio.h>
#include "current_measurements.h"



int detectRange(int* currentValues, int size){
    int countSetRanges = 0;
    for(int i = 0; i < size; i++){
        countSetRanges++;
    }
    return countSetRanges;
}