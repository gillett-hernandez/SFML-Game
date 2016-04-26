#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <iostream>
#include "player.hpp"

int main(int argc, char const *argv[]) {
    // http://www.sfml-dev.org/tutorials/2.3/window-window.php
    // ^ references sf::Window type, not sf::RenderWindow
    // why?
    //
    sf::RenderWindow window(sf::VideoMode(800, 600), "SFML works!", sf::Style::Titlebar | sf::Style::Close);
    sf::CircleShape shape(100.f);
    shape.setFillColor(sf::Color::Green);

    // Load a sprite to display
    sf::Texture texture;
    if (!texture.loadFromFile("./resources/heart.png")){
        return EXIT_FAILURE;
    }
    sf::Sprite sprite(texture);
    Player* player = new Player(100, 100, sprite);

    sf::Music music;
    if (!music.openFromFile("./resources/flowey.ogg")) {
            return EXIT_FAILURE;
    }
    // Play the music
    music.play();
    
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
                    if (event.key.code == sf::Keyboard::Q) {
                        window.close();
                    }
                    if (event.key.code == sf::Keyboard::Escape) {
                        std::cout << "the escape key was pressed" << std::endl;
                        std::cout << "control:" << event.key.control << std::endl;
                        std::cout << "alt:" << event.key.alt << std::endl;
                        std::cout << "shift:" << event.key.shift << std::endl;
                        std::cout << "system:" << event.key.system << std::endl;
                    }
                    break;
                default:
                    break;
            }
        }

        window.clear();
        window.draw(shape);
        window.draw(player->sprite);
        window.display();
    }

    return 0;
}
