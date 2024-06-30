#include <SFML/Graphics.hpp>
#include <cmath>
#include <vector>
#include <random>
#include <algorithm>
#include <iostream>
#include "BubbleSort.cpp"
#include "InsertionSort.cpp"
#include "SelectionSort.cpp"

const int WINDOW_WIDTH = 800;
const int WINDOW_HEIGHT = 800;
const int NUM_ELTS = 4000;
// 11th term of fib
const float MIN_RADIUS = 144.f;
// 89
// 144
// 233
// 14th term of fib
const float MAX_RADIUS = 377.f;
const sf::Color HIGHLIGHT = sf::Color(255, 115, 115);
// To-Do: Add UI functionality to adjust speed
const int STEPS_PER_FRAME = 8943;

class SortVisualizer {
private:
    sf::Color dynaFill(float shade) {  
        return sf::Color(shade, shade / 4, shade / 3, 55);
    }
    sf::RenderWindow window;
    std::vector<float> elts;
    std::mt19937 rng;
    int currIdx = 0;
    bool sortingComplete = false;
    bool endAnimationComplete = false;
    
    int selectIdx = 0;
    int selectMinIdx = 0;

    InsertionSort algorithm = InsertionSort(NUM_ELTS);
    //BubbleSort algorithm = BubbleSort(NUM_ELTS);
    //SelectionSort algorithm = SelectionSort(NUM_ELTS);
    
    void initializeElements() {
        std::uniform_real_distribution<float> dist(MIN_RADIUS, MAX_RADIUS);
        for (int i = 0; i < NUM_ELTS; ++i) {
            elts.push_back(dist(rng));
        }
    }

    void drawElements() {
        sf::VertexArray lines(sf::Lines, NUM_ELTS * 2);
        for (int i = 0; i < NUM_ELTS; ++i) {

            float theta = i * (2 * M_PI / NUM_ELTS);
            float x = (WINDOW_WIDTH / 2) + (elts[i] * std::cos(theta));
            float y = (WINDOW_HEIGHT / 2) + (elts[i] * std::sin(theta));
            lines[i * 2].position = sf::Vector2f(WINDOW_WIDTH / 2, WINDOW_HEIGHT / 2);
            lines[i * 2 + 1].position = sf::Vector2f(x, y);
            
            sf::Uint8 shade = static_cast<sf::Uint8>(255 * (elts[i] / MAX_RADIUS));
            sf::Color lineColor = (i == currIdx || i == currIdx + 1) 
                ? HIGHLIGHT
                : dynaFill(shade);
            lines[i * 2].color = lineColor;
            lines[i * 2 + 1].color = lineColor;
        }
        window.draw(lines);
    }

    void render() {
        window.clear(sf::Color::Black);
        drawElements();
        window.display();
    }

public:
    SortVisualizer() : window(sf::VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT), "Selection Sort") {
        window.setFramerateLimit(120);
        rng.seed(std::random_device()());
        initializeElements();
    }

    void run() {
        while (window.isOpen()) {
            sf::Event event;
            while (window.pollEvent(event)) {
                if (event.type == sf::Event::Closed)
                    window.close();
            }
            if (!sortingComplete) {
                for (int timer = 0; timer < STEPS_PER_FRAME; ++timer) {
                    sortingComplete = algorithm.step(currIdx, elts) || sortingComplete;
                }
                render();
            }
            else if (!endAnimationComplete) {
                // Re-iterate through all elements
                for (currIdx = 0; currIdx < NUM_ELTS; currIdx += 10) {
                    render();
                }
                endAnimationComplete = true;
            }
            else render();
        }
    }
};

int main() {
    SortVisualizer visualizer;
    visualizer.run();
    return 0;
}
