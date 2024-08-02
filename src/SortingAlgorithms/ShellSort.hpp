#pragma once
#include <vector>
#include <algorithm>


class ShellSort {
    private:
        const int NUM_ELEMENTS;
        int *idx;
        int *numSwaps;
        int *numComparisons;
        
        int gap;

    public:
        ShellSort(const int &NUM_ELTS, int *currIdx, int *swaps, int *comparisons);
        
        bool step(std::vector<float> &elements);

};