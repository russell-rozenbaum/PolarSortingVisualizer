#pragma once
#include <vector>
#include <algorithm>


class MergeSort {
    private:
        const int NUM_ELEMENTS;
        int *idx;
        int *numSwaps;
        int *numComparisons;

        std::vector<int> lengthOfSubs = {};

    public:
        MergeSort(const int &NUM_ELTS, int *currIdx, int *swaps, int *comparisons);
        
        bool step(std::vector<float> &elements);

};