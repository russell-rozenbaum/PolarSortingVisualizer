#pragma once
#include <vector>
#include <algorithm>


class ReverseBubbleSort {
    private:
        const int NUM_ELEMENTS;
        int bottomIndex;

    public:
        ReverseBubbleSort(const int &NUM_ELTS, int &currIdx);
        
        bool step(int &currIdx, std::vector<float> &elements);

};