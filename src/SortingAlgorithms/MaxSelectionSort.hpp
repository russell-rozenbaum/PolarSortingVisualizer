#pragma once
#include <vector>
#include <algorithm>


class MaxSelectionSort {
    private:
        const int NUM_ELEMENTS;
        int selectIdx;
        int selectMaxIdx;
        

    public:
        MaxSelectionSort(const int &NUM_ELTS, int &currIdx);
        
        bool step(int &currIdx, std::vector<float> &elements);

};