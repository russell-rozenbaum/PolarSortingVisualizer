#include "RadixSort.hpp"
#include <iostream>

RadixSort::RadixSort(const int &NUM_ELTS, const float &MAX_RADIUS) : 
        NUM_ELEMENTS(NUM_ELTS),
         MAX_R(MAX_RADIUS),
          //converted(false),
           counted(false),
            accumulated(false),
            // Not perfect, but pretty precise for using a vector of floats
              place(0.0001)
                { for (int i = 0; i < 10; i++) buckets[i] = 0; }

bool RadixSort::step(int &currIdx, std::vector<float> &elements) {
    if (MAX_R / place <= 1) {
        return true;
    }
    
    if (!counted) { 
        countOfOcc(currIdx, elements);
    }
    else if (!accumulated) {
        accumulateBuckets();
    }
    // Not sure, but inaccuracies with visualization may occur as 
    // discrepencies between snapshot and elements begin to emerge
    else  {
        construct(currIdx,elements);
    }

    return false;
}

/*
void RadixSort::convertToIntList(int &currIdx, std::vector<float> &elements) {
    if (currIdx < NUM_ELEMENTS) {
        elements.at(currIdx) = static_cast<int>(std::round(elements.at(currIdx)));
        currIdx++;
    }
    else {
        currIdx = 0;
        converted = true;
    }
}
*/

void RadixSort::countOfOcc(int &currIdx, const std::vector<float> &elements) {
    if (currIdx >= NUM_ELEMENTS) {
        counted = true;
        currIdx = NUM_ELEMENTS - 1;
        // Perform deep copy to hold current state of elements
        snapshot = elements;
        return;
    }
    buckets[static_cast<int>(elements[currIdx] / place) % 10]++;
    currIdx++;
}

void RadixSort::accumulateBuckets() {
    for (int i = 1; i < 10; i++) {
            buckets[i] += buckets[i - 1];
    }
    accumulated = true;
}

void RadixSort::construct(int &currIdx, std::vector<float> &elements) {
    if (currIdx < 0) {
        currIdx = 0;
        reset();
    }
    elements[buckets[static_cast<int>(snapshot[currIdx] / place) % 10] - 1] = snapshot[currIdx];
    buckets[static_cast<int>(snapshot[currIdx] / place) % 10]--;
    currIdx--;
}

void RadixSort::reset() {
    counted = false;
    accumulated = false;
    place *= 10;
    for (int i = 0; i < 10; i++) buckets[i] = 0;
}