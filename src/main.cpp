#include "Visuals/Visualizer.cpp"

int main() {
    Visualizer visualizer(Algorithm::MaxSelection, Theme::Solar);
    visualizer.run();
    Visualizer visualizer2(Algorithm::MinSelection, Theme::Ocean);
    visualizer2.run();
    Visualizer visualizer3(Algorithm::Bubble, Theme::Sunset);
    visualizer3.run();
    Visualizer visualizer4(Algorithm::ReverseBubble, Theme::Arctic);
    visualizer4.run();
    Visualizer visualizer5(Algorithm::Insertion, Theme::Solar);
    visualizer5.run();
    Visualizer visualizer7(Algorithm::Shell, Theme::Solar);
    visualizer7.run();
    Visualizer visualizer6(Algorithm::Radix, Theme::Rusted);
    visualizer6.run();
    return 0;
}

// Run 'make' in project folder to build
// Run './sort' to run binary
// Run 'make clean' to remove binary
