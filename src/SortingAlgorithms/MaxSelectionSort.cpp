#include "MaxSelectionSort.hpp"

MaxSelectionSort::MaxSelectionSort(const int &NUM_ELTS, int& currIdx) : 
        NUM_ELEMENTS(NUM_ELTS), selectIdx(NUM_ELTS - 1), selectMaxIdx(0) {
            currIdx = selectIdx;
        }

bool MaxSelectionSort::step(int &currIdx, std::vector<float> &elements) {
        if (selectIdx < 0) {
            return true;
        }
        else if (currIdx < 0) {
            std::swap(elements[selectIdx], elements[selectMaxIdx]);
            selectIdx--;
            currIdx = selectIdx - 1;
            selectMaxIdx = selectIdx;
        }
        if (elements[currIdx] > elements[selectMaxIdx]) {
            selectMaxIdx = currIdx;
        }
        currIdx--;
        return false;
    }