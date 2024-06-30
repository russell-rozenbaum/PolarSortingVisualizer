#pragma once
#include <vector>
#include <algorithm>
#include <cmath>


class RadixSort {
    private:
        const int NUM_ELEMENTS;
        const float MAX_R;
        int* currIdx;

        //bool converted;
        bool counted;
        bool accumulated;
        bool constructed;

        int place;
        int buckets[10];
        std::vector<float> snapshot;

        //void convertToIntList(int &currIdx, std::vector<float> &elements);
        void countOfOcc(int &currIdx, const std::vector<float> &elements);
        void accumulateBuckets();
        void construct(int &currIdx, std::vector<float> &elements);
        void reset();

    public:
        RadixSort(const int &NUM_ELTS, const float &MAX_RADIUS);
        
        bool step(int &currIdx, std::vector<float> &elements);

};