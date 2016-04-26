#include <SFML/Graphics.hpp>
#include "player.hpp"

Player::Player(int x, int y, sf::Sprite& sprite) {
    this->pos[0] = x;
    this->pos[1] = y;
    this->sprite = sprite;
    this->sprite.setPosition(x, y);
}
