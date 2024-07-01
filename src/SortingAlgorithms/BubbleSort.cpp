#include "BubbleSort.hpp"

BubbleSort::BubbleSort(const int &NUM_ELTS) : 
        NUM_ELEMENTS(NUM_ELTS), topIndex(NUM_ELTS - 1) {}

bool BubbleSort::step(int &currIdx, std::vector<float> &elements) {
        if (currIdx > topIndex) {
            currIdx = 0;
            topIndex--;
            if (topIndex < 0) return true;
        }

        if (elements[currIdx] > elements[currIdx + 1]) {
            std::swap(elements[currIdx], elements[currIdx + 1]);
        }
        currIdx++;
        return false;
    }