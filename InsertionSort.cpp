#include "InsertionSort.hpp"

InsertionSort::InsertionSort(const int &NUM_ELTS) : 
        NUM_ELEMENTS(NUM_ELTS), insertIdx(0) {}

bool InsertionSort::step(int &currIdx, std::vector<float> &elements) {
        if (insertIdx >= NUM_ELEMENTS - 1) {
            return true;
        }
        if (currIdx <= 0) {
            insertIdx++;
            currIdx = insertIdx;
        }
        else if (elements[currIdx] < elements[currIdx - 1]) {
            std::swap(elements[currIdx], elements[currIdx - 1]);
            currIdx--;
        }
        else {
            insertIdx++;
            currIdx = insertIdx;
        }
        return false;
    }