#pragma once
#include <vector>
#include <algorithm>


class MinSelectionSort {
    private:
        const int NUM_ELEMENTS;
        int selectIdx;
        int selectMinIdx;
        int *idx;
        int *numSwaps;
        int *numComparisons;
        

    public:
        MinSelectionSort(const int &NUM_ELTS, int *currIdx, int *swaps, int *comparisons);
        
        bool step(std::vector<float> &elements);

};