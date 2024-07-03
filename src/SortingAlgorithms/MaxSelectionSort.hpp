#pragma once
#include <vector>
#include <algorithm>


class MaxSelectionSort {
    private:
        const int NUM_ELEMENTS;
        int selectIdx;
        int selectMaxIdx;
        int *idx;
        int *numSwaps;
        int *numComparisons;
        

    public:
        MaxSelectionSort(const int &NUM_ELTS, int *currIdx, int *swaps, int *comparisons);
        
        bool step(std::vector<float> &elements);

};