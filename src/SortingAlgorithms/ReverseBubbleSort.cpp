#include "ReverseBubbleSort.hpp"

ReverseBubbleSort::ReverseBubbleSort(const int &NUM_ELTS, int *currIdx, int *swaps, int *comparisons) : 
    NUM_ELEMENTS(NUM_ELTS), bottomIndex(1), idx(currIdx), numSwaps(swaps), numComparisons(comparisons) {
        *idx = NUM_ELEMENTS - 1;
    }

bool ReverseBubbleSort::step(std::vector<float> &elements) {
        if (*idx < bottomIndex) {
            *idx = NUM_ELEMENTS - 1;
            bottomIndex++;
            if (bottomIndex >= NUM_ELEMENTS) return true;
        }
        if (elements[*idx] < elements[*idx - 1]) {
            std::swap(elements[*idx], elements[*idx - 1]);
            (*numSwaps)++;
        }
        (*numComparisons)++;
        (*idx)--;
        return false;
    }