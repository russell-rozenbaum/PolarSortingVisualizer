#pragma once
#include <vector>
#include <algorithm>


class MinSelectionSort {
    private:
        const int NUM_ELEMENTS;
        int selectIdx;
        int selectMinIdx;
        

    public:
        MinSelectionSort(const int &NUM_ELTS);
        
        bool step(int &currIdx, std::vector<float> &elements);

};