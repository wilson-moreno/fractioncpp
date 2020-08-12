/*************************************************
 * Header for Fraction class quicksort algorithm *
 *************************************************/

#ifndef FRACQSORT_H_INCLUDED
#define FRACQSORT_H_INCLUDED

class FractionQuicksort{
private:
    const int low{0};           // Holds the value of the lowest index of the the array
    const int high{0};          // Holds the value of the highest index of the array
    const int arraySize;        // Holds the value of the size of the array
    Fraction* fractionArray;    // The collections of Fraction objects;

    bool swap(int, int);        // Swaps the value of two elements in the array
    void quicksort(Fraction*, int, int);
    int partition(Fraction*, int, int);

public:
    FractionQuicksort(int arraySize=10);
    ~FractionQuicksort();
    void initializeArray();
    void printArray();
    void printDecimalArray();
    void sort();
};


#endif // FRACQSORT_H_INCLUDED
