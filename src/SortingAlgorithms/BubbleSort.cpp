#include "BubbleSort.hpp"

BubbleSort::BubbleSort(const int &NUM_ELTS) : 
        NUM_ELEMENTS(NUM_ELTS) {}

bool BubbleSort::step(int &currIdx, std::vector<float> &elements) {
        if (currIdx >= NUM_ELEMENTS - 1) {
            currIdx = 0;
            if (std::is_sorted(elements.begin(), elements.end())) {
                return true;
            }
        }

        if (elements[currIdx] > elements[currIdx + 1]) {
            std::swap(elements[currIdx], elements[currIdx + 1]);
        }
        currIdx++;
        return false;
    }