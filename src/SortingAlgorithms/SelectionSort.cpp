#include "SelectionSort.hpp"

SelectionSort::SelectionSort(const int &NUM_ELTS) : 
        NUM_ELEMENTS(NUM_ELTS), selectIdx(0), selectMinIdx(0) {}

bool SelectionSort::step(int &currIdx, std::vector<float> &elements) {
        if (selectIdx >= NUM_ELEMENTS - 1) {
            return true;
        }
        else if (currIdx >= NUM_ELEMENTS - 1) {
            std::swap(elements[selectIdx], elements[selectMinIdx]);
            selectIdx++;
            currIdx = selectIdx + 1;
            selectMinIdx = selectIdx;
        }
        if (elements[currIdx] < elements[selectMinIdx]) {
            selectMinIdx = currIdx;
        }
        currIdx++;
        return false;
    }