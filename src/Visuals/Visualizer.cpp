#include "Visualizer.hpp"

Visualizer::Visualizer(const Algorithm &a, const Theme &th) : algo(a), theme(th), window(sf::VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT), "Polar Sorting") {

    (a == Algorithm::Radix) ? stepsPerFrame = 80 : stepsPerFrame = 8033;

    window.setFramerateLimit(120);
    rng.seed(std::random_device()());
    initializeElements();
}

void Visualizer::initializeElements() {
    std::uniform_real_distribution<float> dist(MIN_RADIUS, MAX_RADIUS);
    for (int i = 0; i < NUM_ELTS; ++i) {
        elts.push_back(dist(rng));
    }
}

void Visualizer::drawElements() {
    sf::VertexArray lines(sf::Lines, NUM_ELTS * 2);
    for (int i = 0; i < NUM_ELTS; ++i) {

        float theta = i * (2 * M_PI / NUM_ELTS);
        float x = (WINDOW_WIDTH / 2) + ((elts[i] / GROWTH_FACTOR) * std::cos(theta));
        float y = (WINDOW_HEIGHT / 2) + ((elts[i] / GROWTH_FACTOR) * std::sin(theta));
        lines[i * 2].position = sf::Vector2f(WINDOW_WIDTH / 2, WINDOW_HEIGHT / 2);
        lines[i * 2 + 1].position = sf::Vector2f(x, y);
        
        sf::Uint8 shade = static_cast<sf::Uint8>(255 * (elts[i] / MAX_RADIUS));
        sf::Color lineColor = (i == currIdx || i == currIdx + 1) 
            ? theme.getHighlight()
            : theme.dynaFill(shade);
        lines[i * 2].color = lineColor;
        lines[i * 2 + 1].color = lineColor;
    }
    window.draw(lines);
}

void Visualizer::render() {
    window.clear(sf::Color::Black);
    drawElements();
    window.display();
}

void Visualizer::run() {
    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();
        }
        if (!sortingComplete) {
            for (int timer = 0; timer < stepsPerFrame; ++timer) {
                switch (algo) {
                    case Algorithm::Bubble :
                        sortingComplete = bubble.step(currIdx, elts) || sortingComplete;
                        break;
                    case Algorithm::ReverseBubble :
                        sortingComplete = reverseBubble.step(currIdx, elts) || sortingComplete;
                        break;
                    case Algorithm::MinSelection :
                        sortingComplete = minSelection.step(currIdx, elts) || sortingComplete;
                        break;
                    case Algorithm::MaxSelection :
                        sortingComplete = maxSelection.step(currIdx, elts) || sortingComplete;
                        break;
                    case Algorithm::Insertion :
                        sortingComplete = insertion.step(currIdx, elts) || sortingComplete;
                        break;
                    case Algorithm::Radix :
                        sortingComplete = radix.step(currIdx, elts) || sortingComplete;
                        break;
                }
            }
            render();
        }
        else if (!endAnimationComplete) {
            for (int i = 1; i < NUM_ELTS; i++) {
                std::cout << "index: " << (elts[i] > elts[i - 1]) << "\n";
            }
            // Re-iterate through all elements
            for (currIdx = 0; currIdx < NUM_ELTS; currIdx += 10) {
                render();
            }
            endAnimationComplete = true;
        }
        else render();
    }
}