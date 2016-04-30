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
    // sf::CircleShape shape(100.f);
    // shape.setFillColor(sf::Color::Green);

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
    sf::Time frameTime = sf::milliseconds(16);
    while (window.isOpen()) {
        clock.restart();

        sf::Event event;
        while (window.pollEvent(event)) {
            switch(event.type) {
                case sf::Event::Closed:
                    window.close();
                    break;
                case sf::Event::KeyPressed:
                    switch(event.key.code) {
                        case sf::Keyboard::Escape:
                            std::cout << "the escape key was pressed" << std::endl;
                            std::cout << "control:" << event.key.control << std::endl;
                            std::cout << "alt:" << event.key.alt << std::endl;
                            std::cout << "shift:" << event.key.shift << std::endl;
                            std::cout << "system:" << event.key.system << std::endl;
                        case sf::Keyboard::Q:
                            window.close();
                            break;
                        default:
                            break;
                    }
                    break;
                default:
                    break;
            }
        }

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::W)){// || sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) {
            std::cout << "the W or Up key was pressed" << std::endl;
            player->pos[1] -= 5;
            player->updateSprite();
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)){// || sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
            std::cout << "the A or Left key was pressed" << std::endl;
            player->pos[0] -= 5;
            player->updateSprite();
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)){// || sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) {
            std::cout << "the S or Down key was pressed" << std::endl;
            player->pos[1] += 5;
            player->updateSprite();
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)){// || sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
            std::cout << "the D or Right key was pressed" << std::endl;
            player->pos[0] += 5;
            player->updateSprite();
        }

        window.clear();
        // window.draw(shape);
        window.draw(player->sprite);
        window.display();
        auto elapsed = clock.getElapsedTime();
        if (elapsed < frameTime) {
            std::cout << "elapsed time this frame " << elapsed.asMilliseconds() << std::endl;
            sf::sleep(frameTime - elapsed);
        }
    }

    return 0;
}
