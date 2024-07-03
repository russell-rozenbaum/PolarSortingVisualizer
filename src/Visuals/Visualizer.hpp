#include <SFML/Graphics.hpp>
#include <cmath>
#include <vector>
#include <random>
#include <algorithm>
#include <iostream>
#include <sstream>
#include "../SortingAlgorithms/BubbleSort.cpp"
#include "../SortingAlgorithms/ReverseBubbleSort.cpp"
#include "../SortingAlgorithms/InsertionSort.cpp"
#include "../SortingAlgorithms/MinSelectionSort.cpp"
#include "../SortingAlgorithms/MaxSelectionSort.cpp"
#include "../SortingAlgorithms/RadixSort.cpp"
#include "Themes.cpp"

const int WINDOW_WIDTH = 800;
const int WINDOW_HEIGHT = 800;
const int NUM_ELTS = 12000;
const int GROWTH_FACTOR = 1;
const float MIN_RADIUS = 0.f;
const float MAX_RADIUS = 377.f * GROWTH_FACTOR;
const sf::Color HIGHLIGHT = sf::Color(255, 115, 115);
int stepsPerFrame;

enum class Algorithm {
    Bubble,
    ReverseBubble,
    MinSelection,
    MaxSelection,
    Insertion,
    Radix,
};

class Visualizer {
private:
    sf::RenderWindow window;
    std::vector<float> elts;
    std::mt19937 rng;
    int currIdx = 0;
    bool sortingComplete = false;
    bool endAnimationComplete = false;
    Themes theme;
    Algorithm algo;

    sf::Font font;
    sf::Text titleText;
    sf::Text statsText;
    int comparisons = 0;
    int swaps = 0;


    InsertionSort insertion = InsertionSort(NUM_ELTS, &currIdx, &swaps, &comparisons);
    BubbleSort bubble = BubbleSort(NUM_ELTS, &currIdx, &swaps, &comparisons);
    ReverseBubbleSort reverseBubble = ReverseBubbleSort(NUM_ELTS, &currIdx, &swaps, &comparisons);
    MinSelectionSort minSelection = MinSelectionSort(NUM_ELTS, &currIdx, &swaps, &comparisons);
    MaxSelectionSort maxSelection = MaxSelectionSort(NUM_ELTS, &currIdx, &swaps, &comparisons);
    RadixSort radix = RadixSort(NUM_ELTS, MAX_RADIUS, &currIdx, &swaps, &comparisons);
    
    void initializeElements();

    void initializeText();

    void drawElements();

    void updateText();

    void render();

public:
    Visualizer(const Algorithm &a, const Theme &th);

    void run();

};