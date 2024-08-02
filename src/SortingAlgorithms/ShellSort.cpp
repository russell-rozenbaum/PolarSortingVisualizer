#include "ShellSort.hpp"

ShellSort::ShellSort(const int &NUM_ELTS, int *currIdx, int *swaps, int *comparisons) : 
        NUM_ELEMENTS(NUM_ELTS), idx(currIdx), numSwaps(swaps), numComparisons(comparisons), gap(NUM_ELTS / 2) {}

bool ShellSort::step(std::vector<float> &elements) {
    if (gap <= 0) {
        return true;
    }
    else if ((*idx + gap) >= NUM_ELEMENTS) {
        *idx = 0;
        gap--;
    }
    else { 
        if (elements[*idx] > elements[*idx + gap]) {
            std::swap(elements[*idx], elements[*idx + gap]);
            (*numSwaps)++;
        }
        (*idx)++;
        (*numComparisons)++;
    }
    return false;
}