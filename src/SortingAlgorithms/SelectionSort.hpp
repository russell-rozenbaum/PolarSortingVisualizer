#pragma once
#include <vector>
#include <algorithm>


class SelectionSort {
    private:
        const int NUM_ELEMENTS;
        int* currIdx;
        int selectIdx;
        int selectMinIdx;
        

    public:
        SelectionSort(const int &NUM_ELTS);
        
        bool step(int &currIdx, std::vector<float> &elements);

};