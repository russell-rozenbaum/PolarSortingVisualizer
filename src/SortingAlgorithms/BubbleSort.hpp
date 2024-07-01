#pragma once
#include <vector>
#include <algorithm>


class BubbleSort {
    private:
        const int NUM_ELEMENTS;
        int topIndex;

    public:
        BubbleSort(const int &NUM_ELTS);
        
        bool step(int &currIdx, std::vector<float> &elements);

};