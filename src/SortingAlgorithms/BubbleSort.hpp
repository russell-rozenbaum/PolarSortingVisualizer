#pragma once
#include <vector>
#include <algorithm>


class BubbleSort {
    private:
        const int NUM_ELEMENTS;
        int topIndex;
        int *idx;
        int *numSwaps;
        int *numComparisons;

    public:
        BubbleSort(const int &NUM_ELTS, int *currIdx, int *swaps, int *comparisons);
        
        bool step(std::vector<float> &elements);

};