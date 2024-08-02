#include "Visualizer.hpp"

Visualizer::Visualizer(const Algorithm &a, const Theme &th) : algo(a), theme(th), window(sf::VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT), "Polar Sorting") {

    (a == Algorithm::Radix) ? stepsPerFrame = 180 : stepsPerFrame = 128000;

    window.setFramerateLimit(FPS);
    rng.seed(std::random_device()());
    initializeElements();
    initializeText();
}

void Visualizer::initializeElements() {
    std::uniform_real_distribution<float> dist(MIN_RADIUS, MAX_RADIUS);
    for (int i = 0; i < NUM_ELTS; ++i) {
        elts.push_back(dist(rng));
    }
}

void Visualizer::initializeText() {
    if (!font.loadFromFile("src/fonts/Raleway-VariableFont_wght.ttf")) {
        // Handle font loading error
    }
    titleText.setFont(font);
    titleText.setCharacterSize(24);
    titleText.setFillColor(sf::Color::White);
    titleText.setPosition(10, 10);

    statsText.setFont(font);
    statsText.setCharacterSize(18);
    statsText.setFillColor(sf::Color::White);
    statsText.setPosition(10, 40);
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

void Visualizer::updateText() {
    std::string algorithmName;
    switch (algo) {
        case Algorithm::Bubble: algorithmName = "Bubble Sort"; break;
        case Algorithm::ReverseBubble: algorithmName = "Sinking Sort"; break;
        case Algorithm::MinSelection: algorithmName = "Selection Sort (Min Search)"; break;
        case Algorithm::MaxSelection: algorithmName = "Selection Sort (Max Search)"; break;
        case Algorithm::Insertion: algorithmName = "Insertion Sort"; break;
        case Algorithm::Radix: algorithmName = "Radix Sort"; break;
        case Algorithm::Shell: algorithmName = "Shell Sort"; break;
    }
    titleText.setString(algorithmName);

    std::ostringstream stats;
    stats << "Comparisons: " << comparisons << "\nSwaps: " << swaps;
    /* <<
     "\nSort Time: ~" << 
     static_cast<float>(steps / 1000) << " thousands of steps"; */
    statsText.setString(stats.str());
    
}

void Visualizer::render() {
    window.clear(sf::Color::Black);
    drawElements();
    updateText();
    window.draw(titleText);
    window.draw(statsText);
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
                        sortingComplete = bubble.step(elts) || sortingComplete;
                        break;
                    case Algorithm::ReverseBubble :
                        sortingComplete = reverseBubble.step(elts) || sortingComplete;
                        break;
                    case Algorithm::MinSelection :
                        sortingComplete = minSelection.step(elts) || sortingComplete;
                        break;
                    case Algorithm::MaxSelection :
                        sortingComplete = maxSelection.step(elts) || sortingComplete;
                        break;
                    case Algorithm::Insertion :
                        sortingComplete = insertion.step(elts) || sortingComplete;
                        break;
                    case Algorithm::Radix :
                        sortingComplete = radix.step(elts) || sortingComplete;
                        break;
                     case Algorithm::Shell :
                        sortingComplete = shell.step(elts) || sortingComplete;
                        break;
                }
                steps++;
            }
            render();
        }
        else if (!endAnimationComplete) {
            for (int i = 1; i < NUM_ELTS; i++) {
                std::cout << "index: " << (elts[i] > elts[i - 1]) << "\n";
            }
            // Re-iterate through all elements
            for (currIdx = 0; currIdx < NUM_ELTS; currIdx += 50) {
                render();
            }
            endAnimationComplete = true;
        }
        else window.close();
        //else render();
    }
}