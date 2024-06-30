#pragma once
#include <vector>
#include <algorithm>


class BubbleSort {
    private:
        std::vector<float> *elements;
        const int NUM_ELEMENTS;
        int* currIdx;

    public:
        BubbleSort(const int &NUM_ELTS);
        
        bool step(int &currIdx, std::vector<float> &elements);

};