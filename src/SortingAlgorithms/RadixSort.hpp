#pragma once
#include <vector>
#include <algorithm>


class RadixSort {
    private:
        const int NUM_ELEMENTS;
        const float MAX_R;
        int *idx;
        int *numSwaps;
        int *numComparisons;

        //bool converted;
        bool counted;
        bool accumulated;
        bool constructed;

        float place;
        int buckets[10];
        std::vector<float> snapshot;

        //void convertToIntList(int &currIdx, std::vector<float> &elements);
        void countOfOcc(const std::vector<float> &elements);
        void accumulateBuckets();
        void construct(std::vector<float> &elements);
        void reset();

    public:
        RadixSort(const int &NUM_ELTS, const float &MAX_RADIUS, int *currIdx, int *swaps, int *comparisons);
        
        bool step(std::vector<float> &elements);

};