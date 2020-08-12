#include <iostream>
#include <cstdlib>
#include <ctime>
#include "fraction.h"
#include "fracqsort.h"

FractionQuicksort::FractionQuicksort(int arraySize)
:low(0), high(arraySize-1), arraySize(arraySize){
    fractionArray = new Fraction[arraySize];
    initializeArray();
}

FractionQuicksort::~FractionQuicksort(){
    delete [] fractionArray;
}

void FractionQuicksort::initializeArray(){
    int numerator;
    int denominator;
    srand(time(0));

    for(int i=0; i < arraySize; i++){
        numerator = 10 + (rand() % 90);
        denominator = numerator + (rand() % 90);
        fractionArray[i] = Fraction(numerator, denominator);
    }
}

void FractionQuicksort::printArray(){
    for( int i=0 ; i < arraySize ; i++ ){
        cout << fractionArray[i] << " ";
    }
    cout << endl;
}

void FractionQuicksort::printDecimalArray(){
    for(int i=0; i < arraySize; i++){
        cout << fractionArray[i].getDecimal() << " ";
    }
    cout << endl;
}

bool FractionQuicksort::swap(int a, int b){
    if(a >= low && a <= high && b >= low && b <= high){
        Fraction hold = fractionArray[a];
        fractionArray[a] = fractionArray[b];
        fractionArray[b] = hold;
        return true;
    } else {
        return false;
    }
}

void FractionQuicksort::sort(){
    quicksort(fractionArray, low, high);
}

void FractionQuicksort::quicksort(Fraction *fractionArray, int low, int high){
    int finalPosition{0};

    if(low >= high || high <= low)return;

    finalPosition = partition(fractionArray, low, high);
    quicksort(fractionArray, finalPosition+1, high);
    quicksort(fractionArray, low, finalPosition - 1);
}

int FractionQuicksort::partition(Fraction* fractionArray, int left, int right){
    int valueMarker = left;
    int compareMarker = right;
    int hold = {0};

    while(valueMarker != compareMarker){
        if(valueMarker < compareMarker){
           if(fractionArray[compareMarker] < fractionArray[valueMarker]){
              swap(valueMarker, compareMarker);
              hold = valueMarker;
              valueMarker = compareMarker;
              compareMarker = hold + 1;
           } else {
             compareMarker--;
           }
        }

        if(compareMarker < valueMarker){
            if(fractionArray[compareMarker] > fractionArray[valueMarker]){
                swap(valueMarker, compareMarker);
                hold = valueMarker;
                valueMarker = compareMarker;
                compareMarker = hold - 1;
            } else {
              compareMarker++;
            }
        }
    }

    return valueMarker;
}


