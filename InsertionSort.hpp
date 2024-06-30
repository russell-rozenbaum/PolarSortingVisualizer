#pragma once
#include <vector>
#include <algorithm>


class InsertionSort {
    private:
        std::vector<float> *elements;
        const int NUM_ELEMENTS;
        int* currIdx;
        int insertIdx;

    public:
        InsertionSort(const int &NUM_ELTS);
        
        bool step(int &currIdx, std::vector<float> &elements);

};

