#include "MinSelectionSort.hpp"

MinSelectionSort::MinSelectionSort(const int &NUM_ELTS, int *currIdx, int *swaps, int *comparisons) : 
        NUM_ELEMENTS(NUM_ELTS), selectIdx(0), selectMinIdx(0), idx(currIdx), numSwaps(swaps), numComparisons(comparisons) {}

bool MinSelectionSort::step(std::vector<float> &elements) {
    if (selectIdx >= NUM_ELEMENTS - 1) {
        return true;
    }
    else if (*idx >= NUM_ELEMENTS - 1) {
        std::swap(elements[selectIdx], elements[selectMinIdx]);
        (*numSwaps)++;
        selectIdx++;
        *idx = selectIdx + 1;
        selectMinIdx = selectIdx;
    }
    if (elements[*idx] < elements[selectMinIdx]) {
        selectMinIdx = *idx;
    }
    (*numComparisons)++;
    (*idx)++;
    return false;
}