#include "InsertionSort.hpp"

InsertionSort::InsertionSort(const int &NUM_ELTS, int *currIdx, int *swaps, int *comparisons) : 
        NUM_ELEMENTS(NUM_ELTS), insertIdx(0), idx(currIdx), numSwaps(swaps), numComparisons(comparisons) {}

bool InsertionSort::step(std::vector<float> &elements) {

    if (insertIdx >= NUM_ELEMENTS - 1) {
        return true;
    }
    if (*idx <= 0) {
        insertIdx++;
        *idx = insertIdx;
    }
    else if (elements[*idx] < elements[*idx - 1]) {
        std::swap(elements[*idx], elements[*idx - 1]);
        (*numSwaps)++;
        (*idx)--;
    }
    else {
        insertIdx++;
        *idx = insertIdx;
    }
    (*numComparisons)++;
    return false;
}