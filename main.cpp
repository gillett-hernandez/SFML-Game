#include <SFML/Graphics.hpp>

int main(int argc, char const *argv[]) {
    // http://www.sfml-dev.org/tutorials/2.3/window-window.php
    // ^ references sf::Window type, not sf::RenderWindow
    // why?
    //
    sf::RenderWindow window(sf::VideoMode(200, 200), "SFML works!");
    sf::CircleShape shape(100.f);
    shape.setFillColor(sf::Color::Green);
    sf::Clock clock;
    while (window.isOpen()) {
        sf::Time elapsed = clock.restart();

        sf::Event event;
        while (window.pollEvent(event)) {
            switch(event.type) {
                case sf::Event::Closed:
                    window.close();
                    break;
                case sf::Event::KeyPressed:
                    //...
                    break;
                default:
                    break;
            }
        }

        window.clear();
        window.draw(shape);
        window.display();
    }

    return 0;
}
