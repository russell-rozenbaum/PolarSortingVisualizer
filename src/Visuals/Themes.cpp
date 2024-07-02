#include "Themes.hpp"



Themes::Themes(Theme theme) {
    switch (theme) {
        case Theme::Arctic:
            highlight = sf::Color(185, 205, 225);
            redDenom = 2.1f;
            greenDenom = 1.25f;
            blueDenom = 1.f;
            alpha = 60;
            break;
        case Theme::Ocean:
            highlight = sf::Color(50, 155, 215);
            redDenom = 3.5f;
            greenDenom = 1.75f;
            blueDenom = 1.f;
            alpha = 45;
            break;
        case Theme::Rusted:
            highlight = sf::Color(215, 135, 125);
            redDenom = 1.8f;
            greenDenom = 4.8f;
            blueDenom = 5.2f;
            alpha = 75;
            break;
        case Theme::Solar:
            highlight = sf::Color(255, 115, 115);
            redDenom = 1.f;
            greenDenom = 4.f;
            blueDenom = 3.f;
            alpha = 55;
            break;
        case Theme::Sunset:
            highlight = sf::Color(255, 155, 35);
            redDenom = 1.05f;
            greenDenom = 2.8f;
            blueDenom = 4.2f;
            alpha = 45;
            break;
    }
}


sf::Color Themes::dynaFill(float shade) {  
    return sf::Color(shade / redDenom,
        shade / greenDenom,
        shade / blueDenom,
        alpha);
}

sf::Color Themes::getHighlight() {
    return highlight;
}