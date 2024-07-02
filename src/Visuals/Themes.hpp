#pragma once
#include <SFML/Graphics.hpp>

enum class Theme {
    Arctic,
    Ocean,
    Rusted,
    Solar,
    Sunset,
};

class Themes {
    private:

        sf::Color highlight;
        float redDenom;
        float greenDenom;
        float blueDenom;
        int alpha;


    public: 

        Themes(Theme theme);

        sf::Color dynaFill(float shade);
        sf::Color getHighlight();

};