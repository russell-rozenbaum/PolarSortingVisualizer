#include "MaxSelectionSort.hpp"

MaxSelectionSort::MaxSelectionSort(const int &NUM_ELTS, int *currIdx, int *swaps, int *comparisons) : 
        NUM_ELEMENTS(NUM_ELTS), selectIdx(NUM_ELTS - 1), selectMaxIdx(0), idx(currIdx), numSwaps(swaps), numComparisons(comparisons) {
            *currIdx = selectIdx;
        }

bool MaxSelectionSort::step(std::vector<float> &elements) {
        if (selectIdx < 0) {
            return true;
        }
        else if ((*idx) < 0) {
            std::swap(elements[selectIdx], elements[selectMaxIdx]);
            (*numSwaps)++;
            selectIdx--;
            (*idx) = selectIdx - 1;
            selectMaxIdx = selectIdx;
        }
        if (elements[(*idx)] > elements[selectMaxIdx]) {
            selectMaxIdx = (*idx);
        }
        (*numComparisons)++;
        (*idx)--;
        return false;
    }