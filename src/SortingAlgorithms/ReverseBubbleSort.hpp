#pragma once
#include <vector>
#include <algorithm>


class ReverseBubbleSort {
    private:
        const int NUM_ELEMENTS;
        int bottomIndex;
        int *idx;
        int *numSwaps;
        int *numComparisons;

    public:
        ReverseBubbleSort(const int &NUM_ELTS, int *currIdx, int *swaps, int *comparisons);
        
        bool step(std::vector<float> &elements);

};