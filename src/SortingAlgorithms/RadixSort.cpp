#include "RadixSort.hpp"
#include <iostream>

RadixSort::RadixSort(const int &NUM_ELTS, const float &MAX_RADIUS, int *currIdx, int *swaps, int *comparisons) :
         NUM_ELEMENTS(NUM_ELTS),
          MAX_R(MAX_RADIUS),
           counted(false),
            accumulated(false),
            // Not perfect, but pretty precise for using a vector of floats
              place(0.0001), 
              idx(currIdx), 
               numSwaps(swaps), 
                numComparisons(comparisons)
                { for (int i = 0; i < 10; i++) buckets[i] = 0; }

bool RadixSort::step(std::vector<float> &elements) {
    if (MAX_R / place <= 1) {
        return true;
    }
    
    if (!counted) { 
        countOfOcc(elements);
    }
    else if (!accumulated) {
        accumulateBuckets();
    }
    // To-do: Inaccuracies with visualization may occur as 
    // discrepencies between snapshot and elements begin to emerge
    else  {
        construct(elements);
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

void RadixSort::countOfOcc(const std::vector<float> &elements) {
    if (*idx >= NUM_ELEMENTS) {
        counted = true;
        *idx = NUM_ELEMENTS - 1;
        // Perform deep copy to hold current state of elements
        snapshot = elements;
        return;
    }
    buckets[static_cast<int>(elements[*idx] / place) % 10]++;
    (*numComparisons)++;
    (*idx)++;
}

void RadixSort::accumulateBuckets() {
    for (int i = 1; i < 10; i++) {
            buckets[i] += buckets[i - 1];
    }
    accumulated = true;
}

void RadixSort::construct(std::vector<float> &elements) {
    if (*idx < 0) {
        *idx = 0;
        reset();
    }
    elements[buckets[static_cast<int>(snapshot[*idx] / place) % 10] - 1] = snapshot[*idx];
    (*numSwaps)++;
    buckets[static_cast<int>(snapshot[*idx] / place) % 10]--;
    (*idx)--;
}

void RadixSort::reset() {
    counted = false;
    accumulated = false;
    place *= 10;
    for (int i = 0; i < 10; i++) buckets[i] = 0;
}