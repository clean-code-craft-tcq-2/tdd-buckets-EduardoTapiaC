#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "current_measurements.h"

char csvValues[300];
int numberOfRanges; //captures up to 10 ranges
int hitsOnRange[10];
int rangeStart[10];
int rangeEnd[10];


//sort measures from lowest to highest using Insertion sort
int* sortMeasures(int* arrayValues, int size) {
    for(int i = 1; i < size; i++){
            int target = arrayValues[i];
            int j = i;
            while (j > 0 && arrayValues[j - 1] > target){
                arrayValues[j] = arrayValues[j -1];
                j--;
            }
            arrayValues[j] = target;
        }
        return arrayValues;
}

// returns number of continuous ranges in an OrderedList(max 10). 
// captures hits and boundaries of each range on hitsOnRange, rangeStart and rangeEnd respectively
int findHitsOnRanges(int* arrayValues, int size) {
    int currVal = arrayValues[0];
    rangeStart[0] = arrayValues[0];
    numberOfRanges = 0;
    hitsOnRange[0] = 1;
    for (int i = 1; i < size; i++)
    {
        if(currVal == arrayValues[i]){  //same number
            hitsOnRange[numberOfRanges]++;
            continue;
        }
        if(currVal + 1 == arrayValues[i]) { //next number is a continuation
            currVal++;
            hitsOnRange[numberOfRanges]++;
            continue;
        } else {        // create boundaries for this range
            rangeEnd[numberOfRanges] = currVal;
            numberOfRanges++;
            rangeStart[numberOfRanges] = arrayValues[i];
            hitsOnRange[numberOfRanges] = 1;
            currVal = arrayValues[i];
        }
    }
    rangeEnd[numberOfRanges] = arrayValues[size - 1];
    return numberOfRanges;
}

void rangeCsvFormatter(int nRanges, int* lowerBounds, int* higherBounds, int* nHits, char* csvValues) {
    //limited to 100,000 
    csvValues[0] = '\0'; //invalidate previous string
    char stringify[6];
    for(int i=0; i <= nRanges; i++){
        //lower limit
        strcpy(stringify, "");
        sprintf(stringify, "%d", lowerBounds[i]);
        strcat(csvValues, stringify);

        //separator
        strcat(csvValues,"-");

        //upper limit
        strcpy(stringify, "");
        sprintf(stringify, "%d", higherBounds[i]);
        strcat(csvValues, stringify);

        //separator for hits
        strcat(csvValues,", ");

        //hits
        strcpy(stringify, "");
        sprintf(stringify, "%d", nHits[i]);
        strcat(csvValues, stringify);
        
        //next column
        strcat(csvValues,"\n");
    }

}

char* detectRanges(int* arrayValues, int size) {
    sortMeasures(arrayValues, size);
    findHitsOnRanges(arrayValues, size);
    rangeCsvFormatter(numberOfRanges, rangeStart, rangeEnd, hitsOnRange, csvValues);
    return csvValues;
}