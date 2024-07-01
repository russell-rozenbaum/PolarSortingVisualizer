#include "ReverseBubbleSort.hpp"

ReverseBubbleSort::ReverseBubbleSort(const int &NUM_ELTS, int &currIdx) : 
    NUM_ELEMENTS(NUM_ELTS), bottomIndex(1) {
        currIdx = NUM_ELEMENTS - 1;
    }

bool ReverseBubbleSort::step(int &currIdx, std::vector<float> &elements) {
        if (currIdx < bottomIndex) {
            currIdx = NUM_ELEMENTS - 1;
            bottomIndex++;
            if (bottomIndex >= NUM_ELEMENTS) return true;
        }

        if (elements[currIdx] < elements[currIdx - 1]) {
            std::swap(elements[currIdx], elements[currIdx - 1]);
        }
        currIdx--;
        return false;
    }