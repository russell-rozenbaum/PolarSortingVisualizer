#include "BubbleSort.hpp"

BubbleSort::BubbleSort(const int &NUM_ELTS, int *currIdx, int *swaps, int *comparisons) : 
        NUM_ELEMENTS(NUM_ELTS), topIndex(NUM_ELTS - 1), idx(currIdx), numSwaps(swaps), numComparisons(comparisons) {}

bool BubbleSort::step(std::vector<float> &elements) {
        if (*idx > topIndex) {
            *idx = 0;
            topIndex--;
            if (topIndex < 0) return true;
        }
        if (elements[*idx] > elements[*idx + 1]) {
            std::swap(elements[*idx], elements[*idx + 1]);
            (*numSwaps)++;
        }
        (*numComparisons)++;
        (*idx)++;
        return false;
    }