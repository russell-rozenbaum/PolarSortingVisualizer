#pragma once
#include <vector>
#include <algorithm>


class InsertionSort {
    private:
        const int NUM_ELEMENTS;
        int insertIdx;

    public:
        InsertionSort(const int &NUM_ELTS);
        
        bool step(int &currIdx, std::vector<float> &elements);

};

