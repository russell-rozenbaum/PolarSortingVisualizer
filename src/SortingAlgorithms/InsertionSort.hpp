#pragma once
#include <vector>
#include <algorithm>


class InsertionSort {
    private:
        const int NUM_ELEMENTS;
        int insertIdx;
        int *idx;
        int *numSwaps;
        int *numComparisons;

    public:
        InsertionSort(const int &NUM_ELTS, int *currIdx, int *swaps, int *comparisons);
        
        bool step(std::vector<float> &elements);

};

